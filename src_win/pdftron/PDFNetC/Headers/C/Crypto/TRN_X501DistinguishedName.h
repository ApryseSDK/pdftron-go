//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CX501DistinguishedName
#define PDFTRON_H_CX501DistinguishedName

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_ObjectIdentifier.h>

struct TRN_X501DistinguishedName_tag;
typedef struct TRN_X501DistinguishedName_tag* TRN_X501DistinguishedName;


/* methods: */
TRN_API TRN_X501DistinguishedNameHasAttribute(TRN_X501DistinguishedName self, TRN_ObjectIdentifier in_oid, TRN_Bool* result);
TRN_API TRN_X501DistinguishedNameGetStringValuesForAttribute(TRN_X501DistinguishedName self, TRN_ObjectIdentifier in_oid, TRN_Vector* result);
TRN_API TRN_X501DistinguishedNameGetAllAttributesAndValues(TRN_X501DistinguishedName self, TRN_Vector* result);

TRN_API TRN_X501DistinguishedNameDestroy(TRN_X501DistinguishedName self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CX501DistinguishedName */
