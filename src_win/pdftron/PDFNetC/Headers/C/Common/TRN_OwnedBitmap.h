

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCOMMONOWNEDBITMAP
#define PDFTRON_H_CCOMMONOWNEDBITMAP

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

TRN_API TRN_OwnedBitmapGetWidth(TRN_OwnedBitmap bitmap, TRN_UInt32* result);

TRN_API TRN_OwnedBitmapGetHeight(TRN_OwnedBitmap bitmap, TRN_UInt32* result);

TRN_API TRN_OwnedBitmapGetTotalSize(TRN_OwnedBitmap bitmap, TRN_UInt32* result);

TRN_API TRN_OwnedBitmapGetData(TRN_OwnedBitmap bitmap, TRN_UChar** result);

TRN_API TRN_OwnedBitmapGetBlendMode(TRN_OwnedBitmap, int* result);

TRN_API TRN_OwnedBitmapDestroy(TRN_OwnedBitmap bitmap);



#ifdef __cplusplus
}
#endif



#endif

