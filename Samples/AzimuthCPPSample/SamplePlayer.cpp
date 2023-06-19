#include "SamplePlayer.h"

#include <raylib/raylib.h>
#include <Azimuth/GameObjects/ATransform.h>

#include <Azimuth/Resources/Resources.h>
#include <Azimuth/Resources/TextureResource.h>

SamplePlayer::SamplePlayer(GameStateManager* _gsMan, GameObjectManager* _goMan)
	: GameObject("Player", _gsMan, _goMan), m_texture(nullptr)
{
	Transform()->TRS({ 400, 300 }, 45, { 50, 50 });
}

void SamplePlayer::Load()
{
	m_texture = Resources::Find<Texture2D, TextureResource>("textures/test");
}

void SamplePlayer::Update(float _dt)
{
	if (IsKeyDown(KEY_W))
		Transform()->UpdatePosition(0, -50 * _dt);

	if (IsKeyDown(KEY_S))
		Transform()->UpdatePosition(0, 50 * _dt);

	if (IsKeyDown(KEY_A))
		Transform()->UpdatePosition(-50 * _dt, 0);

	if (IsKeyDown(KEY_D))
		Transform()->UpdatePosition(50 * _dt, 0);

	if (IsKeyDown(KEY_Q))
		Transform()->UpdateRotation(-45 * _dt);

	if (IsKeyDown(KEY_E))
		Transform()->UpdateRotation(45 * _dt);
}

void SamplePlayer::Draw()
{
	vec2 pos = Transform()->Position();
	vec2 scale = Transform()->Scale();
	float rotation = Transform()->Rotation();

	/*DrawRectanglePro({ pos.x, pos.y, scale.x, scale.y }, { scale.x / 2, scale.y / 2 }, rotation, RED);*/
	DrawTexturePro(*m_texture,
		{ 0, 0, (float)m_texture->Get().width, (float)m_texture->Get().height },
		{ pos.x, pos.y, scale.x, scale.y },
		{ scale.x / 2, scale.y / 2 },
		rotation,
		WHITE);
}

void SamplePlayer::Unload()
{
}
