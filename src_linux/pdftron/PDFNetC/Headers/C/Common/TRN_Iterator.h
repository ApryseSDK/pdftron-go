//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonIterator
#define PDFTRON_H_CCommonIterator

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif 

TRN_API TRN_IteratorHasNext(TRN_Iterator itr,TRN_Bool* result);
TRN_API TRN_IteratorCurrent(TRN_Iterator itr, TRN_ItrData* result);
TRN_API TRN_IteratorNext(TRN_Iterator itr);
TRN_API TRN_IteratorAssign(TRN_Iterator right, TRN_Iterator* result);
TRN_API TRN_IteratorDestroy(TRN_Iterator itr);
TRN_API TRN_DictIteratorHasNext(TRN_DictIterator itr,TRN_Bool* result);
TRN_API TRN_DictIteratorKey(TRN_DictIterator itr, TRN_Obj* result);
TRN_API TRN_DictIteratorValue(TRN_DictIterator itr, TRN_Obj* result);
TRN_API TRN_DictIteratorNext(TRN_DictIterator itr);
TRN_API TRN_DictIteratorAssign(TRN_DictIterator right, TRN_DictIterator* result);
TRN_API TRN_DictIteratorDestroy(TRN_DictIterator itr);

#ifdef __cplusplus
}
#endif 

#endif // PDFTRON_H_CCommonIterator
