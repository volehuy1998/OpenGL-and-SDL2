#pragma once
#include <iostream>
#include <exception>
#include "Window.hpp"

class application_exception : public std::runtime_error
{
public:
	application_exception(const std::string& error) : 
		std::runtime_error(error) {}
};

struct Application
{
	static Application* application;
	static Application* Intance();

	Window* window;

	bool active;

	Application();
	bool Run();
	void Stop();
	~Application();
};
