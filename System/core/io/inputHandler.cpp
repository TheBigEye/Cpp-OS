#include "inputHandler.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

#include "../../utils/consoleUtils.h"

const int KEY_SHIFT = 0x10;
const int KEY_CTRL = VK_CONTROL;
const int KEY_ALT = VK_MENU;
const int KEY_ENTER = VK_RETURN;
const int KEY_ESC = VK_ESCAPE;
const int KEY_SPACE = VK_SPACE;
const int KEY_LEFT = VK_LEFT;
const int KEY_RIGHT = VK_RIGHT;
const int KEY_UP = VK_UP;
const int KEY_DOWN = VK_DOWN;
const int KEY_BACKSPACE = VK_BACK;
const int KEY_TAB = VK_TAB;
const int KEY_CAPSLOCK = VK_CAPITAL;
const int KEY_DELETE = VK_DELETE;
const int KEY_END = VK_END;
const int KEY_HOME = VK_HOME;
const int KEY_INSERT = VK_INSERT;
const int KEY_PAGEUP = VK_PRIOR;
const int KEY_PAGEDOWN = VK_NEXT;

const int KEY_F1 = VK_F1;
const int KEY_F2 = VK_F2;
const int KEY_F3 = VK_F3;
const int KEY_F4 = VK_F4;
const int KEY_F5 = VK_F5;
const int KEY_F6 = VK_F6;
const int KEY_F7 = VK_F7;
const int KEY_F8 = VK_F8;
const int KEY_F9 = VK_F9;
const int KEY_F10 = VK_F10;
const int KEY_F11 = VK_F11;
const int KEY_F12 = VK_F12;

const int KEY_NUMLOCK = VK_NUMLOCK;
const int KEY_SCROLLLOCK = VK_SCROLL;
const int KEY_PAUSE = VK_PAUSE;
const int KEY_LWIN = VK_LWIN;
const int KEY_RWIN = VK_RWIN;
const int KEY_APPS = VK_APPS;

const int KEY_NUMPAD0 = VK_NUMPAD0;
const int KEY_NUMPAD1 = VK_NUMPAD1;
const int KEY_NUMPAD2 = VK_NUMPAD2;
const int KEY_NUMPAD3 = VK_NUMPAD3;
const int KEY_NUMPAD4 = VK_NUMPAD4;
const int KEY_NUMPAD5 = VK_NUMPAD5;
const int KEY_NUMPAD6 = VK_NUMPAD6;
const int KEY_NUMPAD7 = VK_NUMPAD7;
const int KEY_NUMPAD8 = VK_NUMPAD8;
const int KEY_NUMPAD9 = VK_NUMPAD9;
const int VMULTIPLY = VK_MULTIPLY;
const int KEY_ADD = VK_ADD;
const int KEY_SUBTRACT = VK_SUBTRACT;
const int KEY_DECIMAL = VK_DECIMAL;
const int KEY_DIVIDE = VK_DIVIDE;
const int KEY_NUMPADENTER = VK_RETURN;

const int KEY_A = 0x41;
const int KEY_B = 0x42;
const int KEY_C = 0x43;
const int KEY_D = 0x44;
const int KEY_E = 0x45;
const int KEY_F = 0x46;
const int KEY_G = 0x47;
const int KEY_H = 0x48;
const int KEY_I = 0x49;
const int KEY_J = 0x4A;
const int KEY_K = 0x4B;
const int KEY_L = 0x4C;
const int KEY_M = 0x4D;
const int KEY_N = 0x4E;
const int KEY_O = 0x4F;
const int KEY_P = 0x50;
const int KEY_Q = 0x51;
const int KEY_R = 0x52;
const int KEY_S = 0x53;
const int KEY_T = 0x54;
const int KEY_U = 0x55;
const int KEY_V = 0x56;
const int KEY_W = 0x57;
const int KEY_X = 0x58;
const int KEY_Y = 0x59;
const int KEY_Z = 0x5A;
const int KEY_0 = 0x30;
const int KEY_1 = 0x31;
const int KEY_2 = 0x32;
const int KEY_3 = 0x33;
const int KEY_4 = 0x34;
const int KEY_5 = 0x35;
const int KEY_6 = 0x36;
const int KEY_7 = 0x37;
const int KEY_8 = 0x38;
const int KEY_9 = 0x39;

const int KEY_LSHIFT = VK_LSHIFT;
const int KEY_RSHIFT = VK_RSHIFT;
const int KEY_LCTRL = VK_LCONTROL;
const int KEY_RCTRL = VK_RCONTROL;
const int KEY_LALT = VK_LMENU;
const int KEY_RALT = VK_RMENU;

const int KEY_SEMICOLON = VK_OEM_1;
const int KEY_PLUS = VK_OEM_PLUS;
const int KEY_COMMA = VK_OEM_COMMA;
const int KEY_MINUS = VK_OEM_MINUS;
const int KEY_PERIOD = VK_OEM_PERIOD;
const int KEY_FORWARDSLASH = VK_OEM_2;
const int KEY_TILDE = VK_OEM_3;
const int KEY_LBRACKET = VK_OEM_4;
const int KEY_BACKSLASH = VK_OEM_5;
const int KEY_RBRACKET = VK_OEM_6;
const int KEY_QUOTE = VK_OEM_7;

const int MOUSE_B1 = 0x01; // Mouse left click
const int MOUSE_B2 = 0x02; // Mouse right click
const int MOUSE_B3 = 0x04; // Mouse middle click

/**
* Returns a boolean value if the mouse position and button presses match the arguments.
*
* @param xa The point A where the X tracking of the mouse will start.
* @param xb The point B where the X mouse tracking will end.
* @param ya The point A where the Y tracking of the mouse will start.
* @param xb The point B where the Y mouse tracking will end.
* @param buttonCode The button that should be pressed between these positions.
* @return
        False: if the given conditions are not met.
        True: if all conditions are met
*/
bool Input::getMouse(int xa, int xb, int ya, int yb, int buttonCode) {
    // Check mouse position and buttons events
    if ((getConsoleMouseX() >= xa && getConsoleMouseX() <= xb) && (getConsoleMouseY() >= ya && getConsoleMouseY() <= yb) && (GetAsyncKeyState(buttonCode) && 0x8000)) {
        return true;
    }
    return false;
}

bool Input::getMouse(int xa, int xb, int ya, int yb) {
    // Check mouse position and buttons events
    if ((getConsoleMouseX() >= xa && getConsoleMouseX() <= xb) && (getConsoleMouseY() >= ya && getConsoleMouseY() <= yb)) {
        return true;
    }
    return false;
}

/**
* Returns a boolean value if any specified key is being pressed.
*
* @param keyCode The code of the keyboard key that will be tracked.
*/
bool Input::getKey(int keyCode) {
    if (GetAsyncKeyState(keyCode) && 0x8000) { // 0x8000 Check if  is high-order bits is set (1 << 15)
        return true;
    }
    return false;
}

bool Input::isKeyPressed() {
    if (kbhit()) {
        return true;
    }
    return false;
}

