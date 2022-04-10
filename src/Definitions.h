#ifndef DEFINITIONS_HEADER
#define DEFINITIONS_HEADER

#define _DEBUG

#include "ftxui/component/event.hpp"
typedef bool Input_callback(ftxui::Event event);

enum inputs{
	ARROW_RIGHT,
	ARROW_LEFT,
	ARROW_DOWN,
	ARROW_UP
};


#include <string>

typedef struct COORD {
	short X;
	short Y;
} COORD;

class ConsoleCharacter {
public:
	COORD coordinate;
	std::string character;

	ConsoleCharacter(COORD coord, std::string charac) { coordinate = coord; character = charac; }
};

class Node
{
public:
	int val;
	Node(int num = 1) : val(num) {}
};

#endif