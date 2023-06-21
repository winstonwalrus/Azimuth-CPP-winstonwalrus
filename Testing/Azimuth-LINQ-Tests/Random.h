#pragma once

#include <list>
#include <vector>

using std::list;
using std::vector;

namespace AzimuthLINQTests
{
	class Random
	{
	public:
		static list<int> IntList(int _count, bool _allEven = false, int _maxValue = 100);
		static vector<int> IntVector(int _count, bool _allEven = false, int _maxValue = 100);

		template<typename T>
		static list<T> TemplateList(int _count, T(*_generator)());
		template<typename T>
		static vector<T> TemplateVector(int _count, T(*_generator)());
		template<typename T, typename P1>
		static list<T> TemplateList(int _count, T(*_generator)(P1), P1 _param1);
		template<typename T, typename P1>
		static vector<T> TemplateVector(int _count, T(*_generator)(P1), P1 _val_param1ue);
		template<typename T, typename P1, typename P2>
		static list<T> TemplateList(int _count, T(*_generator)(P1, P2), P1 _param1, P2 _param2);
		template<typename T, typename P1, typename P2>
		static vector<T> TemplateVector(int _count, T(*_generator)(P1, P2), P1 _param1, P2 _param2);

	};
	
	template<typename T>
	inline list<T> Random::TemplateList(int _count, T(*_generator)())
	{
		list<T> values;

		for (int i = 0; i < _count; i++)
			values.push_back(_generator());

		return values;
	}
	
	template<typename T>
	inline vector<T> Random::TemplateVector(int _count, T(*_generator)())
	{
		vector<T> values;

		for (int i = 0; i < _count; i++)
			values.push_back(_generator());

		return values;
	}

	template<typename T, typename P1>
	inline list<T> Random::TemplateList(int _count, T(*_generator)(P1), P1 _param1)
	{
		list<T> values;

		for (int i = 0; i < _count; i++)
			values.push_back(_generator(_param1));

		return values;
	}

	template<typename T, typename P1>
	inline vector<T> Random::TemplateVector(int _count, T(*_generator)(P1), P1 _val_param1ue)
	{
		vector<T> values;

		for (int i = 0; i < _count; i++)
			values.push_back(_generator(_param1));

		return values;
	}

	template<typename T, typename P1, typename P2>
	inline list<T> Random::TemplateList(int _count, T(*_generator)(P1, P2), P1 _param1, P2 _param2)
	{
		list<T> values;

		for (int i = 0; i < _count; i++)
			values.push_back(_generator(_param1, _param2));

		return values;
	}

	template<typename T, typename P1, typename P2>
	inline vector<T> Random::TemplateVector(int _count, T(*_generator)(P1, P2), P1 _param1, P2 _param2)
	{
		vector<T> values;

		for (int i = 0; i < _count; i++)
			values.push_back(_generator(_param1, _param2));

		return values;
	}
}

