#include "Recipe.h"

Recipe::Recipe(std::string dishName, std::string dishType,
	std::vector<Ingridient> ingridients, std::vector<DishCookingStep> stepByStepManual)
{
	this->dishName = dishName;
	this->dishTypes.push_back(dishType);
	this->ingridients = ingridients;
	this->stepByStepManual = stepByStepManual;
}

std::string Recipe::GetDishName()
{
	return this->dishName;
}

void Recipe::SetDishName(std::string newDishName)
{
	this->dishName = newDishName;
}

bool Recipe::DeleteRecipeFolder(std::string directoryName)
{
	return 0;
}

bool Recipe::CreateRecipeFolder(std::string directoryName)
{
	// Проверяем, существует ли уже папка

	directoryName = "C:\\Users\\sasha\\source\\repos\\RECIPEBOOK\\RECIPEBOOK\\RECIPEBOOK\\Recipes\\" + directoryName;
	struct stat stat_info;
	stat(directoryName.c_str(), &stat_info);
	
	if (stat_info.st_mode & S_IFDIR)
	{
		return true;
	}

	// Если нет, создаём её  
	mkdir(directoryName.c_str());
	return true;

}