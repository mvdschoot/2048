#include "Definitions.h"
#include "Application.h"

void Application::run()
{
	initialise();
	renderer.Start(screen);
}


void Application::initialise()
{
	board_size = getBoardSize();
	renderer.initialise(board_size);
	board = new Board(board_size);
}

int Application::getBoardSize()
{
	#ifdef _DEBUG
		return 5;
	#endif

	std::cout << "How big board (2-6): ";
	char c;
	std::cin >> c;

	int size = 0;
	try {
		size = std::stoi(std::string(1, c));
		if (size < 2 || size > 6) {
			std::cout << "Bad size" << std::endl;
			size = getBoardSize();
		}
	}
	catch (std::exception& e) {
		std::cout << "Must be a number" << std::endl;
		size = getBoardSize();
	}

	return size;
}




