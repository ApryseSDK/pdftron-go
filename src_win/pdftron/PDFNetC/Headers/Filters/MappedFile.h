//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPFiltersMappedFile
#define PDFTRON_H_CPPFiltersMappedFile

#include <Common/UString.h>
#include <Filters/Filter.h>
#include <Common/Common.h>
#include <C/Filters/TRN_Filter.h>

namespace pdftron { 
	namespace Filters {

/** 
 * MappedFile is a utility class to read files on a file system. Because MappedFile file is 
 * derived from pdftron.Filters.Filter you can directly chain MappedFile objects to other
 * 'pdftron.Filters'.
 *
 * MappedFile objects support random access to files using the Seek method. Seek 
 * allows the read/write position to be moved to any position within the file. This
 * is done through a shared memory mapped chunk manager. The byte offset is relative 
 * to the seek reference point, which can be the beginning, the current position, 
 * or the end of the underlying file, as represented by the three properties of the 
 * Filter.ReferencePos class.
 *
 * MappedFile objects are thread-safe, meaning separate copies of a MappedFile can Seek
 * to different locations in the file, without conflicting with one another.
 * 
 * Disk files always support random access. At the time of construction, the CanSeek()
 * property value is set to true or false depending on the underlying file type.
 * 
 * @note .NET or Java applications should explicitly Close() files when they are not needed.
 * If the files are not closed or disposed this may lead to the resource exhaustion.
 */ 
class MappedFile : public Filter
{
public:

	/**
	 * Create a new instance of MappedFile class with the specified path
	 */
	MappedFile (const UString& filename);


	/**
	 * Check is the two MappedFile-s refer to the same file on disc. 
	 * @return true if the two files share the same filename, 
	 * false otherwise. 
	 */
	bool operator == (const MappedFile& f) const;

	/**
	 * Check is the two file paths are equivalent (i.e. they refer to the 
	 * same file on disc. 
	 * @return true if the two files share the same filename, false otherwise. 
	 */
	static bool Equivalent( const UString& ph1, const UString& ph2);

	/**
	 * @return the size of the current file.
	 */
	size_t FileSize();


};

#include <Impl/MappedFile.inl>
	
	};	// namespace Filters
};	// namespace pdftron

#endif // PDFTRON_H_CPPFiltersMappedFile
