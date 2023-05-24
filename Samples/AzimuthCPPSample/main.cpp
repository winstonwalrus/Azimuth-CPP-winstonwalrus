#include <Azimuth/Application.h>
#include <Azimuth/Game.h>

class SampleGame : public Game
{
protected:
	void Load() override;

};

int main(int _argc, char* _argv[])
{
	return Application::Run<SampleGame>(_argv);
}

void SampleGame::Load()
{
}
