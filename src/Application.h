#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <exception>


#include "GameHandler.h"
#include "Definitions.h"

#include "ftxui/screen/screen.hpp"

class Application
{
public:
	Application(){};
	~Application() {};
	void run();

private:
	int board_size = -1;

	GameHandler renderer;

	void initialise();
	int getBoardSize();
};

#endif