#include <iostream>
#include <chrono>
#include <vector>


#include "ftxui/screen/screen.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/component.hpp"       // for Slider, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/event.hpp"

volatile int count = 0;
long time = 0;
std::vector<ftxui::Element> boxes();

ftxui::Element make_box(int w, int h) {
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

ftxui::Element render() {
	long elapsed = std::chrono::system_clock::now() - time;
	if (elapsed >= 2000){
		for(auto it = boxes.begin(); it != boxes.end(); ++it) {
			(*it)
		}
	}
}

bool onEvent(ftxui::Event e) {
	// std::cout << "Event!!" << std::endl;
	count = 1000;
	return false;
}

int main(int argc, char** argv) {
	auto screen = ftxui::ScreenInteractive::TerminalOutput();

	std::vector<ftxui::Elements> rows;
	for(int x = 0; x < 5; x++) {
		std::vector<ftxui::Element> cols;
		for(int y = 0; y < 5; y++) {
			auto box = make_box(10, 5);
			cols.push_back(box);
		}
		rows.push_back(cols);
	}

	auto grid = ftxui::gridbox(rows);
	auto container = ftxui::Component(ftxui::Renderer(render));
	container = ftxui::CatchEvent(container, onEvent);

	time = std::chrono::system_clock::now();
	screen.Loop(container);
	
	return EXIT_SUCCESS;
}