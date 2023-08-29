cmake_minimum_required(VERSION 3.0)
project(chapter3)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # important!
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

add_subdirectory(useEigen)
add_subdirectory(useGeometry)
add_subdirectory(examples)
add_subdirectory(visualizeGeometry)




