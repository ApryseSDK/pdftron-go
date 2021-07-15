
inline PageLabel::PageLabel(const TRN_PageLabel& l) : TRN_PageLabel(l)
{
}

inline PageLabel PageLabel::Create(SDF::SDFDoc& doc, Style style, const UString& prefix, int start_at)
{
	TRN_PageLabel result;
	REX(TRN_PageLabelCreate(doc.mp_doc,(enum TRN_PageLabelStyle)style,prefix.mp_impl,start_at,&result));
	return result;
}

inline PageLabel::PageLabel(SDF::Obj l, int first_page, int last_page)
{
	REX(TRN_PageLabelCreateFromObj(l.mp_obj,first_page,last_page, this));
}

inline PageLabel::PageLabel (const PageLabel& d)
{
	REX(TRN_PageLabelAssign(this, &d));
}

inline PageLabel& PageLabel::operator=(const PageLabel& d)
{
	REX(TRN_PageLabelAssign(this, &d));
	return *this;
}

inline bool PageLabel::operator==(const PageLabel& d)
{
	RetBool(TRN_PageLabelCompare(this, &d, &result));
}

inline bool PageLabel::IsValid() const
{
	RetBool(TRN_PageLabelIsValid(this, &result));
}

inline UString PageLabel::GetLabelTitle(int page_num)
{
	RetStr(TRN_PageLabelGetLabelTitle(this,page_num,&result));
}

inline void PageLabel::SetStyle(Style style)
{
	REX(TRN_PageLabelSetStyle(this,(enum TRN_PageLabelStyle)style))
}

inline PageLabel::Style PageLabel::GetStyle() const
{
	enum TRN_PageLabelStyle result;
	REX(TRN_PageLabelGetStyle(this,&result));
	return (PageLabel::Style)result;
}

inline UString PageLabel::GetPrefix() const
{
	RetStr(TRN_PageLabelGetPrefix(this,&result));
}

inline void PageLabel::SetPrefix(const UString& prefix)
{
	REX(TRN_PageLabelSetPrefix(this,prefix.mp_impl));
}

inline int PageLabel::GetStart() const
{
	RetInt(TRN_PageLabelGetStart(this,&result));
}

inline void PageLabel::SetStart(int start_at)
{
	REX(TRN_PageLabelSetStart(this,start_at));
}

inline int PageLabel::GetFirstPageNum()
{
	RetInt(TRN_PageLabelGetFirstPageNum(this,&result));
}

inline int PageLabel::GetLastPageNum()
{
	RetInt(TRN_PageLabelGetLastPageNum(this,&result));
}

inline SDF::Obj PageLabel::GetSDFObj () const
{
	RetObj(TRN_PageLabelGetSDFObj(this,&result));
}

