#include "../Header/Application.hpp"
#include <SDL2/SDL.h>
#include <GL/gl.h>

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
	active = true;
	try
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw application_exception(SDL_GetError());
		}
		else
		{
			window = new Window("OpenGL & SDL2", 400, 400);
		}
	}
	catch (application_exception& exception)
	{
		std::cout << "Application error: ";
		std::cout << exception.what() << std::endl;
	}
	catch (window_exception& exception)
	{
		std::cout << "Window error: ";
		std::cout << exception.what() << std::endl;
	}
	catch (glContext_exception& exception)
	{
		std::cout << "glContext error: ";
		std::cout << exception.what() << std::endl;
	}
}

bool Application::Run()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				this->Stop();
				break;
		}
	}
	window->Update();
	return active;
}

void Application::Stop()
{
	active = false;	
}

Application::~Application()
{
	delete window;
	SDL_Quit();
}
