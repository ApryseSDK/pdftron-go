inline X501AttributeTypeAndValue::X501AttributeTypeAndValue(const X501AttributeTypeAndValue& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline X501AttributeTypeAndValue& X501AttributeTypeAndValue::operator= (const X501AttributeTypeAndValue& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline X501AttributeTypeAndValue::X501AttributeTypeAndValue(TRN_X501AttributeTypeAndValue impl)
	: m_impl(impl)
	, m_owner(true)
{}

#ifdef SWIG
inline X501AttributeTypeAndValue::X501AttributeTypeAndValue()
	: m_impl(0)
	, m_owner(false)
{}
#endif

inline X501AttributeTypeAndValue::~X501AttributeTypeAndValue()
{
	Destroy();
}

inline void X501AttributeTypeAndValue::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_X501AttributeTypeAndValueDestroy(m_impl));
		m_owner = false;
	}
}

inline ObjectIdentifier X501AttributeTypeAndValue::GetAttributeTypeOID() const
{
	TRN_ObjectIdentifier result;
	REX(TRN_X501AttributeTypeAndValueGetAttributeTypeOID((TRN_X501AttributeTypeAndValue)m_impl, (TRN_ObjectIdentifier*) &result));
	return ObjectIdentifier(result);
}

inline UString X501AttributeTypeAndValue::GetStringValue() const
{
	UString result;
	REX(TRN_X501AttributeTypeAndValueGetStringValue((TRN_X501AttributeTypeAndValue)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

