//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsFreeText
#define PDFTRON_H_CPPPDFAnnotsFreeText

#include <PDF/Annots/Line.h>
#include <PDF/QuadPoint.h>

#ifdef SWIG
#define Line LineAnnot
#endif

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A FreeText annotation (PDF 1.3) displays text directly on the page. 
 * Unlike an ordinary Text annotation, a FreeText annotation has no 
 * open or closed state; The content of the FreeText annotation is always
 * visible instead of being displayed in a popup window.
 */
class FreeText : public Markup
{
	public:	
		/** 
		 * Creates a FreeText annotation and initializes it using given Cos/SDF object.
		 * @param d The Cos/SDF object to initialze the annotation with.
		 * @note The constructor does not copy any data, but is instead the logical
		 * equivalent of a type cast.
		*/
		FreeText(SDF::Obj d = 0);

		/** 
		 * Creates a FreeText annotation and initializes it using given annotation object.
		 * @param ann Annot object used to initialize the FreeText annotation.
		 * @note The constructor does not copy any data, but is instead the logical
		 * equivalent of a type cast.
		*/
		FreeText(const Annot& ann) : Markup(ann.GetSDFObj()) {} 
		
		/** 
		 * Creates a new FreeText annotation in the specified document.
		 * 
		 * @param doc A document to which the FreeText annotation is added.
		 * @param pos A rectangle specifying the FreeText annotation's bounds in default user space units.
		 * 
		 * @return A newly created blank FreeText annotation.
		*/
		static FreeText Create(SDF::SDFDoc& doc, const Rect& pos);
	
		/** 
		 * Returns the default appearance of the FreeText annotation. 
		 * 
		 * @return A string representing the default appearance of the annotation. 
		 * @note The default appearance string is used to format the text.
		 * The annotation dictionary's Appearance entry, if present, 
		 * will take precedence over this entry. 
		 * @note this method corresponds to the 'DA' entry in the annotation dictionary.
		 */
		UString GetDefaultAppearance() const;

		/** 
		 * Sets the default appearance of the FreeText annotation.  
		 * 
		 * @param app_str A string representing the default appearance of the annotation. 
		 * @note The default appearance string is used to format the text.
		 * The annotation dictionary's Appearance entry, if present, 
		 * will take precedence over this entry. 
		 * @note this method corresponds to the 'DA' entry in the annotation dictionary.
		*/
		void SetDefaultAppearance(const char* app_str);

		/**						 
		 * Returns the quading format of the FreeText annotation. 
		 * (PDF 1.4)
		 * 
		 * @return A int (code) indicating the quading format of the FreeText annotation.
		 * @note The following are the quading formats corresponding to each int code.
		 * 0 Left-justified
		 * 1 Centered
		 * 2 Right-justified
		*/
		int GetQuaddingFormat() const;

		/**
		 * Sets the quading format of the FreeText annotation. 
		 * (Optional; PDF 1.4)						
		 * 
		 * @param format A int code indicating the quading format of the FreeText annotation.
		 * Default value: 0 (left-justified).
		 * @note The int code specifies the form of quadding (justification) 
		 * that shall be used in displaying the annotation's text:
		 * 0 Left-justified
		 * 1 Centered
		 * 2 Right-justified
		*/
		void SetQuaddingFormat(const int format);

		/** 						 
		 * Returns the callout line points of the FreeText annotation. 
		 * (PDF 1.6)
		 * 
		 * @param p1 The target point. (where the ending style is used)
		 * @param p2 The ending point.
		 * @param p3 The knee point.
		 * @return Three point objects if the line is bent or two point objects if
		 * the line is straight.
		 * @note If the line is straight, i.e. only has two points, 
		 * two points will be returned in p1 and p2, and p3 will be the same as p2.
		 * The coordinates are given in default user space. 
		*/
		Point GetCalloutLinePoint1() const;
		Point GetCalloutLinePoint2() const;
		Point GetCalloutLinePoint3() const;

#ifndef SWIG
		/**
		 * Returns the callout line points of the FreeText annotation.
		 * (PDF 1.6)
		 *
		 * @param p1 The target point. (where the ending style is used)
		 * @param p2 The ending point.
		 * @param p3 The knee point.
		 * @return Three point objects if the line is bent or two point objects if
		 * the line is straight.
		 * @note If the line is straight, i.e. only has two points,
		 * two points will be returned in p1 and p2, and p3 will be the same as p2.
		 * The coordinates are given in default user space.
		*/
		void GetCalloutLinePoints(Point& p1, Point& p2, Point& p3) const;
#endif
		
		/** 
		 * Sets the callout line points of the FreeText annotation.
		 * (Optional; meaningful only if IT is FreeTextCallout; PDF 1.6)						 
		 * 
		 * @param p1 The target point. (where the ending style is used)
		 * @param p2 The knee point.
		 * @param p3 The ending point. 
		 * @note The coordinates are defined in default user space.  
		*/
		void SetCalloutLinePoints(const Point& p1, const Point& p2, const Point& p3); 

		/** 
		 * Sets the callout line points of the FreeText annotation.
		 * (Optional; meaningful only if IT is FreeTextCallout; PDF 1.6)						 
		 * 
		 * @param p1 The target point. (where the ending style is used)
		 * @param p2 The ending point.
		 * @note The coordinates are defined in default user space. 
		*/
		void SetCalloutLinePoints(const Point& p1, const Point& p2);


		/** 
		 * This enum defines the intention of the FreeText annotation
		*/
		enum IntentName
		{
			e_FreeText,				///<The annotation intended to function as a plain FreeText annotation. 
			e_FreeTextCallout,		///<The annotation is intended to function as a callout. 
			e_FreeTextTypeWriter,	///<The annotation is intended to function as a click-to-type or typewriter object and no callout line is drawn.
			e_Unknown				///<User defined or Invalid.
		};

		/**	
		 * Returns Intent name of the FreeText annotation. 
		 * (PDF 1.4)
		 * 
		 * @return The intent name of the annotation as 
		 * an entry from the enum "IntentName".
		*/
		IntentName GetIntentName() const;

		/**
		 * Sets the Intent name of the FreeText annotation. 
		 * (Optional; PDF 1.4)
		 * 
		 * @param mode The intent name of the annotation as 
		 * an entry from the enum "IntentName".
		*/
		void SetIntentName(IntentName mode=e_FreeText);

		/**						 
		 * Returns the ending style of the callout line of the FreeText Annotation. 
		 * 
		 * @return The ending style represented as one of the entries of the enum "EndingStyle"
		 * @note The ending style specifies the line ending style that 
		 * shall be used in drawing the callout line specified in CallOut Line Points
		 * (CL). The enum entry shall specify the line ending style for the endpoint 
		 * defined by the target point(p1) of the CallOut Line Points. 
		 * Default value: e_None.
		 */
		Line::EndingStyle GetEndingStyle() const;

		/**
		 * Sets the ending style of the callout line of the FreeText Annotation. 
		 * (Optional; meaningful only if CL is present; PDF 1.6)						  
		 * 
		 * @param style The ending style represented using one of the 
		 * entries of the enum "EndingStyle"
		 * @note The ending style specifies the line ending style that 
		 * shall be used in drawing the callout line specified in CallOut Line Points
		 * (CL). The enum entry shall specify the line ending style for the endpoint 
		 * defined by the target point(p1) of the CallOut Line Points. 
		 * Default value: e_None.
		 */
		void SetEndingStyle( Line::EndingStyle style);

		/** 
		 * Sets the ending style of the callout line of the FreeText Annotation. 
		 * (Optional; meaningful only if CL is present; PDF 1.6)						 
		 * 
		 * @param est The ending style represented using a string. 
		 * @note The ending style specifies the line ending style that 
		 * shall be used in drawing the callout line specified in CallOut Line Points
		 * (CL). The enum entry shall specify the line ending style for the endpoint 
		 * defined by the target point(p1) of the CallOut Line Points. 
		 * Default value: "None".
		 */
		void SetEndingStyle(const char* est);

		/** 
		 * Sets the text color of the FreeText Annotation.
		 * 
		 * @param color ColorPt object representing the color.
		 * @param col_comp number of colorant components in ColorPt object.
		 *
		 * @note Current implementation of this method creates a non-standard
		 * entry in the annotation dictionary and uses it to generate the appearance
		 * stream. Make sure you call RefreshAppearance() after changing text or
		 * line color, and remember that editing the annotation in other PDF
		 * applications will produce different appearance.
		 */
		void SetTextColor( const ColorPt& color, int col_comp );
		
		/** 
		 * Returns the text color of the FreeText Annotation.
		 * 
		 * @note Current implementation of this method uses a non-standard
		 * entry in the annotation dictionary and will not return meaningful
		 * results when called on annotations not created with PDFTron software.
		 */
		ColorPt GetTextColor();

		int GetTextColorCompNum();

#ifndef SWIG
		/**
		 * Returns the text color of the FreeText Annotation.
		 *
		 * @param color reference to ColorPt object, where results will be saved.
		 * @param col_comp reference to an integer,
		 * where number of colorant components will be written.
		 *
		 * @note Current implementation of this method uses a non-standard
		 * entry in the annotation dictionary and will not return meaningful
		 * results when called on annotations not created with PDFTron software.
		 */
		void GetTextColor( ColorPt& color, int& col_comp );
#endif

		/** 
		 * Sets the line and border color of the FreeText Annotation.
		 * 
		 * @param color ColorPt object representing the color.
		 * @param col_comp number of colorant components in ColorPt object.
		 *
		 * @note Current implementation of this method creates a non-standard
		 * entry in the annotation dictionary and uses it to generate the appearance
		 * stream. Make sure you call RefreshAppearance() after changing text or
		 * line color, and remember that editing the annotation in other PDF
		 * applications will produce different appearance.
		 */
		void SetLineColor( const ColorPt& color, int col_comp );

		/** 
		 * Returns the line and border color of the FreeText Annotation.
		 * 
		 * @param color reference to ColorPt object, where results will be saved.
		 * @param col_comp reference to an integer, 
		 * where number of colorant components will be written.
		 *
		 * @note Current implementation of this method uses a non-standard
		 * entry in the annotation dictionary and will not return meaningful
		 * results when called on annotations not created with PDFTron software.
		 */
		ColorPt GetLineColor();
		int GetLineColorCompNum();

#ifndef SWIG
		/**
		 * Returns the line and border color of the FreeText Annotation.
		 *
		 * @param color reference to ColorPt object, where results will be saved.
		 * @param col_comp reference to an integer,
		 * where number of colorant components will be written.
		 *
		 * @note Current implementation of this method uses a non-standard
		 * entry in the annotation dictionary and will not return meaningful
		 * results when called on annotations not created with PDFTron software.
		 */
		void GetLineColor(  ColorPt& color, int& col_comp );
#endif
		/**
		 * Sets the default appearance font size. A value of zero specifies
		 * that the font size should should adjust so that the text uses
		 * as much of the FreeText bounding box as possible.
		 *
		 * @param font_size Set the default font size. A value of zero means
		 * auto resize font.
		 */
		void SetFontSize( double font_size );

		/**
		 * Get the default appearance font size. To get the actual font
		 * size used, call RefreshAppearance and then use ElementReader
		 * on the content stream of this annotation.
		 *
		 * @return the default font size, where a value of zero indicates
		 * auto sizing.
		 */
		double GetFontSize();

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
		FreeText(TRN_Annot freetext);
	#endif
	// @endcond

};//class FreeText

			} //namespace Annot
		} //namespace PDF
} //namespace pdftron

#ifdef SWIG
#undef Line
#endif

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsFreeText
