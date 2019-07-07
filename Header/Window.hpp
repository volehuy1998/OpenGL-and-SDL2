#pragma once
#include <iostream>
#include <exception>
#include <SDL2/SDL.h>

constexpr auto SDL_WINDOW_FLAG = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

struct window_exception : public std::runtime_error
{
	window_exception(const std::string& error) : std::runtime_error(error)
	{}
};

struct glContext_exception : public std::runtime_error
{
	glContext_exception(const std::string& error) : std::runtime_error(error)
	{}
};

struct Window
{
	SDL_Window* window;
	SDL_GLContext glContext;

	Window(const std::string& title, int width, int height);
	Window(const std::string& title, int x, int y, int width, int height);
	void InitRenderer();
	void Update();
	~Window();
};
