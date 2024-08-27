#include "main.hpp"
#include "components/tabbed_navigator.hpp"
#include "views/overview.hpp"

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

namespace Did::Views {

ftxui::Component Main(Did::States::Main& state)
{
	auto overview = Views::Overview();

	auto blah_page = ftxui::Container::Vertical({
			});

	static const std::vector<std::string> tab_names = {"Overview", "blah"};

	return Components::TabbedNavigator(&tab_names, {overview, blah_page}) | ftxui::Renderer(ftxui::border);
}

}
