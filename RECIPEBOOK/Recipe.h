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
	std::string cookingText;
	std::string picture;
};

class Recipe
{
public:
	std::string dishName;
	std::string comment;
	int preparingTime;
	int cookingTime;
	int allTime;
	int dishCalories;
	int mark;

	std::vector<Ingridient> ingridients;

	std::vector<std::string> stepByStepManual;

	std::vector<std::string> dishTypes;

	Recipe() = default;

	bool CreateFolder(const std::string directoryName);
	bool DeleteFolder(std::string directoryName);
	//bool CreateFile();
};