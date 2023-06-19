#pragma once

#include <list>
#include <vector>

using std::list;
using std::vector;

template<typename T>
class LINQ
{
public:
	static bool Any(list<T> _collection, bool(*_pred)(T));
	static bool Any(vector<T> _collection, bool(*_pred)(T));

	static bool All(list<T> _collection, bool(*_pred)(T));
	static bool All(vector<T> _collection, bool(*_pred)(T));

	static list<T> Where(list<T> _collection, bool(*_pred)(T));
	static vector<T> Where(vector<T> _collection, bool(*_pred)(T));

	template<typename S>
	static list<S> Select(list<T> _collection, S(*_pred)(T));
	template<typename S>
	static vector<S> Select(vector<T> _collection, S(*_pred)(T));

};

template<typename T>
inline bool LINQ<T>::Any(list<T> _collection, bool(*_pred)(T))
{
	bool flag = false;

	for (auto iter = _collection.begin(); iter != _collection.end(); iter++)
	{
		flag |= _pred(*iter);
	}

	return flag;
}

template<typename T>
inline bool LINQ<T>::Any(vector<T> _collection, bool(*_pred)(T))
{
	bool flag = false;

	for (auto iter = _collection.begin(); iter != _collection.end(); iter++)
	{
		flag |= _pred(*iter);
	}

	return flag;
}

template<typename T>
inline bool LINQ<T>::All(list<T> _collection, bool(*_pred)(T))
{
	bool flag = true;

	for (auto iter = _collection.begin(); iter != _collection.end(); iter++)
	{
		flag &= _pred(*iter);
	}

	return flag;
}

template<typename T>
inline bool LINQ<T>::All(vector<T> _collection, bool(*_pred)(T))
{
	bool flag = true;

	for (auto iter = _collection.begin(); iter != _collection.end(); iter++)
	{
		flag &= _pred(*iter);
	}

	return flag;
}

template<typename T>
inline list<T> LINQ<T>::Where(list<T> _collection, bool(*_pred)(T))
{
	list<T> selected;

	for (auto iter = _collection.begin(); iter != _collection.end(); iter++)
	{
		if (_pred(*iter))
			selected.push_back(*iter);
	}

	return selected;
}

template<typename T>
inline vector<T> LINQ<T>::Where(vector<T> _collection, bool(*_pred)(T))
{
	vector<T> selected;

	for (auto iter = _collection.begin(); iter != _collection.end(); iter++)
	{
		if (_pred(*iter))
			selected.push_back(*iter);
	}

	return selected;
}

template<typename T>
template<typename S>
inline list<S> LINQ<T>::Select(list<T> _collection, S(*_pred)(T))
{
	list<S> selected;

	for (auto iter = _collection.begin(); iter != _collection.end(); iter++)
	{
		selected.push_back(_pred(*iter));
	}

	return selected;
}

template<typename T>
template<typename S>
inline vector<S> LINQ<T>::Select(vector<T> _collection, S(*_pred)(T))
{
	vector<S> selected;

	for (auto iter = _collection.begin(); iter != _collection.end(); iter++)
	{
		selected.push_back(_pred(*iter));
	}

	return selected;
}
