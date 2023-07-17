#pragma once

#include "Azimuth/Azimuth.h"
#include "Azimuth/Sprites/Sprite.h"


class CircleSprite : Sprite
{
public:
	float radius = 1;

	Color color = WHITE;


public:
	DLL CircleSprite(float _radius);
	DLL CircleSprite(float _radius, Color _color);

	DLL void Draw() override;
};

