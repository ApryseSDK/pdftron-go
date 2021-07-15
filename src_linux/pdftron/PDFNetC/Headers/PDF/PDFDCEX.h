//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#if defined(_WIN32)

#ifndef PDFTRON_H_CPPPDFPDFDCEX
#define PDFTRON_H_CPPPDFPDFDCEX

#include <PDF/PDFDoc.h>
#include <C/PDF/TRN_PDFDCEX.h>
#include <SDF/Obj.h>
#include <Windows.h>

namespace pdftron{ 
	namespace PDF {

/** 
* PDFDCEX is a utility class used to represent a PDF Device Context (DC).
* 
* Windows developers can use standard GDI or GDI+ API-s to write on PDFDCEX 
* and to generate PDF documents based on their existing drawing functions.
* PDFDCEX can also be used to implement file conversion from any printable 
* file format to PDF. 
*
* PDFDCEX class can be used in many ways to translate from GDI to PDF:
*  - To translate a single GDI drawing into a single page PDF document.
*  - To translate a single GDI drawing into an object which can be reused
*    many times throughout a PDF document (i.e. as a Form XObject).
*  - To translate many GDI drawings into single page or multipage PDF document.
*  ...
*
* Very few code changes are required to perform the translation from GDI to 
* PDF as PDFDCEX provides a GDI Device Context handle which can be passed to 
* all GDI function requiring an HDC.  PDFDCEX does use a "Virtual Printer" 
* approach so the translation should be of both high quality and speed.
*
* For more advanced translations or creations of PDF documents, such as security
* handling, the use of other PDFNet classes will be required.
*
* An example use of PDFDCEX can be found in PDFDCTest.cpp:
*
* @code
* // Start with a PDFDoc to put the picture into, and a PDFDCEX to translate GDI to PDF
* PDFDoc pdfdoc;
* PDFDCEX pdfdcex;
*
* // Begin the translation from GDI to PDF, provide the PDFDoc to append the translated
* // GDI drawing to and get back a GDI Device Context
* HDC hDC = pdfdcex.Begin(pdfdoc);
* ::StartPage(hDC);
*
* ... perform GDI drawing ...
*
* ::EndPage(hDC);
* // Complete the translation
* pdfdcex.EndDoc();
*
* // Save the PDF document
* pdfdoc.Save("PDFDCEX_is_cool.pdf", SDF::SDFDoc::e_remove_unused, NULL);
* @endcode
*/
class PDFDCEX
{
public:

	/**
	* Default constructor. Creates an empty new GDI to PDF translator.
	*/
	PDFDCEX ();

	/**
	*	Destructor
	*/
	~PDFDCEX ();

	/**
	* Begin the process of translating GDI drawing into a PDF, starting with
	* the creation of a GDI Device Context.
	*
	* @param in_pdfdoc the document which the converted GDI pages will be appended to.
	*
	* @param page_dimension Width and Height, expressed in inches, defining
	* the boundaries of the physical medium on which the page is intended to be
	* displayed or printed. If page_dimension is
	* not specified the default dimensions of the page are 8.5 x 11 inches.
	*
	* <p>The following is a listing of some standard U.S. page sizes: in inches</p>
	*  <ul>
	*    <li>Letter		= Rect(8.5, 11)
	*    <li>Legal		= Rect(8.5, 14)
	*    <li>Ledger		= Rect(17, 11)
	*    <li>Tabloid	= Rect(11, 17)
	*    <li>Executive	= Rect(7.25, 10.5)
	* </ul>
	*
	* <p>The following is a listing of ISO standard page sizes: in 1/72 inch scale</p>
	*  <ul>
	*    <li> 4A0 = Rect(4768, 6741)
	*    <li> 2A0 = Rect(3370, 4768)
	*    <li> A0 =  Rect(2384, 3370)
	*    <li> A1 =  Rect(1684, 2384)
	*    <li> A2 =  Rect(1191, 1684)
	*    <li> A3 =  Rect(842,  1191)
	*    <li> A4 =  Rect(595,  842)
	*    <li> A5 =  Rect(420,  595)
	*    <li> A6 =  Rect(298,  420)
	*    <li> A7 =  Rect(210,  298)
	*    <li> A8 =  Rect(147,  210)
	*    <li> A9 =  Rect(105,  147)
	*    <li> A10 = Rect(74,   105)
	*    <li> B0 =  Rect(2835, 4008)
	*    <li> B1 =  Rect(2004, 2835)
	*    <li> B2 =  Rect(1417, 2004)
	*    <li> B3 =  Rect(1001, 1417)
	*    <LI> B4 =  Rect(709,  1001)
	*    <LI> B5 =  Rect(499,  709)
	*    <LI> B6 =  Rect(354,  499)
	*    <LI> B7 =  Rect(249,  354)
	*    <LI> B8 =  Rect(176,  249)
	*    <LI> B9 =  Rect(125,  176)
	*    <li> B10 = Rect(88,   125)
	*    <li> C0 =  Rect(2599, 3677)
	*    <li> C1 =  Rect(1837, 2599)
	*    <li> C2 =  Rect(1298, 1837)
	*    <li> C3 =  Rect(918,  1298)
	*    <li> C4 =  Rect(649,  918)
	*    <li> C5 =  Rect(459,  649)
	*    <li> C6 =  Rect(323,  459)
	*    <li> C7 =  Rect(230,  323)
	*    <li> C8 =  Rect(162,  230)
	*    <li> C9 =  Rect(113,  162)
	*    <li>C10 =  Rect(79,   113)
	* </ul>
	* 
	* @return a GDI Handle, owned by this object, to a Display Context.
	* @note The GDI handle returned by PDFDCEX is owned by the instance, clients
	* should not destory it.
	*/
	HDC Begin(PDFDoc & in_pdfdoc, const Point& page_dimension = Point(8.5, 11));

	/**
	* Closes the GDI Device Context, translating the GDI instruction to PDF, and adds
	* the PDF objects to the page in the location specified by PDFDCEX::Begin( page, box, ...).
	*
	* @exception An exception is thrown if there are any fatal errors in the 
	* the translation process.
	*/
	void End();

	UInt32 GetDPI();

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC
private:
	TRN_PDFDCEX m_pdfDcEx;
	PDFDCEX(const PDFDCEX&);
	PDFDCEX& operator= (const PDFDCEX&);
// @endcond
};

#include <Impl/PDFDCEX.inl>

	}; // namespace PDF
}; // namespace pdftron

#endif // PDFTRON_H_CPPPDFPDFDCEX

#endif // defined(_WIN32)
