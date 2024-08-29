#include "tasks.hpp"

#include <ftxui/component/component.hpp>
#include <ftxui/dom/table.hpp>

namespace Did::Views {

TasksBase::TasksBase()
{
	using namespace ftxui;


	std::shared_ptr<bool> selected1 = std::make_shared<bool>(false);
	auto option = ButtonOption::Ascii();
	option.label = "x";
	option.on_click = [=]() { 
		*selected1 = !*selected1; 
	};
	option.transform = [=](const EntryState& s) {
		std::string label = *selected1 ? "✓" : "x";
    const std::string t = s.focused ? "[" + label + "]"  //
                                    : " " + label + " ";
    return text(t);
	} ;
	auto button1 = Button(option);

	std::shared_ptr<bool> selected2 = std::make_shared<bool>(false);
	auto option2 = ButtonOption::Ascii();
	option2.label = "x";
	option2.on_click = [=]() { *selected2 = !*selected2; };
	option2.transform = [=](const EntryState& s) {
		std::string label = *selected2 ? "✓" : "x";
    const std::string t = s.focused ? "[" + label + "]"  //
                                    : " " + label + " ";
    return text(t);
	} ;
	auto button2 = Button(option2);

	auto buttons = Container::Vertical({button1, button2});

	auto renderer = Renderer(buttons, [=]() -> Element {
			std::vector<std::vector<Element>> rows;
			rows.push_back({text(" ID "), text(" Task ") | flex, text(" Labels "), text(" Actions ")});
			rows.push_back({text("0"), text("Some task that I need to do") | flex, text("HighPrio"), button1->Render()});
			rows.push_back({text("2"), text("This is another task") | flex, text("LowPrio"), button2->Render()});


			auto table = Table(rows);

			table.SelectRow(0).Decorate(bold);
			table.SelectRow(0).SeparatorVertical(LIGHT);
			table.SelectRow(0).BorderBottom(BorderStyle::DOUBLE);

			table.SelectColumns(0, -1).SeparatorVertical(LIGHT);

			table.SelectRows(1, -1).BorderBottom(BorderStyle::LIGHT);
			table.SelectRows(2, -1).BorderTop(BorderStyle::LIGHT);

			table.SelectRectangle(0, 0, 1, -1).DecorateCells(center);

			if (*selected1)
			{
				table.SelectRow(1).Decorate(color(Color::LightGreen));
			}
			if (*selected2)
			{
				table.SelectRow(2).Decorate(color(Color::LightGreen));
			}

			return table.Render();
	});

	Add(std::move(renderer));
}

ftxui::Component Tasks()
{
	return ftxui::Make<TasksBase>();
}

}
