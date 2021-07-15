//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------


#ifndef PDFTRON_H_CX501AttributeTypeAndValue
#define PDFTRON_H_CX501AttributeTypeAndValue

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_ObjectIdentifier.h>

struct TRN_X501AttributeTypeAndValue_tag;
typedef struct TRN_X501AttributeTypeAndValue_tag* TRN_X501AttributeTypeAndValue;


/* methods: */
TRN_API TRN_X501AttributeTypeAndValueGetAttributeTypeOID(TRN_X501AttributeTypeAndValue self, TRN_ObjectIdentifier* result);
TRN_API TRN_X501AttributeTypeAndValueGetStringValue(TRN_X501AttributeTypeAndValue self, TRN_UString* result);

TRN_API TRN_X501AttributeTypeAndValueDestroy(TRN_X501AttributeTypeAndValue self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CX501AttributeTypeAndValue */
