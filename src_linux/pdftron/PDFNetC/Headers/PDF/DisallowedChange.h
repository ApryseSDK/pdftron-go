//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFDisallowedChange
#define PDFTRON_H_CPPPDFDisallowedChange
#include <C/PDF/TRN_DisallowedChange.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace PDF { 


/**
 * The class DisallowedChange.
 * Data pertaining to a change detected in a document during a digital
 * signature modification permissions verification step, the change bein
 * g both made after the signature was signed, and disallowed by t
 * he signature's permissions settings.
 */
class DisallowedChange
{
public:
	//enums:
	enum Type {
		e_form_filled = 0,
		e_digital_signature_signed = 1,
		e_page_template_instantiated = 2,
		e_annotation_created_or_updated_or_deleted = 3,
		e_other = 4,
		e_unknown = 5
	};
	DisallowedChange();
	DisallowedChange(const DisallowedChange& other);
	DisallowedChange(TRN_DisallowedChange impl);
	DisallowedChange& operator= (const DisallowedChange& other);
	~DisallowedChange();
	
	void Destroy();

	//methods:
	
	/**
	 * Returns the SDF object number of the indirect object associated with this DisallowedChange.
	 * 
	 * @return An unsigned 32-bit integer value.
	 */
	UInt32 GetObjNum() const;
	
	/**
	 * Returns an enumeration value representing the semantic type of this disallowed change.
	 * 
	 * @return An enumeration value of type: Type of DisallowedChange.
	 */
	Type GetType() const;
	
	/**
	 * Returns a string value representing the semantic type of this disallowed change.
	 * 
	 * @return A string.
	 */
	UString GetTypeAsString() const;

#ifndef SWIGHIDDEN
	TRN_DisallowedChange m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/DisallowedChange.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFDisallowedChange
