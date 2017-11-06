#include "ExportInfoSamplePlugin.h"

ClassDesc2* GetExportInfoSamplePluginDesc ()
{
	return ExportInfoSamplePluginClassDesc::GetInstance();
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
	if (this->file_ptr)
	{
		return IMPEXP_FAIL;
	}

	errno_t err = _tfopen_s(&this->file_ptr, name, _T("w"));

	if (err != 0)
	{
		return IMPEXP_FAIL;
	}

	Interval range = i->GetAnimRange();

	_ftprintf_s(this->file_ptr, _T("%s %.1f\n"), _T(PLUGIN_CLASS_NAME), PLUGIN_VERSION / 100.f);
	_ftprintf_s(this->file_ptr, _T("%s\n"), static_cast<const wchar_t*>(i->GetCurFileName()));
	_ftprintf_s(this->file_ptr, _T("Frames %d - %d\n"), range.Start() / GetTicksPerFrame(), range.End() / GetTicksPerFrame());
	_ftprintf_s(this->file_ptr, _T("Rate %d - %d\n"), GetFrameRate(), GetTicksPerFrame());

	fclose(this->file_ptr);
	this->file_ptr = nullptr;

	return IMPEXP_SUCCESS;
}

ExportInfoSamplePluginClassDesc* ExportInfoSamplePluginClassDesc::GetInstance ()
{
	static ExportInfoSamplePluginClassDesc plugin_classdesc;
	return &plugin_classdesc;
}

int ExportInfoSamplePluginClassDesc::IsPublic ()
{
	return TRUE;
}

void* ExportInfoSamplePluginClassDesc::Create (BOOL loading)
{
	return new ExportInfoSamplePlugin;
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
