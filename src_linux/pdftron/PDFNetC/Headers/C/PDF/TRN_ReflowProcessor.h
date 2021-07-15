//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPDFReflowProcessor
#define PDFTRON_H_CPDFReflowProcessor

#include <C/Common/TRN_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

	enum TRN_ResultState {
		e_failure,
		e_success,
		e_security_error,
		e_cancel,
		e_package_error,
		e_previous_crash,
		e_not_found,
		e_fetch,
		e_render,
		e_postponed
	};

	typedef void(*TRN_ProcHandler) (enum TRN_ResultState state, const char * utf8_filepath, void * custom_data);

	TRN_API TRN_ReflowProcessorInitialize();
	TRN_API TRN_ReflowProcessorIsInitialized(TRN_Bool* result);
	TRN_API TRN_ReflowProcessorGetReflow(const TRN_Page page, TRN_ProcHandler proc, void * custom_data);
	TRN_API TRN_ReflowProcessorCancelAllRequests();
	TRN_API TRN_ReflowProcessorCancelRequest(const TRN_Page page);
	TRN_API TRN_ReflowProcessorClearCache();
	TRN_API TRN_SetNoReflowContent(TRN_UString content);
	TRN_API TRN_SetReflowFailedContent(TRN_UString content);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFReflowProcessor
