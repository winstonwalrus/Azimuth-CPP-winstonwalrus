#include "SampleState.h"

#include <Azimuth/GameObjects/ATransform.h>
#include <Azimuth/GameObjects/GameObject.h>
#include <Azimuth/GameObjects/GameObjectManager.h>

#include "SamplePlayer.h"

SampleState::SampleState(GameStateManager* _gsMan, GameObjectManager* _goMan)
	: IGameState("sample", _gsMan, _goMan)
{
}

void SampleState::Load()
{
	m_objectManager->Spawn(new SamplePlayer(m_stateManager, m_objectManager));
}
