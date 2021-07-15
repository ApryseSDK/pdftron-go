//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFStamper
#define PDFTRON_H_CPDFStamper

#define StampCCast (Stamper*)

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_Stamper.h>

#ifdef __cplusplus
extern "C" {
#endif

enum TRN_StamperSizeType
{
	e_Stamper_relative_scale = 1,
	e_Stamper_absolute_size = 2,
	e_Stamper_font_size = 3
};

enum TRN_StamperTextAlignment
{
	e_Stamper_align_left = -1,
	e_Stamper_align_center = 0,
	e_Stamper_align_right = 1
};
enum TRN_StamperHorizontalAlignment
{
	e_Stamper_horizontal_left = -1,
	e_Stamper_horizontal_center = 0,
	e_Stamper_horizontal_right = 1
};

enum TRN_StamperVerticalAlignment
{
	e_Stamper_vertical_bottom = -1,
	e_Stamper_vertical_center = 0,
	e_Stamper_vertical_top = 1
};

//Constructor and destructor
TRN_API TRN_StamperCreate(enum TRN_StamperSizeType size_type, double a, double b, TRN_Stamper* result);

TRN_API TRN_StamperDestroy(TRN_Stamper stamp);

//Stamps
TRN_API TRN_StamperStampImage(TRN_Stamper stamp, TRN_PDFDoc dest_doc, TRN_Image img, TRN_PageSet dest_pages);

TRN_API TRN_StamperStampPage(TRN_Stamper stamp, TRN_PDFDoc dest_doc, TRN_Page page, TRN_PageSet dest_pages);

TRN_API TRN_StamperStampText(TRN_Stamper stamp, TRN_PDFDoc dest_doc, TRN_UString txt, TRN_PageSet dest_pages);


//Text-only methods
TRN_API TRN_StamperSetFont(TRN_Stamper stamp, TRN_Font font);

TRN_API TRN_StamperSetFontColor(TRN_Stamper stamp, const TRN_ColorPt* font_color);

TRN_API TRN_StamperSetTextAlignment(TRN_Stamper stamp, enum TRN_StamperTextAlignment text_alignment);

//Appearance
TRN_API TRN_StamperSetOpacity(TRN_Stamper stamp, double opacity);

TRN_API TRN_StamperSetRotation(TRN_Stamper stamp, double rotation);

TRN_API TRN_StamperSetAsBackground(TRN_Stamper stamp, TRN_Bool background);

TRN_API TRN_StamperSetAsAnnotation(TRN_Stamper stamp, TRN_Bool annotation);

TRN_API TRN_StamperShowsOnScreen(TRN_Stamper stamp, TRN_Bool on_screen);

TRN_API TRN_StamperShowsOnPrint(TRN_Stamper stamp, TRN_Bool on_print);

//Position
TRN_API TRN_StamperSetAlignment(TRN_Stamper stamp, enum TRN_StamperHorizontalAlignment horizontal_alignment, enum TRN_StamperVerticalAlignment vertical_alignment);

TRN_API TRN_StamperSetPosition(TRN_Stamper stamp, double horizontal_distance, double vertical_distance, TRN_Bool use_percentage);

//Size
TRN_API TRN_StamperSetSize(TRN_Stamper stamp, enum TRN_StamperSizeType size_type, double a, double b);

//Static Methods
TRN_API TRN_StamperDeleteStamps(TRN_PDFDoc doc, TRN_PageSet page_set);

TRN_API TRN_StamperHasStamps(TRN_PDFDoc doc, TRN_PageSet page_set, TRN_Bool* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFStamper
