#include "command.h"

#include <windows.h>
#include <iostream>
#include <string.h>

#include "../core/mainKernel.h"
#include "../core/mainRender.h"
#include "../core/io/soundHandler.h"
#include "../shell/graphicShell.h"
#include "../shell/screenShell.h"

#include "../programs/stars.h"
#include "../programs/mesh.h"
#include "../programs/lines.h"

using namespace std;

/*int ReGetCurrentLine();

bool KeGetRunning();
void ReSetCurrentLine(int line);
void ReAddCurrentLine(int line);
void ReSubCurrentLine(int line);
void KeSetRunning(bool value);

void KeInterrupt();
void KeReturn();*/

void CMD(string command) {

	// Make the input to lowercase
	command = toLowercase(command);

	if (command.length() < 1) { // Check if any command are typed
		ReSubCurrentLine(1); // Move the prompt to a new line

	} else { // if a command are typed, check the command and execute it
		if (command == "exit") {
			KeSetRunning(false);

		} else if (startsWith(command, "clear")) {
			ReAddCurrentLine(64);

		} else if (startsWith(command, "outprint") || startsWith(command, "outprint ")) {
			OUTPRINT(command);

		} else if (startsWith(command, "help")) {
			HELP();

		} else if (command == "stars") {
			print("Leaving Kernel mode shell ...", 2, ReGetCurrentLine());
			Sleep(1000);
			KeInterrupt();
			Stars::main();
			KeReturn();

		} else if (command == "lines") {
			print("Leaving Kernel mode shell ...", 2, ReGetCurrentLine());
			Sleep(1000);
			KeInterrupt();
			Lines::main();
			KeReturn();

		} else if (command == "mesh") {
			print("Leaving Kernel mode shell ...", 2, ReGetCurrentLine());
			Sleep(1000);
			KeInterrupt();
			Mesh::main();
			KeReturn();

		} else {
			playSound("Assets/Sound/Error.wav", 44100); // Play error sound
			//Beep(98, 500);
			//Beep(88, 500);
			print("Error: Command " + command + " not found!", 2, ReGetCurrentLine());
		}
	}
}

int OUTPRINT(string command) {
	command = toLowercase(command);
	if (startsWith(command, "outprint ")) {
		command = replace(command, "outprint ", "");
	} else {
		print("ERROR: missing argument!", 2, ReGetCurrentLine());
		return 1;
	}

	print(command, 2, ReGetCurrentLine());
	return 0;
}

int HELP() {
	print("Help: ---------------------------------------------------------------------", 2, ReGetCurrentLine()); ReAddCurrentLine(1);
	print("  help                        - Prints this help message                   ", 2, ReGetCurrentLine()); ReAddCurrentLine(1);
	print("  clear                       - Clears the terminal screen                 ", 2, ReGetCurrentLine()); ReAddCurrentLine(1);
	print("  outprint <message>          - Print a output message                     ", 2, ReGetCurrentLine()); ReAddCurrentLine(1);
	print("  exit                        - End current session                        ", 2, ReGetCurrentLine()); ReAddCurrentLine(1);
	print("---------------------------------------------------------------------------", 2, ReGetCurrentLine());
	return 0;
}
