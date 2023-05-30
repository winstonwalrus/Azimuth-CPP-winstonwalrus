#pragma once

#include <Azimuth/Game.h>

class SampleGame : public Game
{
public:
	// Inherited via Game
	virtual void Load(GameStateManager* _gsMan, GameObjectManager* _goMan) override;

};

