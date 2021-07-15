//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFFlattener
#define PDFTRON_H_CPPPDFFlattener

#include <Common/Common.h>
#include <PDF/PDFDoc.h>
#include <C/PDF/TRN_Flattener.h>

namespace pdftron {
namespace PDF {

/**
 * Flattener is a optional PDFNet add-on that can be used to simplify and optimize 
 * existing PDF's to render faster on devices with lower memory and speeds.
 * 
 * PDF documents can frequently contain very complex page description (e.g. 
 * thousands of paths, different shadings, color spaces, blend modes, large images 
 * etc.) that may not be suitable for interactive viewing on mobile devices.
 * Flattener can be used to speed-up PDF rendering on mobile devices and on the Web 
 * by simplifying page content (e.g. flattening complex graphics into images) while 
 * maintaining vector text whenever possible.
 *
 * By using the FlattenMode::e_simple option each page in the PDF will be
 * reduced to a single background image, with the remaining text over top in vector
 * format. Some text may still get flattened, in particular any text that is clipped, 
 * or underneath, other content that will be flattened.
 *
 * On the other hand the FlattenMode::e_fast will not flatten simple content, such
 * as simple straight lines, nor will it flatten Type3 fonts.
 * 
 * @note 'Flattener' is available as a separately licensable add-on to PDFNet 
 * core license.
 * 
 * @note See 'pdftron.PDF.Optimizer' for alternate approach to optimize PDFs with 
 * focus on file size reduction.
 */
class Flattener
{
public:
	/**
	 * Flattener constructor
	 */
	Flattener();
	~Flattener();

	/**
	 * The output resolution, from 1 to 1000, in Dots Per Inch (DPI) at which to 
	 * render elements which cannot be directly converted. 
	 * the default value is 150 Dots Per Inch
	 * @param dpi the resolution in Dots Per Inch
	 */
	void SetDPI(UInt32 dpi);

	/**
	 * Specifies the maximum image size in pixels.
	 * @param max_pixels the maximum number of pixels an image can have.
	 */
	void SetMaximumImagePixels(UInt32 max_pixels);

	/**
	 * Specifies whether to leave images in existing compression, or as JPEG.
	 * @param jpg if true PDF will contain all JPEG images.
	 */
	void SetPreferJPG(bool jpg);

	/**
	 * Specifies the compression quality to use when generating JPEG images.
	 * @param quality the JPEG compression quality, from 0(highest compression) to 100(best quality).
	 */
	void SetJPGQuality(UInt32 quality);

    enum Threshold
	{
#ifndef SWIG
		/** Render (flatten) any text that is clipped or occluded. */
		e_very_strict, 
        /** Render text that are marginally clipped or occluded. */
        e_strict,
        /** Render text that are somewhat clipped or occluded. */
        e_default,
        /** Only render text that are seriously clipped or occluded. */
        e_keep_most,
        /** Only render text that are completely occluded, or used as a clipping path. */
        e_keep_all
#else // SWIG
		/** Render (flatten) any text that is clipped or occluded. */
		e_threshold_very_strict, 
        /** Render text that are marginally clipped or occluded. */
        e_threshold_strict,
        /** Render text that are somewhat clipped or occluded. */
        e_threshold_default,
        /** Only render text that are seriously clipped or occluded. */
        e_threshold_keep_most,
        /** Only render text that are completely occluded, or used as a clipping path. */
        e_threshold_keep_all
#endif // SWIG
	};

	enum FlattenMode
	{
		/** 
		 * Feature reduce PDF to a simple two layer representation consisting 
		 * of a single background RGB image and a simple top text layer.
		 */
		e_simple,
		/** 
		 * Feature reduce PDF while trying to preserve some 
		 * complex PDF features (such as vector figures, transparency, shadings, 
		 * blend modes, Type3 fonts etc.) for pages that are already fast to render. 
		 * This option can also result in smaller & faster files compared to e_simple,
		 * but the pages may have more complex structure.
		 */
		e_fast
	};

	/**
	 * Used to control how precise or relaxed text flattening is. When some text is
	 * preserved (not flattened to image) the visual appearance of the document may be altered.
	 * @param threshold the threshold setting to use.
	 */
	void SetThreshold(enum Threshold threshold);

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
	 * Process each page in the PDF, flattening content that matches the mode criteria.
	 * @param doc the document to flatten.
	 * @param mode indicates the criteria for which elements are flattened.
	 */
	void Process(pdftron::PDF::PDFDoc& doc, enum FlattenMode mode );

	/**
	 * Process the given page, flattening content that matches the mode criteria.
	 * @param page the page to flatten.
	 * @param mode indicates the criteria for which elements are flattened.
	 */
	void Process(PDF::Page& page, enum FlattenMode mode );

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

	// @cond PRIVATE_DOC

	#ifndef SWIGHIDDEN
	TRN_Flattener mp_impl;
	#endif

private:
	// ElementBuilder should not be copied
	Flattener(const Flattener&);
	Flattener& operator= (const Flattener&);
	// @endcond

};

#include <Impl/Flattener.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFFlattener
