//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFOCGGroup
#define PDFTRON_H_CPPPDFOCGGroup

#include <PDF/OCG/Config.h>
#include <C/PDF/OCG/TRN_OCG.h>

namespace pdftron {
	namespace PDF {
		class PDFDoc;
		namespace OCG {

/**
 * The OCG::Group object represents an optional-content group. This corresponds
 * to a PDF OCG dictionary representing a collection of graphic objects that can 
 * be made visible or invisible (Section 4.10.1 'Optional Content Groups' in PDF 
 * Reference). Any graphic content of the PDF can be made optional, including page 
 * contents, XObjects, and annotations. The specific content objects in the group 
 * have an OC entry in the PDF as part of the surrounding marked content or in the 
 * XObject dictionary. The group itself is a named object that can be typically 
 * manipulated through a Layers panel in a PDF viewer.
 * <p>
 * In the simplest case, the group's ON-OFF state makes the associated content 
 * visible or hidden. The ON-OFF state of a group can be toggled for a particular 
 * context (OCG::Context), and a set of states is kept in a configuration (OCG::Config). 
 * The visibility can depend on more than one group in an optional-content membership 
 * dictionary (OCG::OCMD), and can also be affected by the context's draw mode
 * (OCGContext::OCDrawMode).
 * </p><p>
 * A group has an Intent entry, broadly describing the intended use. A group's 
 * content is considered to be optional (that is, the group's state is considered in 
 * its visibility) if any intent in its list matches an intent of the context. The 
 * intent list of the context is usually set from the intent list of the document 
 * configuration.
 * </p><p>
 * A Usage dictionary entry provides more specific intended usage information than 
 * an intent entry. Possible key values are: CreatorInfo, Language, Export, Zoom,
 * Print, View, User, PageElement. The usage value can act as a kind of metadata, 
 * describing the sort of things that belong to the group, such as text in French, 
 * fine detail on a map, or a watermark. The usage values can also be used by the 
 * AutoState mechanism to make decisions about what groups should be on and what 
 * groups should be off. The AutoState mechanism considers the usage information 
 * in the OCGs, the AS array of the configuration, and external factors; for example, 
 * the language the application is running in, the current zoom level on the page, 
 * or whether the page is being printed.
 */
class Group
{
public:

	/**
	 * Creates a new optional-content group (OCG) object in the document.
	 * @param doc The document in which the new OCG will be created.
	 * @param name The name of the optional-content group.
	 * @return The newly created OCG::Group object.
	 */
	static Group Create(PDFDoc& doc, const UString& name);

	/**
	 * Creates a new optional-content group (OCG) object from an existing 
	 * SDF/Cos object.
	 */	
	Group(SDF::Obj ocg);

	/**
	 * @return True if this is a valid (non-null) OCG, false otherwise. 
	 */	
	bool IsValid() const;

	/** 
	 * @return the name of this optional-content group (OCG).	
	 */
	UString GetName() const;	

	/** 
	 * Sets the name of this optional-content group (OCG).	
	 * @param name The new name.
	 */
	void SetName(const UString& name);

	/**
	 * @return true if this OCG object is in the ON state in a given context,
	 * false otherwise.
	 * @param context The context for which to get the group's state.
	 */
	bool GetCurrentState(const class Context& context) const;   

	/** 
	 * Sets the current ON-OFF state of the optional-content group (OCG) object in a given context.
	 * @param context The context for which to set the group's state. 
	 * @param state The new state.
	 */
	void SetCurrentState(class Context& context, bool state);

	/** 
	 * @return The initial state (ON or OFF) of the optional-content group 
	 * (OCG) object in a given configuration. 
	 * 
	 * @param config The configuration for which to get the group's initial state.
	 * @note If the configuration has a BaseState of Unchanged, and the OCG is 
	 * not listed explicitly in its ON list or OFF list, then the initial state 
	 * is taken from the OCG's current state in the document's default context.
	 */
	bool GetInitialState(const class Config& config) const;

	/** 
	 * Sets the initial state (ON or OFF) of the optional-content group (OCG) 
	 * object in a given configuration.
	 *
	 * @param config The configuration for which to set the group's initial state.
	 * @param state The new initial state, true if the state is ON, false if it is OFF.
	 */ 
	void SetInitialState(class Config& config, bool state);

	/**
	 * @return OCG intent. 
	 * An intent is a name object (or an array of name objects) broadly describing the 
	 * intended use, which can be either "View" or "Design". A group's content is 
 	 * considered to be optional (that is, the group's state is considered in its 
	 * visibility) if any intent in its list matches an intent of the context. The 
	 * intent list of the context is usually set from the intent list of the document 
	 * configuration.
	 */
	SDF::Obj GetIntent() const;

	/**
	 * Sets the Intent entry in an optional-content group's SDF/Cos dictionary. 
	 * For more information, see GetIntent().
	 * @param intent The new Intent entry value (a name object or an array of name objects).
	 */
	void SetIntent(SDF::Obj intent);

	/**
	 * @return true if this OCG is locked in a given configuration, false otherwise.
	 * The on/off state of a locked OCG cannot be toggled by the user through the user interface.
	 * @param config The OC configuration.
	 */	
	bool IsLocked(const Config& config) const;

	/**
	 * Sets the locked state of an OCG in a given configuration. The on/off state of a 
	 * locked OCG cannot be toggled by the user through the user interface.
	 * 
	 * @param config IN/OUT The optional-content configuration.
	 * @param locked true if the OCG should be locked, false otherwise.
	 */
	void SetLocked(const Config& config, bool locked);

	/**
	 * @return true if this group is associated with a Usage dictionary, false otherwise.
	 */
	bool HasUsage() const;

	/**
	 * @return The usage information associated with the given key in the Usage dictionary 
	 * for the group, or a NULL if the entry is not present. A Usage dictionary entry 
	 * provides more specific intended usage information than an intent entry. 
	 * 
	 * @param key The usage key in the usage dictionary entry. The possible key values are: 
	 * CreatorInfo, Language, Export, Zoom, Print, View, User, PageElement.
	 */
	SDF::Obj GetUsage(const char* key) const;

	/**
	 * @return Pointer to the underlying SDF/Cos object.
	 */
	SDF::Obj GetSDFObj () const;

	/**
	 * Copy constructor
	 */
	Group (const Group& g);
	Group& operator=(const Group& g);

	#ifndef SWIGHIDDEN
	Group(TRN_OCG g) : mp_obj(g) {}
	TRN_OCG mp_obj;
	#endif
};

		};	// namespace OCG
	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFOCGGroup
