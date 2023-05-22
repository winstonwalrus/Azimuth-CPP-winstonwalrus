#pragma once

#include "Azimuth.h"

#include <vector>
#include <list>
#include <functional>

using std::vector;
using std::list;
using std::function;

class Application;
class GameObject;

class GameObjectManager
{
public:
	DLL void Spawn(GameObject* _go);
	DLL void Destroy(GameObject* _go);

private:
	friend class Application;

	list<GameObject*> m_gameObjects;
	vector<function<void()>> m_listUpdates;

private:
	DLL GameObjectManager();
	DLL ~GameObjectManager();

	DLL void Update(float _dt);
	DLL void Draw();

};