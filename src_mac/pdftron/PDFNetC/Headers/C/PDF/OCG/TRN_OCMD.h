//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFOCGOCMD
#define PDFTRON_H_CPDFOCGOCMD

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

enum TRN_OCMDVisibilityPolicyType {
	e_OCMD_AllOn, 
	e_OCMD_AnyOn, 
	e_OCMD_AnyOff, 
	e_OCMD_AllOff
};

TRN_API TRN_OCMDCreateFromObj(TRN_Obj ocmd_dict, TRN_OCMD* result);
TRN_API TRN_OCMDCreate(TRN_PDFDoc pdfdoc, TRN_Obj ocgs, enum TRN_OCMDVisibilityPolicyType vis_policy, TRN_OCMD* result);
TRN_API TRN_OCMDCopy(const TRN_OCMD ocmd, TRN_OCMD* result);
TRN_API TRN_OCMDGetSDFObj (const TRN_OCMD ocmd, TRN_Obj* result);

TRN_API TRN_OCMDGetOCGs (const TRN_OCMD ocmd, TRN_Obj* result);
TRN_API TRN_OCMDGetVisibilityExpression (const TRN_OCMD ocmd, TRN_Obj* result);

TRN_API TRN_OCMDIsValid(const TRN_OCMD ocmd, TRN_Bool* result);
TRN_API TRN_OCMDIsCurrentlyVisible(const TRN_OCMD ocmd, const TRN_OCGContext ctx, TRN_Bool* result);

TRN_API TRN_OCMDGetVisibilityPolicy(const TRN_OCMD ocmd, enum TRN_OCMDVisibilityPolicyType* result);
TRN_API TRN_OCMDSetVisibilityPolicy(const TRN_OCMD ocmd, enum TRN_OCMDVisibilityPolicyType vis_policy);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFOCGOCMD
