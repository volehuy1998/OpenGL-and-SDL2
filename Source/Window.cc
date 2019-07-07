#include "../Header/Window.hpp"
#include <GL/gl.h>


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
	glContext = SDL_GL_CreateContext(window); 
	if (glContext == nullptr)
	{
		throw glContext_exception(SDL_GetError());
	}
}

void Window::Update()
{
	glClearColor(0, 1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
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
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
}
