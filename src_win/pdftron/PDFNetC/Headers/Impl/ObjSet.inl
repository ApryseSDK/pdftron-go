
inline ObjSet::ObjSet()
{
	TRN_ObjSetCreate(&mp_set);
}

inline ObjSet::~ObjSet()
{
	DREX(mp_set, TRN_ObjSetDestroy(mp_set));
}

inline void ObjSet::Destroy()
{
	TRN_ObjSetDestroy(mp_set);
	mp_set = 0;
}

inline Obj ObjSet::CreateName(const char* name)
{
	RetObj(TRN_ObjSetCreateName(mp_set,name,&result));
}

inline Obj ObjSet::CreateArray()
{
	RetObj(TRN_ObjSetCreateArray(mp_set,&result));
}

inline Obj ObjSet::CreateBool(bool value)
{
	RetObj(TRN_ObjSetCreateBool(mp_set,BToTB(value),&result));
}

inline Obj ObjSet::CreateDict()
{
	RetObj(TRN_ObjSetCreateDict(mp_set,&result));
}

inline Obj ObjSet::CreateNull()
{
	RetObj(TRN_ObjSetCreateNull(mp_set,&result));
}

inline Obj ObjSet::CreateNumber(double value)
{
	RetObj(TRN_ObjSetCreateNumber(mp_set,value,&result));
}

inline Obj ObjSet::CreateString(const UString& value) 
{
	RetObj(TRN_ObjSetCreateString(mp_set,value.mp_impl,&result));
}

inline Obj ObjSet::CreateFromJson(const UString& value) 
{
	RetObj(TRN_ObjSetCreateFromJson(mp_set,value.mp_impl,&result));
}


