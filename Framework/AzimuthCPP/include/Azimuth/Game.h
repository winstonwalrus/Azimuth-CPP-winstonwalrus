#pragma once

class GameStateManager;
class GameObjectManager;

class Game
{
public:
	virtual ~Game() = default;

protected:
	friend class Application;

protected:
	virtual void Load(GameStateManager* _gsMan, GameObjectManager* _goMan) = 0;
	virtual void Unload() {}
	
	virtual void Draw() {}
	virtual void Update(float _dt) {}

};