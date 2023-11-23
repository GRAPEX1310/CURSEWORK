#pragma once
#include <msclr\marshal_cppstd.h>	
#include <sys/stat.h>
#include <filesystem>
#include <algorithm>
#include <windows.h>
#include <Lmcons.h>
#include <direct.h>
#include <iostream>
#include <fstream> 
#include <stdio.h> 
#include <math.h>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>

using namespace System;
using namespace System::Windows::Forms;
namespace fs = std::filesystem;

class Utils 
{
public:

	static std::string ConvertToSTDString(String^ givenString);
	static std::vector<std::string> ConvertFromSysSrtToArray(String^ givenString);
	static std::pair<std::string, std::string> ConvertToPair(String^ givenString);
	static std::vector<std::string> ConvertToArray(std::string givenString);
	static String^ ConvertToSysString(std::string givenString);
	static std::string GetExtension(const fs::path& path);
	
};