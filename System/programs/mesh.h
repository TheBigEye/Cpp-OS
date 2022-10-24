#ifndef SYSTEM_PROGRAMS_MESH_H_
#define SYSTEM_PROGRAMS_MESH_H_

#include <iostream>
#include <windows.h>

class Mesh {
	public:
		static void setPixel(int x, int y, COLORREF color);
		static void drawCell(int x, int y, int size, COLORREF color);
		static int main();
};

#endif /* SYSTEM_PROGRAMS_MESH_H_ */
