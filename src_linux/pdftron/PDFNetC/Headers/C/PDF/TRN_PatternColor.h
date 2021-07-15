//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPatternColor
#define PDFTRON_H_CPDFPatternColor

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>


	TRN_API TRN_PatternColorCreate (TRN_Obj pattern, TRN_PatternColor* result);

	TRN_API TRN_PatternColorDestroy(TRN_PatternColor pattern);

	TRN_API TRN_PatternColorAssign(TRN_PatternColor left, TRN_PatternColor right);

	enum TRN_PatternColorType
	{
		e_PatternColor_uncolored_tiling_pattern,
		e_PatternColor_colored_tiling_pattern,
		e_PatternColor_shading,
		e_PatternColor_null
	};

	TRN_API TRN_PatternColorGetTypeFromObj(TRN_Obj pattern,enum TRN_PatternColorType* result);

	TRN_API TRN_PatternColorGetType(const TRN_PatternColor pc,enum TRN_PatternColorType* result);

	TRN_API TRN_PatternColorGetSDFObj (TRN_PatternColor pc,TRN_Obj* result);

	TRN_API TRN_PatternColorGetMatrix(TRN_PatternColor pc, TRN_Matrix2D* result);

	TRN_API TRN_PatternColorGetShading(TRN_PatternColor pc, TRN_Shading* result);

	enum TRN_PatternColorTilingType
	{
		e_PatternColor_constant_spacing,
		e_PatternColor_no_distortion,
		e_PatternColor_constant_spacing_fast_fill
	};

	TRN_API TRN_PatternColorGetTilingType(const TRN_PatternColor pc,enum TRN_PatternColorTilingType* result);

	TRN_API TRN_PatternColorGetBBox(TRN_PatternColor pc, TRN_Rect* result);

	TRN_API TRN_PatternColorGetXStep(TRN_PatternColor pc, double* result);

	TRN_API TRN_PatternColorGetYStep(TRN_PatternColor pc, double* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPatternColor
