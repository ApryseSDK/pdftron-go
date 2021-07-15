//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFDestination
#define PDFTRON_H_CPDFDestination

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

enum TRN_DestinationFitType
{
	e_Destination_XYZ,
	e_Destination_Fit,
	e_Destination_FitH,
	e_Destination_FitV,
	e_Destination_FitR,
	e_Destination_FitB,
	e_Destination_FitBH,
	e_Destination_FitBV
};

TRN_API TRN_DestinationCreateXYZ(TRN_Page page, double left, double top, double zoom, TRN_Destination* result);

TRN_API TRN_DestinationCreateFit(TRN_Page page, TRN_Destination* result);

TRN_API TRN_DestinationCreateFitH(TRN_Page page, double top, TRN_Destination* result);

TRN_API TRN_DestinationCreateFitV(TRN_Page page, double left, TRN_Destination* result);

TRN_API TRN_DestinationCreateFitR(TRN_Page page,
	double left, double bottom,	double right, double top, TRN_Destination* result);

TRN_API TRN_DestinationCreateFitB(TRN_Page page, TRN_Destination* result);

TRN_API TRN_DestinationCreateFitBH(TRN_Page page, double top, TRN_Destination* result);

TRN_API TRN_DestinationCreateFitBV(TRN_Page page, double left, TRN_Destination* result);

TRN_API TRN_DestinationCreate(TRN_Obj dest, TRN_Destination* result);

TRN_API TRN_DestinationCopy (const TRN_Destination d, TRN_Destination* result);

TRN_API TRN_DestinationIsValid(const TRN_Destination dest, TRN_Bool* result);

TRN_API TRN_DestinationGetFitType(TRN_Destination dest,enum TRN_DestinationFitType* result);

TRN_API TRN_DestinationGetPage(TRN_Destination dest, TRN_Page* result);

TRN_API TRN_DestinationSetPage(TRN_Destination dest, TRN_Page page);

TRN_API TRN_DestinationGetSDFObj (const TRN_Destination dest, TRN_Obj* result);

TRN_API TRN_DestinationGetExplicitDestObj (TRN_Destination dest, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFDestination
