#include "GameHandler.h"
#include "Designs.h"

int GameHandler::padding = 5;
int GameHandler::grid_size = 0;
int GameHandler::box_width = 0;
int GameHandler::box_height = 0;


void GameHandler::Start()
{
	ftxui::Component component = ftxui::Component(ftxui::Renderer([&](){return GameHandler::Render();}));
	
	component = ftxui::CatchEvent(component, Board::input_callback);
	
	ftxui::ScreenInteractive::FitComponent().Loop(component);
	std::cout << "Exiting..." << std::endl;
	exit(EXIT_SUCCESS);
}

void GameHandler::initialise(int grid_size)
{
	this->grid_size = grid_size;
	board_class = new Board(grid_size);
	get_tile_size(grid_size);
}


ftxui::Element GameHandler::make_grid()
{
	Node** board = Board::update_and_return();
	std::vector<ftxui::Elements> rows;
	for (int x = 0; x < grid_size; x++)
	{
		std::vector<ftxui::Element> cols;
		for (int y = 0; y < grid_size; y++)
		{
			cols.push_back(
				Designs::GET_BOX_DESIGN(
					std::to_string(board[x][y].val), 
					box_width, 
					box_height,
					ftxui::Color::Black
				)
			);
		}
		rows.push_back(cols);
	}

	return ftxui::gridbox(rows);
}

ftxui::Element GameHandler::make_window(ftxui::Element gridbox) 
{
	return Designs::GET_WINDOW_DESIGN(gridbox);
}

ftxui::Element GameHandler::Render()
{
	return make_window(make_grid());
}

void GameHandler::get_tile_size(int grid_size)
{
	struct winsize c;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &c);

	short w = c.ws_col;
	short h = c.ws_row;

	short whfactor = 2;
	h *= whfactor;
	if (w < h)
	{
		box_width = (w - padding) / grid_size;
		box_height = (w - padding) / grid_size / whfactor;
	}
	else
	{
		box_width = (h - (padding / whfactor)) / grid_size;
		box_height = (h - (padding / whfactor)) / whfactor / grid_size;
	}
}