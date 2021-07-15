//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsCircle
#define PDFTRON_H_CPPPDFAnnotsCircle

#include <PDF/Annots/Markup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A Circle annotation is a type of markup annotation that displays an ellipse on 
 * the page. When opened, it can display a pop-up window containing the text of 
 * the associated note. The ellipse may be inscribed and possibly padded within the 
 * annotation rectangle defined by the annotation dictionary's Rect entry.
 */
class Circle : public Markup
{
public:	

	/** 
	 * Creates an Circle annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/		
	Circle(SDF::Obj d = 0);
	
	/** 
	 * Creates a Circle annotation and initializes it using given annotation object.
	 * @param circle Annot object used to initialize the Circle annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/		
	Circle(const Annot& circle) : Markup(circle.GetSDFObj()) {}

	/** 
	 * Creates a new Circle annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Circle annotation.
	 */
	static Circle Create(SDF::SDFDoc& doc, const Rect& pos);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
		Circle(TRN_Annot circle);
	#endif
	// @endcond

};//class Circle
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsCircle
