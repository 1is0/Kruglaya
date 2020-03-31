#include <Windows.h>
#include <stdio.h>
#include "pch.h"
#include <iostream>
#include "MathLib.h"
using namespace std;

int _stdcall SumLib(int a, int b) {
	return a + b;
}
int _stdcall DifferenceLib(int a, int b) {
	return a - b;
}
int _stdcall CompositionLib(int a, int b) {
	return a * b;
}
float _stdcall DivisionLib(int a, int b) {
	return (float)a / (float)b;

}
void _stdcall CompareLib(int a, int b) {
	if (a > b) {
		cout << a << " > " << b;
	}
	else if (a < b) {
		cout << a << " < " << b;
	}
	else {
		cout << a << " = " << b;
	}
}




