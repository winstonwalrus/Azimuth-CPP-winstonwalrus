#pragma once

#include "Azimuth/Sprites/Sprite.h"

#include "Azimuth/Resources/TextureResource.h"
#include <string>

using std::string;


class TextureSprite
{
public:
	float width = 1;
	float height = 1;

	float angle = 0; // measured in radians

	Color color = WHITE;

	TextureResource* texture = nullptr;


public:
	TextureSprite();
	TextureSprite(string _texture, float _size);
	TextureSprite(string _texture, float _width, float _height);
	TextureSprite(string _texture, float _size, Color _color);
	TextureSprite(string _texture, float _width, float _height, Color _color);
	TextureSprite(string _texture, float _size, Color _color, float _angle);
	TextureSprite(string _texture, float _width, float _height, Color _color, float _angle);
};

