//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFReflowProcessor
#define PDFTRON_H_CPPPDFReflowProcessor

#include <C/PDF/TRN_ReflowProcessor.h>
#include <PDF/JobRequest.h>
#include <PDF/Page.h>
#include <Common/UString.h>

namespace pdftron {
	namespace PDF {

/************************************************************************/
/* ReflowProcessor                                                      */
/************************************************************************/
/**
* ReflowProcessor is a processor that manages the requests of converting PDF page documents to
*     reflow documents as HTML files. The output reflowable HTML file is identified by the requested page
*     itself. For each PDF document that at least one of its page is requested for converting to reflow,
*     a folder is created in cache directory. The folder name will be set to a unique ID of the PDF document
*     (obtained from PDFUtil::GetUniqueIdString).
*     Also, the output HTML file is obtained by the page object number. For example, the output HTML path
*     of a PDF page with document ID of 2740180447,229945,WT1NOmJhyyH9xNqwbEbbOg== and object number
*     of 123 will be ../trn_reflowcache/2740180447,229945,WT1NOmJhyyH9xNqwbEbbOg==/123.html
*
* The cache is placed in the sub-directory 'trn_reflowcache' of the PDFNet Resources folder, which can be
*    set by calling PDFNet::SetPersistentCachePath. In the case the PersistentCachePath is not set the HTML
*    files will be stored in the system temp path (PDFNet::GetSystemTempPath()). The cache will be used by any
*    PDFNet process that uses the resource path. If more than one PDFNet process is running concurrently, the
*    first process to acquire a lock on the cache will use it. Subsequent processes will not read or modify
*    the cache.
*/
class ReflowProcessor
{
public:
	/**
	* Initializes reflow cache and job queues.
	*
	* NOTE: This method clears everything in reflow disk cache.
	*/
	static void Initialize();
	/**
	* Checks whether reflow has been already initialized or not.
	*/
	static bool IsInitialized();
	/**
	* Requests for extracting reflow from a page and calling back the proc handler thereafter
	*
	* @param page - The page
	* @param proc - A callback function that will be called after the process is finished, or if that process fails
	* @param custom_data - Custom data to be passed to the ProcHandler
	*/
	static void GetReflow(const Page & page, JobRequest::ProcHandler proc, void * custom_data);
	/**
	* Cancels all job requests.
	*/
	static void CancelAllRequests();
	/**
	* Cancels the request associated with a certain page.
	*/
	static void CancelRequest(const Page & page);
	/**
	* Cancels all requests belonging to the document.
	*/
	//static void CancelRequest(const string & doc_id);
	/**
	* clears the reflow disk cache.
	*/
	static void ClearCache();
	/**
	* sets the content when a page doesn't contain reflowable text
	*/
	static void SetNoReflowContent(const UString & utf8_content);
	/**
	* sets the content when it is failed to extract reflowable text
	*/
	static void SetReflowFailedContent(const UString & utf8_content);
};

#include <Impl/ReflowProcessor.inl>

	}	// namespace PDF
}	// namespace pdftron

#endif PDFTRON_H_CPPPDFReflowProcessor