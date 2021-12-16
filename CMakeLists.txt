cmake_minimum_required(VERSION 3.10)

project(tictactoe VERSION 1.0)
#set(CMAKE_CXX_STANDRA 11)


add_executable(Tic_Tac_Toe-console main.cpp console.cpp)

target_compile_definitions(Tic_Tac_Toe-console PUBLIC _CRT_SECURE_NO_WARNINGS)