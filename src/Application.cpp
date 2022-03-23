#include "Definitions.h"
#include "Application.h"

void Application::run()
{
	initialise();
	frame_rater<1> fp;
	for (;;) {
		gameLoop();
		fp.sleep();
	}
}

void Application::gameLoop()
{
	windowResizeEvent();

	render();
}


void Application::initialise()
{
	board = new Board(getBoardSize());
	
	board->setFramework(windowSize);
}

int Application::getBoardSize()
{
	std::cout << "How big board (2-6): ";
	char c;
	std::cin >> c;

	int size = 0;
	try {
		size = std::stoi(std::string(1, c));
		if (size < 2 || size > 6) {
			system("CLS");
			std::cout << "Bad size" << std::endl;
			size = getBoardSize();
		}
	}
	catch (std::exception& e) {
		system("CLS");
		std::cout << "Must be a number" << std::endl;
		size = getBoardSize();
	}

	return size;
}

void Application::render()
{
	system("CLS");
	HANDLE handl = GetStdHandle(STD_OUTPUT_HANDLE);

	std::vector<Board::ConsoleCharacter>* to_print = board->getFramework();
	for (auto it = to_print->begin(); it != to_print->end(); it++) {
		SetConsoleCursorPosition(handl, it->coordinate);
		std::cout << (it->character.c_str());
	}
}

void Application::windowResizeEvent()
{
	COORD sz = getConsoleSize();
	if (sz.X != windowSize.X || sz.Y != windowSize.Y) {
		board->setFramework(sz);
		windowSize = sz;
	}
}




