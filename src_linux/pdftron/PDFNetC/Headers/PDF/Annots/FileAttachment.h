//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsFileAttachment
#define PDFTRON_H_CPPPDFAnnotsFileAttachment

#include <PDF/Annots/Markup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A file attachment annotation contains a reference to a file, which may be
 * embedded in the PDF document.
 */
class FileAttachment : public Markup
{
	public:
	/**
	 * Icon style
	*/	
	enum Icon
	{
		e_Graph,      ///< The icon has graph appearance
		e_PushPin,    ///<The icon has a push pin appearance.
		e_Paperclip,  ///<The icon has a paper clip appearance
		e_Tag,        ///< The icon has tag appearance
		e_Unknown     ///< The icon has unrecognized appearance type
	};

	/** 
	 * Creates an FileAttachment annotation and initializes it using given Cos/SDF object.
	 * d Cos/SDF object used to initialize the FileAttachment annotation
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	FileAttachment(SDF::Obj d = 0);	

	/** 
	 * Creates an FileAttachment annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the FileAttachment annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	FileAttachment(const Annot& ann) : Markup(ann.GetSDFObj()) {} 
	
	/**
	 * Creates a file attachment annotation.
	 *
	 * A file attachment annotation contains a reference to a file, which typically
	 * is embedded in the PDF file.
	 *
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, in user space coordinates.
	 * Note that FileAttachment icons can differ in their appearance dimensions, so you may want
	 * to match these Rectangle dimensions or the aspect ratio to avoid a squished or stretched appearance:
	 * e_Graph: 40 x 40
	 * e_PushPin: 28 x 40
	 * e_Paperclip: 14 x 34
	 * e_Tag: 40 x 32
	 * @param fs a file specification object used to initialize the file attachment annotation.
	 * @param icon_name The name of an icon to be used in displaying the annotation, default is PushPin.
	 * @note PDF Viewer applications should provide predefined icon appearances for at least 
	 * the following standard names: Graph, PushPin, Paperclip, Tag. Additional names may 
	 * be supported as well. Default value: PushPin.
	 *
	 * @return A new file attachment annotation. 
	*/
	static FileAttachment Create(SDF::SDFDoc& doc, const Rect& pos, FileSpec fs, Icon icon_name = e_PushPin );

	/**
	 * Creates a file attachment annotation.
	 *
	 * A file attachment annotation contains a reference to a file, which typically
	 * is embedded in the PDF file.
	 *
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, in user space coordinates.
	 * Note that FileAttachment icons can differ in their appearance dimensions, so you may want 
	 * to match these Rectangle dimensions or the aspect ratio to avoid a squished or stretched appearance:
	 * e_Graph: 40 x 40
	 * e_PushPin: 28 x 40
	 * e_Paperclip: 14 x 34
	 * e_Tag: 40 x 32
	 * @param path The path to the file which should be attached	 
	 * @param icon_name An icon to be used in displaying the annotation, default is PushPin.
	 * @note PDF Viewer applications should provide predefined icon appearances for at least 
	 * the following standard names: Graph PushPin Paperclip Tag. Additional names may 
	 * be supported as well. Default value: PushPin.
	 *
	 * @return A new file attachment annotation. 
	*/
	static FileAttachment Create(SDF::SDFDoc& doc, const Rect& pos, const UString& path, Icon icon_name = e_PushPin );

	/**
	 * Creates a file attachment annotation. This method should be used when a nonstandard
	 * icon type is desired in the annotation.
	 *
	 * A file attachment annotation contains a reference to a file, which typically
	 * is embedded in the PDF file.
	 *
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds, in user space coordinates.
	 * @param path The path to the file which should be attached
	 * @param icon_name The name of an icon to be used in displaying the annotation.
	 * @note PDF Viewer applications should provide predefined icon appearances for at least 
	 * the following standard names: Graph PushPin Paperclip Tag. Additional names may 
	 * be supported as well. Default value: PushPin.
	 *
	 * @return A new file attachment annotation. 
	*/
	static FileAttachment Create(SDF::SDFDoc& doc, const Rect& pos, const UString& path, const char* icon_name );

	/** 
	 * @return the file specification that contains a file reference or the embedded file data stream. 
	*/
	FileSpec GetFileSpec() const;

	/** 
	 * Sets the file specification.
	 * 
	 * @param file The file specification to associate with this annotation..
	 * The file specification contains a file reference or the embedded file data stream. 
	*/
	void SetFileSpec(const FileSpec& file);

	/**
	 * The function saves the data referenced by this File Attachment to an 
	 * external file.
	 *
	 * If the file is embedded, the function saves the embedded file.
	 * If the file is not embedded, the function will copy the external file.
	 * If the file is not embedded and the external file can't be found, the function 
	 * returns false.
	 * 
	 * @param save_as An optional parameter indicating the filepath and filename
	 * where the data should be saved. If this parameter is not specified the function 
	 * will attempt to save the file using FileSpec.GetFilePath().
	 *
	 * @return true is the file was saved successfully, false otherwise.
	 * 
	 */
	bool Export(const UString& save_as = "") const;
	


	/** 
	 * @return the type the associated icon style.
	 * @default e_PushPin
	 * @note The annotation dictionary's appearance stream, if present, will take precedence over this entry
	 * when displaying the annotation in the viewer.
	*/
	Icon GetIcon() const;

	/** 
	 * Sets the icon style associated with FileAttachment annotation.
	 * (Optional)
	 * 
	 * @param type icon style.
	 * @default e_PushPin
	 * @note The annotation dictionary's appearance stream, if present, will take precedence over this entry
	 * when displaying the annotation in the viewer.
	*/
	void SetIcon(Icon type=e_PushPin);

	/** 
	 * Returns the name of the icon associated with the FileAttachment annotation. 
	 * 
	 * @return A string denoting the name of the icon. 
	 * 
	 * @see GetIcon() GetIconName() returns the icon name as it appears in the annotation dictionary, while GetIcon() returns
	 * the same icon name converted to enumeration value.
	 * @note The annotation dictionary's appearance stream, if present, will take precedence over this entry
	 * when displaying the annotation in the viewer.
	*/
	const char* GetIconName() const; 

	/** 
	 * Sets the name of the icon associated with the FileAttachment annotation. 
	 * (Optional)
	 * 
	 * @param iname A string.denoting the name of the icon. 
	 * @note this method should be used to assign non-standard icon type to the annotation.
	 * @see SetIcon()
	 * @note The annotation dictionary's appearance stream, if present, will take precedence over this entry
	 * when displaying the annotation in the viewer.
	*/
	void SetIconName(const char* iname);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
		FileAttachment(TRN_Annot fileattachment);
	#endif
	// @endcond

}; //class file attachment
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron

#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsFileAttachment
