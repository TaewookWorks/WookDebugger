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

	//�� ��ȸ�ϸ鼭 Program ��� ����.
	EnumWindows(StaticEnumWindowsProc, 0);

	//���� ã�Ҵٸ�?
	if (m_AppState->m_FoundTargetName)
	{
		//
	}


	m_AppState->m_TargetWindowName = "";
}

//ã���� ������ foundtargetname�� true�� �س���.
BOOL CALLBACK MainClass::StaticEnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	// â�� ���̰� / �۾� ǥ���ٿ� ����?
	if (IsWindowVisible(hWnd) && GetWindow(hWnd, GW_OWNER) == nullptr)
	{
		// ����Ʈ�� ������ Ÿ��Ʋ �߰�.
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