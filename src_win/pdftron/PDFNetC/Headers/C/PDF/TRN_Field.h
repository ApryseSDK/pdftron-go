//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFField
#define PDFTRON_H_CPDFField

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_FieldCreate (TRN_Obj field_dict, TRN_Field* result);
TRN_API TRN_FieldAssign (TRN_Field* left, const TRN_Field* right);
TRN_API TRN_FieldDestroy(TRN_Field* field);
TRN_API TRN_FieldIsValid(const TRN_Field* field, TRN_Bool* result) ;

enum TRN_FieldEventType
{
	e_Field_action_trigger_keystroke = 13,
	e_Field_action_trigger_format,
	e_Field_action_trigger_validate,
	e_Field_action_trigger_calculate
};

enum TRN_FieldType
{
	e_Field_button,
	e_Field_check,
	e_Field_radio,
	e_Field_text,
	e_Field_choice,
	e_Field_signature,
	e_Field_null
};

TRN_API TRN_FieldGetType(const TRN_Field* field, enum TRN_FieldType* result);
TRN_API TRN_FieldGetValue(const TRN_Field* field,TRN_Obj* result);
TRN_API TRN_FieldGetValueAsString(const TRN_Field* field, TRN_UString* result);
TRN_API TRN_FieldGetDefaultValueAsString(const TRN_Field* field, TRN_UString* result);
TRN_API TRN_FieldSetValueAsString(TRN_Field* field, TRN_UString value, TRN_ViewChangeCollection* result);
TRN_API TRN_FieldSetValue(TRN_Field* field, TRN_Obj value, TRN_ViewChangeCollection* result);
TRN_API TRN_FieldSetValueAsBool(TRN_Field* field, TRN_Bool value, TRN_ViewChangeCollection* result);
TRN_API TRN_FieldGetTriggerAction(const TRN_Field* field, enum TRN_FieldEventType trigger, TRN_Obj* result);

TRN_API TRN_FieldGetValueAsBool(const TRN_Field* field, TRN_Bool* result);
TRN_API TRN_FieldRefreshAppearance(TRN_Field* field);
TRN_API TRN_FieldEraseAppearance(TRN_Field* field);
TRN_API TRN_FieldGetDefaultValue(const TRN_Field* field, TRN_Obj* result);
TRN_API TRN_FieldGetName(const TRN_Field* field, TRN_UString* result);
TRN_API TRN_FieldGetPartialName(const TRN_Field* field, TRN_UString* result);
TRN_API TRN_FieldRename(TRN_Field* field, const TRN_UString field_name);
TRN_API TRN_FieldIsAnnot(const TRN_Field* field, TRN_Bool* result);

TRN_API TRN_FieldUseSignatureHandler(TRN_Field* field, const TRN_SignatureHandlerId signature_handler_id, TRN_Obj* result);

enum TRN_FieldFlag
{
	e_Field_read_only,
	e_Field_required,
	e_Field_no_export,

	e_Field_pushbutton_flag,

	e_Field_radio_flag,
	e_Field_toggle_to_off,
	e_Field_radios_in_unison,

	e_Field_multiline,
	e_Field_password,
	e_Field_file_select,
	e_Field_no_spellcheck,
	e_Field_no_scroll,
	e_Field_comb,
	e_Field_rich_text,
	e_Field_combo,
	e_Field_edit,
	e_Field_sort,
	e_Field_multiselect,
	e_Field_commit_on_sel_change
};

TRN_API TRN_FieldGetFlag(const TRN_Field* field, enum TRN_FieldFlag flag, TRN_Bool* result);
TRN_API TRN_FieldSetFlag(TRN_Field* field, enum TRN_FieldFlag flag, TRN_Bool value);

enum TRN_FieldTextJustification
{
	e_Field_left_justified,
	e_Field_centered,
	e_Field_right_justified
};

TRN_API TRN_FieldGetJustification(TRN_Field* field, enum TRN_FieldTextJustification* result);
TRN_API TRN_FieldSetJustification(TRN_Field* field, enum TRN_FieldTextJustification j);
TRN_API TRN_FieldSetMaxLen(TRN_Field* field, int max_len);
TRN_API TRN_FieldGetMaxLen(const TRN_Field* field, int* result);
TRN_API TRN_FieldGetDefaultAppearance(TRN_Field* field, TRN_GState* result);

TRN_API TRN_FieldGetUpdateRect(const TRN_Field* field, TRN_Rect* result);
TRN_API TRN_FieldFlatten(TRN_Field* field, TRN_Page page);
TRN_API TRN_FieldFindInheritedAttribute (const TRN_Field* field, const char* attrib, TRN_Obj* result);
TRN_API TRN_FieldGetSDFObj (const TRN_Field* field, TRN_Obj* result);

TRN_API TRN_FieldGetOptCount(const TRN_Field* field, int* result);
TRN_API TRN_FieldGetOpt(const TRN_Field* field, int index, TRN_UString* result);

TRN_API TRN_FieldIsLockedByDigitalSignature(const TRN_Field* field, TRN_Bool* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFField
