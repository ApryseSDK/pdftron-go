//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPageLabel
#define PDFTRON_H_CPPPDFPageLabel

#include <C/PDF/TRN_PageLabel.h>
#include <SDF/SDFDoc.h>

namespace pdftron { 
	namespace PDF {

/** 
 * PDF page labels can be used to describe a page. This is used to 
 * allow for non-sequential page numbering or the addition of arbitrary 
 * labels for a page (such as the inclusion of Roman numerals at the 
 * beginning of a book). PDFNet PageLabel object can be used to specify 
 * the numbering style to use (for example, upper- or lower-case Roman, 
 * decimal, and so forth), the starting number for the first page,
 * and an arbitrary prefix to be pre-appended to each number (for 
 * example, "A-" to generate "A-1", "A-2", "A-3", and so forth.)
 *
 * PageLabel corresponds to the PDF Page Label object (Section 8.3.1, 
 * 'Page Labels' in the PDF Reference Manual.
 * 
 * Each page in a PDF document is identified by an integer page index 
 * that expresses the page's relative position within the document. 
 * In addition, a document may optionally define page labels to identify 
 * each page visually on the screen or in print. Page labels and page 
 * indices need not coincide: the indices are fixed, running consecutively 
 * through the document starting from 1 for the first page, but the 
 * labels can be specified in any way that is appropriate for the particular
 * document. For example, if the document begins with 12 pages of front 
 * matter numbered in roman numerals and the remainder of the document is 
 * numbered in Arabic, the first page would have a page index of 1 and a 
 * page label of i, the twelfth page would have index 12 and label xii, 
 * and the thirteenth page would have index 13 and label 1.
 * 
 * For purposes of page labeling, a document can be divided into labeling 
 * ranges, each of which is a series of consecutive pages using the same 
 * numbering system. Pages within a range are numbered sequentially in 
 * ascending order. A page's label consists of a numeric portion based 
 * on its position within its labeling range, optionally preceded by a 
 * label prefix denoting the range itself. For example, the pages in an 
 * appendix might be labeled with decimal numeric portions prefixed with 
 * the string "A-" and the resulting page labels would be "A-1", "A-2", 
 *
 * @note
 * There is no default numbering style; if no 'S' (Style) entry is present, 
 * page labels consist solely of a label prefix with no numeric portion. 
 * For example, if the 'P' entry (Prefix) specifies the label prefix 
 * "Appendix", each page is simply labeled "Appendix" with no page number. 
 * If the 'P' entry is also missing or empty, the page label is an empty 
 * string.
 *
 * Sample code (See PableLabelsTest sample project for examples):
 * @code
 * // Create a page labeling scheme that starts with the first page in 
 * // the document (page 1) and is using uppercase roman numbering 
 * // style. 
 * doc.SetPageLabel(1, PageLabel::Create(doc, PageLabel::e_roman_uppercase, "My Prefix ", 1));
 * 
 * // Create a page labeling scheme that starts with the fourth page in 
 * // the document and is using decimal Arabic numbering style. 
 * // Also the numeric portion of the first label should start with number 
 * // 4 (otherwise the first label would be "My Prefix 1"). 
 * PageLabel L2 = PageLabel::Create(doc, PageLabel::e_decimal, "My Prefix ", 4);
 * doc.SetPageLabel(4, L2);
 * 
 * // Create a page labeling scheme that starts with the seventh page in 
 * // the document and is using alphabetic numbering style. The numeric 
 * // portion of the first label should start with number 1. 
 * PageLabel L3 = PageLabel::Create(doc, PageLabel::e_alphabetic_uppercase, "My Prefix ", 1);
 * doc.SetPageLabel(7, L3);
 * 
 * // Read page labels from an existing PDF document.
 * PageLabel label;
 * for (int i=1; i<=doc.GetPageCount(); ++i) {
 * label = doc.GetPageLabel(i);
 * if (label.IsValid()) {
 *   UString title = label.GetLabelTitle(i);
 * }
 *
 * @endcode
 */
class PageLabel : private TRN_PageLabel
{
public:

	// The numbering style to be used for the numeric portion of page label.
	enum Style 
	{
		e_decimal,              ///< Decimal Arabic numerals
		e_roman_uppercase,      ///< Uppercase Roman numerals
		e_roman_lowercase,      ///< Lowercase Roman numerals
		e_alphabetic_uppercase, ///< Uppercase letters (A to Z for the first 26 pages, AA to ZZ for the next 26, and so on)
		e_alphabetic_lowercase, ///< Lowercase letters (a to z for the first 26 pages, aa to zz for the next 26, and so on)
		e_none                  ///< No numeric portion in the label
	};

	/**
	 * Creates a new PageLabel.
	 * 
	 * @param doc A document to which the page label is added.
	 * @param style The numbering style for the label.
	 * @param prefix The string used to prefix the numeric portion of the 
	 * page label. 
	 * @param start_at the value to use when generating the numeric portion of the first 
	 * label in this range; must be greater than or equal to 1.
	 * 
	 * @return newly created PageLabel object.
	 */
	static PageLabel Create(SDF::SDFDoc& doc, Style style, const UString& prefix = "", int start_at = 1);

	/**
	 * Create a PageLabel and initialize it using given Cos/SDF object.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 */
	PageLabel(SDF::Obj l=0, int first_page=-1, int last_page=-1);

	/**
	 * Copy constructor
	 */
	PageLabel (const PageLabel& d);

	/**
	 * Assignment operator
	 */
	PageLabel& operator=(const PageLabel& d);

	/**
	 * Compares two PageLabel-s for equality. The comparison will return true
	 * only if both labels share the same underlying SDF/Cos object. 
	 * Two labels are also equivalent if they have the same style, starting 
	 * number (numeric value of the first page associated with the label), 
	 * and prefix strings which are the same byte-for-byte.
	 */
	bool operator==(const PageLabel& d);

	/**
	 * @return whether this is a valid (non-null) PageLabel. If the 
	 * function returns false the underlying SDF/Cos object is null or is 
	 * not valid and the PageLabel object should be treated as null as well.
	 */ 	
	bool IsValid() const;

	/** 
	 * @return the full label title that is in effect for the given page.
	 * If there is no label object in effect, this method returns an
	 * empty string.
	 */
	UString GetLabelTitle(int page_num);

	/**
	 * Sets the numbering style for the label.
	 * 
	 * @param style the numbering style for the label.
	 *
	 * You may use label style to customize the page numbering schemes 
	 * used throughout a document. There are three numbering formats:
	 *  - decimal (often used for normal page ranges) 
	 *  - roman (often used for front matter such as a preface)
	 *  - alphabetic (often used for back matter such as appendices)
	 * 
	 * @note
	 * There is no default numbering style; if no 'S' (Style) entry is present, 
	 * page labels consist solely of a label prefix with no numeric portion. 
	 */
	void SetStyle(Style style);

	/**
	 * @return page numbering style.
	 */
	Style GetStyle() const;

	/**
	 * @return the string used to prefix the numeric portion of 
	 * the page label
	 */ 
	UString GetPrefix() const;

	/**
	 * @param prefix the string used to prefix the numeric portion of 
	 * the page label.
	 */ 
	void SetPrefix(const UString& prefix);
	
	/**
	 * @return the value to use when generating the numeric portion of 
	 * the first label in this range; must be greater than or equal to 1.
	 */
	int GetStart() const;

	/**
	 * @param start_at the value to use when generating the numeric 
	 * portion of the first label in this range; must be greater than 
	 * or equal to 1.
	 */
	void SetStart(int start_at);

	/**
	 * @return the first page in the range associated with this label 
	 * or -1 if the label is not associated with any page. 
	 */
	int GetFirstPageNum();
	
	/**
	 * @return the last page in the range associated with this label 
	 * or -1 if the label is not associated with any page. 
	 */
	int GetLastPageNum();

	/**
	 * @return The pointer to the underlying SDF/Cos object.
	 */
	SDF::Obj GetSDFObj () const;

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	PageLabel(const TRN_PageLabel&);
#endif
// @endcond
};



#include <Impl/PageLabel.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPageLabel
