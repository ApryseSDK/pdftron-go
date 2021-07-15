//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CByteRange
#define PDFTRON_H_CByteRange

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>




/* methods: */
TRN_API TRN_ByteRangeGetStartOffset(const TRN_ByteRange* self, TRN_UInt64* result);
TRN_API TRN_ByteRangeGetEndOffset(const TRN_ByteRange* self, TRN_UInt64* result);
TRN_API TRN_ByteRangeGetSize(const TRN_ByteRange* self, TRN_UInt64* result);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CByteRange */
