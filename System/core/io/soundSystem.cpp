#include <iostream>
#include "soundSystem.h"

using namespace std;

void playSound(string fileName, DWORD sampleRate) {
    // NOTE: to get the file sample rate, use https://www.metadata2go.com/

    ifstream file;
    file.open(fileName.c_str(), ios::binary);

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    file.seekg(0, ios::end);
    int size = file.tellg();

    file.seekg(0, ios::beg);
    char* buffer = new char[size];

    file.read(buffer, size);
    file.close();

    HWAVEOUT hWaveOut;
    WAVEFORMATEX wfx;

    wfx.nSamplesPerSec = sampleRate;
    wfx.wBitsPerSample = 16;
    wfx.nChannels = 2;
    wfx.cbSize = 0;
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nBlockAlign = (wfx.wBitsPerSample * wfx.nChannels) >> 3;
    wfx.nAvgBytesPerSec = wfx.nBlockAlign * wfx.nSamplesPerSec;

    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    WAVEHDR header;

    header.dwBufferLength = size;
    header.dwBytesRecorded = 0;
    header.dwUser = 0;
    header.dwFlags = 0;
    header.dwLoops = 0;
    header.lpData = buffer;
    header.reserved = 0;

    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

    while(!(header.dwFlags & WHDR_DONE)){
        Sleep(100);
    }
    
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
    delete[] buffer;
}
