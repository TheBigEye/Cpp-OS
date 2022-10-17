#ifndef SYSTEM_CORE_MAINKERNEL_H_
#define SYSTEM_CORE_MAINKERNEL_H_

#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>

#include <algorithm>
#include <sstream>

#include "mainRender.h"

#include "../programs/command.h"
#include "../shell/colorShell.h"
#include "../shell/graphicShell.h"
#include "../shell/screenShell.h"
#include "../utils/consoleUtils.h"
#include "../utils/keysUtils.h"

using namespace std;

const int SCREEN_WIDTH = ReGetConsoleWidth();
const int SCREEN_HEIGHT = ReGetConsoleHeight();

// Kernel tick updates delay
const int KERNEL_TIME = 250; // 0.3 secs

// Variables
bool running = false;
string currentCommand = "";

// ----------------------------------------------------------------------------------------------------------------------------

void KeStop();
void KePause();

bool KeGetRunning();
void KeSetRunning(bool value);

void KeKeyInterrupt();

// Default functions
void KeInterrupt();
void KeReturn();

void KERNEL();
void MAIN_SYS();

// ----------------------------------------------------------------------------------------------------------------------------

void KeStop() {
	exit(0);
}

void KePause() {
	print("Press any key to continue...", 2, ReGetCurrentLine() + 1);
	cin.get();
}

bool KeGetRunning() {
	return running;
}

void KeSetRunning(bool value) {
	running = value;	
}

// ----------------------------------------------------------------------------------------------------------------------------

void KeKeyInterrupt() {
	print("-- HANDLED INTERRUPT --", 2, ReGetCurrentLine() + 1);
	KeSetRunning(false); // Interrupt the loop
			
	// Perform the exit
	setCursorPos(2, ReGetCurrentLine() + 2);
	cin.get();
	KeStop();
}

void KeInterrupt() {
	KeSetRunning(false);
}

void KeReturn() {
	KeSetRunning(true);
	ReRedrawGraphics();
}

void KERNEL() {
	
	while(!kbhit() && running) { // While any key isnt pressed
	
		// IF shift key pressioned, INTERRUPT THE SYSTEM
		if (GetKeyState(KEY_SHIFT) & 0x8000) { // 0X8000 Check if  is high-order bits is set (1 << 15)
			KeKeyInterrupt();
		}
		
		RENDER();
		
		Sleep(KERNEL_TIME); // Make a 1 secs delay to the thread
	}
}

void MAIN_SYS() {

	KeSetRunning(true); // ENABLE RUN EVERYTHING

	// WARN: disable these three options if the programm try run on Windows 7 sp1 (this due the Windows API)
	setConsolePosition(200, 100);
	setConsoleSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	setConsoleResizable(false);
	
	//renderColorImage("Assets/logo.bmp", (WIDTH * 3) + 75, (HEIGHT * 4) -36, 0x00ff00, -2);
	
	Sleep(2000); // Sleep thread for 8 secs
	
	ReDrawGraphics(); // Draw graphics
	
	// Main system loop
	while (running == true) {
		
		// If the prompt overrides the buffer, then it clears the screen, resets the lines, and refresh the buffer
		if (ReGetCurrentLine() >= (SCREEN_HEIGHT - 6)) {
			ReRedrawGraphics();	
		} else {
			// Command line interpreter
			drawString(ReGetConsolePrompt(), 2, ReGetCurrentLine(), LIGHTBLUE_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE);
			KERNEL();
			
			getline(cin, currentCommand);
			Sleep(256);
			ReAddCurrentLine(1);
			CMD(currentCommand);
			ReAddCurrentLine(1);
		}

		// Delay 0.25 secs the loop
		//Sleep(256);
	}
}

#endif /* SYSTEM_CORE_MAINKERNEL_H_ */
