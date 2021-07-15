//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsText
#define PDFTRON_H_CPPPDFAnnotsText

#include <PDF/Annots/Markup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A text annotation represents a "sticky note" attached to a point in 
 * the PDF document. When closed, the annotation shall appear as an icon; 
 * when open, it shall display a pop-up window containing the text of 
 * the note in a font and size chosen by the conforming reader. 
 * Text annotations do not scale and rotate with the page (i.e. they should
 * behave as if the NoZoom and NoRotate annotation flags).
 */
class Text : public Markup
{					
	public:
	/** 
	 * Creates a Text annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/	
	Text(SDF::Obj d = 0);

	/** 
	 * Creates a Text annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Text annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Text(const Annot& ann) : Markup(ann.GetSDFObj()) {}

	/** 
	 * Creates a new Text annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Text annotation.
	 */
	//static Text Create(SDF::SDFDoc& doc, const Rect& pos);

	/** 
	 * Creates a new Text annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * @param contents The text of the annotation, that shall be displayed in its popup window.
	 * 
	 * @return A newly created Text annotation.
	 */
	static Text Create(SDF::SDFDoc& doc, const Rect& pos, const UString& contents  = UString("") );	

	/** 
	 * Creates a new Text annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A point specifying the annotation's location in default user space units.
	 *        This determines the location of bottom left corner of the annotation's icon.
	 * @param contents The text of the annotation, that shall be displayed in its popup window.
	 * 
	 * @return A newly created Text annotation.
	 */
	static Text Create(SDF::SDFDoc& doc, const Point& pos, const UString& contents = UString("") );	


	/** 
	 * Returns the initial status of the Text annotation. 
	 * 
	 * @return A boolean value that specifies whether the annotation shall 
	 * initially be displayed as opened.
	 * Default value: false. 
	*/
	bool IsOpen() const;

	/** 
	 * Sets the initial status of the Text annotation. 
	 * (Optional)
	 * 
	 * @param isopen A boolean value that specifies whether the annotation shall 
	 * initially be displayed as opened.
	 * Default value: false.
	*/
	void SetOpen(bool isopen);

	/** 
	 * Icon enumeration defines the type of icon 
	 * associated with the Text annotation.
	 * 
	*/
	enum Icon 
	{
		e_Comment,      ///<comment icon
		e_Key,          ///<key icon
		e_Help,	        ///<Help icon
		e_NewParagraph, ///<New Paragraph icon
		e_Paragraph,    ///<Paragraph icon
		e_Insert,       ///<Insert icon
		e_Note,	        ///<Note icon
		e_Unknown       ///<Unknown, no icon associated or non-standard icon.
	};

	/** 
	 * Returns the type of the icon associated with the Text annotation. 
	 * 
	 * @return A value of the enumeration type "Icon".
	 * Default value: e_Note.
	 * @note The annotation's appearance stream, 
	 * if present, will take precedence over this entry. 
	*/
	Icon GetIcon() const; 

	/** 
	 * Returns the name of the icon associated with the Text annotation. 
	 * 
	 * @return A string denoting the name of the icon. 
	 * @note The following icon names are equivalent 
	 * to predefined icon types from the enum "Icon":
	 * "Comment" = e_Comment
	 * "Key" = e_Key
	 * "Help" = e_Help
	 * "NewParagraph" = e_NewParagraph
	 * "Paragraph" = e_Paragraph
	 * "Insert" = e_Insert
	 * "Note" = e_Note
	 * "Unknown" = e_Unknown
	 * Names other than mentioned above do not have predefined icon appearances. 
	 * @note The annotation's appearance stream, 
	 * if present, will take precedence over this entry. 
	*/
	const char* GetIconName() const; 

	/** 
	 * Sets the type of the icon associated with the Text annotation. 
	 * (Optional)
	 * 
	 * @param icon A value of the enum "Icon" type.
	 * Default value: e_Note.
	 * @note The annotation's appearance stream, 
	 * if present, will take precedence over this entry. 
	*/
	void SetIcon(Icon icon=e_Note);

	/** 
	 * Sets the name of the icon associated with the Text annotation.
	 * (Optional)
	 * 
	 * @param icon A string denoting the name of the icon. 
	 * @note The following icon names are equivalent 
	 * to predefined icon types from the enum "Icon":
	 * "Comment" = e_Comment
	 * "Key" = e_Key
	 * "Help" = e_Help
	 * "NewParagraph" = e_NewParagraph
	 * "Paragraph" = e_Paragraph
	 * "Insert" = e_Insert
	 * "Note" = e_Note
	 * "Unknown" = e_Unknown
	 * Names other than mentioned above do not have predefined icon appearances. 
	 * @note The annotation's appearance stream, 
	 * if present, will take precedence over this entry. 
	*/
	void SetIcon(const char* icon);

	/** 						 
	 * Returns the string indicating the state of the Text annotation. 
	 * (PDF 1.5)
	 * 
	 * @return A string that indicates the state of the Text annotation when first loaded.  
	 * Default: "Unmarked" if StateModel is "Marked"; "None" if StateModel is "Review".
	*/
	UString GetState() const;

	/** 						 
	 * Sets the string indicating the state of the Text annotation. 
	 * (Optional; PDF 1.5 )
	 * 
	 * @param state A string that indicates the state of the Text annotation when first loaded.  
	 * Default: "Unmarked" if StateModel is "Marked"; "None" if StateModel is "Review".
	*/
	void SetState(const UString& state="");

	/** 						 
	 * Returns the string indicating the state model of the Text annotation. 
	 * (PDF 1.5)
	 * 
	 * @return A string containing the state model name - either "Marked" or "Review".
	*/
	UString GetStateModel() const;

	/** 						 
	 * Sets the string indicating the state model of the Text annotation. 
	 * (Required if State is present, otherwise optional; PDF 1.5 )
	 * 
	 * @param sm A string containing the state model name - either "Marked" or "Review".
	 */
	void SetStateModel(const UString& sm );

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	Text(TRN_Annot text);
	#endif
	// @endcond

};//class Text
			};//namespace Annot
		};//namespace PDF
};//namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsText
