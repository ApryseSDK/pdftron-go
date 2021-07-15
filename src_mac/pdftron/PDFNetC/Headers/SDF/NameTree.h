//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSDFNameTree
#define PDFTRON_H_CPPSDFNameTree

#include <C/SDF/TRN_NameTree.h>
#include <SDF/DictIterator.h>
#include <SDF/Obj.h>
#include <SDF/SDFDoc.h>


namespace pdftron { 
	namespace SDF {


/** 
 *  NameTreeIterator is used to traverse key/value pairs in a NameTree.
 */
typedef DictIterator NameTreeIterator;


/** 
 * A NameTree is a common data structure in PDF. See section 3.8.5 'Name Trees' 
 * in PDF Reference Manual for more details.
 * 
 * A name tree serves a similar purpose to a dictionary - associating keys and
 * values - but by different means. NameTrees allow efficient storage of very 
 * large association collections (string/Obj* maps). A NameTree can have many 
 * more entries than a SDF/Cos dictionary can.
 * 
 * NameTree-s use SDF/Cos-style strings (not null-terminated C strings), which 
 * may use Unicode encoding etc.
 * 
 * @code
 *   PDFDoc doc("../Data/PDFReference.pdf");
 *   NameTree dests = NameTree::Find(*doc.GetSDFDoc(), "Dests");
 *   if (dests.IsValid()) {
 *     // Traversing the NameTree
 *     UString key;
 *     for (DictIterator i = dests.GetIterator(); i.HasNext(); i.Next()) 
 *        i.Key().GetAsPDFText(key); // ...
 *   }
 * @endcode
 */
class NameTree
{
public:

	/**
	 * Retrieves the NameTree inside the '/Root/Names' dictionary with the 
	 * specified key name, or creates it if it does not exist.
	 * 
	 * @param doc - The document in which the name tree is created.
	 * @param name - The name of the NameTree to create.
	 *
	 * @return The newly created NameTree for the doc or an existing tree with
	 * the same key name.
	 *
	 * @note although it is possible to create a name tree anywhere in the document
	 * the convention is that all trees are located under '/Root/Names' dictionary.
	 */
	 static NameTree Create(class SDFDoc& doc, const std::string& name);

	/**
	 * Retrieves a name tree, with the given key name, from the '/Root/Names' 
	 * dictionary of the doc.
	 *
	 * @param doc - The document in which to search for the name.
	 * @param name - The name of the name tree to find.
	 * 
	 * @return The requested NameTree. If the requested NameTree exists 
	 * NameTree.IsValid() will return true, and false otherwise. 
	 */ 
	 static NameTree Find(class SDFDoc& doc, const std::string& name);
	
	/**
	 * Create a high level NameTree wrapper around an existing SDF/Cos NameTree. 
	 * This does not copy the object.
	 *
	 * @param name_tree SDF/Cos root of the NameTree object.
	 */
	 NameTree (Obj name_tree);

	/**
	 * Copy constructor
	 */
	 NameTree (const NameTree& d);

	/**
	 * Assignment operator
	 */
	 NameTree& operator=(const NameTree& d);

	/**
	 * @return whether this is a valid (non-null) NameTree. If the 
	 * function returns false the underlying SDF/Cos object is null and 
	 * the NameTree object should be treated as null as well.
	 */ 	
	 bool IsValid();

	/**
	 * Search for the specified key in the NameTree.
	 * 
	 * @return If the key is present the function returns a NameTreeIterator the points 
	 * to the given Key/Value pair. If the key is not found the function returns End() 
	 * (a non-valid) iterator.
	 * 
	 * @param key data buffer representing the key to be found.
	 * @param key_sz The size (in bytes) of the key.
	 *
	 * @code
	 *   DictIterator i = dests.Find("MyKey", 5);
	 *   if (i.HasNext()) { 
	 *     UString key;
	 *     i.GetKey().GetAsPDFText(key); // ...
	 *     cout << "Value: " << i.GetValue().GetType() << endl;
     *   }
	 * @endcode
	 */
	 NameTreeIterator GetIterator(const UChar* key, int key_sz);

	/**
	 * @return an iterator that addresses the first element in the NameTree.
	 * The iterator can be used to traverse all entries stored in the NameTree.
	 * 
	 * @code
	 *  UString key;   
	 *  for (NameTreeIterator i = dests.GetIterator(); i.HasNext(); i.Next()) {
	 *    i.GetKey().GetAsPDFText(key); // ...
	 *  }
	 * @endcode
	 */
	 NameTreeIterator GetIterator();

	 /**
	  * Search the NameTree for a given key.
	  * 
	  * @param key - a key to search for in the dictionary
  	  * @param key_sz - the buffer size used to store the key.
	  * @return null if the tree does not contain the specified key, otherwise 
	  * return the corresponding value.
	  */
	 Obj GetValue(const UChar* key, int key_sz);

	/**
	 * Puts a new entry in the name tree. If an entry with this key
	 * is already in the tree, it is replaced.
	 *
	 * @param key data buffer representing the key of the new entry.
	 * @param key_sz The size (in bytes) of the key.
	 * @param the value associated with the key. It can be any SDF::Obj.
	 */
	 void Put (const UChar* key, int key_sz, Obj value);	

	/**
	 * Removes the specified object from the tree. Does nothing if no object 
	 * with that name exists.
	 *
	 * @param key data buffer representing the key of the entry to be removed.
	 * @param key_sz The size (in bytes) of the key.
	 */
	 void Erase (const UChar* key, int key_sz);

	/**
	 * Removes the NameTree entry pointed by the iterator.
	 * @param pos ditionary iterator object that points to the NameTree entry to be removed.
	 */
	 void Erase (DictIterator& pos);

	/**
	 * @return the object to the underlying SDF/Cos object. If the NameTree.IsValid() 
	 * returns false the SDF/Cos object is NULL.
	 */
	 Obj GetSDFObj () const;


protected:
	NameTree(){};
	TRN_NameTree mp_obj;
};


#include <Impl/NameTree.inl>

	};	// namespace SDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPSDFNameTree
