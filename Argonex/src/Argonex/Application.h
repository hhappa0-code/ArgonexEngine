#pragma once

#include "Core.h"

namespace Argonex
{
	class ARGONEX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
