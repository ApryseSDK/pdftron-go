inline void DocumentPreviewCache::Initialize(UInt64 max_cache_bytes, double max_disk_percentage)
{
	REX(TRN_DocumentPreviewCacheInitialize(max_cache_bytes, max_disk_percentage));
}

inline void DocumentPreviewCache::GetBitmapWithPath(const UString& filepath, UInt32 min_x_size, UInt32 min_y_size, PreviewHandler proc, void* custom_data)
{
	REX(TRN_DocumentPreviewCacheGetBitmapWithPath((TRN_UString)filepath.mp_impl, min_x_size, min_y_size, (TRN_PreviewHandler)proc, custom_data));
}

inline void DocumentPreviewCache::CancelAllRequests()
{
	REX(TRN_DocumentPreviewCacheCancelAllRequests());
}

inline void DocumentPreviewCache::CancelRequest(const UString& filepath)
{
	REX(TRN_DocumentPreviewCacheCancelRequest((TRN_UString)filepath.mp_impl));
}

inline void DocumentPreviewCache::IrrelevantChangeMade(const UString& filepath)
{
	REX(TRN_DocumentPreviewCacheIrrelevantChangeMade((TRN_UString)filepath.mp_impl));
}

inline void DocumentPreviewCache::ClearCache()
{
	REX(TRN_DocumentPreviewCacheClearCache());
}
