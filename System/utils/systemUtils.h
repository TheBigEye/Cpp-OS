#ifndef SYSTEMUTILS_H
#define SYSTEMUTILS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

string getRAM() {
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    string ram = to_string(status.dwMemoryLoad);
    return ram;
}

string getDisk() {
    ULARGE_INTEGER free_bytes_available, total_number_of_bytes, total_number_of_free_bytes;
    GetDiskFreeSpaceEx(NULL, &free_bytes_available, &total_number_of_bytes, &total_number_of_free_bytes);
    
    int usedSpace = (total_number_of_bytes.QuadPart / (1024 * 1024 * 1024)) - (total_number_of_free_bytes.QuadPart / (1024 * 1024 * 1024));
    int availibleSpace = total_number_of_bytes.QuadPart / (1024 * 1024 * 1024);
    int totalSpace = total_number_of_bytes.QuadPart / (1024 * 1024 * 1024);

    string diskSpace = to_string(usedSpace) + " GBs/" + to_string(totalSpace) + " GBs";
    return diskSpace;
}

#endif // SYSTEMUTILS_H
