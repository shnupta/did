file(GLOB_RECURSE headers *.hpp)
file(GLOB_RECURSE sources *.cpp)

add_library(didlib STATIC ${sources} ${headers})
target_link_libraries(didlib
	ftxui::screen
	ftxui::dom
	ftxui::component
	mastermyr::mastermyr
	)
target_include_directories(didlib PUBLIC .)
