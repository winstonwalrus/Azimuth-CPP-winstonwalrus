#pragma once

#include "Azimuth.h"

class GameStateManager;
class GameObjectManager;

class GameObject
{
public:
	DLL GameObject(const char* _name, GameStateManager* _gsMan, GameObjectManager* _goMan);
	DLL virtual ~GameObject();

	DLL virtual void Load();
	DLL virtual void Update(float _dt);
	DLL virtual void Draw();
	DLL virtual void Unload();

	DLL void SetName(const char* _name);
	DLL void SetTag(const char* _tag);

	DLL const char* GetName() const;
	DLL const char* GetTag() const;

protected:
	GameStateManager* m_stateManager;
	GameObjectManager* m_objectManager;

private:
	const char* m_name;
	const char* m_tag;

};

