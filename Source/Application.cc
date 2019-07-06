#include "../Header/Application.hpp"
#include <SDL2/SDL.h>

Application* Application::application = nullptr;
Application* Application::Intance()
{
	if (application == nullptr)
	{
		application = new Application();
	}
	return application;
}

Application::Application()
{
	try
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw application_exception(SDL_GetError());
		}
	}
	catch (application_exception& exception)
	{
		std::cout << "Application error: ";
		std::cout << exception.what() << std::endl;
	}
}

bool Application::Run()
{
	return active;
}

void Application::Stop()
{
	active = false;	
}

Application::~Application()
{
	SDL_Quit();
}
