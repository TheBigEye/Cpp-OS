#include <iostream>
#include "mathUtils.h"

using namespace std;

int SUM(int a, int b) {
	int result = a + b;
	return result;
}

int SUB(int a, int b) {
	int result = a - b;
	return result;
}

int MUL(int a, int b) {
	int result = a * b;
	return result;
}

float DIV(int a, int b) {
	float result = a / b;
	return result;
}

int nextInt(int from, int to) {
    return rand() % (to - from + 1) + from;
}
