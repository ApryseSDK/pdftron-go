//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsUnderline
#define PDFTRON_H_CPPPDFAnnotsUnderline

#include <PDF/Annots/TextMarkup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * An Underline annotation shows as a line segment across the bottom 
 * of a word or a group of contiguous words.
 */
class Underline : public TextMarkup
{
public:
	/** 
	 * Creates an Underline annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Underline(SDF::Obj d);

	/** 
	 * Creates an Underline annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Underline annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Underline(const Annot& ann) : TextMarkup(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Underline annotation in the specified document.
	 * 
	 * @param doc A document to which the Underline annotation is added.
	 * @param pos A rectangle specifying the Underline annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Underline annotation.
	 */
	static Underline Create(SDF::SDFDoc& doc, const Rect& pos);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	Underline(TRN_Annot underline);
	#endif
	// @endcond

};//class Underline
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsUnderline
