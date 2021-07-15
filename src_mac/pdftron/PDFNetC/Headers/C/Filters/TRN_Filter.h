//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CFiltersFilter
#define PDFTRON_H_CFiltersFilter

#ifdef __cplusplus
extern "C" {
#endif 

#include <C/Common/TRN_Types.h>
#include <stdio.h>


enum TRN_FilterStdFileOpenMode
{
	e_Filter_read_mode,   
	e_Filter_write_mode,  
	e_Filter_append_mode, 
};


TRN_API TRN_FilterCreateASCII85Encode(TRN_Filter no_own_input_filter,
	TRN_UInt32 line_width, TRN_Size buf_sz, TRN_Filter* result);

TRN_API TRN_FilterCreateFlateEncode(TRN_Filter no_own_input_filter,
	int compression_level, TRN_Size buf_sz, TRN_Filter* result);

TRN_API TRN_FilterCreateMappedFileFromUString (const TRN_UString filename, TRN_Filter* result);
#ifdef ATLSTREAM
TRN_API	TRN_FilterCreateFromStream(void* stm, TRN_Filter* result);	
#endif // ATLSTREAM

TRN_API TRN_FilterCreateMemoryFilter(TRN_Size buf_sz, TRN_Bool is_input, TRN_Filter* result);

TRN_API TRN_FilterCreateImage2RGBFromElement(TRN_Element elem, TRN_Filter* result);

TRN_API TRN_FilterCreateImage2RGBFromObj(TRN_Obj obj, TRN_Filter* result);

TRN_API TRN_FilterCreateImage2RGB(TRN_Image img, TRN_Filter* result);

TRN_API TRN_FilterCreateImage2RGBAFromElement(TRN_Element elem, TRN_Bool premultiply, TRN_Filter* result);

TRN_API TRN_FilterCreateImage2RGBAFromObj(TRN_Obj obj, TRN_Bool premultiply, TRN_Filter* result);

TRN_API TRN_FilterCreateImage2RGBA(TRN_Image img, TRN_Bool premultiply, TRN_Filter* result);

typedef int (*TRN_SeekProc) (void* _user_data, long _offset, int _origin);
typedef size_t (*TRN_TellProc) (void* _user_data);
typedef TRN_UInt64 (*TRN_TruncProc) (void* _user_data, TRN_UInt64 new_size);
typedef int (*TRN_FlushProc) (void* _user_data);
typedef size_t (*TRN_ReadProc) (void * _DstBuf, size_t _ElementSize, size_t _Count, void* _user_data);
typedef size_t (*TRN_WriteProc) (const void * _Str, size_t _Size, size_t _Count, void* _user_data);
typedef size_t (*TRN_CreateInputIteratorProc) (void* _user_data);
typedef void (*TRN_DestroyProc) (void* _user_data);
    
struct TRN_CustomFilterCallbacks
{
    TRN_SeekProc _seek;
    TRN_TellProc _tell;
    TRN_FlushProc _flush;
    TRN_ReadProc _read;
    TRN_WriteProc _write;
    TRN_CreateInputIteratorProc _createCustomIterator;
    TRN_DestroyProc _destroy;
};
    
typedef struct TRN_CustomFilterCallbacks TRN_CustomFilterCallbacks;

TRN_API TRN_FilterCreateCustom(enum TRN_FilterStdFileOpenMode mode,
							   void* user_data,
							   TRN_SeekProc _seek,
							   TRN_TellProc _tell,
							   TRN_FlushProc _flush,
							   TRN_ReadProc _read,
							   TRN_WriteProc _write,
                               TRN_CreateInputIteratorProc _iterator,
                               TRN_DestroyProc _destroy,
							   TRN_Filter* result);
    
TRN_API TRN_FilterCreateCustomWithStruct(enum TRN_FilterStdFileOpenMode mode,
                               void* user_data,
                               TRN_CustomFilterCallbacks callbacks,
                               TRN_Filter* result);

TRN_API TRN_FilterDestroy (TRN_Filter filter);

TRN_API TRN_FilterMappedFileFileSize(TRN_Filter filter, TRN_Size* result);

TRN_API TRN_FilterMappedFileCompare(TRN_Filter mf1,TRN_Filter mf2, TRN_Bool* result);

TRN_API TRN_FilterAttachFilter(TRN_Filter filter, TRN_Filter no_own_attach_filter);

TRN_API TRN_FilterReleaseAttachedFilter (TRN_Filter filter,TRN_Filter* result);

TRN_API TRN_FilterGetAttachedFilter (TRN_Filter filter,	TRN_Filter* no_own_result);

TRN_API TRN_FilterGetSourceFilter(TRN_Filter filter, TRN_Filter* no_own_result);

TRN_API TRN_FilterGetName (const TRN_Filter filter, const char** result);

TRN_API TRN_FilterGetDecodeName (const TRN_Filter filter, const char** result);

TRN_API TRN_FilterBegin (TRN_Filter filter, TRN_UChar** result);

TRN_API TRN_FilterSize (TRN_Filter filter, TRN_Size* result);

TRN_API TRN_FilterConsume (TRN_Filter filter, TRN_Size num_bytes);

TRN_API TRN_FilterCount (TRN_Filter filter, TRN_Size* result);

TRN_API TRN_FilterSetCount (TRN_Filter filter, TRN_Size new_count, TRN_Size* result);

TRN_API TRN_FilterSetStreamLength (TRN_Filter filter, TRN_Size bytes); 

TRN_API TRN_FilterFlush (TRN_Filter filter);

TRN_API TRN_FilterFlushAll (TRN_Filter filter);

TRN_API TRN_FilterIsInputFilter (TRN_Filter filter, TRN_Bool* result);

TRN_API TRN_FilterCanSeek (TRN_Filter filter, TRN_Bool* result);

TRN_API TRN_FilterWriteToFile(TRN_Filter filter, TRN_UString path, TRN_Bool append);

enum TRN_FilterReferencePos 
{ 
	e_Filter_begin = SEEK_SET,
	e_Filter_end   = SEEK_END, 
	e_Filter_cur   = SEEK_CUR
};

TRN_API TRN_FilterSeek (TRN_Filter filter, TRN_Ptrdiff offset, enum TRN_FilterReferencePos origin);

TRN_API TRN_FilterTell (TRN_Filter filter, TRN_Ptrdiff* result);

TRN_API TRN_FilterCreateInputIterator (TRN_Filter filter, TRN_Filter* result);

TRN_API TRN_FilterGetFilePath(TRN_Filter const filter, TRN_UString* result);

TRN_API TRN_FilterMemoryFilterGetBuffer(TRN_Filter filter, TRN_UChar** result);

TRN_API TRN_FilterMemoryFilterSetAsInputFilter(TRN_Filter filter);

TRN_API TRN_FilterMemoryFilterReset(TRN_Filter filter);

TRN_API TRN_PathCompare(TRN_UString p1, TRN_UString p2, TRN_Bool* result);

#ifdef __cplusplus
}
#endif 

#endif // PDFTRON_H_CFiltersFilter
