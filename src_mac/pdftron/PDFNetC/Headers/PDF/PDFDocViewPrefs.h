//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPDFDocViewPrefs
#define PDFTRON_H_CPPPDFPDFDocViewPrefs

#include <C/PDF/TRN_PDFDocViewPrefs.h>
#include <PDF/Page.h>
#include <PDF/Destination.h>

namespace pdftron { 
	namespace PDF {

/** 
 * PDFDocViewPrefs is a high-level utility class that can be 
 * used to control the way the document is to be presented on 
 * the screen or in print.
 *
 * PDFDocViewPrefs class corresponds to PageMode, PageLayout, and
 * ViewerPreferences entries in the document's catalog. For more 
 * details please refer to section 8.1 'Viewer Preferences' in 
 * PDF Reference Manual.
 */
class PDFDocViewPrefs
{
public:

	/**
	 * A utility method used to set the fist page displayed after 
	 * the document is opened. This method is equivalent to 
	 * PDFDoc::SetOpenAction(goto_action).
	 * 
	 * If OpenAction is not specified the document should be 
	 * opened to the top of the first page at the default magnification 
	 * factor.
	 * 
	 * @param dest A value specifying the page destination to be 
	 * displayed when the document is opened.
	 * 
	 * Example:
	 * @code
	 * Destination dest = Destination::CreateFit(page);
	 * pdfdoc.GetViewPrefs().SetInitialPage(dest);
	 * @endcode 
	 */
	 void SetInitialPage(Destination& dest);

	/**
	 * PageMode specifies how the document should be displayed
	 * when opened: 
	 * 
	 * - e_UseNone Displays document, but neither thumbnails nor 
	 *   bookmarks.
	 * - e_UseThumbs Displays document plus thumbnails.
	 * - e_UseBookmarks Displays document plus bookmarks.
	 * - e_FullScreen Displays document in full-screen viewing mode.
	 * - e_UseOC Displays Optional Content (OC) group panel.
	 * - e_UseAttachments - Displays attachments panel.
	 */
	enum PageMode 
	{
		e_UseNone,
		e_UseThumbs,
		e_UseBookmarks,
		e_FullScreen,
		e_UseOC,
		e_UseAttachments
	};

	/**
	 * Sets PageMode property and change the value of the 
	 * PageMode key in the Catalog dictionary.
	 * 
	 * @param mode New PageMode setting. Default value is e_UseNone.
	 */
	 void SetPageMode(PageMode mode);

	/**
	 * @return The value of currently selected PageMode property.
	 */
	 PageMode GetPageMode();

	/**
	 * PageLayout specifies the page layout to be used when the
	 * document is opened:
	 *
	 * - e_Default PageLayout is not explicitly specified, use user defined
	 * preferred layout.
	 * 
	 * - e_SinglePage Display one page at a time. 
	 * 
	 * - e_OneColumn Display the pages in one-column 
	 * mode.
	 * 
	 * - e_TwoColumnLeft Display the pages in two-column continuous 
	 * mode with first page on left (i.e. all odd numbered pages 
	 * on the left).
	 * 
	 * - e_TwoColumnRight Display the pages in two-column 
	 * continuous mode with first page on right (i.e. all odd 
	 * numbered pages on the right).
	 * 
	 * - e_TwoPageLeft Display the pages two at a time, with 
	 * odd-numbered pages on the left.
	 * 
	 * - e_TwoPageRight Display the pages two at a time, with 
	 * odd-numbered pages on the right.
	 */
	enum PageLayout 
	{
		e_Default,
		e_SinglePage,
		e_OneColumn,
		e_TwoColumnLeft,
		e_TwoColumnRight,
		e_TwoPageLeft,
		e_TwoPageRight
	};

	/**
	 * Sets PageLayout property and change the value of the 
	 * PageLayout key in the Catalog dictionary.
	 * 
	 * @param mode New PageLayout setting. Default value is 
	 * e_SinglePage.
	 */
	 void SetLayoutMode(PageLayout layout);

	/**
	 * @return The value of currently selected PageLayout property.
	 */
	 PageLayout GetLayoutMode();

	/**  
	 * ViewerPref enumeration specifies how various GUI elements 
	 * should behave when the document is opened.
	 * 
	 * - e_HideToolbar A flag specifying whether to hide the 
	 * viewer application's toolbars when the document is active. 
	 * Default value: false.
	 *
	 * - e_HideMenubar A flag specifying whether to hide the viewer 
	 * application's menu bar when the document is active. 
	 * Default value: false.
	 * 
	 * - e_HideWindowUI A flag specifying whether to hide user 
	 * interface elements in the document's window (such as scroll 
	 * bars and navigation controls), leaving only the document's 
	 * contents displayed. Default value: false.
	 *
	 * - e_FitWindow A flag specifying whether to resize the 
	 * document's window to fit the size of the first displayed 
	 * page. Default value: false.
	 *
	 * - e_CenterWindow A flag specifying whether to position the 
	 * document's window in the center of the screen. 
	 * Default value: false.
	 *
	 * - e_DisplayDocTitle A flag specifying whether the window's 
	 * title bar should display the document title taken from the 
	 * Title entry of the document information dictionary. 
	 * If false, the title bar should instead display the name of 
	 * the PDF file containing the document. Default value: false.
	 */
	enum ViewerPref 
	{
		e_HideToolbar, 
		e_HideMenubar, 
		e_HideWindowUI,
		e_FitWindow,
		e_CenterWindow,
		e_DisplayDocTitle,
	};

	/** 
	 * Sets the value of given ViewerPref property. 
	 *
	 * @param pref the ViewerPref property type to modify.
	 * @param value The new value for the property.
	 */
	 void SetPref(ViewerPref pref, bool value);

	/** 
	 * @return the value of given ViewerPref property.
	 * @param pref the ViewerPref property type to query.
	 */
	 bool GetPref(ViewerPref pref);

	/** 
	 * Set the document's page mode, specifying how to display the 
	 * document on exiting full-screen mode. 
	 * 
	 * @param mode PageMode used after exiting full-screen mode.
	 * Default value: e_UseNone.
	 * 
	 * @note This entry is meaningful only if the value of the 
	 * PageMode is set to e_FullScreen; it is ignored otherwise. 
	 */
	 void SetNonFullScreenPageMode(PageMode mode);

	/** 
	 * @return the PageMode used after exiting full-screen mode.
	 * @note This entry is meaningful only if the value of the 
	 * PageMode is set to e_FullScreen; it is ignored otherwise. 
	 */
	 PageMode GetNonFullScreenPageMode();

	/** 
	 * Sets the predominant reading order for text.
	 * 
	 * This flag has no direct effect on the document's contents 
	 * or page numbering but can be used to determine the relative 
	 * positioning of pages when displayed side by side or 
	 * printed n-up. 
	 * 
	 * @param left_to_right - true if the predominant reading 
	 * order for text is from left to right and false if it is 
	 * right to left (including vertical writing systems, such
	 * as Chinese, Japanese, and Korean). 
	 * Default value: left_to_right is true.
	 */
	 void SetDirection(bool left_to_right);

	/** 
	 * @return true is the predominant reading order for text
	 * is left to right, false otherwise. See SetDirection() for 
	 * more information.
	 */
	 bool GetDirection();

	/**
	 * Sets the page boundary representing the area of a page 
	 * to be displayed when viewing the document on the screen.
	 * 
	 * @param box page boundary displayed when viewing the document 
	 * on the screen. By default, PDF viewers will display the 
	 * crop-box.
	 */
	 void SetViewArea(Page::Box box);

	/**
	 * @return the page boundary representing the area of a page 
	 * to be displayed when viewing the document on the screen.
	 */
	 Page::Box GetViewArea();

	/** 
	 * Sets the page boundary to which the contents of a page are 
	 * to be clipped when viewing the document on the screen.
	 * 
	 * @param box screen clip region. The default value is 
	 * page crop-box.
	 */
	 void SetViewClip(Page::Box box);

	/**
	 * @return the page boundary to which the contents of a page 
	 * are to be clipped when viewing the document on the screen.
	 */
	 Page::Box GetViewClip();

	/** 
	 * Sets the page boundary representing the area of a page to 
	 * be rendered when printing the document.
	 * 
	 * @param box printing region. The default value is page 
	 * crop-box.
	 */
	 void SetPrintArea(Page::Box box);

	/**
	 * @return the page boundary representing the area of a page
	 * to be rendered when printing the document.
	 */
	 Page::Box GetPrintArea();

	/** 
	 * Sets the page boundary to which the contents of a page are 
	 * to be clipped when printing the document.
	 * 
	 * @param box printing clip region. The default value is page 
	 * crop-box.
	 */
	 void SetPrintClip(Page::Box box);

	/**
	 * @return the page boundary to which the contents of a page 
	 * are to be clipped when printing the document.
	 */
	 Page::Box GetPrintClip();

	/**
	 * @return document's SDF/Cos 'ViewerPreferences' dictionary 
	 * or NULL if the object is not present.
	 */
	 SDF::Obj GetSDFObj();

	/**
	 * PDFDocViewPrefs constructor. Typically this constructor is 
	 * never used since it is easier to obtain PDFDocViewPrefs using 
	 * PDFDoc.GetViewPrefs()
	 */
	 PDFDocViewPrefs (SDF::Obj tr);
	 PDFDocViewPrefs (const PDFDocViewPrefs&);
	 PDFDocViewPrefs& operator= (const PDFDocViewPrefs&);

	 //added default constructor for swig
	 PDFDocViewPrefs ();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_PDFDocViewPrefs mp_prefs;
	 PDFDocViewPrefs(TRN_PDFDocViewPrefs impl);
#endif
// @endcond
};



#include <Impl/PDFDocViewPrefs.inl>


	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPDFDocViewPrefs
