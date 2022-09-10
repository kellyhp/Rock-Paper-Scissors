#include <iostream>
#include <string>
#include <random>
#include "game.h"
#include <chrono>
#include "InputValidation.h"

int ConvertInput(string value) {
    int User_plays;
    if (value == "r" || value == "rock" || value == "(r)ock") {
        User_plays = 0;
    }
    if (value == "p" || value == "paper" || value =="(p)aper") {
        User_plays = 1;
    }
    if (value == "s" || value == "scissors" || value == "(s)cissors") {
        User_plays = 2;
    }
    return User_plays;
}

int random_play(int argc, char* argv[]){
    unsigned int seed;
    int play;
    if(argc == 1) {
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
    else {
        seed = std::stoi(argv[1]);
    }
    std::minstd_rand generator(seed);
    std::uniform_int_distribution<int> range(0,2);
    play = range(generator);
    return play;
}

void play_game(int argc, char *argv[], string value, int rand_result, string start) {
    string new_value = value;
    int U_input = ConvertInput(new_value);
    if (rand_result == 1 && U_input == 1) {
        cout << "The ai played paper." << endl;
        cout << "You and the AI both played paper." << endl;
        cout << "Keep playing until someone wins." << endl;
        string value1 = getValidChar(start);
        int rand_result1 = random_play(argc, argv);
        play_game(argc, argv, value1, rand_result1, start);
    }
    if (rand_result == 0 && U_input == 0) {
        cout << "The ai played rock." << endl;
        cout << "You and the AI both played rock." << endl;
        cout << "Keep playing until someone wins." << endl;
        string value1 = getValidChar(start);
        int rand_result1 = random_play(argc, argv);
        play_game(argc, argv, value1, rand_result1, start);
    }
    if (rand_result == 2 && U_input == 2) {
        cout << "The ai played scissors." << endl;
        cout << "You and the AI both played scissors." << endl;
        cout << "Keep playing until someone wins." << endl;
        string value1 = getValidChar(start);
        int rand_result1 = random_play(argc, argv);
        play_game(argc, argv, value1, rand_result1, start);
    }
    if (U_input == 1 && rand_result == 0) {
        cout << "The ai played rock." << endl;
        cout << "You win!" << endl;
    }
    if (U_input == 1 && rand_result == 2) {
        cout << "The ai played scissors." << endl;
        cout << "The AI wins :(" << endl;
    }
    if (U_input == 0 && rand_result == 2) {
        cout << "The ai played scissors." << endl;
        cout << "You win!" << endl;
    }
    if (U_input == 0 && rand_result == 1) {
        cout << "The ai played paper." << endl;
        cout << "The AI wins :(" << endl;
    }
    if (U_input == 2 && rand_result == 1) {
        cout << "The ai played paper." << endl;
        cout << "You win!" << endl;
    }
    if (U_input == 2 && rand_result == 0) {
        cout << "The ai played rock." << endl;
        cout << "The AI wins :(" << endl;
    }
}

void replay_game(int argc, char *argv[], string leave, string start) {
    if (leave == "yes" || leave == "y" || leave == "(y)es") {
        string value = getValidChar(start);
        int rand_result = random_play(argc, argv);
        play_game(argc, argv, value, rand_result, start);
        string replay = "Would you like to replay the game?";
        string end = "Enter (Y)es or (N)o: ";
        string leave1 = getValidChar2(end, replay);
        replay_game(argc, argv, leave1, start);
    }
    else if (leave == "no" || leave == "n" || leave == "(n)o") {
        _Exit(0);
    }

}