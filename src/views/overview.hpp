#pragma once

#include <ftxui/component/component_base.hpp>

namespace Did::Views {

class OverviewBase : public ftxui::ComponentBase
{
public:
	explicit OverviewBase();

private:
	int m_top_split_size = 10;
	int m_top_split_left_size = 50;

	int m_dropdown_selector = 0;

	std::vector<std::pair<std::string, bool>> m_due_today_state;
};

ftxui::Component Overview();

}
