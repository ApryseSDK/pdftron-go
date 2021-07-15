//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFStructContentItem
#define PDFTRON_H_CPPPDFStructContentItem

#include <PDF/Page.h>

namespace pdftron { 
	namespace PDF {
		namespace Struct {

/**
 * Content items are graphical objects that exist in the document independently 
 * of the structure tree but are associated with structure elements.
 * 
 * Content items are leaf nodes of the structure tree.
 */
class ContentItem
{
public: 
	/**
	 * Copy constructor and assignment operator.
	 */
	ContentItem(const ContentItem&);
	ContentItem& operator= (const ContentItem&);
	
	enum Type 
	{
		e_MCR,     ///< marked-content reference.
		e_MCID,    ///< marked-content identifier.
		e_OBJR,    ///< object reference dictionary.
		e_Unknown  ///< unknown content type.
	};

	/**
	 * @return the content item type.
	 */
	Type GetType() const;

	/** 
	 * Find the parent structure element.
	 */
	class SElement GetParent();

	/** 
	 * The page on which the marked content is drawn, whether directly as part of 
	 * page content or indirectly by being in a Form XObject or annotation drawn 
	 * on that page.
	 */
	Page GetPage();

	/**
	 * @return Pointer to the underlying SDF/Cos object.
	 */
	SDF::Obj GetSDFObj () const;

	// Type specific methods -----------------------------

	/** 
	 * @return mcid (marked-content identifier).  
	 * 
	 * @note this method only applies to content items with types e_MCR or e_MCID.
	 */
	int GetMCID() const;

	/** 
	 * @return The stream object that contains the marked-content sequence. 
	 * The function will return a non-NULL object only if the marked-content 
	 * sequence resides in a content stream other than the content stream for the
	 * page (e.g. in a form XObject).
	 * 
	 * @note this method only applies to content items with type e_MCR.
	 */
	SDF::Obj GetContainingStm() const;

	/**
	 * @return NULL or the PDF object owning the stream returned by 
	 * GetContainingStm() (e.g. the annotation to which an appearance stream 
	 * belongs).
	 * 
	 * @note this method only applies to content items with type e_MCR.
	 */
	SDF::Obj GetStmOwner() const;

	/**
	 * @return The referenced object. 
	 * @note this method only applies to content items with type e_OBJR.
	 */
	SDF::Obj GetRefObj() const;

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	ContentItem(TRN_ContentItem impl);
	TRN_ContentItem mp_item;
#endif
// @endcond
};


		};	// namespace Struct
	};	// namespace PDF
};	// namespace pdftron

#include <Impl/PDFDoc.inl>

#endif // PDFTRON_H_CPPPDFStructContentItem
