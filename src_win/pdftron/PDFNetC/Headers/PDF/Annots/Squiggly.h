//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsSquiggly
#define PDFTRON_H_CPPPDFAnnotsSquiggly

#include <PDF/Annots/TextMarkup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A Squiggly annotation shows as a wavy line segment across the bottom 
 * of a word or a group of contiguous words.
  */
class Squiggly : public TextMarkup
{
	public:
	/** 
	 * Creates a Squiggly annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 */
	Squiggly(SDF::Obj d);

	/** 
	 * Creates a Squiggly annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Squiggly annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Squiggly(const Annot& ann) : TextMarkup(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Squiggly annotation in the specified document.
	 * 
	 * @param doc A document to which the Popup annotation is added.
	 * @param pos A rectangle specifying the Popup annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Squiggly annotation.
	 */
	static Squiggly Create(SDF::SDFDoc& doc, const Rect& pos);

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
Squiggly(TRN_Annot squiggly);
#endif
// @endcond


};//class Squiggly
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsSquiggly
