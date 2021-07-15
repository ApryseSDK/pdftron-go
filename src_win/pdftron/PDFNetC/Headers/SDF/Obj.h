//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSDFSDFObj
#define PDFTRON_H_CPPSDFSDFObj

#include <Common/Exception.h>
#include <Common/UString.h>
#include <Common/Matrix2D.h>
#include <Filters/FilterWriter.h>
#include <Filters/Filter.h>


namespace pdftron { 
	namespace SDF {

class DictIterator;

/**
 * Obj is a concrete class for all SDF/Cos objects. Obj hierarchy implements the 
 * composite design pattern. As a result, you can invoke a member function of any 
 * 'derived' object through Obj interface. If the member function is not supported 
 * (e.g. if you invoke Obj::GetNumber() on a boolean object) an Exception will be 
 * thrown.
 * 
 * You can use GetType() or obl.Is???() member functions to find out type-information at 
 * run time, however most of the time the type can be inferred from the PDF specification.
 * Therefore when you call Doc::GetTrailer() you can assume that returned object is 
 * a dictionary. If there is any ambiguity use Is???() methods. 
 * 
 * Objects can't be shared across documents, however you can use Doc::ImportObj() 
 * to copy objects from one document to another. 
 * 
 * Objects can be shared within a document provided that they are created as indirect.
 * Indirect objects are the ones that are referenced in cross-reference table.
 * To create an object as indirect use doc.CreateIndirect???() (where ? is the 
 * Object type).
 */
class Obj 
{
public:

	// Common methods for all objects -----------------------------------------------

	/**
	 * The object type.
	 */
	enum Type 
	{
		e_null,
		e_bool,
		e_number,
		e_name,
		e_string,
		e_dict, 
		e_array,
		e_stream
	};

	/**
	 * @return the object type. 
	 * @note this method can be invoked on any Obj.
	 */
	 Type GetType () const;

	/**
	 * @return true if this is a Bool object, false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsBool () const;

	/**
	 * @return true if this is a Number object, false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsNumber () const;

	/**
	 * @return true if this is a Null object, false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsNull () const;

	/**
	 * @return true if this is a Str (String) object, false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsString () const;

	/**
	 * @return true if this is Name, false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsName () const;

	/**
	 * @return true if this is Indirect object (i.e. object referenced in the 
	 * cross-reference table), false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsIndirect () const;

	/**
	 * @return true if this is a Container (a dictionary, array, or a stream),
	 * false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsContainer () const;

	/**
	 * @return true if this is a dictionary (i.e. Dict), false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsDict () const;

	/**
	 * @return true if this is an Array, false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsArray () const;

	/**
	 * @return true if this is a Stream, false otherwise.
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsStream () const;

	/** 
	 * @return the document to which this object belongs.
	 * @note this method can be invoked on any Obj.
	 */ 
	 class SDFDoc& GetDoc () const;

	/**
	 * The function writes the Obj to the output stream
	 * @param stream - the input stream where the Obj will be written
	 * @note this method can be invoked on any Obj.
	 */
	 void Write(Filters::FilterWriter& stream);

	/**
	 * @return the 'size' of the object. The definition of 'size' depends on 
	 * the object type. In particular:
	 *  - For a dictionary or a stream object, the method will return the 
	 *    number of key/value pairs in the dictionary. 
	 *  - For an array object the method will return the number of Obj 
	 *    entries in the array. 
	 *  - For a string object the method will return the number of bytes 
	 *    in the string buffer. 
	 *  - For any other object the method will always return 1. 
	 *
	 * @note this method can be invoked on any Obj.
	 */
	 size_t Size () const;

	// Indirect Methods -------------------------------------------------------------

	/**
	 * @return object number. If this is not an Indirect object, object number of 
	 * a containing indirect object is returned.
	 * @note this method can be invoked on any Obj.
	 */
	 UInt32 GetObjNum () const;

	/**
	 * @return generation number. If this is not an Indirect object, generation number of 
	 * a containing indirect object is returned.
	 * @note this method can be invoked on any Obj.
	 */ 
	 UInt16 GetGenNum () const;

	/**
	 * @return object offset from the beginning of the file. If this is not an Indirect object,
	 * offset of a containing indirect object is returned.
	 * @note this method can be invoked on any Obj.
	 */
	 size_t GetOffset () const;

	/**
	 * @return true if the object is in use or is marked as free. 
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsFree () const;

	/**
	 * Set the object mark. Mark is a boolean value that can be associated with every 
	 * indirect object. This is especially useful when an object graph should be 
	 * traversed and an operation should be performed on each node only once. 
	 * @param mark boolean value that the object's mark should be set to.
	 * @note this method can be invoked on any Obj.
	 */
	 void SetMark (bool mark);

	/**
	 * @return true if the object is marked. 
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsMarked () const;

	/**
	 * @return true if the object is loaded in memory. 
	 * @note this method can be invoked on any Obj.
	 */
	 bool IsLoaded () const;

    /**
     * @return true if this is a valid object, false otherwise. If the function returns
     * false then the underlying SDF/Cos object is null or is not valid.
     */
     bool IsValid () const;

	// Boolean Specific Methods ----------------------------------------------------

	/**
	 * @return bool value if this is Bool.
	 * @exception Exception is thrown if the object is not Obj::Type::e_bool
	 */
	 bool GetBool () const;

	/**
	 * @param b - bool value used to set Bool object.
	 * @exception An Exception is thrown if this is not a Obj::Type::e_bool
	 */
	 void SetBool (bool b);

	// Number Specific Methods -----------------------------------------------------

	/**
	 * @return value, if this is Number.
	 * @exception An Exception is thrown if the object is not a Obj::Type::e_number
	 */
	 double GetNumber () const;

	/**
	 * @param n - value used to set Number object.
	 * @exception An Exception is thrown if this is not a Obj::Type::e_number
	 */
	 void SetNumber (double n);


	// String Specific Methods -----------------------------------------------------

	/**
	 * @return a pointer to the string buffer. Please note that the string may not 
	 * be NULL terminated and that it may not be represented in ASCII or Unicode 
	 * encoding. For more information on SDF/Cos String objects, please refer to 
	 * section 3.2.3 'String Objects' in PDF Reference Manual.
	 * 
	 * @note if SDF/Cos String object is represented as 'PDF Text' (Section 3.8.1 
	 * 'Text Strings' in PDF Reference) you can use GetAsPDFText method to obtain 
	 * Unicode representation of the string.
	 * 
	 * @note use Size() member function in order to obtain the number of bytes in string buffer.
	 * 
	 * @exception Exception is thrown if this is not a Obj::Type::e_string.
	 */
#ifdef SWIG
	 std::vector<unsigned char> GetBuffer () const;
#else
	 const UChar* GetBuffer () const;
#endif

	 /**
	 * @return a vector containing the encrypted string buffer.
	 *
	 * @note Similar in behaviour to GetBuffer except that no decryption is done.
	 * If the file is not encrypted the result should be the same as GetBuffer
	 *
	 * @exception Exception is thrown if this is not a Obj::Type::e_string.
	 */
	 std::vector<unsigned char> GetRawBuffer() const;

	/**
	 * Convert the SDF/Cos String object to 'PDF Text String' (a Unicode string).
	 *
	 * PDF Text Strings are not used to represent page content, however they
	 * are used in text annotations, bookmark names, article names, document 
	 * information etc. These strings are encoded in either PDFDocEncoding or 
	 * Unicode character encoding. For more information on PDF Text Strings, 
	 * please refer to section 3.8.1 'Text Strings' in PDF Reference.
	 * 
	 * @note Not all SDF/Cos String objects are used to represent 'PDF Text'. 
	 * PDF Reference indicates (on a case by case basis ) where an SDF/Cos String 
	 * object can be used as 'PDF Text'.
	 *
	 * @exception An Exception is thrown if this is not a Obj::Type::e_string.
	 */
	 UString GetAsPDFText() const;

#ifndef SWIG
	 void GetAsPDFText(UString& out_str) const;
#endif

	/**
	 * Sets the string object value. 
	 *
	 * @param value - character buffer.
	 * @param size - the size of character buffer.
	 * @exception An Exception is thrown if this is not a Obj::Type::e_string
	 */
	 void SetString(const UChar* value, size_t size);

	/**
	 * Sets the string object value. 
	 * @param str - A Unicode string value.
	 * @exception An Exception is thrown if this is not a Obj::Type::e_string
	 */
	 void SetString(const UString& str);

	// Name Specific Methods -------------------------------------------------------

	/**
	 * @return string representing the Name object.
	 * @exception An Exception is thrown if this is not a Obj::Type::e_name
	 */
	 const char* GetName () const;

	/**
	 * @param name - value used to set Name object.
	 * @exception An Exception is thrown if this is not a Obj::Type::e_name
	 */
	 void SetName (const char* name); 


	// Dictionary Specific Methods -------------------------------------------------

	/** 
	 * @return an iterator that addresses the first element in the dictionary.
	 * @exception An Exception is thrown if this is not a dictionary object (Dict).
	 * 
	 * Sample code used to traverse all entries in the dictionary:
	 * @code
	 *  DictIterator itr = dict.GetDictIterator();
	 *  while (itr.HasNext()) {
	 *      Obj key = itr.Key();
	 *      Obj value = itr.Value();
	 *      // ...
	 *      itr.Next()
	 *   }
	 * @endcode
	 */ 
	 DictIterator GetDictIterator ();

	/**
	 * Search the dictionary for a given key.
	 * 
	 * @param key - a key to search for in the dictionary
	 *
	 * @return The iterator to the matching key/value pair or invalid iterator 
	 * (i.e. itr.HasNext()==fase) if the if the dictionary does not contain the given key. 
 	 *
	 * @note A dictionary entry whose value is Obj::Null is equivalent to an absent entry.
	 * @exception Exception is thrown if this is not a dictionary or a stream 
	 *
	 * Sample code used to search a dictionary for a given key:
	 * @code
	 *  DictIterator itr = info_dict.Find("Info");	
	 *  if (itr.HasNext()) {
	 *    Obj info = itr.Value();
	 *    if (info.IsDict())
	 *      info.PutString("Producer", "PDFTron PDFNet SDK");
	 * }
	 * @endcode
 	 */
	 DictIterator Find (const char* key);

	/**
	 * Search the dictionary for a given key. 
	 * 
	 * @param key - a key to search for in the dictionary
	 * @return NULL if the dictionary does not contain the specified key. 
	 * Otherwise return the corresponding value.
	 * @note A dictionary entry whose value is Obj::Null is equivalent to an absent entry.
	 * @exception Exception is thrown if this is not a dictionary or a stream 
 	 */
	 Obj FindObj (const char* key);

	/**
	 * Search the dictionary for a given key and throw an exception if the key is not found.
	 * 
	 * @param key - a key to search for in the dictionary
	 * @return Obj::Null object if the value matching specified key is a Obj::Null object.
	 * otherwise return the iterator to the matching key/value pair.
	 * @exception An Exception is thrown if the dictionary does not contain the specified key. 
	 * @exception An Exception is thrown if this is not a Obj::Type::e_dict or a stream.
	 */
	 DictIterator Get (const char* key);

	/**
	 * Inserts a <key, Obj::Type::e_name> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @param name The value of the Obj::Type::e_name object to be inserted into 
	 * the dictionary.
	 * 
	 * @return A newly created name object.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutName (const char* key, const char* name);

	/**
	 * Inserts a <key, Obj::Type::e_array> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @return A newly created array object.
	 * 
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * 
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutArray (const char* key);

	/**
	 * Inserts a <key, Obj::Type::e_bool> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @param value The value of the Obj::Type::e_bool object to be inserted into 
	 * the dictionary.
	 * 
	 * @return A newly created boolean object.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutBool (const char* key, bool value);

	/**
	 * Inserts a <key, Obj::Type::e_dict> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * 
	 * @return A newly created dictionary.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutDict (const char* key);

	/**
	 * Inserts a <key, Obj::Type::e_number> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @param value The value of the Obj::Type::e_number object to be inserted into 
	 * the dictionary.
	 * 
	 * @return A newly created number object.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutNumber (const char* key, double value);

	/**
	 * Inserts a <key, Obj::Type::e_string> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @param value The value of the Obj::Type::e_string object to be inserted into 
	 * the dictionary.
	 * 
	 * @return A newly created string object.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutString (const char* key, const char* value);

	/**
	 * Inserts a <key, Obj::Type::e_string> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @param value The buffer used to set the value of the Obj::Type::e_string 
	 * object to be inserted into the dictionary.
	 * @param size The number of bytes to copy from the 'value' buffer parameter.
	 * 
	 * @return A newly created string object.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutString (const char* key, const char* value, int size);

	/**
	 * Inserts a <key, Obj::Type::e_string> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @param value The value of the Obj::Type::e_string object to be inserted into 
	 * the dictionary.
	 * @note PutText will create the string object as a 'PDF Text' object.
	 * 
	 * @return A newly created string object.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutText(const char* key, const UString& value);

	/**
	 * Inserts a <key, Obj::Type::e_null> pair in the dictionary.
	 * @param key The key of the value to set.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note The effect of calling this method is essentially the same as dict.Erase(key) . 
 	 */
	 void PutNull (const char* key);

	/**
	 * Inserts a <key, Obj> pair in the dictionary.
	 * @param key The key of the value to set.
	 * @param obj The value to be inserted into the dictionary. If 'obj' is 
	 * indirect (i.e. is a shared) object it will be inserted by reference,
	 * otherwise the object will be cloned and then inserted into the dictionary.
	 * @return A newly inserted object.
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
 	 */
	 Obj Put(const char* key, Obj obj);

	/**
	 * Inserts a <key, [x1,y1,x2,y2]> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @param x1 The bottom left x value of the rect to be inserted
	 * @param y1 The bottom left y value of the rect to be inserted
	 * @param x2 The top right x value of the rect to be inserted
	 * @param y2 The top right y value of the rect to be inserted
	 * @return A newly created array object.
	 * 
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutRect (const char* key, double x1, double y1, double x2, double y2);

	/**
	 * Inserts a <key, [a,b,c,d,h,v]> pair in the dictionary.
	 * 
	 * @param key The key of the value to set.
	 * @param value - A matrix used to set the values in an array of six numbers.
	 * The resulting array will be inserted into the dictionary.
	 * @return A newly created array object.
	 * 
	 * @exception An Exception is thrown if this is not a dictionary or a stream object.
	 * @note If a dictionary already contains an entry with the same key, the old entry 
	 * will be deleted and all DictIterators to this entry will be invalidated. 
 	 */
	 Obj PutMatrix(const char* key, const Common::Matrix2D& value);

	/**
	 * Removes an element in the dictionary that matches the given key.
	 * @param key A string representing the key value of the element to remove.
	 * @exception An Exception is thrown if this is not a dictionary or a stream.
	 */
	 void Erase (const char* key);

	/**
	 * Removes an element in the dictionary from specified position.
	 * @param pos A dictionary iterator indicating the position of the element to remove.
	 * @exception An Exception is thrown if this is not a dictionary or a stream.
	 */
	 void Erase (DictIterator pos);
	
	/**
	 * Change the key value of a dictionary entry.
	 * The key can't be renamed if another key with the same name already exists 
	 * in the dictionary. In this case Rename returns false. 
	 * @param old_key A string representing the key value to be changed.
	 * @param new_key A string representing the key value that the old key is changed into.
	 * @exception An Exception is thrown if this is not a dictionary or a stream.
	 */
	 bool Rename (const char* old_key, const char* new_key);


	// Array Specific Methods ------------------------------------------------------

	/** 
	 * @param index - The array element to obtain. The first element in an array has an index of zero.
	 * 
	 * @exception throws an Exception if index is outside the array bounds.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array.
	 */ 
	 Obj GetAt (size_t index) const;

	/** 
	 * Inserts an Obj::Type::e_name object in the array.
	 * @return A newly created name object.
	 *
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * @param name The value of the Obj::Type::e_name object to be inserted.
	 *
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertName (size_t pos, const char* name);

	/** 
	 * Inserts an Obj::Type::e_array object in the array.
	 * @return A newly created array object.
	 *
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 *
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertArray (size_t pos);

	/** 
	 * Inserts an Obj::Type::e_bool object in the array.
	 * @return A newly created boolean object.
	 *
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * @param value The value of the Obj::Type::e_bool object to be inserted.
	 *
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertBool (size_t pos, bool value);

	/** 
	 * Inserts an Obj::Type::e_dict object in the array.
	 * @return A newly created dictionary object.
	 *
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 *
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertDict (size_t pos);

	/** 
	 * Inserts an Obj::Type::e_number object in the array.
	 * @return A newly created number object.
	 *
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * @param value The value of the Obj::Type::e_number object to be inserted.
	 *
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertNumber (size_t pos, double value);

	/** 
	 * Inserts an Obj::Type::e_string object in the array.
	 * @return A newly created string object.
	 *
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * @param value The value of the Obj::Type::e_string object to be inserted.
	 *
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertString (size_t pos, const char* value);

	/** 
	 * Inserts an Obj::Type::e_string object in the array.
	 * @return A newly created string object.
	 *
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * @param value The buffer used to set the value of the Obj::Type::e_string 
	 * object to be inserted.
	 * @param size The number of bytes to copy from the 'value' buffer parameter.
	 *
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertString (size_t pos, const char* value, int size);

	/** 
	 * Inserts an Obj::Type::e_string object in the array.
	 * @return A newly created string object.
	 *
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * @param value The value of the Obj::Type::e_string object to be inserted.
	 *
	 * @note InsertText will create the string object as a 'PDF Text' object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertText(size_t pos, const UString& value);

	/** 
	 * Inserts an Obj::Type::e_null object in the array.
	 * @return A newly created null object.
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj InsertNull(size_t pos);

	/**
	 * Inserts an existing Obj in this array.
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * @param obj The value to be inserted into the dictionary. If 'obj' is 
	 * indirect (i.e. is a shared) object it will be inserted by reference,
	 * otherwise the object will be cloned and then inserted.
	 * @return A newly inserted object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
 	 */
	 Obj Insert(size_t pos, Obj obj);

	/**
	 * Inserts an array of 4 numbers in this array.
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * 
	 * @param x1 The bottom left x value of the rect to be inserted
	 * @param y1 The bottom left y value of the rect to be inserted
	 * @param x2 The top right x value of the rect to be inserted
	 * @param y2 The top right y value of the rect to be inserted
	 * @return A newly created array object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
 	 */
	 Obj InsertRect (size_t pos, double x1, double y1, double x2, double y2);

	/**
	 * Inserts an array of 6 numbers in this array.
	 * @param pos - The location in the array to insert the object . The object is inserted 
	 *          before the specified location. The first element in an array has a pos of 
	 *	        zero. If pos >= Array->Length(), appends obj to array.
	 * 
	 * @param value - A matrix used to set the values in an array of six numbers.
	 * The resulting array will be then inserted in this array.
	 * @return A newly created array object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
 	 */
	 Obj InsertMatrix(size_t pos, const Common::Matrix2D& value);

	/**
	 * Appends a new Obj::Type::e_name object at the end of the array.
	 * @return The new array object.
	 * @param name - The value of the Obj::Type::e_name object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackName (const char* name);

	/**
	 * Appends a new Obj::Type::e_array object at the end of the array.
	 * @return The new array object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackArray ();

	/**
	 * Appends a new Obj::Type::e_bool object at the end of the array.
	 * @return The new boolean object.
	 * @param name - The value of the Obj::Type::e_bool object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackBool (bool value);

	/**
	 * Appends a new Obj::Type::e_dict object at the end of the array.
	 * @return The new dictionary object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackDict ();

	/**
	 * Appends a new Obj::Type::e_number object at the end of the array.
	 * @return The new number object.
	 * @param value - The value of the Obj::Type::e_number object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackNumber (double value);

	/**
	 * Appends a new Obj::Type::e_string object at the end of the array.
	 * @return The new string object.
	 * @param value - The value of the Obj::Type::e_string object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackString (const char* value);

	/**
	 * Appends a new Obj::Type::e_string object at the end of the array.
	 * @return The new string object.
	 * @param value The buffer used to set the value of the Obj::Type::e_string 
	 * object to be inserted.
	 * @param size The number of bytes to copy from the 'value' buffer parameter.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackString (const char* value, int size);

	/**
	 * Appends a new Obj::Type::e_string object at the end of the array.
	 * @return The new string object.
	 * @param value The value of the Obj::Type::e_string object to be inserted.
	 * @note InsertText will create the string object as a 'PDF Text' object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackText (const UString& value);

	/**
	 * Appends a new Obj::Type::e_null object at the end of the array.
	 * @return The new null object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackNull ();

	/**
	 * Appends an existing Obj at the end of the array.
	 * @param obj The value to be inserted into the dictionary. If 'obj' is 
	 * indirect (i.e. is a shared) object it will be inserted by reference,
	 * otherwise the object will be cloned and then appended.
	 * @return A newly appended object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBack(Obj obj);

	/**
	 * Appends an array of 4 numbers at the end of the array.
	 * @param x1 The bottom left x value of the rect to be inserted
	 * @param y1 The bottom left y value of the rect to be inserted
	 * @param x2 The top right x value of the rect to be inserted
	 * @param y2 The top right y value of the rect to be inserted
	 * @return A newly appended array object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackRect (double x1, double y1, double x2, double y2);

	/**
	 * Appends an array of 6 numbers at the end of the array.
	 * @param value - A matrix used to set the values in an array of six numbers.
	 * The resulting array will be then inserted in this array.
	 * @return A newly appended array object.
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 Obj PushBackMatrix(const Common::Matrix2D& value);
	
	/**
	 * Checks whether the position is within the array bounds and then removes it from the 
	 * array and moves each subsequent element to the slot with the next smaller index and 
	 * decrements the arrays length by 1.
	 *
	 * @param pos The index for the array member to remove. Array indexes start at 0.
	 * 
	 * @exception An Exception is thrown if this is not an Obj::Type::e_array
	 */
	 void EraseAt (size_t pos);


	// Stream Specific Methods -----------------------------------------------------

	/**
	 * @return the length of the raw/encoded stream equal to the Length parameter
	 * @exception An Exception is thrown if this is not a Obj::Type::e_stream
	 */
	 size_t GetRawStreamLength () const;

	/**
	 * @param decrypt - If true decrypt the stream if the stream is encrypted.
	 * @return - A filter to the encoded stream
	 * @exception An Exception is thrown if this is not a Obj::Type::e_stream
	 */
	 Filters::Filter GetRawStream (bool decrypt) const;

	/**
	 * @return - A filter to the decoded stream
	 * @exception An Exception is thrown if this is not a Obj::Type::e_stream
	 */
	 Filters::Filter GetDecodedStream () const;
	
	 /**
	  * allows to replace the content stream with a new one
	  * without creating a new object
	  */
	 void SetStreamData( 
		 const char* data, 
		 const size_t data_size, 
		 Filters::Filter filter_chain = Filters::Filter() );

	// Support methods ----------------------------------------------------------------

	 Obj() : mp_obj(0) {}
	 Obj(const Obj& c) : mp_obj(c.mp_obj) {}
	 Obj& operator=(const Obj& c) {mp_obj=c.mp_obj; return *this;}

	 /** 
	  * @return true if the object is not null, false otherwise.  
	  */ 
	 operator bool () { return mp_obj!=0;}
	
	/**
	 * @return true if two Obj's point to the same object.
	 * This method does not compare object content. For this operation use 
	 * IsEqualValue() instead. 
	 * @param to - Obj to compare to
	 */
	 bool IsEqual(const Obj& to) const;
	 bool operator ==(const Obj& to) const;
	 bool operator <(const Obj& to) const { return mp_obj < to.mp_obj; }
    
    //for xamarin use only
    static Obj* CreateInternal(ptrdiff_t impl);
    ptrdiff_t GetHandleInternal();

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	 Obj(TRN_Obj impl);
	TRN_Obj mp_obj;
private:
	mutable TRN_SDFDoc temp_doc;
	#endif
	// @endcond
};



	};	// namespace SDF
};	// namespace pdftron



#include <Impl/SDFDoc.inl>

#endif // PDFTRON_H_CPPSDFSDFObj
