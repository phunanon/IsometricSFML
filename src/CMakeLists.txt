cmake_minimum_required(VERSION 3.7)

project(Jaunter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define sources and executable
set(EXECUTABLE_NAME Jaunter)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable(${EXECUTABLE_NAME} Main.cpp display/Display.cpp display/IsoEngine.cpp)

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

add_definitions("-g")
#add_definitions( "-Wall -m64 -O3" )

