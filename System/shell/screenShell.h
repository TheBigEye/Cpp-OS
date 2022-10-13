#ifndef SCREENSHELL_H
#define SCREENSHELL_H

#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

string toLowercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string toUppercase(string str) {
    for(int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}


char getCharFrom(int hex) {
    return (char)hex;
}

char getCharFrom(string oct) {
    int dec = 0;

    for (int i = 0; i < oct.length(); i++) {
        dec = dec * 8 + (oct[i] - '0');
    }
    
    return (char)dec;
}


bool startsWith(string str, string start) {
    if (str.length() < start.length()) {
    	return false;
	} 

    for (int i = 0; i < start.length(); i++) {
        if (str[i] != start[i]) {
            return false;
        }
    }
    return true;
}

string replace(string str, string oldWord, string newWord) {
    string newStr = "";
    int i = 0;
    while (i < str.length()) {
        if (startsWith(str.substr(i), oldWord)) {
            newStr += newWord;
            i += oldWord.length();
        } else {
            newStr += str[i];
            i++;
        }
    }
    return newStr;
}

void clearScreen() {
    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    // std::cout uses a buffer to batch writes to the underlying console.
    // We need to flush that to the console because we're circumventing
    // std::cout entirely; after we clear the console, we don't want
    // stale buffered text to randomly be written out.
    std::cout.flush();

    // Figure out the current width and height of the console window
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
    
    DWORD written;

    // Flood-fill the console with spaces to clear it
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    // Reset the attributes of every character to the default.
    // This clears all background colour formatting, if any.
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    // Move the cursor back to the top left for the next sequence of writes
    SetConsoleCursorPosition(hOut, topLeft);
}

#endif // SCREENSHELL_H

