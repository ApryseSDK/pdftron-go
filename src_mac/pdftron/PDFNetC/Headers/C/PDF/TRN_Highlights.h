//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFHighlights
#define PDFTRON_H_CPDFHighlights

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_HighlightsCreate(TRN_Highlights* result);
TRN_API TRN_HighlightsDestroy(TRN_Highlights hlts);
TRN_API TRN_HighlightsCopyCtor(TRN_Highlights hlts, TRN_Highlights* result);
TRN_API TRN_HighlightsAssign(TRN_Highlights result, TRN_Highlights hlts);

TRN_API TRN_HighlightsAdd(TRN_Highlights hlts2, TRN_Highlights hlts);
TRN_API TRN_HighlightsLoad(TRN_Highlights hlts, TRN_UString file_name);
TRN_API TRN_HighlightsSave(TRN_Highlights hlts, TRN_UString file_name);
TRN_API TRN_HighlightsClear(TRN_Highlights hlts);

TRN_API TRN_HighlightsBegin(TRN_Highlights hlts, TRN_PDFDoc doc);
TRN_API TRN_HighlightsHasNext(TRN_Highlights hlts, TRN_Bool* result);
TRN_API TRN_HighlightsNext(TRN_Highlights hlts);
TRN_API TRN_HighlightsGetCurrentPageNumber(TRN_Highlights hlts, int* result);
TRN_API TRN_HighlightsGetCurrentQuads(TRN_Highlights hlts, const double** quads, int* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFHighlights
