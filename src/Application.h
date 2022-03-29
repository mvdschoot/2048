#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <exception>


#include "frame_rater.h"
#include "Board.h"
#include "Input.h"
#include "Renderer.h"
#include "HelperFunctions.h"
#include "Definitions.h"

#include "ftxui/screen/screen.hpp"

class Application
{
public:
	Application() : board(nullptr) {};
	~Application() {
		free(screen);
		free(board);
	};
	void run();

private:
	int board_size = -1;

	Board *board;
	Input input;
	Renderer renderer;
	ftxui::ScreenInteractive* screen;

	void initialise();
	int getBoardSize();
};

#endif