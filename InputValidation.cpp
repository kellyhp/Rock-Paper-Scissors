#include <iostream>
#include <string>
#include <algorithm>
#include "InputValidation.h"

string RemoveChar(string line) {
    std::string chars = "()";
    std::string s = line;
    for (char i: chars) {
        s.erase(std::remove(s.begin(), s.end(), i), s.end());
    }
    return s;
}
string ConvertLower(string line){
    string new_line;
    std::for_each(line.begin(), line.end(), [](char & c){
        c = ::tolower(c);
    });
    new_line = line;
    return new_line;
}

bool ValidInputs(string line) {
    if (line == "r" || line == "rock") {
        return true;
    }
    else if (line == "p" || line == "paper") {
        return true;
    }
    else if (line == "s" || line == "scissors") {
        return true;
    }
    else {
        return false;
    }
}

bool ValidExit(string line) {
    if (line == "y" || line == "yes") {
        line = "yes";
        return true;
    }
    else if (line == "n" || line == "no") {
        line = "no";
        return true;
    }
    else {
        return false;
    }
}

string getValidChar(const std::string& prompt) {
    std::string lineRead;
    std::string line;
    std::string new_line;
    bool readSuccessful = false;
    do{
        std::cout << prompt;
        std::getline(std::cin, lineRead); // grab the line
        line = RemoveChar(lineRead);
        new_line = ConvertLower(line);
        readSuccessful = ValidInputs(new_line);
    }while(!readSuccessful); //keep asking until they give me what I want
    return new_line;
}

string getValidChar2(const std::string& prompt, const std::string& replay) {
    std::string lineRead;
    std::string line;
    std::string new_line;
    bool readSuccessful = false;
    do{
        std::cout << replay << endl;
        std::cout << prompt;
        std::getline(std::cin, lineRead); // grab the line
        line = RemoveChar(lineRead);
        new_line = ConvertLower(line);
        readSuccessful = ValidExit(new_line);
    }while(!readSuccessful); //keep asking until they give me what I want
    return new_line;
}
