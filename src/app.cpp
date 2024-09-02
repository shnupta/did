#include "app.hpp"
#include "views/main.hpp"

#include <iostream>
#include <mastermyr/runtime.hpp>
#include <mastermyr/alarm.hpp>
#include <mastermyr/time_span.hpp>

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/loop.hpp>

namespace Did {

using namespace std::chrono_literals;

void App::Run()
{
	myr::Runtime runtime;

	auto screen = ftxui::ScreenInteractive::Fullscreen();

	Models::Main main_model; // TODO: will load this from files first, then build the controller and pass that to the main view
	main_model.m_task.m_created_time = myr::DateTime<myr::TimeZone::UTC>::Now();
	std::cerr << main_model.m_task.m_created_time << std::endl;

	// myr::TimeSpan ts = 100ns;


	ftxui::Loop loop(&screen, Views::Main(main_model));

	myr::Alarm render_alarm(runtime, myr::AlarmType::Repeated);
	render_alarm.SetInterval(30ms);
	render_alarm.SetFunction([&] {
				if (loop.HasQuitted())
				{
					render_alarm.Cancel();
					return;
				}

				loop.RunOnce();
			});

	render_alarm.Restart();
	runtime.Start();
}

}
