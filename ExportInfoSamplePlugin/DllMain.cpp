#include "ExportInfoSamplePlugin.h"

HINSTANCE hInstance;

BOOL WINAPI DllMain (HINSTANCE hinstDLL, ULONG fdwReason, LPVOID /*lpvReserved*/)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		hInstance = hinstDLL;
		DisableThreadLibraryCalls(hInstance);
	}

	return TRUE;
}

extern ClassDesc2* GetExportInfoSamplePluginDesc ();

__declspec(dllexport) ClassDesc* LibClassDesc (int i)
{
	switch (i)
	{
		case 0: return GetExportInfoSamplePluginDesc();
	}

	return 0;
}

__declspec(dllexport) const TCHAR* LibDescription ()
{
	return GetString(IDS_LIBDESCRIPTION);
}

__declspec(dllexport) int LibNumberClasses ()
{
	return 1;
}

__declspec(dllexport) ULONG LibVersion ()
{
	return Get3DSMAXVersion();
}

TCHAR* GetString (int id)
{
	static TCHAR buf[256];

	if (hInstance)
	{
		return LoadString(hInstance, id, buf, _countof(buf)) ? buf : nullptr;
	}

	return nullptr;
}
