
inline PDFRasterizer::PDFRasterizer(PDFRasterizer::Type type)
{
	REX(TRN_PDFRasterizerCreate((enum TRN_PDFRasterizerType)type,&mp_rast));
}

inline PDFRasterizer::~PDFRasterizer()
{
	DREX(mp_rast, TRN_PDFRasterizerDestroy(mp_rast));
}

inline void PDFRasterizer::Destroy()
{
	REX(TRN_PDFRasterizerDestroy(mp_rast));
	mp_rast=0;
}

#ifndef SWIG
inline std::vector<unsigned char> PDFRasterizer::Rasterize(Page& page, 
			int width, int height, int stride, 
			int num_comps, bool demult,
			const Common::Matrix2D& device_mtx,
			const Rect* clip,
			const Rect* scrl_clip_regions,
			bool* cancel)
{
	std::vector<unsigned char> result(height * stride);
	REX(TRN_PDFRasterizerRasterizeToMemory(mp_rast,page.mp_page, &result[0],
		width,height,stride, num_comps, BToTB(demult),
		(const TRN_Matrix2D*)&device_mtx,(const TRN_Rect*)clip,
		(const TRN_Rect*)scrl_clip_regions,BToTBP(cancel)));
	return result;
}

inline void PDFRasterizer::Rasterize(Page& page, UChar* in_out_image_buffer, 
			int width, int height, int stride, 
			int num_comps, bool demult,
			const Common::Matrix2D& device_mtx,
			const Rect* clip,
			const Rect* scrl_clip_regions,
			bool* cancel)
{
	REX(TRN_PDFRasterizerRasterizeToMemory(mp_rast,page.mp_page,in_out_image_buffer,
		width,height,stride, num_comps, BToTB(demult),
		(const TRN_Matrix2D*)&device_mtx,(const TRN_Rect*)clip,
		(const TRN_Rect*)scrl_clip_regions,BToTBP(cancel)));
}
#else // SWIG
inline std::vector<unsigned char> PDFRasterizer::Rasterize(
    Page& page,
    int width,
    int height,
    int stride,
    int num_comps,
    bool demult,
    const Common::Matrix2D& device_mtx,
    const Rect* clip,
    const Rect* scrl_clip_regions
)
{
	std::vector<unsigned char> result(height * stride);
	REX(
        TRN_PDFRasterizerRasterizeToMemory(
            mp_rast,
            page.mp_page,
            &result[0],
            width, height, stride, num_comps, BToTB(demult),
            (const TRN_Matrix2D*) &device_mtx,
            (const TRN_Rect*) clip,
            (const TRN_Rect*) scrl_clip_regions,
            NULL
        )
    );
    return result;
}
#endif

#if defined(_WIN32) && !defined(__WINRT__)
inline void PDFRasterizer::Rasterize(Page& page, void* hdc, 
	const Common::Matrix2D& device_mtx, 
	const Rect* clip,
	int dpi,
	bool* cancel)
{
	REX(TRN_PDFRasterizerRasterizeToDevice(mp_rast,page.mp_page,hdc,
		(const TRN_Matrix2D*)&device_mtx,(const TRN_Rect*)clip,dpi,BToTBP(cancel)));
}
#endif

inline void PDFRasterizer::SetDrawAnnotations(bool render_annots)
{
	REX(TRN_PDFRasterizerSetDrawAnnotations(mp_rast, BToTB(render_annots)));
}

inline void PDFRasterizer::SetHighlightFields(bool highlight)
{
	REX(TRN_PDFRasterizerSetHighlightFields(mp_rast, BToTB(highlight)));
}

inline void PDFRasterizer::SetGamma(double exp)
{
	REX(TRN_PDFRasterizerSetGamma(mp_rast, exp));
}

inline void PDFRasterizer::SetOCGContext(OCG::Context* ctx)
{
	REX(TRN_PDFRasterizerSetOCGContext(mp_rast, ctx->mp_obj));
}

inline void PDFRasterizer::SetPrintMode(bool is_printing)
{
	REX(TRN_PDFRasterizerSetPrintMode(mp_rast,BToTB(is_printing)));	
}

inline void PDFRasterizer::SetOverprint(OverprintPreviewMode op)
{
	REX(TRN_PDFRasterizerSetOverprint(mp_rast, (enum TRN_PDFRasterizerOverprintPreviewMode)op));
}

inline void PDFRasterizer::SetAntiAliasing(bool enable_aa)
{
	REX(TRN_PDFRasterizerSetAntiAliasing(mp_rast, BToTB(enable_aa)));
}

inline void PDFRasterizer::SetPathHinting(bool enable_hinting)
{
	REX(TRN_PDFRasterizerSetPathHinting(mp_rast, BToTB(enable_hinting)));
}

inline void PDFRasterizer::SetThinLineAdjustment(bool pixel_grid_fit, bool stroke_adjust)
{
	REX(TRN_PDFRasterizerSetThinLineAdjustment(mp_rast,BToTB(pixel_grid_fit), BToTB(stroke_adjust)));
}

inline void PDFRasterizer::SetImageSmoothing(bool smoothing_enabled,  bool hq_image_resampling)
{
	REX(TRN_PDFRasterizerSetImageSmoothing(mp_rast, BToTB(smoothing_enabled), BToTB(hq_image_resampling)));
}

inline void PDFRasterizer::SetCaching(bool enabled)
{
	REX(TRN_PDFRasterizerSetCaching(mp_rast, BToTB(enabled)));
}

#ifdef SWIG
inline void PDFRasterizer::SetErrorReportProc(Callback* instance)
{
	REX(TRN_PDFRasterizerSetErrorReportProc(mp_rast, (TRN_RasterizerErrorReportProc)&(Callback::StaticErrorReportProc),instance));
}
#else
inline void PDFRasterizer::SetErrorReportProc(PDFRasterizer::ErrorReportProc error_proc, void* data)
{
	REX(TRN_PDFRasterizerSetErrorReportProc(mp_rast, (TRN_RasterizerErrorReportProc)error_proc,data));
}
#endif

inline void PDFRasterizer::SetRasterizerType (PDFRasterizer::Type type)
{
	REX(TRN_PDFRasterizerSetRasterizerType(mp_rast,(enum TRN_PDFRasterizerType)type));
}

inline PDFRasterizer::Type PDFRasterizer::GetRasterizerType ()
{
	enum TRN_PDFRasterizerType result;
	REX(TRN_PDFRasterizerGetRasterizerType(mp_rast,&result));
	return (PDFRasterizer::Type)result;
}

inline void PDFRasterizer::SetColorPostProcessMode(PDFRasterizer::ColorPostProcessMode mode)
{
	REX(TRN_PDFRasterizerSetColorPostProcessMode(mp_rast,(enum TRN_PDFRasterizerColorPostProcessMode)mode));
}

inline PDFRasterizer::ColorPostProcessMode PDFRasterizer::GetColorPostProcessMode() const
{
	enum TRN_PDFRasterizerColorPostProcessMode result;
	REX(TRN_PDFRasterizerGetColorPostProcessMode(mp_rast,&result));
	return (PDFRasterizer::ColorPostProcessMode)result;
}

inline void PDFRasterizer::UpdateBuffer()
{
	REX(TRN_PDFRasterizerUpdateBuffer(mp_rast));
}

inline std::vector<Separation> PDFRasterizer::RasterizeSeparations(	Page& page,	int width, int height, const Common::Matrix2D& mtx,
	const Rect* clip, volatile bool* cancel)
{
	TRN_Vector sep_vec = NULL;
	REX(TRN_PDFRasterizerRasterizeSeparations(mp_rast, page.mp_page, width, height,	(const TRN_Matrix2D*)&mtx, (const TRN_Rect*)clip, 
		BToTBP(cancel),	(TRN_Vector*)&sep_vec));

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

inline Separation::Separation():m_owner(true)
{
	data = NULL;
	separation_name = NULL;
	data_size = 0;
}

inline Separation::~Separation()
{
	if (m_owner)
	{
		TRN_SeparationDestroy((TRN_Separation*)this);
	}
}

inline UInt8 Separation::C() const { return c; }
inline UInt8 Separation::M() const { return m; }
inline UInt8 Separation::Y() const { return y; }
inline UInt8 Separation::K() const { return k; }
inline UInt32  Separation::GetDataSize() const { return data_size; }
inline UString Separation::GetSeparationName() const { return m_separation_name; }

#ifdef SWIG
inline std::vector<unsigned char> Separation::GetData() const {
	std::vector<unsigned char> result(data_size);
	memcpy(&result[0], data, data_size);
	return result;
}
#else
inline const UChar* Separation::GetData() const {
	return data;
}
#endif


inline void CopySeparation(Separation* dst, const Separation* src)
{
	memcpy(dst, src, sizeof(TRN_Separation));
	dst->m_separation_name = src->m_separation_name;
}

inline Separation::Separation(const Separation& copy)
{
	if (copy.m_owner) {
		const_cast<Separation&>(copy).m_owner = false;
		m_owner = true;
		CopySeparation(this, &copy);
	}
	else {
		m_owner = false;
		CopySeparation(this, &copy);
	}
}

inline Separation& Separation::operator= (const Separation& copy)
{
	if (this == &copy)
	{
		return *this;
	}

	if (copy.m_owner) {
		const_cast<Separation&>(copy).m_owner = false;
		m_owner = true;
		CopySeparation(this, &copy);
	}
	else {
		m_owner = false;
		CopySeparation(this, &copy);
	}
	return *this;
}