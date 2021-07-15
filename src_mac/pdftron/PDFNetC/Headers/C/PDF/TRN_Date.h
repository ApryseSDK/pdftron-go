//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFDate
#define PDFTRON_H_CPDFDate

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

TRN_API TRN_DateInit (TRN_UInt16 year, char month, char day, char hour, char minute, char second, TRN_Date* result);
TRN_API TRN_DateAssign (TRN_Date* left, const TRN_Date* right);
TRN_API TRN_DateIsValid(const TRN_Date* date, TRN_Bool* result);
TRN_API TRN_DateAttach(TRN_Date* date, TRN_Obj d);
TRN_API TRN_DateUpdate(TRN_Date* date, TRN_Obj d, TRN_Bool* result);
TRN_API_T(void) TRN_DateSetCurrentTime(TRN_Date* date);
TRN_API_T(TRN_UInt16) TRN_DateGetYear(TRN_Date* date);
TRN_API_T(TRN_UChar) TRN_DateGetMonth(TRN_Date* date);
TRN_API_T(TRN_UChar) TRN_DateGetDay(TRN_Date* date);
TRN_API_T(TRN_UChar) TRN_DateGetHour(TRN_Date* date);
TRN_API_T(TRN_UChar) TRN_DateGetMinute(TRN_Date* date);
TRN_API_T(TRN_UChar) TRN_DateGetSecond(TRN_Date* date);
TRN_API_T(TRN_UChar) TRN_DateGetUT(TRN_Date* date);
TRN_API_T(TRN_UChar) TRN_DateGetUTHour(TRN_Date* date);
TRN_API_T(TRN_UChar) TRN_DateGetUTMin(TRN_Date* date);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFDate
