#ifndef SYSTEM_PROGRAMS_MESH_H_
#define SYSTEM_PROGRAMS_MESH_H_

#include <windows.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#include "../shell/graphicShell.h"
#include "../shell/screenShell.h"
#include "../utils/consoleUtils.h"
#include "../utils/keyboardUtils.h"

using namespace std;

void mSetPixel(int x, int y, COLORREF color) {
    HDC hdc = GetDC(GetConsoleWindow());
    SetPixel(hdc, x, y, color);
    ReleaseDC(GetConsoleWindow(), hdc);
}

void drawCell(int x, int y, int size, COLORREF color) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                mSetPixel(x + i, y + j, color);
            }
        }
    }
}

void drawMesh() {
    while (!(GetKeyState(KEY_SHIFT) & 0x8000)) {
    	clearScreen();
    	system("color 0F");
    	showConsoleCursor(false);

    	int x = 0;
		int y = 0;

		int color = 0;
		int size = 10;
		int count = 0;

        // Start drawing the mesh
	    for (int i = 0; i < 52; i++) {
	        for (int j = 0; j < 102; j++) {
	            color = rand() % 128;
	            drawCell(x, y, size, color); // Draw the square
	            x += size; // Increase the horizontal position

	            count++; // Update and draw the counter
	            stringstream cs; cs << count; string strCount = cs.str();
        	    drawString(strCount, 127 - strCount.size(), 33);
	        }
	        x = 0; // Reset the horizontal position
	        y += size; // Increase the vertical position by size
	    } // When ends, all resets

	}
}

#endif /* SYSTEM_PROGRAMS_MESH_H_ */
