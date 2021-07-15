//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFAction
#define PDFTRON_H_CPDFAction

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_ActionCreateGoto(TRN_Destination dest, TRN_Action* result);
TRN_API TRN_ActionCreateGotoWithKey(TRN_String key, TRN_Destination dest, TRN_Action* result);
TRN_API TRN_ActionCreateGotoRemote(const TRN_FileSpec file, int page_num, TRN_Action* result);
TRN_API TRN_ActionCreateGotoRemoteSetNewWindow(const TRN_FileSpec file, int page_num, TRN_Bool new_window, TRN_Action* result);
TRN_API TRN_ActionCreateURI(TRN_SDFDoc sdfdoc, const char* uri, TRN_Action* result);
TRN_API TRN_ActionCreateURIWithUString(TRN_SDFDoc sdfdoc, const TRN_UString uri, TRN_Action* result);
TRN_API TRN_ActionCreateSubmitForm(const TRN_FileSpec url, TRN_Action* result);
TRN_API TRN_ActionCreateLaunch(TRN_SDFDoc sdfdoc, const char* path, TRN_Action* result);
TRN_API TRN_ActionCreateHideField(TRN_SDFDoc sdfdoc, const char** field_names_list, int field_names_list_size, TRN_Action* result);
TRN_API TRN_ActionCreateImportData(TRN_SDFDoc sdfdoc, const char* path, TRN_Action* result);
TRN_API TRN_ActionCreateResetForm(TRN_SDFDoc sdfdoc, TRN_Action* result);
TRN_API TRN_ActionCreateJavaScript(TRN_SDFDoc sdfdoc, const char* script, TRN_Action* result);
TRN_API TRN_ActionCreate (TRN_Obj in_obj, TRN_Action* result);
TRN_API TRN_ActionCopy (const TRN_Action in_action, TRN_Action* result);
TRN_API TRN_ActionCompare(TRN_Action action, const TRN_Action in_action, TRN_Bool* result);
TRN_API TRN_ActionIsValid(const TRN_Action action,TRN_Bool* result) ;

enum TRN_ActionType
{
		e_Action_GoTo,
		e_Action_GoToR,
		e_Action_GoToE,
		e_Action_Launch,
		e_Action_Thread,
		e_Action_URI,
		e_Action_Sound,
		e_Action_Movie,
		e_Action_Hide,
		e_Action_Named,
		e_Action_SubmitForm,
		e_Action_ResetForm,
		e_Action_ImportData,
		e_Action_JavaScript,
		e_Action_SetOCGState,
		e_Action_Rendition,
		e_Action_Trans,
		e_Action_GoTo3DView,
		e_Action_RichMediaExecute,
		e_Action_Unknown
};

TRN_API TRN_ActionGetType(const TRN_Action action, enum TRN_ActionType* result);
TRN_API TRN_ActionGetDest(TRN_Action action, TRN_Destination* result);
TRN_API TRN_ActionGetNext (const TRN_Action action,TRN_Obj* result);
TRN_API TRN_ActionGetSDFObj (const TRN_Action action,TRN_Obj* result);

enum TRN_ActionFormActionFlag
{
	e_Action_exclude = 0,
	e_Action_include_no_value_fields  = 1,
	e_Action_export_format = 2,			// submit in HTML format if set, FDF format if clear
	e_Action_get_method = 3,
	e_Action_submit_coordinates = 4,
	e_Action_xfdf = 5,
	e_Action_include_append_saves = 6,
	e_Action_include_annotations = 7,
	e_Action_submit_pdf = 8,
	e_Action_canonical_format = 9,
	e_Action_excl_non_user_annots = 10,
	e_Action_excl_F_key = 11,
	// bit 12 is unused by PDF standard
	e_Action_embed_form = 13
};

TRN_API TRN_Action_GetFormActionFlag(const TRN_Action action, enum TRN_ActionFormActionFlag flag, TRN_Bool* result);
TRN_API TRN_Action_SetFormActionFlag(TRN_Action action, enum TRN_ActionFormActionFlag flag, TRN_Bool value);
TRN_API TRN_ActionNeedsWriteLock(const TRN_Action action, TRN_Bool* result);

TRN_API TRN_Action_Execute( TRN_Action action );

TRN_API TRN_ActionExecuteKeyStrokeAction(TRN_Action action, const TRN_KeyStrokeEventData data, TRN_KeyStrokeActionResult* result);

TRN_API TRN_KeyStrokeActionResultIsValid(const TRN_KeyStrokeActionResult action_ret, TRN_Bool* result);
TRN_API TRN_KeyStrokeActionResultGetText(const TRN_KeyStrokeActionResult action_ret, TRN_UString* result);
TRN_API TRN_KeyStrokeActionResultDestroy(TRN_KeyStrokeActionResult action_ret);
TRN_API TRN_KeyStrokeActionResultCopy(TRN_KeyStrokeActionResult action_ret, TRN_KeyStrokeActionResult* result);
TRN_API TRN_KeyStrokeActionResultAssign(TRN_KeyStrokeActionResult left, TRN_KeyStrokeActionResult right);

TRN_API TRN_KeyStrokeEventDataCreate(const TRN_UString field_name, const TRN_UString current, const TRN_UString change, int selection_start, int selection_end, TRN_KeyStrokeEventData* result);
TRN_API TRN_KeyStrokeEventDataDestroy(TRN_KeyStrokeEventData data);
TRN_API TRN_KeyStrokeEventDataCopy(TRN_KeyStrokeEventData data, TRN_KeyStrokeEventData* result);
TRN_API TRN_KeyStrokeEventDataAssign(TRN_KeyStrokeEventData left, TRN_KeyStrokeEventData right);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFAction
