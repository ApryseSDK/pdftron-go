//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsPopup
#define PDFTRON_H_CPPPDFAnnotsPopup

#include <PDF/Annot.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A pop-up annotation (PDF 1.3) displays text in a pop-up window for entry and 
 * editing. It shall not appear alone but is associated with a markup annotation, 
 * its parent annotation, and shall be used for editing the parent's text. 
 * It shall have no appearance stream or associated actions of its own and 
 * shall be identified by the Popup entry in the parent's annotation dictionary.
 */
class Popup : public Annot
{						
	public:	
	/** 
	 * Creates a Popup annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Popup(SDF::Obj d = 0);	

	/** 
	 * Creates a Popup annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Popup annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Popup(const Annot& ann) : Annot(ann.GetSDFObj()) {}

	/** 
	 * Creates a new Popup annotation in the specified document.
	 * 
	 * @param doc A document to which the Popup annotation is added.
	 * @param pos A rectangle specifying the Popup annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Popup annotation.
	*/
	static Popup Create(SDF::SDFDoc& doc, const Rect& pos);

	/** 
	 * Returns the parent annotation of the Popup annotation. 
	 * 
	 * @return An annot object which is the parent annotation of the Popup annotation. 
	 * @note This annotation object represents the parent annotation with which this 
	 * pop-up annotation shall be associated.
	 * @note If this entry is present, the parent annotation's Contents, M, C, and T entries 
	 * shall override those of the pop-up annotation itself.
	 */
	Annot GetParent() const;

	/** 
	 * Sets the Parent annotation of the Popup annotation. 
	 * (Optional)
	 * 
	 * @param parent An annot object which is the parent annotation of the Popup annotation. 
	 * @note This annotation object represents the parent annotation with which this 
	 * pop-up annotation shall be associated.
	 * @note If this entry is present, the parent annotation's Contents, M, C, and T entries 
	 * shall override those of the pop-up annotation itself.
	 */
	void SetParent(const Annot& parent);

	/** 
	 * Returns the initial opening condition of Popup. 
	 * 
	 * @return A bool indicating whether the Popup is initially open.  
	 * @note This is a flag specifying whether the pop-up 
	 * annotation's window shall initially be displayed. 
	 * Default value: false (closed).
	 */
	bool IsOpen() const;

	/** 
	 * Sets the initial opening condition of Popup. 
	 * (Optional)
	 * 
	 * @param is_open A bool indicating whether the Popup is initially open.  
	 * @note This is a flag specifying whether the pop-up 
	 * annotation's window shall initially be displayed. 
	 * Default value: false (closed).
	 */
	void SetOpen(bool is_open);

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
		Popup(TRN_Annot popup);
#endif
// @endcond
}; //class Popup
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsPopup
