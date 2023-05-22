#pragma once

#include "Azimuth.h"

class GameStateManager;
class GameObjectManager;

class IGameState
{
public:
    const char* id;

public:
    DLL IGameState(const char* _id, GameStateManager* _gsMan, GameObjectManager* _goMan);
    DLL ~IGameState();

    virtual void Load() = 0;
    virtual void Update(float _dt) {}
    virtual void Draw() {}
    virtual void Unload() {}

protected:
    GameStateManager* m_stateManager;
    GameObjectManager* m_objectManager;


};

