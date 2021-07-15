//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPFiltersFilter
#define PDFTRON_H_CPPFiltersFilter

#include <Common/UString.h>
#include <C/Filters/TRN_Filter.h>
#include <C/Common/TRN_Types.h>
#include <stdio.h>

namespace pdftron { 
	namespace Filters {

/**
 * Provides a generic view of a sequence of bytes. 
 * 
 * A Filter is the abstract base class of all filters. A filter is an abstraction of 
 * a sequence of bytes, such as a file, an input/output device, an inter-process communication 
 * pipe, or a TCP/IP socket. The Filter class and its derived classes provide a generic view 
 * of these different types of input and output, isolating the programmer from the specific 
 * details of the operating system and the underlying devices.
 * 
 * Besides providing access to input/output sources Filters can be also to transform the data
 * (e.g. to compress the data stream, to normalize the image data, to encrypt data, etc).
 * Filters can also be attached to each other to form pipelines. For example, a filter used to 
 * open an image data file can be attached to a filter that decompresses the data, which is 
 * attached to another filter that will normalize the image data.
 * 
 * Depending on the underlying data source or repository, filters might support only some of 
 * these capabilities. An application can query a stream for its capabilities by using the 
 * IsInputFilter() and CanSeek() properties.
 * 
 * @note To read or write data to a filter, a user will typically use FilterReader/FilterWriter class.
 * instead of using Filter methods
 *
 * For example:
 * @code
 * StdFile file("my_stream.txt", StdFile::e_read_mode);
 * FilterReader reader(file);
 * while (reader.Read(..)) ...
 * @endcode
 */
class Filter
{
public:
	 Filter();
	 ~Filter ();

	 Filter(const Filter& copy);
	
	 Filter& operator=(const Filter& other);

	 /** 
	  * @return true if the object is not null, false otherwise.  
	  */ 
	 operator bool () { return m_impl!=0;}

	/**
	 * Attaches a filter to the this filter. If this filter owns another 
	 * filter it will be deleted. This filter then becomes the owner of the 
	 * attached filter.
	 * @param attach_filter filter object to attach
	 */
	 void AttachFilter(Filter attach_filter);

	/**
	 * Release the ownership of the attached filter. After the attached filter is 
	 * released this filter points to NULL filter. 
	 *
	 * @return - Previously attached filter.
	 */
	 Filter ReleaseAttachedFilter ();	

	 /**
	 * @return - returns attached Filter or a NULL filter if no filter is attached.
	 */
	 Filter GetAttachedFilter ();

	/**
	 * @return - returns the first filter in the chain (usually a file filter)
	 */
	 Filter GetSourceFilter ();

	/**
	 * @return - descriptive name of the filter. 
	 */
	 const char* GetName () const;

	/**
	 * @return - string representing the name of corresponding decode filter as 
	 * it should appear in document (e.g. both ASCIIHexDecode and ASCIIHexEncode 
	 * should return ASCIIHexDecode). 
	 */
	 const char* GetDecodeName () const;

#ifndef SWIG
	/**
	 * @return - beginning of the buffer of Size() bytes that can be used to 
	 * read or write data. 
	 */
	 UChar* Begin ();
#endif

	/**
	 * @return - the size of buffer returned by Begin(). If the Size() returns 0 
	 * end of data has been reached.
	 */
	 size_t Size ();

	/**
	 * Moves the Begin() pointer num_bytes forward. 
	 *
	 * @param num_bytes - number of bytes to consume. num_bytes must be less than or
	 * equal to Size().
	 */
	 void Consume (size_t num_bytes);

	/**
	 * @return - the number of bytes consumed since opening the filter or 
	 *   the last Seek operation
	 */
	 size_t Count ();

	/**
	 * Sets a new counting point for the current filter. All subsequent Consume()
	 * operations will increment this counter. 
	 *
	 * Make sure that the output filter is flushed before using SetCount().
	 * @param new_count number to set the counting point of the filter to.
	 * 
	 * @return - the value of previous counter
	 */
	 size_t SetCount (size_t new_count);

	/**
	 * The functions specifies the length of the data stream. The default
	 * implementation doesn't do anything. For some derived filters such 
	 * as file segment filter it may be useful to override this function 
	 * in order to limit the stream length. 
	 *
	 * @param bytes the length of stream in bytes
	 */
	 void SetStreamLength (size_t bytes); 

	/**
	 * Forces any data remaining in the buffer to be written to input or 
	 * output filter.
	 */
	 void Flush ();

	/**
	 * Forces any data remaining in the filter chain to the source or destination.
	 */
	 void FlushAll ();

	/**
	 * @return - boolean indicating whether this is an input filter.
	 */
	 bool IsInputFilter ();

	/**
	 * @return - true if the stream supports seeking; otherwise, false.  
	 * default is to return false.
	 */
	 bool CanSeek ();

	/**
	 * Provides the fields that represent reference points in streams for seeking.
	 */
	enum ReferencePos 
	{ 
		e_begin = SEEK_SET,
		e_end   = SEEK_END, 
		e_cur   = SEEK_CUR
	};

	/**
	 * When overridden in a derived class, sets the position within the current stream.
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
	 * @note - After each Seek() operation the number of consumed bytes (i.e. 
	 * Count()) is set to 0.
	 *
	 * @exception - throws FilterExc if the method is not implemented in derived class
	 */
	 void Seek (ptrdiff_t offset, ReferencePos origin);

	/**
	 * Reports the current read position in the stream relative to the stream origin. 
	 *
	 * @return - The current position in the stream
	 * @exception - throws FilterExc if the method is not implemented in derived class
	 */
	 ptrdiff_t Tell ();

	/**
	 * Create Filter iterator. Filter iterator similar to a regular filter. However,
	 * there can be only one owner of the attached filter.
	 * 
	 * @note - Derived classes should make sure that there is only one owner of the
	 *   attached stream. Otherwise the attached stream may be deleted several times.
	 *
	 * @exception - throws an exception if the method is not implemented in the derived class
	 */
	 Filter CreateInputIterator ();

	/**
	 * @return the file path to the underlying file stream. 
	 * Default implementation returns empty string.
	 */
	 const UString GetFilePath() const;

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

	 /**
	 *	Writes the entire filter, starting at current position, to
	 *	specified filepath.  Should only be called on an input filter.
	 *
	 *	@param path the output filepath.
	 *	@param append 'true' to append to existing file contents, 'false' to overwrite.
	 */
	 void WriteToFile(const UString& path, bool append);
// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_Filter m_impl;
	Filter(TRN_Filter impl, bool is_owner);
	bool m_owner;
#endif
// @endcond
};


#include <Impl/Filter.inl>


	};	// namespace Filters
};	// namespace pdftron

#endif // PDFTRON_H_CPPFiltersFilter
