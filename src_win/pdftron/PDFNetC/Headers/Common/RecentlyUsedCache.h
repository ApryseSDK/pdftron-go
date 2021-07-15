//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPCommonRecentlyUsedCache
#define PDFTRON_H_CPPCommonRecentlyUsedCache

#include <C/Common/TRN_RecentlyUsedCache.h>
#include <Common/UString.h>
#include <Common/Common.h>

namespace pdftron { 
	namespace Common {

/**
 *	RecentlyUsedCache
 *	
 *	RecentlyUsedCache is a persistent cache that provides thumbnails for recently
 *	used documents in PDFNet.  The cache is stored in the PDFNet Resources folder,
 *	which can be set by calling PDFNet::SetPersistentCachePath. The cache will be used by
 *	any PDFNet process that uses the resource path.  If more than one PDFNet process
 *	is running concurrently, the first process to acquire a lock on the cache will
 *	use it.  Subsequent processes will not read or modify the cache.
 *
 *	Recently used cache will track the order of N recently used documents, and store
 *	references to generated PNG thumbnails for those documents.  Most of this functionality
 *	happens 'magically', without any necessary user action.
 *
 *
 */
class RecentlyUsedCache
{
public:
	/** 
	 * Removes the document from the recently used list 
	 * 
	 * @param document_path path to the document to remove.
	 */
	static void RemoveDocument(const UString& document_path);

	/** 
	 * Marks the document as having been accessed. This happens
	 *	implicitly when calling PDFViewCtrl::SetDoc, but depending
	 *	on your use case, you may also want to call it explicitly.
	 * 
	 * @param document_path path to the document being accessed.
	 */
	static void AccessDocument(const UString& document_path);

	/** 
	 * Get the path to the thumbnail PNG associated with the document.
	 *	Even if the document is in the recently accessed list, there is
	 *	no guarantee it will have an associated PNG.
	 * 
	 * @param document_path path to the document whose bitmap you want to retrieve.
	 * @return the path to the PNG bitmap, if it exists. Otherwise, an empty string.
	 *
	 */
	static UString GetBitmapPathIfExists(const UString& document_path);

	/** 
	 * Blast away the cache from the disk completely, removing any thumbnails
	 *	and recently used state. You may want to do this if you detect some kind
	 *	of corruption, or if the user wants to clear out disk space used by your
	 *	application.
	 */
	static void ResetCache();

	/** 
	 * Initialize the Recently used cache with the provided limits.  If the cache already exists, it will
	 *	shrink to conform to these limits immediately.
	 *
	 * @param num_documents the number of documents to track in the recently used list.
	 * @param max_absolute_space the maximum space, in bytes, the thumbnails can occupy on disk.
	 * @param max_percentage_space the maximum percentage of free space, in range 0 - 1.0, the thumbnails can occupy on disk.

	 */
	static void InitializeRecentlyUsedCache(size_t num_documents, size_t max_absolute_space, double max_percentage_space);
};

#include <Impl/RecentlyUsedCache.inl>

	} // Common
} // pdftron

#endif // PDFTRON_H_CPPCommonRecentlyUsedCache
