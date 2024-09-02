#include "main.hpp"
#include "components/tabbed_navigator.hpp"
#include "views/overview.hpp"
#include "views/tasks.hpp"

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

namespace Did::Views {

ftxui::Component Main(Did::Models::Main& main_model)
{
	auto tasks = Views::Tasks();
	auto overview = Views::Overview();

	auto history = ftxui::Container::Vertical({
			});

	// TODO: the overview page will have pretty much a long list of tasks
	// figure out what tagging and metadata I want to associate with a task
	//
	// The history page will have a calendar which you can select any number of days
	// (and maybe weeks + months at a time) and it will then display the completed tasks
	// and some information about them like days open etc
	static const std::vector<std::string> tab_names = {"Tasks", "Overview", "History"};

	return Components::TabbedNavigator(&tab_names, {tasks, overview, history}) | ftxui::Renderer(ftxui::border);
}

}
