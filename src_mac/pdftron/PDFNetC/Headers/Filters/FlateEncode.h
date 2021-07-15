//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPFiltersFlateEncode
#define PDFTRON_H_CPPFiltersFlateEncode

#include <Filters/Filter.h>
#include <Common/Common.h>
#include <C/Filters/TRN_Filter.h>

namespace pdftron { 
	namespace Filters {

/** 
 * FlateEncode filter can be used to compress any data stream 
 * using Flate (i.e. ZIP) compression method. 
 */
class FlateEncode : public Filter
{
public:

	/** 
	 * Constructor for Flate encoder.
	 *
	 * @param input_filter the input data stream
	 * @param compression_level must be a number between 0 and 9: 1 gives best speed, 
	 * 9 gives best compression, 0 gives no compression at all (the input data is simply 
	 * copied a block at a time), -1 requests a default compromise between speed 
	 * and compression (currently equivalent to level 6).
	 * @param buf_sz filter buffer size (in bytes).
	 */
	FlateEncode (Filter input_filter, int compression_level = -1, size_t buf_sz = 256);
};

#include <Impl/FlateEncode.inl>

	};	// namespace Filters
};	// namespace pdftron

#endif // PDFTRON_H_CPPFiltersFlateEncode
