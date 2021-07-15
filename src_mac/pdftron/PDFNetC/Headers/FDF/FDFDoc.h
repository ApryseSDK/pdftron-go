//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPFDFFDFDoc
#define PDFTRON_H_CPPFDFFDFDoc

#include <SDF/SDFDoc.h>
#include <FDF/FDFField.h>
#include <Common/Iterator.h>
#include <C/FDF/TRN_FDFDoc.h>
#include <PDF/Field.h>

namespace pdftron { 
	namespace FDF {

/**
 * FDFFieldIterator is an iterator type used to traverse interactive form fields 
 * in a FDF document. A FDFFieldIterator points to FDF::FDFField nodes or to the 'null' 
 * FDFField node. A sample use case: 
 * @code
 *  for(FDFFieldIterator itr = fdf_doc.GetFieldIterator(); itr.HasNext(); itr.Next()) {
 *	cout << "Field name: " << itr.Current().GetName() << endl;
 *	cout << "Field partial name: " << itr.Current().GetPartialName() << endl;
 *  }
 * @endcode
 */
typedef Common::Iterator<FDFField> FDFFieldIterator;

/** 
 * FDFDoc is a class representing Forms Data Format (FDF) documents.
 * FDF is typically used when submitting form data to a server, receiving 
 * the response, and incorporating it into the interactive form. It can also 
 * be used to export form data to stand-alone files that can be stored, transmitted 
 * electronically, and imported back into the corresponding PDF interactive form. 
 * In addition, beginning in PDF 1.3, FDF can be used to define a container for 
 * annotations that are separate from the PDF document to which they apply.
 */
class FDFDoc
{
public:

	/**
	 * Default constructor
	 * @param impl If impl is null (default constructor), creates an empty new document.
	 * If impl is not null, initializes a FDFDoc based on the low-level TRN_FDFDoc.
	 */
	 FDFDoc(TRN_FDFDoc impl = 0, bool owner = true);

	/**
	 * Create a FDF document from an existing SDF/Cos document.
	 * 
	 * @param sdfdoc An SDF document. FDFDoc will take the ownership of the low-level document.
	 * @note the SDFDoc will become invalid.  If you would
	 * like to access the low level document use GetSDFDoc
	 */
	 FDFDoc(SDF::SDFDoc& sdfdoc);

	/**
	 * Open an existing FDF document
	 *
	 * @param filepath - pathname to the file.
	 */
	 FDFDoc (const char* filepath);
	 FDFDoc (const UString& filepath);

	/**
	 * Open an existing FDF document
	 *
	 * @param stream - input stream containing a serialized document. The input stream may be a 
	 * random-access file, memory buffer, slow HTTP connection etc.
	 *
	 * @note if the input stream doesn't support Seek() operation the document will load whole 
	 * data stream in memory before parsing. In case of linearized FDF, the document may be parsed 
	 * on-the-fly while it is being loaded in memory. Note that since StdFile implements Seek() 
	 * interface, the document does not have to be fully in memory before it is used.
	 * 
 	 * @note Make sure to call InitSecurityHandler() after FDFDoc(...) for encrypted documents.
	 */
	 FDFDoc (Filters::Filter stream);

	/**
	 * Open a SDF/Cos document from a memory buffer.
	 * @note the document should be fully loaded in the memory buffer. 
	 * @note the buffer ownership is not transfered to the Document so the user should 
	 * clean-up if necessary.
	 * 
	 * @param buf - a memory buffer containing the serialized document
	 * @param buf_size - the size of memory buffer.
	 */
	 FDFDoc (const char* buf, size_t buf_size);

	/**
	 *	Destructor
	 */
	 ~FDFDoc ();

	/**
	 *	Close FDFDoc
	 */
	 void Close();

	/**
	 * @return - true if document was modified, false otherwise
	 */
	 bool IsModified () const; 

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
	 * 
	 * @exception - if the file can't be opened for saving or if there is a problem during Save 
	 * an Exception object will be thrown.
	 */
	 void Save(const UString& path);

	/**
	 * Saves the document to a memory buffer.
	 *
	 * @exception - if there is a problem during Save an Exception object will be thrown.
	 */
	 std::vector<unsigned char> Save();  

#ifndef SWIG
	 /**
	  * Saves the document to a memory buffer.
	  *
	  * @param out_buf a pointer to the buffer containing the serialized version of the
	  * document. (C++ Note) The buffer is owned by a document and the client doesn't need to
	  * do any initialization or cleanup.
	  * @param out_buf_size the size of the serialized document (i.e. out_buf) in bytes.
	  *
	  * @exception - if there is a problem during Save an Exception object will be thrown.
	  */
	 void Save(const char* &out_buf, size_t& out_buf_size);
#endif

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
	 * @return the FDF dictionary located in "/Root" or NULL if dictionary is not present.
	 */
	 SDF::Obj GetFDF();

	/**
	 * Get the PDF document file that this FDF file was exported from or is intended
	 * to be imported into.
	 * 
	 * @return a String with the PDF document file name.
	 */
	 UString GetPDFFileName(); 

	/**
	 * Set the PDF document file that this FDF file was exported from or is intended
	 * to be imported into.
	 * 
	 * @param filepath - pathname to the file.
	 */
	 void SetPDFFileName(const UString& filepath); 

	/**
	 * Get the ID entry from "/Root/FDF" dictionary.
	 * 
	 * @return - An object representing the ID entry in "/Root/FDF" dictionary.
	 */
	 SDF::Obj GetID(); 

	/**
	 * Set the ID entry in "/Root/FDF" dictionary.
	 * 
	 * @param id - ID array object.
	 */
	 void SetID(SDF::Obj id); 

	/**
	 * An interactive form (sometimes referred to as an AcroForm) is a
	 * collection of fields for gathering information interactively from 
	 * the user. A FDF document may contain any number of fields appearing 
	 * on any combination of pages, all of which make up a single, global 
	 * interactive form spanning the entire document.
	 * 
	 * The following methods are used to access and manipulate Interactive form 
	 * fields (sometimes referred to as AcroForms).
	 * 
	 * @return an iterator to the first FDFField in the document.
	 * @note if the document has no AcroForms, HasNext() 
	 * will return false. 
	 */
	 FDFFieldIterator GetFieldIterator();

	 /**
	 * An interactive form (sometimes referred to as an AcroForm) is a
	 * collection of fields for gathering information interactively from
	 * the user. A FDF document may contain any number of fields appearing
	 * on any combination of pages, all of which make up a single, global
	 * interactive form spanning the entire document.
	 *
	 * The following methods are used to access and manipulate Interactive form
	 * fields (sometimes referred to as AcroForms).
	 *
	 * @param field_name String representing the name of the FDFField to get.
	 * @return an iterator to the FDFField in the document.
	 * @note if the document has no AcroForms, HasNext()
	 * will return false.
	 */
	 FDFFieldIterator GetFieldIterator(const UString& field_name);


	/**
	 * @param field_name - a string representing the fully qualified name of 
	 * the field (e.g. "employee.name.first").
	 *
	 * @return a FDFField associated with the given field_name or invalid
	 * field (null) if the field is not found.
	 */
	 FDFField GetField(const UString& field_name);

	/**
	 * Create a new interactive form FDFField.
	 * @return 
	 * @exception
	 */ 
	 FDFField FieldCreate(const UString& field_name, PDF::Field::Type type, SDF::Obj field_value = 0);
	 FDFField FieldCreate(const UString& field_name, PDF::Field::Type type, const UString& field_value);
	
	 /**
	 * @return document's SDF/Cos document
	 */
	 SDF::SDFDoc& GetSDFDoc ();

	 /**
	  * Create a new FDFDoc from XFDF input. Input can be either a XFDF file path, or the XFDF data itself.
	  * @param file_name - string containing either the file path to a XFDF file, or the XML buffer containing the XFDF.
	  * @return A new FDFDoc.
	  */
	 static FDFDoc CreateFromXFDF(const UString& file_name);

	 /** 
	  * Export FDF file as an XFDF file
	  * @param filepath - the filepath of the exported XFDF file
	  */
	 void SaveAsXFDF( const UString& filepath );

	 /** 
	  * Export FDF file as a XFDF string
	  * @return A UString containing the XFDF representation of the FDF file
	  */
	 UString SaveAsXFDF();

	 /**
	  * Merge the annotations from XFDF file into FDF file
	  *
	  * @param command_file - string containing the xml command file path or xml string of the command
	  * @param permitted_user - optional user name of the permitted user
	  */
	 void MergeAnnots( const UString& command_file, const UString& permitted_user = "" );

	 FDFDoc(const FDFDoc& other);
	 
// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	mutable TRN_FDFDoc mp_doc;
#endif
// @endcond
private:	
	FDFDoc& operator=(const FDFDoc& other);
	mutable bool m_owner;
};


#include <Impl/FDFDoc.inl>

	};	// namespace FDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPFDFFDFDoc
