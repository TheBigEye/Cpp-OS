#include "mainKernel.h"

#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <ctime>

#include <algorithm>
#include <sstream>

#include "mainRender.h"

#include "io/inputHandler.h"
#include "../programs/command.h"
#include "../shell/colorShell.h"
#include "../shell/graphicShell.h"
#include "../shell/screenShell.h"
#include "../utils/consoleUtils.h"

using namespace std;

const int SCREEN_WIDTH = ReGetConsoleWidth();
const int SCREEN_HEIGHT = ReGetConsoleHeight();

// Kernel tick updates delay
const int KERNEL_TIME = 1000; // 0.3 secs

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

void KeDelay(int milliseconds) {
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while((now - then) < pause) {
        now = clock();
    }
}


void KeKeyInterrupt() {
    if (KeGetRunning() == true) {
        print("-- HANDLED INTERRUPT --", 2, ReGetCurrentLine() + 1);
        KeSetRunning(false); // Interrupt the loop

        // Perform the exit
        setCursorPos(2, ReGetCurrentLine() + 2);
        cin.get();
        KeStop();
    }
}

void KeInterrupt() {
    clearScreen();
	KeSetRunning(false);
}

void KeReturn() {
	ReRedrawGraphics();
	KeSetRunning(true);
}

// ----------------------------------------------------------------------------------------------------------------------------


void KERNEL() {

	while(!Input::isKeyPressed() && KeGetRunning() == true) { // While any key isn't pressed

        // If shift pressed, INTERRUPT THE SYSTEM
        if (Input::getKey(VK_SHIFT)) {
            KeKeyInterrupt();
        }

        // if mouse is positionated on internet icon and press ctrl, redraw all
        if (Input::getMouse(875, 895, 450, 500, VK_CONTROL)) {
            ReRedrawGraphics();
        }

        RENDER();

        KeDelay(KERNEL_TIME); // Make a 1 secs delay to the code
        //Sleep(1/60.0f * 1000.0f);
    }
}


// @brief The system mainloop :)
void MAIN_SYS() {

	KeSetRunning(true); // ENABLE RUN EVERYTHING

	// WARN: if you have problems in Windows 7, disable these three options (this due the Windows API)
	setConsolePosition(200, 100);
	setConsoleSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	setConsoleResizable(false);

	// Render::mageEx("Assets/logo.bmp", (WIDTH * 3) + 75, (HEIGHT * 4) -36, 0x00ff00, -2);
	// Sleep(2000); // Sleep thread for 2 secs

	ReDrawGraphics(); // Draw graphics

	// Main system loop
	while (KeGetRunning() == true) {

		// If the prompt overrides the buffer, then it clears the screen, resets the lines, and refresh the buffer
		if (ReGetCurrentLine() >= (SCREEN_HEIGHT - 6)) {
			ReRedrawGraphics();
		} else {
			KERNEL();

			getline(cin, currentCommand);
			KeDelay(256);
			ReAddCurrentLine(1);
			CMD(currentCommand);
			ReAddCurrentLine(1);
		}
	}
}
