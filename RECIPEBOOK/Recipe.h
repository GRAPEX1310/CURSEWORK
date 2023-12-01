#pragma once
#include "GRAPHICS.h"
#include "Utils.h"

using namespace System;
using namespace System::Windows::Forms;
namespace fs = std::filesystem;

struct Ingridient
{
	std::string name;
	int weight;
};

struct DishCookingStep
{
	std::string stepText;
	fs::path picturePath;
};

class Recipe
{
public:
	fs::path recipePath;
	fs::path picturePath;

	std::string dishName;
	std::string comment;
	int preparingTime;
	int cookingTime;
	int allTime;
	int dishCalories;
	int mark;
	int id;

	std::vector<Ingridient> ingridients;

	std::vector<DishCookingStep> stepByStepManual;

	std::vector<std::string> dishTypes;

	Recipe() = default;

	//Recipe edit 
	bool CreateRecipe();
	bool DeleteRecipe();
	bool UpdateStepText(int step, std::string text);
	bool UpdateRecipeData(int mode, std::string text);

	//Formatted output
	static std::string MakeCategoryOutput(std::vector<std::string> givenArray);
	static std::string MakeIngridientsOutput(std::vector<Ingridient> givenArray);

	//MainData parsing
	static std::string ParseCategories(std::string text);
	static std::string ParseMark(std::string text);
	static std::string ParseCaloriesAndTime(std::string text);
	static std::string ParseIngridients(std::string text);

	//Converters
	std::string ConvertFromIngridients();
	static std::vector<Ingridient> ConvertToIngridients(std::string givenString);
	std::string ConvertFromDishTypes();
	static std::vector<std::string> ConvertToDishTypes(std::string text);

private:
	//Auxiliary functions
	std::string GetNewRecipeFolder();
	bool CreateRecipeFolder(const fs::path& path);
	void CreateRecipeTxt(const fs::path& path, std::string fileName);
	const fs::path GenerateRecipeFiles();

	//Data writers
	void WriteMainData(const fs::path& path);
	void WriteStepsData(const fs::path& path);

	//Updates
	bool UpdateName(std::string text);
	bool UpdateCategories(std::string text);
	bool UpdateMark(std::string text);
	bool UpdateCalories(std::string text);
	bool UpdatePreparingTime(std::string text);
	bool UpdateCookingTime(std::string text);
	bool UpdateAllTime(std::string text);
	bool UpdateIngridients(std::string text);
};