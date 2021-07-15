
inline FlateEncode::FlateEncode(Filter input_filter, int compression_level, size_t buf_sz) 
{
	input_filter.m_owner=false;
	REX(TRN_FilterCreateFlateEncode(input_filter.m_impl, compression_level, buf_sz, &m_impl));
	// Note: Transfer the ownership
	m_owner = true;
}

