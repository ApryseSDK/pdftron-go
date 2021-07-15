//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFShading
#define PDFTRON_H_CPPPDFShading

#include <PDF/ColorSpace.h>
#include <PDF/Rect.h>
#include <Common/Matrix2D.h>
#include <C/PDF/TRN_Shading.h>

namespace pdftron { 
	namespace PDF {

/**
 * Shading is a class that represents a flat interface around all PDF shading types: 
 *
 *  - In Function-based (type 1) shadings, the color at every point in 
 *    the domain is defined by a specified mathematical function. The function need 
 *    not be smooth or continuous. This is the most general of the available shading 
 *    types, and is useful for shadings that cannot be adequately described with any 
 *    of the other types. 
 *
 *  - Axial shadings (type 2) define a color blend along a line between two points,
 *    optionally extended beyond the boundary points by continuing the boundary
 *    colors.
 * 
 *  - Radial shadings (type 3) define a color blend that varies between two circles.
 *    Shadings of this type are commonly used to depict three-dimensional spheres
 *    and cones.
 *
 *  - Free-form Gouraud-shaded triangle mesh shadings (type 4) and lattice Gouraud 
 *    shadings (type 5) are commonly used to represent complex colored and shaded 
 *    three-dimensional shapes. The area to be shaded is defined by a path composed entirely 
 *    of triangles. The color at each vertex of the triangles is specified, and a technique 
 *    known as Gouraud interpolation is used to color the interiors. The interpolation 
 *    functions defining the shading may be linear or nonlinear.
 *
 *  - Coons patch mesh shadings (type 6) are constructed from one or more color
 *    patches, each bounded by four cubic Bezier curves.
 * 
 *    A Coons patch generally has two independent aspects:
 *    - Colors are specified for each corner of the unit square, and bilinear 
 *      interpolation is used to fill in colors over the entire unit square<BR>
 *    - Coordinates are mapped from the unit square into a four-sided patch whose
 *      sides are not necessarily linear. The mapping is continuous: the corners 
 *      of the unit square map to corners of the patch and the sides of the unit 
 *      square map to sides of the patch.
 *
 *  - Tensor-product patch mesh shadings (type 7) are identical to type 6 
 *    (Coons mesh), except that they are based on a bicubic tensor-product 
 *    patch defined by 16 control points, instead of the 12 control points 
 *    that define a Coons patch. The shading Patterns dictionaries representing 
 *    the two patch types differ only in the value of the Type entry and 
 *    in the number of control points specified for each patch in the data stream. 
 *    Although the Coons patch is more concise and easier to use, the tensor-
 *    product patch affords greater control over color mapping. 
 */
class Shading
{
public:

	/**
	 * Create a Shading from the given SDF/Cos object listed under /Shading entry 
	 * in the page Resource dictionary. If shading_dict dictionary is null, a non valid Shading 
	 * object is created.
	 */
	 Shading (SDF::Obj shading_dict = 0);

	 Shading (const Shading& s);
	 Shading& operator=(const Shading& s);
	 ~Shading();

	enum Type
	{
		e_function_shading,
		e_axial_shading,
		e_radial_shading,
		e_free_gouraud_shading,
		e_lattice_gouraud_shading,
		e_coons_shading,
		e_tensor_shading,
		e_null
	};

	// Common Static/Global methods -------------------------------------------------

#ifndef SWIG
	/**
	 * @param shading_dict SDF/Cos shading dictionary to get the Type from
	 * @return The Type of a given SDF/Cos shading dictionary, or e_null for if
	 * SDF object is not a valid shading object
	 */
	 static Type GetType(SDF::Obj shading_dict);
#endif

	// Common methods ------------------------------------------------------------------

	/**
	 * @return The shading type
	 */ 
	 Shading::Type GetType() const;

	/**
	 * @return the underlying SDF/Cos object
	 */
	 SDF::Obj GetSDFObj ();

	/**
	 * @return The color space in which color values are expressed. 
	 * This may be any device, CIE-based, or special color space 
	 * except a Pattern space.
	 */
	 ColorSpace GetBaseColorSpace();

	/** 
	 * @return true if shading has a bounding box, false otherwise.
	 */
	 bool HasBBox();

	/** 
	 * @return a rectangle giving the left, bottom, right, and top 
	 * coordinates, respectively, of the shading's bounding box. The coordinates 
	 * are interpreted in the shading's target coordinate space. If present, this 
	 * bounding box is applied as a temporary clipping boundary when the shading 
	 * is painted, in addition to the current clipping path and any other clipping 
	 * boundaries in effect at that time.
	 *
	 * @note Use HasBBox() method to determine whether the shading has a
	 * background color.
	 */ 
	 Rect GetBBox();

	/** 
	 * @return true if the shading has a background color or false otherwise.
	 */ 
	 bool HasBackground();

	/**
	 * An color point represented in base color space specifying a single 
	 * background color value. If present, this color is used before
	 * any painting operation involving the shading, to fill those portions of the
	 * area to be painted that lie outside the bounds of the shading object itself. 
	 * In the opaque imaging model, the effect is as if the painting operation were
	 * performed twice: first with the background color and then again with the
	 * shading.
	 * 
	 * @note The background color is applied only when the shading is used as part 
	 * of a shading pattern, not when it is painted directly with the sh operator.
	 * 
	 * @note Use HasBackground() method to determine whether the shading has a
	 * background color.
	 */
	 ColorPt GetBackground();

	/**
	 * @return A flag indicating whether to filter the shading function to prevent
	 * aliasing artifacts. See Table 4.25
	 */
	  bool GetAntialias();

	
	// Specific methods ------------------------------------------------------------

	/**
	 * @return a number specifying the limiting value of a parametric variable t.
	 * The variable is considered to vary linearly between GetParamStart() and 
	 * GetParamEnd() as the color gradient varies between the starting and ending points
	 * of the axis for Axial shading or circles for Radial shading. 
	 * The variable t becomes the input argument to the color function(s).
	 * @note the returned value corresponds to the first value in Domain array. 
	 *
	 * @note for shadings other than Axial or Radial this method throws an exception. 
	 */
	 double GetParamStart();

	/**
	 * @return a number specifying the limiting value of a parametric variable t.
	 * The variable is considered to vary linearly between GetParamStart() and 
	 * GetParamEnd() as the color gradient varies between the starting and ending points 
	 * of the axis for Axial shading or circles for Radial shading.
	 * The variable t becomes the input argument to the color function(s).
	 * @note the returned value corresponds to the second value in Domain array. 
	 *
	 * @note for shadings other than Axial or Radial this method throws an exception. 
	 */
	 double GetParamEnd();

	/**
	 * @return a flag specifying whether to extend the shading beyond the starting 
	 * point of the axis for Axial shading or starting circle for Radial shading.
	 *
	 * @note for shadings other than Axial or Radial this method throws an exception. 
	 */
	 bool IsExtendStart();

	/**
	 * @return a flag specifying whether to extend the shading beyond the ending 
	 * point of the axis for Axial shading or ending circle for Radial shading.
	 *
	 * @note for shadings other than Axial or Radial this method throws an exception. 
	 */
	 bool IsExtendEnd();

	/**
	 * @return a color point for the given value of parametric variable t.
	 *
	 * @note for shadings other than Axial or Radial this method throws an exception.
	 */ 
	 ColorPt GetColor(double t);

#ifndef SWIG
	 void GetColor(double t, ColorPt& out_color);
#endif


	// Specific AxialShading methods -----------------------------------------------

	/**
	 * @return for Axial shading returns four numbers (out_x0, out_y0, out_x1, out_y1) 
	 * specifying the starting and ending coordinates of the axis, expressed in the 
	 * shading's target coordinate space.
	 *
	 * @note for shadings other than Axial this method throws an exception. 
	 */
	 std::vector<double> GetCoordsAxial();

#ifndef SWIG
	 void GetCoords(double& out_x0, double& out_y0, double& out_x1, double& out_y1);
#endif

	// Specific RadialShading methods ----------------------------------------------

	/**
	 * @return for Radial shading returns six numbers (x0 y0 r0 x1 y1 r1) specifying 
	 * the centers and radii of the starting and ending circles, expressed in the 
	 * shading's target coordinate space. The radii r0 and r1 must both be greater 
	 * than or equal to 0. If one radius is 0, the corresponding circle is treated 
	 * as a point; if both are 0, nothing is painted.
	 *
	 * @note for shadings other than Radial this method throws an exception. 
	 */
	 std::vector<double> GetCoordsRadial();

#ifndef SWIG
	 void GetCoords(double& out_x0, double& out_y0, double& out_r0,
		double& out_x1, double& out_y1, double& out_r1);
#endif


	// Specific FunctionShading methods --------------------------------------------

	/**
	 * @return An array of four numbers [xmin xmax ymin ymax] specifying the rectangular 
	 * domain of coordinates over which the color function(s) are defined. 
	 * If the function does not contain /Domain entry the function returns: [0 1 0 1].
	 *
	 * @note for shadings other than Function this method throws an exception. 
	 */
	 std::vector<double> GetDomain();

#ifndef SWIG
	 void GetDomain(double& out_xmin, double& out_xmax, double& out_ymin, double& out_ymax);
#endif

	/**
	 * @return a matrix specifying a mapping from the coordinate space specified 
	 * by the Domain entry into the shading's target coordinate space.
	 *
	 * @note for shadings other than Function this method throws an exception. 
	 */
	 Common::Matrix2D GetMatrix();

	/**
	 * @return a color point for the given value of parametric variable (t1, t2).
	 *
	 * @note for shadings other than Function this method throws an exception. 
	 */ 
	 ColorPt GetColor(double t1, double t2);

#ifndef SWIG
	 void GetColor(double t1, double t2, ColorPt& out_color);
#endif

	/**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 Shading(TRN_Shading impl);
	TRN_Shading mp_shade;
#endif
// @endcond
};


#include <Impl/Shading.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFShading
