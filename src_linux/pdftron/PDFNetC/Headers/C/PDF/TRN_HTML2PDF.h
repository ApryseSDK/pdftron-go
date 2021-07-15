//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFHTML2PDF
#define PDFTRON_H_CPDFHTML2PDF

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

	struct TRN_html2pdf;
	typedef struct TRN_html2pdf* TRN_HTML2PDF;

	struct TRN_html2pdf_webpagesettings;
	typedef struct TRN_html2pdf_webpagesettings* TRN_HTML2PDF_WebPageSettings;

	struct TRN_html2pdf_tocsettings;
	typedef struct TRN_html2pdf_tocsettings* TRN_HTML2PDF_TOCSettings;

	struct TRN_html2pdf_proxy;
	typedef struct TRN_html2pdf_proxy* TRN_HTML2PDF_Proxy;

    // WebPageSettings
	enum TRN_HTML2PDF_WebPageSettings_ErrorHandling
	{
		e_HTML2PDF_WebPageSettings_abort,
		e_HTML2PDF_WebPageSettings_skip,
		e_HTML2PDF_WebPageSettings_ignore
	};

	enum TRN_HTML2PDF_Proxy_Type
	{
		e_HTML2PDF_Proxy_default,
		e_HTML2PDF_Proxy_none,
		e_HTML2PDF_Proxy_http,
		e_HTML2PDF_Proxy_socks5
	};

	TRN_API TRN_HTML2PDF_ProxyCreate (TRN_HTML2PDF_Proxy* result);
	TRN_API TRN_HTML2PDF_ProxyDestroy (TRN_HTML2PDF_Proxy proxy);
	TRN_API TRN_HTML2PDF_ProxySetType (TRN_HTML2PDF_Proxy proxy, enum TRN_HTML2PDF_Proxy_Type type);
	TRN_API TRN_HTML2PDF_ProxySetPort (TRN_HTML2PDF_Proxy proxy, int port);
	TRN_API TRN_HTML2PDF_ProxySetHost (TRN_HTML2PDF_Proxy proxy, const TRN_UString host);
	TRN_API TRN_HTML2PDF_ProxySetUsername (TRN_HTML2PDF_Proxy proxy, const TRN_UString username);
	TRN_API TRN_HTML2PDF_ProxySetPassword (TRN_HTML2PDF_Proxy proxy, const TRN_UString password);

	TRN_API TRN_HTML2PDF_WebPageSettingsCreate (TRN_HTML2PDF_WebPageSettings* result);
	TRN_API TRN_HTML2PDF_WebPageSettingsDestroy (TRN_HTML2PDF_WebPageSettings settings);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetPrintBackground (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool background);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetLoadImages (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool load);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetAllowJavaScript (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool enable);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetSmartShrinking (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool enable);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetMinimumFontSize (TRN_HTML2PDF_WebPageSettings settings, int size);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetDefaultEncoding (TRN_HTML2PDF_WebPageSettings settings, const TRN_UString encoding);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetUserStyleSheet (TRN_HTML2PDF_WebPageSettings settings, const TRN_UString url);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetAllowPlugins (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool enable);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetPrintMediaType (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool print);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetIncludeInOutline (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool include);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetUsername (TRN_HTML2PDF_WebPageSettings settings, const TRN_UString username);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetPassword (TRN_HTML2PDF_WebPageSettings settings, const TRN_UString password);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetJavaScriptDelay (TRN_HTML2PDF_WebPageSettings settings, int msec);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetZoom (TRN_HTML2PDF_WebPageSettings settings, double zoom);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetBlockLocalFileAccess (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool block);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetStopSlowScripts (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool stop);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetDebugJavaScriptOutput (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool forward);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetLoadErrorHandling (TRN_HTML2PDF_WebPageSettings settings, enum TRN_HTML2PDF_WebPageSettings_ErrorHandling val);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetExternalLinks (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool convert);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetInternalLinks (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool convert);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetProduceForms (TRN_HTML2PDF_WebPageSettings settings, TRN_Bool forms);
	TRN_API TRN_HTML2PDF_WebPageSettingsSetProxy (TRN_HTML2PDF_WebPageSettings settings, const TRN_HTML2PDF_Proxy proxy);

	TRN_API TRN_HTML2PDF_TOCSettingsCreate (TRN_HTML2PDF_TOCSettings* result);
	TRN_API TRN_HTML2PDF_TOCSettingsDestroy (TRN_HTML2PDF_TOCSettings settings);
	TRN_API TRN_HTML2PDF_TOCSettingsSetDottedLines (TRN_HTML2PDF_TOCSettings settings, TRN_Bool enable);
	TRN_API TRN_HTML2PDF_TOCSettingsSetLinks (TRN_HTML2PDF_TOCSettings settings, TRN_Bool enable);
	TRN_API TRN_HTML2PDF_TOCSettingsSetCaptionText (TRN_HTML2PDF_TOCSettings settings, TRN_UString caption);
	TRN_API TRN_HTML2PDF_TOCSettingsSetLevelIndentation (TRN_HTML2PDF_TOCSettings settings, int indentation);
	TRN_API TRN_HTML2PDF_TOCSettingsSetTextSizeShrink (TRN_HTML2PDF_TOCSettings settings, double shrink);
	TRN_API TRN_HTML2PDF_TOCSettingsSetXsl (TRN_HTML2PDF_TOCSettings settings, const TRN_UString style_sheet);

	// Static functions
	TRN_API TRN_HTML2PDFStaticConvert (TRN_PDFDoc doc, const TRN_UString url, TRN_Bool* result);
	TRN_API TRN_HTML2PDFStaticConvert2 (TRN_PDFDoc doc, const TRN_UString url, TRN_HTML2PDF_WebPageSettings settings, TRN_Bool* result);

	// Methods
	TRN_API TRN_HTML2PDFCreate (TRN_HTML2PDF* result);
	TRN_API TRN_HTML2PDFDestroy (TRN_HTML2PDF html2pdf);
	TRN_API TRN_HTML2PDFInsertFromUrl (TRN_HTML2PDF html2pdf, const TRN_UString url);
	TRN_API TRN_HTML2PDFInsertFromUrl2 (TRN_HTML2PDF html2pdf, const TRN_UString url, TRN_HTML2PDF_WebPageSettings settings);
	TRN_API TRN_HTML2PDFInsertFromHtmlString (TRN_HTML2PDF html2pdf, const TRN_UString html);
	TRN_API TRN_HTML2PDFInsertFromHtmlString2 (TRN_HTML2PDF html2pdf, const TRN_UString html, TRN_HTML2PDF_WebPageSettings settings);
	TRN_API TRN_HTML2PDFInsertTOC (TRN_HTML2PDF html2pdf);
	TRN_API TRN_HTML2PDFInsertTOC2 (TRN_HTML2PDF html2pdf, const TRN_HTML2PDF_TOCSettings settings);
	TRN_API TRN_HTML2PDFConvert (TRN_HTML2PDF html2pdf, TRN_PDFDoc doc, TRN_Bool* result);
	TRN_API TRN_HTML2PDFGetHttpErrorCode (TRN_HTML2PDF html2pdf, int* result);
	TRN_API TRN_HTML2PDFGetLog (TRN_HTML2PDF html2pdf, TRN_UString* result);
	TRN_API TRN_HTML2PDFSetPaperSize(TRN_HTML2PDF html2pdf, enum TRN_PrinterModePaperSize size);
	TRN_API TRN_HTML2PDFSetPaperSize2 (TRN_HTML2PDF html2pdf, const TRN_UString width, const TRN_UString height);
	TRN_API TRN_HTML2PDFSetLandscape (TRN_HTML2PDF html2pdf, TRN_Bool enable);
	TRN_API TRN_HTML2PDFSetDPI (TRN_HTML2PDF html2pdf, int dpi);
	TRN_API TRN_HTML2PDFSetOutline (TRN_HTML2PDF html2pdf, TRN_Bool enable, int depth);
	TRN_API TRN_HTML2PDFDumpOutline (TRN_HTML2PDF html2pdf, const TRN_UString xml_file);
	TRN_API TRN_HTML2PDFSetPDFCompression (TRN_HTML2PDF html2pdf, TRN_Bool enable);
	TRN_API TRN_HTML2PDFSetMargins (TRN_HTML2PDF html2pdf, const TRN_UString top, const TRN_UString bottom, const TRN_UString left, const TRN_UString right);
	TRN_API TRN_HTML2PDFSetImageDPI (TRN_HTML2PDF html2pdf, int dpi);
	TRN_API TRN_HTML2PDFSetImageQuality (TRN_HTML2PDF html2pdf, int quality);
	TRN_API TRN_HTML2PDFSetCookieJar (TRN_HTML2PDF html2pdf, const TRN_UString path);
	TRN_API TRN_HTML2PDFSetQuiet (TRN_HTML2PDF html2pdf, TRN_Bool quiet);
	TRN_API TRN_HTML2PDFSetModulePath (const TRN_UString path);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFHTML2PDF
