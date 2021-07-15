inline ShapedText::~ShapedText()
{
	Destroy();
}

inline ShapedText::ShapedText(const ShapedText& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void ShapedText::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_ShapedTextDestroy(m_impl));
		m_owner = false;
	}
}

inline ShapedText& pdftron::PDF::ShapedText::operator= (const ShapedText& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline ShapedText::ShapedText()
	: m_impl(0)
	, m_owner(false)
{}

inline ShapedText::ShapedText(TRN_ShapedText impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline double ShapedText::GetScale() const
{
	double result = 0;
	REX(TRN_ShapedTextGetScale((TRN_ShapedText)m_impl, &result));
	return result;
}

inline ShapedText::ShapingStatus ShapedText::GetShapingStatus() const
{
	ShapingStatus result;
	REX(TRN_ShapedTextGetShapingStatus((TRN_ShapedText)m_impl, (enum TRN_ShapedText_ShapingStatus*) &result));
	return result;
}

inline ShapedText::FailureReason ShapedText::GetFailureReason() const
{
	FailureReason result;
	REX(TRN_ShapedTextGetFailureReason((TRN_ShapedText)m_impl, (enum TRN_ShapedText_FailureReason*) &result));
	return result;
}

inline UString ShapedText::GetText() const
{
	UString result;
	REX(TRN_ShapedTextGetText((TRN_ShapedText)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline int ShapedText::GetNumGlyphs() const
{
	int result;
	REX(TRN_ShapedTextGetNumGlyphs((TRN_ShapedText)m_impl, &result));
	return result;
}

inline UInt32 ShapedText::GetGlyph(UInt32 index) const
{
	UInt32 result = 0;
	REX(TRN_ShapedTextGetGlyph((TRN_ShapedText)m_impl, index, &result));
	return result;
}

inline double ShapedText::GetGlyphXPos(UInt32 index) const
{
	double result = 0;
	REX(TRN_ShapedTextGetGlyphXPos((TRN_ShapedText)m_impl, index, &result));
	return result;
}

inline double ShapedText::GetGlyphYPos(UInt32 index) const
{
	double result = 0;
	REX(TRN_ShapedTextGetGlyphYPos((TRN_ShapedText)m_impl, index, &result));
	return result;
}

