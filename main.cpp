/*
* OS Simulator
*
* CHANGELOG:
*	17/10/2022 Splitted mainSystem.h with mainKernel.h and mainRender.h
*	03/10/2022 Added renderColorImage, do the same but can replace the image colors JEJE
*	02/10/2022 Added renderImage to print bmp images on the console :) (OH SHIT, THIS IS EPIC!)
*	01/10/2022 Added a Interrupt function and a basic program
*	27/08/2022 Added RAM and Disk counters to the Taskbar, also added sounds support
*	26/09/2022 Added internet status iconon the taskbar :)
*	25/09/2022 Added updater, now the shell can update the taskbar clock and handle commands at same time
*   24/09/2022 Completed colors values list on colorsShell.h, and added setters/getters to mainSystem.h
*   23/09/2022 Solved clock rounding numbers on timeUtils.h
*   22/09/2022 Moved Math stuff to mathUtils.h and improved code quality a bit
*	20/09/2022 Solved strings positions on the screen, like the KEY HANDLED INTERRUMPT message 
*   17/09/2022 Solved std::cin problem with spaced commands.
*   ...
*/

#include <iostream>
#include <stdio.h>

// System mainloop
#include "System/core/mainKernel.h"

using namespace std;

void charsTest();
void colorsTest();

int main(int argc, char *argv[]) {
	MAIN_SYS(); // Start system
	
	// colorsTest();
	// charsTest();
	
	system("pause");
	return 0; // EXIT
}

// TEST: Color list
void colorsTest() {
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  
    // Print different colors from 1 to 255 on the output screen
    for (int P = 1; P < 255; P++) {
  
        // P is color code of the corresponding color
        SetConsoleTextAttribute(hConsole, P);
  
        // Print Statement
        cout << P << " Hello World, " << "good night!!!" << endl;
    }	
}

// TEST: Chars list
void charsTest() {
    for (int i = 0; i < 256; i++) {
        if (i % 32 == 0) { // Pause each 32 chars printed
        	cout << "dec   |  hex  |   oct   |  chr" << endl;
            system("pause");
        } else {
        	printf("%d\t | %x\t | %o\t | %c\n", i, i, i, i);
		}
    }
}
