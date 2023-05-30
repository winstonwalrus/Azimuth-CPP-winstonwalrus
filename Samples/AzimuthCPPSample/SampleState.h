#pragma once

#include <Azimuth/GameStates/IGameState.h>

class SampleState : public IGameState
{
public:
	SampleState(GameStateManager* _gsMan, GameObjectManager* _goMan);

	void Load() override;

};