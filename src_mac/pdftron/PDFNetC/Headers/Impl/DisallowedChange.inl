inline DisallowedChange::~DisallowedChange()
{
	Destroy();
}

inline DisallowedChange::DisallowedChange(const DisallowedChange& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void DisallowedChange::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_DisallowedChangeDestroy(m_impl));
		m_owner = false;
	}
}

inline DisallowedChange& pdftron::PDF::DisallowedChange::operator= (const DisallowedChange& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline DisallowedChange::DisallowedChange()
	: m_impl(0)
	, m_owner(false)
{}

inline DisallowedChange::DisallowedChange(TRN_DisallowedChange impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline UInt32 DisallowedChange::GetObjNum() const
{
	UInt32 result = 0;
	REX(TRN_DisallowedChangeGetObjNum((TRN_DisallowedChange)m_impl, &result));
	return result;
}

inline DisallowedChange::Type DisallowedChange::GetType() const
{
	Type result;
	REX(TRN_DisallowedChangeGetType((TRN_DisallowedChange)m_impl, (enum TRN_DisallowedChange_Type*) &result));
	return result;
}

inline UString DisallowedChange::GetTypeAsString() const
{
	UString result;
	REX(TRN_DisallowedChangeGetTypeAsString((TRN_DisallowedChange)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

