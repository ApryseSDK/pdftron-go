//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSDFSecurityHandler
#define PDFTRON_H_CPPSDFSecurityHandler

#include <vector>
#include <Common/UString.h>
#include <Filters/Filter.h>

namespace pdftron { 
	namespace SDF {

class Obj;
class SDFDoc;


/**
 * Standard Security Handler is a standard password-based security handler.
 */
class SecurityHandler
{
public:

	enum Permission
	{
		e_owner = 1,		///< the user has 'owner' rights (e.g. rights to change the document's security settings).
		e_doc_open,         ///< open and decrypt the document.
		e_doc_modify,       ///< edit the document more than adding or modifying text notes.
		e_print,            ///< print the document.	
		e_print_high,       ///< high resolution print.
		e_extract_content,  ///< enable content extraction
		e_mod_annot,        ///< allow modifications to annotations
		e_fill_forms,       ///< allow changes to fill in forms
		e_access_support,   ///< content access for the visually impaired.
		e_assemble_doc      ///< allow document assembly
	};

	/**
	 * @return true if the SecurityHandler permits the specified action (Permission p)
	 * on the document, or false if the permission was not granted.
	 * 
	 * @param p A Permission to be granted.
	 * 
	 * @note in order to check for permission the method will repeatedly (up to three 
	 * times) attempt to GetAuthorizationData() and Authorize() permission. If the 
	 * permission is not granted AuthorizeFailed() callback will be called. This callback
	 * method allows derived class to provide UI feedback for failed authorization.
	 */
	 bool GetPermission(Permission p);

	/**
	 * @return The length of the encryption key in bytes.
	 * @note The returned key length is given in bytes.
	 */
	 int GetKeyLength() const;

	/**
	 * @return The encryption algorithm identifier. A code specifying the algorithm 
	 * to be used in encrypting and decrypting the document. Returned number corresponds
	 * to V entry in encryption dictionary. Currently allowed values are from 0-4. 
	 * See PDF Reference Manual for more details.
	 */
	 int GetEncryptionAlgorithmID() const;

	/**
	 * @return The name of the security handler as it appears in the serialized file
	 * as the value of /Filter key in /Encrypt dictionary.
	 */
	 const char* GetHandlerDocName() const;

	/**
	 * @return - true if the SecurityHandler was modified (by calling SetModified()) 
	 * or false otherwise.
	 * 
	 * If the user changes SecurityHandler's settings (e.g. by changing a password), 
	 * IsModified() should return true.
	 */
	 bool IsModified () const;

	/**
	 * @return - true if the SecurityHandler is valid.
	 *
	 */
	 bool IsValid () const;
	
	
	/**
	 * The method allows derived classes to set SecurityHandler is modified flag.
	 * This method should be called whenever there are changes (e.g. a password change) 
	 * to the SecurityHandler
	 * @param is_modified Value to set the SecurityHandler's is modified flag to
	 */ 
	 void SetModified (bool is_modified = true);


	/**
	 * The algorithm to be used in encrypting and decrypting the document.
	 */
	enum AlgorithmType {
                e_RC4_40 = 1,      ///< 40-bit RC4 algorithm.  
                e_RC4_128,         ///< 128-bit RC4 algorithm.     
                e_AES,             ///< Use Crypt filters with 128-bit AES (Advanced Encryption Standard) algorithm.
				e_AES_256		   ///< Use Crypt filters with 256-bit AES (Advanced Encryption Standard) algorithm.
	};

	/** 
	 * Create a Standard Security Handler. 
	 *
	 * @param crypt_type The encryption algorithm identifier. 
	 */ 
	 SecurityHandler (AlgorithmType crypt_type);	

	/** 
	 * Create a Standard Security Handler. 
	 *
	 * @param name The name of the Standard Security Handler.
	 * @param key_len The bit length of the encryption key (40 or 128 bit).
	 * @param enc_code The encryption algorithm identifier. The number corresponds
	 * to the V entry in encryption dictionary. Currently allowed values are (see 
	 * Table 3.18 in PDF Reference Manual v1.6 for more details): 
	 *   - 1 : Encryption using 40-bit RC4 algorithm. 
	 *   - 2 : Encryption using 128-bit RC4 algorithm. Available in PDF 1.4 and above.
	 *   - 3 : This algorithm was deprecated by PDF standard and is not supported. 
	 *   - 4 : Encryption using Crypt filters and 128-bit AES (Advanced Encryption 
	 *         Standard) algorithm. Available in PDF 1.6 and above.
	 * 
	 * @default values for key_len and enc_code are 128 and 2 respectively.
	 */
	 SecurityHandler (const char* name, int key_len, int enc_code);	
	 SecurityHandler ();

	 SecurityHandler (const SecurityHandler& s);
	 SecurityHandler& operator= (const SecurityHandler&);
	 virtual ~SecurityHandler ();
	
	/**
	 * Set the new user password to an ASCII text string
     * @param password the new user password
     *
     * @remark Deprecated. Use versions that accepts UString or buffer instead..
	 */
	 void ChangeUserPasswordASCII(const char* password);

	/**
	 * Set the new user password to a binary string
     * @param password the new user password
     *
     * @remark Deprecated. Use versions that accepts UString or buffer instead.
	 */
	 void ChangeUserPassword(const char* password, size_t pwd_length );

    /**
     * Sets the new user password.
     * @param password The new user password.
     */
    void ChangeUserPassword(const pdftron::UString& password);
     
    /**
     * Sets the new user password.
     * @param password The new user password.
     */
    void ChangeUserPassword(const std::vector<pdftron::UInt8>& password_buf);

	/** 
	 * @return Current user password.
	 */ 
	 const char* GetUserPassword();
	 	
	 /** 
	  * @return Length of the current user password string. This has to be used
	  * when password is a non-ASCII string that may contain '\0' bytes.
	  */ 
	 size_t GetUserPasswordSize() const;

	/**
	 * Set the new master password to an ASCII text string
     * @param password the new master/owner password
     *
     * @remark Deprecated. Use versions that accepts UString or buffer instead.
	 */
	 void ChangeMasterPasswordASCII(const char* password);
	
	/**
	 * Set the new master password to a binary string
     * @param password the new user password
     *
     * @remark Deprecated. Use versions that accepts UString or buffer instead.
	 */
	void ChangeMasterPassword(const char* password, size_t pwd_length);

    /**
     * Sets the new master/owner password.
     * @param password The new master/owner password.
     */
    void ChangeMasterPassword(const pdftron::UString& password);
     
    /**
     * Sets the new master/owner password.
     * @param password_buf The new master/owner password.
     */
    void ChangeMasterPassword(const std::vector<pdftron::UInt8>& password_buf);

	/** 
	 * @return Current master (owner) password.
	 */ 
	const char* GetMasterPassword();

	/** 
	  * @return Length of the current owner password string. This has to be used
	  * when password is a non-ASCII string that may contain '\0' bytes.
	  */ 
	 size_t GetMasterPasswordSize() const;

	/**
	 * Set the permission setting of the StdSecurityHandler.
	 * @param perm indicates a permission to set or clear. It can be any of the 
	 * following values:
	 *
	 *	e_print				// print the document.	
	 *	e_doc_modify		// edit the document more than adding or modifying text notes.
	 *	e_extract_content	// enable content extraction
	 *	e_mod_annot			// allow modifications to annotations
	 *	e_fill_forms		// allow changes to fill in forms
	 *	e_access_support	// content access for the visually impaired.
	 *	e_assemble_doc		// allow document assembly
	 *	e_print_high		// high resolution print.
	 *
	 * @param value true if the permission/s should be granted, false otherwise.
	 */
	 void SetPermission (Permission perm, bool value);

	/**
	 * Change the revision number and the encryption algorithm of the 
	 * standard security handler.
	 * 
	 * @param rev_num the new revision number of the standard security 
	 * algorithm. Currently allowed values for the revision number are 
	 * (see Table 3.18 in PDF Reference Manual v1.6 for more details): 
	 *   - 2 : Encryption using 40-bit RC4 algorithm. 
	 *   - 3 : Encryption using 128-bit RC4 algorithm. Available in PDF 1.4 and above.
	 *   - 4 : Encryption using Crypt filters and 128-bit AES (Advanced Encryption 
	 *         Standard) algorithm. Available in PDF 1.6 and above.
	 */
	 void ChangeRevisionNumber (int rev_num);

	/**
	 * Indicates whether the document-level metadata stream is to 
	 * be encrypted.
	 * 
	 * @param encrypt_metadata true if metadata stream should be
	 * encrypted, false otherwise.
	 * 
	 * @note EncryptMetadata flag affects only Crypt filters available 
	 * in PDF 1.5 (Acrobat 6) and later. By default, metadata stream 
	 * will be encrypted.
	 */
	 void SetEncryptMetadata(bool encrypt_metadata);

	/**
	 * @return the revision number of the standard security algorithm.
	 */
	 int GetRevisionNumber ();

	/**
	 * @return true if the SecurityHandler requires a user password.
	 */
	 bool IsUserPasswordRequired ();

	/**
	 * @return true if the SecurityHandler requires a master (owner) password.
	 */
	 bool IsMasterPasswordRequired ();

	/** 
	 * @return true is this security handler uses 128 bit AES (Advanced Encryption Standard) 
	 * algorithm to encrypt strings or streams.
	 */
	 bool IsAES() const;

	/** 
	 * The following function can be used to verify whether a given stream is 
	 * encrypted using AES.
	 * 
	 * @return true if the given stream is encrypted using AES encryption.
	 * @param stream A pointer to an SDF::Stream object
	 */
	 bool IsAES(Obj stream) const;

	/** 
	 * @return true is this security handler uses RC4 algorithm to encrypt strings or streams.
	 */
	 bool IsRC4() const;

	 /** 
	  * @return true if the object is not null, false otherwise.  
	  */ 
	 operator bool () { return mp_handler!=0;}

	 /**
	 * A callback method indicating repeated failed authorization. 
	 * Override this callback in order to provide a UI feedback for failed 
	 * authorization. Default implementation returns immediately.
	 */
	 virtual void AuthorizeFailed();

	 /**
	 * The method is called when a user tries to set security for an encrypted 
	 * document and when a user tries to open a file. It must decide, based on 
	 * the contents of the authorization data structure, whether or not the 
	 * user is permitted to open the file, and what permissions the user has 
	 * for this file. 
	 * 
	 * @note - This callback must not obtain the authorization data (e.g. by 
	 * displaying a user interface into which a user can type a password). 
	 * This is handled by the security handler's GetAuthorizationData(), which 
	 * must be called before this callback. Instead, Authorize() should work 
	 * with authorization data it has access to.
	 *
	 * @param p - permission to authorize
	 */
	 virtual bool Authorize (Permission p);

	 /**
	 * This method is invoked in case Authorize() failed. The callback must 
	 * determine the user's authorization properties for the document by
	 * obtaining authorization data (e.g. a password through a GUI dialog).
	 * 
	 * The authorization data is subsequently used by the security handler's Authorize()
	 * to determine whether or not the user is authorized to open the file.
	 *
	 * @return false if the operation was canceled, true otherwise.
	 * @param req_opr - the permission for which authorization data is requested.
	 */
	 virtual bool GetAuthorizationData (Permission req_opr);

	 /**
	 * Called when the security handler should activate a dialog box 
	 * with the current security settings that may be modified. 
	 *
	 * @return true if the operation was successful false otherwise.
	 */
	 virtual bool EditSecurityData(SDFDoc& doc);

	 /**
	 * Called when an encrypted document is saved. Fills the document's Encryption 
	 * dictionary with whatever information the security handler wants to store in 
	 * the document.
	 * 
	 * The sequence of events during creation of the encrypt_dict is as follows:
	 *  - encrypt_dict is created (if it does not exist)
	 *  - Filter attribute is added to the dictionary
	 *  - call this method to allow the security handler to add its own attributes
	 *  - call the GetCryptKey to get the algorithm version, key, and key length
	 *  - checks if the V attribute has been added to the dictionary and, if not, 
	 *    then sets V to the algorithm version 
	 *  - set the Length attribute if V is 2 or greater
	 *  - add the encrypt_dict to the document
	 *
	 *	@param doc - The document to save.
	 *  @return - encrypt_dict
	 *  
	 * @warning - Unlike all other strings and streams, direct object elements of
	 * the encrypt_dict are not encrypted automatically. If you want them encrypted, 
	 * you must encrypt them before inserting them into the dictionary.
	 */
	 virtual Obj FillEncryptDict(class SDFDoc& doc);

	 /**
	  * @return A new, cloned instance of SecurityHandler.
	  * @note this method must be implemented in any derived class from SecurityHandler.
	  */
	virtual SecurityHandler* Clone(TRN_SecurityHandler base) const;

	 /** 
	  * The method can be called in GetAuthorizationData() callback to 
      * specify user supplied ASCII password.
      *
      * @remark Deprecated. Use versions that accepts UString or buffer instead.
	  */ 
	 void InitPasswordASCII(const char* password);

	 /** 
	  * The method can be called in GetAuthorizationData() callback to 
      * specify user supplied non-ASCII password.
      *
      * @remark Deprecated. Use versions that accepts UString or buffer instead.
	  */ 
	 void InitPassword(const char* password, size_t pwd_length);
     
	 /** 
	  * This method can be called in GetAuthorizationData() callback to 
	  * specify user supplied password.
	  */
     void InitPassword(const pdftron::UString& password);
     
	 /** 
	  * This method can be called in GetAuthorizationData() callback to 
	  * specify user supplied password.
      */
     void InitPassword(const std::vector<pdftron::UInt8>& password_buf);


	 enum OverloadedFunction {
		 has_CloneProc         = 0x01,
		 has_AuthProc          = 0x02, 
		 has_AuthFailedProc    = 0x04, 
		 has_GetAuthDataProc   = 0x08, 
		 has_EditSecurDataProc = 0x10, 
		 has_FillEncDictProc   = 0x20
	 };

	 /** 
	  * This method informs base security handler which methods are overridden in the 
	  * derived class. The only place this method needs to be invoked is in 
	  * Create(name, key_len, enc_code) static factory method in the derived class.
	  * 
	  * @param overloaded_funct A flag that specifies which functions are overloaded 
	  * in the derived class. For example: SetDerived(SecurityHandler::has_Clone + SecurityHandler::has_FillEncDictProc);
	  */ 
	 void SetDerived(UInt32 overloaded_funct);

	 /** 
	  * @return The derived class or NULL for standard security handler.
	  */ 
	 SecurityHandler* GetDerived() const;

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 SecurityHandler(TRN_SecurityHandler impl, bool owner, UInt32 derived_procs);
	 TRN_SecurityHandler mp_handler;
	 bool m_owner; 
	 UInt32 m_derived_procs;
#endif
// @endcond
};


	};	// namespace SDF
};	// namespace pdftron

#include <Impl/SDFDoc.inl>

#endif // PDFTRON_H_CPPSDFSecurityHandler
