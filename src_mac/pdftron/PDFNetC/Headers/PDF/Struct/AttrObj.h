//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAttrObj
#define PDFTRON_H_CPPPDFAttrObj

#include <SDF/Obj.h>
#include <C/PDF/Struct/TRN_AttrObj.h>

namespace pdftron { 
	namespace PDF {
		namespace Struct {

/**
 * An application or plug-in extension that processes logical structure can attach 
 * additional information, called attributes, to any structure element. 
 * The attribute information is held in one or more attribute objects associated 
 * with the structure element. An attribute object is a dictionary or stream 
 * that includes an entry identifying the application or plug-in that owns the 
 * attribute information. Other entries represent the attributes: the keys are 
 * attribute names, and values are the corresponding attribute values.
 */ 
class AttrObj
{
public: 

	/**
	 * Initialize a AttrObj using an existing low-level Cos/SDF object.
	 * 
	 * @param dict - a low-level (SDF/Cos) dictionary representing the attribute object. 
	 *
	 * @note This constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 */
	 AttrObj (SDF::Obj dict = SDF::Obj(0));
	
	 AttrObj (const AttrObj& a);
	 AttrObj& operator= (const AttrObj& a);

	/** 
	 * @return The name of the application or plug-in extension owning the 
	 * attribute data. 
	 */
	 const char* GetOwner() const;

	/**
	 * @return Pointer to the underlying SDF/Cos object.
	 */
	 SDF::Obj GetSDFObj () const;

private:
	TRN_AttrObj mp_obj;
};


#include <Impl/AttrObj.inl>


		};	// namespace Struct
	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFAttrObj
