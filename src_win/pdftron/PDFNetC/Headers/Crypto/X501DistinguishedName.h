//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFX501DistinguishedName
#define PDFTRON_H_CPPPDFX501DistinguishedName
#include <C/Crypto/TRN_X501DistinguishedName.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>
#include <Crypto/ObjectIdentifier.h>
#include <Crypto/X501AttributeTypeAndValue.h>

namespace pdftron { namespace Crypto { 
	
/**
 * This class represents a distinguished name (DN) as defined in X.501.
 * See the X.500 standards, RFC 5280, and an OID repository for more information.
 */
class X501DistinguishedName
{
public:
	X501DistinguishedName(const X501DistinguishedName& other);
	X501DistinguishedName& operator= (const X501DistinguishedName& other);
	~X501DistinguishedName();
	
	void Destroy();

	//methods:
	
	/**
	 * Returns whether this distinguished name contains a particular attribute, identified by its object identifier (OID).
	 * 
	 * @param in_oid the object identifier representing the sought attribute.
	 * @return a boolean value representing whether this distinguished name contains the supplied attribute.
	 */
	bool HasAttribute(const ObjectIdentifier& in_oid) const;

	/**
	 * Returns a container full of string representations of all the values in this distinguished name that match a particular attribute's object identifier (OID).
	 * If an attribute's OID defines the corresponding value to not be of a string type, then that value will not be returned from this function.
	 *
	 * @param in_oid the object identifier representing the sought attribute.
	 * @return a container of string values containing any strings associated with the supplied attribute
	 */
#ifdef SWIG
	// We use an std::vector of UTF-8 std::strings for SWIG, because SWIG has trouble with mapping UString to string when it's in a vector<UString>.
	std::vector<std::string> GetStringValuesForAttribute(const ObjectIdentifier& in_oid) const;
#else
	 /**
	  * Returns a container full of string representations of all the values in this distinguished name that match a particular attribute's object identifier (OID).
	  * If an attribute's OID defines the corresponding value to not be of a string type, then that value will not be returned from this function.
	  *
	  * @param in_oid the object identifier representing the sought attribute.
	  * @return a container of string values containing any strings associated with the supplied attribute
	  */
	std::vector<UString> GetStringValuesForAttribute(const ObjectIdentifier& in_oid) const;
#endif

	/**
	 * Retrieves all of the attribute-type-to-value pairs in this distinguished name.
	 * 
	 * @return a container of X501AttributeTypeAndValue objects
	 */
	std::vector<pdftron::Crypto::X501AttributeTypeAndValue> GetAllAttributesAndValues() const;
	
#ifdef SWIG
	X501DistinguishedName();
#endif

#ifndef SWIGHIDDEN
	X501DistinguishedName(TRN_X501DistinguishedName impl);
	TRN_X501DistinguishedName m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/X501DistinguishedName.inl>
} //end Crypto
} //end pdftron


#endif //PDFTRON_H_CPPPDFX501DistinguishedName
