//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFStructRoleMap
#define PDFTRON_H_CPPPDFStructRoleMap

#include <SDF/Obj.h>
#include <C/PDF/Struct/TRN_RoleMap.h>

namespace pdftron { 
	namespace PDF {
		namespace Struct {

/**
 * RoleMap is a dictionary that maps the names of structure types used in the 
 * document to their approximate equivalents in the set of standard structure 
 * types.
 */ 
class RoleMap
{
public: 

	/**
	 * Initialize a RoleMap using an existing low-level Cos/SDF role map dictionary.
	 * 
	 * @param dict - a low-level (SDF/Cos) RoleMap dictionary. 
	 * 
	 * @note This constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 */
	 RoleMap (SDF::Obj dict);
	
	 RoleMap (const RoleMap& p);
	 RoleMap& operator= (const RoleMap& p);

	/**
	 * @return true if this is a valid (non-null) RoleMap, false otherwise. 
	 * If the function returns false the underlying SDF/Cos object is null or is 
	 * not valid and the RoleMap should be treated as NULL object.
	 */ 	
	 bool IsValid() const;

	/** 
	 * @return The direct mapping of given StructElement type, or NULL 
	 * if such mapping is not defined. 
	 *
	 * @param type element type
	 */
	 const char* GetDirectMap(const char* type) const;

	/**
	 * Returns the RoleMap dictionary.
	 * @return the object to the underlying SDF/Cos dictionary.
	 */
	 SDF::Obj GetSDFObj () const;


// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 RoleMap(TRN_RoleMap impl);
private:
	TRN_RoleMap mp_map;
#endif
// @endcond
};


#include <Impl/RoleMap.inl>

		};	// namespace Struct
	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFStructRoleMap
