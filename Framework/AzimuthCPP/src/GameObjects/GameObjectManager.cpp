#include "Azimuth/GameObjects/GameObjectManager.h"

#include "Azimuth/GameObjects/GameObject.h"
#include "Azimuth/GameObjects/ATransform.h"

void GameObjectManager::Spawn(GameObject* _go)
{
	m_listUpdates.push_back([=]()
		{
			_go->Load();
			m_gameObjects.push_back(_go);
		});
}

void GameObjectManager::Destroy(GameObject* _go)
{
	m_listUpdates.push_back([=]()
		{
			_go->Unload();
			m_gameObjects.remove(_go);
			delete _go;
		});
}

list<GameObject*> GameObjectManager::FindObjectsWithTag(const char* _tag)
{
	list<GameObject*> objects;

	for (auto iter = m_gameObjects.begin(); iter != m_gameObjects.end(); iter++)
	{
		GameObject* go = *iter;
		if (strcmp(go->GetTag(), _tag) == 0)
		{
			objects.push_back(go);
		}
	}

	return objects;
}

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	for (auto iter = m_gameObjects.begin(); iter != m_gameObjects.end(); iter++)
		delete (*iter);

	m_gameObjects.clear();
	m_listUpdates.clear();
}

void GameObjectManager::Update(float _dt)
{
	for (auto& update : m_listUpdates)
		update();

	m_listUpdates.clear();

	for (auto iter = m_gameObjects.begin(); iter != m_gameObjects.end(); iter++)
	{
		GameObject* go = *iter;
		if (go->Transform()->Parent() == nullptr)
			go->Transform()->Update();

		go->Update(_dt);
	}
}

void GameObjectManager::Draw()
{
	for (auto iter = m_gameObjects.begin(); iter != m_gameObjects.end(); iter++)
	{
		(*iter)->DrawSprite();
		(*iter)->Draw();
	}
}
