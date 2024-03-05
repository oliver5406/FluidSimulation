cmake_minimum_required(VERSION 3.22)

project(FluidSimulationApp)

# Find the SFML library
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(FluidSimulationApp main.cpp)

# Link Directories
#target_link_directories(FluidSimulationApp PRIVATE ${CMAKE_SOURCE_DIR}/../libraries/build)

add_library(FluidSimulationLibrary SHARED IMPORTED)
set_target_properties(FluidSimulationLibrary PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../libraries/build/libFluidSimulationLibrary.a)

# Link Libraries
target_link_libraries(FluidSimulationApp sfml-system sfml-window sfml-graphics)
target_link_libraries(FluidSimulationApp FluidSimulationLibrary)

# CPack configuration
set(CPACK_GENERATOR "TBZ2")
set(CPACK_SOURCE_GENERATOR "TBZ2")
set(CPACK_PACKAGE_DIRECTORY ${PROJECT_BINARY_DIR}/package)
set(CPACK_SOURCE_IGNORE_FILES .git/ .github/ .vscode/ .mypy_cache/ _CPack_Packages/ ${CMAKE_BINARY_DIR}/ ${PROJECT_BINARY_DIR}/)
#set(CPACK_INSTALL_CMAKE_PROJECTS ${PROJECT_NAME} ${PROJECT_BINARY_DIR}
#    CMAKE_PROJECT_INCLUDE_COMPONENTS ALL
#    CMAKE_INSTALL_COMPONENT_ALL EXCLUDE_FROM_ALL
#)

#install(TARGETS FluidSimulationLibrary DESTINATION lib)

include(CPack)