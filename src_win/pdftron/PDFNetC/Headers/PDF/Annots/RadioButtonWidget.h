//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFRadioButtonWidget
#define PDFTRON_H_CPPPDFRadioButtonWidget

#include <PDF/Annots/Widget.h>

namespace pdftron {
	namespace PDF {
		namespace Annots {

class RadioButtonGroup;

/** 
 * An object representing a Radio Button used in a PDF Form.
 */
class RadioButtonWidget : public Widget
{
public:
	/**
	 * Creates a Radio Button Widget annotation and initialize it using given Cos/SDF object.
	 *
	 * <p>
	 * <b> Note: </b> The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param d the object to use to initialize the Radio Button Widget
	 */
	RadioButtonWidget(SDF::Obj d = 0);

	/**
	 * Creates a Radio Button Widget annotation and initialize it using given annotation object.
	 *
	 * <p> 
	 * <b> Note: </b>  The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param annot The annotation to use.
	 */
	RadioButtonWidget(const Annot& annot);

	/**
	 * Gets the group to which the current button is connected.
	 *
	 * @return The group containing this Radio Button.
	 */
	RadioButtonGroup GetGroup();

	/**
	 * Enable the current radio button. Note that this may disable other Radio Buttons in the same group.
	 */
	void EnableButton();

	/**
	 * Determines whether this button is enabled.
	 *
	 * @return A boolean value indicating whether the Radio Button is enabled.
	 */
	bool IsEnabled();
};
		} //namespace Annots
	} //namespace PDF
} //namespace trn

#include <PDF/Annots/RadioButtonGroup.h>

#endif //PDFTRON_H_CPPPDFRadioButtonWidget