#pragma once
#include "Utils.h"
#include "Recipe.h"

using namespace System;
using namespace System::Windows::Forms;
namespace fs = std::filesystem;

struct SearchData
{
	std::string name;

	std::vector<std::string> categories;

	std::vector<std::string> ingridients;

	std::string phraseFromComment;

	std::string phraseFromSteps;

	std::pair<std::string, std::string> dishMark;

	std::pair<std::string, std::string> calories;

	std::pair<std::string, std::string> preparingTime;

	std::pair<std::string, std::string> cookingTime;

	std::pair<std::string, std::string> allTime;

	bool operationType;
};

class SearchEngine
{
public:
	static std::vector<Recipe> Start(SearchData searchData);
	static Recipe FindCurrentRecipe(std::string name);

private:

	//Searchers
	static Recipe SearchUnion(SearchData searchData, const fs::directory_entry& recipePath);
	static Recipe SearchIntersection(SearchData searchData, const fs::directory_entry& recipePath);

	//Parsing & convertation
	static Recipe ParseRecipeData(const fs::path& recipePath);
	static std::vector<DishCookingStep> ParseInstruction(const fs::path& instructionPath);
	static std::vector<DishCookingStep> ParseStepsPicturesPaths(const fs::path& instructionPath, std::vector<DishCookingStep> steps, std::vector<std::string> pictureNames);
	static std::vector<Ingridient> ConvertToIngridients(std::string givenString);

	//Comparators
	static bool UnionComparator(Recipe recipe, SearchData searchData, const fs::path& stepsPath);
	static bool IntersectionComparator(Recipe recipe, SearchData searchData, const fs::path& stepsPath);
	
	//Validation
	static bool IsSubstring(std::string& text, std::string& str);
	static bool ContainsIngridients(std::vector<Ingridient> v1, std::vector<std::string> v2);
	static bool ContainsInstruction(std::vector<DishCookingStep> v1, std::string s2);
	static bool ContainsVector(std::vector<std::string> v1, std::vector<std::string> v2);
};