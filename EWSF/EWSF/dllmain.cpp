#include <Windows.h>

#include "Discord.h"
#include "FPSBreaker.h"

FARPROC oShowNostaleSplash = NULL;
FARPROC oFreeNostaleSplash = NULL;

extern "C" __declspec(dllexport) void __declspec(naked) ShowNostaleSplash()
{
	__asm JMP oShowNostaleSplash;
}

extern "C" __declspec(dllexport) void __declspec(naked) FreeNostaleSplash()
{
	__asm JMP oFreeNostaleSplash;
}

DWORD WINAPI START_UP()
{
	const auto FPS_BREAKER = FpsBreaker::GetInstance();
	FPS_BREAKER.SetFpsLimit(250);

	Discord::Initialize();

	return 0;
}

BOOL APIENTRY DllMain(const HMODULE hModule, const DWORD ulReasonForCall, LPVOID lpReserved)
{
	if (ulReasonForCall == DLL_PROCESS_ATTACH)
	{
		const HMODULE h_lib_module = LoadLibraryA("EWSF.dll");
		if (h_lib_module == nullptr)
		{
			//Can't find EWSF.dll- your error Handling here
			return FALSE;
		}

		oShowNostaleSplash = GetProcAddress(h_lib_module, "ShowNostaleSplash");
		oFreeNostaleSplash = GetProcAddress(h_lib_module, "FreeNostaleSplash");

		DisableThreadLibraryCalls(hModule);
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)(START_UP), nullptr, 0, nullptr);
	}
	return TRUE;
}