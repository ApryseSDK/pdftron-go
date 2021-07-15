//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#if defined(_WIN32) && !defined(__WINRT__) && !defined(PDFNET_LEAN)

#ifndef PDFTRON_H_CPDFPDFDC
#define PDFTRON_H_CPDFPDFDC

#include <C/Common/TRN_Types.h>
#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

TRN_API TRN_PDFDcCreate (TRN_PDFDC *result);
TRN_API TRN_PDFDcBegin (TRN_PDFDC this_pdfdc, TRN_Page in_pdfpage, const TRN_Rect in_bbox, TRN_Bool in_preserveAspectRatio, HDC *result );
TRN_API TRN_PDFDcEnd (TRN_PDFDC this_pdfdc);
TRN_API TRN_PDFDcSetDPI(TRN_PDFDC this_pdfdc, const TRN_UInt32 in_dpi);
TRN_API TRN_PDFDcDestroy(TRN_PDFDC this_pdfdc);



#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFDC

#endif // defined(_WIN32) && !defined(__WINRT__) && !defined(PDFNET_LEAN)
