#pragma once

class Game
{
public:
	virtual ~Game() = default;

protected:
	friend class Application;

protected:
	virtual void Load() = 0;
	virtual void Unload() {}
	
	virtual void Draw() {}
	virtual void Update(float _dt) {}

};