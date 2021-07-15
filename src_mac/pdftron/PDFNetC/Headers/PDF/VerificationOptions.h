//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFVerificationOptions
#define PDFTRON_H_CPPPDFVerificationOptions
#include <C/PDF/TRN_VerificationOptions.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace PDF { 


/**
 * Options pertaining to digital signature verification.
 */
class VerificationOptions
{
public:
	//enums:
	enum SecurityLevel {
		e_compatibility_and_archiving = 0,
		e_maximum = 1
	};
	enum TimeMode {
		e_signing = 0,
		e_timestamp = 1,
		e_current = 2
	};
	enum CertificateTrustFlag {
		e_signing_trust = 1, // analogous to "kPSSigTrustSigning" in FDF cert exchange specification. Automatically set even when not specified, just like in Acrobat.
		e_certification_trust = 2, // analogous to "kPSSigTrustAuthenticDocuments" in FDF cert exchange specification. Allows certifications using this identity to be verified.
		e_dynamic_content = 4, /* analogous to "kPSSigTrustDynamicContent" in FDF cert exchange specification. Just like in Acrobat, does not invalidate dynamic documents,
			just intended to stop viewers from allowing its use on documents which are not trusted for it. */
		e_javascript = 16, /* analogous to "kPSSigTrustJavaScript" in FDF cert exchange specification. Just like in Acrobat, does not invalidate JavaScript-containing documents,
			just intended to stop viewers from allowing its use on documents which are not trusted for it. */
		e_identity = 32, // analogous to "kPSSigTrustIdentity" in FDF cert exchange specification. If this flag is not set, all other flags are ignored, and certificate is used only for path building.
		e_trust_anchor = 64, // analogous to "kPSSigTrustAnchor" in FDF cert exchange specification. If this flag is set, paths may end with this certificate, and no revocation checks are done for it.
		e_default_trust = 97, // handy shortcut for what Acrobat does by default -- trust for everything except javascript and dynamic
		e_complete_trust = 119 // another handy shortcut for testing
	};
	VerificationOptions(const VerificationOptions& other);
	VerificationOptions(TRN_VerificationOptions impl);
	VerificationOptions& operator= (const VerificationOptions& other);
	~VerificationOptions();
	
	void Destroy();

	//methods:
	
	/**
	 * Constructs a set of options for digital signature verification.
	 * 
	 * @param level -- the general security level to use. Sets other security settings internally.
	 */
	VerificationOptions(SecurityLevel level);

	/**
	 * Adds a certificate to the store of trusted certificates inside this options object.
	 *
	 * @param in_certificate_buf -- a buffer consisting of the data of an X.509 public-key
	 * certificate encoded in binary DER (Distinguished Encoding Rules) format, or in PEM
	 * (appropriate Privacy-Enhanced Mail header+Base64 encoded DER+appropriate footer) format
	 * @param in_buf_size -- buffer size
	 * @param in_trust_flags -- a combination of trust flags (see enum CertificateTrustFlag)
	 * that determine for which situations this certificate should be trusted during trust verification.
	 * There is a default parameter value, the e_default_trust CertificateTrustFlag, which matches Acrobat's behaviour for this parameter.
	*/
	void AddTrustedCertificate(const UChar* in_certificate_buf, size_t in_buf_size, const UInt16 in_trust_flags = e_default_trust);

	/**
	 * Adds a certificate to the store of trusted certificates inside this options object, by loading it from a file.
	 * 
	 * @param in_filepath -- a path to a file containing the data of an X.509 public-key certificate encoded in binary DER (Distinguished Encoding Rules) format, or in PEM (appropriate Privacy-Enhanced Mail header+Base64 encoded DER+appropriate footer) format.
	 * @param in_trust_flags -- a combination of trust flags (see enum CertificateTrustFlag)
	 * that determine for which situations this certificate should be trusted during trust verification.
	 * There is a default parameter value, the e_default_trust CertificateTrustFlag, which matches Acrobat's behaviour for this parameter.
	 */
	void AddTrustedCertificate(const UString& in_filepath, const UInt16 in_trust_flags = e_default_trust);

	/**
	 * Bulk trust list loading API from P7C. Attempts to decode the input data as binary DER and trust multiple trusted
	 * root certificates from it. Compatible with Acrobat's .P7C format, which is a variation on PKCS #7/CMS that only
	 * contains certificates (i.e. no CRLs, no signature, etc.). If a certificate cannot be decoded, this is ignored
	 * and an attempt is made to decode the next certificate. This overload takes no account of trust-level flags
	 * because none are available in the P7C format. Therefore, when this function is used, all certificates in the
	 * P7C file will be loaded as if trusted for everything, which may lead to false positives when compared to other PDF software.
	 * (Most applications use the FDF Cert Exchange format.) The FDF-trust-list-loading function "LoadTrustList" should be
	 * used instead whenever possible.
	 *
	 * @param in_P7C_binary_DER_certificates_file_data -- the P7C-format bulk certificate data, encoded in binary DER (Distinguished Encoding Rules)
	 * @param in_size -- the size of the data, in bytes
	 */
	void AddTrustedCertificates(const UChar* in_P7C_binary_DER_certificates_file_data, const size_t in_size);
	
	/**
	 * Bulk trust list loading API with trust flag support. Loads a trust list that is
	 * structured in Acrobat's FDF Data/Cert Exchange format into the VerificationOptions
	 * certificate store. Use of this function is strongly recommended instead of the P7C
	 * API (i.e. AddTrustedCertificates). Certificates inside the FDF trust list that
	 * cannot be decoded and loaded, will be skipped.
	 *
	 * @param in_fdf_cert_exchange_data -- an FDFDoc from the FDF cert exchange data
	 */
	void LoadTrustList(const FDF::FDFDoc& in_fdf_cert_exchange_data);

	/**
	 * Sets a flag that can turn on or off the verification of the permissibility of any modifications made to the document after the signing of the digital signature being verified, in terms of the document and field permissions specified by the digital signature being verified.
	 * 
	 * @param in_on_or_off -- A boolean.
	 */
	void EnableModificationVerification(bool in_on_or_off);
	
	/**
	 * Sets a flag that can turn on or off the verification of the digest (cryptographic hash) component of a digital signature.
	 * 
	 * @param in_on_or_off -- A boolean.
	 */
	void EnableDigestVerification(bool in_on_or_off);
	
	/**
	 * Sets a flag that can turn on or off the verification of the trust status of a digital signature.
	 * 
	 * @param in_on_or_off -- A boolean.
	 */
	void EnableTrustVerification(bool in_on_or_off);

	/**
	 * Enables/disables online CRL revocation checking. The default setting is 
	 * for it to be turned off, but this may change in future versions.
	 *
	 * @note CRL checking is off by default because the technology is inherently complicated
	 * and resource-intensive, but may help improve verification rate when files are verified against 
	 * a recent reference-time (e.g. maximum security mode), because online CRLs will be valid within 
	 * that time. This mode will not be useful for old archival-type ('LTV') documents
	 * verified in archiving-and-compatibility security mode, because their online OCSP and/or CRL
	 * responder servers may not be alive anymore. However, such LTV documents can be created
	 * (if the CRL responder servers are still active) by enabling online checking, verifying, and then
	 * embedding the data using DigitalSignatureField.EnableLTVOfflineVerification.
	 *
	 * @param in_on_or_off -- what setting to use
     */

	void EnableOnlineCRLRevocationChecking(bool in_on_or_off);
	
	/**
	 * Enables/disables online OCSP revocation checking. The default setting is for it to be turned on.
	 * 
	 * @param in_on_or_off -- what setting to use.
	 */
	void EnableOnlineOCSPRevocationChecking(bool in_on_or_off);
	

	/** 
	 * Enables/disables all online revocation checking modes. The default settings are that 
	 * online OCSP is turned on and online CRL is turned off, but the default CRL setting may change in
	 * future versions. 
	 * 
	 *  @note CRL checking is off by default because the technology is inherently complicated
	 * and resource-intensive, but may help improve verification rate when files are verified against
	 * a recent reference-time (e.g. maximum security mode), because online CRLs will be valid within
	 * that time. This mode will not be useful for old archival-type ('LTV') documents
	 * verified in archiving-and-compatibility security mode, because their online OCSP and/or CRL
	 * responder servers may not be alive anymore. However, such LTV documents can be created
	 * (if the CRL responder servers are still active) by enabling online checking, verifying, and then
	 * embedding the data using DigitalSignatureField.EnableLTVOfflineVerification.
	 *
	 * @param in_on_or_off -- what setting to use
  	 */
	void EnableOnlineRevocationChecking(bool in_on_or_off);
	
#ifndef SWIGHIDDEN
	TRN_VerificationOptions m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/VerificationOptions.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFVerificationOptions
