
inline Element::Element() : mp_elem(0)
{
}

inline Element::Element(const Element& c) : mp_elem(c.mp_elem)
{}

inline Element& Element::operator=(const Element&c)
{
	mp_elem=c.mp_elem;
	return *this;
}

inline Element::Type Element::GetType()
{
	enum TRN_ElementType result;
	REX(TRN_ElementGetType(mp_elem,&result));
	return (Element::Type)result;
}

inline GState Element::GetGState()
{
	TRN_GState result;
	REX(TRN_ElementGetGState(mp_elem,&result));
	return GState(result);
}

inline Common::Matrix2D Element::GetCTM()
{
	RetMtx(TRN_ElementGetCTM(mp_elem,&result));
}

inline Rect Element::GetBBox()
{
	Rect bbox;
	TRN_Bool result;
	REX(TRN_ElementGetBBox(mp_elem,(TRN_Rect*)&bbox,&result));
	return bbox;
}

#ifndef SWIG
inline bool Element::GetBBox(Rect& out_bbox)
{
	RetBool(TRN_ElementGetBBox(mp_elem,(TRN_Rect*)&out_bbox,&result));
}
#endif

inline Struct::SElement Element::GetParentStructElement()
{
	TRN_SElement result;
    REX(TRN_ElementGetParentStructElement(mp_elem,&result));
	return Struct::SElement(result);
}

inline int Element::GetStructMCID()
{
	RetInt(TRN_ElementGetStructMCID(mp_elem,&result));
}

inline bool Element::IsOCVisible()
{
	RetBool(TRN_ElementIsOCVisible(mp_elem,&result));
}

inline bool Element::IsClippingPath()
{
	RetBool(TRN_ElementIsClippingPath(mp_elem,&result));
}

inline bool Element::IsStroked()
{
	RetBool(TRN_ElementIsStroked(mp_elem,&result));
}

inline bool Element::IsFilled()
{
	RetBool(TRN_ElementIsFilled(mp_elem,&result));
}

inline bool Element::IsWindingFill()
{
	RetBool(TRN_ElementIsWindingFill(mp_elem,&result));
}

inline bool Element::IsClipWindingFill()
{
	RetBool(TRN_ElementIsClipWindingFill(mp_elem,&result));
}

inline PathData Element::GetPathData() const
{
	PathData data;
	char* arr;
	int size;
	TRN_ElementGetPathTypesCount(mp_elem, &size);
	data.oprs.resize(size);
	TRN_ElementGetPathTypes(mp_elem,(const char**)&arr);
	memcpy(&data.oprs.front(), arr, size);
	
	int dataSize;
	const double* arr2;
	TRN_ElementGetPathPointCount(mp_elem, &dataSize);
	data.pts.resize(dataSize);
	REX(TRN_ElementGetPathPoints(mp_elem, &arr2));
	memcpy(&data.pts.front(), arr2, dataSize * sizeof(double));
	return data;
}

#ifdef SWIG
inline void Element::SetPathData(const PathData& data)
{
	REX(TRN_ElementSetPathTypes(mp_elem,(const char*) &(data.GetOperators().front()), (int)data.GetOperators().size()));
	REX(TRN_ElementSetPathPoints(mp_elem, &data.GetPoints().front(), (int)data.GetPoints().size()));
}
#else
inline void Element::SetPathData(const PathData& data)
{
	REX(TRN_ElementSetPathTypes(mp_elem,(const char*) &(data.GetOperators().front()), (int)data.GetOperators().size()));
	REX(TRN_ElementSetPathPoints(mp_elem, &data.GetPoints().front(), (int)data.GetPoints().size()));
}
#endif

inline void Element::SetPathClip(bool clip)
{
	REX(TRN_ElementSetPathClip(mp_elem, BToTB(clip)));
}

inline void Element::SetPathStroke(bool stroke)
{
	REX(TRN_ElementSetPathStroke(mp_elem,BToTB(stroke)));
}

inline void Element::SetPathFill(bool fill)
{
	REX(TRN_ElementSetPathFill(mp_elem,BToTB(fill)));
}

inline void Element::SetWindingFill(bool winding_rule)
{
	REX(TRN_ElementSetWindingFill(mp_elem,BToTB(winding_rule)));
}

inline void Element::SetClipWindingFill(bool winding_rule)
{
	REX(TRN_ElementSetClipWindingFill(mp_elem,BToTB(winding_rule)));
}

inline SDF::Obj Element::GetXObject()
{
	RetObj(TRN_ElementGetXObject(mp_elem,&result));
}

inline Filters::Filter Element::GetImageData() const
{
	TRN_Filter result;
	REX(TRN_ElementGetImageData(mp_elem,&result));
	return Filters::Filter(result, true);
}

inline int Element::GetImageDataSize() const
{
	RetInt(TRN_ElementGetImageDataSize(mp_elem,&result));
}

#if defined(_WIN32)
inline Gdiplus::Bitmap* Element::GetBitmap() const
{
	TRN_GDIPlusBitmap result;
	REX(TRN_ElementGetBitmap(mp_elem,&result));
	return (Gdiplus::Bitmap*) result;
}

#endif

inline ColorSpace Element::GetImageColorSpace() const
{
	TRN_ColorSpace result;
	REX(TRN_ElementGetImageColorSpace(mp_elem,&result));
	return ColorSpace(result);
}

inline int Element::GetImageWidth() const
{
	RetInt(TRN_ElementGetImageWidth(mp_elem,&result));
}

inline int Element::GetImageHeight() const
{
	RetInt(TRN_ElementGetImageHeight(mp_elem,&result));
}

inline SDF::Obj Element::GetDecodeArray() const
{
	RetObj(TRN_ElementGetDecodeArray(mp_elem,&result));
}

inline int Element::GetBitsPerComponent() const
{
	RetInt(TRN_ElementGetBitsPerComponent(mp_elem,&result));
}

inline int Element::GetComponentNum() const
{
	RetInt(TRN_ElementGetComponentNum(mp_elem,&result));
}

inline bool Element::IsImageMask() const
{
	RetBool(TRN_ElementIsImageMask(mp_elem,&result));
}

inline bool Element::IsImageInterpolate() const
{
	RetBool(TRN_ElementIsImageInterpolate(mp_elem,&result));
}

inline SDF::Obj Element::GetMask() const
{
	RetObj(TRN_ElementGetMask(mp_elem,&result));
}

inline GState::RenderingIntent Element::GetImageRenderingIntent() const
{
	enum TRN_GStateRenderingIntent result;
	REX(TRN_ElementGetImageRenderingIntent(mp_elem,&result));
	return (GState::RenderingIntent)result;
}

inline UString Element::GetTextString()
{
	TRN_UString result;
	REX(TRN_ElementGetTextString(mp_elem,&result));
	return UString(result);	
}

#ifdef SWIG
inline std::vector<unsigned char> Element::GetTextData()
{
	UInt32 size;
	REX(TRN_ElementGetTextDataSize(mp_elem,&size));
	std::vector<unsigned char> result;
	result.resize(size);
	const UChar* arr;
	REX(TRN_ElementGetTextData(mp_elem,&arr));
	memcpy(&(result[0]), arr, size);
	return result;
}
#else
inline const UChar* Element::GetTextData()
{
	const UChar* result;
	REX(TRN_ElementGetTextData(mp_elem,&result));
	return result;
}
#endif

inline UInt32 Element::GetTextDataSize()
{
	UInt32 result;
	REX(TRN_ElementGetTextDataSize(mp_elem,&result));
	return result;
}

inline Common::Matrix2D Element::GetTextMatrix()
{
	RetMtx(TRN_ElementGetTextMatrix(mp_elem,&result));
}

inline CharIterator Element::GetCharIterator()
{
	TRN_Iterator result;
	REX(TRN_ElementGetCharIterator(mp_elem,&result));
	return CharIterator(result);
}

inline double Element::GetTextLength()
{
	RetDbl(TRN_ElementGetTextLength(mp_elem,&result));
}

inline double Element::GetPosAdjustment()
{
	RetDbl(TRN_ElementGetPosAdjustment(mp_elem,&result));
}

inline Point Element::GetNewTextLineOffset()
{
	Point result;
	REX(TRN_ElementGetNewTextLineOffset(mp_elem,&(result.x),&(result.y)));
	return result;
}

#ifndef SWIG
inline void Element::GetNewTextLineOffset(double& out_x, double& out_y)
{
	REX(TRN_ElementGetNewTextLineOffset(mp_elem,&out_x,&out_y));
}
#endif

inline bool Element::HasTextMatrix()
{
	RetBool(TRN_ElementHasTextMatrix(mp_elem,&result));
}

inline void Element::SetTextData(const UChar* text_data, int text_data_size)
{
	REX(TRN_ElementSetTextData(mp_elem,text_data,text_data_size));
}

inline void Element::SetTextMatrix(Common::Matrix2D& mtx)
{
	REX(TRN_ElementSetTextMatrix(mp_elem,(TRN_Matrix2D*)&mtx));
}

inline void Element::SetTextMatrix(double a, double b, double c, double d, double h, double v)
{
	REX(TRN_ElementSetTextMatrixEntries(mp_elem,a,b,c,d,h,v));
}

inline void Element::SetPosAdjustment(double adjust)
{
	REX(TRN_ElementSetPosAdjustment(mp_elem,adjust));
}

inline void Element::UpdateTextMetrics()
{
	REX(TRN_ElementUpdateTextMetrics(mp_elem));
}

inline void Element::SetNewTextLineOffset(double dx, double dy)
{
	REX(TRN_ElementSetNewTextLineOffset(mp_elem,dx,dy));
}

inline Shading Element::GetShading()
{
	TRN_Shading result;
	REX(TRN_ElementGetShading(mp_elem,&result));
	return Shading(result);
}
inline SDF::Obj Element::GetMCPropertyDict()
{
	RetObj(TRN_ElementGetMCPropertyDict(mp_elem,&result));
}
inline SDF::Obj Element::GetMCTag()
{
	RetObj(TRN_ElementGetMCTag(mp_elem,&result));
}


inline Element::Element(TRN_Element impl) : mp_elem(impl)
{}

