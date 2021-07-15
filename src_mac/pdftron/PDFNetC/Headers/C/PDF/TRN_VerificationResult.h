//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CVerificationResult
#define PDFTRON_H_CVerificationResult

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_DigestAlgorithm.h>

/* enums:  */
enum TRN_VerificationResult_DocumentStatus {
	e_VerificationResult_no_error = 0,
	e_VerificationResult_corrupt_file = 1,
	e_VerificationResult_unsigned = 2,
	e_VerificationResult_bad_byteranges = 3,
	e_VerificationResult_corrupt_cryptographic_contents = 4
};
enum TRN_VerificationResult_DigestStatus {
	e_VerificationResult_digest_invalid = 0,
	e_VerificationResult_digest_verified = 1,
	e_VerificationResult_digest_verification_disabled = 2,
	e_VerificationResult_weak_digest_algorithm_but_digest_verifiable = 3,
	e_VerificationResult_no_digest_status = 4,
	e_VerificationResult_unsupported_encoding = 5
};
enum TRN_VerificationResult_TrustStatus {
	e_VerificationResult_trust_verified = 0,
	e_VerificationResult_untrusted = 1,
	e_VerificationResult_trust_verification_disabled = 2,
	e_VerificationResult_no_trust_status = 3
};
enum TRN_VerificationResult_ModificationPermissionsStatus {
	e_VerificationResult_invalidated_by_disallowed_changes = 0,
	e_VerificationResult_has_allowed_changes = 1,
	e_VerificationResult_unmodified = 2,
	e_VerificationResult_permissions_verification_disabled = 3,
	e_VerificationResult_no_permissions_status = 4
};

/* methods: */
TRN_API TRN_VerificationResultGetDigitalSignatureField(TRN_VerificationResult self, TRN_DigitalSignatureField* result);
TRN_API TRN_VerificationResultGetVerificationStatus(TRN_VerificationResult self, TRN_Bool* result);
TRN_API TRN_VerificationResultGetDocumentStatus(TRN_VerificationResult self, enum TRN_VerificationResult_DocumentStatus* result);
TRN_API TRN_VerificationResultGetDigestStatus(TRN_VerificationResult self, enum TRN_VerificationResult_DigestStatus* result);
TRN_API TRN_VerificationResultGetTrustStatus(TRN_VerificationResult self, enum TRN_VerificationResult_TrustStatus* result);
TRN_API TRN_VerificationResultGetPermissionsStatus(TRN_VerificationResult self, enum TRN_VerificationResult_ModificationPermissionsStatus* result);
TRN_API TRN_VerificationResultGetTrustVerificationResult(TRN_VerificationResult self, TRN_TrustVerificationResult* result);
TRN_API TRN_VerificationResultHasTrustVerificationResult(TRN_VerificationResult self, TRN_Bool* result);
TRN_API TRN_VerificationResultGetDisallowedChanges(TRN_VerificationResult self, TRN_Vector* result);
TRN_API TRN_VerificationResultGetDigestAlgorithm(TRN_VerificationResult self, enum TRN_DigestAlgorithm_Type* result);
TRN_API TRN_VerificationResultGetDocumentStatusAsString(TRN_VerificationResult self, TRN_UString* result);
TRN_API TRN_VerificationResultGetDigestStatusAsString(TRN_VerificationResult self, TRN_UString* result);
TRN_API TRN_VerificationResultGetTrustStatusAsString(TRN_VerificationResult self, TRN_UString* result);
TRN_API TRN_VerificationResultGetPermissionsStatusAsString(TRN_VerificationResult self, TRN_UString* result);
TRN_API TRN_VerificationResultGetUnsupportedFeatures(TRN_VerificationResult self, TRN_Vector* result);

TRN_API TRN_VerificationResultDestroy(TRN_VerificationResult self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CVerificationResult */
