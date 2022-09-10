#include <iostream>
using namespace std;
#ifndef ROCKPAPERSCISSORS_GAME_H
#define ROCKPAPERSCISSORS_GAME_H
string ConvertAI(int rand_play);
void play_game(int argc, char *argv[],string value, string rand_result, string start);
string random_play(int argc, char* argv[]);
void replay_game(int argc, char *argv[], string exit, string start);
#endif //ROCKPAPERSCISSORS_GAME_H
