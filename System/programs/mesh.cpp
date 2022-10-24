#include "mesh.h"

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

void Mesh::setPixel(int x, int y, COLORREF color) {
    HDC hdc = GetDC(GetConsoleWindow());
    SetPixel(hdc, x, y, color);
    ReleaseDC(GetConsoleWindow(), hdc);
}

void Mesh::drawCell(int x, int y, int size, COLORREF color) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                setPixel(x + i, y + j, color);
            }
        }
    }
}

int Mesh::main() {
    while (!Input::getKey(VK_SHIFT)) {
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

                if (Input::getKey(VK_SHIFT)) {
                    break; // break the loop
                }

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

	return 0;
}
