#include "SampleGame.h"

#include <Azimuth/GameStates/GameStateManager.h>

#include "SampleState.h"

#include <vector>
#include <iostream>

#include <Azimuth/Utils/LINQ.h>

using std::vector;

struct s
{
	int i;
	bool b;
};

void SampleGame::Load(GameStateManager* _gsMan, GameObjectManager* _goMan)
{
	vector<s> l = { {67, true }, {720, false }, {56, true }, {9, false } };
	for (auto& si : l)
	{
		std::cout << si.i << ":" << (si.b ? "true" : "false") << std::endl;
	}

	vector<int> iL = LINQ<s>::Select<int>(l, [](s _i) -> int
		{
			return _i.i;
		});

	std::cout << "--------------" << std::endl;

	for (auto& i : iL)
	{
		std::cout << i << std::endl;
	}

	iL = LINQ<int>::Where(iL, [](int _i) -> bool
		{
			return _i % 2 == 1;
		});

	std::cout << "--------------" << std::endl;

	for (auto& i : iL)
	{
		std::cout << i << std::endl;
	}

	std::cout << "-----------" << std::endl;

	std::cout << "are there any even numbers? " <<
		(LINQ<int>::Any(iL, [](int _i) -> bool
			{
				return _i % 2 == 0;
			}) ? "yes" : "no") << std::endl;

	std::cout << "-----------" << std::endl;

	std::cout << "are they all odd numbers? " <<
		(LINQ<int>::All(iL, [](int _i) -> bool
			{
				return _i % 2 == 1;
			}) ? "yes" : "no") << std::endl;

	_gsMan->AddState(new SampleState(_gsMan, _goMan));
	_gsMan->ActivateState("sample");
}
