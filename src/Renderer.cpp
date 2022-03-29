#include "Designs.h"
#include "Renderer.h"

int Renderer::padding = 5;
int Renderer::grid_size = 0;
int Renderer::box_width = 0;
int Renderer::box_height = 0;


void Renderer::Start(ftxui::ScreenInteractive* screen)
{
	ftxui::ScreenInteractive::FitComponent().Loop(ftxui::Component(ftxui::Renderer([&](){return Renderer::Render();})));
	std::cout << "Failing!" << std::endl;
	exit(EXIT_FAILURE);
}

void Renderer::initialise(int grid_size)
{
	this->grid_size = grid_size;
	getTileSize(grid_size);
}



ftxui::Element Renderer::make_grid()
{
	std::vector<ftxui::Elements> rows;
	for (int x = 0; x < grid_size; x++)
	{
		std::vector<ftxui::Element> cols;
		for (int y = 0; y < grid_size; y++)
		{
			cols.push_back(Designs::GET_BOX_DESIGN("0", box_width, box_height));
		}
		rows.push_back(cols);
	}

	return ftxui::gridbox(rows);
}

ftxui::Element Renderer::make_window(ftxui::Element gridbox) 
{
	return Designs::GET_WINDOW_DESIGN(gridbox);
}

ftxui::Element Renderer::Render()
{
	return make_window(make_grid());
}

void Renderer::getTileSize(int grid_size)
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