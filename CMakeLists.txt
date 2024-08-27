cmake_minimum_required(VERSION 3.20)

project(did
	LANGUAGES CXX
	VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

add_subdirectory(x_mastermyr)

# libs
add_subdirectory(src)

# executable
add_subdirectory(did)
