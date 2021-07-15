

inline GState::GState() : mp_state(0)
{
}

inline GState::GState(const GState& c)
{
	mp_state=c.mp_state;
}

inline GState& GState::operator=(const GState& c)
{
	mp_state=c.mp_state;
	return *this;
}

inline Common::Matrix2D GState::GetTransform()
{
	RetMtx(TRN_GStateGetTransform(mp_state,&result));
}

inline ColorSpace GState::GetStrokeColorSpace()
{
	TRN_ColorSpace result;
	REX(TRN_GStateGetStrokeColorSpace(mp_state,&result));
	return ColorSpace(result);
}

inline ColorSpace GState::GetFillColorSpace()
{
	TRN_ColorSpace result;
	REX(TRN_GStateGetFillColorSpace(mp_state,&result));
	return result;
}

inline ColorPt GState::GetStrokeColor()
{
	RetCPT(TRN_GStateGetStrokeColor(mp_state,&result));
}

inline PatternColor GState::GetStrokePattern()
{
	RetPC(TRN_GStateGetStrokePattern(mp_state,&result));
}

inline ColorPt GState::GetFillColor()
{
	RetCPT(TRN_GStateGetFillColor(mp_state,&result));
}

inline PatternColor GState::GetFillPattern()
{
	RetPC(TRN_GStateGetFillPattern(mp_state,&result));
}

inline double GState::GetFlatness() const
{
	RetDbl(TRN_GStateGetFlatness(mp_state,&result));
}

inline GState::LineCap GState::GetLineCap() const
{
	enum TRN_GStateLineCap result;
	REX(TRN_GStateGetLineCap(mp_state,&result));
	return (GState::LineCap)result;
}

inline GState::LineJoin GState::GetLineJoin() const
{
	enum TRN_GStateLineJoin result;
	REX(TRN_GStateGetLineJoin(mp_state,&result));
	return (GState::LineJoin)result;
}

inline double GState::GetLineWidth() const
{
	RetDbl(TRN_GStateGetLineWidth(mp_state, &result));
}

inline double GState::GetMiterLimit() const
{
	RetDbl(TRN_GStateGetMiterLimit(mp_state, &result));
}

inline std::vector<double> GState::GetDashes() const
{
	int dashes_sz;
	std::vector<double> dashes;
	REX(TRN_GStateGetDashes(mp_state,0,&dashes_sz));
	dashes.resize(dashes_sz);
	if (dashes_sz < 1) {
		return dashes;
	}
	REX(TRN_GStateGetDashes(mp_state,&(dashes[0]),&dashes_sz));
	return dashes;
}

#ifndef SWIG
inline void GState::GetDashes(std::vector<double>& dashes) const
{
	int dashes_sz;
	REX(TRN_GStateGetDashes(mp_state,0,&dashes_sz));
	dashes.resize(dashes_sz);
	if (dashes_sz < 1) return;
	REX(TRN_GStateGetDashes(mp_state,&(dashes[0]),&dashes_sz));
}
#endif

inline double GState::GetPhase() const
{
	RetDbl(TRN_GStateGetPhase(mp_state,&result));
}

inline double GState::GetCharSpacing() const
{
	RetDbl(TRN_GStateGetCharSpacing(mp_state, &result));
}

inline double GState::GetWordSpacing() const
{
	RetDbl(TRN_GStateGetWordSpacing(mp_state, &result));
}

inline double GState::GetHorizontalScale() const
{
	RetDbl(TRN_GStateGetHorizontalScale(mp_state, &result));
}

inline double GState::GetLeading() const
{
	RetDbl(TRN_GStateGetLeading(mp_state, &result));
}

inline Font GState::GetFont() const
{
	TRN_Font result;
	REX(TRN_GStateGetFont(mp_state, &result));
	return Font(result);
}

inline double GState::GetFontSize() const
{
	RetDbl(TRN_GStateGetFontSize(mp_state, &result));
}

inline GState::TextRenderingMode GState::GetTextRenderMode() const
{
	enum TRN_GStateTextRenderingMode result;
	REX(TRN_GStateGetTextRenderMode(mp_state,&result));
	return (TextRenderingMode)result;
}

inline double GState::GetTextRise() const
{
	RetDbl(TRN_GStateGetTextRise(mp_state,&result));
}

inline bool GState::IsTextKnockout() const
{
	RetBool(TRN_GStateIsTextKnockout(mp_state,&result));
}

inline GState::RenderingIntent GState::GetRenderingIntent() const
{
	enum TRN_GStateRenderingIntent result;
	REX(TRN_GStateGetRenderingIntent(mp_state,&result));
	return (GState::RenderingIntent)result;
}

inline GState::RenderingIntent GState::GetRenderingIntentType(const char* name)
{
	enum TRN_GStateRenderingIntent result;
	REX(TRN_GStateGetRenderingIntentType(name,&result));
	return (GState::RenderingIntent)result;
}

inline GState::BlendMode GState::GetBlendMode()
{
	enum TRN_GStateBlendMode result;
	REX(TRN_GStateGetBlendMode(mp_state,&result));
	return (BlendMode)result;
}

inline double GState::GetFillOpacity() const
{
	RetDbl(TRN_GStateGetFillOpacity(mp_state,&result));
}

inline double GState::GetStrokeOpacity() const
{
	RetDbl(TRN_GStateGetStrokeOpacity(mp_state,&result));
}

inline bool GState::GetAISFlag() const
{
	RetBool(TRN_GStateGetAISFlag(mp_state,&result));
}

inline SDF::Obj GState::GetSoftMask()
{
	RetObj(TRN_GStateGetSoftMask(mp_state,&result));
}

inline Common::Matrix2D GState::GetSoftMaskTransform()
{
	RetMtx(TRN_GStateGetSoftMaskTransform(mp_state,&result));
}

inline bool GState::GetStrokeOverprint() const
{
	RetBool(TRN_GStateGetStrokeOverprint(mp_state,&result));
}

inline bool GState::GetFillOverprint() const
{
	RetBool(TRN_GStateGetFillOverprint(mp_state,&result));
}

inline int GState::GetOverprintMode() const
{
	RetInt(TRN_GStateGetOverprintMode(mp_state,&result));
}

inline bool GState::GetAutoStrokeAdjust() const
{
	RetBool(TRN_GStateGetAutoStrokeAdjust(mp_state,&result));
}

inline double GState::GetSmoothnessTolerance() const
{
	RetDbl(TRN_GStateGetSmoothnessTolerance(mp_state,&result));
}

inline SDF::Obj GState::GetTransferFunct()
{
	RetObj(TRN_GStateGetTransferFunct(mp_state,&result));
}

inline SDF::Obj GState::GetBlackGenFunct()
{
	RetObj(TRN_GStateGetBlackGenFunct(mp_state,&result));
}

inline SDF::Obj GState::GetUCRFunct()
{
	RetObj(TRN_GStateGetUCRFunct(mp_state,&result));
}

inline SDF::Obj GState::GetHalftone()
{
	RetObj(TRN_GStateGetHalftone(mp_state,&result));
}

inline void GState::SetTransform(const Common::Matrix2D& mtx)
{
	REX(TRN_GStateSetTransformMatrix(mp_state,(const TRN_Matrix2D*)&mtx));
}

inline void GState::SetTransform(double a, double b, double c, double d, double h, double v)
{
	REX(TRN_GStateSetTransform(mp_state,a,b,c,d,h,v));
}

inline void GState::Concat(const Common::Matrix2D& mtx)
{
	REX(TRN_GStateConcatMatrix(mp_state,(const TRN_Matrix2D*)&mtx));
}

inline void GState::Concat(double a, double b, double c, double d, double h, double v)
{
	REX(TRN_GStateConcat(mp_state,a,b,c,d,h,v));
}

inline void GState::SetStrokeColorSpace(ColorSpace cs)
{
	REX(TRN_GStateSetStrokeColorSpace(mp_state,cs.mp_cs));
}

inline void GState::SetFillColorSpace(ColorSpace cs)
{
	REX(TRN_GStateSetFillColorSpace(mp_state,cs.mp_cs));
}

inline void GState::SetStrokeColor(const ColorPt& c)
{
	REX(TRN_GStateSetStrokeColorWithColorPt(mp_state,(TRN_ColorPt*)&c));
}

inline void GState::SetStrokeColor(PatternColor pattern)
{
	REX(TRN_GStateSetStrokeColorWithPattern(mp_state,pattern.mp_pc));
}

inline void GState::SetStrokeColor(PatternColor pattern, const ColorPt& c)
{
	REX(TRN_GStateSetStrokeColor(mp_state,pattern.mp_pc,(TRN_ColorPt*)&c));
}

inline void GState::SetFillColor(const ColorPt& c)
{
	REX(TRN_GStateSetFillColorWithColorPt(mp_state,(TRN_ColorPt*)&c));
}

inline void GState::SetFillColor(PatternColor pattern)
{
	REX(TRN_GStateSetFillColorWithPattern(mp_state,pattern.mp_pc));
}

inline void GState::SetFillColor(PatternColor pattern, const ColorPt& c)
{
	REX(TRN_GStateSetFillColor(mp_state, pattern.mp_pc,(const TRN_ColorPt*)&c));
}

inline void GState::SetFlatness(double flatness)
{
	REX(TRN_GStateSetFlatness(mp_state, flatness));
}

inline void GState::SetLineCap(LineCap cap)
{
	REX(TRN_GStateSetLineCap(mp_state, (enum TRN_GStateLineCap)cap));
}

inline void GState::SetLineJoin(LineJoin join)
{
	REX(TRN_GStateSetLineJoin(mp_state, (enum TRN_GStateLineJoin)join));
}

inline void GState::SetLineWidth(double width)
{
	REX(TRN_GStateSetLineWidth(mp_state,width));
}

inline void GState::SetMiterLimit(double miter_limit)
{
	REX(TRN_GStateSetMiterLimit(mp_state,miter_limit));
}

inline void GState::SetDashPattern(const std::vector<double>& dash_array, double phase)
{
	size_t sz = dash_array.size();
	REX(TRN_GStateSetDashPattern(mp_state, (sz<1 ? 0 : &dash_array[0]), int(sz), phase));
}

inline void GState::SetCharSpacing(double char_spacing)
{
	REX(TRN_GStateSetCharSpacing(mp_state,char_spacing));
}

inline void GState::SetWordSpacing(double word_spacing)
{
	REX(TRN_GStateSetWordSpacing(mp_state,word_spacing));
}

inline void GState::SetHorizontalScale(double hscale)
{
	REX(TRN_GStateSetHorizontalScale(mp_state,hscale));
}

inline void GState::SetLeading(double leading)
{
	REX(TRN_GStateSetLeading(mp_state,leading));
}

inline void GState::SetFont(Font font, double font_sz)
{
	REX(TRN_GStateSetFont(mp_state,font.mp_font,font_sz));
}

inline void GState::SetTextRenderMode(TextRenderingMode rmode)
{
	REX(TRN_GStateSetTextRenderMode(mp_state,(enum TRN_GStateTextRenderingMode)rmode));
}

inline void GState::SetTextRise(double rise)
{
	REX(TRN_GStateSetTextRise(mp_state,rise));
}

inline void GState::SetTextKnockout(bool knockout)
{
	REX(TRN_GStateSetTextKnockout(mp_state,BToTB(knockout)));
}

inline void GState::SetRenderingIntent(RenderingIntent intent)
{
	REX(TRN_GStateSetRenderingIntent(mp_state,(enum TRN_GStateRenderingIntent)intent));
}

inline void GState::SetBlendMode(BlendMode BM)
{
	REX(TRN_GStateSetBlendMode(mp_state, (enum TRN_GStateBlendMode)BM));
}

inline void GState::SetFillOpacity(double ca)
{
	REX(TRN_GStateSetFillOpacity(mp_state,ca));
}

inline void GState::SetStrokeOpacity(double CA)
{
	REX(TRN_GStateSetStrokeOpacity(mp_state, CA));
}

inline void GState::SetAISFlag(bool AIS)
{
	REX(TRN_GStateSetAISFlag(mp_state,BToTB(AIS)));
}

inline void GState::SetSoftMask(SDF::Obj SM)
{
	REX(TRN_GStateSetSoftMask(mp_state,SM.mp_obj));
}

inline void GState::SetStrokeOverprint(bool OP)
{
	REX(TRN_GStateSetStrokeOverprint(mp_state,BToTB(OP)));
}

inline void GState::SetFillOverprint(bool op)
{
	REX(TRN_GStateSetFillOverprint(mp_state,BToTB(op)));
}

inline void GState::SetOverprintMode(int OPM)
{
	REX(TRN_GStateSetOverprintMode(mp_state,OPM));
}

inline void GState::SetAutoStrokeAdjust(bool SA)
{
	REX(TRN_GStateSetAutoStrokeAdjust(mp_state,BToTB(SA)));
}

inline void GState::SetSmoothnessTolerance(double SM)
{
	REX(TRN_GStateSetSmoothnessTolerance(mp_state,SM));
}

inline void GState::SetBlackGenFunct(SDF::Obj BG)
{
	REX(TRN_GStateSetBlackGenFunct(mp_state,BG.mp_obj));
}

inline void GState::SetUCRFunct(SDF::Obj UCR)
{
	REX(TRN_GStateSetUCRFunct(mp_state,UCR.mp_obj));
}

inline void GState::SetTransferFunct(SDF::Obj TR)
{
	REX(TRN_GStateSetTransferFunct(mp_state,TR.mp_obj));
}

inline void GState::SetHalftone(SDF::Obj HT)
{
	REX(TRN_GStateSetHalftone(mp_state,HT.mp_obj));
}

inline GState::GState(TRN_GState impl) : mp_state(impl)
{
}

