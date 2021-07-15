//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPageSet
#define PDFTRON_H_CPPPDFPageSet

#include <C/PDF/TRN_PageSet.h>
#include <PDF/PDFDoc.h>
#include <Common/Common.h>

namespace pdftron{
	namespace PDF{

/**
 * PageSet is a container of page numbers ordered following a linear sequence. 
 * The page numbers are integers and must be greater than zero. Duplicates are allowed.
 *
 * (NOTE: This is not a mathematical set)
 */
class PageSet
{

public:
	
	enum Filter
	{
		e_all,
		e_even,
		e_odd
	};

	/**
	 * Default constructor. Constructs 'PageSet' with no pages
	 */
	PageSet( );

	/**
	 * Construct a set of pages with just one number
	 *
	 * @see AddPage
	 */
	PageSet( int one_page );  

	/**
	 * Construct a range of pages
	 *
	 * @see AddRange
	 */
	PageSet( int range_start, int range_end, Filter filter = e_all);

	
	/**
	 * Destructor
	 */
	~PageSet();


	/**
	 * Add a value to the sequence.
	 *
	 * @param one_page The page number being added
	 */
	void AddPage( int one_page );

	/**
	 * Add a range of values to the sequence. Reverse ordering is legal.
	 *
	 * @param range_start The starting value in the range
	 * @param range_end The ending value in the range
	 * @param filter 
	 *		-e_all: Default, includes all pages in the range
	 *		-e_odd: Includes odd numbers in the range (discards even numbers)
	 *		-e_even: Includes even numbers in the range (discards odd numbers)
	 */
	void AddRange( int range_start, int range_end, Filter filter = e_all );

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

	// @cond PRIVATE_DOC

	#ifndef SWIGHIDDEN
	PageSet(TRN_PageSet impl);
	TRN_PageSet mp_impl;
	#endif
	// @endcond

	private : 
		PageSet(Filter filter);
};

#include <Impl/PageSet.inl>

	}
}

#endif // PDFTRON_H_CPPPDFPageSet
