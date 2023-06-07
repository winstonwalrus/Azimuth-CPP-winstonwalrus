#include "Azimuth/Application.h"

#include <raylib/raylib.h>

#include "Azimuth/Config.h"
#include "Azimuth/Window.h"
#include "Azimuth/GameStates/GameStateManager.h"
#include "Azimuth/GameObjects/GameObjectManager.h"

#include "Azimuth/Resources/Resources.h"

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
	m_stateManager(nullptr), m_objectManager(nullptr), m_config(nullptr)
{
}

Application::~Application()
{
	if (m_game != nullptr)
	{
		delete m_game;
		m_game = nullptr;
	}

	if (m_stateManager != nullptr)
	{
		delete m_stateManager;
		m_stateManager = nullptr;
	}

	if (m_objectManager != nullptr)
	{
		delete m_objectManager;
		m_objectManager = nullptr;
	}

	if (Resources::m_instance != nullptr)
	{
		Resources::m_instance->Unload();
		delete Resources::m_instance;
		Resources::m_instance = nullptr;
	}

	if (m_config != nullptr)
	{
		delete m_config;
		m_config = nullptr;
	}
}

void Application::Init()
{
	m_window = new Window();
	m_objectManager = new GameObjectManager();
	m_stateManager = new GameStateManager();

	Resources::m_instance = new Resources();

	m_config = new Config("app");
}

void Application::Process()
{
	Init();

	m_window->Open();

	SetExitKey(*m_config->Get<int>("Program", "quitKey"));
	if (*m_config->Get<bool>("Program", "audioEnabled"))
		InitAudioDevice();

	Resources::m_instance->Load();

	m_game->Load(m_stateManager, m_objectManager);

	while (!m_shouldQuit)
	{
		float dt = GetFrameTime();

		m_game->Update(dt);
		m_objectManager->Update(dt);
		m_stateManager->Update(dt);

		m_window->BeginFrame();

		m_game->Draw();
		m_objectManager->Draw();
		m_stateManager->Draw();

		m_window->EndFrame();

		if (WindowShouldClose())
			m_shouldQuit = true;
	}

	m_game->Unload();

	if (*m_config->Get<bool>("Program", "audioEnabled"))
		CloseAudioDevice();

	m_window->Close();
}
