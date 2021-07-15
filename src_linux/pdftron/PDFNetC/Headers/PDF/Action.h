//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAction
#define PDFTRON_H_CPPPDFAction

#include <PDF/FileSpec.h>
#include <SDF/Obj.h>
#include <C/PDF/TRN_Action.h>
#include <PDF/KeyStrokeActionResult.h>
#include <PDF/KeyStrokeEventData.h>

namespace pdftron { 
	namespace PDF {

/** 
 * Actions are typically what happens when a user clicks on a link or bookmark.
 * 
 * Instead of simply jumping to a destination in the document, an annotation or
 * outline item can specify an action for the viewer application to perform, such 
 * as launching an application, playing a sound, or changing an annotation's 
 * appearance state.
 * 
 * @note Although the Action class provides utility functions for most commonly used 
 * action types, it is possible to read, write, and edit any action type using SDF API 
 * and dictionary entries described in Section 8.5 in the PDF Reference Manual.
 */
class Action
{
public:

	/** 
	 * Creates a new 'GoTo'action. GoTo action takes the user to the 
	 * specified Destination view located in the same document.  
	 *
	 * @param dest A Destination for the new Action.
	 *
	 * @note This method can only be used for destinations in the same 
	 * document as the source document. For cross-document links use 
	 * Action::CreateGotoRemote().
	 */
	 static Action CreateGoto(class Destination dest);

	/** 
	 * Creates a new 'GoTo' action using a 'Named Destination'. GoTo action 
	 * takes the user to the specified 'Named Destination' view located in the 
	 * same document. 
	 * 
	 * @param key - a string buffer representing the destination name. The named
	 * destination will be stored in document's '/Dest' SDF::NameTree.
	 * @param key_sz The size in bytes of the key buffer. 
	 * @param dest The explicit destination used to create the named destination.
	 */
	 static Action CreateGoto(const UChar* key, int key_sz, class Destination dest);

	/** 
	 * Creates a new 'GoToR'action. A remote go-to action is similar to an 
	 * ordinary go-to action but jumps to a destination in another PDF file 
	 * instead of the current file.
	 *
	 * @param file The file referred to by the action.
	 * @param page_num A page number within the remote document. The first page is 
	 * numbered 0.
	 * @new_window A flag specifying whether to open the destination document
	 * in a new window. If new_window is false, the destination document replaces
	 * the current document in the same window, otherwise the viewer application 
	 * should behave in accordance with the current user preference.
	 */
	 static Action CreateGotoRemote(const FileSpec& file, int page_num);

	/**
	 * Creates a new 'GoToR'action. See the above method for details.
	 * 
	 * @param file The file referred to by the action.
	 * @param page_num A page number within the remote document. The first page is 
	 * numbered 0.
	 * @param new_window A flag specifying whether to open the destination document
	 * in a new window. If new_window is false, the destination document replaces
	 * the current document in the same window, otherwise the viewer application 
	 * should behave in accordance with the current user preference.
	 */
	 static Action CreateGotoRemote(const FileSpec& file, int page_num, bool new_window);

	 /**
	  * Create a new URI action. The URI action is typically resolved by opening a URL in 
	  * the default web browser.
	  * 
	  * @param doc The document in which to create the action.
	  * @param uri The uniform resource identifier to resolve, encoded in 7-bit ASCII.
	  * A uniform resource identifier (URI) is a string that identifies (resolves to) a resource
	  * on the Internet; typically a file that is the destination of a hypertext link, although 
	  * it can also resolve to a query or other entity. (URIs are described in Internet RFC 2396, 
	  * Uniform Resource Identifiers (URI).
	  */
     static Action CreateURI(SDF::SDFDoc& doc, const char* uri);

     /**
      * Create a new URI action. The URI action is typically resolved by opening a URL in
      * the default web browser.
      *
      * @param doc The document in which to create the action.
      * @param uri The uniform resource identifier to resolve, encoded in UTF-8.
      * A uniform resource identifier (URI) is a string that identifies (resolves to) a resource
      * on the Internet; typically a file that is the destination of a hypertext link, although
      * it can also resolve to a query or other entity. (URIs are described in Internet RFC 2396,
      * Uniform Resource Identifiers (URI).
      */
     static Action CreateURI(SDF::SDFDoc& doc, UString& uri);

	/** 
	 * Creates a new 'SubmitForm'action. A submit-form action transmits the names 
	 * and values of selected interactive form fields to a specified uniform 
	 * resource locator (URL), presumably the address of a Web server that will 
	 * process them and send back a response.
	 *
	 * @param url A URL file specification giving the uniform resource locator (URL) 
	 * of the script at the Web server that will process the submission.
	 */
	 static Action CreateSubmitForm(const FileSpec& url);

	 /**
	 * Creates a new 'Launch' action. A launch action opens up a file using the
	 * most appropriate program.
	 *
	 * @param doc the document in which to create the action
	 * @param path the full path of the file to be opened
	 */
	static Action CreateLaunch(SDF::SDFDoc& doc, const char* path);

	/**
	 * Creates a new 'Show/Hide Field' action. A show/hide field action shows
	 * or hide certain fields when it's invoked.
	 *
	 * @param sdfdoc the document in which to create the action
	 * @param list_length the number of fields to hide
	 * @param field the list of fields to hide
	 */
	static Action CreateHideField(SDF::SDFDoc& sdfdoc, int list_length, const char** field);

	/**
	 * Creates a new 'Import Data' action. An import data action imports
	 * form data from a FDF file into a PDF document.
	 *
	 * @param doc the document in which to create the action
	 * @param path the full path of the FDF file
	 */
	static Action CreateImportData(SDF::SDFDoc& doc, const char* path);

	/**
	 * Creates a new 'Reset Form' action. A reset form action reset chosen
	 * form fields to their default value.
	 *
	 * @param doc the document in which to create the action
	 */
	static Action CreateResetForm(SDF::SDFDoc& doc);

	/**
	 * Creates a new 'JavaScript' action. A javascript action executes a JavaScript
	 * script when it's invoked.
	 *
	 * @param doc the document in which to create the action
	 * @param script the JavaScript script to be executed
	 */
	static Action CreateJavaScript(SDF::SDFDoc& doc, const char* script);

	/**
	 * A constructor. Creates an Action and initializes it using given Cos/SDF object.
	 *
	 * @param in_obj Pointer to the Cos/SDF object. 
	 *
	 * @note The constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 */
	 Action (SDF::Obj in_obj = 0);

	/**
	 * Copy constructor. Creates a copy of the given Action object.
	 *
	 * @param in_action A reference to an existing Action object.
	 *
	 * @return The new Action. 
	 */
	 Action (const Action& in_action);

	/**
	 *	Sets this Action object equal to the specified Action object.
	 *
	 * @param in_action Reference to a Action object that is assigned to this Action object. 
	 *
	 * @return This method returns a reference to this Action object to allow cascaded assignments.
	 */
	 Action& operator=(const Action& in_action);

	/**
	 * Compares two Action objects for equality.
	 * 
	 * @param in_action A reference to an existing Action object.
	 *
	 * @return True if the both Actions share the same underlying SDF/Cos object; otherwise false. 
	 */
	 bool operator==(const Action& in_action);

	/**
	 * Indicates whether the Action is valid (non-null).
	 *
	 * @return True if this is a valid (non-null) Action; otherwise false. 
	 *
	 * @note If this method returns false the underlying SDF/Cos object is null and 
	 * the Action object should be treated as null as well.
	 */ 	
	 bool IsValid() const;


	/** 
	 * PDF supports the standard action types listed in the following table. 
	 * Plug-in extensions may add new action types.
	 */ 
	enum Type 
	{
		e_GoTo,         ///< Go to a destination in the current document.
		e_GoToR,        ///< ('Go-to remote') Go to a destination in another document.
		e_GoToE,        ///< ('Go-to embedded'; PDF 1.6) Go to a destination in an embedded file.
		e_Launch,       ///< Launch an application, usually to open a file. 
		e_Thread,       ///< Begin reading an article thread.
		e_URI,          ///< Resolve a uniform resource identifier.
		e_Sound,        ///< Play a sound.
		e_Movie,        ///< Play a movie.
		e_Hide,         ///< Set an annotation's Hidden flag.
		e_Named,        ///< Execute an action predefined by the viewer application.
		e_SubmitForm,   ///< Send data to a uniform resource locator.
		e_ResetForm,    ///< Set fields to their default values.
		e_ImportData,   ///< Import field values from a file.
		e_JavaScript,   ///< Execute a JavaScript script.
		e_SetOCGState,  ///< (PDF 1.5) Set the states of optional content groups.
		e_Rendition,    ///< (PDF 1.5) Controls the playing of multimedia content.
		e_Trans,        ///< Updates the display of a document, using a transition dictionary.
		e_GoTo3DView,   ///< (PDF 1.6) Set the current view of a 3D annotation
		e_RichMediaExecute, ///< Adobe supplement to ISO 32000; specifies a command to be sent to rich media annotation's handler
		e_Unknown       ///< Unknown Action type
	};

	/**
	 * @return The type of this Action.
	 */ 
	 Type GetType() const;

	/**
	 * Executes current action; this will only work for some action types that can be executed
	 * only using the information contained in the action object or the associated PDF doc.
	 * See also PDFViewCtrl::ExecuteAction()
	 */
	void Execute();

	/**
	* Executes KeyStrokeAction, this shall be performed when the user modifies a character in a text field
	* or combo box or modifies the selecton in a scrollable list box. This action checks the added text for
	* validity and reject or modify it.
	*
	* @param data Data that contains previous text, added text,and added position information.
	*/
	KeyStrokeActionResult ExecuteKeyStrokeAction(const KeyStrokeEventData& data);

	/**
	 * Test if the action needs writeLock
	 * @return ture if needs, otherwise false
	 */
	bool NeedsWriteLock();

	/**
 	 * @return The next action dictionary, an array of action dictionaries, 
	 * or NULL if there are no additional actions.
	 * 
	 * Sequences of actions can be chained together. For example, the effect 
	 * of clicking a link annotation with the mouse might be to play a sound, 
	 * jump to a new page, and start up a movie. Note that the Next entry is 
	 * not restricted to a single action but may contain an array of actions, 
	 * each of which in turn may have a Next entry of its own. The actions may 
	 * thus form a tree instead of a simple linked list. Actions within each 
	 * Next array are executed in order, each followed in turn by any actions 
	 * specified in its Next entry, and so on recursively. 
	 */
	SDF::Obj GetNext() const;

	/**
	 * @return The Action's Destination view.
	 *
	 * @note This only works for Actions whose subtype is "GoTo".
	 *
	 * @note All named destinations are automatically resolved to the 
	 * explicit destination so you can access destination members directly.
	 */
	 class Destination GetDest();


	/**
	* Flags used by submit form actions. Exclude flag is also used by reset form action.
	* No other action types use flags in the current version of PDF standard (ISO 2300).
	* 
	*/
	enum FormActionFlag
	{
		e_exclude = 0,
		e_include_no_value_fields  = 1,
		e_export_format = 2,			// submit in HTML format if set, FDF format if clear
		e_get_method = 3,
		e_submit_coordinates = 4,
		e_xfdf = 5,
		e_include_append_saves = 6,
		e_include_annotations = 7,
		e_submit_pdf = 8,
		e_canonical_format = 9,
		e_excl_non_user_annots = 10,
		e_excl_F_key = 11,
		// bit 12 is unused by PDF standard
		e_embed_form = 13
	};

	/**
	 * @param flag Action flag to get the value from.
	 * @return boolean value of the given action flag.
	 * @note Action flags are currently only used by submit and reset form actions.
	 */
	bool GetFormActionFlag( FormActionFlag flag ) const ;

	/**
	 * Set the value of a given field flag.
	 * @param flag Action flag to get the value from.
	 * @param value Boolean to set the value of the flag to.
	 * Action flags are currently only used by submit and reset form actions.
	 */
	void SetFormActionFlag( FormActionFlag flag, bool value );


	/**
	 * @return Pointer to the underlying SDF/Cos object.
	 */
	 SDF::Obj GetSDFObj () const;

	 
	 //for xamarin use only
	 static Action* CreateInternal(ptrdiff_t impl);
	 ptrdiff_t GetHandleInternal();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 Action(TRN_Action impl);
	 TRN_Action mp_action;
#endif
// @endcond
};

	}	// namespace PDF
}	// namespace pdftron


#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAction
