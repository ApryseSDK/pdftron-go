//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFFlattener
#define PDFTRON_H_CPDFFlattener

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_FlattenerCreate (TRN_Flattener* result);
TRN_API TRN_FlattenerDestroy(TRN_Flattener flattener);

enum TRN_FlattenerThreshold
{
	e_Flattener_very_strict,
	e_Flattener_strict,
	e_Flattener_default,
	e_Flattener_keep_most,
	e_Flattener_keep_all
};

enum TRN_FlattenerMode
{
	e_Flattener_simple,
	e_Flattener_fast
};

TRN_API TRN_FlattenerSetDPI(TRN_Flattener flattener, TRN_UInt32 dpi);
TRN_API TRN_FlattenerSetThreshold(TRN_Flattener flattener, enum TRN_FlattenerThreshold threshold);
TRN_API TRN_FlattenerSetMaximumImagePixels(TRN_Flattener flattener, TRN_UInt32 max_pixels);
TRN_API TRN_FlattenerSetPreferJPG(TRN_Flattener flattener, TRN_Bool jpg);
TRN_API TRN_FlattenerSetJPGQuality(TRN_Flattener flattener, TRN_UInt32 quality);
TRN_API TRN_FlattenerSetPathHinting(TRN_Flattener flattener, TRN_Bool hinting);
TRN_API TRN_FlattenerProcess(TRN_Flattener flattener, TRN_PDFDoc doc, enum TRN_FlattenerMode mode);
TRN_API TRN_FlattenerProcessPage(TRN_Flattener flattener, TRN_Page page, enum TRN_FlattenerMode mode);



#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFFlattener
