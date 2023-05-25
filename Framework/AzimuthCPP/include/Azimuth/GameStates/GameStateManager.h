#pragma once

#include "Azimuth/Azimuth.h"

#include <list>
#include <map>
#include <functional>
#include <string>

using std::list;
using std::map;
using std::function;
using std::string;

class Application;
class IGameState;

class GameStateManager
{
public:
	DLL void ActivateState(const string& _id);
	DLL void DeativateState(const string& _id);
	DLL void AddState(IGameState* _state);
	DLL void RemoveState(IGameState* _state);

private:
	friend class Application;

	list<IGameState*> m_active;
	list<function<void()>> m_listUpdates;
	map<string, IGameState*> m_states;

private:
	GameStateManager() = default;
	DLL ~GameStateManager();
	GameStateManager(GameStateManager&) = delete;
	GameStateManager(GameStateManager&&) = delete;

	DLL void Update(float _dt);
	DLL void Draw();

};

