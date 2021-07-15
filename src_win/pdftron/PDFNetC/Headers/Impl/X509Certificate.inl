
#ifdef SWIG
inline X509Certificate::X509Certificate()
	: m_impl(0)
	, m_owner(false)
{}
#endif

inline X509Certificate::~X509Certificate()
{
	Destroy();
}

inline X509Certificate::X509Certificate(const X509Certificate& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void X509Certificate::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_X509CertificateDestroy(m_impl));
		m_owner = false;
	}
}

inline X509Certificate& X509Certificate::operator= (const X509Certificate& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}


inline X509Certificate::X509Certificate(TRN_X509Certificate impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline X501DistinguishedName X509Certificate::GetIssuerField() const
{
	TRN_X501DistinguishedName result;
	REX(TRN_X509CertificateGetIssuerField((TRN_X509Certificate)m_impl, (TRN_X501DistinguishedName*) &result));
	return X501DistinguishedName(result);
}

inline X501DistinguishedName X509Certificate::GetSubjectField() const
{
	TRN_X501DistinguishedName result;
	REX(TRN_X509CertificateGetSubjectField((TRN_X509Certificate)m_impl, (TRN_X501DistinguishedName*) &result));
	return X501DistinguishedName(result);
}

inline Int64 X509Certificate::GetNotBeforeEpochTime() const
{
	Int64 result;
	REX(TRN_X509CertificateGetNotBeforeEpochTime((TRN_X509Certificate)m_impl, (TRN_Int64*) &result));
	return result;
}

inline Int64 X509Certificate::GetNotAfterEpochTime() const
{
	Int64 result;
	REX(TRN_X509CertificateGetNotAfterEpochTime((TRN_X509Certificate)m_impl, (TRN_Int64*) &result));
	return result;
}

inline UInt32 X509Certificate::GetRawX509VersionNumber() const
{
	UInt32 result;
	REX(TRN_X509CertificateGetRawX509VersionNumber((TRN_X509Certificate)m_impl, (TRN_UInt32*) &result));
	return result;
}

inline UString X509Certificate::ToString() const
{
	UString result;
	REX(TRN_X509CertificateToString((TRN_X509Certificate)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString X509Certificate::GetFingerprint(enum DigestAlgorithm::Type in_digest_algorithm) const
{
	UString result;
	REX(TRN_X509CertificateGetFingerprint((TRN_X509Certificate)m_impl, (TRN_DigestAlgorithm_Type)in_digest_algorithm, (TRN_UString*)&result.mp_impl));
	return result;
}
inline std::vector<UChar> X509Certificate::GetSerialNumber() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_X509CertificateGetSerialNumber(m_impl, (TRN_Vector*)&vec));
	
	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);
	
	std::vector<UChar> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UChar* current = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current);
		result.push_back(*current);
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}

inline std::vector<X509Extension> X509Certificate::GetExtensions() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_X509CertificateGetExtensions(m_impl, (TRN_Vector*)&vec));
	
	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);
	
	std::vector<X509Extension> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_X509Extension current = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current);
		result.push_back(X509Extension(current));
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}

inline std::vector<UChar> X509Certificate::GetData() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_X509CertificateGetData(m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<UChar> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UChar* current = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current);
		result.push_back(*current);
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;;
}
