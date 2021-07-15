
inline Shading::Shading (SDF::Obj shading_dict)
{
	REX(TRN_ShadingCreate(shading_dict.mp_obj,&mp_shade));
}

inline Shading::Shading (const Shading& s)
{
	REX(TRN_ShadingCreate(0,&mp_shade));
	REX(TRN_ShadingAssign(mp_shade,s.mp_shade));
}

inline Shading& Shading::operator=(const Shading& s)
{
	REX(TRN_ShadingAssign(mp_shade,s.mp_shade))
	return *this;
}

inline Shading::~Shading()
{
	DREX(mp_shade, TRN_ShadingDestroy(mp_shade));
}

inline void Shading::Destroy() {
	REX(TRN_ShadingDestroy(mp_shade));
	mp_shade=0;
}

#ifndef SWIG
inline Shading::Type Shading::GetType(SDF::Obj shading_dict)
{
	enum TRN_ShadingType result;
	REX(TRN_ShadingGetTypeFromObj(shading_dict.mp_obj,&result));
	return (Shading::Type)result;
}
#endif

inline Shading::Type Shading::GetType() const
{
	enum TRN_ShadingType result;
	REX(TRN_ShadingGetType(mp_shade,&result));
	return (Shading::Type)result;
}

inline SDF::Obj Shading::GetSDFObj ()
{
	RetObj(TRN_ShadingGetSDFObj(mp_shade,&result));
}

inline ColorSpace Shading::GetBaseColorSpace()
{
	TRN_ColorSpace result;
	REX(TRN_ShadingGetBaseColorSpace(mp_shade,&result));
	return ColorSpace(result);
}

inline bool Shading::HasBBox()
{
	RetBool(TRN_ShadingHasBBox(mp_shade,&result));
}

inline Rect Shading::GetBBox()
{
	RetRec(TRN_ShadingGetBBox(mp_shade,&result));
}

inline bool Shading::HasBackground()
{
	RetBool(TRN_ShadingHasBackground(mp_shade,&result));
}

inline ColorPt Shading::GetBackground()
{
	RetCPT(TRN_ShadingGetBackground(mp_shade,&result));
}

inline bool Shading::GetAntialias()
{
	RetBool(TRN_ShadingGetAntialias(mp_shade,&result));
}

inline double Shading::GetParamStart()
{
	RetDbl(TRN_ShadingGetParamStart(mp_shade,&result));
}

inline double Shading::GetParamEnd()
{
	RetDbl(TRN_ShadingGetParamEnd(mp_shade,&result));
}

inline bool Shading::IsExtendStart()
{
	RetBool(TRN_ShadingIsExtendStart(mp_shade,&result));
}

inline bool Shading::IsExtendEnd()
{
	RetBool(TRN_ShadingIsExtendEnd(mp_shade,&result));
}

inline ColorPt Shading::GetColor(double t)
{
	ColorPt out_color;
	REX(TRN_ShadingGetColor(mp_shade,t,(TRN_ColorPt*)&out_color));
	return out_color;
}

#ifndef SWIG
inline void Shading::GetColor(double t, ColorPt& out_color)
{
	REX(TRN_ShadingGetColor(mp_shade,t,(TRN_ColorPt*)&out_color));
}
#endif

inline std::vector<double> Shading::GetCoordsAxial()
{
	double out_x0; 
	double out_y0; 
	double out_x1; 
	double out_y1;
	std::vector<double> arr(4);
	REX(TRN_ShadingGetCoords(mp_shade,&out_x0,&out_y0,&out_x1,&out_y1));
	arr[0] = out_x0;
	arr[1] = out_y0;
	arr[2] = out_x1;
	arr[3] = out_y1;
	return arr;
}

#ifndef SWIG
inline void Shading::GetCoords(double& out_x0, double& out_y0, double& out_x1, double& out_y1)
{
	REX(TRN_ShadingGetCoords(mp_shade,&out_x0,&out_y0,&out_x1,&out_y1));
}
#endif

inline std::vector<double> Shading::GetCoordsRadial()
{
	double out_x0; 
	double out_y0;
	double out_r0;
	double out_x1; 
	double out_y1;
	double out_r1;
	std::vector<double> arr(6);
	REX(TRN_ShadingGetCoordsRadial(mp_shade,&out_x0,&out_y0,&out_r0,&out_x1,&out_y1,&out_r1));
	arr[0] = out_x0;
	arr[1] = out_y0;
	arr[2] = out_r0;
	arr[3] = out_x1;
	arr[4] = out_y1;
	arr[5] = out_r1;
	return arr;
}

#ifndef SWIG
inline void Shading::GetCoords(double& out_x0, double& out_y0, double& out_r0,	double& out_x1, double& out_y1, double& out_r1)
{
	REX(TRN_ShadingGetCoordsRadial(mp_shade,&out_x0,&out_y0,&out_r0,&out_x1,&out_y1,&out_r1));
}
#endif

inline std::vector<double> Shading::GetDomain()
{
	double out_xmin;
	double out_xmax;
	double out_ymin;
	double out_ymax;
	std::vector<double> arr(4); 
	REX(TRN_ShadingGetDomain(mp_shade,&out_xmin,&out_xmax,&out_ymin,&out_ymax));
	arr[0] = out_xmin;
	arr[1] = out_xmax;
	arr[2] = out_ymin;
	arr[3] = out_ymax;
	return arr;
}

#ifndef SWIG
inline void Shading::GetDomain(double& out_xmin, double& out_xmax, double& out_ymin, double& out_ymax)
{
	REX(TRN_ShadingGetDomain(mp_shade,&out_xmin,&out_xmax,&out_ymin,&out_ymax));
}
#endif

inline Common::Matrix2D Shading::GetMatrix()
{
	RetMtx(TRN_ShadingGetMatrix(mp_shade,&result));
}

inline ColorPt Shading::GetColor(double t1, double t2)
{
	ColorPt out_color;
	REX(TRN_ShadingGetColorForFunction(mp_shade,t1,t2,(TRN_ColorPt*)&out_color));
	return out_color;
}

#ifndef SWIG
inline void Shading::GetColor(double t1, double t2, ColorPt& out_color)
{
	REX(TRN_ShadingGetColorForFunction(mp_shade,t1,t2,(TRN_ColorPt*)&out_color));
}
#endif

inline Shading::Shading(TRN_Shading impl) : mp_shade(impl) {}

