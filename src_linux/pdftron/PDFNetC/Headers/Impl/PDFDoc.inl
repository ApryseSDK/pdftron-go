#ifndef CPPPDFDOC_INL
#define CPPPDFDOC_INL

#include <SDF/Obj.h>
#include <PDF/Field.h>
#include <PDF/Action.h>
#include <PDF/Annot.h>
#include <PDF/Destination.h>
#include <PDF/Page.h>
#include <PDF/PDFDoc.h>
#include <PDF/Bookmark.h>
#include <PDF/OCG/Config.h>
#include <PDF/Struct/STree.h>
#include <PDF/Struct/ContentItem.h>
#include <PDF/Struct/SElement.h>
#include <PDF/DiffOptions.h>
#include <C/PDF/Struct/TRN_ContentItem.h>
#include <C/PDF/Struct/TRN_STree.h>
#include <C/PDF/Struct/TRN_SElement.h>
#include <cassert>
#include <C/SDF/TRN_SignatureHandler.h>
#include <C/PDF/TRN_DigitalSignatureField.h>

namespace pdftron {
	namespace PDF {

// Bookmark --------------------------------------------------------

inline Bookmark Bookmark::Create(PDFDoc& in_doc, const UString& in_title) {
	TRN_Bookmark result;
	REX(TRN_BookmarkCreate(in_doc.mp_doc,in_title.mp_impl,&result));
	return Bookmark(result);
}

inline Bookmark::Bookmark() : mp_obj(0) {}

inline Bookmark::Bookmark(SDF::Obj in_bookmark_dict) {
	REX(TRN_BookmarkCreateFromObj(in_bookmark_dict.mp_obj,&mp_obj));
}

inline Bookmark::Bookmark(const Bookmark& in_bookmark) {
	REX(TRN_BookmarkCopy(in_bookmark.mp_obj,&mp_obj));
}

inline Bookmark& Bookmark::operator=(const Bookmark& in_bookmark) {
	REX(TRN_BookmarkCopy(in_bookmark.mp_obj,&mp_obj));
	return *this;
}

inline bool Bookmark::operator==(const Bookmark& in_bookmark) {
	TRN_Bool result;
	REX(TRN_BookmarkCompare(mp_obj,in_bookmark.mp_obj,&result));
	return TBToB(result);
}

inline bool Bookmark::IsValid() const {
	TRN_Bool result;
	REX(TRN_BookmarkIsValid(mp_obj, &result));
	return TBToB(result);
}

inline bool Bookmark::HasChildren() {
	TRN_Bool result;
	REX(TRN_BookmarkHasChildren(mp_obj, &result));
	return TBToB(result);
}

inline Bookmark Bookmark::GetNext() {
	TRN_Bookmark result;
	REX(TRN_BookmarkGetNext(mp_obj, &result));
	return Bookmark(result);
}

inline Bookmark Bookmark::GetPrev() {
	TRN_Bookmark result;
	REX(TRN_BookmarkGetPrev(mp_obj, &result))
	return Bookmark(result);
}

inline Bookmark Bookmark::GetFirstChild() {
	TRN_Bookmark result;
	REX(TRN_BookmarkGetFirstChild(mp_obj, &result));
	return Bookmark(result);
}

inline Bookmark Bookmark::GetLastChild() {
	TRN_Bookmark result;
	REX(TRN_BookmarkGetLastChild(mp_obj, &result));
	return Bookmark(result);
}

inline Bookmark Bookmark::GetParent() {
	TRN_Bookmark result;
	REX(TRN_BookmarkGetParent(mp_obj, &result));
	return Bookmark(result);
}

inline Bookmark Bookmark::Find(const UString& in_title) {
	TRN_Bookmark result;
	REX(TRN_BookmarkFind(mp_obj, in_title.mp_impl,&result))
	return Bookmark(result);
}

inline Bookmark Bookmark::AddChild(const UString& in_title) {
	TRN_Bookmark result;
	REX(TRN_BookmarkAddNewChild(mp_obj, in_title.mp_impl,&result));
	return Bookmark(result);
}

inline Bookmark Bookmark::AddChild(Bookmark in_bookmark) {
	REX(TRN_BookmarkAddChild(mp_obj,in_bookmark.mp_obj));
	return in_bookmark;
}

inline Bookmark Bookmark::AddNext(const UString& in_title) {
	TRN_Bookmark result;
	REX(TRN_BookmarkAddNewNext(mp_obj, in_title.mp_impl,&result));
	return Bookmark(result);
}

inline void Bookmark::AddNext(Bookmark in_bookmark) {
	REX(TRN_BookmarkAddNext(mp_obj,in_bookmark.mp_obj));
}

inline Bookmark Bookmark::AddPrev(const UString& in_title) {
	TRN_Bookmark result;
	REX(TRN_BookmarkAddNewPrev(mp_obj,in_title.mp_impl,&result));
	return Bookmark(result);
}

inline void Bookmark::AddPrev(Bookmark in_bookmark) {
	REX(TRN_BookmarkAddPrev(mp_obj, in_bookmark.mp_obj));
}

inline void Bookmark::Delete() {
	REX(TRN_BookmarkDelete(mp_obj));
}

inline void Bookmark::Unlink() {
	REX(TRN_BookmarkUnlink(mp_obj));
}

inline int Bookmark::GetIndent() {
	int result;
	REX(TRN_BookmarkGetIndent(mp_obj, &result));
	return result;
}

inline bool Bookmark::IsOpen() {
	TRN_Bool result;
	REX(TRN_BookmarkIsOpen(mp_obj,&result));
	return TBToB(result);
}

inline void Bookmark::SetOpen(bool in_open) {
	REX(TRN_BookmarkSetOpen(mp_obj, BToTB(in_open)));
}

inline int Bookmark::GetOpenCount() {
	int result;
	REX(TRN_BookmarkGetOpenCount(mp_obj, &result));
	return result;
}

inline UString Bookmark::GetTitle() {
	TRN_UString result;
	REX(TRN_BookmarkGetTitle(mp_obj, &result));
	return UString(result);
}

inline SDF::Obj Bookmark::GetTitleObj() {
	TRN_Obj result;
	REX(TRN_BookmarkGetTitleObj(mp_obj, &result));
	return SDF::Obj(result);
}

inline void Bookmark::SetTitle(const UString& title) {
	REX(TRN_BookmarkSetTitle(mp_obj,title.mp_impl));
}

inline Action Bookmark::GetAction() {
	TRN_Action result;
	REX(TRN_BookmarkGetAction(mp_obj, &result));
	return Action(result);
}

inline void Bookmark::SetAction(Action in_action) {
	REX(TRN_BookmarkSetAction(mp_obj, in_action.mp_action));
}

inline void Bookmark::RemoveAction() {
	REX(TRN_BookmarkRemoveAction(mp_obj));
}

inline int Bookmark::GetFlags() {
	int result;
	REX(TRN_BookmarkGetFlags(mp_obj,&result));
	return result;
}

inline void Bookmark::SetFlags(int in_flags) {
	REX(TRN_BookmarkSetFlags(mp_obj,in_flags));
}

inline std::vector<double> Bookmark::GetColor() {
	double out_r;
	double out_g;
	double out_b;
	std::vector<double> arr(3); 
	REX(TRN_BookmarkGetColor(mp_obj, &out_r,&out_g,&out_b));
	arr[0] = out_r;
	arr[1] = out_g;
	arr[2] = out_b;
	return arr;
}

#ifndef SWIG
inline void Bookmark::GetColor(double& out_r, double& out_g, double& out_b) {
	REX(TRN_BookmarkGetColor(mp_obj, &out_r,&out_g,&out_b));
}
#endif

inline void Bookmark::SetColor(double in_r, double in_g, double in_b) {
	REX(TRN_BookmarkSetColor(mp_obj, in_r,in_g,in_b));
}

inline SDF::Obj Bookmark::GetSDFObj() const {
	TRN_Obj result;
	REX(TRN_BookmarkGetSDFObj(mp_obj,&result));
	return SDF::Obj(result);
}

inline Bookmark::Bookmark(TRN_Bookmark impl) : mp_obj(impl) {
}

// ---------------------------------------------------
//for xamarin use only
inline Bookmark* Bookmark::CreateInternal(ptrdiff_t impl) {
	return new Bookmark((TRN_Bookmark)impl);
}

inline ptrdiff_t Bookmark::GetHandleInternal() {
    return (ptrdiff_t) mp_obj;
}

// PDFDoc --------------------------------------------------------

inline PDFDoc::PDFDoc () {
	REX(TRN_PDFDocCreate(&mp_doc));
}

inline PDFDoc::PDFDoc (SDF::SDFDoc& sdfdoc) {
	REX(TRN_PDFDocCreateFromSDFDoc(sdfdoc.mp_doc,&mp_doc));
}

inline PDFDoc::PDFDoc(const PDFDoc& other) {
	REX(TRN_PDFDocCreateShallowCopy(other.mp_doc, &mp_doc));
}

inline PDFDoc& PDFDoc::operator =(const PDFDoc& other) {
	if(other.mp_doc != mp_doc)
	{
		DREX(mp_doc, TRN_PDFDocDestroy(mp_doc));
		if(other.mp_doc)
		{
			REX(TRN_PDFDocCreateShallowCopy(other.mp_doc, &mp_doc));
		}
	}
	return *this;
}


inline PDFDoc::PDFDoc (const UString& filepath) {
	REX(TRN_PDFDocCreateFromUFilePath(filepath.mp_impl,&mp_doc));
}

inline PDFDoc::PDFDoc (const char* filepath) {
	REX(TRN_PDFDocCreateFromFilePath(filepath,&mp_doc));
}

inline PDFDoc::PDFDoc (Filters::Filter stream) 
{
	stream.m_owner = false;
	REX(TRN_PDFDocCreateFromFilter(stream.m_impl,&mp_doc));
	stream.m_impl = 0;  
}

inline PDFDoc::PDFDoc (const UChar* buf, size_t buf_size) {
	REX(TRN_PDFDocCreateFromBuffer(buf,buf_size,&mp_doc));
}

inline PDFDoc::~PDFDoc () {
	DREX(mp_doc, TRN_PDFDocDestroy(mp_doc));
}

inline void PDFDoc::Close () {
	REX(TRN_PDFDocDestroy(mp_doc));
	mp_doc=0;
}

inline bool PDFDoc::IsEncrypted() {
	TRN_Bool result;
	REX(TRN_PDFDocIsEncrypted(mp_doc, &result));
	return TBToB(result);
}

inline bool PDFDoc::InitSecurityHandler (
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
	REX(TRN_PDFDocInitSecurityHandler(mp_doc, c, &result));
	return TBToB(result);
}

inline bool PDFDoc::InitStdSecurityHandler (const char* password, int password_sz) {
	TRN_Bool result;
	REX(TRN_PDFDocInitStdSecurityHandler(mp_doc,password,password_sz,&result));
	return TBToB(result);
}

inline bool PDFDoc::InitStdSecurityHandler(const pdftron::UString& password)
{
    TRN_Bool result;
    REX(TRN_PDFDocInitStdSecurityHandlerUString(mp_doc, password.mp_impl, &result));
    return TBToB(result);
}

inline bool PDFDoc::InitStdSecurityHandler(const std::vector<UInt8>& password_buf)
{
    TRN_Bool result;
    REX(TRN_PDFDocInitStdSecurityHandlerBuffer(mp_doc, &(password_buf[0]), password_buf.size(), &result));
    return TBToB(result);
}

inline SDF::SecurityHandler PDFDoc::GetSecurityHandler () {
	TRN_SecurityHandler result;
	REX(TRN_PDFDocGetSecurityHandler(mp_doc, &result));

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
		if (c) deriv_procs |= SDF::SecurityHandler::has_CloneProc;
		if (a) deriv_procs |= SDF::SecurityHandler::has_AuthProc;
		if (af) deriv_procs |= SDF::SecurityHandler::has_AuthFailedProc;
		if (ga) deriv_procs |= SDF::SecurityHandler::has_GetAuthDataProc;
		if (es) deriv_procs |= SDF::SecurityHandler::has_EditSecurDataProc;
		if (fd) deriv_procs |= SDF::SecurityHandler::has_FillEncDictProc;
	}

	return SDF::SecurityHandler(result, false, deriv_procs);
}

inline void PDFDoc::RemoveSecurity() {
	REX(TRN_PDFDocRemoveSecurity(mp_doc));
}

inline void PDFDoc::SetSecurityHandler (const SDF::SecurityHandler & handler) {
	const_cast<SDF::SecurityHandler&>(handler).m_owner=false;
	REX(TRN_PDFDocSetSecurityHandler(mp_doc,handler.mp_handler));
}

inline bool PDFDoc::HasSignatures()
{
    TRN_Bool hasSig;
    REX(TRN_PDFDocHasSignatures(mp_doc, &hasSig));
    return (TBToB(hasSig));
}
        
inline bool PDFDoc::HasDownloader()
{
    TRN_Bool hasDown;
    REX(TRN_PDFDocHasDownloader(mp_doc, &hasDown));
    return (TBToB(hasDown));
}

inline SDF::SignatureHandlerId PDFDoc::AddSignatureHandler(const SDF::SignatureHandler& signature_handler)
{
    SDF::SignatureHandler* owned_handler = signature_handler.Clone();
    TRN_SignatureHandler sigHandler;
    REX(TRN_SignatureHandlerCreate(SDF::SignatureHandler::TRN_SignatureHandlerGetNameImpl,
                                SDF::SignatureHandler::TRN_SignatureHandlerAppendDataImpl,
                                SDF::SignatureHandler::TRN_SignatureHandlerResetImpl,
                                SDF::SignatureHandler::TRN_SignatureHandlerCreateSignatureImpl,
                                SDF::SignatureHandler::TRN_SignatureHandlerDestroyImpl,
                                (void*) owned_handler, &sigHandler));
    if (sigHandler == NULL) {
        delete (owned_handler); // important!
        throw (Common::Exception("Error", 0, "PDFDoc.h", "PDFDoc::AddSignatureHandler", "Failed to add SignatureHandler."));
    }
    TRN_SignatureHandlerId result = 0;
    REX(TRN_PDFDocAddSignatureHandler(mp_doc, sigHandler, &result));
    return ((SDF::SignatureHandlerId) result);
}

inline SDF::SignatureHandlerId PDFDoc::AddStdSignatureHandler(const UString& pkcs12_keyfile, const UString& pkcs12_keypass)
{
    TRN_SignatureHandlerId result = 0;
    REX(TRN_PDFDocAddStdSignatureHandlerFromFile(mp_doc, pkcs12_keyfile.mp_impl, pkcs12_keypass.mp_impl, &result));
    return ((SDF::SignatureHandlerId) result);
}

inline SDF::SignatureHandlerId PDFDoc::AddStdSignatureHandler(const std::vector<unsigned char>& pkcs12_keybuffer, const UString& pkcs12_keypass)
{
    TRN_SignatureHandlerId result = 0;
    REX(TRN_PDFDocAddStdSignatureHandlerFromBuffer(mp_doc, &(pkcs12_keybuffer[0]), pkcs12_keybuffer.size(), pkcs12_keypass.mp_impl, &result));
    return ((SDF::SignatureHandlerId) result);
}

inline void PDFDoc::RemoveSignatureHandler(const SDF::SignatureHandlerId signature_handler_id)
{
    REX(TRN_PDFDocRemoveSignatureHandler(mp_doc, (const TRN_SignatureHandlerId) signature_handler_id));
}

inline SDF::SignatureHandler* PDFDoc::GetSignatureHandler(const SDF::SignatureHandlerId signature_handler_id)
{
    TRN_SignatureHandler sigHandler;
    REX(TRN_PDFDocGetSignatureHandler(mp_doc, (const TRN_SignatureHandlerId) signature_handler_id, &sigHandler));
    if (sigHandler == NULL) return (NULL);
    SDF::SignatureHandler* result = NULL;
    REX(TRN_SignatureHandlerGetUserImpl(sigHandler, (void**) &result));
    return (result);
}

inline SDF::UndoManager PDFDoc::GetUndoManager()
{
    TRN_UndoManager um;
    REX(TRN_PDFDocGetUndoManager(mp_doc, &um));
    return SDF::UndoManager(um);
}

inline PDF::DigitalSignatureField PDFDoc::CreateDigitalSignatureField(const UString& in_sig_partial_field_name)
{
	TRN_DigitalSignatureField result;
	REX(TRN_PDFDocCreateDigitalSignatureField(mp_doc, in_sig_partial_field_name.mp_impl, &result));
	return PDF::DigitalSignatureField(result);
}

inline PDF::DigitalSignatureFieldIterator PDFDoc::GetDigitalSignatureFieldIterator()
{
	TRN_Iterator result;
	REX(TRN_PDFDocGetDigitalSignatureFieldIteratorBegin(mp_doc, &result));
	Common::Iterator<PDF::DigitalSignatureField> t(result);
	return t;
}

inline PDF::DigitalSignatureField::DocumentPermissions PDFDoc::GetDigitalSignaturePermissions() const
{
	enum TRN_DigitalSignatureField_DocumentPermissions tmp;
	REX(TRN_PDFDocGetDigitalSignaturePermissions(mp_doc, &tmp));
	return (PDF::DigitalSignatureField::DocumentPermissions) tmp;
}

inline bool PDFDoc::IsModified () const {
	TRN_Bool result;
	REX(TRN_PDFDocIsModified(mp_doc,&result));
	return TBToB(result);
}

inline bool PDFDoc::HasRepairedXRef() const {
	TRN_Bool result;
	REX(TRN_PDFDocHasRepairedXRef(mp_doc, &result));
	return TBToB(result);
}

inline bool PDFDoc::IsLinearized() const {
	TRN_Bool result;
	REX(TRN_PDFDocIsLinearized(mp_doc,&result));
	return TBToB(result);
}

inline void PDFDoc::Save(const UString& path, UInt32 flags) {
	REX(TRN_PDFDocSave(mp_doc, path.mp_impl,flags));
}

#ifndef SWIG
inline void PDFDoc::Save(const UString& path, UInt32 flags, Common::ProgressMonitor*) {
	REX(TRN_PDFDocSave(mp_doc, path.mp_impl,flags));
}
#endif

inline std::vector<unsigned char> PDFDoc::Save(UInt32 flags) {
	size_t size;
	char* buf;
	std::vector<unsigned char> result;
	REX(TRN_PDFDocSaveMemoryBuffer(mp_doc, flags, (const char**)&buf, &size));
	result.resize(size);
	memcpy(&result[0], buf, size);
	return result;
}

#ifndef SWIG
inline void PDFDoc::Save(const char* &out_buf, size_t& out_buf_size, UInt32 flags, Common::ProgressMonitor*) {
	REX(TRN_PDFDocSaveMemoryBuffer(mp_doc, flags, &out_buf, &out_buf_size));
}
#endif

inline void PDFDoc::Save(Filters::Filter& stream, UInt32 flags) {
	REX(TRN_PDFDocSaveStream(mp_doc,stream.m_impl,flags));
}

inline PageIterator PDFDoc::GetPageIterator(UInt32 page_number) {
	TRN_Iterator result;
	REX(TRN_PDFDocGetPageIterator(mp_doc, page_number, &result));
	return Common::Iterator<Page>(result);
}

inline Page PDFDoc::GetPage(UInt32 page_number) {
	TRN_Page result;
	REX(TRN_PDFDocGetPage(mp_doc,page_number,&result));
	return Page(result);
}

inline void PDFDoc::PageRemove(const PageIterator& page_itr) {
	REX(TRN_PDFDocPageRemove(mp_doc, page_itr.mp_impl));
}

inline void PDFDoc::PageInsert(PageIterator& where, Page page) {
	REX(TRN_PDFDocPageInsert(mp_doc, where.mp_impl,page.mp_page));
}

inline void PDFDoc::InsertPages(int insert_before_page_number
								, PDFDoc& sourceDoc
								, int startPage
								, int endPage
								, enum InsertFlag flag
#ifndef SWIG
								, Common::ProgressMonitor * monitor
#endif
	)
{
	TRN_ProgressMonitor* m = 0;
#ifndef SWIG
	 m = (TRN_ProgressMonitor*)monitor;
#endif
	 REX(TRN_PDFDocInsertPages(mp_doc, insert_before_page_number, sourceDoc.mp_doc, startPage, endPage, (enum TRN_PDFDocInsertFlag) flag));
}

inline void PDFDoc::InsertPages(int insert_before_page_number
								, PDFDoc& sourceDoc
								, const PageSet& sourcePageSet
								, enum InsertFlag flag
#ifndef SWIG
								, Common::ProgressMonitor * monitor
#endif
	)
{
	TRN_ProgressMonitor* m = 0;
#ifndef SWIG
	m = (TRN_ProgressMonitor*)monitor;
#endif
	REX(TRN_PDFDocInsertPageSet(mp_doc, insert_before_page_number, sourceDoc.mp_doc, sourcePageSet.mp_impl, (enum TRN_PDFDocInsertFlag) flag));
}

inline void PDFDoc::MovePages(int moveBeforeThisPage
							  , PDFDoc& sourceDoc
							  , int startPage
							  , int endPage
							  , enum InsertFlag flag
#ifndef SWIG
							  , Common::ProgressMonitor * monitor
#endif
	)
{
	TRN_ProgressMonitor* m = 0;
#ifndef SWIG
	m = (TRN_ProgressMonitor*)monitor;
#endif
	REX(TRN_PDFDocMovePages(mp_doc, moveBeforeThisPage, sourceDoc.mp_doc, startPage, endPage, (enum TRN_PDFDocInsertFlag) flag));
}

inline void PDFDoc::MovePages(int moveBeforeThisPage
							  , PDFDoc& sourceDoc
							  , const PageSet& sourcePageSet
							  , enum InsertFlag flag
#ifndef SWIG
							  , Common::ProgressMonitor * monitor
#endif
	)
{	
	TRN_ProgressMonitor* m = 0;
#ifndef SWIG
	m = (TRN_ProgressMonitor*)monitor;
#endif
	REX(TRN_PDFDocMovePageSet(mp_doc, moveBeforeThisPage, sourceDoc.mp_doc, sourcePageSet.mp_impl, (enum TRN_PDFDocInsertFlag) flag));
}

inline void PDFDoc::PagePushFront(Page page) {
	REX(TRN_PDFDocPagePushFront(mp_doc, page.mp_page));
}

inline void PDFDoc::PagePushBack(Page page) {
	REX(TRN_PDFDocPagePushBack(mp_doc, page.mp_page));
}

inline std::vector<Page> PDFDoc::ImportPages(const std::vector<Page>& pages, bool import_bookmarks) {
	assert(sizeof(Page) == sizeof(TRN_Obj));
	size_t sz = pages.size();
	std::vector<Page> result(sz);
	if (sz>0) {
		REX(TRN_PDFDocImportPages(mp_doc,(TRN_Page*)&(pages[0]),
			int(sz),BToTB(import_bookmarks),(TRN_Page*)&(result[0])))
	}
	return result;
}

inline Page PDFDoc::PageCreate(const Rect& media_box) {
	TRN_Page result;
	REX(TRN_PDFDocPageCreate(mp_doc, (const TRN_Rect*)&media_box,&result));
	return Page(result);
}

inline void PDFDoc::AppendTextDiff(Page page1, Page page2) {
	REX(TRN_PDFDocAppendTextDiffPage(mp_doc, page1.mp_page, page2.mp_page));
}

inline void PDFDoc::AppendTextDiff(PDFDoc& doc1, PDFDoc& doc2) {
	REX(TRN_PDFDocAppendTextDiffDoc(mp_doc, doc1.mp_doc, doc2.mp_doc));
}

inline Bookmark PDFDoc::GetFirstBookmark() {
	TRN_Bookmark result;
	REX(TRN_PDFDocGetFirstBookmark(mp_doc,&result));
	return Bookmark(result);
}

inline void PDFDoc::AddRootBookmark(Bookmark root_bookmark) {
	REX(TRN_PDFDocAddRootBookmark(mp_doc, root_bookmark.mp_obj));
}

inline SDF::Obj PDFDoc::GetTrailer () {
	TRN_Obj result;
	REX(TRN_PDFDocGetTrailer(mp_doc,&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::GetRoot() {
	TRN_Obj result;
	REX(TRN_PDFDocGetRoot(mp_doc, &result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::GetPages() {
	TRN_Obj result;
	REX(TRN_PDFDocGetPages(mp_doc, &result));
	return SDF::Obj(result);
}

inline int PDFDoc::GetPageCount () {
	int result;
	REX(TRN_PDFDocGetPageCount(mp_doc, &result));
	return result;
}
        
inline TRN_UInt64 PDFDoc::GetDownloadedByteCount () {
    TRN_UInt64 result;
    REX(TRN_PDFDocGetDownloadedByteCount(mp_doc, &result));
    return result;
}

inline TRN_UInt64 PDFDoc::GetTotalRemoteByteCount () {
    TRN_UInt64 result;
    REX(TRN_PDFDocGetTotalRemoteByteCount(mp_doc, &result));
    return result;
}

inline FieldIterator PDFDoc::GetFieldIterator() {
	TRN_Iterator result;
	REX(TRN_PDFDocGetFieldIteratorBegin(mp_doc, &result));
	Common::Iterator<Field> t(result);
	return t;
}

inline FieldIterator PDFDoc::GetFieldIterator(const UString& field_name) {
	TRN_Iterator result;
	REX(TRN_PDFDocGetFieldIterator(mp_doc, field_name.mp_impl, &result));
	return Common::Iterator<Field>(result);
}

inline Field PDFDoc::GetField(const UString& field_name) {
	TRN_Field result;
	TRN_PDFDocGetField(mp_doc, field_name.mp_impl,&result);
	return*((Field*)&result);
}

inline Field PDFDoc::FieldCreate(const UString& field_name, Field::Type type, SDF::Obj field_value, SDF::Obj def_field_value) {
	TRN_Field result;
	REX(TRN_PDFDocFieldCreate(mp_doc,field_name.mp_impl,(enum TRN_FieldType)type,
		field_value.mp_obj,def_field_value.mp_obj,&result)); 
	return *((Field*)&result);
}

inline Field PDFDoc::FieldCreate(const UString& field_name, Field::Type type, const UString& field_value, const UString& def_field_value)
{
	TRN_Field result;
	REX(TRN_PDFDocFieldCreateFromStrings(mp_doc, field_name.mp_impl, (enum TRN_FieldType)type, field_value.mp_impl, def_field_value.mp_impl,&result));
	return *((Field*)&result);
}

inline void PDFDoc::RefreshFieldAppearances() {
	REX(TRN_PDFDocRefreshFieldAppearances(mp_doc));
}

inline void PDFDoc::RefreshAnnotAppearances(const RefreshOptions* opts)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	RefreshOptions* opt = const_cast<RefreshOptions*>(opts);
	opt_in.impl = opt ? opt->GetInternalObj().mp_obj : 0;
	REX(TRN_PDFDocRefreshAnnotAppearances(mp_doc, &opt_in));
}

inline void PDFDoc::FlattenAnnotations(bool forms_only) {
	REX(TRN_PDFDocFlattenAnnotations(mp_doc, BToTB(forms_only)));
}

inline SDF::Obj PDFDoc::GetAcroForm() {
	TRN_Obj result;
	REX(TRN_PDFDocGetAcroForm(mp_doc,&result));
	return SDF::Obj(result);
}

inline Action PDFDoc::GetOpenAction() {
	TRN_Action result;
	REX(TRN_PDFDocGetOpenAction(mp_doc,&result));
	return Action(result);
}

inline void PDFDoc::SetOpenAction(const Action& action) {
	REX(TRN_PDFDocSetOpenAction(mp_doc,action.mp_action));
}

inline void PDFDoc::AddFileAttachment(const UString& file_key, FileSpec embedded_file) {
	REX(TRN_PDFDocAddFileAttachment(mp_doc,file_key.mp_impl,embedded_file.mp_impl));
}

inline SDF::Obj PDFDoc::CreateIndirectName(const char* name) {
	TRN_Obj result;
	REX(TRN_PDFDocCreateIndirectName(mp_doc,name,&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectArray() {
	TRN_Obj result;
	REX(TRN_PDFDocCreateIndirectArray(mp_doc,&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectBool(bool value) {
	TRN_Obj result;
	REX(TRN_PDFDocCreateIndirectBool(mp_doc,BToTB(value),&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectDict() {
	TRN_Obj result;
	REX(TRN_PDFDocCreateIndirectDict(mp_doc,&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectNull() {
	TRN_Obj result;
	REX(TRN_PDFDocCreateIndirectNull(mp_doc,&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectNumber(double value) {
	TRN_Obj result;
	REX(TRN_PDFDocCreateIndirectNumber(mp_doc,value,&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectString(const UChar* value, UInt32 size) {
	TRN_Obj result;
	REX(TRN_PDFDocCreateIndirectString(mp_doc,(const TRN_UChar*)value, size,&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectString(const UString& str) {
	TRN_Obj result;
	REX(TRN_PDFDocCreateIndirectStringFromUString(mp_doc,str.mp_impl,&result));
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectStream(Filters::FilterReader& data, Filters::Filter filter_chain) {
	TRN_Obj result;
	filter_chain.m_owner = false;
	REX(TRN_PDFDocCreateIndirectStreamFromFilter(mp_doc,data.m_impl,filter_chain.m_impl,&result));
	// Note: Transfer the ownership
	filter_chain.m_impl = 0;
	return SDF::Obj(result);
}

inline SDF::Obj PDFDoc::CreateIndirectStream(const char* data, const size_t data_size, Filters::Filter filter_chain) {
	TRN_Obj result;
	filter_chain.m_owner = false;
	REX(TRN_PDFDocCreateIndirectStream(mp_doc,data, data_size, filter_chain.m_impl, &result));
	// Note: Transfer the ownership
	filter_chain.m_impl = 0;
	return SDF::Obj(result);
}

inline SDF::SDFDoc& PDFDoc::GetSDFDoc () {
	return *((SDF::SDFDoc*)this);
}

inline void PDFDoc::Lock() {
	REX(TRN_PDFDocLock(mp_doc));
}

inline void PDFDoc::Unlock() {
	REX(TRN_PDFDocUnlock(mp_doc));
}

inline void PDFDoc::LockRead() {
	REX(TRN_PDFDocLockRead(mp_doc));
}

inline void PDFDoc::UnlockRead() {
	REX(TRN_PDFDocUnlockRead(mp_doc));
}

inline bool PDFDoc::TryLock( int milliseconds )
{
	TRN_Bool result;
	REX(TRN_PDFDocTimedLock(mp_doc,milliseconds,&result));
	return TBToB(result);
}

inline bool PDFDoc::TryLockRead( int milliseconds )
{
	TRN_Bool result;
	REX(TRN_PDFDocTimedLockRead(mp_doc,milliseconds,&result));
	return TBToB(result);
}

inline UString PDFDoc::GetFileName() const
{
	TRN_UString result;
	REX(TRN_SDFDocGetFileName((TRN_SDFDoc)mp_doc, &result));
	return UString(result);	
}

inline void PDFDoc::GenerateThumbnails(UInt32 size)
{
    REX(TRN_PDFDocGenerateThumbnails(mp_doc, (TRN_UInt32) size));
}

inline void PDFDoc::AppendVisualDiff(Page p1, Page p2, DiffOptions* opts)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = opts ? opts->GetInternalObj().mp_obj : 0;
	REX(TRN_PDFDocAppendVisualDiff(mp_doc, p1.mp_page, p2.mp_page, &opt_in));
}

inline PDFDocViewPrefs PDFDoc::GetViewPrefs() {
	TRN_PDFDocViewPrefs result;
	REX(TRN_PDFDocGetViewPrefs(mp_doc,&result));
    return PDFDocViewPrefs(result);
}

inline SDF::Obj PDFDoc::GetTriggerAction(PDFDoc::ActionTriggerEvent trigger)
{
	TRN_Obj result;
	REX(TRN_PDFDocGetTriggerAction(mp_doc, (enum TRN_PDFDocEventType)trigger, &result));
	return SDF::Obj(result);
}

inline PageLabel PDFDoc::GetPageLabel(int page_num) {
	TRN_PageLabel result;
	REX(TRN_PDFDocGetPageLabel(mp_doc,page_num,&result));
	return *((PageLabel*)(void*)&result);
}

inline void PDFDoc::SetPageLabel(int page_num, PageLabel& label) {
	REX(TRN_PDFDocSetPageLabel(mp_doc,page_num,(TRN_PageLabel*)(void*)&label));
}

inline void PDFDoc::RemovePageLabel(int page_num) {
	REX(TRN_PDFDocRemovePageLabel(mp_doc,page_num));
}

inline Struct::STree PDFDoc::GetStructTree() {
	TRN_STree result;
	REX(TRN_PDFDocGetStructTree(mp_doc,&result));
	return Struct::STree(result);
}

inline bool PDFDoc::HasOC() const {
	TRN_Bool result;
	REX(TRN_PDFDocHasOC(mp_doc,&result));
	return TBToB(result);
}

inline SDF::Obj PDFDoc::GetOCGs() const {
	RetObj(TRN_PDFDocGetOCGs(mp_doc, &result));
}

inline OCG::Config PDFDoc::GetOCGConfig() const {
	TRN_OCGConfig cfg; 
	REX(TRN_PDFDocGetOCGConfig(mp_doc, &cfg));
	return OCG::Config(cfg);
}

inline FDF::FDFDoc PDFDoc::FDFExtract(enum ExtractFlag flag) {
	TRN_FDFDoc result;
	REX(TRN_PDFDocFDFExtract(mp_doc, (enum TRN_PDFDocExtractFlag) flag, &result));
	return FDF::FDFDoc(result);
}

inline FDF::FDFDoc PDFDoc::FDFExtract(PageSet& pages_to_extract, enum ExtractFlag flag) {
	TRN_FDFDoc result;
	REX(TRN_PDFDocFDFExtractPageSet(mp_doc, pages_to_extract.mp_impl, (enum TRN_PDFDocExtractFlag) flag, &result));
	return FDF::FDFDoc(result);
}

inline FDF::FDFDoc PDFDoc::FDFExtract(const std::vector<Annot>& annotations) {
	TRN_FDFDoc result;
	REX(TRN_PDFDocFDFExtractAnnots(mp_doc, (TRN_Annot*)&(annotations[0]), int(annotations.size()), &result));
	return FDF::FDFDoc(result);
}

inline FDF::FDFDoc PDFDoc::FDFExtract(const std::vector<Annot>& annot_added, const std::vector<Annot>& annot_modified, const std::vector<Annot>& annot_deleted)
{
	TRN_FDFDoc result;
	TRN_Annot* annot_added_ptr = annot_added.empty() ? 0 : (TRN_Annot*)&(annot_added[0]);
	TRN_Annot* annot_modified_ptr = annot_modified.empty() ? 0 : (TRN_Annot*)&(annot_modified[0]);
	TRN_Annot* annot_deleted_ptr = annot_deleted.empty() ? 0 : (TRN_Annot*)&(annot_deleted[0]);
	REX(TRN_PDFDocFDFExtractCommand(mp_doc, annot_added_ptr, int(annot_added.size()), annot_modified_ptr, int(annot_modified.size()), annot_deleted_ptr, int(annot_deleted.size()), &result));
	return FDF::FDFDoc(result);
}

inline void PDFDoc::FDFMerge(FDF::FDFDoc& fdf_doc) {
	REX(TRN_PDFDocFDFMerge(mp_doc,fdf_doc.mp_doc));
}

inline void PDFDoc::FDFUpdate(FDF::FDFDoc& fdf_doc) {
	REX(TRN_PDFDocFDFUpdate(mp_doc, fdf_doc.mp_doc));
}

inline PDFDocInfo PDFDoc::GetDocInfo() {
	TRN_PDFDocInfo result;
	REX(TRN_PDFDocGetDocInfo(mp_doc,&result));
	return PDFDocInfo(result);
}

inline void PDFDoc::AddHighlights(const UString& hilite) {
	REX(TRN_PDFDocAddHighlights(mp_doc, hilite.mp_impl));
}

inline bool PDFDoc::IsTagged() {
	TRN_Bool result;
	REX(TRN_PDFDocIsTagged(mp_doc, &result));
	return TBToB(result);
}

inline void PDFDoc::SaveViewerOptimized(const UString& path, const ViewerOptimizedOptions& opts)
{
	REX(TRN_PDFDocSaveViewerOptimized(mp_doc, path.mp_impl, opts.m_obj));
}

inline void PDFDoc::SaveViewerOptimized(const char* &out_buf, size_t& out_buf_size, const ViewerOptimizedOptions& opts)
{
	REX(TRN_PDFDocSaveViewerOptimizedBuffer(mp_doc, &out_buf, &out_buf_size, opts.m_obj));
}

inline PDFDoc::SignaturesVerificationStatus PDFDoc::VerifySignedDigitalSignatures(const VerificationOptions& in_opts) const
{
	TRN_PDFDocSignaturesVerificationStatus result;
	REX(TRN_PDFDocVerifySignedDigitalSignatures(mp_doc, in_opts.m_impl, &result));
	return (SignaturesVerificationStatus)result;
}


//for xamarin use only
inline PDFDoc* PDFDoc::CreateInternal(ptrdiff_t impl) {
	return new PDFDoc((TRN_PDFDoc)impl);
}

inline ptrdiff_t PDFDoc::GetHandleInternal() {
    return (ptrdiff_t) mp_doc;
}
	}; // namespace PDF
}; // namespace pdftron 

// OCG API --------------------------------------------------------

#include <PDF/OCG/Config.h>
#include <PDF/OCG/Group.h>
#include <PDF/OCG/Context.h>
#include <PDF/OCG/OCMD.h>
#include <C/PDF/OCG/TRN_OCGConfig.h>
#include <C/PDF/OCG/TRN_OCG.h>
#include <C/PDF/OCG/TRN_OCGContext.h>
#include <C/PDF/OCG/TRN_OCMD.h>

namespace pdftron{
	namespace PDF {
		namespace OCG {

//------------------------------------------------------------------
inline Config::Config (SDF::Obj cfg) {
	REX(TRN_OCGConfigCreateFromObj(cfg.mp_obj,&mp_obj)); 
}

inline Config::Config (const Config& cfg)
{
	REX(TRN_OCGConfigCopy(cfg.mp_obj,&mp_obj));
}

inline Config& Config::operator=(const Config& cfg) {
	REX(TRN_OCGConfigCopy(cfg.mp_obj,&mp_obj));
	return *this;
}

inline SDF::Obj Config::GetSDFObj () const {
	TRN_Obj result;
	REX(TRN_OCGConfigGetSDFObj(mp_obj,&result));
	return SDF::Obj(result);
}

inline Config Config::Create(PDF::PDFDoc& doc, bool default_config) {
	TRN_OCGConfig cfg;
	REX(TRN_OCGConfigCreate(doc.mp_doc, BToTB(default_config), &cfg));
	return Config(cfg);
}

inline SDF::Obj Config::GetOrder() const {
	TRN_Obj result;
	REX(TRN_OCGConfigGetOrder(mp_obj,&result));
	return SDF::Obj(result);
}

inline void Config::SetOrder(SDF::Obj ocgs_array) {
	REX(TRN_OCGConfigSetOrder(mp_obj, ocgs_array.mp_obj));
}

inline UString Config::GetName() const {
	RetStr(TRN_OCGConfigGetName(mp_obj, &result));	
}

inline void Config::SetName(const UString& name) {
	REX(TRN_OCGConfigSetName(mp_obj, name.mp_impl));
}

inline UString Config::GetCreator() const {
	RetStr(TRN_OCGConfigGetCreator(mp_obj, &result));
}

inline void Config::SetCreator(const UString& name) {
	REX(TRN_OCGConfigSetCreator(mp_obj, name.mp_impl));
}

inline const char* Config::GetInitBaseState() const {
	const char* result;
	REX(TRN_OCGConfigGetInitBaseState(mp_obj, &result));
	return result;
}

inline SDF::Obj Config::GetInitOnStates() const {
	TRN_Obj result;
	REX(TRN_OCGConfigGetInitOnStates(mp_obj,&result));
	return SDF::Obj(result);
}

inline SDF::Obj Config::GetInitOffStates() const {
	TRN_Obj result;
	REX(TRN_OCGConfigGetInitOffStates(mp_obj,&result));
	return SDF::Obj(result);
}

inline void Config::SetInitBaseState(const char* state) {
	REX(TRN_OCGConfigSetInitBaseState(mp_obj, state));
}

inline void Config::SetInitOnStates(SDF::Obj on_array) {
	REX(TRN_OCGConfigSetInitOnStates(mp_obj, on_array.mp_obj));
}

inline void Config::SetInitOffStates(SDF::Obj off_array) {
	REX(TRN_OCGConfigSetInitOffStates(mp_obj, off_array.mp_obj));
}

inline SDF::Obj Config::GetIntent() const  {
	TRN_Obj result;
	REX(TRN_OCGConfigGetIntent(mp_obj,&result));
	return SDF::Obj(result);
}

inline void Config::SetIntent(SDF::Obj intent) {
	REX(TRN_OCGConfigSetIntent(mp_obj, intent.mp_obj));
}

inline SDF::Obj Config::GetLockedOCGs() const {
	TRN_Obj result;
	REX(TRN_OCGConfigGetLockedOCGs(mp_obj,&result));
	return SDF::Obj(result);
}

inline void Config::SetLockedOCGs(SDF::Obj locked_ocg_array) {
	REX(TRN_OCGConfigSetLockedOCGs(mp_obj, locked_ocg_array.mp_obj));
}

//------------------------------------------------------------------

inline Group::Group (SDF::Obj cfg) {
	REX(TRN_OCGCreateFromObj(cfg.mp_obj, &mp_obj)); 
}

inline Group::Group (const Group& cfg)
{
	REX(TRN_OCGCopy(cfg.mp_obj,&mp_obj));
}

inline Group& Group::operator=(const Group& cfg) {
	REX(TRN_OCGCopy(cfg.mp_obj,&mp_obj));
	return *this;
}

inline SDF::Obj Group::GetSDFObj () const {
	TRN_Obj result;
	REX(TRN_OCGGetSDFObj(mp_obj,&result));
	return SDF::Obj(result);
}

inline bool Group::IsValid() const {
	TRN_Bool result;
	REX(TRN_OCGIsValid(mp_obj,&result));
	return TBToB(result);
}

inline Group Group::Create(PDFDoc& doc, const UString& name) {
	TRN_OCG g;
	REX(TRN_OCGCreate(doc.mp_doc, name.mp_impl, &g));
	return Group(g);
}

inline UString Group::GetName() const {
	RetStr(TRN_OCGGetName(mp_obj, &result));	
}

inline void Group::SetName(const UString& name) {
	REX(TRN_OCGSetName(mp_obj, name.mp_impl));
}

inline SDF::Obj Group::GetIntent() const  {
	TRN_Obj result;
	REX(TRN_OCGGetIntent(mp_obj,&result));
	return SDF::Obj(result);
}

inline void Group::SetIntent(SDF::Obj intent) {
	REX(TRN_OCGSetIntent(mp_obj, intent.mp_obj));
}

inline bool Group::HasUsage() const {
	TRN_Bool result;
	REX(TRN_OCGHasUsage(mp_obj, &result));
	return TBToB(result);
}

inline SDF::Obj Group::GetUsage(const char* key) const {
	TRN_Obj result;
	REX(TRN_OCGGetUsage(mp_obj, key, &result));
	return SDF::Obj(result);
}

inline bool Group::GetCurrentState(const Context& context) const {
	TRN_Bool result;
	REX(TRN_OCGGetCurrentState(mp_obj, context.mp_obj, &result));
	return TBToB(result);
}

inline void Group::SetCurrentState(Context& context, bool state) {
	REX(TRN_OCGSetCurrentState(mp_obj, context.mp_obj, BToTB(state)));
}

inline bool Group::GetInitialState(const Config& config) const {
	TRN_Bool result;
	REX(TRN_OCGGetInitialState(mp_obj, config.mp_obj, &result));
	return TBToB(result);
}

inline void Group::SetInitialState(Config& config, bool state) {
	REX(TRN_OCGSetInitialState(mp_obj, config.mp_obj, BToTB(state)));
}

inline bool Group::IsLocked(const Config& config) const {
	TRN_Bool result;
	REX(TRN_OCGIsLocked(mp_obj, config.mp_obj, &result));
	return TBToB(result);
}

inline void Group::SetLocked(const Config& config, bool state) {
	REX(TRN_OCGSetLocked(mp_obj, config.mp_obj, BToTB(state)));
}

//------------------------------------------------------------------

//for xamarin use only
inline Context* Context::CreateInternal(ptrdiff_t impl) {
	return new Context((TRN_OCGContext)impl);
}

inline ptrdiff_t Context::GetHandleInternal() {
    return (ptrdiff_t) mp_obj;
}

inline Context::Context(TRN_OCGContext ctx) 
	: mp_obj(ctx), m_owner(false) 
{
}

inline Context::Context (const Context& cfg) 
	: mp_obj(0), m_owner(true) 
{
	REX(TRN_OCGContextCopy(cfg.mp_obj,&mp_obj));
}

inline Context::~Context() {
	if (m_owner) {
		DREX(mp_obj, TRN_OCGContextDestroy(mp_obj));
	}
}

inline void Context::Destroy() {
	if (m_owner) {
		REX(TRN_OCGContextDestroy(mp_obj));
	}
	mp_obj=0;
}

inline Context& Context::operator=(const Context& cfg) {
	if (m_owner) {
		REX(TRN_OCGContextDestroy(mp_obj));
	}
	REX(TRN_OCGContextCopy(cfg.mp_obj,&mp_obj));
	return *this;
}

inline Context::Context(const Config& config) 
	: mp_obj(0), m_owner(true) 
{
	REX(TRN_OCGContextCreateFromConfig(config.mp_obj,&mp_obj));
}

inline bool Context::GetState(const Group& g) const {
	TRN_Bool result;
	REX(TRN_OCGContextGetState(mp_obj, g.mp_obj, &result));
	return TBToB(result);
}

inline void Context::SetState(const Group& g, bool state) {
	REX(TRN_OCGContextSetState(mp_obj, g.mp_obj, BToTB(state)));
}

inline void Context::ResetStates(bool all_on) {
	REX(TRN_OCGContextResetStates(mp_obj, BToTB(all_on)));
}

inline void Context::SetNonOCDrawing(bool draw_non_OC) {
	REX(TRN_OCGContextSetNonOCDrawing(mp_obj, BToTB(draw_non_OC)));
}

inline bool Context::GetNonOCDrawing() const {
	TRN_Bool result;
	REX(TRN_OCGContextGetNonOCDrawing(mp_obj, &result));
	return TBToB(result);
}

inline void Context::SetOCDrawMode(OCDrawMode oc_draw_mode) {
	REX(TRN_OCGContextSetOCDrawMode(mp_obj, (TRN_OCGContextOCDrawMode) oc_draw_mode));
}

inline Context::OCDrawMode Context::GetOCMode() const {
	enum TRN_OCGContextOCDrawMode result;
	REX(TRN_OCGContextGetOCMode(mp_obj, &result));
	return (Context::OCDrawMode) result;
}

//------------------------------------------------------------------

inline OCMD OCMD::Create(PDFDoc& doc, SDF::Obj ocgs, VisibilityPolicyType vis_policy) {
	TRN_OCMD g;
	REX(TRN_OCMDCreate(doc.mp_doc, ocgs.mp_obj, (TRN_OCMDVisibilityPolicyType)vis_policy, &g));
	return OCMD(g);
}

inline OCMD::OCMD (SDF::Obj ocmd) {
	REX(TRN_OCMDCreateFromObj(ocmd.mp_obj, &mp_obj)); 
}

inline OCMD::OCMD (const OCMD& cfg)
{
	REX(TRN_OCMDCopy(cfg.mp_obj,&mp_obj));
}

inline OCMD& OCMD::operator=(const OCMD& cfg) {
	REX(TRN_OCMDCopy(cfg.mp_obj,&mp_obj));
	return *this;
}

inline SDF::Obj OCMD::GetSDFObj () const {
	TRN_Obj result;
	REX(TRN_OCMDGetSDFObj(mp_obj,&result));
	return SDF::Obj(result);
}

inline SDF::Obj OCMD::GetOCGs() const {
	TRN_Obj result;
	REX(TRN_OCMDGetOCGs(mp_obj, &result));
	return SDF::Obj(result);
}

inline SDF::Obj OCMD::GetVisibilityExpression() const {
	TRN_Obj result;
	REX(TRN_OCMDGetVisibilityExpression(mp_obj, &result));
	return SDF::Obj(result);
}

inline bool OCMD::IsValid() const {
	TRN_Bool result;
	REX(TRN_OCMDIsValid(mp_obj,&result));
	return TBToB(result);
}

inline bool OCMD::IsCurrentlyVisible(const Context& context) const {
	TRN_Bool result;
	REX(TRN_OCMDIsCurrentlyVisible(mp_obj, context.mp_obj, &result));
	return TBToB(result);
}

inline OCMD::VisibilityPolicyType OCMD::GetVisibilityPolicy() const {
	enum TRN_OCMDVisibilityPolicyType result;
	REX(TRN_OCMDGetVisibilityPolicy(mp_obj,&result));
	return (OCMD::VisibilityPolicyType)result;
}

inline void OCMD::SetVisibilityPolicy(VisibilityPolicyType vis_policy) {
	REX(TRN_OCMDSetVisibilityPolicy(mp_obj, (TRN_OCMDVisibilityPolicyType) vis_policy));
}


//------------------------------------------------------------------

		}; // namespace OCG
		
namespace Struct {

//ContentItem
inline ContentItem::ContentItem(const ContentItem& c) {
	REX(TRN_ContentItemCopy(&(c.mp_item),&mp_item));
}

inline ContentItem& ContentItem::operator= (const ContentItem& c) {
	REX(TRN_ContentItemCopy(&(c.mp_item),&mp_item));
	return *this;
}
	
inline ContentItem::Type ContentItem::GetType() const {
	enum TRN_ContentItemType result;
	REX(TRN_ContentItemGetType(&(mp_item),&result));
	return (Type)result;
}

inline SElement ContentItem::GetParent() {
	TRN_SElement result;
	REX(TRN_ContentItemGetParent(&(mp_item),&result));
	return SElement(result);
}

inline Page ContentItem::GetPage() {
	TRN_Page result;
	REX(TRN_ContentItemGetPage(&mp_item,&result));
	return Page(result);
}

inline SDF::Obj ContentItem::GetSDFObj () const {
	TRN_Obj result;
	REX(TRN_ContentItemGetSDFObj(&mp_item,&result));
	return SDF::Obj(result);
}

inline int ContentItem::GetMCID() const {	
	int result;
	REX(TRN_ContentItemGetMCID(&mp_item,&result));
	return result;
}

inline SDF::Obj ContentItem::GetContainingStm() const {
	TRN_Obj result;
	REX(TRN_ContentItemGetContainingStm(&mp_item,&result));
	return SDF::Obj(result);
}

inline SDF::Obj ContentItem::GetStmOwner() const {
	TRN_Obj result;
	REX(TRN_ContentItemGetStmOwner(&mp_item,&result));
	return SDF::Obj(result);
}

inline SDF::Obj ContentItem::GetRefObj() const {
	TRN_Obj result;
	REX(TRN_ContentItemGetRefObj(&mp_item,&result));
	return SDF::Obj(result);
}

inline ContentItem::ContentItem(TRN_ContentItem impl) : mp_item(impl) {}


//SElement

inline SElement::SElement (SDF::Obj dict) {
	REX(TRN_SElementCreate(dict.mp_obj,&mp_elem));
}
	
inline SElement::SElement (const SElement& c) {
	REX(TRN_SElementAssign(&mp_elem, &(c.mp_elem)));
}

inline SElement& SElement::operator= (const SElement& c) {
	REX(TRN_SElementAssign(&mp_elem,&(c.mp_elem)));
	return *this;
}

inline SElement SElement::Create(PDFDoc& doc, const char* struct_type)
{
	TRN_SElement result;
	REX(TRN_SElementCreateFromPDFDoc(doc.mp_doc, struct_type, &result));
	return SElement(result);
}

inline void SElement::Insert(SElement& kid, int insert_before)
{
	REX(TRN_SElementInsert(&mp_elem, &(kid.mp_elem), insert_before));
}

inline int SElement::CreateContentItem(PDFDoc& doc, Page& page, int insert_before)
{
	int result;
	REX(TRN_SElementCreateContentItem(&mp_elem, doc.mp_doc, page.mp_page, insert_before, &result));
	return result;
}


inline bool SElement::IsValid() const {
	RetBool(TRN_SElementIsValid(&mp_elem,&result));

}

inline const char* SElement::GetType() const {
	const char* result;
	REX(TRN_SElementGetType(&mp_elem,&result));
	return result;
}

inline int SElement::GetNumKids() const {
	int result;
	REX(TRN_SElementGetNumKids(&mp_elem,&result));
	return result;
}

inline bool SElement::IsContentItem(int index) const
{
	TRN_Bool result;
	REX(TRN_SElementIsContentItem(&mp_elem,index,&result));
	return TBToB(result);
}

inline ContentItem SElement::GetAsContentItem(int index) const
{
	TRN_ContentItem result;
	REX(TRN_SElementGetAsContentItem(&mp_elem,index,&result));
	return ContentItem(result);
}

inline SElement SElement::GetAsStructElem(int index) const {
	TRN_SElement result;
	REX(TRN_SElementGetAsStructElem(&mp_elem,index,&result));
	return SElement(result);
}

inline SElement SElement::GetParent() const {
	TRN_SElement result;
	REX(TRN_SElementGetParent(&mp_elem,&result));
	return SElement(result);
}

inline STree SElement::GetStructTreeRoot() const {
	TRN_STree result;
	REX(TRN_SElementGetStructTreeRoot(&mp_elem,&result));
	return STree(result);
}

inline bool SElement::HasTitle() const {
	TRN_Bool result;
	REX(TRN_SElementHasTitle(&mp_elem,&result));
	return TBToB(result);
}

inline UString SElement::GetTitle() const {
	TRN_UString result;
	REX(TRN_SElementGetTitle(&mp_elem,&result));
	return UString(result);
}

inline SDF::Obj SElement::GetID() const {
	TRN_Obj result;
	REX(TRN_SElementGetID(&mp_elem, &result));
	return SDF::Obj(result);
}

inline bool SElement::HasActualText() const {
	TRN_Bool result;
	REX(TRN_SElementHasActualText(&mp_elem, &result));
	return TBToB(result);
}

inline UString SElement::GetActualText() const {
	TRN_UString result;
	REX(TRN_SElementGetActualText(&mp_elem,&result));
	return UString(result);
}

inline bool SElement::HasAlt() const {
	TRN_Bool result;
	REX(TRN_SElementHasAlt(&mp_elem,&result));
	return TBToB(result);
}

inline UString SElement::GetAlt() const {
	TRN_UString result;
	REX(TRN_SElementGetAlt(&mp_elem,&result));
	return UString(result);
}

inline SDF::Obj SElement::GetSDFObj() const {
	TRN_Obj result;
	REX(TRN_SElementGetSDFObj(&mp_elem,&result));
	return SDF::Obj(result);
}


inline SElement::SElement(TRN_SElement impl) : mp_elem(impl) {}


//STree

inline STree::STree (SDF::Obj struct_dict) {
	REX(TRN_STreeCreate(struct_dict.mp_obj,&mp_tree));
}
inline STree::STree (const STree& c) {
	REX(TRN_STreeCopy(c.mp_tree,&mp_tree));
}

inline STree& STree::operator= (const STree& c) {
	REX(TRN_STreeCopy(c.mp_tree,&mp_tree));
	return *this;
}

inline STree STree::Create(PDF::PDFDoc& doc)
{
	TRN_STree result;
	REX(TRN_STreeCreateFromPDFDoc(doc.mp_doc, &result));
	return STree(result);
}

inline void STree::Insert(Struct::SElement& kid, int insert_before)
{
	REX(TRN_STreeInsert(mp_tree, &(kid.mp_elem), insert_before));
}

inline bool STree::IsValid() const {
	RetBool(TRN_STreeIsValid(mp_tree,&result));
}

inline int STree::GetNumKids() {
	RetInt(TRN_STreeGetNumKids(mp_tree,&result));
}

inline SElement STree::GetKid(int index) {
	TRN_SElement result;
	REX(TRN_STreeGetKid(mp_tree,index,&result));
	return SElement(result);
}

inline SElement STree::GetElement(const char* id_buf, int id_buf_sz) {
	TRN_SElement result;
	REX(TRN_STreeGetElement(mp_tree,id_buf,id_buf_sz,&result));
	return result;
}

inline RoleMap STree::GetRoleMap() const {
	TRN_RoleMap result;
	REX(TRN_STreeGetRoleMap(mp_tree,&result));
	return RoleMap(result);
}

inline ClassMap STree::GetClassMap() const {
	TRN_ClassMap result;
	REX(TRN_STreeGetClassMap(mp_tree,&result));
	return ClassMap(result);
}

inline SDF::Obj STree::GetSDFObj () const {
	RetObj(TRN_STreeGetSDFObj(mp_tree,&result));
}

inline STree::STree(TRN_STree impl) : mp_tree(impl) {}

inline STree::STree() : mp_tree(0) {}

		}; // namespace Struct
	
	}; // namespace PDF
}; // namespace pdftron


#endif
