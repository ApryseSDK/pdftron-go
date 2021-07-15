//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonUString
#define PDFTRON_H_CCommonUString

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

TRN_API TRN_UStringCreate(TRN_UString* result);
TRN_API TRN_UStringCopy(const TRN_UString str, TRN_UString* result);
TRN_API TRN_UStringCreateFromCharacter(TRN_Unicode value, TRN_UString* result);
TRN_API TRN_UStringCreateFromString(const TRN_Unicode* value, TRN_UString* result);
TRN_API TRN_UStringCreateFromUtf32String( const TRN_UInt32* str, int length, TRN_UString* result );
TRN_API TRN_UStringCreateFromSubstring(const TRN_Unicode* value, int length,TRN_UString* result);

enum TRN_UStringTextEncoding {
	e_UString_ascii_enc = 0,
	e_UString_pdfdoc_enc,      
	e_UString_winansii_enc,    
	e_UString_pdftext_enc,     
	e_UString_utf16be_enc,  
	e_UString_utf8,
	e_UString_no_enc           
};

TRN_API TRN_UStringCreateFromCharString(const char* buf, int buf_sz, enum TRN_UStringTextEncoding enc, TRN_UString* result);
TRN_API TRN_UStringDestroy(TRN_UString to_destroy);
TRN_API TRN_UStringAssignString(TRN_UString str, const TRN_Unicode* uni, int buf_sz);
TRN_API TRN_UStringAssignUString(TRN_UString str, const TRN_UString uni);
TRN_API TRN_UStringAssignAscii(TRN_UString str, const char* uni, int buf_sz, enum TRN_UStringTextEncoding enc);
TRN_API TRN_UStringAssignConcat(TRN_UString str1, const TRN_UString str2);
TRN_API TRN_UStringConcat(const TRN_UString str1, const TRN_UString str2, TRN_UString result); 
TRN_API TRN_UStringGetLength(const TRN_UString str, int* result);
TRN_API TRN_UStringIsEmpty(const TRN_UString str, TRN_Bool* result);
TRN_API TRN_UStringGetBuffer(const TRN_UString str, const TRN_Unicode** result);
TRN_API TRN_UStringCompare(const TRN_UString str1, const TRN_UString str2, int max_length, int* result);
TRN_API TRN_UStringSubStr(const TRN_UString str, int off, int count, TRN_UString* result); 
TRN_API TRN_UStringGetAt(const TRN_UString str, int idx, TRN_Unicode* result);
TRN_API TRN_UStringPushBack(TRN_UString str, TRN_Unicode ch);
TRN_API TRN_UStringResize(TRN_UString str, int count, TRN_Unicode ch);
TRN_API TRN_UStringToLower(TRN_UString str);
TRN_API TRN_UStringToUpper(TRN_UString str);
TRN_API TRN_UStringReserve(TRN_UString str, int count);
TRN_API TRN_UStringCStr(const TRN_UString str, const TRN_Unicode** result);
TRN_API TRN_UStringIsInAscii(const TRN_UString str, TRN_Bool* result);
TRN_API TRN_UStringConvertToAscii(const TRN_UString str, char* in_out_buf, int buf_sz, TRN_Bool null_term, int* result);
TRN_API TRN_UStringConvertToUtf8(const TRN_UString str, char* in_out_buf, int buf_sz, TRN_Bool null_term, int* result);
TRN_API TRN_UStringConvertToUtf32(const TRN_UString str, TRN_UInt32* in_out_buf, int buf_sz, TRN_Bool null_term, int* result);
TRN_API TRN_UStringConvertToPDFText(const TRN_UString str, char* in_out_buf, int buf_sz, TRN_Bool force_unicode, int* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CCommonUString
