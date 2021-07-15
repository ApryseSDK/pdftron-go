//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFAppearanceReferenceList
#define PDFTRON_H_CPDFAppearanceReferenceList

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_Annot.h>

	TRN_API TRN_AppearanceReferenceListCreate(TRN_AppearanceReferenceList* result);
	TRN_API TRN_AppearanceReferenceListAddReference(TRN_AppearanceReferenceList references, TRN_UInt32 obj_num, TRN_UInt16 gen_num, const char* appearance_state, enum TRN_AnnotState annot_state);
	TRN_API TRN_AppearanceReferenceListDestroy(TRN_AppearanceReferenceList references);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFAppearanceReferenceList
