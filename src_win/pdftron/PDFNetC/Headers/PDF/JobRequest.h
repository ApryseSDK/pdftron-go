//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef   H_PDFJobRequest
#define   H_PDFJobRequest

namespace pdftron {
	namespace PDF {

class JobRequest
{
public:

	/*
	* ResultState contains the valid result state of requesting a job
	*/
	enum ResultState {
		e_failure,			///< The request could not be retrieved.
		e_success,			///< Successful retrieval of the request.
		e_security_error,	///< Failure due to password restriction.
		e_cancel,			///< The request was cancelled before it was processed.
		e_package_error,	///< Failure due to encountering a PDF package
		e_previous_crash,	///< Abort this render because we've crashed on this file previously
		e_not_found,		///< GetBitmap was called with a uuid, but could not find the bitmap. GetBitmap should be called again with the document corresponding to that id.
		e_fetch,			///< The following cases are just used for debugging and are not exposed
		e_render,			///  Change to e_success for final release
		e_postponed
	};

	/**
	* Callback for JobRequest
	*
	* @param state Contains the information about the result state of requesting a job
	* @param utf8_filepath An UTF-8, null terminated C-String containing the file path of the requested job. In case of failure utf8_filepath is empty.
	* @param custom_data Custom data specified by the user.
	*/
	typedef void(*ProcHandler) (ResultState state, const char * utf8_filepath, void * custom_data);
};

	};	// namespace PDF
};	// namespace pdftron

#endif // H_PDFJobRequest