//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFElementReader
#define PDFTRON_H_CPDFElementReader

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_GState.h>


TRN_API TRN_ElementReaderCreate(TRN_ElementReader* result);
TRN_API TRN_ElementReaderDestroy(TRN_ElementReader r);
TRN_API TRN_ElementReaderBeginOnPage(TRN_ElementReader r, TRN_Page page, TRN_OCGContext ctx);
TRN_API TRN_ElementReaderBegin(TRN_ElementReader r, TRN_Obj content_stream, TRN_Obj resource_dict, TRN_OCGContext ctx);
TRN_API TRN_ElementReaderAppendResource(TRN_ElementReader r, TRN_Obj res);
TRN_API TRN_ElementReaderNext(TRN_ElementReader r, TRN_Element* result);
TRN_API TRN_ElementReaderCurrent(TRN_ElementReader r, TRN_Element* result);
TRN_API TRN_ElementReaderFormBegin(TRN_ElementReader r);
TRN_API TRN_ElementReaderPatternBegin(TRN_ElementReader r, TRN_Bool fill_pattern, TRN_Bool reset_ctm_tfm);
TRN_API TRN_ElementReaderType3FontBegin(TRN_ElementReader r, TRN_CharData* char_data, TRN_Obj resource_dict);
TRN_API TRN_ElementReaderEnd(TRN_ElementReader r, TRN_Bool* result);
TRN_API TRN_ElementReaderGetChangesIterator(TRN_ElementReader r, TRN_Iterator* result);
TRN_API TRN_ElementReaderIsChanged(TRN_ElementReader r, enum TRN_GStateAttribute attrib, TRN_Bool* result);
TRN_API TRN_ElementReaderClearChangeList(TRN_ElementReader r);
TRN_API TRN_ElementReaderGetFont (TRN_ElementReader r, const char* name, TRN_Obj* result);
TRN_API TRN_ElementReaderGetXObject (TRN_ElementReader r, const char* name, TRN_Obj* result);
TRN_API TRN_ElementReaderGetShading(TRN_ElementReader r, const char* name, TRN_Obj* result);
TRN_API TRN_ElementReaderGetColorSpace (TRN_ElementReader r, const char* name, TRN_Obj* result);
TRN_API TRN_ElementReaderGetPattern (TRN_ElementReader r, const char* name, TRN_Obj* result);
TRN_API TRN_ElementReaderGetExtGState (TRN_ElementReader r, const char* name, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFElementReader
