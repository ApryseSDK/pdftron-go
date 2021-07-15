
inline NameTree NameTree::Create(class SDFDoc& doc, const std::string& name)
{
	NameTree result;
	REX(TRN_NameTreeCreate(doc.mp_doc,name.c_str(),&(result.mp_obj)));
	return result;
}


inline NameTree NameTree::Find(class SDFDoc& doc, const std::string& name)
{
	NameTree result;
	REX(TRN_NameTreeFind(doc.mp_doc,name.c_str(),&(result.mp_obj)));
	return result;
}

inline NameTree::NameTree (Obj name_tree)
{
	REX(TRN_NameTreeCreateFromObj(name_tree.mp_obj,&(mp_obj)));
}


inline NameTree::NameTree (const NameTree& d)
{
	REX(TRN_NameTreeCopy(d.mp_obj,&(mp_obj)));
}

inline NameTree& NameTree::operator=(const NameTree& d)
{
	REX(TRN_NameTreeCopy(d.mp_obj,&(mp_obj)));
	return *this;
}

inline bool NameTree::IsValid()
{
	TRN_Bool result;
	REX(TRN_NameTreeIsValid(mp_obj,&result));
	return TBToB(result);
}

inline NameTreeIterator NameTree::GetIterator(const UChar* key, int key_sz)
{
	TRN_DictIterator result;
	TRN_String keyString = { (const char*)key, (unsigned int)key_sz };
	REX(TRN_NameTreeGetIterator(mp_obj, keyString, &(result)));
	return DictIterator(result);
}

inline Obj NameTree::GetValue(const UChar* key, int key_sz)
{
	TRN_String keyString = { (const char*)key, (unsigned int)key_sz };
	RetObj(TRN_NameTreeGetValue(mp_obj, keyString, &(result)));
}


inline NameTreeIterator NameTree::GetIterator()
{
	TRN_DictIterator result;
	REX(TRN_NameTreeGetIteratorBegin(mp_obj,&(result)));
	return DictIterator(result);
}


inline void NameTree::Put (const UChar* key, int key_sz, Obj value)
{
	TRN_String keyString = { (const char*)key, (unsigned int)key_sz };
	REX(TRN_NameTreePut(mp_obj, keyString, value.mp_obj));
}

inline void NameTree::Erase (const UChar* key, int key_sz)
{
	TRN_String keyString = { (const char*)key, (unsigned int)key_sz };
	REX(TRN_NameTreeEraseKey(mp_obj, keyString));
}

inline void NameTree::Erase (DictIterator& pos)
{
	REX(TRN_NameTreeErase(mp_obj,pos.mp_impl));
}

inline Obj NameTree::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_NameTreeGetSDFObj(mp_obj,&(result)));
	return Obj(result);
}

