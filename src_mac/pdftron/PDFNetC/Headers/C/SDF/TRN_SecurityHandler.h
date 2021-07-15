//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CSDFSecurityHandler
#define PDFTRON_H_CSDFSecurityHandler

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

enum TRN_SecurityHandlerPermission
{
	e_SecurityHandler_owner = 1,            ///< the user has 'owner' rights (e.g. rights to change the document's security settings).
	e_SecurityHandler_doc_open,             ///< open and decrypt the document.
	e_SecurityHandler_doc_modify,           ///< edit the document more than adding or modifying text notes.
	e_SecurityHandler_print,                ///< print the document.	
	e_SecurityHandler_print_high,           ///< high resolution print.
	e_SecurityHandler_extract_content,      ///< enable content extraction
	e_SecurityHandler_mod_annot,            ///< allow modifications to annotations
	e_SecurityHandler_fill_forms,           ///< allow changes to fill in forms
	e_SecurityHandler_access_support,       ///< content access for the visually impaired.
	e_SecurityHandler_assemble_doc          ///< allow document assembly
};

TRN_API TRN_SecurityHandlerClone (TRN_SecurityHandler sh, TRN_SecurityHandler* result);
TRN_API TRN_SecurityHandlerDestroy (TRN_SecurityHandler sh);
TRN_API TRN_SecurityHandlerInitialize(TRN_SecurityHandler sh, TRN_SDFDoc doc, TRN_Obj encrypt_dict, void* custom_data);
TRN_API TRN_SecurityHandlerGetPermission(TRN_SecurityHandler sh, enum TRN_SecurityHandlerPermission p, TRN_Bool* result);

TRN_API TRN_SecurityHandlerGetKeyLength(TRN_SecurityHandler sh, int* result);
TRN_API TRN_SecurityHandlerGetEncryptionAlgorithmID(TRN_SecurityHandler sh, int* result);
TRN_API TRN_SecurityHandlerGetHandlerDocName(TRN_SecurityHandler sh, const char** result);
TRN_API TRN_SecurityHandlerIsModified (TRN_SecurityHandler sh, TRN_Bool* result);
TRN_API TRN_SecurityHandlerSetModified (TRN_SecurityHandler sh, TRN_Bool is_modified);

enum TRN_SecurityHandlerAlgorithmType {
	e_SecurityHandler_RC4_40 = 1,      
	e_SecurityHandler_RC4_128,           
	e_SecurityHandler_AES,
	e_SecurityHandler_AES_256
};

TRN_API TRN_SecurityHandlerCreate (enum TRN_SecurityHandlerAlgorithmType crypt_type, TRN_SecurityHandler* result);	
TRN_API TRN_SecurityHandlerCreateFromEncCode (const char* name, int key_len, int enc_code, TRN_SecurityHandler* result);	
TRN_API TRN_SecurityHandlerCreateDefault (TRN_SecurityHandler* result);	
TRN_API TRN_SecurityHandlerChangeUserPassword(TRN_SecurityHandler sh,const char* password); // Deprecated.
TRN_API TRN_SecurityHandlerChangeUserPasswordNonAscii(TRN_SecurityHandler sh,const char* password, size_t pwd_length );  // Deprecated.
TRN_API TRN_SecurityHandlerGetUserPassword(TRN_SecurityHandler sh, const char** result);  // Non-guaranteed result.
TRN_API TRN_SecurityHandlerGetUserPasswordSize(TRN_SecurityHandler sh, TRN_UInt32* result); // Non-guaranteed result.
TRN_API TRN_SecurityHandlerChangeMasterPassword(TRN_SecurityHandler sh, const char* password); // Deprecated.
TRN_API TRN_SecurityHandlerChangeMasterPasswordNonAscii(TRN_SecurityHandler sh,const char* password, size_t pwd_length ); // Deprecated.
TRN_API TRN_SecurityHandlerGetMasterPassword(TRN_SecurityHandler sh, const char** result); // Non-guaranteed result.
TRN_API TRN_SecurityHandlerGetMasterPasswordSize(TRN_SecurityHandler sh, TRN_UInt32* result); // Non-guaranteed result.
TRN_API TRN_SecurityHandlerSetPermission (TRN_SecurityHandler sh, enum TRN_SecurityHandlerPermission perm, TRN_Bool value);
TRN_API TRN_SecurityHandlerChangeRevisionNumber (TRN_SecurityHandler sh, int rev_num);
TRN_API TRN_SecurityHandlerSetEncryptMetadata(TRN_SecurityHandler sh, TRN_Bool encrypt_metadata);
TRN_API TRN_SecurityHandlerGetRevisionNumber (TRN_SecurityHandler sh, int* result);
TRN_API TRN_SecurityHandlerIsUserPasswordRequired (TRN_SecurityHandler sh, TRN_Bool* result);
TRN_API TRN_SecurityHandlerIsMasterPasswordRequired (TRN_SecurityHandler sh, TRN_Bool* result);
TRN_API TRN_SecurityHandlerIsAES(TRN_SecurityHandler sh, TRN_Bool* result);
TRN_API TRN_SecurityHandlerIsAESObj(TRN_SecurityHandler sh, TRN_Obj stream, TRN_Bool* result);
TRN_API TRN_SecurityHandlerIsRC4(TRN_SecurityHandler sh, TRN_Bool* result);
TRN_API TRN_SecurityHandlerInitPassword(TRN_SecurityHandler sh, const char* password); // Deprecated.
TRN_API TRN_SecurityHandlerInitPasswordNonAscii(TRN_SecurityHandler sh, const char* password, size_t pwd_length); // Deprecated.

// APIs that replace those others accepting passwords
TRN_API TRN_SecurityHandlerChangeUserPasswordUString(TRN_SecurityHandler sh, TRN_UString password);
TRN_API TRN_SecurityHandlerChangeUserPasswordBuffer(TRN_SecurityHandler sh, const TRN_UInt8* password_buf, size_t password_buf_size);
TRN_API TRN_SecurityHandlerChangeMasterPasswordUString(TRN_SecurityHandler sh, TRN_UString password);
TRN_API TRN_SecurityHandlerChangeMasterPasswordBuffer(TRN_SecurityHandler sh, const TRN_UInt8* password_buf, size_t password_buf_size);
TRN_API TRN_SecurityHandlerInitPasswordUString(TRN_SecurityHandler sh, TRN_UString password);
TRN_API TRN_SecurityHandlerInitPasswordBuffer(TRN_SecurityHandler sh, const TRN_UInt8* password_buf, size_t password_buf_size);

//------------------------------------------
// Base class methods that can be overridden in the 'derived' class. The only use 
// case for these methods would be when a derived class must call the base class 
// implementation.

TRN_API TRN_SecurityHandlerAuthorize(TRN_SecurityHandler sh, enum TRN_SecurityHandlerPermission p, TRN_Bool* result);
TRN_API TRN_SecurityHandlerAuthorizeFailed(TRN_SecurityHandler sh);
TRN_API TRN_SecurityHandlerGetAuthorizationData (TRN_SecurityHandler sh, enum TRN_SecurityHandlerPermission req_opr, TRN_Bool* result);
TRN_API TRN_SecurityHandlerEditSecurityData(TRN_SecurityHandler sh, TRN_SDFDoc doc, TRN_Bool* result);
TRN_API TRN_SecurityHandlerFillEncryptDict(TRN_SecurityHandler sh, TRN_SDFDoc doc, TRN_Obj* result);


//------------------------------------------
// Optional user-defined callbacks that can be used to implement 
// custom (derived) security handlers.

typedef TRN_Bool (*TRN_SecurityHandlerAuthProc) (void* derived, enum TRN_SecurityHandlerPermission);
typedef void (*TRN_SecurityHandlerAuthFailedProc) (void* derived);
typedef TRN_Bool (*TRN_SecurityHandlerGetAuthDataProc) (void* derived, enum TRN_SecurityHandlerPermission);
typedef TRN_Bool (*TRN_SecurityHandlerEditSecurDataProc) (void* derived, TRN_SDFDoc doc);
typedef TRN_Obj (*TRN_SecurityHandlerFillEncryptDictProc) (void* derived, TRN_SDFDoc doc);
typedef void (*TRN_SecurityHandlerDerivedDestroyProc) (void* derived);
typedef void* (*TRN_SecurityHandlerDerivedCloneProc) (void* derived, TRN_SecurityHandler base);

TRN_API TRN_SecurityHandlerSetDerived(TRN_SecurityHandler sh, void* derived, 
	TRN_SecurityHandlerDerivedDestroyProc d,
	TRN_SecurityHandlerDerivedCloneProc c,
	TRN_SecurityHandlerAuthProc a,
	TRN_SecurityHandlerAuthFailedProc af,
	TRN_SecurityHandlerGetAuthDataProc ga,
	TRN_SecurityHandlerEditSecurDataProc es,
	TRN_SecurityHandlerFillEncryptDictProc fd);

TRN_API TRN_SecurityHandlerGetDerived(TRN_SecurityHandler sh, void** derived,
	TRN_SecurityHandlerDerivedDestroyProc* d,
	TRN_SecurityHandlerDerivedCloneProc* c,
	TRN_SecurityHandlerAuthProc* a,
	TRN_SecurityHandlerAuthFailedProc* af,
	TRN_SecurityHandlerGetAuthDataProc* ga,
	TRN_SecurityHandlerEditSecurDataProc* es,
	TRN_SecurityHandlerFillEncryptDictProc* fd);
						  

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CSDFSecurityHandler
