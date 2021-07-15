//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFTextSearch
#define PDFTRON_H_CPPPDFTextSearch

#include <PDF/PDFDoc.h>
#include <Common/UString.h>
#include <PDF/Highlights.h>
#include <C/PDF/TRN_TextSearch.h>

namespace pdftron { 
	namespace PDF {

/** 
 * The result of running pdftron::PDF::TextSearch::Run()
 */
class SearchResult 
{
public:

	/** 
	* @return true if a match was found.  
	*/ 
	operator bool () { return IsFound(); }

	/**
	* @return true if a match was found.
	*/	
	bool IsFound() const;

	/**
	 * @return true if finished searching the entire document.
	 */	
	bool IsDocEnd() const;

	/**
	 * @return true if finished searching a page.
	 */	
	bool IsPageEnd() const;

	/**
	 * @return the number of the page with the match.
	 */ 
	int GetPageNumber() const;

	/**
	 * @return the string that matches the search pattern.
	 */
	UString GetMatch() const;

	/**
	 * @return the ambient string of the found string (computed only if 
	 * 'e_ambient_string' is set).
	 */
	UString GetAmbientString() const;

	/**
	 * @return The Highlights info associated with the match (computed 
	 * only if 'e_highlight' is set). 
	 */ 
	Highlights GetHighlights() const;



// @cond PRIVATE_DOC

#ifndef SWIGHIDDEN
	SearchResult();
	SearchResult(const SearchResult& b);
	SearchResult(int, TRN_TextSearchResultCode rc, UString r, UString a, Highlights h);
#endif
// @endcond

private:
	int page_num;
	TRN_TextSearchResultCode resCode;
	UString result;
	UString ambient;
	Highlights hlts;
};


/**
 * TextSearch searches through a PDF document for a user-given search pattern.
 * The current implementation supports both verbatim search and the search
 * using regular expressions, whose detailed syntax can be found at:
 *
 * http://www.boost.org/doc/libs/release/libs/regex/doc/html/boost_regex/syntax/perl_syntax.html
 *
 * TextSearch also provides users with several useful search modes and extra 
 * information besides the found string that matches the pattern. TextSearch
 * can either keep running until a matched string is found or be set to return
 * periodically in order for the caller to perform any necessary updates 
 * (e.g., UI updates). It is also worth mentioning that the search modes can be
 * changed on the fly while searching through a document.
 *
 * Possible use case scenarios for TextSearch include:
 *  - Guide users of a PDF viewer (e.g. implemented by PDFViewCtrl) to places
 *    where they are intersted in;
 *  - Find interested PDF documents which contain certain patterns;
 *  - Extract interested information (e.g., credit card numbers) from a set of files;
 *  - Extract Highlight information (refer to the Highlights class for details) from
 *    files for external use.
 *
 * Note: 
 *  - Since hyphens ('-') are frequently used in PDF documents to concatenate the two
 *    broken pieces of a word at the end of a line, for example
 *
 *	  "TextSearch is powerful for finding patterns in PDF files; yes, it is really pow-
 *     erful."
 * 
 *    a search for "powerful" should return both instances. However, not all end-of-line
 *    hyphens are hyphens added to connect a broken word; some of them could be "real"
 *    hyphens. In addition, an input search pattern may also contain hyphens that complicate
 *    the situation. To tackle this problem, the following conventions are adopted:
 *
 *    a)When in the verbatim search mode and the pattern contains no hyphen, a matching
 *      string is returned if it is exactly the same or it contains end-of-line
 *      or start-of-line hyphens. For example, as mentioned above, a search for "powerful" 
 *      would return both instances.
 *    b)When in verbatim search mode and the pattern contains one or multiple hyphens, a 
 *      matching string is returned only if the string matches the pattern exactly. For 
 *      example, a search for "pow-erful" will only return the second instance, and a search
 *      for "power-ful" will return nothing.
 *    c)When searching using regular expressions, hyphens are not taken care implicitly.
 *      Users should take care of it themselves. For example, in order to find both the
 *      "powerful" instances, the input pattern can be "pow-{0,1}erful".
 *     
 * A sample use case (in C++):
 * 
 * @code
 * //... Initialize PDFNet ...
 * PDFDoc doc(filein);
 * doc.InitSecurityHandler();
 * int page_num;
 * char buf[32];
 * UString result_str, ambient_string;
 * Highlights hlts;
 * TextSearch txt_search;
 * TextSearch::Mode mode = TextSearch::e_whole_word | TextSearch::e_page_stop;
 * UString pattern( "joHn sMiTh" );
 *
 * //PDFDoc doesn't allow simultaneous access from different threads. If this
 * //document could be used from other threads (e.g., the rendering thread inside
 * //PDFView/PDFViewCtrl, if used), it is good practice to lock it.
 * //Notice: don't forget to call doc.Unlock() to avoid deadlock.
 * doc.Lock(); 
 *
 * txt_search.Begin( doc, pattern, mode );
 * while ( true )
 * {
 *	   SearchResult result = code = txt_search.Run(page_num, result_str, ambient_string, hlts );
 *	   if ( code == TextSearch::e_found )
 *	   {
 *		   result_str.ConvertToAscii(buf, 32, true);
 *		   cout << "found one instance: " << char_buf << endl;
 *	   }
 *	   else
 *	   {
 *		   break;
 *	   }
 * }
 *
 * //unlock the document to avoid deadlock.
 * doc.UnLock();
 * @endcode 
 * 
 * 
 * For a full sample, please take a look at the TextSearch sample project.
 */
class TextSearch 
{
public:

	/**
	* Constructor and destructor.
	*/
	TextSearch();
	~TextSearch();

 	/**
	* Typedef the search mode.
	*/
	typedef TRN_UInt32 Mode;

	/** 
	* Search modes that control how searching is conducted.
	*/
	enum TextSearchModes
	{
		//use regular expressions
		e_reg_expression = 0x0001,
		
		//match case-sensitively
		e_case_sensitive = e_reg_expression << 1,

		//match the entire word
		e_whole_word	 = e_case_sensitive << 1,

		//search upward (from the end of the file and from the bottom of a page)
		e_search_up		 = e_whole_word << 1,

		//tells the search process to return when each page is finished; this is
		//useful when a user needs Run() to return periodically so that certain
		//things (e.g., UI) can be updated from time to time.
		e_page_stop		 = e_search_up << 1,		

		//tells the search process to compute Highlight information.
		e_highlight		 = e_page_stop << 1,

		//tells the search process to compute the ambient string of the found pattern.
		//This is useful if a user wants to examine or display what surrounds the
		//found pattern.
		e_ambient_string = e_highlight << 1,

		//refrain from replacing newlines with spaces
		e_raw_text_search = e_ambient_string << 1
	};

	/** 
	* Initialize for search process. This should be called before starting the actual search
	* with method Run().
	* 
	* @param doc the PDF document to search in.
	* @param pattern the pattern to search for. When regular expression is used, it contains
	*        the expression, and in verbatim mode, it is the exact string to search for.
	* @param mode the mode of the search process.
	* @param start_page the start page of the page range to search in. The default value is -1 
	*        indicating the range starts from the first page.
	* @param end_page the end page of the page range to search in. The default value is -1
	*        indicating the range ends at the last page.
	* @return true if the initialization has succeeded.
	*/
	bool Begin(PDFDoc& doc, const UString& pattern, Mode mode, int start_page = -1, int end_page = -1);

	/** 
	* Search the document and returns upon the following circumstances:
	* a)Reached the end of the document;
	* b)Reached the end of a page (if set to return by specifying mode 'e_page_stop' );
	* c)Found an instance matching the search pattern.
	*
	* Note that this method should be called in a loop in order to find all matching instances; 
	* in other words, the search is conducted in an incremental fashion.
	*/
	SearchResult Run();

	/** 
	* Set the current search pattern. Note that it is not necessary to call this method since
	* the search pattern is already set when calling the Begin() method. This method is provided
	* for users to change the search pattern while searching through a document.
	*
	* @param pattern the search pattern to set.
	* @return true if the setting has succeeded.
	*/
	bool SetPattern(const UString& pattern);

	/** 
	* Retrieve the current search mode.
	* @return the current search mode.
	*/
	Mode GetMode() const;

	/** 
	* Set the current search mode. For example, the following code turns on the regular
	* expressions:
	* 
	*	TextSearch ts;
	*   ...
	*   TextSearch::Mode mode = ts.GetMode();
	*   mode |= TextSearch::e_reg_expression;
	*   ts.SetMode(mode);
	*   ...
	*
	* @param mode the search mode to set.
	*/
	void SetMode( Mode mode );

	/**
	 * Tells TextSearch that language is from right to left.
	 * @param flag Set to true if the language is right to left.
	 */
	void SetRightToLeftLanguage(bool flag);

	/** 
	* Retrieve the number of the current page that is searched in.
	* If the returned value is -1, it indicates the search process has not been initialized
	* (e.g., Begin() is not called yet); if the returned value is 0, it indicates the search
	* process has finished, and if the returned value is positive, it is a valid page number.
	* @return the current page number.
	*/
	int GetCurrentPage() const;

	/**
	* Sets the Optional Content Group (OCG) context that should be used when
	* processing the document. This function can be used to change the current
	* OCG context. Optional content (such as PDF layers) will be selectively
	* processed based on the states of optional content groups in the given
	* context.
	*
	* @param ctx Optional Content Group (OCG) context, or NULL if TextSearch
	* should process all content on the page.
	*/
	void SetOCGContext(OCG::Context* context);

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();


// @cond PRIVATE_DOC

private:
	TRN_TextSearch mp_textsearch;
	TextSearch(const TextSearch&);
	TextSearch& operator= (const TextSearch&);
// @endcond

};


#include <Impl/TextSearch.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFTextSearch
