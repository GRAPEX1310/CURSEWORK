#include "Utils.h"

std::string Utils::ConvertToSTDString(String^ givenString)
{
	return msclr::interop::marshal_as<std::string>(givenString);
}

std::vector<std::string> Utils::ConvertFromSysSrtToArray(String^ givenString)
{
	return ConvertToArray(ConvertToSTDString(givenString));
}

std::pair<std::string, std::string> Utils::ConvertToPair(String^ givenString)
{
	std::pair<std::string, std::string> result;

	std::vector<std::string> convertArray = ConvertFromSysSrtToArray(givenString);

	result.first = convertArray[0];
	result.second = convertArray[1];
	return result;
}

std::vector<std::string> Utils::ConvertToArray(std::string givenString)
{
	std::vector<std::string> result;
	std::string currentString = "";

	for (int i = 0; i < givenString.size(); i++)
	{
		char currentChar = givenString[i];
		if (currentChar == ' ')
		{
			if (!currentString.empty() && currentString != "  " && currentString != " ")
			result.push_back(currentString);
			currentString = "";
		}
		else
		{
			currentString += currentChar;
		}
	}

	if (currentString.size() > 2) result.push_back(currentString);

	return result;
}

String^ Utils::ConvertToSysString(std::string givenString)
{
	return msclr::interop::marshal_as<System::String^>(givenString);
}

std::string Utils::GetExtension(const fs::path& path)
{
	return path.extension().string();
}

int Utils::GetCurrentStep(std::string step)
{
	std::string result = "";
	for (int i = 0; i < step.size(); i++)
	{
		if (i > 3)
		{
			result += step[i];
		}
	}
	return std::stoi(result);
}

int Utils::GetCurrentRecipeId(std::string currentRecipe)
{
	std::string result = "";

	for (int i = 1; currentRecipe[i] != ')'; i++)
	{
		result += currentRecipe[i];
	}
	return std::stoi(result);
}
