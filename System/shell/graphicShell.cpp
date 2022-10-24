#include "graphicShell.h"

#include <sstream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#include "../shell/colorShell.h"

// NOTE: the graphics chars, like \277, are octal values from the ASCII table
// NOTE: using the DOS: Occidental European Consolas font

void setCursorPos(int x, int y) {
    // Get the current console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Change the console cursor position
    COORD cursorPos;
    cursorPos.X = x;
    cursorPos.Y= y;

    // Set the new position
    SetConsoleCursorPosition(hConsole, cursorPos);
}

void drawWindow(int x, int y, int width, int height, std::string title, int bordersColor, int backgroundColor, int titleColor, int mainColor) {
    // Get the current console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int tx = (width / 2) - (title.length() / 2);

	// TODO: replace the octal references with getCharFrom(hex) references
	SetConsoleTextAttribute(hConsole, bordersColor); // Apply color to the horizontal borders
	for (int i = x; i < width + 1; i++) {
		setCursorPos(i, y); std::cout << "\304"; // Upper horizontal line
		setCursorPos(i, height); std::cout << "\304"; // Lower horizontal line
	}

	SetConsoleTextAttribute(hConsole, backgroundColor); // Apply color to the background
	for (int i = x; i < width + 1; i++) { // Fill the window background :)
		for (int j = y + 1; j < height; j++) { // + 1 for avoid overwrite the upper bars
			setCursorPos(i, j); std::cout << "\333";
		}
	}

	SetConsoleTextAttribute(hConsole, bordersColor); // Apply color to the vertical borders
	for (int i = y; i < height; i++) {
		setCursorPos(x, i); std::cout << "\263"; // Left vertical line
		setCursorPos(width, i); std::cout << "\263"; // Right vertical line
	}

	// Corners
	setCursorPos(x, y); std::cout << "\332";
	setCursorPos(x, height); std::cout << "\300";
	setCursorPos(width, y); std::cout << "\277";
	setCursorPos(width, height); std::cout << "\331";

	setCursorPos(tx, y); std::cout << "\264";
	SetConsoleTextAttribute(hConsole, titleColor);
	setCursorPos(tx + 1, y); std::cout << title;
	SetConsoleTextAttribute(hConsole, mainColor);
	setCursorPos(tx + title.length() + 1, y); std::cout << "\303";
}

void drawBar(int x, int y, int width, int height, int bordersColor, int backgroundColor, int mainColor) {
    // Get the current console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, bordersColor);
	for (int i = x; i < width; i++) {
		setCursorPos(i, y); std::cout << "\304"; // Upper horizontal line
		setCursorPos(i, height); std::cout << "\304"; // Lower horizontal line
	}

	SetConsoleTextAttribute(hConsole, backgroundColor);
	for (int i = x + 1; i < width; i++) {
		setCursorPos(i, y + 1); std::cout << "\333"; // fill all
	}

	SetConsoleTextAttribute(hConsole, bordersColor);
	for (int i = y; i < height; i++) {
		setCursorPos(x, i); std::cout << "\263"; // Left vertical line
		setCursorPos(width, i); std::cout << "\263"; // Right vertical line
	}

	setCursorPos(x, y); std::cout << "\332";
	setCursorPos(x, height); std::cout << "\300";
	setCursorPos(width, y); std::cout << "\277";
	setCursorPos(width, height); std::cout << "\331";

	SetConsoleTextAttribute(hConsole, mainColor);
}

void drawString(const std::string& str, int x, int y, int backgroundColor, int mainColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Clean the old text in the background
	SetConsoleTextAttribute(hConsole, backgroundColor);
	for (int i = x; i < str.length(); i++) {
		setCursorPos(i, y); std::cout << " ";
	}

	// Put the new text
	setCursorPos(x, y);
	std::cout << str;

	SetConsoleTextAttribute(hConsole, mainColor);
}

void drawDynamicString(const std::string& str, int x, int y, int backgroundColor, int mainColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, backgroundColor);

	// Put the new text
	setCursorPos(x, y);
	std::cout << str;

	// Clean the old text in the background
    for (int i = x; i < str.length(); i++) {
		setCursorPos(i, y); std::cout << " ";
	}

	SetConsoleTextAttribute(hConsole, mainColor);
}

void drawString(const std::string& str, int x, int y, int backgroundColor) {
	drawString(str, x, y, backgroundColor, NORMAL_NORMAL);
}

void drawString(const std::string& str, int x, int y) {
	drawString(str, x, y, NORMAL_NORMAL, NORMAL_NORMAL);
}

void print(const std::string& str, int x, int y) {
	setCursorPos(x, y);
	std::cout << str << std::endl;
}

std::string makeString(const std::string& str) {
    std::stringstream ss;
    ss << str;
    return ss.str();
}

bool isEqualString(std::string A, std::string B) {
    if (A.length() != B.length()) return false;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

void putChar(const char& chr, int x, int y, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << chr;
}

void putString(const std::string& chr, int x, int y, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << chr;
}
