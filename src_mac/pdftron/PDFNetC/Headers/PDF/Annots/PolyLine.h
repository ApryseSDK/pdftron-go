//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsPolyLine
#define PDFTRON_H_CPPPDFAnnotsPolyLine

#include <PDF/Annots/Line.h>
#include <PDF/QuadPoint.h>

#ifdef SWIG
#define Line LineAnnot
#endif

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/**
 * This header defines classes for the Polygon and PolyLine annotations.
 * Polygon annotations (PDF 1.5) display closed polygons on the page. 
 * Such polygons may have any number of vertices connected by straight lines. 
 * Polyline annotations (PDF 1.5) are similar to polygons, except that the 
 * first and last vertex are not implicitly connected.
 */
class PolyLine : public Line
{
	public:	
	/** 
	 * Creates a PolyLine annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	PolyLine(SDF::Obj d = 0);	

	/** 
	 * Creates a PolyLine annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the PolyLine annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	PolyLine(const Annot& ann) : Line(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new PolyLine annotation in the specified document.
	 * 
	 * @param doc A document to which the PolyLine annotation is added.
	 * @param pos A rectangle specifying the PolyLine annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank PolyLine annotation.
	 */
	static PolyLine Create(SDF::SDFDoc& doc, const Rect& pos);

	/** 
	 * Returns the number of vertices in the Vertices array. 
	 * 
	 * @return the number of vertices.
	 * @note The Vertices are the points between which the lines are drawn.
	 * The viewer can draw either the straight lines or the smoothly connecting ones.
	 */
	int GetVertexCount() const;

	/** 
	 * Returns the vertex(as a Point object) corresponding to the index 
	 * within the Vertices array. 
	 * 
	 * @param idx The index of the vertex, should be less than the value returned by GetVertexCount().
	 * @return A Point object corresponding to the vertex in the specified index position.
	 * @note The Vertices are the points between which the lines are drawn.
	 * The viewer can draw either the straight lines or the smoothly connecting ones.
	 */
	Point GetVertex(int idx) const; 
	
	/** 
	 * Sets the vertex(in Point object form) corresponding to the index 
	 * within the Vertices array. 
	 * 
	 * @param idx The index of the vertex.
	 * @param pt A Point object corresponding to the vertex to be added to the array. 
	 * @note The Vertices are the points between which the lines are drawn.
	 * The viewer can draw either the straight lines or the smoothly connecting ones.
	 */
	void SetVertex(int idx, const Point& pt);


	/** 
	 * This enum specifies the intention of the PolyLine annotation, it used
	 * for the purposes of generating the appearance of the annotation.
	*/
	enum IntentType
	{
		e_PolygonCloud,  ///< The annotation is intended to function as a cloud object.
		e_PolyLineDimension, ///< The polyline annotation is intended to function as a dimension. (PDF 1.7)
		e_PolygonDimension, ///< The polygon annotation is intended to function as a dimension. (PDF 1.7)
		e_Unknown           ///< Non-standard intent type
	};

	/**
	 * Returns the intent name as a value of the "IntentName" enumeration type.
	 * 
	 * @return The intent type of the annotation.
	 * @see IntentType
	*/
	IntentType GetIntentName() const;

	/**						
	 * Sets the Intent name as a value of the "IntentName" enumeration type.
	 * (Optional; PDF 1.6 )
	 * 
	 * @param mode The intent name of the annotation.
	 * @see IntentType
	*/
	void SetIntentName(IntentType mode);


#ifndef SWIGHIDDEN
PolyLine(TRN_Annot polyline);
#endif

};//class PolyLine




class Polygon : public PolyLine
{
	public:	
	/** 
	 * Creates a Polygon annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Polygon(SDF::Obj d = 0);	

	/** 
	 * Creates a Polygon annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Polygon annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Polygon(const Annot& ann) : PolyLine(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Polygon annotation in the specified document.
	 * 
	 * @param doc A document to which the Polygon annotation is added.
	 * @param pos A rectangle specifying the Polygon annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Polygon annotation.
	 */
	static Polygon Create(SDF::SDFDoc& doc, const Rect& pos);


#ifndef SWIGHIDDEN
Polygon(TRN_Annot polyline);
#endif

};//class Polygon




			};//namespace Annot
		};//namespace PDF
};//namespace pdftron

#ifdef SWIG
#undef Line
#endif

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsPolyLine
