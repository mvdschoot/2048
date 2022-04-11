#include "Board.h"

Node** Board::board = nullptr;
int Board::size = 0;
std::queue<ftxui::Event> Board::events;

bool Board::input_callback(ftxui::Event evt)
{
	events.push(evt);	
	return true;
} 

void Board::add_tile() {
	std::vector<COORD> picks;
	for(int x = 0; x < size; x++) {
		for(int y = 0; y < size; y++) {
			if (board[x][y].val != 0) {
				continue;
			}
			picks.push_back(COORD{x, y});
		}
	}

	if(picks.empty()) {
		exit(EXIT_SUCCESS);
	}

	std::vector<COORD>::iterator it = picks.begin();
    std::random_device rd;
    std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, std::distance(it, picks.end()) - 1);
    std::advance(it, dis(gen));
	
	board[(*it).X][(*it).Y] = 2;
}

Node** Board::update_and_return()
{
	if (events.empty()) {
		return board;
	}

	ftxui::Event event = events.front();
	events.pop();

	if (event == ftxui::Event::ArrowDown)
		moveDown();
	else if(event == ftxui::Event::ArrowLeft)
		moveLeft();
	else if(event == ftxui::Event::ArrowUp)
		moveUp();
	else if (event == ftxui::Event::ArrowRight)
		moveRight();
	else
		return board;

	
	add_tile();
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


void Board::moveRight()
{
	for (int x = 0; x < size; x++) {
		for(int y = size - 1; y >= 0; y--) {
			if (board[x][y].val == 0)
				continue;

			for(int i = y+1; i < size; i++) {
				if (board[x][i].val == 0) {
					if (i == size - 1) {
						board[x][i].val = board[x][y].val;
						board[x][y].val = 0;
					} 
					continue;
				}

				if (board[x][y].val == board[x][i].val) {
					board[x][i].val *= 2;
					board[x][y].val = 0;
				} else {
					if (i-1 != y) {
						board[x][i-1].val = board[x][y].val;
						board[x][y].val = 0;
					}
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
			if (board[x][y].val == 0)
				continue;

			for(int i = y-1; i >= 0; i--) {
				if (board[x][i].val == 0) {
					if (i == 0) {
						board[x][i].val = board[x][y].val;
						board[x][y].val = 0;
					} 
					continue;
				}

				if (board[x][y].val == board[x][i].val) {
					board[x][i].val *= 2;
					board[x][y].val = 0;
				} else {
					if (i+1 != y) {
						board[x][i+1].val = board[x][y].val;
						board[x][y].val = 0;
					}
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
			if (board[x][y].val == 0)
				continue;

			for(int i = x-1; i >= 0; i--) {
				if (board[i][y].val == 0) {
					if (i == 0) {
						board[i][y].val = board[x][y].val;
						board[x][y].val = 0;
					} 
					continue;
				}

				if (board[x][y].val == board[i][y].val) {
					board[i][y].val *= 2;
					board[x][y].val = 0;
				} else {
					if (i+1 != x) {
						board[i+1][y].val = board[x][y].val;
						board[x][y].val = 0;
					}
				}
				break;
			}
		}
	}
}

void Board::moveDown()
{
	for (int y = 0; y < size; y++) {
		for(int x = size-1; x >= 0; x--) {
			if (board[x][y].val == 0)
				continue;

			for(int i = x+1; i < size; i++) {
				if (board[i][y].val == 0) {
					if (i == size - 1) {
						board[i][y].val = board[x][y].val;
						board[x][y].val = 0;
					} 
					continue;
				}

				if (board[x][y].val == board[i][y].val) {
					board[i][y].val *= 2;
					board[x][y].val = 0;
				} else {
					if (i-1 != x) {
						board[i-1][y].val = board[x][y].val;
						board[x][y].val = 0;
					}
				}
				break;
			}
		}
	}
}