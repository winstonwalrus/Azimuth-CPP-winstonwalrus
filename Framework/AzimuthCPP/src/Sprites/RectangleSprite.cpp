#include "Azimuth/Sprites/RectangleSprite.h"


RectangleSprite::RectangleSprite(float _size)
{
	width, height = _size;
}

RectangleSprite::RectangleSprite(float _size, Color _color)
{
	width, height = _size;
	color = _color;
}

RectangleSprite::RectangleSprite(float _size, Color _color, float _angle)
{
	width, height = _size;
	color = _color;
	angle = _angle;
}

RectangleSprite::RectangleSprite(float _width, float _height)
{
	width = _width;
	height = _height;
}

RectangleSprite::RectangleSprite(float _width, float _height, Color _color)
{
	width = _width;
	height = _height;
	color = _color;
}

RectangleSprite::RectangleSprite(float _width, float _height, Color _color, float _angle)
{
	width = _width;
	height = _height;
	color = _color;
	angle = _angle;
}

RectangleSprite::~RectangleSprite()
{
}


void RectangleSprite::Draw()
{
	DrawRectanglePro({ m_position.x, m_position.y, width, height }, { m_position.x, m_position.y }, angle, color);
}
