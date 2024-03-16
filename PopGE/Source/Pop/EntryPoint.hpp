#pragma once

#include "Application.hpp"

#ifdef POP_PLATFORM_WINDOWS

extern Pop::Application* Pop::CreateApplication();

int main(int argc, char** argv)
{
	Pop::Application* app = Pop::CreateApplication();
	app->Run();
	delete app;
}

#endif