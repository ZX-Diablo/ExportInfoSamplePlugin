#include "ExportInfoSamplePlugin.h"

ClassDesc2* GetExportInfoSamplePluginDesc ()
{
	return nullptr;
}

ExportInfoSamplePlugin* ExportInfoSamplePlugin::GetInstance ()
{
	static ExportInfoSamplePlugin plugin;
	return &plugin;
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

int ExportInfoSamplePluginClassDesc::IsPublic ()
{
	return TRUE;
}

void* ExportInfoSamplePluginClassDesc::Create (BOOL loading)
{
	return ExportInfoSamplePlugin::GetInstance();
}

const MCHAR* ExportInfoSamplePluginClassDesc::ClassName ()
{
	return _T(PLUGIN_CLASS_NAME);
}

SClass_ID ExportInfoSamplePluginClassDesc::SuperClassID ()
{
	return SCENE_EXPORT_CLASS_ID;
}

Class_ID ExportInfoSamplePluginClassDesc::ClassID ()
{
	return PLUGIN_CLASS_ID;
}

const MCHAR* ExportInfoSamplePluginClassDesc::Category ()
{
	return _T(PLUGIN_CLASS_CATEGORY);
}
