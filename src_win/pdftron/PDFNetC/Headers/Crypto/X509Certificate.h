//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFX509Certificate
#define PDFTRON_H_CPPPDFX509Certificate
#include <C/Crypto/TRN_X509Certificate.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>
#include <Crypto/DigestAlgorithm.h>
#include <Crypto/X501DistinguishedName.h>
#include <Crypto/X509Extension.h>

namespace pdftron { namespace Crypto { 

/**
 * This class represents an X509 public-key certificate, as specified in RFC 5280.
 */
class X509Certificate
{
public:
	X509Certificate(const X509Certificate& other);
	X509Certificate& operator= (const X509Certificate& other);
	~X509Certificate();
	
	void Destroy();

	//methods:
	
	/** 
	 * Retrieves the names of the certificate issuer as a map of OIDs (i.e. one of the 
	 * object identifiers from the X.500 attribute types) to string values. The issuer field 
	 * identifies the entity that has signed and issued the certificate. The returned value 
	 * will contain all of the AttributeTypeAndValue items from all of the 
	 * RelativeDistinguishedNames in the Name of the issuer. See RFC 5280, section 4.1.2.4 
	 * and Appendix A.1 (page 116). 
	 *
	 * @return an X501DistinguishedName object
	 */
	X501DistinguishedName GetIssuerField() const;
	
	/** Retrieves the names of the certificate subject as a map of OIDs (i.e. one of the 
	 * object identifiers from the X.500 attribute types) to string values. The subject field 
	 * represents the identity of the entity associated with the certificate's public key. The 
	 * returned value will contain all of the AttributeTypeAndValue items from all of the 
	 * RelativeDistinguishedNames in the Name of the subject. See RFC 5280, section 4.1.2.6 
	 * and Appendix A.1 (page 116). 
	 *
	 * @return an X501DistinguishedName object
  	 */
	X501DistinguishedName GetSubjectField() const;
	
	/** 
	 * Retrieves the notBefore time from the certificate's Validity entry in the form of an 
	 * integral value representing an epoch time. 
	 *
	 * @return an integer containing an epoch time
	 */
	Int64 GetNotBeforeEpochTime() const;
	
	/** 
	 * Retrieves the notAfter time from the certificate's Validity entry in the form of an 
	 * integral value representing an epoch time. 
	 * 
	 * @return an integer containing an epoch time
	 */
	Int64 GetNotAfterEpochTime() const;
	
	/** 
	 * Retrieves the version number representing which version of X509 the certificate corresponds to, from the certificate.
	 *
	 * @return an integer containing the version number
	 *
	 * @note The X509 version number in the certificate, which we return unchanged here, is zero-indexed and therefore is one less in value than the actual version. e.g. X509v3 is represented by a returned version number of 2.
	 */
	UInt32 GetRawX509VersionNumber() const;
	
	/**
	 * Returns a string representation of the certificate.
	 * 
	 * @return a string representation of the certificate.
	 *
	 * @note Output may change in future versions.
	 */
	UString ToString() const;
	
	 /**
	  * Retrieves, in a string, a text representation of a cryptographically-secure digest of the certificate that can be used to identify it uniquely.
	  *
	  * @param in_digest_algorithm An enumeration representing the digest algorithm to use. Currently supported are SHA-1 (SHA-160), SHA-256, SHA-384, and SHA-512.
	  *
	  * @return a string representation of the fingerprint, in the form of double ASCII characters representing hex bytes, separated by colons
	  *
	  * @note Default algorithm parameter is currently SHA-256, but may change in future without further warning, pursuant to security needs.
	  */
	UString GetFingerprint(const enum DigestAlgorithm::Type in_digest_algorithm = DigestAlgorithm::e_SHA256) const;
    
	/**
	 * Retrieves the serialNumber entry from the certificate.
	 * 
	 * @return a big-integer-style container holding bytes representing the components of an integral serial number in big-endian order.
	 */
	std::vector<UChar> GetSerialNumber() const;
	
	/**
	 * Retrieves all extensions (as first specified in V3 of X509, see RFC 5280) from the certificate.
	 * 
	 * @return a container of X509Extension objects.
	 */
	std::vector<X509Extension> GetExtensions() const;
	
	/**
	 * Retrieves the certificate as binary DER-encoded data. (DER is short for Distinguished Encoding Rules.).
	 * 
	 * @return a container of bytes representing the certificate, encoded as binary DER.
	 */
	std::vector<UChar> GetData() const;

#ifdef SWIG
	X509Certificate();
#endif

#ifndef SWIGHIDDEN
	X509Certificate(TRN_X509Certificate impl);
	TRN_X509Certificate m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/X509Certificate.inl>
} //end Crypto
} //end pdftron


#endif //PDFTRON_H_CPPPDFX509Certificate
