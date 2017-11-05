#include "ExportInfoSamplePlugin.h"

ClassDesc2* GetExportInfoSamplePluginDesc ()
{
	return nullptr;
}

int ExportInfoSamplePlugin::ExtCount ()
{
	return 1;
}

const MCHAR* ExportInfoSamplePlugin::Ext (int n)
{
	return _T("txt");
}

const MCHAR* ExportInfoSamplePlugin::LongDesc ()
{
	return _T("Export Info Sample Plugin");
}

const MCHAR* ExportInfoSamplePlugin::ShortDesc ()
{
	return _T("Export plugin");
}

const MCHAR* ExportInfoSamplePlugin::AuthorName ()
{
	return _T("ZX_Diablo");
}

const MCHAR* ExportInfoSamplePlugin::CopyrightMessage ()
{
	return _T("Copyright: ZX_Diablo");
}

const MCHAR* ExportInfoSamplePlugin::OtherMessage1 ()
{
	return _T("");
}

const MCHAR* ExportInfoSamplePlugin::OtherMessage2 ()
{
	return _T("");
}

unsigned int ExportInfoSamplePlugin::Version ()
{
	return PLUGIN_VERSION;
}

void ExportInfoSamplePlugin::ShowAbout (HWND hWnd)
{
}

int ExportInfoSamplePlugin::DoExport (const MCHAR* name, ExpInterface* ei, Interface* i, BOOL suppressPrompts, DWORD options)
{
	return 0;
}
