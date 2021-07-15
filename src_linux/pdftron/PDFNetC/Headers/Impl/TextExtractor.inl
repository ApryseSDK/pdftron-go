
inline TextExtractor::TextExtractor()
{
	REX(TRN_TextExtractorCreate(&mp_extractor));
}
inline TextExtractor::~TextExtractor()
{
	DREX(mp_extractor, TRN_TextExtractorDestroy(mp_extractor));
}

inline void TextExtractor::Destroy()
{
	REX(TRN_TextExtractorDestroy(mp_extractor));
	mp_extractor=0;
}

inline void TextExtractor::Begin(Page page, const Rect* clip_ptr, UInt32 flags)
{
	REX(TRN_TextExtractorBegin(mp_extractor,page.mp_page,(TRN_Rect*)clip_ptr,(int)flags));
}

inline void TextExtractor::SetOCGContext(OCG::Context* ctx)
{
	REX(TRN_TextExtractorSetOCGContext(mp_extractor, ctx->mp_obj));
}

inline int TextExtractor::GetWordCount()
{
	RetInt(TRN_TextExtractorGetWordCount(mp_extractor,&result));
}

inline void TextExtractor::SetRightToLeftLanguage(bool val)
{
	REX(TRN_TextExtractorSetRightToLeftLanguage(mp_extractor, BToTB(val)));
}

inline bool TextExtractor::GetRightToLeftLanguage()
{
	RetBool(TRN_TextExtractorGetRightToLeftLanguage(mp_extractor, &result));
}

inline UString TextExtractor::GetAsText(bool dehyphen)
{
	UString out_str;
	REX(TRN_TextExtractorGetAsText(mp_extractor,BToTB(dehyphen), out_str.mp_impl));
	return out_str;
}

#ifndef SWIG
inline void TextExtractor::GetAsText(UString& out_str, bool dehyphen)
{
	REX(TRN_TextExtractorGetAsText(mp_extractor,BToTB(dehyphen), out_str.mp_impl));
}
#endif

inline UString TextExtractor::GetTextUnderAnnot(const Annot& annot)
{
	UString out_str;
	REX(TRN_TextExtractorGetTextUnderAnnot(mp_extractor, annot.mp_annot, out_str.mp_impl));
	return out_str;
}

#ifndef SWIG
inline void TextExtractor:: GetTextUnderAnnot(UString& out_str, const Annot& annot)
{
	REX(TRN_TextExtractorGetTextUnderAnnot(mp_extractor, annot.mp_annot, out_str.mp_impl));
}
#endif

inline UString TextExtractor::GetAsXML(UInt32 xml_output_flags)
{
	UString xmlStr;
	REX(TRN_TextExtractorGetAsXML(mp_extractor,(int)xml_output_flags, xmlStr.mp_impl));
	return xmlStr;
}

#ifndef SWIG
inline void TextExtractor::GetAsXML(UString& out_xml, UInt32 xml_output_flags)
{
	REX(TRN_TextExtractorGetAsXML(mp_extractor,(int)xml_output_flags, out_xml.mp_impl));
}
#endif


inline SDF::Obj Style::GetFont()
{
	RetObj(TRN_TextExtractorStyleGetFont(&mp_style,&result));
}

inline UString Style::GetFontName()
{
	RetStr(TRN_TextExtractorStyleGetFontName(&mp_style,&result));	
}

inline double Style::GetFontSize()
{
	RetDbl(TRN_TextExtractorStyleGetFontSize(&mp_style,&result));
}

inline int Style::GetWeight()
{
	RetInt(TRN_TextExtractorStyleGetWeight(&mp_style,&result));
}


inline bool Style::IsItalic()
{
	RetBool(TRN_TextExtractorStyleIsItalic(&mp_style, &result));
}

inline bool Style::IsSerif()
{
	RetBool(TRN_TextExtractorStyleIsSerif(&mp_style, &result));
}

inline std::vector<int> Style::GetColor()
{
	UInt8 rgb[3];
	std::vector<int> result (3);
	REX(TRN_TextExtractorStyleGetColor(&mp_style,rgb));
	int i = 0;
	for (i = 0; i < 3; i++) {
		result[i] = rgb[i];
	}
	return result;
}

#ifndef SWIG
inline void Style::GetColor(UInt8 rgb[3])
{
	REX(TRN_TextExtractorStyleGetColor(&mp_style,rgb));
}
#endif

inline bool Style::operator== (const Style& s) const
{
	RetBool(TRN_TextExtractorStyleCompare(&mp_style,(TRN_TextExtractorStyle*)&(s.mp_style),&result));
}

inline bool Style::operator!= (const Style& s) const
{
	return !operator==(s);
}

inline Style::Style()
{
	REX(TRN_TextExtractorStyleCreate(&mp_style))
}

inline Style::Style(const Style& s)
{
	REX(TRN_TextExtractorStyleCopy((TRN_TextExtractorStyle*)&(s.mp_style),&mp_style));
}

inline Style::Style(TRN_TextExtractorStyle impl)
{
	REX(TRN_TextExtractorStyleCopy(&impl, &mp_style));
}

inline int Word::GetNumGlyphs()
{
	RetInt(TRN_TextExtractorWordGetNumGlyphs(&mp_word, &result));
}

inline Rect Word::GetBBox()
{
	double bbox[4];
	REX(TRN_TextExtractorWordGetBBox(&mp_word, bbox));
	Rect rect(bbox[0],bbox[1],bbox[2],bbox[3]);
	return rect;
}

#ifndef SWIG
inline void Word::GetBBox(double out_bbox[4])
{
	REX(TRN_TextExtractorWordGetBBox(&mp_word, out_bbox));
}
#endif

inline std::vector<double> Word::GetQuad()
{
	double quad[8];
	REX(TRN_TextExtractorWordGetQuad(&mp_word,quad));
	std::vector<double> result(8);
	memcpy(&result[0], quad, 8*sizeof(double));
	return result;
}

#ifndef SWIG
inline void Word::GetQuad(double out_quad[8])
{
	REX(TRN_TextExtractorWordGetQuad(&mp_word,out_quad));
}
#endif

inline std::vector<double> Word::GetGlyphQuad(int glyph_idx)
{
	double quad[8];
	REX(TRN_TextExtractorWordGetGlyphQuad(&mp_word,glyph_idx,quad));
	std::vector<double> result(8);
	memcpy(&result[0], quad, 8*sizeof(double));
	return result;
}

#ifndef SWIG
inline void Word::GetGlyphQuad(int glyph_idx, double out_quad[8])
{
	REX(TRN_TextExtractorWordGetGlyphQuad(&mp_word,glyph_idx,out_quad));
}
#endif

inline Style Word::GetCharStyle(int char_idx)
{
	TRN_TextExtractorStyle result;
	REX(TRN_TextExtractorWordGetCharStyle(&mp_word,char_idx, &result));
	return Style(result);
}

inline Style Word::GetStyle()
{
	TRN_TextExtractorStyle result;
	REX(TRN_TextExtractorWordGetStyle(&mp_word, &result));
	return Style(result);
}

inline int Word::GetStringLen()
{
	RetInt(TRN_TextExtractorWordGetStringLen(&mp_word, &result));
}

#ifdef SWIG
inline UString Word::GetString()
{
	const Unicode* result;
	int len;
	REX(TRN_TextExtractorWordGetStringLen(&mp_word, &len));
	REX(TRN_TextExtractorWordGetString(&mp_word, &result));
	UString ustr(result, len);
	return ustr;
}
#else
inline const Unicode* Word::GetString()
{
	const Unicode* result;
	REX(TRN_TextExtractorWordGetString(&mp_word, &result));
	return result;
}
#endif

inline Word Word::GetNextWord()
{
	TRN_TextExtractorWord result;
	REX(TRN_TextExtractorWordGetNextWord(&mp_word,&result));
	return Word(result);
}

inline int Word::GetCurrentNum()
{
	int result;
	REX(TRN_TextExtractorWordGetCurrentNum(&mp_word, &result));
	return result;
}

inline bool Word::operator== (const Word& w) const
{
	RetBool(TRN_TextExtractorWordCompare(&mp_word, (TRN_TextExtractorWord*)&(w.mp_word), &result));
}

inline bool Word::operator!= (const Word& w) const
{
	return !this->operator==(w);
}

inline Word::Word()
{
	REX(TRN_TextExtractorWordCreate(&mp_word));
}

inline Word::Word(TRN_TextExtractorWord impl) : mp_word(impl)
{
}

inline bool Word::IsValid()
{
	RetBool(TRN_TextExtractorWordIsValid(&mp_word, &result));
}


inline int Line::GetNumWords()
{
	RetInt(TRN_TextExtractorLineGetNumWords(&mp_line,&result));
}

inline bool Line::IsSimpleLine()
{
	RetBool(TRN_TextExtractorLineIsSimpleLine(&mp_line, &result));
}

#ifdef SWIG
inline Rect Line::GetBBox()
{
	const double* arr;
	REX(TRN_TextExtractorLineGetBBox(&mp_line, &arr));
	Rect bbox(arr[0],arr[1],arr[2],arr[3]);
	return bbox;
}
#else
inline const double* Line::GetBBox()
{
	const double* result;
	REX(TRN_TextExtractorLineGetBBox(&mp_line, &result));
	return result;
}
#endif

inline std::vector<double> Line::GetQuad()
{
	double quad[8];
	REX(TRN_TextExtractorLineGetQuad(&mp_line, quad));
	std::vector<double> result(8);
	memcpy(&result[0], quad, 8*sizeof(double));
	return result;
}

#ifndef SWIG
inline void Line::GetQuad(double out_quad[8])
{
	REX(TRN_TextExtractorLineGetQuad(&mp_line, out_quad));
}
#endif

inline Word Line::GetFirstWord()
{
	TRN_TextExtractorWord result;
	REX(TRN_TextExtractorLineGetFirstWord(&mp_line, &result));
	return Word(result);
}

inline Word Line::GetWord(int word_idx)
{
	TRN_TextExtractorWord result;
	REX(TRN_TextExtractorLineGetWord(&mp_line, word_idx,&result));
	return Word(result);
}

inline Line Line::GetNextLine()
{
	TRN_TextExtractorLine result;
	REX(TRN_TextExtractorLineGetNextLine(&mp_line, &result));
	return Line(result);
}

inline int Line::GetCurrentNum()
{
	int result;
	REX(TRN_TextExtractorLineGetCurrentNum(&mp_line, &result));
	return result;
}

inline Style Line::GetStyle()
{
	TRN_TextExtractorStyle result;
	REX(TRN_TextExtractorLineGetStyle(&mp_line,&result));
	return Style(result);
}

inline int Line::GetParagraphID()
{
	RetInt(TRN_TextExtractorLineGetParagraphID(&mp_line, &result));
}

inline int Line::GetFlowID()
{
	RetInt(TRN_TextExtractorLineGetFlowID(&mp_line, &result));
}

inline bool Line::EndsWithHyphen()
{
	RetBool(TRN_TextExtractorLineEndsWithHyphen(&mp_line, &result));
}

inline bool Line::operator== (const Line& l) const
{
	RetBool(TRN_TextExtractorLineCompare(&mp_line, (TRN_TextExtractorLine*)&(l.mp_line),&result));
}

inline bool Line::operator!= (const Line& l) const
{
	return !this->operator==(l);
}

inline Line::Line()
{
	REX(TRN_TextExtractorLineCreate(&mp_line));
}


inline Line::Line(TRN_TextExtractorLine impl) : mp_line(impl)
{
}

inline bool Line::IsValid()
{
	RetBool(TRN_TextExtractorLineIsValid(&mp_line, &result));
}


inline int TextExtractor::GetNumLines()
{
	RetInt(TRN_TextExtractorGetNumLines(mp_extractor,&result));
}

inline Line TextExtractor::GetFirstLine()
{
	TRN_TextExtractorLine result;
	REX(TRN_TextExtractorGetFirstLine(mp_extractor, &result));
	return Line(result);
}

