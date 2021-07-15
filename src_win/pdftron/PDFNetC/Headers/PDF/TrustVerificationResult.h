//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFTrustVerificationResult
#define PDFTRON_H_CPPPDFTrustVerificationResult
#include <C/PDF/TRN_TrustVerificationResult.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/VerificationOptions.h>
#include <PDF/PDFDoc.h>
#include <Crypto/X509Certificate.h>

namespace pdftron { namespace PDF { 
	class EmbeddedTimestampVerificationResult;

/**
 * The detailed result of a trust verification step of a verification
 * operation performed on a digital signature.
 */
class TrustVerificationResult
{
public:

	TrustVerificationResult(const TrustVerificationResult& other);
	TrustVerificationResult& operator= (const TrustVerificationResult& other);
	~TrustVerificationResult();
	
	void Destroy();

	//methods:
	
	/**
	 * Retrieves the trust verification status.
	 * 
	 * @return A boolean representing whether or not the trust verification operation was successful. Whether trust-related warnings are treated as errors or not depend on the VerificationOptions used for the verification operation.
	 */
	bool WasSuccessful() const;
	
	/**
	 * Retrieves a string representation of the details of the trust verification status.
	 * 
	 * @return A string.
	 *
	 * @note Output may change in future versions.
	 */
	UString GetResultString() const;
	
	/**
	 * Retrieves the reference-time used for trust verification as an epoch time.
	 * 
	 * @return An integral value representing an epoch time.
	 */
	Int64 GetTimeOfTrustVerification() const;
	
	/**
	 * Retrieves the type of reference-time used for trust verification.
	 * 
	 * @return An enumerated value representing the type of reference-time used for trust verification.
	 */
	VerificationOptions::TimeMode GetTimeOfTrustVerificationEnum() const;

	/**
	 * Returns whether this TrustVerificationResult has a detailed timestamp result inside.
	 * 
	 * @return a boolean value representing whether this TrustVerificationResult has a detailed timestamp result inside.
	 */
	bool HasEmbeddedTimestampVerificationResult() const;

	/**
	 * Returns the detailed timestamp result inside this TrustVerificationResult. One must call HasEmbeddedTimestampVerificationResult first to check whether the result is available.
	 * 
	 * @return an EmbeddedTimestampVerificationResult object.
	 */
	EmbeddedTimestampVerificationResult GetEmbeddedTimestampVerificationResult();	
	
    /**
	 * Retrieves the certificate path that was used for verification.
	 *
	 * @return a container of X509Certificate objects
	 */
	std::vector<Crypto::X509Certificate> GetCertPath() const;

#ifdef SWIG
	TrustVerificationResult();
#endif

#ifndef SWIGHIDDEN
	TrustVerificationResult(TRN_TrustVerificationResult impl);
	TRN_TrustVerificationResult m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

} //end pdftron
} //end PDF

#include <Impl/TrustVerificationResult.inl>

#endif //PDFTRON_H_CPPPDFTrustVerificationResult
