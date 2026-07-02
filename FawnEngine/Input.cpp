#include "Input.h"
#include <Windows.h>

int Input::mouseX = 0;
int Input::mouseY = 0;

int Input::prevMouseX = 0;
int Input::prevMouseY = 0;

int Input::deltaX = 0;
int Input::deltaY = 0;

bool Input::keys[256] = {};
bool Input::prevKeys[256] = {};

void Input::Update()
{
	for (int i = 0; i < 256; i++)
	{
		prevKeys[i] = keys[i];
		keys[i] = (GetAsyncKeyState(i) & 0x8000);
	}
}

void Input::UpdateMouse(HWND hwnd)
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(hwnd, &p);

	prevMouseX = mouseX;
	prevMouseY = mouseY;

	mouseX = p.x;
	mouseY = p.y;

	deltaX = mouseX - prevMouseX;
	deltaY = mouseY - prevMouseY;
}

bool Input::IsKeyDown(int key)
{
	return keys[key];
}

bool Input::IsKeyPressed(int key)
{
	return keys[key] && !prevKeys[key];
}

int Input::GetMouseDeltaX()
{
	return deltaX;
}

int Input::GetMouseDeltaY()
{
	return deltaY;
}