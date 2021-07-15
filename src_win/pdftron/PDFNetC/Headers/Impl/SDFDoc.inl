
#ifndef CPPSDFDOC_INL
#define CPPSDFDOC_INL

#include <SDF/SecurityHandler.h>
#include <SDF/Obj.h>
#include <SDF/DictIterator.h>
#include <SDF/SDFDoc.h>

#include <C/Common/TRN_Vector.h>
#include <C/Common/TRN_Iterator.h>
#include <C/SDF/TRN_Obj.h>
#include <C/SDF/TRN_SecurityHandler.h>
#include <C/SDF/TRN_SDFDoc.h>
#include <cassert>

namespace pdftron{
	namespace SDF{

inline DictIterator::~DictIterator() {
	DREX(mp_impl, TRN_DictIteratorDestroy(mp_impl));
}

inline void DictIterator::Destroy()
{
	REX(TRN_DictIteratorDestroy(mp_impl));
	mp_impl=0;
}

inline void DictIterator::Next() {
	REX(TRN_DictIteratorNext(mp_impl));
}

inline SDF::Obj DictIterator::Key() {
	RetObj(TRN_DictIteratorKey(mp_impl,&result));
}

inline SDF::Obj DictIterator::Value() {
	RetObj(TRN_DictIteratorValue(mp_impl,&result));
}

inline bool DictIterator::HasNext() {
	RetBool(TRN_DictIteratorHasNext(mp_impl,&result));
}

inline DictIterator::DictIterator(TRN_DictIterator impl) : mp_impl(impl) {}

inline DictIterator::DictIterator(const DictIterator& c) {
	mp_impl=0;
	REX(TRN_DictIteratorAssign(c.mp_impl,&mp_impl));
}

inline DictIterator& DictIterator::operator=(const DictIterator& other) {
	REX(TRN_DictIteratorAssign(other.mp_impl,&mp_impl));
	return *this;
}

inline Obj::Obj(TRN_Obj impl) : mp_obj(impl) {}

inline Obj::Type Obj::GetType () const {
	enum TRN_ObjType result;
	REX(TRN_ObjGetType(mp_obj,&result));
	return (Type)result;
}

inline SDFDoc& Obj::GetDoc () const {
	REX(TRN_ObjGetDoc(mp_obj,&temp_doc));
	return *((SDFDoc*)&temp_doc);
}

inline void Obj::Write(Filters::FilterWriter& stream) {
	REX(TRN_ObjWrite(mp_obj,stream.m_impl));
}

inline bool Obj::operator ==(const Obj& to) const {
	RetBool(TRN_ObjIsEqual(mp_obj,to.mp_obj,&result));
}

inline bool Obj::IsEqual(const Obj& to) const { 
	return this->operator ==(to); 
}

inline bool Obj::IsBool () const {
	RetBool(TRN_ObjIsBool(mp_obj,&result));
}

inline bool Obj::GetBool () const {
	RetBool(TRN_ObjGetBool(mp_obj,&result));
}

inline void Obj::SetBool (bool b) {
	REX(TRN_ObjSetBool(mp_obj,BToTB(b)));
}

inline bool Obj::IsNumber () const {
	RetBool(TRN_ObjIsNumber(mp_obj,&result));
}

inline double Obj::GetNumber () const {
	RetDbl(TRN_ObjGetNumber(mp_obj,&result));
}

inline void Obj::SetNumber (double n) {
	REX(TRN_ObjSetNumber(mp_obj,n));
}

inline bool Obj::IsNull () const {
	RetBool(TRN_ObjIsNull(mp_obj,&result));
}

inline bool Obj::IsString () const {
	RetBool(TRN_ObjIsString(mp_obj,&result));
}

#ifdef SWIG
inline std::vector<unsigned char> Obj::GetBuffer () const {
	const TRN_UChar* arr;
	size_t size;
	REX(TRN_ObjSize(mp_obj,&size));
	std::vector<unsigned char> result (size);
	REX(TRN_ObjGetBuffer(mp_obj,&arr));
	memcpy(&result[0], arr, size);
	return result;
}
#else
inline const UChar* Obj::GetBuffer () const {
	const TRN_UChar* result;
	REX(TRN_ObjGetBuffer(mp_obj,&result));
	return result;
}
#endif

inline std::vector<unsigned char> Obj::GetRawBuffer() const {
	TRN_Vector cvector;
	REX(TRN_ObjGetRawBuffer(mp_obj, &cvector));
	void* arr;
	UInt32 size;
	REX(TRN_VectorGetData(cvector, &arr));
	REX(TRN_VectorGetSize(cvector, &size))
	std::vector<unsigned char> result(size);
	memcpy(&result[0], arr, size);
	TRN_VectorDestroy(cvector);
	return result;
}

inline UString Obj::GetAsPDFText() const {
	UString out_str;
	REX(TRN_ObjGetAsPDFText(mp_obj,&(out_str.mp_impl)));
	return out_str;
}

#ifndef SWIG
inline void Obj::GetAsPDFText(UString& out_str) const {
	REX(TRN_ObjGetAsPDFText(mp_obj,&(out_str.mp_impl)));
}
#endif

inline void Obj::SetString(const UChar* value, size_t size) {
	TRN_String valueString = { (const char*)value, (unsigned int)size }; // WARNING, may cause inaccuracies
	REX(TRN_ObjSetString(mp_obj, valueString));
}

inline void Obj::SetString(const UString& value) {
	REX(TRN_ObjSetUString(mp_obj,value.mp_impl));
}

inline bool Obj::IsName () const {
	RetBool(TRN_ObjIsName(mp_obj,&result));
}

inline const char* Obj::GetName () const {
	const char* result;
	REX(TRN_ObjGetName(mp_obj,&result));
	return result;
}

inline void Obj::SetName (const char* name) {
	REX(TRN_ObjSetName(mp_obj,name));
}

inline bool Obj::IsIndirect () const {
	RetBool(TRN_ObjIsIndirect(mp_obj,&result));
}

inline UInt32 Obj::GetObjNum () const {
	UInt32 result;
	REX(TRN_ObjGetObjNum(mp_obj,&result));
	return result;
}

inline UInt16 Obj::GetGenNum () const {
	UInt16 result;
	REX(TRN_ObjGetGenNum(mp_obj,&result));
	return result;
}

inline size_t Obj::GetOffset () const {
	size_t result;
	REX(TRN_ObjGetOffset(mp_obj,&result));
	return result;
}

inline bool Obj::IsFree () const {
	RetBool(TRN_ObjIsFree(mp_obj,&result));
}

inline void Obj::SetMark (bool mark) {
	REX(TRN_ObjSetMark(mp_obj,BToTB(mark)));
}

inline bool Obj::IsMarked () const {
	RetBool(TRN_ObjIsMarked(mp_obj,&result));
}

inline bool Obj::IsLoaded () const {
	RetBool(TRN_ObjIsLoaded(mp_obj,&result));
}

inline bool Obj::IsValid () const {
    return mp_obj != 0;
}

inline bool Obj::IsContainer () const {
	RetBool(TRN_ObjIsContainer(mp_obj,&result));
}

inline size_t Obj::Size () const {
	size_t result;
	REX(TRN_ObjSize(mp_obj,&result));
	return result;
}

inline DictIterator Obj::GetDictIterator () {
	TRN_DictIterator result;
	REX(TRN_ObjGetDictIterator(mp_obj,&result));
	return DictIterator(result);
}

inline bool Obj::IsDict () const {
	RetBool(TRN_ObjIsDict(mp_obj,&result));
}

inline DictIterator Obj::Find (const char* key) {
	TRN_DictIterator result;
	REX(TRN_ObjFind(mp_obj,key,&result));
	return DictIterator(result);
}

inline Obj Obj::FindObj (const char* key) {
	RetObj(TRN_ObjFindObj(mp_obj,key,&result));
}

inline DictIterator Obj::Get (const char* key) {
	TRN_DictIterator result;
	REX(TRN_ObjGet(mp_obj,key,&result));
	return DictIterator(result);
}

inline Obj Obj::PutName (const char* key, const char* name) {
	RetObj(TRN_ObjPutName(mp_obj,key,name,&result));
}

inline Obj Obj::PutArray (const char* key) {
	RetObj(TRN_ObjPutArray(mp_obj,key,&result));
}

inline Obj Obj::PutBool (const char* key, bool value) {
	RetObj(TRN_ObjPutBool(mp_obj,key,BToTB(value),&result));
}

inline Obj Obj::PutDict (const char* key) {
	RetObj(TRN_ObjPutDict(mp_obj,key,&result));
}

inline Obj Obj::PutNumber (const char* key, double value) {
	RetObj(TRN_ObjPutNumber(mp_obj,key,value,&result));
}

inline Obj Obj::PutString (const char* key, const char* value) {
	RetObj(TRN_ObjPutString(mp_obj,key,value,&result));
}

inline Obj Obj::PutString (const char* key, const char* value, int size) {
	RetObj(TRN_ObjPutStringWithSize(mp_obj,key,value,size,&result));
}

inline Obj Obj::PutText(const char* key, const UString& value) {
	RetObj(TRN_ObjPutText(mp_obj,key,value.mp_impl,&result));
}

inline void Obj::PutNull (const char* key) {
	TRN_ObjPutNull(mp_obj,key);
}

inline Obj Obj::Put(const char* key, Obj input_obj) {
	RetObj(TRN_ObjPut(mp_obj,key,input_obj.mp_obj,&result));
}

inline Obj Obj::PutRect (const char* key, double x1, double y1, double x2, double y2) {
	RetObj(TRN_ObjPutRect(mp_obj,key,x1,y1,x2,y2,&result));
}

inline Obj Obj::PutMatrix(const char* key, const Common::Matrix2D& value) {
	RetObj(TRN_ObjPutMatrix(mp_obj,key, (const TRN_Matrix2D*)&value, &result));
}

inline void Obj::Erase (const char* key) {
	REX(TRN_ObjEraseFromKey(mp_obj,key));
}

inline void Obj::Erase (DictIterator pos) {
	REX(TRN_ObjErase(mp_obj,pos.mp_impl));
}

inline bool Obj::Rename (const char* old_key, const char* new_key) {
	RetBool(TRN_ObjRename(mp_obj,old_key,new_key,&result));
}

inline bool Obj::IsArray () const {
	RetBool(TRN_ObjIsArray(mp_obj,&result));
}

inline Obj Obj::GetAt (size_t index) const {
	RetObj(TRN_ObjGetAt(mp_obj,index,&result));
}

inline Obj Obj::InsertName (size_t pos, const char* name) {
	RetObj(TRN_ObjInsertName(mp_obj,pos,name,&result));
}

inline Obj Obj::InsertArray (size_t pos) {
	RetObj(TRN_ObjInsertArray(mp_obj,pos,&result));
}

inline Obj Obj::InsertBool (size_t pos, bool value) {
	RetObj(TRN_ObjInsertBool(mp_obj,pos,value,&result));
}

inline Obj Obj::InsertDict (size_t pos) {
	RetObj(TRN_ObjInsertDict(mp_obj,pos,&result));
}

inline Obj Obj::InsertNumber (size_t pos, double value) {
	RetObj(TRN_ObjInsertNumber(mp_obj,pos,value,&result));
}

inline Obj Obj::InsertString (size_t pos, const char* value) {
	RetObj(TRN_ObjInsertString(mp_obj,pos,value,&result));
}

inline Obj Obj::InsertString (size_t pos, const char* value, int size) {
	RetObj(TRN_ObjInsertStringWithSize(mp_obj,pos,value,size,&result));
}

inline Obj Obj::InsertText(size_t pos, const UString& value) {
	RetObj(TRN_ObjInsertText(mp_obj,pos,value.mp_impl,&result));
}

inline Obj Obj::InsertNull(size_t pos) {
	RetObj(TRN_ObjInsertNull(mp_obj,pos,&result));
}

inline Obj Obj::Insert(size_t pos, Obj input_obj) {
	RetObj(TRN_ObjInsert(mp_obj,pos,input_obj.mp_obj,&result));
}
inline Obj Obj::InsertRect (size_t pos, double x1, double y1, double x2, double y2) {
	RetObj(TRN_ObjInsertRect(mp_obj,pos,x1,y1,x2,y2,&result));
}

inline Obj Obj::InsertMatrix(size_t pos, const Common::Matrix2D& value) {
	RetObj(TRN_ObjInsertMatrix(mp_obj,pos,(const TRN_Matrix2D*)&value,&result));
}

inline Obj Obj::PushBackName (const char* name) {
	RetObj(TRN_ObjPushBackName(mp_obj,name,&result));
}

inline Obj Obj::PushBackArray () {
	RetObj(TRN_ObjPushBackArray(mp_obj,&result));
}

inline Obj Obj::PushBackBool (bool value) {
	RetObj(TRN_ObjPushBackBool(mp_obj,BToTB(value),&result));
}

inline Obj Obj::PushBackDict () {
	RetObj(TRN_ObjPushBackDict(mp_obj,&result));
}

inline Obj Obj::PushBackNumber (double value) {
	RetObj(TRN_ObjPushBackNumber(mp_obj,value,&result));
}

inline Obj Obj::PushBackString (const char* value) {
	RetObj(TRN_ObjPushBackString(mp_obj,value,&result));
}

inline Obj Obj::PushBackString (const char* value, int size) {
	RetObj(TRN_ObjPushBackStringWithSize(mp_obj,value,size,&result));
}

inline Obj Obj::PushBackText (const UString& value) {
	RetObj(TRN_ObjPushBackText(mp_obj,value.mp_impl,&result));
}

inline Obj Obj::PushBackNull () {
	RetObj(TRN_ObjPushBackNull(mp_obj,&result));
}

inline Obj Obj::PushBack(Obj input_obj) {
	RetObj(TRN_ObjPushBack(mp_obj,input_obj.mp_obj,&result));
}

inline Obj Obj::PushBackRect (double x1, double y1, double x2, double y2) {
	RetObj(TRN_ObjPushBackRect(mp_obj,x1,y1,x2,y2,&result));
}

inline Obj Obj::PushBackMatrix(const Common::Matrix2D& value) {
	RetObj(TRN_ObjPushBackMatrix(mp_obj,(const TRN_Matrix2D*)&value,&result));
}

inline void Obj::EraseAt (size_t pos) {
	REX(TRN_ObjEraseAt(mp_obj,pos));
}

inline bool Obj::IsStream () const {
	RetBool(TRN_ObjIsStream(mp_obj,&result));
}

inline size_t Obj::GetRawStreamLength () const {
	size_t result;
	REX(TRN_ObjGetRawStreamLength(mp_obj,&result));
	return result;
}

inline Filters::Filter Obj::GetRawStream (bool decrypt) const {
	TRN_Filter result;
	REX(TRN_ObjGetRawStream(mp_obj,BToTB(decrypt),&result));
	return Filters::Filter(result,true);
}

inline Filters::Filter Obj::GetDecodedStream () const {
	TRN_Filter result;
	REX(TRN_ObjGetDecodedStream(mp_obj,&result));
	return Filters::Filter(result,true);
}

inline void Obj::SetStreamData( const char* data, 
				   const size_t data_size, 
				   Filters::Filter filter_chain )
{
	filter_chain.m_owner = false;
	REX(TRN_ObjSetStreamDataWithFilter( mp_obj, data, data_size, filter_chain.m_impl ));
	// Note: Transfer the ownership
	filter_chain.m_impl = 0;
}

//for xamarin use only
inline Obj* Obj::CreateInternal(ptrdiff_t impl) {
	return new Obj((TRN_Obj)impl);
}

inline ptrdiff_t Obj::GetHandleInternal() {
    return (ptrdiff_t) mp_obj;
}

//for xamarin use only
inline SDFDoc* SDFDoc::CreateInternal(ptrdiff_t impl) {
	return new SDFDoc((TRN_SDFDoc)impl);
}

inline ptrdiff_t SDFDoc::GetHandleInternal() {
    return (ptrdiff_t) mp_doc;
}

inline SDFDoc::SDFDoc () {
	REX(TRN_SDFDocCreate(&mp_doc));
}

inline SDFDoc::SDFDoc (const UString& filepath) {
	REX(TRN_SDFDocCreateFromFileUString(filepath.mp_impl,&mp_doc));
}

inline SDFDoc::SDFDoc (const char* filepath) {
	REX(TRN_SDFDocCreateFromFileString(filepath,&mp_doc));
}

inline SDFDoc::SDFDoc (Filters::Filter stream) {
	stream.m_owner = false;
	REX(TRN_SDFDocCreateFromFilter(stream.m_impl, &mp_doc));
	// Note: SDFDoc takes the ownership of the stream
	stream.m_impl = 0;  
}

inline SDFDoc::SDFDoc (unsigned char* buf, size_t buf_size) {
	REX(TRN_SDFDocCreateFromMemoryBuffer((const char*)buf,buf_size,&mp_doc));
}

inline SDFDoc::~SDFDoc () {
	DREX(mp_doc, TRN_SDFDocDestroy(mp_doc));
}

inline void SDFDoc::Close () {
	if (mp_doc) {
		REX(TRN_SDFDocDestroy(mp_doc));
		mp_doc=0;
	}
}

inline bool SDFDoc::IsEncrypted() {
	TRN_Bool result;
	REX(TRN_SDFDocIsEncrypted(mp_doc,&result));
	return TBToB(result);
}

inline bool SDFDoc::InitSecurityHandler(
#ifndef SWIG
	void* custom_data
#endif	
	) 
{
	void* c = 0;
#ifndef SWIG
	c = custom_data;
#endif	
	TRN_Bool result;
	REX(TRN_SDFDocInitSecurityHandler(mp_doc,c,&result));
	return TBToB(result);
}

inline bool SDFDoc::InitStdSecurityHandler (const char* password, int password_sz) {
	TRN_Bool result;
	REX(TRN_SDFDocInitStdSecurityHandler(mp_doc,password,password_sz,&result));
	return TBToB(result);
}

inline bool SDFDoc::InitStdSecurityHandler(const pdftron::UString& password)
{
    TRN_Bool result;
    REX(TRN_SDFDocInitStdSecurityHandlerUString(mp_doc, password.mp_impl, &result));
    return TBToB(result);
}

inline bool SDFDoc::InitStdSecurityHandler(const std::vector<UInt8>& password_buf)
{
    TRN_Bool result;
    REX(TRN_SDFDocInitStdSecurityHandlerBuffer(mp_doc, &(password_buf[0]), password_buf.size(), &result));
    return TBToB(result);
}

inline bool SDFDoc::IsModified () const {
	TRN_Bool result;
	REX(TRN_SDFDocIsModified(mp_doc,&result));
	return TBToB(result);
}

inline bool SDFDoc::HasRepairedXRef() const {
	TRN_Bool result;
	REX(TRN_SDFDocHasRepairedXRef(mp_doc, &result));
	return TBToB(result);
}

inline bool SDFDoc::IsFullSaveRequired () const {
	TRN_Bool result;
	REX(TRN_SDFDocIsFullSaveRequired(mp_doc,&result));
	return TBToB(result);
}

inline Obj SDFDoc::GetTrailer () {
	TRN_Obj result;
	REX(TRN_SDFDocGetTrailer(mp_doc,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::GetObj (const UInt32 obj_num) const {
	TRN_Obj result;
	REX(TRN_SDFDocGetObj(mp_doc,obj_num,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::ImportObj (Obj obj, bool deep_copy) {
	TRN_Obj result;
	REX(TRN_SDFDocImportObj(mp_doc,obj.mp_obj,BToTB(deep_copy),&(result)));
	return Obj(result);
}

inline std::vector<Obj> SDFDoc::ImportObjs(const std::vector<Obj>& obj_list) {
	size_t sz = obj_list.size();
	std::vector<Obj> ret;
	if(sz>0) {
		size_t i;
		std::vector<TRN_Obj> arr;
		arr.resize(sz);
		for (i=0; i<sz; ++i) arr[i] = obj_list[i].mp_obj;
		REX(TRN_SDFDocImportObjs(mp_doc, &arr[0], int(sz), &arr[0]));
		for (i=0; i<sz; ++i) ret.push_back(Obj(arr[i]));
	}
	return ret;
}
        
inline std::vector<Obj> SDFDoc::ImportObjs(const std::vector<Obj>& obj_list, const std::vector<Obj>& exclude_list) {
    size_t sz = obj_list.size();
    std::vector<TRN_Obj> arr;
    size_t i;
    if(sz>0) {
        size_t i;
        arr.resize(sz);
        for (i=0; i<sz; ++i) arr[i] = obj_list[i].mp_obj;
    }
    
    size_t ex_sz = exclude_list.size();
    std::vector<TRN_Obj> ex_arr;
    if(ex_sz>0) {
        

        ex_arr.resize(ex_sz);
        for (i=0; i<ex_sz; ++i) ex_arr[i] = exclude_list[i].mp_obj;
    }
    
    
    std::vector<Obj> ret;
    if(sz>0) {
        REX(TRN_SDFDocImportObjsWithExcludeList(mp_doc, &arr[0], int(sz), &ex_arr[0], int(ex_sz), &arr[0]));
    
        
        for (i=0; i<sz; ++i) ret.push_back(Obj(arr[i]));
    }
    
    return ret;
}

inline UInt32 SDFDoc::XRefSize () const {
	UInt32 result;
	REX(TRN_SDFDocXRefSize(mp_doc,&result));
	return result;
}

inline void SDFDoc::ClearMarks () {
	REX(TRN_SDFDocClearMarks(mp_doc));
}

inline void SDFDoc::Save(const UString& path, UInt32 flags, const char* header) {
	REX(TRN_SDFDocSave(mp_doc,path.mp_impl,flags,0,header));
}

#ifndef SWIG
inline void SDFDoc::Save(const UString& path, UInt32 flags, Common::ProgressMonitor* progress, const char* header) {
	REX(TRN_SDFDocSave(mp_doc,path.mp_impl,flags,0,header));
}
#endif

inline std::vector<unsigned char> SDFDoc::Save(UInt32 flags, const char* header) {
	size_t size;
	char* buf;
	std::vector<unsigned char> result;
	REX(TRN_SDFDocSaveMemory(mp_doc,(const char**)&buf,&size,flags,0,header));
	result.resize(size);
	memcpy(&result[0], buf, size);
	return result;
}

#ifndef SWIG
inline void SDFDoc::Save(const char* &out_buf, size_t& out_buf_size, UInt32 flags, Common::ProgressMonitor* progress, const char* header) {
	REX(TRN_SDFDocSaveMemory(mp_doc,&out_buf,&out_buf_size,flags,0,header));
}
#endif

inline void SDFDoc::Save(Filters::Filter stream, UInt32 flags, const char* header) {
	REX(TRN_SDFDocSaveStream(mp_doc, stream.m_impl,flags,header));
}

inline const char* SDFDoc::GetHeader() const {
	const char* result;
	REX(TRN_SDFDocGetHeader(mp_doc, &result));
	return result;
}

inline SecurityHandler SDFDoc::GetSecurityHandler () {
	TRN_SecurityHandler result;
	REX(TRN_SDFDocGetSecurityHandler(mp_doc, &result));

	void* derived = 0;
	TRN_SecurityHandlerDerivedDestroyProc d = 0;
	TRN_SecurityHandlerDerivedCloneProc c = 0;
	TRN_SecurityHandlerAuthProc a = 0;
	TRN_SecurityHandlerAuthFailedProc af = 0;
	TRN_SecurityHandlerGetAuthDataProc ga = 0;
	TRN_SecurityHandlerEditSecurDataProc es = 0;
	TRN_SecurityHandlerFillEncryptDictProc fd = 0;

	TRN_SecurityHandlerGetDerived(result, &derived, &d, &c, &a, &af, &ga, &es, &fd);

	UInt32 deriv_procs = 0;
	if (derived) {
		assert(d);
		assert(c); // Every derived class must implement the Clone() method.
		if (c) deriv_procs |= SecurityHandler::has_CloneProc;
		if (a) deriv_procs |= SecurityHandler::has_AuthProc;
		if (af) deriv_procs |= SecurityHandler::has_AuthFailedProc;
		if (ga) deriv_procs |= SecurityHandler::has_GetAuthDataProc;
		if (es) deriv_procs |= SecurityHandler::has_EditSecurDataProc;
		if (fd) deriv_procs |= SecurityHandler::has_FillEncDictProc;
	}

	return SecurityHandler(result, false, deriv_procs);
}

inline void SDFDoc::SetSecurityHandler (SecurityHandler handler) {
	handler.m_owner=false;
	REX(TRN_SDFDocSetSecurityHandler(mp_doc, handler.mp_handler));
}

inline void SDFDoc::RemoveSecurity() {
	REX(TRN_SDFDocRemoveSecurity(mp_doc));
}

inline void SDFDoc::Swap(UInt32 obj_num1, UInt32 obj_num2) {
	REX(TRN_SDFDocSwap(mp_doc,obj_num1,obj_num2));
}

inline bool SDFDoc::IsLinearized() const {
	TRN_Bool result;
	REX(TRN_SDFDocIsLinearized(mp_doc,&result));
	return TBToB(result);
}

inline SDF::Obj SDFDoc::GetLinearizationDict() const {
	TRN_Obj result;
	REX(TRN_SDFDocGetLinearizationDict(mp_doc,&(result)));
	return Obj(result);
}

inline SDF::Obj SDFDoc::GetHintStream() const {
	TRN_Obj result;
	REX(TRN_SDFDocGetHintStream(mp_doc,&(result)));
	return Obj(result);
}

inline void SDFDoc::Lock() {
	REX(TRN_SDFDocLock(mp_doc));
}

inline void SDFDoc::Unlock() {
	REX(TRN_SDFDocUnlock(mp_doc));
}

inline bool SDFDoc::TryLock( int milliseconds )
{
	TRN_Bool result;
	REX(TRN_SDFDocTimedLock(mp_doc,milliseconds,&result));
	return TBToB(result);
}

inline void SDFDoc::LockRead() {
	REX(TRN_SDFDocLockRead(mp_doc));
}

inline void SDFDoc::UnlockRead() {
	REX(TRN_SDFDocUnlockRead(mp_doc));
}

inline bool SDFDoc::TryLockRead( int milliseconds )
{
	TRN_Bool result;
	REX(TRN_SDFDocTimedLockRead(mp_doc,milliseconds,&result));
	return TBToB(result);
}

inline void SDFDoc::EnableDiskCaching( bool use_cache_flag ) {
	REX( TRN_SDFDocEnableDiskCaching(mp_doc,use_cache_flag) );
}

inline UString SDFDoc::GetFileName() const {
	TRN_UString result;
	REX(TRN_SDFDocGetFileName(mp_doc, &result));
	return UString(result);	
}

inline Obj SDFDoc::CreateIndirectName(const char* name) {
	TRN_Obj result;
	REX(TRN_SDFDocCreateIndirectName(mp_doc,name,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectArray() {
	TRN_Obj result;
	REX(TRN_SDFDocCreateIndirectArray(mp_doc,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectBool(bool value) {
	TRN_Obj result;
	REX(TRN_SDFDocCreateIndirectBool(mp_doc,BToTB(value),&(result)));
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectDict() {
	TRN_Obj result;
	REX(TRN_SDFDocCreateIndirectDict(mp_doc,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectNull() {
	TRN_Obj result;
	REX(TRN_SDFDocCreateIndirectNull(mp_doc,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectNumber(double value) {
	TRN_Obj result;
	REX(TRN_SDFDocCreateIndirectNumber(mp_doc,value,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectString(const UChar* value, UInt32 size) {
	TRN_Obj result;
	REX(TRN_SDFDocCreateIndirectString(mp_doc,value,size,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectString(const UString& str) {
	TRN_Obj result;
	REX(TRN_SDFDocCreateIndirectStringFromUString(mp_doc,str.mp_impl,&(result)));
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectStream(Filters::FilterReader& data, Filters::Filter filter_chain) {
	TRN_Obj result;
	filter_chain.m_owner = false;
	REX(TRN_SDFDocCreateIndirectStreamFromFilter(mp_doc,data.m_impl,filter_chain.m_impl,&(result)));
	// Note: SDFDoc takes the ownership of the stream
	filter_chain.m_impl = 0;  
	return Obj(result);
}

inline Obj SDFDoc::CreateIndirectStream(const char* data, const size_t data_size, Filters::Filter filter_chain) {
	TRN_Obj result;
	filter_chain.m_owner = false;
	REX(TRN_SDFDocCreateIndirectStream(mp_doc,data,data_size,filter_chain.m_impl,&(result)));
	// Note: SDFDoc takes the ownership of the stream
	filter_chain.m_impl = 0;  
	return Obj(result);
}

//SecurityHandler

namespace __SecHdlrPrivate
{
	inline void Destroy(void* derived) {
		SecurityHandler* sh = (SecurityHandler*)derived;
		delete sh;
	}

	inline void* Clone(void* derived, TRN_SecurityHandler base) {
		SecurityHandler* sh = (SecurityHandler*)derived;
		SecurityHandler* ret = sh->Clone(base);
		ret->m_owner = false;
		return (void*) ret;
	}

	inline TRN_Obj FillEncryptDict(void* derived, TRN_SDFDoc doc) {
		SecurityHandler* sh = (SecurityHandler*)derived;
		SDFDoc d(doc);
		TRN_Obj ret; 
		try {
			ret = sh->FillEncryptDict(d).mp_obj;
		}
		catch (Common::Exception& ex) {
			d.mp_doc = 0;
			throw ex;
		}
		d.mp_doc = 0;
		return ret;
	}

	inline void AuthorizeFailed(void* derived) {
		SecurityHandler* sh = (SecurityHandler*)derived;
		sh->AuthorizeFailed();
	}
	
	inline TRN_Bool Authorize(void* derived, TRN_SecurityHandlerPermission p) {
		SecurityHandler* sh = (SecurityHandler*)derived;
		return BToTB(sh->Authorize((SecurityHandler::Permission)p));
	}

	inline TRN_Bool GetAuthorizationData(void* derived, TRN_SecurityHandlerPermission p) {
		SecurityHandler* sh = (SecurityHandler*)derived;
		return BToTB(sh->GetAuthorizationData((SecurityHandler::Permission)p));
	}

	inline TRN_Bool EditSecurityData(void* derived, TRN_SDFDoc doc) {
		SecurityHandler* sh = (SecurityHandler*)derived;
		SDFDoc d(doc);
		TRN_Bool ret; 
		try {
			ret = BToTB(sh->EditSecurityData(d));
		}
		catch (Common::Exception& ex) {
			d.mp_doc = 0;
			throw ex;
		}
		d.mp_doc = 0;
		return ret;
	}

	inline void CleanUp(SecurityHandler& sec) {
		if(sec.m_owner) {
			sec.m_owner = false;		
			if (sec.m_derived_procs) {
				REX(TRN_SecurityHandlerSetDerived(sec.mp_handler,0,0,0,0,0,0,0,0));
				REX(TRN_SecurityHandlerDestroy(sec.mp_handler));
			}
			else {
				REX(TRN_SecurityHandlerDestroy(sec.mp_handler));
			}
			sec.mp_handler=0;
		}
	}
};

inline SecurityHandler::SecurityHandler (const SecurityHandler& s) {
	REX(TRN_SecurityHandlerClone(s.mp_handler,&mp_handler));
	m_owner = true;
	m_derived_procs = s.m_derived_procs;
}

inline SecurityHandler& SecurityHandler::operator= (const SecurityHandler& s) {
	if (this != &s) {
		__SecHdlrPrivate::CleanUp(*this);
		if (s.mp_handler) {
			REX(TRN_SecurityHandlerClone(s.mp_handler,&mp_handler));
			m_owner=true;
			m_derived_procs = s.m_derived_procs;
		}
		else {
			m_owner=false;
			m_derived_procs = 0;
		}
	}

	return *this;
}

inline SecurityHandler::SecurityHandler(TRN_SecurityHandler impl, bool owner, UInt32 derived_procs) {
	mp_handler = impl;
	m_owner = owner;
	m_derived_procs = derived_procs;
}

inline SecurityHandler::~SecurityHandler() {
	__SecHdlrPrivate::CleanUp(*this);
}

inline bool SecurityHandler::GetPermission(Permission p) {
	RetBool(TRN_SecurityHandlerGetPermission(mp_handler, 
		(enum TRN_SecurityHandlerPermission)p,&result));
}

inline int SecurityHandler::GetKeyLength() const {
	int result;
	REX(TRN_SecurityHandlerGetKeyLength(mp_handler, &result));
	return result;
}

inline int SecurityHandler::GetEncryptionAlgorithmID() const {
	int result;
	REX(TRN_SecurityHandlerGetEncryptionAlgorithmID(mp_handler, &result));
	return result;
}

inline const char* SecurityHandler::GetHandlerDocName() const {
	const char* result;
	REX(TRN_SecurityHandlerGetHandlerDocName(mp_handler, &result));
	return result;
}

inline bool SecurityHandler::IsModified () const {
	RetBool(TRN_SecurityHandlerIsModified(mp_handler, &result));
}

inline void SecurityHandler::SetModified (bool is_modified) {
	REX(TRN_SecurityHandlerSetModified(mp_handler, BToTB(is_modified)));
}

inline SecurityHandler::SecurityHandler (AlgorithmType crypt_type) {
	REX(TRN_SecurityHandlerCreate((enum TRN_SecurityHandlerAlgorithmType)crypt_type, &mp_handler));
	m_owner=true;
	m_derived_procs = 0;
}

inline SecurityHandler::SecurityHandler (const char* name, int key_len, int enc_code) {
	REX(TRN_SecurityHandlerCreateFromEncCode(name, key_len, enc_code,&mp_handler));
	m_owner=true;
	m_derived_procs = 0;
}

inline SecurityHandler::SecurityHandler () {
	REX(TRN_SecurityHandlerCreateDefault(&mp_handler));
	m_owner=true;
	m_derived_procs = 0;
}

inline bool SecurityHandler::IsValid () const {
    return mp_handler != 0;
}

inline void SecurityHandler::InitPasswordASCII(const char* password) {
	REX(TRN_SecurityHandlerInitPassword(mp_handler, password));
}

inline void SecurityHandler::InitPassword(const char* password, size_t pwd_length )  {
	REX(TRN_SecurityHandlerInitPasswordNonAscii(mp_handler, password, pwd_length));
}

inline void SecurityHandler::InitPassword(const pdftron::UString& password)
{
    REX(TRN_SecurityHandlerInitPasswordUString(mp_handler, password.mp_impl));
}

inline void SecurityHandler::InitPassword(const std::vector<pdftron::UInt8>& password_buf)
{
    REX(TRN_SecurityHandlerInitPasswordBuffer(mp_handler, &(password_buf[0]), password_buf.size()));
}

inline void SecurityHandler::SetDerived(UInt32 overloaded_funct)
{
	assert(overloaded_funct & has_CloneProc); // Clone() method must be implemented in every derived security handler.
	m_owner = false;
	m_derived_procs = overloaded_funct;
	REX(TRN_SecurityHandlerSetDerived(mp_handler, this, 
		__SecHdlrPrivate::Destroy,
		((overloaded_funct & has_CloneProc)  ? __SecHdlrPrivate::Clone : 0), 
		((overloaded_funct & has_AuthProc) ? __SecHdlrPrivate::Authorize : 0), 
		((overloaded_funct & has_AuthFailedProc) ? __SecHdlrPrivate::AuthorizeFailed : 0), 
		((overloaded_funct & has_GetAuthDataProc) ? __SecHdlrPrivate::GetAuthorizationData : 0), 
		((overloaded_funct & has_EditSecurDataProc) ? __SecHdlrPrivate::EditSecurityData : 0), 
		((overloaded_funct & has_FillEncDictProc) ? __SecHdlrPrivate::FillEncryptDict : 0)));
}

inline SecurityHandler* SecurityHandler::GetDerived() const {
	void* derived=0;
	TRN_SecurityHandlerGetDerived(mp_handler, &derived, 0, 0, 0, 0, 0, 0, 0);
	return (SecurityHandler*)derived;
}

inline SecurityHandler* SecurityHandler::Clone(TRN_SecurityHandler base) const
{
	SecurityHandler* derived = GetDerived();
	if ((m_derived_procs & has_CloneProc) && derived) {
		return derived->Clone(base);
	}
	else {
		return new SecurityHandler(*this); 
	}
}

inline Obj SecurityHandler::FillEncryptDict (SDFDoc& doc) 
{ 
	SecurityHandler* derived = GetDerived();
	if ((m_derived_procs & has_FillEncDictProc) && derived) {
		return derived->FillEncryptDict(doc);
	}
	else {
		RetObj(TRN_SecurityHandlerFillEncryptDict(mp_handler, (TRN_SDFDoc)&doc, &result));
	}
}

inline bool SecurityHandler::EditSecurityData(SDFDoc& doc) 
{
	SecurityHandler* derived = GetDerived();
	if ((m_derived_procs & has_EditSecurDataProc) && derived) {
		return derived->EditSecurityData(doc);
	}
	else {
		RetBool(TRN_SecurityHandlerEditSecurityData(mp_handler, (TRN_SDFDoc)& doc, &result));
	}
}
	 
inline bool SecurityHandler::GetAuthorizationData (Permission req_opr) 
{
	SecurityHandler* derived = GetDerived();
	if ((m_derived_procs & has_GetAuthDataProc) && derived) {
		return derived->GetAuthorizationData(req_opr);
	}
	else {
		RetBool(TRN_SecurityHandlerGetAuthorizationData(mp_handler, (TRN_SecurityHandlerPermission)req_opr, &result));
	}
}

inline bool SecurityHandler::Authorize(Permission req_opr) 
{
	SecurityHandler* derived = GetDerived();
	if ((m_derived_procs & has_AuthProc) && derived) {
		return derived->Authorize(req_opr);
	}
	else {
		RetBool(TRN_SecurityHandlerAuthorize(mp_handler, (TRN_SecurityHandlerPermission)req_opr, &result));
	}
}

inline void SecurityHandler::AuthorizeFailed() 
{
	SecurityHandler* derived = GetDerived();
	if ((m_derived_procs & has_AuthFailedProc) && derived) {
		derived->AuthorizeFailed();
	}
	else {
		// The default implementations is a no-op.
	}
}

inline void SecurityHandler::ChangeUserPasswordASCII(const char* password ) {
	REX(TRN_SecurityHandlerChangeUserPassword(mp_handler, password));
}

inline void SecurityHandler::ChangeUserPassword(const char* password, size_t pwd_length ) {
	REX(TRN_SecurityHandlerChangeUserPasswordNonAscii(mp_handler, password, pwd_length));
}

inline void SecurityHandler::ChangeUserPassword(const pdftron::UString& password)
{
    REX(TRN_SecurityHandlerChangeUserPasswordUString(mp_handler, password.mp_impl));
}

inline void SecurityHandler::ChangeUserPassword(const std::vector<pdftron::UInt8>& password_buf)
{
    REX(TRN_SecurityHandlerChangeUserPasswordBuffer(mp_handler, &(password_buf[0]), password_buf.size()));
}

inline const char* SecurityHandler::GetUserPassword() {
	RetCCS(TRN_SecurityHandlerGetUserPassword(mp_handler,&result));
}

inline size_t SecurityHandler::GetUserPasswordSize() const {
	TRN_UInt32 res;
	REX( TRN_SecurityHandlerGetUserPasswordSize( mp_handler, &res ) );
	return res;
}

inline void SecurityHandler::ChangeMasterPasswordASCII(const char* password ) {
	REX(TRN_SecurityHandlerChangeMasterPassword(mp_handler,password));
}

inline void SecurityHandler::ChangeMasterPassword(const char* password, size_t pwd_length ) {
	REX(TRN_SecurityHandlerChangeMasterPasswordNonAscii(mp_handler,password, pwd_length));
}

inline void SecurityHandler::ChangeMasterPassword(const pdftron::UString& password)
{
    REX(TRN_SecurityHandlerChangeMasterPasswordUString(mp_handler, password.mp_impl));
}

inline void SecurityHandler::ChangeMasterPassword(const std::vector<pdftron::UInt8>& password_buf)
{
    REX(TRN_SecurityHandlerChangeMasterPasswordBuffer(mp_handler, &(password_buf[0]), password_buf.size()));
}

inline const char* SecurityHandler::GetMasterPassword() {
	RetCCS(TRN_SecurityHandlerGetMasterPassword(mp_handler,&result));
}

inline size_t SecurityHandler::GetMasterPasswordSize() const {
	TRN_UInt32 res;
	REX( TRN_SecurityHandlerGetMasterPasswordSize( mp_handler, &res ) );
	return res;
}

inline void SecurityHandler::SetPermission (Permission perm, bool value) {
	REX(TRN_SecurityHandlerSetPermission(mp_handler, (enum TRN_SecurityHandlerPermission)perm, BToTB(value)));
}

inline void SecurityHandler::ChangeRevisionNumber (int rev_num) {
	REX(TRN_SecurityHandlerChangeRevisionNumber(mp_handler, rev_num));
}

inline void SecurityHandler::SetEncryptMetadata(bool encrypt_metadata) {
	REX(TRN_SecurityHandlerSetEncryptMetadata(mp_handler, BToTB(encrypt_metadata)));
}

inline int SecurityHandler::GetRevisionNumber () {
	RetInt(TRN_SecurityHandlerGetRevisionNumber(mp_handler,&result));
}

inline bool SecurityHandler::IsUserPasswordRequired () {
	RetBool(TRN_SecurityHandlerIsUserPasswordRequired(mp_handler, &result));
}

inline bool SecurityHandler::IsMasterPasswordRequired () {
	RetBool(TRN_SecurityHandlerIsMasterPasswordRequired(mp_handler, &result));
}

inline bool SecurityHandler::IsAES() const {
	RetBool(TRN_SecurityHandlerIsAES(mp_handler, &result));
}

inline bool SecurityHandler::IsAES(Obj stream) const {
	RetBool(TRN_SecurityHandlerIsAESObj(mp_handler, stream.mp_obj, &result));
}

inline bool SecurityHandler::IsRC4() const {
	RetBool(TRN_SecurityHandlerIsRC4(mp_handler, &result));
}


	};	// namespace PDF
};	// namespace pdftron


#endif
