#ifndef RENDERER_HEADER
#define RENDERER_HEADER

#include "ftxui/screen/screen.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/component.hpp"       // for Slider, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/event.hpp"

#include <iostream>
#include <vector>

#include "Definitions.h"

class Renderer {
public:
	Renderer() {};

	void initialise(int boardSize, int screenWidth, int screenHeight);
	void render(Node** board);

private:

	//ftxui::ScreenInteractive* screen;
	ftxui::Element grid;
	ftxui::Component container;

	const int padding = 5;
	int boxWidth;
	int boxHeight;

	void getTileSize(int boardSize, int w, int h);
	ftxui::Element make_box(int w, int h);
};

#endif