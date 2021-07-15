
inline PatternColor::PatternColor (SDF::Obj pattern)
{
	REX(TRN_PatternColorCreate(pattern.mp_obj,&mp_pc));
}

inline PatternColor::PatternColor(const PatternColor& c)
{
	REX(TRN_PatternColorCreate(0,&mp_pc));
	REX(TRN_PatternColorAssign(mp_pc,c.mp_pc));
}
inline PatternColor& PatternColor::operator=(const PatternColor& c)
{
	REX(TRN_PatternColorAssign(mp_pc,c.mp_pc));
	return *this;
}

inline PatternColor::~PatternColor()
{
	DREX(mp_pc, TRN_PatternColorDestroy(mp_pc));
}

inline void PatternColor::Destroy()
{
	REX(TRN_PatternColorDestroy(mp_pc));
	mp_pc = 0;
}

inline PatternColor::Type GetType(SDF::Obj pattern)
{
	enum TRN_PatternColorType result;
	REX(TRN_PatternColorGetTypeFromObj(pattern.mp_obj,&result));
	return (PatternColor::Type)result;
}

inline PatternColor::Type PatternColor::GetType() const
{
	enum TRN_PatternColorType result;
	REX(TRN_PatternColorGetType(mp_pc,&result));
	return (PatternColor::Type)result;
}

inline SDF::Obj PatternColor::GetSDFObj ()
{
	RetObj(TRN_PatternColorGetSDFObj(mp_pc,&result));
}

inline Common::Matrix2D PatternColor::GetMatrix()
{
	RetMtx(TRN_PatternColorGetMatrix(mp_pc,&result));
}

inline Shading PatternColor::GetShading()
{
	TRN_Shading result;
	REX(TRN_PatternColorGetShading(mp_pc,&result));
	return Shading(result);
}


inline PatternColor::TilingType PatternColor::GetTilingType() const
{
	enum TRN_PatternColorTilingType result;
	REX(TRN_PatternColorGetTilingType(mp_pc,&result));
	return (PatternColor::TilingType)result;
}

inline Rect PatternColor::GetBBox()
{
	RetRec(TRN_PatternColorGetBBox(mp_pc,&result));
}

inline double PatternColor::GetXStep()
{
	RetDbl(TRN_PatternColorGetXStep(mp_pc,&result));
}

inline double PatternColor::GetYStep()
{
	RetDbl(TRN_PatternColorGetYStep(mp_pc,&result));
}

inline PatternColor::PatternColor(TRN_PatternColor impl) : mp_pc(impl)
{
}

inline PatternColor::PatternColor()
{
	REX(TRN_PatternColorCreate(0,&mp_pc));
}

