
inline UString PDFDocInfo::GetTitle()
{
	TRN_UString result;
	REX(TRN_PDFDocInfoGetTitle(mp_info,&result));
	return UString(result);
}

inline SDF::Obj PDFDocInfo::GetTitleObj()
{
	TRN_Obj result;
	REX(TRN_PDFDocInfoGetTitleObj(mp_info,&result))
	return SDF::Obj(result);
}

inline void PDFDocInfo::SetTitle(const UString& title)
{
	REX(TRN_PDFDocInfoSetTitle(mp_info, title.mp_impl));
}

inline UString PDFDocInfo::GetAuthor()
{
	TRN_UString result;
	REX(TRN_PDFDocInfoGetAuthor(mp_info, &result));
	return UString(result);
}

inline SDF::Obj PDFDocInfo::GetAuthorObj()
{
	TRN_Obj result;
	REX(TRN_PDFDocInfoGetAuthorObj(mp_info, &result));
	return SDF::Obj(result);
}

inline void PDFDocInfo::SetAuthor(const UString& author)
{
	REX(TRN_PDFDocInfoSetAuthor(mp_info, author.mp_impl));
}

inline UString PDFDocInfo::GetSubject()
{
	TRN_UString result;
	REX(TRN_PDFDocInfoGetSubject(mp_info, &result));
	return UString(result);
}

inline SDF::Obj PDFDocInfo::GetSubjectObj()
{
	TRN_Obj result;
	REX(TRN_PDFDocInfoGetSubjectObj(mp_info, &result));
	return SDF::Obj(result);
}

inline void PDFDocInfo::SetSubject(const UString& subject)
{
	REX(TRN_PDFDocInfoSetSubject(mp_info, subject.mp_impl));
}

inline UString PDFDocInfo::GetKeywords()
{
	TRN_UString result;
	REX(TRN_PDFDocInfoGetKeywords(mp_info, &result));
	return UString(result);
}

inline SDF::Obj PDFDocInfo::GetKeywordsObj()
{
	TRN_Obj result;
	REX(TRN_PDFDocInfoGetKeywordsObj(mp_info, &result));
	return SDF::Obj(result);
}

inline void PDFDocInfo::SetKeywords(const UString& keywords)
{
	REX(TRN_PDFDocInfoSetKeywords(mp_info, keywords.mp_impl));
}

inline UString PDFDocInfo::GetCreator()
{
	TRN_UString result;
	REX(TRN_PDFDocInfoGetCreator(mp_info, &result));
	return UString(result);
}

inline SDF::Obj PDFDocInfo::GetCreatorObj()
{
	TRN_Obj result;
	REX(TRN_PDFDocInfoGetCreatorObj(mp_info, &result));
	return SDF::Obj(result);
}

inline void PDFDocInfo::SetCreator(const UString& creator)
{
	REX(TRN_PDFDocInfoSetCreator(mp_info, creator.mp_impl));
}

inline UString PDFDocInfo::GetProducer()
{
	TRN_UString result;
	REX(TRN_PDFDocInfoGetProducer(mp_info, &result));
	return UString(result);
}

inline SDF::Obj PDFDocInfo::GetProducerObj()
{
	TRN_Obj result;
	REX(TRN_PDFDocInfoGetProducerObj(mp_info, &result));
	return SDF::Obj(result);
}

inline void PDFDocInfo::SetProducer(const UString& producer)
{
	REX(TRN_PDFDocInfoSetProducer(mp_info, producer.mp_impl));
}

inline Date PDFDocInfo::GetCreationDate()
{
	TRN_Date result;
	REX(TRN_PDFDocInfoGetCreationDate(mp_info, &result));
	return *((Date*)&result);
}

inline void PDFDocInfo::SetCreationDate(const Date& creation_date)
{
	REX(TRN_PDFDocInfoSetCreationDate(mp_info,(const TRN_Date*)&creation_date));
}

inline Date PDFDocInfo::GetModDate()
{
	TRN_Date result;
	REX(TRN_PDFDocInfoGetModDate(mp_info, &result));
	return *((Date*)&result);
}

inline void PDFDocInfo::SetModDate(const Date& mod_date)
{
	REX(TRN_PDFDocInfoSetModDate(mp_info,(const TRN_Date*)&mod_date));
}

inline SDF::Obj PDFDocInfo::GetSDFObj()
{
	TRN_Obj result;
	REX(TRN_PDFDocInfoGetSDFObj(mp_info,&result));
	return SDF::Obj(result);
}

inline PDFDocInfo::PDFDocInfo (SDF::Obj tr)
{
	REX(TRN_PDFDocInfoCreate(tr.mp_obj,&mp_info))
}

inline PDFDocInfo::PDFDocInfo (const PDFDocInfo& c)
{
	REX(TRN_PDFDocInfoCopy(c.mp_info,&mp_info));
}

inline PDFDocInfo& PDFDocInfo::operator= (const PDFDocInfo& c)
{
	REX(TRN_PDFDocInfoCopy(c.mp_info,&mp_info));
	return *this;
}

inline PDFDocInfo::PDFDocInfo (TRN_PDFDocInfo impl) : mp_info(impl)
{
}

inline PDFDocInfo::PDFDocInfo () : mp_info(0)
{
}

