#include <iostream>
using namespace std;
#ifndef ROCKPAPERSCISSORS_INPUTVALIDATION_H
#define ROCKPAPERSCISSORS_INPUTVALIDATION_H
string getValidChar(const std::string& prompt);
bool ValidInputs(string line);
bool ValidExit(string line);
string ConvertLower(string line);
string getValidChar2(const std::string& prompt, const std::string& replay);
#endif //ROCKPAPERSCISSORS_INPUTVALIDATION_H