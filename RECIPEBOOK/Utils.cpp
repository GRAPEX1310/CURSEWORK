#include "Utils.h"

std::string Utils::ConvertToSTDString(String^ givenString)
{
	return msclr::interop::marshal_as<std::string>(givenString);
}

std::vector<std::string> Utils::ConvertToArray(String^ givenString)
{
	std::vector<std::string> result;

	std::string newString = ConvertToSTDString(givenString);

	std::string currentString = "";

	for (int i = 0; i < newString.size(); i++)
	{
		char currentChar = newString[i];
		if (currentChar == ' ')
		{
			result.push_back(currentString);
			currentString = "";
		}
		else
		{
			currentString += currentChar;
		}
	}

	return result;
}

std::pair<std::string, std::string> Utils::ConvertToPair(String^ givenString)
{
	std::pair<std::string, std::string> result;

	std::vector<std::string> convertArray = ConvertToArray(givenString);

	result.first = convertArray[0];
	result.second = convertArray[1];
	return result;
}
