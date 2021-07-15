//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CEmbeddedTimestampVerificationResult
#define PDFTRON_H_CEmbeddedTimestampVerificationResult

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/PDF/TRN_VerificationResult.h>
#include <C/Crypto/TRN_DigestAlgorithm.h>

/* methods: */
TRN_API TRN_EmbeddedTimestampVerificationResultGetVerificationStatus(TRN_EmbeddedTimestampVerificationResult self, TRN_Bool* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetCMSDigestStatus(TRN_EmbeddedTimestampVerificationResult self, TRN_VerificationResult_DigestStatus* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetMessageImprintDigestStatus(TRN_EmbeddedTimestampVerificationResult self, TRN_VerificationResult_DigestStatus* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetTrustStatus(TRN_EmbeddedTimestampVerificationResult self, TRN_VerificationResult_TrustStatus* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetCMSDigestStatusAsString(TRN_EmbeddedTimestampVerificationResult self, TRN_UString* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetMessageImprintDigestStatusAsString(TRN_EmbeddedTimestampVerificationResult self, TRN_UString* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetTrustStatusAsString(TRN_EmbeddedTimestampVerificationResult self, TRN_UString* result);
TRN_API TRN_EmbeddedTimestampVerificationResultHasTrustVerificationResult(TRN_EmbeddedTimestampVerificationResult self, TRN_Bool* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetTrustVerificationResult(TRN_EmbeddedTimestampVerificationResult self, TRN_TrustVerificationResult* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetCMSSignatureDigestAlgorithm(TRN_EmbeddedTimestampVerificationResult self, TRN_DigestAlgorithm_Type* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetMessageImprintDigestAlgorithm(TRN_EmbeddedTimestampVerificationResult self, TRN_DigestAlgorithm_Type* result);
TRN_API TRN_EmbeddedTimestampVerificationResultGetUnsupportedFeatures(TRN_EmbeddedTimestampVerificationResult self, TRN_Vector* result);

TRN_API TRN_EmbeddedTimestampVerificationResultDestroy(TRN_EmbeddedTimestampVerificationResult self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CEmbeddedTimestampVerificationResult */
