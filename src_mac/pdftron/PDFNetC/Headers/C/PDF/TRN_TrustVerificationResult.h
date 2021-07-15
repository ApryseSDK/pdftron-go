//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CTrustVerificationResult
#define PDFTRON_H_CTrustVerificationResult

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/PDF/TRN_VerificationOptions.h>
#include <C/PDF/TRN_EmbeddedTimestampVerificationResult.h>


/* methods: */
TRN_API TRN_TrustVerificationResultWasSuccessful(TRN_TrustVerificationResult self, TRN_Bool* result);
TRN_API TRN_TrustVerificationResultGetResultString(TRN_TrustVerificationResult self, TRN_UString* result);
TRN_API TRN_TrustVerificationResultGetTimeOfTrustVerification(TRN_TrustVerificationResult self, TRN_Int64* result);
TRN_API TRN_TrustVerificationResultGetTimeOfTrustVerificationEnum(TRN_TrustVerificationResult self, enum TRN_VerificationOptions_TimeMode* result);
TRN_API TRN_TrustVerificationResultHasEmbeddedTimestampVerificationResult(TRN_TrustVerificationResult self, TRN_Bool* result);
TRN_API TRN_TrustVerificationResultDestroy(TRN_TrustVerificationResult self);
TRN_API TRN_TrustVerificationResultGetEmbeddedTimestampVerificationResult(TRN_TrustVerificationResult self, TRN_EmbeddedTimestampVerificationResult* result);
TRN_API TRN_TrustVerificationResultGetCertPath(TRN_TrustVerificationResult self,  TRN_Vector* result);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CTrustVerificationResult */
