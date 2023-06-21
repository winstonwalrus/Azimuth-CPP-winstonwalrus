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
	_gsMan->AddState(new SampleState(_gsMan, _goMan));
	_gsMan->ActivateState("sample");
}
