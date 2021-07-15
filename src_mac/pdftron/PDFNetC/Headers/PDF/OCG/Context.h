//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFOCGContext
#define PDFTRON_H_CPPPDFOCGContext

#include <SDF/Obj.h>
#include <C/PDF/OCG/TRN_OCGContext.h>

namespace pdftron { 
	namespace PDF {
		namespace OCG {

/**
 * <p>
 * The OCG::Context object represents an optional-content context in a document, within which 
 * document objects such as words or annotations are visible or hidden. The context keeps track 
 * of the ON-OFF states of all of the optional-content groups (OCGs) in a document. Content is 
 * or is not visible with respect to the OCG states stored in a specific context. Unlike other 
 * objects in OCG namespace, the OCG::Context does not correspond to any explicit PDF structure.
 * </p><p>
 * Each PDFView has a default context (PDF::GetOCGContext()) that it uses for on-screen drawing 
 * and that determines the default state for any drawing. The context has flags that control 
 * whether to draw content that is marked as optional, and whether to draw content that is not 
 * marked as optional.
 * </p><p>
 * When enumerating page content, OCG::Context can be passed as a parameter in ElementReader.Begin() 
 * method. When using PDFDraw, PDFRasterizer, or PDFView class to render PDF pages use 
 ( PDFDraw::SetOCGContext() method to select an OC context.
 * </p><p>
 * There can be more than one Context object, representing different combinations of OCG states. 
 * You can change the states of OCGs within any context. You can build contexts with your own 
 * combination of OCG states, and issue drawing or enumeration commands using that context.
 * For example, you can pass an optional-content context to ElementReader.Begin(). You can save 
 * the resulting state information as part of the configuration (e.g. using Config::SetInit methods), 
 * but the context itself has no corresponding PDF representation, and is not saved. 
 * </p>
 */
class Context
{
public: 

	/** 
	 * Copy constructor.
	 * @param context Another context from which to take initial OCG states.
	 */
	Context(const Context& context);
	Context& operator=(const Context& g);

	/** 
	 * Create a context object that represents an optional-content state of the 
	 * document from a given configuration. 
	 *
	 * @param config A configuration from which to take initial OCG states.
	 */
	Context(const class Config& config);

	/** 
	 * Destructor
	 */
	~Context();

	/** 
	 * @return true is this is a valid (non-null) context, false otherwise.
	 */
	bool IsValid() const { return mp_obj!=0; }

	/** 
	 * @return the ON-OFF states (true or false) for the given optional-content 
	 * group (OCG) in this OC context.
	 *
	 * @param group The optional-content group (OCG) that is queried.
	 */
	bool GetState(const class Group& group) const;

	/** 
	 * Sets the ON-OFF states for the given optional-content group (OCG) in this
	 * context.
	 * @param group The optional-content group (OCG) that is queried.
	 * @param state true for 'ON' and false for 'OFF'.
	 */
	void SetState(const class Group& group, bool state);

	/** 
	 * Sets the sates of all OCGs in the context to ON or OFF. 
	 * @param all_on A flag used to specify whether the OCG states should be set 
	 * to ON (if true), or OFF (if false). 
	 */
	void ResetStates(bool all_on);

	/**
	 * Sets the non-OC status for this context. Content that is not marked 
	 * as optional content is drawn (or element.IsOCVisible()) when 'draw_non_OC' 
	 * is true, and not drawn/visible otherwise.
	 *
	 * @param draw_non_OC A flag specifying whether the content that is not 
	 * marked as optional should be treated as visible.
	 */
	void SetNonOCDrawing(bool draw_non_OC);

	/** 
	 * @return the non-OC status for this context. The flag indicates whether the 
	 * content that is not marked as optional should be treated as visible.
	 * For more information, please see SetNonOCDrawing().
	 */
 	bool GetNonOCDrawing() const;

	/** 
	 * OCDrawMode controls drawing or enumerating the page with respect to optional content.
	 * Together with the value of SetNonOCDrawing this mode controls drawing or enumerating 
	 * content on a page with optional content: 
	 * <ul>
	 * <li>Content that is marked as optional content is drawn or not drawn according to the 
	 * OCDrawMode and the visibility state as determined by the Optional Content Groups (OCGs) 
	 * and OCMDs. 
	 * </li>
	 * <li>Content that is not marked as optional content is drawn when GetNonOCDrawing() is 
	 * true, and not drawn when GetNonOCDrawing() is false.
	 * </li>
	 * </ul>
	 */
	enum OCDrawMode
	{
		/**  
		 * Draw or enumerate optional content that is visible, according to the current state of 
		 * Optional Content Groups (OCGs) and Optional Content Membership Dictionaries (OCMDs). 
		 * This is the default mode.
		 */
		e_VisibleOC,

		/** 
		 * Draw or enumerate all optional content, regardless of its visibility state. If the 
		 * context's 'SetNonOCDrawing' is enabled, all contents of document are shown. 
		 */
		e_AllOC,

		/**	
		 * Draw or enumerate no optional content, regardless of its visibility state. If the 
		 * context's 'SetNonOCDrawing' is not enabled, nothing is drawn, resulting in a blank page.
		 */
		e_NoOC
	};

	/** 
	 * Sets the drawing and enumeration type for this context. This type, together 
	 * with the visibility determined by the OCG and OCMD states, controls whether 
	 * content that is marked as optional content is drawn or enumerated.
	 *
	 * @param oc_draw_mode A flag specifying the visibility of optional content.
	 */
	void SetOCDrawMode(OCDrawMode oc_draw_mode);

	/** 
	 * @return the drawing and enumeration type for this context.
	 * For more information, please see SetOCMode() and OCG::Context::OCDrawMode.
	 */
	OCDrawMode GetOCMode() const;

	 /**
	 * Frees the native memory of the object.
	 */
	void Destroy();

	
	//for xamarin use only
	static Context* CreateInternal(ptrdiff_t impl);
	ptrdiff_t GetHandleInternal();

#ifndef SWIGHIDDEN
	Context(TRN_OCGContext ctx);
	TRN_OCGContext mp_obj;
private:
	bool m_owner;
#endif
};

		};	// namespace OCG
	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFOCGContext
