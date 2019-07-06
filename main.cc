#include "Header/Application.hpp"

int main(int argc, char**argv)
{
	while (Application::Intance()->Run());
	return 0;
}
