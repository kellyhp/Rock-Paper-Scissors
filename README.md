##### Table of Contents  
* [General Info](#general-info)  
* [Technologies](#technologies) 
* [Setup](#setup)
   
## General Info
This project is a Rock Paper Scissors game where you are competing against a bot (random). If both players choose the same, they choose again until someone wins. Once the game ends, the player has an option to play again or exit.

## Technologies
Project is created with:
- CLion 2022.2.1 (can use any other IDE that is C++/C compatible)
- CMake (VERSION 3.15)
- CMAKE 11

## Setup 
To run this project, run any IDE for C/C++ and make sure CMake file has all of the files together. Any integer is applicable to write out in the runtime command line argument and it is optional. The integer will be used as a seed to the random number generator.


This is what my CMakeList.txt file looks like to incorporated all of the files together.
```
cmake_minimum_required(VERSION 3.15)
project(RockPaperScissors)

set(CMAKE_CXX_STANDARD 11)

add_executable(RockPaperScissors main.cpp game.cpp InputValidation.cpp game.h InputValidation.h)
target_compile_options(RockPaperScissors PRIVATE -Wall -Werror)

```
