#ifndef SYSTEM_CORE_MAINRENDER_H_
#define SYSTEM_CORE_MAINRENDER_H_

#include <iostream>

std::string ReGetConsolePrompt();

int ReGetConsoleWidth();
int ReGetConsoleHeight();

int ReGetCurrentLine();
void ReSetCurrentLine(int line);
void ReAddCurrentLine(int line);
void ReSubCurrentLine(int line);

void ReDrawGraphics();
void ReRedrawGraphics();

void RENDER_ICONS();
void RENDER();

#endif /* SYSTEM_CORE_MAINRENDER_H_ */
