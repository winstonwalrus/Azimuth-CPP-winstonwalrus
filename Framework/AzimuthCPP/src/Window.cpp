#include "Azimuth/Window.h"

Window::Window()
	: m_width(800), m_height(600), m_title("Test"), m_clearColor({ 255, 255, 255, 255 })
{
}

void Window::Open()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(m_width, m_height, m_title.c_str());
	
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
