//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPDFDraw
#define PDFTRON_H_CPPPDFPDFDraw

#include <PDF/PDFRasterizer.h>
#include <C/PDF/TRN_PDFDraw.h>

#ifdef SWIG
#include <PDF/Callback.h>
#endif

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
#if defined(_WIN32)
  // A forward declaration for GDI+ Bitmap-s which can be directly created using PDFDraw::GetBitmap() method.
  namespace Gdiplus { class Bitmap; };
#endif
#endif
// @endcond




namespace pdftron { 
	namespace PDF {


//return type for PDFDraw::GetBitmap
class BitmapInfo
{
  	std::vector<unsigned char> buf;
	  
public:
	BitmapInfo(int w, int h, int s, double d, char* b) {
		width = w;
		height = h;
		stride = s;
		dpi = d;
		buf.resize(h*s);
		memcpy(&buf[0], b, h*s);
	}
	int width;
	int height;
	int stride;
	double dpi;

	//copy constructor
	BitmapInfo(const BitmapInfo& b) {
		width = b.width;
		height = b.height;
		stride = b.stride;
		dpi = b.dpi;
		std::vector<unsigned char> temp(b.GetBuffer());
		buf.swap(temp);
	}
	  
	std::vector<unsigned char> GetBuffer() const {
		return buf;
	}
};

class Separation;

/** 
 * PDFDraw contains methods for converting PDF pages to images and to Bitmap objects.
 * Utility methods are provided to export PDF pages to various raster formats as well 
 * as to convert pages to GDI+ bitmaps for further manipulation or drawing.
 * 
 * @note This class is available on all platforms supported by PDFNet. 
 */
class PDFDraw
{
public: 

	/**
	 * PDFDraw constructor and destructor
	 * 
	 * @param dpi - Default resolution used to rasterize pages. If the parameter is not 
	 * specified, the initial resolution is 92 dots per inch. DPI parameter can be 
	 * modified at any time using PDFDraw::SetDPI() method.
	 */
	PDFDraw(double dpi = 92);
	~PDFDraw();

	/**
	 * Sets the core graphics library used for rasterization and 
	 * rendering. Using this method it is possible to quickly switch 
	 * between different implementations. By default, PDFDraw uses 
	 * the built-in, platform independent rasterizer.
	 *
	 * @param type Rasterizer type. 
	 *
	 * @note This method is deprecated, since the GDI+ rasterizer itself is deprecated and will be removed in a future version of PDFNet.
	 * It is strongly recommended to use the built-in rasterizer and to use the XPS print path where vector conversion is needed.
	 */
	void SetRasterizerType (PDFRasterizer::Type type);

	/**
	 * Sets the output image resolution. 
	 * 
	 * DPI stands for Dots Per Inch. This parameter is used to specify the output
	 * image size and quality. A typical screen resolution for monitors these days is 
	 * 92 DPI, but printers could use 200 DPI or more.
	 * 
	 * @param dpi value to set the image resolution to. Higher value = higher resolution.
	 * @note The size of resulting image is a function of DPI and the dimensions of 
	 * the source PDF page. For example, if DPI is 92 and page is 8 inches wide, the 
	 * output bitmap will have 92*8 = 736 pixels per line. If you know the dimensions 
	 * of the destination bitmap, but don't care about DPI of the image you can use 
	 * pdfdraw.SetImageSize() instead.
	 * 
	 * @note if you would like to rasterize extremely large bitmaps (e.g. with 
	 * resolutions of 2000 DPI or more) it is not practical to use PDFDraw directly 
	 * because of the memory required to store the entire image. In this case, you 
	 * can use PDFRasterizer directly to generate the rasterized image in stripes or 
	 * tiles.
	 */
	void SetDPI(double dpi);

	/**
	 * SetImageSize can be used instead of SetDPI() to adjust page  scaling so that 
	 * image fits into a buffer of given dimensions.
	 * 
	 * If this function is used, DPI will be calculated dynamically for each 
	 * page so that every page fits into the buffer of given dimensions.
	 * 
	 * @param width - The width of the image, in pixels/samples.
	 * @param height - The height of the image, in pixels/samples.
	 * @param preserve_aspect_ratio - True to preserve the aspect ratio, false 
	 * otherwise. By default, preserve_aspect_ratio is true.
	 */
	void SetImageSize(int width, int height, bool preserve_aspect_ratio = true);

	/**
	 * Selects the page box/region to rasterize.
	 *
	 * @param region Page box to rasterize. By default, PDFDraw will rasterize 
	 * page crop box.
	 */
	void SetPageBox(Page::Box region);

	/**
	* clip the render region to the provided rect (in page space)
	*
	* @param clip_rect clipping rect. By default, PDFDraw will rasterize 
	* the entire page box.
	*/
	void SetClipRect(Rect clip_rect);

	/**
	 * Flips the vertical (i.e. Y) axis of the image.
	 *
	 * @param flip_y true to flip the Y axis, false otherwise. For compatibility with
	 * most raster formats 'flip_y' is true by default.
	 */
	void SetFlipYAxis(bool flip_y);

	/**
	 * Sets the rotation value for this page. 
	 * 
	 * @note This method is used only for drawing purposes and it does not modify 
	 * the document (unlike Page::SetRotate()).
	 * 
	 * @param angle Rotation value to be set for a given page. Must be one 
	 * of the Page::Rotate values.
	 */
	void SetRotate(Page::Rotate r);

	/**
	 * Enable or disable annotation and forms rendering. By default, all annotations 
	 * and form fields are rendered.
	 *
	 * @param render_annots True to draw annotations, false otherwise. 
	 */
	void SetDrawAnnotations(bool render_annots);

	/**
	 * Enable or disable highlighting form fields. Default is disabled.
	 *
	 * @param highlight_fields true to highlight, false otherwise. 
	 */
	void SetHighlightFields(bool highlight_fields);

	/**
	 * Enable or disable anti-aliasing. 
	 * 
	 * Anti-Aliasing is a technique used to improve the visual 
	 * quality of images when displaying them on low resolution 
	 * devices (for example, low DPI computer monitors).
	 * @param enable_aa if true anti-aliasing will be enabled.
	 * @default Anti-aliasing is enabled by default.
	 */
	void SetAntiAliasing(bool enable_aa);

	/**
	 * Enable or disable path hinting.
	 * 
	 * @param enable_hinting if true path hinting will be enabled. Path hinting is used 
	 * to slightly adjust paths in order to avoid or alleviate artifacts of hair line 
	 * cracks between certain graphical elements. This option is turned on by default.
	 *
	 */
	void SetPathHinting(bool enable_hinting);

	/**
	 * Set thin line adjustment parameters.
	 * 
	 * @param pixel_grid_fit if true (horizontal/vertical) thin lines will be snapped to 
	 * integer pixel positions. This helps make thin lines look sharper and clearer. This
	 * option is turned off by default and it only works if path hinting is enabled.
	 *
	 * @param stroke_adjust if true auto stroke adjustment is enabled. Currently, this would 
	 * make lines with sub-pixel width to be one-pixel wide. This option is turned on by default.
	 */
	void SetThinLineAdjustment(bool pixel_grid_fit, bool stroke_adjust);

	/**
	 * Enable or disable image smoothing. 
	 * 
	 * The rasterizer allows a tradeoff between rendering quality and rendering speed. 
	 * This function can be used to indicate the preference between rendering speed and quality.
	 *
	 * @note image smoothing option has effect only if the source image has higher resolution 
	 * that the output resolution of the image on the rasterized page. PDFNet automatically 
	 * controls at what resolution/zoom factor, 'image smoothing' needs to take effect. 
	 *
	 * @param smoothing_enabled True to enable image smoothing, false otherwise.
	 * @param hq_image_resampling True to use a higher quality (but slower) smoothing algorithm
	 * @default image smoothing is enabled and hq_image_resampling is false.
	 */
	void SetImageSmoothing(bool smoothing_enabled = true, bool hq_image_resampling = false);

	/** 
	 * Enables or disables caching. Caching can improve the rendering performance in cases 
	 * where the same page will be drawn multiple times.
	 * 
	 * @param enabled - if true PDFRasterizer will cache frequently used graphics objects. 
	 */
	void SetCaching(bool enabled = true);	

	/**
	 * Sets the gamma factor used for anti-aliased rendering.
	 * 
	 * @param exp is the exponent value of gamma function. Typical values 
	 * are in the range from 0.1 to 3. 
	 *  
	 * Gamma correction can be used to improve the quality of anti-aliased
	 * image output and can (to some extent) decrease the appearance common 
	 * anti-aliasing artifacts (such as pixel width lines between polygons).
	 * 
	 * @note Gamma correction is used only in the built-in rasterizer.
	 */
	void SetGamma(double exp);

	/** 
	 * Sets the Optional Content Group (OCG) context that should be used when 
	 * rendering the page. This function can be used to selectively render optional
	 * content (such as PDF layers) based on the states of optional content groups 
	 * in the given context.
	 * 
	 * @param ctx Optional Content Group (OCG) context, or NULL if the rasterizer
	 * should render all content on the page.
	 */
	void SetOCGContext(OCG::Context* ctx);
		
	/** 
	 * Tells the rasterizer to render the page 'print' mode. Certain page elements 
	 * (such as annotations or OCG-s) are meant to be visible either on the screen or 
	 * on the printed paper but not both. A common example, is the "Submit" button on 
	 * electronic forms.
	 * 
	 * @param is_printing set to true if the page should be rendered in print mode. 
	 * @default By default, print mode flag is set to false. 
	 */
	void SetPrintMode(bool is_printing);

	/** 
	 * Sets the default color of the page backdrop.
	 * 
	 * @default By default, the page color is white. 
	 * 
	 * @param r the red component of the page backdrop color.
	 * @param g the green component of the page backdrop color.
	 * @param b the blue component of the page backdrop color.
	 * 
	 * @note Only when the page backdrop is not set to transparent (SetPageTransparent), default
	 * page color is used.
	 */
	void SetDefaultPageColor(UInt8 r, UInt8 g, UInt8 b);

	/** 
	 * Sets the page color to transparent.
	 * 
	 * @default By default, PDFDraw assumes that the page is imposed directly on an 
	 * opaque white surface. Some applications may need to impose the page on a different 
	 * backdrop. In this case any pixels that are not covered during rendering will 
	 * be transparent.
	 * 
	 * @param is_transparent If true, page's backdrop color will be transparent.
	 * If false, the page's backdrop will be a opaque white.
	 * 
	 * @note If page transparency is enabled, the alpha channel will be preserved when 
	 * the image is exported as PNG, TIFF(when in RGB space), or RAW.
	 */
	void SetPageTransparent(bool is_transparent);

	/** 
	 * Enable or disable support for overprint and overprint simulation. 
	 * Overprint is a device dependent feature and the results will vary depending on 
	 * the output color space and supported colorants (i.e. CMYK, CMYK+spot, RGB, etc). 
	 * 
	 * @default By default overprint is only enabled for PDF/X files.
	 * 
	 * @param op e_op_on: always enabled; e_op_off: always disabled; e_op_pdfx_on: enabled for PDF/X files only.
	 */
	void SetOverprint(PDFRasterizer::OverprintPreviewMode op);

	/**
	 * A utility method to export the given PDF page to an image file.
	 * 
	 * @param page The source PDF page.
	 *
	 * @param filename - The name of the output image file. The filename should include 
	 * the extension suffix (e.g. 'c:/output/myimage.png').
	 *
	 * @encoder format - The file format of the output image. Currently supported formats 
	 * are: 
	 *    - "RAW"   : RAW format. There are four possibilities:
	 *				  e_rgba - if transparent and color page;
	 *				  e_gray_alpha - if transparent and gray page;
	 *				  e_rgb - if opaque and color page;
	 *				  e_gray - if opaque and gray page.
	 *				NOTE that if page is set to be transparent (SetPageTransparent), 
	 *				the output color channels are already multiplied by the alpha channel.
	 *    - "BMP"   : Bitmap image format (BMP)
	 *    - "JPEG"  : Joint Photographic Experts Group (JPEG) image format
	 *    - "PNG"   : 24-bit W3C Portable Network Graphics (PNG) image format
	 *    - "PNG8"  : 8-bit, palettized PNG format. The exported file size should be 
	 *                smaller than the one generated using "PNG", possibly at the 
	 *                expense of some image quality.
	 *    - "TIFF"  : Tag Image File Format (TIFF) image format.
	 *    - "TIFF8" : Tag Image File Format (TIFF) image format (with 8-bit palete).
	 *
	 * By default, the function exports to PNG.
	 * 
	 * @param encoder_params - An optional SDF dictionary object containing key/value
	 * pairs representing optional encoder parameters. The following table list possible 
	 * parameters for corresponding export filters:
	 * 
	 *  <table border="1">
	 *	<tr>
	 *		<td>Parameter/Key</td>
	 *		<td>Output Format</td>
	 *		<td>Description/Value</td>
	 *		<td>Example</td>
	 *	</tr>
	 *	<tr>
	 *		<td>Quality</td>
	 *		<td>JPEG</td>
	 *		<td>The value for compression 'Quality' must be a number between 0 and 100 
	 *			specifying the tradeoff between compression ratio and loss in image quality. 
	 *			100 stands for best quality.</td>
	 *		<td>
	 *			<P style="Z-INDEX: 0">hint.PutNumber("Quality", 60);</P>
	 *			<P>See the Example 2 in PDFDraw sample project.</P>
	 *		</td>
	 *	</tr>
	 *	<tr>
	 *		<td>Dither</td>
	 *		<td>
	 *			PNG, PNG8, TIFF or TIFF8.</td>
	 *		<td>A boolean used to enable or disable dithering. Relevent only for when the image 
	 *			is exported in palettized or monochrome mode.</td>
	 *		<td>hint.PutBool("Dither", true);</td>
	 *	</tr>
	 *	<tr>
	 *		<td>ColorSpace</td>
	 *		<td>PNG or TIFF for grayscale; TIFF for CMYK; PNG, BMP, JPEG, or TIFF for Separation.</td>
	 *		<td>A name object used to select the rendering and export color space. Currently 
	 *			supported values are "Gray", "RGB, "CMYK", and "Separation". The output image
	 *			format must support specified color space, otherwise the parameter will be ignored.
	 *			An example of image format that supports CMYK is TIFF. Image formats that support 
	 *			grayscale are PNG and TIFF. Separation output is supported in either a single
	 *			N-Channel TIFF, or in separate single-channel files (either PNG, BMP, or JPEG).
	 *			Output in "Separation" space implies that overprint simulation is on.
	 *			By default, the image is rendered and exported in RGB color space.</td>
	 *		<td>hint.PutName("ColorSpace", "CMYK");</td>
	 *	</tr>
	 *	<tr>
	 *		<td>BPC</td>
	 *		<td>PNG or TIFF.</td>
	 *		<td>A number used to specify 'bits per pixel' in the output file. Currently 
	 *			supported values are 1 and 8 (default is 8). To export monochrome (1 bit 
	 *			per pixel) image, use 1 as the value of BPC parameter and use TIFF or PNG as the 
	 *			export format for the image. By default, the image is not dithered when BPC is 1.
	 *			To enable dithering add 'Dither' option in the export hint.</td>
	 *		<td>hint.PutNumber("BPC", 1);</td>
	 *	</tr>
	 *  </table>
	 */
	void Export(Page page, const UString& filename, const char* format = "PNG", SDF::Obj encoder_params = 0);

       /**
	* Export the given PDF page to an image stream.
	* 
	* @param page The source PDF page.
	* @param stream - The output stream.
	* @encoder format - The output image format. See the the overloaded method for details.
	* @param encoder_params - Optional encoder parameters. See the the overloaded method for details.
	 */
	 void Export(Page page, Filters::Filter& stream, const char* format = "PNG", SDF::Obj encoder_params = 0);

       /**
	 * Returns a GDI+ bitmap for the given page.
	 * 
 	 * @param page The source PDF page. 
	 * @return GDI+ bitmap containing the rasterized image of the given page.
	 * 
	 * @note this method is available on .NET platform.
	 */
	#ifdef __DOTNET
	System::Drawing::Bitmap* GetBitmap(Page page);
	#endif

	/**
	 * Draws the contents of the page to a given device context.
	 * 
	 * @note this method is only supported on Windows platforms. 
	 * If your application is running on a Windows platform, you can 
	 * select GDI+ rasterizer with SetRasterizerType() and e_GDIPlus type.
	 *
 	 * @param page The source PDF page. 
	 * @param hdc Device context (i.e. HDC structure).
	 * @param rect The rectangle in the device context inside of which 
	 * the page will be drawn.
	 *
	 * @note This method is deprecated, since the GDI+ rasterizer itself is deprecated and will be removed in a future version of PDFNet. It is recommended to use the built-in rasterizer
	 * via GetBitmap or equivalent methods or utilize the XPS print path through Convert::ToXps or Print::StartPrintJob instead.
	 *
	 */
#if defined(_WIN32) && !defined(__WINRT__)
	void DrawInRect(Page& page, void* hdc, const Rect& rect);
#endif

	/**
	 * Pixel format type.
	 */
	enum PixelFormat {
		e_rgba,
		e_bgra,
		e_rgb,
		e_bgr,
		e_gray, 
		e_gray_alpha,
		e_cmyk
	};

	/**
	 * Returns the raw rasterized image data for the given image.
	 * 
	 * @note This method is relatively low-level and is only available in PDFNet for C++.
	 * If you are using PDFNet for .NET, you can use the function with the same name that
	 * directly returns GDI+ Bitmap.
	 * 
	 * @return a pointer to the internal memory buffer containing the rasterized image 
	 * of the given page. The buffer size is at least 'out_height*out_stride' bytes.
	 * The pixel data is stored in 8 bit per component, BGRA format.
 	 * @param page The source PDF page. 
	 * @param out_width - Filled by the method. The width of the target image in pixels.
	 * @param out_height - Filled by the method. The height of the target image in pixels (the number of rows).
	 * @param out_stride - Filled by the method. Stride determines the physical width 
	 * (in bytes) of one row in memory. If this value is negative the direction of the Y axis 
	 * is inverted. The absolute value of stride is of importance, because it allows rendering 
	 * in buffers where rows are padded in memory (e.g. in Windows bitmaps are padded on 4 byte 
	 * boundaries). 
	 * @param out_dpi - Filled by the method. The output resolution of the image (Dots Per Inch).
	 * @param pix_fmt - Optional parameter used to specify the desired pixel format. The default pixel format is e_bgra.
	 * @param demult - Specifies if the alpha is de-multiplied from the resulting color components. This
	 * parameter is only used for e_rgba, e_bgra, e_gray_alpha formats.
	 */
	const BitmapInfo GetBitmap(Page page, PixelFormat pix_fmt = e_bgra, bool demult = false);

	/**
	 * Returns a vector of rasterized separations for the given image.
	 *
	 * @note This method is relatively low-level and is only available in PDFNet for C++.
	 * If you are using PDFNet for .NET, you can use the function with the same name that
	 * directly returns GDI+ Bitmap.
	 *
	 * @return Separation has a pointer to the internal memory buffer containing the rasterized image
	 * of the given page. The buffer size is at least 'out_height*out_stride' bytes.
	 * The pixel data is stored in 8 bit per component, BGRA format.
	 * @param page The source PDF page.
	 */
	std::vector<Separation> GetSeparationBitmaps(Page page);

#ifndef SWIG
	const UChar* GetBitmap(Page page, int& out_width, int& out_height, int& out_stride, double& out_dpi, 
		PixelFormat pix_fmt = e_bgra, bool demult = false);
#endif

	/** 
	 * Sets the error handling function to be called in case an error is encountered 
	 * during page rendering.
	 * 
	 * @param error_proc Error handling callback function (or delegate in .NET)
	 * @param data Custom data to be passed as a second parameter to 'error_proc'.
	 */
#ifdef SWIG
	void SetErrorReportProc(Callback* instance);
#else
	void SetErrorReportProc(PDFRasterizer::ErrorReportProc error_proc, void* data);
#endif

	/**
	 * Set the color post processing transformation.
	 * This transform is applied to the rasterized bitmap as the final step
	 * in the rasterization process, and is applied directly to the resulting
	 * bitmap (disregarding any color space information). Color post
	 * processing only supported for RGBA output.
	 *
	 * @param mode is the specific transform to be applied
	 */
	void SetColorPostProcessMode(PDFRasterizer::ColorPostProcessMode mode);

	/**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_PDFDraw mp_draw;
#endif
private:
	// PDFDraw should not be copied
	PDFDraw(const PDFDraw& other);
	PDFDraw& operator= (const PDFDraw&);
// @endcond
};


#include <Impl/PDFDraw.inl>


	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPDFDraw
