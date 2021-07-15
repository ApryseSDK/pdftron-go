//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsRubberStamp
#define PDFTRON_H_CPPPDFAnnotsRubberStamp

#include <PDF/Annots/Markup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A RubberStamp annotation displays text or graphics intended 
 * to look as if they were stamped on the page with a rubber stamp. 
 */
class RubberStamp : public Markup
{						
	public:	
	/** 
	 * Creates a RubberStamp annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	RubberStamp(SDF::Obj d = 0);

	/** 
	 * Creates a RubberStamp annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the RubberStamp annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	RubberStamp(const Annot& ann) : Markup(ann.GetSDFObj()) {} 

	/** 
	 * This enum represents the Icon type of the RubberStamp annotation
	*/
	enum Icon
	{
		e_Approved,				///<a stamp with the text "Approved" 
		e_Experimental,			///<a stamp with the text "Experimental" 
		e_NotApproved,			///<a stamp with the text "Not Approved" 
		e_AsIs,					///<a stamp with the text "As Is" 
		e_Expired,				///<a stamp with the text "Expired" 
		e_NotForPublicRelease,	///<a stamp with the text "Not For Public Release" 
		e_Confidential,			///<a stamp with the text "Confidential" 
		e_Final,				///<a stamp with the text "Final" 
		e_Sold,					///<a stamp with the text "Sold" 
		e_Departmental,			///<a stamp with the text "Departmental" 
		e_ForComment,			///<a stamp with the text "For Comment" 
		e_TopSecret,			///<a stamp with the text "Top Secret" 
		e_ForPublicRelease,		///<a stamp with the text "For Public Release" 
		e_Draft,				///<a stamp with the text "Draft" 
		e_Unknown				///< Non-standard or user defined stamp.
	};
	
	/** 
	 * Creates a new RubberStamp annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank RubberStamp annotation.
	*/
	static RubberStamp Create(SDF::SDFDoc& doc, const Rect& pos, Icon icon= e_Draft);

	/** 
	 * Creates a new RubberStamp annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * @param form_xobject An object specifying a custom appearance for the annotation, containing
	 *    TEXT as string (mandatory): The text to be displayed in rubber stamp
	 *    TEXT_BELOW as string (optional): The text to be displayed below the first text
	 *    FILL_COLOR as an array of three or four numbers between 0.0 to 1.0 (optional): The fill color
	 *    TEXT_COLOR as an array of three or four numbers between 0.0 to 1.0 (optional): The text color
	 *    BORDER_COLOR as an array of three or four numbers between 0.0 to 1.0 (optional): The border color
	 *    FILL_COLOR_START as an array of three or four numbers between 0.0 to 1.0 (optional):
	 *       The start fill color if background is gradient
	 *    FILL_COLOR_END as an array of three or four numbers between 0.0 to 1.0 (optional):
	 *       The end fill color if background is gradient
	 *    FILL_OPACITY as a number (optional): the fill opacity
	 *    TEXT_OPACITY as a number (optional): the text opacity
	 *    ROTATION as a number (optional): rotation. valid numbers are {0, 90, 180, 270}
	 *    POINTING_LEFT as a boolean (optional): if the stamp is pointing left
	 *    POINTING_RIGHT as a boolean (optional): if the stamp is pointing right
	 * 
	 * @return A newly created RubberStamp annotation.
	*/
	static RubberStamp Create(SDF::SDFDoc& doc, const Rect& pos, SDF::Obj* form_xobject);

	/** 
	 * Returns the type of the icon associated with the RubberStamp annotation. 
	 * 
	 * @return A value of enum "Icon" that represents 
	 * the type of icon associated with the annotation.	
	 * Default value: e_Draft.
	*/
	Icon GetIcon() const;

	/** 
	 * Sets the type of the icon associated with the RubberStamp annotation.
	 * 
	 * @param type A value of enum "Icon" type that represents 
	 * the type of icon associated with the annotation.	
	 * Default value: e_Draft.
	*/
	void SetIcon(Icon type = e_Draft);

	/** 
	 * Returns the name of the icon associated with the RubberStamp annotation. 
	 * 
	 * @return A string that is the name of the icon associated with 
	 * the RubberStamp annotation. 
	 * @note The following icon names are equivalent 
	 * to predefined icon types from the enum "Icon":
	 * "Approved" = e_Approved
	 * "Experimental" = e_Experimental
	 * "NotApproved" = e_NotApproved
	 * "AsIs" = e_AsIs
	 * "Expired" = e_Expired
	 * "NotForPublicRelease" = e_NotForPublicRelease
	 * "Confidential" = e_Confidential
	 * "Final" = e_Final
	 * "Sold" = e_Sold
	 * "Departmental" = e_Departmental
	 * "Format" = e_ForComment
	 * "TopSecret" = e_TopSecret
	 * "ForPublicRelease" = e_ForPublicRelease
	 * "Draft" = e_Draft
	 * "Unknown" = e_Unknown
	 * Names other than mentioned above do not have predefined icon appearances. 
	*/
	const char* GetIconName() const; 

	/** 
	 * Sets the name of the icon associated with the RubberStamp annotation.
	 * 
	 * @param iconstring the name of the icon associated with 
	 * the RubberStamp annotation. 
	 * @note The following icon names are equivalent 
	 * to predefined icon types from the enum "Icon":
	 * "Approved" = e_Approved
	 * "Experimental" = e_Experimental
	 * "NotApproved" = e_NotApproved
	 * "AsIs" = e_AsIs
	 * "Expired" = e_Expired
	 * "NotForPublicRelease" = e_NotForPublicRelease
	 * "Confidential" = e_Confidential
	 * "Final" = e_Final
	 * "Sold" = e_Sold
	 * "Departmental" = e_Departmental
	 * "Format" = e_ForComment
	 * "TopSecret" = e_TopSecret
	 * "ForPublicRelease" = e_ForPublicRelease
	 * "Draft" = e_Draft
	 * "Unknown" = e_Unknown
	 * Names other than mentioned above do not have predefined icon appearances. 
	*/
	void SetIcon(const char* icon);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
		RubberStamp(TRN_Annot rubberstamp);
	#endif
	// @endcond
					
				}; //class rubber stamp
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsRubberStamp
