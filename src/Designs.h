#ifndef DESIGNS_HEADER
#define DESIGNS_HEADER

#include "ftxui/dom/elements.hpp"

#include <string>
#include <map>
#include "ftxui/screen/color.hpp"

class Designs {
public:
	static ftxui::Element GET_BOX_DESIGN(int value, int w, int h) {
		return ftxui::dbox({ftxui::text(std::to_string(value)) |
			ftxui::bgcolor(color_mapping.at(value)) |
			ftxui::color(ftxui::Color::Black) |
			ftxui::center}) |
		ftxui::size(ftxui::WIDTH, ftxui::EQUAL, w) |
		ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, h) |
		ftxui::bgcolor(color_mapping.at(value)) |
		ftxui::border;
	}	

	static ftxui::Element GET_WINDOW_DESIGN(ftxui::Element gridbox) {
		return ftxui::window(ftxui::text("2048"),
			gridbox
		);										
	}

	static std::map<int, ftxui::Color> color_mapping;
};	

#endif