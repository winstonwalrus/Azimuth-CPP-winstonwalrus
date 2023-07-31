#pragma once

#include "Azimuth/Azimuth.h"
#include "Azimuth/Game.h"

#include <string>

using std::string;

class Window;
class GameStateManager;
class GameObjectManager;
class Config;

class Application
{
public:
	template<Derived<Game> GAME>
	static int Run(char* _argv[]);

	DLL static const char* GetApplicationDirectory();
	DLL static void GetWindowSize(int& _width, int& _height);
	DLL static Window* GetWindow();

	DLL static void Pause() { m_instance->m_paused = true; };
	DLL static void Unpause() { m_instance->m_paused = false; };
	DLL static void SetPause(bool _b) { m_instance->m_paused = _b; };
	DLL static void SwitchPause() { m_instance->m_paused = !m_instance->m_paused; };

	DLL static void Quit();


private:
	DLL static Application* m_instance;

	bool m_paused;

	Game* m_game;
	const char* m_applicationDir;
	
	Window* m_window;
	Config* m_appConfig;
	Config* m_debugConfig;

	bool m_shouldQuit;

	GameStateManager* m_stateManager;
	GameObjectManager* m_gameObjectManager;

private:
	DLL Application(Game* _game);
	DLL ~Application();

	DLL void Init();
	DLL void Process();
	DLL void Terminate();

};

template<Derived<Game> GAME>
inline int Application::Run(char* _argv[])
{
	if (m_instance == nullptr)
	{
		const string argvStr = string(_argv[0]);
		const string appPath = argvStr.substr(0, argvStr.find_last_of("\\"));

		m_instance = new Application(new GAME());
		m_instance->m_applicationDir = appPath.c_str();
		m_instance->Process();

		return 0;
	}

	return -1;
}
