#include "Board.h"

Node** Board::board = nullptr;
int Board::size = -1;
ftxui::Event* Board::event = nullptr;
bool Board::has_event_happened = false;

bool Board::input_callback(ftxui::Event evt)
{
	event = (ftxui::Event*)malloc(sizeof(evt));
	memcpy(event, &evt, sizeof(evt));
	has_event_happened = true;
	
	return true;
} 


void Board::moveRight()
{
	for (int x = 0; x < size; x++) {
		for(int y = size - 2; y >= 0; y--) {
			if (board[x][y].val == -1)
				continue;

			for(int i = y+1; i < size; i++) {
				if (board[x][i].val == -1) {
					continue;
				}

				if (board[x][y].val == board[x][i].val) {
					board[x][i].val *= 2;
					board[x][y].val = -1;
				} else {
					board[x][i-1].val = board[x][y].val;
					board[x][y].val = -1;
				}
				break;
			}
		}
	}
}

void Board::moveLeft()
{
	for (int x = 0; x < size; x++) {
		for(int y = 1; y < size; y++) {
			if (board[x][y].val == -1)
				continue;

			for(int i = y-1; i >= 0; i--) {
				if (board[x][i].val == -1) {
					continue;
				}

				if (board[x][y].val == board[x][i].val) {
					board[x][i].val *= 2;
					board[x][y].val = -1;
				} else {
					board[x][i+1].val = board[x][y].val;
					board[x][y].val = -1;
				}
				break;
			}
		}
	}
}

void Board::moveUp()
{
	for (int y = 0; y < size; y++) {
		for(int x = 1; x < size; x++) {
			if (board[x][y].val == -1)
				continue;

			for(int i = x-1; i >= 0; i--) {
				if (board[i][y].val == -1) {
					continue;
				}

				if (board[x][y].val == board[i][y].val) {
					board[x][y].val *= 2;
					board[i][y].val = -1;
				} else {
					board[x+1][y].val = board[i][y].val;
					board[i][y].val = -1;
				}
				break;
			}
		}
	}
}

void Board::moveDown()
{
	for (int y = 0; y < size; y++) {
		for(int x = size-2; x >= 0; x--) {
			if (board[x][y].val == -1)
				continue;

			for(int i = x; i < size; i++) {
				if (board[i][y].val == -1) {
					continue;
				}

				if (board[x][y].val == board[i][y].val) {
					board[i][y].val *= 2;
					board[x][y].val = -1;
				} else {
					board[i-1][y].val = board[x][y].val;
					board[x][y].val = -1;
				}
				break;
			}
		}
	}
}


Node** Board::update_and_return()
{
	if (has_event_happened == false)
		return board;
	
	std::string a = event->input();
	if (event->input().compare(std::string(ftxui::Event::ArrowDown)) == 0)
		moveDown();
	else if(*event == ftxui::Event::ArrowLeft)
		moveLeft();
	else if(*event == ftxui::Event::ArrowUp)
		moveUp();
	else if (*event == ftxui::Event::ArrowRight)
		moveRight();
	
	has_event_happened = false;

	return board;
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
