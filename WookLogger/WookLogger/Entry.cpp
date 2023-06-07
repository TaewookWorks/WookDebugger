// WookLogger.cpp : Defines the entry point for the application.
//
/// Winmain ����Ʈ (���¿�)
#include "framework.h"
#include "WookLogger.h"
#include "MainIncludes.h"

#define MAX_LOADSTRING 100

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// ���α׷��� ���� ������(Entry Point). ��Ƽ����Ʈ ������Ʈ
int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR	  lpCmdLine,
	_In_ int		  nCmdShow)
{
	char	  szAppName[] = "Wook Debugger";
	HWND	  hWnd;
	MSG      msg;
	WNDCLASS wndclass;

	LPCWSTR appName = L"Wook Debugger";

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = L"Wook Debugger";

	/// ���� Ŭ���� ���
	RegisterClass(&wndclass);

	/// ���� ����
	hWnd = CreateWindow(wndclass.lpszClassName,
		appName,
		WS_OVERLAPPEDWINDOW,
		100, 100, 800, 600,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	/// ������ ������ ȭ�鿡 ǥ��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MainClass* mainClass = new MainClass();
	mainClass->Initialize();


	/// �޽��� ����
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else
		{
			//Sleep(10);
			mainClass->Loop();
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}





	return 0;
}



