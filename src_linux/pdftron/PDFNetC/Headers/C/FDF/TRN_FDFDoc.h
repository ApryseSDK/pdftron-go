//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CFDFFDFDoc
#define PDFTRON_H_CFDFFDFDoc

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_Field.h>

TRN_API TRN_FDFDocCreate(TRN_FDFDoc* result);
TRN_API TRN_FDFDocCreateFromSDFDoc(TRN_SDFDoc no_own_sdfdoc, TRN_FDFDoc* result);
TRN_API TRN_FDFDocCreateFromFilePath (const char* filepath, TRN_FDFDoc* result);
TRN_API TRN_FDFDocCreateFromUFilePath (const TRN_UString filepath, TRN_FDFDoc* result);
TRN_API TRN_FDFDocCreateFromStream (TRN_Filter no_own_stream, TRN_FDFDoc* result);
TRN_API TRN_FDFDocCreateFromMemoryBuffer (const char* buf, TRN_Size buf_size, TRN_FDFDoc* result);
TRN_API TRN_FDFDocDestroy(TRN_FDFDoc doc);
TRN_API TRN_FDFDocIsModified(const TRN_FDFDoc doc, TRN_Bool* result); 
TRN_API TRN_FDFDocSave(TRN_FDFDoc doc, const TRN_UString path);
TRN_API TRN_FDFDocSaveMemoryBuffer(TRN_FDFDoc doc, const char** out_buf, TRN_Size* out_buf_size); 
TRN_API TRN_FDFDocGetTrailer (TRN_FDFDoc doc, TRN_Obj* result);
TRN_API TRN_FDFDocGetRoot(TRN_FDFDoc doc, TRN_Obj* result);
TRN_API TRN_FDFDocGetFDF(TRN_FDFDoc doc, TRN_Obj* result);
TRN_API TRN_FDFDocGetPDFFileName(TRN_FDFDoc doc, TRN_UString* result); 
TRN_API TRN_FDFDocSetPDFFileName(TRN_FDFDoc doc, const TRN_UString filepath); 
TRN_API TRN_FDFDocGetID(TRN_FDFDoc doc, TRN_Obj* result); 
TRN_API TRN_FDFDocSetID(TRN_FDFDoc doc, TRN_Obj id); 
TRN_API TRN_FDFDocGetFieldIteratorBegin(TRN_FDFDoc doc, TRN_Iterator* result);
TRN_API TRN_FDFDocGetFieldIterator(TRN_FDFDoc doc, const TRN_UString field_name, TRN_Iterator* result);
TRN_API TRN_FDFDocGetField(TRN_FDFDoc doc, const TRN_UString field_name, TRN_FDFField* result);
TRN_API TRN_FDFDocFieldCreate(TRN_FDFDoc doc, const TRN_UString field_name, enum TRN_FieldType type, TRN_Obj field_value, TRN_FDFField* result);
TRN_API TRN_FDFDocFieldCreateFromString(TRN_FDFDoc doc, const TRN_UString field_name, enum TRN_FieldType type, TRN_UString field_value, TRN_FDFField* result);
TRN_API TRN_FDFDocGetSDFDoc (TRN_FDFDoc doc, TRN_SDFDoc* no_own_result);
TRN_API TRN_FDFDocCreateFromXFDF(const TRN_UString file_name, TRN_FDFDoc* result);
TRN_API TRN_FDFDocSaveAsXFDF(TRN_FDFDoc doc, const TRN_UString filepath);
TRN_API TRN_FDFDocSaveAsXFDFAsString(TRN_FDFDoc doc, TRN_UString* result);
TRN_API TRN_FDFDocMergeAnnots(TRN_FDFDoc doc, const TRN_UString command_file, const TRN_UString permitted_user);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CFDFFDFDoc
