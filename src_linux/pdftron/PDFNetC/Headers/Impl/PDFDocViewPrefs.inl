
inline void PDFDocViewPrefs::SetInitialPage(Destination& dest)
{
	REX(TRN_PDFDocViewPrefsSetInitialPage(mp_prefs, dest.mp_dest));
}

inline void PDFDocViewPrefs::SetPageMode(PDFDocViewPrefs::PageMode mode)
{
	REX(TRN_PDFDocViewPrefsSetPageMode(mp_prefs, (enum TRN_PDFDocViewPrefsPageMode)mode));
}

inline PDFDocViewPrefs::PageMode PDFDocViewPrefs::GetPageMode()
{
	enum TRN_PDFDocViewPrefsPageMode result;
	REX(TRN_PDFDocViewPrefsGetPageMode(mp_prefs, &result));
	return (PageMode)result;
}

inline void PDFDocViewPrefs::SetLayoutMode(PDFDocViewPrefs::PageLayout mode)
{
	REX(TRN_PDFDocViewPrefsSetLayoutMode(mp_prefs, (enum TRN_PDFDocViewPrefsPageLayout)mode));
}

inline PDFDocViewPrefs::PageLayout PDFDocViewPrefs::GetLayoutMode()
{
	enum TRN_PDFDocViewPrefsPageLayout result;
    REX(TRN_PDFDocViewPrefsGetLayoutMode(mp_prefs, &result));
	return (PageLayout)result;
}

inline void PDFDocViewPrefs::SetPref(PDFDocViewPrefs::ViewerPref pref, bool value)
{
	REX(TRN_PDFDocViewPrefsSetPref(mp_prefs, (enum TRN_PDFDocViewPrefsViewerPref)pref,BToTB(value)));
}

inline bool PDFDocViewPrefs::GetPref(PDFDocViewPrefs::ViewerPref pref)
{
	TRN_Bool result;
	REX(TRN_PDFDocViewPrefsGetPref(mp_prefs, (enum TRN_PDFDocViewPrefsViewerPref)pref,&result));
	return TBToB(result);
}

inline void PDFDocViewPrefs::SetNonFullScreenPageMode(PDFDocViewPrefs::PageMode mode)
{
	REX(TRN_PDFDocViewPrefsSetNonFullScreenPageMode(mp_prefs, (enum TRN_PDFDocViewPrefsPageMode) mode));	
}

inline PDFDocViewPrefs::PageMode PDFDocViewPrefs::GetNonFullScreenPageMode()
{
	enum TRN_PDFDocViewPrefsPageMode result;
	REX(TRN_PDFDocViewPrefsGetNonFullScreenPageMode(mp_prefs,&result));
	return (PageMode)result;
}

inline void PDFDocViewPrefs::SetDirection(bool left_to_right)
{
	REX(TRN_PDFDocViewPrefsSetDirection(mp_prefs,BToTB(left_to_right)));
}

inline bool PDFDocViewPrefs::GetDirection()
{
	TRN_Bool result;
	REX(TRN_PDFDocViewPrefsGetDirection(mp_prefs,&result));
	return TBToB(result);
}

inline void PDFDocViewPrefs::SetViewArea(Page::Box box)
{
	REX(TRN_PDFDocViewPrefsSetViewArea(mp_prefs,(enum TRN_PageBox)box));
}

inline Page::Box PDFDocViewPrefs::GetViewArea()
{
	enum TRN_PageBox result;
	REX(TRN_PDFDocViewPrefsGetViewArea(mp_prefs,&result));
	return (Page::Box)result;
}

inline void PDFDocViewPrefs::SetViewClip(Page::Box box)
{
	
	REX(TRN_PDFDocViewPrefsSetViewClip(mp_prefs, (enum TRN_PageBox)box));
	
}

inline Page::Box PDFDocViewPrefs::GetViewClip()
{
	enum TRN_PageBox result;
	REX(TRN_PDFDocViewPrefsGetViewClip(mp_prefs, &result));
	return (Page::Box)result;
}

inline void PDFDocViewPrefs::SetPrintArea(Page::Box box)
{
	REX(TRN_PDFDocViewPrefsSetPrintArea(mp_prefs, (enum TRN_PageBox)box));
}

inline Page::Box PDFDocViewPrefs::GetPrintArea()
{
	enum TRN_PageBox result;
	REX(TRN_PDFDocViewPrefsGetPrintArea(mp_prefs, &result));
	return (Page::Box)result;
}

inline void PDFDocViewPrefs::SetPrintClip(Page::Box box)
{
	
	REX(TRN_PDFDocViewPrefsSetPrintClip(mp_prefs, (enum TRN_PageBox)box));
	
}

inline Page::Box PDFDocViewPrefs::GetPrintClip()
{
	enum TRN_PageBox result;
	REX(TRN_PDFDocViewPrefsGetPrintClip(mp_prefs, &result));
	return (Page::Box)result;
}

inline SDF::Obj PDFDocViewPrefs::GetSDFObj()
{
	TRN_Obj result;
	REX(TRN_PDFDocViewPrefsGetSDFObj(mp_prefs, &result));
	return SDF::Obj(result);
}

inline PDFDocViewPrefs::PDFDocViewPrefs (SDF::Obj tr)
{
	REX(TRN_PDFDocViewPrefsCreate(tr.mp_obj,&mp_prefs));
}

inline PDFDocViewPrefs::PDFDocViewPrefs (const PDFDocViewPrefs& p)
{
	REX(TRN_PDFDocViewPrefsCopy(p.mp_prefs,&mp_prefs));
}

inline PDFDocViewPrefs& PDFDocViewPrefs::operator= (const PDFDocViewPrefs& p)
{	
	REX(TRN_PDFDocViewPrefsCopy(p.mp_prefs,&mp_prefs));
	return *this;
}

inline PDFDocViewPrefs::PDFDocViewPrefs(TRN_PDFDocViewPrefs impl) : mp_prefs(impl)
{
}

inline PDFDocViewPrefs::PDFDocViewPrefs() : mp_prefs(0)
{
}

