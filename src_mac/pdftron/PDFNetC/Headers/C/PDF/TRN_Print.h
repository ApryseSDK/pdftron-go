//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPRINT
#define PDFTRON_H_CPDFPRINT

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

TRN_API TRN_PrintStartPrintJob(TRN_PDFDoc in_pdfdoc,
							  TRN_UString in_filename,
							  TRN_UString in_jobname,
							  TRN_UString in_outputFileName,
							  TRN_PageSet in_pagesToPrint,
							  TRN_Obj in_printerMode,
							  volatile TRN_Bool * in_cancel,
							  TRN_OCGContext in_ctx);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPRINT
