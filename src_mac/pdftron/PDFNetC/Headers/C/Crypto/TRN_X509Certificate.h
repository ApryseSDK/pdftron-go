//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CX509Certificate
#define PDFTRON_H_CX509Certificate

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_X501DistinguishedName.h>
#include <C/Crypto/TRN_DigestAlgorithm.h>

struct TRN_X509Certificate_tag;
typedef struct TRN_X509Certificate_tag* TRN_X509Certificate;


/* methods: */
TRN_API TRN_X509CertificateGetIssuerField(TRN_X509Certificate self, TRN_X501DistinguishedName* result);
TRN_API TRN_X509CertificateGetSubjectField(TRN_X509Certificate self, TRN_X501DistinguishedName* result);
TRN_API TRN_X509CertificateGetNotBeforeEpochTime(TRN_X509Certificate self, TRN_Int64* result);
TRN_API TRN_X509CertificateGetNotAfterEpochTime(TRN_X509Certificate self, TRN_Int64* result);
TRN_API TRN_X509CertificateGetRawX509VersionNumber(TRN_X509Certificate self, TRN_UInt32* result);
TRN_API TRN_X509CertificateToString(TRN_X509Certificate self, TRN_UString* result);
TRN_API TRN_X509CertificateGetFingerprint(TRN_X509Certificate self, enum TRN_DigestAlgorithm_Type in_digest_algorithm, TRN_UString* result);
TRN_API TRN_X509CertificateGetSerialNumber(TRN_X509Certificate self, TRN_Vector* result);
TRN_API TRN_X509CertificateGetExtensions(TRN_X509Certificate self, TRN_Vector* result);
TRN_API TRN_X509CertificateGetData(TRN_X509Certificate self, TRN_Vector* result);
TRN_API TRN_X509CertificateDestroy(TRN_X509Certificate self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CX509Certificate */
