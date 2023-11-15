#include "Recipe.h"

bool Recipe::DeleteFolder(std::string directoryName)
{
	const std::string recipeFolder = "Recipes";
	const fs::path folderPath = fs::current_path() / recipeFolder / directoryName;

	if (fs::exists(folderPath)) 
	{
		fs::remove(folderPath);
		return true;
	}
	else
	{
		return false;
	}
}

bool Recipe::CreateFolder(const std::string directoryName)
{
	const std::string recipeFolder = "Recipes";
	
	try
	{
		return fs::create_directory(fs::current_path() / recipeFolder / directoryName);
	}
	catch (const std::exception& ex)
	{
		return false;
	}
}