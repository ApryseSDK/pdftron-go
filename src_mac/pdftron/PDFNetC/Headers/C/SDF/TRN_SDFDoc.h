//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CSDFSDFDoc
#define PDFTRON_H_CSDFSDFDoc

#ifdef __cplusplus
extern "C" {
#endif


#include <C/Common/TRN_Types.h>

	TRN_API TRN_SDFDocCreate(TRN_SDFDoc* result);

	TRN_API TRN_SDFDocCreateFromFileUString(const TRN_UString filepath, TRN_SDFDoc* result);

	TRN_API TRN_SDFDocCreateFromFileString(const char* filepath, TRN_SDFDoc* result);

	TRN_API TRN_SDFDocCreateFromFilter(TRN_Filter no_own_stream, TRN_SDFDoc* result);

	TRN_API TRN_SDFDocCreateFromMemoryBuffer(const char* buf, TRN_Size buf_size,TRN_SDFDoc* result);

	TRN_API TRN_SDFDocCreateShallowCopy(TRN_SDFDoc source, TRN_SDFDoc* result);

	TRN_API TRN_SDFDocDestroy(TRN_SDFDoc doc);

	TRN_API TRN_SDFDocReleaseFileHandles(TRN_SDFDoc doc);

	TRN_API TRN_SDFDocIsEncrypted(TRN_SDFDoc doc, TRN_Bool* result);

	TRN_API TRN_SDFDocInitSecurityHandler(TRN_SDFDoc doc, void* custom_data, TRN_Bool* result);

	TRN_API TRN_SDFDocInitStdSecurityHandler(TRN_SDFDoc doc, const char* password, int password_sz, TRN_Bool* result); // Deprecated.

    TRN_API TRN_SDFDocInitStdSecurityHandlerUString(TRN_SDFDoc doc, TRN_UString password, TRN_Bool* result);
    TRN_API TRN_SDFDocInitStdSecurityHandlerBuffer(TRN_SDFDoc doc, const TRN_UInt8* password_buf, size_t password_buf_size, TRN_Bool* result);

	TRN_API TRN_SDFDocIsModified(TRN_SDFDoc const doc,
			TRN_Bool* result);
	TRN_API TRN_SDFDocHasRepairedXRef(TRN_SDFDoc const doc,
			TRN_Bool* result);

	TRN_API TRN_SDFDocIsFullSaveRequired(TRN_SDFDoc const doc,
		TRN_Bool* result);

	TRN_API TRN_SDFDocGetTrailer(TRN_SDFDoc doc, TRN_Obj* result);

	TRN_API TRN_SDFDocGetObj(TRN_SDFDoc const doc,
		const TRN_UInt32 obj_num, TRN_Obj* result);

	TRN_API TRN_SDFDocImportObj(TRN_SDFDoc doc, TRN_Obj obj,
		TRN_Bool deep_copy, TRN_Obj* result);

	TRN_API TRN_SDFDocImportObjs(TRN_SDFDoc doc, TRN_Obj* obj_list, int obj_list_size, TRN_Obj* result);
    
    TRN_API TRN_SDFDocImportObjsWithExcludeList(TRN_SDFDoc doc, TRN_Obj* obj_list, int obj_list_size, TRN_Obj* exclude_list, int exclude_list_size, TRN_Obj* result);

	TRN_API TRN_SDFDocXRefSize(TRN_SDFDoc const doc, TRN_UInt32* result);

	TRN_API TRN_SDFDocClearMarks(TRN_SDFDoc doc);

	enum TRN_SDFDocSaveOptions
	{
		e_SDFDoc_incremental   = 0x01,
		e_SDFDoc_remove_unused = 0x02,
		e_SDFDoc_hex_strings   = 0x04,
		e_SDFDoc_omit_xref     = 0x08,
		e_SDFDoc_linearized    = 0x10,
		e_SDFDoc_compatibility = 0x20
	};


	TRN_API TRN_SDFDocSave(TRN_SDFDoc doc, const TRN_UString path, TRN_UInt32 flags,
		TRN_ProgressMonitor progress, const char* header);

	TRN_API TRN_SDFDocSaveMemory(TRN_SDFDoc doc, const char** out_buf, TRN_Size* out_buf_size,
		TRN_UInt32 flags, TRN_ProgressMonitor progress, const char* header);
	
	TRN_API TRN_SDFDocCustomQuery(TRN_SDFDoc doc, const char* in_json, TRN_Size in_json_size,
		const char** out_json, TRN_Size* out_json_size);

	TRN_API TRN_SDFDocSaveStream(TRN_SDFDoc doc, TRN_Filter stream, TRN_UInt32 flags, const char* header);

	TRN_API TRN_SDFDocGetHeader(const TRN_SDFDoc doc, const char** result);

	TRN_API TRN_SDFDocGetSecurityHandler(TRN_SDFDoc doc, TRN_SecurityHandler* no_own_result);

	TRN_API TRN_SDFDocSetSecurityHandler(TRN_SDFDoc doc, TRN_SecurityHandler no_own_handler);

	TRN_API TRN_SDFDocRemoveSecurity(TRN_SDFDoc doc);

	TRN_API TRN_SDFDocSwap(TRN_SDFDoc doc, TRN_UInt32 obj_num1, TRN_UInt32 obj_num2);

	TRN_API TRN_SDFDocIsLinearized(TRN_SDFDoc const doc, TRN_Bool* result);

	TRN_API TRN_SDFDocGetLinearizationDict(TRN_SDFDoc const doc, TRN_Obj* result);

	TRN_API TRN_SDFDocGetHintStream(TRN_SDFDoc const doc, TRN_Obj* result);

	TRN_API TRN_SDFDocEnableDiskCaching(TRN_SDFDoc doc, TRN_Bool use_cache_flag );

	TRN_API TRN_SDFDocLock(TRN_SDFDoc doc);

	TRN_API TRN_SDFDocUnlock(TRN_SDFDoc doc);

	TRN_API TRN_SDFDocLockRead(TRN_SDFDoc doc);

	TRN_API TRN_SDFDocUnlockRead(TRN_SDFDoc doc);

	TRN_API TRN_SDFDocTryLock( TRN_SDFDoc doc, TRN_Bool* result );

	TRN_API TRN_SDFDocTimedLock( TRN_SDFDoc doc, int milliseconds, TRN_Bool* result );

	TRN_API TRN_SDFDocTryLockRead( TRN_SDFDoc doc, TRN_Bool* result );

	TRN_API TRN_SDFDocTimedLockRead( TRN_SDFDoc doc, int milliseconds, TRN_Bool* result );

	TRN_API TRN_SDFDocGetFileName(TRN_SDFDoc doc, TRN_UString* result);

	TRN_API TRN_SDFDocCreateIndirectName(TRN_SDFDoc doc, const char* name, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectArray(TRN_SDFDoc doc, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectBool(TRN_SDFDoc doc, TRN_Bool value, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectDict(TRN_SDFDoc doc, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectNull(TRN_SDFDoc doc, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectNumber(TRN_SDFDoc doc, double value, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectString(TRN_SDFDoc doc, const TRN_UChar* buf_value, TRN_UInt32 buf_size, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectStringFromUString(TRN_SDFDoc doc, const TRN_UString str, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectStreamFromFilter(TRN_SDFDoc doc, TRN_FilterReader data, TRN_Filter no_own_filter_chain, TRN_Obj* result);
	TRN_API TRN_SDFDocCreateIndirectStream(TRN_SDFDoc doc, const char* data, const TRN_Size data_size, TRN_Filter no_own_filter_chain, TRN_Obj* result);


#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CSDFSDFDoc
