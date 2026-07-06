cmake_minimum_required(VERSION 3.28)

project(tictactoe CXX)

add_executable(Tictactoe main.cpp Game.cpp)

target_compile_features(Tictactoe PRIVATE cxx_std_20)