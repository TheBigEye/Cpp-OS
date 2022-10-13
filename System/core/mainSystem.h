#ifndef MAINSYSTEM_H
#define MAINSYSTEM_H

#include <conio.h>  // Console I/O
#include <stdlib.h> // C standard library
#include <string.h>	// String and chars functions
#include <windows.h>  // Windows API
#include <stdio.h>

#include <algorithm> // Common algorithms
#include <sstream>  // String objects as streams

#include "../core/callsSystem.h"
#include "../programs/command.h"
#include "../shell/colorsShell.h"
#include "../shell/gfxShell.h"
#include "../shell/imgShell.h"
#include "../shell/screenShell.h"
#include "../utils/networkUtils.h"
#include "../utils/consoleUtils.h"
#include "../utils/keysUtils.h"
#include "../utils/mathUtils.h"
#include "../utils/systemUtils.h"
#include "../utils/timeUtils.h"

using namespace std;

// Prompt
const string PROMPT = "OS C:\\>";

// Console window dimensions
const int WIDTH = 128;
const int HEIGHT = 34;

// Screen updates delay
const int UPDATER_DELAY = 250; // 0.3 secs

// Variables
bool running = false;
int currentLine = 2;
string current_command = "";

// ----------------------------------------------------------------------------------------------------------------------------

// Getters
int getCurrentLine() {
	return currentLine;
}

bool getRunning() {
	return running;
}

// Setters
void setCurrentLine(int line) {
	currentLine = line;
}

void addCurrentLine(int line) {
	currentLine += line;
}

void subCurrentLine(int line) {
	currentLine -= line;
}

void setRunning(bool value) {
	running = value;	
}

// ----------------------------------------------------------------------------------------------------------------------------

void KEY_INTERRUPT() {
	print("-- KEY HANDLED INTERRUPT --", 2, getCurrentLine() + 1);
	setRunning(false); // Interrupt the loop
			
	// Perform the exit
	setCursorPos(2, getCurrentLine() + 2);
	cin.get();
	STOP();
}

// Default functions
void drawGraphics() {

	system("color 0F");
		
	drawWindow(0, 1, (WIDTH - 1), (HEIGHT - 2), "System Shell", LIGHTBLUE_WHITE, LIGHTBLUE_LIGHTBLUE, LIGHTBLUE_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Draw the main window in the background
	drawBar(1, 29, (WIDTH - 2), 31, "", RED_WHITE, RED_RED, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Draw the taskbar
}

void reDrawGraphics() {
	showConsoleCursor(false);
	clearScreen();
	drawGraphics(); // Re-draw graphics
	setCurrentLine(2);
	showConsoleCursor(true);
}

void KRNL_INTERRUPT() {
	setRunning(false);
}

void KRNL_RETURN() {
	setRunning(true);
	reDrawGraphics();
}

void UPDATE_GFX() {
	// IF shift key pressioned, INTERRUPT THE SYSTEM
	if (GetKeyState(KEY_SHIFT) & 0x8000) { // 0X8000 Check if  is high-order bits is set (1 << 15)
		KEY_INTERRUPT();
	}

	if (isNetworkConnected() == true) {
		renderColorImage("Assets/Shell/Internet.bmp", 877, 479, 0x00ff00, -2);
	} else {
		renderColorImage("Assets/Shell/No-Internet.bmp", 870, 479, 0x00ff00, -2);
	}
	
	Sleep(1); // Make a 1 secs delay to the thread	
}

void UPDATE_LOGIC() {
	
	while(!kbhit() && running) { // While any key isnt pressed
	
		// IF shift key pressioned, INTERRUPT THE SYSTEM
		if (GetKeyState(KEY_SHIFT) & 0x8000) { // 0X8000 Check if  is high-order bits is set (1 << 15)
			KEY_INTERRUPT();
		}
		
		showConsoleCursor(false); // Hide cursor
		
		// drawRandomCharBorders(0, 0, WIDTH, 33);

		// Draw and update the taskbar clock
		drawString("| " + getCurrentTime(), (WIDTH - 12), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE);
		
		// Draw and update the internet status icon
		if (isNetworkConnected() == true) {
			//renderImage("Assets/Shell/Internet.bmp", WIDTH + 64, HEIGHT + 16);
			drawString("  NET", (WIDTH - 18), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Connected
		} else {
			drawString("  no NET", (WIDTH - 21), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Network error
		}
	
		drawString("RAM: " + getRAM() + "%", (WIDTH - WIDTH + 3), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // RAM used
		drawString("DISK: " + getDisk(), (WIDTH - WIDTH + 13), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Disk used
		
		drawString("MPOS: " + getConsoleMousePos(), (WIDTH - WIDTH + 33), 30, RED_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE); // Mouse Position
		
		setCursorPos(PROMPT.length() + 2, getCurrentLine()); // Go to the prompt position
		showConsoleCursor(true); // Show cursor
		
		UPDATE_GFX();
		
		Sleep(UPDATER_DELAY); // Make a 1 secs delay to the thread
	}
}

void MAIN_KRNL() {

	running = true; // ENABLE RUN EVERYTHING

	// WARN: disable these three options if the programm try run on Windows 7 sp1 (this due the Windows API)
	setConsolePosition(200, 100);
	setConsoleSize(WIDTH, HEIGHT);
	setConsoleResizable(false);
	
	//renderColorImage("Assets/logo.bmp", (WIDTH * 3) + 75, (HEIGHT * 4) -36, 0x00ff00, -2);
	
	Sleep(2000); // Sleep thread for 8 secs
	
	drawGraphics(); // Draw graphics
	
	// Main system loop
	while (running == true) {
		
		// If the prompt overrides the buffer, then it clears the screen, resets the lines, and refresh the buffer
		if (currentLine >= (HEIGHT - 6)) {
			reDrawGraphics();	
		} else {
			// Command line interpreter
			drawString(PROMPT, 2, getCurrentLine(), LIGHTBLUE_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE);
			UPDATE_LOGIC();
			
			getline(cin, current_command);
			Sleep(256);
			addCurrentLine(1);
			CMD(current_command);
			addCurrentLine(1);
		}

		// Delay 0.25 secs the loop
		//Sleep(256);
	}
}

#endif // MAINSYSTEM_H
