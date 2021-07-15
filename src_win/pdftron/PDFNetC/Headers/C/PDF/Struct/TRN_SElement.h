//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFStructSElement
#define PDFTRON_H_CPDFStructSElement

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_SElementCreate(TRN_Obj dict, TRN_SElement* result);
TRN_API TRN_SElementAssign (TRN_SElement* left, const TRN_SElement* right);
TRN_API TRN_SElementCreateFromPDFDoc(TRN_PDFDoc doc, const char* struct_type, TRN_SElement* result);
TRN_API TRN_SElementInsert(TRN_SElement* e, TRN_SElement* kid, int insert_before);
TRN_API TRN_SElementCreateContentItem(TRN_SElement* e, TRN_PDFDoc doc, TRN_Page page, int insert_before, int* result);
TRN_API TRN_SElementIsValid(const TRN_SElement* e, TRN_Bool* result);
TRN_API TRN_SElementGetType(const TRN_SElement* e, const char** result);
TRN_API TRN_SElementGetNumKids(const TRN_SElement* e, int* result);
TRN_API TRN_SElementIsContentItem(const TRN_SElement* e, int index, TRN_Bool* result);
TRN_API TRN_SElementGetAsContentItem(const TRN_SElement* e, int index, TRN_ContentItem* result);
TRN_API TRN_SElementGetAsStructElem(const TRN_SElement* e, int index, TRN_SElement* result);
TRN_API TRN_SElementGetParent(const TRN_SElement* e, TRN_SElement* result);
TRN_API TRN_SElementGetStructTreeRoot(const TRN_SElement* e, TRN_STree* result);
TRN_API TRN_SElementHasTitle(const TRN_SElement* e, TRN_Bool* result);
TRN_API TRN_SElementGetTitle(const TRN_SElement* e, TRN_UString* result);
TRN_API TRN_SElementGetID(const TRN_SElement* e, TRN_Obj* result);
TRN_API TRN_SElementHasActualText(const TRN_SElement* e, TRN_Bool* result);
TRN_API TRN_SElementGetActualText(const TRN_SElement* e, TRN_UString* result);
TRN_API TRN_SElementHasAlt(const TRN_SElement* e, TRN_Bool* result);
TRN_API TRN_SElementGetAlt(const TRN_SElement* e, TRN_UString* result);
TRN_API TRN_SElementGetSDFObj(const TRN_SElement* e, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFStructSElement
