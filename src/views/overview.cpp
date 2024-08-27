#include "overview.hpp"

#include "components/options.hpp"

#include <ftxui/component/component.hpp>

namespace Did::Views {

OverviewBase::OverviewBase()
{
	m_due_today_state.push_back({"A task with a much longer title and more description", false});
	for (int i = 0; i < 20; ++i)
	{
		m_due_today_state.push_back({"Task " + std::to_string(i), false});
	}
	ftxui::Components checkboxes;
	for (auto& box : m_due_today_state)
		checkboxes.push_back(ftxui::Checkbox(box.first, &box.second, Components::WrappedCheckboxOption()));

	auto checkbox_container = ftxui::Container::Vertical(checkboxes);
	auto due_today = ftxui::Renderer(checkbox_container, [=] {
			return ftxui::window(ftxui::text("Due Today") | ftxui::color(ftxui::Color::Red),
					checkbox_container->Render()) | ftxui::vscroll_indicator  | ftxui::yframe;
			});

	auto open_task_counts = ftxui::Container::Vertical({
			ftxui::Renderer([] {
					return ftxui::paragraph("ldskjaf lkjsdfa lkdsjf ksd lskd lskdfjksjdnfl kjsdfkdf lksdlf kjds lkjdflksdjflksdfk lksdj klsjdf lskjdfsdlk j");
					}),
			ftxui::Renderer([] {
					return ftxui::paragraph("ldskjaf lkjsdfa lkdsjf ksd lskd lskdfjksjdnfl kjsdfkdf lksdlf kjds lkjdflksdjflksdfk lksdj klsjdf lskjdfsdlk j");
					})

			});
	auto top_panel = ftxui::ResizableSplitLeft(due_today, open_task_counts, &m_top_split_left_size);

	
	static const std::vector<std::string> es = {"all", "eq", "exeqt"};
	auto tag_filter = ftxui::Dropdown(&es, &m_dropdown_selector);
	auto filter_renderer = ftxui::Renderer(tag_filter, [=] {
			return ftxui::hbox({
					ftxui::window(ftxui::text("Tag Filter"), tag_filter->Render()), ftxui::filler()
					});
			});
	auto rest = ftxui::Container::Vertical({
			filter_renderer
			});

	Add(ftxui::Container::Vertical({
		ftxui::ResizableSplitTop(top_panel, rest, &m_top_split_size)
	}));
}

ftxui::Component Overview()
{
	return ftxui::Make<OverviewBase>();
}

}
