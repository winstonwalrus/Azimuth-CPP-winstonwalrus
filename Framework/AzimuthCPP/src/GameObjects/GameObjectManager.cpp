#include "Azimuth/GameObjects/GameObjectManager.h"
#include "Azimuth/GameObjects/GameObject.h"
#include "Azimuth/GameObjects/ATransform.h"

void GameObjectManager::Spawn(GameObject* _go)
{
	if (std::ranges::find(m_gameObjects, _go) != m_gameObjects.end())
		throw "Game Object already spawned!";

	m_listUpdates.emplace_back([=]()
		{
			_go->Load();
			m_gameObjects.emplace_back(_go);
		});
}

void GameObjectManager::Destroy(GameObject* _go)
{
	if (std::ranges::find(m_gameObjects, _go) == m_gameObjects.end())
		throw "Game Object hasn't been spawned!";

	m_listUpdates.emplace_back([=]()
		{
			_go->Unload();
			m_gameObjects.remove(_go);
			delete _go;
		});
}

list<GameObject*> GameObjectManager::FindObjectsWithTag(const char* _tag)
{
	list<GameObject*> found;

	for (auto iter = m_gameObjects.begin(); iter != m_gameObjects.end(); ++iter)
	{
		GameObject* go = *iter;
		if (strcmp(go->GetTag(), _tag) == 0)
			found.emplace_back(go);
	}

	return found;
}

list<GameObject*> GameObjectManager::GetAll()
{
	return m_gameObjects;
}

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	for (auto iter = m_gameObjects.begin(); iter != m_gameObjects.end(); ++iter)
		delete (*iter);

	m_gameObjects.clear();
	m_listUpdates.clear();
}

void GameObjectManager::Update(float _dt)
{
	for (auto& listUpdate : m_listUpdates)
		listUpdate();

	m_listUpdates.clear();

	for (auto iter = m_gameObjects.begin(); iter != m_gameObjects.end(); ++iter)
	{
		GameObject* go = *iter;
		if (go->Transform()->Parent() == nullptr)
			go->Transform()->Update();

		go->Update(_dt);
	}
}

void GameObjectManager::Draw()
{
	for (auto iter = m_gameObjects.begin(); iter != m_gameObjects.end(); ++iter)
		(*iter)->Draw();
}
