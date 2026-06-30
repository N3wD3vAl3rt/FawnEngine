#include "Input.h"

#include <windows.h>

namespace Input
{
	void Update()
	{
		// Future keyboard, mouse, and controller updates will go here.
	}

	bool IsKeyDown(int virtualKey)
	{
		return (GetAsyncKeyState(virtualKey) & 0x8000) != 0;
	}
}