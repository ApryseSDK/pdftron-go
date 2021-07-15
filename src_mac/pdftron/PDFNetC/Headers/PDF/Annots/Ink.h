//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsInk
#define PDFTRON_H_CPPPDFAnnotsInk

#include <PDF/Annots/Markup.h>
#include <PDF/QuadPoint.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * An ink annotation (PDF 1.3) represents a freehand "scribble" composed 
 * of one or more disjoint paths. When opened, it shall display a pop-up 
 * window containing the text of the associated note. 
 */
class Ink : public Markup
{						
	public:	
	/** 
	 * Creates an Ink annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Ink(SDF::Obj d = 0);

	/** 
	 * Creates an Ink annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Ink annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Ink(const Annot& ann) : Markup(ann.GetSDFObj()) {} 
	
	/** 
	 * Creates a new Ink annotation in the specified document.
	 * 
	 * @param doc A document to which the Ink annotation is added.
	 * @param pos A rectangle specifying the Ink annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Ink annotation.
	*/
	static Ink Create(SDF::SDFDoc& doc, const Rect& pos);

	/** 
	 * Returns number of paths in the annotation. 
	 * 
	 * @return An integer representing the number of paths in the 'InkList'
	 * entry of the annotation dictionary.
	 * @note Each path is an array of Point objects specifying points along the path. 
	 * When drawn, the points shall be connected by straight lines or curves 
	 * in an implementation-dependent way.
	*/
	int GetPathCount() const;

	/** 
	 * Returns number of points in a certain stroked path in the InkList. 
	 * 
	 * @param pathindex path index for each the point count is returned. Index starts at 0.
	 * @return An integer representing the number of points in the stroked path of the Ink list. 
	 * @see GetPathCount()
	 */
	int GetPointCount(unsigned int pathindex) const;
	
	/** 
	 * Returns the specific point in a given path. 
	 *
	 * @param pathindex path index for each the point is returned. Index starts at 0.
	 * @param pointindex index of point in the path. Index starts at 0.
	 * @return A Point object for specified path and point index.
	 * @note Each path is an array of Point objects specifying points along the path. 
	 * When drawn, the points shall be connected by straight lines or curves 
	 * in an implementation-dependent way.
	*/					
	Point GetPoint(unsigned int pathindex, unsigned int pointindex) const;

	/** 
	 * Sets the specific point in the Ink List, adding it if needed.
	 * 
	 * @param pathindex An unsigned integer indicating the index of the path.
	 * @param pointindex An unsigned integer indicating the index of the point
	 * within the stroked path indicated by the parameter "pathindex".
	 * @param pt A Point object that is to be assigned.
	 * @note Ink annotation contains an array of paths.
	 * Each path is an array of Point objects specifying points along the path. 
	 * When drawn, the points shall be connected by straight lines or curves 
	 * in an implementation-dependent way.
	 */
	void SetPoint(unsigned int pathindex, unsigned int pointindex, const Point& pt);

	/**
	 * Erase a rectangle area formed by pt1pt2 with width
	 * 
	 * @param pt1 A point object that is one end of the eraser segment
	 * @param pt2 A point object that is the other end of the eraser segment
	 * @param width The half width of the eraser
	 * @return Whether an ink stroke was erased
	 */
	bool Erase(const Point& pt1, const Point& pt2, double width);

	/**
	* Retrieves whether the Ink will draw like a highlighter.
	* @return true if the Ink will draw like a highlighter. (multiply blend mode)
	* If false it will draw in normal mode. (normal blend mode)
	*/
	bool GetHighlightIntent();

	/**
	 * Enables or disables the Ink drawing like a highlighter.
	 * @param highlight true if the Ink will draw like a highlighter. (multiply blend mode)
	 * If false it will draw in normal mode. (normal blend mode)
	 */
	void SetHighlightIntent(bool highlight);

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
		Ink(TRN_Annot ink);
#endif
// @endcond
}; //class Ink
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsInk
