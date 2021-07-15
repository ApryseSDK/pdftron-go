//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------


#ifndef PDFTRON_H_CPPCommonByteRange
#define PDFTRON_H_CPPCommonByteRange
#include <C/Common/TRN_ByteRange.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace Common { 


/**
 * This class represents a Byte Range.
 */
class ByteRange : public TRN_ByteRange
{
public:
	
	/**
	 * Retrieves the start offset of the byte range.
	 * 
	 * @return an unsigned integer.
	 */
	UInt64 GetStartOffset() const;
	
	/**
	 * Retrieves the end offset of the byte range.
	 * 
	 * @return an unsigned integer.
	 */
	UInt64 GetEndOffset() const;
	
	/**
	 * Retrieves the size of the byte range.
	 * 
	 * @return an unsigned integer.
	 */
	UInt64 GetSize() const;

};

#include <Impl/ByteRange.inl>
} //end pdftron
} //end Common


#endif //PDFTRON_H_CPPCommonByteRange
