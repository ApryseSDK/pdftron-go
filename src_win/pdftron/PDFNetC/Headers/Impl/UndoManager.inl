inline UndoManager::~UndoManager()
{
	Destroy();
}

inline UndoManager::UndoManager(const UndoManager& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void UndoManager::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_UndoManagerDestroy(m_impl));
		m_owner = false;
	}
}

inline UndoManager& pdftron::SDF::UndoManager::operator= (const UndoManager& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

#ifdef SWIG
inline UndoManager::UndoManager()
	: m_impl(0)
	, m_owner(false)
{}
#endif

inline UndoManager::UndoManager(TRN_UndoManager impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline DocSnapshot UndoManager::DiscardAllSnapshots()
{
	DocSnapshot result;
	REX(TRN_UndoManagerDiscardAllSnapshots((TRN_UndoManager)m_impl, (TRN_DocSnapshot*)&result.m_impl));
	return result;
}

inline ResultSnapshot UndoManager::Undo()
{
	ResultSnapshot result;
	REX(TRN_UndoManagerUndo((TRN_UndoManager)m_impl, (TRN_ResultSnapshot*)&result.m_impl));
	return result;
}

inline bool UndoManager::CanUndo() const
{
	TRN_Bool result = 0;
	REX(TRN_UndoManagerCanUndo((TRN_UndoManager)m_impl, &result));
	return result != 0;
}

inline DocSnapshot UndoManager::GetNextUndoSnapshot() const
{
	DocSnapshot result;
	REX(TRN_UndoManagerGetNextUndoSnapshot((TRN_UndoManager)m_impl, (TRN_DocSnapshot*)&result.m_impl));
	return result;
}

inline ResultSnapshot UndoManager::Redo()
{
	ResultSnapshot result;
	REX(TRN_UndoManagerRedo((TRN_UndoManager)m_impl, (TRN_ResultSnapshot*)&result.m_impl));
	return result;
}

inline bool UndoManager::CanRedo() const
{
	TRN_Bool result = 0;
	REX(TRN_UndoManagerCanRedo((TRN_UndoManager)m_impl, &result));
	return result != 0;
}

inline DocSnapshot UndoManager::GetNextRedoSnapshot() const
{
	DocSnapshot result;
	REX(TRN_UndoManagerGetNextRedoSnapshot((TRN_UndoManager)m_impl, (TRN_DocSnapshot*)&result.m_impl));
	return result;
}

inline ResultSnapshot UndoManager::TakeSnapshot()
{
	ResultSnapshot result;
	REX(TRN_UndoManagerTakeSnapshot((TRN_UndoManager)m_impl, (TRN_ResultSnapshot*)&result.m_impl));
	return result;
}

