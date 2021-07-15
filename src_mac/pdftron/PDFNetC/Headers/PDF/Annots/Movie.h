//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsMovie
#define PDFTRON_H_CPPPDFAnnotsMovie

#include <PDF/Annot.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A movie annotation contains animated graphics and sound to be 
 * presented on the computer screen and through the speakers. When the 
 * annotation is activated, the movie is played. 
 */
class Movie : public Annot
{
	public:
	/** 
	 * Creates a Movie annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Movie(SDF::Obj d = 0);	

	/** 
	 * Creates a Movie annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Movie annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Movie(const Annot& ann) : Annot(ann.GetSDFObj()) {} 

	/** 
	 * Creates a new Movie annotation in the specified document.
	 * 
	 * @param doc A document to which the Movie annotation is added.
	 * @param pos A rectangle specifying the Movie annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Movie annotation.
	 */
	static Movie Create(SDF::SDFDoc& doc, const Rect& pos);

	/** 
	 * Returns the title of the Movie Annotation. 
	 * 
	 * @return A string representing the title of the Movie Annotation.
	 * @note Movie actions may use this title to reference the movie annotation.
	*/
	UString GetTitle() const;

	/** 
	 * Sets the title of the Movie Annotation. 
	 *(Optional)
	 * 
	 * @param title A string representing the title of the Movie Annotation.
	 * @note Movie actions may use this title to reference the movie annotation.
	*/
	void SetTitle(const UString& title);

	/** 
	 * Returns the option of whether the Movie is to be played. 
	 * 
	 * @return a boolean value indicating if the movie is to be played.
	 * @note IsToBePlayed is a flag specifying whether to play the movie when the annotation is activated. 
	 * The movie shall be played using default activation parameters. If the value is false, 
	 * the movie shall not be played. 
	 * Default value: true.
	*/
	bool IsToBePlayed() const;
	
	/** 
	 * Sets the option of whether the Movie is to be played. 
	 *(Optional)
	 * 
	 * @param isplay A boolean value telling if the movie is to be played.
	 * Default value: true. 
	 * @note IsToBePlayed is a flag specifying whether to play the movie when the annotation is activated. 
	 * The movie shall be played using default activation parameters. If the value is false, 
	 * the movie shall not be played. 
	 * Default value: true.
	*/
	void SetToBePlayed(bool isplay=true);


// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	Movie(TRN_Annot movie);
#endif
// @endcond

}; //class Movie
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsMovie
