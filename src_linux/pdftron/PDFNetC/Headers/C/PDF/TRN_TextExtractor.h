//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFTextExtractor
#define PDFTRON_H_CPDFTextExtractor

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_TextExtractorCreate(TRN_TextExtractor* result);
TRN_API TRN_TextExtractorDestroy(TRN_TextExtractor te);

enum TRN_TextExtractorProcessingFlags
{
	e_TextExtractor_no_ligature_exp = 1,
	e_TextExtractor_no_dup_remove = 2,
	e_TextExtractor_punct_break = 4,
	e_TextExtractor_remove_hidden_text = 8,
	e_TextExtractor_no_invisible_text = 16
};

TRN_API TRN_TextExtractorSetOCGContext(TRN_TextExtractor te, TRN_OCGContext ctx);
TRN_API TRN_TextExtractorBegin(TRN_TextExtractor te, TRN_Page page, const TRN_Rect* clip_ptr, int flags);
TRN_API TRN_TextExtractorGetWordCount(TRN_TextExtractor te, int* result);
TRN_API TRN_TextExtractorSetRightToLeftLanguage(TRN_TextExtractor te, TRN_Bool rtl);
TRN_API TRN_TextExtractorGetRightToLeftLanguage(TRN_TextExtractor te, TRN_Bool* result);
TRN_API TRN_TextExtractorGetAsText(TRN_TextExtractor te, TRN_Bool dehyphen, TRN_UString result);
TRN_API TRN_TextExtractorGetTextUnderAnnot(TRN_TextExtractor te, TRN_Annot annot, TRN_UString result);

enum TRN_TextExtractorXMLOutputFlags
{
	e_TextExtractor_words_as_elements = 1,
	e_TextExtractor_output_bbox = 2,
	e_TextExtractor_output_style_info = 4
};

TRN_API TRN_TextExtractorGetAsXML(TRN_TextExtractor te, int xml_output_flags, TRN_UString result);

//Style
TRN_API TRN_TextExtractorStyleGetFont(TRN_TextExtractorStyle* tes, TRN_Obj* result);
TRN_API TRN_TextExtractorStyleGetFontName(TRN_TextExtractorStyle* tes, TRN_UString* result);
TRN_API TRN_TextExtractorStyleGetFontSize(TRN_TextExtractorStyle* tes, double* result);
TRN_API TRN_TextExtractorStyleGetWeight(TRN_TextExtractorStyle* tes, int* result);
TRN_API TRN_TextExtractorStyleIsItalic(TRN_TextExtractorStyle* tes, TRN_Bool* result);
TRN_API TRN_TextExtractorStyleIsSerif(TRN_TextExtractorStyle* tes, TRN_Bool* result);
TRN_API TRN_TextExtractorStyleGetColor(TRN_TextExtractorStyle* tes, TRN_UInt8 rgb[3]);

TRN_API TRN_TextExtractorStyleCompare (const TRN_TextExtractorStyle* tes, const TRN_TextExtractorStyle* s, TRN_Bool* result);

TRN_API TRN_TextExtractorStyleCreate(TRN_TextExtractorStyle* result);
TRN_API TRN_TextExtractorStyleCopy(TRN_TextExtractorStyle* s, TRN_TextExtractorStyle* result);


//Word
TRN_API TRN_TextExtractorWordGetNumGlyphs(TRN_TextExtractorWord* tew, int* result);

TRN_API TRN_TextExtractorWordGetBBox(TRN_TextExtractorWord* tew, double out_bbox[4]);
TRN_API TRN_TextExtractorWordGetQuad(TRN_TextExtractorWord* tew, double out_quad[8]);
TRN_API TRN_TextExtractorWordGetGlyphQuad(TRN_TextExtractorWord* tew, int glyph_idx, double out_quad[8]);
TRN_API TRN_TextExtractorWordGetCharStyle(TRN_TextExtractorWord* tew, int char_idx, TRN_TextExtractorStyle* result);

TRN_API TRN_TextExtractorWordGetStyle(TRN_TextExtractorWord* tew, TRN_TextExtractorStyle* result);

TRN_API TRN_TextExtractorWordGetStringLen(TRN_TextExtractorWord* tew, int* result);
TRN_API TRN_TextExtractorWordGetString(TRN_TextExtractorWord* tew, const TRN_Unicode** result);

TRN_API TRN_TextExtractorWordGetNextWord(TRN_TextExtractorWord* tew, TRN_TextExtractorWord* result);
TRN_API TRN_TextExtractorWordGetCurrentNum(TRN_TextExtractorWord* tew, int* result);

TRN_API TRN_TextExtractorWordCompare (const TRN_TextExtractorWord* tew, const TRN_TextExtractorWord* word, TRN_Bool* result);
TRN_API TRN_TextExtractorWordCreate(TRN_TextExtractorWord* result);
TRN_API TRN_TextExtractorWordIsValid(TRN_TextExtractorWord* tew, TRN_Bool* result);


TRN_API TRN_TextExtractorLineGetNumWords(TRN_TextExtractorLine* line, int* result);
TRN_API TRN_TextExtractorLineIsSimpleLine(TRN_TextExtractorLine* line, TRN_Bool* result);
TRN_API TRN_TextExtractorLineGetBBox(TRN_TextExtractorLine* line, const double** result);
TRN_API TRN_TextExtractorLineGetQuad(TRN_TextExtractorLine* line, double out_quad[8]);
TRN_API TRN_TextExtractorLineGetFirstWord(TRN_TextExtractorLine* line, TRN_TextExtractorWord* result);
TRN_API TRN_TextExtractorLineGetWord(TRN_TextExtractorLine* line, int word_idx, TRN_TextExtractorWord* result);
TRN_API TRN_TextExtractorLineGetNextLine(TRN_TextExtractorLine* line, TRN_TextExtractorLine* result);
TRN_API TRN_TextExtractorLineGetCurrentNum(TRN_TextExtractorLine* line, int* result);


TRN_API TRN_TextExtractorLineGetStyle(TRN_TextExtractorLine* line, TRN_TextExtractorStyle* result);

TRN_API TRN_TextExtractorLineGetParagraphID(TRN_TextExtractorLine* line, int* result);
TRN_API TRN_TextExtractorLineGetFlowID(TRN_TextExtractorLine* line, int* result);
TRN_API TRN_TextExtractorLineEndsWithHyphen(TRN_TextExtractorLine* line, TRN_Bool* result);

TRN_API TRN_TextExtractorLineCompare (const TRN_TextExtractorLine* line, const TRN_TextExtractorLine* line2, TRN_Bool* result);
TRN_API TRN_TextExtractorLineCreate(TRN_TextExtractorLine* result);
TRN_API TRN_TextExtractorLineIsValid(TRN_TextExtractorLine* line, TRN_Bool* result);

TRN_API TRN_TextExtractorGetNumLines(TRN_TextExtractor te, int* result);
TRN_API TRN_TextExtractorGetFirstLine(TRN_TextExtractor te, TRN_TextExtractorLine* result);

TRN_API TRN_TextExtractorGetAsTextWithOffsets(TRN_TextExtractor te, TRN_UString uni_result, int* offset_arr, TRN_UInt32* offset_size);
TRN_API TRN_TextExtractorCmptSemanticInfo(TRN_TextExtractor te, TRN_Matrix2D* mtx, double* sen_info_result, TRN_UInt32* sen_info_size);
TRN_API TRN_TextExtractorGetQuads(TRN_TextExtractor te, const TRN_Matrix2D* mtx, double* quads, TRN_UInt32* quads_size);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFTextExtractor
