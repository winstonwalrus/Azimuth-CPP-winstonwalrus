#include <Application.h>
#include <Game.h>

class SampleGame : public Game
{
protected:
	void Load(GameStateManager* _gsMan, GameObjectManager* _goMan) override;

};

int main(int _argc, char* _argv[])
{
	return Application::Run<SampleGame>(_argv);
}

void SampleGame::Load(GameStateManager* _gsMan, GameObjectManager* _goMan)
{
}
