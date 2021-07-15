
inline AttrObj::AttrObj (SDF::Obj dict)
{
	REX(TRN_AttrObjCreate(dict.mp_obj,&mp_obj));
}
	
inline AttrObj::AttrObj (const AttrObj& a)
{
	REX(TRN_AttrObjCopy(a.mp_obj,&mp_obj));
}

inline AttrObj& AttrObj::operator= (const AttrObj& a)
{
	REX(TRN_AttrObjCopy(a.mp_obj,&mp_obj));
	return *this;
}

inline const char* AttrObj::GetOwner() const
{
	const char* result;
	REX(TRN_AttrObjGetOwner(mp_obj, &result));
	return result;
}

inline SDF::Obj AttrObj::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_AttrObjGetSDFObj(mp_obj,&result));
	return SDF::Obj(result);
}

