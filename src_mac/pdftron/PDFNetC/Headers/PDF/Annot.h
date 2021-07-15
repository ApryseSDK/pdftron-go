//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnot
#define PDFTRON_H_CPPPDFAnnot

#include <vector>
#include <SDF/Obj.h>
#include <PDF/Date.h>
#include <SDF/SDFDoc.h>
#include <PDF/Rect.h>
#include <PDF/ColorSpace.h>
#include <PDF/FileSpec.h>
#include <PDF/Page.h>
#include <C/PDF/TRN_Annot.h>
#include <PDF/RefreshOptions.h>

namespace pdftron { 
	namespace PDF {
class BorderStyle;
/** 
 * Annot is a base class for different types of annotations. For annotation 
 * specific properties, please refer to derived classes. 
 * 
 * An annotation is an interactive object placed on a page, such as a text note, a link, 
 * or an embedded file. PDF includes a wide variety of standard annotation types. 
 * An annotation associates an object such as a widget, note, or movie with a location
 * on a page of a PDF document, or provides a means of interacting with the user
 * via the mouse and keyboard. For more details on PDF annotations please refer to 
 * section 12.5 in the PDF Reference Manual and the documentation in derived classes.
 */
class Annot
{
public: 
	typedef pdftron::PDF::BorderStyle BorderStyle;
	/**
	* PDF supports the standard annotation types listed in the following enumeration 
	* (plug-in extensions may add new annotation types):
	*/
	enum Type
	{
		e_Text,           ///< Text annotation
		e_Link,           ///< Link annotation
		e_FreeText,       ///< Free text annotation
		e_Line,           ///< Line annotation
		e_Square,         ///< Square annotation
		e_Circle,         ///< Circle annotation
		e_Polygon,        ///< Polygon annotation
		e_Polyline,       ///< Polyline annotation
		e_Highlight,      ///< Highlight annotation
		e_Underline,      ///< Underline annotation
		e_Squiggly,       ///< Squiggly-underline annotation
		e_StrikeOut,      ///< Strikeout annotation
		e_Stamp,          ///< Rubber stamp annotation
		e_Caret,          ///< Caret annotation
		e_Ink,            ///< Ink annotation
		e_Popup,          ///< Pop-up annotation
		e_FileAttachment, ///< File attachment annotation
		e_Sound,          ///< Sound annotation
		e_Movie,          ///< Movie annotation
		e_Widget,         ///< Widget annotation
		e_Screen,         ///< Screen annotation
		e_PrinterMark,    ///< Printer's mark annotation
		e_TrapNet,        ///< Trap network annotation
		e_Watermark,      ///< Watermark annotation
		e_3D,             ///< 3D annotation
		e_Redact,         ///< Redact annotation
		e_Projection,	  ///< Projection annotation, Adobe supplement to ISO 32000 
		e_RichMedia,      ///< Rich Media annotation, Adobe supplement to ISO 32000 
		e_Unknown         ///< Any other annotation type, not listed in PDF spec and unrecognized by PDFTron software
	};

	/** 
	* Creates a new annotation of a given type, in the specified document.
	* The newly created annotation does not contain any properties specific 
	* to a given annotation type, which means an invalid annotation object could be created.
	* It is therefore recommended to always create an annotation using type specific methods,
	* such as Annots::Line::Create() or Annots::FileAttachment::Create().
	* Users should only call Annot::Create() to create annotations of non-standard types
	* that are not recognized by PDFTron software (by using Annot::e_Unknown as a type).
	* 
	* @param doc A document to which the annotation is added.
	* @param type Subtype of annotation to create.
	* @param pos A rectangle specifying the annotation's bounds, specified in 
	* user space coordinates.
	* 
	* @return A newly created blank annotation for the given annotation type.
	*/
	static Annot Create(SDF::SDFDoc& doc, Type type, const Rect& pos);

	/**
	* Create an annotation and initialize it using given Cos/SDF object.
	* @param d The Cos/SDF object to initialze the annotation with.
	* @note The constructor does not copy any data, but is instead the logical
	* equivalent of a type cast.
	*/
	Annot (SDF::Obj d = 0);

	/**
	* Copy constructor
	*/
	Annot (const Annot& d);

	/**
	* Assignment operator
	*/
	Annot& operator=(const Annot& d);

	/**
	* Compares two annotations for equality. The comparison will return true
	* only if both annotations share the same underlying SDF/Cos object.
	* @param d Annotation to compare to
	*/
	bool operator==(const Annot& d);

	/**
	* @return True if this is a valid (non-null) annotation, false otherwise. 
	* If the function returns false the underlying SDF/Cos object is null or is 
	* not valid and the annotation object should be treated as a null object.
	*/ 
	bool IsValid() const;

	/**
	* @return The underlying SDF/Cos object.
	*/
	SDF::Obj GetSDFObj () const;	

	/**
	* @return The type of this annotation. Corresponds to the "Subtype" entry of annotation
	* dictionary, as per PDF Reference Manual section 12.5.2
	*/
	Type GetType() const;

	/**
	* @return Annotation's bounding rectangle, specified in user space coordinates.
	* 
	* The meaning of the rectangle depends on the annotation type. For Link and RubberStamp 
	* annotations, the rectangle specifies the area containing the hyperlink area or stamp. 
	* For Note annotations, the rectangle is describing the popup window when it's opened. 
	* When it's closed, the icon is positioned at lower left corner. 
	*/
	Rect GetRect() const;

	/**
	* It is possible during viewing that GetRect does not return the most accurate bounding box
	* of what is actually rendered. This method calculates the bounding box, rather than relying
	* on what is specified in the PDF document. The bounding box is defined as the smallest
	* rectangle that includes all the visible content on the annotation.
	*
	* @return the bounding box for this annotation. The dimensions are specified in user space
	* coordinates.
	*/
	Rect GetVisibleContentBox() const;

	/**
	* Return true if this annotation is classified as a markup annotation.
	*
	* @return boolean value, true if this annotation is classified as a markup annotation.
	*/
	bool IsMarkup() const;

	/**
	* Sets the size and location of an annotation on its page.
	* @param pos Annotation's bounding rectangle, specified in user space coordinates.
	*
	* The meaning of the rectangle depends on the annotation type. For Link and RubberStamp 
	* annotations, the rectangle specifies the area containing the hyperlink area or stamp. 
	* For Note annotations, the rectangle is describing the popup window when it's opened. 
	* When it's closed, the icon is positioned at lower left corner. 
	*/
	void SetRect(const Rect& pos);

	/** 
	* Gets the page the annotation is associated with. 
	* 
	* @return A Page object or null page object if the page reference is not available. 
	* The page object returned is an indirect reference to the page object with which 
	* this annotation is associated. 
	* This entry shall be present in screen annotations associated with rendition actions. 
	* 
	* Optional. PDF 1.3 PDF 1.4 PDF 1.5 not used in FDF files. 
	*/
	Page GetPage() const;

	/** 
	* Sets the reference to a page the annotation is associated with. 
	* (Optional PDF 1.3; not used in FDF files)
	* 
	* @param page The page object user wants the annotation to be associated with.
	*  
	* @note The parameter should be an indirect reference to the page object with 
	* which this annotation is associated. This entry shall be present in screen 
	* annotations associated with rendition actions   			
	*/
	void SetPage(const Page& page);

	/**
	* @return The unique identifier for this annotation, or NULL if the identifier is not 
	* available. The returned value is a String object and is the value of the "NM" 
	* field, which was added as an optional attribute in PDF 1.4. 
	*/
	SDF::Obj GetUniqueID() const;

	/**
	* Sets the unique identifier for this annotation. 
	* @param id A buffer containing a unique identifier for this annotation.
	* @param id_buf_sz The size of 'id' buffer, or 0 if the string is NULL terminated.
	* @note It is necessary to ensure that the unique ID generated is actually unique. 
	*/
	void SetUniqueID(const char* id, int id_buf_sz = 0);

	/**
	* Gets an annotation's last modified date.
	* @return The annotation's last modified time and date. If the annotation has no associated
	* date structure, the returned date is not valid (date.IsValid() returns false). Corresponds
	* to the "M" entry of the annotation dictionary.
	*/
	Date GetDate() const;

	/**
	* Sets an annotation's last modified date.
	* @param date The annotation's last modified time and date. Corresponds to the "M" entry of the
	* annotation dictionary.
	*/
	void SetDate(const Date& date);

	/** 
	* Flags specifying various characteristics of the annotation.
	* 
	* - If e_invisible is set, do not display the annotation if it does not belong to 
	* one of the standard annotation types and no annotation handler is available. If clear, 
	* display such an unknown annotation using an appearance stream specified by its appearance 
	* dictionary, if any. 
	* 
	* - If e_hidden is set, do not display or print the annotation or allow it to interact
	* with the user, regardless of its annotation type or whether an annotation handler 
	* is available.
	* 
	* - If e_print is set, print the annotation when the page is printed. If clear, never
	* print the annotation, regardless of whether it is displayed on the screen. This can be 
	* useful, for example, for annotations representing interactive pushbuttons, which would 
	* serve no meaningful purpose on the printed page.
	* 
	* - If e_no_zoom is set, do not scale the annotation's appearance to match the 
	* magnification of the page.
	* 
	* - If e_no_rotate is set, do not rotate the annotation's appearance to match the rotation 
	* of the page.
	* 
	* - If e_no_view is set, do not display the annotation on the screen or allow it to
	* interact with the user. The annotation may be printed (depending on the setting of the 
	* Print flag) but should be considered hidden for purposes of on-screen display and user 
	* interaction.
	* 
	* - If e_read_only is set, do not allow the annotation to interact with the user. The
	* annotation may be displayed or printed (depending on the settings of the NoView and Print 
	* flags) but should not respond to mouse clicks or change its appearance in response to 
	* mouse motions.
	* 
	* - If e_locked is set, do not allow the annotation to be deleted or its properties 
	* (including position and size) to be modified by the user. However, this flag does not 
	* restrict changes to the annotation's contents, such as the value of a form field.
	* 
	* - If e_toggle_no_view is set, invert the interpretation of the NoView flag for certain 
	* events. A typical use is to have an annotation that appears only when a mouse cursor is
	* held over it.
	*
	* - If e_locked_contents is set, do not allow the contents of the annotation to be modified 
	* by the user. This flag does not restrict deletion of the annotation or changes to other 
	* annotation properties, such as position and size.	
	*/
	enum Flag
	{
		e_invisible,         // PDF 1.2
		e_hidden,            // PDF 1.2
		e_print,             // PDF 1.2
		e_no_zoom,           // PDF 1.3
		e_no_rotate,         // PDF 1.3
		e_no_view,           // PDF 1.3
		e_read_only,         // PDF 1.3
		e_locked,            // PDF 1.4
		e_toggle_no_view,     // PDF 1.5
		e_locked_contents    // PDF 1.7
	};


	/** 
	* @return The value of given Flag
	* @param flag The Flag property to query.
	*/
	bool GetFlag(Flag flag) const;

	/** 
	* Sets the value of given Flag. 
	*
	* @param flag The Flag property to modify.
	* @param value The new value for the property.
	*/
	void SetFlag(Flag flag, bool value);

	enum ActionTriggerEvent
	{
		e_action_trigger_activate = 0, //Triggered when the annotation is activated. if present, takes precedence over U entry (e_action_trigger_annot_up)
		e_action_trigger_annot_enter = 1, //Triggered when the cursor enters the annotation's active area
		e_action_trigger_annot_exit = 2, //Triggered when the cursor exits the annotation's active area
		e_action_trigger_annot_down = 3, //Triggered when the mouse button is pressed inside the annotation’s active area
		e_action_trigger_annot_up = 4, //Triggered when the mouse button is released inside the annotation’s active area
		e_action_trigger_annot_focus = 5, //Triggered when the annotation receives the input focus
		e_action_trigger_annot_blur = 6, //Triggered when the annotation loses the input focus
		e_action_trigger_annot_page_open = 7, //Triggered when the page containing the annotation is opened
		e_action_trigger_annot_page_close = 8, //Triggered when the page containing the annotation is closed 
		e_action_trigger_annot_page_visible = 9, //Triggered when the page containing the annotation becomes visible
		e_action_trigger_annot_page_invisible = 10 //Triggered when the page containing the annotation is no longer visible in the interactive PDF processor’s user interface
	};

   /**
	* Get the Action associated with the selected Annot Trigger event.
	*
	* @param trigger the type of trigger event to get
	* @return the Action Obj if present, otherwise NULL
	*/
	SDF::Obj GetTriggerAction(Annot::ActionTriggerEvent trigger);



	/**
	* Gets the border style for the annotation. Typically used for Link annotations.
	*
	* @return Annotation's border style.
	*/
	BorderStyle GetBorderStyle() const;

	/**
	* Sets the border style for the annotation. 
	*
	* @param bs New border style for this annotation.
	* @param oldStyleOnly PDF manual specifies two ways to add border information to an annotation object,
	* either through an array named 'Border' (PDF 1.0), or a dictionary called 'BS' (PDF 1.2) the latter
	* taking precedence over the former. However, if you want to create a border with rounded corners, you can only
	* do that using PDF 1.0 Border specification, in which case if you call SetBorderStyle() set the parameter
	* oldStyleOnly to true. This parameter has a default value of false in the API and does not need to be used otherwise.
	*/
	void SetBorderStyle( const BorderStyle& bs, bool oldStyleOnly = false );

	/**
	* An annotation can define as many as three separate appearances:
	* 
	*  - The normal appearance is used when the annotation is not interacting 
	* with the user. This appearance is also used for printing the annotation.
	* 
	*  - The rollover appearance is used when the user moves the cursor into the 
	*    annotation's active area without pressing the mouse button.
	* 
	*  - The down appearance is used when the mouse button is pressed or held down
	*    within the annotation's active area.
	*/
	enum AnnotationState
	{
		e_normal,
		e_rollover,
		e_down
	};

	/**
	* Gets the annotation's appearance for the given combination of annotation 
	* and appearance states.
	* 
	* @param annot_state the annotation's appearance state, which selects the applicable
	* appearance stream from the appearance sub-dictionary. An annotation can define as many
	* as three separate appearances: The normal, rollover, and down appearance.

	* @param app_state is an optional parameter specifying the appearance state
	* to look for (e.g. "Off", "On", etc). If appearance_state is NULL, the choice 
	* between different appearance states is determined by the AS (Appearance State) 
	* entry in the annotation dictionary.
	* 
	* @return The appearance stream for this annotation, or NULL if the annotation 
	* does not have an appearance for the given combination of annotation and 
	* appearance states.
	*/
	SDF::Obj GetAppearance(AnnotationState annot_state = e_normal, const char* app_state = 0);

	/**
	* Sets the annotation's appearance for the given combination of annotation 
	* and appearance states.
	* (Optional; PDF 1.2)
	* 
	* @param app_stream a content stream defining the new appearance.
	* 
	* @param annot_state the annotation's appearance state, which selects the applicable
	* appearance stream from the appearance sub-dictionary. An annotation can define as many
	* as three separate appearances: The normal, rollover, and down appearance.
	* 
	* @param app_state is an optional parameter specifying the appearance state
	* (e.g. "Off", "On", etc) under which the new appearance should be stored. If 
	* appearance_state is NULL, the annotation will have only one annotation state.
	*/
	void SetAppearance(SDF::Obj app_stream, AnnotationState annot_state = e_normal, const char* app_state = 0);

	/**
	* Removes the annotation's appearance for the given combination of annotation
	* and appearance states.
	*
	* @param annot_state the annotation's appearance state, which selects the applicable
	* appearance stream from the appearance sub-dictionary. An annotation can define as many
	* as three separate appearances: The normal, rollover, and down appearance.
	* 
	* @param app_state is an optional parameter specifying the appearance state
	* (e.g. "Off", "On", etc) under which the new appearance should be stored. If 
	* appearance_state is NULL, the annotation will have only one annotation state.
	*/
	void RemoveAppearance(AnnotationState annot_state = e_normal, const char* app_state = 0);

	/**
	* Flatten/Merge the existing annotation appearances with the page content and
	* delete this annotation from a given page.
	* 
	* Annotation 'flattening' refers to the operation that changes active annotations
	* (such as markup, widgets, 3D models, etc.) into a static area that is part of the 
	* PDF document, just like the other text and images in the document. 
	* 
	* @note an alternative approach to set the annotation as read only is using 
	* Annot.SetFlag(Annot::e_read_only, true) method. Unlike Annot.SetFlag(...), 
	* the result of Flatten() operation can not be programatically reversed.
	*/
	void Flatten(class Page page);

	/**
	* Gets the annotation's active appearance state. 
	* 
	* @return the name of the active state. 
	* The annotation's appearance state, which 
	* selects the applicable appearance stream from an appearance subdictionary.
	*/
	const char* GetActiveAppearanceState() const;

	/**
	* Sets the annotation's active appearance state. 
	* (Required if the appearance dictionary AP contains one or more subdictionaries; PDF 1.2)
	* 
	* @param astate Character string representing the name of the active appearance state. 
	* The string used to select the annotation's appearance state, which 
	* selects the applicable appearance stream from an appearance subdictionary.
	*/
	void SetActiveAppearanceState(const char* astate);


	/**
	* Gets an annotation's color in RGB color space. 
	* 
	* @return A ColorPt object containing an array of three numbers in the range 0.0 to 1.0, 
	* representing an RGB colour used for the following purposes:
	*   - The background of the annotation's icon when closed
	*   - The title bar of the annotation's pop-up window
	*   - The border of a link annotation
	*
	*  If the annotation does not specify an explicit color, a default color is returned. 
	*  Text annotations return 'default yellow;' all others return black. 
	*/
	ColorPt GetColorAsRGB() const;

	/**
	* Returns the annotation's color in CMYK color space. 
	* 
	* @return A ColorPt object containing an array of four numbers in the range 0.0 to 1.0, 
	* representing a CMYK color used for the following purposes:
	*   - The background of the annotation's icon when closed
	*   - The title bar of the annotation's pop-up window
	*   - The border of a link annotation
	*
	* If the annotation does not specify an explicit color, a default color is returned. 
	* Text annotations return 'default yellow;' all others return black. 
	*/
	ColorPt GetColorAsCMYK() const;

	/**
	* Returns the annotation's color in Gray color space. 
	* 
	* @return A ColorPt object containing a number in the range 0.0 to 1.0, 
	* representing a Gray Scale color used for the following purposes:
	* The background of the annotation's icon when closed
	* The title bar of the annotation's pop-up window
	* The border of a link annotation
	* If the annotation does not specify an explicit color, black color is returned. 
	*/
	ColorPt GetColorAsGray() const;

	/**
	* Returns the color space the annotation's color is represented in. 
	* 
	* @return An integer that is either 1(for DeviceGray), 3(DeviceRGB), or 4(DeviceCMYK). 
	* If the annotation has no color, i.e. is transparent, 0 will be returned. 
	*/
	int GetColorCompNum() const;


	/**
	* Sets an annotation's color.
	* (Optional; PDF 1.1)
	* 
	* @param col A ColorPt object in RGB or Gray or CMYK color space representing the annotation's color. 
	* The ColorPt contains an array of numbers in the range 0.0 to 1.0, representing a color used for the following purposes:
	*    The background of the annotation's icon when closed
	*     The title bar of the annotation's pop-up window
	*     The border of a link annotation
	*
	* The number of array elements determines the color space in which the color shall be defined:
	* 0 No color; transparent
	* 1 DeviceGray
	* 3 DeviceRGB
	* 4 DeviceCMYK
	*  
	* @param numcomp - The number of color components used to represent the color (i.e. 1, 3, 4).
	*/
	void SetColor(const ColorPt& col, int numcomp=3);


	/**	
	* Returns the struct parent of an annotation.
	* (Required if the annotation is a structural content item; PDF 1.3)
	*  
	* @return An integer which is the integer key of the annotation's entry 
	* in the structural parent tree.
	* @note The StructParent is the integer key of the annotation's entry 
	* in the structural parent tree.
	* 
	*/
	int GetStructParent() const;

	/**	
	* Sets the struct parent of an annotation.
	* (Required if the annotation is a structural content item; PDF 1.3)
	*  
	* @param parkeyval An integer which is the integer key of the 
	* annotation's entry in the structural parent tree.
	* @note The StructParent is the integer key of the annotation's entry 
	* in the structural parent tree.
	* 
	*/
	void SetStructParent(const int parkeyval);//The value can be set, should be limited. 


	/**
	* Returns optional content associated with this annotation.
	*  
	* @return A SDF object corresponding to the group of optional properties.
	* @note The return value is an Optional Content Group (OCG) or Optional Content Membership 
	* Dictionary (PDF::OCG::OCMD) specifying the optional content properties for the annotation. 
	* Before the annotation is drawn, its visibility shall be determined based on this entry 
	* as well as the annotation flags specified in the Flag entry. If it is determined to be 
	* invisible, the annotation shall be skipped, as if it were not in the document.
	*/
	SDF::Obj GetOptionalContent() const;

	/**
	* Associates optional content with this annotation. (Optional, PDF1.5). 
	*  
	* @param content A pointer to an SDF object corresponding to the optional content,
	* a PDF::OCG::Group or membership dictionary specifying the PDF::OCG::Group properties for 
	* the annotation. Before the annotation is drawn, its visibility 
	* shall be determined based on this entry as well as the annotation 
	* flags specified in the Flag entry . If it is determined to be invisible, 
	* the annotation shall be skipped, as if it were not in the document.
	*/
	void SetOptionalContent(SDF::Obj content);

	/**
	* Sets the content of this annotation. (Optional). 
	*  
	* @param contents A reference to unicode string object with the text that will be associated with
	* this annotation. This is the text that annotation displays on user interaction, if the annotation
	* type supports it.
	*/
	void SetContents(const UString& contents);

	/**
	* Extract the content of this annotation. (Optional). 
	*  
	* @return  A unicode string object with the text that is associated with
	* this annotation. This is the text that annotation displays on user interaction, 
	* if the annotation type supports it.
	*/
	UString GetContents() const;

	/**
	* Returns the rotation value of the annotation. The Rotation specifies the number of degrees by which the
	* annotation shall be rotated counterclockwise relative to the page.
	* The value shall be a multiple of 90.
	*
	* @return An integer representing the rotation value of the annotation.
	* @note This property is part of the appearance characteristics dictionary, this dictionary
	* that shall be used in constructing a dynamic appearance stream specifying the annotation's visual
	* presentation on the page.
	*/
	int GetRotation() const;

	/**
	* Sets the rotation value of the annotation. The Rotation specifies the number of degrees by which the
	* annotation shall be rotated counterclockwise relative to the page.
	* The value shall be a multiple of 90.
	* (Optional)
	*
	* @param angle An integer representing the rotation value of the annotation.
	* @note This property is part of the appearance characteristics dictionary, this dictionary
	* that shall be used in constructing a dynamic appearance stream specifying the annotation's visual
	* presentation on the page.
	*/
	void SetRotation(int angle);

	/**
	* Regenerates the appearance stream for the annotation. 	
	* This method can be used to auto-generate the annotation appearance after creating 
	* or modifying the annotation without providing an explicit appearance or 
	* setting the "NeedAppearances" flag in the AcroForm dictionary.
	*
	* @note If this annotation contains text, and has been added to a rotated page, the text in 
	* the annotation may be rotated. If RefreshAppearance is called *after* the annotation is added 
	* to a rotated page, then any text will be rotated in the opposite direction of the page 
	* rotation. If this method is called *before* the annotation is added to any rotated page, then 
	* no counter rotation will be applied. If you wish to call RefreshAppearance on an annotation 
	* already added to a rotated page, but you don't want the text to be rotated, you can do one 
	* of the following; temporarily un-rotate the page, or, temporarily remove the "Rotate" object 
	* from the annotation. To support users adding text annotations while using a PDF viewer,
	* you can also add any viewer rotation to the annotations Rotate object, to have text always
	* rotated correctly, from the users perspective.
	*/
	void RefreshAppearance();

	/**
	* A version of RefreshAppearance allowing custom options to make slight tweaks in behaviour.
	* @param options The RefreshOptions.
	*/
	void RefreshAppearance(const RefreshOptions& options);

	/**
	* Returns custom data associated with the given key.
	*
	* @param key The key for which to retrieve the associated data.
	* @return the custom data string. If no data is available an empty string is returned.
	*/
	UString GetCustomData(const UString& key) const;

	/**
	* Sets the custom data associated with the specified key.
	*
	* @param key The key under which to store this custom data
	* @param value The custom data string to store
	*/
	void SetCustomData(const UString& key, const UString& value);

	/**
	* Deletes custom data associated with the given key.
	*
	* @param key The key for which to delete the associated data.
	*/
	void DeleteCustomData(const UString& key);

	/**
	* Scales the geometry of the annotation so that its appearance would now fit a new
	* rectangle on the page, in user units. Users still have to call RefreshAppearance() later
	* if they want a corresponding appearance stream to be generated for the new rectangle.
	* The main reason for not combining the two operations together is to be able to resize
	* annotations that do not have an appearance stream.
	*  
	* @param newrect A reference to the new rectangle to which this annotation has to be resized.
	*/
	void Resize(const Rect& newrect);

	//for xamarin use only
	static Annot* CreateInternal(ptrdiff_t impl);
	ptrdiff_t GetHandleInternal();

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	Annot(TRN_Annot annot);
	TRN_Annot mp_annot;
	#endif
	// @endcond

}; //Class Annot

	/**
	* BorderStyle structure specifies the characteristics of the annotation's border.
	* The border is specified as a rounded rectangle.
	*/
class BorderStyle
{
public:
	/**
	* The border style
	*/
	enum Style {
		e_solid,   ///< A solid rectangle surrounding the annotation.
		e_dashed,  ///< A dashed rectangle surrounding the annotation.
		e_beveled, ///< A simulated embossed rectangle that appears to be raised above the surface of the page.
		e_inset,   ///< A simulated engraved rectangle that appears to be recessed below the surface of the page. 
		e_underline  ///< A single line along the bottom of the annotation rectangle.
	};

	/**
	* Creates a new border style with given parameters.
	* @param s The border style.
	* @param b_width The border width expressed in the default user space.
	* @param b_hr The horizontal corner radius expressed in the default user space.
	* @param b_vr The vertical corner radius expressed in the default user space.
	*
	* @note If the corner radii are 0, the border has square (not rounded) corners; if
	* the border width is 0, no border is drawn.
	*/
	BorderStyle(Style s, double b_width, double b_hr = 0, double b_vr = 0);
	/**
	* Creates a new border style with given parameters.
	* @param s The border style.
	* @param b_width The border width expressed in the default user space.
	* @param b_hr The horizontal corner radius expressed in the default user space.
	* @param b_vr The vertical corner radius expressed in the default user space.
	* @param b_dash An array of numbers defining a pattern of dashes and gaps to be used
	* in drawing the border. The dash array is specified in the same format as in the line
	* dash pattern parameter of the graphics state except that the phase is assumed to be 0.
	*
	* @note If the corner radii are 0, the border has square (not rounded) corners; if
	* the border width is 0, no border is drawn.
	*/
	BorderStyle(Style s, double b_width, double b_hr, double b_vr, const std::vector<double>& b_dash);
	BorderStyle(const BorderStyle&);
	~BorderStyle();

	/**
	* Frees the native memory of the object.
	*/
	void Destroy();

	BorderStyle& operator=(const BorderStyle&);
	friend inline bool operator==(const BorderStyle& a, const BorderStyle& b);
	friend inline bool operator!=(const BorderStyle& a, const BorderStyle& b) { return !(a == b); }

	/**
	* @return the border style.
	*/
	Style GetStyle() const;

	/**
	* Sets the border style.
	*/
	void SetStyle(Style style);

	/**
	* @return horizontal corner radius.
	*/
	double GetHR() const;

	/**
	* Sets horizontal corner radius.
	* @param horizontal_radius A number representing the value of the horizontal radius to set the annotation to.
	*/
	void SetHR(double horizontal_radius);

	/**
	* @return vertical corner radius.
	*/
	double GetVR() const;

	/**
	* Sets vertical corner radius.
	* @param vertical_radius A number representing the value of the vertical radius to set the annotation to.
	*/
	void SetVR(double vertical_radius);

	/**
	* @return the border width.
	*/
	double GetWidth() const;

	/**
	* Sets the border width
	* @param width A number representing the width value to set the annotation to.
	*/
	void SetWidth(double width);

	/**
	* @return the border dash pattern.
	* @see BorderStyle()
	*/
	std::vector<double> GetDash() const;

	/**
	* Sets the border dash pattern.
	* @see BorderStyle()
	*/
	void SetDash(const std::vector<double>& dash);

	BorderStyle(TRN_AnnotBorderStyle impl);
	BorderStyle() : mp_bs(0) {}
private:
	friend class PDF::Annot;
	TRN_AnnotBorderStyle mp_bs;
};
	} //namespace PDF
} //namespace pdftron

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnot
