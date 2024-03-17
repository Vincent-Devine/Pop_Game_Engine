#pragma once
#include "Pop/Core/Core.hpp"

namespace Pop::Core
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