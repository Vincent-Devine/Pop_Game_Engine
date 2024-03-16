#pragma once

#include "Application.hpp"
#include "Log.hpp"

#ifdef POP_PLATFORM_WINDOWS

extern Pop::Application* Pop::CreateApplication();

int main(int argc, char** argv)
{
	Pop::Core::Log::OpenFile("log.txt");
	LOG("Test Info", Pop::Core::LogLevel::Info);
	LOG("Test Validation", Pop::Core::LogLevel::Validation);
	LOG("Test Warning", Pop::Core::LogLevel::Warning);
	LOG("Test Critical", Pop::Core::LogLevel::Critical);

	Pop::Application* app = Pop::CreateApplication();
	app->Run();
	delete app;

	Pop::Core::Log::CloseFile();
}

#endif