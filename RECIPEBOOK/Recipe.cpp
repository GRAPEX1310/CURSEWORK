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
	const fs::path path = this->recipePath / "Steps" / "Text" / ("Step" + std::to_string(step) + ".txt");
	std::fstream fstr;
	fstr.open(path);

	if (!fstr.good()) return 0;
	
	std::string s;
	std::getline(fstr, s);

	fstr << text;

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

//Data writers
void Recipe::WriteMainData(const fs::path& path)
{
	std::fstream fstr;
	fstr.open(path / "Data.txt", std::fstream::out);
	int fieldsCounter = 0;

	while (fieldsCounter < 9)
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
			fstr << ConvertIngridients();
			break;
		case 8:
			fstr << ConvertDishTypes();
			break;
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
std::string Recipe::ConvertIngridients()
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

std::string Recipe::ConvertDishTypes()
{
	std::string result = "";

	for (int i = 0; i < this->dishTypes.size(); i++)
	{
		result += this->dishTypes[i] + " ";
	}
	return result;
}
