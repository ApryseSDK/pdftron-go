//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFDocumentPreviewCache
#define PDFTRON_H_CPPPDFDocumentPreviewCache

#include <C/PDF/TRN_DocumentPreviewCache.h>
#include <Common/UString.h>
#include <Common/Common.h>

namespace pdftron { 
	namespace PDF {

/**
 *	DocumentPreviewCache
 *
 *	DocumentPreviewCache is a persistent cache that provides thumbnails for browsing in PDFNet.
 *   The cache is placed in the sub-directory 'trn_DocumentPreviewCache' of the PDFNet Resources folder,
 *   which can be set by calling PDFNet::SetPersistentCachePath. In the case the
 *   PersistentCachePath is not set the files will be stored in the system temp path
 *   (PDFNet::GetSystemTempPath()). The cache will be used by any PDFNet process that
 *	uses the resource path.  If more than one PDFNet process is running concurrently,
 *	the first process to acquire a lock on the cache will use it.  Subsequent processes
 *	will not read or modify the cache.
 *
 *	DocumentPreviewCache will store references to generated JPG thumbnails and keeps track of
 *   the dimensions of the thumbnail and the filesize of the specific pdf documents.
 *   Furthermore it takes care that the size constraints (max_cache_bytes, max_disk_percentage)
 *   are met and in cleans the oldest (in terms of last request) thumbs from the cache
 *   in case of a overflow.
 *
 *   If the user requests a file that is already in the cache and the requested thumb dimensions
 *   are smaller or equal than the ones of the cache-version the URL of the cached thumb is given
 *   back. If the dimensions are bigger the thumb gets rendered again, the old thumb gets
 *   replaced and the URL is given back.
 *
 *   If the size of the pdf document changes the thumb will be rendered again even when there is
 *   a version of that thumbnail in the cache. In case that the user wants to suppress the
 *   re-rendering of that specific thumb (e.g. when the change on the pdf document was made
 *   on another page than the first page which is used for the thumb), IrrelevantChangeMade has to
 *	be called.
 */
class DocumentPreviewCache
{
public:
	/**
	 * thumb_result contains the valid result states of requesting a thumbnail
	 */
	enum preview_result{
		e_failure,			///< The thumbnail could not be retrieved.
		e_success,			///< Successful retrieval of the thumbnail.
		e_security_error,	///< Failure due to password restriction.
		e_cancel,			///< The request was cancelled before it was processed.
		e_package_error		///< Failure due to encountering a PDF package
	};

	/**
	 * Callback for GetBitmap
	 *
	 * @param result Contains the information about the result of GetBitmap
	 * @param utf8_filepath An UTF-8, null terminated C-String containing the file path of the retrieved thumbnail. In case of failure utf8_filepath is empty.
	 * @param custom_data Custom data specified by the user.
	 */
	typedef void(*PreviewHandler) (preview_result result, const char* utf8_filepath, void* custom_data);


	/**
	 * Initialize the thumbnail cache. If the cache already exists, it will
	 *	shrink to conform to these limits immediately.
	 *
	 * @param max_cache_bytes The absolute maximum size on disk for the temporary thumbnail cache in bytes.
	 * @param max_disk_percentage The maximum percentage of free disk space that the cache can take up (0 - 1.0).
	 */
	static void Initialize(UInt64 max_cache_bytes, double max_disk_percentage);

	
	/**
	 * GetBitmap gets the path to the thumbnail in the DocumentPreviewCache associated with the document at 'filepath'.
	 *   The decision if the thumb should be re-rendered is based on two factors.
	 *   First if the current version fulfills the minimal dimensions 'min_x_size' x 'min_y_size' and
	 *   second if the size of the pdf document hasn't changed. To signal an edit of the pdf document without
	 *   a resulting re-rendering of the thumb see IrrelevantChangeMade.
	 *
	 * @param filepath - The URL of the pdf file.
	 * @param min_x_size - Minimal width of the thumbnail.
	 * @param min_y_size - Minimal height of the thumbnail.
	 * @param proc - A callback function that will be called after the thumbnail is retrieved, or if that retrieval fails.
	 * @param custom_data - Custom data to be passed to the ThumbPreviewHandler.
	 */
	static void GetBitmapWithPath(const UString& filepath, UInt32 min_x_size, UInt32 min_y_size, PreviewHandler proc, void* custom_data);

	
	/**
	 * CancelAllRequests cancels all pending requests.
	 *   The ThumbPreviewHandler of each pending request will signal that the thumb could not be found.
	 */
	static void CancelAllRequests();

	
	/**
	 * CancelRequest cancels all pending thumbnail requests associated with 'filepath'.
	 *   If the cancel request is processed earlier than the path of the thumbnail could be retrieved
	 *   the respective request will be cancelled and the ThumbPreviewHandler will signal that the thumb could not be found.
	 *
	 * @param filepath - URL of pdf file
	 */
	static void CancelRequest(const UString& filepath);

	
	/**
	 * IrrelevantChangeMade should be called if the size of the pdf file at 'filepath' was changed but the thumbnail 
	 *   should not be re-generated. This should be done when no editing was done on the first page of the document
	 *   or merely annotations were added on the front page.
	 *
	 * @param filepath - URL of pdf file
	 */
	static void IrrelevantChangeMade(const UString& filepath);

	
	/**
	 * Remove the cache from the disk completely, deleting any thumbnails. You may want to do this if you detect some kind
	 *	of corruption, or if the user wants to clear out disk space used by your application.
	 */
	static void ClearCache();
};

#include <Impl/DocumentPreviewCache.inl>

	} // PDF
} // pdftron

#endif // PDFTRON_H_CPPPDFDocumentPreviewCache
