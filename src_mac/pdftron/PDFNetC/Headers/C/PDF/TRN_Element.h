//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFElement
#define PDFTRON_H_CPDFElement

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_GState.h>

#ifdef __cplusplus
extern "C" {
#endif

enum TRN_ElementType
{
	e_Element_null,
	e_Element_path,
	e_Element_text_begin,
	e_Element_text,
	e_Element_text_new_line,
	e_Element_text_end,
	e_Element_image,
	e_Element_inline_image,
	e_Element_shading,
	e_Element_form,
	e_Element_group_begin,
	e_Element_group_end,
	e_Element_marked_content_begin,
	e_Element_marked_content_end,
	e_Element_marked_content_point
};

TRN_API TRN_ElementGetType(TRN_Element e, enum TRN_ElementType* result);
TRN_API TRN_ElementGetGState(TRN_Element e, TRN_GState* result);
TRN_API TRN_ElementGetCTM(TRN_Element e, TRN_Matrix2D* result);
TRN_API TRN_ElementGetBBox(TRN_Element e, TRN_Rect* out_bbox, TRN_Bool* result);
TRN_API TRN_ElementGetParentStructElement(TRN_Element e, TRN_SElement* result);
TRN_API TRN_ElementGetStructMCID(TRN_Element e, int* result);
TRN_API TRN_ElementIsOCVisible(TRN_Element e, TRN_Bool* result);
TRN_API TRN_ElementIsClippingPath(TRN_Element e, TRN_Bool* result);
TRN_API TRN_ElementIsStroked(TRN_Element e, TRN_Bool* result);
TRN_API TRN_ElementIsFilled(TRN_Element e, TRN_Bool* result);
TRN_API TRN_ElementIsWindingFill(TRN_Element e, TRN_Bool* result);
TRN_API TRN_ElementIsClipWindingFill(TRN_Element e, TRN_Bool* result);

enum TRN_ElementPathSegmentType
{
	e_Element_moveto = 1,
	e_Element_lineto,
	e_Element_cubicto,
	e_Element_conicto,
	e_Element_rect,
	e_Element_closepath
};

TRN_API TRN_ElementGetPathTypes(TRN_Element e, const char** result);
TRN_API TRN_ElementGetPathTypesCount(TRN_Element e, int* result);
TRN_API TRN_ElementGetPathPoints(TRN_Element e, const double** result);
TRN_API TRN_ElementGetPathPointCount(TRN_Element e, int* result);
TRN_API TRN_ElementSetPathClip(TRN_Element e, TRN_Bool clip);
TRN_API TRN_ElementSetPathStroke(TRN_Element e, TRN_Bool stroke);
TRN_API TRN_ElementSetPathFill(TRN_Element e, TRN_Bool fill);
TRN_API TRN_ElementSetWindingFill(TRN_Element e, TRN_Bool winding_rule);
TRN_API TRN_ElementSetClipWindingFill(TRN_Element e, TRN_Bool winding_rule);
TRN_API TRN_ElementSetPathPoints(TRN_Element e, const double* buf_in_points, int buf_count);
TRN_API TRN_ElementSetPathTypes(TRN_Element e, const char* in_seg_types, int count);
TRN_API TRN_ElementGetXObject(TRN_Element e, TRN_Obj* result);
TRN_API TRN_ElementGetImageData(TRN_Element e, TRN_Filter* no_own_result);
TRN_API TRN_ElementGetImageDataSize(TRN_Element e, int* result);

#ifdef _WIN32
TRN_API TRN_ElementGetBitmap(TRN_Element e, TRN_GDIPlusBitmap* result);
#endif

TRN_API TRN_ElementGetImageColorSpace(TRN_Element e, TRN_ColorSpace* result);
TRN_API TRN_ElementGetImageWidth(TRN_Element e, int* result);
TRN_API TRN_ElementGetImageHeight(TRN_Element e, int* result);
TRN_API TRN_ElementGetDecodeArray(TRN_Element e, TRN_Obj* result);
TRN_API TRN_ElementGetBitsPerComponent(TRN_Element e, int* result);
TRN_API TRN_ElementGetComponentNum(TRN_Element e, int* result);
TRN_API TRN_ElementIsImageMask(TRN_Element e, TRN_Bool* result);
TRN_API TRN_ElementIsImageInterpolate(TRN_Element e, TRN_Bool* result);
TRN_API TRN_ElementGetMask(TRN_Element e, TRN_Obj* result);
TRN_API TRN_ElementGetImageRenderingIntent(TRN_Element e, enum TRN_GStateRenderingIntent* result);
TRN_API TRN_ElementGetTextString(TRN_Element e, TRN_UString* result);
TRN_API TRN_ElementGetTextData(TRN_Element e,  const TRN_UChar** result);
TRN_API TRN_ElementGetTextDataSize(TRN_Element e, TRN_UInt32* result);
TRN_API TRN_ElementGetTextMatrix(TRN_Element e, TRN_Matrix2D* result);
TRN_API TRN_ElementGetCharIterator(TRN_Element e, TRN_Iterator* result);
TRN_API TRN_ElementGetTextLength(TRN_Element e, double* result);
TRN_API TRN_ElementGetPosAdjustment(TRN_Element e, double* result);
TRN_API TRN_ElementGetNewTextLineOffset(TRN_Element e, double* out_x, double* out_y);
TRN_API TRN_ElementHasTextMatrix(TRN_Element e, TRN_Bool* result);
TRN_API TRN_ElementSetTextData(TRN_Element e, const TRN_UChar* buf_text_data, int buf_text_data_size);
TRN_API TRN_ElementSetTextMatrix(TRN_Element e, const TRN_Matrix2D* mtx);
TRN_API TRN_ElementSetTextMatrixEntries(TRN_Element e, double a, double b, double c, double d, double h, double v);
TRN_API TRN_ElementSetPosAdjustment(TRN_Element e, double adjust);
TRN_API TRN_ElementUpdateTextMetrics(TRN_Element e);
TRN_API TRN_ElementSetNewTextLineOffset(TRN_Element e, double dx, double dy);
TRN_API TRN_ElementGetShading(TRN_Element e, TRN_Shading* result);
TRN_API TRN_ElementGetMCPropertyDict(TRN_Element e, TRN_Obj* result);
TRN_API TRN_ElementGetMCTag(TRN_Element e, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFElement
