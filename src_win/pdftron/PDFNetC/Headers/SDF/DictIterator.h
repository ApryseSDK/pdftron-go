//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSDFDictIterator
#define PDFTRON_H_CPPSDFDictIterator

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Iterator.h>

namespace pdftron { 
	namespace SDF {


class Obj;

/**
 * DictIterator is used to traverse key/value pairs in a dictionary.
 * For example a DictIterator can be used to print out all the entries
 * in a given Obj dictionary as follows: 
 * @code
 *  DictIterator itr = dict.GetDictIterator();
 *  while (itr.HasNext()) {
 *      Obj key = itr.Key();
 *	    cout << key.GetName() << endl;
 *      Obj value = itr.Value();
 *      // ...
 *      itr.Next()
 *   }
 * @endcode
 */
class DictIterator
{
public:

	/** 
	 * Advances the iterator to the next element of the collection. 
	 */
	 void Next();
	
	/** 
	 * @return the key of the current dictionary entry. 
	 */
	 SDF::Obj Key();

	/** 
	 * @return the value of the current dictionary entry. 
	 */
	 SDF::Obj Value();

	/** 
	 * @return true if the iterator can be successfully advanced to the 
	 * next element; false if the end collection is reached. 
	 */
	 bool HasNext();

	/**
	 * Copy constructor.
	 */
	 DictIterator(const DictIterator& c);
	 DictIterator& operator=(const DictIterator& other);
	 ~DictIterator();

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	DictIterator(TRN_DictIterator impl);
	TRN_DictIterator mp_impl;
#endif
// @endcond
};

	};
};

#include <Impl/SDFDoc.inl>

#endif // PDFTRON_H_CPPSDFDictIterator
