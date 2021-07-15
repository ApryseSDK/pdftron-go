//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPCommonIterator
#define PDFTRON_H_CPPCommonIterator

#include <Common/Common.h>
#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Iterator.h>


namespace pdftron {
	namespace Common {

/**
 * Supports a simple iteration over a generic collection.
 */
template <class T>
class Iterator
{
public:
	inline Iterator() : mp_impl(0) {}
	inline ~Iterator() {
		DREX(mp_impl, TRN_IteratorDestroy(mp_impl));
	}

	/**
	 * Frees the native memory of the object.
	 */
	inline void Destroy()
	{
		REX(TRN_IteratorDestroy(mp_impl));
		mp_impl = 0;
	}

	/**
	 * Note: HasNext() must be true before calling Next()
	 * Advances the iterator to the next element of the collection.
	 */
	inline void Next() {
		BASE_ASSERT(mp_impl, "Null Iterator");
		REX(TRN_IteratorNext(mp_impl));
	}

	/** 
	 * Note: HasNext() must be true before calling Current()
	 * @return the current element in the collection
	 */
	inline T& Current() {
		BASE_ASSERT(mp_impl, "Null Iterator");
		TRN_ItrData result;	
		REX(TRN_IteratorCurrent(mp_impl,&result));
		return *((T*)result);
	}

	/** 
	 * @return true if the iterator can be successfully advanced to the 
	 * next element; false if the iterator is no longer valid. 
	 */
	inline bool HasNext() {
		BASE_ASSERT(mp_impl, "Null Iterator");
		TRN_Bool result;
		REX(TRN_IteratorHasNext(mp_impl,&result));
		return TBToB(result);
	}
	
	/**
	 * Copy constructor.
	 */
	inline Iterator(const Iterator& c) : mp_impl(0) {
		REX(TRN_IteratorAssign(c.mp_impl,&mp_impl));
	}

	/**
	 * Assignment operator.
	 */
	inline Iterator<T>& operator=(const Iterator<T>& other) {
		REX(TRN_IteratorAssign(other.mp_impl,&mp_impl));
		return *this;
	}

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	inline Iterator(TRN_Iterator impl) : mp_impl(impl) {}
	TRN_Iterator mp_impl;
#endif
// @endcond
};

/**
 * The Iterator specialization for integer type.
 */
template <>
class Iterator<int>
{
public:
	inline Iterator() : mp_impl(0)
	{}
	inline Iterator(TRN_Iterator impl) : mp_impl(impl)
	{
	}
	inline ~Iterator()
	{
		DREX(mp_impl, TRN_IteratorDestroy(mp_impl));
	}

	/**
	 * Frees the native memory of the object.
	 */
	inline void Destroy()
	{
		REX(TRN_IteratorDestroy(mp_impl));
		mp_impl = 0;
	}

	inline void Next()
	{
		BASE_ASSERT(mp_impl, "Null Iterator");
		REX(TRN_IteratorNext(mp_impl));
	}

	inline int Current()
	{
		BASE_ASSERT(mp_impl, "Null Iterator");
		TRN_ItrData result;
		REX(TRN_IteratorCurrent(mp_impl,&result));
		return *((int*)result);
	}

	inline bool HasNext()
	{
		BASE_ASSERT(mp_impl, "Null Iterator");
		TRN_Bool result;
		REX(TRN_IteratorHasNext(mp_impl,&result));
		return TBToB(result);
	}
	
	inline Iterator<int>& operator=(const Iterator<int>& other)
	{
		BASE_ASSERT(other.mp_impl, "Null Iterator");
		REX(TRN_IteratorAssign(other.mp_impl,&mp_impl));
		return *this;
	}

	inline Iterator(const Iterator<int>& c) 
	  : mp_impl(0)
	{
		BASE_ASSERT(c.mp_impl, "Null Iterator");
		REX(TRN_IteratorAssign(c.mp_impl,&mp_impl));
	}

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_Iterator mp_impl;
#endif
// @endcond
};


	};	// namespace Common
};	// namespace pdftron

#endif // PDFTRON_H_CPPCommonIterator
