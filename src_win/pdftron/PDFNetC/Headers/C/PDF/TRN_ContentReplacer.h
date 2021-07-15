//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFContentReplacer
#define PDFTRON_H_CPDFContentReplacer

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

TRN_API TRN_ContentReplacerCreate(TRN_ContentReplacer* result);
TRN_API TRN_ContentReplacerDestroy(TRN_ContentReplacer cr);
TRN_API TRN_ContentReplacer_AddImage(TRN_ContentReplacer cr, const TRN_Rect* target_region, TRN_Obj replacement_image);
TRN_API TRN_ContentReplacer_AddText(TRN_ContentReplacer cr, const TRN_Rect* target_region, const TRN_UString replacement_text);
TRN_API TRN_ContentReplacer_AddString(TRN_ContentReplacer cr, const TRN_UString template_text, const TRN_UString replacement_text);
TRN_API TRN_ContentReplacer_SetMatchStrings(TRN_ContentReplacer cr, const TRN_UString start_str, const TRN_UString end_str);
TRN_API TRN_ContentReplacer_Process(TRN_ContentReplacer cr, TRN_Page page);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFContentReplacer
