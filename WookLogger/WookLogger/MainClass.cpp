#include "MainClass.h"

AppState* MainClass::m_AppState = nullptr;

MainClass::MainClass()
{

}

MainClass::~MainClass()
{

}

void MainClass::Initialize()
{
	m_AppState = new AppState();
	m_AppState->programState = eProgramState::INIT;

	
}

void MainClass::Loop()
{

}

void MainClass::SearchForSrc(std::string _windowTitle)
{
	m_AppState->m_TargetWindowName = _windowTitle;
	m_AppState->m_FoundTargetName = false;

	//쭉 순회하면서 Program 목록 보기.
	EnumWindows(StaticEnumWindowsProc, 0);

	//만약 찾았다면?
	if (m_AppState->m_FoundTargetName)
	{
		//
	}


	m_AppState->m_TargetWindowName = "";
}

//찾으면 무조건 foundtargetname을 true로 해놓음.
BOOL CALLBACK MainClass::StaticEnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	// 창이 보이고 / 작업 표시줄에 보임?
	if (IsWindowVisible(hWnd) && GetWindow(hWnd, GW_OWNER) == nullptr)
	{
		// 리스트에 윈도우 타이틀 추가.
		const int titleLength = GetWindowTextLength(hWnd);
		if (titleLength > 0)
		{
			std::vector<char> titleBuffer(titleLength + 1);
			GetWindowTextA(hWnd, titleBuffer.data(), titleLength + 1);

			if (titleBuffer.data() == m_AppState->m_TargetWindowName)
			{
				m_AppState->m_FoundTargetName = true;
			}
		}
	}

	return TRUE;
}