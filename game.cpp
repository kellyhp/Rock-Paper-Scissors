#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include "game.h"
#include "InputValidation.h"

std::string ConvertAI(int rand_play) {
    std::string AI_plays;
    if (rand_play == 0) {
        AI_plays = "rock";
    }
    if (rand_play == 1) {
        AI_plays = "paper";
    }
    if(rand_play == 2) {
        AI_plays = "scissors";
    }
    return AI_plays;
}

std::string random_play(int argc, char* argv[]){
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
    std::string AI_plays = ConvertAI(play);
    return AI_plays;
}

void play_game(int argc, char *argv[], std::string value, std::string rand_result, std::string start) {
    if (rand_result == "paper" && (value == "p" || value == "paper")) {
        std::cout << "The ai played paper." << std::endl;
        std::cout << "You and the AI both played paper." << std::endl;
        std::cout << "Keep playing until someone wins." << std::endl;
        std::string value1 = getValidChar(start);
        std::string rand_result1 = random_play(argc, argv);
        play_game(argc, argv, value1, rand_result1, start);
    }
    if (rand_result == "rock" && (value == "r" || value == "rock")) {
        std::cout << "The ai played rock." << std::endl;
        std::cout << "You and the AI both played rock." << std::endl;
        std::cout << "Keep playing until someone wins." << std::endl;
        std::string value1 = getValidChar(start);
        std::string rand_result1 = random_play(argc, argv);
        play_game(argc, argv, value1, rand_result1, start);
    }
    if (rand_result == "scissors" && (value == "s" || value == "scissors")) {
        std::cout << "The ai played scissors." << std::endl;
        std::cout << "You and the AI both played scissors." << std::endl;
        std::cout << "Keep playing until someone wins." << std::endl;
        std::string value1 = getValidChar(start);
        std::string rand_result1 = random_play(argc, argv);
        play_game(argc, argv, value1, rand_result1, start);
    }
    if ((value == "paper" || value == "p") && rand_result == "rock") {
        std::cout << "The ai played rock." << std::endl;
        std::cout << "You win!" << std::endl;
    }
    if ((value == "paper" || value == "p") && rand_result == "scissors") {
        std::cout << "The ai played scissors." << std::endl;
        std::cout << "The AI wins :(" << std::endl;
    }
    if ((value == "rock" || value == "r") && rand_result == "scissors") {
        std::cout << "The ai played scissors." << std::endl;
        std::cout << "You win!" << std::endl;
    }
    if ((value == "rock" || value == "r") && rand_result == "paper") {
        std::cout << "The ai played paper." << std::endl;
        std::cout << "The AI wins :(" << std::endl;
    }
    if ((value == "scissors" || value == "s") && rand_result == "paper") {
        std::cout << "The ai played paper." << std::endl;
        std::cout << "You win!" << std::endl;
    }
    if ((value == "scissors" || value == "s") && rand_result == "rock") {
        std::cout << "The ai played rock." << std::endl;
        std::cout << "The AI wins :(" << std::endl;
    }
}

void replay_game(int argc, char *argv[], std::string leave, std::string start) {
    if (leave == "yes" || leave == "y") {
        std::string value = getValidChar(start);
        std::string rand_result = random_play(argc, argv);
        play_game(argc, argv, value, rand_result, start);
        std::string replay = "Would you like to replay the game?";
        std::string end = "Enter (Y)es or (N)o: ";
        std::string leave1 = getValidChar2(end, replay);
        replay_game(argc, argv, leave1, start);
    }
    else if (leave == "no" || leave == "n") {
        _Exit(0);
    }

}
