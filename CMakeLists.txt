cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 14)
project( faceswap )

find_package(dlib REQUIRED)
#include_directories(${dlib_INCLUDE_DIRS})
#target_link_libraries(your_app dlib::dlib)

find_package( OpenCV REQUIRED )

file(GLOB SRC *.cpp *.h)

add_executable( faceswap ${SRC})
target_link_libraries( faceswap dlib::dlib ${OpenCV_LIBS})
