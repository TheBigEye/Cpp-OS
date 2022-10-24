#ifndef SYSTEM_PROGRAMS_LINES_H_
#define SYSTEM_PROGRAMS_LINES_H_

#include <iostream>
#include <windows.h>

class Lines {
	public:
		static void setPixel(int x, int y, COLORREF color);
		static void drawLine(int x1, int y1, int x2, int y2, COLORREF color);
		static int main();
};

#endif /* SYSTEM_PROGRAMS_LINES_H_ */
