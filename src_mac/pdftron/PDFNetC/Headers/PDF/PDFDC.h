//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#if defined(_WIN32)

#ifndef PDFTRON_H_CPPPDFPDFDC
#define PDFTRON_H_CPPPDFPDFDC

#include <PDF/PDFDoc.h>
#include <C/PDF/TRN_PDFDC.h>
#include <SDF/Obj.h>
#include <Windows.h>

namespace pdftron{ 
	namespace PDF {

/** Note: PDFDC is deprecated. Please use PDFDCEx instead.
* PDFDC is a utility class used to represent a PDF Device Context (DC).
* 
* Windows developers can use standard GDI or GDI+ API-s to write on PDFDC 
* and to generate PDF documents based on their existing drawing functions.
* PDFDC can also be used to implement file conversion from any printable 
* file format to PDF. 
*
* PDFDC class can be used in many ways to translate from GDI to PDF:
*  - To translate a single GDI drawing into a single page PDF document.
*  - To translate a single GDI drawing into an object which can be reused
*    many times throughout a PDF document (i.e. as a Form XObject).
*  - To translate many GDI drawings into single page or multipage PDF document.
*  ...
*
* Very few code changes are required to perform the translation from GDI to 
* PDF as PDFDC provides a GDI Device Context handle which can be passed to 
* all GDI function requiring an HDC.  PDFDC does not use a "Virtual Printer" 
* approach so the translation should be of both high quality and speed.
* Unfortunately this also means that StartDoc, EndDoc, StartPage and EndPage
* cannot be called with an HDC created with PDFDC::Begin.
*
* For more advanced translations or creations of PDF documents, such as security
* handling, the use of other PDFNet classes will be required.
*
* An example use of PDFDC can be found in PDFDCTest.cpp:
*
* @code
* // Start with a PDFDoc to put the picture into, and a PDFDC to translate GDI to PDF
* PDFDoc pdfdoc;
* PDFDC pdfDc;
*
* // Create a page to put the GDI content onto
* Page page = pdfdoc.PageCreate();
*
* // Begin the translation from GDI to PDF.
* // Provide the page to place the picture onto, and the bounding box for the content.
* // We're going to scale the GDI content to fill the page while preserving the aspect
* // ratio.
* // Get back a GDI Device Context
* HDC hDC = pdfDc.Begin( page, page.GetCropBox() );
*
*
* ... perform GDI drawing ...
*
* // Complete the translation
* pdfDc.End();
* 
* // Add the page to the document
* pdfdoc.PagePushBack(page);
*
* // Save the PDF document
* pdfdoc.Save("PDFDC_is_cool.pdf", SDF::SDFDoc::e_remove_unused, NULL);
* @endcode
*/
class PDFDC
{
public:

	/**
	* Default constructor. Creates an empty new GDI to PDF translator.
	*/
	PDFDC ();

	/**
	*	Destructor
	*/
	~PDFDC ();

	/**
	* Begin the process of translating GDI drawing into a PDF, starting with
	* the creation of a GDI Device Context.
	*
	* @param in_page the page which will hold the converted GDI drawing.
	* @param in_bbox the location where the PDF objects will be placed on in_page
	* @param in_preserveAspectRatio if true the aspect ratio of the GDI primitives 
	* will be preserved and the PDF objects will be centered within in_box. 
	* 
	* If you wish to create a reusable FormX Object from the transformed page,
	* create the page with the aspect ratio of the GDI drawing.
	*
	* @return a GDI Handle to Display Context.
	*/
	HDC Begin( Page in_page, const Rect in_bbox, bool in_preserveAspectRatio = true );

	/**
	* Closes the GDI Device Context, translating the GDI instruction to PDF, and adds
	* the PDF objects to the page in the location specified by PDFDC::Begin( page, box, ...).
	*
	* @exception An exception is thrown if there are any fatal errors in the 
	* the translation process.
	*/
	void End();

	/**
	* Sets the conversion scale for translating between GDI drawing and PDF objects.
	*
	* DPI stands for Dots Per Inch. This parameter is used to specify the output
	* image size and quality. A typical screen resolution for monitors these days is 
	* 92 DPI, but printers could use 200 DPI or more. In the case of GDI to PDF
	* translation, this method fixes the scale or allows it to adjust to each 
	* GDI drawing between a Begin/End pair.
	* Set the conversion DPI 
	*
	* @param dpi The resolution used to handle device dependent features in GDI 
	* (such as bitmap patterns, raster ops, etc). Please note that this parameter 
	* does not affect the size the PDF nor does it affect the resolution of 
	* embedded images.
	* 
	* @note The size of resulting image is a function of DPI and the dimensions of 
	* the source PDF page. For example, if DPI is 92 and page is 8 inches tall,  
	* then a GDI graphic object of 92 Device Units will be one inch tall on the PDF
	* page. 
	*
	* @note If you would like to auto-scale the GDI drawing to fill the PDFDC
	* bounding box, then use SetDPI(0).
	*/
	void SetDPI(const TRN_UInt32 dpi = 72);

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
private:
	TRN_PDFDC m_pdfdc;

	PDFDC(const PDFDC&);
	PDFDC& operator= (const PDFDC&);
// @endcond
};

#include <Impl/PDFDC.inl>

	}; // namespace PDF
}; // namespace pdftron

#endif // PDFTRON_H_CPPPDFPDFDC

#endif // defined(_WIN32)
