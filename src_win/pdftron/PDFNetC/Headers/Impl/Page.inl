#ifndef HPP_PDFTRON_PDF_PAGE_INL
#define HPP_PDFTRON_PDF_PAGE_INL

#include <SDF/Obj.h>
#include <PDF/Field.h>
#include <PDF/Action.h>
#include <PDF/Annot.h>
#include <PDF/Destination.h>
#include <PDF/Page.h>
#include <PDF/Annots/Caret.h>
#include <PDF/Annots/Circle.h>
#include <PDF/Annots/FileAttachment.h>
#include <PDF/Annots/FreeText.h>
#include <PDF/Annots/Highlight.h>
#include <PDF/Annots/Ink.h>
#include <PDF/Annots/Line.h>
#include <PDF/Annots/Link.h>
#include <PDF/Annots/Markup.h>
#include <PDF/Annots/Movie.h>
#include <PDF/Annots/PolyLine.h>
#include <PDF/Annots/Popup.h>
#include <PDF/Annots/Redaction.h>
#include <PDF/Annots/RubberStamp.h>
#include <PDF/Annots/Screen.h>
#include <PDF/Annots/Sound.h>
#include <PDF/Annots/Square.h>
#include <PDF/Annots/StrikeOut.h>
#include <PDF/Annots/Text.h>
#include <PDF/Annots/TextMarkup.h>
#include <PDF/Annots/Underline.h>
#include <PDF/Annots/Squiggly.h>
#include <PDF/Annots/Watermark.h>

#ifdef SWIG
#define Line LineAnnot
#define Redaction RedactionAnnot
#define Highlight HighlightAnnot
#endif

namespace pdftron {
	namespace PDF {

inline Destination Destination::CreateXYZ(Page page, double left, double top, double zoom)
{
	TRN_Destination result;
	REX(TRN_DestinationCreateXYZ(page.mp_page,left,top,zoom,&result))
	return Destination(result);
}
inline Destination Destination::CreateFit(Page page)
{
	TRN_Destination result;
	REX(TRN_DestinationCreateFit(page.mp_page,&result));
	return Destination(result);
}

inline Destination Destination::CreateFitH(Page page, double top)
{
	TRN_Destination result;
	REX(TRN_DestinationCreateFitH(page.mp_page,top,&result));
	return Destination(result);
}

inline Destination Destination::CreateFitV(Page page, double left)
{
	TRN_Destination result;
	REX(TRN_DestinationCreateFitV(page.mp_page,left,&result));
	return Destination(result);
}

inline Destination Destination::CreateFitR(Page page, double left, double bottom,	double right, double top)
{
	TRN_Destination result;
	REX(TRN_DestinationCreateFitR(page.mp_page,left,bottom,right,top,&result));
	return Destination(result);
}

inline Destination Destination::CreateFitB(Page page)
{
	TRN_Destination result;
	REX(TRN_DestinationCreateFitB(page.mp_page,&result));
	return Destination(result);
}

inline Destination Destination::CreateFitBH(Page page, double top)
{
	TRN_Destination result;
	REX(TRN_DestinationCreateFitBH(page.mp_page,top,&result));
	return Destination(result);
}

inline Destination Destination::CreateFitBV(Page page, double left)
{
	TRN_Destination result;
	REX(TRN_DestinationCreateFitBV(page.mp_page,left,&result))
	return Destination(result);
}

inline Destination::Destination (SDF::Obj dest)
{
	REX(TRN_DestinationCreate(dest.mp_obj,&mp_dest));
}

inline Destination::Destination (const Destination& d)
{
	REX(TRN_DestinationCopy(d.mp_dest,&mp_dest));
}

inline Destination& Destination::operator=(const Destination& d)
{
	REX(TRN_DestinationCopy(d.mp_dest,&mp_dest));
	return *this;
}
inline bool Destination::IsValid() const
{
	TRN_Bool result;
	REX(TRN_DestinationIsValid(mp_dest,&result));
	return TBToB(result);
}

inline Destination::FitType Destination::GetFitType()
{
	enum TRN_DestinationFitType result;
	REX(TRN_DestinationGetFitType(mp_dest,&result));
	return (FitType)result;
}

inline Page Destination::GetPage()
{
	TRN_Page result;
	REX(TRN_DestinationGetPage(mp_dest,&result));
	return Page(result);
}

inline void Destination::SetPage(Page page)
{
	REX(TRN_DestinationSetPage(mp_dest,page.mp_page));
}

inline SDF::Obj Destination::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_DestinationGetSDFObj(mp_dest,&result));
	return SDF::Obj(result);
}

inline SDF::Obj Destination::GetExplicitDestObj ()
{
	TRN_Obj result;
	REX(TRN_DestinationGetExplicitDestObj(mp_dest,&result));
	return SDF::Obj(result);
}

inline Destination::Destination(TRN_Destination impl) : mp_dest(impl)
{
}

inline Destination::Destination() : mp_dest(0)
{
}


//Field
inline Field::Field ()
{
    mp_field.builder = 0;
}

inline Field::Field (SDF::Obj field_dict)
{
	REX(TRN_FieldCreate(field_dict.mp_obj,&mp_field));
}

inline Field::Field (const Field& p)
{
	REX(TRN_FieldAssign(&mp_field,&(p.mp_field)));
}

inline Field& Field::operator= (const Field& p)
{
	REX(TRN_FieldAssign(&mp_field,&(p.mp_field)));
	return *this;
}

inline Field::~Field()
{
	DREX(mp_field.builder, TRN_FieldDestroy(&mp_field));
}

inline void Field::Destroy ()
{
	REX(TRN_FieldDestroy(&mp_field));
	mp_field.builder = 0;
}

inline bool Field::IsValid() const
{
	TRN_Bool result;
	REX(TRN_FieldIsValid(&mp_field,&result));
	return TBToB(result);
}

inline Field::Type Field::GetType() const
{
	enum TRN_FieldType result;
	REX(TRN_FieldGetType(&mp_field,&result));
	return (Type)result;
}

inline SDF::Obj Field::GetValue()
{
	TRN_Obj result;
	REX(TRN_FieldGetValue(&mp_field,&result));
	return SDF::Obj(result);
}

inline UString Field::GetValueAsString()
{
	RetStr(TRN_FieldGetValueAsString(&mp_field, &result));
}

inline ViewChangeCollection Field::SetValue(SDF::Obj value)
{
	TRN_ViewChangeCollection result;
	REX(TRN_FieldSetValue(&mp_field,value.mp_obj,&result));
	return ViewChangeCollection(result);
}

inline ViewChangeCollection Field::SetValue(const UString& value)
{
	TRN_ViewChangeCollection result;
	REX(TRN_FieldSetValueAsString(&mp_field,value.mp_impl,&result));
	return ViewChangeCollection(result);
}

inline ViewChangeCollection Field::SetValue(const char* value)
{
	TRN_ViewChangeCollection result;
	UString v(value, -1, UString::e_utf8);
	REX(TRN_FieldSetValueAsString(&mp_field,v.mp_impl,&result));
	return ViewChangeCollection(result);
}

inline ViewChangeCollection Field::SetValue(bool is_checked)
{
	TRN_ViewChangeCollection result;
	REX(TRN_FieldSetValueAsBool(&mp_field,is_checked,&result));
	return ViewChangeCollection(result);
}

inline SDF::Obj Field::GetTriggerAction(Field::ActionTriggerEvent trigger)
{
	TRN_Obj result;
	REX(TRN_FieldGetTriggerAction(&mp_field, (enum TRN_FieldEventType)trigger, &result ));
	return SDF::Obj(result);
}

inline bool Field::GetValueAsBool()
{
	TRN_Bool result;
	REX(TRN_FieldGetValueAsBool(&mp_field,&result));
	return TBToB(result);
}

inline void Field::RefreshAppearance()
{
	REX(TRN_FieldRefreshAppearance(&mp_field));
}

inline void Field::EraseAppearance()
{
	REX(TRN_FieldEraseAppearance(&mp_field));
}

inline SDF::Obj Field::GetDefaultValue()
{
	TRN_Obj result;
	REX(TRN_FieldGetDefaultValue(&mp_field,&result));
	return SDF::Obj(result);
}

inline UString Field::GetDefaultValueAsString()
{
	RetStr(TRN_FieldGetDefaultValueAsString(&mp_field,&result));
}

inline UString Field::GetName()
{
	TRN_UString result;
	REX(TRN_FieldGetName(&mp_field,&result));
	return UString(result);
}

inline UString Field::GetPartialName()
{
	TRN_UString result;
	REX(TRN_FieldGetPartialName(&mp_field,&result));
	return UString(result);
}

inline void Field::Rename(const UString& field_name)
{
	REX(TRN_FieldRename(&mp_field,field_name.mp_impl));
}

inline bool Field::IsAnnot() const
{
	TRN_Bool result;
	REX(TRN_FieldIsAnnot(&mp_field,&result));
	return TBToB(result);
}

inline bool Field::GetFlag(Flag flag) const
{
	TRN_Bool result;
	REX(TRN_FieldGetFlag(&mp_field,(enum TRN_FieldFlag)flag, &result));
	return TBToB(result);
}
inline void Field::SetFlag(Flag flag, bool value)
{
	REX(TRN_FieldSetFlag(&mp_field,(enum TRN_FieldFlag)flag,BToTB(value)));
}

inline Field::TextJustification Field::GetJustification()
{
	enum TRN_FieldTextJustification result;
	REX(TRN_FieldGetJustification(&mp_field,&result));
	return (TextJustification)result;
}

inline void Field::SetJustification(TextJustification j)
{
	REX(TRN_FieldSetJustification(&mp_field,(enum TRN_FieldTextJustification)j));
}

inline void Field::SetMaxLen(int max_len)
{
	REX(TRN_FieldSetMaxLen(&mp_field,max_len));
}

inline int Field::GetMaxLen() const
{
	int result;
	REX(TRN_FieldGetMaxLen(&mp_field,&result));
	return result;
}

inline UString Field::GetOpt(int index)
{
	TRN_UString result;
	REX(TRN_FieldGetOpt(&mp_field,index,&result));
	return UString(result);
}

inline int Field::GetOptCount() const
{
	int result;
	REX(TRN_FieldGetOptCount(&mp_field, &result));
	return result;
}

inline GState Field::GetDefaultAppearance()
{
	TRN_GState result;
	REX(TRN_FieldGetDefaultAppearance(&mp_field,&result));
	return GState(result);
}

inline void Field::Flatten(class Page page)
{
	REX(TRN_FieldFlatten(&mp_field, page.mp_page));
}

inline Rect Field::GetUpdateRect() const
{
	RetRec(TRN_FieldGetUpdateRect(&mp_field, &result));
}

inline SDF::Obj Field::FindInheritedAttribute (const char* attrib) const
{
	TRN_Obj result;
	REX(TRN_FieldFindInheritedAttribute(&mp_field,attrib,&result));
	return SDF::Obj(result);
}

inline SDF::Obj Field::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_FieldGetSDFObj(&mp_field,&result));
	return SDF::Obj(result);
}

inline SDF::Obj Field::UseSignatureHandler(const SDF::SignatureHandlerId signature_handler_id)
{
    TRN_Obj result = NULL;
    REX(TRN_FieldUseSignatureHandler(&mp_field, (const TRN_SignatureHandlerId) signature_handler_id, &result));
    return (SDF::Obj(result));
}

inline bool Field::IsLockedByDigitalSignature() const
{
	TRN_Bool result;
	REX(TRN_FieldIsLockedByDigitalSignature(&mp_field,&result));
	return TBToB(result);
}

//Action
inline Action Action::CreateGoto(Destination dest)
{
	TRN_Action result;
	REX(TRN_ActionCreateGoto(dest.mp_dest,&result));
	return Action(result);
}

inline Action Action::CreateGoto(const UChar* key, int key_sz, Destination dest)
{
	TRN_Action result;
	TRN_String keyString = { (const char*)key, (unsigned int)key_sz };
	REX(TRN_ActionCreateGotoWithKey(keyString,dest.mp_dest,&result));
	return Action(result);
}

inline Action Action::CreateGotoRemote(const FileSpec& file, int page_num)
{
	TRN_Action result;
	REX(TRN_ActionCreateGotoRemote(file.mp_impl,page_num,&result));
	return Action(result);
}

inline Action Action::CreateGotoRemote(const FileSpec& file, int page_num, bool new_window)
{
	TRN_Action result;
	REX(TRN_ActionCreateGotoRemoteSetNewWindow(file.mp_impl,page_num,BToTB(new_window),&result));
	return Action(result);
}

inline Action Action::CreateURI(SDF::SDFDoc& doc, const char* uri)
{
	TRN_Action result;
	REX(TRN_ActionCreateURI(doc.mp_doc, uri, &result));
	return Action(result);
}

inline Action Action::CreateURI(SDF::SDFDoc& doc, UString& uri)
{
	TRN_Action result;
	REX(TRN_ActionCreateURIWithUString(doc.mp_doc, uri.mp_impl, &result));
	return Action(result);
}

inline Action Action::CreateSubmitForm(const FileSpec& url)
{
	TRN_Action result;
	REX(TRN_ActionCreateSubmitForm(url.mp_impl, &result));
	return Action(result);
}

inline Action Action::CreateLaunch(SDF::SDFDoc& doc, const char* path)
{
	TRN_Action result;
	REX(TRN_ActionCreateLaunch(doc.mp_doc, path, &result));
	return Action(result);
}

inline Action Action::CreateHideField(SDF::SDFDoc& doc, int list_length, const char** field_list)
{
	TRN_Action result;
	REX(TRN_ActionCreateHideField(doc.mp_doc, field_list, list_length, &result));
	return Action(result);
}

inline Action Action::CreateImportData(SDF::SDFDoc& doc, const char* path)
{
	TRN_Action result;
	REX(TRN_ActionCreateImportData(doc.mp_doc, path, &result));
	return Action(result);
}

inline Action Action::CreateResetForm(SDF::SDFDoc& doc)
{
	TRN_Action result;
	REX(TRN_ActionCreateResetForm(doc.mp_doc, &result));
	return Action(result);
}

inline Action Action::CreateJavaScript(SDF::SDFDoc& doc, const char* script)
{
	TRN_Action result;
	REX(TRN_ActionCreateJavaScript(doc.mp_doc, script, &result));
	return Action(result);
}

inline Action::Action (SDF::Obj in_obj)
{
	REX(TRN_ActionCreate(in_obj.mp_obj,&mp_action));
}

inline Action::Action (const Action& in_action)
{
	REX(TRN_ActionCopy(in_action.mp_action,&mp_action));
}

inline Action& Action::operator=(const Action& in_action)
{
	REX(TRN_ActionCopy(in_action.mp_action,&mp_action));
	return *this;
}

inline bool Action::operator==(const Action& in_action)
{
	TRN_Bool result;
	REX(TRN_ActionCompare(mp_action,in_action.mp_action,&result));
	return TBToB(result);
}

inline bool Action::IsValid() const
{
	TRN_Bool result;
	REX(TRN_ActionIsValid(mp_action,&result));
	return TBToB(result);
}

inline Action::Type Action::GetType() const
{
	enum TRN_ActionType result;
	REX(TRN_ActionGetType(mp_action,&result));
	return (Type)result;
}

inline SDF::Obj Action::GetNext() const
{
	TRN_Obj result;
	REX(TRN_ActionGetNext(mp_action,&result));
	return SDF::Obj(result);
}

inline Destination Action::GetDest()
{
	TRN_Destination result;
	REX(TRN_ActionGetDest(mp_action,&result))
	return Destination(result);
}

inline SDF::Obj Action::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_ActionGetSDFObj(mp_action,&result));
	return SDF::Obj(result);
}

inline Action::Action(TRN_Action impl) : mp_action(impl)
{
}

//for xamarin use only
inline Action* Action::CreateInternal(ptrdiff_t impl) {
	return new Action((TRN_Action)impl);
}

inline ptrdiff_t Action::GetHandleInternal() {
    return (ptrdiff_t) mp_action;
}

inline void Action::Execute() 
{
	REX( TRN_Action_Execute(mp_action));
}

inline KeyStrokeActionResult Action::ExecuteKeyStrokeAction(const KeyStrokeEventData& data)
{
	TRN_KeyStrokeActionResult result;
	REX(TRN_ActionExecuteKeyStrokeAction(mp_action, data.mp_data, &result));
	return KeyStrokeActionResult(result);
}

inline bool Action::NeedsWriteLock()
{
	TRN_Bool result;
	REX(TRN_ActionNeedsWriteLock(mp_action, &result));
	return TBToB(result);
}

inline bool  Action::GetFormActionFlag( FormActionFlag flag ) const 
{
	TRN_Bool result;
	REX(TRN_Action_GetFormActionFlag(mp_action, static_cast<TRN_ActionFormActionFlag>(flag), &result));
	return static_cast<bool>(result != 0);
}


inline void  Action::SetFormActionFlag( FormActionFlag flag, bool value )
{
	REX(TRN_Action_SetFormActionFlag(mp_action, static_cast<TRN_ActionFormActionFlag>(flag), static_cast<TRN_Bool>(value)));
}






//Page

inline Page::Page (SDF::Obj page_dict)
{
	REX(TRN_PageCreate(page_dict.mp_obj,&mp_page));
}
inline Page::Page (const Page& p)
{
	REX(TRN_PageCopy(p.mp_page,&mp_page));
}
inline Page& Page::operator= (const Page& p)
{
	REX(TRN_PageCopy(p.mp_page,&mp_page));
	return *this;
}

inline bool Page::IsValid() const
{
	TRN_Bool result;
	REX(TRN_PageIsValid(mp_page,&result));
	return TBToB(result);
}

inline int Page::GetIndex() const
{
	int result;
	REX(TRN_PageGetIndex(mp_page,&result));
	return result;
}

inline Rect Page::GetBox(Box type) const
{
	TRN_Rect result;
	REX(TRN_PageGetBox(mp_page,(enum TRN_PageBox)type,&result));
	return *((Rect*)&result);
}

inline void Page::SetBox(Box type, const Rect& box) const
{
	REX(TRN_PageSetBox(mp_page,(enum TRN_PageBox)type,(const TRN_Rect*)&box));
}

inline Rect Page::GetCropBox() const
{
	TRN_Rect result;
	REX(TRN_PageGetCropBox(mp_page,&result));
	return *((Rect*)&result);
}

inline void Page::SetCropBox(const Rect& box)
{
	REX(TRN_PageSetCropBox(mp_page,(const TRN_Rect*)&box));
}

inline Rect Page::GetMediaBox() const
{
	TRN_Rect result;
	REX(TRN_PageGetMediaBox(mp_page,&result));
	return *((Rect*)&result);
}

inline void Page::SetMediaBox(const Rect& box)
{
	REX(TRN_PageSetMediaBox(mp_page,(const TRN_Rect*)&box));
}

inline Rect Page::GetVisibleContentBox() const
{
	TRN_Rect result;
	REX(TRN_PageGetVisibleContentBox(mp_page,&result));
	return *((Rect*)&result);
}


inline Page::Rotate Page::GetRotation() const
{
	enum TRN_PageRotate result;
	REX(TRN_PageGetRotation(mp_page,&result));
	return (Page::Rotate)result;
}

inline void Page::SetRotation(Rotate angle)
{
	REX(TRN_PageSetRotation(mp_page,(enum TRN_PageRotate)angle));
}

inline double Page::GetPageWidth(Box box_type)
{
	double result;
	REX(TRN_PageGetPageWidth(mp_page,(enum TRN_PageBox)box_type,&result));
	return result;
}

inline double Page::GetPageHeight(Box box_type)
{
	double result;
	REX(TRN_PageGetPageHeight(mp_page,(enum TRN_PageBox)box_type,&result));
	return result;
}

inline Common::Matrix2D Page::GetDefaultMatrix(bool flip_y, Box box_type, Rotate angle) const
{
	TRN_Matrix2D result;
	REX(TRN_PageGetDefaultMatrix(mp_page,BToTB(flip_y),
		(enum TRN_PageBox)box_type, (enum TRN_PageRotate)angle,&result));
	return *((Common::Matrix2D*)&result);
}

inline SDF::Obj Page::GetAnnots() const
{
	TRN_Obj result;
	REX(TRN_PageGetAnnots(mp_page,&result));
	return SDF::Obj(result);
}

inline UInt32 Page::GetNumAnnots() const
{
	UInt32 result;
	REX(TRN_PageGetNumAnnots(mp_page,&result));
	return result;
}

inline Annot Page::GetAnnot(UInt32 index) const
{
	TRN_Annot result;
	REX(TRN_PageGetAnnot(mp_page,index,&result));
	return Annot(result);
}

inline SDF::Obj Page::GetTriggerAction(Page::ActionTriggerEvent trigger)
{
	TRN_Obj result;
	REX(TRN_PageGetTriggerAction(mp_page, (enum TRN_PageEventType)trigger, &result));
	return SDF::Obj(result);
}

inline void Page::AnnotInsert(UInt32 pos, Annot& annot)
{
	REX(TRN_PageAnnotInsert(mp_page,pos,annot.mp_annot));
}

inline void Page::AnnotPushBack(Annot& annot)
{
	REX(TRN_PageAnnotPushBack(mp_page,annot.mp_annot));
}

inline void Page::AnnotPushFront(Annot& annot)
{
	REX(TRN_PageAnnotPushFront(mp_page, annot.mp_annot));
}

inline void Page::AnnotRemove(Annot& annot)
{
	REX(TRN_PageAnnotRemove(mp_page, annot.mp_annot));
}

inline void Page::AnnotRemove(UInt32 index)
{
	REX(TRN_PageAnnotRemoveByIndex(mp_page, index));
}

inline void Page::Scale(double scale)
{
	REX(TRN_PageScale(mp_page, scale));
}

inline void Page::FlattenField(Field field_to_flatten)
{
	REX(TRN_PageFlattenField(mp_page, (TRN_Field*)&field_to_flatten));
}

inline bool Page::HasTransition() const
{
	TRN_Bool result;
	REX(TRN_PageHasTransition(mp_page, &result));
	return TBToB(result);
}

inline double Page::GetUserUnitSize() const
{
	double result;
	REX(TRN_PageGetUserUnitSize(mp_page, &result));
	return result;
}

inline void Page::SetUserUnitSize(double unit_size)
{
	REX(TRN_PageSetUserUnitSize(mp_page, unit_size));
}

inline SDF::Obj Page::GetResourceDict () const
{
	TRN_Obj result;
	REX(TRN_PageGetResourceDict(mp_page, &result));
	return SDF::Obj(result);
}

inline SDF::Obj Page::GetContents () const
{
	TRN_Obj result;
	REX(TRN_PageGetContents(mp_page,&result));
	return SDF::Obj(result);
}

inline SDF::Obj Page::GetThumb() const 
{
	TRN_Obj result;
	REX(TRN_PageGetThumb(mp_page,&result));
	return SDF::Obj(result);
}

inline SDF::Obj Page::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_PageGetSDFObj(mp_page,&result));
	return SDF::Obj(result);
}

inline SDF::Obj Page::FindInheritedAttribute (const char* attrib) const
{
	TRN_Obj result;
	REX(TRN_PageFindInheritedAttribute(mp_page,attrib,&result));
	return SDF::Obj(result);
}

inline Page::Page(TRN_Page impl) : mp_page(impl) {}

inline Page::Rotate Page::AddRotations(Page::Rotate r0, Page::Rotate r1)
{
	enum TRN_PageRotate result;
	REX(TRN_PageAddRotations((enum TRN_PageRotate)r0, (enum TRN_PageRotate)r1, &result));
	return (Page::Rotate)result;
}

inline Page::Rotate Page::SubtractRotations(Page::Rotate r0, Page::Rotate r1)
{
	enum TRN_PageRotate result;
	REX(TRN_PageSubtractRotations((enum TRN_PageRotate)r0, (enum TRN_PageRotate)r1, &result));
	return (Page::Rotate)result;
}

inline int Page::RotationToDegree(Page::Rotate r)
{
	int result;
	REX(TRN_PageRotationToDegree((enum TRN_PageRotate)r, &result));
	return result;
}

inline Page::Rotate Page::DegreeToRotation(int r)
{
	enum TRN_PageRotate result;
	REX(TRN_PageDegreeToRotation(r, &result));
	return (Page::Rotate)result;
}

// ---------------------------------------------------
//for xamarin use only
inline Annot* Annot::CreateInternal(ptrdiff_t impl) {
	return new Annot((TRN_Annot)impl);
}

inline ptrdiff_t Annot::GetHandleInternal() {
    return (ptrdiff_t) mp_annot;
}

inline Annot::Annot (SDF::Obj d)
{
	REX(TRN_AnnotCreateFromObj(d.mp_obj,&mp_annot));
}

inline Annot::Annot (const Annot& d)
{
	REX(TRN_AnnotCopy(d.mp_annot,&mp_annot));
}

inline Annot& Annot::operator=(const Annot& d) {
	REX(TRN_AnnotCopy(d.mp_annot,&mp_annot));
	return *this;
}

inline bool Annot::operator==(const Annot& d) {
	TRN_Bool result;
	REX(TRN_AnnotCompare(mp_annot,d.mp_annot,&result));
	return TBToB(result);
}

inline bool Annot::IsValid() const {
	TRN_Bool result;
	REX(TRN_AnnotIsValid(mp_annot,&result));
	return TBToB(result);
}

inline Annot::Type Annot::GetType() const {
	enum TRN_AnnotType type;
	REX(TRN_AnnotGetType(mp_annot,&type));
	return (Annot::Type)type;
}

inline SDF::Obj Annot::GetSDFObj () const {
	TRN_Obj result;
	REX(TRN_AnnotGetSDFObj(mp_annot,&result));
	return SDF::Obj(result);
}

inline Rect Annot::GetRect() const {
	TRN_Rect result;
	REX(TRN_AnnotGetRect(mp_annot,&result));
	return *((Rect*)&result);
}

inline Rect Annot::GetVisibleContentBox() const {
	TRN_Rect result;
	REX(TRN_AnnotGetVisibleContentBox(mp_annot, &result));
	return *((Rect*)&result);
}

inline bool Annot::IsMarkup() const {
	TRN_Bool result;
	REX(TRN_AnnotIsMarkup(mp_annot,&result));
	return (result!=0);
}

inline void Annot::SetRect(const Rect& p) {
	REX(TRN_AnnotSetRect(mp_annot,(const TRN_Rect*)&p));
}

inline bool Annot::GetFlag(Flag flag) const {
	TRN_Bool result;
	REX(TRN_AnnotGetFlag(mp_annot,(enum TRN_AnnotFlag)flag,&result));
	return TBToB(result);
}

inline void Annot::SetFlag(Flag flag, bool value) {
	REX(TRN_AnnotSetFlag(mp_annot,(enum TRN_AnnotFlag)flag,BToTB(value)));
}

inline SDF::Obj Annot::GetTriggerAction(Annot::ActionTriggerEvent trigger)
{
	TRN_Obj result;
	REX(TRN_AnnotGetTriggerAction(mp_annot, (enum TRN_AnnotEventType)trigger, &result));
	return SDF::Obj(result);
}

inline Date Annot::GetDate() const {
	TRN_Date result;
	REX(TRN_AnnotGetDate(mp_annot,&result));
	return *((Date*)&result);
}

inline void Annot::SetDate(const Date& date) {
	REX(TRN_AnnotSetDate(mp_annot,(const TRN_Date*)&date));
}

inline SDF::Obj Annot::GetUniqueID() const {
	TRN_Obj result;
	REX(TRN_AnnotGetUniqueID(mp_annot,&result));
	return SDF::Obj(result);
}

inline void Annot::SetUniqueID(const char* id, int id_buf_sz){
	REX(TRN_AnnotSetUniqueID(mp_annot,id,id_buf_sz));
}

inline ColorPt Annot::GetColorAsRGB() const 
{
	RetCPT(TRN_AnnotGetColorAsRGB(mp_annot, &result));
}

inline ColorPt Annot::GetColorAsCMYK() const
{
	RetCPT(TRN_AnnotGetColorAsCMYK(mp_annot, &result));
}

inline ColorPt Annot::GetColorAsGray() const
{
	RetCPT(TRN_AnnotGetColorAsGray(mp_annot, &result));
}


inline void Annot::SetColor(const ColorPt& c, int comp_num){
	REX(TRN_AnnotSetColor(mp_annot, &c.m_c, comp_num));
}

inline int Annot::GetColorCompNum() const
{
	int result;
	REX(TRN_AnnotGetColorCompNum(mp_annot, &result));
	return result;
}

//State
inline UString Annot::GetContents() const
{
	TRN_UString result;
	REX(TRN_AnnotGetContents(mp_annot,&result));
	return UString(result);	
}

inline void Annot::SetContents(const UString& state)
{
	REX(TRN_AnnotSetContents(mp_annot, state.mp_impl));
}

inline void Annot::Resize(const Rect& p) {
	REX(TRN_AnnotResize(mp_annot,(const TRN_Rect*)&p));
}

inline UString Annot::GetCustomData(const UString& key) const
{
	TRN_UString result;
	REX(TRN_AnnotGetCustomData(mp_annot, key.mp_impl, &result));
	return UString(result);
}

inline void Annot::SetCustomData(const UString& key, const UString& value)
{
	REX(TRN_AnnotSetCustomData(mp_annot, key.mp_impl, value.mp_impl));
}

inline void Annot::DeleteCustomData(const UString& key)
{
	REX(TRN_AnnotDeleteCustomData(mp_annot, key.mp_impl));
}

// BorderStyle
inline BorderStyle::BorderStyle(Style s, double b_width, double b_hr, double b_vr)
{
	REX(TRN_AnnotBorderStyleCreate((enum TRN_AnnotBorderStyleStyle)s, b_width,b_hr,b_vr,&mp_bs));
}

inline BorderStyle::BorderStyle(Style s, double b_width, double b_hr, double b_vr, const std::vector<double>& b_dash)
{
	size_t sz = b_dash.size();
	REX(TRN_AnnotBorderStyleCreateWithDashPattern((enum TRN_AnnotBorderStyleStyle)s, b_width, b_hr, b_vr, (double*)(sz<1 ? 0 : &b_dash[0]), int(sz), &mp_bs));
}

inline BorderStyle::BorderStyle(const BorderStyle& bs)
{
	REX(TRN_AnnotBorderStyleCopy(bs.mp_bs, &mp_bs));
}

inline BorderStyle::~BorderStyle()
{
	DREX(mp_bs, TRN_AnnotBorderStyleDestroy(mp_bs));
}

inline void BorderStyle::Destroy()
{
	REX(TRN_AnnotBorderStyleDestroy(mp_bs));
	mp_bs=0;
}

inline BorderStyle& BorderStyle::operator=(const BorderStyle& bs) {
	if(this->mp_bs)
	{
		if( this == &bs ) 
			return *this;
		REX( TRN_AnnotBorderStyleAssign( bs.mp_bs, this->mp_bs ) );
	}
	else
	{
		REX(TRN_AnnotBorderStyleCopy(bs.mp_bs, &mp_bs));
	}
	return *this;
}

inline bool operator==( const  BorderStyle& a, const  BorderStyle& b )
{
	TRN_Bool result;
	REX( TRN_AnnotBorderStyleCompare( a.mp_bs, b.mp_bs, &result ) );
	return result!=0;
}


inline BorderStyle Annot::GetBorderStyle() const
{
	TRN_AnnotBorderStyle result;
	REX(TRN_AnnotGetBorderStyle(mp_annot, &result));
	return BorderStyle(result);
}

inline void Annot::SetBorderStyle(const BorderStyle& bs, bool oldStyleOnly )
{
	REX(TRN_AnnotSetBorderStyle(mp_annot,bs.mp_bs,oldStyleOnly));
}

inline BorderStyle::Style BorderStyle::GetStyle() const
{
	TRN_AnnotBorderStyleStyle result;
	REX(TRN_AnnotBorderStyleGetStyle( mp_bs, &result));
	return (BorderStyle::Style)result;	
}

inline void BorderStyle::SetStyle( BorderStyle::Style style)
{
	REX(TRN_AnnotBorderStyleSetStyle( mp_bs, (TRN_AnnotBorderStyleStyle)style));
}

inline double BorderStyle::GetHR() const
{
	double result;
	REX(TRN_AnnotBorderStyleGetHR(mp_bs,&result));
	return result;
}
inline void BorderStyle::SetHR(double hr)
{
	REX(TRN_AnnotBorderStyleSetHR(mp_bs, hr));
}

inline double BorderStyle::GetVR() const
{
	double result;
	REX(TRN_AnnotBorderStyleGetVR(mp_bs,&result));
	return result;
}
inline void BorderStyle::SetVR(double vr)
{
	REX(TRN_AnnotBorderStyleSetVR(mp_bs,vr));
}
inline double BorderStyle::GetWidth() const
{
	double result;
	REX(TRN_AnnotBorderStyleGetWidth(mp_bs,&result));
	return result;
}

inline void BorderStyle::SetWidth(double width)
{
	REX(TRN_AnnotBorderStyleSetWidth(mp_bs,width));
}

inline std::vector<double> BorderStyle::GetDash() const
{
	double* out_buf; int buf_length;
	REX(TRN_AnnotBorderStyleGetDashPattern(mp_bs, &out_buf, &buf_length))
	std::vector<double> res(buf_length);
	if (buf_length>0) {
		memcpy(&(res[0]), out_buf, buf_length*sizeof(double));
	}
	return res;
}

inline void BorderStyle::SetDash( const std::vector<double>& dash)
{
	size_t sz = dash.size();
	REX(TRN_AnnotBorderStyleSetDashPattern(mp_bs, (sz<1 ? 0 : &dash[0]), int(sz)));
}


inline BorderStyle::BorderStyle(TRN_AnnotBorderStyle impl) { mp_bs=impl; }


inline SDF::Obj Annot::GetAppearance(Annot::AnnotationState as, const char* app_state)
{
	TRN_Obj result;
	REX(TRN_AnnotGetAppearance(mp_annot,(enum TRN_AnnotState)as, app_state, &result));
	return SDF::Obj(result);
}


inline void Annot::SetAppearance(SDF::Obj app_stream, Annot::AnnotationState annot_state, const char* app_state)
{
	REX(TRN_AnnotSetAppearance(mp_annot,app_stream.mp_obj,(enum TRN_AnnotState)annot_state, app_state));
}


inline void Annot::RemoveAppearance(Annot::AnnotationState annot_state, const char* app_state)
{
	REX(TRN_AnnotRemoveAppearance(mp_annot, (enum TRN_AnnotState)annot_state, app_state));
}

inline void Annot::Flatten(Page pg)
{
	REX(TRN_AnnotFlatten(mp_annot, pg.mp_page));
}

inline Page Annot::GetPage() const
{
	TRN_Page result;
	REX(TRN_AnnotGetPage(mp_annot, &result));
	return Page(result);
}

inline void Annot::SetPage(const Page& page)
{
	REX(TRN_AnnotSetPage(mp_annot, page.mp_page));
}



inline const char* Annot::GetActiveAppearanceState() const
{
	const char* result;
	REX(TRN_AnnotGetActiveAppearanceState(mp_annot, &result));
	return result;
}
	
inline void Annot::SetActiveAppearanceState(const char* astate)
{
	REX(TRN_AnnotSetActiveAppearanceState(mp_annot, astate));
}


inline int Annot::GetStructParent() const
{
	int result;
	REX(TRN_AnnotGetStructParent(mp_annot, &result)); 
	return result;
}
			
inline void Annot::SetStructParent(const int parkeyval)
{
	REX(TRN_AnnotSetStructParent(mp_annot, parkeyval));
}

inline SDF::Obj Annot::GetOptionalContent() const
{
	TRN_Obj result;
	REX(TRN_AnnotGetOptionalContent(mp_annot, &result));
	return SDF::Obj(result);
}

inline void Annot::SetOptionalContent(SDF::Obj oc)
{
	REX(TRN_AnnotSetOptionalContent(mp_annot, oc.mp_obj));
}

// --------------------------------------------
inline Annot Annot::Create(SDF::SDFDoc& doc, Annot::Type type, const Rect& pos){
	TRN_Annot result;
	REX(TRN_AnnotCreate(doc.mp_doc,  static_cast<TRN_AnnotType>(type),(const TRN_Rect*)&pos, &result));
	return Annot(result);
}

inline int Annot::GetRotation() const
{
	int result;
	REX(TRN_AnnotGetRotation(mp_annot, &result));
	return result;
}

inline void Annot::SetRotation(int rotation)
{
	REX(TRN_AnnotSetRotation(mp_annot, rotation));
}

inline void Annot::RefreshAppearance() //Maybe able to substitute annn to this later(so one less parameter). 
{
	REX(TRN_AnnotRefreshAppearance(mp_annot));
}

inline void Annot::RefreshAppearance(const RefreshOptions& opts)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	RefreshOptions* opt = const_cast<RefreshOptions*>(&opts);
	opt_in.impl = opt ? opt->GetInternalObj().mp_obj : 0;
	REX(TRN_AnnotRefreshAppearanceRefreshOptions(mp_annot, &opt_in));
}

inline Annot::Annot(TRN_Annot annot) : mp_annot(annot)
{

}

namespace Annots 
{

//Caret
	inline Caret::Caret(SDF::Obj d):Markup(d)
{
	REX(TRN_CaretAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Caret Caret::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_CaretAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Caret(result);
}
inline Caret Caret::Create(SDF::SDFDoc& doc, const Rect& pos, Rect padding)
{
	TRN_Annot result;
	REX(TRN_CaretAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	REX(TRN_MarkupAnnotSetPadding(result, (const TRN_Rect*)&padding ));
	return Caret(result);
}


//Sy
inline const char* Caret::GetSymbol() const
{
	const char* result;
	REX(TRN_CaretAnnotGetSymbol(mp_annot,&result));
	return result;
}

inline void Caret::SetSymbol(const char* symbol)
{
	REX(TRN_CaretAnnotSetSymbol(mp_annot, symbol));
}

inline Caret::Caret(TRN_Annot caret) : Markup(caret)
{
	
}


//Circle
inline Circle::Circle(SDF::Obj d):Markup(d)
{
	REX(TRN_CircleAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Circle Circle::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_CircleAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Circle(result);
}


inline Circle::Circle(TRN_Annot circle) : Markup(circle)
{
	
}

//FileAttachment
inline FileAttachment::FileAttachment(SDF::Obj d):Markup(d)
{
	REX(TRN_FileAttachmentAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline FileAttachment FileAttachment::Create(SDF::SDFDoc& doc, const Rect& pos, FileSpec fs, Icon icon_name ) {
	TRN_Annot result;
	REX(TRN_FileAttachmentAnnotCreateWithFileSpec(doc.mp_doc,(const TRN_Rect*)&pos, fs.mp_impl, static_cast<TRN_FileAttachmentAnnotIcon>(icon_name), &result));
	return FileAttachment(result);
}

inline FileAttachment FileAttachment::Create(SDF::SDFDoc& doc, const Rect& pos, const UString& path, FileAttachment::Icon icon_name) {
	TRN_Annot result;
	REX(TRN_FileAttachmentAnnotCreateWithIcon(doc.mp_doc,(const TRN_Rect*)&pos, path.mp_impl, static_cast<TRN_FileAttachmentAnnotIcon>(icon_name), &result));
	return FileAttachment(result);
}

inline FileAttachment FileAttachment::Create(SDF::SDFDoc& doc, const Rect& pos, const UString& path, const char* icon_name) {
	TRN_Annot result;
	REX(TRN_FileAttachmentAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, path.mp_impl, icon_name, &result));
	return FileAttachment(result);
}

//FS
inline FileSpec FileAttachment::GetFileSpec() const {
	TRN_FileSpec result;
	REX(TRN_FileAttachmentAnnotGetFileSpec(mp_annot, &result));
	return FileSpec(result);
}


inline void FileAttachment::SetFileSpec(const FileSpec& fs) {
	REX(TRN_FileAttachmentAnnotSetFileSpec(mp_annot, fs.mp_impl));
}

inline bool FileAttachment::Export(const UString& save_as) const {
	TRN_Bool result;
	REX(TRN_FileAttachmentAnnotExport(mp_annot, save_as.mp_impl,&result));
	return TBToB(result);
}


//Name  //Note for this functionality we will provide inner convertion mechannism so no matter which function the users call, they will always get their satisfactory result. 
inline FileAttachment::Icon FileAttachment::GetIcon() const
{
	enum TRN_FileAttachmentAnnotIcon result;
	REX(TRN_FileAttachmentAnnotGetIcon(mp_annot, &result))
	return (Icon)result;
}

inline const char* FileAttachment::GetIconName() const
{
	const char* result;
	REX(TRN_FileAttachmentAnnotGetIconName(mp_annot,&result));
	return result;
}

inline void FileAttachment::SetIcon(Icon type)
{
	REX(TRN_FileAttachmentAnnotSetIcon(mp_annot,(enum TRN_FileAttachmentAnnotIcon)type));
}

inline void FileAttachment::SetIconName(const char* icon)
{
	REX(TRN_FileAttachmentAnnotSetIconName(mp_annot, icon));
}

inline FileAttachment::FileAttachment(TRN_Annot fileattachment) : Markup(fileattachment)
{
	
}


//FreeText
inline FreeText::FreeText(SDF::Obj d):Markup(d)
{
	REX(TRN_FreeTextAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline FreeText FreeText::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_FreeTextAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return FreeText(result);
}

//DA  
inline UString FreeText::GetDefaultAppearance() const
{
	RetStr(TRN_FreeTextAnnotGetDefaultAppearance(mp_annot, &result));
	return result;
}
inline void FreeText::SetDefaultAppearance(const char* app_str)
{
	REX(TRN_FreeTextAnnotSetDefaultAppearance(mp_annot, app_str));
}

//Q   
inline int FreeText::GetQuaddingFormat() const
{
	int result;
	REX(TRN_FreeTextAnnotGetQuaddingFormat(mp_annot, &result)); 
	return result;
}
inline void FreeText::SetQuaddingFormat(const int app_qform)
{
	REX(TRN_FreeTextAnnotSetQuaddingFormat(mp_annot, app_qform));
}

//CL
inline Point FreeText::GetCalloutLinePoint1() const
{
	Point p1, p2, p3;
	REX(TRN_FreeTextAnnotGetCalloutLinePoints(mp_annot, (TRN_Point*)&p1, (TRN_Point*)&p2, (TRN_Point*)&p3));
	return p1;
}

inline Point FreeText::GetCalloutLinePoint2() const
{
	Point p1, p2, p3;
	REX(TRN_FreeTextAnnotGetCalloutLinePoints(mp_annot, (TRN_Point*)&p1, (TRN_Point*)&p2, (TRN_Point*)&p3));
	return p2;
}

inline Point FreeText::GetCalloutLinePoint3() const
{
	Point p1, p2, p3;
	REX(TRN_FreeTextAnnotGetCalloutLinePoints(mp_annot, (TRN_Point*)&p1, (TRN_Point*)&p2, (TRN_Point*)&p3));
	return p3;
}

#ifndef SWIG
inline void FreeText::GetCalloutLinePoints(Point& p1, Point& p2, Point& p3) const
{
	REX(TRN_FreeTextAnnotGetCalloutLinePoints(mp_annot, (TRN_Point*)&p1, (TRN_Point*)&p2, (TRN_Point*)&p3));
}
#endif

inline void FreeText::SetCalloutLinePoints(const Point& p1, const Point& p2, const Point& p3)
{
	REX(TRN_FreeTextAnnotSetCalloutLinePoints(mp_annot, (TRN_Point*)&p1, (TRN_Point*)&p2, (TRN_Point*)&p3));
}

inline void FreeText::SetCalloutLinePoints(const Point& p1, const Point& p2)
{	
	REX(TRN_FreeTextAnnotSetCalloutLinePointsTwo(mp_annot, (TRN_Point*)&p1, (TRN_Point*)&p2));	
}

//IT
inline FreeText::IntentName FreeText::GetIntentName() const
{
	enum TRN_FreeTextAnnotIntentName result;
	REX(TRN_FreeTextAnnotGetIntentName(mp_annot, &result))
	return (IntentName)result;
}
inline void FreeText::SetIntentName(IntentName mode)
{
	REX(TRN_FreeTextAnnotSetIntentName(mp_annot,(enum TRN_FreeTextAnnotIntentName)mode));	
}


inline Line::EndingStyle FreeText::GetEndingStyle() const
{
	enum TRN_LineAnnotEndingStyle result;
	REX(TRN_FreeTextAnnotGetEndingStyle(mp_annot, &result));
	return (Line::EndingStyle)result;				
}

inline void FreeText::SetEndingStyle( Line::EndingStyle est)
{
	REX(TRN_FreeTextAnnotSetEndingStyle(mp_annot,(enum TRN_LineAnnotEndingStyle)est));
}

inline void FreeText::SetEndingStyle(const char* est)
{
	REX(TRN_FreeTextAnnotSetEndingStyleName(mp_annot, est));
}


inline void FreeText::SetTextColor( const ColorPt& color, int col_comp )
{
	REX(TRN_FreeTextAnnotSetTextColor(mp_annot, reinterpret_cast<const TRN_ColorPt*>(&color), col_comp ) );
}

inline void FreeText::SetLineColor( const ColorPt& color, int col_comp )
{
	REX(TRN_FreeTextAnnotSetLineColor(mp_annot, reinterpret_cast<const TRN_ColorPt*>(&color), col_comp ) );
}

inline ColorPt FreeText::GetTextColor()
{
	ColorPt color;
	int col_comp = 0;
	REX(TRN_FreeTextAnnotGetTextColor(mp_annot, reinterpret_cast<TRN_ColorPt*>(&color), &col_comp ) );
	return color;
}

inline int FreeText::GetTextColorCompNum()
{
	ColorPt color;
	int col_comp = 0;
	REX(TRN_FreeTextAnnotGetTextColor(mp_annot, reinterpret_cast<TRN_ColorPt*>(&color), &col_comp ) );
	return col_comp;
}

#ifndef SWIG
inline void FreeText::GetTextColor(  ColorPt& color, int& col_comp )
{
	REX(TRN_FreeTextAnnotGetTextColor(mp_annot, reinterpret_cast<TRN_ColorPt*>(&color), &col_comp ) );
}
#endif

inline ColorPt FreeText::GetLineColor()
{
	ColorPt color;
	int col_comp = 0;
	REX(TRN_FreeTextAnnotGetLineColor(mp_annot, reinterpret_cast<TRN_ColorPt*>(&color), &col_comp ) );
	return color;
}

inline int FreeText::GetLineColorCompNum()
{
	ColorPt color;
	int col_comp = 0;
	REX(TRN_FreeTextAnnotGetLineColor(mp_annot, reinterpret_cast<TRN_ColorPt*>(&color), &col_comp ) );
	return col_comp;
}

inline void FreeText::SetFontSize( double font_size )
{
	REX(TRN_FreeTextAnnotSetFontSize(mp_annot, font_size));
}

inline double FreeText::GetFontSize()
{
	double font_size;
	REX(TRN_FreeTextAnnotGetFontSize(mp_annot, &font_size));
	return font_size;
}

#ifndef SWIG
inline void FreeText::GetLineColor(  ColorPt& color, int& col_comp )
{
	REX(TRN_FreeTextAnnotGetLineColor(mp_annot, reinterpret_cast<TRN_ColorPt*>(&color), &col_comp ) );
}
#endif


inline FreeText::FreeText(TRN_Annot freetext) : Markup(freetext)
{
	
}

//Highlight
inline Highlight::Highlight(SDF::Obj d):TextMarkup(d)
{
	REX(TRN_HighlightAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Highlight Highlight::Create(SDF::SDFDoc& doc, const Rect& pos)
{
		TRN_Annot result;
		REX(TRN_HighlightAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
		return Highlight(result); 
}

inline Highlight::Highlight(TRN_Annot highlight) : TextMarkup(highlight)
{
}

//Ink
inline Ink::Ink(SDF::Obj d):Markup(d)
{
	REX(TRN_InkAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Ink Ink::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_InkAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Ink(result);
}


//InkList
inline int Ink::GetPathCount()const
{
	int result;
	REX(TRN_InkAnnotGetPathCount(mp_annot, &result));
	return result;
}

inline int Ink::GetPointCount(unsigned int pathindex)const
{
	int result;
	REX(TRN_InkAnnotGetPointCount(mp_annot, pathindex, &result));
	return result;
}

inline Point Ink::GetPoint(unsigned int pathindex, unsigned int pointindex)const
{
	TRN_Point result;
	REX(TRN_InkAnnotGetPoint(mp_annot, pathindex, pointindex, &result));
	return *((Point*)&result);
}

inline void Ink::SetPoint(unsigned int pathindex, unsigned int pointindex, const Point& pt)
{
	REX(TRN_InkAnnotSetPoint(mp_annot, pathindex, pointindex, (const TRN_Point*)&pt));
}

inline bool Ink::Erase(const Point& pt1, const Point& pt2, double width)
{
	TRN_Bool result;
	REX(TRN_InkAnnotErase(mp_annot, (const TRN_Point*)&pt1, (const TRN_Point*)&pt2, width, &result));
	return TBToB(result);
}

inline void Ink::SetHighlightIntent(bool highlight)
{
	REX(TRN_InkAnnotSetHighlightIntent(mp_annot, BToTB(highlight)));
}


inline bool Ink::GetHighlightIntent()
{
	TRN_Bool result;
	REX(TRN_InkAnnotGetHighlightIntent(mp_annot, &result));
	return TBToB(result);
}
					
inline Ink::Ink(TRN_Annot ink) : Markup(ink)
{
	
}		

//Line
inline Line::Line(SDF::Obj d):Markup(d)
{
	REX(TRN_LineAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Line Line::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_LineAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Line(result);
}


inline Point Line::GetStartPoint() const
{
	TRN_Point result;
	REX(TRN_LineAnnotGetStartPoint(mp_annot, &result));
	return *((Point*)&result);
}

inline void Line::SetStartPoint(const Point& sp)
{
	REX(TRN_LineAnnotSetStartPoint(mp_annot, (const TRN_Point*)&sp));
}


inline Point Line::GetEndPoint () const
{
	TRN_Point result;
	REX(TRN_LineAnnotGetEndPoint(mp_annot, &result));
	return *((Point*)&result);
}

inline void Line::SetEndPoint(const Point& ep)
{
	REX(TRN_LineAnnotSetEndPoint(mp_annot, (const TRN_Point*)&ep));
}	
	

//LE
inline Line::EndingStyle Line::GetStartStyle()const
{
	enum TRN_LineAnnotEndingStyle result;
	REX(TRN_LineAnnotGetStartStyle(mp_annot,&result));
	return (EndingStyle)result;				
}

inline void Line::SetStartStyle(EndingStyle sst)
{
	REX(TRN_LineAnnotSetStartStyle(mp_annot,(enum TRN_LineAnnotEndingStyle)sst));
}

inline Line::EndingStyle Line::GetEndStyle() const
{
	enum TRN_LineAnnotEndingStyle result;
	REX(TRN_LineAnnotGetEndStyle(mp_annot,&result));
	return (EndingStyle)result;			
}

inline void Line::SetEndStyle(EndingStyle est)
{
	REX(TRN_LineAnnotSetEndStyle(mp_annot,(enum TRN_LineAnnotEndingStyle)est));
}


//LL //Only required if LLE presents. 
inline double Line::GetLeaderLineLength() const
{
	double result;
	REX(TRN_LineAnnotGetLeaderLineLength(mp_annot, &result)); 
	return result;
}

inline void Line::SetLeaderLineLength(const double& ll)
{
	REX(TRN_LineAnnotSetLeaderLineLength(mp_annot, ll));
}

//LLE
inline double Line::GetLeaderLineExtensionLength() const
{
	double result;
	REX(TRN_LineAnnotGetLeaderLineExtensionLength(mp_annot, &result)); 
	return result;
}

inline void Line::SetLeaderLineExtensionLength(const double& ll)
{
	REX(TRN_LineAnnotSetLeaderLineExtensionLength(mp_annot, ll));
}

//Cap
inline bool Line::GetShowCaption() const
{
	TRN_Bool result;
	REX(TRN_LineAnnotGetShowCaption(mp_annot, &result));
	return TBToB(result);
}

inline void Line::SetShowCaption(bool showCaption)
{
	REX(TRN_LineAnnotSetShowCaption(mp_annot, BToTB(showCaption)));
}
		
//IT
inline Line::IntentType Line::GetIntentType() const
{
	enum TRN_LineAnnotIntentType result;
	REX(TRN_LineAnnotGetIntentType(mp_annot,&result));
	return (IntentType)result;
}

inline void Line::SetIntentType(IntentType style)
{
	REX(TRN_LineAnnotSetIntentType(mp_annot,(enum TRN_LineAnnotIntentType)style));
}

//LLO
inline double Line::GetLeaderLineOffset() const
{
	double result;
	REX(TRN_LineAnnotGetLeaderLineOffset(mp_annot, &result)); 
	return result;
}

inline void Line::SetLeaderLineOffset(double ll)
{
	REX(TRN_LineAnnotSetLeaderLineOffset(mp_annot, ll));
}

//CP
inline Line::CapPos Line::GetCaptionPosition() const
{
	enum TRN_LineAnnotCapPos result;
	REX(TRN_LineAnnotGetCapPos(mp_annot,&result));
	return (CapPos)result;
}

inline void Line::SetCaptionPosition(const CapPos& style)
{
	REX(TRN_LineAnnotSetCapPos(mp_annot,(enum TRN_LineAnnotCapPos)style));
}

inline double Line::GetTextHOffset() const
{
	double result;
	REX(TRN_LineAnnotGetTextHOffset(mp_annot, &result)); 
	return result;
}

inline void Line::SetTextHOffset(double offset)
{
	REX(TRN_LineAnnotSetTextHOffset(mp_annot, offset));
}

inline double Line::GetTextVOffset() const
{
	double result;
	REX(TRN_LineAnnotGetTextVOffset(mp_annot, &result)); 
	return result;
}

inline void Line::SetTextVOffset(double offset)
{
	REX(TRN_LineAnnotSetTextVOffset(mp_annot, offset));
}
					
inline Line::Line(TRN_Annot line) : Markup(line)
{
	
}

//Link
inline Link::Link(SDF::Obj d):Annot(d)
{
	REX(TRN_LinkAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Link Link::Create(SDF::SDFDoc& doc, const Rect& pos){
	TRN_Annot result;
	REX(TRN_LinkAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Link(result);
}

inline Link Link::Create(SDF::SDFDoc& doc, const Rect& pos, const Action& action)
{
	TRN_Annot result;
	REX(TRN_LinkAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	REX(TRN_LinkAnnotSetAction(result, action.mp_action ));
	return Link(result);
}


inline void Link::RemoveAction(){
	REX(TRN_LinkAnnotRemoveAction(mp_annot));
}

inline UString Link::GetNormalizedUrl(const UString& url)
{
    TRN_UString result;
    REX(TRN_GetNormalizedUrl(url.mp_impl, &result));
    return UString(result);
}

 //A
inline Action Link::GetAction() const
 {
	TRN_Action result;
	REX(TRN_LinkAnnotGetAction(mp_annot,&result));
	return Action(result);
 }

inline void Link::SetAction (const Action& action) {
	REX(TRN_LinkAnnotSetAction(mp_annot,action.mp_action));
}
 
 
 //H
inline Link::HighlightingMode Link::GetHighlightingMode() const
{
	enum TRN_LinkAnnotHighlightingMode result;
	REX(TRN_LinkAnnotGetHighlightingMode(mp_annot,&result));
	return (HighlightingMode)result;
}

inline void Link::SetHighlightingMode(HighlightingMode mode)
{
	REX(TRN_LinkAnnotSetHighlightingMode(mp_annot,(enum TRN_LinkAnnotHighlightingMode)mode));
}

inline int Link::GetQuadPointCount() const
{
	int result;
	REX(TRN_LinkAnnotGetQuadPointCount(mp_annot, &result));
	return result;		
}

inline QuadPoint Link::GetQuadPoint(int idx) const
{
	TRN_QuadPoint result;
	REX(TRN_LinkAnnotGetQuadPoint(mp_annot, idx, &result));
	return *((QuadPoint*)&result);
}

inline void Link::SetQuadPoint(int idx, const QuadPoint& qp)
{
	REX(TRN_LinkAnnotSetQuadPoint(mp_annot, idx, (const TRN_QuadPoint*)&qp));
}

inline Link::Link(TRN_Annot link) : Annot(link)
{
	
}


//Movie
inline Movie::Movie(SDF::Obj d):Annot(d)
{
	REX(TRN_MovieAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Movie Movie::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_MovieAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Movie(result);
}


//T
inline UString Movie::GetTitle() const
{
	RetStr(TRN_MovieAnnotGetTitle(mp_annot, &result));
}

inline void Movie::SetTitle(const UString& title)
{
	REX(TRN_MovieAnnotSetTitle(mp_annot, title.mp_impl));
}

inline bool Movie::IsToBePlayed() const
{
	TRN_Bool result;
	REX(TRN_MovieAnnotIsToBePlayed(mp_annot,&result));
	return TBToB(result);
}

inline void Movie::SetToBePlayed(bool isplay)
{
	REX(TRN_MovieAnnotSetToBePlayed(mp_annot, BToTB(isplay)));
}

inline Movie::Movie(TRN_Annot movie) : Annot(movie)
{
	
}



//PolyLine
inline PolyLine::PolyLine(SDF::Obj d): Line(d)
{
	REX(TRN_PolyLineAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline PolyLine PolyLine::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_PolyLineAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return PolyLine(result);
}

inline PolyLine::PolyLine(TRN_Annot polyline) : Line(polyline)
{
	
}


inline int PolyLine::GetVertexCount() const
{
	int result;
	REX(TRN_PolyLineAnnotGetVertexCount(mp_annot, &result));
	return result;
}

inline Point PolyLine::GetVertex(int idx) const
{
	TRN_Point result;
	REX(TRN_PolyLineAnnotGetVertex(mp_annot, idx, &result));
	return *((Point*)&result);
}

inline void PolyLine::SetVertex(int idx, const Point& pt)
{
	REX(TRN_PolyLineAnnotSetVertex(mp_annot, idx, (const TRN_Point*)&pt));
}



//IT
inline PolyLine::IntentType PolyLine::GetIntentName() const
{
	enum TRN_PolyLineAnnotIntentType result;
	REX(TRN_PolyLineAnnotGetIntentName(mp_annot,&result));
	return (IntentType)result;
}

inline void PolyLine::SetIntentName(IntentType style)
{
	REX(TRN_PolyLineAnnotSetIntentName(mp_annot,(enum TRN_PolyLineAnnotIntentType)style));
}	




//Polygon
inline Polygon::Polygon(SDF::Obj d): PolyLine(d)
{
	REX(TRN_PolygonAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Polygon Polygon::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_PolygonAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Polygon(result);
}

inline Polygon::Polygon(TRN_Annot polygon) : PolyLine(polygon)
{
	
}



//Popup
inline Popup::Popup(SDF::Obj d):Annot(d)
{
	REX(TRN_PopupAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Popup Popup::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_PopupAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Popup(result);
}


//Parent
inline Annot Popup::GetParent() const
{
	TRN_Annot result;
	REX(TRN_PopupAnnotGetParent(mp_annot,&result));
	return Annot(result);	
}

inline void Popup::SetParent(const Annot& parent)
{
	REX(TRN_PopupAnnotSetParent(mp_annot, parent.mp_annot));
}


//Open
inline bool Popup::IsOpen() const
{
	TRN_Bool result;
	REX(TRN_PopupAnnotIsOpen(mp_annot,&result));
	return TBToB(result);	
}

inline void Popup::SetOpen(bool is_open)
{
	REX(TRN_PopupAnnotSetOpen(mp_annot, BToTB(is_open)));
}
				

inline Popup::Popup(TRN_Annot popup) : Annot(popup)
{
	
}

//Redaction
inline Redaction::Redaction(SDF::Obj d):Markup(d)
{
	REX(TRN_RedactionAnnotCreateFromObj(d.mp_obj, &mp_annot));
}
inline Redaction Redaction::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_RedactionAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Redaction(result);
}

inline int Redaction::GetQuadPointCount()
{
	int result;
	REX(TRN_RedactionAnnotGetQuadPointCount(mp_annot, &result));
	return result;				
}

inline QuadPoint Redaction::GetQuadPoint(int idx) const
{
	TRN_QuadPoint result;
	REX(TRN_RedactionAnnotGetQuadPoint(mp_annot, idx, &result));
	return *((QuadPoint*)&result);
}

inline void Redaction::SetQuadPoint(int idx, const QuadPoint& qp)
{
	REX(TRN_RedactionAnnotSetQuadPoint(mp_annot, idx, (const TRN_QuadPoint*)&qp));
}



//RO //According to Ivan, just using SDF::Obj
inline SDF::Obj Redaction::GetAppFormXO()const
{
	TRN_Obj result;
	REX(TRN_RedactionAnnotGetAppFormXO(mp_annot,&result));
	return SDF::Obj(result);
}

inline void Redaction::SetAppFormXO(SDF::Obj formxo)
{
	REX(TRN_RedactionAnnotSetAppFormXO(mp_annot, formxo.mp_obj));
}

//OverlayText
inline UString Redaction::GetOverlayText() const
{
	TRN_UString result;
	REX(TRN_RedactionAnnotGetOverlayText(mp_annot,&result));
	return UString(result);	
}
inline void Redaction::SetOverlayText(const UString& title)
{
	REX(TRN_RedactionAnnotSetOverlayText(mp_annot,title.mp_impl));
}

//Repeat
inline bool Redaction::GetUseRepeat() const
{
	TRN_Bool result;
	REX(TRN_RedactionAnnotGetUseRepeat(mp_annot,&result));
	return TBToB(result);
}

inline void Redaction::SetUseRepeat(bool repeat)
{
	REX(TRN_RedactionAnnotSetUseRepeat(mp_annot, BToTB(repeat)));
}

//DA
inline UString Redaction::GetOverlayTextAppearance() const
{
	TRN_UString result;
	REX(TRN_RedactionAnnotGetOverlayTextAppearance(mp_annot,&result));
	return UString(result);
}
inline void Redaction::SetOverlayTextAppearance(const UString& app)
{
	REX(TRN_RedactionAnnotSetOverlayTextAppearance(mp_annot,app.mp_impl));
}

//Q
inline Redaction::QuadForm Redaction::GetQuadForm() const
{
	enum TRN_RedactionAnnotQuadForm result;
	REX(TRN_RedactionAnnotGetQuadForm(mp_annot,&result));
	return (QuadForm)result;
}

inline void Redaction::SetQuadForm(QuadForm form)
{
	REX(TRN_RedactionAnnotSetQuadForm(mp_annot,(enum TRN_RedactionAnnotQuadForm)form));
}

inline Redaction::Redaction(TRN_Annot redaction) : Markup(redaction)
{
	
}


//RubberStamp
inline RubberStamp::RubberStamp(SDF::Obj d):Markup(d)
{
	REX(TRN_RubberStampAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline RubberStamp RubberStamp::Create(SDF::SDFDoc& doc, const Rect& pos, Icon icon)
{
	TRN_Annot result;
	REX(TRN_RubberStampAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	RubberStamp ret(result);
	ret.SetIcon(icon);
	return ret;
}

inline RubberStamp RubberStamp::Create(SDF::SDFDoc& doc, const Rect& pos, SDF::Obj* formxo)
{
	TRN_Annot result;
	REX(TRN_RubberStampAnnotCreateCustom(doc.mp_doc,(const TRN_Rect*)&pos, formxo->mp_obj, &result));
	RubberStamp ret(result);
	return ret;
}

inline RubberStamp::Icon RubberStamp::GetIcon() const
{
	enum TRN_RubberStampAnnotIcon result;
	REX(TRN_RubberStampAnnotGetIcon(mp_annot,&result));
	return (Icon)result;
}

inline void RubberStamp::SetIcon(Icon type)
{
	REX(TRN_RubberStampAnnotSetIcon(mp_annot,(enum TRN_RubberStampAnnotIcon)type));
}
inline const char* RubberStamp::GetIconName() const
{
	const char* result;
	REX(TRN_RubberStampAnnotGetIconName(mp_annot, &result));
	return result;
}

inline void RubberStamp::SetIcon(const char* icon)
{
	REX(TRN_RubberStampAnnotSetIconName(mp_annot, icon));
}

inline RubberStamp::RubberStamp(TRN_Annot rubberstamp) : Markup(rubberstamp)
{
	
}



//Sound
inline Sound::Sound(SDF::Obj d):Markup(d)
{
	REX(TRN_SoundAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Sound Sound::Create(SDF::SDFDoc& doc, const Rect& pos, Sound::Icon icon)
{
	TRN_Annot result;
	REX(TRN_SoundAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	REX(TRN_SoundAnnotSetIcon( result, (TRN_SoundAnnotIcon)icon ) );
	return Sound(result);
}

inline Sound Sound::CreateWithData(SDF::SDFDoc& doc, const Rect& pos, Filters::Filter source_data, int sample_bits, int sample_frequency, int num_channels, Sound::Icon icon)
{
	TRN_Annot result;
	source_data.m_owner = false;
	REX(TRN_SoundAnnotCreateWithData(doc.mp_doc,(const TRN_Rect*)&pos,source_data.m_impl, sample_bits, sample_frequency, num_channels, &result));
	REX(TRN_SoundAnnotSetIcon( result, (TRN_SoundAnnotIcon)icon ) );
	return Sound(result);
}

inline Sound Sound::Create(SDF::SDFDoc& doc, const Point& pos, Sound::Icon icon)
{
	TRN_Annot result;
	REX(TRN_SoundAnnotCreateAtPoint(doc.mp_doc,(const TRN_Point*)&pos, &result));
	REX(TRN_SoundAnnotSetIcon( result, (TRN_SoundAnnotIcon)icon ) );
	return Sound(result);
}



//Sound
inline SDF::Obj Sound::GetSoundStream() const
{
	TRN_Obj result;
	REX(TRN_SoundAnnotGetSoundStream(mp_annot, &result));
	return SDF::Obj(result);
}

inline void Sound::SetSoundStream(SDF::Obj sound_stream)
{
	REX(TRN_SoundAnnotSetSoundStream(mp_annot, sound_stream.mp_obj));
}

inline Sound::Icon Sound::GetIcon() const
{
	enum TRN_SoundAnnotIcon result;
	REX(TRN_SoundAnnotGetIcon(mp_annot, &result));
	return (Icon)result;	
}
inline void Sound::SetIcon(Icon type)
{
	REX(TRN_SoundAnnotSetIcon(mp_annot,(enum TRN_SoundAnnotIcon)type));
}

inline const char* Sound::GetIconName() const
{
	const char* result;
	REX(TRN_SoundAnnotGetIconName(mp_annot, &result));
	return result;
}
inline void Sound::SetIcon(const char* type)
{
	REX(TRN_SoundAnnotSetIconName(mp_annot, type));
}

inline Sound::Sound(TRN_Annot sound) : Markup(sound)
{
}


//Square
inline Square::Square(SDF::Obj d):Markup(d)
{
	REX(TRN_SquareAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Square Square::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_SquareAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Square(result);
}

inline Square::Square(TRN_Annot square) : Markup(square)
{
	
}

//Squiggly
inline Squiggly::Squiggly(SDF::Obj d):TextMarkup(d)
{
	REX(TRN_SquigglyAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Squiggly Squiggly::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_SquigglyAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Squiggly(result); 
}

inline Squiggly::Squiggly(TRN_Annot squiggly) : TextMarkup(squiggly)
{
}

//StrikeOut
inline StrikeOut::StrikeOut(SDF::Obj d):TextMarkup(d)
{
	REX(TRN_StrikeOutAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline StrikeOut StrikeOut::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_StrikeOutAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return StrikeOut(result); 
}

inline StrikeOut::StrikeOut(TRN_Annot strikeout) : TextMarkup(strikeout)
{
}


//Text
inline Text::Text(SDF::Obj d):Markup(d)
{
	REX(TRN_TextAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

//inline Text Text::Create(SDF::SDFDoc& doc, const Rect& pos)
//{
//	TRN_Annot result;
//	REX(TRN_TextAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
//	return Text(result);
//}

inline Text Text::Create(SDF::SDFDoc& doc, const Rect& pos, const UString& contents)
{
	TRN_Annot result;
	REX(TRN_TextAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	REX(TRN_AnnotSetContents(result, contents.mp_impl));
	return Text(result);
}

inline Text Text::Create(SDF::SDFDoc& doc, const Point& pos, const UString& contents)
{
	TRN_Annot result;
	REX(TRN_TextAnnotCreateAtPoint(doc.mp_doc,(const TRN_Point*)&pos, &result));
	if( contents.GetLength() > 0 )
		REX(TRN_AnnotSetContents(result, contents.mp_impl));
	return Text(result);
}

inline bool Text::IsOpen() const
{
	TRN_Bool result;
	REX(TRN_TextAnnotIsOpen(mp_annot,&result));
	return TBToB(result);
}

inline void Text::SetOpen(bool isopen)
{
	REX(TRN_TextAnnotSetOpen(mp_annot, BToTB(isopen)));
}

inline Text::Icon Text::GetIcon() const
{
	enum TRN_TextAnnotIcon result;
	REX(TRN_TextAnnotGetIcon(mp_annot,&result));
	return (Icon)result;
}

inline void Text::SetIcon(Icon type)
{
	REX(TRN_TextAnnotSetIcon(mp_annot,(enum TRN_TextAnnotIcon)type));
}

inline const char* Text::GetIconName() const
{
	const char* result;
	REX(TRN_TextAnnotGetIconName(mp_annot, &result));
	return result;
}

inline void Text::SetIcon(const char* icon)
{
	REX(TRN_TextAnnotSetIconName(mp_annot, icon));
}
						
//State
inline UString Text::GetState() const
{
	TRN_UString result;
	REX(TRN_TextAnnotGetState(mp_annot,&result));
	return UString(result);	
}

inline void Text::SetState(const UString& state)
{
	REX(TRN_TextAnnotSetState(mp_annot, state.mp_impl));
}

//StateModel
inline UString Text::GetStateModel() const
{
	TRN_UString result;
	REX(TRN_TextAnnotGetStateModel(mp_annot,&result));
	return UString(result);	
}

inline void Text::SetStateModel(const UString& statemodule)
{
	REX(TRN_TextAnnotSetStateModel(mp_annot, statemodule.mp_impl));
}


inline Text::Text(TRN_Annot text) : Markup(text)
{
}						


//TextMarkup
inline TextMarkup::TextMarkup(SDF::Obj d):Markup(d)
{
	REX(TRN_TextMarkupAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline int TextMarkup::GetQuadPointCount()
{
	int result;
	REX(TRN_TextMarkupAnnotGetQuadPointCount(mp_annot, &result));
	return result;					
}

inline QuadPoint TextMarkup::GetQuadPoint(int idx) const
{
	TRN_QuadPoint result;
	REX(TRN_TextMarkupAnnotGetQuadPoint(mp_annot, idx, &result));
	return *((QuadPoint*)&result);
}

inline void TextMarkup::SetQuadPoint(int idx, const QuadPoint& qp)
{
	REX(TRN_TextMarkupAnnotSetQuadPoint(mp_annot, idx, (const TRN_QuadPoint*)&qp));
}

inline TextMarkup::TextMarkup(TRN_Annot textmarkup) : Markup(textmarkup)
{
}


//Underline
inline Underline::Underline(SDF::Obj d):TextMarkup(d)
{
	REX(TRN_UnderlineAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Underline Underline::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_UnderlineAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Underline(result); 
}

inline Underline::Underline(TRN_Annot underline) : TextMarkup(underline)
{
	
}

//Watermark
inline Watermark::Watermark(SDF::Obj d):Annot(d)
{
	REX(TRN_WatermarkAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Watermark Watermark::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_WatermarkAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Watermark(result); 
}

inline Watermark::Watermark(TRN_Annot watermark) : Annot(watermark)
{
	
}

		};// namespace Annots

	};
};

#ifdef SWIG
#undef Highlight
#undef Line
#undef Redaction
#endif

#endif
