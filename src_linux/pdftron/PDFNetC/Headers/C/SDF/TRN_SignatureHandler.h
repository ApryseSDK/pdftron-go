//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CSDFSignatureHandler
#define PDFTRON_H_CSDFSignatureHandler

#ifdef __cplusplus
extern "C" {
#endif
    
#include <C/Common/TRN_Types.h>

/**
 * Signature methods to be extended
 */

/**
 * Pre-condition: out_name must be initialized.
 */
typedef TRN_Exception (TRN_SIGAPI *TRN_SignatureHandlerGetNameFunction)(TRN_UString* name, void* unused);
typedef TRN_Exception (TRN_SIGAPI *TRN_SignatureHandlerAppendDataFunction)(const TRN_SignatureData data, void* unused);
typedef TRN_Exception (TRN_SIGAPI *TRN_SignatureHandlerResetFunction)(TRN_Bool* result, void* unused);
typedef TRN_Exception (TRN_SIGAPI *TRN_SignatureHandlerCreateSignatureFunction)(TRN_SignatureData* signature, void* unused);
//typedef TRN_Exception (TRN_SIGAPI *TRN_SignatureHandlerValidateSignatureFunction)(TRN_Obj sig_dict, TRN_ValidateSignatureResult* result, void* unused);
typedef TRN_Exception (TRN_SIGAPI *TRN_SignatureHandlerDestructorFunction)(void* unused);

TRN_API TRN_SignatureHandlerCreate(TRN_SignatureHandlerGetNameFunction get_name,
                                    TRN_SignatureHandlerAppendDataFunction append_data,
                                    TRN_SignatureHandlerResetFunction reset,
                                    TRN_SignatureHandlerCreateSignatureFunction create_signature,
                                    /*TRN_SignatureHandlerValidateSignatureFunction validate_signature,*/
                                    TRN_SignatureHandlerDestructorFunction destructor,
                                    void* unused,
                                    TRN_SignatureHandler* signature_handler);
TRN_API TRN_SignatureHandlerDestroy(TRN_SignatureHandler signature_handler, void** unused);
TRN_API TRN_SignatureHandlerGetName(TRN_SignatureHandler signature_handler, TRN_UString* result);
TRN_API TRN_SignatureHandlerAppendData(TRN_SignatureHandler signature_handler, const TRN_SignatureData data);
TRN_API TRN_SignatureHandlerReset(TRN_SignatureHandler signature_handler, TRN_Bool* result);
TRN_API TRN_SignatureHandlerCreateSignature(TRN_SignatureHandler signature_handler, TRN_SignatureData* result);
//TRN_API TRN_SignatureHandlerValidateSignature(TRN_SignatureHandler signature_handler, TRN_Obj sig_dict, TRN_ValidateSignatureResult* result);
TRN_API TRN_SignatureHandlerDestructor(TRN_SignatureHandler signature_handler);
TRN_API TRN_SignatureHandlerGetUserImpl(TRN_SignatureHandler signature_handler, void** result);

#ifdef __cplusplus
}
#endif
    
#endif // PDFTRON_H_CSDFSignatureHandler
