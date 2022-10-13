#include <iostream>
#include "consoleUtils.h"

using namespace std;

/**
 * Change the output console size.
 *
 * @param width The width that the window will have by characters.
 * @param height The height that the window will have by characters.
 */
void setConsoleSize(int width, int height) {
	stringstream ss;
	ss << "mode con cols=" << width << " " << "lines=" << height; // Modify the command string to insert the variables
	string s = ss.str(); // Convert all to string
	system(s.c_str()); // Run the command
}


/**
* Enable or disable the console window resizing property
*
* @param resizable Determines whether the window can be resizable or not.
*/
void setConsoleResizable(bool resizable) {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    if (resizable) {
        style |= WS_MAXIMIZEBOX; // Maximize button
        style |= WS_THICKFRAME;	// Mouse resizing
    } else {
        style &= ~WS_MAXIMIZEBOX;
        style &= ~WS_THICKFRAME;
    }
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}


/**
 * Change the output console position on the screen.
 *
 * @param x The x axis where the window will be placed.
 * @param y The y axis where the window will be placed.
 */
void setConsolePosition(int x, int y) {
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}


/**
 * Change the output console cursor size to show a styled block cursor.
 */
void setConsoleBlockCursor(){
	HANDLE hout; //handle to the console
	CONSOLE_CURSOR_INFO cursor;//cursor struct
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
    //set our handle for output

	cursor.dwSize = 100;
	//the structure member dwsize of
    //CONSOLE_CURSOR_INFO takes an int argument 
    //from 1-100, and the next function uses this
    //value to change the size of the cursor
    //accordingly

	SetConsoleCursorInfo(hout, &cursor);
	//pass the cursor info structure and our handle
	//to this function and we're done :)

	//you can also change the visibility of the cursor
	//with the structures other member called bVisible
}

/**
 * Show or hide the output console cursor.
 *
 * @param showFlag Determines whether the cursor is displayed or not.
 */
void showConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

/**
 * Changes the font size of the console (in turn this also changes the size of the window).
 *
 * @param FontSize The font size.
 */
void setConsoleFontSize(int fontSize) {
    CONSOLE_FONT_INFOEX cfi;
    
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;  // Width of each character in the font
    cfi.dwFontSize.Y = fontSize; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

/**
 * Get and return the current mouse position (x y) on the console screen.
 */
string getConsoleMousePos() {
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(GetConsoleWindow(), &p);
    stringstream sh; sh << "x: " << int(p.x) << " y: " << int(p.y); string strMousePos = sh.str();
    return strMousePos;
}

/**
 * Show or hide the mouse pointer on the console window.
 *
 * @param showFlag Determines whether the cursor is displayed or not.
 * @deprecated Sadly this not works with console applications :(
 */
void showConsoleMouse(bool showFlag) {
	ShowCursor(showFlag); // Shows it again
}

