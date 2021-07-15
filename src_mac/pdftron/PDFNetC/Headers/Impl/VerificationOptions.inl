inline VerificationOptions::~VerificationOptions()
{
	Destroy();
}

inline VerificationOptions::VerificationOptions(const VerificationOptions& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void VerificationOptions::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_VerificationOptionsDestroy(m_impl));
		m_owner = false;
	}
}

inline VerificationOptions& pdftron::PDF::VerificationOptions::operator= (const VerificationOptions& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline VerificationOptions::VerificationOptions(TRN_VerificationOptions impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline  VerificationOptions::VerificationOptions(SecurityLevel in_level)
	:m_impl(NULL), m_owner(true)
{
	REX(TRN_VerificationOptionsCreate((enum TRN_VerificationOptions_SecurityLevel) in_level, (TRN_VerificationOptions*)&m_impl));
}


inline void VerificationOptions::AddTrustedCertificate(const UChar* in_certificate_buf, size_t in_buf_size, const UInt16 in_trust_flags)
{
	REX(TRN_VerificationOptionsAddTrustedCertificate(m_impl, in_certificate_buf, in_buf_size, in_trust_flags));
}

inline void VerificationOptions::AddTrustedCertificate(const UString& in_filepath, const UInt16 in_trust_flags)
{
	REX(TRN_VerificationOptionsAddTrustedCertificateUString((TRN_VerificationOptions)m_impl, (TRN_UString)in_filepath.mp_impl, in_trust_flags));
}

inline void VerificationOptions::EnableModificationVerification(bool in_on_or_off)
{
	REX(TRN_VerificationOptionsEnableModificationVerification(m_impl, in_on_or_off));
}

inline void VerificationOptions::EnableDigestVerification(bool in_on_or_off)
{
	REX(TRN_VerificationOptionsEnableDigestVerification(m_impl, in_on_or_off));
}

inline void VerificationOptions::EnableTrustVerification(bool in_on_or_off)
{
	REX(TRN_VerificationOptionsEnableTrustVerification(m_impl, in_on_or_off));
}

inline void VerificationOptions::EnableOnlineCRLRevocationChecking(bool in_on_or_off)
{
	REX(TRN_VerificationOptionsEnableOnlineCRLRevocationChecking((TRN_VerificationOptions)m_impl, in_on_or_off));
}

inline void VerificationOptions::EnableOnlineOCSPRevocationChecking(bool in_on_or_off)
{
	REX(TRN_VerificationOptionsEnableOnlineOCSPRevocationChecking((TRN_VerificationOptions)m_impl, in_on_or_off));
}

inline void VerificationOptions::EnableOnlineRevocationChecking(bool in_on_or_off)
{
	REX(TRN_VerificationOptionsEnableOnlineRevocationChecking((TRN_VerificationOptions)m_impl, in_on_or_off));
}

inline void VerificationOptions::AddTrustedCertificates(const UChar* in_P7C_binary_DER_certificates_file_data, const size_t in_size)
{
	REX(TRN_VerificationOptionsAddTrustedCertificates((TRN_VerificationOptions)m_impl, in_P7C_binary_DER_certificates_file_data, in_size));
}

inline void VerificationOptions::LoadTrustList(const FDF::FDFDoc& in_fdf_cert_exchange_data)
{
	REX(TRN_VerificationOptionsLoadTrustList((TRN_VerificationOptions)m_impl, in_fdf_cert_exchange_data.mp_doc));
}
