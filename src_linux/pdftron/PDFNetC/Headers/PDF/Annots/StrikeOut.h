//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsStrikeOut
#define PDFTRON_H_CPPPDFAnnotsStrikeOut

#include <PDF/Annots/TextMarkup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A StrikeOut annotation shows as a line segment crossing out
 * a word or a group of contiguous words.
 */
class StrikeOut : public TextMarkup
{
	public:
	/** 
	 * Creates a StrikeOut annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 */
	StrikeOut(SDF::Obj d);

	/** 
	 * Creates a StrikeOut annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the StrikeOut annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	StrikeOut(const Annot& ann) : TextMarkup(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new StrikeOut annotation in the specified document.
	 * 
	 * @param doc A document to which the Popup annotation is added.
	 * @param pos A rectangle specifying the Popup annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank StrikeOut annotation.
	 */
	static StrikeOut Create(SDF::SDFDoc& doc, const Rect& pos);

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
StrikeOut(TRN_Annot strikeout);
#endif
// @endcond

};//class StrikeOut
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsStrikeOut
