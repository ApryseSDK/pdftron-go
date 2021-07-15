//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsRedaction
#define PDFTRON_H_CPPPDFAnnotsRedaction

#include <PDF/Annots/Markup.h>
#include <PDF/QuadPoint.h>

#ifdef SWIG
#define Redaction RedactionAnnot
#endif

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A redaction annotation (PDF 1.7) identifies content that is intended to 
 * be removed from the document. The intent of redaction annotations is to 
 * enable the following:
 * a)Content identification. A user applies redact annotations that specify 
 * the pieces or regions of content that should be removed. Up until the 
 * next step is performed, the user can see, move and redefine these 
 * annotations.
 * b)Content removal. The user instructs the viewer application to apply 
 * the redact annotations, after which the content in the area specified 
 * by the redact annotations is removed. In the removed content's place, 
 * some marking appears to indicate the area has been redacted. Also, the 
 * redact annotations are removed from the PDF document.
 * Redaction annotations provide a mechanism for the first step in the 
 * redaction process (content identification). This allows content to be 
 * marked for redaction in a non-destructive way, thus enabling a review 
 * process for evaluating potential redactions prior to removing the 
 * specified content.
 * Redaction annotations shall provide enough information to be used 
 * in the second phase of the redaction process (content removal). 
 * This phase is application-specific and requires the conforming reader 
 * to remove all content identified by the redaction annotation, as well 
 * as the annotation itself.
 * Conforming readers that support redaction annotations shall provide 
 * a mechanism for applying content removal, and they shall remove all 
 * traces of the specified content. If a portion of an image is contained 
 * in a redaction region, that portion of the image data shall be destroyed; 
 * clipping or image masks shall not be used to hide that data. 
 * Such conforming readers shall also be diligent in their consideration 
 * of all content that can exist in a PDF document, including XML Forms 
 * Architecture (XFA) content and Extensible Metadata Platform (XMP) 
 * content.
 */
class Redaction : public Markup
{
	public:
	/** 
	 * Creates a Redaction annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Redaction(SDF::Obj d = 0);	

	/** 
	 * Creates an Redaction annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Redaction annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Redaction(const Annot& ann) : Markup(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Redaction annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, in user space coordinates.
	 * 
	 * @return A newly created blank Circle annotation.
	*/
	static Redaction Create(SDF::SDFDoc& doc, const Rect& pos);

	/** 
	 * Returns the number of QuadPoints in the QuadPoints array of the Redaction annotation.
	 * 
	 * @return The number of QuadPoints. 
	 * @note An array of n QuadPoints that denote 
	 * the content region that is intended to be removed. If quad points are not present, 
	 * the Rect entry denotes the content region that is intended to be removed.
	*/
	int GetQuadPointCount();

	/** 
	 * Returns the QuadPoint located at a certain index of the QuadPoint array of the Redaction 
	 * annotation. 
	 * 
	 * @param idx The index of the QuadPoint, starts at zero and must be less than return value of GetQuadPointCount().
	 * @return The QuadPoint located at a certain index of the QuadPoint array of the Redaction annotation. 
	 * @note An array of n QuadPoints that denote 
	 * the content region that is intended to be removed. If quad points are not present, 
	 * the Rect entry denotes the content region that is intended to be removed.
	*/
	QuadPoint GetQuadPoint(int idx) const;

	/** 					
	 * Set the QuadPoint to be located at a certain index of the QuadPoint array of the Redaction 
	 * annotation. 
	 * (Optional; PDF 1.6 )
	 * 
	 * @param idx The index position where the QuadPoint of interest is to be inserted, starting at 0.
	 * @param qp  The QuadPoint to be inserted at that position. 
	 * @note  For orientation purposes, the bottom of a quadrilateral is the line formed by p1 and p2 of the QuadPoint.  
	 * QuadPoints shall be ignored if any coordinate in the array lies outside the region specified by Rect.
	*/
	void SetQuadPoint(int idx, const QuadPoint& qp);

	/** 
	 * Returns Overlay appearance of the Redaction annotation.
	 * 
	 * @return An SDF object that represents the overlay appearance of the Redaction annotation. 
	 * @note This object is a form XObject specifying the overlay appearance for this 
	 * redaction annotation. After this redaction is applied and the affected content has been removed, 
	 * the overlay appearance should be drawn such that its origin lines up with the lower-left corner 
	 * of the annotation rectangle. This form XObject is not necessarily related to other annotation 
	 * appearances, and may or may not be present in the Appearance dictionary. This entry takes precedence over the Interior Color(IC), 
	 * OverlayText, OverlayTextAppearance(DA), and QuadPoint(Q) entries.
	*/
	SDF::Obj GetAppFormXO()const;

	
	/** 
	 * Sets Overlay appearance of the Redaction annotation.
	 * (Optional)
	 * 
	 * @param formxo An SDF object that represents the overlay appearance of the Redaction annotation. 
	 * @note This object is a form XObject specifying the overlay appearance for this 
	 * redaction annotation. After this redaction is applied and the affected content has been removed, 
	 * the overlay appearance should be drawn such that its origin lines up with the lower-left corner 
	 * of the annotation rectangle. This form XObject is not necessarily related to other annotation 
	 * appearances, and may or may not be present in the Appearance dictionary. This entry takes precedence over the Interior Color(IC), 
	 * OverlayText, OverlayTextAppearance(DA), and QuadPoint(Q) entries.
	*/
	void SetAppFormXO(SDF::Obj formxo);

	/** 
	 * Returns Overlay text of the Redaction annotation.
	 * 
	 * @return A string containing the overlay text of the annotation. 
	 * @note The OverlayText string is a text string specifying the 
	 * overlay text that should be drawn over the redacted region 
	 * after the affected content has been removed. 
	 * This entry is ignored if the Overlay appearance(RO) entry is present.
	*/
	UString GetOverlayText() const;

	/** 
	 * Sets Overlay text of the Redaction annotation.
	 * 
	 * @param title A string containing the overlay text of the annotation. 
	 * @note The OverlayText string is a text string specifying the 
	 * overlay text that should be drawn over the redacted region 
	 * after the affected content has been removed. 
	 * This entry is ignored if the Overlay appearance stream (RO) entry is present.
	*/
	void SetOverlayText(const UString& title);

	/** 
	 * Returns the option of whether to use repeat for the Redaction annotation.
	 * 
	 * @return A bool indicating whether to repeat for the Redaction annotation.  
	 * @note If userepeat value is true, then the text specified by OverlayText 
	 * should be repeated to fill the redacted region after the affected content 
	 * has been removed. This entry is ignored if the Overlay appearance stream 
	 * (RO) entry is present.
	 * Default value: false.
	*/
	bool GetUseRepeat() const;

	/** 
	 * Sets the option of whether to use repeat for the Redaction annotation.
	 * 
	 * @param userepeat A bool indicating whether to repeat for the Redaction annotation.  
	 * @note If userepeat value is true, then the text specified by OverlayText 
	 * should be repeated to fill the redacted region after the affected content 
	 * has been removed. This entry is ignored if the Overlay appearance stream 
	 * (RO) entry is present.
	 * @default userepeat = false.
	*/
	void SetUseRepeat(bool userepeat=false);

	/** 
	 * Returns Overlay text appearance of the Redaction annotation.
	 * 
	 * @return A string containing the overlay text appearance of the annotation. 
	 * @note The overlay text appearance is the appearance string to be used 
	 * in formatting the overlay text when it is drawn after the affected content
	 * has been removed. This entry is ignored if the Overlay appearance stream
	 * (RO) entry is present.
	*/
	UString GetOverlayTextAppearance() const;

	/** 
	 * Sets Overlay text appearance of the Redaction annotation.
	 * 
	 * @param app A string containing the overlay text appearance of the annotation. 
	 * @note The overlay text appearance is the appearance string to be used 
	 * in formatting the overlay text when it is drawn after the affected content
	 * has been removed. This entry is ignored if the Overlay appearance stream 
	 * (RO) entry is present.
	*/
	void SetOverlayTextAppearance(const UString& app);

	/** 
	 * This enum represents the justification format of the Redaction annotation's overlay text.
	 * 
	*/
	enum QuadForm
	{
		e_LeftJustified,  ///< Overlay text is left justified
		e_Centered,       ///< Overlay text is centered
		e_RightJustified, ///< Overlay text is right justified 
		e_None            ///< No justification to the overlay text. 
	};

	/** 
	 * Returns Overlay text quadding(justification) format of the Redaction annotation.
	 * 
	 * @return A value of the "QuadForm" enum type, indicating the 
	 * overlay text quadding(justification) format of the Redaction annotation's overlay text.
	*/
	QuadForm GetQuadForm() const;

	/** 
	 * Sets Overlay text quadding (justification) format of the Redaction annotation.
	 * 
	 * @param form A value of the "QuadForm" enum type, indicating the 
	 * overlay text quadding(justification) format of the Redaction annotation. 
	 * @note Quadding format specifies the form of justification to be 
	 * used in displaying the overlay text.
	 * @default form=e_LeftJustified
	*/
	void SetQuadForm(QuadForm form=e_LeftJustified);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	Redaction(TRN_Annot redaction);
	#endif
	// @endcond
	
}; //class Redaction
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron

#ifdef SWIG
#undef Redaction
#endif

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsRedaction
