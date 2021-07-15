
inline PDFDraw::PDFDraw(double dpi)
{
	REX(TRN_PDFDrawCreate(dpi,&mp_draw));
}

inline PDFDraw::~PDFDraw()
{
	DREX(mp_draw, TRN_PDFDrawDestroy(mp_draw));
}

inline void PDFDraw::Destroy()
{
	REX(TRN_PDFDrawDestroy(mp_draw));
	mp_draw=0;
}

inline void PDFDraw::SetRasterizerType (PDFRasterizer::Type type)
{
	REX(TRN_PDFDrawSetRasterizerType(mp_draw,(enum TRN_PDFRasterizerType)type));
}

inline void PDFDraw::SetDPI(double dpi)
{
	REX(TRN_PDFDrawSetDPI(mp_draw,dpi));
}

inline void PDFDraw::SetImageSize(int width, int height, bool preserve_aspect_ratio)
{
	REX(TRN_PDFDrawSetImageSize(mp_draw,width,height,BToTB(preserve_aspect_ratio)));
}

inline void PDFDraw::SetPageBox(Page::Box region)
{
	REX(TRN_PDFDrawSetPageBox(mp_draw,(enum TRN_PageBox)region));
}

inline void PDFDraw::SetClipRect(Rect rect)
{
	REX(TRN_PDFDrawSetClipRect(mp_draw, (const TRN_Rect*)&rect ));
}

inline void PDFDraw::SetFlipYAxis(bool flip_y)
{
	REX(TRN_PDFDrawSetFlipYAxis(mp_draw,BToTB(flip_y)));	
}

inline void PDFDraw::SetRotate(Page::Rotate r)
{
	REX(TRN_PDFDrawSetRotate(mp_draw,(enum TRN_PageRotate)r));	
}

inline void PDFDraw::SetDrawAnnotations(bool render_annots)
{
	REX(TRN_PDFDrawSetDrawAnnotations(mp_draw,BToTB(render_annots)));
}

inline void PDFDraw::SetHighlightFields(bool highlight)
{
	REX(TRN_PDFDrawSetHighlightFields(mp_draw,BToTB(highlight)));
}

inline void PDFDraw::SetGamma(double exp)
{
	REX(TRN_PDFDrawSetGamma(mp_draw,exp));
}

inline void PDFDraw::SetOCGContext(OCG::Context* ctx)
{
	REX(TRN_PDFDrawSetOCGContext(mp_draw, ctx->mp_obj));
}

inline void PDFDraw::SetPrintMode(bool is_printing)
{
	REX(TRN_PDFDrawSetPrintMode(mp_draw,BToTB(is_printing)));	
}

inline void PDFDraw::SetDefaultPageColor(UInt8 r, UInt8 g, UInt8 b)
{
	REX(TRN_PDFDrawSetDefaultPageColor(mp_draw, r, g, b));
}

inline void PDFDraw::SetPageTransparent(bool is_transparent)
{
	REX(TRN_PDFDrawSetPageTransparent(mp_draw, BToTB(is_transparent)));	
}

inline void PDFDraw::SetOverprint(PDFRasterizer::OverprintPreviewMode op)
{
	REX(TRN_PDFDrawSetOverprint(mp_draw, (enum TRN_PDFRasterizerOverprintPreviewMode)op));
}

inline void PDFDraw::SetAntiAliasing(bool enable_aa)
{
	REX(TRN_PDFDrawSetAntiAliasing(mp_draw,BToTB(enable_aa)));
}

inline void PDFDraw::SetPathHinting(bool enable_hinting)
{
	REX(TRN_PDFDrawSetPathHinting(mp_draw, BToTB(enable_hinting)));
}

inline void PDFDraw::SetThinLineAdjustment(bool pixel_grid_fit, bool stroke_adjust)
{
	REX(TRN_PDFDrawSetThinLineAdjustment(mp_draw,BToTB(pixel_grid_fit), BToTB(stroke_adjust)));
}

inline void PDFDraw::SetImageSmoothing(bool smoothing_enabled, bool hq_image_resampling)
{
	REX(TRN_PDFDrawSetImageSmoothing(mp_draw,BToTB(smoothing_enabled), BToTB(hq_image_resampling)));	
}

inline void PDFDraw::SetCaching(bool enabled)
{
	REX(TRN_PDFDrawSetCaching(mp_draw,BToTB(enabled)));	
}

inline void PDFDraw::SetColorPostProcessMode(PDFRasterizer::ColorPostProcessMode mode)
{
	REX(TRN_PDFDrawSetColorPostProcessMode(mp_draw, (enum TRN_PDFRasterizerColorPostProcessMode)mode));
}

inline void PDFDraw::Export(Page page, const UString& filename, const char* format, SDF::Obj encoder_params)
{
	REX(TRN_PDFDrawExport(mp_draw,page.mp_page,filename.mp_impl,format,encoder_params.mp_obj));
}

inline void PDFDraw::Export(Page page, Filters::Filter& stream, const char* format, SDF::Obj encoder_params)
{
	REX(TRN_PDFDrawExportStream(mp_draw,page.mp_page,stream.m_impl,format,encoder_params.mp_obj));
}

#ifdef __DOTNET
inline System::Drawing::Bitmap* PDFDraw::GetBitmap(Page page)
{
	TRN_SystemDrawingBitmap result;
	REX(TRN_PDFDrawGetBitmapDotNet(mp_draw,page.mp_page,&result));
	(System::Drawing::Bitmap*) result;
}
#endif
#ifdef _WIN32
inline void PDFDraw::DrawInRect(Page& page, void* hdc, const Rect& rect)
{
	REX(TRN_PDFDrawDrawInRect(mp_draw,page.mp_page,hdc,(const TRN_Rect*)&rect));	
}
#endif

inline const BitmapInfo PDFDraw::GetBitmap(Page page, PixelFormat pix_fmt, bool demult)
{
	const TRN_UChar* result;
	int width;
	int height;
	int stride;
	double dpi;
	REX(TRN_PDFDrawGetBitmap(mp_draw,page.mp_page,&width,&height,&stride,&dpi,
		(enum TRN_PDFDrawPixelFormat)pix_fmt, demult, &result));
	BitmapInfo bmp(width,height,stride,dpi,(char*)result);
	return bmp;
}

#ifndef SWIG
inline const UChar* PDFDraw::GetBitmap(Page page, int& out_width, int& out_height, int& out_stride, double& out_dpi, 
									   PixelFormat pix_fmt, bool demult)
{
	const TRN_UChar* result;
	REX(TRN_PDFDrawGetBitmap(mp_draw,page.mp_page,&out_width,&out_height,&out_stride,&out_dpi,
		(enum TRN_PDFDrawPixelFormat)pix_fmt, demult, &result));
	return result;
}
#endif

#ifdef SWIG
inline void PDFDraw::SetErrorReportProc(Callback* instance)
{
	REX(TRN_PDFDrawSetErrorReportProc(mp_draw,(TRN_RasterizerErrorReportProc)&(Callback::StaticErrorReportProc),instance));
}
#else
inline void PDFDraw::SetErrorReportProc(PDFRasterizer::ErrorReportProc error_proc, void* data)
{
	REX(TRN_PDFDrawSetErrorReportProc(mp_draw,(TRN_RasterizerErrorReportProc)error_proc,data));
}
#endif

inline std::vector<Separation> PDFDraw::GetSeparationBitmaps(Page page)
{
	TRN_Vector sep_vec = NULL;
	REX(TRN_PDFDrawGetSeparationBitmaps(mp_draw, page.mp_page, (TRN_Vector*)&sep_vec));

	TRN_UInt32 sep_size;
	TRN_VectorGetSize(sep_vec, &sep_size);

	std::vector<Separation> result(sep_size);
	for (UInt32 i = 0; i < sep_size; ++i)
	{
		TRN_Separation* current_separation;
		TRN_VectorGetAt(sep_vec, i, (void**)& current_separation);

		memcpy(&result[i], current_separation, sizeof(TRN_Separation));

		UString tmp(current_separation->separation_name);
		result[i].m_separation_name = tmp;
	}

	TRN_VectorDestroyKeepContents(sep_vec);
	return result;
}
