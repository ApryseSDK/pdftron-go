//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPageSet
#define PDFTRON_H_CPDFPageSet

#define PageSetCCast (PageSet*)

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_PageSet.h>

#ifdef __cplusplus
extern "C" {
#endif


enum TRN_PageSetFilter
{
	e_PageSet_all,
	e_PageSet_even,
	e_PageSet_odd
};

//Constructor and destructor
TRN_API TRN_PageSetCreate(TRN_PageSet* result);

TRN_API TRN_PageSetCreateSinglePage(int one_page, TRN_PageSet* result);

TRN_API TRN_PageSetCreateRange(int range_start, int range_end, TRN_PageSet* result);

TRN_API TRN_PageSetCreateFilteredRange(int range_start, int range_end, enum TRN_PageSetFilter filter, TRN_PageSet* result);

TRN_API TRN_PageSetDestroy(TRN_PageSet page_set);

TRN_API TRN_PageSetAddPage(TRN_PageSet page_set, int one_page);

TRN_API TRN_PageSetAddRange(TRN_PageSet page_set, int range_start, int range_end, enum TRN_PageSetFilter filter);


#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPageSet
