#pragma once
#include "Application.h"

#ifdef OX_PLATFORM_WINDOWS

extern OX::Application* OX::CreateApplication();

int main(int argc, char** argv)
{
	OX::Application* app = OX::CreateApplication();
	app->Run();
	delete app;
}

#endif