cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(USE_EXTERNAL_GLFW TRUE)

add_executable(untitled main.cpp include/entity.h include/player.h player.cpp enitity.cpp include/platform.h platform.cpp)
target_link_libraries(${PROJECT_NAME} raylib)
