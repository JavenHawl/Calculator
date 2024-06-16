cmake_minimum_required(VERSION 3.10)

project(opencv_test1)

find_package(OpenCV REQUIRED)

add_executable(opencv_test1 main.cpp show.cpp NHWC_to_NCHW.cpp)
target_link_libraries(opencv_test1 ${OpenCV_LIBS})