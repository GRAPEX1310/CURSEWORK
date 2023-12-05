#include "SearchEngine.h"

std::vector<Recipe> SearchEngine::Start(SearchData searchData)
{
    std::vector<Recipe> searchResultArray;
    const fs::path folderPath = fs::current_path() / "Recipes";
    Recipe currentRecipe;

    for (const auto& entry : fs::directory_iterator(folderPath))
    {
        if (fs::is_directory(entry))
        {
            if (searchData.operationType)
            {
                currentRecipe = SearchUnion(searchData, entry);
            }
            else
            {
                currentRecipe = SearchIntersection(searchData, entry);
            }

            if (currentRecipe.dishName != "-1")
            {
                currentRecipe.recipePath = folderPath / entry;

                const fs::path middlePath = currentRecipe.recipePath / "MainData" / "Pic";

                int i = 0;

                for (const auto& file : fs::directory_iterator(middlePath))
                {
                    i++;
                    if (Utils::GetExtension(file) == ".jpg")
                    {
                        currentRecipe.picturePath = middlePath / file;
                    }
                }

                if (!i) currentRecipe.picturePath = "none";
                searchResultArray.push_back(currentRecipe);
            }

        }
    }

    return searchResultArray;
}

//Searchers
Recipe SearchEngine::SearchUnion(SearchData searchData, const fs::directory_entry& recipePath)
{
    std::fstream fstr;

    Recipe recipe = ParseRecipeData(recipePath);

    if (!UnionComparator(recipe, searchData, recipePath))
    {
        recipe.dishName = "-1";
    }

    return recipe;
}

Recipe SearchEngine::SearchIntersection(SearchData searchData, const fs::directory_entry& recipePath)
{
    std::fstream fstr;

    Recipe recipe = ParseRecipeData(recipePath);

    if (!IntersectionComparator(recipe, searchData, recipePath))
    {
        recipe.dishName = "-1";
    }


    return recipe;
}

Recipe SearchEngine::FindCurrentRecipe(int id)
{
    SearchData searchData;
    searchData.id = id;
    std::vector<Recipe> result = Start(searchData);
    if (!result.empty()) return result[0];
    else return Recipe();
}

//Comparators
bool SearchEngine::UnionComparator(Recipe recipe, SearchData searchData, const fs::path& stepsPath)
{
    //name and comment
    if (searchData.name != "" && !IsSubstring(recipe.dishName, searchData.name)) { return false; }
    if (searchData.phraseFromComment != "" && !IsSubstring(recipe.comment, searchData.phraseFromComment)) { return false; }

    //preparing time
    if (searchData.preparingTime.first != "" && searchData.preparingTime.second != "" &&
        !(recipe.preparingTime >= std::stoi(searchData.preparingTime.first) &&
            recipe.preparingTime <= std::stoi(searchData.preparingTime.second))) {
        return false;
    }

    //cooking time
    if (searchData.cookingTime.first != "" && searchData.cookingTime.second != "" &&
        !(recipe.cookingTime >= std::stoi(searchData.cookingTime.first) &&
            recipe.cookingTime <= std::stoi(searchData.cookingTime.second))) {
        return false;
    }

    //all time
    if (searchData.allTime.first != "" && searchData.allTime.second != "" &&
        !(recipe.allTime >= std::stoi(searchData.allTime.first) &&
            recipe.allTime <= std::stoi(searchData.allTime.second))) {
        return false;
    }

    //calories
    if (searchData.calories.first != "" && searchData.calories.second != "" &&
        !(recipe.dishCalories >= std::stoi(searchData.calories.first) &&
            recipe.dishCalories <= std::stoi(searchData.calories.second))) {
        return false;
    }

    //mark
    if (searchData.dishMark.first != "" && searchData.dishMark.second != "" &&
        !(recipe.mark >= std::stoi(searchData.dishMark.first) &&
            recipe.mark <= std::stoi(searchData.dishMark.second))) {
        return false;
    }
    
    if (searchData.id != 0 && searchData.id != recipe.id)
    {
        return false;
    }
    


    auto recipeIngridients = recipe.ingridients;
    auto searchIngridients = searchData.ingridients;

    if (searchIngridients.size() != 0 && !ContainsIngridients(recipeIngridients, searchIngridients)) return false;

    auto recipeTypes = recipe.dishTypes;
    auto searchTypes = searchData.categories;

    if (searchTypes.size() != 0 && !ContainsVector(recipeTypes, searchTypes)) return false;

    auto recipeSteps = recipe.stepByStepManual;
    auto searchSteps = searchData.phraseFromSteps;

    if (searchSteps.size() != 0 && !ContainsInstruction(recipeSteps, searchSteps)) return false;

    return true;
}

bool SearchEngine::IntersectionComparator(Recipe recipe, SearchData searchData, const fs::path& stepsPath)
{
    //name and comment
    if (searchData.name != "" && IsSubstring(recipe.dishName, searchData.name)) return true;
    if (searchData.phraseFromComment != "" && IsSubstring(recipe.comment, searchData.phraseFromComment)) return true;

    //preparing time
    if (searchData.preparingTime.first != "" && searchData.preparingTime.second != "" &&
        (recipe.preparingTime >= std::stoi(searchData.preparingTime.first) &&
            recipe.preparingTime <= std::stoi(searchData.preparingTime.second))) return true;

    //cooking time
    if (searchData.cookingTime.first != "" && searchData.cookingTime.second != "" &&
        (recipe.cookingTime >= std::stoi(searchData.cookingTime.first) &&
            recipe.cookingTime <= std::stoi(searchData.cookingTime.second))) return true;

    //all time
    if (searchData.allTime.first != "" && searchData.allTime.second != "" &&
        (recipe.allTime >= std::stoi(searchData.allTime.first) &&
            recipe.allTime <= std::stoi(searchData.allTime.second))) return true;

    //calories
    if (searchData.calories.first != "" && searchData.calories.second != "" &&
        (recipe.dishCalories >= std::stoi(searchData.calories.first) &&
            recipe.dishCalories <= std::stoi(searchData.calories.second))) return true;

    //mark
    if (searchData.dishMark.first != "" && searchData.dishMark.second != "" &&
        (recipe.mark >= std::stoi(searchData.dishMark.first) &&
            recipe.mark <= std::stoi(searchData.dishMark.second))) return true;


    if (searchData.id != 0 && searchData.id == recipe.id)
    {
        return true;
    }

    auto recipeIngridients = recipe.ingridients;
    auto searchIngridients = searchData.ingridients;

    if (searchIngridients.size() != 0 && ContainsIngridients(recipeIngridients, searchIngridients)) return true;

    auto recipeTypes = recipe.dishTypes;
    auto searchTypes = searchData.categories;

    if (searchTypes.size() != 0 && ContainsVector(recipeTypes, searchTypes)) return true;

    auto recipeSteps = recipe.stepByStepManual;
    auto searchSteps = searchData.phraseFromSteps;

    if (searchSteps.size() != 0 && ContainsInstruction(recipeSteps, searchSteps)) return true;

    return false;
}

//Validation
bool SearchEngine::ContainsIngridients(std::vector<Ingridient> v1, std::vector<std::string> v2)
{
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i].name == v2[j])
            j++;
        i++;
    }
    return j == v2.size();
}

bool SearchEngine::ContainsInstruction(std::vector<DishCookingStep> v1, std::string s2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        if (IsSubstring(v1[i].stepText, s2)) return true;
    }
    return false;
}

bool SearchEngine::ContainsVector(std::vector<std::string> v1, std::vector<std::string> v2)
{
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] == v2[j])
            j++;
        i++;
    }
    return j == v2.size();
}

bool SearchEngine::IsSubstring(std::string& text, std::string& str)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text.substr(i, str.length()) == str)
        {
            return true;
        }
    }
    return false;
}

//Parsing & convertation
Recipe SearchEngine::ParseRecipeData(const fs::path& recipePath)
{
    Recipe recipe;
    std::fstream fstr;

    const fs::path dataPath = recipePath / "MainData" / "Data.txt";
    const fs::path instructionPath = recipePath / "Steps";

    fstr.open(dataPath, std::fstream::in);

    if (!fstr.good())
    {
        recipe.dishName = "-1";
        return recipe;
    }

    std::string field;
    int fieldsCounter = 0;

    while (std::getline(fstr, field) || fieldsCounter <= 9)
    {
        switch (fieldsCounter)
        {
        case 0:
            recipe.dishName = field;
            break;
        case 1:
            recipe.comment = field;
            break;
        case 2:
            recipe.preparingTime = std::stoi(field);
            break;
        case 3:
            recipe.cookingTime = std::stoi(field);
            break;
        case 4:
            recipe.allTime = std::stoi(field);
            break;
        case 5:
            recipe.dishCalories = std::stoi(field);
            break;
        case 6:
            recipe.mark = std::stoi(field);
            break;
        case 7:
            recipe.ingridients = ConvertToIngridients(field);
            break;
        case 8:
            recipe.dishTypes = Utils::ConvertToArray(field);
            break;
        case 9:
            recipe.id = std::stoi(field);
            break;
        default:
            break;
        }

        fieldsCounter++;
    }

    recipe.stepByStepManual = ParseInstruction(instructionPath);

    return recipe;
}

std::vector<DishCookingStep> SearchEngine::ParseInstruction(const fs::path& instructionPath)
{
    const fs::path textPath = instructionPath / "Text";

    std::vector<DishCookingStep> result;
    std::vector<std::string> stepPicNames;

    for (const auto& entry : fs::directory_iterator(textPath))
    {
        DishCookingStep currentStep;

        if (fs::is_regular_file(entry))
        {
            std::fstream fstr;
            fstr.open(entry, std::fstream::in);

            if (!fstr.good())
            {
                continue;
            }

            std::string line;

            std::string pictureName = "";
            while (std::getline(fstr, line))
            {
                std::string currentstr = "";
                for (int i = 0; i < line.size(); i++)
                {
                    if (line[i] == '[')
                    {
                        while (line[i] != ']')
                        {
                            i++;
                            pictureName += line[i];
                        }
                        pictureName.erase(pictureName.begin() + pictureName.size() - 1);
                    }

                    else
                    {
                        currentstr += line[i];
                    }
                }

                currentStep.stepText += currentstr + '\n';
            }
            stepPicNames.push_back(pictureName);
        }

        result.push_back(currentStep);
    }
    result = ParseStepsPicturesPaths(instructionPath, result, stepPicNames);

    return result;
}

std::vector<DishCookingStep> SearchEngine::ParseStepsPicturesPaths(const fs::path& instructionPath, std::vector<DishCookingStep> steps, std::vector<std::string> pictureNames)
{
    for (int i = 0; i < steps.size(); i++)
    {
        if (pictureNames[i] == "!")
        {
            steps[i].picturePath = "none";
        }
        else
        {
            steps[i].picturePath = instructionPath / (pictureNames[i] + ".jpg");
        }
    }

    return steps;
}

std::vector<Ingridient> SearchEngine::ConvertToIngridients(std::string givenString)
{
    std::vector<Ingridient> resultArray;

    std::string currentString = "";
    Ingridient currentIngridient;
    bool counter = 0;

    for (int i = 0; i < givenString.size(); i++)
    {
        char currentChar = givenString[i];

        if (currentChar == ' ')
        {
            if (counter)
            {
                currentIngridient.weight = std::stoi(currentString);
                resultArray.push_back(currentIngridient);
            }

            else
            {
                currentIngridient.name = currentString;
            }

            currentString = "";
            counter = !counter;
        }

        else
        {
            currentString += currentChar;
        }
    }

    currentIngridient.weight = std::stoi(currentString);
    resultArray.push_back(currentIngridient);

    return resultArray;
}