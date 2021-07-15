//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFHTML2PDF
#define PDFTRON_H_CPPPDFHTML2PDF

#include <PDF/PDFDoc.h>
#include <PDF/Print.h>
#include <C/PDF/TRN_HTML2PDF.h>

namespace pdftron {
	namespace PDF {
		
class Proxy;
class WebPageSettings;
class TOCSettings;

/** 
 * 'pdftron.PDF.HTML2PDF' is an optional PDFNet Add-On utility class that can be 
 * used to convert HTML web pages into PDF documents by using an external
 * module (html2pdf).
 *
 * The html2pdf modules can be downloaded from http: www.pdftron.com/pdfnet/downloads.html.
 *
 * Users can convert HTML pages to PDF using the following operations:
 * - Simple one line static method to convert a single web page to PDF. 
 * - Convert HTML pages from URL or string, plus optional table of contents, in user defined order. 
 * - Optionally configure settings for proxy, images, java script, and more for each HTML page. 
 * - Optionally configure the PDF output, including page size, margins, orientation, and more. 
 * - Optionally add table of contents, including setting the depth and appearance.
 *
 * The following code converts a single webpage to pdf
 *
 * @code
 * using namespace pdftron;
 * using namespace PDF;
 *
 * PDFDoc pdfdoc;
 * if ( HTML2PDF::Convert(pdfdoc, "http://www.gutenberg.org/wiki/Main_Page") )
 *		pdfdoc.Save(outputFile, SDF::SDFDoc::e_remove_unused, NULL);
 * @endcode
 * 
 * The following code demonstrates how to convert multiple web pages into one pdf,
 * excluding the background, and with lowered image quality to save space.
 *
 * @code
 * using namespace pdftron;
 * using namespace PDF;
 *
 * HTML2PDF converter;
 * converter.SetImageQuality(25);
 * 
 * HTML2PDF::WebPageSettings settings;
 * settings.SetPrintBackground(false);
 *
 * converter.InsertFromURL("http://www.gutenberg.org/wiki/Main_Page", settings);
 *
 * PDFDoc pdfdoc;
 * if ( converter.Convert(pdfdoc) )
 *		pdfdoc.Save(outputFile, SDF::SDFDoc::e_remove_unused, NULL);
 * @endcode
 */
class HTML2PDF
{
public:
	typedef pdftron::PDF::Proxy Proxy;
	typedef pdftron::PDF::WebPageSettings WebPageSettings;
	typedef pdftron::PDF::TOCSettings TOCSettings;

#ifndef SWIG
	/**
	 * Convert the HTML document at url and append the results
	 * to doc.
	 *
	 * @pre html2pdf module must be located in the working directory, or
	 * with the PDFNetC library.
	 *
	 * @return true if successful, otherwise false. Use 
	 * @ref GetHttpErrorCode for possible HTTP errors.
	 *
	 * @param doc - Target PDF to which converted HTML pages will
	 * be appended to.
	 * @param url - HTML page, or relative path to local HTML page,
	 * that will be converted to PDF format.
	 *
	 * @note If you wish to convert more than one web page you need to use
	 * an instance of HTML2PDF.
	 */
	static bool Convert(PDFDoc& doc, const UString& url);

	/**
	 * Convert the HTML document at url and append the results
	 * to doc.
	 *
	 * @pre html2pdf module must be located in the working directory, or
	 * with the PDFNetC library.
	 *
	 * @return true if successful, otherwise false. Use 
	 * @ref GetHttpErrorCode for possible HTTP errors.
	 *
	 * @param doc - Target PDF to which converted HTML pages will
	 * be appended to.
	 * @param url - HTML page, or relative path to local HTML page,
	 * that will be converted to PDF format.
	 * @param settings - Modify how the web page is loaded and
	 * converted.
	 *
	 * @note If you wish to convert more than one web page you need to use
	 * an instance of HTML2PDF.
	 */
	static bool Convert(PDFDoc& doc, const UString& url, const WebPageSettings& settings);
#endif

	/**
	 * Add a web page to be converted. A single URL typically 
	 * results in many PDF pages.
	 * @param url - HTML page, or relative path to local HTML page
	 */
	void InsertFromURL(const UString& url);

	/**
	 * Add a web page to be converted. A single URL typically 
	 * results in many PDF pages.
	 *
	 * @param url - HTML page, or relative path to local HTML page
	 * @param settings - How the web page should be loaded and converted
	 */
	void InsertFromURL(const UString& url, const WebPageSettings& settings);

	/**
	 * Convert HTML encoded in string.
	 *
	 * @param html - String containing HTML code.
	 */
	void InsertFromHtmlString(const UString& html);

	/**
	 * Convert HTML encoded in string.
	 *
	 * @param html - String containing HTML code.
	 * @param settings - How the HTML content described in html is loaded.
	 */
	void InsertFromHtmlString(const UString& html, const WebPageSettings& settings);

	/**
	 * Add a table of contents to the produced PDF.
	 */
	void InsertTOC();

	/**
	 * Add a table of contents to the produced PDF.
	 *
	 * @param settings - Settings for the table of contents.
	 */
	void InsertTOC(const TOCSettings& settings);

	/**
	 * Convert HTML documents and append the results
	 * to doc.
	 *
	 * @pre html2pdf module must be located in the working directory, or
	 * with the PDFNetC library.
	 *
	 * @return true if successful, otherwise false. Use 
	 * @ref GetHttpErrorCode for possible HTTP errors.
	 *
	 * @param doc - Target PDF to which converted HTML pages will
	 * be appended to.
	 *
	 * @note Use @ref InsertFromURL and @ref InsertFromHtmlString to
	 * add HTML documents to be converted.
	 */
	bool Convert(PDFDoc& doc);

	/**
	 * Return the largest HTTP error code encountered during conversion
	 *
	 * @return the largest HTTP code greater then or equal to 300 encountered during loading
	 * of any of the supplied objects, if no such error code is found 0 is returned.
	 *
	 * @note This function will only return a useful result after @ref Convert has been called.
	 */
	int GetHTTPErrorCode() const;

	/**
	 * Display HTML to PDF conversion progress, warnings, and errors, to stdout.
	 *
	 * @param quiet - If false, progress information is sent to stdout during conversion.
	 *
	 * @note You can get the final results using GetLog.
	 */
	void SetQuiet(bool quiet);

	/**
	 * Get results of conversion, including errors and warnings, in human readable form.
	 *
	 * @return String containing results of conversion.
	 */
	UString GetLog() const;

	/**
	 * Set the only location that PDFNet will look for the html2pdf module.
	 *
	 * @param path - A folder or file path. If non-empty, PDFNet will only
	 * look in path for the html2pdf module, otherwise it will search in
	 * the default locations for the module.
	 */
	static void SetModulePath(const UString& path);

	/**
	 * Default constructor.
	 */
	HTML2PDF();

	/**
	 * Destructor.
	 */
	~HTML2PDF();

	/**
	 * Set paper size of output PDF
	 *
	 * @param size - Paper size to use for produced PDF.
	 */
	void SetPaperSize(PrinterMode::PaperSize size);  

	/**
	 * Manually set the paper dimensions of the produced PDF.
	 *
	 * @param width - Width of the page, e.g. "4cm".
	 * @param height - Height of the page, eg. "12in".
	 *
	 * @note Supported units are mm, cm, m, in, pica(pc), pixel(px) and point(pt).
	 */
	void SetPaperSize(const UString& width, const UString& height);

	/**
	 * Set page orientation for output PDF.
	 *
	 * @param enable - If true generated PDF pages will be orientated to
	 * landscape, otherwise orientation will be portrait.
	 */
	void SetLandscape(bool enable);

	/**
	 * Change the DPI explicitly for the output PDF.
	 *
	 * @param dpi - Dots per inch, e.g. 80.
	 *
	 * @attention This has no effect on X11 based systems.
	 * @note Results also depend on @ref SetSmartShrinking.
	 */
	void SetDPI(int dpi);

	/**
	 * Add bookmarks to the PDF.
	 *
	 * @param enable - If true bookmarks will be generated for the
	 * produced PDF.
	 * @param depth - Maximum depth of the outline (e.g. 4).
	 */
	void SetOutline(bool enable, int depth = 4);

	/**
	 * Save outline to a xml file.
	 *
	 * @param xml_file - Path of where xml data representing outline 
	 * of produced PDF should be saved to.
	 */
	void DumpOutline(const UString& xml_file);

	/**
	 * Use loss less compression to create PDF.
	 *
	 * @param enable - If true loss less compression will be used to
	 * create PDF.
	 */
	void SetPDFCompression(bool enable);

	/**
	 * Set margins of generated PDF.
	 *
	 * @param top - Size of the top margin, e.g. "2cm". 
	 * @param bottom - Size of the bottom margin, e.g. "2cm".
	 * @param left - Size of the left margin, e.g. "2cm".
	 * @param right - Size of the right margin, e.g. "2cm".
	 *
	 * @note Supported units are mm, cm, m, in, pica(pc), pixel(px) and point(pt).
	 */
	void SetMargins(const UString& top, const UString& bottom, const UString& left, const UString& right);

	/**
	 * Maximum DPI to use for images in the generated PDF.
	 *
	 * @param dpi - Maximum dpi of images in produced PDF, e.g. 80.
	 */
	void SetImageDPI(int dpi);

	/**
	 * JPEG compression factor to use when generating PDF.
	 *
	 * @param quality - Compression factor, e.g. 92.
	 */
	void SetImageQuality(int quality);

	/**
	 * Path of file used for loading and storing cookies.
	 *
	 * @param path - Path to file used for loading and storing cookies.
	 */
	void SetCookieJar(const UString& path);

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

	// @cond PRIVATE_DOC

	#ifndef SWIGHIDDEN
	TRN_HTML2PDF mp_html2pdf;
	#endif

private:
	HTML2PDF(const HTML2PDF&);
	HTML2PDF& operator= (const HTML2PDF&);
	// @endcond

};


	/**
	 * Proxy settings to be used when loading content from web pages.
	 *
	 * @note These Proxy settings will only be used if type is not e_default.
	 */
class Proxy
{
public:
	/**
	 * Default constructor
	 */
	Proxy();

	/**
	 * Destructor
	 */
	~Proxy();

	/**
	 * Set the type of proxy to use.
	 *
	 * @param type - If e_default, use whatever the html2pdf library decides
	 * on. If e_none, explicitly sets that no proxy is to be used. If e_http
	 * or e_socks5 then the corresponding proxy protocol is used.
	 */
	enum Type { e_default, e_none, e_http, e_socks5 };
	void SetType(Type type);

	/**
	 * Set the proxy host to use.
	 *
	 * @param host - String defining the host name, e.g. "myserver" or "www.xxx.yyy.zzz"
	 */
	void SetHost(const UString& host);

	/**
	 * Set the port number to use
	 *
	 * @param port - A valid port number, e.g. 3128.
	 */
	void SetPort(int port);

	/**
	 * Set the username to use when logging into the proxy
	 *
	 * @param username - The login name, e.g. "elbarto".
	 */
	void SetUsername(const UString& username);

	/**
	 * Set the password to use when logging into the proxy with username
	 *
	 * @param password - The password to use, e.g. "bart".
	 */
	void SetPassword(const UString& password);

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();

	// @cond PRIVATE_DOC

#ifndef SWIGHIDDEN
	TRN_HTML2PDF_Proxy mp_impl;
#endif
	// @endcond

};

/**
 * Settings that control how a web page is opened and converted to PDF.
 */
class WebPageSettings
{
public:
	/**
	 * Default constructor
	 */
	WebPageSettings();

	/**
	 * Destructor
	 */
	~WebPageSettings();

	/**
	 * Print the background of this web page.
	 *
	 * @param background - If true background is printed.
	 */
	void SetPrintBackground(bool background);

	/**
	 * Print the images of this web page.
	 *
	 * @param load - If true images are printed.
	 */
	void SetLoadImages(bool load);

	/**
	 * Allow javascript from this web page to be run.
	 *
	 * @param enable - If true javascript's are allowed.
	 */
	void SetAllowJavaScript(bool enable);

	/**
	 * Allow intelligent shrinking to fit more content per page.
	 *
	 * @param enable - If true intelligent shrinking is enabled and
	 * the pixel/dpi ratio is non constant.
	 */
	void SetSmartShrinking(bool enable);

	/**
	 * Set the smallest font size allowed, e.g 9.
	 *
	 * @param size - No fonts will appear smaller than this.
	 */
	void SetMinimumFontSize(int size);

	/**
	 * Default encoding to be used when not specified by the web page.
	 *
	 * @param encoding - Default encoding, e.g. utf-8 or iso-8859-1.
	 *
	 * @note available encodings are Apple Roman, Big5, Big5-HKSCS,
	 * CP949, EUC-JP, EUC-KR, GB18030-0, IBM 850,
	 * IBM 866, IBM 874, ISO 2022-JP, ISO 8859-1 to 10, ISO 8859-13 to 16,
	 * Iscii-Bng, Dev, Gjr, Knd, Mlm, Ori, Pnj, Tlg, Tml, JIS X 0201, JIS X 0208,
	 * KOI8-R, KOI8-U, MuleLao-1, ROMAN8, Shift-JIS, TIS-620, TSCII,
	 * UTF-8, UTF-16, UTF-16BE, UTF-16LE, UTF-32, UTF-32BE, UTF-32LE,
	 * Windows-1250 to 1258, WINSAMI2.
	 */
	void SetDefaultEncoding(const UString& encoding);

	/**
	 * Url or path to user specified style sheet.
	 *
	 * @param url - URL or file path to user style sheet to be used
	 * with this web page.
	 */
	void SetUserStyleSheet(const UString& url);

	/**
	 * Allow Netscape and flash plugins from this web page to
	 * be run. Enabling will have limited success.
	 *
	 * @param enable - If true Netscape & flash plugins will be run.
	 */
	void SetAllowPlugins(bool enable);

	/**
	 * Controls how content will be printed from this web page.
	 *
	 * @param print - If true the print media type will be used, otherwise
	 * the screen media type will be used to print content.
	 */
	void SetPrintMediaType(bool print);

	/**
	 * Add sections from this web page to the outline and
	 * table of contents.
	 *
	 * @param include - If true PDF pages created from this web
	 * page will show up in the outline, and table of contents,
	 * otherwise, produced PDF pages will be excluded.
	 */
	void SetIncludeInOutline(bool include);

	/**
	 * HTTP authentication username to use when logging into the website.
	 *
	 * @param username - The login name to use with the server, e.g. "bart".
	 */
	void SetUsername(const UString& username);

	/**
	 * HTTP authentication password to use when logging into the website.
	 *
	 * @param password - The login password to use with the server, e.g. "elbarto".
	 */
	void SetPassword(const UString& password);

	/**
	 * Amount of time to wait for a web page to start printing after
	 * it's completed loading. Converter will wait a maximum of msec milliseconds
	 * for javascript to call window.print().
	 *
	 * @param msec - Maximum wait time in milliseconds, e.g. 1200.
	 */
	void SetJavaScriptDelay(int msec);

	/**
	 * Zoom factor to use when loading object.
	 *
	 * @param zoom - How much to magnify the web content by, e.g. 2.2.
	 */
	void SetZoom(double zoom);

	/**
	 * Allow local and piped files access to other local files.
	 *
	 * @param block - If true local files will be inaccessible.
	 */
	void SetBlockLocalFileAccess(bool block);

	/**
	 * Stop slow running javascript's.
	 *
	 * @param stop - If true, slow running javascript's will be stopped.
	 */
	void SetStopSlowScripts(bool stop);

	/**
	 * Forward javascript warnings and errors to output.
	 *
	 * @param forward - If true javascript errors and warnings will be forwarded
	 * to stdout and the log.
	 */
	void SetDebugJavaScriptOutput(bool forward);

	/**
	 * How to handle objects that failed to load.
	 *
	 * @param type - If e_abort then conversion process is aborted, if
	 * e_skip then the converter will not add this web page to the PDF
	 * output, and if e_skip then the converter will try to add this
	 * web page to the PDF output.
	 */
	enum ErrorHandling {
		e_abort,	// Abort the conversion process.
		e_skip,		// Do not add the object to the final output
		e_ignore	// Try to add the object to the final output.
	};
	void SetLoadErrorHandling(ErrorHandling type);

	/**
	 * Convert external links in HTML document to external
	 * PDF links.
	 *
	 * @param convert - If true PDF pages produced from this web page
	 * can have external links.
	 */
	void SetExternalLinks(bool convert);

	/**
	 * Convert internal links in HTML document into PDF references.
	 *
	 * @param convert - If true PDF pages produced from this web page
	 * will have links to other PDF pages.
	 */
	void SetInternalLinks(bool convert);

	/**
	 * Turn HTML forms into PDF forms.
	 *
	 * @param forms - If true PDF pages produced from this web page
	 * will have PDF forms for any HTML forms the web page has.
	 */
	void SetProduceForms(bool forms);

	/**
	 * Use this proxy to load content from this web page.
	 *
	 * @param proxy - Contains settings for proxy
	 */
	void SetProxy(const Proxy& proxy);

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();

	// @cond PRIVATE_DOC

#ifndef SWIGHIDDEN
	TRN_HTML2PDF_WebPageSettings mp_impl;
#endif
	// @endcond

};

/**
 * Settings for table of contents.
 */
class TOCSettings
{
public:
	/**
	 * Default table of contents settings.
	 */
	TOCSettings();

	/**
	 * destructor.
	 */
	~TOCSettings();

	/**
	 * Use a dotted line when creating TOC.
	 *
	 * @param enable - Table of contents will use dotted lines.
	 */
	void SetDottedLines(bool enable);

	/**
	 * Create links from TOC to actual content.
	 *
	 * @param enable - Entries in table of contents will
	 * link to section in the PDF.
	 */
	void SetLinks(bool enable);

	/**
	 * Caption text to be used with TOC.
	 *
	 * @param caption - Text that will appear with the table of contents.
	 */
	void SetCaptionText(const UString& caption);

	/**
	 * Indentation used for every TOC level...
	 *
	 * @param indentation - How much to indent each level, e.g. "2"
	 */
	void SetLevelIndentation(int indentation);

	/**
	 * How much to shrink font for every level, e.g. 0.8
	 *
	 * @param shrink - Rate at which lower level entries will appear smaller
	 */
	void SetTextSizeShrink(double shrink);

	/**
	 * xsl style sheet used to convert outline XML into a
	 * table of content.
	 *
	 * @param style_sheet - Path to xsl style sheet to be used to generate
	 * this table of contents.
	 */
	void SetXsl(const UString& style_sheet);

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();

	// @cond PRIVATE_DOC

#ifndef SWIGHIDDEN
	TRN_HTML2PDF_TOCSettings mp_impl;
#endif
	// @endcond

};

	};	// namespace PDF
};	// namespace pdftron

#include <Impl/HTML2PDF.inl>

#endif // PDFTRON_H_CPPPDFHTML2PDF
