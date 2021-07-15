//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFFileSpec
#define PDFTRON_H_CPPPDFFileSpec

#include <C/PDF/TRN_FileSpec.h>
#include <SDF/SDFDoc.h>


namespace pdftron { 
	namespace PDF {

/** 
 * FileSpec corresponds to the PDF file specification object. 
 * 
 * A PDF file can refer to the contents of another file by using a file specification, 
 * which can take either of the following forms:
 * 
 * - A simple file specification gives just the name of the target file in 
 *   a standard format, independent of the naming conventions of any particular file system. 
 * 
 * - A full file specification includes information related to one or more specific file
 *   systems.
 * 
 * - A URL reference.
 *
 * Although the file designated by a file specification is normally external to the
 * PDF file referring to it, it is also possible to embed the file allowing its contents 
 * to be stored or transmitted along with the PDF file. However, embedding a file does not 
 * change the presumption that it is external to (or separate from) the PDF file.
 * 
 * For more details on file specifications, please refer to Section 3.10, 'File Specifications'
 * in the PDF Reference Manual.
 */
class FileSpec
{
public:

	/**
	 * Creates a file specification for the given file. By default, the specified 
	 * file is embedded in PDF.
	 * 
	 * @param doc - A document to which the FileSpec should be added. To obtain 
	 * SDFDoc from PDFDoc use PDFDoc::GetSDFDoc() or Obj::GetDoc().
	 * 
	 * @param path - The path to convert into a file specification.
	 * 
	 * @param embed - A flag indicating whether to embed specified in the PDF. 
	 * By default, all files are embedded.
	 * 
  	 * @return newly created FileSpec object.
	 */
	 static FileSpec Create(SDF::SDFDoc& doc, const UString& path, bool embed = true);

	/**
	 * Creates a URL file specification.
	 * 
	 * @param doc - A document to which the FileSpec should be added. To obtain 
	 * SDFDoc from PDFDoc use PDFDoc::GetSDFDoc() or Obj::GetDoc().
	 * 
	 * @param url - A uniform resource locator (URL) of the form defined in 
	 * Internet RFC 1738, Uniform Resource Locators Specification.
	 * 
  	 * @return newly created FileSpec object.
	 */
	 static FileSpec CreateURL(SDF::SDFDoc& doc, const char* url);

	/**
	 * Create a FileSpec and initialize it using given Cos/SDF object.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	 */
	 FileSpec(SDF::Obj f);

	/**
	 * Copy constructor
	 */
	 FileSpec (const FileSpec& d);

	/**
	 * Assignment operator
	 */
	 FileSpec& operator=(const FileSpec& d);

	/**
	 * Compares two FileSpec-s for equality. The comparison will return true
	 * only if both annotations share the same underlying SDF/Cos object. 
	 */
	 bool operator==(const FileSpec& d);

	/**
	 * @return whether this is a valid (non-null) FileSpec. If the 
	 * function returns false the underlying SDF/Cos object is null or is not valid 
	 * and the FileSpec object should be treated as null as well.
	 */ 	
	 bool IsValid() const;

	/**
	 * The function saves the data referenced by this FileSpec to an external file.
	 *
	 * @param save_as An optional parameter indicating the filepath and filename
	 * where the data should be saved. If this parameter is not specified, the function
	 * will attempt to save the file using FileSpec.GetFilePath().
	 * 
	 * If the file is embedded, the function saves the embedded file.
	 * If the file is not embedded, the function will copy the external file.
	 * If the file is not embedded and the external file can't be found, the function 
	 * returns false.
	 * 
	 * @return true is the file was saved successfully, false otherwise.
	 */
	 bool Export(const UString& save_as = "") const;

	/** 
	 * The function returns data referenced by this FileSpec.
	 *  
	 * @return A stream (filter) containing file data.
	 * If the file is embedded, the function returns a stream to the embedded file.
	 * If the file is not embedded, the function will return a stream to the external file. 
	 * If the file is not embedded and the external file can't be found, the function 
	 * returns NULL.
	 */
	 Filters::Filter GetFileData() const;

	/**
	 * @return The file path for this file specification. 
	 * 
	 * If the FileSpec is a dictionary, a corresponding platform specific path 
	 * is returned (DOS, Mac, or Unix). Otherwise the function returns the path represented 
	 * in the form described in Section 3.10.1, 'File Specification Strings,' or , if the 
	 * file system is URL, as a uniform resource locator (URL). If the FileSpec is not 
	 * valid, an empty string is returned.
	 */
	 UString GetFilePath() const;

	/** 
	 * The functions sets the descriptive text associated with the file specification. 
	 * This test is typically used in the EmbeddedFiles name tree. 
	 */
	void SetDesc(const UString& desc);

	/**
	 * @return The underlying SDF/Cos object.
	 */
	 SDF::Obj GetSDFObj () const;

	 FileSpec();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	 FileSpec(TRN_FileSpec fs);
	TRN_FileSpec mp_impl;
#endif
// @endcond
};


#include <Impl/FileSpec.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFFileSpec
