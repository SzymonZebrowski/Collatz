cmake_minimum_required(VERSION 3.9)
project(Collatz)

set(CMAKE_CXX_STANDARD 11)

add_executable(Collatz main.cpp AVLnode.cpp AVLnode.h List.cpp List.h ListNode.cpp ListNode.h)