#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>
#include <string>
#include <exception>


#include "frame_rater.h"
#include "Board.h"
#include "Input.h"
#include "Renderer.h"
#include "HelperFunctions.h"
#include "Definitions.h"

class Application
{
public:
	Application() : board(nullptr) {};
	void run();
	void gameLoop();

private:
	const float FPS = 60.0f;
	COORD windowSize;

	Board *board;
	Input input;
	Renderer renderer;

	void initialise();
	int getBoardSize();
	void render();
};

#endif