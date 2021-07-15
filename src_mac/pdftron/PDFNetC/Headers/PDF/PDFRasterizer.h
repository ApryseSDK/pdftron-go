//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFRasterizer
#define PDFTRON_H_CPPPDFRasterizer

#include <PDF/Page.h>
#include <C/PDF/TRN_PDFRasterizer.h>
#include <PDF/OCG/Context.h>
#ifdef SWIG
#include <PDF/Callback.h>
#endif
#include <C/Common/TRN_Types.h>

namespace pdftron { 
	namespace PDF {

/** DownloadedType lists the events triggered by calling OpenURLAsync. */
enum DownloadedType
{
	/** A new page has been downloaded. */
	e_downloadedtype_page = 0,
	/** A thumbnail has been downloaded. */
	e_downloadedtype_thumb,
	/** The named destinations have been downloaded. These may be necessary for link activation. */
	e_downloadedtype_named_dests,
	/** The document outline (bookmarks) has been downloaded. */
	e_downloadedtype_outline,
	/** The entire document has been downloaded. */
	e_downloadedtype_finished,
	/** An error has occurred while downloading and downloading has stopped. */
	e_downloadedtype_failed,
	/** The initial document information is available and it is now ok to query for document information. */
	e_downloadedtype_opened
};

class PDFDoc;
/** 
 * Download event handling.
 * A type of callback function (or a delegate in .NET terminology) that is called
 * during download events triggered by calling OpenURLAsync.
 */
typedef void (*DownloadReportHandler) (DownloadedType type, PDFDoc* doc, int page_num, int obj_num, const char* message, void* data);

/**
 *  This class is used to store separations in PDFRasterize and PDFDraw  
 */
class Separation : public TRN_separation
{
public:
	Separation();
	~Separation();
	Separation(const Separation&);
	Separation& operator= (const Separation&);
	UInt8 C() const;
	UInt8 M() const;
	UInt8 Y() const;
	UInt8 K() const;
	UInt32 GetDataSize() const;
	UString GetSeparationName() const;
#ifdef SWIG
	std::vector<unsigned char> GetData() const;
#else
	const UChar* GetData() const;
#endif

	UString m_separation_name;

private:
	bool m_owner;
};

/** 
 * PDFRasterizer is a low-level PDF rasterizer.
 * 
 * The main purpose of this class is to convert PDF pages to raster 
 * images (or bitmaps).
 * 
 * @note PDFRasterizer is a relatively low-level class. If you need to 
 * convert PDF page to an image format or a Bitmap, consider 
 * using PDF::PDFDraw. Similarly, if you are building an interactive 
 * PDF viewing application you may want to use PDF::PDFView instead.
 */
class PDFRasterizer
{
public:

	/**
	 * PDFNet includes two separate rasterizer implementations utilizing different 
	 * graphics libraries.
	 * 
	 * The default rasterizer is 'e_BuiltIn' which is a high-quality, 
	 * anti-aliased and platform independent rasterizer. This rasterizer
	 * is available on all supported platforms.
	 * 
	 * On Windows platforms, PDFNet also includes GDI+ based rasterizer.
	 * (deprecated and will be removed in a future version of PDFNet)
	 * This rasterizer is included mainly to provide vector output for 
	 * printing, for EMF/WMF export, etc. For plain image rasterization 
	 * we recommend using the built-in rasterizer.
	 */
	enum Type {
		e_BuiltIn,  ///< high-quality, platform independent rasterizer.
		e_GDIPlus   ///< GDI+ based rasterizer. (Deprecated)
	}; 

	/**
	 * Determines if overprint is used.
	 * e_op_on: overprint is always on;
	 * e_op_off: overprint is always off.
	 * e_op_pdfx_on: overprint is on only for PDF/X files.
	 */
	enum OverprintPreviewMode {
		e_op_off = 0,
		e_op_on,
		e_op_pdfx_on
	};

	/**
	 * PDFRasterizer constructor and destructor
	 */
	PDFRasterizer(Type type = e_BuiltIn);
	~PDFRasterizer();

	/**
	 * Draws the page into a given memory buffer.
	 * 
	 * @note This method is available on all platforms and in all 
	 * rasterizer implementations.
	 * 
	 * @param page The page to rasterize. 
	 * @param in_out_image_buffer A pointer to a memory buffer. The buffer must contain 
	 * at least (stride * height) bytes.
	 * @param width The width of the target image in pixels.
	 * @param height The height of the target image in pixels (the number of rows).
	 * @param stride Stride determines the physical width (in bytes) of one row in memory. 
	 * If this value is negative the direction of the Y axis is inverted. The absolute 
	 * value of stride is of importance, because it allows rendering in buffers where
	 * rows are padded in memory (e.g. in Windows bitmaps are padded on 4 byte boundaries). 
	 * Besides allowing rendering on the whole buffer stride parameter can be used 
	 * for rendering in a rectangular subset of a buffer.
	 * @param num_comps The number (4 or 5) representing the number of color components 
	 * in the device color space. For BGR+Alpha set this parameter to 4, and for CMYK+Alpha use 5. 
	 * If other values are set, exceptions will be thrown.
	 * @param demult - Specifies if the alpha is de-multiplied from the resulting color components. 
	 * @param device_mtx Device transformation matrix that maps PDF page from PDF user space 
	 * into device coordinate space (e.g. pixel space). PDF user space is represented in 
	 * page units, where one unit corresponds to 1/72 of an inch.
	 * @param clip Optional parameter defining the clip region for the page. If the parameter
	 *  is null or is not specified, PDFRasterizer uses page's crop box as a default clip region.
	 * @param scrl_clp_regions Optional parameter reserved for a future use.
	 * @param cancel An optional variable that can be used to stop the rendering thread. 
	 * 
	 *
	 * Sample code:
	 * @code
	 *   float drawing_scale = 2: 
	 *   Common::Matrix2D mtx(drawing_scale, 0, 0, drawing_scale, 0, 0);
	 *   PDF::Rect bbox(page.GetMediaBox());
	 *   bbox.Normalize();
	 *   int width = int(bbox.Width() * drawing_scale); 
	 *   int height = int(bbox.Height() * drawing_scale);
	 * 
	 *   // Stride is represented in bytes and is aligned on 4 byte 
	 *   // boundary so that you can render directly to GDI bitmap.
	 *   // A negative value for stride can be used to flip the image 
	 *   // upside down.
	 *   int comps = 4;  // for BGRA
	 *   int stride = ((width * comps + 3) / 4) * 4;
	 *
	 *   // buf is a memory buffer containing at least (stride*height) bytes.
	 * 	 memset(ptr, 0xFF, height*stride);  // Clear the background to opaque white paper color.
	 * 
	 *   PDFRasterizer rast;
	 *   rast.Rasterize(page, buf, width, height, stride, 4, false, mtx);
	 * @endcode 
	 */
#ifndef SWIG
	std::vector<unsigned char> Rasterize(Page& page,
				int width, int height, int stride, 
				int num_comps, bool demult,
				const Common::Matrix2D& device_mtx,
				const Rect* clip = 0,
				const Rect* scrl_clip_regions = 0,
				bool* cancel = 0);

	void Rasterize(Page& page, UChar* in_out_image_buffer, 
				int width, int height, int stride, 
				int num_comps, bool demult,
				const Common::Matrix2D& device_mtx,
				const Rect* clip = 0,
				const Rect* scrl_clip_regions = 0,
				bool* cancel = 0);
#else // SWIG
    std::vector<unsigned char> Rasterize(
        Page& page,
        int width,
        int height,
        int stride,
        int num_comps,
        bool demult,
        const Common::Matrix2D& device_mtx,
        const Rect* clip = 0,
        const Rect* scrl_clip_regions = 0
    );
#endif // SWIG

	/**
	 * Draws the page into a given memory buffer.
	 *
	 * @note This method is available on all platforms and in all
	 * rasterizer implementations.
	 *
	 * @param page The page to rasterize.
	 * @param width The width of the target image in pixels.
	 * @param height The height of the target image in pixels (the number of rows).
	 * @param mtx Device transformation matrix that maps PDF page from PDF user space
	 * into device coordinate space (e.g. pixel space). PDF user space is represented in
	 * page units, where one unit corresponds to 1/72 of an inch.
	 * @param clip Optional parameter defining the clip region for the page. If the parameter
	 *  is null or is not specified, PDFRasterizer uses page's crop box as a default clip region.
	 * @param cancel An optional variable that can be used to stop the rendering thread.
	 */
	std::vector<Separation> RasterizeSeparations(
		Page& page,
		int width,
		int height,
		const Common::Matrix2D& mtx,
		const Rect* clip,
		volatile bool* cancel
	);

#ifdef _WIN32
	/**
	 * Draws the contents of the page to a given device context.
	 *
	 * This method can be used to send raster or GDI output to arbitrary
	 * Windows device context (e.g. memory bitmap device, printer device,
	 * or EMF/WMF record).
	 *
	 * See also PDF::PDFDraw::DrawInRect()
	 *
	 * @note this method is only supported on Windows platforms.
	 * If your application is running on a Windows platform, you can
	 * select GDI+ rasterizer with SetRasterizerType() and e_GDIPlus type.
	 *
	 * @param page The page to rasterize.
	 * @param hdc Device context (i.e. HDC structure).
	 * @param device_mtx Device transformation matrix that maps PDF page from PDF user space
	 * into device coordinate space (e.g. pixel space). PDF user space is represented in
	 * page units, where one unit corresponds to 1/72 of an inch.
	 * @param clip Optional parameter defining the clip region for the page. In the parameter
	 *  is null or is not specified, PDFRasterizer uses page's crop box as a default clip region.
	 * @param dpi Optional parameter used to specify the resolution of the rasterized bitmap.
	 * This parameter is used only for built-in rasterizer. If the parameter is not specified or
	 * is less than zero, PDFNet will query the target device to determine the output resolution.
	 * @param cancel An optional variable that can be used to stop the rendering thread.
	 *
	 * @note This method is deprecated, since the GDI+ rasterizer itself is deprecated and will be removed in a future version of PDFNet. It is recommended to use the built-in rasterizer
	 * via other Rasterize methods or utilize the XPS print path through Convert::ToXps or Print::StartPrintJob instead.
	 *
	 */
	void Rasterize(Page& page, void* hdc, 
		const Common::Matrix2D& device_mtx, 
		const Rect* clip = 0,
		int dpi = -1,
		bool* cancel = 0);
#endif
	/**
	 * Enable or disable annotation and forms rendering. By default, annotations and forms 
	 * are rendered.
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
	 * 
	 * @default Anti-aliasing is enabled by default.
	 */
	void SetAntiAliasing(bool enable_aa);

	/**
	 * Enable or disable path hinting.
	 * 
	 * @param enable_hinting if true path hinting is enabled. Path hinting is used to slightly
	 * adjust paths in order to avoid or alleviate artifacts of hair line cracks between
	 * certain graphical elements. This option is turned on by default.
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
	 * @param expgamma is the exponent value of gamma function. Typical values 
	 * are in the range from 0.1 to 3. 
	 *  
	 * Gamma correction can be used to improve the quality of anti-aliased
	 * image output and can (to some extent) decrease the appearance common 
	 * anti-aliasing artifacts (such as pixel width lines between polygons).
	 * 
	 * @note Gamma correction is used only in the built-in rasterizer.
	 */
	void SetGamma(double expgamma);

	/** 
	 * Sets the Optional Content Group (OCG) context that should be used when 
	 *  rendering the page. This function can be used to selectively render optional
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
	 * @param is_printing set to true is the page should be rendered in print mode. 
	 * @default By default, print mode flag is set to false. 
	 */
	void SetPrintMode(bool is_printing);

	/** 
	 * Enable or disable support for overprint and overprint simulation. 
	 * Overprint is a device dependent feature and the results will vary depending on 
	 * the output color space and supported colorants (i.e. CMYK, CMYK+spot, RGB, etc). 
	 * 
	 * @default By default overprint is only enabled for PDF/X files.
	 * 
	 * @param op e_op_on: always enabled; e_op_off: always disabled; e_op_pdfx_on: enabled for PDF/X files only.
	 */
	void SetOverprint(OverprintPreviewMode op);

	/** 
	 * Error handling.
	 * A type of callback function (or a delegate in .NET terminology) that is called in case
	 * an error is encountered during rendering.
	 */
	typedef void (*ErrorReportProc) (const char* message, void* data);

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
	void SetErrorReportProc(ErrorReportProc error_proc, void* data);
#endif

	/**
	 * Sets the core graphics library used for rasterization and 
	 * rendering. Using this method it is possible to quickly switch 
	 * between different implementations. By default, PDFNet uses a 
	 * built-in, high-quality, and platform independent rasterizer.
	 *
	 * @param type Rasterizer type. 
	 *
	 * @note This method is deprecated, since the GDI+ rasterizer itself is deprecated and will be removed in a future version of PDFNet. 
	 * It is strongly recommended to use the built-in rasterizer and to use the XPS print path where vector conversion is needed.
	 */
	void SetRasterizerType (Type type);

	/**
	 * @return the type of current rasterizer.
	 * @note This method is deprecated, since the GDI+ rasterizer itself is deprecated and will be removed in a future version of PDFNet.
	 * It is strongly recommended to use the built-in rasterizer and to use the XPS print path where vector conversion is needed.
	 */
	Type GetRasterizerType ();

	/** 
	 * ColorPostProcessMode is used to modify colors after rendering.
	 */
	enum ColorPostProcessMode
	{
		e_postprocess_none = 0,
		e_postprocess_invert,
        e_postprocess_gradient_map,
        e_postprocess_night_mode
	};
    
	/**
	 * Set the color post processing transformation.
	 * This transform is applied to the rasterized bitmap as the final step
	 * in the rasterization process, and is applied directly to the resulting
	 * bitmap (disregarding any color space information). Color post
	 * processing only supported for RGBA output.
	 *
	 * @param mode is the specific transform to be applied
	 */
	 void SetColorPostProcessMode(ColorPostProcessMode mode);

	 /**
	 * @return the current color post processing mode.
	 */
	 ColorPostProcessMode GetColorPostProcessMode() const;

	 /**
	 *  This function is typically called for progressive rendering, in which
	 *  we don't want to stop the main rendering thread. Since the rendering thread may
	 *  modify separation channels, we don't consider separations in progressive rendering.
	 */ 
	 void UpdateBuffer();

	/**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_PDFRasterizer mp_rast;
private:
	PDFRasterizer(const PDFRasterizer&);
	PDFRasterizer& operator= (const PDFRasterizer&);
#endif
// @endcond
};



#include <Impl/PDFRasterizer.inl>

	
	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFRasterizer
