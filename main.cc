#include "Application.hpp"

int main(int, char**)
{
	while (Application::Intance()->Run());
	return 0;
}
