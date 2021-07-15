//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFTimestampingConfiguration
#define PDFTRON_H_CPPPDFTimestampingConfiguration
#include <C/PDF/TRN_TimestampingConfiguration.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>
#include <PDF/VerificationOptions.h>
#include <PDF/TimestampingTestResult.h>

namespace pdftron { namespace PDF { 

/**
 * A class representing a set of options for timestamping a document.
 */
class TimestampingConfiguration
{
public:

	TimestampingConfiguration(const TimestampingConfiguration& other);
	TimestampingConfiguration& operator= (const TimestampingConfiguration& other);
	~TimestampingConfiguration();
	
	void Destroy();

	//methods:
	
	/**
	 * Constructor.
	 * 
	 * @param in_url -- a string representing a URL of a timestamp authority (TSA) to use during timestamping
	 */
	 TimestampingConfiguration(const UString& in_url);
	
	/**
	 * Setter to change the timestamp authority (TSA) URL to use during timestamping.
	 * 
	 * @param in_url -- a string representing a URL of a timestamp authority.
	 */
	 void SetTimestampAuthorityServerURL(const UString& in_url);
	
	/**
	 * Setter for a username to use during timestamping.
	 * 
	 * @param in_username -- a string representing a username..
	 */
	 void SetTimestampAuthorityServerUsername(const UString& in_username);
	
	/**
	 * Setter for a username to use during timestamping.
	 * 
	 * @param in_password -- a string representing a password..
	 */
	 void SetTimestampAuthorityServerPassword(const UString& in_password);
	
	/**
	 * Setter for whether to use a nonce (unique random number) during timestamping. 
	 * This is on by default, and should be on whenever a timestamp authority 
	 * supports it, because it helps prevent replay attacks.
	 *
	 * @param in_use_nonce -- a boolean value representing whether or not to use a nonce
	 */
	void SetUseNonce(bool in_use_nonce);
	
	/**
	 * Tests a timestamping configuration for usability and reports any failures. This function
	 * does not throw on many common failures, unlike the real signing, thereby allowing early 
	 * diagnosis of things like connectivity issues with timestamp authorities.
	 *
	 * @param in_opts -- a set of verification options to try to use
	 * @return A result object containing information about the status of the configuration test
	 * and any errors that occurred during it.
	 */
	TimestampingTestResult TestConfiguration(const pdftron::PDF::VerificationOptions& in_opts) const;

#ifdef SWIG
	TimestampingConfiguration();
#endif

#ifndef SWIGHIDDEN
	TimestampingConfiguration(TRN_TimestampingConfiguration impl);
	TRN_TimestampingConfiguration m_impl;
#endif

};

#include <Impl/TimestampingConfiguration.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFTimestampingConfiguration
