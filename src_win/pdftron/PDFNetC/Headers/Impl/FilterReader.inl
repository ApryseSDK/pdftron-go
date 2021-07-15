
inline FilterReader::FilterReader() 
{
	REX(TRN_FilterReaderCreate(0, &m_impl));
}

inline FilterReader::FilterReader (Filter& filter)
{
	REX(TRN_FilterReaderCreate(filter.m_impl, &m_impl));
}

inline FilterReader::~FilterReader ()
{
	DREX(m_impl, TRN_FilterReaderDestroy(m_impl));
}

inline int FilterReader::Get()
{
	int result;
	REX(TRN_FilterReaderGet(m_impl,&result));
	return result;
}

inline int FilterReader::Peek()
{
	int result;
	REX(TRN_FilterReaderPeek(m_impl,&result));
	return result;
}

inline std::vector<unsigned char> FilterReader::Read(size_t buf_size)
{
	size_t size;
	std::vector<unsigned char> result;
	result.resize(buf_size);
	REX(TRN_FilterReaderRead(m_impl, &result[0], buf_size, &size));
	result.resize(size);
	return result;
}

#ifndef SWIG
inline size_t FilterReader::Read(UChar* buf, size_t buf_size)
{
	size_t result;
	REX(TRN_FilterReaderRead(m_impl,buf,buf_size,&result));
	return result;
}
#endif

inline void FilterReader::AttachFilter(Filter& filter)
{
	REX(TRN_FilterReaderAttachFilter(m_impl, filter.m_impl));
}

inline Filter FilterReader::GetAttachedFilter()
{
	TRN_Filter result;
	REX(TRN_FilterReaderGetAttachedFilter(m_impl, &result));
	return Filter(result,false);
}

inline void FilterReader::Seek(ptrdiff_t offset, Filter::ReferencePos origin)
{
	REX(TRN_FilterReaderSeek(m_impl,offset,(enum TRN_FilterReferencePos)origin));
}

inline ptrdiff_t FilterReader::Tell ()
{
	ptrdiff_t result;
	REX(TRN_FilterReaderTell(m_impl,&result));
	return result;
}

inline size_t FilterReader::Count ()
{
	size_t result;
	REX(TRN_FilterReaderCount(m_impl, &result));
	return result;
}

inline void FilterReader::Flush ()
{
	REX(TRN_FilterReaderFlush(m_impl));
}
inline void FilterReader::FlushAll ()
{
	REX(TRN_FilterReaderFlushAll(m_impl));
}

