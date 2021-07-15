inline ResultSnapshot::~ResultSnapshot()
{
	Destroy();
}

inline ResultSnapshot::ResultSnapshot(const ResultSnapshot& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void ResultSnapshot::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_ResultSnapshotDestroy(m_impl));
		m_owner = false;
	}
}

inline ResultSnapshot& pdftron::SDF::ResultSnapshot::operator= (const ResultSnapshot& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline ResultSnapshot::ResultSnapshot()
	: m_impl(0)
	, m_owner(false)
{}

inline ResultSnapshot::ResultSnapshot(TRN_ResultSnapshot impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline DocSnapshot ResultSnapshot::CurrentState() const
{
	DocSnapshot result;
	REX(TRN_ResultSnapshotCurrentState((TRN_ResultSnapshot)m_impl, (TRN_DocSnapshot*)&result.m_impl));
	return result;
}

inline DocSnapshot ResultSnapshot::PreviousState() const
{
	DocSnapshot result;
	REX(TRN_ResultSnapshotPreviousState((TRN_ResultSnapshot)m_impl, (TRN_DocSnapshot*)&result.m_impl));
	return result;
}

inline bool ResultSnapshot::IsOk() const
{
	TRN_Bool result = 0;
	REX(TRN_ResultSnapshotIsOk((TRN_ResultSnapshot)m_impl, &result));
	return result != 0;
}

inline bool ResultSnapshot::IsNullTransition() const
{
	TRN_Bool result = 0;
	REX(TRN_ResultSnapshotIsNullTransition((TRN_ResultSnapshot)m_impl, &result));
	return result != 0;
}

