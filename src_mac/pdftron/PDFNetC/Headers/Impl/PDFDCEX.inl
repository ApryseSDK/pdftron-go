

inline PDFDCEX::PDFDCEX()
{
	REX(TRN_PDFDCEXCreate(&m_pdfDcEx));
}

inline PDFDCEX::~PDFDCEX()
{
	DREX(m_pdfDcEx, TRN_PDFDCEXDestroy(m_pdfDcEx));
}

inline void PDFDCEX::Destroy()
{
	REX(TRN_PDFDCEXDestroy(m_pdfDcEx));
	m_pdfDcEx = 0;
}

inline HDC PDFDCEX::Begin(PDFDoc & in_pdfdoc, const Point& page_dimension)
{
	HDC result;
	REX(TRN_PDFDCEXBegin(m_pdfDcEx, in_pdfdoc.mp_doc, (const TRN_Point*)&page_dimension, &result));
	return result;
}

inline void PDFDCEX::End()
{
	REX(TRN_PDFDCEXEnd(m_pdfDcEx));
}

inline UInt32 PDFDCEX::GetDPI()
{
    UInt32 tmp = 0;
	TRN_PDFDCEXGetDPI( m_pdfDcEx, &tmp );
    return tmp;
}
