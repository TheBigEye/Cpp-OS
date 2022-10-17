#ifndef SYSTEM_UTILS_CONSOLEUTILS_H_
#define SYSTEM_UTILS_CONSOLEUTILS_H_

#include <iostream>
#include <sstream>
#include <string.h>
#include <windows.h>
#include <winuser.h>

using namespace std;

void setConsoleSize(int width, int height);
void setConsoleResizable(bool resizable);
void setConsolePosition(int x, int y);
void setConsoleBlockCursor();
void showConsoleCursor(bool showFlag);
void setConsoleFontSize(int fontSize);
string getConsoleMousePos();
void showConsoleMouse(bool showFlag);

#endif /* SYSTEM_UTILS_CONSOLEUTILS_H_ */

