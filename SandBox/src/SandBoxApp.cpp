#include "Engine.h"


class SandBoxApp : public OX::Application
{
public:
	SandBoxApp()
	{

	}
	virtual ~SandBoxApp() {}

	virtual void Run() override
	{
		while (true)
		{

		}
	}
};

OX::Application* OX::CreateApplication()
{
	return new SandBoxApp();
}