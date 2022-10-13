#ifndef IMGSHELL_H
#define IMGSHELL_H

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

// WARNING: ONLY USE 24 BITS BITMAPS
void renderImage(string filename, int x, int y) {
    HDC hdc = GetDC(GetConsoleWindow());

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGBTRIPLE *pixels;
    
    int width, height;
    int padding;
    int i, j;
    
    FILE *file;
    file = fopen(filename.c_str(), "rb");
    if (file == NULL) {
        cout << "Error opening file" << endl;
        return;
    }
    
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);
    
    if (bih.biBitCount != 24) {
        cout << "Error: the file is not 24 bit" << endl;
        return;
    }
    
    width = bih.biWidth;
    height = bih.biHeight;
    
    padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;
    pixels = new RGBTRIPLE[width * height];
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&pixels[(height - i - 1) * width + j], sizeof(RGBTRIPLE), 1, file);
        }
        fseek(file, padding, SEEK_CUR);
    }
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            SetPixelV(hdc, x + j, y + i, RGB(pixels[i * width + j].rgbtRed, pixels[i * width + j].rgbtGreen, pixels[i * width + j].rgbtBlue));
        }
    }
    
    delete[] pixels;
    fclose(file);
}


void renderColorImage(string filename, int x, int y, int colorA = -1, int colorB = -2) {
	
	// -1 Not specified color
	// -2 Use the console bg color
	// 0xfffetc..  Use a Hex color

    HDC hdc = GetDC(GetConsoleWindow());

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGBTRIPLE *pixels;
    int width, height;
    int padding;
    int i, j;
    FILE *file;
    file = fopen(filename.c_str(), "rb");
    if (file == NULL) {
        cout << "Error opening file" << endl;
        return;
    }
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);
    if (bih.biBitCount != 24) {
        cout << "Error: the file is not 24 bit" << endl;
        return;
    }
    width = bih.biWidth;
    height = bih.biHeight;
    padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;
    pixels = new RGBTRIPLE[width * height];
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&pixels[(height - i - 1) * width + j], sizeof(RGBTRIPLE), 1, file);
        }
        fseek(file, padding, SEEK_CUR);
    }
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (colorB == -2) {
                colorB = GetPixel(hdc, x + j, y + i);
            }
            if (colorA != -1 && colorB != -1) {
                if (RGB(pixels[i * width + j].rgbtRed, pixels[i * width + j].rgbtGreen, pixels[i * width + j].rgbtBlue) == colorA) {
                    SetPixel(hdc, x + j, y + i, colorB);
                    continue;
                }
            }
            SetPixel(hdc, x + j, y + i, RGB(pixels[i * width + j].rgbtRed, pixels[i * width + j].rgbtGreen, pixels[i * width + j].rgbtBlue));
        }
    }
    delete[] pixels;
    fclose(file);
}

#endif // IMGSHELL_H
