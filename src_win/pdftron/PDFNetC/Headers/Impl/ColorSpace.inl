
inline ColorPt::ColorPt(double x,double y,double z,double w) {
	REX(TRN_ColorPtInit(x,y,z,w, &m_c));
}

inline ColorPt::ColorPt(const ColorPt& co) {
	REX(TRN_ColorPtInit(0,0,0,0, &m_c));
	REX(TRN_ColorPtAssign(&m_c, &co.m_c));
}

inline ColorPt::~ColorPt() {
	DREX(m_c.c, TRN_ColorPtDestroy(&m_c));
	m_c.c = 0;
}

inline void ColorPt::Destroy() {
	REX(TRN_ColorPtDestroy(&m_c));
	m_c.c = 0;
}

inline ColorPt& ColorPt::operator =(const ColorPt& co) {
	REX(TRN_ColorPtAssign(&m_c, &co.m_c));
	return *this;
}

inline bool ColorPt::operator== (const ColorPt& co) const {
	RetBool(TRN_ColorPtCompare(&m_c, &co.m_c, &result));
}

inline void ColorPt::Set(double x,double y, double z, double w) {
	REX(TRN_ColorPtSet(&m_c,x,y,z,w));
}

inline void ColorPt::Set(int colorant_index,double colorant_value) {
	REX(TRN_ColorPtSetByIndex(&m_c, colorant_index,colorant_value));
}

inline double ColorPt::Get(int colorant_index) const {
	double result;
	REX(TRN_ColorPtGet(&m_c, colorant_index,&result));
	return result;
}

inline void ColorPt::SetColorantNum(int num) {
	REX(TRN_ColorPtSetColorantNum(&m_c, num));
}


inline ColorSpace ColorSpace::CreateDeviceGray() {
	TRN_ColorSpace result;
	REX(TRN_ColorSpaceCreateDeviceGray(&result));
	return ColorSpace(result);
}

inline ColorSpace ColorSpace::CreateDeviceRGB() {
	TRN_ColorSpace result;
	REX(TRN_ColorSpaceCreateDeviceRGB(&result));
	return ColorSpace(result);
}

inline ColorSpace ColorSpace::CreateDeviceCMYK() {
	TRN_ColorSpace result;
	REX(TRN_ColorSpaceCreateDeviceCMYK(&result));
	return ColorSpace(result);
}

inline ColorSpace ColorSpace::CreatePattern() {
	TRN_ColorSpace result;
	REX(TRN_ColorSpaceCreatePattern(&result));
	return ColorSpace(result);
}


inline ColorSpace ColorSpace::CreateICC(SDF::SDFDoc& doc, const UString& filepath)
{
	TRN_ColorSpace result;
	REX(TRN_ColorSpaceCreateICCFromFile( (doc.mp_doc), (TRN_UString)(&filepath), &result ));
	return ColorSpace(result);
}

inline ColorSpace ColorSpace::CreateICC(SDF::SDFDoc& doc, Filters::Filter stm)
{
	TRN_ColorSpace result;
	stm.m_owner = false;
	REX(TRN_ColorSpaceCreateICCFromFilter( (doc.mp_doc), stm.m_impl, &result ) );
	// Note: SDFDoc takes the ownership of the stream
	stm.m_impl = 0;  
	return ColorSpace(result);
}

inline ColorSpace ColorSpace::CreateICC(SDF::SDFDoc& doc, const UChar* buf, size_t buf_sz)
{
	TRN_ColorSpace result;
	REX(TRN_ColorSpaceCreateICCFromBuffer( (doc.mp_doc), buf, (TRN_UInt32)buf_sz, &result ));
	return ColorSpace(result);
}

inline ColorSpace::ColorSpace (SDF::Obj color_space) {
	REX(TRN_ColorSpaceCreate(color_space.mp_obj,&mp_cs));
}

inline ColorSpace::ColorSpace(const ColorSpace& c) {
	REX(TRN_ColorSpaceCreate(0,&mp_cs));
	REX(TRN_ColorSpaceAssign(mp_cs,c.mp_cs));
}

inline ColorSpace& ColorSpace::operator=(const ColorSpace& c) {
	REX(TRN_ColorSpaceAssign(mp_cs, c.mp_cs));
	return *this;
}

inline ColorSpace::~ColorSpace() {
	DREX(mp_cs, TRN_ColorSpaceDestroy(mp_cs));
}

inline void ColorSpace::Destroy() {
	REX(TRN_ColorSpaceDestroy(mp_cs));
	mp_cs=0;
}

#ifndef SWIG
inline int ColorSpace::GetComponentNum(Type cs_type, SDF::Obj cs) {
	RetInt(TRN_ColorSpaceGetComponentNumFromObj((enum TRN_ColorSpaceType)cs_type,cs.mp_obj,&result));	
}

inline ColorSpace::Type ColorSpace::GetType(SDF::Obj cs) {
	enum TRN_ColorSpaceType result;
	REX(TRN_ColorSpaceGetTypeFromObj(cs.mp_obj,&result));
	return (ColorSpace::Type)result;
}
#endif

inline ColorSpace::Type ColorSpace::GetType() const {
	enum TRN_ColorSpaceType result;
	REX(TRN_ColorSpaceGetType(mp_cs,&result));
	return (ColorSpace::Type)result;
}

inline SDF::Obj ColorSpace::GetSDFObj () {
	RetObj(TRN_ColorSpaceGetSDFObj(mp_cs,&result));
}

inline int ColorSpace::GetComponentNum() {
	RetInt(TRN_ColorSpaceGetComponentNum(mp_cs,&result));
}
inline void ColorSpace::InitColor(ColorPt& out_colorants) {
	REX(TRN_ColorSpaceInitColor(mp_cs, (TRN_ColorPt*)&out_colorants));
}

inline void ColorSpace::InitComponentRanges(std::vector<double>& out_decode_low, std::vector<double>& out_decode_range) {
	int num_comps=GetComponentNum();
	out_decode_low.resize(num_comps);
	out_decode_range.resize(num_comps);
	if (num_comps < 1) return;
	REX(TRN_ColorSpaceInitComponentRanges(mp_cs,&(out_decode_low[0]),&(out_decode_range[0]),num_comps));
}

inline ColorPt ColorSpace::Convert2Gray(const ColorPt& in_color) {
	ColorPt out_color;
	REX(TRN_ColorSpaceConvert2Gray(mp_cs,(TRN_ColorPt*)&in_color,(TRN_ColorPt*)&out_color));
	return out_color;
}

#ifndef SWIG
inline void ColorSpace::Convert2Gray(const ColorPt& in_color, ColorPt& out_color) {
	REX(TRN_ColorSpaceConvert2Gray(mp_cs,(TRN_ColorPt*)&in_color,(TRN_ColorPt*)&out_color));
}
#endif

inline ColorPt ColorSpace::Convert2RGB(const ColorPt& in_color) {
	ColorPt out_color;
	REX(TRN_ColorSpaceConvert2RGB(mp_cs,(TRN_ColorPt*)&in_color,(TRN_ColorPt*)&out_color));
	return out_color;
}

#ifndef SWIG
inline void ColorSpace::Convert2RGB(const ColorPt& in_color, ColorPt& out_color) {
	REX(TRN_ColorSpaceConvert2RGB(mp_cs,(TRN_ColorPt*)&in_color,(TRN_ColorPt*)&out_color));
}
#endif

inline ColorPt ColorSpace::Convert2CMYK(const ColorPt& in_color) {
	ColorPt out_color;
	REX(TRN_ColorSpaceConvert2CMYK(mp_cs,(TRN_ColorPt*)&in_color,(TRN_ColorPt*)&out_color));
	return out_color;
}

#ifndef SWIG
inline void ColorSpace::Convert2CMYK(const ColorPt& in_color, ColorPt& out_color) {
	REX(TRN_ColorSpaceConvert2CMYK(mp_cs,(TRN_ColorPt*)&in_color,(TRN_ColorPt*)&out_color));
}
#endif

inline ColorSpace ColorSpace::GetAlternateColorSpace() {
	TRN_ColorSpace result;
	REX(TRN_ColorSpaceGetAlternateColorSpace(mp_cs,&result));
	return ColorSpace(result);
}

inline ColorSpace ColorSpace::GetBaseColorSpace() {
	TRN_ColorSpace result;
	REX(TRN_ColorSpaceGetBaseColorSpace(mp_cs,&result));
	return ColorSpace(result);
}

inline int ColorSpace::GetHighVal() {
	RetInt(TRN_ColorSpaceGetHighVal(mp_cs,&result));
}

#ifndef SWIG
inline const UChar* ColorSpace::GetLookupTable() {
	const TRN_UChar* result;
	REX(TRN_ColorSpaceGetLookupTable(mp_cs,&result));
	return (const UChar*)result;
}
#endif

inline ColorPt ColorSpace::GetBaseColor(UChar color_idx) {
	ColorPt out_color;
	REX(TRN_ColorSpaceGetBaseColor(mp_cs,color_idx,(TRN_ColorPt*)&out_color));
	return out_color;
}

#ifndef SWIG
inline void ColorSpace::GetBaseColor(UChar color_idx, ColorPt& out_color) {
	REX(TRN_ColorSpaceGetBaseColor(mp_cs,color_idx,(TRN_ColorPt*)&out_color));
}
#endif

inline Function ColorSpace::GetTintFunction()	{
	TRN_Function result;
	REX(TRN_ColorSpaceGetTintFunction(mp_cs,&result));
	return Function(result);
}

inline bool ColorSpace::IsAll() {
	RetBool(TRN_ColorSpaceIsAll(mp_cs,&result));
}

inline bool ColorSpace::IsNone() {
	RetBool(TRN_ColorSpaceIsNone(mp_cs,&result));
}


inline ColorSpace::ColorSpace(TRN_ColorSpace impl) : mp_cs(impl) 
{}

