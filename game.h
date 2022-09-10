#include <iostream>
using namespace std;
#ifndef ROCKPAPERSCISSORS_GAME_H
#define ROCKPAPERSCISSORS_GAME_H
int ConvertInput(string value);
void play_game(int argc, char *argv[],string value, int rand_result, string start);
int random_play(int argc, char* argv[]);
void replay_game(int argc, char *argv[], string exit, string start);
#endif //ROCKPAPERSCISSORS_GAME_H