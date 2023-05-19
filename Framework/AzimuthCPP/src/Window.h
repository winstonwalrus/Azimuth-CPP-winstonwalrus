#pragma once

#include "Azimuth.h"

#include <raylib/raylib.h>

#include <string>

using std::string;

class Window
{
private:
	friend class Application;

	int m_width;
	int m_height;
	string m_title;
	Color m_clearColor;

private:
	DLL Window();
	Window(Window&) = delete;
	Window(Window&&) = delete;
	~Window() = default;

	DLL void Open();
	DLL void Close();

	DLL void BeginFrame();
	DLL void EndFrame();

};

