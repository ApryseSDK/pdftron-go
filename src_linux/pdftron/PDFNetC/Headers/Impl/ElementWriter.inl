
inline ElementWriter::ElementWriter()
{
	REX(TRN_ElementWriterCreate(&mp_writer));
}

inline ElementWriter::~ElementWriter()
{
	DREX(mp_writer, TRN_ElementWriterDestroy(mp_writer));
}

inline void ElementWriter::Destroy()
{
	REX(TRN_ElementWriterDestroy(mp_writer));
	mp_writer=0;
}

inline void ElementWriter::Begin( Page& page, WriteMode placement, bool page_coord_sys, bool compress, SDF::Obj resources)
{
	REX(TRN_ElementWriterBeginOnPage(mp_writer,
		page.mp_page, static_cast<TRN_ElementWriterWriteMode>(placement), BToTB(page_coord_sys), BToTB(compress), resources.mp_obj));
}

inline void ElementWriter::Begin( SDF::Obj stream_obj_to_update, bool compress, SDF::Obj resources)
{
	REX(TRN_ElementWriterBeginOnObj(mp_writer, stream_obj_to_update.mp_obj, compress, resources.mp_obj ) );
}

inline void ElementWriter::Begin(SDF::SDFDoc& doc, bool compress)
{
	REX(TRN_ElementWriterBegin(mp_writer,doc.mp_doc,BToTB(compress)));
}

inline SDF::Obj ElementWriter::End()
{
	TRN_Obj result;
	REX(TRN_ElementWriterEnd(mp_writer,&result));
	return SDF::Obj(result);
}

inline void ElementWriter::WriteElement(Element element)
{
	REX(TRN_ElementWriterWriteElement(mp_writer,element.mp_elem));
}

inline void ElementWriter::WritePlacedElement(Element element)
{
	REX(TRN_ElementWriterWritePlacedElement(mp_writer,element.mp_elem));
}

inline void ElementWriter::WriteGStateChanges(Element element)
{
	REX(TRN_ElementWriterWriteGStateChanges(mp_writer, element.mp_elem));
}

inline void ElementWriter::Flush()
{
	REX(TRN_ElementWriterFlush(mp_writer));
}

inline void ElementWriter::WriteBuffer(std::vector<unsigned char> data)
{
	REX(TRN_ElementWriterWriteBuffer(mp_writer,(const char*)&(data[0]),static_cast<int>(data.size())));
}

#ifndef SWIG
inline void ElementWriter::WriteBuffer(const char* data, int data_sz)
{
	REX(TRN_ElementWriterWriteBuffer(mp_writer,data,data_sz));
}
#endif

inline void ElementWriter::WriteString(const char* str)
{
	REX(TRN_ElementWriterWriteString(mp_writer,str));
}

inline void ElementWriter::SetDefaultGState(ElementReader& reader)
{
	REX(TRN_ElementWriterSetDefaultGState(mp_writer, reader.mp_reader));
}

inline ElementWriter::ElementWriter(TRN_ElementWriter impl) : mp_writer(impl)
{
}


