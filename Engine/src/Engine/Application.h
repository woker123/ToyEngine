#pragma once
#include "Core.h"

namespace Toy
{
	class TOY_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	Application* CreateApplication();
}



