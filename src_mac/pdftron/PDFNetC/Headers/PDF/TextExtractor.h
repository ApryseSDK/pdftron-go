//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFTextExtractor
#define PDFTRON_H_CPPPDFTextExtractor

#include <PDF/Page.h>
#include <PDF/Rect.h>
#include <Common/UString.h>
#include <C/PDF/TRN_TextExtractor.h>
#include <vector>
#include<PDF/OCG/Context.h>

namespace pdftron { 
	namespace PDF {

class Style;
class Word;
class Line;

/**
 * TextExtractor is used to analyze a PDF page and extract words and logical 
 * structure within a given region. The resulting list of lines and words can 
 * be traversed element by element or accessed as a string buffer. The class 
 * also includes utility methods to extract PDF text as HTML or XML.
 * 
 * Possible use case scenarios for TextExtractor include:
 *  - Converting PDF pages to text or XML for content repurposing.
 *  - Searching PDF pages for specific words or keywords.
 *  - Indexing large PDF repositories for indexing or content 
 *    retrieval purposes (i.e. implementing a PDF search engine).
 *  - Classifying or summarizing PDF documents based on their text content.
 *  - Finding specific words for content editing purposes (such as splitting pages 
 *    based on keywords etc).
 * 
 * The main task of TextExtractor is to interpret PDF pages and offer a 
 * simple to use API to: 
 *  - Normalize all text content to Unicode.
 *  - Extract inferred logical structure (word by word, line by line, 
 *    or paragraph by paragraph).
 *  - Extract positioning information for every line, word, or a glyph.
 *  - Extract style information (such as information about the font, font size,
 *    font styles, etc) for every line, word, or a glyph.
 *  - Control the content analysis process. A number of options (such as 
 *    removal of text obscured by images) is available to let the user 
 *    direct the flow of content recognition algorithms that will meet their
 *    requirements.
 *  - Offer utility methods to convert PDF page content to text, XML, or HTML.
 * 
 * Note: TextExtractor is analyzing only textual content of the page.
 * This means that the rasterized (e.g. in scanned pages) or vectorized
 * text (where glyphs are converted to path outlines) will not be recognized 
 * as text. Please note that it is still possible to extract this content 
 * using pdftron.PDF.ElementReader interface.
 * 
 * In some cases TextExtractor may extract text that does not appear to 
 * be on the visible page (e.g. when text is obscured by an image or a 
 * rectangle). In these situations it is possible to use processing flags
 * such as 'e_remove_hidden_text' and 'e_no_invisible_text' to remove 
 * hidden text. 
 * 
 * A sample use case (in C++):
 * 
 * @code
 * ... Initialize PDFNet ...
 * PDFDoc doc(filein);
 * doc.InitSecurityHandler();
 * Page page = *doc.PageBegin();
 * TextExtractor txt;
 * txt.Begin(page, 0, TextExtractor::e_remove_hidden_text);
 * UString text;
 * txt.GetAsText(text);
 * // or traverse words one by one...
 * TextExtractor::Line line = txt.GetFirstLine(), lend;
 * TextExtractor::Word word, wend;
 * for (; line!=lend; line=line.GetNextLine()) {
 *  for (word=line.GetFirstWord(); word!=wend; word=word.GetNextWord()) {
 *    text.Assign(word.GetString(), word.GetStringLen());
 *    cout << text << '\n';
 *  }
 * }
 * @endcode 
 * 
 * A sample use case (in C#):
 * 
 * @code
 * ... Initialize PDFNet ...
 * PDFDoc doc = new PDFDoc(filein);
 * doc.InitSecurityHandler();
 * Page page = doc.PageBegin().Current();
 * TextExtractor txt = new TextExtractor();
 * txt.Begin(page, 0, TextExtractor.ProcessingFlags.e_remove_hidden_text);
 * string text = txt.GetAsText();
 * // or traverse words one by one...
 * TextExtractor.Word word;
 * for (TextExtractor.Line line = txt.GetFirstLine(); line.IsValid(); line=line.GetNextLine()) {
 *   for (word=line.GetFirstWord(); word.IsValid(); word=word.GetNextWord()) {
 *     Console.WriteLine(word.GetString());
 *   }
 * }
 * @endcode 
 * 
 * For full sample code, please take a look at TextExtract sample project.
 */
class TextExtractor 
{
public:
	typedef pdftron::PDF::Style Style;
	typedef pdftron::PDF::Word Word;
	typedef pdftron::PDF::Line Line;

	/**
	* Constructor and destructor
	*/
	 TextExtractor();
	 ~TextExtractor();

	/** 
	 * Processing options that can be passed in Begin() method to direct 
	 * the flow of content recognition algorithms
	 */
	 enum ProcessingFlags
	{
		// Disables expanding of ligatures using a predefined mapping. 
		// Default ligatures are: fi, ff, fl, ffi, ffl, ch, cl, ct, ll, 
		// ss, fs, st, oe, OE. 
		e_no_ligature_exp = 1, 

		// Disables removing duplicated text that is frequently used to 
		// achieve visual effects of drop shadow and fake bold. 
		e_no_dup_remove = 2,

		// Treat punctuation (e.g. full stop, comma, semicolon, etc.) as 
		// word break characters. 
		e_punct_break = 4,

		// Enables removal of text that is obscured by images or 
		// rectangles. Since this option has small performance penalty 
		// on performance of text extraction, by default it is not 
		// enabled.
		e_remove_hidden_text = 8, 

		// Enables removing text that uses rendering mode 3 (i.e. invisible text).
		// Invisible text is usually used in 'PDF Searchable Images' (i.e. scanned 
		// pages with a corresponding OCR text). As a result, invisible text 
		// will be extracted by default.
		e_no_invisible_text = 16,

		// Enables removal of text that is marked as part of a Watermark layer
		e_no_watermarks = 128
	};

	/**
	* Start reading the page. 
	* 
	* @param page Page to read.
	* @param clip_ptr A pointer to the optional clipping rectangle. This 
	* parameter can be used to selectively read text from a given rectangle.
	* @param flags A list of ProcessingFlags used to control text extraction 
	* algorithm.
	*/
	 void Begin(Page page, const Rect* clip_ptr = 0, UInt32 flags = 0);

	/**
	* Sets the Optional Content Group (OCG) context that should be used when
	* processing the document. This function can be used to change the current
	* OCG context. Optional content (such as PDF layers) will be selectively
	* processed based on the states of optional content groups in the given
	* context.
	*
	* @param ctx Optional Content Group (OCG) context, or NULL if TextExtractor
	* should process all content on the page.
	*/
	void SetOCGContext(OCG::Context* ctx);
	
	/** 
	* @return the number of words on the page.
	*/ 
	 int GetWordCount();
	 
	/**  
	* Sets the directionality of text extractor.
	* Must be called before the processing of a page started.
	* @param rtl mode reverses the directionality of TextExtractor algorithm.
	*/ 
	 void SetRightToLeftLanguage(bool rtl);
	/** 
	* @return the directionality of text extractor.
	*/ 
	
	 bool GetRightToLeftLanguage();
	/** 
	* Get all words in the current selection as a single string.
	* 
	* @param out_str The string containing all words in the current 
	* selection. Words will be separated with space (i.e. ' ') or 
	* new line (i.e. '\n') characters.
	* 
	* @param dehyphen If true, finds and removes hyphens that split words 
	* across two lines. Hyphens are often used a the end of lines as an 
	* indicator that a word spans two lines. Hyphen detection enables removal 
	* of hyphen character and merging of text runs to form a single word. 
	* This option has no effect on Tagged PDF files.
	*/
	 UString GetAsText(bool dehyphen = true);

#ifndef SWIG
	 void GetAsText(UString& out_str, bool dehyphen = true);
#endif
    
    /**
     * Get all the characters that intersect an annotation.
     *
     * @param annot The annotation to intersect with.
     */
    UString GetTextUnderAnnot(const Annot& annot);
    
#ifndef SWIG
    void GetTextUnderAnnot(UString& out_str, const Annot& annot);
#endif


	/**
	 * Flags controlling the structure of XML output in a call to GetAsXML().
	 */ 
	enum XMLOutputFlags 
	{
		// Output words as XML elements instead of inline text.
		e_words_as_elements = 1, 

		// Include bounding box information for each XML element. 
		// The bounding box information will be stored as 'bbox' attribute.
		e_output_bbox = 2, 

		// Include font and styling information.
		e_output_style_info = 4
	};

	/** 
	 * Get text content in a form of an XML string.
	 * 
	 * @param out_xml - The string containing XML output.
	 * @param xml_output_flags - flags controlling XML output. For more 
	 * information, please see TextExtract::XMLOutputFlags.
	 * 
	 * XML output will be encoded in UTF-8 and will have the following
	 * structure:
	 * @code
	 * <Page num="1 crop_box="0, 0, 612, 792" media_box="0, 0, 612, 792" rotate="0">
	 *  <Flow id="1">
	 *   <Para id="1">
	 *    <Line box="72, 708.075, 467.895, 10.02" style="font-family:Calibri; font-size:10.02; color: #000000;">
	 *      <Word box="72, 708.075, 30.7614, 10.02">PDFNet</Word>
	 *      <Word box="106.188, 708.075, 15.9318, 10.02">SDK</Word>
	 *      <Word box="125.617, 708.075, 6.22242, 10.02">is</Word>
	 *      ...
	 *    </Line>
	 *   </Para>     
	 *  </Flow>
	 * </Page>	 	 
	 * @endcode
	 *
	 * The above XML output was generated by passing the following union of 
	 * flags in the call to GetAsXML(): 
	 *   (TextExtractor::e_words_as_elements | TextExtractor::e_output_bbox | TextExtractor::e_output_style_info)
	 * 
	 * In case 'xml_output_flags' was not specified, the default XML output 
	 * would look as follows:
	 * 
	 * <Page num="1 crop_box="0, 0, 612, 792" media_box="0, 0, 612, 792" rotate="0">
	 * <Flow id="1">
	 * <Para id="1">
	 *     <Line>PDFNet SDK is an amazingly comprehensive, high-quality PDF developer toolkit...</Line>
	 *     <Line>levels. Using the PDFNet PDF library, ...</Line>
	 *     ...
	 *   </Para>     
	 *  </Flow>
	 * </Page>	 	 
	 * @endcode
	 */
	 UString GetAsXML(UInt32 xml_output_flags = 0);

#ifndef SWIG
	 void GetAsXML(UString& out_xml, UInt32 xml_output_flags = 0);
#endif

	 /**
  * @return The number of lines of text on the selected page.
  */
	 int GetNumLines();


	 /**
	  * @return The first line of text on the selected page.
	  *
	  * @note To traverse the list of all text lines on the page use line.GetNextLine().
	  * @note To traverse the list of all word on a given line use line.GetFirstWord().
	  */
	 Line GetFirstLine();

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

	 // @cond PRIVATE_DOC
private:
	TRN_TextExtractor mp_extractor;

	// TextExtractor should not be copied
	TextExtractor(const TextExtractor& other);
	TextExtractor& operator= (const TextExtractor&);
	// @endcond
};

/** 
	* A class representing predominant text style associated with a 
	* given Line, a Word, or a Glyph. The class includes information about 
	* the font, font size, font styles, text color, etc.
	*/ 
class Style 
{
public:

	/** 
		* @return low-level PDF font object. A high level font object can 
		* be instantiated as follows: 
		* In C++: pdftron.PDF.Font f(style.GetFont())
		* In C#: pdftron.PDF.Font f = new pdftron.PDF.Font(style.GetFont());
		*/
	SDF::Obj GetFont();

	/** 
		* @return the font name used to draw the selected text.
		*/
	UString GetFontName();

	/** 
		* @return The font size used to draw the selected text as it 
		* appears on the output page.
		* @note Unlike the 'font size' in the graphics state (pdftron.PDF.GState)
		* the returned font size accounts for the effects CTM, text matrix,
		* and other graphics state attributes that can affect the appearance of 
		* text.
		*/
	double GetFontSize();

	/** 
		* @return The weight (thickness) component of the fully-qualified font name 
		* or font specifier. The possible values are 100, 200, 300, 400, 500, 600, 700, 
		* 800, or 900, where each number indicates a weight that is at least as dark as 
		* its predecessor. A value of 400 indicates a normal weight; 700 indicates bold.
		* Note: The specific interpretation of these values varies from font to font. 
		* For example, 300 in one font may appear most similar to 500 in another.
		*/
	int GetWeight();

	/** 
		* @return true if glyphs have dominant vertical strokes that are slanted.
		* @note the return value corresponds to the state of 'italic' flag in the 'Font Descriptor'.
		*/
	bool IsItalic();

	/** 
		* @return true if glyphs have serifs, which are short strokes drawn at an angle on the top 
		* and bottom of glyph stems.
		* @note the return value corresponds to the state of 'serif' flag in the 'Font Descriptor'.
		*/
	bool IsSerif();

	/** 
		* @return text color in RGB color space.
		*/
	std::vector<int> GetColor();

#ifndef SWIG
	void GetColor(UInt8 rgb[3]);
#endif

	bool operator== (const Style& s) const;
	bool operator!= (const Style& s) const;

	Style();

	// @cond PRIVATE_DOC 
	#ifndef SWIGHIDDEN
	Style(const Style& s);
	Style(TRN_TextExtractorStyle impl);
	TRN_TextExtractorStyle mp_style;
	#endif
	// @endcond
};

/**
	* TextExtractor::Word object represents a word on a PDF page. 
	* Each word contains a sequence of characters in one or more styles 
	* (see TextExtractor::Style).
	*/
class Word 
{
public:
	/** 
		* @return The number of glyphs in this word.
		*/
		int GetNumGlyphs();

	/** 
		* @param out_bbox The bounding box for this word (in unrotated page 
		* coordinates). 
		* @note To account for the effect of page '/Rotate' attribute, 
		* transform all points using page.GetDefaultMatrix().
	 	*/
	Rect GetBBox();

#ifndef SWIG
	void GetBBox(double out_bbox[4]);
#endif

	/** 
		* @param out_quad The quadrilateral representing a tight bounding box 
		* for this word (in unrotated page coordinates).
		*/
	std::vector<double> GetQuad();

#ifndef SWIG
	void GetQuad(double out_quad[8]);
#endif

	/** 
		* @param glyph_idx The index of a glyph in this word.
		* @param out_quad The quadrilateral representing a tight bounding box 
		* for a given glyph in the word (in unrotated page coordinates).
		*/
	std::vector<double> GetGlyphQuad(int glyph_idx);

#ifndef SWIG
	void GetGlyphQuad(int glyph_idx, double out_quad[8]);
#endif

	/** 
		* @param char_idx The index of a character in this word.
		* @return The style associated with a given character.
		*/
	Style GetCharStyle(int char_idx);

	/**
		* @return predominant style for this word.
		*/
	Style GetStyle();

	/**
		* @return the number of characters in this word.
		*/
	int GetStringLen();

	/** 
		* @return the content of this word represented as a Unicode string.
		*/
#ifdef SWIG
	UString GetString();
#else
	const Unicode* GetString();
#endif

	/** 
		* @return the next word on the current line.
		*/
	Word GetNextWord();

	/** 
		* @return the index of this word of the current line. A word that 
		* starts the line will return 0, whereas the last word in the line
		* will return (line.GetNumWords()-1).
		*/
	int GetCurrentNum();

	/** 
		* @return true if this is a valid word, false otherwise.
		*/
	bool IsValid();

	bool operator== (const Word&) const;
	bool operator!= (const Word&) const;
	Word();

	// @cond PRIVATE_DOC 
	#ifndef SWIGHIDDEN
	Word(TRN_TextExtractorWord impl);
	TRN_TextExtractorWord mp_word;
	#endif
	// @endcond
};

/**
	* TextExtractor::Line object represents a line of text on a PDF page. 
	* Each line consists of a sequence of words, and each words in one or 
	* more styles.
	*/	
class Line {
public: 

	/** 
		* @return The number of words in this line.
		*/
	int GetNumWords();

	/** 
		* @return true is this line is not rotated (i.e. if the 
		* quadrilaterals returned by GetBBox() and GetQuad() coincide).
		*/
	bool IsSimpleLine();

	/** 
		* @param out_bbox The bounding box for this line (in unrotated page 
		* coordinates). 
		* @note To account for the effect of page '/Rotate' attribute, 
		* transform all points using page.GetDefaultMatrix().
		*/
#ifdef SWIG
	Rect GetBBox();
#else
	const double* GetBBox();
#endif

	/** 
		* @param out_quad The quadrilateral representing a tight bounding box 
		* for this line (in unrotated page coordinates).
		*/
	std::vector<double> GetQuad();

#ifndef SWIG
	void GetQuad(double out_quad[8]);
#endif

	/** 
		* @return the first word in the line.
		* @note To traverse the list of all words on this line use word.GetNextWord().
		*/
	Word GetFirstWord();

	/** 
		* @return the i-th word in this line.
		* @param word_idx A integer representing the index of the word to get.
		*/
	Word GetWord(int word_idx);

	/** 
		* @return the next line on the page.
		*/
	Line GetNextLine();

	/** 
		* @return the index of this line of the current page.
		*/
	int GetCurrentNum();

	/**
		* @return predominant style for this line.
		*/
	Style GetStyle();

	/**
		* @return The unique identifier for a paragraph or column
		* that this line belongs to. This information can be used to 
		* identify which lines belong to which paragraphs. 
		*/
	int GetParagraphID();

	/** 
		* @return The unique identifier for a paragraph or column
		* that this line belongs to. This information can be used to 
		* identify which lines/paragraphs belong to which flows. 
		*/
	int GetFlowID();

	/** 
		* @return true is this line of text ends with a hyphen (i.e. '-'),
		* false otherwise.
		*/
	bool EndsWithHyphen();

	/** 
		* @return true if this is a valid line, false otherwise.
		*/
	bool IsValid();

	bool operator== (const Line&) const;
	bool operator!= (const Line&) const;
	Line();

	// @cond PRIVATE_DOC 
	#ifndef SWIGHIDDEN
	Line(TRN_TextExtractorLine impl);
	TRN_TextExtractorLine mp_line;
	#endif
	// @endcond
};




#include <Impl/TextExtractor.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFTextExtractor
