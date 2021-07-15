//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFCOCGOCG
#define PDFTRON_H_CPDFCOCGOCG

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_OCGCreate(TRN_PDFDoc pdfdoc, const TRN_UString name, TRN_OCG* result);
TRN_API TRN_OCGCreateFromObj(TRN_Obj ocg_dict, TRN_OCG* result);
TRN_API TRN_OCGCopy(const TRN_OCG ocg, TRN_OCG* result);
TRN_API TRN_OCGGetSDFObj (const TRN_OCG ocg, TRN_Obj* result);
TRN_API TRN_OCGIsValid(const TRN_OCG ocg, TRN_Bool* result);

TRN_API TRN_OCGGetName(const TRN_OCG c, TRN_UString* result);
TRN_API TRN_OCGSetName(const TRN_OCG c, TRN_UString value);

TRN_API TRN_OCGGetIntent(const TRN_OCG c, TRN_Obj* result);
TRN_API TRN_OCGSetIntent(const TRN_OCG c, TRN_Obj value);

TRN_API TRN_OCGHasUsage(const TRN_OCG c, TRN_Bool* result);
TRN_API TRN_OCGGetUsage(const TRN_OCG c, const char* key, TRN_Obj* result);

TRN_API TRN_OCGGetCurrentState(const TRN_OCG c, const TRN_OCGContext ctx, TRN_Bool* result);
TRN_API TRN_OCGSetCurrentState(const TRN_OCG c, const TRN_OCGContext ctx, TRN_Bool state);

TRN_API TRN_OCGGetInitialState(const TRN_OCG c, const TRN_OCGConfig cfg, TRN_Bool* result);
TRN_API TRN_OCGSetInitialState(const TRN_OCG c, const TRN_OCGConfig cfg, TRN_Bool state);

TRN_API TRN_OCGIsLocked(const TRN_OCG c, const TRN_OCGConfig cfg, TRN_Bool* result);
TRN_API TRN_OCGSetLocked(const TRN_OCG c, const TRN_OCGConfig cfg, TRN_Bool state);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFCOCGOCG
