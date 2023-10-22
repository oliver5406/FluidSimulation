cmake_minimum_required(VERSION 3.22)

project(FluidSimulationApp)

# Find the SFML library
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(FluidSimulationApp main.cpp)

# Link Directories
target_link_directories(FluidSimulationApp PRIVATE ${CMAKE_SOURCE_DIR}/../libraries/build)

# Link Libraries
target_link_libraries(FluidSimulationApp sfml-system sfml-window sfml-graphics)
target_link_libraries(FluidSimulationApp FluidSimulationLibrary)
