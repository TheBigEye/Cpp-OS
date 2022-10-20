#include "mainKernel.h"

#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

#include <algorithm>
#include <sstream>

#include "mainRender.h"

#include "../programs/command.h"
#include "../shell/colorShell.h"
#include "../shell/graphicShell.h"
#include "../shell/screenShell.h"
#include "../utils/consoleUtils.h"
#include "../utils/keyboardUtils.h"

using namespace std;

const int SCREEN_WIDTH = ReGetConsoleWidth();
const int SCREEN_HEIGHT = ReGetConsoleHeight();

// Kernel tick updates delay
const int KERNEL_TIME = 250; // 0.3 secs

// Variables
bool running = false;
string currentCommand = "";

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

void KeDelay(unsigned int milliseconds) {
    clock_t ticks1, ticks2;
    unsigned int tic1 = 0,tic2 = 0,tick = 0;

    ticks1 = clock();
    while(tick < milliseconds) {
        ticks2 = clock();
        tic1 = ticks2 / CLOCKS_PER_SEC - ticks1;
        tic2 = ticks1 / CLOCKS_PER_SEC;
        tick = ticks2 - ticks1;
    }
    ticks2 = clock();
}

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

// ----------------------------------------------------------------------------------------------------------------------------

void KERNEL() {
	while(!kbhit() && KeGetRunning() == true) { // While any key isn't pressed

		// IF shift key pressed, INTERRUPT THE SYSTEM
		if (GetKeyState(KEY_SHIFT) & 0x8000) { // 0x8000 Check if  is high-order bits is set (1 << 15)
			KeKeyInterrupt();
		}

		RENDER();

		KeDelay(KERNEL_TIME); // Make a 1 secs delay to the code
	}
}

void MAIN_SYS() {

	KeSetRunning(true); // ENABLE RUN EVERYTHING

	// WARN: if you have problems in Windows 7, disable these three options (this due the Windows API)
	setConsolePosition(200, 100);
	setConsoleSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	setConsoleResizable(false);

	// renderColorImage("Assets/logo.bmp", (WIDTH * 3) + 75, (HEIGHT * 4) -36, 0x00ff00, -2);
	// Sleep(2000); // Sleep thread for 2 secs

	ReDrawGraphics(); // Draw graphics

	// Main system loop
	while (KeGetRunning() == true) {

		// If the prompt overrides the buffer, then it clears the screen, resets the lines, and refresh the buffer
		if (ReGetCurrentLine() >= (SCREEN_HEIGHT - 6)) {
			ReRedrawGraphics();
		} else {
			// Command line interpreter
			drawString(ReGetConsolePrompt(), 2, ReGetCurrentLine(), LIGHTBLUE_LIGHTWHITE, LIGHTBLUE_LIGHTWHITE);
			KERNEL();

			getline(cin, currentCommand);
			KeDelay(256);
			ReAddCurrentLine(1);
			CMD(currentCommand);
			ReAddCurrentLine(1);
		}
	}
}
