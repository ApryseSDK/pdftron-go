//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.	 
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFElementWriter
#define PDFTRON_H_CPPPDFElementWriter

#include <PDF/Page.h>
#include <PDF/Element.h>
#include <Common/Matrix2D.h>
#include <C/PDF/TRN_ElementWriter.h>
#include <PDF/ElementReader.h>

namespace pdftron { 
	namespace PDF {


/**
 * ElementWriter can be used to assemble and write new content to a page, Form XObject, 
 * Type3 Glyph stream, pattern stream, or any other content stream. 
 */
class ElementWriter
{
public:

	 ElementWriter();
	 ~ElementWriter();


	/**
	 *
	 * Enumeration describing the placement of the element written to a page.
	 */
	enum WriteMode {
		e_underlay,    ///> element is put in the background layer of the page
		e_overlay,     ///> element appears on top of the existing graphics
		e_replacement  ///> element will replace current page contents
	};

	/** 
	 * Begin writing to the given page. 
	 * 
	 * By default, new content will be appended to the page, as foreground graphics. 
	 * It is possible to add new page content as background graphics by setting the 
	 * second parameter in begin method to 'true' (e.g. writer.Begin(page, true)).
	 *
	 * @param page The page to write content. 
	 *
	 * @param placement An optional flag indicating whether the new content should 
	 * be added as a foreground or background layer to the existing page. By default, the new
	 * content will appear on top of the existing graphics. 
	 *
	 * @param page_coord_sys An optional flag used to select the target coordinate system
	 * if true (default), the coordinates are relative to the lower-left corner of the page,
	 * otherwise the coordinates are defined in PDF user coordinate system (which may, 
	 * or may not coincide with the page coordinates).
	 * 
	 * @param compress An optional flag indicating whether the page content stream 
	 * should be compressed. This may be useful for debugging content streams. Also 
	 * some applications need to do a clear text search on strings in the PDF files.
	 * By default, all content streams are compressed.
	 *
	 * @param resources the resource dictionary in which to store resources for the final page. 
	 * By default, a new resource dictionary will be created.    
	 */
	void Begin( Page& page, WriteMode placement = e_overlay, bool page_coord_sys = true, bool compress = true, SDF::Obj resources = 0);

	/** 
	 * Begin writing an Element sequence to a new stream. Use this function to write 
	 * Elements to a content stream other than the page. For example, you can create
	 * Form XObjects (See Section '4.9 Form XObjects' in PDF Reference for more details) 
	 * pattern streams, Type3 font glyph streams, etc.
	 * 
	 * @param doc - A low-level SDF/Cos document that will contain the new stream. You can 
	 * access low-level document using PDFDoc::GetSDFDoc() or Obj::GetDoc() methods.
	 *
	 * @param compress An optional flag indicating whether the page content stream 
	 * should be compressed. This may be useful for debugging content streams. Also 
	 * some applications need to do a clear text search on strings in the PDF files.
	 * By default, all content streams are compressed.
	 * 
	 * @note the newly created content stream object is returned when writing operations
	 * are completed (i.e. after the call to ElementWriter::End()).
	 */
	 void Begin(SDF::SDFDoc& doc, bool compress = true);


	/** 
	 * Begin writing an Element sequence to a stream. Use this function to write 
	 * Elements to a content stream which will replace an existing content stream in an
	 * object passed as a parameter.
	 * 
	 * @param stream_obj_to_update - A low-level SDF stream object that will contain the new stream.
	 * Old stream inside that object will be discarded.
	 *
	 * @param compress An optional flag indicating whether the content stream 
	 * should be compressed. This may be useful for debugging content streams. Also 
	 * some applications need to do a clear text search on strings in the PDF files.
	 * By default, all content streams are compressed.
	 * 
	 * @param resources the resource dictionary in which to store resources for the final page.
	 * By default, a new resource dictionary will be created.
	 *
	 * @note The content stream object is returned when writing operations
	 * are completed (i.e. after the call to ElementWriter::End()).
	 */
	void Begin(SDF::Obj stream_obj_to_update, bool compress = true, SDF::Obj resources = 0);

	/** 
	 * Finish writing to a page
	 * 
	 * @return A low-level stream object that was used to store Elements.
	 */
	 SDF::Obj End();

	/**
	 * Writes the Element to the content stream.
	 * @param element The element to write to the content stream.
	 */
	 void WriteElement(Element element);

	/**
	 * A utility function that surrounds the given Element with a graphics state 
	 * Save/Restore Element (i.e. in PDF content stream represented as 'q element Q').
	 *
	 * The function is equivalent to calling WriteElement three times: 
	 *	 WriteElement(eSave); 
	 *	 WriteElement(element); 
	 *	 WriteElement(eRestore);
	 * 
	 * where eSave is 'e_group_begin' and eRestore is 'e_group_end' Element
	 * 
	 * The function is useful when XObjects such as Images and Forms are drawn on 
	 * the page.
	 * @param element Element object to enact function on.
	 */
	 void WritePlacedElement(Element element);

	/** 
	 * The Flush method flushes all pending Element writing operations.
	 * This method is typically only required to be called when intermixing 
	 * direct content writing (i.e. WriteBuffer/WriteString) with Element writing.
	 */ 
	 void Flush(); 

	/**
	 * Writes an arbitrary buffer to the content stream. 
	 * This function can be used to insert comments, inline-image data, and 
	 * chunks of arbitrary content to the output stream.
	 */
	 void WriteBuffer(std::vector<unsigned char> data);

#ifndef SWIG
	 void WriteBuffer(const char* data, int data_sz);
#endif

	/**
	 * Writes an arbitrary string to the content stream. 
	 * Serves the same purpose as WriteBuffer().
	 * @param str String to write to the content stream.
	 */
	 void WriteString(const char* str);

 	/**
	 * Write only the graphics state changes applied to this element and skip writing the element itself.
	 * This is especially useful when rewriting page content, but with the intention to skip certain elements.
	 * @param element The element for which to write graphics state changes.
	 */
	 void WriteGStateChanges(Element element);

	/**
	 * This method is used to initialize ElementWriter state with the state of a given ElementReader.
	 * This can be used to avoid incorrectly writing inherited GState attributes.
	 * @param reader ElementReader.
	 */
	 void SetDefaultGState(ElementReader& reader);
	
	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_ElementWriter mp_writer;
	 ElementWriter(TRN_ElementWriter impl);
#endif
private:
	// ElementWriter should not be copied
	ElementWriter(const ElementWriter& other);
	ElementWriter& operator= (const ElementWriter&);
// @endcond



};


#include <Impl/ElementWriter.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFElementWriter
