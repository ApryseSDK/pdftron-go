//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPrint
#define PDFTRON_H_CPPPDFPrint

#include <PDF/PDFDoc.h>
#include <C/PDF/TRN_Print.h>
#include <SDF/Obj.h>
#include <SDF/ObjSet.h>
#include <PDF/PageSet.h>

namespace pdftron{ 
	namespace PDF {

/** 
 * Print is a utility class for printing PDF documents to printers.
 * 
 */
class PrinterMode; // forward declaration

class Print {
public:
	

	/** 
	 * (Windows Only)
	 * Print the PDFDoc to a printer. Depending on the OS and installed 
	 * libraries, the PDFDoc will be sent using the GDI or the XPS print path.
	 * This function will block until the print job is done at the OS level.
	 * 
	 * @note If the printer is grayscale, only grayscale data will be sent.
	 *
	 * @param in_pdfdoc the PDFDoc to be printed
	 * @param in_printerName the name of the printer to print to
	 * @param in_jobName the name of the job for print queue monitoring, 
	 * can be empty.
	 * @param in_outputFileName if not empty, the name of the output file to 
	 * save the printout into.  This could be a PostScript, PCL, XPS or other
	 * file.
	 * @param in_pagesToPrint a PageSet specifying which pages to print.
	 * @param in_printMode options for the printer, see the PrinterMode class below.
	 * @param in_cancel set this to true to cancel the print job.
	 * @param in_context (Optional) Optional Content Group setting, for example from PDFViewCtrl::GetOCGContext.
	 * @return void.  Throws a trn::Common::Exception on failure.
	 */
	static void StartPrintJob( 
		PDFDoc & in_pdfdoc,
		const UString & in_printerName, 
		const UString & in_jobName,
		const UString & in_outputFileName,
		PageSet * in_pagesToPrint = NULL,
		PrinterMode * in_printerMode = NULL,
		volatile bool * in_cancel = NULL,
		OCG::Context * in_context = NULL);

	/** 
	 * (Windows Only)
	 * Print the PDFDoc to a printer. Depending on the OS and installed 
	 * libraries, the PDFDoc will be sent using the GDI or the XPS print path.
	 * This function will block until the print job is done at the OS level.
	 * 
	 * @note Same functionality as other StartPrintJob but with char * types for 
	 * printer name, job name, output file name
	 * @note If the printer is grayscale, only grayscale data will be sent.
	 * @param in_pdfdoc the PDFDoc to be printed
	 * @param in_printerName the name of the printer to print to
	 * @param in_jobName the name of the job for print queue monitoring, 
	 * can be empty.
	 * @param in_outputFileName if not empty, the name of the output file to 
	 * save the printout into.  This could be a PostScript, PCL, XPS or other
	 * file.
  	 * @param in_pagesToPrint a PageSet specifying which pages to print.
	 * @param in_printMode options for the printer, see the PrinterMode class below.
	 * @param in_cancel set this to true to cancel the print job.
	 * @param in_context (Optional) Optional Content Group setting, for example from PDFViewCtrl::GetOCGContext.
	 *
	 * @return void.  Throws a trn::Common::Exception on failure.
	 */
	static void StartPrintJob( 
					   PDFDoc & in_pdfdoc,
					   const char * in_printerName, 
					   const char * in_jobName,
					   const char * in_outputFileName,
				   	   PageSet * in_pagesToPrint = NULL,
					   PrinterMode * in_printerMode = NULL,
					   volatile bool * in_cancel = NULL,
					   OCG::Context * in_context = NULL);


};



/** 
 * PrinterMode is a utility class used to represent options for printing.
 * 
 */
class PrinterMode
{
public:
	/**
	 * Paper sizes
	 */
	enum PaperSize {
		e_custom = 0,
		e_letter,
		e_letter_small,
		e_tabloid,
		e_ledger,
		e_legal,
		e_statement,
		e_executive,
		e_a3,
		e_a4,
		e_a4_small,
		e_a5,
		e_b4_jis,
		e_b5_jis,
		e_folio,
		e_quarto,
		e_10x14,
		e_11x17,
		e_note,
		e_envelope_9,
		e_envelope_10,
		e_envelope_11,
		e_envelope_12,
		e_envelope_14,
		e_c_size_sheet,
		e_d_size_sheet,
		e_e_size_sheet,		
		e_envelope_dl,
		e_envelope_c5,
		e_envelope_c3,
		e_envelope_c4,
		e_envelope_c6,
		e_envelope_c65,
		e_envelope_b4,
		e_envelope_b5,
		e_envelope_b6,
		e_envelope_italy,
		e_envelope_monarch,
		e_6_3_quarters_envelope,
		e_us_std_fanfold,
		e_german_std_fanfold,
		e_german_legal_fanfold,
		e_b4_iso,
		e_japanese_postcard,
		e_9x11,
		e_10x11,
		e_15x11,
		e_envelope_invite,
		e_reserved_48,
		e_reserved_49,
		e_letter_extra,
		e_legal_extra,
		e_tabloid_extra,
		e_a4_extra,
		e_letter_transverse,
		e_a4_transverse,
		e_letter_extra_transverse,
		e_supera_supera_a4,
		e_Superb_Superb_a3,
		e_letter_plus,
		e_a4_plus,
		e_a5_transverse,
		e_b5_jis_transverse,
		e_a3_extra,
		e_a5_extra,
		e_b5_iso_extra,
		e_a2,
		e_a3_transverse,
		e_a3_extra_transverse,
		e_japanese_double_postcard,
		e_a6,
		e_japanese_envelope_kaku_2,
		e_japanese_envelope_kaku_3,
		e_japanese_envelope_chou_3,
		e_japanese_envelope_chou_4,
		e_letter_rotated,
		e_a3_rotated,
		e_a4_rotated,
		e_a5_rotated,
		e_b4_jis_rotated,
		e_b5_jis_rotated,
		e_japanese_postcard_rotated,
		e_double_japanese_postcard_rotated,
		e_a6_rotated,
		e_japanese_envelope_kaku_2_rotated,
		e_japanese_envelope_kaku_3_rotated,
		e_japanese_envelope_chou_3_rotated,
		e_japanese_envelope_chou_4_rotated,
		e_b6_jis,
		e_b6_jis_rotated,
		e_12x11,
		e_japanese_envelope_you_4,
		e_japanese_envelope_you_4_rotated,
		e_prc_16k,
		e_prc_32k,
		e_prc_32k_big,
		e_prc_envelop_1,
		e_prc_envelop_2,
		e_prc_envelop_3,
		e_prc_envelop_4,
		e_prc_envelop_5,
		e_prc_envelop_6,
		e_prc_envelop_7,
		e_prc_envelop_8,
		e_prc_envelop_9,
		e_prc_envelop_10,
		e_prc_16k_rotated,
		e_prc_32k_rotated,
		e_prc_32k_big__rotated,
		e_prc_envelop_1_rotated,
		e_prc_envelop_2_rotated,
		e_prc_envelop_3_rotated,
		e_prc_envelop_4_rotated,
		e_prc_envelop_5_rotated,
		e_prc_envelop_6_rotated,
		e_prc_envelop_7_rotated,
		e_prc_envelop_8_rotated,
		e_prc_envelop_9_rotated,
		e_prc_envelop_10_rotated,
	};

	/// Enumerated values for specifying how the printed pages are flipped when duplexing
	enum DuplexMode {
		e_Duplex_Auto = 0,					///< use the current printer setting
		e_Duplex_None = 1,					///< single-sided printing
		e_Duplex_LongSide = 2,				///< flip the paper along the long side
		e_Duplex_ShortSide = 3				///< flip the paper along the short side
	};

	/// Enumerated values for specifying the quality of the printing
	enum OutputQuality {
		e_OutputQuality_Draft = -1,			///< printer draft mode
		e_OutputQuality_Low = -2,			///< printer low quality mode
		e_OutputQuality_Medium = -3,		///< printer medium quality mode
		e_OutputQuality_High = -4			///< printer high quality mode
	};

	/// Enumerated values for specifying the color mode for printing
	enum OutputColor {
		e_OutputColor_Color = 0,			///< 24bpp
		e_OutputColor_Grayscale = 1,		///< 8bpp
		e_OutputColor_Monochrome = 2,		///< single color (1bpp)
	};
	
	/// Enumerated values for specifying the orientation of output pages
	enum Orientation
	{
		e_Orientation_Portrait = 0,			///< taller than wide
		e_Orientation_Landscape	= 1			///< wider than tall
	};

	/// Enumerated values for specifying the scaling of document pages
	enum ScaleType {
		e_ScaleType_None = 0,				///< no scaling
		e_ScaleType_FitToOutputPage = 1,	///< fit to the output page
		e_ScaleType_ReduceToOutputPage = 2	///< shrink to fit the output page
	};

	/// Enumerated values for specifying the layout of multiple document pages
	/// onto output pages
	enum NUp {
		e_NUp_1_1 = 0,						///< 1 document page to 1 output page
		e_NUp_2_1 = 1,						///< 2 document pages to 1 output page
		e_NUp_2_2 = 2,						///< 2 by 2 document pages to 1 output page
		e_NUp_3_2 = 3,						///< 3 by 2 document pages to 1 output page
		e_NUp_3_3 = 4,						///< 3 by 3 document pages to 1 output page
		e_NUp_4_4 = 5,						///< 4 by 4 document pages to 1 output page
	};

	/// Enumerated values for specifying the ordering of document pages onto 
	/// output pages
	enum NUpPageOrder {
		e_PageOrder_LeftToRightThenTopToBottom = 0,	
		e_PageOrder_RightToLeftThenTopToBottom = 1,
		e_PageOrder_TopToBottomThenLeftToRight = 2,
		e_PageOrder_BottomToTopThenLeftToRight = 3
	};

	/// Enumerated values for specifying the document content to print
	enum PrintContentTypes {
		e_PrintContent_DocumentOnly = 0,
		e_PrintContent_DocumentAndAnnotations = 1,			
		e_PrintContent_DocumentAnnotationsAndComments = 2
	};


	PrinterMode();
	~PrinterMode();
	
	/** 
	 * Set automatic centering of document pages onto the output pages
	 *
	 * @param autoCenter if true will center document pages onto the output
	 * pages. Default is true.
	 */
	void SetAutoCenter(bool autoCenter);

	/** 
	 * Set automatic rotation of document pages to best fit the output pages
	 *
	 * @param autoRotate if true will rotate document pages onto the output
	 * pages. Default is true.
	 */
	void SetAutoRotate(bool autoRotate);

	/**
	 * Set the collation of the printing, useful for multiple copies
	 *
	 * @param collation if true, pages of copies will be printed 1, 2, 3. 
	 * if false, then pages of copies will be printed 1, 1, 1, ..., 2, 2, 2, ...
	 * Default is true.
	 */
	void SetCollation( bool collation );

	/**
	 * Set the number of copies to be printed
	 *
	 * @param copyCount the number of copies to be printed, must be greater 
	 * than zero. Default is 1.
	 */
	void SetCopyCount( int copyCount );

	/**
	 * Set the DPI (dots per inch) of the printing
	 *
	 * @param dpi, 300 is typically laser printer output, 96 dpi is LCD screen
	 * the larger this value the larger the file sent to the printer and
	 * the finer the document features that can be resolved. Default is 300.
	 */
	void SetDPI( int dpi );

	/**
	 * Set the duplexing mode 
	 *
	 * @param mode one of {e_Duplex_Auto, e_Duplex_None, e_Duplex_LongSide, 
	 * e_Duplex_ShortSide}.  Default is e_Duplex_Auto.
	 */
	void SetDuplexing( DuplexMode mode );

	/** 
	 * Set the number of document pages to place on the output pages
	 * across and vertically.  Pages will be automatically rotated to 
	 * best fit the page.
	 * 
	 * @param nup one of {e_NUp_1_1, e_NUp_2_1, e_NUp_2_2, e_NUp_3_2, e_NUp_3_3,
	 * e_NUp_4_4}.  Default is e_NUp_1_1.
	 * @param pageOrder order of document pages across and down output page.
	 * Default is e_PageOrder_LeftToRightThenTopToBottom.
	 */
	void SetNUp(NUp nup, NUpPageOrder pageOrder = e_PageOrder_LeftToRightThenTopToBottom);

	/** 
	 * Set the number of document pages to place on the output pages
	 * across and vertically.  Pages will be automatically rotated to 
	 * best fit the page.
	 * 
	 * Typical values: (2,1) 2-up; (2,2) 4 per page, etc
	 *
	 * @param x number of document pages across.  Default is 1.
	 * @param y number of document pages down.  Default is 1.
	 * @param pageOrder order of document pages across and down output page
	 * Default is e_PageOrder_LeftToRightThenTopToBottom.
	 */
	void SetNUp(unsigned int x, unsigned int y, NUpPageOrder pageOrder = e_PageOrder_LeftToRightThenTopToBottom);

	/** 
	 * Set the orientation of the output document
	 *
	 * @param orientation {e_Orientation_Portrait, e_Orientation_Landscape}
	 * Default is e_Orientation_Portrait.
	 */
	void SetOrientation(Orientation orientation);

	/** 
	 * Set the printing of annotations
	 *
	 * @param printContent one of {e_PrintContent_DocumentOnly, 
	 * e_PrintContent_DocumentAndAnnotations}.
	 * Default is e_PrintContent_DocumentAndAnnotations.
	 */
	void SetOutputAnnot(PrintContentTypes printContent);

	/**
	 * Set the color output of the printing
	 *
	 * @param color one of {e_OutputColor_Color, e_OutputColor_Grayscale, 
	 * e_OutputColor_Monochrome}.  Default is e_OutputColor_Color.
	 *
	 * @note If the XPS print path is being used, then the printer spooler file will
	 * ignore the grayscale option and be in full color.  The printer driver
	 * will then perform any color conversions necessary.
	 */
	void SetOutputColor( OutputColor color );

	/**
	 * Set the quality of the printing. Overridden if SetDPI is called.
	 *
	 * @param quality one of {e_OutputQuality_Draft, e_OutputQuality_Low,
	 * e_OutputQuality_Medium, e_OutputQuality_High}.  Default is
	 * to use DPI of 300.
	 */
	void SetOutputQuality( OutputQuality quality );

	/** 
	 * Set the printing of page borders, helpful when printing multiple document
	 * pages per output page
	 *
	 * @param printBorder if true will add a thin frame around each page border.
	 * Default is false.
	 */
	void SetOutputPageBorder(bool printBorder);

	/** 
	 * Set the output printer paper size (assumed to be correct)
	 *
	 * @param size the size of the output paper size in points (72 points = 1 inch).
	 * Default is US Letter or Rect(0, 0, 612, 792)
	 */
	void SetPaperSize(const Rect & size = Rect(0, 0, 612, 791) );
	
	/**
	 * Set the output printer paper size
	 * @param paperSize standard paper size enumerator
	 */
	void SetPaperSize(pdftron::PDF::PrinterMode::PaperSize paperSize);

	/**
	 * Set the scaling of the document pages to the output pages. Causes
	 * SetScaleType(e_ScaleType_CustomScale) to be set.
	 *
	 * @param scale to apply to document pages.  1.0 is no scale, greater
	 * than 1.0 increases document page sizes, less than 1.0 reduces
	 * document pages sizes on output pages.  Default is 1.0
	 */
	void SetScale(double scale);

	/** 
	 * Set the scaling of the document page to the output pages
	 *
	 * @param scaleType one of {e_ScaleType_None, e_ScaleType_FitToOutputPage,
	 * e_ScaleType_ReduceToOutputPage}. Default is e_ScaleType_None.
	 */
	void SetScaleType(ScaleType scaleType);
	
	/**
	 * Set whether RLE image compression is used for printing bitmaps
	 *
	 * @param useRleImageCompression if true, printer spool file will be
	 * reduced. However, some printers do not support this type of image
	 * compression and will produce blank pages.  Default is false
	 */
	void SetUseRleImageCompression( bool useRleImageCompression );


	// @cond PRIVATE_DOC

	#ifndef SWIGHIDDEN
	SDF::Obj m_printerMode;
	#endif
	// @endcond PRIVATE_DOC

private:
	SDF::ObjSet m_printerModeSet;
};

	}; // namespace PDF
}; // namespace pdftron

#include <Impl/Print.inl>

#endif // PDFTRON_H_CPPPDFPrint
