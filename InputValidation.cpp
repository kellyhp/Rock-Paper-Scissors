#include <iostream>
#include <string>
#include <algorithm>
#include "InputValidation.h"

string ConvertLower(string line){
    std::string new_line;
    std::for_each(line.begin(), line.end(), [](char & c){
        c = ::tolower(c);
    });
    new_line = line;
    return new_line;
}

bool ValidInputs(string line) {
    if (line == "r" || line == "rock" || line == "(r)ock") {
        return true;
    }
    else if (line == "p" || line == "paper" || line =="(p)aper") {
        return true;
    }
    else if (line == "s" || line == "scissors" || line == "(s)cissors") {
        return true;
    }
    else {
        return false;
    }
}

bool ValidExit(string line) {
    if (line == "y" || line == "yes" || line == "(y)es") {
        return true;
    }
    else if (line == "n" || line == "no" || line == "(n)o") {
        return true;
    }
    else {
        return false;
    }
}

string getValidChar(const std::string& prompt) {
    std::string lineRead;
    std::string line;
    bool readSuccessful = false;
    do{
        std::cout << prompt;
        std::getline(std::cin, lineRead); // grab the line
        line = ConvertLower(lineRead);
        readSuccessful = ValidInputs(line);
    }while(!readSuccessful); //keep asking until they give me what I want
    return line;
}

string getValidChar2(const std::string& prompt, const std::string& replay) {
    std::string lineRead;
    std::string line;
    bool readSuccessful = false;
    do{
        std::cout << replay << endl;
        std::cout << prompt;
        std::getline(std::cin, lineRead); // grab the line
        line = ConvertLower(lineRead);
        readSuccessful = ValidExit(line);
    }while(!readSuccessful); //keep asking until they give me what I want
    return line;
}