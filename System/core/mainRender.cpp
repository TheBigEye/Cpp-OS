#include "mainRender.h"

#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>

#include <algorithm>
#include <sstream>

#include "io/inputHandler.h"
#include "../shell/colorShell.h"
#include "../shell/screenShell.h"
#include "../shell/graphicShell.h"
#include "../shell/imageShell.h"
#include "../utils/consoleUtils.h"
#include "../utils/systemUtils.h"
#include "../utils/networkUtils.h"
#include "../utils/timeUtils.h"

using namespace std;

// Console window dimensions
const int WIDTH = 128;
const int HEIGHT = 34;

int currentLine = 2;

string PROMPT = "OS C:\\>";
string TASKBAR, OLD_TASKBAR = "";
string CLOCK, OLD_CLOCK = "";

// Shell colors
int SHELL_BACKGROUND_COLOR = AQUA_AQUA;
int SHELL_BORDERS_COLOR = AQUA_WHITE;
int SHELL_FOREGROUND_COLOR = AQUA_LIGHTWHITE;

// Taskbar colors
int TASKBAR_BACKGROUND_COLOR = RED_RED;
int TASKBAR_BORDERS_COLOR = RED_WHITE;
int TASKBAR_FOREGROUND_COLOR = RED_LIGHTWHITE;

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
    showConsoleCursor(false);
	system("color 0F");

	// Draw the main window in the background
	drawWindow(
        0, 1,
        (WIDTH - 1), (HEIGHT - 2),
        "System Shell",
        SHELL_BORDERS_COLOR,
        SHELL_BACKGROUND_COLOR,
        LIGHTWHITE_BLACK,
        SHELL_FOREGROUND_COLOR
    );

	// Draw the Taskbar
	drawBar(1, 29,
        (WIDTH - 2), 31,
        TASKBAR_BORDERS_COLOR,
        TASKBAR_BACKGROUND_COLOR,
        SHELL_FOREGROUND_COLOR
    );

	showConsoleCursor(true);
}

void ReRedrawGraphics() {
	clearScreen(); // Clean the screen buffer

	// Reset the TUI components
	TASKBAR = "";
    OLD_TASKBAR = "";
    CLOCK = "";
    OLD_CLOCK = "";

	ReDrawGraphics(); // Re-draw graphics
	ReSetCurrentLine(2); // Reset the prompt position
}

void RENDER_ICONS() {
	// Draw and update the Internet icon
	if (isNetworkConnected() == true) {
        Render::imageEx("Assets/Shell/Internet.bmp", 877, 480, 0x00ff00, -2);
	} else {
		Render::imageEx("Assets/Shell/No-Internet.bmp", 870, 480, 0x00ff00, -2);
	}
}

void RENDER() {

    // Dynamic variables --------------------------------------------------------------------------
    string ramCount = makeString("RAM: " + getRAM() + "%");
    string diskCount = makeString("DISK: " + getDisk());
    /*string mousePosition = makeString("MPOS: " + getConsoleMousePos());*/

    TASKBAR = makeString(ramCount + "  " + diskCount + " " /*+ mousePosition*/ + " ");
    CLOCK = makeString("| " + getCurrentTime());
    // --------------------------------------------------------------------------------------------

	showConsoleCursor(false); // Hide cursor

	// For avoid visual issues when updates the taskbar
	if (isEqualString(TASKBAR, OLD_TASKBAR) == false) {
        drawString(TASKBAR, 3, 30, TASKBAR_FOREGROUND_COLOR, SHELL_FOREGROUND_COLOR); // Taskbar info
        OLD_TASKBAR = TASKBAR;
	}

	// Draw and update the Taskbar clock
    if (isEqualString(CLOCK, OLD_CLOCK) == false) {
        drawString(CLOCK, (WIDTH - 12), 30, TASKBAR_FOREGROUND_COLOR, SHELL_FOREGROUND_COLOR); // Taskbar info
        OLD_CLOCK = CLOCK;
	}

	// Draw and update the Internet text
	if (isNetworkConnected() == true) {
		drawString("NET", (WIDTH - 16), 30, TASKBAR_FOREGROUND_COLOR, SHELL_FOREGROUND_COLOR); // Connected
	} else {
		drawString("no NET", (WIDTH - 18), 30, TASKBAR_FOREGROUND_COLOR, SHELL_FOREGROUND_COLOR); // Network error
	}

	// Draw command prompt
	drawString(ReGetConsolePrompt(), 2, ReGetCurrentLine(), SHELL_FOREGROUND_COLOR, SHELL_FOREGROUND_COLOR);
	setCursorPos(PROMPT.length() + 2, ReGetCurrentLine()); // Go to the prompt position

	RENDER_ICONS();

	showConsoleCursor(true); // Show cursor
}
