//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFFont
#define PDFTRON_H_CPDFFont

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/PDF/TRN_ShapedText.h>


enum TRN_FontStandardType1Font
{
	e_Font_times_roman = 0,
	e_Font_times_bold,
	e_Font_times_italic,
	e_Font_times_bold_italic,
	e_Font_helvetica,
	e_Font_helvetica_bold,
	e_Font_helvetica_oblique,
	e_Font_helvetica_bold_oblique,
	e_Font_courier,
	e_Font_courier_bold,
	e_Font_courier_oblique,
	e_Font_courier_bold_oblique,
	e_Font_symbol,
	e_Font_zapf_dingbats,
	e_Font_null
};

enum TRN_FontEncoding
{
	e_Font_IdentityH = 0,
	e_Font_Indices
};

TRN_API TRN_FontCreateFromObj(TRN_Obj font_dict,TRN_Font* result);
TRN_API TRN_FontCreate(TRN_SDFDoc doc , enum TRN_FontStandardType1Font type, TRN_Font* result);
TRN_API TRN_FontCreateFromFontDescriptor(TRN_SDFDoc doc , TRN_Font from, const TRN_UString char_set, TRN_Font* result);
TRN_API TRN_FontCreateFromName(TRN_SDFDoc doc, const char* name, const TRN_UString char_set, TRN_Font* result);
TRN_API TRN_FontCreateAndEmbed(TRN_SDFDoc doc , enum TRN_FontStandardType1Font type, TRN_Font* result);
TRN_API TRN_FontCreateTrueTypeFont(TRN_SDFDoc doc , TRN_UString font_path,
								   TRN_Bool embed, TRN_Bool subset, TRN_Font* result);

#ifdef _WIN32
TRN_API TRN_FontCreateTrueTypeFont2(TRN_SDFDoc doc , const void* type,
									TRN_Bool embed, TRN_Bool subset,TRN_Font* result);
#endif


TRN_API TRN_FontCreateCIDTrueTypeFont(TRN_SDFDoc doc , TRN_UString font_path,
									  TRN_Bool embed, TRN_Bool subset, enum TRN_FontEncoding encoding,
									  TRN_UInt32 ttc_font_index, TRN_Font* result);

#ifdef _WIN32
TRN_API TRN_FontCreateCIDTrueTypeFont2(TRN_SDFDoc doc , const void* logfonta,
									   TRN_Bool embed, TRN_Bool subset, enum TRN_FontEncoding encoding, TRN_Font* result);
TRN_API TRN_FontCreateCIDTrueTypeFont2Unicode(TRN_SDFDoc doc, const void* logfontw,
									   TRN_Bool embed, TRN_Bool subset, enum TRN_FontEncoding encoding, TRN_Font* result);
#endif



TRN_API TRN_FontCreateType1Font(TRN_SDFDoc doc, TRN_UString font_path,
								TRN_Bool embed, TRN_Font* result);

TRN_API TRN_FontAssign(TRN_Font left, TRN_Font right);
TRN_API TRN_FontDestroy(TRN_Font font);

enum TRN_FontType
{
	e_Font_Type1,
	e_Font_TrueType,
	e_Font_MMType1,
	e_Font_Type3,
	e_Font_Type0,
	e_Font_CIDType0,
	e_Font_CIDType2,
};

TRN_API TRN_FontGetType(TRN_Font font, enum TRN_FontType* result);
TRN_API TRN_FontIsSimple(TRN_Font font, TRN_Bool* result);
TRN_API TRN_FontGetTypeFromObj(TRN_Obj font_dict, enum TRN_FontType* result);
TRN_API TRN_FontGetSDFObj(TRN_Font font, TRN_Obj* result);
TRN_API TRN_FontGetDescriptor(TRN_Font font, TRN_Obj* result);
TRN_API TRN_FontGetName(TRN_Font font, const char**  result);
TRN_API TRN_FontGetFamilyName(TRN_Font font,const char** result);
TRN_API TRN_FontIsFixedWidth(TRN_Font font, TRN_Bool* result);
TRN_API TRN_FontIsSerif(TRN_Font font,TRN_Bool* result);
TRN_API TRN_FontIsSymbolic(TRN_Font font,TRN_Bool* result);
TRN_API TRN_FontIsItalic(TRN_Font font, TRN_Bool* result);
TRN_API TRN_FontIsAllCap(TRN_Font font, TRN_Bool* result);
TRN_API TRN_FontIsForceBold(TRN_Font font, TRN_Bool* result);
TRN_API TRN_FontIsHorizontalMode(TRN_Font font, TRN_Bool* result);
TRN_API TRN_FontGetWidth(TRN_Font font, TRN_UInt32 char_code,double* result);
TRN_API TRN_FontGetMaxWidth(TRN_Font font, double* result);
TRN_API TRN_FontGetMissingWidth(TRN_Font font, double* result);
TRN_API TRN_FontGetCharCodeIterator(TRN_Font font,TRN_Iterator* result);

TRN_API TRN_FontGetGlyphPath(TRN_Font font, TRN_UInt32 char_code,
							 TRN_UChar* buf_oprs, int* out_buf_oprs_sz,
							 double* buf_data, int* out_buf_data_sz,
							 int* out_glyph_indesx,
							 TRN_Bool conics2cubics,
							 TRN_Matrix2D* transform, TRN_Bool* result);

TRN_API TRN_FontGetShapedText(TRN_Font font, const TRN_UString text_to_shape, TRN_ShapedText* result);
TRN_API TRN_FontMapToUnicode(TRN_Font font, TRN_UInt32 char_code,
							 TRN_Unicode* out_uni_arr, const int in_uni_sz,
							 int* out_chars, TRN_Bool* result);

TRN_API TRN_FontGetEncoding(TRN_Font font, const char*** result);
TRN_API TRN_FontIsEmbedded(TRN_Font font, TRN_Bool* result);
TRN_API TRN_FontGetEmbeddedFontName(TRN_Font font, const char** result);
TRN_API TRN_FontGetEmbeddedFont(TRN_Font font, TRN_Obj* result);
TRN_API TRN_FontGetEmbeddedFontBufSize(TRN_Font font,int* result);
TRN_API TRN_FontGetUnitsPerEm(TRN_Font font, TRN_UInt16* result);
TRN_API TRN_FontGetBBox(TRN_Font font, TRN_Rect* result);
TRN_API TRN_FontGetAscent(TRN_Font font, double* result);
TRN_API TRN_FontGetDescent(TRN_Font font, double* result);
TRN_API TRN_FontGetStandardType1FontType(TRN_Font font, int* result);
TRN_API TRN_FontIsCFF(TRN_Font font, TRN_Bool* result);
TRN_API TRN_FontGetType3FontMatrix(TRN_Font font, TRN_Matrix2D* result);
TRN_API TRN_FontGetType3GlyphStream(TRN_Font font, TRN_UInt32 char_code, TRN_Obj* result);
TRN_API TRN_FontGetVerticalAdvance(TRN_Font font, TRN_UInt32 char_code, double* out_pos_vect_x, double* out_pos_vect_y, double* result);
TRN_API TRN_FontGetDescendant(TRN_Font font, TRN_Font* result);
TRN_API TRN_FontMapToCID(TRN_Font font, TRN_UInt32 char_code, TRN_UInt32* result);
TRN_API TRN_FontMapToCID2(TRN_Font font, const TRN_UChar* char_data, int char_data_avail, TRN_UInt32* out_charcode, TRN_UInt32* out_cid, int* result);

#ifdef __cplusplus
} // extern C
#endif

#endif // PDFTRON_H_CPDFFont
