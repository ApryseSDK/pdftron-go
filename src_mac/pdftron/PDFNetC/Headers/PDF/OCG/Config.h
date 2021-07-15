//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFOCGConfig
#define PDFTRON_H_CPPPDFOCGConfig

#include <SDF/Obj.h>
//#include <PDF/PDFDoc.h>
#include <C/PDF/OCG/TRN_OCGConfig.h>

namespace pdftron {
	namespace PDF {

		class PDFDoc;

		namespace OCG {

/**
 * The OCG::Config object represents an optional-content (OC) configuration 
 * structure (see section 4.10.3 in PDF Reference), used to persist a set 
 * of visibility states and other optional-content information in a PDF file 
 * A document has a default configuration, saved in the D entry in the 
 * 'OCProperties' dictionary (that can be obtained using pdfdoc.GetOCConfig()), 
 * and can have a list of other configurations, saved as an array in the 
 * 'Configs' entry in the OCProperties dictionary.
 * <p>
 * Configurations are typically used to initialize the OCG ON-OFF states for 
 * an optional-content context (OCG::Context). The OCG order in the configuration 
 * is the order in which the groups appear in the Layers panel of a PDF viewer. 
 * The configuration can also define a set of mutually exclusive OCGs, called a 
 * radio button group.
 * </p>
 */
class Config
{
public: 

	/**
	 * Creates a new optional-content configuration object in the document.
	 * @param doc The document in which the new OCG::Config will be created.
	 * @param default_config If true, the configuration will be set as the 
	 * default OCG configuration (i.e. listed as a D entry under 'OCProperties' 
	 * dictionary).
	 * @return The newly created configuration object.
	 */
	static Config Create(PDFDoc& doc, bool default_config);

	/**
	 * Creates a new optional-content configuration from an existing SDF/Cos object.
	 */	
	Config(SDF::Obj ocg_config);

	/** 
	 * @return true is this is a valid (non-null) configuration, false otherwise.
	 */
	bool IsValid() const { return mp_obj !=0; }

	/**
	 * @return the Obj array that specifies the order of optional content (OC) groups 
	 * in this configuration or NULL if the configuration does not contain any OCGs. 
	 * The order of OCGs in the array is used to represent the order in which the 
	 * group names are displayed in the Layers panel of a PDF viewer application.
	 * For more information, please refer to Section 4.10.3 in the PDF Reference.
	 */
	SDF::Obj GetOrder() const;

	/**
	 * Sets the user interface display order of optional-content groups (OCGs) in 
	 * this configuration. This is the order in which the group names are displayed 
	 * in the Layers panel of a PDF viewer.
	 * 
	 * @param ocgs_array The SDF/Cos object containing the OCG order array. 
	 * For more information, please refer to section 4.10.3 in the PDF Reference.
	 */
	void SetOrder(SDF::Obj ocgs_array);

	/** 
	 * @return the name of an optional-content configuration (suitable for 
	 * presentation in a user interface). 
	 */
	UString GetName() const;
	
	/** 
	 * Sets the name of an optional-content configuration (suitable for presentation
	 * in a user interface). The method stores the specified string as the Name entry 
	 * in the configuration's SDF/Cos dictionary.
	 * @param name The new name string.
	 */
	void SetName(const UString& name);

	/** 
	 * @return the creator property of an optional-content configuration. The string
	 * is used to represent the name of the application or feature that created this 
	 * configuration. 
	 */
	UString GetCreator() const;

	/** 
	 * Sets the creator property of an optional-content configuration. Stores the 
	 * specified string as the Creator entry in the configuration's SDF/Cos dictionary.
	 * @param name The new creator string.
	 */
	void SetCreator(const UString& name);

	/** 
	* @return the base initialization state. This state is used to initialize the states 
	* of all the OCGs in a document when this configuration is applied. The value of this entry 
	* must be one of the following names:
	*  <li>ON: The states of all groups are turned ON. </li>
	*  <li>OFF: The states of all groups are turned OFF.</li>
	*  <li>Unchanged: The states of all groups are left unchanged.</li>
	* 
	* <p> After base initialization, the contents of the ON and OFF arrays are processed, overriding 
	* the state of the groups included in the arrays.</p>
	* @note: If BaseState is present in the document's default configuration dictionary, its value must 
	* be "ON".
	* @default ON.
	 */
	const char* GetInitBaseState() const;

	/** 
	 * @return the "ON" initialization array from the configuration dictionary or 
	 * NULL if the array is not present. The returned object is an array of optional 
	 * content groups whose state should be set to ON when this configuration is applied.
	 * Note: If the BaseState entry is ON, this entry is redundant.
	 */
	SDF::Obj GetInitOnStates() const;

	/** 
	 * @return the "OFF" initialization array from the configuration dictionary or 
	 * NULL if the array is not present. The returned object is an array of optional 
	 * content groups whose state should be set to OFF when this configuration is applied.
	 * Note: If the BaseState entry is OFF, this entry is redundant.
	 */
	SDF::Obj GetInitOffStates() const;

	/** 
	 * Sets the base initialization state. For more info, please see GetInitBaseState().
	 * @param state new base state ("ON", "OFF", or "Unchanged").
	 */
	void SetInitBaseState(const char* state = "ON");

	/** 
	 * Sets the 'ON' initialization array in the configuration dictionary. 
	 * @param on_array the initialization array to be used 
	 * @note For more info, please see SetInitOnStates() and section 4.10.3 in PDF Reference.
	 */
	void SetInitOnStates(SDF::Obj on_array);

	/** 
	 * Sets the 'OFF' initialization array in the configuration dictionary. 
	 * @param off_array the initialization array to be used.
	 * @note For more info, please see SetInitOffStates() and section 4.10.3 in PDF Reference.
	 */
	void SetInitOffStates(SDF::Obj off_array);

	/**
	* @return OCG configuration intent. An intent is a name object (or an array of name 
	* objects) broadly describing the intended use, which can be either "View" or "Design". 
	* A group's content is considered to be optional (that is, the group's state is considered 
	* in its visibility) if any intent in its list matches an intent of the context. The 
	* intent list of the context is usually set from the intent list of the document 
	* configuration. If the configuration has no Intent entry, the default value of 
	* "View" is used. 
	*/
	SDF::Obj GetIntent() const;

	/**
	 * Sets the Intent entry in an optional-content configuration's SDF/Cos dictionary.
 	 * For more information, see GetIntent().
	 * @param intent The new Intent entry value (a name object or an array of name objects).
	 */
	void SetIntent(SDF::Obj intent);

	/** 
	 * @return the list of locked OCGs or NULL if there are no locked OCGs. 
	 * The on/off state of a locked OCG cannot be toggled by the user through the 
	 * user interface.
	 */
	SDF::Obj GetLockedOCGs() const;

	/** 
	 * Sets the array of locked OCGs. The on/off state of a locked OCG cannot be 
	 * toggled by the user through the user interface.
	 * 
	 * @param locked_ocg_array An SDF/Cos array of OCG objects to be locked in this 
	 * configuration, or an empty array if the configuration should not contain 
	 * locked OCGs. The default is the empty array.
	 */
	void SetLockedOCGs(SDF::Obj locked_ocg_array);

	/**
	 * @return Pointer to the underlying SDF/Cos object.
	 */
	SDF::Obj GetSDFObj () const;

	/**
	 * Copy constructor
	 */
	Config (const Config& g);
	Config& operator=(const Config& g);

	#ifndef SWIGHIDDEN
	Config(TRN_OCGConfig c) : mp_obj(c) {}
	TRN_OCGConfig mp_obj;
	#endif
};

		};	// namespace OCG
	};	// namespace PDF
};	// namespace pdftron

#include <Impl/PDFDoc.inl>

#endif // PDFTRON_H_CPPPDFOCGConfig
