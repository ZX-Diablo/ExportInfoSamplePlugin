#pragma once

#include <iparamb2.h>

#include <max.h>
#include <maxapi.h>
#include <maxtypes.h>

#include "resource.h"

#define PLUGIN_CLASS_ID Class_ID(0x64ca39bb, 0x5d2a67c4)
#define PLUGIN_VERSION 100
#define PLUGIN_CLASS_NAME "ExportInfoSamplePlugin"
#define PLUGIN_CLASS_CATEGORY "Sample Plugins"

extern HINSTANCE hInstance;

extern TCHAR* GetString (int id);

class ExportInfoSamplePlugin : public SceneExport
{
public:
	static ExportInfoSamplePlugin* GetInstance ();

public:
	int ExtCount () override;
	const MCHAR* Ext (int n) override;

	const MCHAR* LongDesc () override;
	const MCHAR* ShortDesc () override;

	const MCHAR* AuthorName () override;
	const MCHAR* CopyrightMessage () override;
	const MCHAR* OtherMessage1 () override;
	const MCHAR* OtherMessage2 () override;

	unsigned int Version () override;

	void ShowAbout (HWND hWnd) override;

	int DoExport (const MCHAR* name, ExpInterface* ei, Interface* i, BOOL suppressPrompts = FALSE, DWORD options = 0) override;
};

class ExportInfoSamplePluginClassDesc : public ClassDesc2
{
public:
	int IsPublic () override;
	void* Create (BOOL loading = FALSE) override;
	const MCHAR* ClassName () override;
	SClass_ID SuperClassID () override;
	Class_ID ClassID () override;
	const MCHAR* Category () override;
};
