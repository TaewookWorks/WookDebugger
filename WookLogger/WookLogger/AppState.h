#pragma once
#include <iostream>
#include <string>
#include "Util.h"

class AppState
{
public:
	AppState();
	~AppState();

	

	eProgramState programState = eProgramState::NONE;
	std::string m_TargetWindowName = "";
	bool m_FoundTargetName = false;
};

