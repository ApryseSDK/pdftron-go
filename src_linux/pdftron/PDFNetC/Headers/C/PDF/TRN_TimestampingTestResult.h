//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CTimestampingTestResult
#define PDFTRON_H_CTimestampingTestResult

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>



/* methods: */
TRN_API TRN_TimestampingTestResultGetStatus(TRN_TimestampingTestResult self, TRN_Bool* result);
TRN_API TRN_TimestampingTestResultGetString(TRN_TimestampingTestResult self, TRN_UString* result);
TRN_API TRN_TimestampingTestResultHasResponseVerificationResult(TRN_TimestampingTestResult self, TRN_Bool* result);
TRN_API TRN_TimestampingTestResultGetResponseVerificationResult(TRN_TimestampingTestResult self, TRN_EmbeddedTimestampVerificationResult* result);

TRN_API TRN_TimestampingTestResultDestroy(TRN_TimestampingTestResult self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CTimestampingTestResult */
