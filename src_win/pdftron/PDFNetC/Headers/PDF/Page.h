//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPage
#define PDFTRON_H_CPPPDFPage

#include <PDF/Rect.h>
#include <SDF/Obj.h>
#include <C/PDF/TRN_Page.h>
#include <Common/Matrix2D.h>

namespace pdftron { 
	namespace PDF {

class Annot;  // Forward declaration

/**
 * Page is a high-level class representing PDF page object (see 'Page Objects' in 
 * Section 3.6.2, 'Page Tree,' in PDF Reference Manual).
 *
 * Among other associated objects, a page object contains: 
 *  - A series of objects representing the objects drawn on the page (See Element and 
 *    ElementReader class for examples of how to extract page content).
 *  - A list of resources used in drawing the page 
 *  - Annotations 
 *  - Beads, private metadata, optional thumbnail image, etc.
 */ 
class Page
{
public: 

	/**
	 * Initialize a page using an existing low-level Cos/SDF page object.
	 * 
	 * @param page_dict - a low-level (SDF/Cos) page dictionary. 
	 * 
	 * @note This constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 * 
	 * @note Because PDF::PDFDoc provides a complete high-level interface for Page creation 
	 * and traversal this constructor is rarely used.
	 */
	 Page (SDF::Obj page_dict = 0);
	
	 Page (const Page& p);
	 Page& operator= (const Page& p);

	/**
	 * @return true if this is a valid (non-null) page, false otherwise. 
	 * If the function returns false the underlying SDF/Cos object is null  
	 * or is not valid.
	 */ 	
	 bool IsValid() const;

	/**
	 * @return the Page number indication the position of this Page in document's page sequence. 
	 * Document's page sequence is indexed from 1. Page number 0 means that the page is not part 
	 * of document's page sequence or that the page is not valid. 
	 */
	 int GetIndex() const;

	/**
	 * PDF page can define as many as five separate boundaries to control various aspects of the 
	 * imaging process (for more details please refer to Section 10.10.1 'Page Boundaries' in PDF 
	 * Reference Manual):
	 *
	 * - The media box defines the boundaries of the physical medium on which the page is to be 
	 * printed. It may include any extended area surrounding the finished page for bleed, printing 
	 * marks, or other such purposes. It may also include areas close to the edges of the medium 
	 * that cannot be marked because of physical limitations of the output device. Content falling 
	 * outside this boundary can safely be discarded without affecting the meaning of the PDF file.
	 * 
	 * - The crop box defines the region to which the contents of the page are to be clipped (cropped) 
	 * when displayed or printed. Unlike the other boxes, the crop box has no defined meaning in 
	 * terms of physical page geometry or intended use; it merely imposes clipping on the page 
	 * contents. The default value is the page's media box.
	 * 
	 * - The bleed box defines the region to which the contents of the page should be clipped when 
	 * output in a production environment. This may include any extra bleed area needed to 
	 * accommodate the physical limitations of cutting, folding, and trimming equipment. 
	 * The default value is the page's crop box.
	 * 
	 * - The trim box defines the intended dimensions of the finished page after trimming. It may 
	 * be smaller than the media box to allow for production related content, such as printing 
	 * instructions, cut marks, or color bars. The default value is the page's crop box.
	 * 
	 * - The art box defines the extent of the page's meaningful content (including potential 
	 * white space) as intended by the page's creator. The default value is the page's crop box.	 
	 */
	enum Box
	{
		e_media,
		e_crop,
		e_bleed,
		e_trim,
		e_art
	};

	/**
	 * @return the box specified for the page object intersected with the media box. 
	 *
	 * @param type The type of the page bounding box. Possible values are: e_media, e_crop, 
	 * e_bleed, e_trim, and e_art.
	 * 
	 * If the value for 'type' is e_crop, this call is equivalent to GetCropBox().
	 * If the value for 'type' is e_media, this call is equivalent to GetMediaBox().
	 */
	 Rect GetBox(Box type) const;

	/**
	 * Sets the page bounding box specified by 'page_region' for this page.
	 * 
	 * @param type The type of the page bounding box. Possible values are: e_media, e_crop, 
	 * e_bleed, e_trim, and e_art.
	 * @param box A rectangle specifying the coordinates to set for the box. The coordinates are
	 * specified in user space units.
	 */
	 void SetBox(Box type, const Rect& box) const;

	/**
	 * @return the crop box for this page. The page dimensions are specified in user space 
	 * coordinates. 
	 * 
	 * The crop box is the region of the page to display and print.
	 * @note this method is equivalent to GetBox(Page::e_crop)
	 */
	 Rect GetCropBox() const;

	/**
	 * Sets the crop box for this page. The crop box is the region of the page to 
	 * display and print.
	 * 
	 * @param box the new crop box for this page. The page dimensions are specified in user space 
	 * coordinates.
	 *
	 * The crop box defines the region to which the contents of the page are to be clipped (cropped) 
	 * when displayed or printed.
	 * 
	 * @note this method is equivalent to SetBox(Page::e_crop)
	 */
	 void SetCropBox(const Rect& box);

	/**
	 * @return the media box for this page. The page dimensions are specified in user space 
	 * coordinates.
	 *
	 * The media box defines the boundaries of the physical medium on which the page is to 
	 * be printed. It may include any extended area surrounding the finished page for bleed, 
	 * printing marks, or other such purposes. 
	 * 
	 * @note this method is equivalent to GetBox(Page::e_media)
	 * @exception if the page is missing media box the function throws Exception
	 */
	 Rect GetMediaBox() const;

	/**
	 * Sets the media box for this page.
	 * 
	 * @param box the new media box for this page. The page dimensions are specified in user space 
	 * coordinates.
	 *
	 * The media box defines the boundaries of the physical medium on which the page is to 
	 * be printed. It may include any extended area surrounding the finished page for bleed, 
	 * printing marks, or other such purposes. 
	 * 
	 * @note this method is equivalent to SetBox(Page::e_media)
	 */
	 void SetMediaBox(const Rect& box);

	/**
	 * @return the bounding box for this page. The page dimensions are specified in user space 
	 * coordinates.
	 *
	 * The bounding box is defined as the smallest rectangle that includes all the visible content on the page.
	 */
	Rect GetVisibleContentBox() const;

	/** 
	 * Specifies page rotation, in degrees.
	 */
	enum Rotate 
	{
		e_0,
		e_90,
		e_180,
		e_270
	};

	/**
	 * Rotate r0 clockwise by r1
	 *
	 * @param r0 first rotation.
	 * @param r1 second rotation.
	 * @return returns r0 + r1
	 */
	static Rotate AddRotations(Rotate r0, Rotate r1);

	/**
	* Rotate r0 counter clockwise by r1.
	*
	* @param r0 first rotation.
	* @param r1 second rotation.
	* @return returns r0 - r1
	*/
	static Rotate SubtractRotations(Rotate r0, Rotate r1);

	/**
	 * Convert a rotation to a number.
	 *
	 * @param r rotation to convert to number
	 * @return one of four numbers; 0, 90, 180 or 270.
	 */
	static int RotationToDegree(Rotate r);

	/**
	 * Convert a number that represents rotation in degrees to a rotation enum.
	 *
	 * @param r degree to convert to rotation. Valid numbers are multiples of 90.
	 * @return one of four angles; e_0, e_90, e_180 or e_270. Returns e_0 if input is
	 * not a multiple 90.
	 */
	static Rotate DegreeToRotation(int r);

	/**
	 * @return the rotation value for this page.
	 */
	 Rotate GetRotation() const;

	/**
	 * Sets the rotation value for this page. 
	 * 
	 * @param angle Rotation value to be set for a given page. Must be one 
	 * of the Page::Rotate values.
	 */
	 void SetRotation(Rotate angle);

	/** 
	 * @return the width for the given page region/box taking into account page
	 * rotation attribute (i.e. /Rotate entry in page dictionary).
	 *
 	 * @param box_type indicates the page box/region to query for width.
	 */
	 double GetPageWidth(Box box_type = e_crop);

	/** 
	 * @return the height for the given page region/box taking into account page
	 * rotation attribute (i.e. /Rotate entry in page dictionary).
	 *
 	 * @param box_type indicates the page box/region to query for height.
	 */
	 double GetPageHeight(Box box_type = e_crop);

	/** 
	 * @return the matrix that transforms user space coordinates to rotated and cropped coordinates.
	 * The origin of this space is the bottom-left of the rotated, cropped page.
	 * 
	 * @param flip_y this parameter can be used to mirror the page. if 'flip_y' is true the Y 
	 * axis is not flipped and it is increasing, otherwise Y axis is decreasing.
	 * 
 	 * @param box_type an optional parameter used to specify the page box/region that the matrix 
	 * should map to. By default, the function transforms user space coordinates to cropped 
	 * coordinates.
	 * 
	 * @param angle an optional parameter used to specify page rotation in addition to the 
	 * rotation specified in the page dictionary. This parameter is usually used to rotate the
	 * page without modifying the document itself.
	 */
	 Common::Matrix2D GetDefaultMatrix(bool flip_y = false, Box box_type = e_crop, Rotate angle = e_0) const;

	/**
	 * Returns SDF/Cos array containing annotation dictionaries. See Section 8.4 in 
	 * the PDF Reference for a description of the annotation array.
	 * 
	 * @return an array of annotation dictionaries representing annotations
	 * associated with the page or NULL if page dictionary is not specified.
	 */
	 SDF::Obj GetAnnots() const;

	/**
	 * Returns the number of annotations on a page. Widget annotations (form fields) are 
	 * included in the count.
	 *
	 * @return The number of annotations on a page.
	 */
	 UInt32 GetNumAnnots() const;

	/**
	 * Returns the annotation on the page.
	 * 
	 * @return Annotation object. If the index is out of range returned Annot object
	 * is not valid (i.e. annot.IsValid() returns false).
	 * 
	 * @param index - The index of the annotation to get on a page. The first annotation 
	 * on a page has an index of zero.
	 */
	 Annot GetAnnot(UInt32 index) const;

	 enum ActionTriggerEvent
	 {
		 e_action_trigger_page_open = 11, //Triggered when the page is opened and shall be executed after such an action
		 e_action_trigger_page_close = 12 //Triggered when the page is closed, This action applies to the page being closed and shall be executed before any other page is opened
	 };

	 /**
	 * Get the Action associated with the selected Page Trigger event.
	 *
	 * @param trigger the type of trigger event to get
	 * @return the Action Obj if present, otherwise NULL
	 */
	 SDF::Obj GetTriggerAction(Page::ActionTriggerEvent trigger);

	/**
	 * Adds an annotation at the specified location in a page's annotation array.
	 * 
	 * @param pos - The location in the array to insert the object. The object is inserted
	 * before the specified location. The first element in an array has a pos of zero. 
	 * If pos >= GetNumAnnots(), the method appends the annotation to the array.
	 * @param annot - The annotation to add.
	 */
	 void AnnotInsert(UInt32 pos, Annot& annot);

	/**
	 * Adds an annotation to the end of a page's annotation array.
	 * @param annot - The annotation to prepend in a page's annotation array.
	 */
	 void AnnotPushBack(Annot& annot);

	/**
	 * Adds an annotation to the beginning of a page's annotation array.
	 * @param annot - The annotation to append in a page's annotation array.
	 */
	 void AnnotPushFront(Annot& annot);

	/**
	 * Removes the given annotation from the page.
	 * @note Removing the annotation invalidates the given Annot object.
	 * @param annot The annotation to remove.
	 */
	 void AnnotRemove(Annot& annot);

	/**
	 * Removes the annotation at a given location.
	 * @note Removing the annotation invalidates any associated Annot object.
	 * @param index - A zero based index of the annotation to remove.
	 */
	 void AnnotRemove(UInt32 index);

	/**
	 * A utility method used to scale physical dimensions of the page including 
	 * all page content. 
	 * 
	 * @param scale A number greater than 0 which is used as a scale factor.
	 *  For example, calling page.Scale(0.5) will reduce physical dimensions of the 
	 *  page to half its original size, whereas page.Scale(2) will double the physical 
	 * dimensions of the page and will rescale all page content appropriately.
	 * 
	 * @note Unlike SetUserUnitSize(unit_size) which is only supported in PDF 1.6  
	 * (i.e. Acrobat 7) and above, page.Scale(sc) supports all PDF versions.  
	 */
	 void Scale(double scale);

	/**
	 * Flatten/Merge existing form field appearances with the page content and
	 * remove widget annotation.
	 * 
	 * Form 'flattening' refers to the operation that changes active form fields 
	 * into a static area that is part of the PDF document, just like the other 
	 * text and images in the document. A completely flattened PDF form does not 
	 * have any widget annotations or interactive fields. 
	 * @param field_to_flatten field to flatten
	 * @note An alternative approach to set the field as read only is using 
	 * Field.SetFlag(Field::e_read_only, true) method. Unlike Field.SetFlag(...), 
	 * the result of FlattenField() operation can not be programatically reversed.
	 */
	 void FlattenField(class Field field_to_flatten);

	/** 
	 * Tests whether this page has a transition.
	 */
	 bool HasTransition() const;

	/**
	 * Returns the UserUnit value for the page. A UserUnit is a positive number giving 
	 * the size of default user space units, in multiples of 1/72 inch.
	 * 
	 * @return the UserUnit value for the page. If the key is not present in the 
	 * page dictionary the default of 1.0 is returned.
	 */
	 double GetUserUnitSize() const;

	/**
	 * Sets the UserUnit value for a page.
	 * 
	 * @param unit_size A positive number giving the size of default user space 
	 * units, in multiples of 1/72 inch.
	 *
	 * @note This is a PDF 1.6 feature. See the implementation note 171 in 
	 * PDF Reference for details.
	 */
	 void SetUserUnitSize(double unit_size);

	/**
	 * @return a pointer to the page resource dictionary.
	 * @exception if the page is missing resource dictionary the function throws Exception
	 */
	 SDF::Obj GetResourceDict () const;

	/**
	 * @return NULL if page is empty, otherwise a single stream or an array of streams.
	 */
	 SDF::Obj GetContents () const;
	
	/**
	 * Returns the page dictionary.
	 * 
	 * @return the object to the underlying SDF/Cos object.
	 */
	 SDF::Obj GetSDFObj () const;

	/**
	 * Some of the page attributes are designated as inheritable.
	 * If such an attribute is omitted from a page object, its value is inherited 
	 * from an ancestor node in the page tree. If the attribute is a required one, 
	 * a value must be supplied in an ancestor node; if it is optional and no 
	 * inherited value is specified, the default value should be used.
	 *
	 * The function walks up the page inheritance tree in search for specified 
	 * attribute.
	 * @param attrib A string representing the attribute to search for.
	 * @return if the attribute was found return a pointer to the value. Otherwise 
	 * the function return NULL.
	 *
	 *	Resources dictionary (Required; inheritable) 
	 *  MediaBox rectangle (Required; inheritable)
	 *  CropBox rectangle (Optional; inheritable)
	 *  Rotate integer (Optional; inheritable)
	 */
	 SDF::Obj FindInheritedAttribute (const char* attrib) const;


	 /** 
	  * @return true if the object is not null, false otherwise.  
	  */ 
	 operator bool () { return IsValid();}

	 /** 
	 * @return Object representing the Image thumbnail.
	  */ 
	 SDF::Obj GetThumb() const;


// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	Page(TRN_Page impl);
	TRN_Page mp_page;
#endif
// @endcond
};


	};	// namespace PDF
};	// namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFPage
