//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFFont
#define PDFTRON_H_CPPPDFFont

#include <Common/Matrix2D.h>
#include <Common/UString.h>
#include <Common/Iterator.h>
#include <PDF/Rect.h>
#include <PDF/PathData.h>
#include <PDF/ShapedText.h>
#include <C/PDF/TRN_Font.h>
#include <C/SDF/TRN_SDFDoc.h>
#include <vector>

namespace pdftron {
	namespace PDF {

/**
 * A font that is used to draw text on a page. It corresponds to a Font Resource 
 * in a PDF file. More than one page may reference the same Font object.
 * A Font has a number of attributes, including an array of widths, the character 
 * encoding, and the font's resource name.
 * 
 * PDF document can contain several different types of fonts and Font class 
 * represents a single, flat interface around all PDF font types.
 * 
 * There are two main classes of fonts in PDF: simple and composite fonts.
 * 
 * Simple fonts are Type1, TrueType, and Type3 fonts. All simple fonts have the 
 * following properties:<BR><BR>
 *  - Glyphs in the font are selected by single-byte character codes 
 *    obtained from a string that is shown by the text-showing operators. 
 *    Logically, these codes index into a table of 256 glyphs; the mapping 
 *    from codes to glyphs is called the font's encoding. Each font program 
 *    has a built-in encoding. Under some circumstances, the encoding can 
 *    be altered by means described in Section 5.5.5 "Character Encoding" in 
 *    PDF Reference Manual.<BR><BR>
 * 
 *  - Each glyph has a single set of metrics. Therefore simple fonts support 
 *    only horizontal writing mode.<BR><BR>
 * 
 * A composite font is one whose glyphs are obtained from a font like object 
 * called a CIDFont (e.g. CIDType0Font and CIDType0Font). A composite font is 
 * represented by a font dictionary whose Subtype value is Type0. The Type 0 font 
 * is known as the root font, while its associated CIDFont is called its descendant.
 * CID-keyed fonts provide a convenient and efficient method for defining
 * multiple-byte character encodings and fonts with a large number of glyphs. 
 * These capabilities provide great flexibility for representing text in writing 
 * systems for languages with large character sets, such as Chinese, Japanese, 
 * and Korean (CJK).
 */
class Font
{
public:

	enum StandardType1Font
	{
		e_times_roman = 0,
		e_times_bold,
		e_times_italic,
		e_times_bold_italic,
		e_helvetica,
		e_helvetica_bold,
		e_helvetica_oblique,
		e_helvetica_bold_oblique,
		e_courier,
		e_courier_bold,
		e_courier_oblique,
		e_courier_bold_oblique,
		e_symbol, 
		e_zapf_dingbats,
		e_null				// not a standard font
	};

	/** 
	 * Create a PDF::Font object from an existing SDF font object that is embedded 
	 * in the document. If font_dict is null, a non valid font is created.
	 * @param font_dict The Cos/SDF object to create the Font object with.
	 */
	 Font (SDF::Obj font_dict = 0);

	/** 
	 * Create a PDF::Font object for the given standard (also known as base 14 font)
	 */
	 static Font Create(SDF::SDFDoc& doc, StandardType1Font type, bool embed = false );

	/**
	 * Embed an external TrueType font in the document as a Simple font. 
	 * 
	 * @note glyphs in the Simple font are selected by single-byte character codes. 
	 * If you want to work with multi-byte character codes (e.g. UTF16) you need to 
	 * create a CID font.
	 * 
	 * @param doc Document in which the external font should be embedded.
	 * @param font_path Path to the external font file.
	 * @param embed A boolean indicating whether the font should be embedded or 
	 * not. For accurate font reproduction set the embed flag to 'true'. 
	 * @param subset A boolean indicating whether the embedded font should
	 * be subsetted.
	 */
	 static Font CreateTrueTypeFont(SDF::SDFDoc& doc, const UString& font_path, 
		bool embed=true, bool subset=true);

	/** 
	 * Create a TrueType PDF font with the characteristics specified 
	 * in the LOGFONTA structure. 
	 *
	 * @param doc Document in which the external font should be embedded.
	 * @param logfont A pointer to a Windows LOGFONTA structure that defines the 
	 * characteristics of the logical font.
	 * @param embed A boolean indicating whether the font should be embedded or 
	 * not. For accurate font reproduction set the embed flag to 'true'. 
	 * @param subset A boolean indicating whether the embedded font should
	 * be subsetted.
	 * 
	 * @note This method is available only on Windows platforms.
	 */ 
	#ifdef _WIN32
	 static Font CreateTrueTypeFont2(SDF::SDFDoc& doc, const void* logfont, 
		bool embed=true, bool subset=true);
	#endif


	 enum Encoding
	 {
		 e_IdentityH=0,
		 e_Indices 
	 };

	/**
	 * Embed an external TrueType font in the document as a CID font.
	 * By default the function selects "Identity-H" encoding that maps 2-byte 
	 * character codes ranging from 0 to 65,535 to the same Unicode value. 
	 * Other predefined encodings are listed in Table 5.15 'Predefined CMap names'
	 * in PDF Reference Manual.
	 * 
	 * @param doc - document in which the external font should be embedded.
	 * @param font_path - path to the external font file.
	 * @param embed - a boolean indicating whether the font should be embedded or 
	 * not. For accurate font reproduction set the embed flag to 'true'. 
	 * @param subset - a boolean indicating whether the embedded font should 
	 * be subsetted
	 * @param encoding - the encoding type either e_IdentityH (default) 
	 * or e_Indices (to write glyph indices rather than unicode)
	 * @param ttc_font_index - if a TrueTypeCollection (TTC) font is loaded this
	 * parameter controls which font is actually picked
	 */
	 static Font CreateCIDTrueTypeFont(SDF::SDFDoc& doc, const UString& font_path, 
		bool embed = true, bool subset = true, 
		Encoding encoding=e_IdentityH,
		UInt32 ttc_font_index=0);

	/**
	 * Create a CID TrueType PDF font with the characteristics specified 
	 * in the LOGFONTA structure. 
	 * 
	 * @param doc - document in which the external font should be embedded.
	 * @param logfonta A pointer to a Windows LOGFONTA structure that defines the 
	 * characteristics of the logical font.
	 * @param embed - a boolean indicating whether the font should be embedded or 
	 * not. For accurate font reproduction set the embed flag to 'true'. 
	 * @param subset - a boolean indicating whether the embedded font should 
	 * be subsetted
	 * @param encoding - the encoding type either e_IdentityH (default) 
	 * or e_Indices (to write glyph indices rather than unicode)
	 *
	 * @note This method is available only on Windows platforms.
	 */
	#ifdef _WIN32
	 static Font CreateCIDTrueTypeFont2(SDF::SDFDoc& doc, const void* logfonta, 
		bool embed = true, bool subset = true, 
		Encoding encoding=e_IdentityH);
	#endif

	 /**
	 * Create a CID TrueType PDF font with the characteristics specified
	 * in the LOGFONTA structure.
	 *
	 * @param doc - document in which the external font should be embedded.
	 * @param logfontw A pointer to a Windows LOGFONTW structure that defines the
	 * characteristics of the logical font.
	 * @param embed - a boolean indicating whether the font should be embedded or
	 * not. For accurate font reproduction set the embed flag to 'true'.
	 * @param subset - a boolean indicating whether the embedded font should
	 * be subsetted
	 * @param encoding - the encoding type either e_IdentityH (default)
	 * or e_Indices (to write glyph indices rather than unicode)
	 *
	 * @note This method is available only on Windows platforms.
	 */
#ifdef _WIN32
	 static Font CreateCIDTrueTypeFont2Unicode(SDF::SDFDoc& doc, const void* logfontw,
		 bool embed = true, bool subset = true,
		 Encoding encoding = e_IdentityH);
#endif

	/**
	 * Create a new Unicode font based on the description of an existing PDF font.
	 */
	static Font Create(SDF::SDFDoc& doc, Font& from, const UString& char_set);
	static Font Create(SDF::SDFDoc& doc, const char* name, const UString& char_set);

	/**
	 * Embed an external Type1 font in the document. 
	 * 
	 * @param doc - document in which the external font should be embedded.
	 * @param font_path - path to the external font file.
	 * @param embed - a boolean indicating whether the font should be embedded or 
	 * not. For accurate font reproduction set the embed flag to 'true'. 
	 */
	 static Font CreateType1Font(SDF::SDFDoc& doc, const UString& font_path, bool embed = true);

	// Common Font methods ----------------------------------------------------------

	enum Type
	{
		e_Type1,			// Type 1 PostScript font	
		e_TrueType,			// TrueType font
		e_MMType1,			// Type 1 multiple master PostScript font
		e_Type3,			// Type 3 PostScript font
		e_Type0,			// Type 0 PostScript composite (CID) font
		e_CIDType0,			// Type 0 CID font
		e_CIDType2,			// Type 2 CID font
	};


	 Font(const Font& c);
	 Font& operator=(const Font& c);

	/** 
	 * @return Font Type
	 */
	 Type GetType();

	/** 
	 * @return true for non-CID based fonts such as Type1, TrueType, and Type3
	 *
  	 * All simple fonts have the following properties:<BR><BR>
	 * 
	 * - Glyphs in the font are selected by single-byte character codes 
	 *   obtained from a string that is shown by the text-showing operators. 
	 *   Logically, these codes index into a table of 256 glyphs; the mapping 
	 *   from codes to glyphs is called the font's encoding. Each font program 
	 *   has a built-in encoding. Under some circumstances, the encoding can 
	 *   be altered by means described in Section 5.5.5 "Character Encoding" in 
	 *   PDF Reference Manual.<BR><BR>
	 * 
	 * - Each glyph has a single set of metrics. Therefore simple fonts support 
	 *   only horizontal writing mode.<BR><BR>
	 */
	 bool IsSimple();

#ifndef SWIG
	/**
	 * @return The type of a given SDF/Cos font dictionary
	 */
	 static Type GetType(SDF::Obj font_dict);
#endif

	/**
	 * @return a SDF/Cos object of this Font.
	 */
	 SDF::Obj GetSDFObj ();

	/**
	 * @return a SDF/Cos object representing FontDescriptor or NULL is FontDescriptor
	 * is not present.
	 */
	 SDF::Obj GetDescriptor();

	/** 
	 * @return the name of a font. The behavior depends on the font type; 
	 * for a Type 3 font it gets the value of the Name key in a PDF Font resource. 
	 * For other types it gets the value of the BaseFont key in a PDF font resource.
	 */
	 const char* GetName();

	/** 
	 * @return the face's family name. This is an ASCII string, usually in English, 
	 * which describes the typeface's family (like 'Times New Roman', 'Bodoni', 'Garamond', 
	 * etc). This is a least common denominator used to list fonts.
	 */
	 const char* GetFamilyName();

	/**
	 * @return true if all glyphs have the same width
	 */
	 bool IsFixedWidth();

	/**
	 * @return true if glyphs have serifs
	 */
	 bool IsSerif();

	/**
	 * @return true if font contains characters outside the Adobe standard Latin character set.
	 */
	 bool IsSymbolic();

	/**
	 * @return true if glyphs have dominant vertical strokes that are slanted.
	 */
	 bool IsItalic();

	/**
	 * @return true if font contains no lowercase letters
	 */
	 bool IsAllCap();

	/**
	 * @return true if bold glyphs should be painted with extra pixels at very small text sizes.
	 */
	 bool IsForceBold();

	/**
	 * @return true if the font uses horizontal writing mode, false for vertical writing mode.
	 */
	 bool IsHorizontalMode();

	/**
	 * @return advance width, measured in glyph space units for the glyph
	 * matching given character code. 
	 *
	 * @note 1000 glyph units = 1 text space unit
	 * @note The width returned has NOT been scaled by the font size, text matrix,
	 *		 nor the CTM.
	 *
	 * The function gets the advance width of the font glyph. The advance width 
	 * is the amount by which the current point advances when the glyph is drawn. 
	 * The advance width may not correspond to the visible width of the glyph 
	 * and for this reason, the advance width cannot be used to determine the glyphs'
	 * bounding boxes.
	 */
	 double GetWidth(UInt32 char_code) const;

	/**
	 * @return the maximal advance width, in font units, for all glyphs in this face.
	 */
	 double GetMaxWidth();

	/**
	 * @return the default width to use for character codes whose widths are 
	 * not specified in a font dictionary's Widths array. 
	 */
	 double GetMissingWidth();

	/**
	 * GetCharCodeIterator represents an iterator interface used to traverse 
	 * a list of char codes for which there is a glyph outline in the embedded font.
	 */
	 Common::Iterator<UInt32> GetCharCodeIterator();


	/**
	 * The function retrieves the glyph outline for a given character code.
	 * 
	 * @param char_code character to query
	 * @param conics2cubics if set to true converts all quadratic Bezier curves to cubic 
	 * Beziers, otherwise no conversion is performed.
	 * @param An optional matrix used to transform glyph data coordinates. If null/unspecified, 
	 * glyph data points will not be transformed.
	 *
	 * @return A PathData object containing the path information.
	 * 
	 * @note the function can return only the following operators (Element::e_moveto, 
	 * Element::e_lineto, Element::e_cubicto and optionally Element::e_conicto if 
	 * conics2cubics parameter is set to true.
	 * 
 	 * @note This function is not applicable to Type3 font and will throw an exception. 
	 * Use GetType3GlyphStream instead.
	 *
	 * @note Check PathData::IsDefined to see if the char_code was mapped to 'undefined character code'.
	 */
	PathData GetGlyphPath(UInt32 char_code,
					  bool conics2cubics, 
					  Common::Matrix2D* transform = 0);


	/**
	 * Creates a set of positioned glyphs corresponding to the visual representation
	 * of the provided text string.
	 *
	 * The shaped text will take into  account any advanced positioning and
	 * substitution features provided by an underylying embedded font file. 
	 * For example, these features could include kerning, ligatures, and diacritic
	 * positioning. Typically the resulting shaped text would be fed into 
	 * ElementBuilder.CreateShapedTextRun()
	 *
	 * @param text_to_shape the string to be shaped.
	 *
	 * @return A ShapedText object representing the result of the shaping operation.
	 * 
	 * @note Shaping requires a Type0 font with an embedded font file which 
	 * covers all the unicode codepoints in the source text. For best results,
	 * this font should use the e_Indices encoding scheme, as shaping features
	 * that combine multiple codepoints into one glyph (ligatures, for example)
	 * will not work well in non-index encoded fonts.
	 *
	 */
	ShapedText GetShapedText(const UString& text_to_shape);

	/**
	 * Maps the encoding specific 'charcode' to Unicode. Conversion of 'charcode' 
	 * to Unicode can result in up to four Unicode characters.
	 * 
	 * @param char_code encoding specific 'charcode' that needs to be converted 
	 * to Unicode. 
	 *
	 * @param out_uni_arr A pointer to an array of Unicode characters where 
	 * the conversion result will be stored.
	 *
	 * @param in_uni_sz The number of characters that can be written to out_uni_arr.
	 * You can assume that the function will never map to more than 10 characters.
	 *
	 * @param out_char_num The function will modify this value to return the 
	 * number of Unicode characters written in 'out_uni_arr' array.
	 * 
	 * @return true if char_code was mapped to Unicode public area or false if 
	 * the char_code was mapped to Unicode private area. 
	 * 
	 * A char_code is mapped to Unicode private area when the information required 
	 * for proper mapping is missing in PDF document (e.g. a predefined encoding 
	 * or ToUnicode CMap).
	 *
	 * @note This function is not applicable to CIDFonts (e_CIDType0 and e_CIDType2) 
	 * and will throw an exception if called. 
	 */
	 UString MapToUnicode(UInt32 char_code);

#ifndef SWIG
	 bool MapToUnicode(UInt32 char_code, 
			Unicode* out_uni_arr, const int in_uni_sz, 
			int &out_chars);
#endif

#ifndef SWIG
	/**
	 * @return the font's encoding array (the mapping of character codes to glyphs). 
	 * The array contains 256 pointers. If a pointer is not NULL, it points to a 
	 * C string containing the name of the glyph for the code point corresponding 
	 * to the index. If it is NULL, then the name of the glyph is unchanged from 
	 * that specified by the font's built-in encoding.
	 *
	 * For a Type 3 font, all glyph names will be present in the encoding array, 
	 * and NULL entries correspond to un-encoded code points. 
	 * 
	 * @note The Font object is the owner of the array.
	 * @note This function is not applicable to composite fonts (e_type0, e_CIDType0, 
	 * and e_CIDType2) and will throw an exception. 
	 */
	 const char** GetEncoding();
#endif

	/**
	 * Tests whether or not the specified font is stored as a font file in a stream 
	 * embedded in the PDF file. 
	 *
	 * @return true if the font is embedded in the file, false otherwise.
	 */ 
	 bool IsEmbedded();

	/** 
	 * @return the PostScript font name for the embedded font. If the embedded font
	 * name is not available the function returns the empty string .
	 */
	 const char* GetEmbeddedFontName();

	/** 
	 * @return the stream object of the embedded font or NULL if there if the 
	 * font is not embedded.
 	 * @note This function is not applicable to Type3 font and will throw exception. 
	 */
	 SDF::Obj GetEmbeddedFont();

	/** 
	 * @return the size of decoded buffer containing embedded font data or 0 
	 * if this information is not known in advance.  
	 * 
	 * @note The size of decoded buffer may not be known in advance for all 
	 * fonts and may not be correct.
 	 * @note This function is not applicable to Type3 font and will throw exception. 
	 */
	 int GetEmbeddedFontBufSize();

	/**
	 * @return the number of font units per EM square for this face. This is 
	 * typically 2048 for TrueType fonts, 1000 for Type1 fonts
	 * 
	 * @note Only relevant for scalable formats (such as TrueType and Type1).
	 * 
	 * @note This function is not applicable to Type3 font and will throw an exception. 
	 * Use GetType3FontMatrix instead.
	 */
	 UInt16 GetUnitsPerEm();

	/**
	 * @return A rectangle expressed in the glyph coordinate system, specifying the 
	 * font bounding box. This is the smallest rectangle enclosing the shape that would 
	 * result if all of the glyphs of the font were placed with their origins coincident 
	 * and then filled.
	 */
	 Rect GetBBox();

	/**
	 * The face's ascender is the vertical distance from the baseline to the topmost 
	 * point of any glyph in the face. This field's value is a positive number, expressed
	 * in the glyph coordinate system. For all font types except Type 3, the units of 
	 * glyph space are one-thousandth of a unit of text space. Some font designs use 
	 * a value different from 'bbox.yMax'. 
	 * 
	 * @note Only relevant for scalable formats.
	 */
	 double GetAscent();

	/**
	 * The face's descender is the vertical distance from the baseline to the bottommost 
	 * point of any glyph in the face. This field's value is a negative number expressed
	 * in the glyph coordinate system. For all font types except Type 3, the units of
	 * glyph space are one-thousandth of a unit of text space. Some font designs use 
	 * a value different from 'bbox.yMin'. 
	 *
	 * @note Only relevant for scalable formats.
	 */
	 double GetDescent();


	// Type1 specific methods -------------------------------------------------------

	/**
	 * @return Font::e_null if the font is not a standard Type1 font or some 
	 * other StandardType1Font value for a standard Type1 font.
	 */
	 int GetStandardType1FontType();

	/**
	 * @return true if the embedded font is represented as CFF (Compact Font Format). 
	 * @note Only Type1 and Type1C fonts can be represented in CFF format
	 */
	 bool IsCFF();

	// Type3 specific methods -------------------------------------------------------

	/**
	 * @return Type3 font matrix, mapping glyph space to text space
	 * A common practice is to define glyphs in terms of a 1000-unit
	 * glyph coordinate system, in which case the font matrix is [0.001 0 0 0.001 0 0].
	 *
	 * @note Relevant only for a Type3 font.
	 */ 
	 Common::Matrix2D GetType3FontMatrix();

	/**
	 * @return a SDF/Cos glyph stream for the given char_code. 
	 * If specified char_code is not found in the CharProcs dictionary the
	 * function returns NULL.
	 *
	 * @note Relevant only for a Type3 font.
	 */ 
	 SDF::Obj GetType3GlyphStream(UInt32 char_code);


	// Type0 specific methods -------------------------------------------------------


	/**
	 * @return vertical advance. vertical advance is a displacement vector for vertical 
	 * writing mode (i.e. writing mode 1); its horizontal component is always 0. 
	 * 
	 * @param char_code character to query for vertical advance
	 * @param out_pos_vect_x - initialized by the method. horizontal component of the 
	 * position vector defining the position of the vertical writing mode origin 
	 * relative to horizontal writing mode origin.
	 * @param out_pos_vect_y - initialized by the method. vertical component of the 
	 * position vector defining the position of the vertical writing mode origin  
	 * relative to horizontal writing mode origin.
	 * 
	 * @note Use this method only for composite fonts with vertical writing mode 
	 * (i.e. if Font.IsHorizontalMode() returns false). The method will return 0 as vertical 
	 * advance for simple fonts or for composite fonts with only horizontal writing mode.
	 * @note Relevant only for a Type0 font.
	 */	
#ifndef SWIG
	 double GetVerticalAdvance(UInt32 char_code, double &out_pos_vect_x, double &out_pos_vect_y);
#endif
 
	 std::vector<double> GetVerticalAdvance(UInt32 char_code);

	/**
	 * @return descendant CIDFont.
	 *
	 * @note Relevant only for a Type0 font.
	 */
	 Font GetDescendant();

	/**
	 * @return a CID matching specified charcode.
	 *
	 * @note Relevant only for a Type0 font.
	 */
	 UInt32 MapToCID(UInt32 char_code) const;

#ifndef SWIG
	/**
	 * The function maps charcode (out_charcode) from char_data buffer to a CID (out_cid) and 
	 * return the number of bytes representing the CID in the buffer.
	 *
	 * @param char_data the input data buffer containing one or more bytes of input charcode
	 * @param char_data_avail the number of bytes in the char_data buffer
	 * @param out_charcode the first charcode in char_data buffer. 
	 * @param out_cid CID corresponding to the out_charcode parsed from char_data buffer. 
	 *
	 * @return the number of bytes consumed by out_cid. This number must be less than or equal to
	 * char_data_avail
	 *
	 * @note Relevant only for a Type0 font.
	 */
	 int MapToCID(const UChar* char_data, int char_data_avail, UInt32& out_charcode, UInt32& out_cid) const;
#endif

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	Font(TRN_Font impl);
	~Font();	
	TRN_Font mp_font;
#endif
// @endcond
};


#include <Impl/Font.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFFont
