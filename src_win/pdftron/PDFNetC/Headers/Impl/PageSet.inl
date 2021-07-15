inline PageSet::PageSet( )
{
	REX( TRN_PageSetCreate(&mp_impl) );
}

inline PageSet::PageSet( int one_page )
{
	REX(TRN_PageSetCreateSinglePage(one_page, &mp_impl));
}  

inline PageSet::PageSet( int range_start, int range_end, Filter filter )
{
	REX(TRN_PageSetCreateFilteredRange(range_start, range_end, (TRN_PageSetFilter)filter, &mp_impl));
}

inline PageSet::PageSet(TRN_PageSet impl) : mp_impl(impl)
{
}

inline PageSet::~PageSet()
{
	DREX(mp_impl, TRN_PageSetDestroy(mp_impl));
}

inline void PageSet::Destroy()
{
	REX( TRN_PageSetDestroy(mp_impl) );
	mp_impl = 0;
}

inline void PageSet::AddPage( int one_page )
{
	REX( TRN_PageSetAddPage(mp_impl, one_page) );
}

inline void PageSet::AddRange( int range_start, int range_end, Filter filter )
{
	REX(TRN_PageSetAddRange(mp_impl, range_start, range_end, (TRN_PageSetFilter)filter));
}

