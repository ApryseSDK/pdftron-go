//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSDFSDFDoc
#define PDFTRON_H_CPPSDFSDFDoc

#include <Common/Matrix2D.h>
#include <Filters/FilterReader.h>
#include <vector>

namespace pdftron { 
	namespace Common {
		struct ProgressMonitor;
	}

	namespace SDF {


// forward declarations
class Obj; 
class SecurityHandler;

/** 
 * SDFDoc is a low-level document representing a graph of SDF::Obj nodes that 
 * can be used to build higher-level document models such as PDF (Portable Document
 * Format) or FDF (Forms Document Format).
 * 
 * SDFDoc brings together document security, document utility methods, and all SDF 
 * objects.
 * 
 * A SDF document can be created from scratch using a default constructor:
 * 
 * SDFDoc mydoc;
 * Obj trailer = mydoc.GetTrailer();
 * 
 * SDF document can be also created from an existing file (e.g. an external PDF document): 
 * @code
 * SDFDoc mydoc("in.pdf");
 * Obj trailer = mydoc.GetTrailer();
 * @endcode
 * or from a memory buffer or some other Filter/Stream such as a HTTP Filter connection: 
 * 
 * @code
 * MemoryFilter memory = ....
 * SDFDoc mydoc(memory);
 * Obj trailer = mydoc.GetTrailer();
 * @endcode
 * 
 * Finally SDF document can be accessed from a high-level PDF document as follows: 
 * 
 * @code
 * PDFDoc doc("in.pdf");
 * SDFDoc& mydoc = doc.GetSDFDoc();
 * Obj trailer = mydoc.GetTrailer();
 * @endcode
 * 
 * Note that the examples above used doc.GetTrailer() in order to access document 
 * trailer, the starting SDF object (root node) in every document. Following the trailer 
 * links, it is possible to visit all low-level objects in a document (e.g. all pages, 
 * outlines, fonts, etc). 
 * 
 * SDFDoc also provides utility methods used to import objects and object collections 
 * from one document to another. These methods can be useful for copy operations between 
 * documents such as a high-level page merge and document assembly.
 */
class SDFDoc
{
public:

	/**
	 * Default constructor. Creates a new document. 
	 * The new document contains only trailer and Info dictionary. 
	 * To build the rest of the document get document's root dictionary using GetTrailer() and 
	 * populate it with new key/value pairs.
	 */
	 SDFDoc ();

	/**
	 * Open a SDF/Cos document from a file.
	 *
	 * @param filepath - path name to the file.
	 *
	 * @note Make sure to call InitStdSecurityHandler() or InitSecurityHandler() after SDFDoc(...) 
	 * in case the document is encrypted.
	 */
	 SDFDoc (const UString& filepath);
	 SDFDoc (const char* filepath);

	/**
	 * Open a SDF/Cos document from a Filter (i.e. a data stream) object.
	 *
	 * @param stream - input stream containing a serialized document. The input stream may be a 
	 * random-access file, memory buffer, slow HTTP connection etc.
	 *
	 * @note if the input stream doesn't support Seek() operation the document will load whole 
	 * data stream in memory before parsing. In case of linearized PDF, the document may be parsed 
	 * on-the-fly while it is being loaded in memory. Note that since StdFile implements Seek() 
	 * interface, the document does not have to be fully in memory before it is used.
	 * 
	 * @note Make sure to call InitStdSecurityHandler() or InitSecurityHandler() after SDFDoc(...) 
	 * in case the document is encrypted.
	 */
	 SDFDoc (Filters::Filter stream);

	/**
	 * Open a SDF/Cos document from a memory buffer.
	 *
	 * @note the document should be fully loaded in the memory buffer. 
	 * @note the buffer ownership is not transfered to the document so the user should 
	 * clean-up if necessary.
	 * 
	 * @param buf - a memory buffer containing the serialized document
	 * @param buf_size - the size of memory buffer.
	 * 
	 * @note Make sure to call InitStdSecurityHandler() or InitSecurityHandler() after SDFDoc(...) 
	 * in case the document is encrypted.
	 */
	 SDFDoc (unsigned char* buf, size_t buf_size);

	/**
	 *	Destructor
	 */
	 ~SDFDoc ();

	/**
	 *	Close SDFDoc
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
	bool InitStdSecurityHandler (const char* password, int password_sz);

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
	 * @return - true if the document requires full save.
	 */
	 bool IsFullSaveRequired () const;

	/**
	 * @return - A dictionary representing the root of the document (i.e. 
	 * a document trailer dictionary)
	 */
	 Obj GetTrailer ();

	/**
	 * @param obj_num - object number of the object to retrieve.
	 * @return - the latest version of the object matching specified object number. 
	 * @exception - exception is thrown if the object is not found.
	 */
	 Obj GetObj (const UInt32 obj_num) const;

	/**
	 * @param obj - an object to import.
	 * @param deep_copy - a boolean indicating whether to perform a deep or shallow copy.
	 * In case of shallow copy all indirect references will be set to null.
	 *
	 * If the object belongs to a document the function will perform deep or shallow 
	 * clone depending whether deep_copy flag was specified.
	 * 
	 * If the object does not belong to any document ImportObj does not take the 
	 * object ownership. ImportObj copies the source object and it is users 
	 * responsibility to delete free objects.
	 *
	 * @return - a pointer to the root indirect object in this document
	 */
	 Obj ImportObj (Obj obj, bool deep_copy);

	/**
	 * The function performs a deep copy of all objects specified in the 'obj_list'. 
	 * If objects in the list are directly or indirectly referring to the same object/s,
	 * only one copy of the shared object/s will be copied. Therefore, unlike repeated calls
	 * to ImportObj, this method will import only one copy of shared objects (objects 
	 * representing an intersection of graphs specified through 'obj_list' of root pointers.
	 * 
	 * @note - All object in the import list must belong to the same source document. 
	 * @note - The function does not perform the shallow copy since ImportObj() can be used instead.
	 * 
	 * @param obj_list - a list of root objects to import. All directly or indirectly objects will be
	 * imported as well.
	 * @return - a list of imported root objects in this document.
	 */
	 std::vector<Obj> ImportObjs(const std::vector<Obj>& obj_list);
    
    /**
     * The function performs a deep copy of all objects specified in the 'obj_list'.
     * If objects in the list are directly or indirectly referring to the same object/s,
     * only one copy of the shared object/s will be copied. Therefore, unlike repeated calls
     * to ImportObj, this method will import only one copy of shared objects (objects
     * representing an intersection of graphs specified through 'obj_list' of root pointers.
     *
     * @note - All object in the import list must belong to the same source document.
     * @note - The function does not perform the shallow copy since ImportObj() can be used instead.
     *
     * @param obj_list - a list of root objects to import. All directly or indirectly objects will be
     * imported as well.
     * @param exclude_list - a list of objects to not include in the deep copy.
     * @return - a list of imported root objects in this document.
     */
     std::vector<Obj> ImportObjs(const std::vector<Obj>& obj_list, const std::vector<Obj>& exclude_list);

	/**
	 * @return - The size of cross reference table
	 */
	 UInt32 XRefSize () const;

	/**
	 * Removes 'marked' flag from all objects in cross reference table.
	 */
	 void ClearMarks ();

	enum SaveOptions 
	{
		e_incremental   = 0x01,     // Save the document using incremental mode.
		e_remove_unused = 0x02,     // Remove unused objects. Requires full save.
		e_hex_strings   = 0x04,     // Save all string in hexadecimal format.
		e_omit_xref     = 0x08,     // Do not save cross-reference table
		e_linearized    = 0x10,     // Save the document in linearized (fast web-view) format. Requires full save.
		e_compatibility = 0x20      // Save the document in a manner that maximizes compatibility with older PDF consumers (e.g. the file will not use compressed object and xref streams).
	};

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
      * @param flags - A bit field composed of an OR of the SDFDoc::SaveOptions values.
      * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
      * @param header - File header. A new file header is set only during full save.
      *
      * @exception - if the file can't be opened for saving or if there is a problem during Save
      *	an Exception object will be thrown.
      *
      * @note - Save will modify the SDFDoc object's internal representation.  As such,
      *			  the user should acquire a write lock before calling save.
      */
	 void Save(const UString& path, UInt32 flags, Common::ProgressMonitor* progress, const char* header);
#endif

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
	 * @param flags - A bit field composed of an OR of the SDFDoc::SaveOptions values. 
	 * @param header - File header. A new file header is set only during full save.
	 * 
	 * @exception - if the file can't be opened for saving or if there is a problem during Save 
	 *	an Exception object will be thrown.
	 *
	 * @note - Save will modify the SDFDoc object's internal representation.  As such, 
	 *			  the user should acquire a write lock before calling save.
	 */
	 void Save(const UString& path, UInt32 flags, const char* header);

	/**
	 * Saves the document to a memory buffer.
	 * 
	 * @param flags - A bit field composed of an OR of the SDFDoc::SaveOptions values. 
	 * Note that this method ignores e_incremental flag. 
	 * @param header - File header. A new file header is set only during full save.
	 *
	 * @return the buffer containing the serialized version of the document.
	 *
	 * @exception - if there is a problem during Save an Exception object will be thrown.
	 *
	 * @note - Save will modify the SDFDoc object's internal representation.  As such, 
	 *			  the user should acquire a write lock before calling save.
	 */
	 std::vector<unsigned char> Save(UInt32 flags, const char* header);

#ifndef SWIG
	 /**
	  * Saves the document to a memory buffer.
	  *
	  * @param out_buf a pointer to the buffer containing the serialized version of the
	  * document. (C++ Note) The buffer is owned by a document and the client doesn't need to
	  * do any initialization or cleanup.
	  * @param out_buf_size the size of the serialized document (i.e. out_buf) in bytes.
	  *
	  * @param flags - A bit field composed of an OR of the SDFDoc::SaveOptions values.
	  * Note that this method ignores e_incremental flag.
	  * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
	  * @param header - File header. A new file header is set only during full save.
	  *
	  * @exception - if there is a problem during Save an Exception object will be thrown.
	  *
	  * @note - Save will modify the SDFDoc object's internal representation.  As such,
	  *			  the user should acquire a write lock before calling save.
	  */
	 void Save(const char* &out_buf, size_t& out_buf_size, UInt32 flags, Common::ProgressMonitor* progress, const char* header); 
#endif

     /**
	 * Saves the document to a stream.
	 * 
	 * @param stream The output stream where to write data.
	 * @param flags - A bit field composed of an OR of the SDFDoc::SaveOptions values. 
	 * @param progress - A pointer to the progress interface. NULL if progress tracking is not required.
	 * @param header - File header. A new file header is set only during full save. See also GetHeader()
	 *
	 * @exception - if there is a problem during Save an Exception object will be thrown.
	 *
	 * @note - Save will modify the SDFDoc object's internal representation.  As such, 
	 *			  the user should acquire a write lock before calling save.
	 */
	 void Save(Filters::Filter stream, UInt32 flags, const char* header); 
	
	/**
	 * @return the header string identifying the document version to which the file conforms. 
	 * For a file conforming to PDF version 1.4, the header should be %PDF-1.4. 
	 * In general header strings have the following syntax: %AAA-N.n where AAA identifies 
	 * document specification (such as PDF, FDF, PJTF etc), N is the major version and 
	 * n is the minor version. The new header string can be set during a full save (see SDFDoc::Save()).
	 * For a document that is not serialized the function returns an empty string.
	 */ 
	 const char* GetHeader() const;

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
	 SecurityHandler GetSecurityHandler ();

	/**
	 * The function sets a new SecurityHandler as the current security handler.
	 *
	 * @param handler - new SecurityHandler
	 * 
	 * @note Setting a new security handler will not invalidate the access to
	 * the original file and will take effect during document Save().
	 * 
	 * @note If the security handler is modified, document will perform a full save 
	 * even if e_incremental was given as a flag in Save() method.
	 */
	 void SetSecurityHandler (SecurityHandler handler);

	/**
	 * This function removes document security.
	 */
	 void RemoveSecurity();

	/**
	 * Sometimes it is desirable to modify all indirect references to a given 
	 * indirect object. It would be inefficient to manually search for all 
	 * indirect references to a given indirect object.
	 * 
	 * A more efficient and less error prone method is to replace the indirect 
	 * object in the cross reference table with a new object. This way the object 
	 * that is referred to is modified (or replaced) and indirect references do 
	 * not have to be changed.
	 *
	 * @param obj_num1 - object number of first object to be swapped.
	 * @param obj_num2 - object number of second object to be swapped.
	 * 
	 * @exception the function throws exception in case the swap can't be 
	 * performed.
	 */
	 void Swap(UInt32 obj_num1, UInt32 obj_num2);

	/**
	 * Used to create SDF/Cos indirect object.
	 * 
	 * Unlike direct objects, indirect objects can be referenced by more than one 
	 * object (i.e. indirect objects they can be shared). 
	 *
	 * @param name - indirect const char* object to create.
	 * @note In C++ doc.CreateIndirect???(...) is equivalent to ???::CreateIndirect(...).
	 */
	 Obj CreateIndirectName(const char* name);
	 /**
	 * Used to create SDF/Cos indirect object.
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects they can be shared).
	 *
	 * @note In C++ doc.CreateIndirect???(...) is equivalent to ???::CreateIndirect(...).
	 */
	 Obj CreateIndirectArray();
	 /**
	 * Used to create SDF/Cos indirect object.
	 *
	 * Unlike direct objects, indirect objects can be referenced by more than one
	 * object (i.e. indirect objects they can be shared).
	 *
	 * @param value - indirect boolean to create.
	 * @note In C++ doc.CreateIndirect???(...) is equivalent to ???::CreateIndirect(...).
	 */
	 Obj CreateIndirectBool(bool value);
	 Obj CreateIndirectDict();
	 Obj CreateIndirectNull();
	 Obj CreateIndirectNumber(double value);
	 Obj CreateIndirectString(const UChar* value, UInt32 size);
	 Obj CreateIndirectString(const UString& str);

	 /**
	  * @note After calling the following methods the filter object is invalidated and should not be used
	  */
	 Obj CreateIndirectStream(Filters::FilterReader& data, Filters::Filter filter_chain=Filters::Filter());
	 Obj CreateIndirectStream(const char* data, const size_t data_size, Filters::Filter filter_chain =Filters::Filter());


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
	 * 'SDFDoc.SaveOptions.e_linearized' flag in the Save method.
	 */
	 bool IsLinearized() const;

	/**
	 * Returns document's initial linearization dictionary if it is available.
	 * 
	 * @return - the linearization dictionary of the original document or NULL 
	 * if the dictionary is not available.
	 */
	 SDF::Obj GetLinearizationDict() const;

	/**
	 * Returns document's initial linearization hint stream if it is available.
	 * 
	 * @return - the linearization hint stream of the original document or NULL 
	 * if the hint stream is not available.
	 */
	 SDF::Obj GetHintStream() const;

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
	 * Removes the lock from the document. 
	 */
	 void UnlockRead();

	/**
	 * Try locking the document, waiting no longer than specified number of milliseconds.
	 * @param milliseconds - max number of milliseconds to wait for the document to lock
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
	 * A document uses a temporary file which is used to cache the contents
	 * of any new stream object created in the document (that is the default behavior).
	 * @param use_cache_flag - true to enable caching, false to disable caching.
	 * Use this function to enable or disable this feature dynamically.
	 */
	 void EnableDiskCaching( bool use_cache_flag );

	 
	 //for xamarin use only
	 static SDFDoc* CreateInternal(ptrdiff_t impl);
	 ptrdiff_t GetHandleInternal();
	 
	 // @cond PRIVATE_DOC
	 #ifndef SWIGHIDDEN
	 SDFDoc(TRN_SDFDoc doc) : mp_doc(doc) {}
	 TRN_SDFDoc mp_doc;
private:
	SDFDoc(SDFDoc& other);
	SDFDoc& operator=(SDFDoc& other);
	#endif
	// @endcond
};


	};	// namespace SDF
};	// namespace pdftron


#include <Impl/SDFDoc.inl>

#endif // PDFTRON_H_CPPSDFSDFDoc
