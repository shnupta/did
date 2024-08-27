#pragma once

#include <ftxui/component/component_base.hpp>
#include <vector>

namespace Did::Components {

class TabbedNavigatorBase : public ftxui::ComponentBase
{
public:
	explicit TabbedNavigatorBase(const std::vector<std::string>*, ftxui::Components);

private:
	int m_selected = 0;
};

// Combination of a horizontal toggle navigator which controls the selection of passed in pages
ftxui::Component TabbedNavigator(const std::vector<std::string>* tab_names, ftxui::Components tab_pages);


}
