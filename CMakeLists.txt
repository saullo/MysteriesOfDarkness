cmake_minimum_required(VERSION 3.22)
project(MysteriesOfDarkness)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_subdirectory(Editor)
add_subdirectory(Vendors)
add_subdirectory(Engine)