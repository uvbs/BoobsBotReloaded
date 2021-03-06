// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "stdafx.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Console::Initialize();
		Draw::Initialize();
		Feature::Initialize();

		Console::Log(R"( ____              _         ____        _   _____      _                 _          _)");
		Console::Log(R"(|  _ \            | |       |  _ \      | | |  __ \    | |               | |        | |)");
		Console::Log(R"(| |_) | ___   ___ | |__  ___| |_) | ___ | |_| |__) |___| | ___   __ _  __| | ___  __| |)");
		Console::Log(R"(|  _ < / _ \ / _ \| '_ \/ __|  _ < / _ \| __|  _  // _ \ |/ _ \ / _` |/ _` |/ _ \/ _` |)");
		Console::Log(R"(| |_) | (_) | (_) | |_) \__ \ | _) |(_) | |_| | \ \  __/ | (_) | (_) | (_| |  __/ (_| |)");
		Console::Log(R"(|____/ \___/ \___/|_.__/|___/____/ \___/ \__|_|  \_\___|_|\___/ \__,_|\__,_|\___|\__,_|)");

		Hook::InstallUICallback(Feature::Manager::ExecuteUiFeatures);
		Hook::InstallFrameCallback(Feature::Manager::ExecuteFrameFeatures);
		Console::Log("Installed Hooks");
		
		Feature::Manager::PrintFeatures();



	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

