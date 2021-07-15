//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFStructSElement
#define PDFTRON_H_CPPPDFStructSElement

namespace pdftron { 
	namespace PDF {
		class PDFDoc;
		namespace Struct {

/**
 * SElement represents PDF structural elements, which are nodes in a tree   
 * structure, defining a PDF document's logical structure.
 *
 * Unlike the StructTree, SElement can have two different kinds 
 * of children: another SElement or a ContentItem (which can be marked 
 * content (MC), or a PDF object reference (OBJR)). 
 */ 
class SElement
{
public: 

	/**
	 * Initialize a SElement using an existing low-level Cos/SDF object.
	 * 
	 * @param dict - a low-level (SDF/Cos) dictionary representing the structural element. 
	 *
	 * @note This constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 */
	 SElement (SDF::Obj dict = SDF::Obj(0));
	
	 SElement (const SElement&);
	 SElement& operator= (const SElement&);
	 
	/**
	 * Creates a new SElement.
	 * @param doc
	 * @param struct_type
	 */
	 static SElement Create(pdftron::PDF::PDFDoc& doc, const char* struct_type);	

	/**
	 * Inserts the specified kid SElement into this element.
	 *
	 * @param insert_before The position after which the kid is inserted. If 
	 * element currently has no kids, insert_before is ignored.
	 */ 
	void Insert(SElement& kid, int insert_before);

	/**
	 * @param doc The document in which the new ContentItem will be created in.
	 * @param page The page object to insert the ContentItem in.
	 * @param insert_before The position after which the kid is inserted. If 
	 * element currently has no kids, insert_before is ignored.
	 */
	int CreateContentItem(PDFDoc& doc, Page& page, int insert_before = -1);

	/**
	 * @return true if this is a valid structure element object, false otherwise. 
	 */ 	
	 bool IsValid() const;

	/** 
	 * @return The element's structural element type. The type corresponds to 
	 * the 'S' (i.e. subtype) key in the structure element dictionary. 
	 * 
	 * The type identifies the nature of the structure element and its role 
	 * within the document (such as a chapter, paragraph, or footnote).
	 */
	 const char* GetType() const;

	/**
	 * @return The number of direct kids.
	 */
	 int GetNumKids() const;

	/**
	 * @return true if the kid at a given array index is a content item, 
	 * false otherwise. 
	 * @param index The index of the kid type to obtain. 
	 *
	 * To retrieve a content item at a given array index use GetAsContentItem(index), 
	 * otherwise use GetAsStructElem(index)
	 */
	 bool IsContentItem(int index) const;

	/**
	 * @return The kid at a given array index assuming that the kid is a ContentItem. 
	 * @note use IsContentItem(index) prior to calling this method to make sure that 
	 * the kid is indeed a ContentItem.
	 * @param index The index of the kid to obtain. 
	 */
	 class ContentItem GetAsContentItem(int index) const;

	/**
	 * @return The kid at a given array index assuming that the kid is a SElement. 
	 * @note use IsContentItem(index) prior to calling this method to make sure that 
	 * the kid is not a ContentItem and is another SElement.
	 * @param index The index of the kid to obtain. 
	 */
	 SElement GetAsStructElem(int index) const;

	/** 
	 * @return The immediate ancestor element of the specified element in 
	 * the structure tree. 
	 *
	 * @note If the element's parent is the structure tree root, the returned 
	 * SElement will be not valid (i.e. element.IsValid() -> false) and the 
	 * underlying SDF/Cos object will be NULL.
	 */
	 SElement GetParent() const;

	/** 
	 * @return The structure tree root of the document that directly or 
	 * indirectly contains this element.
	 */
	 class STree GetStructTreeRoot() const;

	/** 
	 * @return if this SElement has title. 
	 * 
	 * The title of the structure element, a text string representing it in 
	 * human-readable form.
	 */
	 bool HasTitle() const;

	/** 
	 * @return The title of this structure element.
	 */
	 UString GetTitle() const;

	/** 
	 * @return the ID of an element, or NULL if the ID is not defined. 
	 */
	 SDF::Obj GetID() const;

	/** 
	 * @return if this structure element defines ActualText. 
	 * 
	 * ActualText is an exact replacement for the structure element and its children.
	 * This replacement text is useful when extracting the document's contents in 
	 * support of accessibility to users with disabilities or for other purposes.
	 */
	 bool HasActualText() const;

	/** 
	 * @return The ActualText associated with this element. 
	 * 
	 * @note The ActualText can be defined as an empty string. To differentiate 
	 * between an ActualText string of zero length and no ActualText being defined, 
	 * use HasActualText(). 
	 */
	 UString GetActualText() const;

	/** 
	 * @return if this structure element defines Alt text. 
	 * 
	 * Alt text is an alternate description of the structure element and 
	 * its children in human-readable form, which is useful when extracting 
	 * the document's contents in support of accessibility.
	 */
	 bool HasAlt() const;

	/** 
	 * @return The alternate text associated with this element. 
	 * 
	 * @note The Alt text can be defined as an empty string. To differentiate 
	 * between an Alt text string of zero length and no Alt text being defined, 
	 * use HasAlt(). 
	 */
	 UString GetAlt() const;

	/**
	 * @return Pointer to the underlying SDF/Cos object.
	 */
	 SDF::Obj GetSDFObj() const;


// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	SElement(TRN_SElement impl);
	TRN_SElement mp_elem;
#endif
// @endcond
};



		};	// namespace Struct
	};	// namespace PDF
};	// namespace pdftron

#include <Impl/PDFDoc.inl>

#endif // PDFTRON_H_CPPPDFStructSElement
