//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef H_FiltersMemoryFilter
#define H_FiltersMemoryFilter

#include <Filters/Filter.h>
#include <Common/Common.h>
#include <C/Filters/TRN_Filter.h>

namespace pdftron { 
	namespace Filters {

/**
 * MemoryFilter is a memory buffer that can be used as a source or a sink Filter in 
 * the Filter pipeline. When a MemoryFilter is the source, other filters can read data
 * stored in memory; When MemoryFilter is a sink, other filters generate data which
 * is then pushed in a memory buffer owned by MemoryFilter (MemoryFilter makes sure
 * that there is enough space to accommodate all data).
 */
class MemoryFilter : public Filter
{
public:

	MemoryFilter(size_t buf_sz, bool is_input);

	/**
	 * @note MemoryFilter specific function.
	 * @return a pointer to the beginning of the buffer. Use method Count() to 
	 * determine the number of bytes written to or read from MemoryFilter.
	 */
	UChar* GetBuffer();

	/**
	 * @note MemoryFilter specific function used to change filter mode from output to input. 
	 * The utility function is useful in cases when and output data buffer should be 
	 * converted to an input stream. 
	 *
	 * @note The function has no effect on an input MemoryFilter.
	 */
	void SetAsInputFilter();

};


#include <Impl/MemoryFilter.inl>

	};	// namespace Filters
};	// namespace pdftron


#endif // H_FiltersMemoryFilter
