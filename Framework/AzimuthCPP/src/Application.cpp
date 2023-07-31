#include "Azimuth/Application.h"

#include <raylib/raylib.h>

#include "Azimuth/Window.h"
#include "Azimuth/Utils/Config.h"
#include "Azimuth/Resources/Resources.h"

#include "Azimuth/GameStates/GameStateManager.h"
#include "Azimuth/GameObjects/GameObjectManager.h"


Application* Application::m_instance = nullptr;
bool Application::m_paused = false;

const char* Application::GetApplicationDirectory()
{
	return m_instance->m_applicationDir;
}

void Application::GetWindowSize(int& _width, int& _height)
{
	_width = m_instance->m_window->m_width;
	_height = m_instance->m_window->m_height;
}

Window* Application::GetWindow()
{
	return m_instance->m_window;
}

void Application::Pause()
{
	m_instance->m_paused = true;
}

void Application::Unpause()
{
	m_instance->m_paused = false;
}

void Application::SetPause(bool _b)
{
	m_instance->m_paused = _b;
}

void Application::SwitchPause()
{
	m_instance->m_paused = !m_instance->m_paused;
}

void Application::Quit()
{
	m_instance->m_shouldQuit = true;
}

Application::Application(Game* _game)
	: m_game(_game), m_applicationDir(nullptr), m_window(nullptr), m_shouldQuit(false),
	m_stateManager(nullptr), m_gameObjectManager(nullptr), m_appConfig(nullptr), m_debugConfig(nullptr)
{
}

Application::~Application()
{
	if (m_game != nullptr)
	{
		delete m_game;
		m_game = nullptr;
	}

	if (m_window != nullptr)
	{
		delete m_window;
		m_window = nullptr;
	}

	if (m_stateManager != nullptr)
	{
		delete m_stateManager;
		m_stateManager = nullptr;
	}

	if (m_gameObjectManager != nullptr)
	{
		delete m_gameObjectManager;
		m_gameObjectManager = nullptr;
	}

	if (m_appConfig != nullptr)
	{
		delete m_appConfig;
		m_appConfig = nullptr;
	}

	if (m_debugConfig != nullptr)
	{
		delete m_debugConfig;
		m_debugConfig = nullptr;
	}

	if (Resources::m_instance != nullptr)
	{
		delete Resources::m_instance;
		Resources::m_instance = nullptr;
	}
}

void Application::Init()
{
	m_window = new Window();

	m_stateManager = new GameStateManager();
	m_gameObjectManager = new GameObjectManager();

	m_debugConfig = new Config("debug");
	m_appConfig = new Config("app");

	m_window->Open(*m_appConfig->Get<int>("Application", "quitKey"));
	Resources::m_instance = new Resources();
	Resources::m_instance->Load();

	m_game->Load(m_stateManager, m_gameObjectManager);
}

void Application::Process()
{
	Init();

	while (!m_shouldQuit)
	{
		float dt = GetFrameTime();

		if (!m_paused)
		{
			m_game->Update(dt);

			m_stateManager->Update(dt);
			m_gameObjectManager->Update(dt);
		}

		m_window->BeginFrame();

		m_game->Draw();

		m_stateManager->Draw();
		m_gameObjectManager->Draw();
		m_stateManager->LateDraw();

		m_window->EndFrame();

		if (WindowShouldClose())
			m_shouldQuit = true;
	}

	Terminate();
}

void Application::Terminate()
{
	Resources::m_instance->Unload();

	m_game->Unload();
	m_window->Close();
}
