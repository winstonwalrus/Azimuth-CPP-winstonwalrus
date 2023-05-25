#include "Azimuth/GameStates/IGameState.h"

#include "Azimuth/GameObjects/ATransform.h"
#include "Azimuth/GameObjects/GameObject.h"
#include "Azimuth/GameObjects/GameObjectManager.h"

GameObject* IGameState::GetWorld() const
{
    return m_world;
}

const string& IGameState::GetID() const
{
    return m_id;
}

IGameState::IGameState(const string& _id, GameStateManager* _gsMan, GameObjectManager* _goMan)
    : m_id(_id), m_stateManager(_gsMan), m_objectManager(_goMan), 
    m_world(new GameObject((_id + " - World").c_str(), _gsMan, _goMan))
{
    _goMan->Spawn(m_world);
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

GameObject* IGameState::CreateObject(const char* _name)
{
    GameObject* newObj = new GameObject(_name, m_stateManager, m_objectManager);
    newObj->Transform()->SetParent(m_world->Transform());

    return newObj;
}

void IGameState::DestroyObject(GameObject* _go)
{
    if (_go != nullptr)
    {
        _go->Transform()->SetParent(nullptr);
        m_objectManager->Destroy(_go);
    }
}
