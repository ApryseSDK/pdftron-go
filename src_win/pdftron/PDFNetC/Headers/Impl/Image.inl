
inline Image Image::Create(SDF::SDFDoc& doc, const UString& filename, SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateFromFile(doc.mp_doc,filename.mp_impl,
		encoder_hints.mp_obj,&result));
	return Image(result);
}
inline Image Image::Create(SDF::SDFDoc& doc,
	const UChar* image_data, 
	size_t image_data_size, 
	int width,
	int height,
	int bpc, 
	ColorSpace color_space, 
	SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateFromMemory(doc.mp_doc,image_data,
		image_data_size,width,height,bpc,color_space.mp_cs,
		encoder_hints.mp_obj,&result));
	return Image(result);
}

inline Image Image::Create(SDF::SDFDoc& doc,
	Filters::FilterReader& image_data, 				 
	int width,
	int height,
	int bpc, 
	ColorSpace color_space, 
	SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateFromStream(doc.mp_doc,image_data.m_impl,
		width,height,bpc,color_space.mp_cs,encoder_hints.mp_obj,&result));
	return Image(result);
}

inline Image Image::Create(SDF::SDFDoc& doc,
	const UChar* image_data,
	size_t image_data_size,
	SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateFromMemory2(doc.mp_doc, image_data, image_data_size,
		encoder_hints.mp_obj, &result));
	return Image(result);
}

inline Image Image::Create(SDF::SDFDoc& doc,
	Filters::Filter stream,
	SDF::Obj encoder_hints)
{
	TRN_Image result;
	stream.m_owner = false;
	REX(TRN_ImageCreateFromStream2(doc.mp_doc, stream.m_impl, encoder_hints.mp_obj, &result));
	stream.m_impl = 0;
	return Image(result);
}

#if defined(_WIN32)
inline Image Image::Create(SDF::SDFDoc& doc, Gdiplus::Bitmap* bmp, SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateFromBitmap(doc.mp_doc,(TRN_GDIPlusBitmap)bmp,encoder_hints.mp_obj,&result));
	return Image(result);
}
#endif

inline Image Image::CreateImageMask(SDF::SDFDoc& doc,
	const char* image_data, 
	size_t image_data_size, 
	int width,
	int height,
	SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateImageMask(doc.mp_doc,image_data,
		image_data_size,width,height,encoder_hints.mp_obj,&result));
	return Image(result);
}

inline Image Image::CreateImageMask(SDF::SDFDoc& doc,
	Filters::FilterReader& image_data, 				 
	int width,
	int height,
	SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateImageMaskFromStream(doc.mp_doc,
		image_data.m_impl,width,height,encoder_hints.mp_obj,&result));
	return Image(result);
}

inline Image Image::CreateSoftMask(SDF::SDFDoc& doc,
	const char* image_data, 
	size_t image_data_size, 
	int width,
	int height,
	int bpc, 
	SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateSoftMask(doc.mp_doc,image_data,image_data_size,
		width,height,bpc,encoder_hints.mp_obj,&result));
	return Image(result);
}

inline Image Image::CreateSoftMask(SDF::SDFDoc& doc,
	Filters::FilterReader& image_data, 				 
	int width,
	int height,
	int bpc, 
	SDF::Obj encoder_hints)
{
	TRN_Image result;
	REX(TRN_ImageCreateSoftMaskFromStream(doc.mp_doc,
		image_data.m_impl,width,height,bpc,
		encoder_hints.mp_obj,&result));
	return Image(result);
}

inline Image Image::Create(SDF::SDFDoc& doc,
	const char* image_data, 
	size_t image_data_size, 
	int width, 
	int height, 
	int bpc, 
	ColorSpace color_space,
	InputFilter input_format)
{
	TRN_Image result;
	REX(TRN_ImageCreateDirectFromMemory(doc.mp_doc,image_data,
		image_data_size,width,height,bpc,color_space.mp_cs,
		(enum TRN_ImageInputFilter)input_format,&result));
	return Image(result);
}

inline Image Image::Create(SDF::SDFDoc& doc,
	Filters::FilterReader& image_data, 				 
	int width, 
	int height, 
	int bpc, 
	ColorSpace color_space,
	InputFilter input_format)
{
	TRN_Image result;
	REX(TRN_ImageCreateDirectFromStream(doc.mp_doc,
		image_data.m_impl,width,height,bpc,color_space.mp_cs,
		(enum TRN_ImageInputFilter)input_format,&result));
	return Image(result);
}

inline Image::Image(SDF::Obj image_xobject)
{
	REX(TRN_ImageCreateFromObj(image_xobject.mp_obj,&mp_image));
}

inline Image::Image(const Image& c)
{
	REX(TRN_ImageCopy(c.mp_image,&mp_image));
}

inline Image& Image::operator=(const Image& c)
{
	REX(TRN_ImageCopy(c.mp_image,&mp_image));
	return *this;
}

inline SDF::Obj Image::GetSDFObj () const
{
	RetObj(TRN_ImageGetSDFObj(mp_image,&result));
}

inline bool Image::IsValid() const
{
	RetBool(TRN_ImageIsValid(mp_image,&result));
}

inline Filters::Filter Image::GetImageData() const
{
	TRN_Filter result;
	REX(TRN_ImageGetImageData(mp_image,&result));
	return Filters::Filter(result,true);
}

inline int Image::GetImageDataSize() const
{
	RetInt(TRN_ImageGetImageDataSize(mp_image, &result));
}

#if defined(_WIN32)
inline Gdiplus::Bitmap* Image::GetBitmap() const
{
	TRN_GDIPlusBitmap result;
	REX(TRN_ImageGetBitmap(mp_image,&result));
	return (Gdiplus::Bitmap*)result;
}
#endif

inline ColorSpace Image::GetImageColorSpace() const
{
	TRN_ColorSpace result;
	REX(TRN_ImageGetImageColorSpace(mp_image,&result));
	return ColorSpace(result);
}

inline int Image::GetImageWidth() const
{
	RetInt(TRN_ImageGetImageWidth(mp_image,&result));
}

inline int Image::GetImageHeight() const
{
	RetInt(TRN_ImageGetImageHeight(mp_image,&result));
}

inline SDF::Obj Image::GetDecodeArray() const
{
	RetObj(TRN_ImageGetDecodeArray(mp_image,&result));
}

inline int Image::GetBitsPerComponent() const
{
	RetInt(TRN_ImageGetBitsPerComponent(mp_image,&result));
}

inline int Image::GetComponentNum() const
{
	RetInt(TRN_ImageGetComponentNum(mp_image,&result));
}

inline bool Image::IsImageMask() const
{
	RetBool(TRN_ImageIsImageMask(mp_image,&result));
}

inline bool Image::IsImageInterpolate() const
{
	RetBool(TRN_ImageIsImageInterpolate(mp_image,&result));
}

inline SDF::Obj Image::GetMask() const
{
	RetObj(TRN_ImageGetMask(mp_image,&result));
}

inline void Image::SetMask(Image& image_mask) 
{
	REX(TRN_ImageSetMask(mp_image,image_mask.mp_image));
}

inline void Image::SetMask(SDF::Obj mask)
{
	REX(TRN_ImageSetMaskWithObj(mp_image,mask.mp_obj));
}

inline SDF::Obj Image::GetSoftMask()
{
	RetObj(TRN_ImageGetSoftMask(mp_image,&result));
}

inline void Image::SetSoftMask(Image& soft_mask)
{
	REX(TRN_ImageSetSoftMask(mp_image,soft_mask.mp_image));
}

inline GState::RenderingIntent Image::GetImageRenderingIntent() const
{
	enum TRN_GStateRenderingIntent result;
	REX(TRN_ImageGetImageRenderingIntent(mp_image,&result));
	return (GState::RenderingIntent)result;
}

inline int Image::Export(const UString& filename)
{
	RetInt(TRN_ImageExport(mp_image,filename.mp_impl,&result));
}

inline int Image::Export(Filters::FilterWriter& writer)
{
	RetInt(TRN_ImageExportFromStream(mp_image,writer.m_impl,&result));
}

inline void Image::ExportAsTiff(const UString& filename)
{
	REX(TRN_ImageExportAsTiff(mp_image,filename.mp_impl));
}

inline void Image::ExportAsTiff(Filters::FilterWriter& writer)
{
	REX(TRN_ImageExportAsTiffFromStream(mp_image,writer.m_impl));
}

inline void Image::ExportAsPng(const UString& filename)
{
	REX(TRN_ImageExportAsPng(mp_image,filename.mp_impl));
}

inline void Image::ExportAsPng(Filters::FilterWriter& writer)
{
	REX(TRN_ImageExportAsPngFromStream(mp_image,writer.m_impl));
}

inline Image::Image(TRN_Image impl) : mp_image(impl) {}

