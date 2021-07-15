//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPageLabel
#define PDFTRON_H_CPDFPageLabel

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>


	enum TRN_PageLabelStyle
	{
		e_PageLabel_decimal,
		e_PageLabel_roman_uppercase,
		e_PageLabel_roman_lowercase,
		e_PageLabel_alphabetic_uppercase,
		e_PageLabel_alphabetic_lowercase,
		e_PageLabel_none
	};

	TRN_API TRN_PageLabelCreate(TRN_SDFDoc doc, enum TRN_PageLabelStyle style, const TRN_UString prefix, int start_at, TRN_PageLabel* result);

	TRN_API TRN_PageLabelCreateFromObj(TRN_Obj l, int first_page, int last_page, TRN_PageLabel* result);

	TRN_API TRN_PageLabelAssign (TRN_PageLabel* left, const TRN_PageLabel* right);

	TRN_API TRN_PageLabelCompare(TRN_PageLabel* l, const TRN_PageLabel* d, TRN_Bool* result);

	TRN_API TRN_PageLabelIsValid(const TRN_PageLabel* l, TRN_Bool* result);

	TRN_API TRN_PageLabelGetLabelTitle(TRN_PageLabel* l, int page_num, TRN_UString* result);

	TRN_API TRN_PageLabelSetStyle(TRN_PageLabel* l, enum TRN_PageLabelStyle style);

	TRN_API TRN_PageLabelGetStyle(const TRN_PageLabel* l, enum TRN_PageLabelStyle* result);

	TRN_API TRN_PageLabelGetPrefix(const TRN_PageLabel* l, TRN_UString* result);

	TRN_API TRN_PageLabelSetPrefix(TRN_PageLabel* l, const TRN_UString prefix);

	TRN_API TRN_PageLabelGetStart(const TRN_PageLabel* l, int* result);

	TRN_API TRN_PageLabelSetStart(TRN_PageLabel* l, int start_at);

	TRN_API TRN_PageLabelGetFirstPageNum(TRN_PageLabel* l, int* result);

	TRN_API TRN_PageLabelGetLastPageNum(TRN_PageLabel* l, int* result);

	TRN_API TRN_PageLabelGetSDFObj (const TRN_PageLabel* l, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPageLabel
