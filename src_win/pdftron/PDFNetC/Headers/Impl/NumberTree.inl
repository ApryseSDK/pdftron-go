

inline NumberTree::NumberTree (Obj number_tree)
{
	REX(TRN_NumberTreeCreate(number_tree.mp_obj,&mp_obj));
}

inline NumberTree::NumberTree (const NumberTree& d)
{
	REX(TRN_NumberTreeCopy(d.mp_obj,&mp_obj));
}

inline NumberTree& NumberTree::operator=(const NumberTree& d)
{
	REX(TRN_NumberTreeCopy(d.mp_obj,&mp_obj));
	return *this;
}

inline bool NumberTree::IsValid()
{
	TRN_Bool result;
	REX(TRN_NumberTreeIsValid(mp_obj,&result));
	return TBToB(result);
}

inline NumberTreeIterator NumberTree::GetIterator(TRN_Int32 key)
{
	TRN_DictIterator result;
	REX(TRN_NumberTreeGetIterator(mp_obj,key,&(result)));
	return DictIterator(result);
}


inline NumberTreeIterator NumberTree::GetIterator()
{
	TRN_DictIterator result;
	REX(TRN_NumberTreeGetIteratorBegin(mp_obj,&(result)));
	return DictIterator(result);
}

inline Obj NumberTree::GetValue(TRN_Int32 key)
{
	RetObj(TRN_NumberTreeGetValue(mp_obj, key, &result));
}


inline void NumberTree::Put (TRN_Int32 key, Obj value)
{
	REX(TRN_NumberTreePut(mp_obj,key,value.mp_obj));
}

inline void NumberTree::Erase (TRN_Int32 key)
{
	REX(TRN_NumberTreeEraseKey(mp_obj,key));
}

inline void NumberTree::Erase (DictIterator& pos)
{
	REX(TRN_NumberTreeErase(mp_obj,pos.mp_impl));
}

inline Obj NumberTree::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_NumberTreeGetSDFObj(mp_obj,&(result)));
	return Obj(result);
}

