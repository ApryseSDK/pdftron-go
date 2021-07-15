//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPFiltersFilterWriter
#define PDFTRON_H_CPPFiltersFilterWriter

#include <C/Common/TRN_Types.h>
#include <C/Filters/TRN_FilterWriter.h>
#include <Filters/Filter.h>
#include <Filters/FilterReader.h>

namespace pdftron { 
	namespace Filters {


/** 
 * FilterWriter is a utility class providing a convenient way to write data
 * to an output filter (using Filter directly is not very intuitive).
 *  
 * For example:
 * @code
 * StdFile outfile("file.dat", StdFile::e_write_mode);
 * FilterWriter fwriter(outfile);
 * fwriter.WriteBuffer(buf, buf_sz);
 * fwriter.Flush();
 * @endcode
 */
class FilterWriter
{
public:

	 FilterWriter (); 
	 FilterWriter (Filter& filter);
	 ~FilterWriter ();

	/**
	 * Write a single character to the output stream.
	 * @param ch An unsigned character to write to the output stream.
	 */
	 void WriteUChar(UChar ch);

	/**
	 * Write an integer to the output stream.
	 * @param num An integer to write to the output stream.
	 */
	void WriteInt(Int16 num);
	void WriteInt(UInt16 num);
	void WriteInt(Int32 num);
	void WriteInt(UInt32 num);
	void WriteInt(Int64 num);
	void WriteInt(UInt64 num);

	/**
	 * Write a string to the output stream.
	 * @param str A string to write to the output stream. 
	 */
	 void WriteString(const std::string& str);

	/**
	 * Write a null terminated string
	 * @param str A terminated string string to write to the output stream. 
	 */
	 void WriteString(const char* str);

	/**
	 * Write the entire input stream to the output stream (i.e. to this FilterWriter).
	 * @param reader A FilterReader attached to an input stream. 
	 */
	 void WriteFilter(FilterReader& reader);

	/**
	 * Write out a null terminated 'line' followed by a end of line character 
	 * default end of line character is carriage return.
	 * @param line string to write out.
	 * @param eol end of line character. Defaults to carriage return (0x0D).
	 */
	 void WriteLine(const char* line, char eol = 0x0D);

	/**
	 * @param buf buffer object to write out.
	 * @return - returns the number of bytes actually written to a stream. This number may
	 *   less than buf_size if the stream is corrupted. 
	 */
	 size_t WriteBuffer(std::vector<unsigned char> buf);

#ifndef SWIG
	 size_t WriteBuffer(const char* buf, size_t buf_size);
#endif

	/**
	 * Attaches a filter to the this FilterWriter.
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
	TRN_FilterWriter m_impl;
#endif
// @endcond
};



#include <Impl/FilterWriter.inl>

	};	// namespace Filters
};	// namespace pdftron

#endif // PDFTRON_H_CPPFiltersFilterWriter
