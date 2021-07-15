inline bool WebFontDownloader::IsAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_WebFontDownloaderIsAvailable(&result));
	return result != 0;
}

inline void WebFontDownloader::EnableDownloads()
{
	REX(TRN_WebFontDownloaderEnableDownloads());
}

inline void WebFontDownloader::DisableDownloads()
{
	REX(TRN_WebFontDownloaderDisableDownloads());
}

inline void WebFontDownloader::PreCacheAsync()
{
	REX(TRN_WebFontDownloaderPreCacheAsync());
}

inline void WebFontDownloader::ClearCache()
{
	REX(TRN_WebFontDownloaderClearCache());
}

inline void WebFontDownloader::SetCustomWebFontURL(UString url)
{
	REX(TRN_WebFontDownloaderSetCustomWebFontURL((TRN_UString)url.mp_impl));
}

