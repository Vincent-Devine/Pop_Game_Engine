#pragma once
#include "Core.hpp"

namespace Pop
{
	class POP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}