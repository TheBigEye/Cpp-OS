#ifndef SYSTEM_SHELL_GRAPHICSHELL_H_
#define SYSTEM_SHELL_GRAPHICSHELL_H_

#include <sstream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#include "../shell/colorShell.h"

using namespace std;

// NOTE: the graphics chars, like \277, are octal values from the ascii table
// NOTE: using the DOS: occidental european Consolas font

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
	
	int i = 0; int j = 0; 
	int tx = (width / 2) - (title.length() / 2);
	
	// TODO: replace the octal references with getCharFrom(hex) references
	
	SetConsoleTextAttribute(hConsole, bordersColor); // Apply color to the horizontal borders
	for (i = x; i < width + 1; i++) {
		setCursorPos(i, y); cout << "\304"; // Upper horizontal line
		setCursorPos(i, height); cout << "\304"; // Lower horizontal line
	}
	
	SetConsoleTextAttribute(hConsole, backgroundColor); // Apply color to the bakground
	for (i = x; i < width + 1; i++) { // Fill the window background :)
		for (j = y + 1; j < height; j++) { // + 1 for avoid overwrite the upper bars
			setCursorPos(i, j); cout << "\333";
		}
	}

	SetConsoleTextAttribute(hConsole, bordersColor); // Apply color to the vertical borders
	for (i = y; i < height; i++) {
		setCursorPos(x, i); cout << "\263"; // Left vertical line
		setCursorPos(width, i); cout << "\263"; // Right vertical line
	}

	// Corners
	setCursorPos(x, y); cout << "\332";
	setCursorPos(x, height); cout << "\300";
	setCursorPos(width, y); cout << "\277";
	setCursorPos(width, height); cout << "\331";

	setCursorPos(tx, y);
	SetConsoleTextAttribute(hConsole, titleColor);
	cout << "\264" + title + "\303";
	SetConsoleTextAttribute(hConsole, mainColor);
}

void drawBar(int x, int y, int width, int height, std::string title, int bordersColor, int backgroundColor, int titleColor, int mainColor) {
    // Get the current console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int i = 0; 
	int tx = (width / 2) - (title.length() / 2);
	
	SetConsoleTextAttribute(hConsole, bordersColor);
	for (i = x; i < width; i++) {
		setCursorPos(i, y); cout << "\304"; // Upper horizontal line
		setCursorPos(i, height); cout << "\304"; // Lower horizontal line
	}
	
	SetConsoleTextAttribute(hConsole, backgroundColor);
	for (i = x + 1; i < width; i++) {
		setCursorPos(i, y + 1); cout << "\333"; // fill all
	}

	SetConsoleTextAttribute(hConsole, bordersColor);	
	for (i = y; i < height; i++) {
		setCursorPos(x, i); cout << "\263"; // Left vertical line
		setCursorPos(width, i); cout << "\263"; // Right vertical line
	}

	setCursorPos(x, y); cout << "\332"; 
	setCursorPos(x, height); cout << "\300";
	setCursorPos(width, y); cout << "\277";
	setCursorPos(width, height); cout << "\331";

	setCursorPos(tx, y);
	if (title.length() < 1) {
		cout << "\304";
	} else {
		SetConsoleTextAttribute(hConsole, titleColor);
		cout << " " + title + " ";
	}

	SetConsoleTextAttribute(hConsole, mainColor);
}

void drawString(std::string str, int x, int y, int backgroundColor, int mainColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Clean the old text in the background
	SetConsoleTextAttribute(hConsole, backgroundColor);
	for (int i = x; i < str.length(); i++) {
		setCursorPos(i, y); cout << " ";
	}
	
	// Put the new text
	setCursorPos(x, y);
	cout << str;
	
	SetConsoleTextAttribute(hConsole, mainColor);
}

void drawString(string str, int x, int y, int backgroundColor) {
	drawString(str, x, y, backgroundColor, NORMAL_NORMAL);
}

void drawString(string str, int x, int y) {
	drawString(str, x, y, NORMAL_NORMAL, NORMAL_NORMAL);
}

template <typename Any>
void print(Any str, int x, int y) {
	setCursorPos(x, y);
	cout << str << endl;
}

void putChar(string c, int x, int y, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, color);
    cout << c;
}

#endif /* SYSTEM_SHELL_GRAPHICSHELL_H_ */
