//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFTimestampingTestResult
#define PDFTRON_H_CPPPDFTimestampingTestResult
#include <C/PDF/TRN_TimestampingTestResult.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace PDF { 

class EmbeddedTimestampVerificationResult;

/**
 * A class representing the result of testing a timestamping configuration.
 */
class TimestampingTestResult
{
public:

	TimestampingTestResult(const TimestampingTestResult& other);
	TimestampingTestResult& operator= (const TimestampingTestResult& other);
	~TimestampingTestResult();
	
	void Destroy();

	//methods:
	
	/**
	 * Retrieves the overall status of the timestamping configuration testing operation.
	 * 
	 * @return a boolean value representing the status.
	 */
	bool GetStatus() const;
	
	/**
	 * Retrieves a result message regarding the timestamping configuration testing operation.
	 * 
	 * @return a string result message. 
	 * @note Output may change in future versions.
	 */
	UString GetString() const;

	/**
	 * Returns whether a timestamp response verification result is available. This means
	 * that false will be returned when a timestamp response was not received or was empty
	 * (e.g. network failures, improper server configuration, bad URL, etc.). This function
	 * should be called to check for the availability of a verification result before actually
	 * attempting to retrieve one using GetResponseVerificationResult (which throws if a result is not
	 * available).
	 *
	 * @return whether a timestamp response verification result is available
	 */
	bool HasResponseVerificationResult() const;
	
	/**
	 * If a timestamp response was successfully retrieved from a timestamp authority, returns
	 * the result of verifying it. If a timestamp response was not received, throws. One should
	 * call HasResponseVerificationResult first to see if a detailed result is available before calling
	 * this function.
	 * 
	 * @return a timestamp response verification result
	 */
	EmbeddedTimestampVerificationResult GetResponseVerificationResult() const;

#ifdef SWIG
	TimestampingTestResult();
#endif

#ifndef SWIGHIDDEN
	TimestampingTestResult(TRN_TimestampingTestResult impl);
	TRN_TimestampingTestResult m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/TimestampingTestResult.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFTimestampingTestResult
