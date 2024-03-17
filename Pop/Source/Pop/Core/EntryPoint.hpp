#pragma once

#include "Pop/Core/Application.hpp"
#include "Pop/Core/Log.hpp"

#ifdef POP_PLATFORM_WINDOWS

extern Pop::Core::Application* Pop::Core::CreateApplication();

int main(int argc, char** argv)
{
	Pop::Core::Log::OpenFile("log.txt");
	LOG("Test Info", Pop::LogLevel::Info);
	LOG("Test Validation", Pop::LogLevel::Validation);
	LOG("Test Warning", Pop::LogLevel::Warning);
	LOG("Test Critical", Pop::LogLevel::Critical);

	Pop::Core::Application* app = Pop::Core::CreateApplication();
	app->Run();
	delete app;

	Pop::Core::Log::CloseFile();
}

#endif