//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFElementBuilder
#define PDFTRON_H_CPDFElementBuilder

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_ShapedText.h>

TRN_API TRN_ElementBuilderCreate(TRN_ElementBuilder* result);
TRN_API TRN_ElementBuilderDestroy(TRN_ElementBuilder b);

TRN_API TRN_ElementBuilderReset(TRN_ElementBuilder b, TRN_GState gs);

TRN_API TRN_ElementBuilderCreateImage(TRN_ElementBuilder b, TRN_Image img,TRN_Element* result);
TRN_API TRN_ElementBuilderCreateImageFromMatrix(TRN_ElementBuilder b, TRN_Image img, const TRN_Matrix2D* mtx, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateImageScaled(TRN_ElementBuilder b, TRN_Image img, double x, double y, double hscale, double vscale, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateGroupBegin(TRN_ElementBuilder b, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateGroupEnd(TRN_ElementBuilder b, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateShading(TRN_ElementBuilder b, TRN_Shading sh, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateFormFromStream(TRN_ElementBuilder b, TRN_Obj form, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateFormFromPage(TRN_ElementBuilder b, TRN_Page page, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateFormFromDoc(TRN_ElementBuilder b, TRN_Page page, TRN_PDFDoc doc, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateTextBeginWithFont(TRN_ElementBuilder b, TRN_Font font, double font_sz, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateTextBegin(TRN_ElementBuilder b, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateTextEnd(TRN_ElementBuilder b, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateTextRun(TRN_ElementBuilder b, const char* text_data, TRN_Font font, double font_sz, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateTextRunWithSize(TRN_ElementBuilder b, const char* text_data, TRN_UInt32 text_data_sz, TRN_Font font, double font_sz, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateTextRunUnsigned(TRN_ElementBuilder b, TRN_String text_data, TRN_Font font, double font_sz, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateNewTextRun(TRN_ElementBuilder b, const char* text_data, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateNewTextRunWithSize(TRN_ElementBuilder b, const char* text_data, TRN_UInt32 text_data_sz, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateNewTextRunUnsigned(TRN_ElementBuilder b, TRN_String text_data, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateUnicodeTextRun(TRN_ElementBuilder b, const TRN_Unicode* text_data, TRN_UInt32 text_data_sz, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateShapedTextRun(TRN_ElementBuilder b, const TRN_ShapedText text_data, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateTextNewLineWithOffset(TRN_ElementBuilder b, double dx, double dy, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateTextNewLine(TRN_ElementBuilder b, TRN_Element* result);
TRN_API TRN_ElementBuilderCreatePath(TRN_ElementBuilder b, const double* points_list, int points_list_size, const char* buf_seg_types, int buf_seg_types_size, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateRect(TRN_ElementBuilder b, double x, double y, double width, double height, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateEllipse(TRN_ElementBuilder b, double x, double y, double width, double height, TRN_Element* result);

TRN_API TRN_ElementBuilderPathBegin(TRN_ElementBuilder b);
TRN_API TRN_ElementBuilderPathEnd(TRN_ElementBuilder b, TRN_Element* result);
TRN_API TRN_ElementBuilderRect(TRN_ElementBuilder b, double x, double y, double width, double height);
TRN_API TRN_ElementBuilderEllipse(TRN_ElementBuilder b, double x, double y, double width, double height);
TRN_API TRN_ElementBuilderMoveTo(TRN_ElementBuilder b, double x, double y);
TRN_API TRN_ElementBuilderLineTo(TRN_ElementBuilder b, double x, double y);
TRN_API TRN_ElementBuilderCurveTo(TRN_ElementBuilder b, double cx1, double cy1, double cx2, double cy2, double x2, double y2);
TRN_API TRN_ElementBuilderArcTo(TRN_ElementBuilder b, double x, double y, double width, double height, double start, double extent);
TRN_API TRN_ElementBuilderArcTo2(TRN_ElementBuilder b, double xr, double yr, double rx, TRN_Bool isLargeArc, TRN_Bool sweep, double endX, double endY);
TRN_API TRN_ElementBuilderClosePath(TRN_ElementBuilder b);

TRN_API TRN_ElementBuilderCreateMarkedContentBeginInlineProperties(TRN_ElementBuilder b, const char* tag, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateMarkedContentBegin(TRN_ElementBuilder b, const char* tag, TRN_Obj property_dict, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateMarkedContentEnd(TRN_ElementBuilder b, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateMarkedContentPointInlineProperties(TRN_ElementBuilder b, const char* tag, TRN_Element* result);
TRN_API TRN_ElementBuilderCreateMarkedContentPoint(TRN_ElementBuilder b, const char* tag, TRN_Obj property_dict, TRN_Element* result);


#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFElementBuilder
