//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFImage
#define PDFTRON_H_CPDFImage

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_GState.h>

#ifdef __cplusplus
extern "C" {
#endif

TRN_API TRN_ImageCreateFromFile(TRN_SDFDoc doc, const TRN_UString filename, TRN_Obj encoder_hints, TRN_Image* result);

TRN_API TRN_ImageCreateFromMemory(TRN_SDFDoc doc,
	const unsigned char* buf,
	TRN_Size buf_size,
	int width,
	int height,
	int bpc,
	TRN_ColorSpace color_space,
	TRN_Obj encoder_hints, TRN_Image* result);

TRN_API TRN_ImageCreateFromMemory2(TRN_SDFDoc doc,
	const unsigned char* buf,
	TRN_Size buf_size,
	TRN_Obj encoder_hints, TRN_Image* result);

TRN_API TRN_ImageCreateFromStream(TRN_SDFDoc doc,
	TRN_FilterReader image_data,
	int width,
	int height,
	int bpc,
	TRN_ColorSpace color_space,
	TRN_Obj encoder_hints, TRN_Image* result);

TRN_API TRN_ImageCreateFromStream2(TRN_SDFDoc doc,
	TRN_Filter no_own_image_data,
	TRN_Obj encoder_hints, TRN_Image* result);

#ifdef _WIN32
TRN_API TRN_ImageCreateFromBitmap(TRN_SDFDoc doc, TRN_GDIPlusBitmap bmp, TRN_Obj encoder_hints, TRN_Image* result);
#endif

TRN_API TRN_ImageCreateImageMask(TRN_SDFDoc doc,
	const char* buf,
	TRN_Size buf_size,
	int width,
	int height,
	TRN_Obj encoder_hints, TRN_Image* result);

TRN_API TRN_ImageCreateImageMaskFromStream(TRN_SDFDoc doc,
	TRN_FilterReader image_data,
	int width,
	int height,
	TRN_Obj encoder_hints, TRN_Image* result);

TRN_API TRN_ImageCreateSoftMask(TRN_SDFDoc doc,
	const char* buf,
	TRN_Size buf_size,
	int width,
	int height,
	int bpc,
	TRN_Obj encoder_hints, TRN_Image* result);

TRN_API TRN_ImageCreateSoftMaskFromStream(TRN_SDFDoc doc,
	TRN_FilterReader image_data,
	int width,
	int height,
	int bpc,
	TRN_Obj encoder_hints, TRN_Image* result);

enum TRN_ImageInputFilter
{
	e_Image_none,
	e_Image_jpeg,
	e_Image_jp2,
	e_Image_flate,
	e_Image_g3,
	e_Image_g4,
	e_Image_ascii_hex
};

TRN_API TRN_ImageCreateDirectFromMemory(TRN_SDFDoc doc,
	const char* buf,
	TRN_Size buf_size,
	int width,
	int height,
	int bpc,
	TRN_ColorSpace color_space,
	enum TRN_ImageInputFilter input_format, TRN_Image* result);



TRN_API TRN_ImageCreateDirectFromStream(TRN_SDFDoc doc,
	TRN_FilterReader image_data,
	int width,
	int height,
	int bpc,
	TRN_ColorSpace color_space,
	enum TRN_ImageInputFilter input_format, TRN_Image* result);

TRN_API TRN_ImageCreateFromObj(TRN_Obj image_xobject, TRN_Image* result);

TRN_API TRN_ImageCopy(const TRN_Image c, TRN_Image* result);

TRN_API TRN_ImageGetSDFObj (TRN_Image img, TRN_Obj* result);

TRN_API TRN_ImageIsValid(const TRN_Image img, TRN_Bool* result);

TRN_API TRN_ImageGetImageData(TRN_Image img, TRN_Filter* no_own_result);

TRN_API TRN_ImageGetImageDataSize(TRN_Image img, int* result);

#ifdef _WIN32
TRN_API TRN_ImageGetBitmap(TRN_Image img, TRN_GDIPlusBitmap* result);
#endif

TRN_API TRN_ImageGetImageColorSpace(TRN_Image img, TRN_ColorSpace* result);

TRN_API TRN_ImageGetImageWidth(TRN_Image img, int* result);

TRN_API TRN_ImageGetImageHeight(TRN_Image img, int* result);

TRN_API TRN_ImageGetDecodeArray(TRN_Image img, TRN_Obj* result);

TRN_API TRN_ImageGetBitsPerComponent(TRN_Image img, int* result);

TRN_API TRN_ImageGetComponentNum(TRN_Image img, int* result);

TRN_API TRN_ImageIsImageMask(TRN_Image img, TRN_Bool* result);

TRN_API TRN_ImageIsImageInterpolate(TRN_Image img, TRN_Bool* result);

TRN_API TRN_ImageGetMask(TRN_Image img, TRN_Obj* result);

TRN_API TRN_ImageSetMask(TRN_Image img, TRN_Image image_mask);

TRN_API TRN_ImageSetMaskWithObj(TRN_Image img, TRN_Obj mask);

TRN_API TRN_ImageGetSoftMask(TRN_Image img, TRN_Obj* result);

TRN_API TRN_ImageSetSoftMask(TRN_Image img, TRN_Image soft_mask);

TRN_API TRN_ImageGetImageRenderingIntent(TRN_Image img, enum TRN_GStateRenderingIntent* result);

TRN_API TRN_ImageExport(TRN_Image img, const TRN_UString filename, int* result);

TRN_API TRN_ImageExportFromStream(TRN_Image img, TRN_FilterWriter writer, int* result);

TRN_API TRN_ImageExportAsTiff(TRN_Image img, const TRN_UString filename);

TRN_API TRN_ImageExportAsTiffFromStream(TRN_Image img, TRN_FilterWriter writer);

TRN_API TRN_ImageExportAsPng(TRN_Image img, const TRN_UString filename);

	TRN_API TRN_ImageExportAsPngFromStream(TRN_Image img, TRN_FilterWriter writer);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFImage
