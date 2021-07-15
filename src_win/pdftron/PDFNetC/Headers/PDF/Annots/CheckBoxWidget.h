//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFCheckBoxWidget
#define PDFTRON_H_CPPPDFCheckBoxWidget

#include <PDF/Annots/Widget.h>

namespace pdftron {
	namespace PDF {
		namespace Annots {

/** 
 * An object representing a check box used in a PDF Form.
 */
class CheckBoxWidget : public Widget
{
public:
	/**
	 * Creates a Check Box Widget annotation and initialize it using given Cos/SDF object.
	 *
	 * <p>
	 * <b> Note: </b> The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param d the object to use to initialize the Check Box Widget
	 */
	CheckBoxWidget(SDF::Obj d = 0);

	/**
	 * Creates a Check Box Widget annotation and initialize it using given annotation object.
	 *
	 * <p> 
	 * <b> Note: </b>  The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param annot The annotation object to use.
	 */
	CheckBoxWidget(const Annot& annot);

	/**
	 * Creates a new Check Box Widget annotation, in the specified document.
	 *
	 * @param doc The document to which the annotation is to be added.
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param field_name The name of the field for which to create a CheckBox widget.
	 * @return A newly created blank Check Box Widget annotation.
	 */
	static CheckBoxWidget Create(PDFDoc& doc, const Rect& pos, const UString& field_name = "");

	/**
	 * Creates a new Check Box Widget annotation, in the specified document.
	 *
	 * @param doc The document to which the annotation is to be added.
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param field the field for which to create a CheckBox widget
	 * @return A newly created blank Check Box Widget annotation.
	 */
	static CheckBoxWidget Create(PDFDoc& doc, const Rect& pos, const Field& field);

	/**
	 * Returns whether the checkbox is checked.
	 *
	 * @return  A boolean value indicating whether the checkbox is checked.
	 */
	bool IsChecked();

	/**
	 * Check or uncheck the Check Box Widget
	 *
	 * @param value If true, the annotation should be checked. Otherwise it should be unchecked.
	 */
	void SetChecked(bool checked);
};

		}; //namespace Annots
	}; //namespace PDF
}; //namespace trn

#include <Impl/CheckBoxWidget.inl>

#endif // PDFTRON_H_CPPPDFCheckBoxWidget