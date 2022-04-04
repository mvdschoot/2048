#ifndef DESIGNS_HEADER
#define DESIGNS_HEADER

#include "ftxui/dom/elements.hpp"

#include <string>

class Designs {
public:
	static ftxui::Element GET_BOX_DESIGN(std::string text, int w, int h, ftxui::Color color) {
		return ftxui::dbox({ftxui::text(text) |
			ftxui::bgcolor(ftxui::Color::Cornsilk1) |
			ftxui::color(color) |
			ftxui::center}) |
		ftxui::size(ftxui::WIDTH, ftxui::EQUAL, w) |
		ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, h) |
		ftxui::bgcolor(ftxui::Color::DarkBlue) |
		ftxui::border;
	}	

	static ftxui::Element GET_WINDOW_DESIGN(ftxui::Element gridbox) {
		return ftxui::window(ftxui::text("2048"),
			gridbox
		);										
	}
};							

#endif