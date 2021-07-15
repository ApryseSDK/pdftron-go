//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFFileSpec
#define PDFTRON_H_CPDFFileSpec

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_FileSpecCreate(TRN_SDFDoc doc, const TRN_UString path, TRN_Bool embed, TRN_FileSpec* result);
TRN_API TRN_FileSpecCreateURL(TRN_SDFDoc doc, const char* url, TRN_FileSpec* result);
TRN_API TRN_FileSpecCreateFromObj(TRN_Obj f, TRN_FileSpec* result);
TRN_API TRN_FileSpecCopy (const TRN_FileSpec d, TRN_FileSpec* result);
TRN_API TRN_FileSpecCompare(TRN_FileSpec fs, const TRN_FileSpec d, TRN_Bool* result);
TRN_API TRN_FileSpecIsValid(const TRN_FileSpec fs, TRN_Bool* result);
TRN_API TRN_FileSpecExport(const TRN_FileSpec fs, const TRN_UString save_as, TRN_Bool* result);
TRN_API TRN_FileSpecGetFileData(const TRN_FileSpec fs, TRN_Filter* no_own_result);
TRN_API TRN_FileSpecGetFilePath(const TRN_FileSpec fs,TRN_UString* result);
TRN_API TRN_FileSpecSetDesc(const TRN_FileSpec fs, const TRN_UString desc);
TRN_API TRN_FileSpecGetSDFObj (const TRN_FileSpec fs, TRN_Obj* result) ;


#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFFileSpec
