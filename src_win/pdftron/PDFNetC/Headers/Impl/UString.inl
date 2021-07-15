
inline UString::UString()
{ REX(TRN_UStringCreate(&mp_impl))}

inline UString::UString(const UString& str)
{ REX(TRN_UStringCopy(str.mp_impl,&mp_impl))}

inline UString::UString(Unicode value)
{ REX(TRN_UStringCreateFromCharacter((TRN_Unicode)value,&mp_impl)) }

inline UString::UString(const Unicode* value)
{ REX(TRN_UStringCreateFromString((TRN_Unicode*)value,&mp_impl)) }

inline UString::UString(const Unicode* value, int length)
{ REX(TRN_UStringCreateFromSubstring((TRN_Unicode*)value,length,&mp_impl)) }

inline UString::UString(const char* buf, int buf_sz, TextEncoding enc)
{ REX(TRN_UStringCreateFromCharString(buf,buf_sz,(TRN_UStringTextEncoding)enc,&mp_impl))}

inline UString::UString(const std::string & str, TextEncoding enc )
{ 
	REX(TRN_UStringCreateFromCharString( str.data(), (int)str.size(), (TRN_UStringTextEncoding)enc, &mp_impl) );
}

inline UString::UString( const std::wstring& value )
{
	// get around MSVC warning C4127 about constant conditionals
	const bool has_2_byte_char = sizeof(std::wstring::value_type)==2;
	const bool has_4_byte_char = sizeof(std::wstring::value_type)==4;
	if( has_2_byte_char ) {
		REX(TRN_UStringCreateFromSubstring((const TRN_Unicode*)(value.data()),(int)value.size(),&mp_impl));
	}
	else if( has_4_byte_char ) {
		REX(TRN_UStringCreateFromUtf32String( (const TRN_UInt32*)(value.data()), (int)value.size(), &mp_impl));
	}
}

inline UString::~UString() 
{ 
	DREX(mp_impl, TRN_UStringDestroy(mp_impl))
}

inline UString& UString::operator=(const UString& str)
{ return Assign(str); }

inline UString& UString::operator=(const char* ascii_str)
{ return Assign2(ascii_str); }

inline UString& UString::Assign(const UString& uni) {
	REX(TRN_UStringAssignUString(mp_impl,uni.mp_impl));
	return *this;
}

inline UString& UString::Assign(const Unicode* uni, int buf_sz) {
	REX(TRN_UStringAssignString(mp_impl,(const TRN_Unicode*)uni,buf_sz));
	return *this;
}

inline UString& UString::Assign2(const char* buf, int buf_sz, TextEncoding enc) {
	REX(TRN_UStringAssignAscii(mp_impl,buf,buf_sz,(TRN_UStringTextEncoding)enc));
	return *this;
}

inline UString& UString::operator+=(const UString& str) {
	REX(TRN_UStringAssignConcat(mp_impl, str.mp_impl));
	return *this;
}

inline UString UString::Concat(const UString &str) const {
	UString result;
	REX(TRN_UStringConcat(mp_impl, str.mp_impl, result.mp_impl));
	return result;
}

inline int UString::GetLength() const {
	int result;
	REX(TRN_UStringGetLength(mp_impl,&result));
	return result;
}

inline bool UString::Empty() const {
	TRN_Bool result;
	REX(TRN_UStringIsEmpty(mp_impl,&result));
	return TBToB(result);
}

inline const Unicode* UString::GetBuffer() const {
	const TRN_Unicode* result;
	REX(TRN_UStringGetBuffer(mp_impl,&result));
	return (Unicode*)result;
}

inline int UString::Compare(const UString& str, int max_length) const {
	int result;
	REX(TRN_UStringCompare(mp_impl,str.mp_impl,max_length,&result));
	return result;
}

inline UString UString::SubStr(int off, int count) const {
	UString result;
	REX(TRN_UStringSubStr(mp_impl,off,count,&(result.mp_impl)));
	return result;
}

inline Unicode UString::GetAt(int idx) const {
	TRN_Unicode result;
	REX(TRN_UStringGetAt(mp_impl,idx,&result));
	return (Unicode)result;
}

inline void UString::PushBack(Unicode ch) 
{ REX(TRN_UStringPushBack(mp_impl,ch)); }

inline void UString::Resize(int count, Unicode ch)
{ REX(TRN_UStringResize(mp_impl,count,ch)); }

inline void UString::ToUpper()
{ REX(TRN_UStringToUpper(mp_impl)); }

inline void UString::ToLower()
{ REX(TRN_UStringToLower(mp_impl)); }

inline void UString::Reserve(int count)
{ REX(TRN_UStringReserve(mp_impl,count));	}

inline const Unicode* UString::CStr() const { 
	const TRN_Unicode* result;
	REX(TRN_UStringCStr(mp_impl,&result));
	return (Unicode*)result;
}

inline bool UString::IsInAscii() const {
	TRN_Bool result;
	REX(TRN_UStringIsInAscii(mp_impl,&result));
	return TBToB(result);
}

inline int UString::ConvertToAscii(char* in_out_buf, int buf_sz, bool null_term) const {
	int result;
	REX(TRN_UStringConvertToAscii(mp_impl,in_out_buf,buf_sz,null_term,&result));
	return result;
}

inline std::string UString::ConvertToAscii() const 
{
	std::string s;
	int sz = this->ConvertToAscii(0, 0, false);
	if ( sz > 0 ) 
	{ 
		s.resize(sz);
		this->ConvertToAscii(&s[0], sz, false);			
	}
	return s;  
}

inline int UString::ConvertToUtf8(char* in_out_buf, int buf_sz, bool null_term) const {
	int result;
	REX(TRN_UStringConvertToUtf8(mp_impl,in_out_buf,buf_sz,null_term,&result));
	return result;
}

inline std::string UString::ConvertToUtf8() const {
	std::string s;
	int sz = this->ConvertToUtf8(0, 0, false);
	if ( sz > 0 ) 
	{ 
		s.resize(sz);
		this->ConvertToUtf8(&s[0], sz, false);			
	}
	return s;  
}

inline int UString::ConvertToUtf32( UInt32* out_buf, int buf_sz, bool null_term ) const
{
	int result;
	REX(TRN_UStringConvertToUtf32(mp_impl,out_buf,buf_sz,null_term,&result));
	return result;
}

inline std::wstring UString::ConvertToNativeWString() const
{
	// get around MSVC warning C4127 about constant conditionals
	const bool has_2_byte_char = sizeof(std::wstring::value_type)==2;
	const bool has_4_byte_char = sizeof(std::wstring::value_type)==4;
	if(has_2_byte_char) 
	{
		return std::wstring( this->GetBuffer(), this->GetBuffer() + this->GetLength() );
	} 
#if !(_MSC_VER == 1200) 
	else if( has_4_byte_char ) 
	{
		std::basic_string<UInt32> s = this->ConvertToUtf32();
		if(s.size() > 0)
		{
			const std::wstring::value_type* begin = (const std::wstring::value_type*)&s[0];
			const std::wstring::value_type* end = (const std::wstring::value_type*)(&s[s.size() - 1] + 1);
			return std::wstring(begin, end);
		}
		return std::wstring();
	}
#endif
}

inline std::basic_string<UInt32> UString::ConvertToUtf32() const
{
	int sz = this->ConvertToUtf32(0, 0, false);
	std::basic_string<UInt32> s;
	if ( sz > 0 ) 
	{ 
		s.resize(sz);
		this->ConvertToUtf32(&s[0], sz, false);			
	}
	return s; 
}

inline int UString::ConvertToPDFText(char* in_out_buf, int buf_sz, bool force_unicode) const {
	int result;
	REX(TRN_UStringConvertToPDFText(mp_impl,in_out_buf,buf_sz,force_unicode,&result));
	return result;
}

inline UString::UString(TRN_UString impl) : mp_impl(impl) {
}

