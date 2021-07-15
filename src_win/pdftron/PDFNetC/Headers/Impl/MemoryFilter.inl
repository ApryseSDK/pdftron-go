
inline MemoryFilter::MemoryFilter(size_t buf_sz, bool is_input) {
	REX(TRN_FilterCreateMemoryFilter(buf_sz, is_input, &m_impl));
	m_owner=true;
}

inline UChar* MemoryFilter::GetBuffer() {
	TRN_UChar* result;
	REX(TRN_FilterMemoryFilterGetBuffer(m_impl, &result));
	return result;
}

inline void MemoryFilter::SetAsInputFilter() {
	REX(TRN_FilterMemoryFilterSetAsInputFilter(m_impl));
}

