#ifndef BOARD_HEADER
#define BOARD_HEADER

#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <random>
#include <time.h>

#include "HelperFunctions.h"
#include "Definitions.h"

class Board
{
public:

	Board(int size) { init(size); }
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	// Getters
	int getSize() { return size; };
	Node **getBoard() { return board; };

private:
	Node **board;
	int size;
	const int padding = 5;

	void init(int size);
};

#endif