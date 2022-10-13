#ifndef LINES_H
#define LINES_H

#include <windows.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#include "../shell/gfxShell.h"
#include "../utils/consoleUtils.h"
#include "../utils/keysUtils.h"

using namespace std;

bool lTrueColor = false;

void lSetPixel(int x, int y, COLORREF color) {
    HDC hdc = GetDC(GetConsoleWindow());
    SetPixel(hdc, x, y, color);
    ReleaseDC(GetConsoleWindow(), hdc);
}

void drawLine(int x1, int y1, int x2, int y2, COLORREF color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        lSetPixel(x, y, color);
        x += xInc;
        y += yInc;
    }
}

void drawLines(){
	
	system("cls");
	system("color 0F");
	
	showConsoleCursor(false);
	
    int x1 = rand() % 1000;
    int y1 = rand() % 500;
    int x2 = rand() % 1000;
    int y2 = rand() % 500;
    
    int color = 0;
    int count = 0;
    
    while (!(GetKeyState(KEY_SHIFT) & 0x8000)) {
    	
		if (count >= 360) {
			system("cls");
			if (lTrueColor == false) {
				lTrueColor = true;
			} else {
				lTrueColor = false;
			}
			count = 0;
		}
        
        if (lTrueColor == false) {
        	color = rand() % 16777215;
        	drawLine(x1, y1, x2, y2, color);
		} else {
			drawLine(x1, y1, x2, y2, RGB(rand() % 256, rand() % 256, rand() % 256));
		}
        
        x1 = x2;
        y1 = y2;
        x2 = rand() % 1000;
        y2 = rand() % 500;
        
        count++;
        
        stringstream cs; cs << count; string strCount = cs.str();
        drawString(strCount, 127 - strCount.size(), 33);

        Sleep(50);
    }
}

#endif // LINES_H
