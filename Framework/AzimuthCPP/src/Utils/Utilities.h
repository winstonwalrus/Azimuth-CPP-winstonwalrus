#pragma once

#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

class Utilities
{
public:
	static list<char> ToCharVec(string _string);

	static vector<string> Split(string _string, char _delim, int& _count);

	static bool TryParse(string _string, bool& _val);

	static bool TryParse(string _string, int& _val);

};