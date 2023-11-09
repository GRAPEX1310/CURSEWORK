#pragma once
#include <msclr\marshal_cppstd.h>	
#include <sys/stat.h>
#include <algorithm>
#include <windows.h>
#include <cstdio>
#include <Lmcons.h>
#include <direct.h>
#include <stdio.h> 
#include <math.h>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>

using namespace System;
using namespace System::Windows::Forms;

class Utils 
{
public:

	static std::string ConvertToSTDString(String^ givenString);
	static std::vector<std::string> ConvertToArray(String^ givenString);
	static std::pair<std::string, std::string> ConvertToPair(String^ givenString);
	
};