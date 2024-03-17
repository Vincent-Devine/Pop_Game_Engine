#include "Pop/Core/Application.hpp"
#include "Pop/Core/Log.hpp"
#include "Pop/Events/ApplicationEvent.hpp"

namespace Pop::Core
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		Event::WindowResizeEvent event(1920, 1080);
		LOG(event.ToString(), LogLevel::Info);
		// while (true);
	}
}