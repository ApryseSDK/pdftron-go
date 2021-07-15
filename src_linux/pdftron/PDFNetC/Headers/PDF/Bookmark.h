//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFBookmark
#define PDFTRON_H_CPPPDFBookmark

#include <PDF/Action.h>
#include <C/PDF/TRN_Bookmark.h>

namespace pdftron { 
	namespace PDF {


/** 
 * A %PDF document may optionally display a document outline on the screen, allowing
 * the user to navigate interactively from one part of the document to another.
 * The outline consists of a tree-structured hierarchy of Bookmarks (sometimes
 * called outline items), which serve as a 'visual table of contents' to display the 
 * document's structure to the user. 
 * 
 * Each Bookmark has a title that appears on screen, and an Action that specifies 
 * what happens when a user clicks on the Bookmark. The typical action for a 
 * user-created Bookmark is to move to another location in the current document, 
 * although any action (see PDF::Action) can be specified.
 *
 * Bookmark is a utility class used to simplify work with %PDF bookmarks (or 
 * outlines; see section 8.2.2 'Document Outline' in %PDF Reference Manual for 
 * more details).
 */
class Bookmark
{
public:

	/**
	 * Creates a new valid Bookmark with given title in the 
	 * specified document. 
	 *
	 * @param in_doc The document in which a Bookmark is to be created. 
	 * @param in_title The title string value of the new Bookmark. 
	 *
	 * @return The new Bookmark. 
	 *
	 * @note The new Bookmark is not linked to the outline tree. 
	 * Use AddChild()/AddNext()/AddPrev() methods in order to link the Bookmark 
	 * to the outline tree
	 */
	 static Bookmark Create(class PDFDoc& in_doc, const UString& in_title);

	/**
	 * A constructor. Creates a null (non-valid) bookmark.
	 */
	 Bookmark();

	/**
	 * A constructor. Creates a Bookmark and initialize it using given Cos/SDF object.
	 *
	 * @param in_bookmark_dict Pointer to the Cos/SDF object (outline item dictionary). 
	 *
	 * @return The new Bookmark. 
	 *
	 * @note The constructor does not copy any data, but is instead the logical 
	 * equivalent of a type cast.
	 */
	 Bookmark(SDF::Obj in_bookmark_dict);

	/**
	 * Copy constructor. Creates a copy of the given Bookmark object.
	 *
	 * @param in_bookmark A reference to an existing Bookmark object.
	 *
	 * @return The new Bookmark. 
	 */
	 Bookmark(const Bookmark& in_bookmark);

	/**
	 *	Sets this Bookmark object equal to the specified Bookmark object.
	 *
	 * @param in_bookmark Reference to a Bookmark object that is assigned to this Bookmark object. 
	 *
	 * @return This method returns a reference to this Bookmark object to allow cascaded assignments.
	 */
	 Bookmark& operator=(const Bookmark& in_bookmark);

	/**
	 * Compares two Bookmark objects for equality.
	 * 
	 * @param in_bookmark A reference to an existing Bookmark object.
	 *
	 * @return True if the both Bookmarks share the same underlying SDF/Cos object; otherwise false. 
	 */
	 bool operator==(const Bookmark& in_bookmark);

	/**
	 * Indicates whether the Bookmark is valid (non-null).
	 *
	 * @return True if this is a valid (non-null) Bookmark; otherwise false. 
	 *
	 * @note If this method returns false the underlying SDF/Cos object is null and 
	 * the Bookmark object should be treated as null as well.
	 */ 	
	 bool IsValid() const;

	/**
	 * Indicates whether the Bookmark has children.
	 *
	 * @return True if the Bookmark has children; otherwise false.
	 */
	 bool HasChildren();	

	/**
	 * Returns the Bookmark's next (right) sibling.
	 *
	 * @return the Bookmark's next (right) sibling.
	 */
	 Bookmark GetNext();

	/**
	 * Returns the Bookmark's previous (left) sibling.
	 *
	 * @return The Bookmark's previous (left) sibling.
	 */
	 Bookmark GetPrev();

	/**
	 * Returns the Bookmark's first child.
	 *
	 * @return The Bookmark's first child.
	 */
	 Bookmark GetFirstChild();

	/**
	 * Returns the Bookmark's last child.
	 *
	 * @return The Bookmark's last child.
	 */
	 Bookmark GetLastChild();

	/**
	 * Returns the Bookmark's parent Bookmark.
	 *
	 * @return The Bookmark's parent Bookmark.
	 */
	 Bookmark GetParent();

	/**
	 * Returns the Bookmark specified by the given title string.
	 *
	 * @param in_title The title string value of the Bookmark to find. 
	 *
	 * @return A Bookmark matching the title string value specified.
	 */
	 Bookmark Find(const UString& in_title);

	/** 
	 * Adds a new Bookmark as the new last child of this Bookmark.
	 * 
	 * @param in_title The title string value of the new Bookmark. 
	 *
	 * @return The newly created child Bookmark.
	 *
	 * @note If this Bookmark previously had no children, it will be open 
	 * after the child is added.
	 */ 
	 Bookmark AddChild(const UString& in_title);

	/** 
	 * Adds the specified Bookmark as the new last child of this Bookmark.
	 * 
	 * @param in_bookmark The Bookmark object to be added as a last child of this Bookmark.
	 *
	 * @note Parameter in_bookmark must not be linked to a bookmark tree.
	 * @note If this Bookmark previously had no children, it will be open 
	 * after the child is added.
	 */
	 Bookmark AddChild(Bookmark in_bookmark);

	/** 
	 * Adds a new Bookmark to the tree containing this Bookmark, as the 
	 * new right sibling.
	 *
	 * @param in_title The title string value of the new Bookmark. 
	 *
	 * @return The newly created sibling Bookmark.
	 */ 
	 Bookmark AddNext(const UString& in_title);

	/** 
	 * Adds the specified Bookmark as the new right sibling to this Bookmark,
	 * adjusting the tree containing this Bookmark appropriately.
	 * 
	 * @param in_bookmark The Bookmark object to be added to this Bookmark.
	 *
	 * @note Parameter in_bookmark must not be linked to a bookmark tree.
	 */ 
	 void AddNext(Bookmark in_bookmark);

	/** 
	 * Adds a new Bookmark to the tree containing this Bookmark, as the 
	 * new left sibling.
	 *
	 * @param in_title The title string value of the new Bookmark. 
	 *
	 * @return The newly created sibling Bookmark.
	 */ 
	 Bookmark AddPrev(const UString& in_title);

	/** 
	 * Adds the specified Bookmark as the new left sibling to this Bookmark, 
	 * adjusting the tree containing this Bookmark appropriately.
	 * 
	 * @param in_bookmark The Bookmark object to be added to this Bookmark.
	 *
	 * @note Parameter in_bookmark must not be linked to a bookmark tree.
	 */ 
	 void AddPrev(Bookmark in_bookmark);

	/** 
	 * Removes the Bookmark's subtree from the bookmark tree containing it.
	 */ 
	 void Delete();

	/** 
	 * Unlinks this Bookmark from the bookmark tree that contains it, and 
	 * adjusts the tree appropriately. 
	 *
	 * @note After the bookmark is unlinked is can be moved to another place 
	 * in the bookmark tree located in the same document.
	 */ 
	 void Unlink();

	/**
	 * Returns the indentation level of the Bookmark in its containing tree.
	 *
	 * @return The indentation level of the Bookmark in its containing tree.
	 *
	 * @note The root level has an indentation level of zero.
	 */
	 int GetIndent();

	/**
	 * Indicates whether the Bookmark is open.
	 *
	 * @return True if this Bookmark is open; otherwise false. 
	 *
	 * @note An open Bookmark shows all its children.
	 */
	 bool IsOpen();

	/**
	 * Opens or closes the Bookmark.
	 *
	 * @param in_open Boolean value that contains the status. 
	 * If true, the Bookmark is opened. Otherwise the Bookmark is closed.
	 *
	 * @note An opened Bookmark shows its children, while a closed Bookmark does not.
	 */
	 void SetOpen(bool in_open);

	/**
	 * Returns the number of opened bookmarks in this subtree.
	 *
	 * @return The number of opened bookmarks in this subtree (not including 
	 * this Bookmark). If the item is closed, a negative integer whose 
	 * absolute value specifies how many descendants would appear if the 
	 * item were reopened.
	 */
	 int GetOpenCount();

	/**
	 * Returns the Bookmark's title string.
	 *
	 * @return The Bookmark's title string).
	 */
	 UString GetTitle();

	/**
	 * Returns the Bookmark's title string object.
	 * @return The Bookmark's title string object.
	 */
	 SDF::Obj GetTitleObj();

	/**
	 * Sets the Bookmark's title string.
	 *
	 * @param title The new title string for the bookmark.
	 */ 
	 void SetTitle(const UString& title);

	/**
	 * Returns the Bookmark's action.
	 *
	 * @return The Bookmark's action.
	 */
	 Action GetAction();

	/** 
	 * Sets the Bookmark's action.
	 *
	 * @param in_action The new Action for the Bookmark. 
	 */
	 void SetAction(Action in_action);

	/** 
	 * Removes the Bookmark's action.
	 */
	 void RemoveAction();	

	/**
	 * Returns the Bookmark's flags.
	 *
	 * @return The flags of the Bookmark object.
	 * Bit 1 (least-significant bit) indicates italic font whereas 
	 * bit 2 indicates bold font.
	 * Therefore, 0 indicates normal, 1 is italic, 2 is bold, and 3 is bold-italic.
	 */ 
	 int GetFlags();

	/**
	 * Sets the Bookmark's flags.
	 *
	 * @param in_flags The new bookmark flags. 
	 * Bit 1 (the least-significant bit) indicates italic font whereas 
	 * bit 2 indicates bold font. 
	 * Therefore, 0 indicates normal, 1 is italic, 2 is bold, and 3 is bold-italic.
	 */
	 void SetFlags(int in_flags);

	/**
	 * Returns the Bookmark's RGB color value.
	 *
	 * @param out_r Reference to a variable that receives the red component of the color.
	 * @param out_g Reference to a variable that receives the green component of the color.
	 * @param out_b Reference to a variable that receives the blue component of the color.
	 *
	 * @note The three numbers  \a out_r, \a out_g, and \a out_b are in the range 0.0 to 1.0,
	 * representing the components in the DeviceRGB color space of the color 
	 * to be used for the Bookmark's text.
	 *
	 * <b>Example:</b>  
	 * \code 
	 *   double red, green, blue; 
	 *   bookmark.GetColor(red, green, blue);
	 * \endcode
	 */ 
	 std::vector<double> GetColor();

#ifndef SWIG
	 void GetColor(double& out_r, double& out_g, double& out_b);
#endif

	/**
	 * Sets the Bookmark's color value.
	 *
	 * @param in_r The red component of the color.
	 * @param in_g The green component of the color.
	 * @param in_b The blue component of the color.
	 *
	 * @note The three numbers \a in_r, \a in_g, and \a in_b are in the range 0.0 to 1.0, representing
	 * the components in the DeviceRGB color space of the color to be used
	 * for the Bookmark's text. 
	 * Default color value is black, [0.0 0.0 0.0].
	 */
	 void SetColor(double in_r = 0.0, double in_g = 0.0, double in_b = 0.0);

	/**
	 * Returns the underlying SDF/Cos object.
	 *
	 * @return The underlying SDF/Cos object.
	 *
	 * @note A null (non-valid) bookmark returns a null object.
	 */
	 SDF::Obj GetSDFObj() const;

   //for xamarin use only
	static Bookmark* CreateInternal(ptrdiff_t impl);
	ptrdiff_t GetHandleInternal();


// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	Bookmark(TRN_Bookmark impl);
	TRN_Bookmark mp_obj;
#endif
// @endcond
};

	};	// namespace PDF
};	// namespace pdftron

#include <Impl/PDFDoc.inl>

#endif // PDFTRON_H_CPPPDFBookmark
