#pragma once

#include <windows.h>

class Window
{
public:
	bool Create(HINSTANCE instance);
	void Show();

	HWND GetHandle() const;

private:
	HWND hwnd = nullptr;
};