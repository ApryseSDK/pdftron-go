//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPatternColor
#define PDFTRON_H_CPPPDFPatternColor

#include <SDF/Obj.h>
#include <Common/Matrix2D.h>
#include <PDF/Shading.h>
#include <C/PDF/TRN_PatternColor.h>


namespace pdftron { 
	namespace PDF {

/**
 * Patterns are quite general, and have many uses; for example, they can be used 
 * to create various graphical textures, such as weaves, brick walls, sunbursts, 
 * and similar geometrical and chromatic effects.

 * Patterns are specified in a special family of color spaces named Pattern, whose
 * 'color values' are PatternColor objects instead of the numeric component values 
 * used with other spaces. Therefore PatternColor is to pattern color space what is 
 * ColorPt to all other color spaces.
 * 
 * A tiling pattern consists of a small graphical figure called a pattern cell. 
 * Painting with the pattern replicates the cell at fixed horizontal and vertical 
 * intervals to fill an area. The effect is as if the figure were painted on the 
 * surface of a clear glass tile, identical copies of which were then laid down 
 * in an array covering the area and trimmed to its boundaries. This is called 
 * tiling the area.
 * 
 * The pattern cell can include graphical elements such as filled areas, text, 
 * and sampled images. Its shape need not be rectangular, and the spacing of 
 * tiles can differ from the dimensions of the cell itself.
 * 
 * The order in which individual tiles (instances of the cell) are painted is 
 * unspecified and unpredictable; it is inadvisable for the figures on adjacent 
 * tiles to overlap.
 */
class PatternColor 
{
public:

	// Common PatternColor methods ----------------------------------------------------

	/**
	 * Create a PatternColor from the given SDF/Cos object listed under Pattern entry 
	 * in page Resource dictionary
	 */
	PatternColor (SDF::Obj pattern);

	PatternColor(const PatternColor&);
	PatternColor& operator=(const PatternColor&);
	
	~PatternColor();

	enum Type
	{
		e_uncolored_tiling_pattern,
		e_colored_tiling_pattern,
		e_shading,
		e_null
	};

	/**
	 * @return The pattern type
	 */ 
	Type GetType() const;

	/**
	 * @return the underlying SDF/Cos object
	 */
	SDF::Obj GetSDFObj ();

	/** 
	 * @return pattern matrix, a transformation matrix that maps the pattern's 
	 * internal coordinate system to the default coordinate system of the pattern's
	 * parent content stream (the content stream in which the pattern is defined as
	 * a resource). The concatenation of the pattern matrix with that of the parent content
	 * stream establishes the pattern coordinate space, within which all graphics objects
	 * in the pattern are interpreted.
	 */
	Common::Matrix2D GetMatrix();


	// Specific ShadingPattern methods -----------------------------------------------

	/**
	 * @return The shading object defining the shading pattern's gradient fill.
	 *
	 * @note for patterns other than Shading this method throws an exception. 
	 */
	Shading GetShading();


	// Specific TilingPattern methods ------------------------------------------------

	enum TilingType
	{
		e_constant_spacing,
		e_no_distortion,
		e_constant_spacing_fast_fill
	};

	/**
	 * @return the tiling type identifier that controls adjustments to the spacing 
	 * of tiles relative to the device pixel grid:
	 *
	 * @note for patterns other than Tiling this method throws an exception. 
	 */ 
	TilingType GetTilingType() const;

	/** 
	 * @return A rectangle in the pattern coordinate system giving the 
	 * coordinates of the left, bottom, right, and top edges, respectively, 
	 * of the pattern cell's bounding box. These boundaries are used to clip 
	 * the pattern cell.
	 *
	 * @note for patterns other than Tiling this method throws an exception. 
	 */
	Rect GetBBox();

	/** 
	 * @return the desired horizontal spacing between pattern cells, measured 
	 * in the pattern coordinate system.
	 *
	 * @note that XStep and YStep may differ from the dimensions of the pattern 
	 * cell implied by the BBox entry. This allows tiling with irregularly shaped 
	 * figures. XStep and YStep may be either positive or negative, but not zero.
	 *
	 * @note for patterns other than Tiling this method throws an exception. 
	 */
	double GetXStep();

	/**  
	 * @return the desired vertical spacing between pattern cells, measured in
	 * the pattern coordinate system. 
	 *
	 * @note for patterns other than Tiling this method throws an exception. 
	 */
	double GetYStep();

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	PatternColor(TRN_PatternColor impl);
	PatternColor();
	TRN_PatternColor mp_pc;
#endif
// @endcond
};



#include <Impl/PatternColor.inl>


	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPatternColor
