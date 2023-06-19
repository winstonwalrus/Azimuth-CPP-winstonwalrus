#include "Azimuth/Window.h"

#include "Azimuth/Utils/Config.h"

Window::Window()
	: m_config(new Config("window")), m_width(0), m_height(0), m_clearColor(), m_title(nullptr)
{
}

void Window::Open(int _quitKey)
{
	m_width = *m_config->Get<int>("Window", "width");
	m_height = *m_config->Get<int>("Window", "height");
	m_title = (char*)m_config->Get<string>("Window", "title")->c_str();
	m_clearColor = *m_config->Get<Color>("Window", "clearColor");

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetExitKey(_quitKey);

	InitWindow(m_width, m_height, m_title);
	
	InitAudioDevice();
}

void Window::Close()
{
	CloseAudioDevice();
	CloseWindow();
}

void Window::BeginFrame()
{
	BeginDrawing();
	ClearBackground(m_clearColor);

	m_width = GetScreenWidth();
	m_height = GetScreenHeight();
}

void Window::EndFrame()
{
	EndDrawing();
}
