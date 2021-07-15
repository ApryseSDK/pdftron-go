
inline FilterWriter::FilterWriter ()
{
	REX(TRN_FilterWriterCreate(0, &m_impl));
}

inline FilterWriter::FilterWriter (Filter& filter)
{
	REX(TRN_FilterWriterCreate(filter.m_impl, &m_impl));
}

inline FilterWriter::~FilterWriter ()
{
	DREX(m_impl, TRN_FilterWriterDestroy(m_impl));
}

inline void FilterWriter::WriteUChar(UChar ch)
{
	REX(TRN_FilterWriterWriteUChar(m_impl,ch));
}

inline void FilterWriter::WriteInt(Int16 num)
{
	REX(TRN_FilterWriterWriteInt16(m_impl,num));
}

inline void FilterWriter::WriteInt(UInt16 num)
{
	REX(TRN_FilterWriterWriteUInt16(m_impl,num));
}

inline void FilterWriter::WriteInt(Int32 num)
{
	REX(TRN_FilterWriterWriteInt32(m_impl,num));
}

inline void FilterWriter::WriteInt(UInt32 num)
{
	REX(TRN_FilterWriterWriteUInt32(m_impl,num));
}

inline void FilterWriter::WriteInt(Int64 num)
{
	REX(TRN_FilterWriterWriteInt64(m_impl,num));
}

inline void FilterWriter::WriteInt(UInt64 num)
{
	REX(TRN_FilterWriterWriteUInt64(m_impl,num));
}

inline void FilterWriter::WriteString(const std::string& str)
{
	REX(TRN_FilterWriterWriteString(m_impl,str.c_str()));
}

inline void FilterWriter::WriteString(const char* str)
{
	REX(TRN_FilterWriterWriteString(m_impl,str));
}

inline void FilterWriter::WriteFilter(FilterReader& reader)
{
	REX(TRN_FilterWriterWriteFilter(m_impl,reader.m_impl));
}

inline void FilterWriter::WriteLine(const char* line, char eol)
{
	REX(TRN_FilterWriterWriteLine(m_impl,line,eol));
}

inline size_t FilterWriter::WriteBuffer(std::vector<unsigned char> buf)
{
	size_t result;
	REX(TRN_FilterWriterWriteBuffer(m_impl,(const char*)&(buf[0]),buf.size(),&result));
	return result;
}

#ifndef SWIG
inline size_t FilterWriter::WriteBuffer(const char* buf, size_t buf_size)
{
	size_t result;
	REX(TRN_FilterWriterWriteBuffer(m_impl,buf,buf_size,&result));
	return result;
}
#endif

inline void FilterWriter::AttachFilter(Filter& filter)
{
	REX(TRN_FilterWriterAttachFilter(m_impl,filter.m_impl));
}

inline Filter FilterWriter::GetAttachedFilter()
{
	TRN_Filter result;
	REX(TRN_FilterWriterGetAttachedFilter(m_impl,&result));
	return Filter(result,false);
}

inline void FilterWriter::Seek(ptrdiff_t offset, Filter::ReferencePos origin)
{
	REX(TRN_FilterWriterSeek(m_impl,offset,(enum TRN_FilterReferencePos)origin));
}

inline ptrdiff_t FilterWriter::Tell ()
{
	ptrdiff_t result;
	REX(TRN_FilterWriterTell(m_impl,&result));
	return result;
}

inline size_t FilterWriter::Count ()
{
	size_t result;
	REX(TRN_FilterWriterCount(m_impl,&result));
	return result;
}

inline void FilterWriter::Flush ()
{
	REX(TRN_FilterWriterFlush(m_impl));
}

inline void FilterWriter::FlushAll ()
{
	REX(TRN_FilterWriterFlushAll(m_impl));
}

