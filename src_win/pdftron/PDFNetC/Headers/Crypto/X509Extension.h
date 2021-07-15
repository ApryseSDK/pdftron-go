//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------


#ifndef PDFTRON_H_CPPPDFX509Extension
#define PDFTRON_H_CPPPDFX509Extension
#include <C/Crypto/TRN_X509Extension.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace Crypto { 
	
/**
 * This class represents an X509v3 certificate extension. See RFC 5280 as a specification.
 */
class X509Extension
{
public:
	X509Extension(const X509Extension& other);
	X509Extension& operator= (const X509Extension& other);
	void Destroy();

	//methods:
	
	/**
	 * Retrieves whether the extension is 'critical'. See RFC 5280 for an explanation of what this means.
	 * 
	 * @return a boolean representing the criticality flag of the extension.
	 */
	bool IsCritical() const;
	
	/**
	 * Retrieves the OID (object identifier) of the extension in the form of integer components in a container. The meaning of an OID can be determined from an OID repository.
	 * 
	 * @return an ObjectIdentifier object.
	 */
	ObjectIdentifier GetObjectIdentifier() const;
	
	/**
	 * Returns a string representation of the extension.
	 * 
	 * @return a string representation of the extension.
	 *
	 * @note Output may change in future versions.
	 */
	UString ToString() const;

	/**
	 * Retrieves the raw binary DER-encoded data of the extension. (DER is short for Distinguished Encoding Rules.)
	 *
	 * @return a container holding the bytes of the extension in the form of binary DER-encoded data
	 */
	std::vector<UChar> GetData() const;

	~X509Extension();

#ifdef SWIG
	X509Extension();
#endif

#ifndef SWIGHIDDEN
	X509Extension(TRN_X509Extension impl);
	TRN_X509Extension m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/X509Extension.inl>
} //end Crypto
} //end pdftron


#endif //PDFTRON_H_CPPPDFX509Extension
