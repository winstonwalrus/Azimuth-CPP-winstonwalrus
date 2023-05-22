#pragma once

#include "Azimuth.h"

#include <vector>
#include <map>
#include <functional>

using std::vector;
using std::map;
using std::function;

class Application;
class IGameState;

class GameStateManager
{
public:
    DLL void ActivateState(const char* _id);
    DLL void DeactivateState(const char* _id);
    DLL void AddState(IGameState* _state);

private:
    friend class Application;

    vector<IGameState*> m_active;
    vector<function<void()>> m_listUpdates;
    map<const char*, IGameState*> m_states;

private:
    DLL GameStateManager();
    DLL ~GameStateManager();

    DLL void Update(float _dt);
    DLL void Draw();

};