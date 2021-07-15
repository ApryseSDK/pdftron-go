//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFX501AttributeTypeAndValue
#define PDFTRON_H_CPPPDFX501AttributeTypeAndValue
#include <C/Crypto/TRN_X501AttributeTypeAndValue.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>
#include <Crypto/ObjectIdentifier.h>

namespace pdftron { namespace Crypto { 


/**
  * This class represents an AttributeTypeAndValue as mentioned in RFC 5280 in the context of DistinguishedNames and as defined in ITU X.501.
 */
class X501AttributeTypeAndValue
{
public:
	X501AttributeTypeAndValue(const X501AttributeTypeAndValue& other);
	X501AttributeTypeAndValue& operator= (const X501AttributeTypeAndValue& other);

	void Destroy();

	//methods:
	
	/**
	 * Retrieves the OID (i.e. one of the object identifiers from the X.500 attribute types) in the form of integer components in a container.
	 * 
	 * @return an ObjectIdentifier object.
	 */
	ObjectIdentifier GetAttributeTypeOID() const;
	
	/**
	 * Retrieves the value associated with the contained OID (object identifier) as a string, if the value is defined by the OID to be of a string type.
	 * 
	 * @return a string containing the string value.
	 */
	UString GetStringValue() const;

	~X501AttributeTypeAndValue();

#ifdef SWIG
	X501AttributeTypeAndValue();
#endif

#ifndef SWIGHIDDEN
	X501AttributeTypeAndValue(TRN_X501AttributeTypeAndValue impl);
	TRN_X501AttributeTypeAndValue m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/X501AttributeTypeAndValue.inl>
} //end Crypto
} //end pdftron


#endif //PDFTRON_H_CPPPDFX501AttributeTypeAndValue
