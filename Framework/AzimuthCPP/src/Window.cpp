#include "Azimuth/Window.h"

#include "Azimuth/Config.h"

Window::Window()
	: m_config(new Config("window"))
{
	m_width = *m_config->Get<int>("Window", "width");
	m_height = *m_config->Get<int>("Window", "height");
	m_clearColor = *m_config->Get<Color>("Window", "clearColor");
	m_title = m_config->Get<string>("Window", "title")->c_str();
}

void Window::Open()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(m_width, m_height, m_title.c_str());
}

void Window::Close()
{
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
