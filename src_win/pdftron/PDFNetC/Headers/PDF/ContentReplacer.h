//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFContentReplacer
#define PDFTRON_H_CPPPDFContentReplacer

#include <PDF/Page.h>
#include <C/PDF/TRN_ContentReplacer.h>

namespace pdftron {
	namespace PDF {
/** 
 * ContentReplacer is a utility class for replacing content (text and images)
 * in existing PDF (template) documents.
 *
 * Users can replace content in a PDF page using the following operations:
 * - Replace an image that exists in a target rectangle with a replacement image. 
 * - Replace text that exists in a target rectangle with replacement text. 
 * - Replace all instances of a specially marked string with replacement string.
 *
 * The following code replaces an image in a target region. This code also 
 * replaces the text "[NAME]" and "[JOB_TITLE]" with "John Smith"
 * and "Software Developer" respectively. Notice the square braces ('[' and ']') on
 * the target strings in the original PDFDoc. These square braces are not included in
 * the actual function calls below, as they're implicitly added.
 *
 * @code
 * PDFDoc doc("../../TestFiles/BusinessCardTemplate.pdf");
 * doc.InitSecurityHandler();
 * ContentReplacer replacer;
 * Page page = doc.GetPage(1);
 * Image img = Image::Create(doc, "../../TestFiles/peppers.jpg");
 * replacer.AddImage(page.GetMediaBox(), img.GetSDFObj());
 * replacer.AddString("NAME", "John Smith");
 * replacer.AddString("JOB_TITLE", "Software Developer");
 * replacer.Process(page);
 * @endcode
 */
class ContentReplacer
{
public:
	/**
	 * Create a new ContentReplacer object, to which replacement rules will be added.
	 * The same object can be used to 'Process' multiple pages.
	 */
	ContentReplacer();
	~ContentReplacer();

	/**
	 * Replace the image that best fits into 'target_region' with 'replacement_image'.
	 *
	 * @param target_region - The rectangle defining the area in which an image
	 * that best fits the rectangle will be replaced by 'replacement_image'.
	 *
	 * @param replacement_image - The 'SDF.Obj' of a 'PDF.Image' object.
	 *
	 * @note The best fit is the image that closest matches 'target_region'. For example if
	 * there are two images on the page, one taking up all of the page, and the other 
	 * smaller, and the smaller one has similar dimensions and position of 
	 * 'target_region', then the smaller image would be replaced, not the larger.
	 * Furthermore, if 'target_region' encloses multiple images, then only the image
	 * with the largest area in 'target_region' will be replaced.
	 */
	void AddImage(const Rect& target_region, SDF::Obj replacement_image);

	/**
	 * All text inside 'target_region' will be deleted and replaced with 'replacement_text'. 
	 *
	 * @param target_region - The rectangle defining the area in which all text will
	 * be replaced by 'replacement_text'.
	 *
	 * @param replacement_text - The new text that will replace the existing text
	 * in 'target_region'.
	 *
	 * @note The 'replacement_text' will be styled in the same font/color/style that is used 
	 * by the original text. If there are multiple font styles, the most prevalent style will
	 * be used. Also, the 'replacement_text' will wrap within the 'target_region', 
	 * but if it is too long, the overflow text will not be visible, and no surrounding
	 * content will be affected.
	 */
	void AddText(const Rect& target_region, const UString& replacement_text);

	/**
	 * Any text of the form "[template_text]" will be replaced by "replacement_text".
	 *
	 * @param template_text - The text to remove.
	 *
	 * @param replacement_text - The new text that will appear in place of 'template_text'.
	 *
	 * @note Only text wrapped in '[' and ']' will be checked, and if it matches 'template_text',
	 * then 'template_text' and the surrounding square braces will be replaced
	 * by 'replacement_text'. For example AddString("TITLE", "Doctor") will replace any
	 * text consisting of "[TITLE]" with "Doctor".
	 */
	void AddString(const UString& template_text, const UString& replacement_text);

	/**
	 * Change the delimiters from '[' and ']' to arbitary strings.
	 *
	 * @param start_str - The starting delimiter string.
	 *
	 * @param end_str - The ending delimiter string.
	 *
	 * @note While empty strings are allowed as delimiters, a warning is displayed. 
	 * Otherwise there are no restrictions.  For example, after SetMatchStrings("<<", ">>"), 
	 * AddString("TITLE", "Doctor") will replace any text consisting of "<<TITLE>>" with
	 * "Doctor".  Similarly, after SetMatchStrings("Beginning...", "...ending."), 
	 * AddString("TITLE", "Doctor") will replace "Beginning...TITLE...ending." with 
	 * "Doctor".
	 */
	void SetMatchStrings(const UString& start_str, const UString& end_str);

	/**
	 * Apply the replacement instructions to the target page. Subsequent calls
	 * to 'Process' can be made on other pages, and it will apply the same rules.
	 *
	 * @param page - The page to apply the content replacement instructions to.
	 */
	void Process(Page& page);

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();

#ifndef SWIGHIDDEN
	TRN_ContentReplacer mp_impl;
#endif
};

	};	// namespace PDF
};	// namespace pdftron

#include <Impl/ContentReplacer.inl>

#endif // PDFTRON_H_CPPPDFContentReplacer
