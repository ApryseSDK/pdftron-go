//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFOCGOCMD
#define PDFTRON_H_CPPPDFOCGOCMD

#include <C/PDF/OCG/TRN_OCMD.h>
#include <Common/BasicTypes.h>

namespace pdftron { 
	namespace PDF {
		namespace OCG {

/**
* The OCMD object represents an Optional Content Membership Dictionary (OCMD) 
* that allows the visibility of optional content to depend on the states in a 
* set of optional-content groups (OCG::Group). The object directly corresponds 
* to the OCMD dictionary (Section 4.10.1 'Optional Content Groups' in PDF 
* Reference).
* <p>
* An OCMD collects a set of OCGs. It sets a visibility policy, so that 
* content in the member groups is visible only when all groups are ON 
* or OFF, or when any of the groups is ON or OFF. This makes it possible 
* to set up complex dependencies among groups. For example, an object can be 
* visible only if some other conditions are met (such as if another layer is 
* visible).
* </p>
*/
class OCMD
{
public: 

	/**
	 * Visibility Policy Type.
	 * A Visibility Policy is used to determine whether an PDF::Element is visible 
	 * in a given OCG::Context, depending on whether all groups in OCGs array are 
	 * "ON" or "OFF", or when any of the groups is "ON" or "OFF". 
	 */  
	enum VisibilityPolicyType {
		e_AllOn,  ///< visible only if all of the entries in OCGs are ON.
		e_AnyOn,  ///< visible if any of the entries in OCGs are ON.
		e_AnyOff, ///< visible if any of the entries in OCGs are OFF.
		e_AllOff  ///< visible only if all of the entries in OCGs are OFF.
	};

	/**
	 * Creates a new optional-content membership dictionary (OCMD) object in the 
	 * given document for the given groups and visibility policy. 
	 *
	 * @param doc The document in which the new OCMD will be created.
	 * @param ocgs An array of optional-content groups (OCGs) to be members of the dictionary.
	 * @param policy The visibility policy that determines the visibility of content with respect 
	 * to the ON-OFF state of OCGs listed in the dictionary.
	 *
	 * @return The newly created OCG::OCMD object.
	 */
	static OCMD Create(PDFDoc& doc, SDF::Obj ocgs, VisibilityPolicyType vis_policy);

	/**
	 * Creates a new optional-content group membership dictionary (OCMD) object from 
	 * an existing SDF/Cos object.
	 */	
	OCMD(SDF::Obj ocmd);

	/**
	 * @return True if this is a valid (non-null) OCMD, false otherwise. 
	 */	
	bool IsValid() const;

	/** 
	 * Returns the optional-content groups listed under 'OCGs' entry in the object 
	 * dictionary. 
	 * 
	 * @return A dictionary (for a single OCG::Group object), an SDF::Obj array 
	 * (for multiple OCG::Group objects) or NULL (for an empty OCMD).
	 */
	SDF::Obj GetOCGs() const;	

	/**
	 * Returns the optional-content membership dictionary's visibility policy, which 
	 * determines the visibility of content with respect to the ON-OFF state of 
	 * OCGs listed in the dictionary. 
	 * 
	 * @return The visibility policy. 
	 */
	VisibilityPolicyType GetVisibilityPolicy() const;

	/**
	 * Sets the optional-content membership dictionary's visibility policy, which 
	 * determines the visibility of content with respect to the ON-OFF state of 
	 * OCGs listed in the dictionary. 
	 * @param vis_policy New visibility policy.
	 */
	void SetVisibilityPolicy(VisibilityPolicyType vis_policy);

	/** 
	 * @return If the PDOCMD has a visibility expression entry, return the 
	 * SDF::Obj array object representing the expression, otherwise returns NULL.
	 */
	SDF::Obj GetVisibilityExpression() const;

	/**
	 * @return true if content tagged with this OCMD is visible in the given 
	 * context, false if it is hidden.
	 * <p>
	 * Based on the optional-content groups listed in the dictionary, the current 
	 * ON-OFF state of those groups within the specified context, and the 
	 * dictionary's visibility policy, test whether the content tagged with 
	 * this dictionary would be visible.
	 * 
	 * @param context The context in which the visibility of content is tested.
	 */
	bool IsCurrentlyVisible(const class Context& context) const;   

	/**
	 * @return Pointer to the underlying SDF/Cos object.
	 */
	SDF::Obj GetSDFObj () const;

	/**
	 * Copy constructor
	 */
	OCMD (const OCMD& g);
	OCMD& operator=(const OCMD& g);

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	OCMD(TRN_OCMD o) : mp_obj(o) {}
	TRN_OCMD mp_obj;
	#endif
	// @endcond
};

		};	// namespace OCG
	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFOCGOCMD
