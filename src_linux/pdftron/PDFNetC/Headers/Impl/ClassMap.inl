
inline ClassMap::ClassMap (SDF::Obj dict)
{
	REX(TRN_ClassMapCreate(dict.mp_obj,&mp_map));
}
inline ClassMap::ClassMap (const ClassMap& p)
{
	REX(TRN_ClassMapCopy(p.mp_map,&mp_map));
}

inline ClassMap& ClassMap::operator= (const ClassMap& p)
{
	REX(TRN_ClassMapCopy(p.mp_map,&mp_map));
	return *this;
}

inline bool ClassMap::IsValid() const
{
	TRN_Bool result;
	REX(TRN_ClassMapIsValid(mp_map,&result));
	return TBToB(result);
}

inline SDF::Obj ClassMap::GetSDFObj () const
{
	RetObj(TRN_ClassMapGetSDFObj(mp_map,&result));
}

inline ClassMap::ClassMap(TRN_ClassMap impl) : mp_map(impl)
{
}

