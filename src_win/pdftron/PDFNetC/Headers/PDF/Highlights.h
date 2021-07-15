//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPHighlights
#define PDFTRON_H_CPPHighlights

#include <Common/UString.h>
#include <C/PDF/TRN_Highlights.h>

namespace pdftron { 
	namespace PDF {

struct Highlight
{
	Highlight()
	{
		page_num = 0; //invalid
		position = 0;
		length = 0;
	}

	Highlight(int pg, int pos, int len) : page_num(pg), position(pos), length(len)
	{}

	Highlight(const Highlight& hlt) : page_num(hlt.page_num), position(hlt.position), length(hlt.length)
	{}

	int page_num;
	int position;
	int length;
};

/**
 * Highlights is used to store the necessary information and perform certain 
 * tasks in accordance with Adobe's Highlight standard, whose details can be
 * found at:
 *
 * http://partners.adobe.com/public/developer/en/pdf/HighlightFileFormat.pdf
 *
 * In a nutshell, the Highlights class maintains a set of highlights.
 * Each highlight contains three pieces of information: 
 *
 * page: the number of the page this Highlight is on;
 * position: the start position (text offset) of this Highlight;
 * length: the length of this Highlight.
 *    
 * Possible use case scenarios for Highlights include:
 *  - Load a Highlight file (in XML format) and highlight the corresponding 
 *    texts in the viewer (e.g., if the viewer is implemented using PDFViewCtrl, 
 *    it can be achieved simply by calling PDFViewCtrl::SelectByHighlights() 
 *    method);
 *  - Save the Highlight information (e.g., constructed by the TextSearch 
 *    class) to an XML file for external uses.
 *
 * Note: 
 *  - The Highlights class does not maintain the corresponding PDF document for
 *    its highlights. It is the user's responsibility to match them up.
 *  - The Highlights class ensures that each highlight it maintains is 
 *    unique (no two highlights have the same page, position and length values).
 *  - The current implementation of Highlights only supports the 'characters'
 *    encoding for 'units' as described in the format; the 'words' encoding is 
 *    not supported at this point.
 * 
 * 
 * For a sample code, please take a look at the TextSearchTest sample project.
 */
class Highlights 
{
	friend class PDFView;
	friend class PDFViewCtrl;
	friend class TextSearch;
public:

	typedef pdftron::PDF::Highlight Highlight;
	/**
	* Constructor and destructor.
	*/
	Highlights();
	~Highlights();
	/**
	 * Copy constructor.
	 */
	Highlights(const Highlights& hlts);

	/**
	* Assignment operator.
	*/
	Highlights& operator = ( const Highlights& hlts );

	/**
	* Load the Highlight information from a file. Note that the
	* pre-existing Highlight information is discarded.
	* 
	* @param file_name the name of the file to load from.
	*/
	void Load( const UString& file_name );

	/**
	* Save the current Highlight information in the class to a file.
	* 
	* @param file_name the name of the file to save to.
	*/
	void Save( const UString& file_name );

	/**
	* Add highlights.
	* 
	* @param hlts the Highlights instance containing the highlights to be added.
	*/
	void Add( const Highlights& hlts );

	/**
	* Clear the current Highlight information in the class.
	*/
	void Clear();

	/**
	* Rewind the internal pointer to the first highlight. 
	*
	* @param doc the PDF document to which the highlights correspond.
	*
	* @note the PDF document can be a dummy document unless GetCurrentQuads()
	* is to be called.
	*/
	void Begin(PDFDoc& doc);

	/**
	* Query if there is any subsequent highlight after the current highlight.
	*/
	bool HasNext() const;

	/**
	* Move the current highlight to the next highlight.
	*/
	void Next();

	/**
	* Get the page number of the current highlight.
	*/
	int GetCurrentPageNumber() const;

	/**
	* Get the corresponding quadrangles of the current highlight.
	* 
	* @param quads the output pointer to the resulting quadrangles.
	*
	* @return the number of the resulting quadrangles. Each quadrangle has
	* eight doubles (x1, y1), (x2, y2), (x3, y3), (x4, y4) denoting the four 
	* vertices in counter-clockwise order.
	*
	* @note the 'quads' array is owned by the current Highlights and does not need to be 
	* explicitly released. Since a highlight may correspond to multiple quadrangles, e.g., 
	* when it crosses a line, the number of resulting quadrangles may be larger than 1.
	*/
	std::vector<QuadPoint> GetCurrentQuads() const;

#ifndef SWIG
	int GetCurrentQuads(const double* &quads) const;
#endif

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

	 
  //for xamarin use only
	 static Highlights* CreateInternal(ptrdiff_t impl);
	 ptrdiff_t GetHandleInternal();

#ifndef SWIGHIDDEN
    
//private:
     TRN_Highlights mp_highlights;
    //for xamarin use only
	Highlights(TRN_Highlights impl) : mp_highlights(impl) {}
#endif
};


#include <Impl/Highlights.inl>

	}	// namespace PDF
}	// namespace pdftron

#endif // PDFTRON_H_CPPHighlights
