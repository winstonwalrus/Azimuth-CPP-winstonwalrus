#include "Azimuth/Application.h"

#include <raylib/raylib.h>

#include "Azimuth/Window.h"

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
	: m_game(_game), m_applicationDir(nullptr), m_window(nullptr), m_shouldQuit(false)
{
}

Application::~Application()
{
	if (m_game != nullptr)
	{
		delete m_game;
		m_game = nullptr;
	}
}

void Application::Init()
{
	m_window = new Window();
}

void Application::Process()
{
	Init();

	m_window->Open();

	m_game->Load();

	while (!m_shouldQuit)
	{
		float dt = GetFrameTime();

		m_game->Update(dt);

		m_window->BeginFrame();

		m_game->Draw();

		m_window->EndFrame();

		if (WindowShouldClose())
			m_shouldQuit = true;
	}

	m_game->Unload();

	m_window->Close();
}
