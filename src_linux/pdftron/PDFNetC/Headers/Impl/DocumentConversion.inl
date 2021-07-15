inline DocumentConversion::~DocumentConversion()
{
	Destroy();
}

inline DocumentConversion::DocumentConversion(const DocumentConversion& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void DocumentConversion::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_DocumentConversionDestroy(&m_impl));
		m_owner = false;
	}
}

inline DocumentConversion& pdftron::PDF::DocumentConversion::operator= (const DocumentConversion& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline DocumentConversion::DocumentConversion()
	: m_impl(0)
	, m_owner(false)
{}

inline DocumentConversion::DocumentConversion(TRN_DocumentConversion impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline DocumentConversion::Result DocumentConversion::TryConvert()
{
	Result result;
	REX(TRN_DocumentConversionTryConvert((TRN_DocumentConversion)m_impl, (enum TRN_DocumentConversion_Result*) &result));
	return result;
}

inline void DocumentConversion::Convert()
{
	REX(TRN_DocumentConversionConvert((TRN_DocumentConversion)m_impl));
}

inline void DocumentConversion::ConvertNextPage()
{
	REX(TRN_DocumentConversionConvertNextPage((TRN_DocumentConversion)m_impl));
}

inline PDFDoc DocumentConversion::GetDoc()
{
	PDFDoc result;
	REX(TRN_DocumentConversionGetDoc((TRN_DocumentConversion)m_impl, (TRN_PDFDoc*)&result.mp_doc));
	return result;
}

inline DocumentConversion::Result DocumentConversion::GetConversionStatus() const
{
	Result result;
	REX(TRN_DocumentConversionGetConversionStatus((TRN_DocumentConversion)m_impl, (enum TRN_DocumentConversion_Result*) &result));
	return result;
}

inline void DocumentConversion::CancelConversion()
{
	REX(TRN_DocumentConversionCancelConversion((TRN_DocumentConversion)m_impl));
}

inline bool DocumentConversion::IsCancelled() const
{
	TRN_Bool result = 0;
	REX(TRN_DocumentConversionIsCancelled((TRN_DocumentConversion)m_impl, &result));
	return result != 0;
}

inline bool DocumentConversion::HasProgressTracking() const
{
	TRN_Bool result = 0;
	REX(TRN_DocumentConversionHasProgressTracking((TRN_DocumentConversion)m_impl, &result));
	return result != 0;
}

inline double DocumentConversion::GetProgress() const
{
	double result = 0;
	REX(TRN_DocumentConversionGetProgress((TRN_DocumentConversion)m_impl, &result));
	return result;
}

inline UString DocumentConversion::GetProgressLabel() const
{
	UString result;
	REX(TRN_DocumentConversionGetProgressLabel((TRN_DocumentConversion)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UInt32 DocumentConversion::GetNumConvertedPages() const
{
	UInt32 result = 0;
	REX(TRN_DocumentConversionGetNumConvertedPages((TRN_DocumentConversion)m_impl, &result));
	return result;
}

inline UString DocumentConversion::GetErrorString() const
{
	UString result;
	REX(TRN_DocumentConversionGetErrorString((TRN_DocumentConversion)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UInt32 DocumentConversion::GetNumWarnings() const
{
	UInt32 result = 0;
	REX(TRN_DocumentConversionGetNumWarnings((TRN_DocumentConversion)m_impl, &result));
	return result;
}

inline UString DocumentConversion::GetWarningString(UInt32 index) const
{
	UString result;
	REX(TRN_DocumentConversionGetWarningString((TRN_DocumentConversion)m_impl, index, (TRN_UString*)&result.mp_impl));
	return result;
}

// ---------------------------------------------------
//for xamarin use only
inline DocumentConversion* DocumentConversion::CreateInternal(ptrdiff_t impl) {
	return new DocumentConversion((TRN_DocumentConversion)impl);
}

inline ptrdiff_t DocumentConversion::GetHandleInternal() {
    return (ptrdiff_t) m_impl;
}
