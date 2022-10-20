#ifndef SYSTEM_SHELL_SCREENSHELL_H_
#define SYSTEM_SHELL_SCREENSHELL_H_

#include <iostream>

std::string toLowercase(std::string str);
std::string toUppercase(std::string str);
char getCharFrom(int hex);
char getCharFrom(std::string oct);
bool startsWith(std::string str, std::string start);
std::string replace(std::string str, std::string oldWord, const std::string &newWord);
void clearScreen();

#endif /* SYSTEM_SHELL_SCREENSHELL_H_ */

