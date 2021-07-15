inline ExternalAnnotManager::~ExternalAnnotManager()
{
	Destroy();
}

inline ExternalAnnotManager::ExternalAnnotManager(const ExternalAnnotManager& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void ExternalAnnotManager::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_ExternalAnnotManagerDestroy(&m_impl));
		m_owner = false;
	}
}

inline ExternalAnnotManager& pdftron::PDF::ExternalAnnotManager::operator= (const ExternalAnnotManager& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline ExternalAnnotManager::ExternalAnnotManager()
	: m_impl(0)
	, m_owner(false)
{}

inline ExternalAnnotManager::ExternalAnnotManager(TRN_ExternalAnnotManager impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline void ExternalAnnotManager::MergeXFDF(UString xfdf_content)
{
	REX(TRN_ExternalAnnotManagerMergeXFDF((TRN_ExternalAnnotManager)m_impl, (TRN_UString)xfdf_content.mp_impl));
}

inline UString ExternalAnnotManager::Undo()
{
	UString result;
	REX(TRN_ExternalAnnotManagerUndo((TRN_ExternalAnnotManager)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString ExternalAnnotManager::GetLastXFDF() const
{
	UString result;
	REX(TRN_ExternalAnnotManagerGetLastXFDF((TRN_ExternalAnnotManager)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString ExternalAnnotManager::GetLastJSON() const
{
	UString result;
	REX(TRN_ExternalAnnotManagerGetLastXFDF((TRN_ExternalAnnotManager)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString ExternalAnnotManager::Redo()
{
	UString result;
	REX(TRN_ExternalAnnotManagerRedo((TRN_ExternalAnnotManager)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString ExternalAnnotManager::GetNextRedoInfo()
{
	UString result;
	REX(TRN_ExternalAnnotManagerGetNextRedoInfo((TRN_ExternalAnnotManager)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString ExternalAnnotManager::GetNextUndoInfo()
{
	UString result;
	REX(TRN_ExternalAnnotManagerGetNextUndoInfo((TRN_ExternalAnnotManager)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString ExternalAnnotManager::TakeSnapshot(UString payload)
{
	UString result;
	REX(TRN_ExternalAnnotManagerTakeSnapshot((TRN_ExternalAnnotManager)m_impl, (TRN_UString)payload.mp_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

