//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPFiltersASCII85Encode
#define PDFTRON_H_CPPFiltersASCII85Encode

#include <Filters/Filter.h>
#include <Common/Common.h>
#include <C/Filters/TRN_Filter.h>

namespace pdftron { 
	namespace Filters {

/** 
 * ASCII85Encode filter can be used to encode any data stream
 * into a stream that does not contain any binary characters.
 */
class ASCII85Encode : public Filter
{
public:

	/**
	 * @param line_width specifies the width of the encoded line expressed in the number of characters.
	 */
	 ASCII85Encode (Filter input_filter, int line_width = 72, size_t buf_sz = 256);
};

#include <Impl/ASCII85Encode.inl>


	};	// namespace Filters
};	// namespace pdftron

#endif // PDFTRON_H_CPPFiltersASCII85Encode
