//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFGState
#define PDFTRON_H_CPDFGState

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif


enum TRN_GStateAttribute
{
	e_GState_transform = 0,
	e_GState_rendering_intent,

	e_GState_stroke_cs,
	e_GState_stroke_color,
	e_GState_fill_cs,
	e_GState_fill_color,

	e_GState_line_width,
	e_GState_line_cap,
	e_GState_line_join,
	e_GState_flatness,
	e_GState_miter_limit,
	e_GState_dash_pattern,

	e_GState_char_spacing,
	e_GState_word_spacing,
	e_GState_horizontal_scale,
	e_GState_leading,
	e_GState_font,
	e_GState_font_size,
	e_GState_text_render_mode,
	e_GState_text_rise,
	e_GState_text_knockout,

	e_GState_text_pos_offset,

	e_GState_blend_mode,
	e_GState_opacity_fill,
	e_GState_opacity_stroke,
	e_GState_alpha_is_shape,
	e_GState_soft_mask,
	e_GState_smoothnes,
	e_GState_auto_stoke_adjust,
	e_GState_stroke_overprint,
	e_GState_fill_overprint,
	e_GState_overprint_mode,
	e_GState_transfer_funct,
	e_GState_BG_funct,
	e_GState_UCR_funct,
	e_GState_halftone,
	e_GState_null
};

TRN_API TRN_GStateGetTransform(TRN_GState gs, TRN_Matrix2D* result);

TRN_API TRN_GStateGetStrokeColorSpace(TRN_GState gs, TRN_ColorSpace* result);

TRN_API TRN_GStateGetFillColorSpace(TRN_GState gs, TRN_ColorSpace* result);

TRN_API TRN_GStateGetStrokeColor(TRN_GState gs, TRN_ColorPt* result);

TRN_API TRN_GStateGetStrokePattern(TRN_GState gs, TRN_PatternColor* result);

TRN_API TRN_GStateGetFillColor(TRN_GState gs, TRN_ColorPt* result);

TRN_API TRN_GStateGetFillPattern(TRN_GState gs, TRN_PatternColor* result);

TRN_API TRN_GStateGetFlatness(const TRN_GState gs, double* result);


enum TRN_GStateLineCap
{
	e_GState_butt_cap = 0,
	e_GState_round_cap,
	e_GState_square_cap
};

TRN_API TRN_GStateGetLineCap(const TRN_GState gs, enum TRN_GStateLineCap* result);


enum TRN_GStateLineJoin
{
	e_GState_miter_join = 0,
	e_GState_round_join,
	e_GState_bevel_join
};

TRN_API TRN_GStateGetLineJoin(const TRN_GState gs,enum TRN_GStateLineJoin* result);

TRN_API TRN_GStateGetLineWidth(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetMiterLimit(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetDashes(const TRN_GState gs, double* out_buf_dashes, int* buf_out_dashes_sz);

TRN_API TRN_GStateGetPhase(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetCharSpacing(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetWordSpacing(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetHorizontalScale(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetLeading(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetFont(const TRN_GState gs, TRN_Font* result);

TRN_API TRN_GStateGetFontSize(const TRN_GState gs, double* result);

enum TRN_GStateTextRenderingMode
{
	e_GState_fill_text = 0,
	e_GState_stroke_text,
	e_GState_fill_stroke_text,
	e_GState_invisible_text,
	e_GState_fill_clip_text,
	e_GState_stroke_clip_text,
	e_GState_fill_stroke_clip_text,
	e_GState_clip_text
};

TRN_API TRN_GStateGetTextRenderMode(const TRN_GState gs, enum TRN_GStateTextRenderingMode* result);

TRN_API TRN_GStateGetTextRise(const TRN_GState gs, double* result);

TRN_API TRN_GStateIsTextKnockout(const TRN_GState gs, TRN_Bool* result);

enum TRN_GStateRenderingIntent
{
	e_GState_absolute_colorimetric,
	e_GState_relative_colorimetric,
	e_GState_saturation,
	e_GState_perceptual
};

TRN_API TRN_GStateGetRenderingIntent(const TRN_GState gs, enum TRN_GStateRenderingIntent* result);

TRN_API TRN_GStateGetRenderingIntentType(const char* name, enum TRN_GStateRenderingIntent* result);

enum TRN_GStateBlendMode
{
	e_GState_bl_compatible = 0,
	e_GState_bl_normal,
	e_GState_bl_multiply,
	e_GState_bl_screen,
	e_GState_bl_difference,
	e_GState_bl_darken,
	e_GState_bl_lighten,
	e_GState_bl_color_dodge,
	e_GState_bl_color_burn,
	e_GState_bl_exclusion,
	e_GState_bl_hard_light,
	e_GState_bl_overlay,
	e_GState_bl_soft_light,
	e_GState_bl_luminosity,
	e_GState_bl_hue,
	e_GState_bl_saturation,
	e_GState_bl_color
};

TRN_API TRN_GStateGetBlendMode(TRN_GState gs,enum TRN_GStateBlendMode* result);

TRN_API TRN_GStateGetFillOpacity(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetStrokeOpacity(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetAISFlag(const TRN_GState gs, TRN_Bool* result);

TRN_API TRN_GStateGetSoftMask(TRN_GState gs, TRN_Obj* result);

TRN_API TRN_GStateGetSoftMaskTransform(TRN_GState gs, TRN_Matrix2D* result);

TRN_API TRN_GStateGetStrokeOverprint(const TRN_GState gs, TRN_Bool* result);

TRN_API TRN_GStateGetFillOverprint(const TRN_GState gs, TRN_Bool* result);

TRN_API TRN_GStateGetOverprintMode(const TRN_GState gs, int* result);

TRN_API TRN_GStateGetAutoStrokeAdjust(const TRN_GState gs, TRN_Bool* result);

TRN_API TRN_GStateGetSmoothnessTolerance(const TRN_GState gs, double* result);

TRN_API TRN_GStateGetTransferFunct(TRN_GState gs, TRN_Obj* result);

TRN_API TRN_GStateGetBlackGenFunct(TRN_GState gs, TRN_Obj* result);

TRN_API TRN_GStateGetUCRFunct(TRN_GState gs, TRN_Obj* result);

TRN_API TRN_GStateGetHalftone(TRN_GState gs, TRN_Obj* result);

TRN_API TRN_GStateSetTransformMatrix(TRN_GState gs,const TRN_Matrix2D* mtx);

TRN_API TRN_GStateSetTransform(TRN_GState gs,double a, double b, double c, double d, double h, double v);

TRN_API TRN_GStateConcatMatrix(TRN_GState gs, const TRN_Matrix2D* mtx);
TRN_API TRN_GStateConcat(TRN_GState gs,double a, double b, double c, double d, double h, double v);

TRN_API TRN_GStateSetStrokeColorSpace(TRN_GState gs,TRN_ColorSpace cs);

TRN_API TRN_GStateSetFillColorSpace(TRN_GState gs,TRN_ColorSpace cs);

TRN_API TRN_GStateSetStrokeColorWithColorPt(TRN_GState gs,const TRN_ColorPt* c);

TRN_API TRN_GStateSetStrokeColorWithPattern(TRN_GState gs,TRN_PatternColor pattern);

TRN_API TRN_GStateSetStrokeColor(TRN_GState gs,TRN_PatternColor pattern, const TRN_ColorPt* c);

TRN_API TRN_GStateSetFillColorWithColorPt(TRN_GState gs,const TRN_ColorPt* c);

TRN_API TRN_GStateSetFillColorWithPattern(TRN_GState gs,TRN_PatternColor pattern);

TRN_API TRN_GStateSetFillColor(TRN_GState gs,TRN_PatternColor pattern, const TRN_ColorPt* c);

TRN_API TRN_GStateSetFlatness(TRN_GState gs,double flatness);

TRN_API TRN_GStateSetLineCap(TRN_GState gs,enum TRN_GStateLineCap cap);

TRN_API TRN_GStateSetLineJoin(TRN_GState gs,enum TRN_GStateLineJoin join);

TRN_API TRN_GStateSetLineWidth(TRN_GState gs,double width);

TRN_API TRN_GStateSetMiterLimit(TRN_GState gs,double miter_limit);

TRN_API TRN_GStateSetDashPattern(TRN_GState gs, const double* dash_array, int dash_array_size, double phase);

TRN_API TRN_GStateSetCharSpacing(TRN_GState gs,double char_spacing);

TRN_API TRN_GStateSetWordSpacing(TRN_GState gs,double word_spacing);

TRN_API TRN_GStateSetHorizontalScale(TRN_GState gs,double hscale);

TRN_API TRN_GStateSetLeading(TRN_GState gs,double leading);

TRN_API TRN_GStateSetFont(TRN_GState gs,TRN_Font font, double font_sz);

TRN_API TRN_GStateSetTextRenderMode(TRN_GState gs,enum TRN_GStateTextRenderingMode rmode);

TRN_API TRN_GStateSetTextRise(TRN_GState gs,double rise);

TRN_API TRN_GStateSetTextKnockout(TRN_GState gs,TRN_Bool knockout);

TRN_API TRN_GStateSetRenderingIntent(TRN_GState gs,enum TRN_GStateRenderingIntent intent);

TRN_API TRN_GStateSetBlendMode(TRN_GState gs,enum TRN_GStateBlendMode BM);

TRN_API TRN_GStateSetFillOpacity(TRN_GState gs,double ca);

TRN_API TRN_GStateSetStrokeOpacity(TRN_GState gs,double ca);

TRN_API TRN_GStateSetAISFlag(TRN_GState gs,TRN_Bool AIS);

TRN_API TRN_GStateSetSoftMask(TRN_GState gs,TRN_Obj SM);

TRN_API TRN_GStateSetStrokeOverprint(TRN_GState gs,TRN_Bool OP);

TRN_API TRN_GStateSetFillOverprint(TRN_GState gs,TRN_Bool op);

TRN_API TRN_GStateSetOverprintMode(TRN_GState gs,int OPM);

TRN_API TRN_GStateSetAutoStrokeAdjust(TRN_GState gs,TRN_Bool SA);

TRN_API TRN_GStateSetSmoothnessTolerance(TRN_GState gs,double SM);

TRN_API TRN_GStateSetBlackGenFunct(TRN_GState gs,TRN_Obj BG);

TRN_API TRN_GStateSetUCRFunct(TRN_GState gs,TRN_Obj UCR);

TRN_API TRN_GStateSetTransferFunct(TRN_GState gs,TRN_Obj TR);

TRN_API TRN_GStateSetHalftone(TRN_GState gs,TRN_Obj HT);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFGState
