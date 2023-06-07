#include "Azimuth/Config.h"

#include "Azimuth/Application.h"
#include "Azimuth/Utils.h"

#include <fstream>
#include <vector>

using std::fstream;
using std::ios;
using std::getline;
using std::vector;

Config::Config(const string& _name)
{
	m_path = string(Application::GetApplicationDirectory()) + "\\assets\\config\\" + _name + ".cfg";
	Load();
}

Config::~Config() = default;

void Config::Load()
{
	fstream file = fstream(m_path, ios::in);

	if (file.fail() || file.bad())
		return;

	string line = "";
	string category = "";

	while (getline(file, line))
	{
		category = ProcessLine(line, category);
	}

	file.close();
}

string Config::ProcessLine(string _line, string _category)
{
	if ((_line.length() > 0 && _line[0] == '#') || _line.length() == 0)
		return _category;

	string category = ProcessCategory(_line, _category);

	if (_category != category)
		return category;

	ProcessValue(_line, _category);

	return _category;
}

void Config::ProcessValue(string _line, string _category)
{
	size_t equalIndex = _line.find_first_of('=');

	string varName = _line.substr(0, equalIndex);
	string val = _line.substr(equalIndex + 1, _line.length() - equalIndex - 1);

	if (val.find('.') != string::npos && IsDecimal(val))
	{
		ProcessDecimal(varName, val, _category);
	}
	else
	{
		int iVal = 0;
		bool bVal = false;

		if (Utils::TryParse(val, iVal))
		{
			InsertValue(varName, iVal, _category, m_intValues);
		}
		else if (Utils::TryParse(val, bVal))
		{
			InsertValue(varName, bVal, _category, m_boolValues);
		}
		else
		{
			InsertValue(varName, val, _category, m_textValues);
		}
	}
}

void Config::ProcessDecimal(string _varName, string _val, string _category)
{
	int count = 0;
	vector<string> split = Utils::Split(_val, ',', count);

	if (count == 1)
	{
		InsertValue(_varName, std::stof(split[0]), _category, m_floatValues);
	}
	else
	{
		vector<float> converted;
		for (size_t i = 0; i < count; i++)
		{
			converted.push_back(std::stof(split[i]));
		}

		if (count == 2)
		{
			InsertValue(_varName, { converted[0], converted[1] }, _category, m_vectorValues);
		}
		else if (count == 4)
		{
			Color color =
			{
				(unsigned char)converted[0],
				(unsigned char)converted[1],
				(unsigned char)converted[2],
				(unsigned char)converted[3]
			};

			InsertValue(_varName, color, _category, m_colorValues);
		}
	}
}

bool Config::IsDecimal(string _val)
{
	bool(*isAnyAlpha)(char) = [](char _c) -> bool
	{
		return std::isalpha(_c);
	};

	bool(*isNoneDot)(char) = [](char _c) -> bool
	{
		return _c != '.';
	};

	return !(Utils::Any(_val, isAnyAlpha) || Utils::All(_val, isNoneDot));
}

string Config::ProcessCategory(string _line, string _category)
{
	return _line[0] == '[' ? _line.substr(1, _line.size() - 2) : _category;
}
