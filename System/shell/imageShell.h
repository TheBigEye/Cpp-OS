#ifndef SYSTEM_SHELL_IMAGESHELL_H_
#define SYSTEM_SHELL_IMAGESHELL_H_

#include <iostream>

class Render {
	public:
		static void image(std::string filename, int x, int y);
		static void imageEx(std::string filename ,int x, int y, int colorA, int colorB, int brightness, bool showBorders);
		static void imageEx(std::string filename, int x, int y, int colorA, int colorB, int brightness);
		static void imageEx(std::string filename, int x, int y, int colorA, int colorB);
};

#endif /* SYSTEM_SHELL_IMAGESHELL_H_ */
