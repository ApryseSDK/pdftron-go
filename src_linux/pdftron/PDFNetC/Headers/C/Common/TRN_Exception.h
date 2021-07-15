//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonExceptions
#define PDFTRON_H_CCommonExceptions

#ifdef __cplusplus
extern "C" {
#endif 

#include <C/Common/TRN_Types.h>

TRN_API_T(TRN_Int32) TRN_GetLineNum(TRN_Exception e);
TRN_API_T(const char*) TRN_GetCondExpr(TRN_Exception e);
TRN_API_T(const char*) TRN_GetFileName(TRN_Exception e);
TRN_API_T(const char*) TRN_GetFunction(TRN_Exception e);
TRN_API_T(const char*) TRN_GetMessage(TRN_Exception e);
TRN_API_T(TRN_UInt32) TRN_GetErrorCode(TRN_Exception e);
TRN_API_T(const char*) TRN_GetFullMessage(TRN_Exception e);
TRN_API TRN_CreateExceptionEx( const char* cond_expr, 
			const char* filename, TRN_Int32 linenumber, 
			const char* function, const char* message, TRN_UInt32 errorcode);
TRN_API TRN_CreateException( const char* cond_expr, 
							const char* filename, TRN_Int32 linenumber, 
							const char* function, const char* message);

#ifdef __cplusplus
} // extern C
#endif 

#endif // PDFTRON_H_CCommonExceptions
