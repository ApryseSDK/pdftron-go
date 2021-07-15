#ifndef CPPHTML2PDF_INL
#define CPPHTML2PDF_INL

#include <cassert>

namespace pdftron {
	namespace PDF {

		inline Proxy::Proxy() {
			REX(TRN_HTML2PDF_ProxyCreate(&mp_impl));
		}

		inline Proxy::~Proxy() {
			DREX(mp_impl, TRN_HTML2PDF_ProxyDestroy(mp_impl));
		}

		inline void Proxy::Destroy() {
			REX(TRN_HTML2PDF_ProxyDestroy(mp_impl));
			mp_impl=0;
		}

		inline void Proxy::SetType(Type type) {
			REX(TRN_HTML2PDF_ProxySetType(mp_impl, (enum TRN_HTML2PDF_Proxy_Type)type));
		}

		inline void Proxy::SetPort(int port) {
			REX(TRN_HTML2PDF_ProxySetPort(mp_impl, port));
		}

		inline void Proxy::SetHost(const UString& host) {
			REX(TRN_HTML2PDF_ProxySetHost(mp_impl, host.mp_impl));
		}

		inline void Proxy::SetUsername(const UString& username) {
			REX(TRN_HTML2PDF_ProxySetUsername(mp_impl, username.mp_impl));
		}

		inline void Proxy::SetPassword(const UString& password) {
			REX(TRN_HTML2PDF_ProxySetPassword(mp_impl, password.mp_impl));
		}

		inline WebPageSettings::WebPageSettings() {
			REX(TRN_HTML2PDF_WebPageSettingsCreate(&mp_impl));
		}

		inline WebPageSettings::~WebPageSettings() {
			DREX(mp_impl, TRN_HTML2PDF_WebPageSettingsDestroy(mp_impl));
		}

		inline void WebPageSettings::Destroy() {
			REX(TRN_HTML2PDF_WebPageSettingsDestroy(mp_impl));
			mp_impl=0;
		}

		inline void WebPageSettings::SetPrintBackground(bool background) {
			REX(TRN_HTML2PDF_WebPageSettingsSetPrintBackground(mp_impl, BToTB(background)));
		}

		inline void WebPageSettings::SetLoadImages(bool load) {
			REX(TRN_HTML2PDF_WebPageSettingsSetLoadImages(mp_impl, BToTB(load)));
		}

		inline void WebPageSettings::SetAllowJavaScript(bool enable) {
			REX(TRN_HTML2PDF_WebPageSettingsSetAllowJavaScript(mp_impl, BToTB(enable)));
		}

		inline void WebPageSettings::SetSmartShrinking(bool enable) {
			REX(TRN_HTML2PDF_WebPageSettingsSetSmartShrinking(mp_impl, BToTB(enable)));
		}

		inline void WebPageSettings::SetMinimumFontSize(int size) {
			REX(TRN_HTML2PDF_WebPageSettingsSetMinimumFontSize(mp_impl, size));
		}

		inline void WebPageSettings::SetDefaultEncoding(const UString& encoding) {
			REX(TRN_HTML2PDF_WebPageSettingsSetDefaultEncoding(mp_impl, encoding.mp_impl));
		}

		inline void WebPageSettings::SetUserStyleSheet(const UString& url) {
			REX(TRN_HTML2PDF_WebPageSettingsSetUserStyleSheet(mp_impl, url.mp_impl));
		}

		inline void WebPageSettings::SetAllowPlugins(bool enable) {
			REX(TRN_HTML2PDF_WebPageSettingsSetAllowPlugins(mp_impl, BToTB(enable)));
		}

		inline void WebPageSettings::SetPrintMediaType(bool print) {
			REX(TRN_HTML2PDF_WebPageSettingsSetPrintMediaType(mp_impl, BToTB(print)));
		}

		inline void WebPageSettings::SetIncludeInOutline(bool include) {
			REX(TRN_HTML2PDF_WebPageSettingsSetIncludeInOutline(mp_impl, BToTB(include)));
		}

		inline void WebPageSettings::SetUsername(const UString& username) {
			REX(TRN_HTML2PDF_WebPageSettingsSetUsername(mp_impl, username.mp_impl));
		}

		inline void WebPageSettings::SetPassword(const UString& password) {
			REX(TRN_HTML2PDF_WebPageSettingsSetPassword(mp_impl, password.mp_impl));
		}

		inline void WebPageSettings::SetJavaScriptDelay(int msec) {
			REX(TRN_HTML2PDF_WebPageSettingsSetJavaScriptDelay(mp_impl, msec));
		}

		inline void WebPageSettings::SetZoom(double zoom) {
			REX(TRN_HTML2PDF_WebPageSettingsSetZoom(mp_impl, zoom));
		}

		inline void WebPageSettings::SetBlockLocalFileAccess(bool block) {
			REX(TRN_HTML2PDF_WebPageSettingsSetBlockLocalFileAccess(mp_impl, BToTB(block)));
		}

		inline void WebPageSettings::SetStopSlowScripts(bool stop) {
			REX(TRN_HTML2PDF_WebPageSettingsSetStopSlowScripts(mp_impl, BToTB(stop)));
		}

		inline void WebPageSettings::SetDebugJavaScriptOutput(bool forward) {
			REX(TRN_HTML2PDF_WebPageSettingsSetDebugJavaScriptOutput(mp_impl, BToTB(forward)));
		}

		inline void WebPageSettings::SetLoadErrorHandling(ErrorHandling type) {
			REX(TRN_HTML2PDF_WebPageSettingsSetLoadErrorHandling(mp_impl,
				(enum TRN_HTML2PDF_WebPageSettings_ErrorHandling)type));
		}

		inline void WebPageSettings::SetExternalLinks(bool convert) {
			REX(TRN_HTML2PDF_WebPageSettingsSetExternalLinks(mp_impl, BToTB(convert)));
		}

		inline void WebPageSettings::SetInternalLinks(bool convert) {
			REX(TRN_HTML2PDF_WebPageSettingsSetInternalLinks(mp_impl, BToTB(convert)));
		}

		inline void WebPageSettings::SetProduceForms(bool forms) {
			REX(TRN_HTML2PDF_WebPageSettingsSetProduceForms(mp_impl, BToTB(forms)));
		}

		inline void WebPageSettings::SetProxy(const Proxy& proxy) {
			REX(TRN_HTML2PDF_WebPageSettingsSetProxy(mp_impl, proxy.mp_impl));
		}

		inline TOCSettings::TOCSettings() {
			REX(TRN_HTML2PDF_TOCSettingsCreate(&mp_impl));
		}

		inline TOCSettings::~TOCSettings() {
			DREX(mp_impl, TRN_HTML2PDF_TOCSettingsDestroy(mp_impl));
		}

		inline void TOCSettings::Destroy() {
			REX(TRN_HTML2PDF_TOCSettingsDestroy(mp_impl));
			mp_impl = 0;
		}

		inline void TOCSettings::SetDottedLines(bool enable) {
			REX(TRN_HTML2PDF_TOCSettingsSetDottedLines(mp_impl, BToTB(enable)));
		}

		inline void TOCSettings::SetLinks(bool enable) {
			REX(TRN_HTML2PDF_TOCSettingsSetLinks(mp_impl, BToTB(enable)));
		}

		inline void TOCSettings::SetCaptionText(const UString& caption) {
			REX(TRN_HTML2PDF_TOCSettingsSetCaptionText(mp_impl, caption.mp_impl));
		}

		inline void TOCSettings::SetLevelIndentation(int indentation) {
			REX(TRN_HTML2PDF_TOCSettingsSetLevelIndentation(mp_impl, indentation));
		}

		inline void TOCSettings::SetTextSizeShrink(double shrink) {
			REX(TRN_HTML2PDF_TOCSettingsSetTextSizeShrink(mp_impl, shrink));
		}

		inline void TOCSettings::SetXsl(const UString& style_sheet) {
			REX(TRN_HTML2PDF_TOCSettingsSetXsl(mp_impl, style_sheet.mp_impl));
		}

		#ifndef SWIG
		inline bool HTML2PDF::Convert(PDFDoc& doc, const UString& url) {
			TRN_Bool ret;
			REX(TRN_HTML2PDFStaticConvert(doc.mp_doc, url.mp_impl, &ret));
			return TBToB(ret);
		}

		inline bool HTML2PDF::Convert(PDFDoc& doc, const UString& url, const WebPageSettings& settings) {
			TRN_Bool ret;
			REX(TRN_HTML2PDFStaticConvert2(doc.mp_doc, url.mp_impl, settings.mp_impl, &ret));
			return TBToB(ret);
		}
		#endif

		inline void HTML2PDF::InsertFromURL(const UString& url) {
			REX(TRN_HTML2PDFInsertFromUrl(mp_html2pdf, url.mp_impl));
		}

		inline void HTML2PDF::InsertFromURL(const UString& url, const WebPageSettings& settings) {
			REX(TRN_HTML2PDFInsertFromUrl2(mp_html2pdf, url.mp_impl, settings.mp_impl));
		}

		inline void HTML2PDF::InsertFromHtmlString(const UString& html) {
			REX(TRN_HTML2PDFInsertFromHtmlString(mp_html2pdf, html.mp_impl));
		}

		inline void HTML2PDF::InsertFromHtmlString(const UString& html, const WebPageSettings& settings) {
			REX(TRN_HTML2PDFInsertFromHtmlString2(mp_html2pdf, html.mp_impl, settings.mp_impl));
		}

		inline void HTML2PDF::InsertTOC() {
			REX(TRN_HTML2PDFInsertTOC(mp_html2pdf));
		}

		inline void HTML2PDF::InsertTOC(const TOCSettings& settings) {
			REX(TRN_HTML2PDFInsertTOC2(mp_html2pdf, settings.mp_impl));
		}

		inline bool HTML2PDF::Convert(PDFDoc& doc) {
			TRN_Bool ret;
			REX(TRN_HTML2PDFConvert(mp_html2pdf, doc.mp_doc, &ret));
			return TBToB(ret);
		}

		inline int HTML2PDF::GetHTTPErrorCode() const {
			int ret;
			REX(TRN_HTML2PDFGetHttpErrorCode(mp_html2pdf, &ret));
			return ret;
		}

		inline HTML2PDF::HTML2PDF() {
			REX(TRN_HTML2PDFCreate(&mp_html2pdf));
		}

		inline HTML2PDF::~HTML2PDF() {
			DREX(mp_html2pdf, TRN_HTML2PDFDestroy(mp_html2pdf));
		}

		inline void HTML2PDF::Destroy() {
			REX(TRN_HTML2PDFDestroy(mp_html2pdf));
			mp_html2pdf=0;
		}

		inline void HTML2PDF::SetPaperSize(PrinterMode::PaperSize size) {
			REX(TRN_HTML2PDFSetPaperSize(mp_html2pdf, (enum TRN_PrinterModePaperSize)size));
		}

		inline void HTML2PDF::SetPaperSize(const UString& width, const UString& height) {
			REX(TRN_HTML2PDFSetPaperSize2(mp_html2pdf, width.mp_impl, height.mp_impl));
		}

		inline void HTML2PDF::SetLandscape(bool enable) {
			REX(TRN_HTML2PDFSetLandscape(mp_html2pdf, BToTB(enable)));
		}
		
		inline void HTML2PDF::SetDPI(int dpi) {
			REX(TRN_HTML2PDFSetDPI(mp_html2pdf, dpi));
		}

		inline void HTML2PDF::SetOutline(bool enable, int depth) {
			REX(TRN_HTML2PDFSetOutline(mp_html2pdf, BToTB(enable), depth));
		}

		inline void HTML2PDF::DumpOutline(const UString& xml_file) {
			REX(TRN_HTML2PDFDumpOutline(mp_html2pdf, xml_file.mp_impl));
		}

		inline void HTML2PDF::SetPDFCompression(bool enable) {
			REX(TRN_HTML2PDFSetPDFCompression(mp_html2pdf, BToTB(enable)));
		}

		inline void HTML2PDF::SetMargins(const UString& top, const UString& bottom, const UString& left, const UString& right) {
			REX(TRN_HTML2PDFSetMargins(mp_html2pdf, top.mp_impl, bottom.mp_impl, left.mp_impl, right.mp_impl));
		}

		inline void HTML2PDF::SetImageDPI(int dpi) {
			REX(TRN_HTML2PDFSetImageDPI(mp_html2pdf, dpi));
		}

		inline void HTML2PDF::SetImageQuality(int quality) {
			REX(TRN_HTML2PDFSetImageQuality(mp_html2pdf, quality));
		}

		inline void HTML2PDF::SetCookieJar(const UString& path) {
			REX(TRN_HTML2PDFSetCookieJar(mp_html2pdf, path.mp_impl));
		}

		inline void HTML2PDF::SetQuiet(bool quiet) {
			REX(TRN_HTML2PDFSetQuiet(mp_html2pdf, BToTB(quiet)));
		}

		inline UString HTML2PDF::GetLog() const {
			TRN_UString result;
			REX(TRN_HTML2PDFGetLog(mp_html2pdf, &result));
			return UString(result);	
		}

		inline void HTML2PDF::SetModulePath(const UString& path) {
			REX(TRN_HTML2PDFSetModulePath(path.mp_impl));
		}

	}; // namespace PDF
}; // namespace pdftron


#endif // CPPHTML2PDF_INL
