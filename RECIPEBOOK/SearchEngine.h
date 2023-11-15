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

	std::vector<std::string> phraseFromComment;

	std::vector<std::string> phraseFromSteps;

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

private:

	static std::vector<Recipe> SearchUnion(SearchData searchData);
	static std::vector<Recipe> SearchIntersection(SearchData searchData);
	static Recipe ReadFile(fs::path path);
	static std::vector<Ingridient> ConvertToIngridients(std::string givenString);
};