//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFDoc
#define PDFTRON_H_CPDFPDFDoc

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_Field.h>
#include <C/PDF/TRN_Page.h>
#include <C/PDF/TRN_GeometryCollection.h>
#include <C/PDF/TRN_DigitalSignatureField.h>

#ifdef __cplusplus
extern "C" {
#endif

enum TRN_PDFDocEventType
{
	e_PDFDoc_action_trigger_doc_will_close = 17,
	e_PDFDoc_action_trigger_doc_will_save,
	e_PDFDoc_action_trigger_doc_did_save,
	e_PDFDoc_action_trigger_doc_will_print,
	e_PDFDoc_action_trigger_doc_did_print
};

enum TRN_PDFDocInsertFlag {
	e_PDFDoc_none,				//default, do not insert bookmarks
	e_PDFDoc_insert_bookmark	//insert bookmarks
};

enum TRN_PDFDocExtractFlag {
	e_PDFDoc_forms_only,				// default, only extract form fields to FDF
	e_PDFDoc_annots_only,				// only extract annots
	e_PDFDoc_both                      // extract both form fields and annots
};

enum TRN_PDFDocSignaturesVerificationStatus
{
	e_PDFDoc_unsigned,
	// e_failure == bad doc, digest, or MDP (i.e. does not include trust issues, because those are flaky due to being network/config-related)
	e_PDFDoc_failure,
	e_PDFDoc_untrusted,
	e_PDFDoc_unsupported,
	// unsigned sigs skipped; parts of document may be unsigned (check GetByteRanges on signed sigs to find out)
	e_PDFDoc_verified
};
struct TRN_downloadcontainer;
typedef struct TRN_downloadcontainer* TRN_DownloadContainer;
typedef TRN_Filter TRN_Downloader;

typedef void (*TRN_DownloadProc) (TRN_DownloadContainer cont, size_t offset, size_t size, void* user_data, void* options);
typedef void (*TRN_NotifyUpdatePageCallback) (TRN_PDFDoc doc, TRN_UInt32 page_num, TRN_UInt32 page_obj_num, void* custom_data);
typedef void (*TRN_NotifyUpdateOutlineCallback) (TRN_PDFDoc doc, void* custom_data);
typedef void (*TRN_NotifyUpdateNamedDestsCallback) (TRN_PDFDoc doc, void* custom_data);
typedef void (*TRN_NotifyUpdateThumbCallback) (TRN_PDFDoc doc, TRN_UInt32 page_num, TRN_UInt32 thumb_obj_num, void* custom_data);
typedef void (*TRN_NotifyFinishedDownloadCallback) (TRN_PDFDoc doc, void* custom_data);
typedef void (*TRN_NotifyDocumentError) (TRN_PDFDoc doc, const char* msg, void* custom_data);
typedef int (*TRN_GetCurrentPageCallback)(TRN_PDFDoc doc, void * custom_data);

struct TRN_DownloadCallbacks
{
	TRN_DownloadProc m_download_proc;
	void* m_download_proc_data;
	TRN_NotifyUpdatePageCallback m_update_page;
	TRN_NotifyUpdateOutlineCallback m_update_outline;
	TRN_NotifyUpdateNamedDestsCallback m_update_named_dests;
	TRN_NotifyUpdateThumbCallback m_update_thumb;
	TRN_NotifyFinishedDownloadCallback m_finished_download;
	TRN_NotifyDocumentError m_document_error;
	TRN_GetCurrentPageCallback m_get_current_page;
	void* m_custom_data;
};
TRN_API TRN_DownloadComplete(const char* data, size_t start_byte, size_t size, TRN_DownloadContainer cont);
TRN_API TRN_PDFDocDownloadPages(TRN_PDFDoc doc, TRN_UInt32* pages_arr, TRN_Size pages_arr_size, TRN_Bool cancel_others, TRN_Bool download_thumbs);
TRN_API TRN_PDFDocDownloadThumb(TRN_PDFDoc doc, TRN_UInt32 page_num, TRN_Obj* result);
TRN_API TRN_DownloaderCreate(struct TRN_DownloadCallbacks* callbacks, size_t file_size, TRN_UString cache_file, TRN_Downloader* result);
TRN_API TRN_DownloaderStop(TRN_Downloader downloader);
TRN_API TRN_DownloaderIsLinearizationValid(TRN_Downloader downloader, TRN_Bool* result);
TRN_API TRN_DownloaderGetRequiredChunks(TRN_Downloader downloader, TRN_UInt32 page_num, TRN_Size* buf, TRN_Size size);
TRN_API TRN_DownloaderGetRequiredChunksSize(TRN_Downloader downloader, TRN_UInt32 page_num, TRN_Size* result);
TRN_API TRN_GetDownloadChunkSize(TRN_Size* result);
TRN_API TRN_PDFDocDownloaderInitialize(TRN_PDFDoc doc, TRN_Downloader downloader);
TRN_API TRN_PDFDocGetTriggerAction(TRN_PDFDoc doc, enum TRN_PDFDocEventType trigger, TRN_Obj* result);
TRN_API TRN_PDFDocGetFinalObjRef(TRN_PDFDoc doc, TRN_UInt32 original_obj_num, TRN_UInt16 original_gen_num, TRN_UInt32* out_obj_num, TRN_UInt16* out_gen_num);

TRN_API TRN_PDFDocAppearancesToXodBuffer(TRN_PDFDoc in_pdfdoc, TRN_AppearanceReferenceList reference_list, TRN_Vector* result);



TRN_API TRN_PDFDocCreate (TRN_PDFDoc* result);
TRN_API TRN_PDFDocCreateFromSDFDoc(TRN_SDFDoc no_own_sdfdoc, TRN_PDFDoc* result);
TRN_API TRN_PDFDocCreateFromUFilePath (const TRN_UString filepath, TRN_PDFDoc* result);
TRN_API TRN_PDFDocCreateFromFilePath (const char* filepath, TRN_PDFDoc* result);
TRN_API TRN_PDFDocCreateFromFilter(TRN_Filter no_own_stream, TRN_PDFDoc* result);
TRN_API TRN_PDFDocCreateFromBuffer (const TRN_UChar* buf, TRN_Size buf_size, TRN_PDFDoc* result);
TRN_API TRN_PDFDocCreateFromLayoutEls(const char* buf, TRN_Size buf_size, TRN_PDFDoc* result);
TRN_API TRN_PDFDocCreateShallowCopy(TRN_PDFDoc source, TRN_PDFDoc* result);
TRN_API TRN_PDFDocDestroy (TRN_PDFDoc doc);
TRN_API TRN_PDFDocIsEncrypted(TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFDocInitSecurityHandler (TRN_PDFDoc doc, void* custom_data, TRN_Bool* result);
TRN_API TRN_PDFDocInitStdSecurityHandler(TRN_PDFDoc doc, const char* password, int password_sz, TRN_Bool* result); // Deprecated.
TRN_API TRN_PDFDocInitStdSecurityHandlerUString(TRN_PDFDoc doc, TRN_UString password, TRN_Bool* result);
TRN_API TRN_PDFDocInitStdSecurityHandlerBuffer(TRN_PDFDoc doc, const TRN_UInt8* password_buf, size_t password_buf_size, TRN_Bool* result);
TRN_API TRN_PDFDocGetSecurityHandler(TRN_PDFDoc doc, TRN_SecurityHandler* no_own_result);
TRN_API TRN_PDFDocSetSecurityHandler(TRN_PDFDoc doc, TRN_SecurityHandler no_own_handler);
TRN_API TRN_PDFDocRemoveSecurity(TRN_PDFDoc doc);
TRN_API TRN_PDFDocGetDocInfo(TRN_PDFDoc doc, TRN_PDFDocInfo* result );
TRN_API TRN_PDFDocGetViewPrefs(TRN_PDFDoc doc, TRN_PDFDocViewPrefs* result);
TRN_API TRN_PDFDocIsModified (const TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFDocHasRepairedXRef(const TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFDocIsLinearized(const TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFDocSave(TRN_PDFDoc doc, const TRN_UString path, TRN_UInt32 flags);
TRN_API TRN_PDFDocSaveMemoryBuffer(TRN_PDFDoc doc, TRN_UInt32 flags, const char** out_buf, TRN_Size* out_buf_size);
TRN_API TRN_PDFDocSaveStream(TRN_PDFDoc doc, TRN_Filter stream, TRN_UInt32 flags);
TRN_API TRN_PDFDocGetPageIterator(TRN_PDFDoc doc, TRN_UInt32 page_number, TRN_Iterator* result );
TRN_API TRN_PDFDocGetPage(TRN_PDFDoc doc, TRN_UInt32 page_number, TRN_Page* result);
TRN_API TRN_PDFDocPageRemove(TRN_PDFDoc doc, const TRN_Iterator page_itr);
TRN_API TRN_PDFDocPageInsert(TRN_PDFDoc doc, TRN_Iterator where, TRN_Page page);
TRN_API TRN_PDFDocInsertPages(TRN_PDFDoc dest_doc, TRN_UInt32 insert_before_page_number, TRN_PDFDoc src_doc, TRN_UInt32 start_page, TRN_UInt32 end_page, enum TRN_PDFDocInsertFlag flag);
TRN_API TRN_PDFDocInsertPageSet(TRN_PDFDoc dest_doc, TRN_UInt32 insert_before_page_number, TRN_PDFDoc src_doc, TRN_PageSet source_page_set, enum TRN_PDFDocInsertFlag flag);
TRN_API TRN_PDFDocMovePages(TRN_PDFDoc dest_doc, TRN_UInt32 move_before_page_number, TRN_PDFDoc src_doc, TRN_UInt32 start_page, TRN_UInt32 end_page, enum TRN_PDFDocInsertFlag flag);
TRN_API TRN_PDFDocMovePageSet(TRN_PDFDoc dest_doc, TRN_UInt32 move_before_page_number, TRN_PDFDoc src_doc, TRN_PageSet source_page_set, enum TRN_PDFDocInsertFlag flag);
TRN_API TRN_PDFDocPagePushFront(TRN_PDFDoc doc, TRN_Page page);
TRN_API TRN_PDFDocPagePushBack(TRN_PDFDoc doc, TRN_Page page);
TRN_API TRN_PDFDocImportPages(TRN_PDFDoc doc, const TRN_Page* page_buf, int buf_size, TRN_Bool import_bookmarks, TRN_Page* buf_result);
TRN_API TRN_PDFDocPageCreate(TRN_PDFDoc doc, const TRN_Rect* media_box, TRN_Page* result);
TRN_API TRN_PDFDocAppendTextDiffPage(TRN_PDFDoc doc, TRN_Page page1, TRN_Page page2);
TRN_API TRN_PDFDocAppendTextDiffDoc(TRN_PDFDoc doc, TRN_PDFDoc doc1, TRN_PDFDoc doc2);
TRN_API TRN_PDFDocGetFirstBookmark(TRN_PDFDoc doc, TRN_Bookmark* result );
TRN_API TRN_PDFDocAddRootBookmark(TRN_PDFDoc doc, TRN_Bookmark root_bookmark);
TRN_API TRN_PDFDocGetTrailer (TRN_PDFDoc doc, TRN_Obj* result);
TRN_API TRN_PDFDocGetRoot(TRN_PDFDoc doc, TRN_Obj* result);
TRN_API TRN_PDFDocJSContextInitialize(TRN_PDFDoc doc);
TRN_API TRN_PDFDocGetPages(TRN_PDFDoc doc, TRN_Obj* result);
TRN_API TRN_PDFDocGetPageCount (TRN_PDFDoc doc, int* result);
TRN_API TRN_PDFDocGetDownloadedByteCount (TRN_PDFDoc doc, TRN_UInt64* result);
TRN_API TRN_PDFDocGetTotalRemoteByteCount (TRN_PDFDoc doc, TRN_UInt64* result);
TRN_API TRN_PDFDocGetFieldIteratorBegin(TRN_PDFDoc doc, TRN_Iterator* result);
TRN_API TRN_PDFDocGetFieldIterator(TRN_PDFDoc doc, const TRN_UString field_name, TRN_Iterator* result);
TRN_API TRN_PDFDocGetField(TRN_PDFDoc doc, const TRN_UString field_name, TRN_Field* result);
TRN_API TRN_PDFDocFieldCreate(TRN_PDFDoc doc, const TRN_UString field_name, enum TRN_FieldType type, TRN_Obj field_value , TRN_Obj def_field_value, TRN_Field* result);
TRN_API TRN_PDFDocFieldCreateFromStrings(TRN_PDFDoc doc, const TRN_UString field_name, enum TRN_FieldType type, TRN_UString field_value , TRN_UString def_field_value, TRN_Field* result);
TRN_API TRN_PDFDocRefreshFieldAppearances(TRN_PDFDoc doc);
TRN_API TRN_PDFDocRefreshAnnotAppearances(TRN_PDFDoc doc, const TRN_OptionBase* options);
TRN_API TRN_PDFDocFlattenAnnotations(TRN_PDFDoc doc, TRN_Bool forms_only);
TRN_API TRN_PDFDocFlattenAnnotationsAdvanced(TRN_PDFDoc doc, TRN_UInt32 flags);
TRN_API TRN_PDFDocGetAcroForm(TRN_PDFDoc doc, TRN_Obj* result);
TRN_API TRN_PDFDocFDFExtract(TRN_PDFDoc doc, enum TRN_PDFDocExtractFlag flag, TRN_FDFDoc* result);
TRN_API TRN_PDFDocFDFExtractPageSet(TRN_PDFDoc doc, TRN_PageSet pages_to_extract, enum TRN_PDFDocExtractFlag flag, TRN_FDFDoc* result);
TRN_API TRN_PDFDocFDFExtractAnnots(TRN_PDFDoc doc, const TRN_Annot* annot_buf, int buf_size, TRN_FDFDoc* result);
TRN_API TRN_PDFDocFDFExtractCommand(TRN_PDFDoc doc, const TRN_Annot* annot_added_buf, int annot_added_buf_size, const TRN_Annot* annot_modified_buf, int annot_modified_buf_size, const TRN_Annot* annot_deleted_buf, int annot_deleted_buf_size, TRN_FDFDoc* result);
TRN_API TRN_PDFDocFDFMerge(TRN_PDFDoc doc, TRN_FDFDoc fdf_doc);
TRN_API TRN_PDFDocFDFUpdate(TRN_PDFDoc doc, TRN_FDFDoc fdf_doc);
TRN_API TRN_PDFDocFDFUpdateAppearanceDocs(TRN_PDFDoc doc, TRN_FDFDoc fdf_doc, TRN_AppearanceDocument* doc_list, int doc_list_size);
TRN_API TRN_PDFDocGetOpenAction(TRN_PDFDoc doc, TRN_Action* result);
TRN_API TRN_PDFDocSetOpenAction(TRN_PDFDoc doc, const TRN_Action action);
TRN_API TRN_PDFDocAddFileAttachment(TRN_PDFDoc doc, const TRN_UString file_key, TRN_FileSpec embedded_file);
TRN_API TRN_PDFDocGetPageLabel(TRN_PDFDoc doc, int page_num, TRN_PageLabel* result);
TRN_API TRN_PDFDocSetPageLabel(TRN_PDFDoc doc, int page_num, const TRN_PageLabel* label);
TRN_API TRN_PDFDocRemovePageLabel(TRN_PDFDoc doc, int page_num);
TRN_API TRN_PDFDocGetStructTree(TRN_PDFDoc doc, TRN_STree* result);
TRN_API TRN_PDFDocHasOC(TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFDocGetOCGs(TRN_PDFDoc doc, TRN_Obj* result);
TRN_API TRN_PDFDocGetOCGConfig(TRN_PDFDoc doc, TRN_OCGConfig* result);
TRN_API TRN_PDFDocCreateIndirectName(TRN_PDFDoc doc, const char* name, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectArray(TRN_PDFDoc doc, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectBool(TRN_PDFDoc doc, TRN_Bool value, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectDict(TRN_PDFDoc doc, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectNull(TRN_PDFDoc doc, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectNumber(TRN_PDFDoc doc, double value, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectString(TRN_PDFDoc doc, const TRN_UChar* value, TRN_UInt32 buf_size, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectStringFromUString(TRN_PDFDoc doc, const TRN_UString str, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectStreamFromFilter(TRN_PDFDoc doc, TRN_FilterReader data, TRN_Filter no_own_filter_chain, TRN_Obj* result);
TRN_API TRN_PDFDocCreateIndirectStream(TRN_PDFDoc doc, const char* data, const TRN_Size data_size, TRN_Filter no_own_filter_chain, TRN_Obj* result);
TRN_API TRN_PDFDocGetSDFDoc (TRN_PDFDoc doc, TRN_SDFDoc* no_own_result);
TRN_API TRN_PDFDocLock(TRN_PDFDoc doc);
TRN_API TRN_PDFDocUnlock(TRN_PDFDoc doc);
TRN_API TRN_PDFDocLockRead(TRN_PDFDoc doc);
TRN_API TRN_PDFDocUnlockRead(TRN_PDFDoc doc);
TRN_API TRN_PDFDocTryLock( TRN_PDFDoc doc, TRN_Bool* result );
TRN_API TRN_PDFDocTimedLock( TRN_PDFDoc doc, int milliseconds, TRN_Bool* result );
TRN_API TRN_PDFDocTryLockRead( TRN_PDFDoc doc, TRN_Bool* result );
TRN_API TRN_PDFDocTimedLockRead( TRN_PDFDoc doc, int milliseconds, TRN_Bool* result );
TRN_API TRN_PDFDocAddHighlights(TRN_PDFDoc doc, const TRN_UString hilite);
TRN_API TRN_PDFDocIsTagged(TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFDocHasSignatures(TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFDocHasDownloader(TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFDocAddSignatureHandler(TRN_PDFDoc doc, TRN_SignatureHandler signature_handler, TRN_SignatureHandlerId* result);
TRN_API TRN_PDFDocAddStdSignatureHandlerFromFile(TRN_PDFDoc doc, const TRN_UString pkcs12_file, const TRN_UString pkcs12_pass, TRN_SignatureHandlerId* result);
TRN_API TRN_PDFDocAddStdSignatureHandlerFromBuffer(TRN_PDFDoc doc, const TRN_UInt8* pkcs12_buffer, const TRN_Size pkcs12_buf_size, const TRN_UString pkcs12_pass, TRN_SignatureHandlerId* result);
TRN_API TRN_PDFDocRemoveSignatureHandler(TRN_PDFDoc doc, const TRN_SignatureHandlerId signature_handler_id);
TRN_API TRN_PDFDocGetSignatureHandler(TRN_PDFDoc doc, const TRN_SignatureHandlerId signature_handler_id, TRN_SignatureHandler* result);
TRN_API TRN_PDFDocGenerateThumbnails(TRN_PDFDoc doc, TRN_UInt32 size);
TRN_API TRN_PDFDocAppendVisualDiffWithOptsObj(TRN_PDFDoc doc, TRN_Page p1, TRN_Page p2, TRN_Obj opts_dict);
TRN_API TRN_PDFDocAppendVisualDiff(TRN_PDFDoc doc, TRN_Page p1, TRN_Page p2, const TRN_OptionBase* opts);
TRN_API TRN_PDFDocGetGeometryCollectionForPage(TRN_PDFDoc in_pdfdoc, int page_num, TRN_GeometryCollection* result);
TRN_API TRN_PDFDocGetUndoManager(TRN_PDFDoc doc, TRN_UndoManager* result);
TRN_API TRN_PDFDocCreateDigitalSignatureField(TRN_PDFDoc doc, const TRN_UString in_sig_field_name, TRN_DigitalSignatureField* result);
TRN_API TRN_PDFDocGetDigitalSignatureField(TRN_PDFDoc doc, const TRN_UString field_name, TRN_DigitalSignatureField* result);
TRN_API TRN_PDFDocGetDigitalSignatureFieldIteratorBegin(TRN_PDFDoc doc, TRN_Iterator* result);
TRN_API TRN_PDFDocGetDigitalSignaturePermissions(TRN_PDFDoc doc, enum TRN_DigitalSignatureField_DocumentPermissions* result);
TRN_API TRN_PDFDocSaveViewerOptimized(TRN_PDFDoc doc, const TRN_UString path, const TRN_Obj opts);
TRN_API TRN_PDFDocSaveViewerOptimizedBuffer(TRN_PDFDoc doc, const char** out_buf, TRN_Size* out_buf_size, const TRN_Obj opts);
TRN_API TRN_PDFDocVerifySignedDigitalSignatures(TRN_PDFDoc doc, TRN_VerificationOptions opts, enum TRN_PDFDocSignaturesVerificationStatus* result);
// #define JDM 1
#ifdef JDM
	struct TRN_displist_;
	typedef struct TRN_displist_* TRN_DispList;

	TRN_API TRN_DispListCreate(TRN_Page page, TRN_DispList* result);
	TRN_API TRN_DispListTag(TRN_DispList lst, double* rects, TRN_Size rect_num, const char* tag, TRN_Obj prop_dict, TRN_Bool intersect_mode, TRN_Bool reshuffle, TRN_Bool* result);
	TRN_API TRN_DispListClearTags(TRN_DispList lst);
	TRN_API TRN_DispListSave(TRN_DispList lst, TRN_Page page);
	TRN_API TRN_DispListDestroy(TRN_DispList lst);
#endif


#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFDoc
