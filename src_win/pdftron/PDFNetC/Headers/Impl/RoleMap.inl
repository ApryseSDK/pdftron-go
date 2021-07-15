
inline RoleMap::RoleMap (SDF::Obj dict)
{
	REX(TRN_RoleMapCreate(dict.mp_obj,&mp_map));
}
	
inline RoleMap::RoleMap (const RoleMap& p)
{
	REX(TRN_RoleMapCopy(p.mp_map,&mp_map));
}

inline RoleMap& RoleMap::operator= (const RoleMap& p)
{
	REX(TRN_RoleMapCopy(p.mp_map,&mp_map));
	return *this;
}

inline bool RoleMap::IsValid() const
{
	TRN_Bool result;
	REX(TRN_RoleMapIsValid(mp_map,&result));
	return TBToB(result);
}

inline const char* RoleMap::GetDirectMap(const char* type) const
{
	const char* result;
	REX(TRN_RoleMapGetDirectMap(mp_map,type,&result));
	return result;
}

inline SDF::Obj RoleMap::GetSDFObj () const
{
	TRN_Obj result;
	REX(TRN_RoleMapGetSDFObj(mp_map,&result));
	return SDF::Obj(result);
}

inline RoleMap::RoleMap(TRN_RoleMap impl) : mp_map(impl)
{
}

