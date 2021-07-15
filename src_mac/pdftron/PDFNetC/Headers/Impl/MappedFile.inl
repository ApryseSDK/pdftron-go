
inline MappedFile::MappedFile (const UString& filename)
{
	REX(TRN_FilterCreateMappedFileFromUString(filename.mp_impl, &m_impl));
	m_owner=true;
}

inline bool MappedFile::operator == (const MappedFile& f) const
{
	TRN_Bool result;
	REX(TRN_FilterMappedFileCompare(m_impl,f.m_impl,&result));
	return TBToB(result);
}

inline bool MappedFile::Equivalent( const UString& ph1, const UString& ph2)
{
	TRN_Bool result;
	REX(TRN_PathCompare(ph1.mp_impl,ph2.mp_impl,&result));
	return TBToB(result);
}

inline size_t MappedFile::FileSize()
{
	size_t result;
	REX(TRN_FilterMappedFileFileSize(m_impl,&result));
	return result;
}

