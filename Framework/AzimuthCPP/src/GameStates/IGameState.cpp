#include "IGameState.h"

IGameState::IGameState(const char* _id, GameStateManager* _gsMan, GameObjectManager* _goMan)
    : id(_id), m_stateManager(_gsMan), m_objectManager(_goMan)
{

}

IGameState::~IGameState()
{
    m_stateManager = nullptr;
}
