#ifndef SYSTEM_UTILS_SYSTEMUTILS_H_
#define SYSTEM_UTILS_SYSTEMUTILS_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

std::string getRAM() {
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    std::string ram = std::to_string(status.dwMemoryLoad);
    return ram;
}

std::string getDisk() {
    ULARGE_INTEGER free_bytes_available, total_number_of_bytes, total_number_of_free_bytes;
    GetDiskFreeSpaceEx(NULL, &free_bytes_available, &total_number_of_bytes, &total_number_of_free_bytes);

    int usedSpace = (total_number_of_bytes.QuadPart / (1024 * 1024 * 1024)) - (total_number_of_free_bytes.QuadPart / (1024 * 1024 * 1024));
    // int availibleSpace = total_number_of_bytes.QuadPart / (1024 * 1024 * 1024);
    int totalSpace = total_number_of_bytes.QuadPart / (1024 * 1024 * 1024);

    std::string diskSpace = std::to_string(usedSpace) + " GBs/" + std::to_string(totalSpace) + " GBs";
    return diskSpace;
}



#endif /* SYSTEM_UTILS_SYSTEMUTILS_H_ */
