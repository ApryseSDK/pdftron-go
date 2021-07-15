inline X509Extension::X509Extension(const X509Extension& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline X509Extension& X509Extension::operator= (const X509Extension& other)
{
	Destroy();

	m_impl = other.m_impl;

	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

#ifdef SWIG
inline X509Extension::X509Extension()
	: m_impl(0)
	, m_owner(false)
{}
#endif

inline X509Extension::X509Extension(TRN_X509Extension impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline X509Extension::~X509Extension()
{
	Destroy();
}

inline void X509Extension::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_X509ExtensionDestroy(m_impl));
		m_owner = false;
	}
}


inline bool X509Extension::IsCritical() const
{
	TRN_Bool result = 0;
	REX(TRN_X509ExtensionIsCritical((TRN_X509Extension)m_impl, &result));
	return result != 0;
}

inline ObjectIdentifier X509Extension::GetObjectIdentifier() const
{
	TRN_ObjectIdentifier result;
	REX(TRN_X509ExtensionGetObjectIdentifier((TRN_X509Extension)m_impl, (TRN_ObjectIdentifier*) &result));
	return ObjectIdentifier(result);
}

inline UString X509Extension::ToString() const
{
	UString result;
	REX(TRN_X509ExtensionToString((TRN_X509Extension)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}


inline std::vector<UChar> X509Extension::GetData() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_X509ExtensionGetData(m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<unsigned char> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UChar* current = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current);
		result.push_back(*current);
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;;
}