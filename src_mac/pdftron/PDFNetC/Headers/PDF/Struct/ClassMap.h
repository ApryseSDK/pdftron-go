//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFStructClassMap
#define PDFTRON_H_CPPPDFStructClassMap

#include <SDF/Obj.h>
#include <C/PDF/Struct/TRN_ClassMap.h>

namespace pdftron { 
	namespace PDF {
		namespace Struct {

/**
 */ 
class ClassMap
{
public: 
	/**
	 * Initialize a ClassMap using an existing low-level Cos/SDF ClassMap object.
	 * 
	 * @param dict - a low-level (SDF/Cos) ClassMap dictionary. 
	 * 
	 * @note This constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 */
	 ClassMap (SDF::Obj dict = SDF::Obj(0));
	
	 ClassMap (const ClassMap& p);
	 ClassMap& operator= (const ClassMap& p);

	/**
	 * @return true if this is a valid (non-null) ClassMap, false otherwise. 
	 * If the function returns false the underlying SDF/Cos object is null or is 
	 * not valid and the ClassMap object should be treated as a null object.
	 */ 	
	 bool IsValid() const;

	/**
	 * Returns the ClassMap dictionary.
	 * 
	 * @return the object to the underlying SDF/Cos object.
	 */
	 SDF::Obj GetSDFObj () const;

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 ClassMap(TRN_ClassMap impl);
private:

	TRN_ClassMap mp_map;
#endif
// @endcond

};

#include <Impl/ClassMap.inl>

		}; // namespace Struct
	}; // namespace PDF
}; // namespace pdftron

#endif // PDFTRON_H_CPPPDFStructClassMap
