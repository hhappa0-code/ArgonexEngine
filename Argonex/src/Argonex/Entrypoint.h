#pragma once

#include "Log.h"

#ifdef ARGONEX_PLATFORM_WINDOWS

extern Argonex::Application* Argonex::CreateApplication();
	
int main(int argc, char** argv)
{
	Argonex::Log::Init();
	ARGONEX_CORE_INFO("Initialized Logger.");

	auto application = Argonex::CreateApplication();

	application->Run();

	delete application;

	return 0;
}

#endif