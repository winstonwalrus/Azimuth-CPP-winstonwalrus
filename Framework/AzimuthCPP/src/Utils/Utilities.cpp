#include "Azimuth/Utils/Utilities.h"

#include <sstream>

using std::stringstream;

list<char> Utilities::ToCharVec(string _string)
{
	list<char> vec;

	for (size_t i = 0; i < _string.length(); i++)
	{
		vec.push_back(_string[i]);
	}

	return vec;
}

vector<string> Utilities::Split(string _string, char _delim, int& _count)
{
	_count = 1;

	for (size_t i = 0; i < _string.length(); i++)
	{
		if (_string[i] == _delim)
			_count++;
	}

	vector<string> split;

	int index = 0;

	for (size_t i = 0; i < _count; i++)
	{
		string val = "";

		for (;; index++)
		{
			if (index >= _string.length())
				break;

			if (_string[index] == _delim)
				break;

			val += _string[index];
		}

		split.push_back(val);
		index++;

		if (index >= _string.length())
			break;
	}

	return split;
}

bool Utilities::TryParse(string _string, bool& _val)
{
	stringstream stream = stringstream(_string);
	bool val;

	if (!(stream >> val))
		return false;

	_val = val;
	return true;
}

bool Utilities::TryParse(string _string, int& _val)
{
	stringstream stream = stringstream(_string);
	int val;

	if (!(stream >> val))
		return false;

	_val = val;
	return true;
}