//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPDFView
#define PDFTRON_H_CPPPDFPDFView

#include <Common/BasicTypes.h>
#include <PDF/PDFDoc.h>
#include <PDF/ExternalAnnotManager.h>
#include <PDF/PDFRasterizer.h>
#include <PDF/Highlights.h>
#include <PDF/LinkInfo.h>
#include <PDF/OCG/Context.h>
#include <C/PDF/TRN_PDFView.h>
#include <PDF/Selection.h>
#include <PDF/DocumentConversion.h>
#include <SDF/ObjSet.h>
#include <PDF/ViewChangeCollection.h>
#include <PDF/ActionParameter.h>
#ifdef SWIG
#include <PDF/Callback.h>
#endif

namespace pdftron {
	namespace PDF {

/**
 * PDFView is a utility class that can be used for interactive rendering of PDF documents.
 *
 * In .NET environment PDFView is derived from System.Windows.Forms.Control and it can be
 * used like a regular form (see PDFViewForm.cs in PDFView sample for C# for a concrete
 * example). 
 * 
 * PDFView implements some essential features such as double-buffering, multi-threaded 
 * rendering, scrolling, zooming, and page navigation that are essential in interactive 
 * rendering applications (e.g. in client PDF viewing and editing applications).
 *
 * PDFView defines several coordinate spaces and it is important to understand their 
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
 * @note PDFView is available on all platforms supported by PDFNet.
 */
class PDFView
{
public:

	/** 
	 * PDFView constructor and destructor. Create PDFView without associating it to any
	 * document.
	 */
	 PDFView();
	 ~PDFView();

	/** 
	 * Associates this PDFView with a given PDF document. 
	 * 
	 * @param doc - A document to be displayed in the view.
	 */
	 void SetDoc(PDFDoc& doc);

	 /**
	 * Associates this PDFView with a given document conversion.
	 * The conversion will be performed page-by-page, asynchronously.
	 * The pdview object will be updated to display the conversion result
	 *
	 * @param doc - A document to be displayed in the view.
	 */

	 void OpenUniversalDoc(DocumentConversion& conversion);

     /** 
	 * Close the associated PDF document. 
	 */
	 void CloseDoc();

	/** 
	 * @return Currently associated document with this PDFView.
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
	PagePresentationMode GetPagePresentationMode() const;
    
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
     *
     * Sets the color post processing transformation. This transform is applied
     * to the rasterized bitmap as the final step in the rasterization process,
     * and is applied directly to the resulting bitmap (disregarding any color
     * space information). Color post processing only supported for RGBA output.
     *
     * This mode will map the brightness of the original rasterized bitmap to a
     * gradient in image_file_contents from left to right.
     *
     * @param image_file_contents A filter with image file contents.
     *
     */
    void SetColorPostProcessMapFile(Filters::Filter image_file_contents);
    
    /**
     * Sets the color post processing transformation. This transform is
     * applied to the rasterized bitmap as the final step in the rasterization
     * process, and is applied directly to the resulting bitmap (disregarding
     * any color space information). Color post processing only supported for
     * RGBA output. This mode will map the brightness of the original
     * rasterized bitmap to a gradient between whiteColor and blackColor
     *
     * @param white_color The white color (ARGB) of the page.
     *
     * @param black_color The black color (ARGB) of the page.
     */
    void SetColorPostProcessColors(unsigned int white_color, unsigned int black_color);

	 /**
	 * @return the current color post processing mode.
	 */
	 PDFRasterizer::ColorPostProcessMode GetColorPostProcessMode() const;

	/**
	 * @return the current page displayed in the view.
	 */
	int GetCurrentPage() const;

	/**
	 * @return the total number of pages in the document.
	 */
	int GetPageCount() const;

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
	 * Get a vector with the pages currently visible on the screen.
	 *
	 * @return a vector of the pages currently visible on the screen.
	 */
	std::vector<int> GetVisiblePages() const ;

	/**
	 * Returns the current zoom factor.
	 * 
	 * @return current zoom (or scaling) component used to display the page content. 
	 */
	double GetZoom() const;

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
	 * The zoom point (x,y) is represented in the screen space, which 
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
	 * @return  The current rotation of this PDFView.
	 */
	Page::Rotate GetRotation() const;

	/**
	 * @return the number of the page located under the given screen 
	 * coordinate. The positive number indicates a valid page, whereas 
	 * number less than 1 means that no page was found. 
	 */
	int GetPageNumberFromScreenPt(double x, double y) const;

	/**
	 * Converts a point expressed in screen space to a point in canvas space.
	 */
	Point ConvScreenPtToCanvasPt(const Point& pt) const;

#ifndef SWIG
	void ConvScreenPtToCanvasPt(double& x, double& y) const;
#endif

	/**
	 * Converts a point expressed in canvas space to a point in screen space.
	 */
	Point ConvCanvasPtToScreenPt(const Point& pt) const;

#ifndef SWIG
	void ConvCanvasPtToScreenPt(double& x, double& y) const;
#endif

	/**
	 * Converts a point expressed in canvas space to a point in a page space.
	 * 
	 * @param page_num the page number for the page used as the origin of the destination 
	 * coordinate system. Negative values are used to represent the current page.
	 * Pages are indexed starting from one.
	 */
	Point ConvCanvasPtToPagePt(const Point& pt, int page_num = -1) const;

#ifndef SWIG
	void ConvCanvasPtToPagePt(double& x, double& y, int page_num = -1) const;
#endif

	/**
	 * Converts a point from a page space to point in canvas space.
	 * 
	 * @param page_num the page number for the page used as the origin of the destination 
	 * coordinate system. Negative values are used to represent the current page.
	 * Pages are indexed starting from one.
	 */
	Point ConvPagePtToCanvasPt(const Point& pt, int page_num = -1) const;

#ifndef SWIG
	void ConvPagePtToCanvasPt(double& x, double& y, int page_num = -1) const;
#endif

	/**
	 * Converts a point expressed in screen space to a point in a page space.
	 * 
	 * @param page_num the page number for the page used as the origin of the destination 
	 * coordinate system. Negative values are used to represent the current page.
	 * Pages are indexed starting from one.
	 */
	Point ConvScreenPtToPagePt(const Point& pt, int page_num = -1) const;

#ifndef SWIG
	void ConvScreenPtToPagePt(double& x, double& y, int page_num = -1) const;
#endif

	/**
	 * Converts a point in a page space to a point in the screen space.
     * If PDFView is in a non-continous page view mode, and the page is not visible,
     * the result is undefined.
	 * 
	 * @param page_num the page number for the page used as the origin of the destination 
	 * coordinate system. Negative values are used to represent the current page.
	 * Pages are indexed starting from one.
	 */
	Point ConvPagePtToScreenPt(const Point& pt, int page_num = -1) const;

#ifndef SWIG
	void ConvPagePtToScreenPt(double& x, double& y, int page_num = -1) const;
#endif

	/**
	 * Snaps an xy coordinate pair (in screen space) to the nearest piece of
	 * document geometry.
	 */
	Point SnapToNearestInDoc(const Point& screen_pt);

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
	 * @param page_num same as for PDFView.Conv???() methods.
	 *
	 * @note to obtain a transformation matrix that maps screen 
	 * coordinates to page coordinates, you can invert the device matrix. 
	 * For example: 
	 * @code
	 *   Common::Matrix2D scr2page(pdfview.GetDeviceTransform());
	 *   scr2page.Inverse();
	 * @endcode 
	 */
	Common::Matrix2D GetDeviceTransform(int page_num = -1) const;

	/** 
	 * Sets the error handling function to be called in case an error is encountered 
	 * during page rendering.
	 * 
	 * @param error_proc Error handling callback function (or delegate in .NET)
	 * @param data Custom data to be passed as a second parameter to 'error_proc'.
	 */
#ifdef SWIG
	void SetErrorReportProc(Callback* instance);
#else
	void SetErrorReportProc(PDFRasterizer::ErrorReportProc error_proc, void* data);
#endif

	/** 
	 * A prototype for a callback function (or a delegate in .NET terminology) 
	 * that will be called whenever current page number changes.
	 * 
	 * @param current_page the current page.
	 * @param num_pages total number of pages in the document.
	 * @param data Custom data to be passed as a second parameter to 'curr_pagenum_proc'.
	 */
	typedef void (*CurrentPageProc) (int current_page, int num_pages, void* data);

	/** 
	 * Sets the callback function (i.e. a delegate) that is called whenever current 
	 * page number changes. This can be used to update the current page number within 
	 * GUI applications etc.
	 * 
	 * @param curr_pagenum_proc Callback function (or a delegate in .NET).
	 * @param data Custom data to be passed as a second parameter to 'curr_pagenum_proc'.
	 */
#ifdef SWIG
	 void SetCurrentPageProc(Callback* instance);
#else
	 void SetCurrentPageProc(CurrentPageProc curr_pagenum_proc, void* data);
#endif

	/**
	 * A prototype for a callback function (or a delegate in .NET terminology) 
	 * for JavaScript action. Can be used to handle alert event which pops up
	 * a window with alert message.
	 *
	 * @param event_type such as 'alert'
	 * @param json contains event data
	 * @param data user defined data
	 */
	 typedef void(*JavaScriptEventProc) (const char* event_type, const char* json, void* data);

	 /**
	 * Sets the callback function (i.e. a delegate) for JavaScript action. 
	 * Can be used to handle alert event which pops up a window with alert message.
	 *
	 * @param js_proc Callback function (or a delegate in .NET).
	 * @param data user defined data
	 */
#ifdef SWIG
	 void SetJavaScriptEventCallBack(Callback* instance);
#else
	 void SetJavaScriptEventCallBack(JavaScriptEventProc js_proc, void* data);
#endif

	/** 
	 * A prototype for a callback function (or a delegate in .NET terminology) 
	 * that will be called whenever current zoom (magnification) number changes.
	 * 
	 * @param current_zoom the current zoom.
	 * @param data Custom data to be passed as a second parameter to 'curr_zoom_proc'.
	 */
	 typedef void (*CurrentZoomProc) (double curr_zoom_proc, void* data);

	/** 
	 * Sets the callback function (i.e. a delegate) that is called whenever current 
	 * zoom (magnification) changes. This can be used to update the current zoom number 
	 * within GUI applications etc.
	 * 
	 * @param curr_zoom_proc Callback function (or a delegate in .NET).
	 * @param data Custom data to be passed as a second parameter to 'curr_zoom_proc'.
	 */
#ifdef SWIG
	 void SetCurrentZoomProc(Callback* instance);
#else
	 void SetCurrentZoomProc(CurrentZoomProc curr_zoom_proc, void* data);
#endif

	 /**
	 * Requests action object to be executed by PDFViewCtrl. Action must belong to the document
	 * currently displayed in PDFViewCtrl.
	 * @param action object that is to be executed.
	 */
	 void ExecuteAction(Action& action);

	 void ExecuteAction(ActionParameter& action_param);

	/**
	 * Returns the width of the scrollable space.
	 */
	 double GetCanvasWidth() const;

	/**
	 * Returns the height of the scrollable space.
	 */
	 double GetCanvasHeight() const;

	/**
	 * @return the current horizontal scroll position in the scrollable space. 
	 */
	 double GetHScrollPos() const;

	/**	
	 * @return the current vertical scroll position in the scrollable space. 
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
	 * Sets the horizontal scroll position in scrollable space.
	 * 
	 * @param the new horizontal scroll position. The position should be in the range
	 * between 0 and GetCanvasWidth(). 
	 */
	 void SetHScrollPos(double pos);

	/**
	 * Sets the vertical scroll position in scrollable space.
	 * 
	 * @param the new vertical scroll position. The position should be in the range
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
	 * Resize rendering buffer to new dimensions.
	 * 
	 * @param width - The width of the target image in pixels.
	 * @param height - The height of the target image in pixels (the number of rows).
	 * @note this method is typically used only in PDFNet for C++
	 */
	 void OnSize(int width, int height);

	/**
	 *
	 * @param visible_region_only - Specifies if the method refers only to currently
	 * visible content.
	 * 
	 * @return true is the rendering thread finished rendering the view, 
	 * false if the rendering is still in progress.
	 */
	 bool IsFinishedRendering(bool visible_region_only) const;

	/**
	 * Cancels rendering in progress. If PDFView is not busy rendering the page, 
	 * the function has no side effects.
	 */
	 void CancelRendering();
	
	/**
	 * Redraws the contents of the buffer.
	 */
	 void Update(bool all = false);

	/**
	 * Redraws the given area in the buffer.
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
	 * Updates the page layout within the view. This function must be called  
	 * after document page sequence is modified (such as when a page is being 
	 * added to or removed from a document) or after changes to page dimensions
	 * (e.g. after a page is rotated or resized).
	 */
	void UpdatePageLayout();

	/**
	 * Returns the pointer to the internal memory buffer containing the rasterized image 
	 * of the given page. The buffer size is at least 'GetBufferHeight*GetBufferStride' bytes.
	 * The pixel data is stored in 8 bit per component, BGRA format.
	 */
#ifdef SWIG
	std::vector<unsigned char> GetBuffer() const;
#else
	const char* GetBuffer() const;
#endif

	 /**
	 * Update the internal memory buffer that can be returned by GetBuffer(). Since PDFView may not 
	 * necessarily update the buffer until it finishes rendering the current viewing area, it is
	 * required to call UpdateBuffer() to force PDFView to write the current rasterized contents
	 * to the buffer. This is important for, say, calling GetBuffer() in a different thread to
	 * implement progressive rendering.
	 *
	 * @note UpdateBuffer() ensures thread safety internally. In addition, PDFView calls
	 * UpdateBuffer() internally before the user-defined finishing-rendering
	 * callback function (specified by SetRenderFinishProc) is called, if applicable.
	 * this method is typically used only in PDFNet for C++.
	 */
	void UpdateBuffer();

	/**
	 * Returns the width of the rendering buffer in pixels.
	 * @note this method is typically used only in PDFNet for C++
	 */
	 int GetBufferWidth() const;

	/**
	 * Returns the width of the rendering buffer in pixels.
	 * @note this method is typically used only in PDFNet for C++
	 */
	 int GetBufferHeight() const;

	/**
	 * Returns the stride of the rendering buffer in pixels.
	 * @note this method is typically used only in PDFNet for C++
	 */
	 int GetBufferStride() const;
    
    /**
     * Disable rendering of a particular annotation. This does not change the
     * annotation itself, just how it is displayed in this viewer instance.
     *
     * @param annot The annotation object to cease drawing for.
     */
    void HideAnnotation(Annot annot);
    
    /**
     * Enable rendering of a particular annotation. Only has an effect if
     * HideAnnotation() has previously been called on the same annot.
     *
     * @param annot The annotation object to resume rendering.
     */
    void ShowAnnotation(Annot annot);

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
	 * PDFView, or NULL (i.e. context.IsValid()==false) if there is no OCG
	 * context associated with the view. If an OCG context associated with the 
	 * view, optional content (such as PDF layers) will be selectively rendered 
	 * based on the states of optional content groups in the given context.
	 */ 
	OCG::Context GetOCGContext();
	
	/**
	 * Prompts the PDFViewCtrl to update its list of optional content groups.
	 * Call this method if you modify the PDFDoc in a way that adds or removes
	 * a layer. For example, after using Stamper to create a stamp.
	 */
	void UpdateOCGContext();

	
	/**
	 * Declaration for the callback function that will be called just 
	 * before PDFView starts rendering.
	 * 
	 * @param data Custom data to be passed as a parameter to 'proc'.
	 */
	typedef void (*RenderBeginEventProc) (void* data);

	/**
	 * Declaration for the callback function that will be called after 
	 * PDFView is done with rendering.
	 *
	 * @param data Custom data to be passed as a parameter to 'proc'.
	 * @param canceled - this parameter is false if PDFView successfully 
	 * completed the rendering, or is true if the rendering was canceled.
	 *
	 * @note this callback is available only in the C++ SDK and not 
	 * available in pre-packaged PDF viewing controls (.NET/Java/ActiveX).
	 */
	typedef void (*RenderFinishEventProc) (void* data, bool canceled);

	/** 
	 * Set a callback function that can be used to notify the client 
	 * that PDFView is about to start rendering and modifying the contents
	 * of the rendering buffer.
	 * 
	 * @param proc A callback function that will be called just before 
	 * PDFView starts rendering.
	 * @param data Custom data to be passed as a parameter to 'proc'.
	 *
	 * @note this method is available only in the C++ SDK and not 
	 * available in pre-packaged PDF viewing controls (.NET/Java/ActiveX).
	 */
#ifdef SWIG
	 void SetRenderBeginProc(class Callback* instance);
#else
	 void SetRenderBeginProc(RenderBeginEventProc proc, void* data);
#endif

	/** 
	 * Set a callback function that can be used to notify the client 
	 * that PDFView finished rendering and modifying the contents
	 * of the rendering buffer.
	 * 
	 * @param proc A callback function that will be called after PDFView 
	 * is done with rendering.
	 * @param data Custom data to be passed as a parameter to 'proc'.
	 *
	 * @note this method is available only in the C++ SDK and is not 
	 * available in pre-packaged PDF viewing controls (.NET/Java/ActiveX).
	 */
#ifdef SWIG
	 void SetRenderFinishProc(class Callback* instance);
#else
	 void SetRenderFinishProc(RenderFinishEventProc proc, void* data);
#endif
	

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
	bool SelectWithSnapping(double x1, double y1, int page1, double x2, double y2, int page2,
		bool snap_to_start, bool snap_to_end);

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
	* Selects a region according to a Selection object
	*
	* @return true if some texts were selected, false otherwise.
	* @param select - an instance of the Selection class
	*/
	bool Select(const Selection& select);
	
	/**
	 * Cancel the text search thread if FindText() is started in a different thread. Note that if the text search thread
	 * is currently being suspended by the render thread, it will only be canceled after it is awaken by the render thread.
	 */
	void CancelFindText();
	
	/**
	 * Selects all text on the page.
	 */
	 void SelectAll();

	/**
	 * @return return true if there is selection, false otherwise.
	 */
	 bool HasSelection() const;

	/**
	 * Remove any text selection.
	 */
	 void ClearSelection();

	/**
	 * @return Current text selection for a given page
	 */
	Selection GetSelection( int pagenum = -1 ) const;

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
	 * @param a - The alpha value of the background color. Default value is 255.
	 */
	void SetBackgroundColor(UInt8 r, UInt8 g, UInt8 b, UInt8 a = 255);

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
	 * @param horiz_space horizontal spacing (represented in pixels) between 
	 * adjacent pages in the view. Default is 10.
	 * @param vert_space vertical spacing (represented in pixels) between adjacent 
	 * pages in the view. Default is 10.
	 */
	void SetPageSpacing(int horiz_col_space, int vert_col_space, int horiz_pad, int vert_pad);

	/**
	 *	Sets the cache parameters of the page cache on disk (which caches content streams and
	 *	mipmapped images) for this specific document. These parameters will override the default cache
	 *  parameters.  Note that if this function is called after the document has been rasterized, it has no
	 *  effect.
	 *
	 *  @param document - The document whose settings will be modified.
	 *	@param max_cache_size - The maximum size, in bytes, of the entire document's page cache. Set to zero to disable the viewer cache.
	 *	@param on_disk - If set to 'true', cache will be stored on the local filesystem. If set to 'false', cache will be stored in heap memory.
	 *
	 *	@default Desktop: max_cache_size = 512 MB, on_disk = true | Mobile:  max_cache_size = 100 MB, on_disk = false
	 */
	static void SetViewerCache(SDF::SDFDoc& document, size_t max_cache_size, bool on_disk);

	/**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

	 /**
	 * Set device pixel density
	 */
	 void SetDevicePixelDensity(double dpi, double scale_factor);

	 /**
	 * Gets the annotation bounding box in screen points
	 *
	 *
	 * @param annot target annotation
	 * @param page_num the page number that the annotation is on S
	 * @return the annotation bounding box in screen points
	 */
	 Rect GetScreenRectForAnnot(Annot annot, int page_num = -1);
    
	/**
	 * Gets the annotation at the (x, y) position expressed in screen coordinates 
	 * 
	 * 
	 * @param x x coordinate of the screen point
	 * @param y y coordinate of the screen point
	 * @param distanceThreshold Maximum distance from the point (x, y) to the annotation for the annot to be considered a hit.
	 * @param minimumLineWeight For very thin lines, it is almost impossible to hit the actual line. This specifies a minimum line thickness (in screen coordinates) for the purpose of calculating whether a point is inside the annotation or not.
	 * @return the annotation at (x, y). If there is no annotation at (x, y), the returned annotation's IsValid method will return false.
	 */
	 Annot GetAnnotationAt(int x, int y, double distanceThreshold, double minimumLineWeight);
    
	/**
	 * PageViewMode lists common modes of viewing PDF pages. PDFView currently supports
	 * the following viewing modes:
	 *   - e_fit_page - page zoom is automatically adjusted so that entire page fits into available space.
	 *   - e_fit_width - page zoom is automatically adjusted so that page width fits into available space.
	 *   - e_fit_height - page zoom is automatically adjusted so that page height fits into available space.
	 *   - e_zoom - page is zoomed. The zoom ratio is specified using SetZoom() function.
	 *   - PVM_SIZE - the size of the enum, should always stay as the last element
	 */
	enum PageViewMode
	{
		e_fit_page = 0,
		e_fit_width,
		e_fit_height,
		e_zoom,
		PVM_SIZE	//must stay as the last element
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
	PageViewMode GetPageViewMode() const;
    
	/**
	 * Helper function that will refresh annotation and/or field appearances if needed, and then
	 * render modified page areas, all based on the contents of the view_change parameter.
	 *
	 * @param view_change contains all the updated fields and rectangles.
	 */
	void RefreshAndUpdate(const ViewChangeCollection& view_change);

	/**
	 * Sets the reference page view mode. In a non-continous page presentation
	 * mode, the reference page view mode is used to determine the page view
	 * mode upon a page change event. For example, if the reference page view
	 * mode is set to e_fit_width, the new page coming in will
	 * be displayed with width-fit mode.
	 *
	 * @param mode
	 *            The reference page view mode to set. Valid values are
	 *            e_fit_page, e_fit_width, and
	 *            e_fit_height.
	 */
	 void SetPageRefViewMode(PageViewMode mode);
    
	/**
	 * Gets the reference page view mode. See more details about reference
	 * page view mode in {@link #setPageRefViewMode(int)}.
	 */
	PageViewMode GetPageRefViewMode() const;

	/**
	 * Specify the different thumbnail settings for the viewer. It is recommended that this
	 * not be called after SetDoc in order to avoid clearing cached thumbnails. Calling
	 * this method with different parameters will also clear the persistent disk cache if
	 * it is in use.
	 * 
	 * @param use_embedded Enables or disables using thumbnails embedded in the PDF document as a preview of the rendered page. (Currently ignored - future versions may take advantage of embedded thumbnails)
	 * @param generate_at_runtime Enables or disables generating thumbnails at runtime.
	 * @param use_disk_cache Enables or disables caching thumbnails on disk. If possible thumbnails are cached in a persistent manner.
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
#ifdef SWIG
	 void GetThumbAsync(int page_num, Callback* instance);
#else
	 void GetThumbAsync(int page_num, ThumbAsyncHandler proc, void* custom_data);
#endif

	 /**
	  * Gets the data size of a cached thumbnail.
	  *
	  * @param page_num The page number of the thumbnail.
	  * @return if the thumbnail is available returns the size of the thumbnail
	  * in bytes otherwise returns 0
	  */
	size_t GetThumbInCacheSize(int page_num);

	 /**
	  * Retrieves the specified thumbnail from the persistent thumbnail
	  * cache on disk if it is available.
	  *
	  * @param page_num The page number of the thumbnail.
	  * @param buf the buffer in which to store thumbnail data. This buffer should have space for GetThumbInCacheSize bytes.
	  * @param out_width the width of the thumbnail
	  * @param out_height the height of the thumbnail
	  * @return true if the thumbnail is found in the cache and false otherwise.
	  */
	 bool GetThumbInCache(int page_num, UChar* buf, UInt32& out_width, UInt32& out_height);

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

	/** 
	 * FindTextHandler
	 * A type of callback function (or a delegate in .NET terminology) that is called
	 * once FindTextAsync is completed.
	 */
	typedef void (*FindTextHandler)(bool success, PDF::Selection selection, void* custom_data);

	
#ifdef SWIG
	/** 
	 * Sets the FindText handling function to be called once FindTextAsync is done,
	 * whether it was interrupted, canceled, or completed.
	 * 
	 * @param instance A pointer to the Callback object
	 */
	void SetFindTextHandler(Callback* instance);
#else // SWIG
	/** 
	* Sets the FindText handling function to be called once FindTextAsync is done,
	* whether it was interrupted, canceled, or completed.
	* 
	* @param proc FindText handling callback function (or delegate in .NET)
	* @param data Custom data to be passed as a parameter to 'proc'.
	*/
	void SetFindTextHandler(PDFView::FindTextHandler proc, void* custom_data);
#endif // SWIG

	/** 
	 * Searches for the provided search string in the documents in a secondary thread,
	 * and calls FindTextHandler with the resulting selection.
	 * 
	 * @param search_str The string to search for in the document
	 * @param match_case Set to true for case-sensitive search
	 * @param match_whole_word Set to true to match whole words only
	 * @param search_up Set to true to search up through the document
	 * @param reg_exp Set to true to interpret search_str as a regular expression
	 *
	 */
	 void FindTextAsync(const UString& search_str, bool match_case, bool match_whole_word, bool search_up, bool reg_exp);
    
    /**
     * Returns a vector of all of the annotations on the given page.
     *
     * @param page_num The page number for which to retrieve annotations.
     *
     * @returns A vector of all of the annotations on the given page.
     *
     */
    std::vector<Annot> GetAnnotationsOnPage(int page_num);

    /**
     * Returns a vector of annotations under the line (x1, y1, x2, y2) expressed in screen coordinates.
	 * Does not include form field annotations.
     *
     * @param x1 The x-coordinate of the first point of the line.
	 * @param y1 The y-coordinate of the first point of the line.
	 * @param x2 The x-coordinate of the second point of the line.
	 * @param y2 The y-coordinate of the second point of the line.
     *
     * @returns A vector of annotations under the line (x1, y1, x2, y2) expressed in screen coordinates.
     *
     */
    std::vector<Annot> GetAnnotationListAt(int x1, int y1, int x2, int y2);
    
    void EnableUndoRedo();
    UString Undo();
    UString Redo();
    void TakeSnapshot(const UString& meta_info);
    UString GetNextUndoInfo();
    UString GetNextRedoInfo();
    void RevertAllChanges();
    
    ExternalAnnotManager GetExternalAnnotManager(const UString& author, ExternalAnnotManager::Mode mode = ExternalAnnotManager::e_admin_undo_own);
	
    
	// @cond PRIVATE_DOC
private:
	TRN_PDFView mp_view;
	TRN_PDFDoc temp_doc;

	// PDFView should not be copied
	PDFView(const PDFView&);
	PDFView& operator= (const PDFView&);

	FindTextHandler mp_findtexthandler;
    void* mp_findtextdata;

	static void StaticTRNPDFViewFindTextHandler(TRN_Bool success, TRN_PDFViewSelection selection, void* custom_data);

	//for internal use only
#if defined(__iOS__)
public:
	#include <Impl/PDFView.internal>
#endif // defined(__iOS__)
	// @endcond
};

#include <Impl/PDFView.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPDFView
