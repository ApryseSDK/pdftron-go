
inline FDFDoc::FDFDoc(TRN_FDFDoc impl, bool owner)
{
	if (impl) {
		mp_doc = impl;
	}
	else {
		REX(TRN_FDFDocCreate(&mp_doc));
	}
	m_owner = owner;
}

inline FDFDoc::FDFDoc(SDF::SDFDoc& sdfdoc) : m_owner(true) {
	REX(TRN_FDFDocCreateFromSDFDoc(sdfdoc.mp_doc,&mp_doc));
	sdfdoc.mp_doc=0;
}

inline FDFDoc::FDFDoc (const char* filepath) : m_owner(true) {
	REX(TRN_FDFDocCreateFromFilePath(filepath,&mp_doc));
}

inline FDFDoc::FDFDoc (const UString& filepath) : m_owner(true) {
	REX(TRN_FDFDocCreateFromUFilePath(filepath.mp_impl,&mp_doc));
}

inline FDFDoc::FDFDoc (Filters::Filter stream) : m_owner(true) {
	stream.m_owner = false;
	REX(TRN_FDFDocCreateFromStream(stream.m_impl,&mp_doc));
	// Note: FDFDoc takes the ownership of the stream
	stream.m_impl = 0; 
}

inline FDFDoc::FDFDoc (const char* buf, size_t buf_size) : m_owner(true) {
	REX(TRN_FDFDocCreateFromMemoryBuffer(buf,buf_size,&mp_doc));
}

inline FDFDoc::FDFDoc (const FDFDoc& other)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner=true;
	}
	else {
		m_owner=false;
	}

	mp_doc=other.mp_doc;
}

inline FDFDoc& FDFDoc::operator =(const FDFDoc& other) 
{
	if(m_owner) { 
		REX(TRN_FDFDocDestroy(mp_doc));
		mp_doc=0;
	}

	if(other.m_owner) {
		other.m_owner = false;
		m_owner=true;
	}
	else {
		m_owner=false;
	}

	mp_doc=other.mp_doc;
	return *this;
}

inline FDFDoc::~FDFDoc () {
	if(m_owner) { 
		DREX(mp_doc, TRN_FDFDocDestroy(mp_doc));
	}
}

inline void FDFDoc::Close () {
	if(m_owner) { 
		REX(TRN_FDFDocDestroy(mp_doc));
		mp_doc=0;
	}
}

inline bool FDFDoc::IsModified () const {
	RetBool(TRN_FDFDocIsModified(mp_doc,&result));
}

inline void FDFDoc::Save(const UString& path) {
	REX(TRN_FDFDocSave(mp_doc,path.mp_impl));
}

inline std::vector<unsigned char> FDFDoc::Save() {
	size_t size;
	char* buf;
	std::vector<unsigned char> result;
	REX(TRN_FDFDocSaveMemoryBuffer(mp_doc,(const char**)&buf,&size));
	result.resize(size);
	memcpy(&result[0], buf, size);
	return result;
}

#ifndef SWIG
inline void FDFDoc::Save(const char* &out_buf, size_t& out_buf_size) {
	REX(TRN_FDFDocSaveMemoryBuffer(mp_doc,&out_buf,&out_buf_size));
}
#endif

inline SDF::Obj FDFDoc::GetTrailer () {
	RetObj(TRN_FDFDocGetTrailer(mp_doc,&result));
}

inline SDF::Obj FDFDoc::GetRoot() {
	RetObj(TRN_FDFDocGetRoot(mp_doc,&result));
}

inline SDF::Obj FDFDoc::GetFDF() {
	RetObj(TRN_FDFDocGetFDF(mp_doc,&result));
}

inline UString FDFDoc::GetPDFFileName() {
	RetStr(TRN_FDFDocGetPDFFileName(mp_doc,&result));
}

inline void FDFDoc::SetPDFFileName(const UString& filepath) {
	REX(TRN_FDFDocSetPDFFileName(mp_doc,filepath.mp_impl));
}

inline SDF::Obj FDFDoc::GetID() {
	RetObj(TRN_FDFDocGetID(mp_doc,&result));
}

inline void FDFDoc::SetID(SDF::Obj id) {
	REX(TRN_FDFDocSetID(mp_doc,id.mp_obj));
}

inline FDFFieldIterator FDFDoc::GetFieldIterator() {
	TRN_Iterator result;
	REX(TRN_FDFDocGetFieldIteratorBegin(mp_doc,&result));
	return Common::Iterator<FDFField>(result);
}

inline FDFFieldIterator FDFDoc::GetFieldIterator(const UString& field_name)
{
	TRN_Iterator result;
	REX(TRN_FDFDocGetFieldIterator(mp_doc, field_name.mp_impl,&result));
	return Common::Iterator<FDFField>(result);
}


inline FDFField FDFDoc::GetField(const UString& field_name) {

	RetFDFField(TRN_FDFDocGetField(mp_doc,field_name.mp_impl,&result));
}

inline FDFField FDFDoc::FieldCreate(const UString& field_name, PDF::Field::Type type, SDF::Obj field_value) {
	RetFDFField(TRN_FDFDocFieldCreate(mp_doc,field_name.mp_impl,(enum TRN_FieldType) type, field_value.mp_obj,&result));
}

inline FDFField FDFDoc::FieldCreate(const UString& field_name, PDF::Field::Type type, const UString& field_value){
	RetFDFField(TRN_FDFDocFieldCreateFromString(mp_doc, field_name.mp_impl,(enum TRN_FieldType) type, field_value.mp_impl, &result));
}


inline SDF::SDFDoc& FDFDoc::GetSDFDoc() {
	return *((SDF::SDFDoc*)this);
}

inline FDFDoc FDFDoc::CreateFromXFDF (const UString& filepath) {
	TRN_FDFDoc doc;
	REX(TRN_FDFDocCreateFromXFDF(filepath.mp_impl, &doc));
	return FDFDoc(doc);
}

inline void FDFDoc::SaveAsXFDF (const UString& filepath) {
	REX(TRN_FDFDocSaveAsXFDF(mp_doc, filepath.mp_impl));
}

inline UString FDFDoc::SaveAsXFDF(){
	RetStr(TRN_FDFDocSaveAsXFDFAsString(mp_doc,&result));
}

inline void FDFDoc::MergeAnnots(const UString& command_file, const UString& permitted_user) {
	REX(TRN_FDFDocMergeAnnots(mp_doc, command_file.mp_impl, permitted_user.mp_impl));
}
