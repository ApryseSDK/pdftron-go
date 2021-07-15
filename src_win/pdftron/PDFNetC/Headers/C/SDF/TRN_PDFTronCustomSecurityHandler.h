//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------


#ifndef PDFTRON_H_CPDFTronCustomSecurityHandler
#define PDFTRON_H_CPDFTronCustomSecurityHandler

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>

TRN_API TRN_PDFTronCustomSecurityHandlerCreate(TRN_UInt32 custom_id, TRN_SecurityHandler* result);

#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CPDFTronCustomSecurityHandler */
