//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsWatermark
#define PDFTRON_H_CPPPDFAnnotsWatermark

#include <PDF/Annot.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A Watermark annotation is an annotation that is printed at a fixed    
 * size and position on a page, regardless of the dimensions of the printed page. 
*/
class Watermark : public Annot
{
	public:

	/** 
	 * Creates a Watermark annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 */
	Watermark(SDF::Obj d = 0);

	/** 
	 * Creates a Watermark annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Watermark annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 */
	Watermark(const Annot& ann) : Annot(ann.GetSDFObj()) {}
	
	/** 
	 * Creates a new Watermark annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Watermark annotation.
	 */
	static Watermark Create(SDF::SDFDoc& doc, const Rect& pos);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	Watermark(TRN_Annot watermark);
	#endif
	// @endcond

}; //class Watermark
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsWatermark
