#include "GameObject.h"

GameObject::GameObject(const char* _name, GameStateManager* _gsMan, GameObjectManager* _goMan)
	: m_stateManager(_gsMan), m_objectManager(_goMan), m_name(_name), m_tag("Default")
{
}

GameObject::~GameObject()
{
}

void GameObject::Load()
{
}

void GameObject::Update(float _dt)
{
}

void GameObject::Draw()
{
}

void GameObject::Unload()
{
}

void GameObject::SetName(const char* _name)
{
	m_name = _name;
}

void GameObject::SetTag(const char* _tag)
{
	m_tag = _tag;
}

const char* GameObject::GetName() const
{
	return m_name;
}

const char* GameObject::GetTag() const
{
	return m_tag;
}
