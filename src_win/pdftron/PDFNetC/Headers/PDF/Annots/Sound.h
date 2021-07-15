//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFAnnotsSound
#define PDFTRON_H_CPPPDFAnnotsSound

#include <PDF/Annots/Markup.h>

namespace pdftron { 
		namespace PDF {
			namespace Annots {
/** 
 * A Sound annotation represents a sound recording attached to a point in 
 * the PDF document. When closed, this annotation appear as an icon; when open
 * and activated, a sound record from the computer's microphone or imported from a file
 * associated with this annotation is played.The icon of this annotation by default
 * is a speaker.  
 */
class Sound : public Markup
{
	public:
	/** 
	 * The Icon of the Sound annotation.
	*/
	enum Icon
	{
		e_Speaker,	///< Speaker sound
		e_Mic,		///< Mic sound
		e_Unknown	///< Invalid or non-standard
	};
	
	/** 
	 * Creates a Sound annotation and initializes it using given Cos/SDF object.
	 * @param d The Cos/SDF object to initialze the annotation with.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Sound(SDF::Obj d = 0);

	/** 
	 * Creates a Sound annotation and initializes it using given annotation object.
	 * @param ann Annot object used to initialize the Sound annotation.
	 * @note The constructor does not copy any data, but is instead the logical
	 * equivalent of a type cast.
	*/
	Sound(const Annot& ann) : Markup(ann.GetSDFObj()) {}

	/** 
	 * Creates a new Sound annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A rectangle specifying the annotation's bounds in default user space units.
	 * 
	 * @return A newly created blank Sound annotation.
	*/
	static Sound Create(SDF::SDFDoc& doc, const Rect& pos, Icon icon = e_Speaker );
	
	/** 
	* Creates a new Sound annotation in the specified document. Accepts raw
	* audio data, along with a few parameters describing the format of that data
	* 
	* @param doc A document to which the annotation is added.
	* @param pos A rectangle specifying the annotation's bounds in default user space units.
	* @param source_data The raw sound data for the newly created annot
	* @param bits_per_sample The number of bits per sample in source data
	* @param sample_freq The number of samples per second present in source data
	* @param num_channels The number of audio channels in source_data
	* @param icon A value of the "Icon" enumeration type specifying the icon to display.
	* 
	* @return A newly created blank Sound annotation.
	*/
	static Sound CreateWithData(SDF::SDFDoc& doc, const Rect& pos, Filters::Filter source_data, int bits_per_sample, int sample_freq, int num_channels, Icon icon = e_Speaker );

	/** 
	 * Creates a new Sound annotation in the specified document.
	 * 
	 * @param doc A document to which the annotation is added.
	 * @param pos A point specifying the annotation's location in default user space units.
	 * 
	 * @return A newly created blank Sound annotation.
	*/
	static Sound Create(SDF::SDFDoc& doc, const Point& pos, Icon icon = e_Speaker );

	/** 
	 * Returns the sound object of the Sound annotation.
	 * 
	 * @return An SDF object representing a sound stream.
	 * @note The sound stream is to be played when the Sound 
	 * annotation is activated. 
	*/
	SDF::Obj GetSoundStream() const;

	/** 
	 * Sets the sound object of the Sound annotation.
	 * 
	 * @param icon An SDF object representing a sound stream.
	 * @note The sound stream is to be played when the Sound 
	 * annotation is activated. 
	*/
	void SetSoundStream(SDF::Obj icon);
	
	/** 
	 * Returns the Icon of the Sound annotation.
	 * 
	 * @return A value of the "Icon" enum.
	 * Default value: e_Speaker.
	 * @note The Icon defines the appearance associated with the Sound annotation.
	 * The annotation's appearance stream, if present, will take
	 * precedence over this entry.
	*/
	Icon GetIcon() const;

	/** 
	 * Sets the Icon of the Sound annotation.
	 *(Optional)
	 * 
	 * @param type A value of the "Icon" enumeration type specifying the icon to display.
	 * Default value: e_Speaker.
	 * @note The Icon defines the appearance associated with the Sound annotation.
	 * The annotation's appearance stream, if present, will take
	 * precedence over this entry.
	*/
	void SetIcon(Icon type=e_Speaker);

	/** 
	 * Returns the Icon name of the Sound annotation.
	 * 
	 * @return A string denoting the Icon name of the Sound annotation.
	 * @note The following Icon names are equivalent 
	 * to predefined Icons from the enum "Icon":
	 * "Speaker" = e_Speaker
	 * "Mic" = e_Mic
	 * "Unknown" = e_Unknown
	 * The Icon defines the appearance associated with the Sound annotation.
	 * Names other than mentioned above do not have predefined icon appearances. 
	 * The annotation's appearance stream, if present, will take
	 * precedence over this entry.
	*/
	const char* GetIconName() const;
	
	/** 
	 * Sets the Icon name of the Sound annotation.
	 *(Optional)
	 * 
	 * @param type A string denoting the Icon name of the Sound annotation.
	 * @note The following Icon names are equivalent 
	 * to predefined types from the enum "Icon":
	 * "Speaker" = e_Speaker
	 * "Mic" = e_Mic
	 * "Unknown" = e_Unknown
	 * The Icon defines the appearance associated with the Sound annotation.
	 * Names other than mentioned above do not have predefined icon appearances. 
	 * The annotation's appearance stream, if present, will take
	 * precedence over this entry.
	*/
	void SetIcon(const char* type);

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
Sound(TRN_Annot sound);
#endif
// @endcond

}; //class Sound
			}; //namespace Annot
		}; //namespace PDF
}; //namespace pdftron
#include <Impl/Page.inl>

#endif // PDFTRON_H_CPPPDFAnnotsSound
