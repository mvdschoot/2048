#ifndef DEFINITIONS_HEADER
#define DEFINITIONS_HEADER


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