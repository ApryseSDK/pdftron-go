//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFShading
#define PDFTRON_H_CPDFShading

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>


TRN_API TRN_ShadingCreate(TRN_Obj shading_dict, TRN_Shading* result);

TRN_API TRN_ShadingAssign(TRN_Shading left, TRN_Shading right);

TRN_API TRN_ShadingDestroy(TRN_Shading s);

enum TRN_ShadingType
{
	e_Shading_function_shading,
	e_Shading_axial_shading,
	e_Shading_radial_shading,
	e_Shading_free_gouraud_shading,
	e_Shading_lattice_gouraud_shading,
	e_Shading_coons_shading,
	e_Shading_tensor_shading,
	e_Shading_null
};

TRN_API TRN_ShadingGetTypeFromObj(TRN_Obj shading_dict, enum TRN_ShadingType* result);

TRN_API TRN_ShadingGetType(const TRN_Shading s,enum TRN_ShadingType* result);

TRN_API TRN_ShadingGetSDFObj (TRN_Shading s, TRN_Obj* result);

TRN_API TRN_ShadingGetBaseColorSpace(TRN_Shading s, TRN_ColorSpace* result);

TRN_API TRN_ShadingHasBBox(TRN_Shading s, TRN_Bool* result);

TRN_API TRN_ShadingGetBBox(TRN_Shading s, TRN_Rect* result);

TRN_API TRN_ShadingHasBackground(TRN_Shading s, TRN_Bool* result);

TRN_API TRN_ShadingGetBackground(TRN_Shading s, TRN_ColorPt* result);

TRN_API TRN_ShadingGetAntialias(TRN_Shading s, TRN_Bool* result);

TRN_API TRN_ShadingGetParamStart(TRN_Shading s, double* result);

TRN_API TRN_ShadingGetParamEnd(TRN_Shading s, double* result);

TRN_API TRN_ShadingIsExtendStart(TRN_Shading s, TRN_Bool* result);

TRN_API TRN_ShadingIsExtendEnd(TRN_Shading s, TRN_Bool* result);

TRN_API TRN_ShadingGetColor(TRN_Shading s, double t, TRN_ColorPt* out_color);

TRN_API TRN_ShadingGetCoords(TRN_Shading s, double* out_x0, double* out_y0, double* out_x1, double* out_y1);

TRN_API TRN_ShadingGetCoordsRadial(TRN_Shading s, double* out_x0, double* out_y0, double* out_r0,
	double* out_x1, double* out_y1, double* out_r1);

TRN_API TRN_ShadingGetDomain(TRN_Shading s, double* out_xmin, double* out_xmax, double* out_ymin, double* out_ymax);

TRN_API TRN_ShadingGetMatrix(TRN_Shading s, TRN_Matrix2D* result);

TRN_API TRN_ShadingGetColorForFunction(TRN_Shading s, double t1, double t2, TRN_ColorPt* out_color);

//TRN_API GouraudMesh TRN_ShadingGetGouraudMesh(TRN_Shading s, );

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFShading
