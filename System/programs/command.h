#ifndef COMMAND_H
#define COMMAND_H

#include <windows.h>
#include <iostream>
#include <string.h>

#include "../core/mainSystem.h"
#include "../core/io/soundSystem.h"
#include "../shell/screenShell.h"
#include "../shell/gfxShell.h"

#include "../programs/stars.h"
#include "../programs/mesh.h"
#include "../programs/lines.h"

using namespace std;

int getCurrentLine();
bool getRunning();
void setCurrentLine(int line);
void addCurrentLine(int line);
void subCurrentLine(int line);
void setRunning(bool value);

void KRNL_INTERRUPT();
void KRNL_RETURN();

void CMD(string command);
int OUTPRINT(string command);
int HELP();

void CMD(string command) {
	
	// Make the input to lowercase
	command = toLowercase(command);
	
	if (command.length() < 1) { // Check if any command are typed
		subCurrentLine(1); // Move the prompt to a new line

	} else { // if a command are typed, check the command and execute it
		if (command == "exit") {
			setRunning(false);
			
		} else if (startsWith(command, "clear")) {
			addCurrentLine(64);
				
		} else if (startsWith(command, "print") || startsWith(command, "print ")) {
			OUTPRINT(command);
		
		} else if (startsWith(command, "help")) {
			HELP();
		
		} else if (command == "stars") {
			print("Leaving Kernel mode shell ...", 2, getCurrentLine());
			Sleep(1000);
			KRNL_INTERRUPT();
			drawStars();
			KRNL_RETURN();
			
		} else if (command == "lines") {
			print("Leaving Kernel mode shell ...", 2, getCurrentLine());
			Sleep(1000);
			KRNL_INTERRUPT();
			drawLines();
			KRNL_RETURN();
		
		} else if (command == "mesh") {
			print("Leaving Kernel mode shell ...", 2, getCurrentLine());
			Sleep(1000);
			KRNL_INTERRUPT();
			drawMesh();
			KRNL_RETURN();
		
		} else {
			playSound("Assets/Sound/Error.wav", 44100); // Play error sound
			//Beep(98, 500);
			//Beep(88, 500);
			print("ERROR: Command " + command + " not found!", 2, getCurrentLine());
		}
	}
}

int OUTPRINT(string command) {
	command = toLowercase(command);
	if (startsWith(command, "print ")) {
		command = replace(command, "print ", "");
	} else {
		print("ERROR: missing argument!", 2, getCurrentLine());
		return 1;
	}
	
	print(command, 2, getCurrentLine());
	return 0;
}

int HELP() {
	print("Help: ---------------------------------------------------------------------", 2, getCurrentLine()); addCurrentLine(1);
	print("  help                        - Prints this help message                   ", 2, getCurrentLine()); addCurrentLine(1);
	print("  clear                       - Clears the terminal screen                 ", 2, getCurrentLine()); addCurrentLine(1);
	print("  print <message>             - Print a output message                     ", 2, getCurrentLine()); addCurrentLine(1);
	print("  exit                        - End current session                        ", 2, getCurrentLine()); addCurrentLine(1);
	print("---------------------------------------------------------------------------", 2, getCurrentLine());
	return 0;
}

#endif // COMMAND_H
