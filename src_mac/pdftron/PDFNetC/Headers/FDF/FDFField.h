//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPFDFFDFField
#define PDFTRON_H_CPPFDFFDFField

#include <SDF/Obj.h>
#include <C/FDF/TRN_FDFField.h>

namespace pdftron { 
	namespace FDF {


class FDFField
{
public: 

	/** 
	 * Construct a FDF::FDFField from a SDF dictionary representing a terminal field node.
	 */ 
	FDFField (SDF::Obj field_dict = 0, SDF::Obj fdf_dict = 0);

	FDFField (const FDFField& p);
	FDFField& operator= (const FDFField& p);

	/** 
	 * @return the value of the Field (the value of its /V key) or NULL if the 
	 * value is not specified. 
	 * The format of field's value varies depending on the field type.
	 */
	SDF::Obj GetValue();

	/** 
	 * Sets the value of the FDFField (the value of the field's /V key).
	 * @param value - the value to set the FDFField to
	 *
	 * @note in order to remove/erase the existing value use SetValue(SDF::Null)
	 */
	void SetValue(SDF::Obj value);

	/** 
	 * @return a string representing the fully qualified name of the field 
	 * (e.g. "employee.name.first").
	 */
	UString GetName();

	/** 
	 * @return a string representing the partial name of the field (e.g. 
	 * "first" when "employee.name.first" is fully qualified name).
	 */
	UString GetPartialName();
    
	/**
	 * @return the object to the underlying SDF/Cos object.
	 */
	SDF::Obj GetSDFObj () const;

	/**
	 * The function returns the specified attribute.
	 * @param attrib - name of the attribute to find
	 * @return return the attribute value if the given attribute name
	 * was found or a NULL object if the given attribute name was not found.
	 */
	SDF::Obj FindAttribute (const char* attrib) const;

	 /** 
	  * @return true if the object is not null, false otherwise.  
	  */ 
	 operator bool () { return m_field.mp_leaf_node!=0;}

private:
	TRN_FDFField m_field;
};



#include <Impl/FDFField.inl>

	};	// namespace FDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPFDFFDFField
