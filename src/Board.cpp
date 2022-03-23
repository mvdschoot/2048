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


void Board::setFramework(COORD consoleSize)
{
	framework = std::vector<ConsoleCharacter>();

	// Alles wordt uitgedrukt in horizontale pixels tot op het renderen
	COORD fontInfo = getConsoleFont();
	float font_ratio = fontInfo.Y / fontInfo.X;


	COORD maxBoardSize;
	consoleSize.Y *= font_ratio;
	if (consoleSize.X < consoleSize.Y) {
		maxBoardSize = { (short)(consoleSize.X - (2*padding)), (short)(consoleSize.X / font_ratio - padding) };
	}
	else {
		maxBoardSize = { (short)(consoleSize.Y - (2*padding)), (short)(consoleSize.Y / font_ratio - padding )};
	}

	COORD boxSize = { maxBoardSize.X / size, maxBoardSize.Y / size };
	COORD position{ padding + 1, padding/2 + 1 };

	// HORIZONTALE LIJNEN
	for (int i = 0; i <= size; i++) {
		framework.push_back(ConsoleCharacter(position, std::string(maxBoardSize.X, '-')));
		position.Y += boxSize.Y;
	}

	// VERTICALE LIJNEN
	position = { (short)(padding + 1), (short)(padding/2 + 1) };
	for (int i = 0; i <= size; i++) {
		for (int x = 0; x <= maxBoardSize.Y; x++) {
			std::string c = x % boxSize.Y == 0 ? "+" : "|";
			framework.push_back(ConsoleCharacter(position, c));
			position.Y += 1;
		}

		position.X += boxSize.X;
		position.Y = padding/2 + 1;
	}

	// POSITIONS
	int index = 0;
	for (int y = 0; y < size; y++) {
		COORD pos{ padding + 1 + (boxSize.X / 2), padding + 1 + (boxSize.Y / 2) + boxSize.Y * y};
		for (int x = 0; x < size; x++) {
			framework.insert(framework.begin() + index++, ConsoleCharacter(pos, "0"));
			pos.X += boxSize.X;
		}
	}
}


std::vector<Board::ConsoleCharacter>* Board::getFramework()
{
	int index = 0;
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			framework.at(index++).character = std::to_string(board[x][y].val);
		}
	}

	return &framework;
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
