#include "Azimuth/Sprites/TextureSprite.h"

#include "Azimuth/Resources/Resources.h"


TextureSprite::TextureSprite()
{
}

TextureSprite::TextureSprite(string _texture, float _size)
{
	texture = Resources::Find<Texture, TextureResource>(_texture);
	width, height = _size;
}

TextureSprite::TextureSprite(string _texture, float _width, float _height)
{
	texture = Resources::Find<Texture, TextureResource>(_texture);
	width = _width;
	height = _height;
}

TextureSprite::TextureSprite(string _texture, float _size, Color _color)
{
	texture = Resources::Find<Texture, TextureResource>(_texture);
	width, height = _size;
	color = _color;
}

TextureSprite::TextureSprite(string _texture, float _width, float _height, Color _color)
{
	texture = Resources::Find<Texture, TextureResource>(_texture);
	width = _width;
	height = _height;
	color = _color;
}

TextureSprite::TextureSprite(string _texture, float _size, Color _color, float _angle)
{
	texture = Resources::Find<Texture, TextureResource>(_texture);
	width, height = _size;
	color = _color;
	angle = _angle;
}

TextureSprite::TextureSprite(string _texture, float _width, float _height, Color _color, float _angle)
{
	texture = Resources::Find<Texture, TextureResource>(_texture);
	width = _width;
	height = _height;
	color = _color;
	angle = _angle;
}
