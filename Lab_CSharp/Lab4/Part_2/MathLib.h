#pragma once
#ifdef MATHLIB_EXPORTS
#define MATHLIB_API __declspec(dllexport)
#else
#define MATHLIB_API __declspec(dllimport)
#endif

#include <cstdint>


typedef void(__stdcall* Notification)(const char*);



extern "C" int MATHLIB_API __stdcall SumLib(int a, int b);

extern "C" int MATHLIB_API __stdcall DifferenceLib(int a, int b);

extern "C" int MATHLIB_API __stdcall CompositionLib(int a, int b);

extern "C" float MATHLIB_API __stdcall DivisionLib(int a, int b);

extern "C" void MATHLIB_API __stdcall CompareLib(int a, int b);
