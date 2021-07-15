
inline Font::Font (SDF::Obj font_dict)
{
	REX(TRN_FontCreateFromObj(font_dict.mp_obj,&mp_font));
}

inline Font::Font(TRN_Font impl) : mp_font(impl)
{
}

inline Font::~Font() 
{
	DREX(mp_font, TRN_FontDestroy(mp_font));
}

inline void Font::Destroy() 
{
	DREX(mp_font, TRN_FontDestroy(mp_font));
}

inline Font Font::Create(SDF::SDFDoc& doc, StandardType1Font type, bool embed )
{
	if( embed ) {
		RetFont(TRN_FontCreateAndEmbed(doc.mp_doc,(enum TRN_FontStandardType1Font)type,&result));
	}
	else {
		RetFont(TRN_FontCreate(doc.mp_doc,(enum TRN_FontStandardType1Font)type,&result));
	}
}

inline Font Font::CreateTrueTypeFont(SDF::SDFDoc& doc, const UString& font_path, bool embed, bool subset)
{
	RetFont(TRN_FontCreateTrueTypeFont(doc.mp_doc,font_path.mp_impl,BToTB(embed),BToTB(subset),&result));
}

#ifdef _WIN32
inline Font Font::CreateTrueTypeFont2(SDF::SDFDoc& doc, const void* logfonta, bool embed, bool subset)
{
	RetFont(TRN_FontCreateTrueTypeFont2(doc.mp_doc,logfonta,BToTB(embed),BToTB(subset),&result));
}
#endif
inline Font Font::CreateCIDTrueTypeFont(SDF::SDFDoc& doc, const UString& font_path, bool embed, bool subset, Font::Encoding encoding, UInt32 ttc_font_index)
{
	RetFont(TRN_FontCreateCIDTrueTypeFont(doc.mp_doc,font_path.mp_impl,BToTB(embed),BToTB(subset),(TRN_FontEncoding)encoding,ttc_font_index,&result));
}

#ifdef _WIN32
inline Font Font::CreateCIDTrueTypeFont2(SDF::SDFDoc& doc, const void* logfonta, bool embed, bool subset, Font::Encoding encoding)
{
	RetFont(TRN_FontCreateCIDTrueTypeFont2(doc.mp_doc,logfonta,BToTB(embed),BToTB(subset),(TRN_FontEncoding)encoding,&result));
}

inline Font Font::CreateCIDTrueTypeFont2Unicode(SDF::SDFDoc& doc, const void* logfontw, bool embed, bool subset, Font::Encoding encoding)
{
	RetFont(TRN_FontCreateCIDTrueTypeFont2Unicode(doc.mp_doc, logfontw, BToTB(embed), BToTB(subset), (TRN_FontEncoding)encoding, &result));
}
#endif

inline Font Font::Create(SDF::SDFDoc& doc, Font& from, const UString& char_set)
{
	RetFont(TRN_FontCreateFromFontDescriptor(doc.mp_doc, from.mp_font, char_set.mp_impl, &result));
}

inline Font Font::Create(SDF::SDFDoc& doc, const char* name, const UString& char_set)
{
	RetFont(TRN_FontCreateFromName(doc.mp_doc, name, char_set.mp_impl, &result));
}

inline Font Font::CreateType1Font(SDF::SDFDoc& doc, const UString& font_path, bool embed)
{
	RetFont(TRN_FontCreateType1Font(doc.mp_doc,font_path.mp_impl,BToTB(embed),&result));
}

inline Font::Font(const Font& c)
{
	REX(TRN_FontCreateFromObj(0,&mp_font));
	REX(TRN_FontAssign(mp_font,c.mp_font));
}

inline Font& Font::operator=(const Font& c)
{
	REX(TRN_FontAssign(mp_font,c.mp_font));
	return *this;
}

inline Font::Type Font::GetType()
{
	enum TRN_FontType result;
	REX(TRN_FontGetType(mp_font,&result));
	return (Font::Type)result;
}

inline bool Font::IsSimple()
{
	RetBool(TRN_FontIsSimple(mp_font,&result)); 
}

#ifndef SWIG
inline Font::Type Font::GetType(SDF::Obj font_dict)
{
	enum TRN_FontType result;
	REX(TRN_FontGetTypeFromObj(font_dict.mp_obj,&result));
	return (Font::Type)result;
}
#endif

inline SDF::Obj Font::GetSDFObj ()
{
	RetObj(TRN_FontGetSDFObj(mp_font, &result));
}

inline SDF::Obj Font::GetDescriptor()
{
	RetObj(TRN_FontGetDescriptor(mp_font, &result));
}

inline const char* Font::GetName()
{
	RetCCS(TRN_FontGetName(mp_font,&result));
}

inline const char* Font::GetFamilyName()
{
	RetCCS(TRN_FontGetFamilyName(mp_font, &result));
}

inline bool Font::IsFixedWidth()
{
	RetBool(TRN_FontIsFixedWidth(mp_font, &result));
}

inline bool Font::IsSerif()
{
	RetBool(TRN_FontIsSerif(mp_font, &result));
}

inline bool Font::IsSymbolic()
{
	RetBool(TRN_FontIsSymbolic(mp_font, &result));
}

inline bool Font::IsItalic()
{
	RetBool(TRN_FontIsItalic(mp_font, &result));
}

inline bool Font::IsAllCap()
{
	RetBool(TRN_FontIsAllCap(mp_font, &result));
}

inline bool Font::IsForceBold()
{
	RetBool(TRN_FontIsForceBold(mp_font, &result));
}

inline bool Font::IsHorizontalMode()
{
	RetBool(TRN_FontIsHorizontalMode(mp_font, &result));
}

inline double Font::GetWidth(UInt32 char_code) const
{
	RetDbl(TRN_FontGetWidth(mp_font,char_code,&result));
}

inline double Font::GetMaxWidth()
{
	RetDbl(TRN_FontGetMaxWidth(mp_font,&result));
}

inline double Font::GetMissingWidth()
{
	RetDbl(TRN_FontGetMissingWidth(mp_font,&result));
}

inline Common::Iterator<UInt32> Font::GetCharCodeIterator()
{
	TRN_Iterator result;
	REX(TRN_FontGetCharCodeIterator(mp_font,&result));
	return Common::Iterator<UInt32>(result);
}

inline PathData Font::GetGlyphPath(UInt32 char_code,
					bool conics2cubics, 
					Common::Matrix2D* transform)
{
	TRN_Bool result0;
	int oprs_sz,data_sz, glyph_idx;
	REX(TRN_FontGetGlyphPath(mp_font, char_code, 0, &oprs_sz, 0, &data_sz,
		&glyph_idx, BToTB(conics2cubics),(TRN_Matrix2D*)transform, &result0));
	TRN_Bool result;
	std::vector<unsigned char> out_oprs;
	std::vector<double> out_data;
	if (result0 && oprs_sz>0 && data_sz>0) {
		out_oprs.resize(oprs_sz);
		out_data.resize(data_sz);
		TRN_FontGetGlyphPath(mp_font,char_code,&(out_oprs[0]),
			&oprs_sz, &(out_data[0]), &data_sz, &glyph_idx, BToTB(conics2cubics),
			(TRN_Matrix2D*)transform, &result);
	}
	else {
		out_oprs.resize(0); 
		out_data.resize(0);
		result = TBToB(result0);
	}
	return PathData(TBToB(result), glyph_idx, out_oprs, out_data);
}

inline ShapedText Font::GetShapedText(const UString& text_to_shape)
{
	TRN_ShapedText result;
	REX(TRN_FontGetShapedText(mp_font, text_to_shape.mp_impl, &result));
	return ShapedText(result);
}

inline UString Font::MapToUnicode(UInt32 char_code)
{
	Unicode out_uni_arr[8];
	int out_chars = 0;
	TRN_Bool b = true;
	TRN_FontMapToUnicode(mp_font,char_code,out_uni_arr,8,&out_chars,&b);	
	return UString(out_uni_arr, out_chars);
}

#ifndef SWIG
inline bool Font::MapToUnicode(UInt32 char_code, 
		Unicode* out_uni_arr, const int in_uni_sz, 
		int &out_chars)
{
	RetBool(TRN_FontMapToUnicode(mp_font,char_code,out_uni_arr,
		in_uni_sz,&out_chars,&result));
}
#endif

#ifndef SWIG
inline const char** Font::GetEncoding()
{
	const char** result;
	REX(TRN_FontGetEncoding(mp_font,&result));
	return result;
}
#endif

inline bool Font::IsEmbedded()
{
	RetBool(TRN_FontIsEmbedded(mp_font,&result));
}

inline const char* Font::GetEmbeddedFontName()
{
	RetCCS(TRN_FontGetEmbeddedFontName(mp_font,&result));
}

inline SDF::Obj Font::GetEmbeddedFont()
{
	RetObj(TRN_FontGetEmbeddedFont(mp_font, &result));
}

inline int Font::GetEmbeddedFontBufSize()
{
	RetInt(TRN_FontGetEmbeddedFontBufSize(mp_font,&result));
}

inline UInt16 Font::GetUnitsPerEm()
{
	UInt16 result;
	REX(TRN_FontGetUnitsPerEm(mp_font, &result));
	return result;
}

inline Rect Font::GetBBox()
{
	RetRec(TRN_FontGetBBox(mp_font, &result));
}

inline double Font::GetAscent()
{
	RetDbl(TRN_FontGetAscent(mp_font,&result));
}

inline double Font::GetDescent()
{
	RetDbl(TRN_FontGetDescent(mp_font,&result));
}

inline int Font::GetStandardType1FontType()
{
	RetInt(TRN_FontGetStandardType1FontType(mp_font,&result));
}

inline bool Font::IsCFF()
{
	RetBool(TRN_FontIsCFF(mp_font,&result));
}

inline Common::Matrix2D Font::GetType3FontMatrix()
{
	RetMtx(TRN_FontGetType3FontMatrix(mp_font,&result));
}

inline SDF::Obj Font::GetType3GlyphStream(UInt32 char_code)
{
	RetObj(TRN_FontGetType3GlyphStream(mp_font,char_code,&result));
}

inline std::vector<double> Font::GetVerticalAdvance(UInt32 char_code)
{
	double out_pos_vect_x;
	double out_pos_vect_y;
	double result;
	std::vector<double> arr(3);
	TRN_FontGetVerticalAdvance(mp_font,char_code,&out_pos_vect_x,&out_pos_vect_y,&result);
	arr[0] = out_pos_vect_x;
	arr[1] = out_pos_vect_y;
	arr[2] = result;
	return arr;
}

#ifndef SWIG
inline double Font::GetVerticalAdvance(UInt32 char_code, double &out_pos_vect_x, double &out_pos_vect_y)
{
	RetDbl(TRN_FontGetVerticalAdvance(mp_font,char_code,&out_pos_vect_x,&out_pos_vect_y,&result));
}
#endif

inline Font Font::GetDescendant()
{
	RetFont(TRN_FontGetDescendant(mp_font,&result));
}

inline UInt32 Font::MapToCID(UInt32 char_code) const
{
	UInt32 result;
	REX(TRN_FontMapToCID(mp_font,char_code,&result));
	return result;
}

#ifndef SWIG
inline int Font::MapToCID(const UChar* char_data, int char_data_avail, UInt32& out_charcode, UInt32& out_cid) const
{
	RetInt(TRN_FontMapToCID2(mp_font,char_data,char_data_avail,&out_charcode,&out_cid,&result));
}
#endif

