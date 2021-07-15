//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CSDFSDFObj
#define PDFTRON_H_CSDFSDFObj

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

enum TRN_ObjType 
{
	e_Obj_null,
	e_Obj_bool,
	e_Obj_number,
	e_Obj_name,
	e_Obj_string,
	e_Obj_dict, 
	e_Obj_array,
	e_Obj_stream
};

TRN_API TRN_ObjGetType (const TRN_Obj o, enum TRN_ObjType* result);
TRN_API TRN_ObjGetDoc (const TRN_Obj o, TRN_SDFDoc* result);
TRN_API TRN_ObjWrite(TRN_Obj o, TRN_FilterWriter stream);
TRN_API TRN_ObjIsEqual(TRN_Obj o, TRN_Obj to, TRN_Bool* result);
TRN_API TRN_ObjIsBool (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjGetBool (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjSetBool (TRN_Obj o, TRN_Bool b);
TRN_API TRN_ObjIsNumber (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjGetNumber (const TRN_Obj o, double* result);
TRN_API TRN_ObjSetNumber (TRN_Obj o, double n);
TRN_API TRN_ObjIsNull (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjIsString (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjGetRawBuffer(const TRN_Obj o, TRN_Vector* result);
TRN_API TRN_ObjGetBuffer (const TRN_Obj o, const TRN_UChar** result);
TRN_API TRN_ObjGetAsPDFText(const TRN_Obj o, TRN_UString* result);
TRN_API TRN_ObjSetString(TRN_Obj o, TRN_String value);
TRN_API TRN_ObjSetUString(TRN_Obj o, const TRN_UString value);
TRN_API TRN_ObjIsName (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjGetName (const TRN_Obj o, const char** result);
TRN_API TRN_ObjSetName (TRN_Obj o, const char* name); 
TRN_API TRN_ObjIsIndirect (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjGetObjNum (const TRN_Obj o, TRN_UInt32* result);
TRN_API TRN_ObjGetGenNum (const TRN_Obj o, TRN_UInt16* result);
TRN_API TRN_ObjGetOffset (const TRN_Obj o, TRN_Size* result);
TRN_API TRN_ObjIsFree (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjSetMark (TRN_Obj o, TRN_Bool mark);
TRN_API TRN_ObjIsMarked (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjIsLoaded (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjIsContainer (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjSize (const TRN_Obj o, TRN_Size* result);
TRN_API TRN_ObjGetDictIterator (TRN_Obj o, TRN_DictIterator* result);
TRN_API TRN_ObjIsDict (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjFind (TRN_Obj o, const char* key, TRN_DictIterator* result);
TRN_API TRN_ObjFindObj (TRN_Obj o, const char* key, TRN_Obj* result);
TRN_API TRN_ObjGet (TRN_Obj o, const char* key, TRN_DictIterator* result);
TRN_API TRN_ObjPutName (TRN_Obj o, const char* key, const char* name, TRN_Obj* result);
TRN_API TRN_ObjPutArray (TRN_Obj o, const char* key, TRN_Obj* result);
TRN_API TRN_ObjPutBool (TRN_Obj o, const char* key, TRN_Bool value, TRN_Obj* result);
TRN_API TRN_ObjPutDict (TRN_Obj o, const char* key, TRN_Obj* result);
TRN_API TRN_ObjPutNumber (TRN_Obj o, const char* key, double value, TRN_Obj* result);
TRN_API TRN_ObjPutString (TRN_Obj o, const char* key, const char* value, TRN_Obj* result);
TRN_API TRN_ObjPutStringWithSize (TRN_Obj o, const char* key, const char* value, int size, TRN_Obj* result);
TRN_API TRN_ObjPutText(TRN_Obj o, const char* key, const TRN_UString t, TRN_Obj* result); 
TRN_API TRN_ObjPutNull (TRN_Obj o, const char* key);
TRN_API TRN_ObjPut(TRN_Obj o, const char* key, TRN_Obj input_obj, TRN_Obj* result);
TRN_API TRN_ObjPutRect(TRN_Obj o, const char* key, double x1, double y1, double x2, double y2, TRN_Obj* result);
TRN_API TRN_ObjPutMatrix(TRN_Obj o, const char* key, const TRN_Matrix2D* mtx, TRN_Obj* result);
TRN_API TRN_ObjEraseFromKey (TRN_Obj o, const char* key);
TRN_API TRN_ObjErase (TRN_Obj o, TRN_DictIterator pos);
TRN_API TRN_ObjRename (TRN_Obj o, const char* old_key, const char* new_key, TRN_Bool* result);
TRN_API TRN_ObjIsArray (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjGetAt (const TRN_Obj o, TRN_Size index, TRN_Obj* result);
TRN_API TRN_ObjInsertName (TRN_Obj o, TRN_Size pos, const char* name, TRN_Obj* result);
TRN_API TRN_ObjInsertArray (TRN_Obj o, TRN_Size pos, TRN_Obj* result);
TRN_API TRN_ObjInsertBool (TRN_Obj o, TRN_Size pos, TRN_Bool value, TRN_Obj* result);
TRN_API TRN_ObjInsertDict (TRN_Obj o, TRN_Size pos, TRN_Obj* result);
TRN_API TRN_ObjInsertNumber (TRN_Obj o, TRN_Size pos, double value, TRN_Obj* result);
TRN_API TRN_ObjInsertString (TRN_Obj o, TRN_Size pos, const char* value, TRN_Obj* result);
TRN_API TRN_ObjInsertStringWithSize(TRN_Obj o, TRN_Size pos, const char* value, int size, TRN_Obj* result);
TRN_API TRN_ObjInsertText (TRN_Obj o, TRN_Size pos, const TRN_UString t, TRN_Obj* result);
TRN_API TRN_ObjInsertNull(TRN_Obj o, TRN_Size pos, TRN_Obj* result);
TRN_API TRN_ObjInsert(TRN_Obj o, TRN_Size pos, TRN_Obj input_obj, TRN_Obj* result);
TRN_API TRN_ObjInsertRect(TRN_Obj o, TRN_Size pos, double x1, double y1, double x2, double y2, TRN_Obj* result);
TRN_API TRN_ObjInsertMatrix(TRN_Obj o, TRN_Size pos, const TRN_Matrix2D* mtx, TRN_Obj* result);
TRN_API TRN_ObjPushBackName (TRN_Obj o, const char* name, TRN_Obj* result);
TRN_API TRN_ObjPushBackArray (TRN_Obj o, TRN_Obj* result);
TRN_API TRN_ObjPushBackBool (TRN_Obj o, TRN_Bool value, TRN_Obj* result);
TRN_API TRN_ObjPushBackDict (TRN_Obj o, TRN_Obj* result);
TRN_API TRN_ObjPushBackNumber (TRN_Obj o, double value, TRN_Obj* result);
TRN_API TRN_ObjPushBackString (TRN_Obj o, const char* value, TRN_Obj* result);
TRN_API TRN_ObjPushBackStringWithSize (TRN_Obj o, const char* value, int size, TRN_Obj* result);
TRN_API TRN_ObjPushBackText (TRN_Obj o, const TRN_UString t, TRN_Obj* result);
TRN_API TRN_ObjPushBackNull (TRN_Obj o, TRN_Obj* result);
TRN_API TRN_ObjPushBack(TRN_Obj o, TRN_Obj input_obj, TRN_Obj* result);
TRN_API TRN_ObjPushBackRect(TRN_Obj o, double x1, double y1, double x2, double y2, TRN_Obj* result);
TRN_API TRN_ObjPushBackMatrix(TRN_Obj o, const TRN_Matrix2D* mtx, TRN_Obj* result);
TRN_API TRN_ObjEraseAt (TRN_Obj o, TRN_Size pos);
TRN_API TRN_ObjIsStream (const TRN_Obj o, TRN_Bool* result);
TRN_API TRN_ObjGetRawStreamLength (const TRN_Obj o, TRN_Size* result);
TRN_API TRN_ObjSetStreamData( TRN_Obj obj, const char* data, const size_t data_size );
TRN_API TRN_ObjSetStreamDataWithFilter(TRN_Obj obj, const char* data, const size_t data_size, TRN_Filter no_own_filter_chain);
TRN_API TRN_ObjGetRawStream (const TRN_Obj o, TRN_Bool decrypt, TRN_Filter* no_own_result);
TRN_API TRN_ObjGetDecodedStream (const TRN_Obj o, TRN_Filter* no_own_result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CSDFSDFObj
