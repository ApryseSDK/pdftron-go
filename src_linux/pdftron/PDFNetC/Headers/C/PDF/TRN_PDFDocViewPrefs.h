//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFDocViewPrefs
#define PDFTRON_H_CPDFPDFDocViewPrefs

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_Page.h>

TRN_API TRN_PDFDocViewPrefsSetInitialPage(TRN_PDFDocViewPrefs p, TRN_Destination dest);

enum TRN_PDFDocViewPrefsPageMode
	{
		e_PDFDocViewPrefs_UseNone,
		e_PDFDocViewPrefs_UseThumbs,
		e_PDFDocViewPrefs_UseBookmarks,
		e_PDFDocViewPrefs_FullScreen,
		e_PDFDocViewPrefs_UseOC,
		e_PDFDocViewPrefs_UseAttachments
	};

TRN_API TRN_PDFDocViewPrefsSetPageMode(TRN_PDFDocViewPrefs p, enum TRN_PDFDocViewPrefsPageMode mode);

TRN_API TRN_PDFDocViewPrefsGetPageMode(TRN_PDFDocViewPrefs p, enum TRN_PDFDocViewPrefsPageMode* result);

enum TRN_PDFDocViewPrefsPageLayout
{
	e_PDFDocViewPrefs_Default,
	e_PDFDocViewPrefs_SinglePage,
	e_PDFDocViewPrefs_OneColumn,
	e_PDFDocViewPrefs_TwoColumnLeft,
	e_PDFDocViewPrefs_TwoColumnRight,
	e_PDFDocViewPrefs_TwoPageLeft,
	e_PDFDocViewPrefs_TwoPageRight
};

TRN_API TRN_PDFDocViewPrefsSetLayoutMode(TRN_PDFDocViewPrefs p, enum TRN_PDFDocViewPrefsPageLayout mode);

TRN_API TRN_PDFDocViewPrefsGetLayoutMode(TRN_PDFDocViewPrefs p, enum TRN_PDFDocViewPrefsPageLayout* result);

enum TRN_PDFDocViewPrefsViewerPref
{
	e_PDFDocViewPrefs_HideToolbar,
	e_PDFDocViewPrefs_HideMenubar,
	e_PDFDocViewPrefs_HideWindowUI,
	e_PDFDocViewPrefs_FitWindow,
	e_PDFDocViewPrefs_CenterWindow,
	e_PDFDocViewPrefs_DisplayDocTitle,
};

TRN_API TRN_PDFDocViewPrefsSetPref(TRN_PDFDocViewPrefs p, enum TRN_PDFDocViewPrefsViewerPref pref, TRN_Bool value);

TRN_API TRN_PDFDocViewPrefsGetPref(TRN_PDFDocViewPrefs p, enum TRN_PDFDocViewPrefsViewerPref pref, TRN_Bool* result);

TRN_API TRN_PDFDocViewPrefsSetNonFullScreenPageMode(TRN_PDFDocViewPrefs p, enum TRN_PDFDocViewPrefsPageMode mode);

TRN_API TRN_PDFDocViewPrefsGetNonFullScreenPageMode(TRN_PDFDocViewPrefs p, enum TRN_PDFDocViewPrefsPageMode* result);

TRN_API TRN_PDFDocViewPrefsSetDirection(TRN_PDFDocViewPrefs p, TRN_Bool left_to_right);

TRN_API TRN_PDFDocViewPrefsGetDirection(TRN_PDFDocViewPrefs p, TRN_Bool* result);

TRN_API TRN_PDFDocViewPrefsSetViewArea(TRN_PDFDocViewPrefs p, enum TRN_PageBox box);

TRN_API TRN_PDFDocViewPrefsGetViewArea(TRN_PDFDocViewPrefs p, enum TRN_PageBox* result);

TRN_API TRN_PDFDocViewPrefsSetViewClip(TRN_PDFDocViewPrefs p, enum TRN_PageBox box);

TRN_API TRN_PDFDocViewPrefsGetViewClip(TRN_PDFDocViewPrefs p, enum TRN_PageBox* result);

TRN_API TRN_PDFDocViewPrefsSetPrintArea(TRN_PDFDocViewPrefs p, enum TRN_PageBox box);

TRN_API TRN_PDFDocViewPrefsGetPrintArea(TRN_PDFDocViewPrefs p, enum TRN_PageBox* result);

TRN_API TRN_PDFDocViewPrefsSetPrintClip(TRN_PDFDocViewPrefs p, enum TRN_PageBox box);

TRN_API TRN_PDFDocViewPrefsGetPrintClip(TRN_PDFDocViewPrefs p, enum TRN_PageBox* result);

TRN_API TRN_PDFDocViewPrefsGetSDFObj(TRN_PDFDocViewPrefs p, TRN_Obj* result);


TRN_API TRN_PDFDocViewPrefsCreate (TRN_Obj tr, TRN_PDFDocViewPrefs* result);
TRN_API TRN_PDFDocViewPrefsCopy (const TRN_PDFDocViewPrefs prefs, TRN_PDFDocViewPrefs* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFDocViewPrefs
