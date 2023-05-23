#include "Application.h"

#include <raylib/raylib.h>

#include "Window.h"
#include "Utils/Config.h"

#include "GameStates/GameStateManager.h"
#include "GameObjects/GameObjectManager.h"

Application* Application::m_instance = nullptr;

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

void Application::Quit()
{
	m_instance->m_shouldQuit = true;
}

Application::Application(Game* _game)
	: m_game(_game), m_applicationDir(nullptr), m_window(nullptr), m_shouldQuit(false),
	m_stateManager(nullptr), m_gameObjectManager(nullptr)
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
}

void Application::Init()
{
	m_window = new Window();

	m_stateManager = new GameStateManager();
	m_gameObjectManager = new GameObjectManager();

	m_debugConfig = new Config("debug");
	m_appConfig = new Config("app");

	m_window->Open(*m_appConfig->Get<int>("Application", "quitKey"));
	m_game->Load(m_stateManager, m_gameObjectManager);
}

void Application::Process()
{
	Init();

	while (!m_shouldQuit)
	{
		float dt = GetFrameTime();

		m_game->Update(dt);

		m_stateManager->Update(dt);
		m_gameObjectManager->Update(dt);

		m_window->BeginFrame();

		m_game->Draw();

		m_stateManager->Draw();
		m_gameObjectManager->Draw();

		m_window->EndFrame();

		if (WindowShouldClose())
			m_shouldQuit = true;
	}

	Terminate();
}

void Application::Terminate()
{
	m_game->Unload();
	m_window->Close();
}
