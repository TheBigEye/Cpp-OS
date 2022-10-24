#ifndef SYSTEM_PROGRAMS_STARS_H_
#define SYSTEM_PROGRAMS_STARS_H_

#include <windows.h>
#include <iostream>

class Stars {
    public:
        static void setPixel(int x, int y, COLORREF color);
        static void drawStar(int x, int y, int size, COLORREF color);
        static int main();
};

#endif /* SYSTEM_PROGRAMS_STARS_H_ */
