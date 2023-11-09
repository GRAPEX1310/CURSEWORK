#pragma once
#include "GRAPHICS.h"
#include "Utils.h"

using namespace System;
using namespace System::Windows::Forms;

struct Ingridient
{
	std::string name;
	int weight;
};

struct DishCookingStep
{
	std::string cookingText;
	std::string picture;
};

class Recipe
{
private:
	std::string dishName;
	std::string comment;
	int preparingTime;
	int cookingTime;
	int allTime;
	int dishCalories;
	int dishRate;
	int mark;

	std::vector<Ingridient> ingridients;

	std::vector<DishCookingStep> stepByStepManual;

	std::vector<std::string> dishTypes;

public:
	Recipe(std::string dishName, std::string dishType, 
		std::vector<Ingridient> ingridients, std::vector<DishCookingStep> stepByStepManual);
	Recipe() = default;

	std::string GetDishName();
	void SetDishName(std::string newDishName);
	bool CreateRecipeFolder(std::string directoryName);
	bool DeleteRecipeFolder(std::string directoryName);
};