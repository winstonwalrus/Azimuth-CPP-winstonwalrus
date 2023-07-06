#pragma once

#include "Azimuth/Sprites/Sprite.h"


class RectangleSprite : Sprite
{
public:
	float width = 1;
	float height = 1;

	float angle = 0; // measured in radians

	Color color = WHITE;


public:
	RectangleSprite(float _size);
	RectangleSprite(float _size, Color _color);
	RectangleSprite(float _size, Color _color, float _angle);
	RectangleSprite(float _width, float _height);
	RectangleSprite(float _width, float _height, Color _color);
	RectangleSprite(float _width, float _height, Color _color, float _angle);

	~RectangleSprite();

	void Draw() override;
};
