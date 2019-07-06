#pragma once
#include <iostream>
#include <exception>
#include <SDL2/SDL.h>

constexpr auto SDL_WINDOW_FLAG = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
constexpr auto SDL_RENDERER_FLAG = SDL_RENDERER_ACCELERATED;

struct window_exception : public std::runtime_error
{
	window_exception(const std::string& error) : std::runtime_error(error)
	{}
};

struct renderer_exception : public std::runtime_error
{
	renderer_exception(const std::string& error) : std::runtime_error(error)
	{}
};

struct Window
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	Window(const std::string& title, int width, int height);
	Window(const std::string& title, int x, int y, int width, int height);
	void InitRenderer();
	~Window();
};
