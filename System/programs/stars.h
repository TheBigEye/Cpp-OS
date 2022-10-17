#ifndef SYSTEM_PROGRAMS_STARS_H_
#define SYSTEM_PROGRAMS_STARS_H_

#include <windows.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#include "../shell/graphicShell.h"
#include "../utils/consoleUtils.h"
#include "../utils/keysUtils.h"

using namespace std;

bool sTrueColor = false;

void sSetPixel(int x, int y, COLORREF color) {
    HDC hdc = GetDC(GetConsoleWindow());
    SetPixel(hdc, x, y, color);
    ReleaseDC(GetConsoleWindow(), hdc);
}

void drawStar(int x, int y, int size, COLORREF color) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1 || i == 1 || i == size - 2 || j == 1 || j == size - 2) {
                sSetPixel(x + i, y + j, color);
            }
        }
    }
}

void drawStars() {
	
	system("cls");
	system("color 0F");
	
	showConsoleCursor(false);
	
    int x = 8;
    int y = 8;
    
    int size = 10;
    int color = 0;
    int count = 0;
    
    // If press SHIFT so interrupts the program
    while (!(GetKeyState(KEY_SHIFT) & 0x8000)) {
    	
        if (count >= 360) {
            system("cls");
            if (sTrueColor == false) {
            	sTrueColor = true;
            } else {
            	sTrueColor = false;
			}
            count = 0;
        }
        
        x = rand() % 1024;
        y = rand() % 512;
        
        size = rand() % 20 + 2;
        
        if (sTrueColor == false) {
        	color = rand() % 16777215;
        	drawStar(x, y, size, color);
		} else {
			drawStar(x, y, size, RGB(rand() % 256, rand() % 256, rand() % 256));
		}
        
        count++;
        
        stringstream cs; cs << count; string strCount = cs.str();
        drawString(strCount, 127 - strCount.size(), 33);
        
        Sleep(100);
    }
}

#endif /* SYSTEM_PROGRAMS_STARS_H_ */
