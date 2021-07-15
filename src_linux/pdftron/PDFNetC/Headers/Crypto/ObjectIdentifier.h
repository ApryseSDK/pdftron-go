//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFObjectIdentifier
#define PDFTRON_H_CPPPDFObjectIdentifier
#include <C/Crypto/TRN_ObjectIdentifier.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace Crypto { 
/**
 * This class represents an object identifier (OID), as defined by ITU and used in X.509.
 */
class ObjectIdentifier
{
public:
	//enums:
	enum Predefined {
		e_commonName = 0,
		e_surname = 1,
		e_countryName = 2,
		e_localityName = 3,
		e_stateOrProvinceName = 4,
		e_streetAddress = 5,
		e_organizationName = 6,
		e_organizationalUnitName = 7
	};

	ObjectIdentifier(const ObjectIdentifier& other);
	ObjectIdentifier& operator= (const ObjectIdentifier& other);
	~ObjectIdentifier();
	
	void Destroy();

	//methods:
	
	/**
	 * Constructs an ObjectIdentifier from an enum.
	 * 
	 * @param in_oid_enum the enumerated value to use
	 * 
	 * @note Not all possible OID values are available as enum values.
	 */
	ObjectIdentifier(const Predefined in_oid_enum);

	
	/** 
	 * Constructor from array of unsigned integer components of an object identifier.
	 * 
	 * @param in_arr -- a pointer to an array of integers to use
	 * @param in_size -- the number of items items in the array
	 */
	ObjectIdentifier(const UInt32* in_arr, const size_t in_size);

	/**
	 * Retrieves the value of the object identifier.
	 * 
	 * @return the value of the object identifier, as a container of integer components.
	 */
	std::vector<UInt32> GetRawValue() const;

#ifdef SWIG
	ObjectIdentifier();
#endif

#ifndef SWIGHIDDEN
	ObjectIdentifier(TRN_ObjectIdentifier impl);
	TRN_ObjectIdentifier m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/ObjectIdentifier.inl>
} //end Crypto
} //end pdftron


#endif //PDFTRON_H_CPPPDFObjectIdentifier
