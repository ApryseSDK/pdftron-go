//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFElementReader
#define PDFTRON_H_CPPPDFElementReader

#include <PDF/Page.h>
#include <PDF/Element.h>
#include <PDF/OCG/Context.h>
#include <Common/Iterator.h>
#include <C/PDF/TRN_ElementReader.h>


namespace pdftron { 
	namespace PDF {

		
/**
 * GSChangesIterator is an iterator type that can be used to traverse a list 
 * of changes in the graphics state between subsequent graphical elements on the 
 * page. For a sample use case, please see ElementReaderAdv sample project.
 */ 
typedef Common::Iterator<int> GSChangesIterator; 


typedef TRN_CharData CharData;
	
/**
 * ElementReader can be used to parse and process content streams. ElementReader provides a 
 * convenient interface used to traverse the Element display list of a page. The display list 
 * representing graphical elements (such as text-runs, paths, images, shadings, forms, etc) is 
 * accessed using the intrinsic iterator. ElementReader automatically concatenates page contents
 * spanning multiple streams and provides a mechanism to parse contents of sub-display lists 
 * (e.g. forms XObjects and Type3 fonts).
 *
 * A sample use case for ElementReader is given below:
 * @code
 * ...
 * ElementReader reader;
 * reader.Begin(page);
 * for (Element element=reader.Next(); element; element = reader.Next()) // Read page contents
 * {
 *   switch (element.GetType())	{
 *     case Element::e_path: { // Process path data...
 *         const double* data = element.GetPathPoints();
 *         int sz = element.GetPointCount();
 *     }
 *     break; 
 *     case Element::e_text: 
 *         // ...
 *     break;
 *   }
 * }
 * reader.End();
 * @endcode
 * 
 *  For a full sample, please refer to ElementReader and ElementReaderAdvTest sample projects.
 */
class ElementReader
{
public:

	ElementReader();
	~ElementReader();

	/** 
	 * Begin processing a page.
	 * 
	 * @param page A page to start processing.
	 *
	 * @param ocg_context An optional parameter used to specify the Optional Content (OC) 
	 * Context that should be used when processing the page. When the OCG::Context is specified, 
	 * Element::IsOCVisible() will return 'true' or 'false' depending on the visibility of the 
	 * current Optional Content Group (OCG) and the states of flags in the given context.
	 * 
	 * @note When page processing is completed, make sure to call ElementReader.End().
	 */
	void Begin(const Page& page, OCG::Context* ocg_context = 0);	

	/** 
	 * Begin processing given content stream. The content stream may be 
	 * a Form XObject, Type3 glyph stream, pattern stream or any other content stream.
	 * 
	 * @param content_stream - A stream object representing the content stream (usually 
	 * a Form XObject).
	 * 
	 * @param resource_dict - An optional '/Resource' dictionary parameter. 
	 * If content stream refers to named resources that are not present in
	 * the local Resource dictionary, the names are looked up in the supplied 
	 * resource dictionary.    
	 *
	 * @param ocg_context An optional parameter used to specify the Optional Content (OC) 
	 * Context that should be used when processing the page. When the OCG::Context is specified, 
	 * Element::IsOCVisible() will return 'true' or 'false' depending on the visibility of the 
	 * current Optional Content Group (OCG) and the states of flags in the given context.
	 * 
	 * @note When page processing is completed, make sure to call ElementReader.End().
	 */
	void Begin(SDF::Obj content_stream, SDF::Obj resource_dict = 0, OCG::Context* ocg_context = 0);

	/** 
	 * @return a page Element or a 'NULL' element if the end of current-display list was 
	 * reached. You may use GetType() to determine the type of the returned Element. 
	 * 
	 * @note Every call to ElementReader::Next() destroys the current Element. 
	 * Therefore, an Element becomes invalid after subsequent 
	 * ElementReader::Next() operation.
	 */
	Element Next();

	/** 
	 * @return the current Element or a 'NULL' Element. The current element is the one 
	 * returned in the last call to Next().
	 * 
	 * @note Every call to ElementReader::Next() destroys the current Element. Therefore, an 
	 * Element becomes invalid after subsequent ElementReader::Next() operation.
	 */
	Element Current();

	/** 
	 * When the current element is a form XObject you have the option to skip form 
	 * processing (by not calling FormBegin()) or to open the form stream and 
	 * continue Element traversal into the form. 
	 * 
	 * To open a form XObject display list use FormBegin() method. The Next() returned 
	 * Element will be the first Element in the form XObject display list. Subsequent calls to Next() 
	 * will traverse form's display list until NULL is returned. At any point you can 
	 * close the form sub-list using ElementReader::End() method. After the form display 
	 * list is closed (using End()) the processing will return to the parent display list 
	 * at the point where it left off before entering the form XObject.
	 */
	void FormBegin();

	/** 
	 * A method used to spawn the sub-display list representing the tiling pattern
	 * of the current element in the ElementReader. You can call this method at any 
	 * point as long as the current element is valid.
	 * 
	 * @param fill_pattern If true, the filling pattern of the current element will
	 * be spawned; otherwise, the stroking pattern of the current element will be
	 * spawned. Note that the graphics state will be inherited from the parent content
	 * stream (the content stream in which the pattern is defined as a resource) automatically.
	 * 
	 * @param reset_ctm_tfm An optional parameter used to indicate whether the pattern's
	 * display list should set its initial CTM and transformation matrices to identity matrix.
	 * In general, we should leave it to be false.
	 *	 
	 * To open a tiling pattern sub-display list use PatternBegin(pattern) method. 
	 * The Next() returned Element will be the first Element in the pattern display list. 
	 * Subsequent calls to Next() will traverse pattern's display list until NULL is 
	 * encountered. At any point you can close the pattern sub-list using 
	 * ElementReader::End() method. After the pattern display list is closed, 
	 * the processing will return to the parent display list at the point where 
	 * pattern display list was spawned.
	 */
	void PatternBegin(bool fill_pattern, bool reset_ctm_tfm = false);

	/**
	 * A method used to spawn a sub-display list representing a Type3 Font glyph. You can
	 * call this method at any point as long as the current element in the ElementReader
	 * is a text element whose font type is type 3.
	 * 
	 * @param char_data The information about the glyph to process. You can get this information
	 * by dereferencing a CharIterator.
	 * 
	 * @param resource_dict - An optional '/Resource' dictionary parameter. 
	 * If any glyph descriptions refer to named resources but Font Resource dictionary
	 * is absent, the names are looked up in the supplied resource dictionary.    
	 *
	 * To open a Type3 font sub-display list use Type3FontBegin() method. The Next() 
	 * returned Element will be the first Element in the glyph's display list. 
	 * Subsequent calls to Next() will traverse glyph's display list until NULL is 
	 * returned. At any point you can close the glyph sub-list using ElementReader::End() 
	 * method. After the glyph display list is closed, the processing will return to the 
	 * parent display list at the point where glyph display list was spawned.
	 */
	void Type3FontBegin(CharData& char_data, SDF::Obj resource_dict = 0);

	/**
	 * Close the current display list. 
	 * 
	 * If the current display list is a sub-list created using FormBegin(), PatternBegin(), 
	 * or Type3FontBegin() methods, the function will end the sub-list and will return 
	 * processing to the parent display list at the point where it left off before 
	 * entering the sub-list.
	 * 
	 * @return true if the closed display list is a sub-list or false if it is a root 
	 * display list.
	 */
	bool End();

	/**
	 * @return an iterator to the beginning of the list containing identifiers of modified 
	 * graphics state attributes since the last call to ClearChangeList(). The list can 
	 * be consulted to determine which graphics states were modified between two  
	 * Elements. Attributes are ordered in the same way as they are set in the content 
	 * stream. Duplicate attributes are eliminated.
	 */ 
	GSChangesIterator GetChangesIterator();

	/**
	 * @return true if given GState attribute was changed since the last call to 
	 * @param attrib the GState attribute to test if it has been changed
	 * ClearChangeList().
	 */
	bool IsChanged(GState::GStateAttribute attrib); 

	/**
	 * Clear the list containing identifiers of modified graphics state attributes.
	 * The list of modified attributes is then accumulated during a subsequent call(s)
	 * to ElementReader.Next().
	 */
	void ClearChangeList();

	/** 
	 * @param res resource dictionary for finding images, fonts, etc.
	 */
	void AppendResource(SDF::Obj res);

	/**
	 * @param name string of the name of the SDF/Cos object to get
	 * @return SDF/Cos object matching the specified name in the current resource 
	 * dictionary. For 'Page' the name is looked up in the page's /Resources/<Class>
	 * dictionary. For Form XObjects, Patterns, and Type3 fonts that have a content 
	 * stream within page content stream the specified resource is first looked-up in the 
	 * resource dictionary of the inner stream. If the resource is not found, the name is 
	 * looked up in the outer content stream's resource dictionary. The function returns 
	 * NULL if the resource was not found.
	 */
	SDF::Obj GetFont (const char* name);

	/**
	 * @param name string of the name of the SDF/Cos object to get
	 * @note see ElementReader::GetFont
	 */
	SDF::Obj GetXObject (const char* name);		

	/**
	 * @param name string of the name of the SDF/Cos object to get
	 * @note see ElementReader::GetFont
	 */
	SDF::Obj GetShading(const char* name);

	/**
	 * @param name string of the name of the SDF/Cos object to get
	 * @note see ElementReader::GetFont
	 */
	SDF::Obj GetColorSpace (const char* name);

	/**
	 * @param name string of the name of the SDF/Cos object to get
	 * @note see ElementReader::GetFont
	 */
	SDF::Obj GetPattern (const char* name);

	/**
	 * @param name string of the name of the SDF/Cos object to get
	 * @note see ElementReader::GetFont
	 */
	SDF::Obj GetExtGState (const char* name);

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	ElementReader(TRN_ElementReader impl);
	TRN_ElementReader mp_reader;
#endif
private:
	ElementReader(const ElementReader&);
	ElementReader& operator= (const ElementReader&);
// @endcond
};



#include <Impl/ElementReader.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFElementReader
