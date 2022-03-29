#include "Board.h"

void Board::moveRight()
{
}

void Board::moveLeft()
{
}

void Board::moveUp()
{
}

void Board::moveDown()
{
}


void Board::init(int size)
{
	this->size = size;
	board = (Node**)calloc(size, sizeof(Node*));
	for (int x = 0; x < size; x++) {
		board[x] = (Node*)calloc(size, sizeof(Node));
		for (int y = 0; y < size; y++) {
			board[x][y] = Node(0);
		}
	}

	srand(time(NULL));
	int x = floor((float)rand() / (float)RAND_MAX * (float)size);
	int y = floor((float)rand() / (float)RAND_MAX * (float)size);
	board[x][y].val = 2;

	x = floor(rand() / RAND_MAX * size);
	y = floor(rand() / RAND_MAX * size);
	board[x][y].val = 2;
}
