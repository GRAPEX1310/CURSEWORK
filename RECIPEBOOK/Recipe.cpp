#include "Recipe.h"

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

bool Recipe::CreateRecipe()
{
	const std::string recipeFolder = "Recipes";
	
	try
	{
		return fs::create_directory(fs::current_path() / recipeFolder / this->recipePath);
	}
	catch (const std::exception& ex)
	{
		return false;
	}
}