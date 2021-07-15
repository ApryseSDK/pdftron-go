//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFTextWidget
#define PDFTRON_H_CPPPDFTextWidget

#include <PDF/Annots/Widget.h>

namespace pdftron {
	namespace PDF {
		namespace Annots {

/** 
 *  An object representing a Text Box used in a PDF Form.
 */
class TextWidget : public Widget
{
public:
	/**
	 * Creates a Text Widget annotation and initialize it using given Cos/SDF object.
	 *
	 * <p>
	 * <b> Note: </b> The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param d The object to use to initialize the Text Widget
	 */
	TextWidget(SDF::Obj d = 0);

	/**
	 * Creates a Text Widget annotation and initialize it using given annotation object.
	 *
	 * <b> Note: </b>  The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param annot The annotation object to use.
	 */
	TextWidget(const Annot& annot);

	/**
	 * Creates a new Text Widget annotation, in the specified document.
	 *
	 * @param doc The document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param field_name The name of the field for which to create a Text widget.
	 * @return A newly created blank Text Widget annotation.
	 */
	static TextWidget Create(PDFDoc& doc, const Rect& pos, const UString& field_name = "");

	/**
	 * Creates a new Text Widget annotation, in the specified document.
	 *
	 * @param doc The document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param field the field for which to create a Text Widget.
	 * @return A newly created blank Widget annotation.
	 */
	static TextWidget Create(PDFDoc& doc, const Rect& pos, const Field& field);

	/**
	 * Sets the text content of the Text Widget.
	 * 
 	 * @param text The text to be displayed in the Text Widget.
	 */
	void SetText(const UString& text);

	/**
	 * Retrieves the text content of the Text Widget.
	 *
	 * @return  The Text Widget contents.
	 */
	UString GetText();
};

		}; //namespace Annots
	}; //namespace PDF
}; //namespace pdftron


#include <Impl/TextWidget.inl>

#endif // PDFTRON_H_CPPPDFTextWidget