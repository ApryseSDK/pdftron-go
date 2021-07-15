//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsLink
#define PDFTRON_H_CPPPDFAnnotsLink

#include <PDF/Annot.h>
#include <PDF/QuadPoint.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {

/**
 * A link annotation represents either a hypertext link to a destination elsewhere in the document 
 * or an action to be performed. 
*/
class Link : public Annot
{
	public:	
		/** 
		 * Creates a Link annotation and initializes it using given Cos/SDF object.
		 * @param d The Cos/SDF object to initialze the annotation with.
		 * @note The constructor does not copy any data, but is instead the logical
		 * equivalent of a type cast.
		 */
		Link(SDF::Obj d = 0);

		/** 
		 * Creates a Link annotation and initializes it using given annotation object.
		 * @param ann Annot object used to initialize the Link annotation.
		 * @note The constructor does not copy any data, but is instead the logical
		 * equivalent of a type cast.
		*/
		Link(const Annot& ann) : Annot(ann.GetSDFObj()) {} 

		/** 
		 * Creates a new Link annotation in the specified document.
		 * 
		 * @param doc A document to which the Link annotation is added.
		 * @param pos A rectangle specifying the Link annotation's bounds in default user space units.
		 * 
		 * @return A newly created blank Link annotation.
		*/
		static Link Create(SDF::SDFDoc& doc, const Rect& pos);

		/** 
		 * Creates a new Link annotation.
		 * 
		 * @param doc A document to which the annotation is added.
		 * @param pos A rectangle specifying the annotation's bounds in default user space units.
		 * @param action Action for the link annotation.
		 * 
		 * @return A new Link annotation. 
		*/
		static Link Create(SDF::SDFDoc& doc, const Rect& pos, const Action& action);

		/** 
		 * Removes this annotation's action.
		*/
		void RemoveAction();

		/** 
		 * Returns the Action of the Link Annotation. 
		 * 
		 * @return An Action object of the Link annotation. 
		 * @note The return value is an action that shall be performed when the 
		 * link annotation is activated
		*/
		Action GetAction() const;

		/** 
		 * Sets the Action of the Link Annotation.
		 * (Optional; PDF 1.1 )
		 * 
		 * @param action An Action object that shall be associated with this Link annotation. 
		 * @note The parameter is an action that shall be performed when the 
		 * link annotation is activated.
		*/
		void SetAction(const Action& action);
		 
		 /**
		 * This enum specifies the highlighting mode of the Link Annotation.
		 * The annotation's highlighting mode is the visual effect that shall be used when 
		 * the mouse button is pressed or held down inside its active area, possible values as
		 * follows:
		 * 
		 * e_none - No highlighting. 
		 * e_invert - Invert the contents of the annotation rectangle.  
		 * e_outline - Invert the annotation's border.
		 * e_push - Display the annotation as if it were being pushed below the surface of the page. 
		*/
		 enum HighlightingMode 
		 {
			 e_none,     
			 e_invert,   
			 e_outline,  
			 e_push      
		 };

		/** 					
		 * Returns the highlighting mode of this Link annotation. 
		 *
		 * @return the highLighting mode as a value of the enum "HighlightingMode". 
		 * @note The annotation's highlighting mode is the visual effect that shall be used when 
		 * the mouse button is pressed or held down inside its active area.
		*/
		 HighlightingMode GetHighlightingMode() const;

		/** 				
		 * Sets the highlighting mode for this Link annotation. 
		 * (Optional; PDF 1.2 )
		 * 
		 * @param mode the mode as a value of the enum "HighlightingMode".
		 * @note The annotation's highlighting mode is the visual effect that shall be used when 
		 * the mouse button is pressed or held down inside its active area.
		*/
		 void SetHighlightingMode(HighlightingMode mode);

		 /**				
		 * Returns the number of QuadPoints in the 'QuadPoints' array of the Link annotation.
		 *
		 * @return The number of QuadPoints.
		 * @note An array of n QuadPoints specifying the coordinates of n quadrilaterals 
		 * in default user space that comprise the region in which the link should be active. 
		 * The coordinates specifying the four vertices of the quadrilateral are in counterclockwise order. 
		 * For orientation purposes, the bottom of a quadrilateral is the line formed by p1 and p2 of the QuadPoint.  
		 * QuadPoints shall be ignored if any coordinate in the array lies outside the region specified by Rect.
		*/
		 int GetQuadPointCount() const;
		  
		/** 				
		 * Returns the QuadPoint located at a certain index of the QuadPoint array of the Link 
		 * annotation.
		 *
		 * @param idx The index of the QuadPoint, starts at zero and should be less than the return value of GetQuadPointCount().
		 * @return The QuadPoint located at a certain index of the QuadPoint array of the Link annotation. 
		 * @note An array of n QuadPoints specifying the coordinates of n quadrilaterals 
		 * in default user space that comprise the region in which the link should be active. 
		 * The coordinates specifying the four vertices of the quadrilateral are in counterclockwise order. 
		 * For orientation purposes, the bottom of a quadrilateral is the line formed by p1 and p2 of the QuadPoint.
		 * QuadPoints shall be ignored if any coordinate in the array lies outside the region specified by Rect.
		*/
		 QuadPoint GetQuadPoint(int idx) const;

		/** 
		 * Set the QuadPoint to be located at a certain index of the QuadPoint array of the Link annotation. 
		 * (Optional; PDF 1.6 )
		 *
		 * @param idx The index of the QuadPoint, starts at zero and should be less than the return value of GetQuadPointCount().
		 * @param qp  The QuadPoint to be stored in the annotation.
		 * @note An array of n QuadPoints specifying the coordinates of n quadrilaterals 
		 * in default user space that comprise the region in which the link should be active. 
		 * The coordinates specifying the four vertices of the quadrilateral are in counterclockwise order. 
		 * For orientation purposes, the bottom of a quadrilateral is the line formed by p1 and p2 of the QuadPoint.
		 * QuadPoints shall be ignored if any coordinate in the array lies outside the region specified by Rect.
		*/
		 void SetQuadPoint(int idx, const QuadPoint& qp);
    
		/**
		 * Prepends http:// to a string if it does not contain :// or @.
		 * This can be important when passing a url to other APIs that expect a URI scheme.
		 *
		 * @param url The string to possibly be prepended
		 * @return The string that is possibly been prepended.
		*/
		static UString GetNormalizedUrl(const UString& url);

		// @cond PRIVATE_DOC
		#ifndef SWIGHIDDEN 
		Link(TRN_Annot link);
		#endif
		// @endcond

};//class Link
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsLink
