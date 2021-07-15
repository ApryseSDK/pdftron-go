//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPDFViewCtrl
#define PDFTRON_H_CPPPDFPDFViewCtrl

#include <PDF/PDFDoc.h>
#include <PDF/PDFRasterizer.h>
#include <PDF/Highlights.h>
#include <PDF/LinkInfo.h>
#include <PDF/OCG/Context.h>
#include <PDF/Selection.h>
#include <SDF/ObjSet.h>
#include <C/PDF/TRN_PDFViewCtrl.h>
#include <vector>
#include <PDF/ActionParameter.h>

namespace pdftron {
	namespace PDF {

/**
* PDFViewCtrl is a utility class that can be used for interactive rendering of PDF documents.
*
* In .NET environment PDFViewCtrl is derived from System.Windows.Forms.Control and it can be
* used like a regular form (see PDFViewForm.cs in PDFView sample for C# for a concrete
* example). 
*
* Unlike PDFView, PDFViewCtrl is a control that implements a number of tool modes,
* dialog boxes like find and password, has some built-in form filling capabilities 
* and a navigation panel for bookmarks, thumbview and layer views.
* 
* PDFViewCtrl defines several coordinate spaces and it is important to understand their 
* differences: 
* 
* - Page Space refers to the space in which a PDF page is defined. It is determined by
* a page itself and the origin is at the lower-left corner of the page. Note that Page
* Space is independent of how a page is viewed in PDFView and each page has its own Page
* space.
*
* - Canvas Space refers to the tightest axis-aligned bounding box of all the pages given
* the current page presentation mode in PDFView. For example, if the page presentation
* mode is e_single_continuous, all the pages are arranged vertically with one page in each
* row, and therefore the Canvas Space is rectangle with possibly large height value. For 
* this reason, Canvas Space is also, like Page Space, independent of the zoom factor. Also
* note that since PDFView adds gaps between adjacent pages, the Canvas Space is larger than
* the space occupied by all the pages. The origin of the Canvas Space is located at the 
* upper-left corner. 
*
* - Screen Space (or Client Space) is the space occupied by PDFView and its origin is at
* the upper-left corner. Note that the virtual size of this space can extend beyond the 
* visible region.
*
* - Scrollable Space is the virtual space within which PDFView can scroll. It is determined
* by the Canvas Space and the current zoom factor. Roughly speaking, the dimensions of the 
* Scrollable Space is the dimensions of the Canvas Space timed by the zoom. Therefore, a large
* zoom factor will result in a larger Scrollable region given the same Canvas region. For this
* reason, Scrollable Space might also be referred to as Zoomed Canvas Space. Note that since
* PDFView adds gaps between pages in Canvas Space and these gaps are not scaled when rendered, 
* the scrollable range is not exactly what the zoom factor times the Canvas range. For 
* functions such as SetHScrollPos(), SetVScrollPos(), GetCanvasHeight(), and 
* GetCanvasWidth(), it is the Scrollable Space that is involved.
*
*/
class PDFViewCtrl
{
public:

	/** 
	* PDFViewCtrl constructor and destructor. 
	* Create PDFViewCtrl without associating it to any
	* document.
	* @param parent_hwnd the platform specific window handle
	* @param hinstance on windows the current HINSTANCE
	* @param compatibility indicates if PDFViewCtrl is compatible with v.5.7.0 and older. 
	* The default value is false. PDFViewCtrl shipped with PDFNet v.5.8.0 has enhanced features
	* for better viewing experience, including pre-rendering invisible regions.
	*/
	PDFViewCtrl(void* parent_hwnd, void* hinstance, bool compatibility = false);
	~PDFViewCtrl();

	/** 
	* Associates this PDFViewCtrl with a given PDF document. 
	* 
	* @param doc - A document to be displayed in the view.
	* @param password - the password used to initialize the document 
	*
 	* @note Acquires a write lock on the document
	*/
	bool SetDoc(PDFDoc& doc, const char* password = 0);

	/** 
	* Closes the document currently opened in PDFViewCtrl.
	* @note Acquires a write lock on the document
	*/
	void CloseDoc();

	/** 
	* @return Currently associated document with this PDFViewCtrl.
	*/
	PDFDoc* GetDoc();

	/**
	 * Acquires a write lock on the currently open document,
	 * optionally canceling all threads accessing the document.
	 */
	 void DocLock(bool cancel_threads);

	/**
	 * Releases the write lock from the currently open document. 
	 */
	 void DocUnlock();

	/**
	 * Try acquiring a write lock on the currently open document, waiting no
	 * longer than specified number of milliseconds.
	 * @return true if the document is locked for multi-threaded access, false otherwise.
	 */
	 bool DocTryLock( int milliseconds = 0 );

	/**
	 * Locks the currently open document to prevent competing write threads 
	 * (using Lock()) from accessing the document at the same time. 
	 * Other reader threads however, will be allowed to access the document.
	 * Threads attempting to obtain write access to the document will wait in 
	 * suspended state until the thread that owns the lock calls doc.UnlockRead().
	 * Note: To avoid deadlocks obtaining a write lock while holding
	 * a read lock is not permitted and will throw an exception. If this situation is encountered
	 * please either unlock the read lock before the write lock is obtained
	 * or acquire a write lock (rather than read lock) in the first place.
	 */
	 void DocLockRead();

	/**
	 * Releases the read lock from the currently open document. 
	 */
	 void DocUnlockRead();

	/**
	 * Try acquiring a read lock on the current document, waiting no longer than specified 
	 * number of milliseconds.
	 * @return true if the document is locked for multi-threaded access, false otherwise.
	 */
	 bool DocTryLockRead( int milliseconds = 0 );

	/**
	* Enumeration used to indicate the sub-window that triggered an event.
	* Can be checked by clients when they are receiving event callbacks from PDFViewCtrl.
	*/
	enum WindowID {
		e_main_view,
		e_thumb_view,
		e_layers_view,
		e_bookmark_view,
		e_navigation_pane,
		e_navigation_toolbar,
		e_toolbar,
		e_status_bar,
		e_dialog_modal,
		e_dialog_modeless
	};

	enum ControlEventType {
		e_mouse_move,
		e_mouse_enter,
		e_mouse_leave,
		e_mouse_left_down,
		e_mouse_left_up,
		e_mouse_left_dclick,
		e_mouse_right_down,
		e_mouse_right_up,
		e_mouse_right_dclick,
		e_mouse_middle_down,
		e_mouse_middle_up,
		e_mouse_middle_dclick,
		e_mouse_wheel,
		e_context_menu,
		e_key_down,
		e_key_up,
		e_key_press,
		e_paint,
		e_window_open,
		e_window_close
	};


	/**
	* Struct containing the data necessary to process mouse event callback
	* on the client side.
	*/
	struct MouseEvent {
		int			m_x;
		int			m_y;
		int         m_wheelRotation;
		int         m_wheelDelta;
		int         m_linesPerAction;
		UInt8       m_leftDown;
		UInt8       m_middleDown;
		UInt8       m_rightDown;
		UInt8       m_controlDown;
		UInt8       m_shiftDown;
		UInt8       m_altDown;
		UInt8       m_metaDown;

		// identifies  the type of event
		enum ControlEventType m_event_type;
		// identifies which window emitted the event
		enum WindowID m_event_window;
		// if TRUE, this event was emitted after PDFViewCtrl has processed it
		UInt8        m_pdfviewctrl_processed; 
	};

	/**
	* Struct containing the data necessary to process key event callback
	* on the client side.
	*/
	struct KeyEvent {
		int          m_x;
		int          m_y;
		long int     m_keyCode;
		Unicode	     m_unicode;
		UInt8        m_controlDown;
		UInt8        m_shiftDown;
		UInt8        m_altDown;
		UInt8        m_metaDown;
		// identifies  the type of event
		enum ControlEventType m_event_type;
		// this helps you identify which window emitted the event
		enum WindowID m_event_window;
		// if TRUE, this event was emitted after PDFViewCtrl has processed it
		UInt8        m_pdfviewctrl_processed; 
	};

	/**
	* Struct containing the data necessary to process paint event callback
	* on the client side.
	*/
	struct PaintEvent {
		// platform-dependent device context pointer
		void*           m_hdc;
		enum TRN_PDFViewCtrlWindowID m_event_window;
		TRN_Bool        m_pdfviewctrl_processed; 
	};

	struct SizeEvent {
		int m_width;
		int m_height;
		int m_x_position;
		int m_y_position;
		// this helps you identify which window emitted the event
		enum WindowID m_event_window;
	};

	/**
	 * This event structure will be returned on windows-related events,
	 * such as windows being shown / closed, etc.
	 */
	struct WindowEvent {
		// identifies  the type of event
		enum ControlEventType m_event_type;
		// this helps you identify which window emitted the event
		enum WindowID m_event_window;
	};

	/**
	 * This event structure will be returned when text search is finished.
	 */
	struct TextFindDoneEvent {
		bool m_found;
		enum ControlEventType m_event_type;
		enum WindowID m_event_window;

		TextFindDoneEvent( PDFViewCtrl::WindowID id, ControlEventType tp, bool found )
			: m_event_type(tp),
			  m_event_window(id),
			  m_found(found)
		{}
	};

	/**
	 * This event structure will be returned when a user tries to edit an annotation.
	 */
	struct AnnotationEditPermissionEvent {
		TRN_Annot m_annot;
		// identifies  the type of event
		enum ControlEventType m_event_type;
		// this helps you identify which window emitted the event
		enum WindowID m_event_window;

		AnnotationEditPermissionEvent(PDFViewCtrl::WindowID id, ControlEventType tp, TRN_Annot annot)
			: m_annot(annot),
			  m_event_type(tp),
			  m_event_window(id)
		{}
	};

	// handlers for generic event signals emitted by PDFViewCtrl;
	// they return boolean, return value of true means no PDFViewCtrl processing should take place
	typedef UInt8 (*MouseEventHandler) ( struct MouseEvent* evt, void* custom_data );
	typedef UInt8 (*KeyEventHandler)   ( struct KeyEvent* evt,   void* custom_data );
	typedef UInt8 (*PaintEventHandler) ( struct PaintEvent* evt, void* custom_data );
	typedef UInt8 (*SizeEventHandler)  ( struct SizeEvent* evt,  void* custom_data );
	typedef UInt8 (*WindowEventHandler)( struct WindowEvent* evt, void* custom_data);
	typedef UInt8 (*TextFindDoneHandler)(struct TextFindDoneEvent* evt, void* custom_data);
	typedef UInt8 (*AnnotationEditPermissionHandler)(struct AnnotationEditPermissionEvent* evt, void* custom_data);

	/**
	* Class containing the event handlers to be called when certain GUI actions
	* are happening
	*/
	struct EventHandlers
	{
		MouseEventHandler mouse_move;
		MouseEventHandler mouse_enter;
		MouseEventHandler mouse_leave;
		MouseEventHandler mouse_left_down;
		MouseEventHandler mouse_left_up;
		MouseEventHandler mouse_left_dclick;
		MouseEventHandler mouse_right_down;
		MouseEventHandler mouse_right_up;
		MouseEventHandler mouse_right_dclick;
		MouseEventHandler mouse_middle_down;
		MouseEventHandler mouse_middle_up;
		MouseEventHandler mouse_middle_dclick;
		MouseEventHandler on_mousewheel;
		MouseEventHandler on_context_menu;
		KeyEventHandler	  key_down;
		KeyEventHandler   key_up;
		KeyEventHandler   character_entered;
		PaintEventHandler on_paint;
		SizeEventHandler  on_size;
		WindowEventHandler on_window_event;
		TextFindDoneHandler on_find_text_done;
		AnnotationEditPermissionHandler on_edit_annotation;

		void* custom_data;

		EventHandlers();
	};

	/**
	* Sets the handlers to be called when the certain events happen
	* @param a class containing the event handlers
	*/
	void SetCustomEventHandlers( EventHandlers* handlers );

	/**
	* a callback function that gets executed when something triggers a PDF
	* action in the document. The parameter action can be converted to 
	* Action object via Action( (SDF::Obj*)action ).
	* If this function returns true, PDFViewCtrl will not try to execute the
	* action internally.
	*/
	typedef UInt8 (*ActionHandler) ( TRN_Action action, void* custom_data );

	/**
	* Sets the handler function to be called on PDF action execution
	* @param a function pointer to the callback 
	*/
	void SetActionHandler( ActionHandler action_callback, void* custom_data  );

	/**
	* Requests action object to be executed by PDFViewCtrl. Action must belong to the document 
	* currently displayed in PDFViewCtrl.
	* @param action object that is to be executed.
	*/
	void ExecuteAction(ActionParameter action_param );

	/** 
	* A prototype for a callback function (or a delegate in .NET terminology) 
	* that will be called whenever current page number changes.
	* 
	* @param current_page the current page.
	* @param num_pages total number of pages in the document.
	* @param data Custom data to be passed as a second parameter to 'curr_pagenum_proc'.
	*/
	typedef void (*CurrentPageHandler) (int current_page, int num_pages, void* data);

	/** 
	* Sets the callback function (i.e. a delegate) that is called whenever current 
	* page number changes. This can be used to update the current page number within 
	* GUI applications etc.
	* 
	* @param curr_pagenum_proc Callback function (or a delegate in .NET).
	* @param data Custom data to be passed as a second parameter to 'curr_pagenum_proc'.
	*/
	void SetCurrentPageHandler(CurrentPageHandler curr_pagenum_proc, void* data);

	/** 
	* A prototype for a callback function (or a delegate in .NET terminology) 
	* that will be called whenever current zoom (magnification) number changes.
	* 
	* @param current_zoom the current zoom.
	* @param data Custom data to be passed as a second parameter to 'curr_zoom_proc'.
	*/
	typedef void (*CurrentZoomHandler) (double current_zoom, void* data);

	/** 
	* Sets the callback function (i.e. a delegate) that is called whenever current 
	* zoom (magnification) changes. This can be used to update the current zoom number 
	* within GUI applications etc.
	* 
	* @param curr_zoom_proc Callback function (or a delegate in .NET).
	* @param data Custom data to be passed as a second parameter to 'curr_zoom_proc'.
	*/
	void SetCurrentZoomHandler(CurrentZoomHandler curr_zoom_proc, void* data);

	typedef void (*ErrorReportHandler) (const char* message, void* data);

	/** 
	* Sets the error handling function to be called in case an error is encountered 
	* during page rendering.
	* 
	* @param error_proc Error handling callback function (or delegate in .NET)
	* @param data Custom data to be passed as a second parameter to 'error_proc'.
	*/
	void SetErrorReportHandler(ErrorReportHandler error_proc, void* data);

	/**
	* Sets new position and size for the control
	* 
	* @param x - The x position of the control within its parent
	* @param y - The y position of the control within its parent
	* @param width - The width of the target image in pixels.
	* @param height - The height of the target image in pixels (the number of rows).
	* 
	* @note this method is typically used only in PDFNet for C++
	*/
	void OnSize(int x, int y, int width, int height);

	/**
	* Creates and displays a find dialog so the user
	* can search through the text in the control
	*/
	void Find();

	/**
	* Copies the current selection in this control.
	*/
	void Copy();

	/**
	* Selects all text on the page.
	*/
	void SelectAll();

	/**
	* Sets whether the control will render progressively or will just 
	* draw once the entire view has been rendered
	* @param progressive if true the view will be rendered progressively
	*
	* @note Progressive rendering is useful when a PDF page contain lots of elements 
	* (e.g. many vector paths, text, or many little images). When progressive rendering 
	* is enabled PDFNet will use painter algorithm to draw the page. This way user may 
	* be able to see partially rendered page. If a page contains only a single large 
	* image, there would be no visible benefit from progressive rendering. 
	*/
	void SetProgressiveRendering(bool progressive=true);

	/**
	* Enables or disables the navigation panel
	* @param show if true the navigation panel will be enabled
	*/
	void ShowNavPanel(bool show);
	
	/**
	*  return true if the navigation panel is enabled
	*/
	bool IsNavPanelVisible() const;

	/**
	* Enables or disables the scrollbar in the viewing area.
	* @param show if true the scrollbar will be enabled.
	*/
	void EnableScrollbar( bool show );

	/**
	* Enables or disables the toolbar on top of the viewing area.
	* @param show if true the toolbar will be enabled.
	*/
	void ShowToolbar( bool show);

	/**
	* Enables or disables the status bar at the bottom of the viewing area.
	* @param show if true the status bar will be enabled.
	*/
	void ShowStatusBar( bool show);

	/**
	* Enables or disables the toolbar controlling the navigation panel.
	* @param show if true the navigation toolbar will be enabled.
	*/
	void ShowNavToolbar( bool show);

	/**
	* Enables or disables the menu bar that gives access to the PDFViewCtrl user functions.
	* @param show if true the menu bar will be enabled.
	*/
	void ShowMenuBar( bool show );

	/**
	* Enables or disables interactive form editing
	* @param on if true interactive forms will be enabled
	*/
	void EnableInteractiveForms(bool on);

	/**
	* Enables or disables popup dialogs such as password entry and find
	* dialogs as well as popup menus.
	* @param show if true dialogs will be enabled
	*/
	void ShowDialogs(bool show);

	static const UInt32 e_none=0x00;
	static const UInt32 e_bookmarks=0x01;
	static const UInt32	e_layers=0x02;
	static const UInt32	e_thumbview=0x04;
	static const UInt32	e_all=0x07;
	typedef UInt32 PanelType;

	/**
	* Sets which panels will be enabled in the navigation panel
	* @param panels - A bit field composed of an OR of PDFViewCtrl::PanelType values.  
	*/
	void SetEnabledPanels(UInt32 panels);

	/**
	* Returns which panels are enabled in the navigation panel
	* @return A bit field composed of an OR of PDFViewCtrl::PanelType values.
	* which describes which panels are currently enabled in the navigation panel.
	*/
	UInt32 GetEnabledPanels() const ;

	/**
	* Sets the currently selected panel in the navigation panel
	* @param panel the panel to select
	*/
	void SetSelectedPanel(PanelType panel);

	/**
	* Returns the currently selected panel in the navigation panel
	* @return the currently selected panel type
	*/
	PanelType GetSelectedPanel() const ;

	/**
	* Sets the horizontal size of the navigation panel
	* @param pos the new horizontal size
	*/
	void SetSplitPosition(int pos);

	/**
	* Returns the current horizontal size of the navigation panel
	* @return the horizontal size of the navigation panel
	*/
	int GetSplitPosition() const ;

	/**
	* Displays a print dialog to receive information from the user
	* and prints the document. 
	* @note Can acquire a write lock on the document.
	*/
	void Print();

	/**
	* Programatically prints the document without any dialogs.  
	* @param first_page the first page to print
	* @param last_page the last page to print
	* @param rotation the print rotation which can allow the user to
	* specify landscape mode
	* @param copies the number of copies to print
	* @param printer_name the name of the printer to use
	*
	* @note Acquires a write lock on the document
	*/
	void Print(int first_page, int last_page, Page::Rotate rotation, 
		int copies, const char* printer_name);

	
	/**
	* Programatically prints the document without any dialogs
	* @param first_page the first page to print
	* @param last_page the last page to print
	* @param rotation the print rotation which can allow the user to
	* specify landscape mode
	* @param copies the number of copies to print
	* @param printer_name the name of the printer to use
	*
	* @note Acquires a write lock on the document
	*/
	void Print(int first_page, int last_page, Page::Rotate rotation, 
		int copies, const UString& printer_name);

	
	/**
	* Causes this window to be repainted.
	*/
	void Refresh();


	/**
	* Requests that PDFViewCtrl start rendering, if necessary.
	* 
	* @note Refresh() simply causes the window to be repainted at the system level. It
	* does not make PDFViewCtrl to render anything new. RequestRendering() tells PDFViewCtrl
	* to check if there are regions (both visible and invisible) that have not been rendered; if so
	* a background rendering thread will be started. This function should be called if 
	* CancelRendering() was called to stop the ongoing rendering thread. Update() tells
	* PDFViewCtrl to discard the rendered content and start a rendering
	* thread. This function should be used if the content of the PDF is modified.
	*/
	void RequestRendering();


	/**
	* Directs all mouse input to this window. Call ReleaseMouse to release the capture.
	*/
	void CaptureMouse();

	/**
	*  Releases mouse input captured with CaptureMouse()
	*/
	void ReleaseMouse();

	/**
	*  Returns true if this window has the current mouse capture
	*/
	bool HasCapture() const;

	/**
	 * Enables or disables whether links are activated when the user clicks on them 
	 * @param enable if true enable link activation, otherwise disable it
	 */
	void EnableLinkActivation(bool enable);

	/**
	* Load the current configuration of PDFViewCtrl from a file.
	* @param name of the file from which the settings are loaded. If it is an empty string, 
	* default location is chosen by PDFViewCtrl.
	*/
	void LoadCurrentConfiguration( const UString & path );

	/**
	* Save the current configuration of PDFViewCtrl to a file.
	* @param name of the file to which the settings are saved. If it is an empty string, 
	* default location is chosen by PDFViewCtrl.
	*/
	void SaveCurrentConfiguration( const UString & path, Common::ProgressMonitor* progress = 0 );

	/**
	* Retrieve the annotation which stores the default properties for
	* a given type. User can change these default settings by operating
	* on this annotation.
	* @param the key, or identifier, of the annotation type for which the default is required.
	* Usually this is the same as the value of 'Subtype' entry in the annotation's dictionary, 
	* allowing to easily get default annotation for given type. 
	* PDFNet is also using the following non-standard names annotation types which have more than
	* associated creation tool:
	* 'Arrow' to store the properties of the Line annotation drawn as an arrow;
	* 'FreeTextCallout' to store the properties of the FreeText annotation drawn as a callout box.
	*/
	Annot GetDefaultAnnotation( const char* type );
		
	/**
	 * Changes the background color on a given child window. That window must already exist.
	 */
	void SetWindowBackgroundColor( WindowID winid, const ColorPt& color );
#ifdef WIN32
	void SetWindowCursor( PDFViewCtrl::WindowID winid, HCURSOR cursor );
#endif

	/**
	* Set the key focus to PDFViewCtrl. This is useful when a user needs to set the focus programatically.
	*/
	void SetFocus();

	/* dialogs creation API */

	/**
	 * create Document Properties dialog
	 * @note Can acquire a write lock on the document.
	 */
	void DocProperties();

	/**
	 * create DeletePagesDialog to prompt user for pages in the current PDF document to delete.
	 * @note Can acquire a write lock on the document.
	 */
	void DeletePages();

	/**
	 * create InsertPagesDialog to prompt user for page number from another PDF document to insert.
	 * @note Can acquire a write lock on the document.
	 */
	void InsertPages(const UString& src_name);

	/**
	 * create InsertBlankPagesDialog to prompt user for size and number of blank pages to insert.
	 * @note Can acquire a write lock on the document.
	 */
	void InsertBlankPages();

	/**
	 * create ReplacePagesDialog to prompt user for page number from another PDF document to replace
	 * pages from current PDF document
	 * @note Can acquire a write lock on the document.
	 */
	void ReplacePages(const UString& src_name = UString());

	/**
	 * create RotatePagesDialog to prompt user to rotate n pages at a specified rotation
	 * @note Can acquire a write lock on the document.
	 */
	void RotatePages();

	/**
	 * create ExtractPagesDialog to prompt user to extract n pages from the PDF and save it to a new file
	 */
	void ExtractPages();

	/**
	 * create CropPagesDialog where the user can specify a cropping for any of the boxes in a PDF Page.
	 * The user can apply the cropping to any set of pages.  
	 * @note Can acquire a write lock on the document.
	 */
	void CropPages();

	/**
	 * create AddWatermarkDialog where user can define a watermark and stamp it to a document.  
	 * @note Can acquire a write lock on the document.
	 */
	void AddWatermark();

	/* end of dialogs creation API */

	/**
	 * methods below are shared with the interface of PDFView class
     	 */

	/** 
	* PageViewMode lists common modes of viewing PDF pages. PDFViewCtrl currently supports 
	* the following viewing modes: 
	*   - e_fit_page - page zoom is automatically adjusted so that entire page fits into available space.
	*   - e_fit_width - page zoom is automatically adjusted so that page width fits into available space.
	*   - e_fit_height - page zoom is automatically adjusted so that page height fits into available space.
	*   - e_zoom - page is zoomed. The zoom factor is specified using SetZoom() function.
	*/
	enum PageViewMode
	{
		e_fit_page = 0,
		e_fit_width,
		e_fit_height,
		e_zoom
	};

	/**
	* Sets the page viewing mode
	*
	* @param mode - the new page viewing mode.
	* @default The default PageView mode is e_fit_width.
	*/
	void SetPageViewMode(PageViewMode mode);

	/**
	* @return the current page viewing mode
	*/
	PageViewMode GetPageViewMode() const ;

	/** 
	 * PagePresentationMode lists common modes of presenting PDF pages. 
	 */
	enum PagePresentationMode
	{
		e_single_page = 1,         //<<< Display one page at a time.
		e_single_continuous,       //<<< Display the pages in one column.
		e_facing,                  //<<< Display the pages two at a time, with odd-numbered pages on the left.
		e_facing_continuous,       //<<< Display the pages in two columns, with odd-numbered pages on the left.
		e_facing_cover,            //<<< Display the pages two at a time, with odd-numbered pages on the right.
		e_facing_continuous_cover  //<<< Display the pages in two columns, with odd-numbered pages on the right.
	};

	/**
	* Sets the current page presentation mode.
	*
	* @param mode - the new page presentation mode.
	* @default The default PagePresentationMode is e_single_continuous.
	*/
	void SetPagePresentationMode(PagePresentationMode mode);

	/**
	* @return the current page presentation mode.
	*/
	PagePresentationMode GetPagePresentationMode() const ;
    
	/**
	 * Set the color post processing transformation.
	 * This transform is applied to the rasterized bitmap as the final step
	 * in the rasterization process, and is applied directly to the resulting
	 * bitmap (disregarding any color space information). Color post
	 * processing only supported for RGBA output.
	 *
	 * @param mode is the specific transform to be applied
	 */
	void SetColorPostProcessMode(PDFRasterizer::ColorPostProcessMode mode);

	 /**
	 * @return the current color post processing mode.
	 */
	PDFRasterizer::ColorPostProcessMode GetColorPostProcessMode() const;

	/**
	* @return the current page displayed in the view.
	*/
	int GetCurrentPage() const ;

	/**
	* @return the total number of pages in the document.
	*/
	int GetPageCount() const ;

	/**
	* Get a vector with the pages currently visible on the screen.
	* 
	* @return a vector of the pages currently visible on the screen.
	*/
	std::vector<int> GetVisiblePages() const ;

	/**
	* Sets the current page to the first page in the document.
	* 
	* @return true if successful, false otherwise.
	*/
	bool GotoFirstPage();

	/**
	* Sets the current page to the last page in the document.
	* 
	* @return true if successful, false otherwise.
	*/
	bool GotoLastPage();

	/**
	* Sets the current page to the next page in the document.
	* 
	* @return true if successful, false otherwise.
	*/
	bool GotoNextPage();

	/**
	* Sets the current page to the previous page in the document.
	* 
	* @return true if successful, false otherwise.
	*/
	bool GotoPreviousPage();

	/**
	* Sets the current page to the given page.
	* 
	* @return true if successful, false otherwise.
	*/
	bool SetCurrentPage(int page_num);

	/**
	 * Changes the viewing area to fit a rectangle rect on page page_num.
	 * Rectangle must be specified in page coordinates.
	 * This will adjust current page and zoom appropriately.
	 * 
	 * @return true if successful, false otherwise.
	 */
	bool ShowRect( int page_num, const Rect& rect );

	/**
	* Returns the current zoom factor.
	* 
	* @return current zoom (or scaling) component used to display the page content. 
	*/
	double GetZoom() const ;

	/**
	* Sets the zoom factor to a new value. The function zooms to a point at the 
	* center of the rendering buffer.
	* 
	* @param zoom - new scaling component used to display the page content. 
	* @return true if successful, false otherwise.
	*/
	bool SetZoom(double zoom);

	/**
	 * Sets the zoom factor to a new value using the given pixel coordinate
	 * (x,y) as a zoom center, which will stay fixed on the screen.
	 * 
	 * The zoom point (x,y) is represented in the screen coordinate system, which 
	 * starts in the upper-left corner of the client window.
	 *
	 * Should you want to move (x, y) to the center of the client window, you can 
	 * use the OnScroll() subsequently:
	 *
	 *
	 *		int x, y;
	 *		double zoom;
	 *		...
	 *		view.SetZoom(x, y, zoom);
	 *		int width = view.GetBufferWidth();
	 *		int height = view.GetBufferHeight();
	 *		int dx = (int)(x - (double)width/2 + 0.5);
	 *		int dy = (int)(y - (double)height/2 + 0.5);
	 *		view.OnScroll(dx, dy);
	 *
	 * 
	 * @param x - the horizontal coordinate to zoom in. 
	 * @param y - the vertical coordinate to zoom in.
	 * @param zoom - new scaling component used to display the page content. 
	 * @return true if successful, false otherwise.
	 */
	bool SetZoom(int x, int y, double zoom);

	/**
	 * Sets the zoom factor to a new value using the given pixel coordinate
	 * (x,y) to find an intersecting paragraph.
	 * The width of the paragraph helps to determine the zoom value, center
	 * of the paragraph is used as a zoom center.
	 * Paragraph has to contain more than one line and be wider than 1/5th of a page width.
	 * When called on a paragraph wider than current zoom level the new zoom level 
	 * is set to fit the entire page(zoom out). 
	 *
	 * The zoom point (x,y) is represented in the screen space, which 
	 * starts in the upper-left corner of the client window.
	 * 
	 * @param x - the horizontal coordinate to look for a text block. 
	 * @param y - the vertical coordinate to look for a text block.
	 * @return true if successful, false if no paragraph intersects the given point.
	 */
	bool SmartZoom(int x, int y);

	/**
	* Rotates all pages in the document 90 degrees clockwise.
	*/
	void RotateClockwise();

	/**
	* Rotates all pages in the document 90 degrees counter-clockwise.
	*/
	void RotateCounterClockwise();

	/**
	* @return  The current rotation of this PDFViewCtrl.
	*/
	Page::Rotate GetRotation() const ;

	/**
	* @return  the number of the page in the screen space. The positive number indicates a valid page, whereas 
	* number less than 1 means that no page was found. 
	*/
	int GetPageNumberFromScreenPt(double x, double y) const ;

	/**
	* Converts a point expressed in screen space to a point in canvas space.
	*/
	void ConvScreenPtToCanvasPt(double& x, double& y) const ;

	/**
	* Converts a point expressed in canvas space to a point in screen space.
	*/
	void ConvCanvasPtToScreenPt(double& x, double& y) const;

	/**
	* Converts a point expressed in canvas space to a point in a page space.
	* 
	* @param page_num the page number for the page used as the origin of the destination 
	* coordinate system. Negative values are used to represent the current page.
	* Pages are indexed starting from one.
	*/
	void ConvCanvasPtToPagePt(double& x, double& y, int page_num = -1) const;

	/**
	* Converts a point from a page space to a point in canvas space.
	* 
	* @param page_num the page number for the page used as the origin of the destination 
	* coordinate system. Negative values are used to represent the current page.
	* Pages are indexed starting from one.
	*/
	void ConvPagePtToCanvasPt(double& x, double& y, int page_num = -1) const;

	/**
	* Converts a point expressed in screen space to a point on a page space.
	* 
	* @param page_num the page number for the page used as the origin of the destination 
	* coordinate system. Negative values are used to represent the current page.
	* Pages are indexed starting from one.
	*/
	void ConvScreenPtToPagePt(double& x, double& y, int page_num = -1) const;

	/**
	* Converts a point from a page space to a point in screen space.
	* 
	* @param page_num the page number for the page used as the origin of the destination 
	* coordinate system. Negative values are used to represent the current page.
	* Pages are indexed starting from one.
	*/
	void ConvPagePtToScreenPt(double& x, double& y, int page_num = -1) const;

	/**
	* Snaps an xy coordinate pair (in screen space) to the nearest piece of 
	* document geometry. 
	*/
	void SnapToNearestInDoc(double& screen_x, double& screen_y);

	/** 
	* Set the point snapping mode for the SnapToNearestInDoc method.
	* By default SnapToNearestInDoc will snap to line endpoints, midpoints, and intersections.
	*
	* @param mode_flag a bitwise combination of the members of `GeometryCollection::SnappingMode`
	*/
	void SetSnappingMode(UInt32 mode_flags);

	/**
	* @return the device transformation matrix. The device transformation 
	* matrix maps the page coordinate system to screen (or device) coordinate 
	* system.
	* 
	* @param page_num same as for PDFViewCtrl.Conv???() methods.
	*
	* @note to obtain a transformation matrix that maps screen 
	* coordinates to page coordinates, you can invert the device matrix. 
	* For example: 
	* @code
	*   Common::Matrix2D scr2page(pdfviewctrl.GetDeviceTransform());
	*   scr2page.Inverse();
	* @endcode 
	*/
	Common::Matrix2D GetDeviceTransform(int page_num = -1) const;

	/**
	* Returns the current width of the scrollable space.
	*/
	double GetCanvasWidth() const;

	/**
	* Returns the current height of the scrollable space.
	*/
	double GetCanvasHeight() const;

	/**
	* @return the current horizontal scroll position of the scrollable space.
	*/
	double GetHScrollPos() const;

	/**
	* @return the current vertical scroll position of the scrollable space.
	*/
	double GetVScrollPos() const;


	/**
	* Scrolls the contents of the rendering buffer 'pix_dx' horizontally and 'pix_dy' vertically.
	* 
	* @param pix_dx horizontal scroll offset, in pixels
	* @param pix_dy vertical scroll offset, in pixels
	*/
	void OnScroll(int pix_dx, int pix_dy);

	/**
	* Sets the horizontal scroll position of the scrollable space.
	* 
	* @param the new horizontal scroll position of the scrollable space. The
	* position should be a number in the range between 0 and GetCanvasWidth(). 
	*/
	void SetHScrollPos(double pos);

	/**
	* Sets the vertical scroll position of the scrollable space.
	* 
	* @param the new vertical scroll position. The position should be a number in the range
	* between 0 and GetCanvasheight().
	*
	* Should you want to center to a location (px, py) expressed in a page space, 
	* you can use the following code:
	*
	*		//focus 
	*		view.SetCurrentPage(page_num);
	*		view.ConvPagePtToScreenPt(px, py, page_num);
	*		view.SetZoom((int)px, (int)py, view.GetZoom());
	*
	*		//center
	*		int width = view.GetBufferWidth();
	*		int height = view.GetBufferHeight();
	*		int dx = (int)(px - (double)width/2 + 0.5);
	*		int dy = (int)(py - (double)height/2 + 0.5);
	*		view.OnScroll(dx, dy);
	*
	*/
	void SetVScrollPos(double pos);

	/**
	* @return true if the rendering thread has finished or the current visible region has
	* been fully rendered.
	*
	* @param visible_region_only The control might pre-render invisible regions if the compatibility parameter
	* is set to false when its constructor is called. In this case, the rendering thread might still
	* be ongoing even if the current visible region has been rendered. If visible_region_only
	* parameter is set to true, this function only checks if the visible region has been rendered,
	* regardless if the rendering thread is ongoing. If compatibility parameter is 
	* set to true when its constructor is called, this parameter takes no effect.
	*/
	bool IsFinishedRendering(bool visible_region_only) const;

	/**
	* Cancels rendering in progress. If PDFViewCtrl is not busy rendering the page, 
	* the function has no side effects.
	*/
	void CancelRendering();

	/**
	* Redraws the contents.
	* @param all If true,  all the rendered contents are discarded and re-rendered; otherwise, 
	* only the visible region will be re-rendered.
	*/
	void Update(bool all = false);

	/**
	* Redraws the contents in the given area.
	* @param update The rectangle to update expressed in screen coordinates.
	*/
	void Update(const Rect& update);

	/**
	* Redraws the area covered with a given annotation.
	* @param annot The annotation to update.
	* @param page_num The page number on which the annotation is located.
	*/
	void Update(const Annot& annot, int page_num);

	/**
	* Redraws all instances (Widgets) of the field.
	* @param field the field for which to update all occurances
	*/
	void Update(const Field& field);

	/**
	 * Updates the page layout withing the view. This function must be called  
	 * after document page sequence is modified (such as when a page is being 
	 * added to or removed from a document) or after changes to page dimensions
	 * (e.g. after a page is rotated or resized).
	 */
	void UpdatePageLayout();

	/**
	 * Disable rendering of a particular annotation. This does not change the annotation itself, just how it is displayed in this viewer instance.
	 * @param annot The annotation object to cease drawing for.
	 */
	void HideAnnotation(const Annot& annot);

	/**
	 * Enable rendering of a particular annotation. Only has an effect if HideAnnotation() has previously been called on the same annot.
	 * @param annot The annotation object to resume rendering. 
	 */
	void ShowAnnotation(const Annot& annot);

	/**
	* Returns the width of the main view in pixels.
	* @note this method is typically used only in PDFNet for C++
	*/
	int GetViewWidth() const;

	/**
	* Returns the width of the main view in pixels.
	* @note this method is typically used only in PDFNet for C++
	*/
	int GetViewHeight() const;


	/**
	* Enable or disable annotation and forms rendering. By default, all annotations 
	* and form fields are rendered.
	*
	* @param render_annots True to draw annotations, false otherwise. 
	*/
	void SetDrawAnnotations(bool render_annots);

	/**
	 * Enables or disables URL extraction.
	 *
	 * @param enabled if true URL extraction is enabled, if false URL extraction is
	 * disabled.
	 *
	 * @default by default URL extraction is disabled
	 *
	 * @note If set to enabled when the document is already opened, it may not
	 * find links on pages that were already rendered. It is suggested to
	 * set this flag before opening the document.
	 */
	void SetUrlExtraction(bool enabled);

	/**
	 * Gets the link info at a given point, specified in client space.
	 *
	 * @param x the x position in client space
	 * @param y the y position in client space
	 *
	 * @return the LinkInfo object with the link information or null if
	 * no link is found in the queried location.
	 *
	 * @note To get valid links, SetUrlExtraction(boolean) must be
	 * set to true before opening the document.
	 */
	LinkInfo GetLinkAt(int x, int y);

	/**
	 * Enable or disable highlighting form fields. Default is disabled.
	 *
	 * @param highlight_fields true to highlight, false otherwise. 
	 */
	void SetHighlightFields(bool highlight_fields);
	
	/**
	* Set the border color for required fields 
	* 
	* This option only has an effect if field highlighting is turned on using
	* `SetHighlightFields(true)`. 
	* 
	* @param new_border_color the new border color, in rgba form.
	*/
	void SetRequiredFieldBorderColor(const ColorPt& new_border_color);

	/**
	* Enable or disable anti-aliasing. 
	* 
	* Anti-Aliasing is a technique used to improve the visual 
	* quality of images when displaying them on low resolution 
	* devices (for example, low DPI computer monitors).
	* 
	* @default Anti-aliasing is enabled by default.
	*/
	void SetAntiAliasing(bool enable_aa);

	/**
	 * Enable or disable path hinting.
	 * 
	 * @param enable_hinting if true path hinting is enabled. Path hinting is used to slightly
	 * adjust paths in order to avoid or alleviate artifacts of hair line cracks between
	 * certain graphical elements. This option is turned on by default.
	 *
	 */
	void SetPathHinting(bool enable_hinting);

	/**
	 * Set thin line adjustment parameters.
	 * 
	 * @param pixel_grid_fit if true (horizontal/vertical) thin lines will be snapped to 
	 * integer pixel positions. This helps make thin lines look sharper and clearer. This
	 * option is turned off by default and it only works if path hinting is enabled.
	 *
	 * @param stroke_adjust if true auto stroke adjustment is enabled. Currently, this would 
	 * make lines with sub-pixel width to be one-pixel wide. This option is turned on by default.
	 */
	void SetThinLineAdjustment(bool pixel_grid_fit, bool stroke_adjust);

	/**
	* Enable or disable image smoothing. 
	* 
	* The rasterizer allows a trade-off between rendering quality and rendering speed. 
	* This function can be used to indicate the preference between rendering speed and quality.
	*
	* @note image smoothing option has effect only if the source image has higher resolution 
	* that the output resolution of the image on the rasterized page. PDFNet automatically 
	* controls at what resolution/zoom factor, 'image smoothing' needs to take effect. 
	*
	* @param smoothing_enabled True to enable image smoothing, false otherwise.
	* @default image smoothing is enabled.
	*/
	void SetImageSmoothing(bool smoothing_enabled = true);

	/**
	* Enables of disables caching of images, fonts, and other resources. Disabling caching 
	* can lower memory requirements at the expense of rendering speed.	 
	* 
	* @param enabled if true caching is enabled, if false caching is disabled.
	* @default by default caching is enabled
	*/
	void SetCaching(bool enabled);

	/**
	* Sets the core graphics library used for rasterization and 
	* rendering. Using this method it is possible to quickly switch 
	* between different implementations. By default, PDFNet uses a 
	* built-in, high-quality, and platform independent rasterizer.
	*
	* @param type Rasterizer type. 
	*/
	void SetRasterizerType (PDFRasterizer::Type type);

	/**
	* Sets the gamma factor used for anti-aliased rendering.
	* 
	* @param exp is the exponent value of gamma function. Typical values 
	* are in the range from 0.1 to 3. 
	*  
	* Gamma correction can be used to improve the quality of anti-aliased
	* image output and can (to some extent) decrease the appearance common 
	* anti-aliasing artifacts (such as pixel width lines between polygons).
	* 
	* @note Gamma correction is used only in the built-in rasterizer.
	*/
	void SetGamma(double exp);

	/** 
	 * Enable or disable support for overprint and overprint simulation. 
	 * Overprint is a device dependent feature and the results will vary depending on 
	 * the output color space and supported colorants (i.e. CMYK, CMYK+spot, RGB, etc). 
	 * 
	 * @default By default overprint is only enabled for PDF/X files.
	 * 
	 * @param op e_op_on: always enabled; e_op_off: always disabled; e_op_pdfx_on: enabled for PDF/X files only.
	 */
	void SetOverprint(PDFRasterizer::OverprintPreviewMode op);

	/** 
	* Sets the Optional Content Group (OCG) context that should be used when 
	* viewing the document. This function can be used to change the current 
	* OCG context. Optional content (such as PDF layers) will be selectively 
	* rendered based on the states of optional content groups in the given 
	* context.
	* 
	* @param ctx Optional Content Group (OCG) context, or NULL if the rasterizer
	* should render all content on the page.
	* 
	* @note Unlike PDFDraw.SetOCGContext() this method copies the given context. 
	* As a result, in order to modify the state of OCG groups in the current 
	* context use GetOCGContext() to obtain the currently selected content
	* and then modify states.
	*/
	void SetOCGContext(const OCG::Context& ctx);

	/**
	* @return the Optional Content Group (OCG) context associated with this
	* PDFViewCtrl, or NULL (i.e. context.IsValid()==false) if there is no OCG
	* context associated with the view. If an OCG context associated with the 
	* view, optional content (such as PDF layers) will be selectively rendered 
	* based on the states of optional content groups in the given context.
	*/ 
	OCG::Context GetOCGContext();

	/**
	* PDFViewCtrl class supports a number of 'built-in' tool modes. 
	* ToolMode enumerates tool modes supported by PDFViewCtrl.
	*/
	enum ToolMode 
	{
		e_custom,				    // Custom tool
		e_pan,						// Pan tool
		e_text_rect_select,			// Rectangular text selection tool
		e_text_struct_select,		// HTML Style text selection tool
		e_zoom_in,					// Zoom in tool
		e_zoom_out,					// Zoom out tool
		e_annot_edit,			    // Annotation editing tool
		e_line_create,				// Line creation tool
		e_arrow_create,				// Arrow creation tool
		e_rect_create,				// Rectangle creation tool
		e_oval_create,				// Oval/Ellipse creation tool
		e_ink_create,				// Freehand drawing tool
		e_text_annot_create,		// Text annotation creation tool
		e_stamp_create,				// Stamp Annotation creation tool
		e_highlight_create,			// highlight text tool 
		e_underline_create,			// underline text tool
		e_strikeout_create,			// cross out text tool
		e_squiggly_create,			// squiggly underline tool
		e_text_box_create,			// free text creation tool
		e_calloutbox_create,		// free text with a callout tool
		e_polygon_create,		  	// polygon creation tool
		e_polyline_create,			// polyline creation tool
		e_file_attachment,			// file attachment creation
		e_sound_attachment,			// sound annotation creation
		e_movie_attachment,			// movie annotation creation
		e_caret_create,				// caret placement tool
		e_redaction_create,			// redaction placement tool    
		e_text_field_create,		// interactive text field creation
		e_check_box_create,			// interactive check box creation tool
		e_radio_button_create,		// interactive radio button tool
		e_list_box_create,			// interactive list box creation tool
		e_combo_box_create,			// interactive combo box creation tool
		e_button_create,			// interactive button creation tool
		e_link_create,				// create a link annotation
		e_tool_mode_end
	};

	/**
	* Sets the new tool mode (such as pan, text select, etc).
	* @param mode - new tool mode.
	*/
	void SetToolMode(ToolMode mode);

	/**
	* @return Current tool mode.
	*/
	ToolMode GetToolMode() const;

	 /**
	  * TextSelectionMode lists different text selection modes that can be used to highlight text.
	  * PDFView currently supports the following text selection modes: 
	  *   - e_structural - Selects text based on the logical structure of the page. This type of selection is similar to HTML like selection in web-browsers.
	  *   - e_rectangular - Selects all words that intersect the given selection rectangle.
	  *   - e_structural_algorithm_2 - Similar to e_structural but use different algorithm when the start point is not inside a block (not being too smart).
	  */
	enum TextSelectionMode {
		e_structural,
		e_rectangular,
		e_structural_algorithm_2
	};

	/**
	 * Sets the selection mode used for text highlighting.
	 * @param tm the text selection mode.
	 */
	 void SetTextSelectionMode(TextSelectionMode tm);

	/**
	 * Selects text within the given region using the current text selection mode.
	 * 
	 * @return true if some text was selected, false otherwise.
	 * @param x1, y1, x2, y2 - two points (screen coordinates, origin located at the upper-left corner of this view)
	 * defining the opposite corners of a selection rectangle.
	 */
	bool Select(double x1, double y1, double x2, double y2);

	/**
	* Selects text within the given region using the current text selection mode with defined snap-to-start and snap-to-end modes.
	*
	* @return true if some text was selected, false otherwise.
	* @param x1, y1, x2, y2 - two points (screen coordinates, origin located at the upper-left corner of this view)
	* defining the opposite corners of a selection rectangle.
	* @param snap_to_start, snap-to-end: if selected text should contain the whole word at start/end of selection points.
	*/
	bool SelectWithSnapping(double x1, double y1, double x2, double y2, bool snap_to_start, bool snap_to_end);

	/**
	* Selects text within the given region using the current text selection mode with smart snap-to-start and snap-to-end modes.
	*
	* @return true if some text was selected, false otherwise.
	* @param x1, y1, x2, y2 - two points (screen coordinates, origin located at the upper-left corner of this view)
	* defining the opposite corners of a selection rectangle.
	*/
	bool SelectWithSmartSnapping(double x1, double y1, double x2, double y2);

	/**
	* Selects texts using structural mode.
	* 
	* @return true if some texts were selected, false otherwise.
	* @param (x1, y1), page1 - the first selection point (in page coordinates space) on page page1
	* @param (x2, y2), page2 - the second selection point (in page coordinates space) on page page2
	*/
	bool Select(double x1, double y1, int page1, double x2, double y2, int page2);

	/**
	* Selects texts using structural mode with defined snap-to-start and snap-to-end modes.
	*
	* @return true if some texts were selected, false otherwise.
	* @param (x1, y1), page1 - the first selection point (in page coordinates space) on page page1
	* @param (x2, y2), page2 - the second selection point (in page coordinates space) on page page2
	* @param snap_to_start, snap-to-end: if selected text should contain the whole word at start/end of selection points
	*/
	bool SelectWithSnapping(double x1, double y1, int page1, double x2, double y2, int page2, bool snap_to_start, bool snap_to_end);

	/**
	* Selects texts using structural mode with smart snap-to-start and snap-to-end modes.
	*
	* @return true if some texts were selected, false otherwise.
	* @param (x1, y1), page1 - the first selection point (in page coordinates space) on page page1
	* @param (x2, y2), page2 - the second selection point (in page coordinates space) on page page2
	*/
	bool SelectWithSmartSnapping(double x1, double y1, int page1, double x2, double y2, int page2);

	/**
	* Selects texts identified by Highlights.
	* 
	* @return true if some texts were selected, false otherwise.
	* @param highlights - an instance of Highlights class.
	*/
	bool Select(const Highlights& highlights);

	
	/**
	* Selects a region according to a PDFView::Selection object
	*
	* @return true if some texts were selected, false otherwise.
	* @param select - an instance of the Selection class
	*/
	bool Select(const Selection& select);

	/**
	* @return return true if there is selection, false otherwise.
	*/
	bool HasSelection() const;

	/**
	* Remove any text selection.
	*/
	void ClearSelection();

	/**
	* @return Current text selection for a given page.
	* If there is only selection on one page, then page number
	* does not need to be provided.
	*/
	Selection GetSelection( int page = -1 ) const;

	/**
	* @return the first page number that has text selection on it.
	* Useful when there are selections on multiple pages at the same time.
	*/
	int GetSelectionBeginPage() const ;

	/**
	* @return the last page number that has text selection on it.
	* Useful when there are selections on multiple pages at the same time.
	*/
	int GetSelectionEndPage() const;

	/**
	* @return returns true if given page number has any text selection on it.
	* Useful when there are selections on multiple pages at the same time.
	*/
	bool HasSelectionOnPage( int ipage ) const;

	/**
	* Requests for preparing words of the given page.
	* Note: Words are going to be prepared asynchronously
	*
	* @param page_num - page number
	*/
	void PrepareWords(int page_num);

	/**
	* @return true if words of the given page has been prepared, false otherwise
	* @param page_num - page number
	*/
	bool WereWordsPrepared(int page_num) const;

	/**
	* @return true if there is a text in the given rectangle, false otherwise
	* and point (x2, y2) is the end selection point. The points are defined in screen space.
	*/
	bool IsThereTextInRect(double x1, double y1, double x2, double y2) const;

	/**
	* Requests for preparing annotations of the given page.
	* Note: Annotations are going to be prepared asynchronously
	*
	* @param page_num - page number
	* @param distance_threshold - Maximum distance from the point (x, y) to the annotation for the annot to be considered a hit.
	* @param minimum_line_weight - For very thin lines, it is almost impossible to hit the actual line.
	* This specifies a minimum line thickness (in screen coordinates) for the purpose of calculating whether
	* a point is inside the annotation or not
	*/
	void PrepareAnnotsForMouse(int page_num, double distance_threshold, double minimum_line_weight);

	/**
	* @return true if annotations of the given page have been prepared, false otherwise
	* @param page_num - page number
	*/
	bool WereAnnotsForMousePrepared(int page_num) const;

	/**
	* @return annotation type at the given point
	* @param x - x coordinate of the input point
	* @param y - y coordinate in the input point
	*/
	Annot::Type GetAnnotTypeUnder(double x, double y);

	/**
	* Enables or disables drawing of a thin border around each page.
	* @param border_visible - if true, the border will be visible.
	*/
	void SetPageBorderVisibility(bool border_visible);

	/**
	 * Enables or disables the transparency grid (check board pattern) to reflect 
	 * page transparency.
	 * @param trans_grid_visible - if true, the grid is turned on.
	 */
	void SetPageTransparencyGrid(bool trans_grid_visible);

	/**
	* Sets the default 'paper' color used to draw background of each page.
	* @param r, g, b - RGB color specifying the default page color.
	*/
	void SetDefaultPageColor(UInt8 r, UInt8 g, UInt8 b);

	/**
	* Sets the default background color used to paint the area surrounding each page.
	* @param r, g, b - RGB color specifying the default background color.
	*/
	void SetBackgroundColor(UInt8 r, UInt8 g, UInt8 b);

	/**
	* Sets the horizontal alignment used for rendering pages within the view.
	* @param align an integer specifying the horizontal alignment. Depending 
	* of whether align is positive, negative, or zero - pages will be right, 
	* left or center aligned: 
	*   align<0  -> pages are left aligned.
	*   align==0 -> pages are centered.
	*   align>0  -> pages are right aligned.
	*/
	void SetHorizontalAlign(int align);

	/**
	 * Sets the vertical alignment used for rendering pages within the view.
	 * @param align an integer specifying the vertical alignment. Depending 
	 * of whether align is positive, negative, or zero - pages will be bottom, 
	 * top or center aligned: 
	 *   align<0  -> pages are top aligned.
	 *   align==0 -> pages are centered.
	 *   align>0  -> pages are bottom aligned.
	 */
	void SetVerticalAlign(int align);

	/**
	* Sets the vertical and horizontal padding and column spacing between adjacent pages in the view. 
	* 
	* 
	* @param horiz_col_space horizontal column spacing (represented in pixels) between 
	* adjacent pages in the view. Default is 10.
	* @param vert_col_space vertical column spacing (represented in pixels) between adjacent 
	* pages in the view. Default is 10.
	* @param horiz_pad horizontal padding (represented in pixels) on the left and right side 
	* of the view. Default is 10.
	* @param vert_pad vertical padding (represented in pixels) on the top and bottom side 
	* of the view. Default is 10.
	*/
	void SetPageSpacing(int horiz_col_space, int vert_col_space, int horiz_pad, int vert_pad);

	/**
	* Gets the annotation bounding box in screen coordinates 
	* 
	* 
	* @param annot the target annotation
	* @param page_num the page where the annotation is on
	* @return the bounding box of the annotation in screen coordinates
	*/
	Rect GetScreenRectForAnnot(Annot annot, int page_num = -1);

	/**
	* Gets the annotation at the (x, y) position expressed in screen coordinates 
	* 
	* 
	* @param x x coordinate of the screen point
	* @param y y coordinate of the screen point
	* @return the annotation at (x, y). If there is no annotation at (x, y), the returned annotation's IsValid method will return false.
	*/
	Annot GetAnnotationAt(int x, int y);

	/** 
	 * Sets the download report handling function to be called on download events,
	 * such as when a new page or thumbnail is available, and any download related errors.
	 * 
	 * @param download_proc Download handling callback function (or delegate in .NET)
	 * @param data Custom data to be passed as a parameter to 'download_proc'.
	 */
	void SetDownloadReportHandler(DownloadReportHandler download_proc, void* data);

	/**
	 * Asynchronously open a PDF file at the given url. The PDFDoc that is downloaded
	 * is owned by this object and will be deallocated when this object is done with the doc.
	 * This works best with PDF's that are linearized, as pages can be downloaded and viewed in random access order,
	 * without the need to download the entire document. A viewing session can also be
	 * persisted across multiple viewing/application sessions to remove redundant downloads 
	 * and improve overall performance by using the optional cache_pdf parameter.
	 * @note Use SetDownloadReportHandler to track the download progress.
	 * 
	 * @param url the url to open
	 * 
	 * @param cache_pdf This function will use downloaded data to construct a PDF in this location. 
	 * If null or blank, the PDF will be stored in a temporary location. If the path points to the result 
	 * of a previous call to this function for this particular URL, then PDFViewCtrl will resume that download.
	 * Note that if disk caching is disabled this file will not be used.
	 * 
	 * @param password The PDF password to use to open the PDF.
	 * @param options Optional HTTP request options to use with every HTTP request.
	 */
	void OpenURLAsync(const char* url, UString cache_pdf="", const char* password = 0, const class HTTPRequestOptions* options = 0);

	/**
	 * Specify the different thumbnail settings for the viewer.
	 * 
	 * @param use_embedded Enables or disables using thumbnails embedded in the PDF document as a preview of the rendered page. (Currently ignored - future versions may take advantage of embedded thumbnails)
	 * @param generate_at_runtime Enables or disables generating thumbnails at runtime.
	 * @param use_disk_cache Enables or disables caching thumbnails in a temporary disk file.
	 * @param thumb_max_side_length The maximum size, in pixels, of a dimension of generated thumbnails.
	 * @param max_abs_cache_size The absolute maximum size on disk, in bytes, for the temporary thumbnail cache.
	 * @param max_perc_cache_size The maximum percentage of free disk space, in the range 0 - 1.0, that the cache can take up.
	 */
	void SetupThumbnails(bool use_embedded, bool generate_at_runtime, bool use_disk_cache, int thumb_max_side_length, size_t max_abs_cache_size, double max_perc_cache_size);

	/**
	 * Remove all thumbnails from the persistent disk cache. 
	 */
	void ClearThumbCache();

	/**
	 * Declaration for the callback function that will be called after GetThumbAsync
	 * retrieves a thumbnail from the on-disk thumbnail cache.
	 * 
	 * @param page_num The page number of the thumbnail.
	 * @param was_thumb_found A boolean value which is true if the thumbnail could be retrieved from the persistent cache, and false otherwise.
	 * @param thumb_buf A pointer to the thumbnail image.  This buffer's size, in bytes, is equal to thumb_width * thumb_height * 4.
	 * @param thumb_width The width, in pixels, of the thumbnail image.
	 * @param thumb_height The height, in pixels, of the thumbnail image.
	 * @param custom_data Custom data passed into GetThumbAsync.
	 */
	typedef void (*ThumbAsyncHandler) (int page_num, bool was_thumb_found, const char* thumb_buf, int thumb_width, int thumb_height, void* custom_data);

	/** 
	 * Retrieves the specified thumbnail from the persistent thumbnail
	 * cache on disk, then calling proc on the resulting thumbnail.
	 * 
	 * @param page_num The page number of the thumbnail.
	 * @param proc A callback function that will be called after the thumbnail is retrieved, or if that retrieval fails.
	 * @param data Custom data to be passed as a parameter to 'proc'.
	 */
	void GetThumbAsync(int page_num,  ThumbAsyncHandler proc, void* custom_data);

	 /*
	  *	Cancel all pending GetThumbAsync requests. Your callback function will still be called
	  *	for each canceled request, but 'was_thumb_found' will be set to 'false'.
	  */
	 void CancelAllThumbRequests();

	/** 
	 * A type of callback function that is called
	 * from a secondary thread to issue a rendering
	 * request on the UI thread.
	 */
	 typedef void (*RequestRenderInWorkerThreadProc) (void* custom_data);

	/** 
	 * Sets a callback for issuing a render request on the UI thread.
	 * The callback will be called from a secondary thread.  The called
	 * code is responsible for dispatching an event to the UI thread
	 * using the relevant mechanism.
	 * @param proc The callback.
	 * @param data Custom data to be passed as a parameter to 'proc'.
	 */
#ifdef SWIG
	 void SetRequestRenderInWorkerThreadProc(Callback* instance);
#else
	 void SetRequestRenderInWorkerThreadProc(RequestRenderInWorkerThreadProc proc, void* custom_data);
#endif

#ifdef SWIG
	/** 
	 * Sets the FindText handling function to be called once FindTextAsync is done,
	 * whether it was interrupted, canceled, or completed.
	 * 
	 * @param A pointer to the Callback object
	 */
	void SetFindTextHandler(Callback * instance);
#else
	/** 
	 * FindTextAsync Handling
	 * A type of callback function (or a delegate in .NET terminology) that is called
	 * once FindTextAsync is completed.
	 */
	typedef void (*FindTextAsyncHandler) (bool success, Selection& select, void * custom_data);

	/** 
	* Sets the FindText handling function to be called once FindTextAsync is done,
	* whether it was interrupted, canceled, or completed.
	* 
	* @param proc FindText handling callback function (or delegate in .NET)
	* @param data Custom data to be passed as a parameter to 'proc'.
	*/
	void SetFindTextHandler(FindTextAsyncHandler proc, void * custom_data);
#endif
	/** 
	 * Searches for the provided search string in the documents in a secondary thread,
	 * and calls FindTextAsyncHandler with the resulting selection.
	 * 
	 * @param search_str The string to match
	 * @param match_case Set to true for case-sensitive search.
	 * @param match_whole_word Set to true to match whole words only
	 * @param search_up Set to true to search up through the document
	 * @param reg_exp Set to true to interpret search_str as regular expression 
	 */
	void FindTextAsync(const UString& search_str, bool match_case, bool match_whole_word, 
						bool search_up, bool reg_exp);


// @cond PRIVATE_DOC
private:
	TRN_PDFViewCtrl mp_view;
	TRN_PDFDoc temp_doc;

	// PDFViewCtrl should not be copied
	PDFViewCtrl(const PDFViewCtrl& other);
	PDFViewCtrl& operator= (const PDFViewCtrl&);

	//For FindTextAsync callback landing pad
	FindTextAsyncHandler m_findtext_proc;
	void * m_findtext_data;
	static void NativeFindTextHandler(unsigned char success, TRN_PDFViewSelection select, void * custom_data);
	// @endcond
};

/**
 * Class for customizing network requests.
 */
class HTTPRequestOptions
{
public:
	/**
	 * Create a HTTPRequestOptions object.
	 */
	HTTPRequestOptions();
	/**
	 * Set a custom header to use with all requests.
	 * @param header A custom header.
	 * @param val The value of the custom header.
	 */
	void AddHeader(const UString& header, const UString& val);
protected:
	TRN_Obj m_obj;
	friend class PDF::PDFViewCtrl;
	SDF::ObjSet m_objset;
};

#include <Impl/PDFViewCtrl.inl>

    }	// namespace PDF
}	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPDFViewCtrl
