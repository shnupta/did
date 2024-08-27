#include "options.hpp"

namespace Did::Components {

ftxui::CheckboxOption WrappedCheckboxOption()
{
  auto option = ftxui::CheckboxOption();
  option.transform = [](const ftxui::EntryState& s) {
#if defined(FTXUI_MICROSOFT_TERMINAL_FALLBACK)
    // Microsoft terminal do not use fonts able to render properly the default
    // radiobox glyph.
    auto prefix = ftxui::text(s.state ? "[X] " : "[ ] ");  // NOLINT
#else
    auto prefix = ftxui::text(s.state ? "▣ " : "☐ ");  // NOLINT
#endif
    auto t = ftxui::paragraph(s.label);
    if (s.active) {
      t |= ftxui::bold;
    }
    if (s.focused) {
      t |= ftxui::inverted;
    }
    return ftxui::hbox({prefix, t});
  };
  return option;
}

}
