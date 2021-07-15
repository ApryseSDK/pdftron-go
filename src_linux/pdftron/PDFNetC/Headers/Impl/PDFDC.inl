
inline PDFDC::PDFDC()
{
	REX(TRN_PDFDcCreate(&m_pdfdc));
}

inline PDFDC::~PDFDC()
{
	DREX(m_pdfdc, TRN_PDFDcDestroy(m_pdfdc));
}

inline void PDFDC::Destroy()
{
	REX(TRN_PDFDcDestroy(m_pdfdc));
	m_pdfdc = 0;
}

inline HDC PDFDC::Begin( Page in_page, const Rect in_bbox, bool in_preserveAspectRatio )
{
	HDC result;
	REX(TRN_PDFDcBegin (m_pdfdc, in_page.mp_page, (const TRN_Rect)in_bbox, in_preserveAspectRatio, &result));
	return result;
}

inline void PDFDC::End()
{
	TRN_PDFDcEnd(m_pdfdc);
}


inline void PDFDC::SetDPI( const TRN_UInt32 in_dpi )
{
	REX(TRN_PDFDcSetDPI (m_pdfdc, in_dpi ));
}