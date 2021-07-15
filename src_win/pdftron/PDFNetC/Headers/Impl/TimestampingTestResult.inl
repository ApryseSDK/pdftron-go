#ifdef SWIG
inline TimestampingTestResult::TimestampingTestResult()
	: m_impl(0)
	, m_owner(false)
{}
#endif


inline TimestampingTestResult::~TimestampingTestResult()
{
	Destroy();
}

inline TimestampingTestResult::TimestampingTestResult(const TimestampingTestResult& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void TimestampingTestResult::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_TimestampingTestResultDestroy(m_impl));
		m_owner = false;
	}
}

inline TimestampingTestResult& pdftron::PDF::TimestampingTestResult::operator= (const TimestampingTestResult& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}


inline TimestampingTestResult::TimestampingTestResult(TRN_TimestampingTestResult impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline bool TimestampingTestResult::GetStatus() const
{
	TRN_Bool result = 0;
	REX(TRN_TimestampingTestResultGetStatus((TRN_TimestampingTestResult)m_impl, &result));
	return result != 0;
}

inline UString TimestampingTestResult::GetString() const
{
	UString result;
	REX(TRN_TimestampingTestResultGetString((TRN_TimestampingTestResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline bool TimestampingTestResult::HasResponseVerificationResult() const
{
	TRN_Bool result = 0;
	REX(TRN_TimestampingTestResultHasResponseVerificationResult((TRN_TimestampingTestResult)m_impl, &result));
	return result != 0;
}

inline EmbeddedTimestampVerificationResult TimestampingTestResult::GetResponseVerificationResult() const
{
	TRN_EmbeddedTimestampVerificationResult result;
	REX(TRN_TimestampingTestResultGetResponseVerificationResult((TRN_TimestampingTestResult)m_impl, (TRN_EmbeddedTimestampVerificationResult*) &result));
	return EmbeddedTimestampVerificationResult(result);
}

