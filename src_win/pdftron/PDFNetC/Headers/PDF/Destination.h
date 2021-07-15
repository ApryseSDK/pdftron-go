//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFDestination
#define PDFTRON_H_CPPPDFDestination

#include <C/PDF/TRN_Destination.h>
#include <SDF/Obj.h>

namespace pdftron { 
	namespace PDF {

class Page;	 // Forward declaration


/** 
 * A destination defines a particular view of a document, consisting of the 
 * following:
 *
 * - The page of the document to be displayed
 * - The location of the document window on that page
 * - The magnification (zoom) factor to use when displaying the page
 * 
 * Destinations may be associated with Bookmarks, Annotations, and Remote Go-To Actions.
 * 
 * Destination is a utility class used to simplify work with PDF Destinations; 
 * Please refer to section 8.2.1 'Destinations' in PDF Reference Manual for details.
 */
class Destination
{
public:

	/**
	 * View Destination Fit Types:
	 * 
	 * XYZ - Destination specified as upper-left corner point and a zoom factor.
	 * Fit - Fits the page into the window
	 * FitH - Fits the widths of the page into the window
	 * FitV - Fits the height of the page into a window.
	 * FitR - Fits the rectangle specified by its upper-left and lower-right corner points into the window.
	 * FitB - Fits the rectangle containing all visible elements on the page into the window.
	 * FitBH - Fits the width of the bounding box into the window.
	 * FitBV - Fits the height of the bounding box into the window.
	 */
	enum FitType
	{
		e_XYZ,
		e_Fit, 	 
		e_FitH, 	 
		e_FitV, 	 
		e_FitR, 	 
		e_FitB, 	 
		e_FitBH, 	 
		e_FitBV 	 
	};

	/**
	 * Create a new 'XYZ' Destination.
	 *
	 * The new Destination displays the page designated by 'page', with the 
	 * coordinates ('left', 'top') positioned at the top-left corner of the 
	 * window and the contents of the page magnified by the factor 'zoom'. 
	 * A null value for any of the parameters 'left', 'top', or 'zoom' specifies 
	 * that the current value of that parameter is to be retained unchanged. 
	 * A 'zoom' value of 0 has the same meaning as a null value.
	 * the page within the window in the other dimension.
	 * @param page Page object to display
	 * @param left horizontal coordinate of the left edge of the window
	 * @param top vertical coordinate of the top edge of the window
	 * @param zoom amount to zoom the page by
	 */
	 static Destination CreateXYZ(Page page, double left, double top, double zoom);
		
	/**
	 * Create a new 'Fit' Destination.
	 * 
	 * The new Destination displays the page designated by 'page', with its contents
	 * magnified just enough to fit the entire page within the window both
	 * horizontally and vertically. If the required horizontal and vertical
	 * magnification factors are different, use the smaller of the two, centering
	 * the page within the window in the other dimension.
	 * @param page Page object to display
	 */
	 static Destination CreateFit(Page page);

	/**
	 * Create a new 'FitH' Destination.
	 *
	 * The new Destination displays the page designated by 'page', with the 
	 * vertical coordinate 'top' positioned at the top edge of the window and 
	 * the contents of the page magnified just enough to fit the entire width 
	 * of the page within the window.
	 * @param page Page object to display
	 * @param top vertical coordinate of the top edge of the window
	 */
	 static Destination CreateFitH(Page page, double top);

	/**
	 * Create a new 'FitV' Destination.
	 *
	 * The new Destination displays the page designated by 'page', with the 
	 * horizontal coordinate 'left' positioned at the left edge of the window 
	 * and the contents of the page magnified just enough to fit the entire 
	 * height of the page within the window.
	 * @param page Page object to display
	 * @param left horizontal coordinate of the left edge of the window
	 */
	 static Destination CreateFitV(Page page, double left);

	/**
	 * Create a new 'FitR' Destination.
	 *
	 * The new Destination displays the page designated by 'page', with its 
	 * contents magnified just enough to fit the rectangle specified by the 
	 * coordinates 'left', 'bottom', 'right', and 'top' entirely within the 
	 * window both horizontally and vertically. If the required horizontal 
	 * and vertical magnification factors are different, use the smaller of
	 * the two, centering the rectangle within the window in the other 
	 * dimension.
	 * @param page Page object to display
	 * @param left horizontal coordinate of the left edge of the window
	 * @param bottom vertical coordinate of the bottom edge of the window
	 * @param right horizontal coordinate of the right edge of the window
	 * @param top vertical coordinate of the top edge of the window
	 */
	 static Destination CreateFitR(Page page, 
		double left, double bottom,	double right, double top);

	/**
	 * Create a new 'FitB' Destination.
	 *
	 * The new Destination displays the page designated by 'page', with its 
	 * contents magnified just enough to fit its bounding box entirely within 
	 * the window both horizontally and vertically. If the required 
	 * horizontal and vertical magnification factors are different, use the 
	 * smaller of the two, centering the bounding box within the window in 
	 * the other dimension.
	 * @param page Page object to display
	 */
	 static Destination CreateFitB(Page page);

	/**
	 * Create a new 'FitBH' Destination.
	 *
	 * The new Destination displays the page designated by 'page', with 
	 * the vertical coordinate 'top' positioned at the top edge of the window 
	 * and the contents of the page magnified just enough to fit the entire 
	 * width of its bounding box within the window.
	 * @param page Page object to display
	 * @param top vertical coordinate of the top edge of the window
	 */
	 static Destination CreateFitBH(Page page, double top);

	/**
	 * Create a new 'FitBV' Destination.
	 *
	 * The new Destination displays Display the page designated by 'page', 
	 * with the horizontal coordinate 'left' positioned at the left edge of 
	 * the window and the contents of the page magnified just enough to fit 
	 * the entire height of its bounding box within the window.
	 * @param page Page object to display
	 * @param left horizontal coordinate of the left edge of the window
	 */
	 static Destination CreateFitBV(Page page, double left);

	/**
	 * Create a Destination and initialize it using given Cos/SDF object.
	 * 
	 * @param dest - a low-level (SDF/Cos) destination object. The low-level 
	 * destination can be either a named destination (i.e. a Name or a String)
	 * or an explicit destination (i.e. an Array Obj). Please refer to section 
	 * 8.2.1 'Destinations' in PDF Reference Manual for more details.
	 *
	 * @note The constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 * 
	 * @note Named destinations (in case 'dest' is a Name or a String) are 
	 * automatically resolved to the explicit destination. If the name can't 
	 * be resolved to the explicit destination dest.IsValid() will return false.
	 */
	 Destination (SDF::Obj dest);

	/**
	 * Copy constructor
	 */
	 Destination (const Destination& d);

	/**
	 * Assignment operator
	 */
	 Destination& operator=(const Destination& d);

	/**
	 * @return True if this is a valid Destination and can be resolved, false otherwise. 
	 *
	 * @note If this method returns false the underlying SDF/Cos object is null and 
	 * the Action object should be treated as null as well.
	 */ 	
	 bool IsValid() const;

	/**
	 * @return destination's FitType.
	 * @exception An Exception is thrown if this is not a valid Destination. 
	 */ 
	 FitType GetFitType();

	/**
	 * @return the Page that this destination refers to.
	 * @exception An Exception is thrown if this is not a valid Destination. 
	 */ 
	 Page GetPage();

	/**
	 * Modify the destination so that it refers to the new 'page' as the destination page.
	 * 
	 * @param page The new page associated with this Destination.
	 * @exception An Exception is thrown if this is not a valid Destination. 
	 */ 
	 void SetPage(Page page);

	/**
	 * @return the object to the underlying SDF/Cos object. 
	 * The returned SDF/Cos object is an explicit destination (i.e. the Obj is either 
	 * an array defining the destination, using the syntax shown in Table 8.2 in PDF 
	 * Reference Manual), or a dictionary with a 'D' entry whose value is such an 
	 * array. The latter form allows additional attributes to be associated with 
	 * the destination
	 */
	 SDF::Obj GetSDFObj () const;

	/**
	 * @return the explicit destination SDF/Cos object. This is always an Array 
	 * as shown in Table 8.2 in PDF Reference Manual.
	 * 
	 * @exception An Exception is thrown if this is not a valid Destination. 
	 */ 
	 SDF::Obj GetExplicitDestObj ();

	 Destination(TRN_Destination impl);

	 // added default constructor for swig;
	 Destination();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_Destination mp_dest;
#endif
// @endcond
};


	};	// namespace PDF
};	// namespace pdftron

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFDestination
