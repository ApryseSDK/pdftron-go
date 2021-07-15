//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFColorSpace
#define PDFTRON_H_CPDFColorSpace

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>


TRN_API TRN_ColorPtInit(double x, double y, double z, double w, TRN_ColorPt* result);

TRN_API TRN_ColorPtAssign(TRN_ColorPt* left, const TRN_ColorPt* right);
TRN_API TRN_ColorPtCompare(const TRN_ColorPt* left, const TRN_ColorPt* right, TRN_Bool* result);

TRN_API TRN_ColorPtDestroy(TRN_ColorPt* cp);

TRN_API TRN_ColorPtSet(TRN_ColorPt* cp, double x, double y, double z, double w);
TRN_API TRN_ColorPtSetByIndex(TRN_ColorPt* cp, int colorant_index, double colorant_value);
TRN_API TRN_ColorPtGet( const TRN_ColorPt* cp, int colorant_index, double* result);
TRN_API TRN_ColorPtSetColorantNum(TRN_ColorPt* cp, int num);

// for xamarin use only
TRN_API TRN_ColorPtCreate(TRN_ColorPt** result);
TRN_API TRN_ColorPtDestroy2(TRN_ColorPt* cp);
// end for xamarin use only

enum TRN_ColorSpaceType
{
	e_ColorSpace_device_gray,
	e_ColorSpace_device_rgb,
	e_ColorSpace_device_cmyk,
	e_ColorSpace_cal_gray,
	e_ColorSpace_cal_rgb,
	e_ColorSpace_lab,
	e_ColorSpace_icc,
	e_ColorSpace_indexed,
	e_ColorSpace_pattern,
	e_ColorSpace_separation,
	e_ColorSpace_device_n,
	e_ColorSpace_null
};


TRN_API TRN_ColorSpaceCreateDeviceGray(TRN_ColorSpace* result);

TRN_API TRN_ColorSpaceCreateDeviceRGB(TRN_ColorSpace* result);

TRN_API TRN_ColorSpaceCreateDeviceCMYK(TRN_ColorSpace* result);

TRN_API TRN_ColorSpaceCreatePattern(TRN_ColorSpace* result);

TRN_API TRN_ColorSpaceCreate (TRN_Obj color_space, TRN_ColorSpace* result);

TRN_API TRN_ColorSpaceCreateICCFromFile( TRN_SDFDoc doc, const TRN_UString filepath, TRN_ColorSpace* result );

TRN_API TRN_ColorSpaceCreateICCFromFilter(TRN_SDFDoc doc, TRN_Filter no_own_filter, TRN_ColorSpace* result);

TRN_API TRN_ColorSpaceCreateICCFromBuffer( TRN_SDFDoc doc, const TRN_UChar* buf, const TRN_UInt32 buf_sz, TRN_ColorSpace* result );

TRN_API TRN_ColorSpaceAssign(TRN_ColorSpace left, TRN_ColorSpace right);

TRN_API TRN_ColorSpaceDestroy(TRN_ColorSpace cs);

TRN_API TRN_ColorSpaceGetComponentNumFromObj(enum TRN_ColorSpaceType cs_type, TRN_Obj cs_obj, int* result);

TRN_API TRN_ColorSpaceGetTypeFromObj(TRN_Obj cs_obj, enum TRN_ColorSpaceType* result);

TRN_API TRN_ColorSpaceGetType(const TRN_ColorSpace cs, enum TRN_ColorSpaceType* result);

TRN_API TRN_ColorSpaceGetSDFObj (TRN_ColorSpace cs, TRN_Obj* result);

TRN_API TRN_ColorSpaceGetComponentNum(TRN_ColorSpace cs, int* result);

TRN_API TRN_ColorSpaceInitColor(TRN_ColorSpace cs, TRN_ColorPt* out_colorants);

TRN_API TRN_ColorSpaceInitComponentRanges(TRN_ColorSpace cs,
										  double* out_decode_low,
										  double* out_decode_range, int num_comps);

TRN_API TRN_ColorSpaceConvert2Gray(TRN_ColorSpace cs, const TRN_ColorPt* in_color, TRN_ColorPt* out_color);

TRN_API TRN_ColorSpaceConvert2RGB(TRN_ColorSpace cs, const TRN_ColorPt* in_color, TRN_ColorPt* out_color);

TRN_API TRN_ColorSpaceConvert2CMYK(TRN_ColorSpace cs, const TRN_ColorPt* in_color, TRN_ColorPt* out_color);

TRN_API TRN_ColorSpaceGetAlternateColorSpace(TRN_ColorSpace cs, TRN_ColorSpace* result);

TRN_API TRN_ColorSpaceGetBaseColorSpace(TRN_ColorSpace cs, TRN_ColorSpace* result);

TRN_API TRN_ColorSpaceGetHighVal(TRN_ColorSpace cs, int* result);

TRN_API TRN_ColorSpaceGetLookupTable(TRN_ColorSpace cs, const TRN_UChar** result);

TRN_API TRN_ColorSpaceGetBaseColor(TRN_ColorSpace cs, TRN_UChar color_idx, TRN_ColorPt* out_color);

TRN_API TRN_ColorSpaceGetTintFunction(TRN_ColorSpace cs, TRN_Function* result);

TRN_API TRN_ColorSpaceIsAll(TRN_ColorSpace cs, TRN_Bool* result);

TRN_API TRN_ColorSpaceIsNone(TRN_ColorSpace cs, TRN_Bool* result);


#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFColorSpace
