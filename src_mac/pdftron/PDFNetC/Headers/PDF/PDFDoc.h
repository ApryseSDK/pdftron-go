//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPDFDoc
#define PDFTRON_H_CPPPDFPDFDoc

#include <Common/BasicTypes.h>
#include <FDF/FDFDoc.h>
#include <PDF/PDFDocInfo.h>
#include <PDF/PageLabel.h>
//#include <PDF/OCG/Config.h>
#include <C/PDF/TRN_PDFDoc.h>
#include <PDF/PDFDocViewPrefs.h>
#include <SDF/SDFDoc.h>
#include <PDF/Page.h>
#include <PDF/PageSet.h>
#include <PDF/DiffOptions.h>
#include <PDF/Annot.h>
#include <Common/Iterator.h>
#include <SDF/SignatureHandler.h>
#include <SDF/UndoManager.h>
#include <PDF/DigitalSignatureField.h>
#include <PDF/ViewerOptimizedOptions.h>
#include <PDF/RefreshOptions.h>

namespace pdftron {
	namespace PDF {
		namespace OCG{
			class Config;
		}
		namespace Struct{class STree;};

/**
 * PageIterator is an iterator type that can be used to traverse a list of 
 * pages in a PDF document. For more information, please PDFDoc::GetPageIterator().
 */ 
typedef Common::Iterator<Page> PageIterator;

/**
 * FieldIterator is an iterator type that can be used to traverse a list of 
 * form fields in a PDF document. For more information, please PDFDoc::GetFieldIterator().
 */ 
typedef Common::Iterator<Field> FieldIterator;

/**
 * DigitalSignatureFieldIterator is an iterator type that can be used to traverse a list of 
 * digital signature form fields in a PDF document. 
 */ 
typedef Common::Iterator<DigitalSignatureField> DigitalSignatureFieldIterator;

/** 
 * PDFDoc is a high-level class describing a single PDF (Portable Document 
 * Format) document. Most applications using PDFNet will use this class to 
 * open existing PDF documents, or to create new PDF documents from scratch.
 * 
 * The class offers a number of entry points into the document. For example,
 *  - To access pages use pdfdoc.GetPageIterator() or pdfdoc.GetPage(page_num).
 *  - To access form fields use pdfdoc.GetFieldIterator(), pdfdoc.GetFieldIterator(name) or pdfdoc.GetField(name).
 *  - To access document's meta-data use pdfdoc.GetDocInfo().
 *  - To access the outline tree use pdfdoc.GetFirstBookmark().
 *  - To access low-level Document Catalog use pdfdoc.GetRoot().
 *  ...
 * 
 * The class also offers utility methods to slit and merge PDF pages, 
 * to create new pages, to flatten forms, to change security settings, etc.
 */
class PDFDoc
{
public:

	/**
	 * Default constructor. Creates an empty new document.
	 */
	 PDFDoc ();

	/**
	 * Create a PDF document from an existing SDF/Cos document.
	 * 
	 * @param sdfdoc a pointer to the SDF document. Created PDFDoc will 
	 * take the ownership of the low-level document.
	 * 
	 * @note the SDFDoc will become invalid.  If you would
	 * like to access the low level document use GetSDFDoc
	 */
	 PDFDoc (SDF::SDFDoc& sdfdoc);

	 /**
	 * Create a shallow copy of another PDFDoc
	 *
	 * @param other a reference to the PDF document to clone. Created PDFDoc will
	 * retain a reference to the same low-level document as the source.
	 *
	 */
	 PDFDoc(const PDFDoc& other);
	 PDFDoc& operator= (const PDFDoc&);

	/**
	 * Open an existing PDF document
	 *
	 * @param filepath - pathname to the file.
	 *
	 * @note Make sure to call InitSecurityHandler() after PDFDoc(...) in case 
	 * a document is encrypted
	 */
	 PDFDoc (const UString& filepath);
	 PDFDoc (const char* filepath);

	/**
	 * Open an existing PDF document
	 *
	 * @param stream - input stream containing a serialized document. The input stream may be a 
	 * random-access file, memory buffer, slow HTTP connection etc.
	 *
	 * @note if the input stream doesn't support Seek() operation the document will load whole 
	 * data stream in memory before parsing. In case of linearized PDF, the document may be parsed 
	 * on-the-fly while it is being loaded in memory. Note that since MappedFile implements Seek() 
	 * interface, the document does not have to be fully in memory before it is used.
	 * 
	 * @note Make sure to call InitSecurityHandler() after PDFDoc(...) for encrypted documents.
	 * @note PDFDoc takes the ownership of the stream.
	 */
	 PDFDoc (Filters::Filter stream);

	/**
	 * Open a SDF/Cos document from a memory buffer.
	 * @note the document should be fully loaded in the memory buffer. 
	 * @note the buffer ownership is not transfered to the document so the user should 
	 * clean-up any allocated memory if necessary.
	 * 
	 * @param buf - a memory buffer containing the serialized document
	 * @param buf_size - the size of memory buffer.
	 */
	 PDFDoc (const UChar* buf, size_t buf_size);

	/**
	 *	Destructor
	 */
	 ~PDFDoc ();

	/**
	 *	Close PDFDoc
	 */
	 void Close();

	/**
	 * @return true if the document is/was originally encrypted false otherwise.
	 */ 
	 bool IsEncrypted();

	/**
	 * Initializes document's SecurityHandler. This version of InitSecurityHandler() 
	 * works with Standard and Custom PDF security and can be used in situations where 
	 * the password is obtained dynamically via user feedback. See EncTest sample for 
	 * example code.
	 * 
	 * This function should be called immediately after an encrypted 
	 * document is opened. The function does not have any side effects on 
	 * documents that are not encrypted.
	 * 
	 * If the security handler was successfully initialized it can be later obtained
	 * using GetSecurityHandler() method.
	 *
	 * @exception An exception is thrown if the matching handler for document's 
	 * security was not found in the global SecurityManager. In this case, you 
	 * need to register additional custom security handlers with the global 
	 * SecurityManager (using SecurityManagerSingleton).
	 * 
	 * @return true if the SecurityHandler was successfully initialized (this 
	 * may include authentication data collection, verification etc.), 
	 * false otherwise.
	 * 
	 * @param custom_data An optional parameter used to specify custom data 
	 * that should be passed in SecurityHandler::Initialize() callback.
	 */
	bool InitSecurityHandler (
#ifndef SWIG
		void* custom_data = 0
#endif
		);

	/**
	 * Initializes document's SecurityHandler using the supplied 
	 * password. This version of InitSecurityHandler() assumes that 
	 * document uses Standard security and that a password is specified 
	 * directly.
	 * 
	 * This function should be called immediately after an encrypted 
	 * document is opened. The function does not have any side effects on 
	 * documents that are not encrypted.
	 * 
	 * If the security handler was successfully initialized, it can be later 
	 * obtained using GetSecurityHandler() method.
	 * 
	 * @return true if the given password successfully unlocked the document,
	 * false otherwise.
	 * 
	 * @exception An exception is thrown if the document's security Filter is 
	 * not 'Standard'. In this case, you need to register additional custom 
	 * security handlers with the global SecurityManager (SecurityManagerSingleton).
	 *
	 * @param password Specifies the password used to open the document without 
	 * any user feedback. If you would like to dynamically obtain the password, 
	 * you need to derive a custom class from StdSecurityHandler() and use 
	 * InitSecurityHandler() without any parameters. See EncTest sample 
	 * for example code.
	 *
	 * @param password_sz An optional parameter used to specify the size of 
	 * the password buffer, in bytes. If the 'password_sz' is 0, or if the parameter 
     * is not specified, the function assumes that the string is null terminated.
     *
     * @remark Deprecated. Use versions that accepts UString or buffer instead.
	 */
	 bool InitStdSecurityHandler(const char* password, int password_sz);

	/**
	 * Initializes document's SecurityHandler using the supplied 
	 * password. This version of InitSecurityHandler() assumes that 
	 * document uses Standard security and that a password is specified 
	 * directly.
	 * 
	 * This function should be called immediately after an encrypted 
	 * document is opened. The function does not have any side effects on 
	 * documents that are not encrypted.
	 * 
	 * If the security handler was successfully initialized, it can be later 
     * obtained using GetSecurityHandler() method.
     *
     * @param password Specifies the password used to open the document without
     * any user feedback. If you would like to dynamically obtain the password,
     * you need to derive a custom class from StdSecurityHandler() and use
     * InitSecurityHandler() without any parameters. See EncTest sample
     * for example code.
	 * 
	 * @return true if the given password successfully unlocked the document,
	 * false otherwise.
	 * 
	 * @exception An exception is thrown if the document's security Filter is 
	 * not 'Standard'. In this case, you need to register additional custom 
	 * security handlers with the global SecurityManager (SecurityManagerSingleton).
	 */
    bool InitStdSecurityHandler(const pdftron::UString& password);
    
	/**
	 * Initializes document's SecurityHandler using the supplied 
	 * password. This version of InitSecurityHandler() assumes that 
	 * document uses Standard security and that a password is specified 
	 * directly.
	 * 
	 * This function should be called immediately after an encrypted 
	 * document is opened. The function does not have any side effects on 
	 * documents that are not encrypted.
	 * 
	 * If the security handler was successfully initialized, it can be later 
     * obtained using GetSecurityHandler() method.
     *
     * @param password_buf Specifies the password used to open the document without
     * any user feedback. If you would like to dynamically obtain the password,
     * you need to derive a custom class from StdSecurityHandler() and use
     * InitSecurityHandler() without any parameters. See EncTest sample
     * for example code.
	 * 
	 * @return true if the given password successfully unlocked the document,
	 * false otherwise.
	 * 
	 * @exception An exception is thrown if the document's security Filter is 
	 * not 'Standard'. In this case, you need to register additional custom 
	 * security handlers with the global SecurityManager (SecurityManagerSingleton).
	 */
    bool InitStdSecurityHandler(const std::vector<UInt8>& password_buf);

	/**
	 * @return Currently selected SecurityHandler.
	 *
	 * @note InitSecurityHandler() should be called before GetSecurityHandler() 
	 * in order to initialize the handler.
	 *
	 * @note Returned security handler can be modified in order to change the 
	 * security settings of the existing document. Changes to the current handler 
	 * will not invalidate the access to the original file and will take effect 
	 * during document Save().
	 * 
	 * @note If the security handler is modified, document will perform a full save 
	 * even if e_incremental was given as a flag in Save() method.
	 */
	 SDF::SecurityHandler GetSecurityHandler ();

	/**
	 * The function sets a new SecurityHandler as the current security handler.
	 *
	 * @param handler new SecurityHandler
	 * 
	 * @note Setting a new security handler will not invalidate the access to
	 * the original file and will take effect during document Save().
	 * 
	 * @note If the security handler is modified, document will perform a full save 
	 * even if e_incremental was given as a flag in Save() method.
	 */
	 void SetSecurityHandler(const SDF::SecurityHandler & handler);

	/**
	 * This function removes document security.
	 */
	 void RemoveSecurity();

    /**
     * Indicates whether this documents contains any digital signatures.
     * @return True if a digital signature is found in this PDFDoc.
     */
    bool HasSignatures();

    /**
     * Adds a signature handler to the signature manager.
     *
     * @param signature_handler The signature handler instance to add to the signature manager.
     *
     * @return A unique ID representing the SignatureHandler within the SignatureManager.
     */
    SDF::SignatureHandlerId AddSignatureHandler(const SDF::SignatureHandler& signature_handler);

    /**
     * Adds a standard (built-in) signature handler to the signature manager. This method will use cryptographic
     * algorithm based on Adobe.PPKLite/adbe.pkcs7.detached filter to sign a PDF.
     *
     * @param pkcs12_file The private key certificate store to use.
     * @param pkcs12_pass The passphrase for the provided private key.
     *
     * @return A unique ID representing the SignatureHandler within the SignatureManager.
     */
    SDF::SignatureHandlerId AddStdSignatureHandler(const UString& pkcs12_keyfile, const UString& pkcs12_keypass);

    /**
     * Adds a standard (built-in) signature handler to the signature manager. This method will use cryptographic
     * algorithm based on Adobe.PPKLite/adbe.pkcs7.detached filter to sign a PDF.
     *
     * @param pkcs12_keybuffer The private key certificate store to use (as a data buffer in an array of bytes).
     * @param pkcs12_pass The passphrase for the provided private key.
     *
     * @return A unique ID representing the SignatureHandler within the SignatureManager.
     */
    SDF::SignatureHandlerId AddStdSignatureHandler(const std::vector<unsigned char>& pkcs12_keybuffer, const UString& pkcs12_keypass);

    /**
     * Removes a signature handler from the signature manager.
     *
     * @param signature_handler_id The unique id of the signature handler to remove.
     */
    void RemoveSignatureHandler(const SDF::SignatureHandlerId signature_handler_id);

    /**
     * Gets the associated signature handler instance from the signature manager by looking it up with the handler name.
     *
     * @param signature_handler_id The unique id of the signature handler to get.
     *
     * @return The signature handler instance if found, otherwise NULL.
     */
    SDF::SignatureHandler* GetSignatureHandler(const SDF::SignatureHandlerId signature_handler_id);

    /**
     * @return The UndoManager object (one-to-one mapped to document)
     */
    SDF::UndoManager GetUndoManager();

	/**
	 * Creates an unsigned digital signature form field inside the document.
	 * 
	 * @param in_sig_field_name The fully-qualified name to give the digital signature field. If one is not provided, a unique name is created automatically.
	 * 
	 * @return A DigitalSignatureField object representing the created digital signature field.
	 */
	PDF::DigitalSignatureField CreateDigitalSignatureField(const UString& in_sig_field_name = "");
	
	/**
	 * Retrieves an iterator that iterates over digital signature fields.
	 * 
     * @return An iterator that iterates over digital signature fields.
     */
	PDF::DigitalSignatureFieldIterator GetDigitalSignatureFieldIterator();
	
	/**
	 * Retrieves the most restrictive document permissions locking level from 
	 * all of the signed digital signatures in the document.
	 *
	 * @return An enumerated value representing the most restrictive document permission level found in the document.
	 */
	PDF::DigitalSignatureField::DocumentPermissions GetDigitalSignaturePermissions() const;
	
	/**
	 * @return The class representing document information metadata.
	 * (i.e. entries in the document information dictionary). 
	 */
	PDFDocInfo GetDocInfo();

	/**
	 * @return Viewer preferences for this document.
	 * 
	 * PDFDocViewPrefs is a high-level utility class that can be 
	 * used to control the way the document is to be presented on 
	 * the screen or in print.
	 */
	 PDFDocViewPrefs GetViewPrefs();

	 enum ActionTriggerEvent
	 {
		 e_action_trigger_doc_will_close = 17, //Triggered before closing a document
		 e_action_trigger_doc_will_save = 18, //Triggered before saving a document
		 e_action_trigger_doc_did_save = 19, //Triggered after saving a document
		 e_action_trigger_doc_will_print = 20, //Triggered before printing a document
		 e_action_trigger_doc_did_print = 21 //Triggered after printing a document
	 };

	 /**
	 * Get the Action associated with the selected Doc Trigger event.
	 *
	 * @param trigger the type of trigger event to get
	 * @return the Action Obj if present, otherwise NULL
	 */
	 SDF::Obj GetTriggerAction(PDFDoc::ActionTriggerEvent trigger);

	/**
	 * Call this function to determine whether the document has been modified since 
	 * it was last saved.
	 * 
	 * @return - true if document was modified, false otherwise
	 */
	 bool IsModified () const; 

	 /**
	 * Checks whether or not the underlying file has an XRef table that had to be repaired
	 * when the file was opened. If the document had an invalid XRef table when opened,
	 * PDFNet will have repaired the XRef table for its working representation of the document.
	 *
	 * @return - true if document was found to be corrupted, and was repaired, during
	 * opening and has not been saved since.
	 *
	 * @note - If this function returns true, it is not possible to incrementally save the document
	 * (see http://www.pdftron.com/kb_corrupt_xref)
	 */
	 bool HasRepairedXRef() const;

	/**
	 * Call this function to determine whether the document is represented in 
	 * linearized (fast web view) format.
	 * 
	 * @return - true if document is stored in fast web view format, false otherwise.
	 * 
	 * @note any changes to the document can invalidate linearization. The function will 
	 * return 'true' only if the original document is linearized and if it is not 
	 * modified.
	 *
	 * In order to provide good performance over relatively slow communication links, 
	 * PDFNet can generate PDF documents with linearized objects and hint tables that 
	 * can allow a PDF viewer application to download and view one page of a PDF file 
	 * at a time, rather than requiring the entire file (including fonts and images) to 
	 * be downloaded before any of it can be viewed.
	 * 
	 * To save a document in linearized (fast web view) format you only need to pass 
	 * 'Doc.SaveOptions.e_linearized' flag in the Save method.
	 */
	 bool IsLinearized() const;
    
    /**
     * Indicates whether this document was created via the `PDFViewCtrl` method `OpenURLAsync`.
     * @return True if the document was created via the `PDFViewCtrl` method `OpenURLAsync`; False otherwise.
     */
    bool HasDownloader();
    
    /**
     *
     * Returns the number of bytes that have been downloaded, when `HasDownloader()` is True.
     *
     * @return The number bytes downloaded.
     *
     * @exception if 'HasDownloader()` returns False, calling this method will result
     * in an exception.
     */
    UInt64 GetDownloadedByteCount ();
    
    /**
     *
     * Returns the document's total size in bytes, when `HasDownloader()` is True.
     *
     * @return The total number of bytes in the remote document.
     *
     * @exception if 'HasDownloader()` returns False, calling this method will result
     * in an exception.
     */
    UInt64 GetTotalRemoteByteCount ();

	/**
	 * Saves the document to a file. 
	 * 
	 * If a full save is requested to the original path, the file is saved to a file 
	 * system-determined temporary file, the old file is deleted, and the temporary file 
	 * is renamed to path.
	 * 
	 * A full save with remove unused or linearization option may re-arrange object in 
	 * the cross reference table. Therefore all pointers and references to document objects 
	 * and resources should be re acquired in order to continue document editing.
	 * 
	 * In order to use incremental save the specified path must match original path and 
	 * e_incremental flag bit should be set. 
	 * 
	 * @param path - The full path name to which the file is saved.
	 * @param flags - A bit field composed of an OR of SDFDoc::SaveOptions values.
	 * 
	 * @exception - if the file can't be opened for saving or if there is a problem during Save 
	 *	an Exception object will be thrown.
	 *
	 * @note - Save will modify the PDFDoc object's internal representation.  As such, 
	 *			  the user should acquire a write lock before calling save.
	 *
	 * @note - If the original pdf has a corrupt xref table (see HasRepairedXref), then
	 * it can not be saved using the e_incremental flag.
	 */
	 void Save(const UString& path, UInt32 flags);

#ifndef SWIG
	 /**
	  * Saves the document to a file.
	  *
	  * If a full save is requested to the original path, the file is saved to a file
	  * system-determined temporary file, the old file is deleted, and the temporary file
	  * is renamed to path.
	  *
	  * A full save with remove unused or linearization option may re-arrange object in
	  * the cross reference table. Therefore all pointers and references to document objects
	  * and resources should be re acquired in order to continue document editing.
	  *
	  * In order to use incremental save the specified path must match original path and
	  * e_incremental flag bit should be set.
	  *
	  * @param path - The full path name to which the file is saved.
	  * @param flags - A bit field composed of an OR of SDFDoc::SaveOptions values.
	  * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
	  *
	  * @exception - if the file can't be opened for saving or if there is a problem during Save
	  *	an Exception object will be thrown.
	  *
	  * @note - Save will modify the PDFDoc object's internal representation.  As such,
	  *			  the user should acquire a write lock before calling save.
	  *
	  * @note - If the original pdf has a corrupt xref table (see HasRepairedXref), then
	  * it can not be saved using the e_incremental flag.
	  */
	 void Save(const UString& path, UInt32 flags, Common::ProgressMonitor* progress);
#endif
	 
	 std::vector<unsigned char> Save(UInt32 flags);

#ifndef SWIG
	 /**
	  * Saves the document to a memory buffer.
	  *
	  * @param out_buf a pointer to the buffer containing the serialized version of the
	  * document. (C++ Note) The buffer is owned by a document and the client doesn't need to
	  * do any initialization or cleanup.
	  * @param out_buf_size the size of the serialized document (i.e. out_buf) in bytes.
	  *
	  * @param flags - A bit field composed of an OR of SDFDoc::SaveOptions values. Note that
	  * this method ignores e_incremental flag.
	  * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
	  *
	  * @exception - if there is a problem during Save an Exception object will be thrown.
	  *
	  * @note - Save will modify the PDFDoc object's internal representation.  As such,
	  *			  the user should acquire a write lock before calling save.
	  *
	  * @note - If the original pdf has a corrupt xref table (see HasRepairedXref), then
	  * it can not be saved using the e_incremental flag.
	  */
	 void Save(const char* &out_buf, size_t& out_buf_size, UInt32 flags, Common::ProgressMonitor* progress);  
#endif

     /**
	 * Saves the document to a stream.
	 * 
	 * @param stream The output stream where to write data.
	 * @param flags - A bit field composed of an OR of the SDFDoc::SaveOptions values. 
	 *
	 * @exception - if there is a problem during Save an Exception object will be thrown.
	 *
	 * @note - Save will modify the PDFDoc object's internal representation.  As such, 
	 *			  the user should acquire a write lock before calling save.
	 *
	 * @note - If the original pdf has a corrupt xref table (see HasRepairedXref), then
	 * it can not be saved using the e_incremental flag.
	 */
	 void Save(Filters::Filter& stream, UInt32 flags); 

	/**
	 * Use the Next() method on the returned iterator to traverse all pages in the document. 
	 * For example:
	 * @code 
	 *   PageIterator itr = pdfdoc.GetPageIterator();
	 *   while (itr.HasNext()) { //  Read every page
	 *      Page page = itr.Current();
	 *      // ...
	 *      itr.Next()
	 *   }
	 * @endcode
	 * 
	 * For full sample code, please take a look at ElementReader, PDFPageTest and PDFDraw sample projects.
	 * @return an iterator to the first page in the document.
	 * @param page_number page to set the iterator on. 1 corresponds to the first page.
	 */
	 PageIterator GetPageIterator(UInt32 page_number=1);

	/**
	 * @param page_number - the page number in document's page sequence. Page numbers 
	 * in document's page sequence are indexed from 1. 
	 *
	 * @return a Page corresponding to a given page number, or null (invalid page)
	 * if the document does not contain the given page number.
	 *
	 * For example:
	 * @code 
	 *   Page page = pdfdoc.GetPage(page_num);
	 *   if (page == null) return; //  Page not found
	 * @endcode
	 */
	 Page GetPage(UInt32 page_number);

	/**
	 * @param page_itr - the PageIterator to the page that should be removed
	 * A PageIterator for the given page can be obtained using PDFDoc::GetPageIterator(page_num) 
	 * or using direct iteration through document's page sequence.
	 */
	 void PageRemove(const PageIterator& page_itr);

	 enum InsertFlag {
		e_none,				//default, do not insert bookmarks
		e_insert_bookmark,	//insert bookmarks (use this option when inserting many pages in a single call)
		e_insert_goto_bookmark // same as e_insert_bookmark, but ignore GoToR and URI links, while still retaining bookmark hierarchy (use this option when inserting one page at a time)
	};

	/**
	 * Insert/Import a single page at a specific location in the page sequence.
	 * 
	 * @param where - The location in the page sequence indicating where to insert 
	 * the page. The page is inserted before the specified location. 
	 *
	 * @param page - A page to insert.

	 * @note Invalidates all PageIterators pointing to the document.
	 */
	 void PageInsert(PageIterator& where, Page page);

	 /**
	 * Inserts a range of pages from specified PDFDoc
	 *
	 * @param insert_before_page_number - the destination of the insertion. If less than or equal to 1, 
	 * the pages are added to the beginning of the document. If larger than the number of pages 
	 * in the destination document, the pages are appended to the document.
	 * @param src_doc - source PDFDoc to insert from
	 * @param start_page - start of the page number to insert
	 * @param end_page - end of the page number to insert
	 * @param flag - specifies insert options
	 * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
	 */
	void InsertPages(int insert_before_page_number
		, PDFDoc& src_doc
		, int start_page
		, int end_page 
		, enum InsertFlag flag 
#ifndef SWIG		
		, Common::ProgressMonitor * monitor = 0
#endif
		);

	/**
	 * Inserts a range of pages from specified PDFDoc using PageSet
	 *
	 * @param insert_before_page_number - the destination of the insertion. If less than or equal to 1, 
	 * the pages are added to the beginning of the document. If larger than the number of pages 
	 * in the destination document, the pages are appended to the document.
	 * @param src_doc - source PDFDoc to insert from
	 * @param source_page_set - a collection of the page number to insert
	 * @param flag - specifies insert options
	 * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
	 */
	void InsertPages(int insert_before_page_number
		, PDFDoc& src_doc
		, const PageSet& source_page_set
		, enum InsertFlag flag
#ifndef SWIG
		, Common::ProgressMonitor * monitor = 0
#endif
		);

	
	/**
	 * Moves a range of pages from specified PDFDoc. Pages are deleted from source document after move.
	 *
	 * @param move_before_page_number - the destination of the move. If less than or equal to 1, 
	 * the pages are moved to the beginning of the document. If larger than the number of pages 
	 * in the destination document, the pages are moved to the end of the document.
	 * @param src_doc - source PDFDoc to move from
	 * @param start_page - start of the page number to move
	 * @param end_page - end of the page number to move
	 * @param flag - specifies insert options
	 * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
	 * @note MovePages function does not save src_doc. It merely delete pages in memeory. For permanent changes,
	 * PDFDoc::Save should be used to save src_doc after function exists.
	 */
	void MovePages(int move_before_page_number
		, PDFDoc& src_doc
		, int start_page
		, int end_page
		, enum InsertFlag flag
#ifndef SWIG
		, Common::ProgressMonitor * monitor = 0
#endif
		);

	
	/**
	 * Moves a range of pages from specified PDFDoc. Pages are deleted from source document after move.
	 *
	 * @param move_before_page_number - the destination of the move. If less than or equal to 1, 
	 * the pages are moved to the beginning of the document. If larger than the number of pages 
	 * in the destination document, the pages are moved to the end of the document.
	 * @param src_doc - source PDFDoc to move from
	 * @param source_page_set - a collection of the page number to move
	 * @param flag - specifies insert options
	 * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
	 * @note MovePages function does not save src_doc. It merely delete pages in memeory. For permanent changes,
	 * PDFDoc::Save should be used to save src_doc after function exists.
	 */
	void MovePages(int move_before_page_number
		, PDFDoc& src_doc
		, const PageSet& source_page_set
		, enum InsertFlag flag
#ifndef SWIG
		, Common::ProgressMonitor * monitor = 0
#endif
		);

	/**
	 * Adds a page to the beginning of a document's page sequence.
	 * @param page - a page to prepend to the document
	 * Invalidates all PageIterators pointing to the document.
	 */
	 void PagePushFront(Page page);

	/**
	 * Adds a page to the end of a document's page sequence.
	 * @param page - a page to append to the document
	 * @note Invalidates all PageIterators pointing to the document.
	 */
	 void PagePushBack(Page page);

	/**
	 * The function imports a list of pages to this document. Although a list of pages 
	 * can be imported using repeated calls to PageInsert(), PageImport will not import 
	 * duplicate copies of resources that are shared across pages (such as fonts, images, 
	 * colorspaces etc). Therefore this method is recommended when a page import list 
	 * consists of several pages that share the same resources. 
	 * 
	 * @param pages A list of pages to import. All pages should belong to the same source document.
	 * @param import_bookmarks An optional flag specifying whether any bookmark items 
	 * pointing to pages in the import list should be merged with the target (i.e. this) 
	 * document.
	 * 	 
	 * @return a list of imported pages. Note that imported pages are not placed in the 
	 * document page sequence. This can be done using methods such as PageInsert(), 
	 * PagePushBack(), etc.
	 */
	 std::vector<Page> ImportPages(const std::vector<Page>& pages, bool import_bookmarks = false);

	 /**
	  * Create a new, empty page in the document. You can use PageWriter to fill the 
	  * page with new content. Finally the page should be inserted at specific 
	  * place within document page sequence using PageInsert/PagePushFront/PagePushBack
	  * methods.
	  *
	  * @return A new, empty page. 
	  *
	  * @note the new page still does not belong to document page sequence and should be 
	  * subsequently placed at a specific location within the sequence.
	  *
	  * @param media_box A rectangle, expressed in default user space units, defining 
	  * the boundaries of the physical medium on which the page is intended to be 
	  * displayed or printed. A user space units is 1/72 of an inch. If media_box is 
	  * not specified the default dimensions of the page are 8.5 x 11 inches (or 
	  * 8.5*72, 11*72 units). 
	  *
	  * <p>The following is a listing of some standard U.S. page sizes:</p>
	  *  <ul>
	  *    <li>Letter    = Rect(0, 0, 612, 792)
	  *    <li>Legal	    = Rect(0, 0, 612, 1008)
	  *    <li>Ledger	= Rect(0, 0, 1224, 792)
	  *    <li>Tabloid   = Rect(0, 0, 792, 1224)
	  *    <li>Executive	= Rect(0, 0, 522, 756)
	  * </ul>
	  * 
	  * <p>The following is a listing of ISO standard page sizes:</p>
	  *  <ul>
	  *    <li> 4A0 = Rect(0, 0, 4768, 6741) 
	  *    <li> 2A0 = Rect(0, 0, 3370, 4768)  
	  *    <li> A0 =  Rect(0, 0, 2384, 3370)
	  *    <li> A1 =  Rect(0, 0, 1684, 2384)
	  *    <li> A2 =  Rect(0, 0, 1191, 1684)
	  *    <li> A3 =  Rect(0, 0, 842,  1191)
	  *    <li> A4 =  Rect(0, 0, 595,  842)
	  *    <li> A5 =  Rect(0, 0, 420,  595)
	  *    <li> A6 =  Rect(0, 0, 298,  420)
	  *    <li> A7 =  Rect(0, 0, 210,  298)
	  *    <li> A8 =  Rect(0, 0, 147,  210)
	  *    <li> A9 =  Rect(0, 0, 105,  147)
	  *    <li> A10 = Rect(0, 0, 74,   105)
	  *    <li> B0 =  Rect(0, 0, 2835, 4008)
	  *    <li> B1 =  Rect(0, 0, 2004, 2835)
	  *    <li> B2 =  Rect(0, 0, 1417, 2004)
	  *    <li> B3 =  Rect(0, 0, 1001, 1417)
	  *    <LI> B4 =  Rect(0, 0, 709,  1001)
	  *    <LI> B5 =  Rect(0, 0, 499,  709)
	  *    <LI> B6 =  Rect(0, 0, 354,  499)
	  *    <LI> B7 =  Rect(0, 0, 249,  354)
	  *    <LI> B8 =  Rect(0, 0, 176,  249)
	  *    <LI> B9 =  Rect(0, 0, 125,  176)
	  *    <li> B10 = Rect(0, 0, 88,   125)
	  *    <li> C0 =  Rect(0, 0, 2599, 3677)
	  *    <li> C1 =  Rect(0, 0, 1837, 2599)
	  *    <li> C2 =  Rect(0, 0, 1298, 1837)
	  *    <li> C3 =  Rect(0, 0, 918,  1298)
	  *    <li> C4 =  Rect(0, 0, 649,  918)
	  *    <li> C5 =  Rect(0, 0, 459,  649)
	  *    <li> C6 =  Rect(0, 0, 323,  459)
	  *    <li> C7 =  Rect(0, 0, 230,  323)
	  *    <li> C8 =  Rect(0, 0, 162,  230)
	  *    <li> C9 =  Rect(0, 0, 113,  162)
	  *    <li>C10 =  Rect(0, 0, 79,   113)
	  * </ul>
	  */
	 Page PageCreate(const Rect& media_box = Rect(0, 0, 612, 792));

	/**
	 * Imports two external pages and highlights the differences between them.
	 * This function adds two new pages to the current document. The two input
	 * pages are typically coming from two different PDF files.
	 * @param page1 is the before page, the basis of the comparison
	 * @param page2 is the after page, to which the basis is compared to
	 * @note This function is beta and is subject to change
	 */
	 void AppendTextDiff(Page page1, Page page2);

	/**
	 * Imports two external PDFs and highlights the differences between them.
	 * @param doc1 is the before document, the basis of the comparison
	 * @param doc2 is the after document, to which the basis is compared to
	 * @note This function is beta and is subject to change
	 */
	 void AppendTextDiff(PDFDoc& doc1, PDFDoc& doc2);

	/**
	 * @return - the first Bookmark from the document's outline tree. If the 
	 * Bookmark tree is empty the underlying SDF/Cos Object is null and returned
	 * Bookmark is not valid (i.e. Bookmark::IsValid() returns false). 
	 */
	 class Bookmark GetFirstBookmark();

	/**
	 * Adds/links the specified Bookmark to the root level of document's outline tree.
	 * @param root_bookmark Bookmark to Add/link
	 * @note parameter 'root_bookmark' must not be linked (must not be belong) to 
	 * a bookmark tree.
	 */
	 void AddRootBookmark(class Bookmark root_bookmark);

	/**
	 * @return - A dictionary representing the Cos root of the document (document's trailer)
	 */
	 SDF::Obj GetTrailer ();

	/**
	 * @return - A dictionary representing the Cos root of the document (/Root entry 
	 * within the trailer dictionary)
	 */
	 SDF::Obj GetRoot();

	/**
	 * @return - A dictionary representing the root of the low level page-tree
	 */
	 SDF::Obj GetPages();

	/**
	 * @return the number of pages in the document.
	 */
	 int GetPageCount ();
    

	/**
	 * An interactive form (sometimes referred to as an AcroForm) is a
	 * collection of fields for gathering information interactively from 
	 * the user. A PDF document may contain any number of fields appearing 
	 * on any combination of pages, all of which make up a single, global 
	 * interactive form spanning the entire document.
	 * 
	 * The following methods are used to access and manipulate Interactive form 
	 * fields (sometimes referred to as AcroForms).
	 * 
	 * @return an iterator to the first Field in the document.
	 * 
	 * The list of all Fields present in the document can be traversed as follows:
	 * @code
	 * FieldIterator itr = pdfdoc.GetFieldIterator();
	 * for(; itr.HasNext(); itr.Next()) {
	 *   Field field = itr.Current();
 	 *   Console.WriteLine("Field name: {0}", field.GetName());
	 *  }
 	 * @endcode 
	 * 
	 * For a sample, please refer to 'InteractiveForms' sample project.
	 */
	 FieldIterator GetFieldIterator();

	 /**
	  * An interactive form (sometimes referred to as an AcroForm) is a
	  * collection of fields for gathering information interactively from
	  * the user. A PDF document may contain any number of fields appearing
	  * on any combination of pages, all of which make up a single, global
	  * interactive form spanning the entire document.
	  *
	  * The following methods are used to access and manipulate Interactive form
	  * fields (sometimes referred to as AcroForms).
	  *
	  * @param field_name String representing the name of the field to get.
	  * @return an iterator to the Field in the document.
	  *
	  * For a sample, please refer to 'InteractiveForms' sample project.
	  */
	 FieldIterator GetFieldIterator(const UString& field_name);

	/**
	 * @param field_name - a string representing the fully qualified name of 
	 * the field (e.g. "employee.name.first").
	 *
	 * @return a FieldIterator referring to an interactive Field
	 * or to invalid field if the field name was not found. If a given field name was 
	 * not found itr.HasNext() will return false. For example:
	 * 
	 * @code
	 * FieldIterator itr = pdfdoc.GetFieldIterator("name");
	 * if (itr.HasNext()) {
	 *   Console.WriteLine("Field name: {0}", itr.Current().GetName());
	 * }
 	 * else { ...field was not found... }
 	 * @endcode 
	 */
	 Field GetField(const UString& field_name);

	/**
	 * Create a new interactive form Field.
	 *
	 * @param field_name a string representing the fully qualified name of the 
	 * field (e.g. "employee.name.first"). field_name must be either a unique name or 
	 * equal to an existing terminal field name. 
	 * @param type field type (e.g. Field::e_text, Field::e_button, etc.)
	 * @param field_value
	 * @param def_field_value
	 * @return the new form Field.
	 *
	 * @exception if 'field_name' is equal to an existing non-terminal field name an 
	 * exception is thrown. 
	 */ 
	 Field FieldCreate(const UString& field_name, 
		Field::Type type, 
		SDF::Obj field_value = 0, 
		SDF::Obj def_field_value = 0);

	 /**
	  * Create a new interactive form Field.
	  *
	  * @param field_name a string representing the fully qualified name of the
	  * field (e.g. "employee.name.first"). field_name must be either a unique name or
	  * equal to an existing terminal field name.
	  * @param type field type (e.g. Field::e_text, Field::e_button, etc.)
	  * @param field_value
	  * @param def_field_value
	  * @return the new form Field.
	  *
	  * @exception if 'field_name' is equal to an existing non-terminal field name an
	  * exception is thrown.
	  */
	 Field FieldCreate(const UString& field_name,
		 Field::Type type,
		 const UString& field_value,
		 const UString& def_field_value = "");

	/**
	 * Regenerates the appearance stream for every widget annotation in the document 
	 * Call this method if you modified field's value and would like to update 
	 * field's appearances.
	 */
	 void RefreshFieldAppearances();

	/**
	* Generates the appearance stream for annotations in the document using the specified options. A common use case is to generate appearances
	* only for missing annotations, which can be accomplished using the default options.
	* @param options Options that can be used to adjust this generation process.
	*/
	void RefreshAnnotAppearances(const RefreshOptions* options = 0);
	
	/**
	 * Flatten all annotations in the document.
	 * @param forms_only if false flatten all annotations, otherwise flatten
	 * only form fields.
	 */
	 void FlattenAnnotations(bool forms_only = false);

	/**
	 * @return the AcroForm dictionary located in "/Root" or NULL if dictionary is not present.
	 */
	 SDF::Obj GetAcroForm();

	 enum ExtractFlag {
		 e_forms_only,				// default, only extract form fields to FDF
		 e_annots_only,				// only extract annots
		 e_both,                      // extract both form fields and annots
		 e_annots_only_no_links = 5 // same as e_annots_only but no url links get converted
	 };

	/**
	 * Extract form data and/or annotations to FDF
	 * @param flag - specifies extract options
	 * @return a pointer to the newly created FDF file with an interactive data.
	 */
	 FDF::FDFDoc FDFExtract(enum ExtractFlag flag = e_forms_only);

	/**
	 * Extract form data and/or annotations to FDF
	 * @param pages_to_extract The set of pages for which to extract interactive data.
	 * @param flag specifies extract options
	 * @return a pointer to the newly created FDF file with an interactive data.
	 */
	 FDF::FDFDoc FDFExtract(PageSet& pages_to_extract, enum ExtractFlag flag = e_forms_only);

	 /**
	  * Extract selected annotations to FDF
	  * @param annotations the annotation(s) to extract
	  * @return a pointer to the newly created FDF file with the interactive data.
	  */
	 FDF::FDFDoc FDFExtract(const std::vector<Annot>& annotations);

	 /**
	  * Extract annotations to FDF
	  * @param annot_added specifies the array of added annotations
	  * @param annot_modified specifies the array of modified annotations
	  * @param annot_deleted specifies the array of deleted annotations
	  * @return a pointer to the newly created FDF file with an interactive data.
	  */
	 FDF::FDFDoc FDFExtract(const std::vector<Annot>& annot_added, const std::vector<Annot>& annot_modified, const std::vector<Annot>& annot_deleted);

	/**
	 * Import form data from FDF file to PDF interactive form.
	 * @param fdf_doc - a reference to the FDF file
	 */
	 void FDFMerge(FDF::FDFDoc& fdf_doc);

	 /**
	 * Replace existing form and annotation data with those imported from the FDF file.
	 * Since this method avoids updating annotations unnecessarily it is ideal for incremental save.
	 * @param fdf_doc - a reference to the FDF file
	 */
	 void FDFUpdate(FDF::FDFDoc& fdf_doc);

	/**
	 * @return Action that is triggered when the document is opened.
	 * The returned action can be either a destination or some other kind 
	 * of Action (see Section 8.5, 'Actions' in PDF Reference Manual).
	 * 
	 * @note if the document does not nave associated action the returned Action 
	 * will be null (i.e. Action.IsValid() returns false)
	 */
	 Action GetOpenAction();

	/**
	 * Sets the Action that will be triggered when the document is opened.
	 * 
	 * @param action A new Action that will be triggered when the document is opened.
	 * An example of such action is a GoTo Action that takes the user to a given 
	 * location in the document.
	 */
	 void SetOpenAction(const Action& action);

	/**
	 * Associates a file attachment with the document. 
	 *
	 * The file attachment will be displayed in the user interface of a viewer application 
	 * (in Acrobat this is File Attachment tab). The function differs from  
	 * Annot.CreateFileAttachment() because it associates the attachment with the 
	 * whole document instead of an annotation on a specific page.
	 * 
	 * @param file_key A key/name under which the attachment will be stored.
	 * @param embedded_file Embedded file stream
	 * 
	 * @note Another way to associate a file attachment with the document is using SDF::NameTree: 
	 * @code
	 *   SDF::NameTree names = SDF::NameTree::Create(doc, "EmbeddedFiles");
	 *   names.Put(file_key, file_keysz, embedded_file.GetSDFObj());
	 * @endcode
	 */
	 void AddFileAttachment(const UString& file_key, FileSpec embedded_file);

	/** 
	 * @return the PageLabel that is in effect for the given page. 
	 * If there is no label object in effect, this method returns an
	 * invalid page label object.
	 * 
	 * @param page_num The page number. Because PDFNet indexes pages 
	 * starting from 1, page_num must be larger than 0.
	 */
	 PageLabel GetPageLabel(int page_num);

	/** 
	 * Attaches a label to a page. This establishes the numbering scheme 
	 * for that page and all following it, until another page label is 
	 * encountered. This label allows PDF producers to define a page 
	 * numbering system other than the default. 
	 *
	 * @param page_num The number of the page to label. If page_num is 
	 * less than 1 or greater than the number of pages in the document, 
	 * the method does nothing.
	 */
	 void SetPageLabel(int page_num, PageLabel& label);

	/** 
	 * Removes the page label that is attached to the specified page, 
	 * effectively merging the specified range with the previous page 
	 * label sequence.
	 *
	 * @param page_num The page from which the page label is removed.
	 * Because PDFNet indexes pages starting from 1, page_num must be 
	 * larger than 0.
	 */
	 void RemovePageLabel(int page_num);

	/**
	 * @return true if this document is marked as Tagged PDF, false otherwise.
	 */
	bool IsTagged();

	/**
	 * @return The document's logical structure tree root.
	 */
	 Struct::STree GetStructTree();

	 /** 
	 * @return true if the optional content (OC) feature is associated with 
	 * the document. The document is considered to have optional content if 
	 * there is an OCProperties dictionary in the document's catalog, and 
	 * that dictionary has one or more entries in the OCGs array.
	 */
	 bool HasOC() const;

	 /**
	 * @return the Obj array that contains optional-content groups (OCGs) for 
	 * the document, or NULL if the document does not contain any OCGs. The 
	 * order of the groups is not guaranteed to be the creation order, and is 
	 * not the same as the display order.
	 */
	 SDF::Obj GetOCGs() const;

	 /**
	 * @return the default optional-content configuration for the document 
	 * from the OCProperties D entry.
	 */
	 OCG::Config GetOCGConfig() const;

	 /** 
	 * AddHighlights is used to highlight text in a document using 'Adobe's Highlight 
	 * File Format' (Technical Note #5172 ). The method will parse the character offset data
	 * and modify the current document by adding new highlight annotations.
	 *
	 * @param hilite a string representing the filename for the highlight file or 
	 * or a data buffer containing XML data. 
	 *
	 * @exception An exception will be thrown if the XML file is malformed or os out
	 * of sync with the document.
	 */
	 void AddHighlights(const UString& hilite);

	/**
	* This method creates an SDF/Cos indirect name object 
	*
	 * Unlike direct objects, indirect objects can be referenced by more than one 
	 * object (i.e. indirect objects can be shared). 
	 * 
	 */
	 SDF::Obj CreateIndirectName(const char* name);
	 /**
	 * This method creates an SDF/Cos indirect array object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect array object.
	 */
	 SDF::Obj CreateIndirectArray();
	 /**
	 * This method creates an SDF/Cos indirect boolean object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect boolean object.
	 * @param value the value with which to create the boolean object.
	 */
	 SDF::Obj CreateIndirectBool(bool value);
	 /**
	 * This method creates an SDF/Cos indirect dict object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect dict object.
	 */
	 SDF::Obj CreateIndirectDict();
	 /**
	 * This method creates an SDF/Cos indirect null object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect null object.
	 */
	 SDF::Obj CreateIndirectNull();
	 /**
	 * This method creates an SDF/Cos indirect number object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect number object.
	 * @param value the value with which to create the number object.
	 */
	 SDF::Obj CreateIndirectNumber(double value);
	 /**
	 * This method creates an SDF/Cos indirect string object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect string object.
	 * @param value Unsigned char pointer with which to create the string object.
	 * @param size length of string.
	 */
	 SDF::Obj CreateIndirectString(const UChar* value, UInt32 size);
	 /**
	 * This method creates an SDF/Cos indirect string object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect string object.
	 * @param str reference to string with which to create the string object.
	 */
	 SDF::Obj CreateIndirectString(const UString& str);
	 /**
	 * This method creates an SDF/Cos indirect stream object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect stream object.
	 * @param data reference to a FilterReader object with which to create the stream object.
	 * @param filter_chain filter object with which to create the stream object. Defaults to Filters::Filter(0,false)
	 */
	 SDF::Obj CreateIndirectStream(Filters::FilterReader& data, Filters::Filter filter_chain=Filters::Filter(0,false));
	 /**
	 * This method creates an SDF/Cos indirect stream object
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects can be shared).
	 * @return Returns a new indirect stream object.
	 * @param data pointer to string with which to create the stream object.
	 * @param data_size length of string.
	 * @param filter_chain filter object with which to create the stream object. Defaults to Filters::Filter(0,false)
	 */
	 SDF::Obj CreateIndirectStream(const char* data, const size_t data_size, Filters::Filter filter_chain = Filters::Filter (0,false));

	/**
	 * @return document's SDF/Cos document
	 */
	 SDF::SDFDoc& GetSDFDoc ();

	/**
	 * Explicit conversion operator from PDFDoc to SDF::Doc.
	 * @return document's SDF/Cos document
	 */
	 operator SDF::SDFDoc& () { return GetSDFDoc(); }


	/**
	 * Locks the document to prevent competing threads from accessing the document 
	 * at the same time. Threads attempting to access the document will wait in 
	 * suspended state until the thread that owns the lock calls doc.Unlock().
	 */
	 void Lock();

	/**
	 * Removes the lock from the document.
	 */
	 void Unlock();

	/**
	 * Try locking the document, waiting no longer than specified number of milliseconds.
	 * @param milliseconds - max number of milliseconds to wait for the document to lock
	 * @return true if the document is locked for multi-threaded access, false otherwise.
	 */
	 bool TryLock( int milliseconds = 0 );

	/**
	 * Locks the document to prevent competing write threads (using Lock()) from accessing the document 
	 * at the same time. Other reader threads however, will be allowed to access the document.
	 * Threads attempting to obtain write access to the document will wait in 
	 * suspended state until the thread that owns the lock calls doc.UnlockRead().
	 * Note: To avoid deadlocks obtaining a write lock while holding
	 * a read lock is not permitted and will throw an exception. If this situation is encountered
	 * please either unlock the read lock before the write lock is obtained
	 * or acquire a write lock (rather than read lock) in the first place.
	 */
	 void LockRead();

	/**
	 * Removes the read lock from the document. 
	 */
	 void UnlockRead();

	/**
	 * Tries to obtain a read lock the document for <milliseconds> duration, and returns 
	 * true if the lock was successfully acquired
	 * @param milliseconds duration to obtain a read lock for.
	 * @return true if the document is locked for multi-threaded access, false otherwise.
	 */
	 bool TryLockRead( int milliseconds = 0 );

	 /**
	  * @return The filename of the document if the document is loaded from disk, 
	  * or empty string if the document is not yet saved or is loaded from a memory 
	  * buffer.
	  */
	 UString GetFileName() const;

    /**
     * Generates thumbnail images for all the pages in this PDF document.
     * @param size The maximum dimension (width or height) that thumbnails will have.
     */
    void GenerateThumbnails(UInt32 size);
	
	/**
	 * Generates a PDF diff of the given pages by overlaying and blending them on top of each other.
	 * @param p1 one of the two pages for comparing.
	 * @param p2 the other page for comparing.
	 * @param opts options for comparison results.
	 */
	void AppendVisualDiff(Page p1, Page p2, DiffOptions* opts);
	
	/**
	 * Applies optimizations to improve viewing speed and saves the document to the specified file.
	 * The main optimizations used are linearization and embedding thumbnails for the
	 * first page and any complex pages.
	 *
	 * @param path The full path name to which the file is saved.
	 * @param opts The optimization options
	 *
	 * @exception if the file can't be opened for saving or if there is a problem during Save
	 * an Exception object will be thrown.
	 */
	void SaveViewerOptimized(const UString& path, const ViewerOptimizedOptions& opts);

	/**
	* Applies optimizations to improve viewing speed and saves the document to a memory buffer.
	* The main optimizations used are linearization and embedding thumbnails for the
	* first page and any other pages that are slow to render.
	*
	* @param out_buf a pointer to the buffer containing the serialized version of the
	* document. (C++ Note) The buffer is owned by a document and the client doesn't need to
	* do any initialization or cleanup.
	* @param out_buf_size the size of the serialized document (i.e. out_buf) in bytes.
	* @param opts - The optimization options
	*
	* @exception - if the file can't be opened for saving or if there is a problem during Save
	*	an Exception object will be thrown.
	*/
	void SaveViewerOptimized(const char* &out_buf, size_t& out_buf_size, const ViewerOptimizedOptions& opts);

	 enum SignaturesVerificationStatus
	 {
		 e_unsigned,
		 // e_failure == bad doc, digest, or MDP (i.e. does not include trust issues, because those are flaky due to being network/config-related)
		 e_failure,
		 e_untrusted,
		 e_unsupported,
		 // unsigned sigs skipped; parts of document may be unsigned (check GetByteRanges on signed sigs to find out)
		 e_verified
	 };

	 /**
	  * Attempts to verify all signed cryptographic digital signatures in the document, ignoring unsigned signatures.
	  *
	  * @return an enumeration value representing the state of the document's signatures
	 */
	 SignaturesVerificationStatus VerifySignedDigitalSignatures(const VerificationOptions& in_opts) const;

    //for xamarin use only
    static PDFDoc* CreateInternal(ptrdiff_t impl);
    ptrdiff_t GetHandleInternal();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN

	TRN_PDFDoc mp_doc;
	//for xamarin use only
	PDFDoc(TRN_PDFDoc impl) : mp_doc(impl) {}
#endif
// @endcond
    
};

	};	// namespace PDF
};	// namespace pdftron


#include <Impl/PDFDoc.inl>

#endif // PDFTRON_H_CPPPDFPDFDoc
