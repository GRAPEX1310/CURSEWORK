#include "Recipe.h"

//Formatted output
std::string Recipe::MakeCategoryOutput(std::vector<std::string> givenArray)
{
	std::string result = "Категории: ";
	for (int i = 0; i < givenArray.size(); i++)
	{
		if (i > 0) result += ",";
		result += " " + givenArray[i];
	}
	return result;
}

std::string Recipe::MakeIngridientsOutput(std::vector<Ingridient> givenArray)
{
	std::string result = "Ингридиенты: ";
	for (int i = 0; i < givenArray.size(); i++)
	{
		if (i > 0) result += ",";
		result += " " + givenArray[i].name + "(" + std::to_string(givenArray[i].weight) + ")";
	}
	return result;
}

//Recipe edit
bool Recipe::DeleteRecipe()
{
	const std::string recipeFolder = "Recipes";
	const fs::path folderPath = fs::current_path() / recipeFolder / this->recipePath;
	if (fs::exists(folderPath))
	{
		fs::remove(folderPath);
		return true;
	}
	else return false;
}

bool Recipe::CreateRecipe()
{
	const fs::path basePath = GenerateRecipeFiles();
	const fs::path dataPath = basePath / "MainData";
	const fs::path stepsPath = basePath / "Steps" / "Text";

	WriteMainData(dataPath);
	WriteStepsData(stepsPath);
	return 1;
}

bool Recipe::UpdateStepText(int step, std::string text)
{
	std::string temp = "";

	const fs::path path = this->recipePath / "Steps" / "Text" / ("Step" + std::to_string(step) + ".txt");
	std::ifstream fstr1;
	fstr1.open(path);

	if (!fstr1.good()) return 0;

	std::string s;
	std::getline(fstr1, s);
	fstr1.close();

	std::ofstream fstr;
	fstr.open(path);

	if (!fstr.good()) return 0;

	fstr << s << '\n';
	fstr << text;
	fstr.close();
	return 1;
}

bool Recipe::UpdateRecipeData(int mode, std::string text)
{

	switch (mode)
	{
	case 0:
		UpdateName(text);
		break;
	case 1:
		UpdateCategories(text);
		break;
	case 2:
		UpdateMark(text);
		break;
	case 3:
		UpdateCalories(text);
		break;
	case 4:
		UpdatePreparingTime(text);
		break;
	case 5:
		UpdateCookingTime(text);
		break;
	case 6:
		UpdateAllTime(text);
		break;
	case 7:
		UpdateIngridients(text);
		break;

	default:
		break;
	}

	return 1;
}

//Auxiliary functions
std::string Recipe::GetNewRecipeFolder()
{
	const fs::path& folderPath = fs::current_path() / "Recipes";
	std::string lastDirectoryName = "";
	std::string currentDirectoryName = "";
	int n = 1;
	for (const auto& entry : fs::directory_iterator(folderPath))
	{
		if (fs::is_directory(entry))
		{
			const fs::path& currentFolder = entry;
			lastDirectoryName = currentDirectoryName;
			currentDirectoryName = currentFolder.filename().string();
			if (n > 1 && (+lastDirectoryName[lastDirectoryName.size() - 1] + 2)
				== (+currentDirectoryName[currentDirectoryName.size() - 1]))
			{
				lastDirectoryName.erase(lastDirectoryName.begin() + lastDirectoryName.size() - 1);
				return lastDirectoryName + std::to_string(currentDirectoryName[currentDirectoryName.size() - 1] - 1);
			}
			n++;
		}
	}
	lastDirectoryName.erase(lastDirectoryName.begin() + lastDirectoryName.size() - 1);
	return lastDirectoryName + std::to_string(n);
}

bool Recipe::CreateRecipeFolder(const fs::path& path)
{
	if (std::filesystem::exists(path))
	{
		return 0;
	}
	else
	{
		try
		{
			std::filesystem::create_directories(path);
			return 1;
		}
		catch (const std::exception& ex)
		{
			return 0;
		}
	}
}

void Recipe::CreateRecipeTxt(const fs::path& path, std::string fileName)
{
	std::ofstream fstr(path / fileName);
}

const fs::path Recipe::GenerateRecipeFiles()
{
	std::fstream fstr;
	std::string recipeFolderName = GetNewRecipeFolder();
	const fs::path basePath = fs::current_path() / "Recipes" / recipeFolderName;
	bool correct = CreateRecipeFolder(basePath);

	if (!correct) return fs::current_path();

	const fs::path dataPath = basePath / "MainData";
	const fs::path stepsPath = basePath / "Steps";

	bool ok1 = CreateRecipeFolder(dataPath);
	bool ok2 = CreateRecipeFolder(stepsPath);

	if (!(ok1 && ok2)) return fs::current_path();

	CreateRecipeTxt(dataPath, "Data.txt");
	ok2 = CreateRecipeFolder(dataPath / "Pic");

	if (!(ok1 && ok2)) return fs::current_path();

	ok1 = CreateRecipeFolder(stepsPath / "Text");

	if (!ok1) return fs::current_path();

	for (int i = 0; i < this->stepByStepManual.size(); i++)
	{
		CreateRecipeTxt(stepsPath / "Text", ("Step" + std::to_string(i + 1) + ".txt"));
	}

	return basePath;
}

void Recipe::SetNewId()
{
	int res = 1;
	const fs::path folderPath = fs::current_path() / "Recipes";
	Recipe currentRecipe;

	for (const auto& entry : fs::directory_iterator(folderPath))
	{
		if (fs::is_directory(entry))
		{
			res++;
		}
	}

	this->id = res;
}

//Data writers
void Recipe::WriteMainData(const fs::path& path)
{
	std::fstream fstr;
	fstr.open(path / "Data.txt", std::fstream::out);
	int fieldsCounter = 0;

	while (fieldsCounter <= 9)
	{
		switch (fieldsCounter)
		{
		case 0:
			fstr << this->dishName;
			break;
		case 1:
			fstr << this->comment;
			break;
		case 2:
			fstr << this->preparingTime;
			break;
		case 3:
			fstr << this->cookingTime;
			break;
		case 4:
			fstr << this->allTime;
			break;
		case 5:
			fstr << this->dishCalories;
			break;
		case 6:
			fstr << this->mark;
			break;
		case 7:
			fstr << ConvertFromIngridients();
			break;
		case 8:
			fstr << ConvertFromDishTypes();
			break;
		case 9: 
			fstr << this->id;
		default:
			break;
		}
		fstr << '\n';
		fieldsCounter++;
	}
}

void Recipe::WriteStepsData(const fs::path& path)
{
	for (int i = 0; i < this->stepByStepManual.size(); i++)
	{
		std::fstream fstr;
		fstr.open(path / ("Step" + std::to_string(i + 1) + ".txt"));
		fstr << "[!]";
		fstr << this->stepByStepManual[i].stepText;
	}
}

//Converters
std::string Recipe::ConvertFromIngridients()
{
	std::string result = "";

	for (int i = 0; i < this->ingridients.size(); i++)
	{
		result += this->ingridients[i].name + " " + std::to_string(this->ingridients[i].weight);
		if (i != this->ingridients.size() - 1)
		{
			result += " ";
		}
	}
	return result;
}

std::string Recipe::ConvertFromDishTypes()
{
	std::string result = "";

	for (int i = 0; i < this->dishTypes.size(); i++)
	{
		result += this->dishTypes[i] + " ";
	}
	return result;
}

std::vector<std::string> Recipe::ConvertToDishTypes(std::string text)
{
	std::vector<std::string> result;

	std::string current = "";
	for (int i = 0; i < text.size(); i++)
	{
		char a = text[i];

		if (a == ' ')
		{
			result.push_back(current);
			i++;
			current = "";
		}

		else
		{
			current += a;
		}
	}

	if (!current.empty()) result.push_back(current);

	return result;
}

std::vector<Ingridient> Recipe::ConvertToIngridients(std::string givenString)
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

//Updates
bool Recipe::UpdateName(std::string text)
{
	const fs::path path = this->recipePath / "MainData";

	this->dishName = text;

	WriteMainData(path);

	return true;
}

bool Recipe::UpdateCategories(std::string text)
{
	const fs::path path = this->recipePath / "MainData";

	std::string resultText = ParseCategories(text, 0);

	this->dishTypes = Utils::ConvertToArray(resultText);

	WriteMainData(path);

	return true;
}

bool Recipe::UpdateMark(std::string text)
{
	const fs::path path = this->recipePath / "MainData";

	std::string resultText = ParseMark(text, 0);

	this->mark = std::stoi(resultText);

	WriteMainData(path);

	return true;
}

bool Recipe::UpdateCalories(std::string text)
{
	const fs::path path = this->recipePath / "MainData";

	std::string resultText = ParseCaloriesAndTime(text, 0);

	this->dishCalories = std::stoi(resultText);

	WriteMainData(path);

	return true;
}

bool Recipe::UpdatePreparingTime(std::string text)
{
	const fs::path path = this->recipePath / "MainData";

	std::string resultText = ParseCaloriesAndTime(text, 0);

	this->preparingTime = std::stoi(resultText);

	WriteMainData(path);

	return true;
}

bool Recipe::UpdateCookingTime(std::string text)
{
	const fs::path path = this->recipePath / "MainData";

	std::string resultText = ParseCaloriesAndTime(text, 0);

	this->cookingTime = std::stoi(resultText);

	WriteMainData(path);

	return true;
}

bool Recipe::UpdateAllTime(std::string text)
{
	const fs::path path = this->recipePath / "MainData";

	std::string resultText = ParseCaloriesAndTime(text, 0);

	this->allTime = std::stoi(resultText);

	WriteMainData(path);

	return true;
}

bool Recipe::UpdateIngridients(std::string text)
{

	const fs::path path = this->recipePath / "MainData";

	this->ingridients = ConvertToIngridients(ParseIngridients(text, 0));

	WriteMainData(path);

	return true;
}

//Parsers
std::string Recipe::ParseCategories(std::string text, int mode)
{
	std::string result = "";
	std::string current = "";

	int m;
	if (mode == 0) m = 12;
	else m = 0;

	for (int i = m; i < text.size(); i++)
	{
		char a = text[i];

		if (a == ',')
		{
			result += current + " ";
			i++;
			current = " ";
		}

		else
		{
			current += a;
		}
	}
	if (!current.empty()) result += current;

	return result;
}

std::string Recipe::ParseMark(std::string text, int mode)
{
	std::string result = "";

	int m;
	if (mode == 0) m = 15;
	else m = 0;

	for (int i = m; i < text.size() - 3; i++)
	{
		result += text[i];
	}

	return result;
}

std::string Recipe::ParseCaloriesAndTime(std::string text, int mode)
{
	std::string result = "";
	int i = text.size() - 1;
	while (text[i] != ' ' || i != 0)
	{
		result += text[i];
		i--;
	}
	reverse(result.begin(), result.end());
	return result;
}

std::string Recipe::ParseIngridients(std::string text, int mode)
{
	std::string result = "";
	std::string current = "";

	int m;
	if (mode == 0) m = 14;
	else m = 0;

	for (int i = m; i < text.size(); i++)
	{
		char a = text[i];

		while (a != '(')
		{
			current += a;
			i++;
			a = text[i];
		}

		i++;
		a = text[i];

		current += " ";

		while (a != ')')
		{
			current += a;
			i++;
			a = text[i];
		}

		if (i < text.size() - 1)
		{
			i++;
			a = text[i];
			if (a == ',')
			{
				result += current;
				current = "";
			}
		}
	}

	if (!current.empty()) result += current;

	return result;
}

void Recipe::ParseInstructionText(std::vector<std::string> stepsText)
{
	for (int i = 0; i < stepsText.size(); i++)
	{
		DishCookingStep ds;
		ds.stepText = stepsText[i];
		ds.picturePath = "none";
		this->stepByStepManual.push_back(ds);
	}
}
