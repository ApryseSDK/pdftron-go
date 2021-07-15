//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFComboBoxWidget
#define PDFTRON_H_CPPPDFComboBoxWidget

#include <PDF/Annots/Widget.h>

namespace pdftron {
	namespace PDF {
		namespace Annots {

/** 
 * An object representing a combo box used in a PDF Form.
 */
class ComboBoxWidget : public Widget
{
public:
	/**
	 * Creates a Combo Box Widget annotation and initialize it using given Cos/SDF object.
	 *
	 * <p>
	 * <b> Note: </b> The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param d the object to use to initialize the ComboBoxWidget
	 */
	ComboBoxWidget(SDF::Obj d = 0);

	/**
	 * Creates a Combo Box Widget annotation and initialize it using given annotation object.
	 *
	 * <p> 
	 * <b> Note: </b>  The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param annot The annotation to use.
	 */
	ComboBoxWidget(const Annot& annot);

	/**
	 * Creates a new Combo Box Widget annotation, in the specified document.
	 *
	 * @param doc The document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param field_name The name of the field for which to create a ComboBox widget
	 * @return A newly created blank Combo Box Widget annotation.
	 */
	static ComboBoxWidget Create(PDFDoc& doc, const Rect& pos, const UString& field_name = "");

	/**
	 * Creates a new Widget annotation, in the specified document.
	 *
	 * @param doc The document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param field The field for which to create a Text widget
	 * @return A newly created blank Widget annotation.
	 */
	static ComboBoxWidget Create(PDFDoc& doc, const Rect& pos, const Field& field);

	/**
	 * Adds an option to Combo Box widget.
	 *
	 * @param value The option to add
	 */
	void AddOption(const UString& value);

#ifdef SWIG
	/**
	 * Adds multiple options to Combo Box widget.
	 *
	 * @param opts The options to add
	 */
	void AddOptions(const std::vector<std::string>& opts);

	/**
	 * Gets all options of the Combo Box widget.
	 *
	 * @return The options of the Combo Box widget
	 */
	std::vector<std::string> GetOptions();

	/**
	 * Replaces the current Combo Box widget options with a new set.
	 *
	 * @param new_opts The new set of options to use.
	 */
	void ReplaceOptions(const std::vector<std::string>& new_opts);
#else
	/**
	 * Adds multiple options to Combo Box widget.
	 *
	 * @param opts The options to add
	 */
	void AddOptions(const std::vector<UString>& opts);
	/**
	 * Gets all options of the Combo Box widget.
	 *
	 * @return The options of the Combo Box widget
	 */
	std::vector<UString> GetOptions();

	/**
	 * Replaces the current Combo Box widget options with a new set.  
	 *
	 * @param new_opts The new set of options to use.
	 */
	void ReplaceOptions(const std::vector<UString>& new_opts);
#endif

	/**
	 *  Selects the given option in the Combo Box widget
	 *
	 * @param value The option to select
	 */
	void SetSelectedOption(const UString& value);

	/**
	 * Retrieves the option selected in the ComboBox widget
	 *
	 * @return The option selected in the ComboBox widget
	 */
	UString GetSelectedOption();

	/**
	 * Removes the option from Combo Box widget. 
	 *
	 * @param value The option to remove
	 */
	void RemoveOption(const UString& value);
};

		}; //namespace Annots
	}; //namespace PDF
}; //namespace pdftron

#include <Impl/ComboBoxWidget.inl>

#endif // PDFTRON_H_CPPPDFComboBoxWidget