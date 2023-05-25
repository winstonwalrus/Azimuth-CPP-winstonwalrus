#include "Azimuth/GameStates/GameStateManager.h"

#include "Azimuth/GameStates/IGameState.h"

void GameStateManager::ActivateState(const string& _id)
{
	if (m_states.find(_id) == m_states.end())
		return;

	m_listUpdates.push_back([=]()
		{
			m_states[_id]->Load();
			m_active.push_back(m_states[_id]);
		});
}

void GameStateManager::DeativateState(const string& _id)
{
	if (m_states.find(_id) == m_states.end())
		return;

	m_listUpdates.push_back([=]()
		{
			IGameState* state = m_states[_id];
			auto iter = std::ranges::find(m_active, state);
			if (iter == m_active.end())
				return;

			(*iter)->Unload();
			m_active.erase(iter);
		});
}

void GameStateManager::AddState(IGameState* _state)
{
	if (m_states.find(_state->m_id) != m_states.end())
		return;

	m_states[_state->m_id] = _state;
}

void GameStateManager::RemoveState(IGameState* _state)
{
	if (m_states.find(_state->m_id) != m_states.end())
		return;

	DeativateState(_state->m_id);
	m_states.erase(m_states.find(_state->m_id));
}

GameStateManager::~GameStateManager()
{
	for (auto state = m_states.begin(); state != m_states.end(); state++)
		delete state->second;

	m_states.clear();
	m_active.clear();
	m_listUpdates.clear();
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