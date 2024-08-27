#include "app.hpp"
#include "views/main.hpp"

#include <mastermyr/runtime.hpp>
#include <mastermyr/alarm.hpp>

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/loop.hpp>

namespace Did {

using namespace std::chrono_literals;

void App::Run()
{
	myr::Runtime runtime;

	auto screen = ftxui::ScreenInteractive::Fullscreen();

	States::Main state;
	ftxui::Loop loop(&screen, Views::Main(state));

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
