//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFDocumentPreviewCache
#define PDFTRON_H_CPDFDocumentPreviewCache

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_UString.h>

#ifdef __cplusplus
extern "C" {
#endif

enum TRN_DocumentPreviewCache_result{
	e_DocumentPreviewCache_failure,
	e_DocumentPreviewCache_success,
	e_DocumentPreviewCache_security_error,
	e_DocumentPreviewCache_cancel,
	e_DocumentPreviewCache_package_error
};

typedef void(*TRN_PreviewHandler) (enum TRN_DocumentPreviewCache_result result, const char* utf8_filepath, void* custom_data);

//typedef void(*TRN_PreviewHandler) (bool was_successful, const char* utf8_filepath, void* custom_data);

TRN_API TRN_DocumentPreviewCacheInitialize(TRN_UInt64 max_cache_bytes, double max_disk_percentage);
TRN_API TRN_DocumentPreviewCacheGetBitmapWithPath(TRN_UString document_path, TRN_UInt32 min_x_size, TRN_UInt32 min_y_size, TRN_PreviewHandler proc, void* custom_data);
TRN_API TRN_DocumentPreviewCacheCancelAllRequests();
TRN_API TRN_DocumentPreviewCacheCancelRequest(TRN_UString filepath);
TRN_API TRN_DocumentPreviewCacheIrrelevantChangeMade(TRN_UString filepath);
TRN_API TRN_DocumentPreviewCacheClearCache();

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFDocumentPreviewCache
