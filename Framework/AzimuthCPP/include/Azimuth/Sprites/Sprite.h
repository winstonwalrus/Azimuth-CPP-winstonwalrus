#pragma once

#include "Azimuth/Azimuth.h"

#include "Azimuth/GameObjects/GameObject.h"
#include <raylib/raylib.h>
#include <glm/vec2.hpp>

using glm::vec2;


class Sprite
{
protected:
	friend GameObject;

	vec2 m_position;


public:
	DLL virtual void Draw() {};

};

