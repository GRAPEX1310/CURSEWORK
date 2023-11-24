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

	std::vector<Ingridient> ingridients;

	std::vector<DishCookingStep> stepByStepManual;

	std::vector<std::string> dishTypes;

	Recipe() = default;

	//Recipe edit 
	bool CreateRecipe();
	bool DeleteRecipe();
	bool UpdateStepText(int step, std::string text);

	//Formatted output
	static std::string MakeCategoryOutput(std::vector<std::string> givenArray);
	static std::string MakeIngridientsOutput(std::vector<Ingridient> givenArray);

private:
	//Auxiliary functions
	 std::string GetNewRecipeFolder();
	 bool CreateRecipeFolder(const fs::path& path);
	 void CreateRecipeTxt(const fs::path& path, std::string fileName);
	 const fs::path GenerateRecipeFiles();
	 
	 //Converters
	 std::string ConvertIngridients();
	 std::string ConvertDishTypes();

	 //Data writers
	 void WriteMainData(const fs::path& path);
	 void WriteStepsData(const fs::path& path);
	 void Foo(std::vector<std::string> vector);
};