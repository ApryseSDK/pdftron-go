//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsHighlight
#define PDFTRON_H_CPPPDFAnnotsHighlight

#include <PDF/Annots/TextMarkup.h>

#ifdef SWIG
#define Highlight HighlightAnnot
#endif

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A Highlight annotation covers a word or a group of contiguous words with partially transparent
 * color.
 */
class Highlight : public TextMarkup
{
public:
	/** 
	 * Creates a Highlight annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Highlight(SDF::Obj d);

	/** 
	 * Creates a Highlight annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Highlight annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Highlight(const Annot& ann) : TextMarkup(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Highlight annotation in the specified document.
	 * 
	 * @param doc A document to which the Highlight annotation is added.
	 * @param pos A rectangle specifying the Highlight annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Highlight annotation.
	 */
	static Highlight Create(SDF::SDFDoc& doc, const Rect& pos);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
		Highlight(TRN_Annot highlight);
	#endif
	// @endcond
};//class Highlight

			};//namespace Annot
		};//namespace PDF
};//namespace pdftron

#ifdef SWIG
#undef Highlight
#endif

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsHighlight
