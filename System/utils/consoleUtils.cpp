#include "consoleUtils.h"

#include <iostream>
#include <sstream>
#include <string.h>
#include <windows.h>
#include <winuser.h>

using namespace std;

/**
 * Change the output console size.
 *
 * @param width The width that the window will have by characters.
 * @param height The height that the window will have by characters.
 */
void setConsoleSize(int width, int height) {
	stringstream ss;
	ss << "mode con cols=" << width << " " << "lines=" << height; // Modify the command string to insert the variables
	string s = ss.str(); // Convert all to string
	system(s.c_str()); // Run the command
}


/**
* Enable or disable the console window resizing property
*
* @param resizable Determines whether the window can be resizable or not.
*/
void setConsoleResizable(bool resizable) {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    if (resizable) {
        style |= WS_MAXIMIZEBOX; // Maximize button
        style |= WS_THICKFRAME;	// Mouse resizing
    } else {
        style &= ~WS_MAXIMIZEBOX;
        style &= ~WS_THICKFRAME;
    }
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}


/**
 * Change the output console position on the screen.
 *
 * @param x The x axis where the window will be placed.
 * @param y The y axis where the window will be placed.
 */
void setConsolePosition(int x, int y) {
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

/**
 * Show or hide the output console cursor.
 *
 * @param showFlag Determines whether the cursor is displayed or not.
 */
void showConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo); // Get the console cursor info
    cursorInfo.bVisible = showFlag; // Change the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo); // Apply the changes
}

/**
 * Changes the font size of the console (in turn this also changes the size of the window).
 *
 * @param FontSize The font size.
 */
void setConsoleFontSize(int fontSize) {
    CONSOLE_FONT_INFOEX cfi;

    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;  // Width of each character in the font
    cfi.dwFontSize.Y = fontSize; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int getConsoleMouseX() {
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(GetConsoleWindow(), &p);
    return int(p.x);
}

int getConsoleMouseY() {
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(GetConsoleWindow(), &p);
    return int(p.y);
}

/**
 * Get and return the current mouse position (x y) on the console screen.
 */
string getConsoleMousePos() {
    stringstream sh;
    sh << "x: " << getConsoleMouseX() << " y: " << getConsoleMouseY();
    string strMousePos = sh.str();
    return strMousePos;
}


