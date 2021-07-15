//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSDFNumberTree
#define PDFTRON_H_CPPSDFNumberTree

#include <C/SDF/TRN_NumberTree.h>
#include <SDF/DictIterator.h>
#include <SDF/Obj.h>
#include <SDF/SDFDoc.h>

namespace pdftron { 
	namespace SDF {


/** 
 *  NumberTreeIterator is used to traverse key/value pairs in a NumberTree.
 */
typedef DictIterator NumberTreeIterator;


/** 
 * A NumberTree is a common data structure in PDF. See section 3.8.6 'Number Trees' 
 * in PDF Reference Manual for more details.
 * 
 * A number tree serves a similar purpose to a dictionary - associating keys and
 * values - but by different means. NumberTrees allow efficient storage of very 
 * large association collections (number/Obj* maps). A NumberTree can have many 
 * more entries than a SDF/Cos dictionary can.
 * 
 * Sample code:
 * @code
 *   PDFDoc doc("../Data/test.pdf");
 *   NumberTree labels(doc.GetRoot().Get("PageLabels").Value());
 *   if (labels.IsValid()) {
 *     // Traversing the NumberTree 
 *     for (NumberTreeIterator i = labels.GetIterator(); i.HasNext(); i.Next()) 
 *         cout << "Key: " << i.Key().GetNumber() << endl;
 *   }
 * @endcode
 */
class NumberTree
{
public:

	
	/**
	 * Create a high level NumberTree wrapper around an existing SDF/Cos NumberTree. 
	 * This does not copy the object.
	 *
	 * @param number_tree SDF/Cos root of the NumberTree object.
	 */
	 NumberTree (Obj number_tree);

	/**
	 * Copy constructor
	 */
	 NumberTree (const NumberTree& d);

	/**
	 * Assignment operator
	 */
	 NumberTree& operator=(const NumberTree& d);

	/**
	 * @return whether this is a valid (non-null) NumberTree. If the 
	 * function returns false the underlying SDF/Cos object is null and 
	 * the NumberTree object should be treated as null as well.
	 */ 	
	 bool IsValid();

	/**
	 * Search for the specified key in the NumberTree.
	 * 
	 * @return If the key is present the function returns a NumberTreeIterator the points 
	 * to the given Key/Value pair. If the key is not found the function returns End() 
	 * (a non-valid) iterator.
	 * 
	 * @param key the number representing the key to be found.
	 *
	 * Sample code:
	 *   NumberTreeIterator i = dests.Find(5);
	 *   if (i.HasNext()) { 
	 *     cout << "Key: " << i.GetKey()->GetNumber() << endl;
	 *     cout << "Value: " << i.GetValue()->GetType() << endl;
	 *   }
	 *
	 */
	 NumberTreeIterator GetIterator(Int32 key);

	/**
	 * @return an iterator to the first key/value pair (i.e. NNTreeData) in 
	 * the document. You can use the Next method on the returned iterator to 
	 * traverse all entries stored under the NumberTree.
	 * 
	 * Sample code:
	 * 	 for (NumberTreeIterator i = dests.GetIterator(); i.HasNext(); i.Next()) 
	 * 	   cout << "Key: " << i.GetKey().GetNumber() << endl;
	 */
	 NumberTreeIterator GetIterator();

	 Obj GetValue(Int32 key);


	/**
	 * Puts a new entry in the name tree. If an entry with this number
	 * is already in the tree, it is replaced.
	 *
	 * @param key A number representing the key of the new entry.
	 * @param value the value associated with the key. It can be any SDF::Obj.
	 */
	 void Put (Int32 key, Obj value);	

	/**
	 * Removes the specified object from the tree. Does nothing if no object 
	 * with that number exists.
	 *
	 * @param key A number representing the key of the entry to be removed.
	 */
	 void Erase (Int32 key);

	/**
	 * Removes the NumberTree entry pointed by the iterator. 
	 * @param pos dictionary iterator object that points to the NumberTree entry to be removed
	 */
	 void Erase (DictIterator& pos);

	/**
	 * @return the object to the underlying SDF/Cos object. If the NumberTree.IsValid() 
	 * returns false the SDF/Cos object is NULL.
	 */
	 Obj GetSDFObj () const;


protected:

	TRN_NumberTree mp_obj;
};



#include <Impl/NumberTree.inl>

	};	// namespace SDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPSDFNumberTree
