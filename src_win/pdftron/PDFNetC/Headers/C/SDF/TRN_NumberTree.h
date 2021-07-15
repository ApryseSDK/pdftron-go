//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CSDFNumberTree
#define PDFTRON_H_CSDFNumberTree

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>


TRN_API TRN_NumberTreeCreate(TRN_Obj number_tree, TRN_NumberTree* result);

TRN_API TRN_NumberTreeCopy (TRN_NumberTree const tree, TRN_NumberTree* result);

TRN_API TRN_NumberTreeIsValid(TRN_NumberTree tree, TRN_Bool* result);

TRN_API TRN_NumberTreeGetIterator(TRN_NumberTree tree, TRN_Int32 key, 
			 TRN_DictIterator* result);

TRN_API TRN_NumberTreeGetValue(TRN_NumberTree tree, TRN_Int32 key, 
			 TRN_Obj* result);

TRN_API TRN_NumberTreeGetIteratorBegin(TRN_NumberTree tree, 
								  TRN_DictIterator* result);

TRN_API TRN_NumberTreePut (TRN_NumberTree tree, TRN_Int32 key, TRN_Obj value);	

TRN_API TRN_NumberTreeEraseKey (TRN_NumberTree tree, TRN_Int32 key);

TRN_API TRN_NumberTreeErase (TRN_NumberTree tree, TRN_DictIterator pos);

TRN_API TRN_NumberTreeGetSDFObj (TRN_NumberTree const tree, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CSDFNumberTree
