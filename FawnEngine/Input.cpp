#include "Input.h"
#include <Windows.h>

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

bool Input::IsKeyDown(int key)
{
	return keys[key];
}

bool Input::IsKeyPressed(int key)
{
	return keys[key] && !prevKeys[key];
}