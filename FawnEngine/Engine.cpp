#include <Windows.h>
#include "Engine.h"
#include "Player.h"
#include "Input.h"
#include "Camera.h"
#include "World.h"

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

	renderer.Initialize(hwnd, width, height);

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
	camera.Update(world.GetPlayerPosition());
	world.Update();
}

void Engine::Render()
{
	renderer.Clear(0x00202020);

	Vector2 camPos = camera.GetPosition();

	world.Render(camPos, renderer);

	renderer.Present();
}

void Engine::Shutdown()
{
	// nothing yet
}

HWND Engine::GetWindowHandle() const
{
	return hwnd;
}
