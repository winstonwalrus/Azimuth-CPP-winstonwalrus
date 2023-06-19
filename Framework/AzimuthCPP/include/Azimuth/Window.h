#pragma once

#include "Azimuth/Azimuth.h"

#include <raylib/raylib.h>

class Config;

class Config;

class Window
{
private:
	friend class Application;

	int m_width;
	int m_height;
	char* m_title;
	Color m_clearColor;

	Config* m_config;

private:
	DLL Window();
	Window(Window&) = delete;
	Window(Window&&) = delete;
	~Window() = default;

	DLL void Open(int _quitKey);
	DLL void Close();

	DLL void BeginFrame();
	DLL void EndFrame();

};

