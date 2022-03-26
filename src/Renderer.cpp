#include "Renderer.h"

void Renderer::initialise(int boardSize, int screenWidth, int screenHeight) {
	auto screen = ftxui::ScreenInteractive::TerminalOutput();
	

	getTileSize(boardSize, screenWidth, screenHeight);

	std::vector<ftxui::Elements> rows;
	for(int x = 0; x < boardSize; x++) {
		std::vector<ftxui::Element> cols;
		for(int y = 0; y < boardSize; y++) {
			cols.push_back(make_box(boxWidth, boxHeight));
		}
		rows.push_back(cols);
	}

	grid = ftxui::gridbox(rows);
	container = ftxui::Component(ftxui::Renderer([&] {return grid;}));
	screen.Loop(container);
}

ftxui::Element Renderer::make_box(int w, int h) {
	return ftxui::dbox({
		ftxui::text("0") |
		ftxui::bgcolor(ftxui::Color::Cornsilk1) |
		ftxui::color(ftxui::Color::Black) |
		ftxui::center
	}) |
	ftxui::size(ftxui::WIDTH, ftxui::EQUAL, w) | 
	ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, h) |
	ftxui::bgcolor(ftxui::Color::DarkBlue) |
	ftxui::border;
}

void Renderer::render(Node** board) {
	ftxui::Render(screen, ftxui::vbox({
                   ftxui::text("idkanker"),
                   ftxui::separator(),
                   grid
               }));
	//screen.Print();
}


void Renderer::getTileSize(int boardSize, int w, int h) {
	const int whfactor = 2;

	h *= whfactor;
	if (w < h) {
		boxWidth = (w - padding) / boardSize;
		boxHeight = (w - padding) / boardSize / whfactor;
	} else {
		boxWidth = (h - (padding / whfactor)) / boardSize;
		boxHeight = (h - (padding / whfactor)) / whfactor / boardSize;
	}
}