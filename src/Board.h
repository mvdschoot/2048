#pragma once

#include <stdlib.h>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <string>
#include <random>
#include <time.h>

#include "HelperFunctions.h"

class Board
{
public:
	class Node {
	public:
		int val;
		Node(int num = 1) : val(num) {}
	};
	class ConsoleCharacter {
	public:
		ConsoleCharacter(COORD coord, std::string charac) { coordinate = coord; character = charac; }
		COORD coordinate;
		std::string character;
	};

	Board(int size) { init(size); }
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	void setFramework(COORD consoleSize);

	// Getters
	int getSize() { return size; };
	Node** getBoard() { return board; };
	std::vector<ConsoleCharacter>* getFramework();


private:
	Node** board;
	int size;
	const int padding = 5;

	std::vector<ConsoleCharacter> framework;

	void init(int size);
};