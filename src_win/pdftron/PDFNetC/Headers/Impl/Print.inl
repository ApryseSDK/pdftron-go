namespace pdftron {
	namespace PDF {

inline void Print::StartPrintJob(PDFDoc & in_pdfdoc,
								 const UString & in_printerName, 
								 const UString & in_jobName,
								 const UString & in_outputFileName,
								 PageSet * in_pagesToPrint,
								 PrinterMode * in_printerMode,
								 volatile bool * in_cancel,
								 OCG::Context * in_context)
{
	REX(TRN_PrintStartPrintJob(in_pdfdoc.mp_doc, 
		in_printerName.mp_impl, 
		in_jobName.mp_impl, 
		in_outputFileName.mp_impl, 
		in_pagesToPrint ? in_pagesToPrint->mp_impl : NULL, 
		in_printerMode ? in_printerMode->m_printerMode.mp_obj : NULL, 
		(volatile TRN_Bool *) in_cancel,
		in_context ? in_context->mp_obj : NULL));
}

inline void Print::StartPrintJob(PDFDoc & in_pdfdoc,
								 const char * in_printerName, 
								 const char * in_jobName,
								 const char * in_outputFileName,
								 PageSet * in_pagesToPrint,
								 PrinterMode * in_printerMode,
								 volatile bool * in_cancel,
								 OCG::Context * in_context)
{
	// change char*'s to UString's, call overloaded function
	Print::StartPrintJob(in_pdfdoc, 
		UString(in_printerName), 
		UString(in_jobName), 
		UString(in_outputFileName), 
		in_pagesToPrint,
		in_printerMode, 
		in_cancel,
		in_context);
}

inline PrinterMode::PrinterMode() 
: m_printerMode(SDF::Obj())
{
	m_printerMode = m_printerModeSet.CreateDict();
}

inline PrinterMode::~PrinterMode()
{
}

inline void PrinterMode::SetAutoCenter(bool autoCenter)
{
	m_printerMode.PutBool("AutoCenter", autoCenter);
}

inline void PrinterMode::SetAutoRotate(bool autoRotate)
{
	m_printerMode.PutBool("AutoRotate", autoRotate);
}

inline void PrinterMode::SetCollation( bool collation )
{
	m_printerMode.PutBool("Collation", collation);
}

inline void PrinterMode::SetCopyCount( int copyCount )
{
	m_printerMode.PutNumber("CopyCount", copyCount);
}

inline void PrinterMode::SetDuplexing( PrinterMode::DuplexMode mode )
{
	m_printerMode.PutNumber("Duplexing", (double) mode);
}

inline void PrinterMode::SetDPI( int dpi )
{
	m_printerMode.PutNumber("DPI", (double) dpi);
}

inline void PrinterMode::SetNUp(NUp nup, NUpPageOrder pageOrder )
{
	m_printerMode.PutNumber("NupType", (double) nup);
	m_printerMode.PutNumber("NUpPageOrder", (double) pageOrder);
}

inline void PrinterMode::SetNUp(unsigned int x, unsigned int y, NUpPageOrder pageOrder)
{
	m_printerMode.PutNumber("NupType", (double) -1);
	m_printerMode.PutNumber("NupX", (double) ((int) x));
	m_printerMode.PutNumber("NupY", (double) ((int) y));
	m_printerMode.PutNumber("NUpPageOrder", (double) pageOrder);
}	

inline void PrinterMode::SetOrientation(Orientation orientation)
{
	m_printerMode.PutNumber("Orientation", (double) orientation);
}	

inline void PrinterMode::SetOutputAnnot(PrintContentTypes printContent)
{
	m_printerMode.PutNumber("PrintContent", (double) printContent);
}

inline void PrinterMode::SetOutputColor( PrinterMode::OutputColor color )
{
	m_printerMode.PutNumber("OutputColor", (double) color);
}

inline void PrinterMode::SetOutputPageBorder(bool printBorder)
{
	m_printerMode.PutBool("OutputPageBorder", printBorder);
}

inline void PrinterMode::SetOutputQuality( PrinterMode::OutputQuality quality )
{
	m_printerMode.PutNumber("OutputQuality", (double) quality);
}

inline void PrinterMode::SetPaperSize(const Rect & size)
{
	m_printerMode.PutNumber("PaperSizeX1", size.x1);
	m_printerMode.PutNumber("PaperSizeX2", size.x2);
	m_printerMode.PutNumber("PaperSizeY1", size.y1);
	m_printerMode.PutNumber("PaperSizeY2", size.y2);
	m_printerMode.PutNumber("PaperSize", 0); //0 is custom paper size
}

inline void PrinterMode::SetPaperSize(pdftron::PDF::PrinterMode::PaperSize paperSize)
{
	m_printerMode.PutNumber("PaperSize", (int)paperSize);
	if (paperSize != e_custom) 
	{
		m_printerMode.PutNumber("PaperSizeX1", 0);
		m_printerMode.PutNumber("PaperSizeX2", 0);
		m_printerMode.PutNumber("PaperSizeY1", 0);
		m_printerMode.PutNumber("PaperSizeY2", 0);	
	}
}

inline void PrinterMode::SetScale(double scale)
{
	m_printerMode.PutNumber("ScaleType", (double) -1);
	m_printerMode.PutNumber("ScaleValue", scale);
}

inline void PrinterMode::SetScaleType(ScaleType scaleType)
{
	m_printerMode.PutNumber("ScaleType", (double) scaleType);
}	

inline void PrinterMode::SetUseRleImageCompression( bool useRleImageCompression )
{
	m_printerMode.PutBool("UseRleImageCompression", useRleImageCompression);
}

	}; // namespace pdftron
}; // namespace SDF

