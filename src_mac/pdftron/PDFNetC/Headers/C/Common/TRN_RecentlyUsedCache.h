//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonRecentlyUsedCache
#define PDFTRON_H_CCommonRecentlyUsedCache

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_UString.h>

#ifdef __cplusplus
extern "C" {
#endif

TRN_API TRN_RecentlyUsedCacheRemoveDocument(TRN_UString document_path);
TRN_API TRN_RecentlyUsedCacheAccessDocument(TRN_UString document_path);

TRN_API TRN_RecentlyUsedCacheGetBitmapPathIfExists(TRN_UString document_path, TRN_UString * output_bitmap_path);

TRN_API TRN_RecentlyUsedCacheResetCache();
TRN_API TRN_RecentlyUsedCacheInitializeRecentlyUsedCache(size_t num_documents, size_t max_absolute_space, double max_percentage_space);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CCommonRecentlyUsedCache
