#ifndef SYSTEM_CORE_MAINRENDER_H_
#define SYSTEM_CORE_MAINRENDER_H_

#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>

#include <algorithm>
#include <sstream>

#include "../shell/colorShell.h"
#include "../shell/screenShell.h"
#include "../shell/graphicShell.h"
#include "../shell/imageShell.h"
#include "../utils/consoleUtils.h"
#include "../utils/systemUtils.h"
#include "../utils/networkUtils.h"
#include "../utils/timeUtils.h"

using namespace std;

const string PROMPT = "OS C:\\>";

// Console window dimensions
const int WIDTH = 128;
const int HEIGHT = 34;

int currentLine = 2;

// ----------------------------------------------------------------------------------------------------------------------------

string ReGetConsolePrompt();

int ReGetConsoleWidth();
int ReGetConsoleHeight();

int ReGetCurrentLine();
void ReSetCurrentLine(int line);
void ReAddCurrentLine(int line);
void ReSubCurrentLine(int line);

void ReDrawGraphics();
void ReRedrawGraphics();

void RENDER();

// ----------------------------------------------------------------------------------------------------------------------------

string ReGetConsolePrompt() {
	return PROMPT;
} 

int ReGetConsoleWidth() {
	return WIDTH;
} 

int ReGetConsoleHeight() {
	return HEIGHT;
}

int ReGetCurrentLine() {
	return currentLine;
}

void ReSetCurrentLine(int line) {
	currentLine = line;
}

void ReAddCurrentLine(int line) {
	currentLine += line;
}

void ReSubCurrentLine(int line) {
	currentLine -= line;
}

// ----------------------------------------------------------------------------------------------------------------------------

void ReDrawGraphics() {

	system("color 0F");
		
	// Draw the main window in the background
	drawWindow(0, 1, (WIDTH - 1), (HEIGHT - 2), "System Shell", LIGHTBLUE_WHITE, LIGHTBLUE_LIGHTBLUE, LIGHTBLUE_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); 
	
	// Draw the taskbar
	drawBar(1, 29, (WIDTH - 2), 31, "", RED_WHITE, RED_RED, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); 
}

void ReRedrawGraphics() {
	showConsoleCursor(false);
	clearScreen();
	ReDrawGraphics(); // Re-draw graphics
	ReSetCurrentLine(2);
	showConsoleCursor(true);
}

void RENDER_ICONS() {
	// Draw and update the internet icon
	if (isNetworkConnected() == true) {
		renderColorImage("Assets/Shell/Internet.bmp", 877, 479, 0x00ff00, -2);
	} else {
		renderColorImage("Assets/Shell/No-Internet.bmp", 870, 479, 0x00ff00, -2);
	}
}

void RENDER() {
	showConsoleCursor(false); // Hide cursor
	
	drawString("RAM: " + getRAM() + "%", (WIDTH - WIDTH + 3), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // RAM used
	drawString("DISK: " + getDisk(), (WIDTH - WIDTH + 13), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Disk used
	drawString("MPOS: " + getConsoleMousePos(), (WIDTH - WIDTH + 33), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Mouse Position

	// Draw and update the internet text
	if (isNetworkConnected() == true) {
		drawString("NET", (WIDTH - 16), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Connected
	} else {
		drawString("no NET", (WIDTH - 18), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Network error
	}
	
	// Draw and update the taskbar clock
	drawString("| " + getCurrentTime(), (WIDTH - 12), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE);
	
	setCursorPos(PROMPT.length() + 2, ReGetCurrentLine()); // Go to the prompt position
	showConsoleCursor(true); // Show cursor
	
	RENDER_ICONS();
	
	Sleep(100);
}

#endif /* SYSTEM_CORE_MAINRENDER_H_ */
