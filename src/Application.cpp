#include "Definitions.h"
#include "Application.h"

void Application::run()
{
	initialise();
	frame_rater<1> fp;
	for (;;) {
		gameLoop();
		fp.sleep();
		break;
	}
}

void Application::gameLoop()
{

	renderer.render(board->getBoard());
}


void Application::initialise()
{
	board = new Board(getBoardSize());
	renderer.initialise(board->getSize(), 150, 50);
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





