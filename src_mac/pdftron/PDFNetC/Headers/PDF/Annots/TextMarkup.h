//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsTextMarkup
#define PDFTRON_H_CPPPDFAnnotsTextMarkup

#include <PDF/Annots/Markup.h>
#include <PDF/QuadPoint.h>


namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A TextMarkup is a base class for highlight, underline, 
 * strikeout, and squiggly annotations. 
 */
class TextMarkup : public Markup
{
	public:	
	/** 
	 * Creates a TextMarkup annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	 TextMarkup(SDF::Obj d);

	/** 
	 * Creates a TextMarkup annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the TextMarkup annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	 TextMarkup(const Annot& ann) : Markup(ann.GetSDFObj()) {} 

	/** 
	 * Returns the number of QuadPoints in the QuadPoints array of the TextMarkup annotation 
	 * (PDF 1.6)
	 * 
	 * @return The number of QuadPoints. 
	 * @note QuadPoints specify the coordinates of quadrilaterals in default user space. Each quadrilateral 
	 * encompasses a word or group of contiguous words in the text underlying the annotation. 
	 * The four points(p1, p2, p3, p4) of a QuadPoint specify the quadrilateral's four vertices 
	 * in counterclockwise order. 
	 * The text needs to be oriented with respect to the edge connecting points (p1) and (p2).
	 * The annotation dictionary's Appearance entry, if present, takes precedence over QuadPoints.
	*/
	 int GetQuadPointCount();

	/** 						 
	 * Returns the QuadPoint located at a certain index of the QuadPoint array.
	 * (PDF 1.6)
	 * 
	 * @param idx The index where the QuadPoint is located. The index starts at zero and must be less than return value of GetQuadPointCount().
	 * @return The QuadPoint located at a certain index of the QuadPoint array of the TextMarkup annotation. 
	 * @note QuadPoints specify the coordinates of quadrilaterals in default user space. Each quadrilateral 
	 * encompasses a word or group of contiguous words in the text underlying the annotation. 
	 * The four points(p1, p2, p3, p4) of a QuadPoint specify the quadrilateral's four vertices 
	 * in counterclockwise order. 
	 * The text needs to be oriented with respect to the edge connecting points (p1) and (p2).
	 * The annotation dictionary's Appearance entry, if present, takes precedence over QuadPoints.
	*/
	 QuadPoint GetQuadPoint(int idx) const;

	/** 
	 * Sets the QuadPoint to be located at a certain index of the QuadPoint array.
	 * (Optional; PDF 1.6 )
	 * 
	 * @param idx The index where the QuadPoint is to be located (the index is counted from 0).
	 * @param qp The QuadPoint to be located at a certain index of the QuadPoint array of the TextMarkup annotation. 
     * @attention To make this QuadPoint compatible with Adobe Acrobat|Reader, you can use either clockwise or counterclockwise order,
     * but the points p3 and p4 must be swapped. This is because those readers do not follow the PDF specification for TextMarkup QuadPoints.
	 * @note An array of n QuadPoints specifying the coordinates of n quadrilaterals in default user space. Each quadrilateral shall 
	 * encompasses a word or group of contiguous words in the text underlying the annotation. The coordinates for each quadrilateral 
	 * shall be given in the order p1, p2, p3, p4 specifying the quadrilateral's four vertices in counterclockwise order. 
	 * The text shall be oriented with respect to the edge connecting points (p1) and (p2).
	 * The annotation dictionary's Appearance(AP) entry, if present, shall take precedence over QuadPoints.
	*/
	 void SetQuadPoint(int idx, const QuadPoint& qp); 

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TextMarkup(TRN_Annot textmarkup);
#endif
// @endcond

				};//class TextMarkup
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsTextMarkup
