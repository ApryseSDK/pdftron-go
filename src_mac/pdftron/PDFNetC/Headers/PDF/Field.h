//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFField
#define PDFTRON_H_CPPPDFField

#include <Common/UString.h>
#include <SDF/Obj.h>
#include <PDF/GState.h>
#include <C/PDF/TRN_Field.h>
#include <SDF/SignatureHandler.h>
#include <PDF/ViewChangeCollection.h>

namespace pdftron { 
	namespace PDF {

/**
 * An interactive form (sometimes referred to as an AcroForm) is a 
 * collection of fields for gathering information interactively from 
 * the user. A PDF document may contain any number of Fields appearing 
 * on any combination of pages, all of which make up a single, global 
 * interactive form spanning the entire document.
 * 
 * PDFNet fully supports reading, writing, and editing PDF forms and 
 * provides many utility methods so that work with forms is simple and 
 * efficient. Using PDFNet forms API arbitrary subsets of form fields 
 * can be imported or exported from the document, new forms can be 
 * created from scratch, and the appearance of existing forms can be 
 * modified. 
 * 
 * In PDFNet Fields are accessed through FieldIterator-s. The list of 
 * all Fields present in the document can be traversed as follows:
 * 
 * @code
 * FieldIterator itr = pdfdoc.GetFieldIterator();
 * for(; itr.HasNext(); itr.Next()) {
 *   Field field = itr.Current();
 *   Console.WriteLine("Field name: {0}", field.GetName());
 *  }
 * @endcode 
 * 
 * For a full sample, please refer to 'InteractiveForms' sample project.
 * 
 * To search field by name use FieldFind method. For example:
 * @code
 * FieldIterator itr = pdfdoc.FieldFind("name");
 * if (itr.HasNext()) {
 *   Console.WriteLine("Field name: {0}", itr.Current().GetName());
 * }
 * else { ...field was not found... }
 * @endcode 
 * 
 * If a given field name was not found or if the end of the field list 
 * was reached the iterator HasNext() will return false.
 *
 * If you have a valid iterator you can access the Field using Current() method. For example: 
 * Field field = itr.Current();
 *
 * Using Flatten(...) method it is possible to merge field 
 * appearances with the page content. Form 'flattening' refers to the 
 * operation that changes active form fields into a static area that is  
 * part of the PDF document, just like the other text and images in 
 * the document. A completely flattened PDF form does not have any 
 * widget annotations or interactive fields. 
 */
class Field
{
public: 

	/** 
	 * Construct a PDF::Field from a SDF dictionary representing a terminal field node.
	 * @param field_dict the SDF dictionary to construct the field from.
	 */ 
	 Field (SDF::Obj field_dict);

	 Field (const Field& p);
	 Field& operator= (const Field& p);
	 ~Field();

	/**
	 * @return whether this is a valid (non-null) Field. If the 
	 * function returns false the underlying SDF/Cos object is null and 
	 * the Field object should be treated as null as well.
	 */ 	
	 bool IsValid() const;

	/** 
	 * Interactive forms support the following field types:
	 *	- Button fields represent interactive controls on the screen that the user can
	 *	  manipulate with the mouse. They include pushbuttons, check-boxes, and radio buttons.
	 *	- Text fields are boxes or spaces in which the user can enter text from the keyboard.
	 *	- Choice fields contain several text items, at most one of which may be selected as
	 *	  the field value. They include scrollable list boxes and combo boxes.
	 *	- Signature fields represent electronic 'signatures' for authenticating the identity
	 *	  of a user and the validity of the document's contents.
	 */
	enum Type
	{
		e_button,       // Pushbutton field
		e_check,        // Check box field
		e_radio,        // Radio button field
		e_text,         // Text field
		e_choice,       // Choice field
		e_signature,    // Digital signature field
		e_null			// Unknown field type
	};

	/** 
	 * @return The field's value, whose type/format varies depending on the field type.
	 * See the descriptions of individual field types for further information.
	 */
	 Type GetType() const;

	/** 
	 * @return the value of the Field (the value of its /V key) or NULL if the 
	 * value is not specified. 
	 *
	 * The format of field's value varies depending on the field type.
	 */
	 SDF::Obj GetValue();
	 UString GetValueAsString();
	 
	/** 
	 * @return Field value as a boolean.
	 * @note This method is usually for check-box and radio button fields. 
	 */	 
	 bool GetValueAsBool();

	/** 
	 * Sets the value of the field (i.e. the value of the field's /V key).
	 * The format of field's value varies depending on the field type.
	 *
	 * @param value the new field value. 
	 *
	 * @note in order to remove/erase the existing value use pass a SDF::Null
	 * object to SetValue().
	 * 
	 * @note <p>In PDF, Field's value is separate from its annotation (i.e. how the 
	 * field appears on the page). After you modify Field's value you need to 
	 * refresh Field's appearance using RefreshAppearance() method. 
	 * </p><p>
	 * Alternatively, you can delete "AP" entry from the Widget annotation and set 
	 * "NeedAppearances" flag in AcroForm dictionary (i.e. 
	 * doc.GetAcroForm().Put("NeedAppearances", Obj.CreateBool(true)); )
	 * This will force viewer application to auto-generate new field appearances 
	 * every time the document is opened.
	 * </p><p>
	 * Yet another option is to generate a custom annotation appearance using 
	 * ElementBuilder and ElementWriter and then set the "AP" entry in the widget 
	 * dictionary to the new appearance stream. This functionality is useful in 
	 * applications that need advanced control over how the form fields are rendered. 
	 * </p>
	 */
	 ViewChangeCollection SetValue(const UString& value);
	 ViewChangeCollection SetValue(SDF::Obj value);
	 ViewChangeCollection SetValue(const char* value);
	 	
	 enum ActionTriggerEvent
	 {
		 e_action_trigger_keystroke = 13, //Triggered when user modifies text, or selection, in a text, combo or list field
		 e_action_trigger_format = 14, //Triggered before a field value is displayed. 
		 e_action_trigger_validate = 15, //Triggered when a field value is changed
		 e_action_trigger_calculate = 16 //Triggered when field is recalculated due to a change in another field
	 };

	/** 
	 * Sets the value of a check-box or radio-button field.
	 * @param value If true, the filed will be set to 'True', if false the field will 
	 * be set to 'False'.
	 *
	 * @note This method is usually for check-box and radio button fields. 
	 */	 	
	 ViewChangeCollection SetValue(bool value);

	/**
	 * Get the Action associated with the selected Field Trigger event.
	 *
	 * @param trigger the type of trigger event to get
	 * @return the Action Obj if present, otherwise NULL
	 */
	 SDF::Obj GetTriggerAction(Field::ActionTriggerEvent trigger);

	/** 
	 * Regenerates the appearance stream for the Widget Annotation containing 
	 * variable text. Call this method if you modified field's value and would 
	 * like to update field's appearance.
	 *
	 * @note If this field contains text, and has been added to a rotated page, the text in 
	 * the field may be rotated. If RefreshAppearance is called *after* the field is added 
	 * to a rotated page, then any text will be rotated in the opposite direction of the page 
	 * rotation. If this method is called *before* the field is added to any rotated page, then 
	 * no counter rotation will be applied. If you wish to call RefreshAppearance on a field 
	 * already added to a rotated page, but you don't want the text to be rotated, you can do one 
	 * of the following; temporarily un-rotate the page, or, temporarily remove the "P" object 
	 * from the field.
	 */ 
	 void RefreshAppearance();

	/** 
	 * Removes any appearances associated with the field.
	 */ 
	 void EraseAppearance();

	/** 
	 * @return The default value to which the field reverts when a reset-form action 
	 * is executed or NULL if the default value is not specified. 
	 *  
	 * The format of field's value varies depending on the field type. 
	 */
	 SDF::Obj GetDefaultValue();
	 UString GetDefaultValueAsString();

	/** 
	 * @return a string representing the fully qualified name of the field 
	 * (e.g. "employee.name.first").
	 */
	 UString GetName();

	/** 
	 * @return a string representing the partial name of the field (e.g. 
	 * "first" when "employee.name.first" is fully qualified name).
	 */
	 UString GetPartialName();

	/** 
	 * Modifies the field name.
	 * 
	 * @param field_name a string representing the fully qualified name of 
	 * the field (e.g. "employee.name.first").
	 */
	 void Rename(const UString& field_name);

	/**
	 * @return true if this Field is a Widget Annotation
	 * 
	 * Determines whether or not this Field is an Annotation. 
	 */
	 bool IsAnnot() const;

	/**
	 * Flags specifying various characteristics of the fields.
	 * 
	 * Field flags common to all field types: 
	 * ----------------------------------------------
	 * - If e_read_only flag is set the user may not change the value 
	 * of the field. Any associated widget annotations will not interact with 
	 * the user; that is, they will not respond to mouse clicks or change their 
	 * appearance in response to mouse motions. This flag is useful for fields 
	 *  whose values are computed or imported from a database.
   	 *
	 * - If e_required flag is set, the field must have a value at the time 
	 * it is exported by a submit-form action.
	 *
	 * - If e_no_export flag is set, the field must not be exported by a 
	 * submit-form action.
	 * 
	 * Field flags specific to radio buttons: 
	 * ----------------------------------------------
	 * - If e_toggle_to_off is clear, exactly one radio button must be selected 
	 * at all times; clicking the currently selected button has no effect. 
	 * If set, clicking the selected button deselects it, leaving no button selected.
	 * 
	 * - If e_radios_in_unison is set, a group of radio buttons within a radio button 
	 * field that use the same value for the on state will turn on and off in unison; 
	 * that is if one is checked, they are all checked. If clear, the buttons are 
	 * mutually exclusive (the same behavior as HTML radio buttons).
	 * 
	 * Field flags specific to text fields: 
	 * ----------------------------------------------
	 * - If e_multiline is set, the field can contain multiple lines of text; 
	 * if clear, the field's text is restricted to a single line.
	 * 
	 * - If e_password If set, the field is intended for entering a secure password 
	 * that should not be echoed visibly to the screen. Characters typed from the 
	 * keyboard should instead be echoed in some unreadable form, such as asterisks 
	 * or bullet characters. The value is not stored if this flag is set.
	 * 
	 * - If e_file_select is set, the text entered in the field represents the pathname 
	 * of a file whose contents are to be submitted as the value of the field.
	 * 
	 * - If e_no_spellcheck is set, text entered in the field is not spell-checked.
 	 *  
	 * - If e_no_scroll is set, the field does not scroll (horizontally for single-line 
	 * fields, vertically for multiple-line fields) to accommodate more text than fits
	 * within its annotation rectangle. Once the field is full, no further text is 
	 * accepted.
	 * 
	 * - If e_comb is set, the field is automatically divided into as many equally
	 * spaced positions, or combs, as the value of MaxLen, and the text is laid out
	 * into those combs. Meaningful only if the MaxLen entry is present in the text 
	 * field and if the Multiline, Password, and FileSelect flags are clear. 
	 * 
	 * - If e_rich_text is set, the value of this field should be represented as a rich 
	 * text string. If the field has a value, the RV entry of the field dictionary 
	 * specifies the rich text string.
	 * 
	 * Field flags specific to choice fields: 
	 * ----------------------------------------------
	 * 
	 * - If e_combo is set, the field is a combo box; 
	 * if clear, the field is a list box.
	 * 
	 * - If e_edit is set, the combo box includes an editable text box as well as a 
	 * dropdown list; if clear, it includes only a drop-down list. This flag is 
	 * meaningful only if the e_combo flag is set.
	 * 
	 * - If e_sort is set, the field's option items should be sorted alphabetically. 
	 * This flag is intended for use by form authoring tools, not by PDF viewer 
	 * applications. Viewers should simply display the options in the order in
	 * which they occur in the Opt array.
	 * 
	 * - If e_multiselect is set, more than one of the field's option items may be 
	 * selected simultaneously; if clear, no more than one item at a time may be
	 * selected.
	 * 
	 * - If e_commit_on_sel_change is set, the new value is committed as soon as a 
	 * selection is made with the pointing device. This option enables applications 
	 * to perform an action once a selection is made, without requiring the user
	 * to exit the field. If clear, the new value is not committed until the user
	 * exits the field.
	 */
	enum Flag
	{        
		e_read_only,                // Common flags
		e_required,
		e_no_export,
		
		e_pushbutton_flag,          // Pushbutton flags
		
		e_radio_flag,               // Radio buttons flags
		e_toggle_to_off,            
		e_radios_in_unison,
		
		e_multiline,                // Text fields flags
		e_password,
		e_file_select,
		e_no_spellcheck,
		e_no_scroll,
		e_comb,
		e_rich_text,
		 
		e_combo,                    // Choice fields flags
		e_edit,
		e_sort,
		e_multiselect,
		e_commit_on_sel_change
	};

	/** 
	 * @return the value of given field flag
	 */
	 bool GetFlag(Flag flag) const;
    
	/** 
	 * Set the value of given FieldFlag. 
	 * 
	 * @note You can use this method to set the field as read-only.
	 * An alternative approach to set the field as read only is using Page.Flatten(...) 
	 * method. Unlike Flatten(...), the result of SetFlag(...) can be programatically 
	 * reversed.
	 */
	 void SetFlag(Flag flag, bool value);

	/**
	* Enumeration specifying the form of quadding (justification) to be used
	* in displaying the text fields. 
	*/ 
	enum TextJustification 
	{
		e_left_justified,
		e_centered,
		e_right_justified
	};

	/** 
	 * @return the form of quadding (justification) to be used in displaying 
	 * the text fields.
	 */
	 TextJustification GetJustification();

	/** 
	 * Sets the justification to be used in displaying the text field.
	 * @param j enum representing justification to set the text field to, options are e_left_justified, e_centered and e_right_justified
	 * @note This method is specific to a text field.
	 */
	 void SetJustification(TextJustification j);

	/** 
	 * Sets the maximum length of the field's text, in characters.
	 * @param max_len maximum length of a field's text.
	 * @note This method is specific to a text field.
	 */
	void SetMaxLen(int max_len);

	/**
	 * Returns the total number of options in a list or combo box.
	 */
	int GetOptCount() const;

	/**
	 * @param index index position of the option to retrieve.
	 * @return The string of the option at the givent index.
	 * @note The index must be less than the value returned by GetOptCount().
	 */
	UString GetOpt(int index);
	
	/** 
	 * @return The maximum length of the field's text, in characters, or a 
	 * negative number if the length is not limited.
	 * @note This method is specific to a text field.
	 */
	int GetMaxLen() const;

	/** 
	 * @return The default graphics state that should be used in formatting the 
	 * text. The state corresponds to /DA entry in the field dictionary.
	 */
	GState GetDefaultAppearance();

	/**
	 * Flatten/Merge existing form field appearances with the page content and
	 * remove widget annotation.
	 * 
	 * Form 'flattening' refers to the operation that changes active form fields 
	 * into a static area that is part of the PDF document, just like the other 
	 * text and images in the document. A completely flattened PDF form does not 
	 * have any widget annotations or interactive fields. 
	 * 
	 * @param page page object to flatten
	 * @note an alternative approach to set the field as read only is using 
	 * Field.SetFlag(Field::e_read_only, true) method. Unlike Field.SetFlag(...), 
	 * the result of Flatten() operation can not be programatically reversed.
	 */
	 void Flatten(class Page page);

	 /**
	 * @return The rectangle that should be refreshed after changing a field.
	 */
	 Rect GetUpdateRect() const;

	/**
	 * Some of the Field attributes are designated as inheritable.
	 * If such an attribute is omitted from a Field object, its value is inherited 
	 * from an ancestor node in the Field tree. If the attribute is a required one, 
	 * a value must be supplied in an ancestor node; if it is optional and no 
	 * inherited value is specified, the default value should be used.
	 *
	 * The function walks up the Field inheritance tree in search for specified 
	 * attribute.
	 * 
	 * @return The attribute value if the given attribute name was found 
	 * or a NULL object if the given attribute name was not found.
	 *
	 *  Resources dictionary (Required; inheritable) 
	 *  MediaBox rectangle (Required; inheritable)
	 *  CropBox rectangle (Optional; inheritable)
	 *  Rotate integer (Optional; inheritable)
	 */
	 SDF::Obj FindInheritedAttribute (const char* attrib) const;

	/**
	 * @return the underlying SDF/Cos object.
	 */
	 SDF::Obj GetSDFObj () const;

	 /** 
	  * @return true if the object is not null, false otherwise.  
	  */ 
	 operator bool () { return IsValid();}

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

    /**
     * Sets the signature handler to use for adding a signature to this field. If the signature handler is not found
     * in PDFDoc's signature handlers list, this field will not be signed. To add signature handlers, use PDFDoc.AddSignatureHandler
     * method.
     *
     * If a signature handler is already assigned to this field and this method is called once again, the associate signature
     * handler for this field will be updated with the new handler.
     *
     * @param signature_handler_id The unique id of the SignatureHandler to use for adding signature in this field.
     * 
     * @return The signature dictionary created using the SignatureHandler, or NULL pointer if the signature handler is not found.
     */
    SDF::Obj UseSignatureHandler(const SDF::SignatureHandlerId signature_handler_id);

	/** 
	 * Returns whether modifying this field would invalidate a digital signature in the document.
	 * 
	 * @return whether modifying this field would invalidate a digital signature in the document
	 */
	bool IsLockedByDigitalSignature() const;
	
// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_Field mp_field;
	Field ();
#endif
// @endcond

};



	};	// namespace PDF
};	// namespace pdftron


#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFField
