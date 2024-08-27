#pragma once

#include "states/main.hpp"

#include <ftxui/component/component.hpp>

namespace Did::Views {

// Main view holding all subviews
ftxui::Component Main(Did::States::Main&);

}
