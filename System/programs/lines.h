#ifndef SYSTEM_PROGRAMS_LINES_H_
#define SYSTEM_PROGRAMS_LINES_H_

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

class Lines {
	public:
		void setPixel(int x, int y, COLORREF color) {
		    HDC hdc = GetDC(GetConsoleWindow());
		    SetPixel(hdc, x, y, color);
		    ReleaseDC(GetConsoleWindow(), hdc);
		}
		
		void draw(int x1, int y1, int x2, int y2, COLORREF color) {
		    int dx = x2 - x1;
		    int dy = y2 - y1;
		    
		    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
		    float xInc = dx / (float) steps;
		    float yInc = dy / (float) steps;
		    
		    float x = x1;
		    float y = y1;
		    
		    for (int i = 0; i <= steps; i++) {
		        setPixel(x, y, color);
		        x += xInc;
		        y += yInc;
		    }
		}
};


void drawLines() {

	Lines Pencil;
	
	system("cls");
	system("color 0F");
	
	showConsoleCursor(false);
	bool trueColor = false;
	
    int x1 = rand() % 1000;
    int y1 = rand() % 500;
    int x2 = rand() % 1000;
    int y2 = rand() % 500;
    
    int color = 0;
    int count = 0;
    
    while (!isKeyPressed(KEY_SHIFT)) {
    	
		if (count >= 360) {
			system("cls");
			if (trueColor == false) {
				trueColor = true;
			} else {
				trueColor = false;
			}
			count = 0;
		}
        
        if (trueColor == false) {
        	color = rand() % 16777215;
        	Pencil.draw(x1, y1, x2, y2, color);
		} else {
			Pencil.draw(x1, y1, x2, y2, RGB(rand() % 256, rand() % 256, rand() % 256));
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

#endif /* SYSTEM_PROGRAMS_LINES_H_ */
