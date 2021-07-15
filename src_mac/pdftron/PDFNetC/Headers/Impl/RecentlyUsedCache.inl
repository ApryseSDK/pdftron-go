inline void RecentlyUsedCache::RemoveDocument(const UString& document_path)
{
	REX(TRN_RecentlyUsedCacheRemoveDocument((TRN_UString)document_path.mp_impl));
}

inline void RecentlyUsedCache::AccessDocument(const UString& document_path)
{
	REX(TRN_RecentlyUsedCacheAccessDocument((TRN_UString)document_path.mp_impl));
}

inline UString RecentlyUsedCache::GetBitmapPathIfExists(const UString& document_path)
{
	RetStr(TRN_RecentlyUsedCacheGetBitmapPathIfExists((TRN_UString)document_path.mp_impl, &result));
}

inline void RecentlyUsedCache::ResetCache()
{
	REX(TRN_RecentlyUsedCacheResetCache());
}

inline void RecentlyUsedCache::InitializeRecentlyUsedCache(size_t num_documents, size_t max_absolute_space, double max_percentage_space)
{
	REX(TRN_RecentlyUsedCacheInitializeRecentlyUsedCache(num_documents, max_absolute_space, max_percentage_space));
}