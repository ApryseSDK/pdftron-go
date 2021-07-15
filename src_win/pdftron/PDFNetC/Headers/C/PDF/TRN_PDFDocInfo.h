//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFDocInfo
#define PDFTRON_H_CPDFPDFDocInfo

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_PDFDocInfoGetTitle(TRN_PDFDocInfo info, TRN_UString* result);

TRN_API TRN_PDFDocInfoGetTitleObj(TRN_PDFDocInfo info, TRN_Obj* result);

TRN_API TRN_PDFDocInfoSetTitle(TRN_PDFDocInfo info, const TRN_UString title);

TRN_API TRN_PDFDocInfoGetAuthor(TRN_PDFDocInfo info, TRN_UString* result);

TRN_API TRN_PDFDocInfoGetAuthorObj(TRN_PDFDocInfo info, TRN_Obj* result);

TRN_API TRN_PDFDocInfoSetAuthor(TRN_PDFDocInfo info, const TRN_UString author);

TRN_API TRN_PDFDocInfoGetSubject(TRN_PDFDocInfo info, TRN_UString* result);

TRN_API TRN_PDFDocInfoGetSubjectObj(TRN_PDFDocInfo info, TRN_Obj* result);

TRN_API TRN_PDFDocInfoSetSubject(TRN_PDFDocInfo info, const TRN_UString subject);

TRN_API TRN_PDFDocInfoGetKeywords(TRN_PDFDocInfo info, TRN_UString* result);

TRN_API TRN_PDFDocInfoGetKeywordsObj(TRN_PDFDocInfo info, TRN_Obj* result);

TRN_API TRN_PDFDocInfoSetKeywords(TRN_PDFDocInfo info, const TRN_UString keywords);

TRN_API TRN_PDFDocInfoGetCreator(TRN_PDFDocInfo info, TRN_UString* result);

TRN_API TRN_PDFDocInfoGetCreatorObj(TRN_PDFDocInfo info, TRN_Obj* result);

TRN_API TRN_PDFDocInfoSetCreator(TRN_PDFDocInfo info, const TRN_UString creator);

TRN_API TRN_PDFDocInfoGetProducer(TRN_PDFDocInfo info, TRN_UString* result);

TRN_API TRN_PDFDocInfoGetProducerObj(TRN_PDFDocInfo info, TRN_Obj* result);

TRN_API TRN_PDFDocInfoSetProducer(TRN_PDFDocInfo info, const TRN_UString producer);

TRN_API TRN_PDFDocInfoGetCreationDate(TRN_PDFDocInfo info, TRN_Date* result);

TRN_API TRN_PDFDocInfoSetCreationDate(TRN_PDFDocInfo info, const TRN_Date* creation_date);

TRN_API TRN_PDFDocInfoGetModDate(TRN_PDFDocInfo info, TRN_Date* result);

TRN_API TRN_PDFDocInfoSetModDate(TRN_PDFDocInfo info, const TRN_Date* mod_date);

TRN_API TRN_PDFDocInfoGetSDFObj(TRN_PDFDocInfo info, TRN_Obj* result);

TRN_API TRN_PDFDocInfoCreate(TRN_Obj tr, TRN_PDFDocInfo* result);

TRN_API TRN_PDFDocInfoCopy (const TRN_PDFDocInfo info, TRN_PDFDocInfo* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFDocInfo
