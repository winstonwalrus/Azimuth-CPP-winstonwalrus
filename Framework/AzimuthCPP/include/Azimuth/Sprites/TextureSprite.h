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
	DLL TextureSprite();
	DLL TextureSprite(string _texture, float _size);
	DLL TextureSprite(string _texture, float _width, float _height);
	DLL TextureSprite(string _texture, float _size, Color _color);
	DLL TextureSprite(string _texture, float _width, float _height, Color _color);
	DLL TextureSprite(string _texture, float _size, Color _color, float _angle);
	DLL TextureSprite(string _texture, float _width, float _height, Color _color, float _angle);
};

