#ifndef SYSTEM_UTILS_CONSOLEUTILS_H_
#define SYSTEM_UTILS_CONSOLEUTILS_H_

#include <iostream>
#include <sstream>
#include <string.h>
#include <windows.h>
#include <winuser.h>

void setConsoleSize(int width, int height);
void setConsoleResizable(bool resizable);
void setConsolePosition(int x, int y);
void showConsoleCursor(bool showFlag);
void setConsoleFontSize(int fontSize);
std::string getConsoleMousePos();

#endif /* SYSTEM_UTILS_CONSOLEUTILS_H_ */

