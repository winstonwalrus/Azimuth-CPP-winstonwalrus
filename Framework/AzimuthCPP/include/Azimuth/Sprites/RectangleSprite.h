#pragma once

#include "Azimuth/Azimuth.h"
#include "Azimuth/Sprites/Sprite.h"


class RectangleSprite : Sprite
{
public:
	float width = 1;
	float height = 1;

	float angle = 0; // measured in radians

	Color color = WHITE;


public:
	DLL RectangleSprite(float _size);
	DLL RectangleSprite(float _size, Color _color);
	DLL RectangleSprite(float _size, Color _color, float _angle);
	DLL RectangleSprite(float _width, float _height);
	DLL RectangleSprite(float _width, float _height, Color _color);
	DLL RectangleSprite(float _width, float _height, Color _color, float _angle);

	DLL void Draw() override;
};
