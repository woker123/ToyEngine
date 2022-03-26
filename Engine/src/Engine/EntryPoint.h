#pragma once
#include "Application.h"
#include "Log.h"

/******************This header file will be used by client application*******************/

#ifdef TOY_PLATFORM_WINDOWS

extern Toy::Application* Toy::CreateApplication();

int main(int argc, char** argv)
{
	Toy::Log::Init();
	TOY_CORE_LOG_TRACE("Initialized Log");
	int num = 1;

	TOY_CORE_LOG_ERROR("Valu={0}", num);

	Toy::Application* app = Toy::CreateApplication();
	app->Run();
	delete app;
}

#endif