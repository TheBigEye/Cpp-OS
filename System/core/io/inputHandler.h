#ifndef SYSTEM_CORE_IO_INPUTHANDLER_H_
#define SYSTEM_CORE_IO_INPUTHANDLER_H_

#include <iostream>

class Input {
    public:
        static bool getMouse(int xa, int xb, int ya, int yb, int buttonCode);
        static bool getMouse(int xa, int xb, int ya, int yb);
        static bool getKey(int keyCode);
        static bool isKeyPressed();
};

#endif /* SYSTEM_CORE_IO_INPUTHANDLER_H_ */
