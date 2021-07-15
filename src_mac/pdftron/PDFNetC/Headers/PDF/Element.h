//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.	 
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFElement
#define PDFTRON_H_CPPPDFElement

#include <SDF/Obj.h>
#include <PDF/GState.h>
#include <PDF/Rect.h>
#include <PDF/CharData.h> 
#include <PDF/PathData.h> 
#include <PDF/Struct/SElement.h>
#include <C/PDF/TRN_Element.h>

namespace pdftron { 
	namespace PDF {


/**
 * Element is the abstract interface used to access graphical elements used to build the 
 * display list. 
 *  
 * Just like many other classes in PDFNet (e.g. ColorSpace, Font, Annot, etc), Element
 * class follows the composite design pattern. This means that all Elements are 
 * accessed through the same interface, but depending on the Element type (that can be 
 * obtained using GetType()), only methods related to that type can be called.
 * For example, if GetType() returns e_image, it is illegal to call a method specific to 
 * another Element type (i.e. a call to a text specific GetTextData() will throw an 
 * Exception).
 */
class Element 
{
public:
	// Common Methods ---------------------------------------------------------------

	enum Type
	{
		e_null,                  // undefined element type
		e_path,                  // path object
		e_text_begin,            // marks the beginning of a text container
		e_text,                  // text object within a text container
		e_text_new_line,         // indicates the start of the new text line
		e_text_end,              // marks the end of text container
		e_image,                 // image XObject
		e_inline_image,          // inline image object
		e_shading,               // shading object
		e_form,                  // a form XObject 
		e_group_begin,           // push graphics state operator (q)
		e_group_end,             // pop graphics state operator (Q)
		e_marked_content_begin,  // marks the beginning of marked content sequence (BMC, BDC)
		e_marked_content_end,    // marks the end of marked content sequence (EMC)
		e_marked_content_point   // designate a marked-content point (MP, DP) 
	};

	Element();
	Element(const Element& c);
	Element& operator=(const Element&c);
	operator bool () { return mp_elem!=0;}

	/**
	 * @return the current element type.
	 */
	Type GetType();

	/**
	 * @return GState of this Element
	 */
	GState GetGState();

	/**
	 * @return Current Transformation Matrix (CTM) that maps coordinates to the 
	 * initial user space.
	 */ 
	Common::Matrix2D GetCTM();

	/**
	 * Obtains the bounding box for a graphical element.
	 * 
	 * Calculates the bounding box for a graphical element (i.e. an Element that belongs 
	 * to one of following types: e_path, e_text, e_image, e_inline_image, e_shading e_form).
	 * The returned bounding box is guaranteed to encompass the Element, but is not guaranteed 
	 * to be the smallest box that could contain the element. For example, for Bezier curves 
	 * the bounding box will enclose all control points, not just the curve itself.
	 * 
	 * @return true if this is a graphical element and the bounding box can be calculated;
	 * false for non-graphical elements which don't have bounding box.
	 * 
	 * @param out_bbox (Filled by the method) A reference to a rectangle specifying the 
	 * bounding box of Element (a rectangle that surrounds the entire element). The coordinates 
	 * are represented in the default PDF page coordinate system and are using units called points 
	 * ( 1 point = 1/72 inch =  2.54 /72 centimeter). The bounding box already accounts for the 
	 * effects of current transformation matrix (CTM), text matrix, font size, and other properties 
	 * in the graphics state. If this is a non-graphical element (i.e. the method returns false) the 
	 * bounding box is undefined.
	 */ 
	Rect GetBBox();

#ifndef SWIG
	bool GetBBox(Rect& out_bbox);
#endif
	
	/**
	 * @return Parent logical structure element (such as 'span' or 'paragraph').
	 * If the Element is not associated with any structure element, the returned
	 * SElement will not be valid (i.e. selem.IsValid() -> false).
	 */
	Struct::SElement GetParentStructElement();

	/**
	 * @return Marked Content Identifier (MCID) for this Element or 
	 * a negative number if the element is not assigned an identifier/MCID.
	 * 
	 * Marked content identifier can be used to associate an Element with 
	 * logical structure element that refers to the Element.
	 */
	int GetStructMCID();

	/** 
	 * @return true if this element is visible in the optional-content 
	 * context (OCG::Context). The method considers the context's current OCMD stack, 
	 * the group ON-OFF states, the non-OC drawing status, the drawing and enumeration mode, 
	 * and the intent. 
	 * 
	 * When enumerating page content, OCG::Context can be passed as a parameter in 
	 * ElementReader.Begin() method. When using PDFDraw, PDFRasterizer, or PDFView class to 
	 * render PDF pages use PDFDraw::SetOCGContext() method to select an OC context.
	 */
	bool IsOCVisible();
	
	// Path Element (e_path) Get Methods --------------------------------------------

	/** 
	 * @return true if the current path element is a clipping path and should be added 
	 * to clipping path stack.
	 */
	bool IsClippingPath();

	/** 
	 * @return true if the current path element should be stroked
	 */
	bool IsStroked();

	/** 
	 * @return true if the current path element should be filled
	 */
	bool IsFilled();
	
	/** 
	 * @return true if the current path should be filled using non-zero winding rule, 
	 * or false if the path should be filled using even-odd rule.
	 * 
	 * According non-zero winding rule, you can determine whether a test point is inside or 
	 * outside a closed curve as follows: Draw a line from a test point to a point that 
	 * is distant from the curve. Count the number of times the curve crosses the test 
	 * line from left to right, and count the number of times the curve crosses the test 
	 * line from right to left. If those two numbers are the same, the test point is 
	 * outside the curve; otherwise, the test point is inside the curve. 
	 * 
	 * According to even-odd rule, you can determine whether a test point is inside 
	 * or outside a closed curve as follows: Draw a line from the test point to a point 
	 * that is distant from the curve. If that line crosses the curve an odd number of 
	 * times, the test point is inside the curve; otherwise, the test point is outside 
	 * the curve. 
	 */
	 bool IsWindingFill();

	/** 
	 * @return true if the current clip path is using non-zero winding rule, or false 
	 * for even-odd rule.
	 */
	 bool IsClipWindingFill();

	/** 
	 * Returns the PathData stored by the path element.
	 * 
	 * @return The PathData which contains the operators and corresponding point data.
	 */
	 PathData GetPathData() const;
	 
	// Path Element (e_path) Set Methods --------------------------------------------
	 
	/**
	 * Set the PathData of this element. The PathData contains the array of points
	 * stored by the element and the array of path segment types.
	 */
	 void SetPathData(const PathData& data);

	/** 
	 * Indicate whether the path is a clipping path or non-clipping path 
	 * @param clip true to set path to clipping path. False for non-clipping path.
	 */
	 void SetPathClip(bool clip);

	/** 
	 * Indicate whether the path should be stroked
	 * @param stroke true to set path to be stroked. False for no stroke path.
	 */
	 void SetPathStroke(bool stroke);

	/** 
	 * Indicate whether the path should be filled
	 * @param fill true to set path to be filled. False for no fill path.
	 */
	 void SetPathFill(bool fill);

	/** 
	 * Sets path's fill rule. 
	 * @param winding_rule if winding_rule is true path will be filled using non-zero 
	 * winding fill rule, otherwise even-odd fill will be used.
	 */
	 void SetWindingFill(bool winding_rule);

	/** 
	 * Sets clipping path's fill rule. 
	 * @param winding_rule if winding_rule is true clipping should use non-zero 
	 * winding rule, or false for even-odd rule.
	 */
	 void SetClipWindingFill(bool winding_rule);

	// XObject Element (e_image or e_form_begin) Methods ----------------------------

	/** 
	 * @return the SDF object of the Image/Form object.
	 */
	 SDF::Obj GetXObject();


	// Image (e_image and e_inline_image) Element Methods ---------------------------

	/** 
	 * @return A stream (filter) containing decoded image data 
	 */
	 Filters::Filter GetImageData() const;

	/** 
	 * @return the size of image data in bytes
	 */
	 int GetImageDataSize() const;

	/**
	 * Convert PDF image to GDI+ Bitmap.
	 * 
	 * @return GDI+ bitmap from this image. PDFNet creates a GDI+ 
	 * bitmap that closely matches the original image in terms
	 * of the image depth and the number of color channels. PDF color 
	 * spaces that do not have a counterpart in GDI+ are converted 
	 * to RGB.
	 * 
	 * @note This method is available only on Windows platforms.
	 */
	#if defined(_WIN32)
	 Gdiplus::Bitmap* GetBitmap() const;
	#endif

	/** 
	 * @return The SDF object representing the color space in which image
	 * are specified or NULL if the image is an image mask 
	 * 
	 * The returned color space may be any type of color space except Pattern.
	 */
	 ColorSpace GetImageColorSpace() const;

	/** 
	 * @return the width of the image, in samples.
	 */
	 int GetImageWidth() const;

	/** 
	 * @return the height of the image, in samples.
	 */
	 int GetImageHeight() const;

	/** 
	 * @return Decode array or NULL if the parameter is not specified. A decode object is an 
	 * array of numbers describing how to map image samples into the range of values 
	 * appropriate for the color space of the image. If ImageMask is true, the array must be 
	 * either [0 1] or [1 0]; otherwise, its length must be twice the number of color 
	 * components required by ColorSpace. Default value depends on the color space, 
	 * See Table 4.36 in PDF Ref. Manual.
	 */
	 SDF::Obj GetDecodeArray() const;

	/** 
	 * @return the number of bits used to represent each color component. Only a 
	 * single value may be specified; the number of bits is the same for all color 
	 * components. Valid values are 1, 2, 4, and 8. 
	 */
	 int GetBitsPerComponent() const;

	/** 
	 * @return the number of color components per sample.
	 */
	 int GetComponentNum() const;


	/** 
	 * @return a boolean indicating whether the inline image is to be treated as an image mask.
	 */
	 bool IsImageMask() const;

	/** 
	 * @return a boolean indicating whether image interpolation is to be performed.
	 */
	 bool IsImageInterpolate() const; 

	/** 
	 * @return an image XObject defining an image mask to be applied to this image (See
	 * 'Explicit Masking', 4.8.5), or an array specifying a range of colors
	 * to be applied to it as a color key mask (See 'Color Key Masking'). 
	 * 
	 * If IsImageMask() return true, this method will return NULL.
	 */
	 SDF::Obj GetMask() const; 

	/** 
	 * @return The color rendering intent to be used in rendering the image.
	 */
	 GState::RenderingIntent GetImageRenderingIntent() const;

	// Text Element (e_text) Get Methods --------------------------------------------

	/** 
	 * @return a pointer to Unicode string for this text Element. The 
	 * function maps character codes to Unicode array defined by Adobe 
	 * Glyph List (http://partners.adobe.com/asn/developer/type/glyphlist.txt).
	 * 
	 * @note In PDF text can be encoded using various encoding schemes 
	 * and in some cases it is not possible to extract Unicode encoding. 
	 * If it is not possible to map charcode to Unicode the function will 
	 * map a character to undefined code, 0xFFFD. This code is defined in 
	 * private Unicode range.
	 * 
	 * @note If you would like to map raw text to Unicode (or some other encoding) 
	 * yourself use CharIterators returned by CharBegin()/CharEnd() and 
	 * PDF::Font code mapping methods.
	 *
	 * @note The string owner is the current element (i.e. ElementReader or ElementBuilder).
	 */
	 UString GetTextString();

	/** 
	 * @return a pointer to the internal text buffer for this text element.
	 * @note GetTextData() returns the raw text data and not a Unicode string.
	 * In PDF text can be encoded using various encoding schemes so it is necessary 
	 * to consider Font encoding while processing the content of this buffer. 
	 * 
	 * @note Most of the time GetTextString() is what you are looking for instead.
	 * GetTextString() maps the raw text directly into Unicode (as specified by Adobe 
	 * Glyph List (AGL) ). Even if you would prefer to decode text yourself it is more 
	 * convenient to use CharIterators returned by CharBegin()/CharEnd() and 
	 * PDF::Font code mapping methods.
	 *
	 * @note the buffer owner is the current element (i.e. ElementReader or ElementBuilder).
	 */
#ifdef SWIG
	 std::vector<unsigned char> GetTextData();
#else
	 const UChar* GetTextData();
#endif
	
	/** 
	 * @return the size of the internal text buffer returned in GetTextData().
	 */
	 UInt32 GetTextDataSize();

	/**
	 * @return a reference to the current text matrix (Tm).
	 */
	 Common::Matrix2D GetTextMatrix();

	/**
	 * @return a CharIterator addressing the first CharData element in the text run.
	 * 
	 * CharIterator points to CharData. CharData is a data structure that contains 
	 * the char_code number (used to retrieve glyph outlines, to map to Unicode, etc.), 
	 * character positioning information (x, y), and the number of bytes taken by the 
	 * character within the text buffer.
	 *
	 * @note CharIterator follows the standard STL forward-iterator interface. 
	 * 
	 * An example of how to use CharIterator.
	 * @code
	 *     for (CharIterator itr = element.GetCharIterator(); itr.HasNext(); itr.Next()) {
	 * 			unsigned int char_code = itr.Current().char_code;
	 * 			double char_pos_x = itr.Current().x;
	 * 			double char_pos_y = itr.Current().y;
	 *     }
	 * @endcode 
	 * 
	 * @note Character positioning information (x, y) is represented in text space. 
	 * In order to get the positioning in the user space, the returned value should 
	 * be scaled using the text matrix (GetTextMatrix()) and the current transformation 
	 * matrix (GetCTM()). See section 4.2 'Other Coordinate Spaces' in PDF Reference 
	 * Manual for details and PDFNet FAQ - "How do I get absolute/relative text and 
	 * character positioning?".
	 * 
	 * @note within a text run a character may occupy more than a single byte (e.g. 
	 * in case of composite/Type0 fonts). The role of CharIterator/CharData is to 
	 * provide a uniform and easy to use interface to access character information.
	 */
	 CharIterator GetCharIterator();

	/** 
	 * @return The text advance distance in text space.  
	 * 
	 * The total sum of all of the advance values from rendering all of the characters 
	 * within this element, including the advance value on the glyphs, the effect of 
	 * properties such as 'char-spacing', 'word-spacing' and positioning adjustments 
	 * on 'TJ' elements. 
	 * 
	 * @note Computed text length is represented in text space. In order to get the 
	 * length of the text run in the user space, the returned value should be scaled 
	 * using the text matrix (GetTextMatrix()) and the current transformation 
	 * matrix (GetCTM()). See section 4.2 'Other Coordinate Spaces' in PDF Reference 
	 * Manual for details.
	 */
	 double GetTextLength();
	
	/**
	 * @return The number used to adjust text matrix in horizontal direction when drawing
	 * text. The number is expressed in thousandths of a unit of text space. The returned 
	 * number corresponds to a number value within TJ array. For 'Tj' text strings the 
	 * returned value is always 0.
	 * 
	 * @note because CharIterator positioning information already accounts for TJ 
	 * adjustments this method is rarely used.
	 */
	 double GetPosAdjustment();

	// Text New Line Element (e_text_new_line) Methods ------------------------------

	/** 
	 * Returns the offset (out_x, out_y) to the start of the current line relative to 
	 * the beginning of the previous line.  
	 *  
	 * out_x and out_y are numbers expressed in unscaled text space units. 
	 * The returned numbers correspond to the arguments of 'Td' operator.
	 */
	 Point GetNewTextLineOffset();

#ifndef SWIG
	 void GetNewTextLineOffset(double& out_x, double& out_y);
#endif

	/** 
	 * Sets the offset (dx, dy) to the start of the current line relative to the beginning 
	 * of the previous line.  
	 * @param dx horizontal offset to the start of the curret line
	 * @param dy vertical offset to the start of the current line
	 */
	 void SetNewTextLineOffset(double dx, double dy);


	// Text Element (e_text and e_text_new_line) Methods ----------------------------

   	/**
	 * @return true if this element is directly associated with a text matrix 
	 * (that is Tm operator is just before this text element) or false if the text 
	 * matrix is default or is inherited from previous text elements.
	 */
	  bool HasTextMatrix();


	// Text Element (e_text) Set Methods --------------------------------------------

	/** 
	 * Set the text data for the current e_text Element.
	 * @param buf_text_data a pointer to a buffer containing text.
	 * @param text_data_size the size of the internal text buffer
	 */
	  void SetTextData(const UChar* buf_text_data, int text_data_size);
	
	/**
	 * Sets the text matrix for a text element.
	 * 
	 * @param mtx The new text matrix for this text element
	 */
	 void SetTextMatrix(Common::Matrix2D& mtx);

	/**
	 * Sets the text matrix for a text element. This method accepts text 
	 * transformation matrix components directly.
	 * 
	 * A transformation matrix in PDF is specified by six numbers, usually 
	 * in the form of an array containing six elements. In its most general 
	 * form, this array is denoted [a b c d h v]; it can represent any linear 
	 * transformation from one coordinate system to another. For more 
	 * information about PDF matrices please refer to section 4.2.2 'Common 
	 * Transformations' in PDF Reference Manual, and to documentation for 
	 * Matrix2D class.
	 * 
	 * @param a - horizontal 'scaling' component of the new text matrix.
	 * @param b - 'rotation' component of the new text matrix.
	 * @param c - 'rotation' component of the new text matrix.
	 * @param d - vertical 'scaling' component of the new text matrix.
	 * @param h - horizontal translation component of the new text matrix.
	 * @param v - vertical translation component of the new text matrix.
	 */
	 void SetTextMatrix(double a, double b, double c, double d, double h, double v);
	
	/**
	 * @param adjust number to set the horizontal adjustment to
	 * 
	 * @note Positive values move the current text element backwards (along text direction).
	 *       Negative values move the current text element forward (along text direction).
	 */
	 void SetPosAdjustment(double adjust);

	/**  
	 * Recompute the character positioning information (i.e. CharIterator-s) and 
	 * text length. 
	 * 
	 * Element objects caches text length and character positioning information. 
	 * If the user modifies the text data or graphics state the cached information 
	 * is not correct. UpdateTextMetrics() can be used to recalculate the correct
	 * positioning and length information. 
	 */
	 void UpdateTextMetrics();


	// Shading Element (e_shading) Methods ------------------------------------------

	/** 
	 * @return the SDF object of the Shading object.
	 */
	 Shading GetShading();

	// Marked Content Elements 
	// (e_marked_content_begin and e_marked_content_point) Methods ------------------

	/**
	 * @return a dictionary containing the property list or NULL if property
	 * dictionary is not present.
	 *
	 * @note the function automatically looks under Properties sub-dictionary of the 
	 * current resource dictionary if the dictionary is not in-line. Therefore you 
	 * can assume that returned Obj is dictionary if it is not NULL.
	 */
	 SDF::Obj GetMCPropertyDict();
	
	/**
	 * @return a tag is a name object indicating the role or significance of 
	 * the marked content point/sequence.
	 */ 
	 SDF::Obj GetMCTag();
	
	 ~Element() {}


// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 Element(TRN_Element impl);
	TRN_Element mp_elem;
#endif
// @endcond
};


#include <Impl/Element.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFElement
