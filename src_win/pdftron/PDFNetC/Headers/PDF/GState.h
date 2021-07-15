//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFGState
#define PDFTRON_H_CPPPDFGState

#include <C/PDF/TRN_GState.h>
#include <Common/Matrix2D.h>
#include <PDF/ColorSpace.h>
#include <PDF/Font.h>
#include <PDF/PatternColor.h>

namespace pdftron { 
	namespace PDF {

/**
 * GState is a class that keeps track of a number of style attributes used to visually 
 * define graphical Elements. Each PDF::Element has an associated GState that can be used to 
 * query or set various graphics properties.
 * 
 * @note current clipping path is not tracked in the graphics state for efficiency 
 * reasons. In most cases tracking of the current clipping path is best left to the 
 * client.
 */
class GState 
{
public:

	 GState();
	 GState(const GState& c);
	 GState& operator=(const GState& c);

	// GState properties
	enum GStateAttribute
	{		
		e_transform = 0,            // General graphics state attributes
		e_rendering_intent,

		e_stroke_cs,
		e_stroke_color,
		e_fill_cs,
		e_fill_color,

		e_line_width,                // Path attributes
		e_line_cap,
		e_line_join,
		e_flatness,
		e_miter_limit,
		e_dash_pattern,		

		e_char_spacing,              // Text attributes
		e_word_spacing,
		e_horizontal_scale,
		e_leading,
		e_font,
		e_font_size,
		e_text_render_mode,
		e_text_rise,
		e_text_knockout,

		// Adjusts the text position by a given amount. The attribute can be 
		// accessed through Element interface
		e_text_pos_offset,

		e_blend_mode,                // Extended graphics state attributes 
		e_opacity_fill,
		e_opacity_stroke,
		e_alpha_is_shape,
		e_soft_mask,
		e_smoothnes,
		e_auto_stoke_adjust,
		e_stroke_overprint, 
		e_fill_overprint,
		e_overprint_mode,
		e_transfer_funct,
		e_BG_funct,
		e_UCR_funct,
		e_halftone,

		// null attribute
		e_null
	};

	// Get Methods ------------------------------------------------------------------

	/**
	 * @return the transformation matrix for this element. 
	 * @note If you are looking for a matrix that maps coordinates to the initial 
	 * user space see Element::GetCTM().
	 */ 
	 Common::Matrix2D GetTransform();

	/**
	 * @return color space used for stroking
	 */ 
	 ColorSpace GetStrokeColorSpace();

	/**
	 * @return color space used for filling
	 */ 
	 ColorSpace GetFillColorSpace();

	/**
	 * @return a color value/point represented in the current stroke color space
	 */
	 ColorPt GetStrokeColor();

	/**
	 * @return the SDF pattern object of currently selected PatternColorSpace used for stroking.
	 */ 
	 PatternColor GetStrokePattern();

	/**
	 * @return a color value/point represented in the current fill color space
	 */ 
	 ColorPt GetFillColor();

	/**
	 * @return the pattern color of currently selected pattern color space used for filling.
	 */ 
	 PatternColor GetFillPattern();

	/**
	 * @return current value of flatness tolerance
	 * 
	 * Flatness is a number in the range 0 to 100; a value of 0 specifies the output 
	 * device's default flatness tolerance.
	 * 
	 * The flatness tolerance controls the maximum permitted distance in device pixels
	 * between the mathematically correct path and an approximation constructed from 
	 * straight line segments.
	 */
	 double GetFlatness() const;


	enum LineCap 
	{
		e_butt_cap = 0,     // The stroke is squared off at the endpoint of the path.
		e_round_cap,        // A semicircular arc with a diameter equal to the line width.
		e_square_cap        // squared off stroke continues beyond the endpoint of the path.
	};

	/**
	 * @return currently selected LineCap style
	 * 
	 * The line cap style specifies the shape to be used at the ends of open sub-paths 
	 * (and dashes, if any) when they are stroked.
	 */ 
	 LineCap GetLineCap() const;


	enum LineJoin
	{
		e_miter_join = 0,   // The two segments are extended until they meet
		e_round_join,       // A circle with a diameter equal to the line width
		e_bevel_join        // The two segments are finished with butt caps
	};

	/**
	 * @return currently selected LineJoin style
	 * 
	 * The line join style specifies the shape to be used at the corners of paths that 
	 * are stroked.
	 */ 
	 LineJoin GetLineJoin() const;

	/**
	 * @return the thickness of the line used to stroke a path.
	 * @note A line width of 0 denotes the thinnest line that can be rendered at device 
	 * resolution: 1 device pixel wide.
	 */ 
	 double GetLineWidth() const;

	/**
	 * @return current value of miter limit. 
	 * 
	 * The miter limit imposes a maximum on the ratio of the miter length to the 
	 * line width. When the limit is exceeded, the join is converted from a miter 
	 * to a bevel.
	 */ 
	 double GetMiterLimit() const;

	/**
	 * @return The method fills the vector with an array of numbers representing the dash pattern
	 * 
	 * The line dash pattern controls the pattern of dashes and gaps used to stroke 
	 * paths. It is specified by a dash array and a dash phase. The dash array's elements 
	 * are numbers that specify the lengths of alternating dashes and gaps; the dash phase
	 * specifies the distance into the dash pattern at which to start the dash. The elements
	 * of both the dash array and the dash phase are expressed in user space units.
	 */ 
	 std::vector<double> GetDashes() const;

#ifndef SWIG
	 void GetDashes(std::vector<double>& dashes) const;
#endif

	/**
	 * @return the phase of the currently selected dash pattern. dash phase is expressed in 
	 * user space units.
	 */ 
	 double GetPhase() const;

	/**
	 * @return currently selected character spacing. 
	 * 
	 * The character spacing parameter is a number specified in unscaled text space
	 * units. When the glyph for each character in the string is rendered, the character 
	 * spacing is added to the horizontal or vertical component of the glyph's displacement,
	 * depending on the writing mode. See Section 5.2.1 in PDF Reference Manual for details.
	 */ 
	 double GetCharSpacing() const;

	/**
	 * @return currently selected word spacing
	 * 
	 * Word spacing works the same way as character spacing, but applies only to the
	 * space character (char code 32). See Section 5.2.2 in PDF Reference Manual for details.
	 */ 
	 double GetWordSpacing() const;

	/**
	 * @return currently selected horizontal scale
	 * 
	 * The horizontal scaling parameter adjusts the width of glyphs by stretching 
	 * or compressing them in the horizontal direction. Its value is specified as 
	 * a percentage of the normal width of the glyphs, with 100 being the normal width. 
	 * The scaling always applies to the horizontal coordinate in text space, independently 
	 * of the writing mode. See Section 5.2.3 in PDF Reference Manual for details.
	 */ 
	 double GetHorizontalScale() const;

	/**
	 * @return currently selected leading parameter
	 * 
	 * The leading parameter is measured in unscaled text space units. It specifies
	 * the vertical distance between the baselines of adjacent lines of text. 
	 * See Section 5.2.4 in PDF Reference Manual for details.
	 */ 
	 double GetLeading() const;

	/**
	 * @return currently selected font
	 */ 
	 Font GetFont() const;

	/**
	 * @return the font size
	 */ 
	 double GetFontSize() const;

	enum TextRenderingMode 
	{
		e_fill_text = 0,            // Fill text.
		e_stroke_text,              // Stroke text.
		e_fill_stroke_text,         // Fill, then stroke text.
		e_invisible_text,           // Neither fill nor stroke text (invisible).
		e_fill_clip_text,           // Fill text and add to path for clipping (see above).
		e_stroke_clip_text,         // Stroke text and add to path for clipping.
		e_fill_stroke_clip_text,    // Fill, then stroke text and add to path for clipping.
		e_clip_text                 // Add text to path for clipping.
	};

	/**
	 * @return current text rendering mode. 
	 * 
	 * The text rendering mode determines whether showing text causes glyph outlines to 
	 * be stroked, filled, used as a clipping boundary, or some combination of the three.
	 * See Section 5.2.5 in PDF Reference Manual for details..
	 */ 
	 TextRenderingMode GetTextRenderMode() const;

	/**
	 * @return current value of text rise
	 * 
	 * Text rise specifies the distance, in unscaled text space units, to move the
	 * baseline up or down from its default location. Positive values of text rise 
	 * move the baseline up
	 */ 
	 double GetTextRise() const;

	/**
	 * @return a boolean flag that determines the text element is considered 
	 * elementary objects for purposes of color compositing in the transparent imaging 
	 * model.
	 */ 
	 bool IsTextKnockout() const;

	enum RenderingIntent
	{
		e_absolute_colorimetric,
		e_relative_colorimetric,
		e_saturation,
		e_perceptual
	};

	/**
	 * @return The color intent to be used for rendering the Element
	 */ 
	 RenderingIntent GetRenderingIntent() const;

	/**
	 * A utility function that maps a string representing a rendering intent to 
	 * RenderingIntent type. 
	 * @param name string that represents the rendering intent to get.
	 * @return The color rendering intent type matching the specified string
	 */ 
	 static RenderingIntent GetRenderingIntentType(const char* name);

	// Extended graphics state 'Get' methods ----------------------------------------

	// The standard separable blend modes available in PDF.
	enum BlendMode
	{
		e_bl_compatible = 0, 
		e_bl_normal, 
		e_bl_multiply, 
		e_bl_screen, 
		e_bl_difference, 
		e_bl_darken, 
		e_bl_lighten, 
		e_bl_color_dodge, 
		e_bl_color_burn, 
		e_bl_exclusion, 
		e_bl_hard_light, 
		e_bl_overlay, 
		e_bl_soft_light, 
		e_bl_luminosity, 
		e_bl_hue, 
		e_bl_saturation,
		e_bl_color
	};

	/**
	 * @return the current blend mode to be used in the transparent imaging model. 
	 * Corresponds to the /BM key within the ExtGState's dictionary.
	 */
	 BlendMode GetBlendMode();

	/**
	 * @return the opacity value for painting operations other than stroking.
	 * Returns the value of the /ca key in the ExtGState dictionary. If the value is not 
	 * found, the default value of 1 is returned.
	 */   
	 double GetFillOpacity() const;

	/**
	 * @return opacity value for stroke painting operations for paths and glyph outlines.
	 * Returns the value of the /CA key in the ExtGState dictionary. If the value is not 
	 * found, the default value of 1 is returned.
	 */
	 double GetStrokeOpacity() const;

	/** 
	 * @return the alpha source flag ('alpha is shape'), specifying whether the 
	 * current soft mask and alpha constant are to be interpreted as shape values 
	 * (true) or opacity values (false).
	 */ 
	 bool GetAISFlag() const;

	/**
	 * @return Associated soft mask. NULL if the soft mask is not selected or 
	 * SDF dictionary representing the soft mask otherwise.
	 */   
	 SDF::Obj GetSoftMask();

	/**
	 * @return The soft mask transform. This is the transformation matrix at the moment the soft 
	 * mask is established in the graphics state with the gs operator. This information is only 
	 * relevant when applying the soft mask that may be specified in the graphics state to the 
	 * current element.
	 */ 
	Common::Matrix2D GetSoftMaskTransform();

	/** 
	 * @return whether overprint is enabled for stroke painting operations.
	 * Corresponds to the /OP key within the ExtGState's dictionary.
	 */ 
	 bool GetStrokeOverprint() const;

	/** 
	 * @return whether overprint is enabled for fill painting operations.
	 * Corresponds to the /op key within the ExtGState's dictionary.
	 */ 
	 bool GetFillOverprint() const;

	/**
	 * @return the overprint mode used by this graphics state.
	 * Corresponds to the /OPM key within the ExtGState's dictionary.
	 */
	 int GetOverprintMode() const;

	/**
	 * @return a flag specifying whether stroke adjustment is enabled in the graphics 
	 * state. Corresponds to the /SA key within the ExtGState's dictionary.
	 */
	 bool GetAutoStrokeAdjust() const;

	/**
	 * @return the smoothness tolerance used to control the quality of smooth 
	 * shading. Corresponds to the /SM key within the ExtGState's dictionary.
	 * The allowable error (or tolerance) is expressed as a fraction of the range 
	 * of the color component, from 0.0 to 1.0. 
	 */
	 double GetSmoothnessTolerance() const;

	/**
	 * @return currently selected transfer function (NULL by default) used during
	 * color conversion process. A transfer function adjusts the values of color 
	 * components to compensate for nonlinear response in an output device and in 
	 * the human eye. Corresponds to the /TR key within the ExtGState's dictionary.
	 */
	 SDF::Obj GetTransferFunct();

	/**
	 * @return currently selected black-generation function (NULL by default) used 
	 * during conversion between DeviceRGB and DeviceCMYK. Corresponds to the /BG key 
	 * within the ExtGState's dictionary.
	 */
	 SDF::Obj GetBlackGenFunct();

	/**
	 * @return currently selected undercolor-removal function (NULL by default) used 
	 * during conversion between DeviceRGB and DeviceCMYK. Corresponds to the /UCR key 
	 * within the ExtGState's dictionary.
	 */
	 SDF::Obj GetUCRFunct();

	/**
	 * @return currently selected halftone dictionary or stream (NULL by default).
	 * Corresponds to the /HT key within the ExtGState's dictionary.
	 * Halftoning is a process by which continuous-tone colors are approximated on an
	 * output device that can achieve only a limited number of discrete colors.
	 */
	 SDF::Obj GetHalftone();

	// Set Methods ------------------------------------------------------------------

	/**
	 * Set the transformation matrix associated with this element.
	 * 
	 * @param mtx The new transformation for this text element.
	 *
	 * @note in PDF associating a transformation matrix with an element
	 * ('cm' operator) will also affect all subsequent elements.
	 */ 
	 void SetTransform(const Common::Matrix2D& mtx);

	/**
	 * Set the transformation matrix associated with this element.
	 * 
	 * A transformation matrix in PDF is specified by six numbers, usually 
	 * in the form of an array containing six elements. In its most general 
	 * form, this array is denoted [a b c d h v]; it can represent any linear 
	 * transformation from one coordinate system to another. For more 
	 * information about PDF matrices please refer to section 4.2.2 'Common 
	 * Transformations' in PDF Reference Manual, and to documentation for 
	 * pdftron::Common::Matrix2D class.
	 * 
	 * @param a - horizontal 'scaling' component of the new text matrix.
	 * @param b - 'rotation' component of the new text matrix.
	 * @param c - 'rotation' component of the new text matrix.
	 * @param d - vertical 'scaling' component of the new text matrix.
	 * @param h - horizontal translation component of the new text matrix.
	 * @param v - vertical translation component of the new text matrix.
	 */
	 void SetTransform(double a, double b, double c, double d, double h, double v);

	/**
	 * Concatenate the given matrix to the transformation matrix of this element.
	 * @param mtx Matrix2D object to concatenate the current matrix with.
	 */ 
	 void Concat(const Common::Matrix2D& mtx);
	 /**
	 * Concatenate the given matrix expressed in its values to the transformation 
	 * matrix of this element.
	 * @param a - horizontal 'scaling' component of the new text matrix.
	 * @param b - 'rotation' component of the new text matrix.
	 * @param c - 'rotation' component of the new text matrix.
	 * @param d - vertical 'scaling' component of the new text matrix.
	 * @param h - horizontal translation component of the new text matrix.
	 * @param v - vertical translation component of the new text matrix.
	 */
	 void Concat(double a, double b, double c, double d, double h, double v);

	/**
	 * Sets the color space used for stroking operations
	 * @param cs ColorSpace object to use for stroking operations
	 */ 
	 void SetStrokeColorSpace(ColorSpace cs);

	/**
	 * Sets the color space used for filling operations
	 * @param cs ColorSpace object to use for filling operations
	 */
	 void SetFillColorSpace(ColorSpace cs);

	/**
	 * Sets the color value/point used for stroking operations. 
	 * @param c is the color used for stroking operations
	 * @note The color value must be represented in the currently selected color space used 
	 * for stroking.
	 */
	 void SetStrokeColor(const ColorPt& c);

	/**
	 * Set the stroke color to the given tiling pattern.
	 * @param pattern SDF pattern object.
	 * @note The currently selected stroke color space must be Pattern color space.
	 */ 
	 void SetStrokeColor(PatternColor pattern);

	/**
	 * Set the stroke color to the given uncolored tiling pattern.
	 * @param pattern pattern (PatternType = 1 and PaintType = 2) object.
	 * @param c is a color in the pattern's underlying color space.
	 * @note The currently selected stroke color space must be Pattern color space.
	 */ 
	 void SetStrokeColor(PatternColor pattern, const ColorPt& c);

	/**
	 * Sets the color value/point used for filling operations. 
	 * @param c the color used for filling operations
	 * The color value must be represented in the currently selected color space used
	 * for filling.
	 */
	 void SetFillColor(const ColorPt& c);

	/**
	 * Set the fill color to the given tiling pattern.
	 * @param pattern New pattern color.
	 * @note The currently selected fill color space must be Pattern color space.
	 */ 
	 void SetFillColor(PatternColor pattern);

	/**
	 * Set the fill color to the given uncolored tiling pattern.
	 * @param pattern PatternColor (PatternType = 1 and PaintType = 2) object.
	 * @param c is a color in the pattern's underlying color space.
	 * @note The currently selected fill color space must be Pattern color space.
	 */ 
	 void SetFillColor(PatternColor pattern, const ColorPt& c);

	/**
	 * Sets the value of flatness tolerance. 
	 *
	 * @param flatness is a number in the range 0 to 100; a value of 0 specifies the output 
	 * device's default flatness tolerance.
	 * 
	 * The flatness tolerance controls the maximum permitted distance in device pixels
	 * between the mathematically correct path and an approximation constructed from 
	 * straight line segments.
	 */ 
	 void SetFlatness(double flatness);

	/**
	 * Sets LineCap style property.
	 *
	 * The line cap style specifies the shape to be used at the ends of open subpaths 
	 * (and dashes, if any) when they are stroked.
	 */
	 void SetLineCap(LineCap cap);

	/**
	 * Sets LineJoin style property.
	 * 
	 * The line join style specifies the shape to be used at the corners of paths that 
	 * are stroked.
	 */ 
	 void SetLineJoin(LineJoin join);

	/**
	 * Sets the thickness of the line used to stroke a path.
	 * @param width a non-negative number expressed in user space units.
	 * A line width of 0 denotes the thinnest line that can be rendered at device 
	 * resolution: 1 device pixel wide.
	 */
	 void SetLineWidth(double width);

	/**
	 * Sets miter limit. 
	 * @param miter_limit A number that imposes a maximum on the ratio of the miter 
	 * length to the line width. When the limit is exceeded, the join is converted 
	 * from a miter to a bevel.
	 */ 
	 void SetMiterLimit(double miter_limit);

	/**
	 * Sets the dash pattern used to stroke paths. The line dash pattern controls
	 * the pattern of dashes and gaps used to stroke paths. It is specified by a dash
	 * array and a dash phase. The elements of both the dash array and the dash phase
	 * are expressed in user space units.
	 * @param dash_array the numbers that specify the lengths of alternating dashes and gaps.
	 * @param phase specifies the distance into the dash pattern at which to start the dash.
	 */ 
	 void SetDashPattern(const std::vector<double>& dash_array, double phase);

	/**
	 * Sets character spacing. 
	 * @param char_spacing a number specified in unscaled text space units. When the 
	 * glyph for each character in the string is rendered, the character spacing is 
	 * added to the horizontal or vertical component of the glyph's displacement,
	 * depending on the writing mode. See Section 5.2.1 in PDF Reference Manual for details.
	 */ 
	 void SetCharSpacing(double char_spacing);

	/**
	 * Sets word spacing.
	 * @param word_spacing - a number specified in unscaled text space units.
	 * Word spacing works the same way as character spacing, but applies only to the
	 * space character (char code 32). See Section 5.2.2 in PDF Reference Manual for details.
	 */
	 void SetWordSpacing(double word_spacing);

	/**
	 * Sets horizontal scale.
	 * The horizontal scaling parameter adjusts the width of glyphs by stretching 
	 * or compressing them in the horizontal direction. Its value is specified as 
	 * a percentage of the normal width of the glyphs, with 100 being the normal width. 
	 * The scaling always applies to the horizontal coordinate in text space, independently 
	 * of the writing mode. See Section 5.2.3 in PDF Reference Manual for details.
	 * @param hscale value to set horizontal scale to.
	 */
	 void SetHorizontalScale(double hscale);

	/**
	 * Sets the leading parameter.
	 * 
	 * The leading parameter is measured in unscaled text space units. It specifies
	 * the vertical distance between the baselines of adjacent lines of text.
	 * See Section 5.2.4 in PDF Reference Manual for details.
	 * @param leading number representing vertical distance between lines of text
	 */
	 void SetLeading(double leading);

	/**
	 * Sets the font and font size used to draw text.
	 * @param font Font to draw the text with
	 * @param font_sz size of the font to draw the text with
	 */
	 void SetFont(Font font, double font_sz);

	/**
	 * Sets text rendering mode. 
	 * The text rendering mode determines whether showing text causes glyph outlines to 
	 * be stroked, filled, used as a clipping boundary, or some combination of the three.
	 * See Section 5.2.5 in PDF Reference Manual for details..
	 */
	 void SetTextRenderMode(TextRenderingMode rmode);

	/**
	 * Sets text rise.
	 * Text rise specifies the distance, in unscaled text space units, to move the
	 * baseline up or down from its default location. Positive values of text rise 
	 * move the baseline up
	 * @param rise distance to move baseline up. Negative values move baseline down.
	 */
	 void SetTextRise(double rise);

	/**
	 * Mark the object as elementary for purposes of color compositing in the 
	 * transparent imaging model.
	 * @param knockout Whether an object is elementary or not.
	 */
	 void SetTextKnockout(bool knockout);
	
	/**
	 * Sets the color intent to be used for rendering the Element. 
	 */
	 void SetRenderingIntent(RenderingIntent intent);

	// Extended graphics state 'Set' methods ----------------------------------------

	/**
	 * Sets the current blend mode to be used in the transparent imaging model.
	 * Corresponds to the /BM key within the ExtGState's dictionary.
	 * @param BM - New blending mode type.
	 *
	 * @code
	 * // C#
	 * gs.SetBlendMode(GState.BlendMode.e_lighten);
	 *
	 * // C++ 
	 * gs->SetBlendMode(GState::e_lighten);
	 * @endcode 
	 */
	 void SetBlendMode(BlendMode BM);

	/**
	 * Sets the opacity value for painting operations other than stroking.
	 * Corresponds to the value of the /ca key in the ExtGState dictionary. 
	 * @param ca value to set fill opacity to
	 */
	 void SetFillOpacity(double ca);

	/**
	 * Sets opacity value for stroke painting operations for paths and glyph outlines.
	 * Corresponds to the value of the /CA key in the ExtGState dictionary. 
	 * @param ca value to set stroke opacity to
	 */
	 void SetStrokeOpacity(double ca);

	/** 
	 * Specifies if the alpha is to be interpreted as a shape or opacity mask.
	 * The alpha source flag ('alpha is shape'), specifies whether the 
	 * current soft mask and alpha constant are to be interpreted as shape values 
	 * (true) or opacity values (false).
	 * @param AIS true for interpretation as shape values or false for opacity values
	 */
	 void SetAISFlag(bool AIS);

	/**
	 * Sets the soft mask of the extended graphics state. 
	 * Corresponds to the /SMask key within the ExtGState's dictionary.
	 * @param SM - SDF/Cos black-generation function or name
	 */
	 void SetSoftMask(SDF::Obj SM);

	/** 
	 * Specifies if overprint is enabled for stroke operations. Corresponds to the /OP 
	 * key within the ExtGState's dictionary.
	 * @param OP true to enable overprint for stroke, false to disable.
	 */
	 void SetStrokeOverprint(bool OP);

	/** 
	 * Specifies if overprint is enabled for fill operations. Corresponds to the /op 
	 * key within the ExtGState's dictionary.
	 * @param op true to enable overprint for fill, false to disable.
	 */
	 void SetFillOverprint(bool op);

	/**
	 * Sets the overprint mode. Corresponds to the /OPM key within the ExtGState's 
	 * dictionary.
	 * @param OPM overprint mode.
	 */
	 void SetOverprintMode(int OPM);

	/**
	 * Specify whether to apply automatic stroke adjustment.
	 * Corresponds to the /SA key within the ExtGState's dictionary.
	 * @param SA if true automatic stroke adjustment will be applied.
	 */
	 void SetAutoStrokeAdjust(bool SA);

	/**
	 * Sets the smoothness tolerance used to control the quality of smooth 
	 * shading. Corresponds to the /SM key within the ExtGState's dictionary.
	 * 
	 */
	 void SetSmoothnessTolerance(double SM);

	/**
	 * Sets black-generation function used during conversion between DeviceRGB 
	 * and DeviceCMYK. Corresponds to the /BG key within the ExtGState's 
	 * dictionary.
	 * @param BG - SDF/Cos black-generation function or name
	 */
	 void SetBlackGenFunct(SDF::Obj BG);

	/**
	 * Sets undercolor-removal function used during conversion between DeviceRGB 
	 * and DeviceCMYK. Corresponds to the /UCR key within the ExtGState's 
	 * dictionary.
	 * @param UCR - SDF/Cos undercolor-removal function or name
	 */
	 void SetUCRFunct(SDF::Obj UCR);

	/**
	 * Sets transfer function used during color conversion process. A transfer 
	 * function adjusts the values of color components to compensate for nonlinear 
	 * response in an output device and in the human eye. Corresponds to the /TR key 
	 * within the ExtGState's dictionary.
	 * @param TR - SDF/Cos transfer function, array, or name
	 */
	 void SetTransferFunct(SDF::Obj TR);

	/**
	 * @return currently selected halftone dictionary or stream (NULL by default).
	 * Corresponds to the /HT key within the ExtGState's dictionary.
	 * Halftoning is a process by which continuous-tone colors are approximated on an
	 * output device that can achieve only a limited number of discrete colors.
	 * @param HT - SDF/Cos halftone dictionary, stream, or name
	 */
	 void SetHalftone(SDF::Obj HT);
	
// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	GState(TRN_GState impl);
	TRN_GState mp_state;
#endif
// @endcond
};


#include <Impl/GState.inl>

	};	// namespace PDF
};	// namespace pdftron



// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
#ifdef _WIN32
  // A forward declaration for GDI+
  namespace Gdiplus { class Bitmap; };
#endif
#endif
// @endcond

#endif // PDFTRON_H_CPPPDFGState
