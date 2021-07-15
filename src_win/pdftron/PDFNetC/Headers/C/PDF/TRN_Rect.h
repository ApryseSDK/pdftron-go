//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFRect
#define PDFTRON_H_CPDFRect

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif


TRN_API TRN_RectInit (double x1, double y1, double x2, double y2, TRN_Rect* result);
TRN_API TRN_RectAssign (TRN_Rect* left, const TRN_Rect* right);
TRN_API TRN_RectAttach(TRN_Rect* rect, TRN_Obj obj);
TRN_API TRN_RectUpdate(TRN_Rect* rect, TRN_Obj obj, TRN_Bool* result);
TRN_API TRN_RectGet(const TRN_Rect* rect, double* out_x1, double* out_y1, double* out_x2, double* out_y2);
TRN_API TRN_RectSet(TRN_Rect* rect, double x1, double y1, double x2, double y2);
TRN_API_T(double) TRN_RectGetX1(const TRN_Rect* rect);
TRN_API_T(double) TRN_RectGetY1(const TRN_Rect* rect);
TRN_API_T(double) TRN_RectGetX2(const TRN_Rect* rect);
TRN_API_T(double) TRN_RectGetY2(const TRN_Rect* rect);
TRN_API_T(void) TRN_RectSetX1(TRN_Rect* rect, double x1);
TRN_API_T(void) TRN_RectSetY1(TRN_Rect* rect, double y1);
TRN_API_T(void) TRN_RectSetX2(TRN_Rect* rect, double x2);
TRN_API_T(void) TRN_RectSetY2(TRN_Rect* rect, double y2);
TRN_API TRN_RectWidth(const TRN_Rect* rect,double* result);
TRN_API TRN_RectHeight(const TRN_Rect* rect,double* result);
TRN_API TRN_RectContains(const TRN_Rect* rect, double x, double y, TRN_Bool* result);
TRN_API TRN_RectIntersectRect(TRN_Rect* rect, const TRN_Rect* rect1, const TRN_Rect* rect2, TRN_Bool* result);
TRN_API TRN_RectNormalize(TRN_Rect* rect);
TRN_API TRN_RectInflate1(TRN_Rect* rect, double amount);
TRN_API TRN_RectInflate2(TRN_Rect* rect, double x, double y);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFRect
