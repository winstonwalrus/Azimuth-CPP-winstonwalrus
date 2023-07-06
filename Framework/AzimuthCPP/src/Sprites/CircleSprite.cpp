#include "Azimuth/Sprites/CircleSprite.h"

CircleSprite::CircleSprite(float _radius)
{
	radius = _radius;
}

CircleSprite::CircleSprite(float _radius, Color _color)
{
	radius = _radius;
	color = _color;
}

void CircleSprite::Draw()
{
	DrawCircle(m_position.x, m_position.y, radius, color);
}
