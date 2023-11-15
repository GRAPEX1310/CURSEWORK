#include "SearchEngine.h"

std::vector<Recipe> SearchEngine::Start(SearchData searchData)
{
    if (searchData.operationType) return SearchUnion(searchData);
    else return SearchIntersection(searchData);
}

std::vector<Recipe> SearchEngine::SearchUnion(SearchData searchData)
{
    std::vector<Recipe> searchResultArray;

    return searchResultArray;
}

std::vector<Recipe> SearchEngine::SearchIntersection(SearchData searchData)
{
    std::vector<Recipe> searchResultArray;
    
    return searchResultArray;
}

Recipe SearchEngine::ReadFile(fs::path path)
{
    Recipe recipe;
    std::fstream fs;

    fs.open(path, std::fstream::in);
    
    if (!fs.good())
    {
        recipe.dishName = "-1";
        return recipe;
    }

    std::string field;
    int fieldsCounter = 0;

    while (std::getline(fs, field))
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
            recipe.stepByStepManual = Utils::ConvertToArray(field);
            break;
        default:
            break;
        }

        fieldsCounter++;
    }

    return recipe;
}

std::vector<Ingridient> SearchEngine::ConvertToIngridients(std::string givenString)
{
    std::vector<Ingridient> resultArray;

    std::string currentString = "";
    Ingridient currentIngridient;
    bool counter = 1;

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
