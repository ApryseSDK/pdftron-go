//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsCaret
#define PDFTRON_H_CPPPDFAnnotsCaret

#include <PDF/Annots/Markup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A Caret annotation (PDF 1.5) is a visual symbol that indicates 
 * the presence of text edits. 
*/	
class Caret : public Markup
{
	public:	
	
	/** 
	* Creates an Caret annotation and initializes it using given Cos/SDF object.
	* @param d The Cos/SDF object to initialze the annotation with.
	* @note The constructor does not copy any data, but is instead the logical
	* equivalent of a type cast.
	*/					
	Caret(SDF::Obj d = 0);	
	
	/** 
	* Creates an Caret annotation and initializes it using given annotation object.
	* @param ann Annot object used to initialize the Caret annotation. 
	* @note The constructor does not copy any data, but is instead the logical
	* equivalent of a type cast.
	*/		
	Caret(const Annot& ann) : Markup(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Caret annotation in the specified document.
	 * 
	 * @param doc A document to which the Caret annotation is added.
	 * @param pos A rectangle specifying the Caret annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Caret annotation.
	*/
	static Caret Create(SDF::SDFDoc& doc, const Rect& pos);

	/** 
	 * Creates a new Caret annotation, in the specified document, specifying  
	 * a set of four numbers that shall describe the numerical differences 
	 * between two rectangles: the Rect entry of the annotation and the actual 
	 * boundaries of the underlying Caret.
	 * 
	 * @param doc A document to which the Caret annotation is added.
	 * @param pos A rectangle specifying the Caret annotation's bounds in default user space units.
	 * @param diff A set of four numbers(represented as a Rect object)specifying the numerical differences 
	 * between two rectangles: the Rect entry of the annotation and the actual 
	 * boundaries of the underlying Caret.
	 * @return A newly created Caret annotation with rectangle difference specified.
	*/
	static Caret Create(SDF::SDFDoc& doc, const Rect& pos, Rect padding);						

	/** 
	 * Returns the paragraph symbol associated with the caret.
	 * 
	 * @return The name of the symbol. This can be either "P" (Use a new 
	 * paragraph symbol) or "None" (Don't use any symbol).
	 * Default value: None.
	 */
	const char* GetSymbol() const;

	/** 
	 * Sets the caret symbol.
	 * @param symbol The name of the symbol. This can be either "P" (Use a new 
	 * paragraph symbol) or "None" (Don't use any symbol).
	 * Default value: None.
	 */
	void SetSymbol(const char* symbol);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
		Caret(TRN_Annot caret);
	#endif
	// @endcond
};


			};//namespace Annot
		};//namespace PDF
};//namespace pdftron

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsCaret
