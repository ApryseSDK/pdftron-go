//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsSquare
#define PDFTRON_H_CPPPDFAnnotsSquare

#include <PDF/Annots/Markup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * Square annotation is used to display a rectangle on the page. When opened, 
 * a square annotation can display a pop-up window containing the text of the 
 * associated note. The rectangle may be inscribed and possibly padded within the 
 * annotation rectangle defined by the annotation dictionary's Rect entry.
*/
class Square : public Markup
{
	public:	
	/** 
	 * Creates an Square annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/		
	Square(SDF::Obj d = 0);
	
	/** 
	 * Creates a Square annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Square annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/		
	Square(const Annot& ann) : Markup(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Square annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, in user space coordinates.
	 * 
	 * @return A newly created blank Square annotation.
	 */
	static Square Create(SDF::SDFDoc& doc, const Rect& pos);

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	Square(TRN_Annot square);
#endif
// @endcond

};//class Square
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsSquare
