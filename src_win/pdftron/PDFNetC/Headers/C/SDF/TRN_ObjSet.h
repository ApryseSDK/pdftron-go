//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CSDFObjSet
#define PDFTRON_H_CSDFObjSet

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_ObjSetCreate(TRN_ObjSet* result);
TRN_API TRN_ObjSetDestroy(TRN_ObjSet set);

TRN_API TRN_ObjSetCreateName(TRN_ObjSet set, const char* name, TRN_Obj* result);
TRN_API TRN_ObjSetCreateArray(TRN_ObjSet set, TRN_Obj* result);
TRN_API TRN_ObjSetCreateBool(TRN_ObjSet set, TRN_Bool value, TRN_Obj* result);
TRN_API TRN_ObjSetCreateDict(TRN_ObjSet set, TRN_Obj* result);
TRN_API TRN_ObjSetCreateNull(TRN_ObjSet set, TRN_Obj* result);
TRN_API TRN_ObjSetCreateNumber(TRN_ObjSet set, double value, TRN_Obj* result);
TRN_API TRN_ObjSetCreateString(TRN_ObjSet set, TRN_UString value, TRN_Obj* result);
TRN_API TRN_ObjSetCreateFromJson(TRN_ObjSet set, TRN_UString json, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CSDFObjSet
