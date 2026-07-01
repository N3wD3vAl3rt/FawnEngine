#pragma once

class Input
{
public:
	static void Update();

	static bool IsKeyDown(int key);
	static bool IsKeyPressed(int key);

private:
	static bool keys[256];
	static bool prevKeys[256];
};
