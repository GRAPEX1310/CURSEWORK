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
