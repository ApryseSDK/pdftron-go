//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFRedactor
#define PDFTRON_H_CPPPDFRedactor

#include <vector>
#include <PDF/PDFDoc.h>
#include <PDF/Element.h>
#include <C/PDF/TRN_Redactor.h>

namespace pdftron {
	namespace PDF {

class Redaction;
class Appearance;

/**
 * PDF Redactor is a separately licensable Add-on that offers options to remove 
 * (not just covering or obscuring) content within a region of PDF. 
 * With printed pages, redaction involves blacking-out or cutting-out areas of 
 * the printed page. With electronic documents that use formats such as PDF, 
 * redaction typically involves removing sensitive content within documents for 
 * safe distribution to courts, patent and government institutions, the media, 
 * customers, vendors or any other audience with restricted access to the content. 
 *
 * The redaction process in PDFNet consists of two steps:
 * 
 *  a) Content identification: A user applies redact annotations that specify the 
 * pieces or regions of content that should be removed. The content for redaction 
 * can be identified either interactively (e.g. using 'pdftron.PDF.PDFViewCtrl' 
 * as shown in PDFView sample) or programmatically (e.g. using 'pdftron.PDF.TextSearch'
 * or 'pdftron.PDF.TextExtractor'). Up until the next step is performed, the user 
 * can see, move and redefine these annotations.
 *  b) Content removal: Using 'pdftron.PDF.Redactor.Redact()' the user instructs 
 * PDFNet to apply the redact regions, after which the content in the area specified 
 * by the redact annotations is removed. The redaction function includes number of 
 * options to control the style of the redaction overlay (including color, text, 
 * font, border, transparency, etc.).
 * 
 * PDFTron Redactor makes sure that if a portion of an image, text, or vector graphics 
 * is contained in a redaction region, that portion of the image or path data is 
 * destroyed and is not simply hidden with clipping or image masks. PDFNet API can also 
 * be used to review and remove metadata and other content that can exist in a PDF 
 * document, including XML Forms Architecture (XFA) content and Extensible Metadata 
 * Platform (XMP) content.
 */
class Redactor
{
public:
	typedef pdftron::PDF::Redaction Redaction;
	typedef pdftron::PDF::Appearance Appearance;
	/**
	 * Apply the redactions specified in red_array to the PDFDoc doc.
	 *
	 * @param doc - the document to redact
	 * @param red_arr - an array of redaction regions.
	 * @param app - optional parameter used to customize the appearance of the redaction overlay.
	 * @param ext_neg_mode - if true, negative redactions expand beyond the page to remove 
	 * content from other pages in the document. if false, the redaction will be localized
	 * to the given page.
	 * @param page_coord_sys - if true, redaction coordinates are relative to the lower-left corner of the page,
	 * otherwise the redaction coordinates are defined in PDF user coordinate system (which may or may not coincide with 
	 * page coordinates).
	 */
	static void Redact(PDFDoc& doc, const std::vector<Redaction>& red_arr, const Appearance& app, bool ext_neg_mode, bool page_coord_sys);
	static void Redact(PDFDoc& doc, const std::vector<Redaction>& red_arr, const Appearance& app, bool ext_neg_mode);
	static void Redact(PDFDoc& doc, const std::vector<Redaction>& red_arr, const Appearance& app);
	static void Redact(PDFDoc& doc, const std::vector<Redaction>& red_arr);

};



class Redaction
{
public:
	/**
	 * @param page_num - a page number on which to perform the redaction.
	 * @param bbox - the bounding box for the redaction in PDF page coordinate system.
	 * @param negative - if true, remove the content outside of the redaction area,
	 * otherwise remove the content inside the redaction area.
	 * @param text - optional anchor text to be placed in the redaction region.
	 */
	Redaction(int page_num, const Rect& bbox, bool negative, const UString& text);
	~Redaction();

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();

	// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	Redaction();
	Redaction(const Redaction& other);
	Redaction(TRN_Redaction impl);
	TRN_Redaction mp_imp;
#endif
	// @endcond
};

/**
 * Class used to customize the appearance of the optional redaction overlay.
 */
class Appearance
{
public:
	Appearance()
	{
		// Defaults
		RedactionOverlay = true;
		PositiveOverlayColor.Set(1, 1, 1);
		NegativeOverlayColor.Set(1, 1, 1);
		UseOverlayText = true;
		MinFontSize = 2;
		MaxFontSize = 24;
		TextColor.Set(0, 0, 0);
		HorizTextAlignment = -1; // left justified
		VertTextAlignment = 1; // top justified
		Border = true;
		ShowRedactedContentRegions = false;
		RedactedContentColor.Set(0.3, 0.3, 0.3);  // Gray
	}

	/**
	 * If RedactionOverlay is set to true, Redactor will draw an overlay
	 * covering all redacted regions. The rest of properties in the
	 * Appearance class defines visual properties of the overlay.
	 * If false the overlay region will not be drawn.
	 */
	bool RedactionOverlay;

	/**
	 * PositiveOverlayColor defines the overlay background color in RGB color space for positive redactions.
	 */
	ColorPt PositiveOverlayColor;

	/**
	 * NegativeOverlayColor defines the overlay background color in RGB color space for negative redactions.
	 */
	ColorPt NegativeOverlayColor;

	/**
	 * Border specifies if the overlay will be surrounded by a border.
	 */
	bool Border;

	/**
	 * Specifies if the text (e.g. "Redacted" etc.) should be placed on
	 * top of the overlay. The remaining properties relate to the positioning,
	 * and styling of the overlay text.
	 */
	bool UseOverlayText;

	/**
	 * Specifies the font used to represent the text in the overlay.
	 */
	Font TextFont;

	/**
	 * Specifies the minimum and maximum font size used to represent the text in the overlay.
	 */
	double MinFontSize, MaxFontSize;

	/**
	 * Specifies the color used to paint the text in the overlay (in RGB).
	 */
	ColorPt TextColor;

	/**
	 * Specifies the horizontal text alignment in the overlay:
	 *   align<0  -> text will be left aligned.
	 *   align==0 -> text will be center aligned.
	 *   align>0  -> text will be right aligned.
	 */
	int HorizTextAlignment;

	/**
	 * Specifies the vertical text alignment in the overlay:
	 *   align<0  -> text will be top aligned.
	 *   align==0 -> text will be center aligned.
	 *   align>0  -> text will be bottom aligned.
	 */
	int VertTextAlignment;

	/**
	 * Specifies whether an overlay should be drawn in place of the redacted content.
	 * This option can be used to indicate the areas where the content was removed from
	 * without revealing the content itself.
	 * @default Default value is False.
	 * @note The overlay region used RedactedContentColor as a fill color.
	 */
	bool ShowRedactedContentRegions;

	/**
	 * Specifies the color used to paint the regions where content was removed.
	 * Only useful when ShowRedactedContentRegions == true.
	 * @default Default value is Gray color.
	 */
	ColorPt RedactedContentColor;
};
	};	// namespace PDF
};	// namespace pdftron

#include <Impl/Redactor.inl>

#endif // PDFTRON_H_CPPPDFRedactor
