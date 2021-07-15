
inline ElementReader::ElementReader()
{
	REX(TRN_ElementReaderCreate(&mp_reader));
}

inline ElementReader::~ElementReader()
{
	DREX(mp_reader, TRN_ElementReaderDestroy(mp_reader));
}

inline void ElementReader::Destroy()
{
	REX(TRN_ElementReaderDestroy(mp_reader));
	mp_reader=0;
}

inline void ElementReader::Begin(const Page& page, OCG::Context* ocg_context)
{
	REX(TRN_ElementReaderBeginOnPage(mp_reader, page.mp_page, 
		ocg_context ? ocg_context->mp_obj : 0));
}

inline void ElementReader::Begin(SDF::Obj content_stream, SDF::Obj resource_dict, OCG::Context* ocg_context)
{
	REX(TRN_ElementReaderBegin(mp_reader,
		content_stream.mp_obj, resource_dict.mp_obj,
		ocg_context ? ocg_context->mp_obj : 0));
}

inline void ElementReader::AppendResource(SDF::Obj res)
{
	REX(TRN_ElementReaderAppendResource(mp_reader, res.mp_obj));
}

inline Element ElementReader::Next()
{
	TRN_Element result;
	REX(TRN_ElementReaderNext(mp_reader,&result));
	return Element(result);
}

inline Element ElementReader::Current()
{
	TRN_Element result;
	REX(TRN_ElementReaderCurrent(mp_reader,&result));
	return Element(result);
}

inline void ElementReader::FormBegin()
{
	REX(TRN_ElementReaderFormBegin(mp_reader));
}

inline void ElementReader::PatternBegin(bool fill_pattern, bool reset_ctm_tfm)
{
	REX(TRN_ElementReaderPatternBegin(mp_reader, BToTB(fill_pattern), BToTB(reset_ctm_tfm)));
}

inline void ElementReader::Type3FontBegin(CharData& char_data, SDF::Obj resource_dict)
{
	REX(TRN_ElementReaderType3FontBegin(mp_reader, &char_data, resource_dict.mp_obj));
}

inline bool ElementReader::End()
{
	RetBool(TRN_ElementReaderEnd(mp_reader,&result));
}

inline GSChangesIterator ElementReader::GetChangesIterator()
{
	TRN_Iterator result;
	REX(TRN_ElementReaderGetChangesIterator(mp_reader,&result));
	return Common::Iterator<int>(result);
}

inline bool ElementReader::IsChanged(GState::GStateAttribute attrib)
{
	RetBool(TRN_ElementReaderIsChanged(mp_reader,
		(enum TRN_GStateAttribute)attrib,&result));
}

inline void ElementReader::ClearChangeList()
{
	REX(TRN_ElementReaderClearChangeList(mp_reader));
}

inline SDF::Obj ElementReader::GetFont (const char* name)
{
	RetObj(TRN_ElementReaderGetFont(mp_reader,name,&result));
}

inline SDF::Obj ElementReader::GetXObject (const char* name)	
{
	RetObj(TRN_ElementReaderGetXObject(mp_reader,name,&result));
}

inline SDF::Obj ElementReader::GetShading(const char* name)
{
	RetObj(TRN_ElementReaderGetShading(mp_reader,name,&result));
}

inline SDF::Obj ElementReader::GetColorSpace (const char* name)
{
	RetObj(TRN_ElementReaderGetColorSpace(mp_reader,name,&result));
}

inline SDF::Obj ElementReader::GetPattern (const char* name)
{
	RetObj(TRN_ElementReaderGetPattern(mp_reader,name,&result));
}

inline SDF::Obj ElementReader::GetExtGState (const char* name)
{
	RetObj(TRN_ElementReaderGetExtGState(mp_reader,name,&result));
}

inline ElementReader::ElementReader(TRN_ElementReader impl) : mp_reader(impl)
{}

