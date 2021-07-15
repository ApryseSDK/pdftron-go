
inline TimestampingConfiguration::TimestampingConfiguration(const TimestampingConfiguration& other)
	: m_impl(other.m_impl)
{
}

inline TimestampingConfiguration& TimestampingConfiguration::operator= (const TimestampingConfiguration& other)
{
	m_impl = other.m_impl;
	return *this;
}

#ifdef SWIG
inline TimestampingConfiguration::TimestampingConfiguration()
	: m_impl(0)
{}
#endif

inline TimestampingConfiguration::TimestampingConfiguration(TRN_TimestampingConfiguration impl)
	: m_impl(impl)
{}

inline TimestampingConfiguration::TimestampingConfiguration(const UString& in_url)
{
	REX(TRN_TimestampingConfigurationCreateFromURL((TRN_UString)in_url.mp_impl, &m_impl));
}

inline TimestampingConfiguration::~TimestampingConfiguration()
{
	DREX(m_impl, TRN_TimestampingConfigurationDestroy(m_impl));
}

inline void TimestampingConfiguration::Destroy()
{
	REX(TRN_TimestampingConfigurationDestroy(m_impl));
	m_impl=0;
}

inline void TimestampingConfiguration::SetTimestampAuthorityServerURL(const UString& in_url)
{
	REX(TRN_TimestampingConfigurationSetTimestampAuthorityServerURL((TRN_TimestampingConfiguration)m_impl, (TRN_UString)in_url.mp_impl));
}

inline void TimestampingConfiguration::SetTimestampAuthorityServerUsername(const UString& in_username)
{
	REX(TRN_TimestampingConfigurationSetTimestampAuthorityServerUsername((TRN_TimestampingConfiguration)m_impl, (TRN_UString)in_username.mp_impl));
}

inline void TimestampingConfiguration::SetTimestampAuthorityServerPassword(const UString& in_password)
{
	REX(TRN_TimestampingConfigurationSetTimestampAuthorityServerPassword((TRN_TimestampingConfiguration)m_impl, (TRN_UString)in_password.mp_impl));
}

inline void TimestampingConfiguration::SetUseNonce(bool in_use_nonce)
{
	REX(TRN_TimestampingConfigurationSetUseNonce((TRN_TimestampingConfiguration)m_impl, (TRN_Bool)in_use_nonce));
}

inline TimestampingTestResult TimestampingConfiguration::TestConfiguration(const VerificationOptions& in_opts) const
{
	TRN_TimestampingTestResult result;
	REX(TRN_TimestampingConfigurationTestConfiguration((TRN_TimestampingConfiguration)m_impl, (TRN_VerificationOptions)in_opts.m_impl, (TRN_TimestampingTestResult*)&result));
	return TimestampingTestResult(result);
}

