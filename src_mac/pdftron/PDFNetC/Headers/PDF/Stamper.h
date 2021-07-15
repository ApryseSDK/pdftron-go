//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFStamper
#define PDFTRON_H_CPPPDFStamper

#include <C/PDF/TRN_Stamper.h>
#include <PDF/PDFDoc.h>
#include <PDF/Image.h>
#include <PDF/Page.h>
#include <Common/Common.h>
#include <SDF/Obj.h>
#include <PDF/PageSet.h>

namespace pdftron{
	namespace PDF{



/**
 * Stamper is a utility class that can be used to stamp PDF pages with text, images, 
 * or vector art (including another PDF page) in only a few lines of code.
 * 
 * Although Stamper is very simple to use compared to ElementBuilder/ElementWriter 
 * it is not as powerful or flexible. In case you need full control over PDF creation
 * use ElementBuilder/ElementWriter to add new content to existing PDF pages as 
 * shown in the ElementBuilder sample project.
 */
class Stamper
{
public:

	enum SizeType
	{
		e_relative_scale = 1,
		e_absolute_size = 2,
		e_font_size = 3
	};

	enum HorizontalAlignment
	{
		e_horizontal_left = -1,
		e_horizontal_center = 0,
		e_horizontal_right = 1
	};

	enum VerticalAlignment
	{
		e_vertical_bottom = -1,
		e_vertical_center = 0,
		e_vertical_top = 1 
	};

	enum TextAlignment
	{
		e_align_left = -1,
		e_align_center = 0,
		e_align_right = 1
	};
	
	/**
	 * Stamper constructor
	 *
	 * @param size_type Specifies how the stamp will be sized
	 *		-e_relative_scale: Stamp size is relative to the size of the crop box of
	 *		the destination page. 'a' is a percentage of the width of the crop box 
	 *		(e.g.: 0.5 is 50% of the width of the crop box) 'b' is a percentage of the
	 *		height of the crop box. If 'a' <= 0 then only b will be used. If 'b' <= 0 
	 *		then only 'a' will be used.
	 *
	 *		-e_absolute_scale: Stamp size is explicitly set. 'a' sets the width of
	 *		of the stamp's bounding box. 'b' sets the height of the stamp's bounding
	 *		box. The width and height are constant, regardless of the size of the 
	 *		destination page's bounding box. 
	 *
	 *		-e_font_size: This type only applies to text stamps. 'a' sets the font
	 *		size. 'b' is ignored. 
	 * @param a @see size_type
	 * @param b @see size_type
	 */
	Stamper(SizeType size_type, double a, double b);

	/** 
	 * Stamper default destructor
	 */
	~Stamper();

	/**
	 * Stamps an image to the given destination document at the set of page numbers
	 *
	 * @param dest_doc The document being stamped
	 * @param src_img The image that is being stamped to the document
	 * @param dest_pages The set of pages in the document being stamped
	 */
	void StampImage(PDFDoc& dest_doc, Image src_img, const PageSet& dest_pages);

	/**
	 * Stamps a PDF page to the given destination document at the set of page numbers
	 *
	 * @param dest_doc The document being stamped
	 * @param src_page The page that is being stamped to the document
	 * @param dest_pages The set of pages in the document being stamped
	 */
	void StampPage(PDFDoc& dest_doc, Page src_page, const PageSet& dest_pages);

	/**
	 * Stamps text to the given destination document at the set of page numbers
	 *
	 * @param dest_doc The document being stamped
	 * @param src_txt The image that is being stamped to the document
	 * @param dest_pages The set of pages in the document being stamped
	 */
	void StampText(PDFDoc& dest_doc, const UString& src_txt, const PageSet& dest_pages);

	/**
	 * 
	 * Defines the font of the stamp. (This only applies to text-based stamps)
	 * 
	 * @param font The font of the text stamp
	 */
	void SetFont(Font font);


	/**
	 * Sets the font color (This only effects text-based stamps)
	 * 
	 * @param font_color The color of the font
	 */
	void SetFontColor(const ColorPt& color);

	/**
	 * Sets the opacity value for the stamp
	 *
	 * @param opacity The opacity value of the stamp
	 */
	void SetOpacity(double opacity);


	/**
	 * Rotates the stamp by the given number of degrees
	 * 
	 * @param rotation Rotation in degrees
	 */
	void SetRotation(double rotation);


	/**
	 * Specifies if the stamp is to be stamped in the background or the foreground.
	 * 
	 * @param background A flag specifying if the stamp should be added 
	 * as a background layer to the destination page
	 */
	void SetAsBackground(bool background);

	/**
	 * Specifies if the stamp is to be stamped as an annotation.
	 * 
	 * @param annotation A flag specifying if the stamp should be added 
	 * as an annotation or not
	 *
	 * @note Stamps created with this setting do not work with SetAsBackground,
	 * HasStamps, and DeleteStamps, if annotation is true.
	 */
	void SetAsAnnotation(bool annotation);

	/**
	 * @param on_screen Specifies if the watermark will be displayed on screen
	 */
	void ShowsOnScreen(bool on_screen);

	/**
	 * @param on_print Specifies if the watermark will be displayed when printed
	 */
	void ShowsOnPrint(bool on_print);

	/**
	 * Sets the horizontal and vertical position of the stamp. 
	 *
	 * @see SetAlignment
	 *
	 * @param horizontal_distance Horizontal distance from left, right or center of crop box
	 * @param vertical_distance Vertical distance from top, bottom or center of crop box
	 * @param use_percentage If true, horizontal_distance is a percentage of the crop
	 * box width (e.g.: 0.5 is 50% of the width of the crop box) and vertical_distance
	 * is a percentage of the crop box height. If false, horizontal_distance and
	 * vertical_distance is measured in points.
	 */
	void SetPosition(double horizontal_distance, double vertical_distance, bool use_percentage=false);

	/**
	 * Sets the alignment for the x and y variables.
	 *
	 * @see SetPosition
	 *
	 * @param horizontal_alignment Can be set to e_left, e_center or e_right
	 *		e_left:	horizontal_distance measures the distance between the left edge of the stamp's
	 *			bounding box and the left edge of the crop box
	 *		e_center: horizontal_distance measures the distance between the horizontal bisector of the
	 *			stamp's bounding box and the horizontal bisector of the crop box
	 *		e_right: horizontal_distance measures the distance between the right edge of the stamp's
	 *			bounding box and the right edge of the crop box
	 *		
	 * @param vertical_alignment Can be set to e_top, e_center or e_bottom
	 *		e_bottom: vertical_distance measures the distance between the bottom edge of the stamp's
	 *			bounding box and the bottom edge of the crop box
	 *		e_center: vertical_distance measures the distance between the vertical bisector of the
	 *			stamp's bounding box and the vertical bisector of the crop box
	 *		e_top: vertical_distance measures the distance between the top edge of the stamp's
	 *			bounding box and the top edge of the crop box
	 */
	void SetAlignment(HorizontalAlignment horizontal_alignment, VerticalAlignment vertical_alignment);

	/**
	 * Sets the text alignment (note: this only applies to text watermarks)
	 *
	 * @param text_alignment Enumerator for text alignment (e_left, e_center, e_right)
	 */
	void SetTextAlignment(TextAlignment text_alignment);

	/** 
	 * Sets the size of the stamp 
	 *
	 * @param size_type Specifies how the stamp will be sized
	 *		-e_relative_scale: Stamp size is relative to the size of the crop box of
	 *		the destination page. 'a' is a percentage of the width of the crop box 
	 *		(e.g.: 0.5 is 50% of the width of the crop box) 'b' is a percentage of the
	 *		height of the crop box. If 'a' <= 0 then only b will be used. If 'b' <= 0 
	 *		then only 'a' will be used.
	 *
	 *		-e_absolute_scale: Stamp size is explicitly set. 'a' sets the width of
	 *		of the stamp's bounding box. 'b' sets the height of the stamp's bounding
	 *		box. The width and height are constant, regardless of the size of the 
	 *		destination page's bounding box. 
	 *
	 *		-e_font_size: This type only applies to text stamps. 'a' sets the font
	 *		size. 'b' is ignored.
	 * @param a Generally the horizontal component of the size. See size_type for more details.
	 * @param b Generally the vertical component of the size. See size_type for more details.
	 */
	void SetSize(SizeType size_type, double a, double b);

	/**
	 * Deletes PDFTron stamps from document at given page numbers
	 *
	 * @param doc The document to delete stamps from
	 * @param page_set The set of pages to delete stamps from
	 */
	static void DeleteStamps(PDFDoc& doc, const PageSet& page_set);

	/**
	 * Returns true if the given set of pages has at least one stamp
	 *
	 * @param doc The document that's being checked
	 * @param page_set The set of page that's being checked
	 */
	static bool HasStamps(PDFDoc& doc, const PageSet& page_set);

	/**
	 * Frees the native memory of the object.
	 */
	 void Destroy();


// @cond PRIVATE_DOC

#ifndef SWIGHIDDEN
	Stamper(TRN_Stamper impl);
	TRN_Stamper mp_impl;
#endif
// @endcond


};

#include <Impl/Stamper.inl>

	}
}

#endif // PDFTRON_H_CPPPDFStamper
