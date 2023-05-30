#pragma once

#include <Azimuth/GameObjects/GameObject.h>

class TextureResource;

class SamplePlayer : public GameObject
{
public:
	SamplePlayer(GameStateManager* _gsMan, GameObjectManager* _goMan);

	void Load() override;
	void Update(float _dt) override;
	void Draw() override;
	void Unload() override;

private:
	TextureResource* m_texture;

};

