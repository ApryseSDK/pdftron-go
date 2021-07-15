//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFRadioButtonGroup
#define PDFTRON_H_CPPPDFRadioButtonGroup

#include <PDF/PDFDoc.h>
#include <PDF/Annots/RadioButtonWidget.h>

namespace pdftron {
	namespace PDF {
		namespace Annots {

/**
 * An object representing a Group of Radio Buttons that can be used to create new Radio Buttons. 
 * If a group contains multiple buttons they will be connected.
 */
class RadioButtonGroup
{
public:
	/**
	 * Creates a RadioButtonGroup and initialize it using given Field object.
	 *
	 * <p>
	 * <b> Note: </b> The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param field The field with which to initialize the RadioButtonGroup
	 */
	RadioButtonGroup(const Field& field);

	/**
	 * Creates a new RadioButtonGroup in the specified document.
	 *
	 * @param doc The document in which the RadioButtonGroup is created.
	 * @param field_name The name of the field to create and use in this RadioButtonGroup.
	 * @return A newly created RadioButtonGroup.
	 */
	static RadioButtonGroup Create(PDFDoc& doc, const UString& field_name = "");

	/**
	 * Adds a new RadioButtonWidget to the RadioButtonGroup 
	 *
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param onstate  The onstate for this button. This will rarely need to be explicitly set. However, it can be used to allow 
	 * multiple radiobuttons in a group to be on at once if they have the same onstate.
	 * @return A newly created default RadioButtonWidget.
	 */
	RadioButtonWidget Add(const Rect& pos, const char* onstate = "");

	/**
	 * Gets the number of buttons in this RadioButtonGroup 
	 *
	 * @return The number of buttons in this RadioButtonGroup
	 */	
	UInt32 GetNumButtons();

	/**
	 * Retrieves the button at a given index.
 	 * @param index The index to use.
	 * @return The RadioButtonWidget at the given index
	 */	
	RadioButtonWidget GetButton(UInt32 index);

	/**
	 * Gets the field associated with this RadioButtonGroup
	 * @return The Field associated with this RadioButtonGroup
	 */	
	Field GetField() const;
	
	/**
	 * Add all group buttons to the page
 	 * @param page The page in which to add the buttons.
	 */			
	void AddGroupButtonsToPage(Page page);

	RadioButtonGroup(const RadioButtonGroup& group);
	RadioButtonGroup& operator=(const RadioButtonGroup& c);
	RadioButtonGroup(TRN_RadioButtonGroup impl);
	~RadioButtonGroup();
private:
	TRN_RadioButtonGroup mp_group;
};
		} //namespace Annots
	} //namespace PDF
} //namespace pdftron


#include <Impl/RadioButtonGroup.inl>

#endif // PDFTRON_H_CPPPDFRadioButtonGroup