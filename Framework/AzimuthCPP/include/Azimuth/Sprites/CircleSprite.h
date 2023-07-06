#pragma once

#include "Azimuth/Sprites/Sprite.h"


class CircleSprite : Sprite
{
public:
	float radius = 1;

	Color color = WHITE;


public:
	CircleSprite(float _radius);
	CircleSprite(float _radius, Color _color);

	void Draw() override;
};

