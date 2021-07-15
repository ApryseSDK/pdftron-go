//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPFiltersFilterReader
#define PDFTRON_H_CPPFiltersFilterReader

#include <C/Filters/TRN_FilterReader.h>
#include <Common/Common.h>
#include <Filters/Filter.h>

#include <vector>

namespace pdftron { 
	namespace Filters {
		

/** 
 * FilterReader is a utility class providing a convenient way to read data
 * from an input filter (using Filter directly is not very intuitive).
 *  
 * For example:
 * @code
 * StdFile file("my_stream.txt", StdFile::e_read_mode);
 * FilterReader reader(file);
 * while (reader.Read(...)) ...
 * @endcode
 */
class FilterReader
{
public:

	 FilterReader ();
	 FilterReader (Filter& filter);
	 ~FilterReader ();

	/**
	 * @return - the next character from the stream or EOF (-1) if the end of file is reached.
	 */
	 int Get();

	/**
	 * @return - the next character without extracting it from the stream or
	 *			 or EOF (-1) if the end of file is reached.
	 */
	 int Peek();

	/**
	 * @return - returns the number of bytes actually read and stored in buffer (buf), 
	 *   which may be less than buf_size if the end of the stream is encountered before 
	 *   reaching count. 
	 */
	 std::vector<unsigned char> Read(size_t buf_size);

#ifndef SWIG
	 size_t Read(UChar* buf, size_t buf_size);
#endif

	/**
	 * Attaches a filter to the this FilterReader. 
	 * @param filter filter object to attach
	 */
	 void AttachFilter(Filter& filter);

	/**
	 * @return - The attached Filter or a NULL filter if no filter is attached.
	 */
	 Filter GetAttachedFilter();

	/**
	 * Sets the position within the current stream.
	 * 
	 * @param offset - A byte offset relative to origin. If offset is negative, 
	 *  the new position will precede the position specified by origin by the number 
	 *  of bytes specified by offset. If offset is zero, the new position will be the 
	 *  position specified by origin. If offset is positive, the new position will follow 
	 *  the position specified by origin by the number of bytes specified by offset. 
	 *
	 * @param origin - A value of type ReferencePos indicating the reference point used 
	 * to obtain the new position
	 *
	 * @note - After each Seek() operation the number of consumed bytes (i.e. Count()) is set to 0.
	 * @exception - throws an exception if the method is not implemented in the associated filter.
	 */
	 void Seek(ptrdiff_t offset, Filter::ReferencePos origin);

	/**
	 * Reports the current read position in the stream relative to the stream origin. 
	 *
	 * @return - The current position in the stream
	 * @exception - throws an exception if the method is not implemented in the associated filter.
	 */
	 ptrdiff_t Tell ();

	/**
	 * @return - the number of bytes consumed since opening the filter or 
	 * since the last Seek operation.
	 */
	 size_t Count ();

	/**
	 * Forces any data remaining in the buffer to be written to input or output filter.
	 */
	 void Flush ();

	/**
	 * Forces any data remaining in the filter chain to the source or destination.
	 */
	 void FlushAll ();

//private:
// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_FilterReader m_impl;
#endif
// @endcond
};


#include <Impl/FilterReader.inl>

	};	// namespace Filters
};	// namespace pdftron


#endif // PDFTRON_H_CPPFiltersFilterReader
