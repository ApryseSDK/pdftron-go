//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonVector
#define PDFTRON_H_CCommonVector

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

	TRN_API TRN_VectorGetSize(TRN_Vector vec, TRN_UInt32* result); 
	TRN_API TRN_VectorGetData(TRN_Vector vec, void** result);
	TRN_API TRN_VectorGetAt(TRN_Vector vec, TRN_UInt32 pos, void** result);

	TRN_API TRN_VectorDestroy(TRN_Vector vec);
	TRN_API TRN_VectorDestroyKeepContents(TRN_Vector vec);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CCommonVector
