//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFCONVERT
#define PDFTRON_H_CPDFCONVERT

#ifdef __cplusplus
extern "C" {
#endif

#include <C/PDF/TRN_BlackBoxContext.h>
#include <C/PDF/TRN_Reflow.h>
#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_DocumentConversion.h>

TRN_API TRN_ConvertFromXps (TRN_PDFDoc in_pdfdoc, TRN_UString in_filename );
TRN_API TRN_ConvertFromXpsMem (TRN_PDFDoc in_pdfdoc, const char* buf, size_t buf_sz );

TRN_API TRN_ConvertCreateBlackBoxContext(TRN_UString in_filename, TRN_BlackBoxContext *result);
TRN_API TRN_ConvertCreateReflow(TRN_Page in_page, TRN_UString json_zones, TRN_Reflow* result);

// EMF conversions are only supported on Windows
TRN_API TRN_ConvertFromEmf (TRN_PDFDoc in_pdfdoc, TRN_UString in_filename );
TRN_API TRN_ConvertPageToEmf (TRN_Page in_page, TRN_UString in_filename );
TRN_API TRN_ConvertDocToEmf (TRN_PDFDoc in_pdfdoc, TRN_UString in_filename );

TRN_API TRN_ConvertFromText(TRN_PDFDoc in_pdfdoc, TRN_UString in_filename, TRN_Obj options);

TRN_API TRN_ConvertPageToSvg (TRN_Page in_page, TRN_UString output_filename);
TRN_API TRN_ConvertPageToSvgWithOptions (TRN_Page in_page, TRN_UString output_filename, TRN_Obj options);
TRN_API TRN_ConvertDocToSvg (TRN_PDFDoc in_pdfdoc, TRN_UString in_filename);
TRN_API TRN_ConvertDocToSvgWithOptions (TRN_PDFDoc in_pdfdoc, TRN_UString in_filename, TRN_Obj options);

TRN_API TRN_ConvertToXps (TRN_PDFDoc in_pdfdoc, TRN_UString output_filename, TRN_Obj options);
TRN_API TRN_ConvertFileToXps (TRN_UString in_inputFilename, TRN_UString in_outputFilename, TRN_Obj options);
TRN_API TRN_ConvertFileToXod (TRN_UString in_filename, TRN_UString output_filename, TRN_Obj options);
TRN_API TRN_ConvertToXod (TRN_PDFDoc in_pdfdoc, TRN_UString output_filename, TRN_Obj options);
TRN_API TRN_ConvertFileToXodStream (TRN_UString in_filename, TRN_Obj options, TRN_Filter* result);
TRN_API TRN_ConvertToXodStream (TRN_PDFDoc in_pdfdoc, TRN_Obj options, TRN_Filter* result);

TRN_API TRN_ConvertToXodWithMonitor(TRN_PDFDoc in_pdfdoc, TRN_Obj options, TRN_ConversionMonitor* result);

TRN_API TRN_ConversionMonitorNext(TRN_ConversionMonitor conversionMonitor, TRN_Bool* result);
TRN_API TRN_ConversionMonitorReady(TRN_ConversionMonitor conversionMonitor, TRN_Bool* result);
TRN_API TRN_ConversionMonitorProgress(TRN_ConversionMonitor conversionMonitor, TRN_UInt32* result);
TRN_API TRN_ConversionMonitorFilter(TRN_ConversionMonitor conversionMonitor, TRN_Filter* result);
TRN_API TRN_ConversionMonitorDestroy(TRN_ConversionMonitor conversionMonitor);

TRN_API TRN_ConvertWordToPdf(TRN_PDFDoc in_pdfdoc, TRN_UString in_filename, TRN_Obj options);
TRN_API TRN_ConvertWordToPdfConversion(TRN_PDFDoc* in_pdfdoc, TRN_UString in_filename,  TRN_Obj options, TRN_DocumentConversion* result);
TRN_API TRN_ConvertWordToPdfWithFilter(TRN_PDFDoc in_pdfdoc, TRN_Filter no_own_in_stream, TRN_Obj options);
TRN_API TRN_ConvertWordToPdfConversionWithFilter(TRN_PDFDoc* in_pdfdoc, TRN_Filter in_stream, TRN_Obj options, TRN_DocumentConversion* result);

TRN_API TRN_ConvertOfficeToPdfWithPath(TRN_PDFDoc in_pdfdoc, TRN_UString in_filename, TRN_Obj options);
TRN_API TRN_ConvertStreamingPdfConversionWithPath(TRN_UString in_filename, TRN_Obj options, TRN_DocumentConversion* result);
TRN_API TRN_ConvertStreamingPdfConversionWithPdfAndPath(TRN_PDFDoc* in_pdfdoc, TRN_UString in_filename, TRN_Obj options, TRN_DocumentConversion* result);
TRN_API TRN_ConvertOfficeToPdfWithFilter(TRN_PDFDoc in_pdfdoc, TRN_Filter no_own_in_stream, TRN_Obj options);
TRN_API TRN_ConvertStreamingPdfConversionWithFilter(TRN_Filter in_stream, TRN_Obj options, TRN_DocumentConversion* result);
TRN_API TRN_ConvertStreamingPdfConversionWithPdfAndFilter(TRN_PDFDoc* in_pdfdoc, TRN_Filter in_stream, TRN_Obj options, TRN_DocumentConversion* result);


TRN_API TRN_ConvertToPdf(TRN_PDFDoc in_pdfdoc, TRN_UString in_filename);
TRN_API TRN_ConvertFromCAD(TRN_PDFDoc in_pdfdoc, TRN_UString in_filename, TRN_Obj opts);
TRN_API TRN_ConvertFromDICOM(TRN_PDFDoc in_pdfdoc, TRN_UString in_filename, TRN_Obj opts);
TRN_API TRN_ConvertFromTiff(TRN_PDFDoc in_pdfdoc, TRN_Filter in_data);
TRN_API TRN_ConvertRequiresPrinter (TRN_UString in_filename, TRN_Bool *result );

TRN_API TRN_ConvertPrinterInstall (TRN_UString in_printerName );
TRN_API TRN_ConvertPrinterUninstall ();
TRN_API TRN_ConvertPrinterGetPrinterName (TRN_UString *result);
TRN_API TRN_ConvertPrinterSetPrinterName(TRN_UString in_printerName);
TRN_API TRN_ConvertPrinterIsInstalled (TRN_UString in_printerName, TRN_Bool *result );
enum TRN_ConvertPrinterMode
{
	e_Convert_auto = 0,
	e_Convert_interop_only,
	e_Convert_printer_only,
	e_Convert_prefer_builtin_converter
};
TRN_API TRN_ConvertPrinterSetMode(enum TRN_ConvertPrinterMode print_mode);
TRN_API TRN_ConvertPrinterGetMode(enum TRN_ConvertPrinterMode *result);

TRN_API TRN_ConvertPageToHtml(TRN_Page page, TRN_UString* result);
TRN_API TRN_ConvertPageToHtmlZoned(TRN_Page page, TRN_UString json_zones, TRN_UString* result);
TRN_API TRN_ConvertFileToHtml (TRN_UString in_filename, TRN_UString output_path, TRN_Obj options);
TRN_API TRN_ConvertToHtml (TRN_PDFDoc in_pdfdoc, TRN_UString output_path, TRN_Obj options);
TRN_API TRN_ConvertFileToWord (TRN_UString inputFilename, TRN_UString outputPath, TRN_Obj options);
TRN_API TRN_ConvertToWord (TRN_PDFDoc pdfdoc, TRN_UString outputPath, TRN_Obj options);
TRN_API TRN_ConvertFileToEpub (TRN_UString in_filename, TRN_UString output_path, TRN_Obj html_options, TRN_Obj epub_options);
TRN_API TRN_ConvertToEpub (TRN_PDFDoc in_pdfdoc, TRN_UString output_path, TRN_Obj html_options, TRN_Obj epub_options);

TRN_API TRN_ConvertFileToTiff (TRN_UString in_filename, TRN_UString output_path, TRN_Obj options);
TRN_API TRN_ConvertToTiff (TRN_PDFDoc in_pdfdoc, TRN_UString output_path, TRN_Obj options);
#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFCONVERT
