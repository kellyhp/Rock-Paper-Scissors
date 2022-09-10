#include <iostream>
#include "InputValidation.h"
#include "game.h"
using namespace std;

int main(int argc, char *argv[]) {
    string start = "Enter (R)ock, (P)aper, or (S)cissors for your move: ";
    string value = getValidChar(start);
    string rand_result = random_play(argc, argv);
    play_game(argc, argv, value, rand_result, start);
    string replay = "Would you like to replay the game?";
    string end = "Enter (Y)es or (N)o: ";
    string leave = getValidChar2(end, replay);
    replay_game(argc, argv, leave, start);
    return 0;
}
