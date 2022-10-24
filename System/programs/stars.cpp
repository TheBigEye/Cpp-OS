#include "stars.h"

#include <windows.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "../core/io/inputHandler.h"
#include "../shell/graphicShell.h"
#include "../shell/screenShell.h"
#include "../utils/consoleUtils.h"

using std::string;
using std::stringstream;

void Stars::setPixel(int x, int y, COLORREF color) {
    HDC hdc = GetDC(GetConsoleWindow());
    SetPixel(hdc, x, y, color);
    ReleaseDC(GetConsoleWindow(), hdc);
}

void Stars::drawStar(int x, int y, int size, COLORREF color) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1 || i == 1 || i == size - 2 || j == 1 || j == size - 2) {
                setPixel(x + i, y + j, color);
            }
        }
    }
}

int Stars::main() {
	clearScreen();
	system("color 0F");

	showConsoleCursor(false);

    int count = 0;
    bool trueColor = false;

    // If press SHIFT interrupts the program
    while (!Input::getKey(VK_SHIFT)) {

        if (count >= 360) {
            clearScreen();
            if (trueColor == false) {
            	trueColor = true;
            } else {
            	trueColor = false;
			}
            count = 0;
        }

        int x = rand() % 1024;
        int y = rand() % 512;

        int size = rand() % 20 + 2;

        if (trueColor == false) {
        	int color = rand() % 16777215;
        	drawStar(x, y, size, color);
		} else {
			drawStar(x, y, size, RGB(rand() % 256, rand() % 256, rand() % 256));
		}

        count++;

        stringstream cs; cs << count; string strCount = cs.str();
        drawString(strCount, 127 - strCount.size(), 33);

        Sleep(100);
    }

    return 0;
}
