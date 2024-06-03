cmake_minimum_required(VERSION 3.10)

project(calculator)



file(GLOB Calculator
"${PROJECT_SOURCE_DIR}/Calculator/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} main.cpp)









