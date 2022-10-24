#include "imageShell.h"

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

// ----------------------------------------------------------------------------------------------------------------------------

void readPixels(FILE *file, RGBTRIPLE *pixels, int width, int height, int padding) { // read the pixels from the file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&pixels[(height - i - 1) * width + j], sizeof(RGBTRIPLE), 1, file); // read the pixels
        }
        fseek(file, padding, SEEK_CUR); // skip the padding
    }
}

void drawPixels(RGBTRIPLE *pixels, int width, int height, int x, int y) {// draw the pixels on the screen
    HDC hdc = GetDC(GetConsoleWindow()); // get the device context

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            SetPixelV(hdc, x + j, y + i, RGB(pixels[i * width + j].rgbtRed, pixels[i * width + j].rgbtGreen, pixels[i * width + j].rgbtBlue)); // draw the pixel
        }
    }

    ReleaseDC(GetConsoleWindow(), hdc);
}

void drawPixelsEx(RGBTRIPLE *pixels, int width, int height, int x, int y, int colorA = -1, int colorB = -2, int brightness = 50) {

	// -1 Not specified color
	// -2 Use the console bg color
	// 0xfffetc..  Use a Hex color

    HDC hdc = GetDC(GetConsoleWindow()); // get the device context

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (colorB == -2) {
                colorB = GetPixel(hdc, x + j, y + i);
            }
            if (colorA != -1 && colorB != -1) {
                if (RGB(pixels[i * width + j].rgbtRed, pixels[i * width + j].rgbtGreen, pixels[i * width + j].rgbtBlue) == colorA) {
                    SetPixelV(hdc, x + j, y + i, colorB);
                    continue;
                }
            }
            if (brightness == 50) {
				SetPixelV(hdc, x + j, y + i, RGB(pixels[i * width + j].rgbtRed, pixels[i * width + j].rgbtGreen, pixels[i * width + j].rgbtBlue));
				continue;
			}
            SetPixelV(hdc, x + j, y + i, RGB(pixels[i * width + j].rgbtRed * brightness / 50, pixels[i * width + j].rgbtGreen * brightness / 50, pixels[i * width + j].rgbtBlue * brightness / 50));
        }
    }

    ReleaseDC(GetConsoleWindow(), hdc);
}

void drawBorders(int x, int y, int width, int height) {
    HDC hdc = GetDC(GetConsoleWindow()); // get the device context

    for (int i = 0; i < height; i++) {
        SetPixelV(hdc, x, y + i, ~GetPixel(hdc, x, y + i));
        SetPixelV(hdc, x + width - 1, y + i, ~GetPixel(hdc, x + width - 1, y + i));
    }
    for (int i = 0; i < width; i++) {
        SetPixelV(hdc, x + i, y, ~GetPixel(hdc, x + i, y));
        SetPixelV(hdc, x + i, y + height - 1, ~GetPixel(hdc, x + i, y + height - 1));
    }
}


// ----------------------------------------------------------------------------------------------------------------------------


/**
* @brief Render an image on console text buffer
*
* @param filename The bitmap image file than will render
* @param x The horizontal position on the screen in pixels
* @param y The vertical position on screen in pixels
*
* WARNING: ONLY USE 24 BITS BITMAPS
*/
void Render::image(string filename, int x, int y) {
    BITMAPFILEHEADER bfh; // bitmap file header
    BITMAPINFOHEADER bih; // bitmap info header

    // width, height and padding
    int width = 0, height = 0, padding = 0;

    FILE *file = fopen(filename.c_str(), "rb"); // open the file in binary mode

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file); // read the file header into the bfh struct
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file); // read the info header into the bih struct

    if (bih.biBitCount != 24) { // check if the file is 24 bit (3 bytes per pixel, 1 byte for each color)
        cout << "Error: the file is not 24 bit" << endl;
        fclose(file);
        return;
    }

    width = bih.biWidth; // get the width of the image from the bih struct
    height = bih.biHeight; // get the height of the image from the bih struct
    RGBTRIPLE pixels[width * height]; // pixels array
    padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4; // calculate the padding (each row of pixels must be a multiple of 4 bytes, so we add some padding to the end of each row)

    readPixels(file, pixels, width, height, padding); // read the pixels into the pixels array
    drawPixels(pixels, width, height, x, y); // draw the pixels

    fclose(file);
}

/**
* @brief Render an image on console text buffer
*
* @param filename The bitmap image file than will render
* @param x The horizontal position on the screen in pixels
* @param y The vertical position on screen in pixels
* @param colorA The color that will be replaced by colorB
* @param colorB The color that will replace colorA
* @param brightness The brightness of the image
* @param showBorders Show borders around the image
*
* WARNING: ONLY USE 24 BITS BITMAPS
*/
void Render::imageEx(std::string filename, int x, int y, int colorA = -1, int colorB = -2, int brightness = 50, bool showBorders = false) {
    BITMAPFILEHEADER bfh; // bitmap file header
    BITMAPINFOHEADER bih; // bitmap info header

    // width, height and padding
    int width = 0, height = 0, padding = 0;

    FILE *file = fopen(filename.c_str(), "rb"); // open the file in binary mode

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    if (bih.biBitCount != 24) {
        std::cout << "Error: the file is not 24 bit" << std::endl;
        fclose(file);
        return;
    }

    width = bih.biWidth; // get the width of the image from the bih struct
    height = bih.biHeight; // get the height of the image from the bih struct
    RGBTRIPLE pixels[width * height]; // pixels array
    padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;  // calculate the padding (each row of pixels must be a multiple of 4 bytes, so we add some padding to the end of each row)

    readPixels(file, pixels, width, height, padding);
    drawPixelsEx(pixels, width, height, x, y, colorA, colorB, brightness);

    if (showBorders) {
        drawBorders(x, y, width, height);
    }

    fclose(file);
}

/*
* TODO: Make this docstring
*/
void Render::imageEx(std::string filename, int x, int y, int colorA = -1, int colorB = -2, int brightness = 50) {
    Render::imageEx(filename, x, y, colorA, colorB, brightness, false);
}

void Render::imageEx(std::string filename, int x, int y, int colorA = -1, int colorB = -2) {
    Render::imageEx(filename, x, y, colorA, colorB, 50, false);
}
