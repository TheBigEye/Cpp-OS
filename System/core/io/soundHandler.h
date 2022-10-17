#ifndef SYSTEM_CORE_IO_SOUNDHANDLER_H_
#define SYSTEM_CORE_IO_SOUNDHANDLER_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void playSound(string fileName, DWORD sampleRate);

#endif /* SYSTEM_CORE_IO_SOUNDHANDLER_H_ */
