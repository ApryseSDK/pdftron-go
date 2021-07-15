//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFListBoxWidget
#define PDFTRON_H_CPPPDFListBoxWidget

#include <PDF/Annots/Widget.h>

namespace pdftron {
	namespace PDF {
		namespace Annots {

/** 
 * An object representing a List Box used in a PDF Form.
 */
class ListBoxWidget : public Widget
{
public:
	/**
	 * Creates a List Box Widget annotation and initialize it using given Cos/SDF object.
	 *
	 * <p>
	 * <b> Note: </b> The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param d the object to use to initialize the List Box Widget
	 */
	ListBoxWidget(SDF::Obj d = 0);

	/**
	 * Creates a List Box Widget annotation and initialize it using given annotation object.
	 *
	 * <p> 
	 * <b> Note: </b>  The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 *
	 * @param annot The annotation to use.
	 */
	ListBoxWidget(const Annot& annot);

	/**
	 * Creates a new List Box Widget annotation, in the specified document.
	 *
	 * @param doc The document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param field_name The name of the field for which to create a List Box Widget
	 * @return A newly created blank List Box Widget annotation.
	 */
	static ListBoxWidget Create(PDFDoc& doc, const Rect& pos, const UString& field_name = "");

	/**
	 * Creates a new List Box Widget annotation, in the specified document.
	 *
	 * @param doc The document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, specified in
	 * user space coordinates.
	 * @param field the field for which to create a List Box Widget
	 * @return A newly created blank List Box Widget annotation.
	 */
	static ListBoxWidget Create(PDFDoc& doc, const Rect& pos, const Field& field);

	/**
	 * Adds option to List Box Widget.
	 *
	 * @param value The option to add
	 */
	void AddOption(const UString& value);

#ifdef SWIG
	/**
	 * Adds multiple options to List Box Widget.
	 *
	 * @param opts The options to add.
	 */
	void AddOptions(const std::vector<std::string>& opts);

	/**
	 * Sets the options for the ListBox widget. 
	 *
	 * @param selected_opts The options to select.
	 */
	void SetSelectedOptions(const std::vector<std::string>& selected_opts);

	/**
	 * Gets all selected options in the List Box widget.
	 *
	 * @return The selected options of the List Box widget
	 */
	std::vector<std::string> GetSelectedOptions();

	/**
	 * Gets all options of the List Box widget.
	 *
	 * @return The options of the List Box widget
	 */
	std::vector<std::string> GetOptions();

	/**
	 * Replaces the current List Box widget options with a new set.
	 *
	 * @param new_opts The new set of options to use.
	 */
	void ReplaceOptions(const std::vector<std::string>& new_opts);
#else
	/**
	 * Adds multiple options to List Box Widget.
	 *
	 * @param opts The options to add.
	 */	
	void AddOptions(const std::vector<UString>& opts);

	/**
	 * Sets the options for the ListBox widget. 
	 *
	 * @param selected_opts The options to select.
	 */
	void SetSelectedOptions(const std::vector<UString>& selected_opts);

	/**
	 * Gets all selected options in the List Box widget.
	 *
	 * @return The selected options of the List Box widget
	 */
	std::vector<UString> GetSelectedOptions();

	/**
	 * Gets all options of the List Box widget.
	 *
	 * @return The options of the List Box widget.
	 */
	std::vector<UString> GetOptions();

	/**
	 * Replaces the current List Box widget options with a new set.
	 *
	 * @param new_opts The new set of options to use.
	 */
	void ReplaceOptions(const std::vector<UString>& new_opts);
#endif

	/**
	 * Removes the option from List Box widget. 
	 *
	 * @param value The option to remove.
	 */
	void RemoveOption(const UString& value);
};

		}; //namespace Annots
	}; //namespace PDF
}; //namespace trn

#include <Impl/ListBoxWidget.inl>

#endif //PDFTRON_H_CPPPDFListBoxWidget