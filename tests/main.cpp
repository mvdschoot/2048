#include <iostream>
#include <chrono>
#include <vector>


#include "ftxui/screen/screen.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/component.hpp"       // for Slider, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/event.hpp"

std::string print;

bool onEvent(ftxui::Event event) {
	print = std::to_string(event.ArrowDown);
	return true;
}

int main(int argc, char** argv) {
	auto screen = ftxui::ScreenInteractive::TerminalOutput();

	ftxui::Component container = ftxui::Component(ftxui::Renderer([&] {return ftxui::vbox(ftxui::text(print));}));
	container = ftxui::CatchEvent(container, onEvent);

	screen.Loop(container);
	
	return EXIT_SUCCESS;
}