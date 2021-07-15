//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFConvert
#define PDFTRON_H_CPPPDFConvert

#include <PDF/PDFDoc.h>
#include <PDF/Page.h>
#include <PDF/PDFRasterizer.h>
#include <PDF/DocumentConversion.h>
#include <PDF/WordToPDFOptions.h>
#include <PDF/CADConvertOptions.h>
#include <PDF/AdvancedImagingConvertOptions.h>
#include <PDF/Reflow.h>
#include <C/PDF/TRN_Convert.h>
#include <SDF/Obj.h>
#include <SDF/ObjSet.h>

namespace pdftron{ 
	namespace PDF {

//////////////////////////////////////////////////////////////////////////
// Experimental - Developer use only
class ConversionMonitor
{
public:
    bool Next();
    bool Ready();
    UInt32 Progress();
    Filters::Filter Filter();
    ConversionMonitor();
    void Destroy();
    ~ConversionMonitor();
    ConversionMonitor(const ConversionMonitor& copy);
	ConversionMonitor& operator=(const ConversionMonitor& other);

	 /** 
	  * @return true if the object is not null, false otherwise.  
	  */ 
	operator bool () { return mp_impl!=0;}
#ifndef SWIGHIDDEN
	TRN_ConversionMonitor mp_impl;
    ConversionMonitor(TRN_ConversionMonitor impl, bool is_owner);
    bool m_owner;
#endif
};
//////////////////////////////////////////////////////////////////////////

class XPSOutputOptions;
class XODOutputOptions;
class HTMLOutputOptions;
class WordOutputOptions;
class EPUBOutputOptions;
class SVGOutputOptions;
class TiffOutputOptions;
class Printer;
/** 
 * Converter is a utility class used to convert documents and files to PDF.
 * Conversion of XPS, EMF and image files to PDF documents is performed internally.
 * Other document formats are converted via native application and printing.
 *
 * @code
 * using namespace pdftron;
 * using namespace PDF;
 * PDFDoc pdfdoc;
 *
 * Convert::FromXps(pdfdoc, input_path + "simple-xps.xps" );
 * Convert::FromEmf(pdfdoc, input_path + "simple-emf.emf" );
 * Convert::ToPdf(pdfdoc, input_path + test docx file.docx );
 *
 * // Save the PDF document
 * UString outputFile = output_path + "ConverterTest.pdf";
 * pdfdoc.Save(outputFile, SDF::SDFDoc::e_remove_unused, NULL);
 * @endcode
 *
 * The PDFTron PDFNet printer needs to be installed to convert document formats.
 * On Windows installation of printer drivers requires administrator UAC, manifests
 * have been added to the Convert samples (C++, C# and Visual Basic).
 *
 * To install the printer the process must be running as administrator.  Execute:
 *
 * @code
 * Convert::Printer::Install();
 * @endcode
 *
 * Installation can take a few seconds, so it is recommended that you install the printer 
 * once as part of your deployment process.  Duplicated installations will be quick since
 * the presence of the printer is checked before installation is attempted.  The printer
 * is a virtual XPS printer supported on Vista and Windows 7, and on Windows XP with the 
 * XPS Essentials Pack.
 *
 * There is no need to uninstall the printer after conversions, it can be left installed 
 * for later access. To uninstall the printer the process must be running as administrator.
 * Execute:
 *
 * @code
 * Convert::Printer::Uninstall();
 * @endcode
 */

class Convert
{
public:
	typedef pdftron::PDF::XPSOutputOptions XPSOutputOptions;
	typedef pdftron::PDF::XODOutputOptions XODOutputOptions;
	typedef pdftron::PDF::HTMLOutputOptions HTMLOutputOptions;
	typedef pdftron::PDF::WordOutputOptions WordOutputOptions;
	typedef pdftron::PDF::EPUBOutputOptions EPUBOutputOptions;
	typedef pdftron::PDF::SVGOutputOptions SVGOutputOptions;
	typedef pdftron::PDF::TiffOutputOptions TiffOutputOptions;
	typedef pdftron::PDF::Printer Printer;

	enum FlattenThresholdFlag {
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
	};

	enum FlattenFlag {
		/**
		 * Disable flattening and convert all content as is.
		 */
		e_off,
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
		e_fast,

		/**
		* Preserve vector content where possible. In particular only feature reduce
		* PDF files containing overprint or very complex vector content. Currently this
		* option can only be used with XODOutputOptions.
		*/
		e_high_quality
	};

	/**
	 * Convert the specified XPS document to PDF and append converted pages
	 * to the specified PDF document.
	 *
	 * @param in_pdfdoc the PDFDoc to append to
	 *
	 * @param in_filename the path to the XPS document to convert
	 *
	 */
	static void FromXps(PDFDoc & in_pdfdoc, const UString & in_filename);

	/**
	 * Convert the specified XPS document contained in memory to PDF 
	 * and append converted pages to the specified PDF document.
	 *
	 * @param in_pdfdoc the PDFDoc to append to
	 *
	 * @param buf the buffer containing the xps document
	 *
	 * @param buf_sz the size of the buffer
	 *
	 */
	static void FromXps(PDFDoc & in_pdfdoc, const char* buf, size_t buf_sz);

	/**
	 * Convert the specified EMF to PDF and append converted pages to
	 * to the specified PDF document.  EMF will be fitted to the page.
	 *
	 * @param in_pdfdoc the PDFDoc to append to
	 *
	 * @param in_filename the path to the EMF document to convert
	 *
	 * @note This method is available only on Windows platforms.
	 */
	static void FromEmf(PDFDoc & in_pdfdoc, const UString & in_filename);

	/**
	* Convert the specified plain text file to PDF and append converted 
	* pages to the specified PDF document.  
	*
	* @param in_pdfdoc the PDFDoc to append to
	*
	* @param in_filename the path to the plain text document to convert
	*
	* @param in_options the conversion options. The available options are:
	*
	*| Option Name             | Type    | Note                                                    |
	*|-------------------------|---------|---------------------------------------------------------|
	*| BytesPerBite            | Integer | In bytes. Use for streaming conversion only.            |
	*| FontFace                | String  | Set the font face used for the conversion.              |
	*| FontSize                | Integer | Set the font size used for the conversion.              |
	*| LineHeightMultiplier    | Double  | Set the line height multiplier used for the conversion. |
	*| MarginBottom            | Double  | In inches. Set the bottom margin of the page.           |
	*| MarginLeft              | Double  | In inches. Set the left margin of the page.             |
	*| MarginRight             | Double  | In inches. Set the right margin of the page.            |
	*| MarginTop               | Double  | In inches. Set the top margin of the page.              |
	*| PageHeight              | Double  | In inches. Set the page height.                         |
	*| PageWidth               | Double  | In inches. Set the page width.                          |
	*| UseSourceCodeFormatting | Boolean | Set whether to use mono font for the conversion.        |
	*/
	static void FromText(PDFDoc & in_pdfdoc, const UString& in_filename, const SDF::Obj& in_options = SDF::Obj());

	/**
	 * Convert the PDFDoc to EMF and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to EMF
	 *
	 * @param in_filename the path to the EMF files to create, one file per page
	 *
	 * @note This method is available only on Windows platforms.
	 */
	static void ToEmf(PDFDoc & in_pdfdoc, const UString & in_filename);

	/**
	 * Convert the Page to EMF and save to the specified path
	 *
	 * @param in_page the Page to convert to EMF
	 *
	 * @param in_filename the path to the EMF file to create
	 *
	 * @note This method is available only on Windows platforms.
	 */
	static void ToEmf(Page & in_page, const UString & in_filename);

	
	/**
	 * Convert the PDFDoc to SVG and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to SVG
	 *
	 * @param in_filename the path to the SVG files to create, one file per page
	 *
	 * @param in_options the conversion options
	 */
	static void ToSvg(PDFDoc & in_pdfdoc, const UString & in_filename, const SVGOutputOptions& in_options);

	/**
	 * Convert the PDFDoc to SVG and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to SVG
	 *
	 * @param in_filename the path to the SVG files to create, one file per page
	 */
	static void ToSvg(PDFDoc & in_pdfdoc, const UString & in_filename);

	/**
	 * Convert the Page to SVG and save to the specified path
	 *
	 * @param in_page the Page to convert to SVG
	 *
	 * @param in_filename the path to the SVG file to create
	 *
	 * @param in_options the conversion options
	 */
	static void ToSvg(Page & in_page, const UString & in_filename, const SVGOutputOptions& in_options);
	
	/**
	 * Convert the Page to SVG and save to the specified path
	 *
	 * @param in_page the Page to convert to SVG
	 *
	 * @param in_filename the path to the SVG file to create
	 */
	static void ToSvg(Page & in_page, const UString & in_filename);
	   	  
	/**
	 * Convert the PDFDoc to XPS and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to XPS
	 *
	 * @param in_filename the path to the document to create
	 *
	 * @param options the conversion options
	 *
	 * @see XPSOutputOptions
	 *
	 */
	static void ToXps(PDFDoc & in_pdfdoc, const UString & in_filename, const XPSOutputOptions& options);

	/**
	 * Convert the PDFDoc to XPS and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to XPS
	 *
	 * @param in_filename the path to the document to create
	 *
	 */
	static void ToXps(PDFDoc & in_pdfdoc, const UString & in_filename);

	/**
	 * Convert the input file to XPS format and save to the specified path
	 *
	 * @param in_inputFilename the file to convert to XPS
	 *
	 * @param in_outputFilename the path to the XPS file to create
	 * 
	 * @param options the conversion options
	 *
	 * @see XPSOutputOptions
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static void ToXps(const UString & in_inputFilename, const UString & in_outputFilename, const XPSOutputOptions& options);

	/**
	 * Convert the input file to XPS format and save to the specified path
	 *
	 * @param in_inputFilename the file to convert to XPS
	 *
	 * @param in_outputFilename the path to the XPS file to create
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static void ToXps(const UString & in_inputFilename, const UString & in_outputFilename);

	/**
	 * Convert the input file to XOD format and save to the specified path
	 *
	 * @param in_filename the file to convert to XOD
	 *
	 * @param out_filename the path to the XOD file to create
	 *
	 * @param options the conversion options 
	 *
	 * @see XODOutputOptions
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static void ToXod(const UString & in_filename, const UString & out_filename, const XODOutputOptions& options);

	/**
	 * Convert the input file to XOD format and save to the specified path
	 *
	 * @param in_filename the file to convert to XOD
	 *
	 * @param out_filename the path to the XOD file to create
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static void ToXod(const UString & in_filename, const UString & out_filename);

	/**
	 * Convert the input file to XOD format and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to XOD
	 *
	 * @param out_filename the path to the XOD file to create
	 *
	 * @param options the conversion options 
	 *
	 * @see XODOutputOptions
	 *
	 * @see ToPdf()
	 *
	 */
	static void ToXod(PDFDoc & in_pdfdoc, const UString & out_filename, const XODOutputOptions& options);

	/**
	 * Convert the input file to XOD format and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to XOD
	 *
	 * @param out_filename the path to the XOD file to create
	 *
	 * @see ToPdf()
	 *
	 */
	static void ToXod(PDFDoc & in_pdfdoc, const UString & out_filename);

	/**
	 * Convert a file to HTML and save to the specified path.
	 * In e_reflow_paragraphs mode, this conversion requires that the optional PDFTron
	 * pdf2html add-on module is available.
	 *
	 * @param in_filename the file to convert to HTML
	 *
	 * @param out_path the path to where generated content will be stored 
	 *
	 * @param options the conversion options 
	 *
	 * @see HTMLOutputOptions
	 *
	 * @see ToPdf()
	 *
	 * @see PDF2HtmlReflowParagraphsModule
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 *
	 */
	static void ToHtml(const UString & in_filename, const UString & out_path, const HTMLOutputOptions& options);

	/**
	 * Convert a file to HTML and save to the specified path
	 *
	 * @param in_filename the file to convert to HTML
	 *
	 * @param out_path the path to where generated content will be stored
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 *
	 */
	static void ToHtml(const UString & in_filename, const UString & out_path);


	/**
	 * Convert a page to HTML and return a string of the html
	 *
	 * @param page the page to convert to HTML
	 *
	 * @return a string containing the page's html  
	 *
	 */
	static UString PageToHtml(const Page & page);
	/**
	 * Convert a page to HTML and return a string of the html
	 *
	 * @param page the page to convert to HTML
	 *
	 * @param json_zones
	 *
	 * @return a string containing the page's html  
	 *
	 */
	static UString PageToHtmlZoned(const Page & page, const UString & json_zones);

	/**
	 * Convert the PDF to HTML and save to the specified path.
	 * In e_reflow_paragraphs mode, this conversion requires that the optional PDFTron
	 * pdf2html add-on module is available.
	 *
	 * @param in_pdfdoc the PDF doc to convert to HTML
	 *
	 * @param out_path the path to where generated content will be stored 
	 *
	 * @param options the conversion options 
	 *
	 * @see HTMLOutputOptions
	 *
	 * @see ToPdf()
	 *
	 * @see PDF2HtmlReflowParagraphsModule
	 *
	 */
	static void ToHtml(PDFDoc & in_pdfdoc, const UString & out_path, const HTMLOutputOptions& options);

	/**
	 * Convert the PDF to HTML and save to the specified path
	 *
	 * @param in_pdfdoc the PDF doc to convert to HTML
	 *
	 * @param out_path the path to where generated content will be stored
	 *
	 * @see ToPdf()
	 *
	 */
	static void ToHtml(PDFDoc & in_pdfdoc, const UString & out_path);

	/**
	 * Convert a PDF file to Word and save the output to the specified path.
	 * This conversion requires that the optional PDFTron pdf2word add-on module is available.
	 *
	 * @param inputFilename the PDF file to convert to Word
	 *
	 * @param outputPath the path to where generated content will be stored 
	 *
	 * @param options the conversion options 
	 *
	 * @see WordOutputOptions
	 *
	 * @see PDF2WordModule
	 *
	 */
	static void ToWord(const UString & inputFilename, const UString & outputPath, const WordOutputOptions& options);

	/**
	 * Convert a PDF file to Word and save the output to the specified path.
	 * This conversion requires that the optional PDFTron pdf2word add-on module is available.
	 *
	 * @param inputFilename the PDF file to convert to Word
	 *
	 * @param outputPath the path to where generated content will be stored 
	 *
	 * @see PDF2WordModule
	 *
	 */
	static void ToWord(const UString & inputFilename, const UString & outputPath);

	/**
	 * Convert PDF to Word and save the output to the specified path.
	 * This conversion requires that the optional PDFTron pdf2word add-on module is available.
	 *
	 * @param pdfdoc the PDF doc to convert to Word
	 *
	 * @param outputPath the path to where generated content will be stored 
	 *
	 * @param options the conversion options 
	 *
	 * @see WordOutputOptions
	 *
	 * @see PDF2WordModule
	 *
	 * @see ToPdf()
	 *
	 */
	static void ToWord(PDFDoc & pdfdoc, const UString & outputPath, const WordOutputOptions& options);

	/**
	 * Convert PDF to Word and save the output to the specified path.
	 * This conversion requires that the optional PDFTron pdf2word add-on module is available.
	 *
	 * @param pdfdoc the PDF doc to convert to Word
	 *
	 * @param outputPath the path to where generated content will be stored 
	 *
	 * @see PDF2WordModule
	 *
	 * @see ToPdf()
	 *
	 */
	static void ToWord(PDFDoc & pdfdoc, const UString & outputPath);

	/**
	 * Convert a file to EPUB format and save to the specified path
	 *
	 * @param in_filename the file to convert to EPUB
	 *
	 * @param out_path the path to the EPUB file to create
	 *
	 * @param html_options the conversion options 
	 *
	 * @param epub_options the conversion options
	 *
	 * @see HTMLOutputOptions
	 *
	 * @see EPUBOutputOptions
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static void ToEpub(const UString & in_filename, const UString & out_path, const HTMLOutputOptions& html_options, const EPUBOutputOptions& epub_options);

	/**
	 * Convert a file to EPUB format and save to the specified path
	 *
	 * @param in_filename the file to convert to EPUB
	 *
	 * @param out_path the path to the EPUB file to create
	 *
	 * @param html_options the conversion options
	 *
	 * @see HTMLOutputOptions
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static void ToEpub(const UString & in_filename, const UString & out_path, const HTMLOutputOptions& html_options);

	/**
	 * Convert a file to EPUB format and save to the specified path
	 *
	 * @param in_filename the file to convert to EPUB
	 *
	 * @param out_path the path to the EPUB file to create
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static void ToEpub(const UString & in_filename, const UString & out_path);

	/**
	 * Convert the PDFDoc to EPUB format and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to EPUB
	 *
	 * @param out_path the path to the EPUB file to create
	 *
	 * @param html_options the conversion options 
	 *
	 * @param epub_options the conversion options
	 *
	 * @see HTMLOutputOptions
	 *
	 * @see EPUBOutputOptions
	 *
	 * @see ToPdf()
	 *
	 */
	static void ToEpub(PDFDoc & in_pdfdoc, const UString & out_path, const HTMLOutputOptions& html_options, const EPUBOutputOptions& epub_options);

	/**
	 * Convert the PDFDoc to EPUB format and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to EPUB
	 *
	 * @param out_path the path to the EPUB file to create
	 *
	 * @param html_options the conversion options
	 *
	 * @see HTMLOutputOptions
	 *
	 * @see ToPdf()
	 *
	 */
	static void ToEpub(PDFDoc & in_pdfdoc, const UString & out_path, const HTMLOutputOptions& html_options);

	/**
	 * Convert the PDFDoc to EPUB format and save to the specified path
	 *
	 * @param in_pdfdoc the PDFDoc to convert to EPUB
	 *
	 * @param out_path the path to the EPUB file to create
	 *
	 * @see ToPdf()
	 *
	 */
	static void ToEpub(PDFDoc & in_pdfdoc, const UString & out_path);

	/**
	 * Convert a file to multipage TIFF and save to the specified path
	 *
	 * @param in_filename the file to convert to multipage TIFF
	 *
	 * @param out_path the path to the TIFF file to create
	 *
	 * @param options the conversion options 
	 *
	 * @see TiffOutputOptions
	 *
	 */
	static void ToTiff(const UString & in_filename, const UString & out_path, const TiffOutputOptions& options);

	/**
	 * Convert a file to multipage TIFF and save to the specified path
	 *
	 * @param in_filename the file to convert to multipage TIFF
	 *
	 * @param out_path the path to the TIFF file to create
	 *
	 */
	static void ToTiff(const UString & in_filename, const UString & out_path);

	/**
	 * Convert the PDF to multipage TIFF and save to the specified path
	 *
	 * @param in_pdfdoc the PDF doc to convert to multipage TIFF
	 *
	 * @param out_path the path to the TIFF file to create
	 *
	 * @param options the conversion options 
	 *
	 * @see TiffOutputOptions
	 *
	 */
	static void ToTiff(PDFDoc & in_pdfdoc, const UString & out_path, const TiffOutputOptions& options);

	/**
	 * Convert the PDF to multipage TIFF and save to the specified path
	 *
	 * @param in_pdfdoc the PDF doc to convert to multipage TIFF
	 *
	 * @param out_path the path to the TIFF file to create
	 *
	 */
	static void ToTiff(PDFDoc & in_pdfdoc, const UString & out_path);

	/**
	 * Generate a stream that incrementally converts the input file to XOD format.
	 *
	 * @param in_filename the file to convert to XOD
	 *
	 * @param options the conversion options 
	 *
	 * @return A filter from which the file can be read incrementally.
	 *
	 * @see XODOutputOptions
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static Filters::Filter ToXod(const UString & in_filename, const XODOutputOptions& options);

	/**
	 * Generate a stream that incrementally converts the input file to XOD format.
	 *
	 * @param in_filename the file to convert to XOD
	 *
	 * @return A filter from which the file can be read incrementally.
	 *
	 * @see ToPdf()
	 *
	 * @note Requires the Convert::Printer class for all file formats
	 * that ToPdf also requires.
	 */
	static Filters::Filter ToXod(const UString & in_filename);

	/**
	 * Generate a stream that incrementally converts the input file to XOD format.
	 *
	 * @param in_pdfdoc the PDFDoc to convert to XOD
	 *
	 * @param options the conversion options 
	 *
	 * @return A filter from which the file can be read incrementally.
	 *
	 * @see XODOutputOptions
	 *
	 * @see ToPdf()
	 *
	 */
	static Filters::Filter ToXod(PDFDoc & in_pdfdoc, const XODOutputOptions& options);

	/**
	 * Generate a stream that incrementally converts the input file to XOD format.
	 *
	 * @param in_pdfdoc the PDFDoc to convert to XOD
	 *
	 * @return A filter from which the file can be read incrementally.
	 *
	 * @see ToPdf()
	 *
	 */
	static Filters::Filter ToXod(PDFDoc & in_pdfdoc);
	//////////////////////////////////////////////////////////////////////////
	// Experimental - Developer use only
	static ConversionMonitor ToXodWithMonitor(PDFDoc & in_pdfdoc, const XODOutputOptions& options);
	static ConversionMonitor ToXodWithMonitor(PDFDoc & in_pdfdoc);


	/**
	 * Convert the a Word document (in .docx format) to pdf and append to the specified PDF document.
	 * This conversion is performed entirely within PDFNet, and does not rely on Word
	 * interop or any other external functionality.
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_pdfdoc the conversion result will be appended to this pdf.
	 *
	 * @param in_filename the path to the source document. The source must be in .docx format.
	 *
	 * @param options the conversion options 
	 *
	 * @throws PDFNetException 
	 *
	 * @see WordToPDFOptions
	 *
	 * @see WordToPdfConversion() if you would like more control over the conversion process
	 *
	 */
	static void WordToPDF( PDFDoc & in_pdfdoc, const UString & in_filename, WordToPDFOptions* options);

	/**
	 * Create a DocumentConversion object suitable for converting a Word document (in .docx format)
	 * to pdf and appending to the specified PDF document.
	 * This conversion will be performed entirely within PDFNet, and does not rely on Word
	 * interop or any other external functionality.
	 * 
	 * This method allows for more control over the conversion process than the single call
	 * WordToPDF() interface. This method does not perform any  conversion logic and can be expected
	 * to return quickly. To do the actual conversion, use the returned DocumentConversion object. 
	 * 
	 * @see DocumentConversion
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_pdfdoc the conversion result will be appended to this pdf.
	 *
	 * @param in_filename the path to the source document. The source must be in .docx format.
	 *
	 * @param options the conversion options 
	 *
	 * @return A DocumentConversion object which encapsulates this particular conversion.
	 *
	 * @see WordToPDFOptions
	 *
	 */
	static DocumentConversion WordToPDFConversion( PDFDoc & in_pdfdoc, const UString & in_filename, WordToPDFOptions* options);

	    /**
	 * Convert the a Word document (in .docx format) to pdf and append to the specified PDF document.
	 * This conversion is performed entirely within PDFNet, and does not rely on Word
	 * interop or any other external functionality.
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_pdfdoc the conversion result will be appended to this pdf.
	 *
	 * @param in_stream the source document data. The source must be in .docx format.
	 *
	 * @param options the conversion options 
	 *
	 * @throws PDFNetException 
	 *
	 * @see WordToPDFOptions
	 *
	 * @see WordToPdfConversion() if you would like more control over the conversion process
	 *
	 */
	static void WordToPDF( PDFDoc & in_pdfdoc, Filters::Filter in_stream, WordToPDFOptions* options);

	/**
	 * Create a DocumentConversion object suitable for converting a Word document (in .docx format)
	 * to pdf and appending to the specified PDF document.
	 * This conversion will be performed entirely within PDFNet, and does not rely on Word
	 * interop or any other external functionality.
	 * 
	 * This method allows for more control over the conversion process than the single call
	 * WordToPDF() interface. This method does not perform any  conversion logic and can be expected
	 * to return quickly. To do the actual conversion, use the returned DocumentConversion object. 
	 * 
	 * @see DocumentConversion
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_pdfdoc the conversion result will be appended to this pdf.
	 *
	 * @param in_stream the source document data. The source must be in .docx format.
	 *
	 * @param options the conversion options 
	 *
	 * @return A DocumentConversion object which encapsulates this particular conversion.
	 *
	 * @see WordToPDFOptions
	 *
	 */
	static DocumentConversion WordToPDFConversion( PDFDoc & in_pdfdoc, Filters::Filter in_stream, WordToPDFOptions* options);
	
	/**
	 * Convert the an office document (in .docx, .xlsx, pptx, or .doc format) to pdf and append to the specified PDF document.
	 * This conversion is performed entirely within PDFNet, and does not rely on Word
	 * interop or any other external functionality.
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_pdfdoc the conversion result will be appended to this pdf.
	 *
	 * @param in_filename the path to the source document.
	 *
	 * @param options the conversion options 
	 *
	 * @throws PDFNetException 
	 *
	 * @see ConversionOptions
	 *
	 * @see StreamingPDFConversion() if you would like more control over the conversion process
	 *
	 */
	static void OfficeToPDF( PDFDoc & in_pdfdoc, const UString & in_filename, ConversionOptions* options);

	/**
	 * Create a DocumentConversion object suitable for converting a file to pdf and appending to the specified PDF document.
	 * Handles incoming files in .docx, .xlsx, pptx, .doc, .png, .jpg, .bmp, .gif, .jp2, .tif, .txt, .xml and .md format
	 * This conversion will be performed entirely within PDFNet, and does not rely on any external functionality.
	 * 
	 * This method allows for more control over the conversion process than the single call
	 * ToPDF() interface. It does not perform any  conversion logic immediately, and can be expected
	 * to return quickly. To perform the actual conversion, use the returned DocumentConversion object.
	 * 
	 * @see DocumentConversion
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_pdfdoc the conversion result will be appended to this pdf.
	 *
	 * @param in_filename the path to the source document.
	 *
	 * @param options the conversion options 
	 *
	 * @return A DocumentConversion object which encapsulates this particular conversion.
	 *
	 * @see ConversionOptions
	 *
	 */
	static DocumentConversion StreamingPDFConversion( PDFDoc & in_pdfdoc, const UString & in_filename, ConversionOptions* options);
	
	/**
	 * Create a DocumentConversion object suitable for converting a file to pdf.
	 * Handles incoming files in .docx, .xlsx, pptx, .doc, .png, .jpg, .bmp, .gif, .jp2, .tif, .txt, .xml and .md format
	 * This conversion will be performed entirely within PDFNet, and does not rely on any external functionality.
	 * 
	 * This method allows for more control over the conversion process than the single call
	 * ToPDF() interface. It does not perform any  conversion logic immediately, and can be expected
	 * to return quickly. To perform the actual conversion, use the returned DocumentConversion object. 
	 * 
	 * @see DocumentConversion
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_filename the path to the source document.
	 *
	 * @param options the conversion options 
	 *
	 * @return A DocumentConversion object which encapsulates this particular conversion.
	 *
	 * @see ConversionOptions
	 *
	 */
	static DocumentConversion StreamingPDFConversion(const UString & in_filename, ConversionOptions* options);

	static Reflow CreateReflow(Page & in_page, const UString & json_zones);

	/**
	 * Convert the an office document (in .docx, .xlsx, pptx, or .doc format) to pdf and append to the specified PDF document.
	 * This conversion is performed entirely within PDFNet, and does not rely on Word
	 * interop or any other external functionality.
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_pdfdoc the conversion result will be appended to this pdf.
	 *
	 * @param in_stream the source document data.
	 *
	 * @param options the conversion options 
	 *
	 * @throws PDFNetException 
	 *
	 * @see ConversionOptions
	 *
	 * @see StreamingPDFConversion() if you would like more control over the conversion process
	 *
	 */
	static void OfficeToPDF( PDFDoc & in_pdfdoc, Filters::Filter in_stream, ConversionOptions* options);

	/**
	 * Create a DocumentConversion object suitable for converting an office document (in .docx, .xlsx, pptx, or .doc format)
	 * to pdf and appending to the specified PDF document.
	 * This conversion will be performed entirely within PDFNet, and does not rely on Word
	 * interop or any other external functionality.
	 * 
	 * This method does not perform any  conversion logic and can be expected
	 * to return quickly. To do the actual conversion, use the returned DocumentConversion object. 
	 * 
	 * @see DocumentConversion
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_pdfdoc the conversion result will be appended to this pdf.
	 *
	 * @param in_stream the source document data.
	 *
	 * @param options the conversion options 
	 *
	 * @return A DocumentConversion object which encapsulates this particular conversion.
	 *
	 * @see ConversionOptions
	 *
	 */
	static DocumentConversion StreamingPDFConversion( PDFDoc & in_pdfdoc, Filters::Filter in_stream, ConversionOptions* options);
	
	/**
	 * Create a DocumentConversion object suitable for converting an office document (in .docx, .xlsx, pptx, or .doc format)
	 * to pdf and appending to the specified PDF document.
	 * This conversion will be performed entirely within PDFNet, and does not rely on Word
	 * interop or any other external functionality.
	 * 
	 * This method does not perform any  conversion logic and can be expected
	 * to return quickly. To do the actual conversion, use the returned DocumentConversion object. 
	 * 
	 * @see DocumentConversion
	 *
	 * @note Font requirements: on some systems you may need to specify extra font resources to aid
	 * in conversion. Please see http://www.pdftron.com/kb_fonts_and_builtin_office_conversion
	 *
	 * @param in_stream the source document data.
	 *
	 * @param options the conversion options 
	 *
	 * @return A DocumentConversion object which encapsulates this particular conversion.
	 *
	 * @see ConversionOptions
	 *
	 */
	static DocumentConversion StreamingPDFConversion(Filters::Filter in_stream, ConversionOptions* options);

	/** 
	 * Convert the file or document to PDF and append to the specified PDF document
	 *
	 * @param in_pdfdoc the PDFDoc to append the converted document to. The
	 * PDFDoc can then be converted to XPS, EMF or SVG using the other functions
	 * in this class.
	 *
	 * @param in_filename the path to the document to be converted to pdf
	 *
	 * @note Internally formats include BMP, EMF, JPEG, PNG, TIF, XPS.
	 *
	 * @note Formats that require external applications for conversion use the
	 * Convert::Printer class and the PDFNet printer to be installed. This is 
	 * only supported on Windows platforms.  Document formats in this category 
	 * include RTF(MS Word or Wordpad), TXT (Notepad or Wordpad), DOC and DOCX 
	 * (MS Word), PPT and PPTX (MS PowerPoint), XLS and XLSX (MS Excel), 
	 * OpenOffice documents, HTML and MHT (Internet Explorer), PUB (MS Publisher),
	 * MSG (MS Outlook).
	 */
	static void ToPdf(PDFDoc & in_pdfdoc, const UString & in_filename);

	/**
	 * Convert the specified CAD file to PDF and append converted pages to the specified PDF document.
	 * This conversion requires that the optional PDFTron CAD add-on module is available.
	 * See the `CADConvertOptions` class for the available options.
	 * See also: the 'CADModule' class
	 *
	 * @param in_pdfdoc the PDFDoc to append to
	 * @param in_filename the path to the CAD document to convert
	 * @param opts The options to use when converting.
	*/
	static void FromCAD(PDFDoc& in_pdfdoc, const UString& in_filename, CADConvertOptions* opts = 0);
	
	/**
	 * Convert the specified AdvancedImaging file to PDF and append converted pages to the specified PDF document.
	 * This conversion requires that the optional PDFTron AdvancedImaging add-on module is available.
	 * See also: the 'AdvancedImagingModule' class
	 *
	 * @param in_pdfdoc the PDFDoc to append to
	 * @param in_filename the path to the CAD document to convert
	 * @param opts The options to use when converting.
	*/

	static void FromDICOM(PDFDoc& in_pdfdoc, const UString& in_filename, AdvancedImagingConvertOptions* opts = 0);

	/**
	 * Convert the specified TIFF filter to PDF and append converted pages to the specified PDF document.
	 *
	 * @param in_pdfdoc the PDFDoc to append to
	 * @param in_data the source TIFF data.
	*/
	static void FromTiff(PDFDoc& in_pdfdoc, Filters::Filter in_data);

	/**
	 * Utility function to determine if ToPdf or ToXps will require the PDFNet
	 * printer to convert a specific external file to PDF.
	 *
	 * @param in_filename the path to the document to be checked
	 *
	 * @return true if ToPdf requires the printer to convert the file, false 
	 * otherwise.
	 *
	 * @note Current implementation looks only at the file extension not
	 * file contents. If the file extension is missing, false will be returned
	 */
	static bool RequiresPrinter(const UString & in_filename);

	
private:
	Convert ();
	~Convert ();
};

/**
 * A class containing options common to ToXps and ToXod functions
 */
class XPSOutputCommonOptions
{
public:
	/**
	 * Creates an XPSConvertOptions object with default settings
	 */
	XPSOutputCommonOptions();
	/**
	 * Sets whether ToXps should be run in print mode. Default is false.
	 * @param print_mode if true print mode is enabled
	 */
	void SetPrintMode(bool print_mode);

	/**
	 * The output resolution, from 1 to 1000, in Dots Per Inch (DPI) at which to render elements which cannot be directly converted. Default is 140.
	 * @param dpi the resolution in Dots Per Inch
	 */
	void SetDPI(UInt32 dpi);

	/**
	 * Sets whether rendering of pages should be permitted when necessary to guarantee output. Default is true.
	 * @param render if false rendering is not permitted under any circumstance
	 */
	void SetRenderPages(bool render);

	/**
	 * Sets whether thin lines should be thickened. Default is true for XPS and false for XOD.
	 * @param thicken if true then thin lines will be thickened
	 */
	void SetThickenLines(bool thicken);

	/**
	 * Sets whether links should be generated from urls
	 * found in the document. Default is false.
	 * @param generate if true links will be generated from urls
	 */
	void GenerateURLLinks(bool generate);

	enum OverprintPreviewMode
	{
		e_op_off = 0,
		e_op_on,
		e_op_pdfx_on
	};

	/**
	 * Enable or disable support for overprint and overprint simulation.
	 * Overprint is a device dependent feature and the results will vary depending on
	 * the output color space and supported colorants (i.e. CMYK, CMYK+spot, RGB, etc).
	 * Default is e_op_pdfx_on.
	 *
	 * @param mode e_op_on: always enabled; e_op_off: always disabled; e_op_pdfx_on: enabled for PDF/X files only.
	 */
	void SetOverprint(enum OverprintPreviewMode mode);

	TRN_Obj m_obj;
protected:
	friend class Convert;
	SDF::ObjSet m_objset;
};

/**
 * A class containing options for ToXps functions
 */
class XPSOutputOptions : public XPSOutputCommonOptions
{
public:
	/**
	 * Sets whether the output format should be open xps. Default is Microsoft xps output.
	 * @param openxps if true open xps output is used
	 */
	void SetOpenXps(bool openxps);
};

/**
 * A class containing options for ToXod functions
 */
class XODOutputOptions : public XPSOutputCommonOptions
{
public:

	enum AnnotationOutputFlag {
		e_internal_xfdf,				// include the annotation file in the XOD output. This is the default option
		e_external_xfdf,				// output the annotation file externally to the same output path with extension .xfdf. 
										// This is not available when using streaming conversion
		e_flatten                       // flatten all annotations that are not link annotations
	};

	/**
	 * Sets whether per page thumbnails should be included in the file. Default is true.
	 * @param include_thumbs if true thumbnails will be included
	 */
	void SetOutputThumbnails(bool include_thumbs);

	/**
	 * The width and height of a square in which thumbnails will
	 * be contained. Default is 400 for normal pages and 1500 for large pages.
	 * @note A large page is a page larger than twice the area of the standard page size (8.5 X 11).
	 * @param size the maximum dimension (width or height) that thumbnails will have.
	 */
	void SetThumbnailSize(UInt32 size);

	/**
	 * The width and height of squares in which thumbnails will
	 * be contained. Default is 400 for normal pages and 1500 for large pages.
	 * @note A large page is a page larger than twice the area of the standard page size (8.5 X 11).
	 * @param regular_size the maximum dimension that thumbnails for regular size pages will have.
	 * @param large_size the maximum dimension that thumbnails for large pages will have.
	 */
	void SetThumbnailSize(UInt32 regular_size, UInt32 large_size);

	/**
	 * If rendering is permitted, sets the maximum number of page elements before that page will be rendered.
	 * Default is 2000000000 which will never cause pages to be completely rendered in this manner.
	 * @param element_limit the maximum number of elements before a given page will be rendered
	 */
	void SetElementLimit(UInt32 element_limit);

	/**
	 * If rendering is permitted, sets whether pages containing opacity masks should be rendered.
	 * This option is used as a workaround to a bug in Silverlight where opacity masks are transformed incorrectly.
	 * Default is false.
	 * @param opacity_render if true pages with opacity masks will be rendered
	 */
	void SetOpacityMaskWorkaround(bool opacity_render);

	/**
	 * Specifies the maximum image slice size in pixels. Default is 2000000.
	 * @note This setting now will no longer reduce the total number of image pixels.
	 * Instead a lower value will just produce more slices and vice versa.
	 * @note Since image compression works better with more pixels a larger
	 * max pixels should generally create smaller files.
	 * @param max_pixels the maximum number of pixels an image can have
	 */
	void SetMaximumImagePixels(UInt32 max_pixels);

	/**
	 * Flatten images and paths into a single background image overlaid with
	 * vector text. This option can be used to improve speed on devices with
	 * little processing power such as iPads. Default is e_high_quality.
	 * @param flatten select which flattening mode to use.
	 */
	void SetFlattenContent(enum Convert::FlattenFlag flatten);

	/**
	 * Used to control how precise or relaxed text flattening is. When some text is
	 * preserved (not flattened to image) the visual appearance of the document may be altered.
	 * @param threshold the threshold setting to use.
	 */
	void SetFlattenThreshold(enum Convert::FlattenThresholdFlag threshold);

	/**
	 * Where possible output JPG files rather than PNG. This will apply to both
	 * thumbnails and document images. Default is true.
	 * @param prefer_jpg if true JPG images will be used whenever possible.
	 */
	void SetPreferJPG(bool prefer_jpg);

	/**
	 * Specifies the compression quality to use when generating JPEG images.
	 * @param quality the JPEG compression quality, from 0(highest compression) to 100(best quality).
	 */
	void SetJPGQuality(UInt32 quality);

	/**
	 * Outputs rotated text as paths. This option is used as a workaround to a bug in Silverlight
	 * where pages with rotated text could cause the plugin to crash. Default is false.
	 * @param workaround if true rotated text will be changed to paths
	 */
	void SetSilverlightTextWorkaround(bool workaround);

	/**
	 * Choose how to output annotations. Default is e_internal_xfdf.
	 * @param annot_output the flag to specify the output option
	 */
	void SetAnnotationOutput(enum AnnotationOutputFlag annot_output);

	/**
	 * Output XOD as a collection of loose files rather than a zip archive.
	 * This option should be used when using the external part retriever in Webviewer. Default is false.
	 * @param generate if true XOD is output as a collection of loose files
	 */
	void SetExternalParts(bool generate);

	/**
	 * Encrypt XOD parts with AES 128 encryption using the supplied password.
	 * This option is not available when using SetExternalParts(true)
	 * @param pass the encryption password
	 */
	void SetEncryptPassword(const char* pass);

	/**
	 * The latest XOD format is only partially supported in Silverlight and Flash
	 * due to various optimizations in the text format and the addition of blend mode support.
	 * This option forces the converter to use an older version of XOD that is Silverlight/Flash compatible
	 * but does not have these improvements. By default the latest XOD format is generated.
	 * @param compatible if true will use the older XOD format which is not compatible with Silverlight/Flash
	 */
	void UseSilverlightFlashCompatible(bool compatible);
};

/**
 * A class containing options common to ToHtml and ToEpub functions
 */
class HTMLOutputOptions
{
public:
	/**
	 * Creates an HTMLOutputCommonOptions object with default settings
	 */
	HTMLOutputOptions();

	/**
	 * Use JPG files rather than PNG. This will apply to all generated images. Default is true.
	 * @param prefer_jpg if true JPG images will be used whenever possible.
	 */
	void SetPreferJPG(bool prefer_jpg);

	/**
	 * Specifies the compression quality to use when generating JPEG images.
	 * @param quality the JPEG compression quality, from 0 (highest compression) to 100 (best quality).
	 */
	void SetJPGQuality(UInt32 quality);

	/**
	 * The output resolution, from 1 to 1000, in Dots Per Inch (DPI) at which to render elements which cannot be directly converted. 
	 * Default is 140.
	 * @note This option is only available for e_fixed_position mode.
	 * @param dpi the resolution in Dots Per Inch
	 */
	void SetDPI(UInt32 dpi);

	/**
	 * Specifies the maximum image slice size in pixels. Default is 2000000.
	 * @note This setting now will no longer reduce the total number of image pixels.
	 * Instead a lower value will just produce more slices and vice versa.
	 * @note Since image compression works better with more pixels a larger
	 * max pixels should generally create smaller files.
	 * @note This option is only available for e_fixed_position mode.
	 * @param max_pixels the maximum number of pixels an image can have
	 */
	void SetMaximumImagePixels(UInt32 max_pixels);

	enum ContentReflowSetting
	{
		e_fixed_position = 0, /* Content uses fixed positioning (default). */
		e_reflow_paragraphs /* Text flows within paragraphs. */
	};

	/**
	 * Switch between fixed (pre-paginated) and reflowable HTML generation. Default is e_fixed_position.
	 * In e_reflow_paragraphs mode, conversions require that the optional PDFTron
	 * pdf2html add-on module is available.
	 * @param reflow the generated HTML will be either fixed or reflowable.
	 * @see ContentReflowSetting
	 * @see PDF2HtmlReflowParagraphsModule
	 */
	void SetContentReflowSetting(ContentReflowSetting reflow);

	/**
	 * Set an overall scaling of the generated HTML pages. Default is 1.0.
	 * @param scale A number greater than 0 which is used as a scale factor. For example, calling SetScale(0.5) will reduce the HTML body of the page to half its original size, whereas SetScale(2) will double the HTML body dimensions of the page and will rescale all page content appropriately.
	 * @note This option is only available for e_fixed_position mode.
	 */
	void SetScale(double scale);

	/**
	 * Enable the conversion of external URL navigation. Default is false.
	 * @param enable if true, links that specify external URL's are converted into HTML.
	 * @note This option is only available for e_fixed_position mode.
	 */
	void SetExternalLinks(bool enable);

	/**
	 * Enable the conversion of internal document navigation. Default is false.
	 * @param enable if true, links that specify page jumps are converted into HTML.
	 * @note This option is only available for e_fixed_position mode.
	 */
	void SetInternalLinks(bool enable);

	/**
	 * Controls whether converter optimizes DOM or preserves text placement accuracy. Default is false.
	 * @param enable if true, converter will try to reduce DOM complexity at the expense of text placement accuracy.
	 * @note This option is only available for e_fixed_position mode.
	 */
	void SetSimplifyText(bool enable);

	/**
	 * Generate a XML file that contains additional information about the conversion process. By default no report is generated.
	 * @param path the file path to which the XML report is written to.
	 * @note This option is only available for e_fixed_position mode.
	 */
	void SetReportFile(const UString& path);

	/**
	 * Specifies the title for the output HTML.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param title the title of the output HTML.
	 */
	void SetTitle(const UString& title);

	/**
	 * Specifies the output image resolution, from 8 to 600, in Pixels Per Inch (PPI). The
	 * higher the PPI, the larger the image. Default is 192.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param dpi the resolution in Pixels Per Inch.
	 */
	void SetImageDPI(UInt32 dpi);

	/**
	 * Specifies whether images are embedded in the HTML without having to link to external files. Default is true.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param embed if true, images are embedd in the HTML, otherwise, images are saved as external files.
	 */
	void SetEmbedImages(bool embed);

	/**
	 * Specifies the amount of time in seconds after which the conversion fails. Default is 300.
	 * Very long files need more time to convert.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param seconds the timeout in seconds.
	 */
	void SetFileConversionTimeoutSeconds(int seconds);

	/**
	 * Specifies a range of pages to be converted. By default all pages are converted. The first page has the page number of 1.
	 * Use a negative value to specify the last page in the PDF.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param pageFrom the first page to be converted.
	 * @param pageTo the last page to be converted (inclusive).
	 */
	void SetPages(int pageFrom, int pageTo);

	/**
	 * Specifies the password if the PDF requires one.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param password the PDF password, if required; an empty string otherwise.
	 */
	void SetPDFPassword(const UString& password);

	enum SearchableImageSetting
	{
		e_ocr_image_text = 0, /* Indicates that both text and image are going to be visible (default). */
		e_ocr_image, /* Indicates that only the images are going to be visible. */
		e_ocr_text /* Indicates that only the text is going to be visible. */
	};

	/**
	 * Specifies how image + hidden text pages should be converted. Default is e_ocr_image_text.
	 * @note This feature does not perform OCR.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param setting the searchable image setting.
	 * @see SearchableImageSetting
	 */
	void SetSearchableImageSetting(SearchableImageSetting setting);

	/**
	 * Determines whether to use <LI> tags for list items. Default is false.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param enable if true, <LI> tags are used for list items.
	 */
	void SetSimpleLists(bool enable);

	/**
	 * Specifies whether hyphens in the PDF should be connected. This only works with English words. Default is false.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param connect if true, hyphens in the PDF will be connected.
	 */
	void SetConnectHyphens(bool connect);

	/**
	 * Specifies whether to disable the detection of section columns. Default is false.
	 * Enable this if your tables are coming out as section columns.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param disable if true, the detection of section columns are disabled.
	 */
	void SetDisableVerticalSplit(bool disable);

	/**
	 * Determines whether to flow contents across the entire browser window. Default is false.
	 * @note This option is only available for e_reflow_paragraphs mode.
	 * @param enable if true, content will flow across entire page.
	 */
	void SetNoPageWidth(bool enable);

protected:
	TRN_Obj m_obj;
	friend class Convert;
	SDF::ObjSet m_objset;
};

/**
 * A class containing options common to ToWord functions
 */
class WordOutputOptions
{
public:
	/**
	 * Creates a WordOutputOptions object with default settings.
	 */
	WordOutputOptions();

	/**
	 * Specifies the compression quality to use when generating JPEG images.
	 * @param quality the JPEG compression quality, from 0 (highest compression) to 100 (best quality). Default is 75.
	 */
	void SetJPGQuality(UInt32 quality);

	/**
	 * Specifies the output image resolution, from 8 to 600, in Pixels Per Inch (PPI). The
	 * higher the PPI, the larger the image. Default 192.
	 * @param dpi the resolution in Pixels Per Inch.
	 */
	void SetImageDPI(UInt32 dpi);

	enum WordOutputFormat
	{
		e_wof_docx = 0,
		e_wof_doc,
		e_wof_rtf
	};

	/**
	 * Specifies the output document format (DOCX, DOC, RTF). It is the most useful when the output file extension
	 * is not .docx, .doc or .rtf.
	 * @param format the output document format (DOCX, DOC, RTF).
	 * @see WordOutputFormat
	 */
	void SetWordOutputFormat(WordOutputFormat format);

	/**
	 * Specifies the amount of time in seconds after which the conversion fails. Default is 300.
	 * Very long files need more time to convert.
	 * @param seconds the timeout in seconds.
	 */
	void SetFileConversionTimeoutSeconds(int seconds);

	/**
	 * Specifies a range of pages to be converted. By default all pages are converted. The first page has the page number of 1.
	 * Use a negative value to specify the last page in the PDF.
	 * @param pageFrom the first page to be converted.
	 * @param pageTo the last page to be converted (inclusive).
	 */
	void SetPages(int pageFrom, int pageTo);

	/**
	 * Specifies the password if the PDF requires one.
	 * @param password the PDF password, if required; an empty string otherwise.
	 */
	void SetPDFPassword(const UString& password);

	enum BookmarkConversionMethod
	{
		e_bm_none = 0, /* Indicates that no bookmarks are created. */
		e_bm_page, /* Indicates that a bookmark is created for each page (default). */
		e_bm_extract /* Indicates that bookmarks are converted from PDF to Word. */
	};

	/**
	 * Specifies if and how PDF bookmarks should be converted into Word. Default is e_bm_none.
	 * @param method the bookmark conversion method.
	 * @see BookmarkConversionMethod
	 */
	void SetBookmarkConversionMethod(BookmarkConversionMethod method);

	enum SearchableImageSetting
	{
		e_ocr_image_text = 0, /* Indicates that both text and image are going to be visible (default). */
		e_ocr_image, /* Indicates that only the images are going to be visible. */
		e_ocr_text /* Indicates that only the text is going to be visible. */
	};

	/**
	 * Specifies how image + hidden text pages should be converted. Default is e_ocr_image_text.
	 * @note This feature does not perform OCR.
	 * @param setting the searchable image setting.
	 * @see SearchableImageSetting
	 */
	void SetSearchableImageSetting(SearchableImageSetting setting);

	/**
	 * Specifies whether to shrink character spaces in order to prevent word wraps. Default is false.
	 * @param shrink if true, character spaces are shrunk in order to prevent word wraps.
	 */
	void SetShrinkCharacterSpacingToPreventWrap(bool shrink);

	/**
	 * Specifies whether PDF line breaks should come out as line breaks in the Word output. This causes each line
	 * of text to become a separate paragraph. Default is false.
	 * @param match if true, line breaks will come out as line breaks in the Word output.
	 */
	void SetMatchPDFLineBreaks(bool match);

	/**
	 * Specifies whether hyphens in the PDF should be connected. This only works with English words. Default is false.
	 * @param connect if true, hyphens in the PDF will be connected.
	 */
	void SetConnectHyphens(bool connect);

	/**
	 * Specifies whether to disable font adjustments during conversion. Default is false.
	 * @param do_not_adjust if true, font adjustments are disabled during conversion.
	 */
	void SetDoNotAdjustFonts(bool do_not_adjust);

	/**
	 * Specifies whether to disable the detection of section columns. Default is false.
	 * Enable this if your tables are coming out as section columns.
	 * @param disable if true, the detection of section columns are disabled.
	 */
	void SetDisableVerticalSplit(bool disable);

protected:
	TRN_Obj m_obj;
	friend class Convert;
	SDF::ObjSet m_objset;
};

/**
 * A class containing options common to ToEpub functions
 */
class EPUBOutputOptions
{
public:
	/**
	 * Creates an EPUBOutputOptions object with default settings
	 */
	EPUBOutputOptions();

	/**
	 * Create the EPUB in expanded format. Default is false.
	 * @param expanded if false a single EPUB file will be generated, otherwise, the generated EPUB will be in unzipped (expanded) format
	 */
	void SetExpanded(bool expanded);

	/**
	 * Set whether the first content page in the EPUB uses the cover image or not. If this
	 * is set to true, then the first content page will simply wrap the cover image in HTML.
	 * Otherwise, the page will be converted the same as all other pages in the EPUB. Default is false.
	 * @param reuse if true the first page will simply be EPUB cover image, otherwise, the first page will be converted the same as the other pages
	 */
	void SetReuseCover(bool reuse);
protected:
	TRN_Obj m_obj;
	friend class Convert;
	SDF::ObjSet m_objset;
};

/**
	 * A class containing options for ToSvg functions
	 */
class SVGOutputOptions
{
public:

	/**
	 * Creates an SVGOutputOptions object with default settings
	 */
	SVGOutputOptions();

	/**
	 * Sets whether to embed all images
	 * @param embed_images if true, images will be embedded. Default is false.
	 */
	void SetEmbedImages(bool embed_images);

	/**
	 * Sets whether to disable conversion of font data to SVG
	 * @param no_fonts if true, font data conversion is disabled. Default is false.
	 */
	void SetNoFonts(bool no_fonts);

	/**
	 * Sets whether to convert all fonts to SVG or not.
	 * @param svg_fonts if true, fonts are converted to SVG. Otherwise they are converted to OpenType.
	 * Default is false.
	 */
	void SetSvgFonts(bool svg_fonts);

	/**
	 * Sets whether to embed fonts into each SVG page file, or to have them shared.
	 * @param embed_fonts if true, fonts are injected into each SVG page.
	 * Otherwise they are created as separate files that are shared between SVG pages.
	 * Default is false.
	 */
	void SetEmbedFonts(bool embed_fonts);

	/**
	 * Sets whether to disable mapping of text to public Unicode region. Instead text will be converted using a custom encoding
	 * @param no_unicode if true, mapping of text to public Unicode region is disabled
	 */
	void SetNoUnicode(bool no_unicode);

	/**
	 * Some viewers do not support the default text positioning correctly. This option works around this issue to place text correctly, but produces verbose output. This option will override SetRemoveCharPlacement
	 * @param individual_char_placement if true, text will be positioned correctly
	 */
	void SetIndividualCharPlacement(bool individual_char_placement);

	/**
	 * Sets whether to disable the output of character positions.  This will produce slightly smaller output files than the default setting, but many viewers do not support the output correctly
	 * @param remove_char_placement if true, the output of character positions is disabled
	 */
	void SetRemoveCharPlacement(bool remove_char_placement);

	/**
	 * Flatten images and paths into a single background image overlaid with
	 * vector text. This option can be used to improve speed on devices with
	 * little processing power such as iPads. Default is e_fast.
	 * @param flatten select which flattening mode to use.
	 */
	void SetFlattenContent(enum Convert::FlattenFlag flatten);

	/**
	 * Used to control how precise or relaxed text flattening is. When some text is
	 * preserved (not flattened to image) the visual appearance of the document may be altered.
	 * @param threshold the threshold setting to use.
	 */
	void SetFlattenThreshold(enum Convert::FlattenThresholdFlag threshold);

	/**
	* The output resolution, from 1 to 1000, in Dots Per Inch (DPI) at which to render elements which cannot be directly converted.
	* Default is 140.
	* @param dpi the resolution in Dots Per Inch
	*/
	void SetFlattenDPI(UInt32 dpi);

	/**
	 * Specifies the maximum image slice size in pixels. Default is 2000000.
	 * @note This setting now will no longer reduce the total number of image pixels.
	 * Instead a lower value will just produce more slices and vice versa.
	 * @note Since image compression works better with more pixels a larger
	 * max pixels should generally create smaller files.
	 * @param max_pixels the maximum number of pixels an image can have
	 */
	void SetFlattenMaximumImagePixels(UInt32 max_pixels);

	/**
	 * Compress output SVG files using SVGZ.
	 * @param svgz if true, SVG files are written in compressed format. Default is false.
	 */
	void SetCompress(bool svgz);

	/**
	 * Sets whether per page thumbnails should be included in the file. Default is true.
	 * @param include_thumbs if true thumbnails will be included
	 */
	void SetOutputThumbnails(bool include_thumbs);

	/**
	 * The maximum dimension for thumbnails.
	 * @param size the maximum dimension (width or height) that
	 * thumbnails will have. Default is 400.
	 */
	void SetThumbnailSize(UInt32 size);

	/**
	 * Create a XML document that contains metadata of the SVG document created.
	 * @param xml if true, XML wrapper is created. Default is true.
	 */
	void SetCreateXmlWrapper(bool xml);

	/**
	 * Set whether the DTD declaration is included in the SVG files.
	 * @param dtd if false, no DTD is added to SVG files. Default is true.
	 */
	void SetDtd(bool dtd);

	/**
	 * Control generation of form fields and annotations in SVG.
	 * @param annots if false, no form fields or annotations are converted. Default is true
	 */
	void SetAnnots(bool annots);

	/**
	* Enable or disable support for overprint and overprint simulation.
	* Overprint is a device dependent feature and the results will vary depending on
	* the output color space and supported colorants (i.e. CMYK, CMYK+spot, RGB, etc).
	* Default is e_op_pdfx_on.
	*
	* @param op e_op_on: always enabled; e_op_off: always disabled; e_op_pdfx_on: enabled for PDF/X files only.
	*/
	void SetOverprint(PDFRasterizer::OverprintPreviewMode mode);
protected:
	TRN_Obj m_obj;
	friend class Convert;
	SDF::ObjSet m_objset;
};

/**
 * A class containing options for ToTiff functions
 */
class TiffOutputOptions
{
public:
	/**
	 * Creates an TiffOutputOptions object with default settings
	 */
	TiffOutputOptions();

	/**
	 * Specifies the page box/region to rasterize.
	 * Possible values are media, crop, trim,
	 * bleed, and art.  By default, page crop
	 * region will be rasterized.
	 */
	void SetBox(enum Page::Box type);

	/**
	 * Rotates all pages by a given number of
	 * degrees counterclockwise. The allowed
	 * values are 0, 90, 180, and 270. The default
	 * value is 0.
	 */
	void SetRotate(enum Page::Rotate rotation);

	/**
	 * User definable clip box. By default, the
	 * clip region is identical to current page
	 * 'box'.
	 */
	void SetClip(double x1, double y1, double x2, double y2);

	/**
	 * Specifies the list of pages to convert. By
	 * default, all pages are converted.
	 */
	void SetPages(const char* page_desc);

	/**
	 * Enable or disable support for overprint and overprint simulation.
	 * Overprint is a device dependent feature and the results will vary depending on
	 * the output color space and supported colorants (i.e. CMYK, CMYK+spot, RGB, etc).
	 * Default is e_op_pdfx_on.
	 *
	 * @param op e_op_on: always enabled; e_op_off: always disabled; e_op_pdfx_on: enabled for PDF/X files only.
	 */
	void SetOverprint(enum PDFRasterizer::OverprintPreviewMode mode);

	/**
	 * Render and export the image in CMYK mode.
	 * By default, the image is rendered and
	 * exported in RGB color space.
	 */
	void SetCMYK(bool enable);

	/**
	 * Enables dithering when the image is
	 * exported in palletized or monochrome mode.
	 *
	 * This option is disabled by default.
	 */
	void SetDither(bool enable);

	/**
	 * Render and export the image in grayscale
	 * mode. Sets pixel format to 8 bits per pixel
	 * grayscale. By default, the image is
	 * rendered and exported in RGB color space.
	 */
	void SetGray(bool enable);

	/**
	 * Export the rendered image as 1 bit per
	 * pixel (monochrome) image. The image will be
	 * compressed using G4 CCITT compression
	 * algorithm. By default, the image is not
	 * dithered. To enable dithering use
	 * 'SetDither' option. This option is disabled by
	 * default.
	 */
	void SetMono(bool enable);

	/**
	 * Enables or disables drawing of
	 * annotations.
	 *
	 * This option is enabled by default.
	 */
	void SetAnnots(bool enable);

	/**
	 * Enables or disables image
	 * smoothing (default: enabled).
	 */
	void SetSmooth(bool enable);

	/**
	 * Renders annotations in the print mode. This
	 * option can be used to render 'Print Only'
	 * annotations and to hide 'Screen Only'
	 * annotations.
	 *
	 * This option is disabled by default.
	 */
	void SetPrintmode(bool enable);

	/**
	 * Sets the page color to transparent. By
	 * default, Convert assumes that the page is
	 * drawn directly on an opaque white surface.
	 * Some applications may need to draw the page
	 * on a different backdrop. In this case any
	 * pixels that are not covered during
	 * rendering will be transparent.
	 *
	 * This option is disabled by default.
	 */
	void SetTransparentPage(bool enable);


	/**
	 * Enabled the output of palettized TIFFs.
	 *
	 * This option is disabled by default.
	 */
	void SetPalettized(bool enable);

	/**
	 * The output resolution, from 1 to 1000, in Dots Per Inch (DPI). The
	 * higher the DPI, the larger the image. Resolutions larger than 1000 DPI can
	 * be achieved by rendering image in tiles or stripes. The default resolution
	 * is 92 DPI.
	 */
	void SetDPI(double dpi);

	/**
	 * Sets the gamma factor used for anti-aliased
	 * rendering. Typical values are in the range
	 * from 0.1 to 3. Gamma correction can be used
	 * to improve the quality of anti-aliased
	 * image output and can (to some extent)
	 * decrease the appearance common
	 * anti-aliasing artifacts (such as pixel
	 * width lines between polygons).  The default
	 * gamma is 0.
	 */
	void SetGamma(double gamma);

	/**
	 * Sets the width of the output image, in pixels.
	 */
	void SetHRes(int hres);

	/**
	 * Sets the height of the output image, in pixels.
	 */
	void SetVRes(int vres);


protected:
	TRN_Obj m_obj;
	friend class Convert;
	SDF::ObjSet m_objset;
};

/**
 * Convert::Printer is a utility class to install the a printer for
 * print-based conversion of documents for Convert::ToPdf
 */
class Printer
{
public:
	/**
	 * Install the PDFNet printer. Installation can take a few seconds,
	 * so it is recommended that you install the printer once as part of
	 * your deployment process.  Duplicated installations will be quick since
	 * the presence of the printer is checked before installation is attempted.
	 * There is no need to uninstall the printer after conversions, it can be
	 * left installed for later access.
	 *
	 * @param in_printerName the name of the printer to install and use for conversions.
	 * If in_printerName is not provided then the name "PDFTron PDFNet" is used.
	 *
	 * @note Installing and uninstalling printer drivers requires the process
	 * to be running as administrator.
	 */
	static void Install(const UString & in_printerName = "PDFTron PDFNet");

	/**
	 * Uninstall all printers using the PDFNet printer driver.
	 *
	 * @note Installing and uninstalling printer drivers requires the process
	 * to be running as administrator.  Only the "PDFTron PDFNet" printer can
	 * be uninstalled with this function.
	 */
	static void Uninstall();

	/**
	 * Get the name of the PDFNet printer installed in this process session.
	 *
	 * @return the Unicode name of the PDFNet printer
	 *
	 * @note if no printer was installed in this process then the predefined string
	 * "PDFTron PDFNet" will be returned.
	 */
	static const UString GetPrinterName();

	/**
	 * Set the name of the PDFNet printer installed in this process session.
	 *
	 * @return the Unicode name of the PDFNet printer
	 *
	 * @note if no printer was installed in this process then the predefined string
	 * "PDFTron PDFNet" will be used.
	 */
	static void SetPrinterName(const UString & in_printerName = "PDFTron PDFNet");

	/**
	 * Determine if the PDFNet printer is installed
	 *
	 * @param in_printerName the name of the printer to install and use for conversions.
	 * If in_printerName is not provided then the name "PDFTron PDFNet" is used.
	 *
	 * @return true if the named printer is installed, false otherwise
	 *
	 * @note may or may not check if the printer with the given name is actually
	 * a PDFNet printer.
	 */
	static bool IsInstalled(const UString & in_printerName = "PDFTron PDFNet");

	enum Mode {
		/**
		* By default PDFNet will pick the best means of converting the target document.
		*/
		e_auto,
		/**
		* For Office file conversions, force COM Interop to be used, regardless if this virtual printer is installed or not.
		*/
		e_interop_only,
		/**
		* For Office file conversions, do not check for Office COM Interop availability, and use the printer path instead.
		*/
		e_printer_only,
		/**
		* For Office file conversions, use the built in converter if it is available for the converted file type.
		*/
		e_prefer_builtin_converter
	};

	/**
	 * Configure how PDFNet prints documents.
	 *
	 * @param mode set the print mode. Default is e_auto.
	 */
	static void SetMode(Mode mode);

	/**
	 * Get the current mode for print jobs.
	 *
	 * @return the current print mode
	 */
	static Mode GetMode();


};

#include <Impl/Convert.inl>

	}; // namespace PDF
}; // namespace pdftron

#endif // PDFTRON_H_CPPPDFConvert
