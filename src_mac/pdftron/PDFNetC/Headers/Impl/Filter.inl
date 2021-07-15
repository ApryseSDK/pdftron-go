
inline Filter::Filter() : m_impl(0), m_owner(true) {}

inline Filter::Filter(TRN_Filter impl, bool is_owner) {
	m_impl=impl;
	m_owner=is_owner;
}

inline Filter::Filter(const Filter& copy) 
{
	if(copy.m_owner) {
		((Filter&)copy).m_owner = false;
		m_owner=true;
	}
	else {
		m_owner=false;
	}

	m_impl=copy.m_impl;
}

inline Filter& Filter::operator =(const Filter& other) 
{
	if(m_owner) { 
		REX(TRN_FilterDestroy(m_impl));
		m_impl=0;
	}

	if(other.m_owner) {
		((Filter&)other).m_owner = false;
		m_owner=true;
	}
	else {
		m_owner=false;
	}

	m_impl=other.m_impl;
	return *this;
}

inline Filter::~Filter () 
{
	if(m_owner) {
		DREX(m_impl, TRN_FilterDestroy(m_impl));
	}
}

inline void Filter::Destroy() {
	if(m_owner) {
		REX(TRN_FilterDestroy(m_impl));
		m_impl=0;
	}
}

inline void Filter::AttachFilter(Filter attach_filter) {
	REX(TRN_FilterAttachFilter(m_impl,(TRN_Filter)(attach_filter.m_impl)));
	attach_filter.m_owner=false;
}

inline Filter Filter::ReleaseAttachedFilter () {
	TRN_Filter result;
	REX(TRN_FilterReleaseAttachedFilter(m_impl,&result));
	return Filter(result,true);
}

inline Filter Filter::GetAttachedFilter () {
	TRN_Filter result;
	REX(TRN_FilterGetAttachedFilter(m_impl,&result));
	return Filter(result, false);
}

inline Filter Filter::GetSourceFilter () {
	TRN_Filter result;
	REX(TRN_FilterGetSourceFilter(m_impl,&result));
	return Filter(result, false);
}

inline const char* Filter::GetName () const {
	const char* result;
	REX(TRN_FilterGetName(m_impl,&result));
	return result;
}

inline const char* Filter::GetDecodeName () const { 
	const char* result;
	REX(TRN_FilterGetDecodeName(m_impl,&result));
	return result;
}

#ifndef SWIG
inline UChar* Filter::Begin () {
	TRN_UChar* result;
	REX(TRN_FilterBegin(m_impl,&result));
	return (UChar*)result;
}
#endif

inline size_t Filter::Size () {
	size_t result;
	REX(TRN_FilterSize(m_impl,&result));
	return result;
}

inline void Filter::Consume (size_t num_bytes) {
	REX(TRN_FilterConsume(m_impl,num_bytes));
}

inline size_t Filter::Count () {
	size_t result;
	REX(TRN_FilterCount(m_impl,&result));
	return result;
}

inline size_t Filter::SetCount (size_t new_count) {
	size_t result;
	REX(TRN_FilterSetCount(m_impl,new_count,&result));
	return result;
}

inline void Filter::SetStreamLength (size_t bytes) {
	REX(TRN_FilterSetStreamLength(m_impl,bytes));
}

inline void Filter::Flush () {
	REX(TRN_FilterFlush(m_impl));
}

inline void Filter::FlushAll () {
	REX(TRN_FilterFlushAll(m_impl));
}

inline bool Filter::IsInputFilter () {
	TRN_Bool result;
	REX(TRN_FilterIsInputFilter(m_impl,&result));
	return TBToB(result);
}

inline bool Filter::CanSeek () {
	TRN_Bool result;
	REX(TRN_FilterCanSeek(m_impl,&result));
	return TBToB(result);
}

inline void Filter::Seek (ptrdiff_t offset, ReferencePos origin) {
	REX(TRN_FilterSeek(m_impl,offset,(enum TRN_FilterReferencePos) origin));
}

inline ptrdiff_t Filter::Tell () {
	ptrdiff_t result;
	REX(TRN_FilterTell(m_impl,&result));
	return result;
}

inline Filter Filter::CreateInputIterator () {
	TRN_Filter result;
	REX(TRN_FilterCreateInputIterator(m_impl,&result));
	return Filter(result,true);
}

inline const UString Filter::GetFilePath() const {
	TRN_UString result;
	REX(TRN_FilterGetFilePath(m_impl,&result));
	UString temp;
	temp.mp_impl=result;
	return temp;
}

inline void Filter::WriteToFile(const UString& path, bool append) {
	REX(TRN_FilterWriteToFile(m_impl, path.mp_impl, BToTB(append)));
}

