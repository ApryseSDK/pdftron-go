//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFElementBuilder
#define PDFTRON_H_CPPPDFElementBuilder

#include <PDF/Page.h>
#include <PDF/Element.h>
#include <Common/Matrix2D.h>
#include <PDF/Image.h>
#include <PDF/Shading.h>
#include <PDF/PDFDoc.h>
#include <PDF/ShapedText.h>
#include <C/PDF/TRN_ElementBuilder.h>

namespace pdftron { 
	namespace PDF {


/**
 * ElementBuilder is used to build new PDF::Elements (e.g. image, text, path, etc) 
 * from scratch. In conjunction with ElementWriter, ElementBuilder can be used to create
 * new page content.
 * 
 * @note Analogous to ElementReader, every call to ElementBuilder.Create? method destroys 
 * the Element currently associated with the builder and all previous Element pointers are 
 * invalidated. 
 * 
 * @note For C++ developers. Analogous to ElementReader, ElementBuilder is the owner of
 * all Element objects it creates. 
 */
class ElementBuilder
{
public:

	 ElementBuilder();
	 ~ElementBuilder();

	/**
	 * The function sets the graphics state of this Element to the given value. 
	 * If 'gs' parameter is not specified or is NULL the function resets the 
	 * graphics state of this Element to the default graphics state (i.e. the 
	 * graphics state at the beginning of the display list).
	 * 
	 * The function can be used in situations where the same ElementBuilder is used 
	 * to create content on several pages, XObjects, etc. If the graphics state is not
	 * Reset() when moving to a new display list, the new Element will have the same 
	 * graphics state as the last Element in the previous display list (and this may 
	 * or may not be your intent).
	 * 
	 * Another use of Reset(gs) is to make sure that two Elements have the graphics 
	 * state. 
	 * @param gs GState (graphics state) object. If NULL or unspecified, resets graphics state to default.
	 */
	 void Reset(GState gs = 0);

	// Image Element ------------------------------------------------

	/**
	 * Create a content image Element out of a given document Image.
	 * @param img the given image.
	 */
	 Element CreateImage(Image& img);

	/**
	 * Create a content image Element out of a given document Image.
	 * @param img the given image.
	 * @param mtx the image transformation matrix.
	 */
	 Element CreateImage(Image& img, const Common::Matrix2D& mtx);

	/**
	 * Create a content image Element out of a given document Image with 
	 * the lower left corner at (x, y), and scale factors (hscale, vscale).
	 * @param img the given image.
	 * @param x The horizontal x position to place the lower left corner of the image
	 * @param y The vertical x position to place the lower left corner of the image
	 * @param hscale The horizontal scale of the image
	 * @param vscale The vertical scale of the image
	 */
	 Element CreateImage(Image& img, double x, double y, double hscale, double vscale);

	/**
	 * Create e_group_begin Element (i.e. 'q' operator in PDF content stream). 
	 * The function saves the current graphics state.
	 */
	 Element CreateGroupBegin();

	/**
	 * Create e_group_end Element (i.e. 'Q' operator in PDF content stream). 
	 * The function restores the previous graphics state.
	 */
	 Element CreateGroupEnd();

	/**
	 * @param sh A Shading object. Shading objects represent a flat interface around 
	 * all PDF shading types (e_function_shading, e_axial_shading, etc.)
	 * Create a shading Element.
	 */
	 Element CreateShading(Shading& sh);

	/**
	 * Create a Form XObject Element.
	 * @param form a Form XObject content stream
	 */
	 Element CreateForm(SDF::Obj form);

	/**
	 * Create a Form XObject Element using the content of the existing page. 
	 * This method assumes that the XObject will be used in the same 
	 * document as the given page. If you need to create the Form XObject 
	 * in a different document use CreateForm(Page, Doc) method.
	 *
	 * @param page A page used to create the Form XObject.
	 */
	 Element CreateForm(Page page);

	/**
	 * Create a Form XObject Element using the content of the existing page.
	 * Unlike CreateForm(Page) method, you can use this method to create form 
	 * in another document.
	 * 
	 * @param page A page used to create the Form XObject.
	 * @param doc Destination document for the Form XObject.
	 */
	 Element CreateForm(Page page, class PDFDoc& doc);

	/**
	 * Start a text block ('BT' operator in PDF content stream). 
	 * The function installs the given font in the current graphics state.
	 * @param font font to set the text in the text block to
	 * @param font_sz size to set the text in the text block to
	 */
	 Element CreateTextBegin(Font font, double font_sz);

	/**
	 * Start a text block ('BT' operator in PDF content stream). 
	 */
	 Element CreateTextBegin();

	/**
	 * Ends a text block.
	 */
	 Element CreateTextEnd();

	/**
	 * Create a text run using the given font.
	 * @note a text run can be created only within a text block
	 */
	 Element CreateTextRun(const char* text_data, Font font, double font_sz);
#ifndef SWIG
	 Element CreateTextRun(const char* text_data, UInt32 text_data_sz, Font font, double font_sz);
	 Element CreateTextRun(const UChar* text_data, UInt32 text_data_sz, Font font, double font_sz);
#endif

	/**
	 * Create a new text run.
	 * @note a text run can be created only within a text block
	 * @note you must set the current Font and font size before calling this function.
	 */
	 Element CreateTextRun(const char* text_data);
#ifndef SWIG
	 Element CreateTextRun(const char* text_data, UInt32 text_data_sz);
	 Element CreateTextRun(const UChar* text_data, UInt32 text_data_sz);
#endif

	/**
	* Create a new Unicode text run.
	*
	* @param text_data pointer to Unicode text
	* @param text_data_sz number of characters (not bytes) in text_data
	*
	* @note you must set the current Font and font size before calling this function 
	* and the font must be created using Font::CreateCIDTrueTypeFont() method.
	* 
	* @note a text run can be created only within a text block
	*/
	 Element CreateUnicodeTextRun(const Unicode* text_data, UInt32 text_data_sz);

	/**
	* Create a new text run from shaped text.
	* Shaped Text can be created with an approriate Font, using the Font::GetShapedText() method. 
	*
	* @param text_data the shaped text data
	*
	* @note you must set the current Font and font size before calling this function 
	* and the font must be created using Font::CreateCIDTrueTypeFont() method, and should
	* be the same font used to generate the shaped text content.
	*
	* @note For best results, the font should be encoded using the e_Indices encoding scheme.
	* 
	* @note a text run can be created only within a text block
	*/
	 Element CreateShapedTextRun(ShapedText text_data);

	/**
	 * Create e_text_new_line Element (i.e. a Td operator in PDF content stream).
	 * Move to the start of the next line, offset from the start of the current 
	 * line by (dx , dy). dx and dy are numbers expressed in unscaled text space 
	 * units.
	 * @param dx The horizontal x offset from the start of the current line
	 * @param dy The vertical y offset from the start of the current line
	 * @return the path Element
	 */
	 Element CreateTextNewLine(double dx, double dy);

	/**
	 * Create e_text_new_line Element (i.e. a T* operator in PDF content stream).
	 * @return the path Element
	 */
	 Element CreateTextNewLine();

	// Path Element -------------------------------------------------

	/**
	 * Create a path Element using given path segment data
	 * @return the path Element
	 */
	 Element CreatePath(const std::vector<double>& points, const std::vector<unsigned char>& seg_types);

#ifndef SWIG
	 Element CreatePath(const double* points, int point_count, const char* seg_types, int seg_types_count);
#endif

	/**
	 * Create a rectangle path Element.
	 * 
	 * @param x The horizontal coordinate of the lower left corner of the rectangle.
	 * @param y The vertical coordinate of the lower left corner of the rectangle.
	 * @param width The width of the rectangle.
	 * @param height The height of the rectangle.
	 * @return the path Element
	 */
	 Element CreateRect(double x, double y, double width, double height);

	/**
	* Create an ellipse (or circle, if width == height) path Element.
	* 
	* @param x The horizontal x coordinate of the ellipse center.
	* @param y The vertical y coordinate of the ellipse center.
	* @param width The width of the ellipse rectangle.
	* @param height The height of the ellipse rectangle.
	* @return the path Element
	*/
	 Element CreateEllipse(double x, double y, double width, double height);

	/**
	 * Starts building a new path Element that can contain an arbitrary sequence 
	 * of lines, curves, and rectangles.
	 */
	 void PathBegin();

	/**
	 * Finishes building of the path Element. 
	 * @return the path Element
	 */
	Element PathEnd();

	/**
	 * Set the current point.
	 * @param x The horizontal x component of the point
	 * @param y The vertical y component of the point
	 */
	 void MoveTo(double x, double y);

	/**
	 * Draw a line from the current point to the given point.
	 * @param x The horizontal x component of the goal point
	 * @param y The vertical y component of the goal point
	 */
	 void LineTo(double x, double y);

	/**
	 * Draw a Bezier curve from the current point to the given point (x2, y2) using 
	 * (cx1, cy1) and (cx2, cy2) as control points.
	 * @param cx1 The x component of the first control point
	 * @param cy1 The y component of the first control point
	 * @param cx2 The x component of the second control point
	 * @param cy2 The y component of the second control point
	 * @param x2 The horizontal x component of the goal point
	 * @param y2 The vertical y component of the goal point
	 */
	 void CurveTo(double cx1, double cy1, double cx2, double cy2, double x2, double y2);

	/**
	 * Draw an arc with the specified parameters (lower left corner, width, height and angles).
	 *
	 * @param x The horizontal x coordinate of the lower left corner of the ellipse encompassing rectangle
	 * @param y The horizontal y coordinate of the lower left corner of the ellipse encompassing rectangle
	 * @param width overall width of the full ellipse (not considering the angular extents).
	 * @param height overall height of the full ellipse (not considering the angular extents).
	 * @param start starting angle of the arc in degrees
	 * @param extent angular extent of the arc in degrees
	 */
	void ArcTo(double x, double y, double width, double height, double start, double extent);

	/**
	 * Draw an arc from the current point to the end point.
	 *
	 * @param xr x radius for the arc
	 * @param yr y radius for the arc
	 * @param rx x-axis rotation in radians
	 * @param isLargeArc indicates if smaller or larger arc is chosen
	 *		1 - one of the two larger arc sweeps is chosen
	 *		0 - one of the two smaller arc sweeps is chosen
	 * @param sweep direction in which arc is drawn (1 - clockwise, 0 - counterclockwise)
	 * @param endX x coordinate of end point
	 * @param endY y coordinate of end point
	 *
	 * @note The Arc is defined the same way as it is specified by SVG or XPS standards. For
	 *		further questions please refer to the XPS or SVG standards.
	 */
	void ArcTo(double xr, double yr,
			   double rx,
			   bool isLargeArc,
			   bool sweep,
			   double endX, double endY);

	/**
	* Add an ellipse (or circle, if rx == ry) to the current path as a complete subpath.
	* Setting the current point is not required before using this function.
	* 
	* @param x The x coordinate of the ellipse center.
	* @param y The y coordinate of the ellipse center.
	* @param width The x radii of the ellipse.
	* @param height The y radii of the ellipse.
	*/
	void Ellipse(double x, double y, double width, double height);

	/**
	 * Add a rectangle to the current path as a complete subpath. 
	 * Setting the current point is not required before using this function.
	 *
	 * @param x The x coordinate of the lower left corner of the rectangle.
	 * @param y The y coordinate of the lower left corner of the rectangle.
	 * @param width The width of the rectangle.
	 * @param height The height of the rectangle.
	 */
	 void Rect(double x, double y, double width, double height);

	/**
	 * Closes the current subpath.
	 */
	 void ClosePath();

	/**
	 *  Create e_marked_content_begin element with an inline property dictionary (i.e. BDC operator in PDF content stream).
	 * 
	 * @param tag the tag entry for this element.
	 * @return the marked content begin element.
	 * @note: The inline property dictionary can be accessed and edited using element.GetMCPropertyDict()
	 */
	Element CreateMarkedContentBeginInlineProperties(const char* tag);
	
	/**
	 * Create e_marked_content_begin element with an associated property dictionary (i.e. BMC or BDC operator in PDF content stream).
	 * 
	 * @param tag the tag entry for this element.
	 * @param property_dict the property dictionary.
	 * @return the marked content begin element.
	 */
	Element CreateMarkedContentBegin(const char* tag, SDF::Obj property_dict);
	
	/**
	 * Create e_marked_content_end element (i.e. EMC operator in PDF content stream).
	 * 
	 * @return the marked content end element.
	 */
	Element CreateMarkedContentEnd();
	
	/**
	 * Create e_marked_content_point element with an inline property dictionary (i.e. DP operator in PDF content stream).
	 * 
	 * @param tag the tag entry for this element.
	 * @return the marked content point element.
	 * @note: The inline property dictionary can be accessed and edited using element.GetMCPropertyDict()
	 */
	Element CreateMarkedContentPointInlineProperties(const char* tag);
	
	/**
	 * Create e_marked_content_point element with an associated property dictionary (i.e. MP or DP operator in PDF content stream).
	 * 
	 * @param tag the tag entry for this element.
	 * @param property_dict the property dictionary.
	 * @return the marked content point element.
	 */
	Element CreateMarkedContentPoint(const char* tag, SDF::Obj property_dict);

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 TRN_ElementBuilder mp_builder;
#endif
private:
	// ElementBuilder should not be copied
	ElementBuilder(const ElementBuilder&);
	ElementBuilder& operator= (const ElementBuilder&);
// @endcond
};


#include <Impl/ElementBuilder.inl>

	};	// namespace PDF
};	// namespace pdftron


#endif // PDFTRON_H_CPPPDFElementBuilder
