cmake_minimum_required(VERSION 3.28)

project(tictactoe CXX)

add_executable(Tictactoe main.cpp TicTacToe.cpp Player.cpp Board.cpp) 

target_compile_features(Tictactoe PRIVATE cxx_std_20)