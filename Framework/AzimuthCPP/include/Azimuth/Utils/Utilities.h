#pragma once

#include "Azimuth/Azimuth.h"

#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

class Utilities
{
public:
	DLL static list<char> ToCharVec(string _string);

	DLL static vector<string> Split(string _string, char _delim, int& _count);

	DLL static bool TryParse(string _string, bool& _val);

	DLL static bool TryParse(string _string, int& _val);

};