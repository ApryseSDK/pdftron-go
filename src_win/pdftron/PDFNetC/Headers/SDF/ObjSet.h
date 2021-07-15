//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSDFObjSet
#define PDFTRON_H_CPPSDFObjSet

#include <SDF/Obj.h>
#include <C/SDF/TRN_ObjSet.h>

namespace pdftron { 
	namespace SDF {

/**
 * ObjSet is a lightweight container that can hold a collection of SDF objects.
 */
class ObjSet
{
public:
	ObjSet();
	~ObjSet();

	/**
	 * Create a new name object in this object set.
	 * @param name The name of the object to create
	 */
	Obj CreateName(const char* name);

	/**
	 * Create a new array object in this object set.
	 */
	Obj CreateArray();

	/**
	 * Create a new boolean object in this object set.
	 * @param value The boolean value of the object to create
	 */
	Obj CreateBool(bool value);

	/**
	 * Create a new dictionary object in this object set.
	 */
	Obj CreateDict();

	/**
	 * Create a new null object in this object set.
	 */
	Obj CreateNull();

	/**
	 * Create a new number object in this object set.
	 * @param The numeric value of the number object to create.
	 */
	Obj CreateNumber(double value);

	/**
	 * Create a new string object in this object set.
	 * The unsigned string value of the string object to create.
	 */
	Obj CreateString(const UString& value);

	/** 
	 * parses a json string to create either a Dictionary or an Array in ObjSet.
	 *
	 * return the created object as Obj
	 */
	Obj CreateFromJson(const UString& value);

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();

private:
	TRN_ObjSet mp_set;
};


#include <Impl/ObjSet.inl>
	};	// namespace SDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPSDFObjSet
