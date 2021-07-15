//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------


#ifndef PDFTRON_H_CX509Extension
#define PDFTRON_H_CX509Extension

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_ObjectIdentifier.h>

struct TRN_X509Extension_tag;
typedef struct TRN_X509Extension_tag* TRN_X509Extension;


/* methods: */
TRN_API TRN_X509ExtensionIsCritical(TRN_X509Extension self, TRN_Bool* result);
TRN_API TRN_X509ExtensionGetObjectIdentifier(TRN_X509Extension self, TRN_ObjectIdentifier* result);
TRN_API TRN_X509ExtensionToString(TRN_X509Extension self, TRN_UString* result);
TRN_API TRN_X509ExtensionGetData(TRN_X509Extension self, TRN_Vector* result);
TRN_API TRN_X509ExtensionDestroy(TRN_X509Extension self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CX509Extension */
