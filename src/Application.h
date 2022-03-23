#pragma once

#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>
#include <string>
#include <Windows.h>
#include <exception>


#include "frame_rater.h"
#include "Board.h"
#include "Input.h"
#include "HelperFunctions.h"

class Application
{
public:
	Application() : board(nullptr), windowSize(getConsoleSize()) {};
	void run();
	void gameLoop();

private:
	const float FPS = 60.0f;
	COORD windowSize;

	Board *board;
	Input input;
	void initialise();
	int getBoardSize();
	void render();
	void windowResizeEvent();
};

