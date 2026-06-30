#include <Windows.h>
#include "Engine.h"
#include "Player.h"

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

	ShowWindow(hwnd, SW_SHOW);
	SetCapture(hwnd);
	ShowCursor(FALSE);

	// NOW safe to grab device context
	hdc = GetDC(hwnd);

	memoryDC = CreateCompatibleDC(hdc);

	BITMAPINFO bmi = {};
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = -height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	void* ptr = nullptr;

	bitmap = CreateDIBSection(
		hdc,
		&bmi,
		DIB_RGB_COLORS,
		&ptr,
		nullptr,
		0
	);

	if (!bitmap || !ptr)
		return false; // FIX: validate framebuffer

	SelectObject(memoryDC, bitmap);

	pixels = static_cast<unsigned int*>(ptr);

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

		Update();
		Render();

		Sleep(16); // ~60 FPS cap
	}

	return 0;
}

void Engine::ClearScreen(unsigned int color)
{
	for (int i = 0; i < width * height; i++)
	{
		pixels[i] = color;
	}
}

void Engine::DrawRect(int x, int y, int w, int h, unsigned int color)
{
	for (int py = 0; py < h; py++)
	{
		for (int px = 0; px < w; px++)
		{
			int drawX = x + px;
			int drawY = y + py;

			if (drawX >= 0 && drawX < width &&
				drawY >= 0 && drawY < height)
			{
				pixels[drawY * width + drawX] = color;
			}
		}
	}
}

void Engine::Update()
{
	// Temporary - game logic will go here
}

void Engine::Render()
{
	ClearScreen(0x00202020);

	DrawRect(
		static_cast<int>(playerX),
		static_cast<int>(playerY),
		10,
		10,
		0x0000FF00
	);

	BitBlt(
		hdc,
		0, 0,
		width,
		height,
		memoryDC,
		0, 0,
		SRCCOPY
	);
}

void Engine::Shutdown()
{
	// nothing yet
}

HWND Engine::GetWindowHandle() const
{
	return hwnd;
}