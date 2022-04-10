#ifndef BOARD_HEADER
#define BOARD_HEADER

#include <stdlib.h>
#include <cstdlib>
#include <queue>
#include <string>
#include <string.h>
#include <random>
#include <time.h>

#include "Definitions.h"

class Board
{
public:

	Board(int size) { init(size); }
	void init(int size);

	static bool input_callback(ftxui::Event evt); 
	static void moveRight();
	static void moveLeft();
	static void moveUp();
	static void moveDown();

	// Getters
	int getSize() { return size; };
	static Node **update_and_return();
	static void add_tile();

	static Node **board;
	static int size;

	static std::queue<ftxui::Event> events;
};

#endif