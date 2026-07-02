#include <Windows.h>
#include "Engine.h"
#include "Player.h"
#include "Input.h"
#include "Camera.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool Engine::Initialize()
{
	hInstance = GetModuleHandle(nullptr);

	const wchar_t CLASS_NAME[] = L"FawnWindowClass";

	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	if (!RegisterClass(&wc))
		return false;

	renderer.Initialize(hwnd, width, height);

	hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Fawn Engine",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1280, 720,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (!hwnd)
		return false; // FIX: validate BEFORE anything else

	ShowWindow(hwnd, SW_SHOW);
	SetCapture(hwnd);
	ShowCursor(FALSE);

	return true;
}

int Engine::Run()
{
	while (true)
	{
		MSG msg = {};

		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				return 0;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Tick();   // engine now delegates work here

		Sleep(16); // ~60 FPS cap
	}

	return 0;
}

void Engine::Tick()
{
	Input::Update();

	Update();
	Render();
}

void Engine::Update()
{
	Input::UpdateMouse(hwnd);
	player.Update();
	camera.Update({ player.GetX(), player.GetY() });
}

void Engine::Render()
{
	renderer.Clear(0x00202020);

	RenderWorld();
	RenderPlayer();

	renderer.Present();
}

void Engine::RenderWorld()
{
	// World will be managed by World/Entity system in v0.6.0
}

void Engine::RenderPlayer()
{
	Vector2 camPos = camera.GetPosition();

	int screenX = (int)(player.GetX() - camPos.x);
	int screenY = (int)(player.GetY() - camPos.y);

	renderer.DrawRect(screenX, screenY, 16, 16, 0x0000FFFF);
}

void Engine::Shutdown()
{
	// nothing yet
}

HWND Engine::GetWindowHandle() const
{
	return hwnd;
}
