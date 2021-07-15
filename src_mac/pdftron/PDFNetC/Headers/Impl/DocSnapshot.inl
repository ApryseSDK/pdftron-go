inline DocSnapshot::~DocSnapshot()
{
	Destroy();
}

inline DocSnapshot::DocSnapshot(const DocSnapshot& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void DocSnapshot::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_DocSnapshotDestroy(m_impl));
		m_owner = false;
	}
}

inline DocSnapshot& pdftron::SDF::DocSnapshot::operator= (const DocSnapshot& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline DocSnapshot::DocSnapshot()
	: m_impl(0)
	, m_owner(false)
{}

inline DocSnapshot::DocSnapshot(TRN_DocSnapshot impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline UInt32 DocSnapshot::GetHash() const
{
	UInt32 result = 0;
	REX(TRN_DocSnapshotGetHash((TRN_DocSnapshot)m_impl, &result));
	return result;
}

inline bool DocSnapshot::IsValid() const
{
	TRN_Bool result = 0;
	REX(TRN_DocSnapshotIsValid((TRN_DocSnapshot)m_impl, &result));
	return result != 0;
}

inline bool DocSnapshot::Equals(DocSnapshot snapshot) const
{
	TRN_Bool result = 0;
	REX(TRN_DocSnapshotEquals((TRN_DocSnapshot)m_impl, (TRN_DocSnapshot)snapshot.m_impl, &result));
	return result != 0;
}

