#include "GameStateManager.h"
#include "IGameState.h"

GameStateManager::GameStateManager()
{

}

GameStateManager::~GameStateManager()
{
    for (auto state = m_states.begin(); state != m_states.end(); state++)
    {
        delete (*state).second;
    }

    m_states.clear();
    m_listUpdates.clear();
    m_active.clear();
}

void GameStateManager::Update(float _dt)
{
    for (auto update : m_listUpdates)
        update();

    m_listUpdates.clear();

    for (auto state : m_active)
        state->Update(_dt);
}

void GameStateManager::Draw()
{
    for (auto state : m_active)
        state->Draw();
}

void GameStateManager::ActivateState(const char* _id)
{
    if (m_states.find(_id) == m_states.end())
        return;

    m_listUpdates.push_back([=]()
        {
            m_states[_id]->Load();
            m_active.push_back(m_states[_id]);
        }
    );
}

void GameStateManager::DeactivateState(const char* _id)
{
    if (m_states.find(_id) == m_states.end())
        return;

    m_listUpdates.push_back([=]()
        {
            IGameState* state = m_states[_id];
            vector<IGameState*>::iterator iter = std::find(m_active.begin(), m_active.end(), state);
            if (iter == m_active.end())
                return;

            (*iter)->Unload();
            m_active.erase(iter);
        });
}

void GameStateManager::AddState(IGameState* _state)
{
    if (m_states.find(_state->id) != m_states.end())
        return;

    m_states[_state->id] = _state;
}