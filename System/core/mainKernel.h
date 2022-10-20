#ifndef SYSTEM_CORE_MAINKERNEL_H_
#define SYSTEM_CORE_MAINKERNEL_H_

#include <iostream>

void KeStop();
void KePause();

bool KeGetRunning();
void KeSetRunning(bool value);

void KeKeyInterrupt();

void KeDelay(unsigned int milliseconds);
void KeInterrupt();
void KeReturn();

void KERNEL();
void MAIN_SYS();

#endif /* SYSTEM_CORE_MAINKERNEL_H_ */
