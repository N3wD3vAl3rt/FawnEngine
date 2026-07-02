#pragma once
#include <Windows.h>

class Input
{
public:
	static void Update();
	static void UpdateMouse(HWND hwnd);

	static bool IsKeyDown(int key);
	static bool IsKeyPressed(int key);

	static int GetMouseDeltaX();
	static int GetMouseDeltaY();

private:
	static bool keys[256];
	static bool prevKeys[256];

	static int mouseX;
	static int mouseY;

	static int prevMouseX;
	static int prevMouseY;

	static int deltaX;
	static int deltaY;
};
