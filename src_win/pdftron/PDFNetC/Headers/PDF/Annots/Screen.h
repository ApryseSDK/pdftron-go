//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsScreen
#define PDFTRON_H_CPPPDFAnnotsScreen

#include <PDF/Annot.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A screen annotation (PDF 1.5) specifies a region of a page upon which 
 * media clips may be played. It also serves as an object from which 
 * actions can be triggered. 
 */
class Screen : public Annot
{
	public:
	/** 
	 * Creates a Screen annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Screen(SDF::Obj d = 0);

	/** 
	 * Creates a Screen annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Screen annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Screen(const Annot& ann) : Annot(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Screen annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Screen annotation.
	*/
	static Screen Create(SDF::SDFDoc& doc, const Rect& pos);

	/** 
	 * Returns the title of the annotation. 
	 * 
	 * @return A string representing the title of the annotation.
	*/
	UString GetTitle() const;

	/** 
	 * Sets the title of the Annotation. 
	 *(Optional)
	 * 
	 * @param title A string representing the title of the annotation.
	*/
	void SetTitle(const UString& title);

	/** 					 
	 * Returns the action of the Screen annotation
	 * 
	 * @return An action object representing the action of the annotation. 
	 * @note The action is an action that shall be performed when the annotation is activated.
	*/
	Action GetAction() const;

	/** 
	 
	 * Sets the action of the Screen annotation
	 * (Optional; PDF 1.1 )
	 * 
	 * @param action An action object representing the action of the annotation. 
	 * @note The action is an action that shall be performed when the annotation is activated.
	*/
	void SetAction(const Action& action);
	
	/** 
	 * Returns the number indicating border color space of the annotation. 
	 * 
	 * @return An integer indicating a color space value from the ColorSpace::Type enum. 
	 * That is, 1 corresponding to "e_device_gray", 
	 * 3 corresponding to "e_device_rgb", and 4 corresponding to "e_device_cmyk".
	 * 0 means this annotation had no color assigned.
	*/
	int GetBorderColorCompNum() const;

	/**
	 * Returns the border color of the annotation.						 
	 * 
	 * @return A color object that denotes the color of the Screen border.
	 * @note The color can be in different color spaces: Gray, RGB, or CMYK. 
	 * Call "GetBorderColorCompNum" to access the color space information corresponding to the border color. 
	*/
	ColorPt GetBorderColor() const;

	/** 
	 * Sets the border color of the annotation.
	 * (Optional)
	 * 
	 * @param col A color object that denotes the color of the screen border.
	 * @param numcomp An integer which value indicates the color space used for the parameter c. 
	*/
	void SetBorderColor(const ColorPt& col, int numcomp); 					

	/** 
	 * Returns the number indicating background color space of the annotation. 
	 * 
	 * @return An integer indicating a color space value from the ColorSpace::Type enum. 
	 * That is, 1 corresponding to "e_device_gray", 
	 * 3 corresponding to "e_device_rgb", and 4 corresponding to "e_device_cmyk" if color space is applicable, 
	 * 0 means no background color was assigned.
	*/
	int GetBackgroundColorCompNum() const;

	/**
	 * Returns the background color of the annotation.						 
	 * 
	 * @return A color object that denotes the color of the Screen background.
	 * @note The color can be in different color spaces: Gray, RGB, or CMYK. 
	 * Call "GetBackgroundColorCompNum" to access the color space information corresponding to the border color. 
	*/
	ColorPt GetBackgroundColor() const;

	/** 
	 * Sets the background color of the annotation.
	 *(Optional)
	 * 
	 * @param col A color point that denotes the color of the screen background.
	 * @param numcomp An integer which value indicates the color space used for the parameter c. 
	*/
	void SetBackgroundColor(const ColorPt& col, int numcomp);

	/** 
	 * Returns static caption text of the annotation.
	 * 
	 * @return A string containing the static caption text of the annotation.  
	 * @note The static caption is the annotation's normal caption, which 
	 * shall be displayed when it is not interacting with the user.
	*/
	UString GetStaticCaptionText() const;

	/** 
	 * Sets static caption text of the annotation.
	 * (Optional; button fields only)					 
	 * 
	 * @param contents A string containing the static caption text of the annotation.  
	 * @note The static caption is the annotation's normal caption, which 
	 * shall be displayed when it is not interacting with the user.
	*/
	void SetStaticCaptionText(const UString& contents);

	/** 					 
	 * Returns the rollover caption text of the annotation.
	 * 
	 * @return A string containing the rollover caption text of the annotation.  
	 * @note The rollover caption shall be displayed when the user rolls the cursor 
	 * into its active area without pressing the mouse button.
	*/
	UString GetRolloverCaptionText() const;

	/** 
	 * Sets the roll over caption text of the annotation.
	 * (Optional; button fields only)					 
	 * 
	 * @param contents A string containing the roll over caption text of the annotation.  
	 * @note The rollover caption shall be displayed when the user rolls the cursor 
	 * into its active area without pressing the mouse button.
	*/
	void SetRolloverCaptionText(const UString& contents);

	/** 					
	 * Returns the button down caption text of the annotation.
	 * 
	 * @return A string containing the button down text of the annotation.  
	 * @note The button down caption shall be displayed when the mouse button is 
	 * pressed within its active area.
	*/
	UString GetMouseDownCaptionText() const;

	/** 
	 * Sets the button down caption text of the annotation.
	 * (Optional; button fields only)					
	 * 
	 * @param contents A string containing the button down text of the annotation.  
	 * @note The button down caption shall be displayed when the mouse button is 
	 * pressed within its active area.
	*/
	void SetMouseDownCaptionText(const UString& contents);

	/** 					 
	 * Returns the static icon associated with the annotation.
	 * 
	 * @return An SDF object that represents the static icon 
	 * associated with the annotation.  
	 * @note The static icon object is a form XObject defining the 
	 * annotation's normal icon, which shall be 
	 * displayed when it is not interacting with the user.
	*/
	SDF::Obj GetStaticIcon() const;

	/** 
	 * Sets the static icon associated with the annotation.
	 * (Optional; button fields only)					 
	 * 
	 * @param icon An SDF object that represents the static icon 
	 * associated with the annotation.  
	 * @note The static icon object is a form XObject defining the 
	 * annotation's normal icon, which shall be 
	 * displayed when it is not interacting with the user.
	*/
	void SetStaticIcon(SDF::Obj icon);

	/** 
	 * Returns the rollover icon associated with the annotation.
	 * 
	 * @return An SDF object that represents the rollover icon 
	 * associated with the annotation.  
	 * @note The rollover icon object is a form XObject defining the 
	 * annotation's rollover icon, which shall be displayed 
	 * when the user rolls the cursor into its active area without 
	 * pressing the mouse button.
	*/
	SDF::Obj GetRolloverIcon() const;

	/** 
	 * Sets the rollover icon associated with the annotation.
	 * (Optional; button fields only)
	 * 
	 * @param icon An SDF object that represents the rollover icon 
	 * associated with the annotation.  
	 * @note The rollover icon object is a form XObject defining the 
	 * annotation's rollover icon, which shall be displayed 
	 * when the user rolls the cursor into its active area without 
	 * pressing the mouse button.
	*/
	void SetRolloverIcon(SDF::Obj icon);

	/** 
	 * Returns the Mouse Down icon associated with the annotation.
	 * 
	 * @return An SDF object that represents the Mouse Down icon 
	 * associated with the annotation.  
	 * @note The Mouse Down icon object is a form XObject defining the 
	 * annotation's alternate (down) icon, which shall be displayed 
	 * when the mouse button is pressed within its active area.
	*/
	SDF::Obj GetMouseDownIcon() const;
	
	/** 
	 * Sets the Mouse Down icon associated with the annotation.
	 * (Optional; button fields only)					 
	 * 
	 * @param icon An SDF object that represents the Mouse Down icon 
	 * associated with the annotation.  
	 * @note The Mouse Down icon object is a form XObject defining the 
	 * annotation's alternate (down) icon, which shall be displayed 
	 * when the mouse button is pressed within its active area.
	*/
	void SetMouseDownIcon(SDF::Obj icon);


	/** 
	 * An enumeration indicating where to position the text of the annotation's 
     * caption relative to its icon.
	 * 
	 * e_NoIcon - No icon; caption only
	 * e_NoCaption - No caption; icon only
	 * e_CBelowI - Caption below the icon
	 * e_CAboveI - Caption above the icon
	 * e_CRightILeft - Caption to the right of the icon
	 * e_CLeftIRight - Caption to the left of the icon
	 * e_COverlayI - Caption overlaid directly on the icon
	 * Default value: e_NoIcon.
	*/
	enum IconCaptionRelation
	{
		e_NoIcon,
		e_NoCaption,
		e_CBelowI,
		e_CAboveI,
		e_CRightILeft,
		e_CLeftIRight,
		e_COverlayI
	};
	
	/** 
	 * Returns the Icon and caption relationship of the  annotation.
	 * 
	 * @return A value of the "IconCaptionRelation" enum type.
	 * Default value: e_NoIcon.
	 * @see IconCaptionRelation
	*/
	IconCaptionRelation GetIconCaptionRelation() const;

	/** 
	 * Sets the Icon and caption relationship of the  annotation.
	 * (Optional; pushbutton fields only)
	 * 
	 * @param icr A value of the "IconCaptionRelation" enum type.
	 * Default value: e_NoIcon.
	 * @see IconCaptionRelation
	*/

	void SetIconCaptionRelation(IconCaptionRelation icr);

	/**
	 * @note The functionality documented below is part of the Icon Fit dictionary. This
	 * dictionary specifies how to display the button's icon within the annotation 
	 * rectangle. If present, the icon fit dictionary shall apply to all
	 * of the annotation's icons (normal, rollover, and alternate).
	*/


	/** 
	 * This enum represents the circumstances under which 
	 * the icon shall be scaled inside the annotation rectangle.  
	*/
	enum ScaleCondition
	{
		e_Always, ///< Always scale
		e_WhenBigger,  ///<  Scale only when the icon is bigger than the annotation rectangle
		e_WhenSmaller, ///< Scale only when the icon is smaller than the annotation rectangle
		e_Never ///< Never scale
	};

	/** 
	 * Returns the condition under which the icon should be scaled.
	 * 
	 * @return A value of the "ScaleCondition" enum type.
	 * Default value: e_Always.
	 * @see ScaleCondition
	*/
	ScaleCondition GetScaleCondition() const;

	/** 
	 * Sets the condition under which the icon should be scaled.
	 * (Optional)
	 * 
	 * @param sc A value of the "ScaleCondition" enum type. 
	 * Default value: e_Always.
	*/
	void SetScaleCondition(ScaleCondition sc);

	/** 
	 * This enum represents the scale type of the annotation.
	 * 
	 * e_Anamorphic - Scale the icon to fill the annotation rectangle 
	 * exactly, without regard to its original aspect 
	 * ratio (ratio of width to height).
	 * e_Proportional - Scale the icon to fit the width or height 
	 * of the annotation rectangle while maintaining 
	 * the icon's original aspect ratio. If the 
	 * required horizontal and vertical scaling 
	 * factors are different, use the smaller of the two, 
	 * centering the icon within the annotation rectangle 
	 * in the other dimension.
	 * Default value: e_Proportional.
	*/
	enum ScaleType
	{
		e_Anamorphic,
		e_Proportional
	};
	
	/** 
	 * Returns the Scale Type of the annotation.
	 * 
	 * @return A value of the "ScaleType" enum which represents the Scale Type of the annotation.  
	 * Default value: P.
	 * @see ScaleType
	*/
	ScaleType GetScaleType() const;

	/** 
	 * Sets the Scale Type of the annotation.
	 * (Optional)
	 * 
	 * @param st An entry of the "ScaleType" enum which represents the Scale Type of the annotation.  
	 * Default value: P.
	 * @see ScaleType
	*/
	void SetScaleType(ScaleType st);

	
	/** 
	 * Returns the horizontal leftover space of the icon within the annotation.
	 * 
	 * @return A number indicating the horizontal 
	 * leftover space of the icon within the annotation.
	 * @note the horizontal leftover is a number that shall be between 
	 * 0.0 and 1.0 indicating the fraction of leftover space to allocate at the left.
	 * A value of 0.0 shall position the icon at the left of the annotation rectangle. 
	 * A value of 0.5 shall center it in the horizontal direction within the rectangle. 
	 * This entry shall be used only if the icon is scaled proportionally. 
	 * Default value: 0.5.
	*/
	double GetHIconLeftOver() const;

	/** 
	 * Sets the horizontal leftover space of the icon within the annotation.
	 * (Optional)
	 * 
	 * @param hl A number indicating the horizontal 
	 * leftover space of the icon within the annotation.
	 * @note the horizontal leftover space is a number that shall be between 
	 * 0.0 and 1.0 indicating the fraction of leftover space to allocate at the left.
	 * A value of 0.0 shall position the icon at the left of the annotation rectangle. 
	 * A value of 0.5 shall center it in the horizontal direction within the rectangle. 
	 * This entry shall be used only if the icon is scaled proportionally. 
	 * Default value: 0.5.
	*/
	void SetHIconLeftOver(double hl);

	/** 
	 * Returns the vertical leftover space of the icon within the annotation.
	 * 
	 * @return a number indicating the vertical
	 * leftover space of the icon within the annotation.
	 * @note the vertical leftover space is a number that 
	 * shall be between 0.0 and 1.0 indicating the fraction of leftover 
	 * space to allocate at the bottom of the icon. 
	 * A value of 0.0 shall position the icon at the bottom 
	 * of the annotation rectangle. 
	 * A value of 0.5 shall center it in the vertical direction within 
	 * the rectangle. 
	 * This entry shall be used only if the icon is scaled proportionally. 
	 * Default value: 0.5.
	*/
	double GetVIconLeftOver() const;

	/** 
	 * Sets the vertical leftover space of the icon within the annotation.
	 * (Optional)
	 * 
	 * @param vl A number indicating the vertical
	 * leftover space of the icon within the annotation.
	 * @note the vertical leftover space is a number that 
	 * shall be between 0.0 and 1.0 indicating the fraction of leftover 
	 * space to allocate at the bottom of the icon. 
	 * A value of 0.0 shall position the icon at the bottom 
	 * of the annotation rectangle. 
	 * A value of 0.5 shall center it in the vertical direction within 
	 * the rectangle. 
	 * This entry shall be used only if the icon is scaled proportionally. 
	 * Default value: 0.5.
	*/
	void SetVIconLeftOver(double vl);

	/** 
	 * Returns the "fit full" flag.
	 * 
	 * @return A boolean value indicating the "fit full" flag value.
	 * @note the fit full flag, if true, indicates that the button 
	 * appearance shall be scaled to fit fully within the bounds of 
	 * the annotation without taking into consideration the line 
	 * width of the border. 
	 * Default value: false.
	*/
	bool GetFitFull() const;

	/** 
	 * Sets the "fit full" flag.
	 * (Optional)
	 * 
	 * @param ff A boolean value indicating the "fit full" flag value.
	 * @note the fit full flag, if true, indicates that the button 
	 * appearance shall be scaled to fit fully within the bounds of 
	 * the annotation without taking into consideration the line 
	 * width of the border. Default value: false.
	*/
	void SetFitFull(bool ff);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
		Screen(TRN_Annot screen);
	#endif
	// @endcond

}; //class Screen
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron
#include <Impl/Screen.inl>

#endif // PDFTRON_H_CPPPDFAnnotsScreen
