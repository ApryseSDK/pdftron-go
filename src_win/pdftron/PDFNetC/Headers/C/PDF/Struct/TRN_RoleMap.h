//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFStructRoleMap
#define PDFTRON_H_CPDFStructRoleMap

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_RoleMapCreate (TRN_Obj dict, TRN_RoleMap* result);
TRN_API TRN_RoleMapCopy (const TRN_RoleMap p, TRN_RoleMap* result);
TRN_API TRN_RoleMapIsValid(const TRN_RoleMap map, TRN_Bool* result);
TRN_API TRN_RoleMapGetDirectMap(const TRN_RoleMap map, const char* type, const char** result);
TRN_API TRN_RoleMapGetSDFObj (const TRN_RoleMap map, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFStructRoleMap
