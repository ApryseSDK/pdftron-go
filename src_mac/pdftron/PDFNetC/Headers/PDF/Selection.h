//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSelection
#define PDFTRON_H_CPPSelection

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_PDFView.h>
namespace pdftron {
	namespace PDF {
	/**
	 * A class representing the current text selection.
	 */
	class Selection {
		friend class PDFView;
		friend class PDFViewCtrl;
	public:
		/** 
		 * @return the page number containing the selected text.
		 */
		 int GetPageNum() const;

		/** 
		* Returns the list of tight bounding quads in the current text selection.
		* @param quads - Sets a pointer to an array of vertices representing 
		* a list of bounding quads for the selected text. Each bounding quad is 
		* represented using 8 numbers in an array of doubles. Each two consecutive
		* values represent the x and y coordinates of a quad vertex and the four
		* vertices are arranged counter-clockwisely,
		*
		*			3--------2
		*			|        |
		*			|        |
		*			|        |
		*			0--------1
		*
		* e.g., (quad[0], quad[1]) is the coordinate of vertex 0, and 
		* (quad[4], quad[5]) is the coordinate of vertex 2. Note that it is only ensured
		* that the four vertices are arranged sequentially; it is possible in practice that 
		* (quad[0], quad[1]) is the coordinate of any vertex. 
		*
		* @return the number of quads in 'quads' array.
		* 
		* @note the 'quads' array is owned by the current selection and does
		* not need to be explicitly released.
		*/
		 std::vector<QuadPoint> GetQuads() const;


		/** 
		 * @return the current text selection represented as an Unicode string.
		 */
		 UString GetAsUnicode() const;


		/** 
		 * @return the current text selection in HTML format. HTML text will 
		 * contain styling information such as text color, font size, style etc.
		 * @note this function can be used to implement clipboard copy and paste
		 * that preserves text formating.
		 */
		 const char* GetAsHtml() const;

#if !defined(SWIG)
		 int GetQuads(const double* & quads) const;
		 void GetAsUnicode(UString& out_str) const;
#endif // !defined(SWIG)

		// @cond PRIVATE_DOC

#ifndef SWIGHIDDEN
		 ~Selection();
		 Selection();
		 Selection(const Selection&);
		 Selection& operator=(const Selection&);
		 Selection(TRN_PDFViewSelection impl);
	private:
		TRN_PDFViewSelection mp_selection;
#endif
		// @endcond

	};

	inline Selection::Selection()
	{
		REX(TRN_PDFViewSelectionCreate(&mp_selection));
	}
	
	inline Selection::~Selection()
	{
		DREX(mp_selection, TRN_PDFViewSelectionDestroy(mp_selection));
	}

	inline Selection::Selection(const Selection& s)
	{
		REX(TRN_PDFViewSelectionCreate(&mp_selection));
		REX(TRN_PDFViewSelectionAssign(mp_selection,s.mp_selection));
	}

	inline Selection::Selection(TRN_PDFViewSelection impl) : mp_selection(impl)
	{

	}

	inline Selection& Selection::operator=(const Selection& s)
	{
		REX(TRN_PDFViewSelectionAssign(mp_selection,s.mp_selection));
		return *this;
	}



	inline int Selection::GetPageNum() const
	{
		RetInt(TRN_PDFViewSelectionGetPageNum(mp_selection,&result));
	}

	//inline int Selection::GetRects(const double* &rects) const
	//{
	//	RetInt(TRN_PDFViewSelectionGetRects(&mp_selection,&rects,&result));
	//}

	inline std::vector<QuadPoint> Selection::GetQuads() const
	{
		int num;
		double* quads;
		TRN_PDFViewSelectionGetQuads(mp_selection,(const double**)&quads,&num);
		std::vector<QuadPoint> result(num);
		int i;
		for(i = 0; i < num; i++) {
			Point p1 = Point(quads[i*8+0], quads[i*8+1]);
			Point p2 = Point(quads[i*8+2], quads[i*8+3]);
			Point p3 = Point(quads[i*8+4], quads[i*8+5]);
			Point p4 = Point(quads[i*8+6], quads[i*8+7]);
			result[i] = QuadPoint(p1, p2, p3, p4);
		}
		return result;
	}

	inline UString Selection::GetAsUnicode() const
	{
		UString unicodeStr;
		REX(TRN_PDFViewSelectionGetAsUnicode(mp_selection, unicodeStr.mp_impl));
		return unicodeStr;
	}

	inline const char* Selection::GetAsHtml() const
	{
		RetCCS(TRN_PDFViewSelectionGetAsHtml(mp_selection, &result));
	}

#if !defined(SWIG)
	inline int Selection::GetQuads(const double* & quads) const
	{
		RetInt(TRN_PDFViewSelectionGetQuads(mp_selection,&quads,&result));
	}

	inline void Selection::GetAsUnicode(UString& out_str) const
	{
		REX(TRN_PDFViewSelectionGetAsUnicode(mp_selection, out_str.mp_impl));
	}
#endif // !defined(SWIG)

	} // PDF
} // PDFTron


#endif // PDFTRON_H_CPPSelection
