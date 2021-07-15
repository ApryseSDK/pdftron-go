// @cond PRIVATE_DOC
// Implementation detail ---------------------------------------

inline Exception::Exception(TRN_Exception e)
{
	this->e=e;
}

inline const char* Exception::GetCondExpr()
{
	return TRN_GetCondExpr(this->e);
}

inline const char* Exception::GetFileName()
{
	return TRN_GetFileName(e);
}
inline const char* Exception::GetFunction()
{
	return TRN_GetFunction(e);
}

inline const char* Exception::GetMessage()
{
	return TRN_GetMessage(e);
}

inline TRN_Int32 Exception::GetLineNumber()
{
	return TRN_GetLineNum(e);
}
inline TRN_UInt32 Exception::GetErrorCode()
{
	return TRN_GetErrorCode(e);
}

inline const char* Exception::what() const throw()
{
	return TRN_GetFullMessage(e);
}

inline Exception::Exception(const char* cond_expr, TRN_Int32 line_number, const char* file_name,
							const char* function, const char* message, TRN_UInt32 error_code)
{
	e=TRN_CreateExceptionEx(cond_expr,file_name,line_number,function,message,error_code);
}

inline std::string Exception::ToString() 
{
	return std::string(TRN_GetFullMessage(e));
}

inline std::ostream& Exception::Print(std::ostream& stream)
{
	return stream << ToString();
}

/**
 * Runtime assertion macro 
 */
#ifdef _WIN32	
	#if (_MSC_VER < 1300)
		// VC6 does not support __FUNCTION__ macro
		#define PDFNET_USE_NO_FUNCTION_MACRO	
	#endif
#endif	

#ifdef PDFNET_USE_NO_FUNCTION_MACRO	
	#define BASE_ASSERT(condition, msg)	if (!(condition)) throw Common::Exception((#condition), __LINE__, __FILE__, "",	msg)
	#define BASE_ASSERTEX(condition, msg,er)	if (!(condition)) throw Common::Exception((#condition), __LINE__, __FILE__, "",	msg, er)
	#define BASE_ASSERT2(condition, derived,  msg) if (!(condition)) throw derived((#condition), __LINE__, __FILE__, "", msg)
	#define BASE_WARNING(condition, msg) if (!(condition)) Common::ReportWarning((#condition), __LINE__, __FILE__, "", msg)
#else
	#define BASE_ASSERT(condition, msg) if (!(condition)) throw Common::Exception((#condition), __LINE__, __FILE__, __FUNCTION__, msg)
	#define BASE_ASSERTEX(condition, msg, er) if (!(condition)) throw Common::Exception((#condition), __LINE__, __FILE__, __FUNCTION__, msg, er)
	#define BASE_ASSERT2(condition, derived, msg) if (!(condition)) throw derived((#condition), __LINE__, __FILE__, __FUNCTION__, msg)
	#define BASE_WARNING(condition, msg) if (!(condition)) Common::ReportWarning((#condition), __LINE__, __FILE__, __FUNCTION__, msg)
#endif

// @endcond
