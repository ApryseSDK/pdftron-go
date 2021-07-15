//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFStructSTree
#define PDFTRON_H_CPPPDFStructSTree

#include <PDF/Struct/RoleMap.h>
#include <PDF/Struct/ClassMap.h>

namespace pdftron { 
	namespace PDF {
		namespace Struct {

/**
 * STree is the root of the structure tree, which is a central repository 
 * for information related to a PDF document's logical structure. There is at most 
 * one structure tree in each document.
 */ 
class STree
{
public: 

	/**
	 * Initialize a STree using an existing low-level Cos/SDF object.
	 * 
	 * @param struct_dict - a low-level (SDF/Cos) dictionary representing the . 
	 * 
	 * @note This constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 */
	 STree (SDF::Obj struct_dict);
	
	 STree (const STree&);
	 STree& operator= (const STree&);

	/**
	 * Create a structure tree if it is missing, else return the existing 
	 * structure tree
	 * @param doc the document in which to create or get the structure tree from
	 *
	 * @return structure tree of the document 
	 */
	static STree Create(PDF::PDFDoc& doc);
	
	/**
	 * Inserts the specified kid element after the given position as a kid of 
	 * the specified structure tree root. 
	 *
	 * @param kid The kid element to insert.
	 * @param insert_before The position after which the kid is inserted. If 
	 * element currently has no kids, insert_before is ignored.
	 */
	void Insert(class SElement& kid, int insert_before);

	/**
	 * @return true if this is a valid STree object, false otherwise. 
	 */ 	
	 bool IsValid() const;

	/**
	 * @return The number of kids of the structure tree root. 
	 */
	 int GetNumKids();
	
	/**
	 * @return The kid at an array index in the structure tree root. 
	 * @param index The index of the kid to obtain. 
	 */
	 class SElement GetKid(int index);

	/**
	 * @return the element associated with the given ID. 
	 * 
	 * @param id_buf A pointer to a buffer containing the ID to search for. 
	 * @param id_buf_sz The number of characters in id_buf. 
	 */
	 class SElement GetElement(const char* id_buf, int id_buf_sz);

	/** 
	 * @return the RoleMap object from the structure tree root.
	 */
	 RoleMap GetRoleMap() const;

	/** 
	 * @return the ClassMap object from the structure tree root.
	 */
	 class ClassMap GetClassMap() const;

	/**
	 * @return Pointer to the underlying SDF/Cos object.
	 */
	 SDF::Obj GetSDFObj () const;

	 STree();
// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 STree(TRN_STree impl);
private:
	TRN_STree mp_tree;
#endif
// @endcond

};


		};	// namespace Struct
	};	// namespace PDF
};	// namespace pdftron

#include <Impl/PDFDoc.inl>

#endif // PDFTRON_H_CPPPDFStructSTree
