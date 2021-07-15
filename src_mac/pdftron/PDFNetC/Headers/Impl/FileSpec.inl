
inline FileSpec::FileSpec(TRN_FileSpec fs) : mp_impl(fs)
{
}

inline FileSpec::FileSpec() : mp_impl(0)
{
}

inline FileSpec FileSpec::Create(SDF::SDFDoc& doc, const UString& path, bool embed)
{
	TRN_FileSpec result;
	REX(TRN_FileSpecCreate(doc.mp_doc,path.mp_impl,BToTB(embed),&result));
	return FileSpec(result);
}

inline FileSpec FileSpec::CreateURL(SDF::SDFDoc& doc, const char* url)
{
	TRN_FileSpec result;
	REX(TRN_FileSpecCreateURL(doc.mp_doc,url,&result));
	return FileSpec(result);
}

inline FileSpec::FileSpec(SDF::Obj f)
{
	REX(TRN_FileSpecCreateFromObj(f.mp_obj,&mp_impl))
}

inline FileSpec::FileSpec (const FileSpec& d)
{
	REX(TRN_FileSpecCopy(d.mp_impl,&mp_impl));
}

inline FileSpec& FileSpec::operator=(const FileSpec& d)
{
	REX(TRN_FileSpecCopy(d.mp_impl,&mp_impl));
	return *this;
}

inline bool FileSpec::operator==(const FileSpec& d)
{
	TRN_Bool result;
	REX(TRN_FileSpecCompare(mp_impl,d.mp_impl,&result));
	return TBToB(result);
}

inline bool FileSpec::IsValid() const
{
	TRN_Bool result;
	REX(TRN_FileSpecIsValid(mp_impl,&result));
	return TBToB(result);
}

inline bool FileSpec::Export(const UString& save_as) const
{
	TRN_Bool result;
	REX(TRN_FileSpecExport(mp_impl,save_as.mp_impl,&result));
	return TBToB(result);
}

inline Filters::Filter FileSpec::GetFileData() const
{
	TRN_Filter result;
	REX(TRN_FileSpecGetFileData(mp_impl,&result));
	return Filters::Filter(result, true);
}

inline UString FileSpec::GetFilePath() const
{
	UString result;
	REX(TRN_FileSpecGetFilePath(mp_impl,&(result.mp_impl)));
	return result;
}

inline void FileSpec::SetDesc(const UString& desc)
{
	REX(TRN_FileSpecSetDesc(mp_impl,desc.mp_impl));
}

inline SDF::Obj FileSpec::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_FileSpecGetSDFObj(mp_impl,&result));
	return SDF::Obj(result);
}


