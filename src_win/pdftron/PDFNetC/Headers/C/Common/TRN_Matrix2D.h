//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonMatrix2D
#define PDFTRON_H_CCommonMatrix2D

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif 

TRN_API	TRN_Matrix2DCopy(const TRN_Matrix2D* m, TRN_Matrix2D* result);
TRN_API	TRN_Matrix2DSet (TRN_Matrix2D* matrix, double a, double b, double c, double d, double h, double v);
TRN_API	TRN_Matrix2DConcat(TRN_Matrix2D* matrix, double a, double b, double c, double d, double h, double v);
TRN_API	TRN_Matrix2DEquals(const TRN_Matrix2D* m1, const TRN_Matrix2D* m2, TRN_Bool* result);
TRN_API	TRN_Matrix2DMult(const TRN_Matrix2D* matrix, double* in_out_x, double* in_out_y);
TRN_API	TRN_Matrix2DInverse (const TRN_Matrix2D* matrix, TRN_Matrix2D* result);
TRN_API	TRN_Matrix2DTranslate (TRN_Matrix2D* matrix, double h, double v);
TRN_API	TRN_Matrix2DPreTranslate(TRN_Matrix2D* matrix, double h, double v);
TRN_API	TRN_Matrix2DPostTranslate(TRN_Matrix2D* matrix, double h, double v);
TRN_API	TRN_Matrix2DScale (TRN_Matrix2D* matrix, double h, double v);
TRN_API	TRN_Matrix2DCreateZeroMatrix (TRN_Matrix2D* result);
TRN_API	TRN_Matrix2DCreateIdentityMatrix (TRN_Matrix2D* result);
TRN_API	TRN_Matrix2DCreateRotationMatrix(const double angle, TRN_Matrix2D* result);
TRN_API	TRN_Matrix2DMultiply(TRN_Matrix2D* matrix, const TRN_Matrix2D* m);

#ifdef __cplusplus
}
#endif 

#endif // PDFTRON_H_CCommonMatrix2D
