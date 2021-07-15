//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.	 
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFCharData
#define PDFTRON_H_CPPPDFCharData

#include <Common/Iterator.h> 

namespace pdftron { 
	namespace PDF {

/**
 * <p>CharIterator is an iterator type that can be used to traverse CharData 
 * in the current e_text element. For a sample use case, please take a look 
 * at ElementReaderAdv sample project.</p>
 * 
 * <p>CharData is a data structure returned by CharIterator that is 
 * used to provide extra information about a character within 
 * a text run. The extra information includes positioning information, 
 * the character data and a number of bytes taken by the character.</p>
 * 
 * <p>char_code := for SimpleFonts char_code := char_data[0], for composite fonts 
 * char_code is the numeric value of data stored in char_data buffer.</p>
 * 
 * <p>(x, y) is a virtual point (x, y), located on the baseline. This point is 
 * called the pen position, and is used to position glyphs.
 * The pen position has already taken into account the effects of any 
 * inter-character adjustments due to properties such as font size, text rise, 
 * character spacing, word spacing and positioning adjustments on 'TJ' elements.</p>
 * 
 * <p>char_data is a  pointer to the buffer containing character data. 
 * For simple fonts each character is represented by a single byte. 
 * For multibyte (CID or Type0) fonts each character may take more than 
 * one byte.</p>
 * 
 * <p>bytes - the number of bytes representing this character in char_data 
 * buffer.  For simple fonts 'bytes' will equal 1. For multibyte (CID or Type0) 
 * fonts 'bytes may be larger than 1.</p>
 */
typedef Common::Iterator<TRN_CharData> CharIterator;

	};	// namespace PDF
};	// namespace pdftron

#endif  // PDFTRON_H_CPPPDFCharData
