//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFStructClassMap
#define PDFTRON_H_CPDFStructClassMap

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_ClassMapCreate(TRN_Obj dict, TRN_ClassMap* result);
TRN_API TRN_ClassMapCopy (const TRN_ClassMap p, TRN_ClassMap* result);
TRN_API TRN_ClassMapIsValid(const TRN_ClassMap map, TRN_Bool* result);
TRN_API TRN_ClassMapGetSDFObj (const TRN_ClassMap map, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFStructClassMap
