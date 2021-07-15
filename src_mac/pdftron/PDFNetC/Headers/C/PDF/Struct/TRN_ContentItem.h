//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFStructContentItem
#define PDFTRON_H_CPDFStructContentItem

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_ContentItemCopy(const TRN_ContentItem* c, TRN_ContentItem* result);

enum TRN_ContentItemType 
{
	e_ContentItem_MCR,    
	e_ContentItem_MCID,    
	e_ContentItem_OBJR,    
	e_ContentItem_Unknown  
};

TRN_API TRN_ContentItemGetType(const TRN_ContentItem* item, enum TRN_ContentItemType* result);
TRN_API TRN_ContentItemGetParent(TRN_ContentItem* item, TRN_SElement* result);
TRN_API TRN_ContentItemGetPage(TRN_ContentItem* item, TRN_Page* result);
TRN_API TRN_ContentItemGetSDFObj (const TRN_ContentItem* item, TRN_Obj* result);
TRN_API TRN_ContentItemGetMCID(const TRN_ContentItem* item, int* result);
TRN_API TRN_ContentItemGetContainingStm(const TRN_ContentItem* item, TRN_Obj* result);
TRN_API TRN_ContentItemGetStmOwner(const TRN_ContentItem* item, TRN_Obj* result);
TRN_API TRN_ContentItemGetRefObj(const TRN_ContentItem* item, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFStructContentItem
