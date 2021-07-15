inline void ReflowProcessor::Initialize()
{
	REX(TRN_ReflowProcessorInitialize());
}

inline bool ReflowProcessor::IsInitialized()
{
	RetBool(TRN_ReflowProcessorIsInitialized(&result));
}

inline void ReflowProcessor::GetReflow(const Page & page, JobRequest::ProcHandler proc, void * custom_data)
{
	REX(TRN_ReflowProcessorGetReflow(page.mp_page, (TRN_ProcHandler)proc, custom_data));
}

inline void ReflowProcessor::CancelAllRequests()
{
	REX(TRN_ReflowProcessorCancelAllRequests());
}

inline void ReflowProcessor::CancelRequest(const Page & page)
{
	REX(TRN_ReflowProcessorCancelRequest(page.mp_page));
}

inline void ReflowProcessor::ClearCache()
{
	REX(TRN_ReflowProcessorClearCache());
}

inline void ReflowProcessor::SetNoReflowContent(const UString& content)
{
	REX(TRN_SetNoReflowContent(content.mp_impl));
}

inline void ReflowProcessor::SetReflowFailedContent(const UString& content)
{
	REX(TRN_SetReflowFailedContent(content.mp_impl));
}
