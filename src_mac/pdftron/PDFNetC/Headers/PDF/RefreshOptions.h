#ifndef PDFTRON_H_CPPPDFRefreshOptions
#define PDFTRON_H_CPPPDFRefreshOptions

#include <PDF/OptionsBase.h>

namespace pdftron{ namespace PDF{ 

class RefreshOptions
{
public:
	RefreshOptions();
	~RefreshOptions();

	
	/**
	* Gets the value DrawBackgroundOnly from the options object
	* If true draw only the background and border, which can be useful when generating the rest of the annotation content elsewhere. Off by default.
	* @return the current value for DrawBackgroundOnly.
	*/
	bool GetDrawBackgroundOnly();

	/**
	* Sets the value for DrawBackgroundOnly in the options object
	* If true draw only the background and border, which can be useful when generating the rest of the annotation content elsewhere. Off by default.
	* @param value the new value for DrawBackgroundOnly
	* @return this object, for call chaining
	*/
	RefreshOptions& SetDrawBackgroundOnly(bool value);

	
	/**
	* Gets the value RefreshExisting from the options object
	* Whether we should refresh annotations with existing appearances. Defaults to false when used in PDFDoc.RefreshAnnotAppearances and true when used in Annot.RefreshAppearance.
	* @return the current value for RefreshExisting.
	*/
	bool GetRefreshExisting();

	/**
	* Sets the value for RefreshExisting in the options object
	* Whether we should refresh annotations with existing appearances. Defaults to false when used in PDFDoc.RefreshAnnotAppearances and true when used in Annot.RefreshAppearance.
	* @param value the new value for RefreshExisting
	* @return this object, for call chaining
	*/
	RefreshOptions& SetRefreshExisting(bool value);

	
	/**
	* Gets the value UseNonStandardRotation from the options object
	* Whether we should use rotation in the annotation even if it is not a multiple of 90. Off by default.
	* @return the current value for UseNonStandardRotation.
	*/
	bool GetUseNonStandardRotation();

	/**
	* Sets the value for UseNonStandardRotation in the options object
	* Whether we should use rotation in the annotation even if it is not a multiple of 90. Off by default.
	* @param value the new value for UseNonStandardRotation.
	* @return this object, for call chaining
	*/
	RefreshOptions& SetUseNonStandardRotation(bool value);

	
	/**
	* Gets the value UseRoundedCorners from the options object
	* Whether we should use the corner radii specified in Annot.BorderStyle. Off by default.
	* @return the current value for UseRoundedCorners.
	*/
	bool GetUseRoundedCorners();

	/**
	* Sets the value for UseRoundedCorners in the options object
	* Whether we should use the corner radii specified in Annot.BorderStyle. Off by default.
	* @param value the new value for UseRoundedCorners.
	* @return this object, for call chaining
	*/
	RefreshOptions& SetUseRoundedCorners(bool value);

	
	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	SDF::Obj& GetInternalObj();

private:
	
	SDF::ObjSet m_obj_set;
	SDF::Obj m_dict;
	#endif
	// @endcond
};

}
}

#include "../Impl/RefreshOptions.inl"
#endif // PDFTRON_H_CPPPDFRefreshOptions
