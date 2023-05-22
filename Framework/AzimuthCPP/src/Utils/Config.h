#pragma once

#define PROGRAM_CATEGORY "Program"
#define WINDOW_CATEGORY "Window"
#define DEBUG_CATEGORY "Debug"

#include <map>
#include <iostream>
#include <string>
#include <raylib/raylib.h>

using std::string;
using std::map;

class Config
{
public:
	template<typename VALUE>
	static VALUE* Get(string _category, string _key);

private:
	friend class Application;

	static Config* m_instance;

	string m_path;

	map<string, map<string, int>> m_intValues;
	map<string, map<string, bool>> m_boolValues;
	map<string, map<string, float>> m_floatValues;
	map<string, map<string, Vector2>> m_vectorValues;
	map<string, map<string, Color>> m_colorValues;
	map<string, map<string, string>> m_textValues;

private:
	Config(string _directory);
	~Config();

	void Load();
	string ProcessLine(string _line, string _category);
	void ProcessValue(string _line, string _category);
	void ProcessDecimal(string _varName, string _val, string _category);
	bool IsDecimal(string _val);
	string ProcessCategory(string _line, string _category);

	template<typename VALUE>
	void InsertValue(string _varName, VALUE _value, string _category, map<string, map<string, VALUE>>& _values);

	template<typename VALUE>
	void ValidateCategory(string _category, map<string, map<string, VALUE>>& _values);

};

template<typename VALUE>
inline VALUE* Config::Get(string _category, string _key)
{
	if (m_instance == nullptr)
	{
		std::cout << "[ERROR] Config not yet initialised" << std::endl;

		return nullptr;
	}

	if (typeid(VALUE) == typeid(int))
	{
		return (VALUE*)(&m_instance->m_intValues[_category][_key]);
	}

	if (typeid(VALUE) == typeid(bool))
	{
		return (VALUE*)(&m_instance->m_boolValues[_category][_key]);
	}

	if (typeid(VALUE) == typeid(float))
	{
		return (VALUE*)(&m_instance->m_floatValues[_category][_key]);
	}

	if (typeid(VALUE) == typeid(Vector2))
	{
		return (VALUE*)(&m_instance->m_vectorValues[_category][_key]);
	}

	if (typeid(VALUE) == typeid(Color))
	{
		return (VALUE*)(&m_instance->m_colorValues[_category][_key]);
	}

	if (typeid(VALUE) == typeid(string))
	{
		return (VALUE*)(&m_instance->m_textValues[_category][_key]);
	}

	std::cout << "Value not found for type: " << typeid(VALUE).name() << " in category: "
		<< _category << " with the key: " << _key << std::endl;

	return nullptr;
}

template<typename VALUE>
inline void Config::InsertValue(string _varName, VALUE _value, string _category, map<string, map<string, VALUE>>& _values)
{
	ValidateCategory(_category, _values);
	_values[_category][_varName] = _value;
}

template<typename VALUE>
inline void Config::ValidateCategory(string _category, map<string, map<string, VALUE>>& _values)
{
	if (_values.find(_category) == _values.end())
		_values[_category] = map<string, VALUE>();
}
