//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFColorSpace
#define PDFTRON_H_CPPPDFColorSpace

#include <C/PDF/TRN_ColorSpace.h>
#include <Common/Common.h>
#include <PDF/Function.h>

namespace pdftron { 
	namespace PDF {


/**
 * ColorPt is an array of colorants (or tint values) representing a color point
 * in an associated color space.
 */
class ColorPt
{
public:

	/**
	 * Constructor
	 * @param x initialized value of first color value (eg. red for rgb colorspace);
	 * @param y initialized value of second color value (eg. green for rgb colorspace);
	 * @param z initialized value of third color value (eg. blue for rgb colorspace);
	 * @param w initialized value of fourth color value (eg. when using CMYK);
	 * @note All colorants should be in the range [0..1], so colors in the range [0..255]
	 * should be divided by 255.0 first.
	 */
	explicit ColorPt(double x = 0, double y = 0, double z = 0, double w = 0);
	ColorPt(const ColorPt& co);
	/**
	* Destructor
	*/
	~ColorPt();

	ColorPt& operator= (const ColorPt& co);
	bool operator== (const ColorPt& co) const;

	/**
 	 * A utility method to set the first 4 tint values. For example, 
	 * color.Set(red, green, blue) will initialize the ColorPt to given 
	 * tint values. 
	 * @param x initialized value of first color value (eg. red for rgb colorspace);
	 * @param y initialized value of second color value (eg. green for rgb colorspace);
	 * @param z initialized value of third color value (eg. blue for rgb colorspace);
	 * @param w initialized value of fourth color value (eg. when using CMYK);
	 * @note color.Set(gray) is equivalent to Set(0, gray);
	 * @note All colorants should be in the range [0..1], so colors in the range [0..255]
	 * should be divided by 255.0 first.
	 */
	void Set(double x = 0, double y = 0, double z = 0, double w = 0);

	/**
	 * Sets a tint value at a given colorant index.
	 * 
	 * @param colorant_index the color index. For example, for a color point
	 * associated with a Gray color space the only allowed value for index 
	 * is 0. For a color point associated with a CMYK color space, the color_index
	 * can range from 0 (cyan) to 4 (black).
	 * 
	 * @param colorant_value The new tint value.
	 * 
	 * For example, the following snippet will initialize the color point
	 * to [red, green, blue]: 
	 * @code
	 * color.SetColorantNum(3);
	 * color.Set(0, red);
	 * color.Set(1, green);
	 * color.Set(2, blue);
	 * @endcode
	 * 
	 * The above code snippet is equivalent to the following line: 
	 *   color.Set(red, green, blue)
	 * 
	 * @note If a color point has more than 4 colorants, SetColorantNum(num_colorants)
	 * must be called before getting or setting tint values.
	 * @note All colorants should be in the range [0..1], so colors in the range [0..255]
	 * should be divided by 255.0 first.
	 */
	void Set(int colorant_index, double colorant_value);

	/**
	 * The number of colorants depends on the associated color space. To find 
	 * how many colorant are associated with a given color space use 
	 * color_space.GetComponentNum().
	 * 
	 * For example, if you have a color point in the RGB color space you can
	 * extract its colorants as follows:
	 * @code
	 * UInt8 rgb[3] = { UInt8(c.Get(0)*255), UInt8(c.Get(1)*255), UInt8(c.Get(2)*255) }; 
	 * @endcode
	 * @param colorant_index number representing the index of the color space to get the tint from
	 * @return the tint value at a given colorant index.
	 */
	double Get(int colorant_index) const;

	/**
	 * If a color point has more than 4 colorants, SetColorantNum(num_colorants)
	 * must be called before getting or setting tint values.
	 * The number of colorants depends on the associated color space. To find 
	 * how many colorant are associated with a given color space use 
	 * color_space.GetComponentNum().
	 */
	void SetColorantNum(int num);

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_ColorPt m_c;
#endif
// @endcond
};


/**
 * This abstract class is used to serve as a color space tag to identify the specific 
 * color space of a Color object. It contains methods that transform colors in a specific 
 * color space to/from several color space such as DeviceRGB and DeviceCMYK. 
 * 
 * For purposes of the methods in this class, colors are represented as arrays of color 
 * components represented as doubles in a normalized range defined by each ColorSpace. 
 * For many ColorSpaces (e.g. DeviceRGB), this range is 0.0 to 1.0. However, some ColorSpaces 
 * have components whose values have a different range. Methods are provided to inquire per 
 * component minimum and maximum normalized values. 
 * 
 * @note Note that in Pattern color space (i.e. for ColorSpace::e_pattern) 'color values' 
 * are PDF::PatternColor objects instead of the numeric component values (i.e. ColorPt) 
 * used with other spaces.
 */ 
class ColorSpace
{
public:

	// Common ColorSpace methods ----------------------------------------------------

	/**
	 * Create a new DeviceGray ColorSpace object
	 */
	 static ColorSpace CreateDeviceGray();

	/**
	 * Create a new DeviceRGB ColorSpace object
	 */
	 static ColorSpace CreateDeviceRGB();

	/**
	 * Create a new DeviceCMYK ColorSpace object
	 */
	 static ColorSpace CreateDeviceCMYK();

	/**
	 * Create a new Pattern ColorSpace object
	 */
	 static ColorSpace CreatePattern();

	/**
	* Create a PDF 'ICCBased' color space given an ICC profile
	*/
	static ColorSpace CreateICC(SDF::SDFDoc& doc, const UString& filepath);
	static ColorSpace CreateICC(SDF::SDFDoc& doc, Filters::Filter stm);
	static ColorSpace CreateICC(SDF::SDFDoc& doc, const UChar* buf, size_t buf_sz);

	/**
	 * Create a ColorSpace from the given SDF/Cos object listed under ColorSpaces entry 
	 * in page Resource dictionary. If color_space dictionary is null, a non valid ColorSpace 
	 * object is created.
	 * @param color_space The Cos/SDF object to initialze the ColorSpace object with.
	 */
	 ColorSpace (SDF::Obj color_space = 0);
	 ColorSpace(const ColorSpace& c);
	 ColorSpace& operator=(const ColorSpace& c);

	/** 
	 * Destructor
	 */
	 ~ColorSpace();
	
	enum Type
	{
		e_device_gray,
		e_device_rgb,
		e_device_cmyk,
		e_cal_gray,
		e_cal_rgb,
		e_lab,
		e_icc,
		e_indexed,
		e_pattern,
		e_separation,
		e_device_n,
		e_null
	};

	// Common Static/Global methods ----------------------------------------------------

#ifndef SWIG
	/**
	 * @return The number of components (tint components) used to represent color
	 * point for this color space
	 * 
	 * @param cs_type
	 * @param cs Cos/SDF color space object.
	 */ 
	 static int GetComponentNum(Type cs_type, SDF::Obj cs);

	/**
	 * @return The Type of a given SDF/Cos color space, or e_null for if 
	 * SDF object is not a valid color space
	 * 
	 * @param cs Cos/SDF color space object.
	 */ 
	 static Type GetType(SDF::Obj cs);
#endif

	/**
	 * @return The type of this color space
	 */ 
	 Type GetType() const;

	/**
	 * @return the underlying SDF/Cos object
	 */
	 SDF::Obj GetSDFObj ();

	/**
	 * @return The number of colorants (tint components) used to represent color
	 *  point in this color space
	 */ 
	 int GetComponentNum();

	/**
	 * Set color to the initial value used for this color space. 
	 * The initial value depends on the color space (see 4.5.7 in PDF Ref. Manual).
	 * @param out_colorants ColorPt object to initialize.
	 */
	 void InitColor(ColorPt& out_colorants);

	/**
	 * Initialize default ranges for each color component in the color space.
	 * For example, default ranges for DeviceRGB are [0 1 0 1 0 1] but for Lab 
	 * the default values might be [0 100 -100 100 -100 100]. 
	 * 
	 * @param an vector of numbers representing the lower bound for each color component.
	 * @param an vector of numbers representing the the difference between high and 
	 * low bound for each color component.
	 *
	 * @note the size of resulting vectors will match the number of color components 
	 * in this color space.
	 */
	 void InitComponentRanges(std::vector<double>& out_decode_low, std::vector<double>& out_decode_range);

	/**
	 * A convenience function used to convert color points from the current 
	 * color space to DeviceGray color space. 
	 *
	 * @param in_color input color point in the current color space
	 * @param out_color output color point in the DeviceGray color space
	 *
	 * @note the number to input colorants must match the number of colorants 
	 * expected by the current color space.
	 */
	 ColorPt Convert2Gray(const ColorPt& in_color);

#ifndef SWIG
	 void Convert2Gray(const ColorPt& in_color, ColorPt& out_color);
#endif

	/**
	 * A convenience function used to convert color points from the current 
	 * color space to DeviceRGB color space.
	 * 
	 * @param in_color input color point in the current color space
	 * @param out_color output color point in the DeviceRGB color space
	 *
	 * @note the number to input colorants must match the number of colorants 
	 * expected by the current color space.
	 */
	 ColorPt Convert2RGB(const ColorPt& in_color);

#ifndef SWIG
	 void Convert2RGB(const ColorPt& in_color, ColorPt& out_color);
#endif

	/**
	 * A convenience function used to convert color points from the current 
	 * color space to DeviceCMYK color space.
	 * 
	 * @param in_color input color point in the current color space
	 * @param out_color output color point in the DeviceCMYK color space
	 *
	 * @note the number to input colorants must match the number of colorants 
	 * expected by the current color space.
	 */
	 ColorPt Convert2CMYK(const ColorPt& in_color);

#ifndef SWIG
	 void Convert2CMYK(const ColorPt& in_color, ColorPt& out_color);
#endif

	/**
	 * @return the alternate color space if it is available or NULL otherwise.
	 * Color spaces that include alternate color space are e_separation, e_device_n, 
	 * and e_icc.
	 */
	 ColorSpace GetAlternateColorSpace();

	/**
	 * @return the base color space if this is an e_indexed or e_pattern with 
	 * associated base color space; NULL otherwise.
	 */
	 ColorSpace GetBaseColorSpace();

	// Indexed color space methods --------------------------------------------------

	/** 
	 * @return the highest index for the color lookup table for Indexed color space. 
	 * Since the color table is indexed from zero to highval, the actual number of entries is
	 * highval + 1. For color spaces other than indexed the method returns 0.
	 *
	 * @note for color spaces other than Indexed this method throws an exception. 
	 */
	 int GetHighVal();

#ifndef SWIG
	/** 
	 * @return the color lookup table for Indexed color space. for color spaces other 
	 * than indexed the method returns NULL.
	 *
	 * @note for color spaces other than Indexed this method throws an exception. 
	 */
	 const UChar* GetLookupTable();
#endif

	/**
	 * Get the base color given a component value (index) in Indexed color space. 
	 * 
	 * @param color_idx color value represented in the index color space
	 * @param out_color the color represented in the base (associated) color space
	 *
	 * @note for color spaces other than Indexed this method throws an exception. 
	 */
	 ColorPt GetBaseColor(UChar color_idx);

#ifndef SWIG
	 void GetBaseColor(UChar color_idx, ColorPt& out_color);
#endif

	// Separation of DeviceN color space methods ------------------------------------

	/**
	 * @return True if Separation or DeviceN color space contains None colorants.
	 * For DeviceN the function returns true only if component colorant names are all None.
	 *
	 * @note for color spaces other than Separation or DeviceN this method throws 
	 * an exception. 
	 */
	 bool IsNone();

	// Separation color space methods -----------------------------------------------

	/**
	 * @return True if Separation color space contains the colorant All.
	 *
	 * @note for color spaces other than Separation this method throws an exception. 
	 */
	 bool IsAll();

	/**
	 * @return the function that transforms tint values into color component 
	 * values in the alternate color space.
	 *
	 * @note for color spaces other than Separation this method throws an exception. 
	 */
	 Function GetTintFunction();

	/**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	ColorSpace(TRN_ColorSpace impl);
	TRN_ColorSpace mp_cs;
#endif
// @endcond
};


#include <Impl/ColorSpace.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif
