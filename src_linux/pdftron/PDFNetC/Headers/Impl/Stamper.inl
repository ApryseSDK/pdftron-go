
//CONSTRUCTOR
inline Stamper::Stamper(SizeType size_type, double a, double b)
{
	REX(TRN_StamperCreate(static_cast<TRN_StamperSizeType>(size_type), a, b, &mp_impl));
}

inline Stamper::Stamper(TRN_Stamper impl)
: mp_impl(impl)
{
}

//DESTRUCTOR
inline Stamper::~Stamper()
{
	DREX(mp_impl, TRN_StamperDestroy(mp_impl));
}

inline void Stamper::Destroy()
{
	REX(TRN_StamperDestroy(mp_impl));
	mp_impl = 0;
}

//STAMPS
inline void Stamper::StampPage(PDF::PDFDoc& dest_doc, Page src_page, const PageSet& dest_pages)
{
	REX(TRN_StamperStampPage(mp_impl, dest_doc.mp_doc, src_page.mp_page, dest_pages.mp_impl));
}

inline void Stamper::StampImage(PDF::PDFDoc& dest_doc, Image src_img, const PageSet& dest_pages)
{
	REX(TRN_StamperStampImage(mp_impl, dest_doc.mp_doc, src_img.mp_image, dest_pages.mp_impl));
}

inline void Stamper::StampText(PDF::PDFDoc& dest_doc, const UString& src_txt, const PageSet& dest_pages)
{
	REX(TRN_StamperStampText(mp_impl, dest_doc.mp_doc, src_txt.mp_impl, dest_pages.mp_impl));
}

//TEXT ONLY METHODS
inline void Stamper::SetFont(Font font)
{
	REX(TRN_StamperSetFont(mp_impl, font.mp_font));
}

inline void Stamper::SetFontColor(const PDF::ColorPt& color)
{
	REX(TRN_StamperSetFontColor(mp_impl, &color.m_c));
}

inline void Stamper::SetTextAlignment(TextAlignment text_alignment)
{
	REX(TRN_StamperSetTextAlignment(mp_impl, (TRN_StamperTextAlignment)text_alignment));
}

//APPEARANCE
inline void Stamper::SetOpacity(double opacity)
{
	REX(TRN_StamperSetOpacity(mp_impl, opacity));
}

inline void Stamper::SetRotation(double rotation)
{
	REX(TRN_StamperSetRotation(mp_impl, rotation));
}

inline void Stamper::SetSize(SizeType size_type, double a, double b)
{
	REX(TRN_StamperSetSize(mp_impl, (TRN_StamperSizeType)size_type, a, b));
}

inline void Stamper::SetAsBackground(bool background)
{
	REX(TRN_StamperSetAsBackground(mp_impl, background));
}

inline void Stamper::SetAsAnnotation(bool annotation)
{
	REX(TRN_StamperSetAsAnnotation(mp_impl, annotation));
}

inline void Stamper::ShowsOnScreen(bool on_screen)
{
	REX(TRN_StamperShowsOnScreen(mp_impl, BToTB(on_screen)));
}

inline void Stamper::ShowsOnPrint(bool on_print)
{
	REX(TRN_StamperShowsOnPrint(mp_impl, BToTB(on_print)));
}


//POSITION
inline void Stamper::SetAlignment(HorizontalAlignment horizontal_alignment, VerticalAlignment vertical_alignment)
{
	REX(TRN_StamperSetAlignment(mp_impl, (TRN_StamperHorizontalAlignment)horizontal_alignment, (TRN_StamperVerticalAlignment)vertical_alignment));
}

inline void Stamper::SetPosition(double x, double y, bool use_percentage)
{
	REX(TRN_StamperSetPosition(mp_impl, x, y, BToTB(use_percentage)));
}

//STATIC METHODS
inline void Stamper::DeleteStamps(PDFDoc& doc, const PageSet& page_set)
{
	REX(TRN_StamperDeleteStamps(doc.mp_doc, page_set.mp_impl));
}

inline bool Stamper::HasStamps(PDFDoc& doc, const PageSet& page_set)
{
	TRN_Bool res;
	REX(TRN_StamperHasStamps(doc.mp_doc, page_set.mp_impl, &res));
	return TBToB(res);
}
