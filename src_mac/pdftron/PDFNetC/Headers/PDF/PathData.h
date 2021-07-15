//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPathData
#define PDFTRON_H_CPPPDFPathData

#include <vector>

namespace pdftron {
	namespace PDF {

/**
 * Contains the information required to draw the path. Contains an array of 
 * PathSegmentType Operators and corresponding path data Points. A point may 
 * be on or off (off points are control points). The meaning of a point 
 * depends on associated id (or segment type) in the path segment type array.
 */
class PathData 
{
public:
	/**
	 * Enumeration used to indicate operator type.
	 */
	enum PathSegmentType
	{
		// Start a new sub-path at the given (x,y) coordinate.
		// Number of arguments: 2
		e_moveto = 1,

		// A line from the current point to the given (x,y) coordinate which becomes 
		// the new current point.
		// Number of arguments: 2
		e_lineto,		 

		// A cubic Bezier curve from the current point to (x,y) using (x1,y1) as
		// the control point at the beginning of the curve and (x2,y2) as the control
		// point at the end of the curve.
		// Number of arguments: 6
		e_cubicto,

		// A quadratic Bezier curve from the current point to (x,y) using (x1,y1) as
		// the control point. Note that e_conicto does not appear in PDF content streams.
		// This operator is only used to represent glyph outlines (e.g. PDF::Font::GetGlyphPath()
		// may return a path containing e_conicto operator).
		// Number of arguments: 4
		e_conicto,		

		// A rectangle at the given (x,y) coordinate and the given width and height (w, h).
		// Number of arguments: 4
		e_rect,

		// Close the current subpath by drawing a straight line from the current point 
		// to current subpath's initial point.
		// Number of arguments: 0
		e_closepath
	};
	
	/**
	 * Create a new empty PathData object.
	 */
	PathData() : is_def(true), glyph_index(0) {};
	
	/**
	 * Overwrite the existing operators.
	 *
	 * @param operators - The new operators to use.
	 */
	void SetOperators(const std::vector<unsigned char>& operators) {
		oprs = operators;
	};

	/**
	 * Overwrite the existing data points.
	 *
	 * @param points - The new data points to use.
	 */
	void SetPoints(const std::vector<double>& points) {
		pts = points;
	};
	
	/**
	 * Get the current operators.
	 *
	 * @return The existing PathSegmentType operators.
	 */
#ifdef SWIG
  	std::vector<unsigned char> GetOperators() const {
		return oprs;
	};  
#else
	const std::vector<unsigned char>& GetOperators() const {
		return oprs;
	};
#endif
    
	/**
	 * Get the current data points.
	 *
	 * @return The existing data points.
	 */
#ifdef SWIG
	std::vector<double> GetPoints() const {
		return pts;
	};  
#else    
	const std::vector<double>& GetPoints() const {
		return pts;
	};
#endif

	/**
	 * If PathData was acquired from Font::GetGlyphPath then is
	 * method will indicate if this is an 'undefined character code'.
	 *
	 * @return True if this is valid, otherwise false.
	 *
	 * @note See Font::GetGlyphPath for more information regarding
	 * what an 'undefined character code' means.
	 */
	bool IsDefined() const {
		return is_def;
	};

	/**
	 * @return The glyph index of the requested path. 0 stands for '.notdef' glyph.
	 */
	int GetGlyphIndex() const {
		return glyph_index;
	}

	

// @cond PRIVATE_DOC

#ifndef SWIGHIDDEN
	bool is_def;
	int glyph_index;
	std::vector<unsigned char> oprs;
	std::vector<double> pts;
	PathData(bool i, int gi, const std::vector<unsigned char>& o, const std::vector<double>& d) : is_def(i), glyph_index(gi), oprs(o), pts(d) {}
#endif
// @endcond

};

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPathData
