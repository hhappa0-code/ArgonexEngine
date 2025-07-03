#pragma once

#ifdef ARGONEX_PLATFORM_WINDOWS

extern Argonex::Application* Argonex::CreateApplication();
	
int main(int argc, char** argv)
{
	auto application = Argonex::CreateApplication();

	application->Run();

	delete application;

	return 0;
}

#endif