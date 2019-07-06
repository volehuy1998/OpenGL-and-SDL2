#include "../Header/Window.hpp"


Window::Window(const std::string& title, int width, int height)
{
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FLAG);
	if (window == nullptr)
	{
		throw window_exception(SDL_GetError());
	}
	else
	{
		this->InitRenderer();
	}
}

void Window::InitRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_FLAG); 
	if (renderer == nullptr)
	{
		throw renderer_exception(SDL_GetError());
	}
}

Window::Window(const std::string& title, int x, int y, int width, int height)
{
	window = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_FLAG);
	if (window == nullptr)
	{
		throw window_exception(SDL_GetError());
	}
	else
	{
		this->InitRenderer();
	}
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
