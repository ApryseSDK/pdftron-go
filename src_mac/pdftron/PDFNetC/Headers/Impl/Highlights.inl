//for xamarin use only
inline Highlights* Highlights::CreateInternal(ptrdiff_t impl) {
	return new Highlights((TRN_Highlights)impl);
}

inline ptrdiff_t Highlights::GetHandleInternal() {
    return (ptrdiff_t) mp_highlights;
}

inline Highlights::Highlights()
{
	REX(TRN_HighlightsCreate(&mp_highlights));
}


inline Highlights::~Highlights()
{
	DREX(mp_highlights, TRN_HighlightsDestroy(mp_highlights));
}

inline void Highlights::Destroy ()
{
	REX(TRN_HighlightsDestroy(mp_highlights));
	mp_highlights = 0;
}

inline Highlights::Highlights(const Highlights& hlts)
{
	REX(TRN_HighlightsCopyCtor(hlts.mp_highlights, &mp_highlights));
}

inline Highlights& Highlights::operator = ( const Highlights& hlts )
{
	REX( TRN_HighlightsAssign(mp_highlights, hlts.mp_highlights) );
	return *this;
}

inline void Highlights::Add( const Highlights& hlts )
{
	REX( TRN_HighlightsAdd(mp_highlights, hlts.mp_highlights ) );
}

inline void Highlights::Load( const UString& file_name )
{
	REX( TRN_HighlightsLoad(mp_highlights, file_name.mp_impl) );
}

inline void Highlights::Save( const UString& file_name )
{
	REX( TRN_HighlightsSave(mp_highlights, file_name.mp_impl) );
}

inline void Highlights::Clear()
{
	REX( TRN_HighlightsClear(mp_highlights) );
}

inline void Highlights::Begin(PDFDoc& doc)
{
	TRN_HighlightsBegin(mp_highlights, doc.mp_doc);
}

inline bool Highlights::HasNext() const
{
	RetBool( TRN_HighlightsHasNext(mp_highlights, &result) );
}

inline void Highlights::Next()
{
	TRN_HighlightsNext(mp_highlights);
}

inline int Highlights::GetCurrentPageNumber() const
{
	RetInt(TRN_HighlightsGetCurrentPageNumber(mp_highlights, &result));
}

inline std::vector<QuadPoint> Highlights::GetCurrentQuads() const
{
	int num;
	double* quads;
	TRN_HighlightsGetCurrentQuads(mp_highlights, ((const double**)&quads), &num);
	std::vector<QuadPoint> result;
	result.resize(num);
	
	int i;
	for(i = 0; i < num; i++) {
		Point p1 = Point(quads[i*8+0], quads[i*8+1]);
		Point p2 = Point(quads[i*8+2], quads[i*8+3]);
		Point p3 = Point(quads[i*8+4], quads[i*8+5]);
		Point p4 = Point(quads[i*8+6], quads[i*8+7]);
		result[i] = QuadPoint(p1, p2, p3, p4);
	}
	return result;
}

#ifndef SWIG
inline int Highlights::GetCurrentQuads(const double* &quads) const
{
	RetInt(TRN_HighlightsGetCurrentQuads(mp_highlights, &quads, &result));
}
#endif


