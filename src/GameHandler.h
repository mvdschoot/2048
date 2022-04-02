#ifndef GAMEHANDLER_HEADER
#define GAMEHANDLER_HEADER

#include "ftxui/screen/screen.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/component.hpp"       // for Slider, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/event.hpp"

#include <iostream>
#include <vector>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "Board.h"
#include "Definitions.h"
#include "Designs.h"

class GameHandler {
public:
	static int grid_size;
	static int padding;
	static int box_width;
	static int box_height;

	GameHandler() {};

	void initialise(int grid_size);
	static ftxui::Element Render();
	void Start(ftxui::ScreenInteractive* screen);

	static bool input_callback(ftxui::Event event)
	
private:
	Board *board;
	static ftxui::Element grid;
	ftxui::Component container;

	void get_tile_size(int boardSize);
	static ftxui::Element make_box(int w, int h);
	static ftxui::Element make_grid();
	static ftxui::Element make_window(ftxui::Element gridbox);
};

#endif