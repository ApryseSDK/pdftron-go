//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonErrorCode
#define PDFTRON_H_CCommonErrorCode

 #ifdef __cplusplus
 extern "C" {
 #endif 

#include <C/Common/TRN_Types.h>

enum TRN_ErrorCodes
{
    e_Error_general,		// Error code was not specified for this exception
    e_Error_network,		// Networking error; check your internet connection or firewall settings
    e_Error_credentials,	// Provided credentials are incorrect; i.e. PDFNet License, document password etc
    e_Error_num
};

 #ifdef __cplusplus
 } // extern C
 #endif 

#endif // PDFTRON_H_CCommonErrorCode
