inline bool PDFNetInternalTools::IsLogSystemAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_PDFNetInternalToolsIsLogSystemAvailable(&result));
	return result != 0;
}

inline bool PDFNetInternalTools::ConfigureLogFromJsonString(UString config_string)
{
	TRN_Bool result = 0;
	REX(TRN_PDFNetInternalToolsConfigureLogFromJsonString((TRN_UString)config_string.mp_impl, &result));
	return result != 0;
}

inline UString PDFNetInternalTools::GetDefaultConfigFile()
{
	UString result;
	REX(TRN_PDFNetInternalToolsGetDefaultConfigFile((TRN_UString*)&result.mp_impl));
	return result;
}

inline void PDFNetInternalTools::LogMessage(LogLevel threshold, UString message, UString filename, UInt32 line_number)
{
	REX(TRN_PDFNetInternalToolsLogMessage((enum TRN_PDFNetInternalTools_LogLevel) threshold, (TRN_UString)message.mp_impl, (TRN_UString)filename.mp_impl, line_number));
}

inline void PDFNetInternalTools::LogStreamMessage(LogLevel threshold, UString stream, UString message, UString filename, UInt32 line_number)
{
	REX(TRN_PDFNetInternalToolsLogStreamMessage((enum TRN_PDFNetInternalTools_LogLevel) threshold, (TRN_UString)stream.mp_impl, (TRN_UString)message.mp_impl, (TRN_UString)filename.mp_impl, line_number));
}

inline bool PDFNetInternalTools::SetLogLocation(UString log_directory, UString log_filename)
{
	TRN_Bool result = 0;
	REX(TRN_PDFNetInternalToolsSetLogLocation((TRN_UString)log_directory.mp_impl, (TRN_UString)log_filename.mp_impl, &result));
	return result != 0;
}

inline bool PDFNetInternalTools::SetLogFileName(UString log_filename)
{
	TRN_Bool result = 0;
	REX(TRN_PDFNetInternalToolsSetLogFileName((TRN_UString)log_filename.mp_impl, &result));
	return result != 0;
}

inline void PDFNetInternalTools::SetThresholdForLogStream(UString stream_name, LogLevel stream_threshold)
{
	REX(TRN_PDFNetInternalToolsSetThresholdForLogStream((TRN_UString)stream_name.mp_impl, (enum TRN_PDFNetInternalTools_LogLevel) stream_threshold));
}

inline void PDFNetInternalTools::SetDefaultLogThreshold(LogLevel threshold)
{
	REX(TRN_PDFNetInternalToolsSetDefaultLogThreshold((enum TRN_PDFNetInternalTools_LogLevel) threshold));
}

inline void PDFNetInternalTools::SetCutoffLogThreshold(LogLevel threshold)
{
	REX(TRN_PDFNetInternalToolsSetCutoffLogThreshold((enum TRN_PDFNetInternalTools_LogLevel) threshold));
}

inline bool PDFNetInternalTools::EnableLogBackend(LogBackend backend)
{
	TRN_Bool result = 0;
	REX(TRN_PDFNetInternalToolsEnableLogBackend((enum TRN_PDFNetInternalTools_LogBackend) backend, &result));
	return result != 0;
}

inline void PDFNetInternalTools::DisableLogBackend(LogBackend backend)
{
	REX(TRN_PDFNetInternalToolsDisableLogBackend((enum TRN_PDFNetInternalTools_LogBackend) backend));
}

inline UString PDFNetInternalTools::GetPDFViewTileSummary()
{
	UString result;
	REX(TRN_PDFNetInternalToolsGetPDFViewTileSummary((TRN_UString*)&result.mp_impl));
	return result;
}

