cmake_minimum_required(VERSION 3.14)
project(queue)

set(CMAKE_CXX_STANDARD 14)

#add_executable(queue main.cpp cmake-build-debug/queue.h task4-1.cpp task4-1.h) #для ручной прогонки
add_executable(queue cmake-build-debug/queue.h task4-1.cpp task4-1.h test.cpp) #для тетстов