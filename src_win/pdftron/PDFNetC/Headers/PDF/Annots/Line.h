//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsLine
#define PDFTRON_H_CPPPDFAnnotsLine

#include <PDF/Annots/Markup.h>
#include <PDF/QuadPoint.h>

#ifdef SWIG
#define Line LineAnnot
#endif

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A line annotation (PDF 1.3) is used to display a single straight 
 * line on the page. When opened, it should display a pop-up window containing 
 * the text of the associated note. 
 */
class Line : public Markup
{
public:
	/** 
	 * Creates a Line annotation and initializes it using given Cos/SDF object.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Line(SDF::Obj d=0);
	
	/** 
	 * Creates a Line annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Line annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Line(const Annot& ann) : Markup(ann.GetSDFObj()) {}	


	/** 
	 * Creates a new Line annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Line annotation.
	 */
	static Line Create(SDF::SDFDoc& doc, const Rect& pos);					
	

	/** 
	 * Returns the coordinates of the start of a line.
	 * 
	 * @return A point specifying the coordinates of the start of the line. 
	 */
	Point GetStartPoint() const;

	/** 
	 * Sets the coordinates of the start of a line.
	 * @param sp  A point specifying the coordinates of the end of the line. 
	 * 
	 */
	void SetStartPoint(const Point& sp);

	/** 
	 * Returns the coordinates of the end of a line.
	 * 
	 * @return A point specifying the coordinates of the end of the line. 
	 */
	Point GetEndPoint () const;

	/** 
	 * Sets the coordinates of the end of a line.
	 * @param ep - A point specifying the coordinates of the end of the line. 
	 * 
	 */
	void SetEndPoint(const Point& ep);				

	/**
	* For each line, one can choose a separate style for the start and the end of the line.
	* The styles are defined by the "EndingStyle" enumeration.
	*/
	enum EndingStyle
	{
		e_Square,	///< A square filled with the annotation's interior color, if any
		e_Circle,	///< A circle filled with the annotation's interior color, if any
		e_Diamond,	///< A diamond shape filled with the annotation's interior color, if any
		e_OpenArrow,	///< Two short lines meeting in an acute angle to form an open arrowhead
		e_ClosedArrow,	///< Two short lines meeting in an acute angle as in the OpenArrow style and connected by a third line to form a triangular closed arrowhead filled with the annotation's interior color, if any
		e_Butt,	///< A short line at the endpoint perpendicular to the line itself
		e_ROpenArrow,  ///< Two short lines in the reverse direction from OpenArrow
		e_RClosedArrow, ///< A triangular closed arrowhead in the reverse direction from ClosedArrow
		e_Slash,	///< A short line at the endpoint approximately 30 degrees clockwise from perpendicular to the line itself
		e_None,	///< No special line ending
		e_Unknown	///< Non-standard or invalid ending
	};

	 /**
	 * Returns the ending style that applies to the first point of the line.
	 * 
	 * @return A enum value from the "EndingStyle".
	 * @note Default value: e_None. 
	 */
	EndingStyle GetStartStyle() const;


	/** 
	 * Sets the ending style that applies to the first point of the line.
	 * (Optional; PDF 1.4.)
	 * 
	 * @param sst A enum value from the "EndingStyle".
	 * @note Default value: e_None. 
	 */
	void SetStartStyle(EndingStyle sst);

	
	/** 
	 * Returns the ending style  that applies to the second point of the line.
	 * 
	 * @return A enum value from the "EndingStyle".
	 * @note Default value: e_None. 
	 */
	EndingStyle GetEndStyle() const;


	/** 
	 * Sets the ending style  that applies to the second point of the line.
	 * (Optional; PDF 1.4)
	 * 
	 * @param est A enum value from the "EndingStyle".
	 * @note Default value: e_None. 
	 */
	void SetEndStyle(EndingStyle est);



	/** 
	 * Returns the leader line length of a line. 
	 *
	 * @return A number denoting the length of the leader line in default user space units.
	 * @note Usually if this entry is specified, the line is intended to be a dimension line (see 
	 * "IT" entry of the annotation dictionary). 
	 * @note Leader length is length of leader lines in default user space that extend from each endpoint 
	 * of the line perpendicular to the line itself. A positive value shall mean that the leader lines 
	 * appear in the direction that is clockwise when traversing the line from its starting point to 
	 * its ending point (as specified by L); a negative value shall indicate the opposite direction.
	 * Default value: 0 (no leader lines) 
	 */
	double GetLeaderLineLength() const;

	/** 	
	 * Sets the leader line length of a line.					 
	 * (PDF 1.6)
	 *
	 * @param length A number denoting the length of the leader line in default user space units. 
	 * @note Usually if this entry is specified, the line is intended to be a dimension line (see 
	 * "IT" entry of the annotation dictionary). 
	 * @note Leader length is length of leader lines in default user space that extend from each endpoint 
	 * of the line perpendicular to the line itself. A positive value shall mean that the leader lines 
	 * appear in the direction that is clockwise when traversing the line from its starting point to 
	 * its ending point (as specified by L); a negative value shall indicate the opposite direction.
	 * Default value: 0 (no leader lines)
	 */
	void SetLeaderLineLength(const double& length);
	
	/** 				
	 * Returns the leader line extension length of a line. 
	 *
	 * @return A number denoting the length of the leader line extension in default user space units. 
	 * @note The leader line extension length is a non-negative number that shall represents 
	 * the length of leader line extensions that extend from the line proper 180 degrees from 
	 * the leader lines.
	 * Default value: 0 (no leader line extensions)
	 */
	double GetLeaderLineExtensionLength() const;

	/** 					
	 * Sets the leader line extension length of a line. 
	 * (PDF 1.6)
	 *
	 * @param length A number denoting the length of the leader line extension in default user space units. 
	 * @note The leader line extension length is a non-negative number that shall represents 
	 * the length of leader line extensions that extend from the line proper 180 degrees from 
	 * the leader lines.
	 * Default value: 0 (no leader line extensions)
	 */
	void SetLeaderLineExtensionLength(const double& length);

	/** 					 
	 * Returns true if caption is to be shown, otherwise false.
	 *
	 * @return A boolean value indicating whether the caption will be shown. 
	 * @note If true, the text specified by the Contents or RCentries shall be replicated as a 
	 * caption in the appearance of the line. The text shall be rendered in a manner 
	 * appropriate to the content, taking into account factors such as writing direction.
	 * Default value: false.
	 */
	bool GetShowCaption() const;
	
	/** 			
	 * Sets the option of whether to show caption. 
	 *
	 * @param showCaption A boolean value indicating whether the caption will be shown. 
	 * @note If true, the text specified by the Contents or RC entries shall be replicated as a 
	 * caption in the appearance of the line. The text shall be rendered in a manner 
	 * appropriate to the content, taking into account factors such as writing direction.
	 * Default value: false.
	 */
	void SetShowCaption(bool showCaption); 

	/**					 
	 * This enum represents the intent of the Line annotation.
	 * For each line, one can specify the purpose of the line by choosing its intent   
	 * defined by the "IntentType" enum. 
	*/
	enum IntentType
	{
		e_LineArrow,  ///< Line is an arrow 
		e_LineDimension, ///< Line is a dimension
		e_null
	};
	
	/** 					
	 * Returns the intent type of the line. 
	 *
	 * @return An intent type value from the "IntentType" enum. 
	 * @note Intent type describes the intent of the line annotation. Valid values shall be "e_LineArrow", which means 
	 * that the annotation is intended to function as an arrow, and "e_LineDimension", which means that the annotation 
	 * is intended to function as a dimension line.
	 */
	IntentType GetIntentType() const;

	/** 
	 * Sets the intent type of the line. 
	 * (For PDF 1.6)
	 *
	 * @param it An intent type value from the "IntentType" enum. 
	 * @note Intent type describes the intent of the line annotation. Valid values shall be "e_LineArrow", which means 
	 * that the annotation is intended to function as an arrow, and "e_LineDimension", which means that the annotation 
	 * is intended to function as a dimension line.
	 */
	void SetIntentType(IntentType it);

	/** 
	 * Returns the leader line offset length of a line. 					 
	 *
	 * @return A number denoting the length of the leader line offset in default user space units. 
	 * @note Leader line offset number is a non-negative number that shall represent the length of the leader 
	 * line offset, which is the amount of empty space between the endpoints of the 
	 * annotation and the beginning of the leader lines.
	 */
	double GetLeaderLineOffset() const;

	/** 
	 * Sets the leader line offset length of a line. 
	 * (PDF 1.7)
	 *
	 * @param length A number denoting the length of the leader line offset in default user space units. 
	 * @note Leader line offset number is a non-negative number that shall represent the length of the leader 
	 * line offset, which is the amount of empty space between the endpoints of the 
	 * annotation and the beginning of the leader lines.
	 */
	void SetLeaderLineOffset(double length);
	
	/**
	 * Enumeration type describing the annotation's caption positioning. 
	 * Valid values are e_Inline, meaning the caption shall be centered inside the line,
	 * and e_Top, meaning the caption shall be on top of the line.
	*/
	enum CapPos
	{
		e_Inline, ///< the caption shall be centered inside the line
		e_Top ///< the caption shall be on top of the line
	};

	/** 
	 * Returns the caption position of a line. 					 
	 *
	 * @return A cap position value from the "CapPos" enum. 
	 * @note Caption position describes the annotation's caption positioning. 
	 * Default value: Inline
	 * @see CapPos
	 */
	CapPos GetCaptionPosition() const;

	/** 
	 * Sets the caption position of a line. 
	 * (Optional, PDF 1.7)
	 *
	 * @param style A caption position value from the "CapPos" enum. 
	 * @note Caption position describes the annotation's caption positioning. 
	 * Default value: Inline
	 * @see CapPos 
	 */
	void SetCaptionPosition(const CapPos& style);

	/** 
	 * Returns the horizontal offset of the caption. 					 
	 *
	 * @return A number denoting the horizontal offset of the caption in default user space units. 

	 * @note The horizontal offset specifies the offset of the caption text from the line's midpoint, 
	 * with a positive value indicating offset to the right and a negative value indicating offset to the left.
	 * Default value: 0 (no offset from normal horizontal positioning).
	 */
	double GetTextHOffset() const;

	/** 
	 * Sets the horizontal offset of the caption. 
	 * (For PDF 1.7 )
	 *
	 * @param offset A number denoting the horizontal offset of the caption in default user space units. 
	 * @note The horizontal offset specifies the offset of the caption text from the line's midpoint, 
	 * with a positive value indicating offset to the right and a negative value indicating offset to the left.
	 * Default value: 0 (no offset from normal horizontal positioning).
	 */
	void SetTextHOffset(double offset);

	/** 
	 * Returns the vertical offset of the caption. 					 
	 *
	 * @return A number denoting the vertical offset of the caption in default user space units. 
	 * @note The vertical offset specifies the offset of the caption text perpendicular to the annotation line, 
	 * with a positive value indicating a shift up and a negative value indicating a shift down.
	 * Default value: 0 (no offset from normal vertical positioning).
	 */
	double GetTextVOffset() const;

	/** 
	 * Sets the vertical offset of the caption. 
	 * (For PDF 1.7 )
	 *
	 * @param offset A number denoting the vertical offset of the caption in default user space units. 
	 * @note The vertical offset specifies the offset of the caption text perpendicular to the annotation line, 
	 * with a positive value indicating a shift up and a negative value indicating a shift down.
	 * Default value: 0 (no offset from normal vertical positioning).
	 */
	void SetTextVOffset(double offset);

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	Line(TRN_Annot line);
#endif
// @endcond

};//class Line
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron

#ifdef SWIG
#undef Line
#endif

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsLine
