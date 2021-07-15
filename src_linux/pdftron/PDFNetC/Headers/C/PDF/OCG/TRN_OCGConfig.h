//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFOCGOCGConfig
#define PDFTRON_H_CPDFOCGOCGConfig

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_OCGConfigCreateFromObj(TRN_Obj dict, TRN_OCGConfig* result);
TRN_API TRN_OCGConfigCreate(TRN_PDFDoc pdfdoc, TRN_Bool default_config, TRN_OCGConfig* result);
TRN_API TRN_OCGConfigCopy(const TRN_OCGConfig c, TRN_OCGConfig* result);
TRN_API TRN_OCGConfigGetSDFObj (const TRN_OCGConfig c, TRN_Obj* result);

TRN_API TRN_OCGConfigGetOrder(const TRN_OCGConfig c, TRN_Obj* result);
TRN_API TRN_OCGConfigSetOrder(const TRN_OCGConfig c, TRN_Obj value);

TRN_API TRN_OCGConfigGetName(const TRN_OCGConfig c, TRN_UString* result);
TRN_API TRN_OCGConfigSetName(const TRN_OCGConfig c, TRN_UString value);

TRN_API TRN_OCGConfigGetCreator(const TRN_OCGConfig c, TRN_UString* result);
TRN_API TRN_OCGConfigSetCreator(const TRN_OCGConfig c, TRN_UString value);

TRN_API TRN_OCGConfigGetInitBaseState(const TRN_OCGConfig c, const char** result);
TRN_API TRN_OCGConfigSetInitBaseState(const TRN_OCGConfig c, const char* value);

TRN_API TRN_OCGConfigGetCreator(const TRN_OCGConfig c, TRN_UString* result);
TRN_API TRN_OCGConfigSetCreator(const TRN_OCGConfig c, TRN_UString value);

TRN_API TRN_OCGConfigGetInitOnStates(const TRN_OCGConfig c, TRN_Obj* result);
TRN_API TRN_OCGConfigSetInitOnStates(const TRN_OCGConfig c, TRN_Obj value);

TRN_API TRN_OCGConfigGetInitOffStates(const TRN_OCGConfig c, TRN_Obj* result);
TRN_API TRN_OCGConfigSetInitOffStates(const TRN_OCGConfig c, TRN_Obj value);

TRN_API TRN_OCGConfigGetIntent(const TRN_OCGConfig c, TRN_Obj* result);
TRN_API TRN_OCGConfigSetIntent(const TRN_OCGConfig c, TRN_Obj value);

TRN_API TRN_OCGConfigGetLockedOCGs(const TRN_OCGConfig c, TRN_Obj* result);
TRN_API TRN_OCGConfigSetLockedOCGs(const TRN_OCGConfig c, TRN_Obj value);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFOCGOCGConfig
