#include "SampleGame.h"

#include "SampleState.h"

#include <Azimuth/GameStates/GameStateManager.h>

void SampleGame::Load(GameStateManager* _gsMan, GameObjectManager* _goMan)
{
	_gsMan->AddState(new SampleState(_gsMan, _goMan));
	_gsMan->ActivateState("sample");
}
