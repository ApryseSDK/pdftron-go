//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CFiltersFiltersWriter
#define PDFTRON_H_CFiltersFiltersWriter

#ifdef __cplusplus
extern "C" {
#endif 

#include <C/Common/TRN_Types.h>
#include <C/Filters/TRN_Filter.h>
#include <stdio.h>

TRN_API TRN_FilterWriterCreate(TRN_Filter filter, TRN_FilterWriter* result);
TRN_API TRN_FilterWriterDestroy (TRN_FilterWriter writer);
TRN_API TRN_FilterWriterAttachFilter(TRN_FilterWriter writer, TRN_Filter filter);
TRN_API TRN_FilterWriterGetAttachedFilter(TRN_FilterWriter writer, TRN_Filter* no_own_result);
TRN_API TRN_FilterWriterSeek(TRN_FilterWriter writer, TRN_Ptrdiff offset, enum TRN_FilterReferencePos origin);
TRN_API TRN_FilterWriterTell (TRN_FilterWriter writer, TRN_Ptrdiff* result);
TRN_API TRN_FilterWriterCount (TRN_FilterWriter writer, TRN_Size* result);
TRN_API TRN_FilterWriterFlush (TRN_FilterWriter writer);
TRN_API TRN_FilterWriterFlushAll (TRN_FilterWriter writer);

TRN_API TRN_FilterWriterWriteUChar(TRN_FilterWriter writer, TRN_UChar ch);
TRN_API TRN_FilterWriterWriteInt16(TRN_FilterWriter writer, TRN_Int16 num);
TRN_API TRN_FilterWriterWriteUInt16(TRN_FilterWriter writer, TRN_UInt16 num);
TRN_API TRN_FilterWriterWriteInt32(TRN_FilterWriter writer, TRN_Int32 num);
TRN_API TRN_FilterWriterWriteUInt32(TRN_FilterWriter writer, TRN_UInt32 num);
TRN_API TRN_FilterWriterWriteInt64(TRN_FilterWriter writer, TRN_Int64 num);
TRN_API TRN_FilterWriterWriteUInt64(TRN_FilterWriter writer, TRN_UInt64 num);
TRN_API TRN_FilterWriterWriteString(TRN_FilterWriter writer, const char* str);
TRN_API TRN_FilterWriterWriteFilter(TRN_FilterWriter writer, TRN_FilterReader reader);
TRN_API TRN_FilterWriterWriteLine(TRN_FilterWriter writer, const char* line, char eol);
TRN_API TRN_FilterWriterWriteBuffer(TRN_FilterWriter writer, const char* buf, TRN_Size buf_size, TRN_Size* result);

#ifdef __cplusplus
}
#endif 

#endif // PDFTRON_H_CFiltersFiltersWriter
