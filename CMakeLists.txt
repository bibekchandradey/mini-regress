cmake_minimum_required(VERSION 3.25)
project(regress VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG        v2.4.1
)

FetchContent_MakeAvailable(CLI11)

add_executable(regress src/main.cpp)
target_link_libraries(regress PRIVATE CLI11::CLI11)
