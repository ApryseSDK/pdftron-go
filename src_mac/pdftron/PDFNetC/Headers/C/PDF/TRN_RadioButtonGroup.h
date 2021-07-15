//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFRadioButtonGroup
#define PDFTRON_H_CPDFRadioButtonGroup

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

	TRN_API TRN_RadioButtonGroupCreateFromField(const TRN_Field* field, TRN_RadioButtonGroup* result);
	TRN_API TRN_RadioButtonGroupCreate(TRN_PDFDoc doc, TRN_UString field_name, TRN_RadioButtonGroup* result);
	TRN_API TRN_RadioButtonGroupCopy(TRN_RadioButtonGroup group, TRN_RadioButtonGroup* result);
	TRN_API TRN_RadioButtonGroupAssign(TRN_RadioButtonGroup left, TRN_RadioButtonGroup right);
	
	TRN_API TRN_RadioButtonGroupDestroy(TRN_RadioButtonGroup group);


	TRN_API TRN_RadioButtonGroupAdd(TRN_RadioButtonGroup group, const TRN_Rect* pos, const char* onstate, TRN_RadioButtonWidget* result);
	TRN_API TRN_RadioButtonGroupGetNumButtons(TRN_RadioButtonGroup group, TRN_UInt32* result);
	TRN_API TRN_RadioButtonGroupGetButton(TRN_RadioButtonGroup group, TRN_UInt32 index, TRN_RadioButtonWidget* result);
	TRN_API TRN_RadioButtonGroupGetField(TRN_RadioButtonGroup group, TRN_Field* result);
	TRN_API TRN_RadioButtonGroupAddGroupButtonsToPage(TRN_RadioButtonGroup group, TRN_Page page);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFRadioButtonGroup
