inline X501DistinguishedName::~X501DistinguishedName()
{
	Destroy();
}

inline X501DistinguishedName::X501DistinguishedName(const X501DistinguishedName& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void X501DistinguishedName::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_X501DistinguishedNameDestroy(m_impl));
		m_owner = false;
	}
}

inline X501DistinguishedName& X501DistinguishedName::operator= (const X501DistinguishedName& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}


inline X501DistinguishedName::X501DistinguishedName(TRN_X501DistinguishedName impl)
	: m_impl(impl)
	, m_owner(true)
{}

#ifdef SWIG
inline X501DistinguishedName::X501DistinguishedName()
	: m_impl(0)
	, m_owner(false)
{}
#endif


inline bool X501DistinguishedName::HasAttribute(const ObjectIdentifier& in_oid) const
{
	TRN_Bool result = 0;
	REX(TRN_X501DistinguishedNameHasAttribute((TRN_X501DistinguishedName)m_impl, in_oid.m_impl, &result));
	return result != 0;
}

#ifdef SWIG
inline std::vector<std::string> X501DistinguishedName::GetStringValuesForAttribute(const ObjectIdentifier& in_oid) const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_X501DistinguishedNameGetStringValuesForAttribute((TRN_X501DistinguishedName)m_impl, in_oid.m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<std::string> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UString current_ustr = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current_ustr);

		result.push_back(UString(current_ustr).ConvertToUtf8());
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}
#else
inline std::vector<UString> X501DistinguishedName::GetStringValuesForAttribute(const ObjectIdentifier& in_oid) const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_X501DistinguishedNameGetStringValuesForAttribute((TRN_X501DistinguishedName)m_impl, in_oid.m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<UString> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UString current_ustr = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current_ustr);
		result.push_back(UString(current_ustr));
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}
#endif
 
inline std::vector<X501AttributeTypeAndValue> X501DistinguishedName::GetAllAttributesAndValues() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_X501DistinguishedNameGetAllAttributesAndValues((TRN_X501DistinguishedName)m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<X501AttributeTypeAndValue> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_X501AttributeTypeAndValue current = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current);
		result.push_back(X501AttributeTypeAndValue(current));
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}
