//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.	 
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFImage
#define PDFTRON_H_CPPPDFImage

#include <PDF/GState.h>
#include <C/PDF/TRN_Image.h>


namespace pdftron { 
	namespace PDF {

/** 
 * Image class provides common methods for working with PDF images. 
 *
 * @note PDF::Element contains a similar interface used to access image data. 
 * To create the Image object from image PDF::Element, pass the Element's SDF/Cos 
 * dictionary to Image constructor (i.e. Image image(element->GetXObject()) )
 */ 
class Image
{
public:

	/**
	 * Create and embed an Image from an external file taking into account specified 
	 * compression hints. 
	 *
	 * By default the function will either pass-through data preserving the original 
	 * compression or will compress data using Flate compression. It is possible to 
	 * fine tune compression or to select a different compression algorithm using 
	 * 'encoder_hints' object.
	 * 
	 * @param doc - A document to which the image should be added. To obtain 
	 * SDF::Doc from PDFDoc use PDFDoc::GetSDFDoc() or Obj::GetDoc().
	 * 
	 * @param filename - The name of the image file. Currently supported formats are 
	 * JPEG, PNG, GIF, TIFF, BMP, EMF, and WMF. Other raster formats can be embedded by 
	 * decompressing image data and using other versions of Image::Create(...) method.
	 *
	 * @param encoder_hints - An optional SDF::Obj containing a hint (or an SDF::Array of 
	 * hints) that could be used to select a specific compression method and compression 
	 * parameters. For a concrete example of how to create encoder hints, please take a look 
	 * at JBIG2Test and AddImage sample projects. The image encoder accepts the following 
	 * hints:
	 * 
	 *  - /JBIG2; SDF::Name("JBIG2"), An SDF::Name Object with value equal to "JBIG2". If the 
	 *	image is monochrome (i.e. bpc == 1), the encoder will compress the image using JBIG2Decode 
	 *	filter.
	 *	Note that JBIG2 compression is not recommended for use on scanned text/financial documents or equivalent
	 *  since its lossless nature can lead to similar looking numbers or characters being replaced.
	 *
	 *  - [/JBIG2 /Threshold 0.6 /SharePages 50] - Compress a monochrome image using lossy JBIG2Decode 
	 *  compression with the given image threshold and by sharing segments from a specified number 
	 *  of pages. The threshold is a floating point number in the range from 0.4 to 0.9. Increasing the threshold 
	 *  value will increase image quality, but may increase the file size. The default value 
	 *  for threshold is 0.85. "SharePages" parameter can be used to specify the maximum number of 
	 *  pages sharing a common 'JBIG2Globals' segment stream. Increasing the value of this parameter 
	 *  improves compression ratio at the expense of memory usage.
	 *
	 *	- [/CCITT] - Compress a monochrome (i.e. bpc == 1) image using CCITT Group 4 compression. This algorithm typically produces 
	 *				larger output than JBIG2, but is lossless. This makes it much more suitable for scanned text documents.
	 *				CCITT is the best option for more general monochrome compression use cases, since JBIG2 has potential to change image content. 
	 *	
	 *  - [/JPEG] - Use JPEG compression with default compression. 
	 *  - [/JPEG /Quality 60] - Use JPEG compression with given quality setting. The "Quality" 
	 *	value is expressed on the 0..100 scale.
	 *
	 *  - [/JP2] or [/JPEG2000] - Use JPEG2000 compression to compress a RGB or a grayscale image
	 *
	 *  - [/Flate] - Use Flate compression with maximum compression at the expense of 
	 *	speed. 
	 *
	 *  - [/Flate /Level 9] - Use Flate compression using specified compression level. 
	 *	Compression "Level" must be a number between 0 and 9: 1 gives best speed, 
	 *	9 gives best compression, 0 gives no compression at all (the input data is simply 
	 *	copied a block at a time). 
	 *
	 *  - /RAW or [/RAW] - The encoder will not use any compression method and the image 
	 *	will be stored in the raw format.
	 * 
	 * @return PDF::Image object representing the embedded image.
	 * @note For C++ developers: Current document does not take the ownership of the 
	 * encoder_hints object. Therefore it is a good programming practice to create 
	 * encoder_hints object on the stack.
	 */
	 static Image Create(SDF::SDFDoc& doc, const UString& filename, SDF::Obj encoder_hints = 0);

	/**
	 * Create and embed an Image. Embed the raw image data taking into account 
	 * specified compression hints. 
	 *
	 * By default the function will compress all images using Flate compression.
	 * It is possible to fine tune compression or to select a different compression 
	 * algorithm using 'encoder_hints' object.
	 * 
	 * @param doc - A document to which the image should be added. The 'Doc' object 
	 * can be obtained using Obj::GetDoc() or PDFDoc::GetSDFDoc().
	 * @param buf - The stream or buffer containing image data. The image data must 
	 * not be compressed and must follow PDF format for sample representation (please refer
	 * to section 4.8.2 'Sample Representation' in PDF Reference Manual for details).
	 * @param width - The width of the image, in samples.
	 * @param height - The height of the image, in samples.
	 * @param bpc - The number of bits used to represent each color component.
	 * @param color_space - The color space in which image samples are represented.
	 * @param encoder_hints - An optional parameter that can be used to fine tune 
	 * compression or to select a different compression algorithm. See Image::Create() 
	 * for details.
	 *
	 * @return PDF::Image object representing the embedded image.
	 */
	 static Image Create(SDF::SDFDoc& doc,
		 const unsigned char* buf,
		 size_t buf_size,
		int width,
		int height,
		int bpc, 
		ColorSpace color_space, 
		SDF::Obj encoder_hints = 0);

	/**
	 * Create and embed an Image. Embed the raw image data taking into account 
	 * specified compression hints. 
	 * @note see Image::Create for details.
	 */
	 static Image Create(SDF::SDFDoc& doc,
		Filters::FilterReader& image_data,
		int width,
		int height,
		int bpc, 
		ColorSpace color_space, 
		SDF::Obj encoder_hints = 0);

	 /**
	 * Create and embed an Image. Embed the raw image data taking into account
	 * specified compression hints.
	 * @note see Image::Create for details.
	 */
	 static Image Create(SDF::SDFDoc& doc,
		 const unsigned char* buf,
		 size_t buf_size,
		 SDF::Obj encoder_hints = 0);

	 /**
	 * Create and embed an Image. Embed the raw image data taking into account
	 * specified compression hints.
	 *
	 * @note see Image::Create for details.
	 * @note PDFNet takes ownership of the filter
	 */
	 static Image Create(SDF::SDFDoc& doc,
		 Filters::Filter image_data,
		 SDF::Obj encoder_hints = 0);

	/**
	 * Create and embed an Image from any GDI+ Bitmap taking into account 
	 * specified compression hints. 
	 * 
	 * @note see Image::Create for details.
	 * @note This method is available only on Windows platforms.
	 *
	 * @param doc - A document to which the image should be added. The 'Doc' object 
	 * can be obtained using Obj::GetDoc() or PDFDoc::GetSDFDoc().
	 * @param bmp - GDI+ bitmap.
	 *
	 * @return PDF::Image object representing the embedded image.
	 */
	#if defined(_WIN32)
	 static Image Create(SDF::SDFDoc& doc, Gdiplus::Bitmap* bmp, SDF::Obj encoder_hints = 0);
	#endif

	/**
	 * Create and embed an ImageMask. Embed the raw image data taking into account 
	 * specified compression hints. The ImageMask can be used as a stencil mask for 
	 * painting in the current color or as an explicit mask specifying which areas of 
	 * the image to paint and which to mask out. One of the most important uses of 
	 * stencil masking is for painting character glyphs represented as bitmaps.
	 * 
	 * @param doc - A document to which the image should be added. The 'Doc' object 
	 * can be obtained using Obj::GetDoc() or PDFDoc::GetSDFDoc().
	 * @param buf - The stream or buffer containing image data stored in 1 bit per 
	 * sample format. The image data must not be compressed and must follow PDF format for 
	 * sample representation (please refer to section 4.8.2 'Sample Representation' in PDF 
	 * Reference Manual for details).
	 * @param width - The width of the image, in samples.
	 * @param height - The height of the image, in samples.
	 * @param encoder_hints - An optional parameter that can be used to fine tune 
	 * compression or to select a different compression algorithm. See Image::Create() 
	 * for details.
	 *
	 * @return PDF::Image object representing the embedded ImageMask.
	 */
	 static Image CreateImageMask(SDF::SDFDoc& doc,
		 const char* buf,
		 size_t buf_size,
		int width,
		int height,
		SDF::Obj encoder_hints = 0);

	/**
	 * Create and embed an ImageMask.
	 * @note see Image::CreateImageMask for details.
	 */ 
	 static Image CreateImageMask(SDF::SDFDoc& doc,
		Filters::FilterReader& image_data, 				 
		int width,
		int height,
		SDF::Obj encoder_hints = 0);

	/** 
	 * Create and embed a Soft Mask. Embed the raw image data taking into account 
	 * specified compression hints.
	 * A soft-mask image (see "Soft-Mask Images" in PDF Reference Manual) is 
	 * used as a source of mask shape or mask opacity values in the transparent 
	 * imaging model. 
	 * 
	 * @param doc - A document to which the image should be added. The 'Doc' object 
	 * can be obtained using Obj::GetDoc() or PDFDoc::GetSDFDoc().
	 * @param buf - The stream or buffer containing image data represented in 
	 * DeviceGray color space (i.e. one component per sample). The image data must not 
	 * be compressed and must follow PDF format for sample representation (please refer
	 * to section 4.8.2 'Sample Representation' in PDF Reference Manual for details).
	 * @param width - The width of the image, in samples.
	 * @param height - The height of the image, in samples.
	 * @param bpc - The number of bits used to represent each color component.
	 * @param encoder_hints - An optional parameter that can be used to fine tune 
	 * compression or to select a different compression algorithm. See Image::Create() 
	 * for details.

	 * @note this feature is available only in PDF 1.4 and higher.
	 */
	 static Image CreateSoftMask(SDF::SDFDoc& doc,
		 const char* buf,
		 size_t buf_size,
		int width,
		int height,
		int bpc, 
		SDF::Obj encoder_hints = 0);

	/**
	 * Create and embed a Soft Mask. Embed the raw image data taking into account 
	 * specified compression hints.
	 * @note see Image::CreateSoftMask for details.
	 */ 
	 static Image CreateSoftMask(SDF::SDFDoc& doc,
		Filters::FilterReader& image_data, 				 
		int width,
		int height,
		int bpc, 
		SDF::Obj encoder_hints = 0);

	// ------------------------------------------------

	enum InputFilter
	{
		e_none,     // Input stream is not compressed
		e_jpeg,     // Input image is a JPEG image
		e_jp2,      // Input image is a JP2 (JPEG2000) image
		e_flate,    // Input image is a Flate compressed
		e_g3,       // Input image is a G3 stream
		e_g4,       // Input image is a G4 stream
		e_ascii_hex // Input image stream compressed using ASCIIHexDecode filter
	};

	/** 
	 * Directly embed the image that is already compressed using the Image::InputFilter 
	 * format. The function can be used to pass-through pre-compressed image data.
	 * 
	 * @param doc - A document to which the image should be added. The 'Doc' object 
	 * can be obtained using Obj::GetDoc() or PDFDoc::GetSDFDoc().
	 * @param buf - The stream or buffer containing compressed image data. 
	 * The compression format must match the input_format parameter. 
	 * @param width - The width of the image, in samples.
	 * @param height - The height of the image, in samples.
	 * @param bpc - The number of bits used to represent each color component.
	 * @param color_space - The color space in which image samples are specified.
	 * @param input_format - Image::InputFilter describing the format of pre-compressed 
	 * image data.
	 * @param encoder_hints - An optional parameter that can be used to fine tune 
	 * compression or to select a different compression algorithm. See Image::Create() 
	 * for details.
	 * @return PDF::Image object representing the embedded image.
	 */ 
	 static Image Create(SDF::SDFDoc& doc,
		 const char* buf,
		 size_t buf_size,
		int width, 
		int height, 
		int bpc, 
		ColorSpace color_space,
		InputFilter input_format);


	/**
	 * Embed the raw image data taking into account specified compression hints. 
	 * @note see the above method for details.
	 */
	 static Image Create(SDF::SDFDoc& doc,
		Filters::FilterReader& image_data, 				 
		int width, 
		int height, 
		int bpc, 
		ColorSpace color_space,
		InputFilter input_format);

	/**
	 * Create an image from an existing image represented as a SDF/Cos object.
	 * 
	 * @note To create the Image object from image PDF::Element, pass the Element's 
	 * SDF/Cos dictionary to Image constructor (i.e. Image image(element->GetXObject()))
	 */
	 Image(SDF::Obj image_xobject = 0);

	 Image(const Image&);
	 Image& operator=(const Image&);

	/**
	 * @return the underlying SDF/Cos object
	 */
	 SDF::Obj GetSDFObj () const;

	/**
	 * @return whether this is a valid raster image. If the function returns false the 
	 * underlying SDF/Cos object is not a valid raster image and this Image object should 
	 * be treated as null.
	 */ 	
	 bool IsValid() const;

	/** 
	 * @return A stream (filter) containing decoded image data 
	 */
	 Filters::Filter GetImageData() const;

	/** 
	 * @return the size of image data in bytes
	 */
	 int GetImageDataSize() const;

	/**
	 * Convert PDF image to GDI+ Bitmap. 
	 * 
	 * @return GDI+ bitmap from this image. PDFNet creates a GDI+ 
	 * bitmap that closely matches the original image in terms
	 * of the image depth and the number of color channels. PDF color 
	 * spaces that do not have a counterpart in GDI+ are converted 
	 * to RGB.
	 * 
	 * @note This method is available only on Windows platforms.
	 */
	#if defined(_WIN32)
	 Gdiplus::Bitmap* GetBitmap() const;
	#endif

	/** 
	 * @return The SDF object representing the color space in which image 
	 * samples are specified or NULL if: 	 
	 *  - the image is an image mask 
	 *  - or is compressed using JPXDecode with missing ColorSpace entry in image dictionary. 
	 * 
	 * The returned color space may be any type of color space except Pattern.
	 */
	 ColorSpace GetImageColorSpace() const;

	/** 
	 * @return the width of the image, in samples.
	 */
	 int GetImageWidth() const;

	/** 
	 * @return the height of the image, in samples.
	 */
	 int GetImageHeight() const;

	/** 
	 * @return Decode array or NULL if the parameter is not specified. A decode object is an 
	 * array of numbers describing how to map image samples into the range of values 
	 * appropriate for the images color space . If ImageMask is true, the array must be 
	 * either [0 1] or [1 0]; otherwise, its length must be twice the number of color 
	 * components required by ColorSpace. Default value depends on the color space, 
	 * See Table 4.36 in PDF Ref. Manual.
	 */
	 SDF::Obj GetDecodeArray() const;

	/** 
	 * @return the number of bits used to represent each color component. Only a 
	 * single value may be specified; the number of bits is the same for all color 
	 * components. Valid values are 1, 2, 4, 8, and 16. 
	 */
	 int GetBitsPerComponent() const;

	/** 
	 * @return the number of color components per sample.
	 */
	 int GetComponentNum() const;

	/** 
	 * @return a boolean indicating whether the inline image is to be treated as an image mask.
	 */
	 bool IsImageMask() const;

	/** 
	 * @return a boolean indicating whether image interpolation is to be performed.
	 */
	 bool IsImageInterpolate() const; 

	/** 
	 * @return an image XObject defining an image mask to be applied to this image (See
	 * 'Explicit Masking', 4.8.5), or an array specifying a range of colors
	 * to be applied to it as a color key mask (See 'Color Key Masking'). 
	 * 
	 * If IsImageMask() return true, this method will return NULL.
	 */
	 SDF::Obj GetMask() const; 

	/** 
	 * Set an Explicit Image Mask.
	 *
	 * @param image_mask An Image object which serves as an explicit mask for the
	 * base (this) image. The base image and the image mask need not have the
	 * same resolution (Width and Height values), but since all images are defined on
	 * the unit square in user space, their boundaries on the page will coincide; that is,
	 * they will overlay each other. The image mask indicates which places on the page
	 * are to be painted and which are to be masked out (left unchanged). Unmasked areas
	 * are painted with the corresponding portions of the base image; masked areas
	 * are not.
	 * 
	 * @note image_mask must be a valid image mask (i.e. image_mask.IsImageMask() must 
	 * return true.
	 */
	 void SetMask(Image& image_mask); 

	/** 
	 * Set a Color Key Mask.
	 * 
	 * @param mask is an Cos/SDF array specifying a range of colors to be masked 
	 * out. Samples in the image that fall within this range are not painted, allowing 
	 * the existing background to show through. The effect is similar to that of the 
	 * video technique known as chroma-key. For details of the array format please 
	 * refer to section 4.8.5 'Color Key Masking' in PDF Reference Manual.
	 * 
	 * @note the current document takes the ownership of the given SDF object.
	 */ 
	 void SetMask(SDF::Obj mask); 

	/** 
	 * @return an image XObject defining a Soft Mask to be applied to this image 
	 * (See section 7.5.4 'Soft-Mask Images' in PDF Reference Manual), or NULL 
	 * if the image does not have the soft mask.
	 */
	 SDF::Obj GetSoftMask();

	/** 
	 * Set a Soft Mask.
	 * 
	 * @param soft_mask is a subsidiary Image object defining a soft-mask image 
	 * (See section 7.5.4 'Soft-Mask Images' in PDF Reference Manual) to be used 
	 * as a source of mask shape or mask opacity values in the transparent imaging 
	 * model. The alpha source parameter in the graphics state determines whether 
	 * the mask values are interpreted as shape or opacity.
	 */
	 void SetSoftMask(Image& soft_mask);

	/** 
	 * @return The color rendering intent to be used in rendering the image.
	 */
	 GState::RenderingIntent GetImageRenderingIntent() const;
    
	/**
	 * Saves this image to a file. 
	 * 
	 * The output image format (TIFF, JPEG, or PNG) will be 
	 * automatically selected based on the properties of the embedded 
	 * image. For example, if the embedded image is using CCITT Fax
	 * compression, the output format will be TIFF. Similarly, if the
	 * embedded image is using JPEG compression the output format will 
	 * be JPEG. If your application needs to explicitly control output 
	 * image format you may want to use ExportAsTiff() or ExportAsPng().
	 *
	 * @param filename string that specifies the path name for 
	 * the saved image. The filename should not include the extension
	 * which will be appended to the filename string based on the output
	 * format.
	 *
	 * @return the number indicating the selected image format:
	 * (0 - PNG, 1 - TIF, 2 - JPEG).
	 */
	 int Export(const UString& filename);

	/**
	 * Saves this image to the output stream.
	 * (0 - PNG, 1 - TIF, 2 - JPEG).
	 * 
	 * @param writer A pointer to FilterWriter used to write to the 
	 * output stream. If the parameter is null, nothing will be written 
	 * to the output stream, but the function returns the format identifier.
	 * 
	 * @return the number indicating the selected image format:
	 * @note see the overloaded Image::Export method for more information.
	 */
	 int Export(Filters::FilterWriter& writer);

	/**
	 * Saves this image to a TIFF file. 
	 *
	 * @param filename string that specifies the path name for 
	 * the saved image. The filename should include the file extension
	 */
	 void ExportAsTiff(const UString& filename);

	/**
	 * Saves this image to a TIFF output stream. 
	 *
	 * @param writer FilterWriter used to write to the output stream.
	 */
	 void ExportAsTiff(Filters::FilterWriter& writer);

	/**
	 * Saves this image to a PNG file. 
	 *
	 * @param filename string that specifies the path name for 
	 * the saved image. The filename should include the file extension
	 */
	 void ExportAsPng(const UString& filename);

	/**
	 * Saves this image to a PNG output stream. 
	 *
	 * @param writer FilterWriter used to write to the output stream.
	 */
	 void ExportAsPng(Filters::FilterWriter& writer);


// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	Image(TRN_Image impl);
	TRN_Image mp_image;
#endif
// @endcond
};



#include <Impl/Image.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFImage
