#include "tabbed_navigator.hpp"
#include <ftxui/component/component.hpp>

namespace Did::Components {

TabbedNavigatorBase::TabbedNavigatorBase(const std::vector<std::string>* names, ftxui::Components pages)
{
	auto menu_options = ftxui::MenuOption::Toggle();
	menu_options.underline.color_active = ftxui::Color::Green;

	auto tab_toggle = ftxui::Menu(names, &m_selected, std::move(menu_options));
	auto tab_pages = ftxui::Container::Tab(pages, &m_selected);
	auto layout = ftxui::Container::Vertical({
			tab_toggle,
			tab_pages
			});

	Add(ftxui::Renderer(layout, [=] {
			return ftxui::vbox({
					tab_toggle->Render(),
					ftxui::separator(),
					tab_pages->Render()
					});
			}));
}

ftxui::Component TabbedNavigator(const std::vector<std::string>* names, ftxui::Components pages)
{
	return ftxui::Make<TabbedNavigatorBase>(names, pages);
}

}
