cmake_minimum_required(VERSION 3.29)
project(TicTacToeC)

set(CMAKE_CXX_STANDARD 20)

set(JAVA_HOME "C:\\Users\\narbo\\.jdks\\openjdk-23.0.1")
include_directories(${JAVA_HOME}/include)
include_directories(${JAVA_HOME}/include/win32)

add_library(TicTacToeC SHARED
        JNImethods.h
        JNImethods.cpp
        Board.cpp
        Board.h)

target_link_options(TicTacToeC PRIVATE -static)