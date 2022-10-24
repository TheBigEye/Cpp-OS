#ifndef SYSTEM_SHELL_GRAPHICSHELL_H_
#define SYSTEM_SHELL_GRAPHICSHELL_H_

#include <iostream>

void setCursorPos(int x, int y);
void drawWindow(int x, int y, int width, int height, std::string title, int bordersColor, int backgroundColor, int titleColor, int mainColor);
void drawBar(int x, int y, int width, int height, int bordersColor, int backgroundColor, int mainColor);
void drawString(const std::string& str, int x, int y, int backgroundColor, int mainColor);
void drawString(const std::string& str, int x, int y, int backgroundColor);
void drawString(const std::string& str, int x, int y);
void drawDynamicString(const std::string& str, int x, int y, int backgroundColor, int mainColor);
std::string makeString(const std::string& str);
bool isEqualString(std::string A, std::string B);
void print(const std::string& str, int x, int y);
void putChar(const char& chr, int x, int y, int color);
void putString(const std::string& chr, int x, int y, int color);

#endif /* SYSTEM_SHELL_GRAPHICSHELL_H_ */
