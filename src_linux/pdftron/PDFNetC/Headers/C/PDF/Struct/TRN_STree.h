//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFStructSTree
#define PDFTRON_H_CPDFStructSTree

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_STreeCreate (TRN_Obj struct_dict, TRN_STree* result);
TRN_API TRN_STreeCreateFromPDFDoc (TRN_PDFDoc doc, TRN_STree* result);
TRN_API TRN_STreeInsert (TRN_STree tree, TRN_SElement* kid, int insert_before);
TRN_API TRN_STreeCopy (const TRN_STree c,TRN_STree* result);
TRN_API TRN_STreeIsValid(const TRN_STree tree, TRN_Bool* result);
TRN_API TRN_STreeGetNumKids(TRN_STree tree, int* result);
TRN_API TRN_STreeGetKid(TRN_STree tree, int index, TRN_SElement* result);
TRN_API TRN_STreeGetElement(TRN_STree tree, const char* id_buf, int id_buf_sz, TRN_SElement* result);
TRN_API TRN_STreeGetRoleMap(const TRN_STree tree, TRN_RoleMap* result);
TRN_API TRN_STreeGetClassMap(const TRN_STree tree, TRN_ClassMap* result);
TRN_API TRN_STreeGetSDFObj (const TRN_STree tree, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFStructSTree
