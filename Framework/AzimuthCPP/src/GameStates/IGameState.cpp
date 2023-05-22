#include "IGameState.h"

#include "GameObjects/GameObjectManager.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/ATransform.h"

#include <string>

using std::string;

IGameState::IGameState(const char* _id, GameStateManager* _gsMan, GameObjectManager* _goMan)
    : id(_id), m_stateManager(_gsMan), m_objectManager(_goMan), m_world(nullptr)
{
    m_world = new GameObject((string(_id) + " - World").c_str(), _gsMan, _goMan);
    m_objectManager->Spawn(m_world);
}

IGameState::~IGameState()
{
    if (m_world != nullptr)
    {
        m_objectManager->Destroy(m_world);
        m_world = nullptr;
    }

    m_stateManager = nullptr;
    m_objectManager = nullptr;
}
