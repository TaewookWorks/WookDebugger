#pragma once
#include <windows.h>
#include <vector>
#include <iostream>
#include <string>
#include "AppState.h"


class MainClass
{
public:
	MainClass();
	~MainClass();

	void Initialize();
	void Loop();

private:


	//Win32�� Static ���
	static void SearchForSrc(std::string _windowTitle);
	static BOOL CALLBACK StaticEnumWindowsProc(HWND hWnd, LPARAM lParam);
	static AppState* m_AppState;
	
};

