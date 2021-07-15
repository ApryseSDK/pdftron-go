inline Reflow::~Reflow()
{
	Destroy();
}

inline Reflow::Reflow(const Reflow& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void Reflow::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_ReflowDestroy(m_impl));
		m_owner = false;
	}
}

inline Reflow& pdftron::PDF::Reflow::operator= (const Reflow& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline Reflow::Reflow()
	: m_impl(0)
	, m_owner(false)
{}

inline Reflow::Reflow(TRN_Reflow impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline UString Reflow::GetHtml()
{
	UString result;
	REX(TRN_ReflowGetHtml((TRN_Reflow)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString Reflow::GetAnnot(UString in_id)
{
	UString result;
	REX(TRN_ReflowGetAnnot((TRN_Reflow)m_impl, (TRN_UString)in_id.mp_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString Reflow::SetAnnot(UString in_json)
{
	UString result;
	REX(TRN_ReflowSetAnnot((TRN_Reflow)m_impl, (TRN_UString)in_json.mp_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

