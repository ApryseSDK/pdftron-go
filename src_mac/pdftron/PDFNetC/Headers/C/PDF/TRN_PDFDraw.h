//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFDraw
#define PDFTRON_H_CPDFPDFDraw

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_PDFRasterizer.h>
#include <C/PDF/TRN_Page.h>
#include <C/PDF/TRN_PDFRasterizer.h>

TRN_API TRN_PDFDrawCreate(double dpi, TRN_PDFDraw* result);
TRN_API TRN_PDFDrawDestroy(TRN_PDFDraw d);
TRN_API TRN_PDFDrawSetRasterizerType (TRN_PDFDraw d, enum TRN_PDFRasterizerType type);
TRN_API TRN_PDFDrawSetDPI(TRN_PDFDraw d, double dpi);
TRN_API TRN_PDFDrawSetImageSize(TRN_PDFDraw d, int width, int height, TRN_Bool preserve_aspect_ratio);
TRN_API TRN_PDFDrawSetPageBox(TRN_PDFDraw d, enum TRN_PageBox region);
TRN_API TRN_PDFDrawSetClipRect(TRN_PDFDraw d, const TRN_Rect* rect);
TRN_API TRN_PDFDrawSetFlipYAxis(TRN_PDFDraw d, TRN_Bool flip_y);
TRN_API TRN_PDFDrawSetRotate(TRN_PDFDraw d, enum TRN_PageRotate angle);
TRN_API TRN_PDFDrawSetDrawAnnotations(TRN_PDFDraw d, TRN_Bool render_annots);
TRN_API TRN_PDFDrawSetHighlightFields(TRN_PDFDraw d, TRN_Bool highlight);
TRN_API TRN_PDFDrawSetAntiAliasing(TRN_PDFDraw d, TRN_Bool enable_aa);
TRN_API TRN_PDFDrawSetPathHinting(TRN_PDFDraw d, TRN_Bool enable_hinting);
TRN_API TRN_PDFDrawSetThinLineAdjustment(TRN_PDFDraw d, TRN_Bool grid_fit, TRN_Bool stroke_adjust);
TRN_API TRN_PDFDrawSetGamma(TRN_PDFDraw d, double exp);
TRN_API TRN_PDFDrawSetOCGContext(TRN_PDFDraw d, TRN_OCGContext ctx);
TRN_API TRN_PDFDrawSetPrintMode(TRN_PDFDraw d, TRN_Bool is_printing);
TRN_API TRN_PDFDrawSetPageTransparent(TRN_PDFDraw d, TRN_Bool is_transparent);
TRN_API TRN_PDFDrawSetDefaultPageColor(TRN_PDFDraw d, TRN_UInt8 r, TRN_UInt8 g, TRN_UInt8 b);
TRN_API TRN_PDFDrawSetOverprint(TRN_PDFDraw d, enum TRN_PDFRasterizerOverprintPreviewMode op);
TRN_API TRN_PDFDrawSetImageSmoothing(TRN_PDFDraw d, TRN_Bool smoothing_enabled, TRN_Bool hq_image_resampling);
TRN_API TRN_PDFDrawSetCaching(TRN_PDFDraw d, TRN_Bool enabled);
TRN_API TRN_PDFDrawExport(TRN_PDFDraw d, TRN_Page page, const TRN_UString filename, const char* format, TRN_Obj encoder_params);
TRN_API TRN_PDFDrawExportStream(TRN_PDFDraw d, TRN_Page page, TRN_Filter stream, const char* format, TRN_Obj encoder_params);
TRN_API TRN_PDFDrawSetColorPostProcessMode(TRN_PDFDraw d, enum TRN_PDFRasterizerColorPostProcessMode mode);
TRN_API TRN_PDFDrawGetSeparationBitmaps(TRN_PDFDraw d, TRN_Page page, TRN_Vector* result);

#if defined(_WIN32) && !defined(__WINRT__)
TRN_API TRN_PDFDrawDrawInRect(TRN_PDFDraw d, TRN_Page page, void* hdc, const TRN_Rect* rect);
#endif

enum TRN_PDFDrawPixelFormat {
	e_PDFDraw_rgba,
	e_PDFDraw_bgra,
	e_PDFDraw_rgb,
	e_PDFDraw_bgr,
	e_PDFDraw_gray,
	e_PDFDraw_gray_alpha,
	e_PDFDraw_cmyk
};


TRN_API TRN_PDFDrawGetBitmap(TRN_PDFDraw d, TRN_Page page, int* out_width, int* out_height, int* out_stride, double* out_dpi,
							 enum TRN_PDFDrawPixelFormat pix_fmt, TRN_Bool demult, const TRN_UChar** result);
TRN_API TRN_PDFDrawSetErrorReportProc(TRN_PDFDraw d, TRN_RasterizerErrorReportProc error_proc, void* data);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFDraw
