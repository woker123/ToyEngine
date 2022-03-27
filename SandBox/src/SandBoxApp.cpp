#include "Engine.h"


class SandBoxApp : public Toy::Application
{
public:
	SandBoxApp()
	{

	}
	virtual ~SandBoxApp() {}

	virtual void Run() override
	{
		Application::Run();
		while (true)
		{

		}
	}
};

Toy::Application* Toy::CreateApplication()
{
	return new SandBoxApp();
}