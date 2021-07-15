//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsMarkup
#define PDFTRON_H_CPPPDFAnnotsMarkup

#include <PDF/Annots/Popup.h>
#include <PDF/Date.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/**
 * Markup is a base class for a number of annotations types that 
 * are used to mark up PDF documents. These annotations have text that 
 * appears as part of the annotation and may be displayed in other ways by a 
 * conforming reader, such as in a Comments pane.
 * Markup annotations may be divided into the following groups:
 * - Free text annotations display text directly on the page. 
 *   The annotation's Contents entry specifies the displayed text.
 * - Most other markup annotations have an associated pop-up window 
 *   that may contain text. The annotation's Contents entry specifies 
 *   the text that shall be displayed when the pop-up window is opened. 
 *   These include text, line, square, circle, polygon, polyline, 
 *   highlight,underline, squiggly-underline, strikeout, rubber stamp, 
 *   caret, ink, and file attachment annotations.
 * - Sound annotations do not have a pop-up window but may also have 
 *   associated text specified by the Contents entry.
 * - A subset of markup annotations are intended to markup text of a 
 *   document (e.g. highlight, strikeout, jagged, underline) and they 
 *   are derived from TextMarkup base class.
 * 
 * @note The pop-up annotation type must not appear by itself; it must be 
 * associated with a markup annotation that uses it to display text.
 *
 * The meaning of an annotation's Contents entry varies by annotation type. 
 * Typically, it is the text that shall be displayed for the annotation or, 
 * if the annotation does not display text, an alternate description of the 
 * annotation's contents in human-readable form. When separating text into 
 * paragraphs, a CARRIAGE RETURN (0Dh) must be used.
 */
class Markup : public Annot
{
	public:

	/** 
	 * Creates a markup annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Markup(SDF::Obj d = 0);

	/** 
	 * Creates a markup annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Markup annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Markup(const Annot& ann) : Annot(ann.GetSDFObj()) {} 

	/** 
	 * Returns the title of the markup annotation. 
	 * 
	 * @return A string representing the title of the markup annotation,
	 * or null is the title is not specified.
	 * 
	 * @note The title is The text label that is displayed in the 
	 * title bar of the annotation's pop-up window when open and active
	 * Markup annotation. 
	 * This entry is also used to identify the user who added the annotation.
	 * It corresponds to the 'T' field of the annotation's dictionary.
	*/
	UString GetTitle();
	
	/** 
	 * Sets the title of the markup annotation. 
	 * (Optional; PDF 1.1)
	 * 
	 * @param title A string.
	 * @note The title is The text label that is displayed in the 
	 * title bar of the annotation's pop-up window when open and active
	 * Markup annotation. 
	 * This entry is also used to identify the user who added the annotation.
	 * It corresponds to the 'T' field of the annotation's dictionary.
	*/
	void SetTitle(const UString& title);
	/** 
	 * Sets the title of the markup annotation. 
	 * (Optional; PDF 1.1)
	 * 
	 * @param title A string.
	 * @note The title is The text label that is displayed in the 
	 * title bar of the annotation's pop-up window when open and active
	 * Markup annotation. 
	 * This entry is also used to identify the user who added the annotation.
	 * It corresponds to the 'T' field of the annotation's dictionary.
	*/
	void SetTitle(const char* title);

	/** 
	 * Returns the Popup object associated with this markup annotation. 
	 * 
	 * @return A Popup object that is associated with this markup annotation. 
	 * @note The Popup is An indirect reference to a pop-up annotation for 
	 * entering or editing the text associated with this annotation.
	*/
	Popup GetPopup() const;

	/** 				
	 * Sets the Popup object associated with this markup annotation.
	 * (Optional; PDF 1.3 )
	 * 
	 * @param ppup A Popup object that is associated with this markup annotation. 
	 * @note the Popup is An indirect reference to a pop-up annotation for 
	 * entering or editing the text associated with this annotation.
	*/
	void SetPopup(const Popup& ppup);

	/** 				
	 * @return The opacity value.  
	 * Default value: 1.0.
	 * @note This value is applied to all visible elements of the annotation in its closed state 
	 * (including its background and border) but not to the pop-up window that appears when 
	 * the annotation is opened. When an appearance stream is presented with the annotation,
	 * this entry is ignored.(However, if the compliant viewer regenerates 
	 * the annotation's appearance stream, it may incorporate this Opacity entry 
	 * into the stream's content.)
	 * @note This corresponds to the 'CA' field of the annotation's dictionary.
	*/
	double GetOpacity() const;
	 
	/** 				
	 * Sets the opacity value for the annotation. 
	 * (Optional; PDF 1.4 )
	 * 
	 * @param op A number indicating the Markup annotation's opacity value. 
	 * Default value: 1.0.
	 * @note This value is applied to all visible elements of the annotation in its closed state 
	 * (including its background and border) but not to the pop-up window that appears when 
	 * the annotation is opened. When an appearance stream is presented with the annotation,
	 * this entry is ignored.(However, if the compliant viewer regenerates 
	 * the annotation's appearance stream, it may incorporate this Opacity entry 
	 * into the stream's content.)
	 * @note This corresponds to the 'CA' field of the annotation's dictionary.
	*/
	void SetOpacity(double op);

	/** 
	 * Returns the subject of the Markup annotation. 
	 * (PDF 1.5)
	 * 
	 * @return A string representing the subject of the Markup annotation.
	 * @note The subject is a short piece of text description about the annotation.
	 * @note This corresponds to the 'Subj' field of the annotation's dictionary.
	*/
	UString GetSubject() const;
	
	/** 					 
	 * Sets subject of the Markup annotation. 
	 * (Optional; PDF 1.5 )
	 * 
	 * @param contents A string representing the subject of the Markup annotation.
	 * @note The subject is a short piece of text description about the annotation.
	 * @note This corresponds to the 'Subj' field of the annotation's dictionary.
	*/
	void SetSubject(const UString& contents);

	/** 				
	 * @return The creation date for the markup annotation. 
	 * 
	 * @note This corresponds to the 'CreationDate' field of the markup annotation's dictionary.
	*/
	Date GetCreationDates() const;

	/** 	
	 * Sets the creation date for the markup annotation.
	 * (Optional; PDF 1.5 )
	 * 
	 * @param dt A Date object indicating the date the markup annotation is created.
	 * @note This corresponds to the 'CreationDate' field of the markup annotation's dictionary.
	*/
	void SetCreationDates(const Date& dt);

	/** 
	 * Border Effect Style
	*/
	enum BorderEffect 
	{
		e_None,   ///< No effect.
		e_Cloudy  ///< Use "cloudy" border.
	};			

	/** 
	 * @return the border effect of the markup annotation. 
	 * Default value: e_None.
	 * 
	 * Beginning with PDF 1.5, some annotations (square, circle, and polygon) may have a 'BE' entry, 
	 * which is a border effect dictionary that specifies an effect that shall be applied to the border
	 * of the annotations. Beginning with PDF 1.6, the free text annotation may also have a BE entry.
	 * @note When "e_Cloudy" is chosen,the width and 
	 * dash array specified by the annotation's BorderStyle entry 
	 * needs to be taken into consideration.
	*/
	BorderEffect GetBorderEffect() const;

	/** 				
	 * Sets the border effect of the markup annotation. (Optional; PDF 1.5 )
	 * 
	 * Beginning with PDF 1.5, some annotations (square, circle, and polygon) may have a 'BE' entry, 
	 * which is a border effect dictionary that specifies an effect that shall be applied to the border
	 * of the annotations. Beginning with PDF 1.6, the free text annotation may also have a BE entry.
	 * @param effect An entry from the enum "BorderEffect" that 
	 * represents the border effect of the Markup annotation. 
	 * Default value: e_None.
	 * @note When "e_Cloudy" is chosen,the width and 
	 * dash array specified by the annotation's BorderStyle entry 
	 * needs to be taken into consideration.
	*/
	void SetBorderEffect(BorderEffect effect = e_None);

	/** 
	 * @return A number describing the intensity of the border effect, in the range 0 to 2. 
	 *
	 * Beginning with PDF 1.5, some annotations (square, circle, and polygon) may have a 'BE' entry, 
	 * which is a border effect dictionary that specifies an effect that shall be applied to the border
	 * of the annotations. Beginning with PDF 1.6, the free text annotation may also have a BE entry.
	*/
	double GetBorderEffectIntensity() const;

	/** 
	 * Sets the border effect intensity of the markup annotation. 
	 * (Optional; valid only if Border effect is Cloudy)					 
	 * 
	 * Beginning with PDF 1.5, some annotations (square, circle, and polygon) may have a 'BE' entry, 
	 * which is a border effect dictionary that specifies an effect that shall be applied to the border
	 * of the annotations. Beginning with PDF 1.6, the free text annotation may also have a BE entry.
	 * @param intensity A number describing the intensity of the border effect, in the 
	 * range 0 (which is default) to 2. 
	 * @note this parameter applies only if Border effect is e_Cloudy.
	*/
	void SetBorderEffectIntensity(double intensity = 0);

	/**				 
	 * Returns the interior color of the annotation.		 
	 * 
	 * @return A ColorPt object that denotes the color of the annotation.
	 * @note The color can be in different color spaces: Gray, RGB, or CMYK. 
	 * Call "GetInteriorColorCompNum" to access the color space information. 
	 * @note According to PDF Reference Manual interior color is not the property 
	 * that is expected for Markup annotations in general, but it applies
	 * to many derived annotations (Line,Square,Circle,Polygon,PolyLine,Redaction) and therefore get()/set() methods are
	 * provided in the base class Markup. Annotations that do not use interior color
	 * will ignore the interior color ('IC' entry), if present in their annotation dictionary.
	 * In case no color is specified, CMYK white is returned.
	 */
	ColorPt GetInteriorColor() const;

	/**
	 * Returns the number indicating the interior color space of the annotation. 
	 * 
	 * @return An integer indicating the number of channels forming the color space.
	 * 3 corresponds to RGB, 4 corresponds to CMYK, and 1 corresponds to Gray. 
	 * If the interior is transparent, the return value is 0. 
	 */
	int GetInteriorColorCompNum() const;

	/** 				
	 * Sets the interior color of the Markup annotation.
	 * 
	 * @param c A ColorPt object that denotes the color of the Markup annotation.
	 * @param CompNum An integer indicating the number of channels forming the
	 * color space used. It also defines the length of the array to be allocated
	 * for storing the entries of c. 
	 * @note It is necessary to make sure the consistency between the type of 
	 * parameter c and the value of parameter CompNum. RGB ColorPt corresponds to 3,
	 * CMYK ColorPt corresponds to 4, Gray ColorPt corresponds to 1, and transparent 
	 * corresponds to 0.
 	 * @note According to PDF Reference Manual interior color is not the property 
	 * that is expected for Markup annotations in general, but it applies
	 * to many derived annotation classes and therefore get()/set() methods are
	 * provided in the base class Markup. Annotations that do not use interior color
	 * will ignore the interior color ('IC' entry), if present in their annotation dictionary.
	 *	
	 * Entries out of the specified color space array length will be discarded.
	 * Missing entries for a specified color space will lead to potential 
	 * exceptions.
	 */
	void SetInteriorColor(const ColorPt& c, int CompNum);

	/** 
	 * Returns the inner bounding rectangle of the Markup annotation. 
	 * 
	 * @return A rectangle specifying the region where content should be displayed.
	 *
	 * @note This rectangle can be same as or inside of  the annotation's rectangle.
	 * If it is smaller, such a difference may occur in 
	 * situations where a border effect causes the size of the annotation Rect
	 * entry to increase beyond that of the rectangle. For FreeText annotation with
	 * a callout, content rectangle specifies an inner region for the text to be displayed.
	 * @note According to PDF Reference Manual content rectangle is not the property 
	 * that is expected for Markup annotations in general, but it applies
	 * to many derived annotation classes (FreeText,Square,Circle,Caret) and therefore get()/set() methods are
	 * provided in the base class Markup. Annotations that do not use this property
	 * will ignore the content rectangle ('RD' entry), if present in their annotation dictionary.
	 */
	Rect GetContentRect() const;

	/** 
	 * Sets the inner bounding rectangle of the Markup annotation. (Optional)
	 * 
	 * @param cr A Rect struct to be assign to the 'RD' entry of the annotation dictionary.
	 * @note This rectangle can be same as or inside of  the annotation's rectangle.
	 * If it is smaller, such a difference may occur in 
	 * situations where a border effect causes the size of the annotation Rect
	 * entry to increase beyond that of the rectangle. For FreeText annotation with
	 * a callout, content rectangle specifies an inner region for the text to be displayed.
	 * @note According to PDF Reference Manual content rectangle is not the property 
	 * that is expected for Markup annotations in general, but it applies
	 * to many derived annotation classes (FreeText,Square,Circle,Caret) and therefore get()/set() methods are
	 * provided in the base class Markup. Annotations that do not use this property
	 * will ignore the content rectangle ('RD' entry), if present in their annotation dictionary.
	 */
	void SetContentRect(const Rect& cr);

	/** 
	 * Returns the rectangle difference between overall annotation rectangle and content rectangle.
	 * 
	 * @return A set of four numbers represented as a Rect struct.
	 * @note The four numbers of the returning struct specify the difference
	 * between two rectangles: the Rect entry of the annotation and the actual
	 * bounding box of the underlying rectangle. Such a difference may occur in 
	 * situations where a border effect causes the size of the annotation Rect
	 * entry to increase beyond that of the rectangle.
	 * The four numbers of the returning struct correspond to the differences 
	 * in default user space, between the left, top, right, and bottom of the 
	 * two above mentioned rectangles. 
	 * @note GetPadding() and GetContentRectangle() both use 'RD' entry of the 
	 * annotation dictionary, but represent it to user in different ways.
	 * @see GetContentRect()
	 */
	Rect GetPadding() const;

	/** 
	 * Sets the rectangle difference between overall annotation rectangle and content rectangle. (Optional)
	 * 
	 * @param rd A set of four numbers represented as a Rect struct
	 * @note The four numbers of rd specify the difference
	 * between two rectangles: the Rect entry of the annotation and the actual
	 * bounding box of the underlying rectangle. Such a difference may occur in 
	 * situations where a border effect causes the size of the annotation Rect
	 * entry to increase beyond that of the rectangle.
	 * The four numbers of the rd correspond to the differences 
	 * in default user space, between the left, top, right, and bottom of the 
	 * two above mentioned rectangles. 
	 * @note SetPadding() and SetContentRectangle() both use 'RD' entry of the 
	 * annotation dictionary. Two methods are provided to give users additional 
	 * flexibility and ease of use in setting the values of the 'RD' field.
	 * @see GetContentRect()
	 */
	void SetPadding(const Rect& rd);
	void SetPadding(double x); // this creates 'x' amount of space between the content and the outer rectangle

    /**
	 * Rotates the appearance of the Markup annotation.
	 *
	 * @param angle The new rotation
	 * @Note: Apply a rotation to an existing appearance.
	 * This rotation will be reflected in the bounding rect of the annot (which
	 * will be updated), but not in any other part of the annotation dictionary.
	 * This will effectively create a custom appearance for the annotation,
	 * and any subsequent calls to `RefreshAppearance` will clear this transformation.
	 */
	void RotateAppearance(double angle);


// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
		Markup(TRN_Annot markup);
#endif
// @endcond

};//class Markup
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron
#include <Impl/Markup.inl>

#endif // PDFTRON_H_CPPPDFAnnotsMarkup
