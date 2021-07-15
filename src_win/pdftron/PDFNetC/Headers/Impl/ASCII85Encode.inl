
inline ASCII85Encode::ASCII85Encode(Filter input_filter, int line_width, size_t buf_sz) 
{
	input_filter.m_owner=false;
	REX(TRN_FilterCreateASCII85Encode(input_filter.m_impl, line_width, buf_sz, &m_impl));
	// Note: Transfer the ownership
	m_owner = true;
}

