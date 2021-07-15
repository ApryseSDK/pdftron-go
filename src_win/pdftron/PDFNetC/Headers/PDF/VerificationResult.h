//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFVerificationResult
#define PDFTRON_H_CPPPDFVerificationResult
#include <C/PDF/TRN_VerificationResult.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

#include <Crypto/DigestAlgorithm.h>
#include <PDF/DisallowedChange.h>

#include <vector>

namespace pdftron { namespace PDF { 
	class TrustVerificationResult;

/**
 * The result of a verification operation performed on a digital signature.
 */
class VerificationResult
{
public:
	typedef pdftron::PDF::DisallowedChange DisallowedChange;
	//enums:
	enum DocumentStatus {
		e_no_error = 0,
		e_corrupt_file = 1,
		e_unsigned = 2,
		e_bad_byteranges = 3,
		e_corrupt_cryptographic_contents = 4
	};
	enum DigestStatus {
		e_digest_invalid = 0,
		e_digest_verified = 1,
		e_digest_verification_disabled = 2,
		e_weak_digest_algorithm_but_digest_verifiable = 3,
		e_no_digest_status = 4,
		e_unsupported_encoding = 5,
		e_unsupported_digest_algorithm = 6
	};
	enum TrustStatus {
		e_trust_verified = 0,
		e_untrusted = 1,
		e_trust_verification_disabled = 2,
		e_no_trust_status = 3,
		e_unsupported_trust_features = 4
	};
	enum ModificationPermissionsStatus {
		e_invalidated_by_disallowed_changes = 0,
		e_has_allowed_changes = 1,
		e_unmodified = 2,
		e_permissions_verification_disabled = 3,
		e_no_permissions_status = 4,
		e_unsupported_permissions_features = 5
	};
	VerificationResult(const VerificationResult& other);
	VerificationResult& operator= (const VerificationResult& other);
	~VerificationResult();
	
	void Destroy();

	//methods:
	
	/**
	 * Retrieves the main verification status. The main status is determined based on the other statuses.
	 * Verification may fail for many reasons; some of these reasons are the presence of features that are 
	 * not supported yet. It may be desirable for you to report unsupported signatures differently (for example, 
	 * using a question mark rather than an X mark). Any unsupported features encountered can be retrieved 
	 * by the use of the function GetUnsupportedFeatures on this class.
	 * 
	 * @return A boolean representing whether or not the verification operation was completely successful.
	 */
	bool GetVerificationStatus() const;
	
	/**
	 * Retrieves the document-related result condition associated with a digital signature verification operation.
	 * 
	 * @return A DocumentStatus-type enumeration value.
	 */
	DocumentStatus GetDocumentStatus() const;
	
	/**
	 * Retrieves the digest-related result condition associated with a digital signature verification operation.
	 * 
	 * @return A DigestStatus-type enumeration value.
	 */
	DigestStatus GetDigestStatus() const;
	
	/**
	 * Retrieves the trust-related result condition associated with a digital signature verification operation.
	 * 
	 * @return A TrustStatus-type enumeration value.
	 */
	TrustStatus GetTrustStatus() const;
	
	/**
	 * Retrieves the result condition about permissions checks performed on any unsigned modifications associated with a digital signature verification operation.
	 * 
	 * @return A ModificationPermissionsStatus-type enumeration value.
	 */
	ModificationPermissionsStatus GetPermissionsStatus() const;

	/**
	 * Returns whether there is a detailed TrustVerificationResult in this VerificationResult or not.
	 *
	 * @return A boolean.
	 */
	bool HasTrustVerificationResult() const;
	/**
	 * Retrieves the detailed result associated with the trust step of the verification operation that returned this VerificationResult, if such a detailed trust result is available. Must call HasTrustVerificationResult first and check for a true result.
	 * 
	 * @return a TrustVerificationResult object
	 *
	 * @note This function will throw if no TrustVerificationResult is available.
	 */
	TrustVerificationResult GetTrustVerificationResult() const;
	
	/** 
	 * Retrieves a list of informational structures regarding any disallowed changes that have been made to the document since the signature associated with this verification result was signed.
	 *
	 * @return a collection of DisallowedChange objects.
	 */
	std::vector<DisallowedChange> GetDisallowedChanges() const;

	/**
	 * Retrieves an enumeration value representing the digest algorithm used to sign the signature that is associated with this verification result.
	 * For DocTimeStamp signatures, returns the weakest algorithm found (between the CMS and message imprint digests).
	 *
	 * @return A DigestAlgorithm enumeration value.
	 */
	Crypto::DigestAlgorithm::Type GetDigestAlgorithm() const;
	
	/**
	 * Retrieves the document-related result condition associated with a digital signature verification operation, as a descriptive string.
	 * 
	 * @return a string.
	 */
	UString GetDocumentStatusAsString() const;
	
	/**
	 * Retrieves the digest-related result condition associated with a digital signature verification operation, as a descriptive string.
	 * 
	 * @return a string.
	 */
	UString GetDigestStatusAsString() const;
	
	/**
	 * Retrieves the trust-related result condition associated with a digital signature verification operation, as a descriptive string.
	 * 
	 * @return a string.
	 */
	UString GetTrustStatusAsString() const;
	
	/**
	 * Retrieves the result condition about permissions checks performed on any unsigned modifications associated with a digital signature verification operation, as a descriptive string.
	 * 
	 * @return a string.
	 */
	UString GetPermissionsStatusAsString() const;

	/**
	 * Retrieves reports about unsupported features encountered during verification.
	 * This function is the canonical source of information about all unsupported features encountered.
	 * Current possible values:
	 * 	"unsupported signature encoding",
	 * 	"usage rights signature",
	 * 	"legal content attestations",
	 * 	"unsupported digest algorithm"
	 *
	 * @return a container of strings representing unsupported features encountered during verification
	 *
	 * @note Output may change in future versions.
	 */
#ifdef SWIG
	// We use an std::vector of UTF-8 std::strings for SWIG, because SWIG has trouble with mapping UString to string when it's in a vector<UString>.
	std::vector<std::string> GetUnsupportedFeatures() const;
#else
	std::vector<UString> GetUnsupportedFeatures() const;
#endif

#ifdef SWIG
	VerificationResult();
#endif

#ifndef SWIGHIDDEN
	VerificationResult(TRN_VerificationResult impl);
	TRN_VerificationResult m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};


} //end pdftron
} //end PDF

#include <Impl/TrustVerificationResult.inl>

#endif //PDFTRON_H_CPPPDFVerificationResult
