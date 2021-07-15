//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFEmbeddedTimestampVerificationResult
#define PDFTRON_H_CPPPDFEmbeddedTimestampVerificationResult
#include <C/PDF/TRN_EmbeddedTimestampVerificationResult.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>
#include <PDF/VerificationResult.h>
#include <PDF/TrustVerificationResult.h>
#include <Crypto/DigestAlgorithm.h>


namespace pdftron { namespace PDF { 

/**
 * This class represents the result of verifying a secure embedded
 * timestamp digital signature.
 */
class EmbeddedTimestampVerificationResult
{
public:
	EmbeddedTimestampVerificationResult(const EmbeddedTimestampVerificationResult& other);
	EmbeddedTimestampVerificationResult& operator= (const EmbeddedTimestampVerificationResult& other);
	~EmbeddedTimestampVerificationResult();
	void Destroy();

	//methods:
	
	/**
	 * Retrieves the main verification status. The main status is determined based on the other statuses.
	 * 
	 * @return A boolean representing whether or not the verification operation was completely successful.
	 */
	bool GetVerificationStatus() const;
	
	/**
	 * Retrieves the result condition associated with the CMS signed digest verification step.
	 * 
	 * @return A DigestStatus-type enumeration value.
	 */
	VerificationResult::DigestStatus GetCMSDigestStatus() const;
	
	/**
	 * Retrieves the result condition associated with the message imprint digest verification step.
	 * 
	 * @return A DigestStatus-type enumeration value.
	 */
	VerificationResult::DigestStatus GetMessageImprintDigestStatus() const;
	
	/**
	 * Retrieves the result condition associated with the trust verification step.
	 * 
	 * @return A TrustStatus-type enumeration value.
	 */
	VerificationResult::TrustStatus GetTrustStatus() const;
	
	/**
	 * Retrieves the result condition associated with the CMS signed digest verification step, as a descriptive string.
	 * 
	 * @return a string
	 * 
	 * @note Output may change in future versions.
	 */
	UString GetCMSDigestStatusAsString() const;
	
	/**
	 * Retrieves the result condition associated with the message imprint digest verification step, as a descriptive string.
	 * 
	 * @return a string
	 * 
	 * @note Output may change in future versions.
	 */
	UString GetMessageImprintDigestStatusAsString() const;
	
	/**
	 * Retrieves the result condition associated with the trust verification step, as a descriptive string.
	 * 
	 * @return a string 
	 * 
	 * @note Output may change in future versions.
	 */
	UString GetTrustStatusAsString() const;
	
	/**
	 * Returns whether there is a detailed TrustVerificationResult in this EmbeddedTimestampVerificationResult.
	 * 
	 * @return A boolean
	 */
	bool HasTrustVerificationResult() const;
	
	/**
	 * Retrieves the detailed result associated with the trust step of the verification operation that returned this EmbeddedTimestampVerificationResult, 
	 * if such a detailed trust result is available. Must call HasTrustVerificationResult first and check for a true result.  
	 * @note This function will throw if there is no trust result available.
	 * 
	 * @return A TrustVerificationResult object.
	 */
	TrustVerificationResult GetTrustVerificationResult() const;
	
	/**
	 * Retrieves an enumeration value representing the digest algorithm used to sign the timestamp token.
	 * 
	 * @return A DigestAlgorithm enumeration value.
	 */
	Crypto::DigestAlgorithm::Type GetCMSSignatureDigestAlgorithm() const;
	
	/**
	 * Retrieves an enumeration value representing the digest algorithm used inside the message imprint field of the timestamp to digest the main signature value.
	 * 
	 * @return A DigestAlgorithm enumeration value.
	 */
	Crypto::DigestAlgorithm::Type GetMessageImprintDigestAlgorithm() const;
	
#ifdef SWIG
	/**
	 * Retrieves reports about unsupported features encountered during verification of the timestamp.
	 * Current possible values:
	 * 	"GeneralizedTime format with length <number greater than 15>",
	 * 	"unsupported digest algorithm"
	 *
	 * @return a container of strings representing unsupported features encountered during verification of the timestamp
	 *
	 * @note Output may change in future versions.
	 */
	// We use an std::vector of UTF-8 std::strings for SWIG, because SWIG has trouble with mapping UString to string when it's in a vector<UString>.
	std::vector<std::string> GetUnsupportedFeatures() const;
#else
	/**
	 * Retrieves reports about unsupported features encountered during verification of the timestamp.
	 * Current possible values:
	 * 	"GeneralizedTime format with length <number greater than 15>",
	 * 	"unsupported digest algorithm"
	 *
	 * @return a container of strings representing unsupported features encountered during verification of the timestamp
	 *
	 * @note Output may change in future versions.
	 */
	std::vector<UString> GetUnsupportedFeatures() const;
#endif

#ifdef SWIG
	EmbeddedTimestampVerificationResult();
#endif

#ifndef SWIGHIDDEN
	EmbeddedTimestampVerificationResult(TRN_EmbeddedTimestampVerificationResult impl);
	TRN_EmbeddedTimestampVerificationResult m_impl;
#endif

private:
#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

} //end pdftron
} //end PDF


#include <Impl/TrustVerificationResult.inl>

#endif //PDFTRON_H_CPPPDFEmbeddedTimestampVerificationResult
