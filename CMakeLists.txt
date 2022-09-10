cmake_minimum_required(VERSION 3.15)
project(RockPaperScissors)

set(CMAKE_CXX_STANDARD 11)

add_executable(RockPaperScissors main.cpp game.cpp InputValidation.cpp game.h InputValidation.h)
target_compile_options(RockPaperScissors PRIVATE -Wall -Werror)
