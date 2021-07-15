//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPCommonCommon
#define PDFTRON_H_CPPCommonCommon

#include <C/Common/TRN_Types.h>
#include <Common/BasicTypes.h>
#include <Common/Exception.h>
#include <string.h>

#define REX(action) { TRN_Exception ex=action; if(ex!=0) throw Common::Exception(ex); }
#define DREX(impl, destroy_action) \
	if (impl) {\
		destroy_action;\
		impl = 0;\
	}
#define DREX_NO_IMPL(destroy_action) destroy_action

#define RetObj(ex) TRN_Obj result; REX(ex); return SDF::Obj(result);
#define RetBool(ex) TRN_Bool result; REX(ex); return TBToB(result);
#define RetInt(ex) int result; REX(ex); return result;
#define RetCCS(ex) const char* result; REX(ex); return result;
#define RetDbl(ex) double result; REX(ex); return result;
#define RetStr(ex) TRN_UString result; REX(ex); return UString(result);

#define RetPC(ex) TRN_PatternColor result; REX(ex); return PatternColor(result);
#define RetFont(ex) TRN_Font result; REX(ex); return Font(result);
#define RetRec(ex) TRN_Rect result; REX(ex); return *((Rect*)&result);
#define RetMtx(ex) TRN_Matrix2D result; REX(ex); return *((Common::Matrix2D*)&result)
#define RetCPT(ex) TRN_ColorPt result; TRN_ColorPtInit(0,0,0,0, &result); REX(ex); return *((ColorPt*)&result)
#define RetFDFField(ex) TRN_FDFField result; REX(ex); return *((FDFField*)&result)

#endif // PDFTRON_H_CPPCommonCommon
