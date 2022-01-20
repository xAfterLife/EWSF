#pragma once
#include <windows.h>

#define IMAGE_BASE 0x00400000   // Default location; NosTale doesn't use ASLR
#define IMAGE_SIZE 0x004B4FFF

class Memscan
{
public:
	static LPVOID FindPattern(const BYTE* lpPattern, LPCSTR szMask);
	static uintptr_t PatternScan(void* module, const char* signature);
};
