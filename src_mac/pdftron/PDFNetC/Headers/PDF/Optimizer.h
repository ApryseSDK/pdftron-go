//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFOptimizer
#define PDFTRON_H_CPPPDFOptimizer

#include <PDF/PDFDoc.h>
#include <C/PDF/TRN_Optimizer.h>

namespace pdftron{
	namespace PDF{


class ImageSettings;
class MonoImageSettings;
class TextSettings;
class OptimizerSettings;

/**
 * The Optimizer class provides functionality for optimizing/shrinking
 * output PDF files.
 * 
 * 'pdftron.PDF.Optimizer' is an optional PDFNet Add-On utility class that can be 
 * used to optimize PDF documents by reducing the file size, removing redundant 
 * information, and compressing data streams using the latest in image compression 
 * technology. PDF Optimizer can compress and shrink PDF file size with the 
 * following operations:
 * - Remove duplicated fonts, images, ICC profiles, and any other data stream. 
 * - Optionally convert high-quality or print-ready PDF files to small, efficient and web-ready PDF. 
 * - Optionally down-sample large images to a given resolution. 
 * - Optionally compress or recompress PDF images using JBIG2 and JPEG2000 compression formats. 
 * - Compress uncompressed streams and remove unused PDF objects. 
 * 
 * @note 'Optimizer' is available as a separately licensable add-on to PDFNet 
 * core license.
 * 
 * @note See 'pdftron.PDF.Flattener' for alternate approach to optimize PDFs for fast 
 * viewing on mobile devices and the Web.
 */
class Optimizer
{
public:
	typedef pdftron::PDF::ImageSettings ImageSettings;
	typedef pdftron::PDF::MonoImageSettings MonoImageSettings;
	typedef pdftron::PDF::TextSettings TextSettings;
	typedef pdftron::PDF::OptimizerSettings OptimizerSettings;


/**
  * Optimize the given document using the optimizers settings
  * @param doc the document to optimize
  * @param color_image_settings the image processing settings
  * for color images
  * @param grayscale_image_settings the image processing settings
  * for grayscale images
  * @param mono_image_settings the image processing settings
  * for monochrome images
  */
	static void Optimize(PDFDoc& doc, const OptimizerSettings& settings);
	static void Optimize(PDFDoc& doc);

	// @cond PRIVATE_DOC

#ifndef SWIGHIDDEN
private:
	Optimizer() {};
#endif
	// @endcond

};


/**
 * A class that stores downsampling/recompression
 * settings for color and grayscale images.
 */
class ImageSettings : public TRN_OptimizerImageSettings
{
public:
	enum CompressionMode
	{
		e_retain,
		e_flate, 
		e_jpeg,
		e_jpeg2000,
		e_none
	};

	enum DownsampleMode
	{
		e_off,
		e_default
	};
	  /**
		* 	create an ImageSettings object with default options
		*/
	ImageSettings();

	  /**
		* Sets the maximum and resampling dpi for images.
		* By default these are set to 144 and 96 respectively.
		* @param maximum the highest dpi of an image before
		* it will be resampled
		* @param resampling the image dpi to resample to if an
		* image is encountered over the maximum dpi
		*/
	void SetImageDPI(double maximum,double resampling);

	  /**
		* Sets the output compression mode for this type of image
		* The default value is e_retain
		* @param mode the compression mode to set
		*/
	void SetCompressionMode(enum CompressionMode mode);

	  /**
		* Sets the downsample mode for this type of image
		* The default value is e_default which will allow downsampling of images
		* @param mode the downsample mode to set
		*/
	void SetDownsampleMode(enum DownsampleMode mode);

	  /**
		* Sets the quality for lossy compression modes
		* from 1 to 10 where 10 is lossless (if possible)
		* the default value is 5
		*/
	void SetQuality(UInt32 quality);

	  /**
		* Sets whether recompression to the specified compression
		* method should be forced when the image is not downsampled.
		* By default the compression method for these images
		* will not be changed.
		* @param force if true the compression method for all
		* images will be changed to the specified compression mode
		*/
	void ForceRecompression(bool force);

	  /**
		* Sets whether image changes that grow the
		* PDF file should be kept.  This is off by default.
		* @param force if true all image changes will be kept.
		*/
	void ForceChanges(bool force);
};

  /**
	* A class that stores image downsampling/recompression
	* settings for monochrome images.
	*/
class MonoImageSettings : public TRN_OptimizerMonoImageSettings
{
public:
	enum CompressionMode
	{
		e_jbig2,
		e_flate,
		e_none,
		e_ccitt
	};

	enum DownsampleMode
	{
		e_off,
		e_default
	};

	  /**
		* 	create an MonoImageSettings object with default options
		*/
	MonoImageSettings();

	  /**
		* Sets the maximum and resampling dpi for monochrome images.
		* By default these are set to 144 and 96 respectively.
		* @param maximum the highest dpi of an image before
		* it will be resampled
		* @param resampling the image dpi to resample to if an
		* image is encountered over the maximum dpi
		*/
	void SetImageDPI(double maximum,double resampling);

	  /**
		* Sets the output compression mode for monochrome images
		* The default value is e_ccitt (CCITT group 4 compression)
		* @param mode the compression mode to set
		*/
	void SetCompressionMode(enum CompressionMode mode);


	  /**
		* Sets the downsample mode for monochrome images
		* The default value is e_default
		* @param mode the compression mode to set
		*/
	void SetDownsampleMode(enum DownsampleMode mode);


	  /**
		* Sets whether recompression to the specified compression
		* method should be forced when the image is not downsampled.
		* By default the compression method for these images
		* will not be changed.
		* @param force if true the compression method for all
		* images will be changed to the specified compression mode
		*/
	void ForceRecompression(bool force);

	  /**
		* Sets whether image changes that grow the
		* PDF file should be kept.  This is off by default.
		* @param force if true all image changes will be kept.
		*/
	void ForceChanges(bool force);

	  /**
		* Sets the quality for lossy compression modes
		* from 1 to 10 where 10 is lossless (if possible).
		* The default value for JBIG2 is 8.5.  The setting is
		* ignored for FLATE.
		*/
	void SetJBIG2Threshold(double jbig2_threshold);

};

  /**
	* A class that stores image text optimization settings.
	*/
class TextSettings : public TRN_OptimizerTextSettings
{
public:
	/**
	  *	create an TextSettings object with default options
	  */
	TextSettings();

	/**
	 * Sets whether embedded fonts will be subset.  This
	 * will generally reduce the size of fonts, but will
	 * strip font hinting.  Subsetting is off by default.
	 * @param subset if true all embedded fonts will be subsetted.
	 */
	void SubsetFonts(bool subset);

	/**
	 * Sets whether fonts should be embedded.  This
	 * will generally increase the size of the file, but will
	 * make the file appear the same on different machines.  
	 * Font embedding is off by default.
	 * @param embed if true all fonts will be embedded.
	 */
	void EmbedFonts(bool embed);
};

/**
  * A class that stores settings for the optimizer
  */
class OptimizerSettings
{
public:
	/**
	  *	create an OptimizerSettings object with default options
	  */
	OptimizerSettings();

	/**
	  * updates the settings for color image processing
	  */
	void SetColorImageSettings(const ImageSettings& settings);

	/**
	  * updates the settings for grayscale image processing
	  */
	void SetGrayscaleImageSettings(const ImageSettings& settings);
		
	/**
	  * updates the settings for monochrome image processing
	  */
	void SetMonoImageSettings(const MonoImageSettings& settings);
		
	/**
	  * updates the settings for text processing
	  */
	void SetTextSettings(const TextSettings& settings);

	/** 
	  * Enable or disable removal of custom entries in the PDF. By default custom entries are removed.</summary>
	  * @param should_remove if true custom entries will be removed.
	  */
	void RemoveCustomEntries(bool should_remove);

	ImageSettings m_color_image_settings;
	ImageSettings m_grayscale_image_settings;
	MonoImageSettings m_mono_image_settings;
	TextSettings m_text_settings;
	bool m_remove_custom;
};
	

#include <Impl/Optimizer.inl>

	} // namespace PDF
} // namespace pdftron

#endif // PDFTRON_H_CPPPDFOptimizer
