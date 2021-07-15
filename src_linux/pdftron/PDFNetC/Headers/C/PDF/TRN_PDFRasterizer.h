//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFRasterizer
#define PDFTRON_H_CPDFPDFRasterizer

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_Annot.h>

typedef void (*TRN_PDFViewThumbAsyncHandler) (int page_num, TRN_Bool was_thumb_found, const char* thumb_buf, int thumb_width, int thumb_height, void* custom_data);
typedef void (*TRN_PDFViewRequestRenderInWorkerThreadProc) (void * custom_data);

enum TRN_PDFRasterizerType {
	e_PDFRasterizer_BuiltIn,
	e_PDFRasterizer_GDIPlus
};

enum TRN_PDFRasterizerOverprintPreviewMode {
	e_PDFRasterizer_op_off = 0,
	e_PDFRasterizer_op_on,
	e_PDFRasterizer_op_pdfx_on
};




TRN_API  TRN_PDFRasterizerCreate(enum TRN_PDFRasterizerType type, TRN_PDFRasterizer* result);
TRN_API  TRN_PDFRasterizerDestroy(TRN_PDFRasterizer r);

TRN_API TRN_PDFRasterizerRasterizeToMemory(TRN_PDFRasterizer r,TRN_Page page, TRN_UChar* in_out_image_buffer,
			int width, int height, int stride,
			int num_comps,
			TRN_Bool demult,
			const TRN_Matrix2D* device_mtx,
			const TRN_Rect* clip,
			const TRN_Rect* scrl_clp_regions,
			volatile TRN_Bool* cancel);

TRN_API TRN_PDFRasterizerGetChunkRenderer(TRN_PDFRasterizer r,TRN_Page page, TRN_UChar* in_out_image_buffer,
										   int width, int height, int stride,
										   int num_comps,
										   TRN_Bool demult,
										   const TRN_Matrix2D* device_mtx,
										   const TRN_Rect* clip,
										   const TRN_Rect* scrl_clp_regions,
										   volatile TRN_Bool* cancel,
										   TRN_ChunkRenderer* result);

TRN_API TRN_PDFRasterizerGetChunkRendererPath(TRN_PDFRasterizer r, TRN_Page page, TRN_UString file_path,
											int width, int height,
											TRN_Bool demult,
											const TRN_Matrix2D* device_mtx,
											const TRN_Rect* clip,
											const TRN_Rect* scrl_clp_regions,
											volatile TRN_Bool* cancel,
											TRN_ChunkRenderer* result);

TRN_API TRN_ChunkRendererRenderNext(TRN_ChunkRenderer cr, TRN_Bool* result);
TRN_API TRN_ChunkRendererDestroy(TRN_ChunkRenderer cr);



#ifdef _WIN32
TRN_API TRN_PDFRasterizerRasterizeToDevice(TRN_PDFRasterizer r,TRN_Page page, void* hdc,
	const TRN_Matrix2D* device_mtx,
	const TRN_Rect* clip,int dpi,
	volatile TRN_Bool* cancel);
#endif
TRN_API TRN_PDFRasterizerSetDrawAnnotations(TRN_PDFRasterizer r,TRN_Bool render_annots);
TRN_API TRN_PDFRasterizerSetHighlightFields(TRN_PDFRasterizer r,TRN_Bool highlight);
TRN_API TRN_PDFRasterizerSetAntiAliasing(TRN_PDFRasterizer r,TRN_Bool enable_aa);
TRN_API TRN_PDFRasterizerSetPathHinting(TRN_PDFRasterizer r, TRN_Bool enable_hinting);
TRN_API TRN_PDFRasterizerSetThinLineAdjustment(TRN_PDFRasterizer r, TRN_Bool grid_fit, TRN_Bool stroke_adjust);
TRN_API TRN_PDFRasterizerSetGamma(TRN_PDFRasterizer r, double expgamma);
TRN_API TRN_PDFRasterizerSetOCGContext(TRN_PDFRasterizer r, TRN_OCGContext ctx);
TRN_API TRN_PDFRasterizerSetPrintMode(TRN_PDFRasterizer r, TRN_Bool is_printing);
TRN_API TRN_PDFRasterizerSetImageSmoothing(TRN_PDFRasterizer r,TRN_Bool smoothing_enabled, TRN_Bool hq_image_resampling);
TRN_API TRN_PDFRasterizerSetOverprint(TRN_PDFRasterizer  r, enum TRN_PDFRasterizerOverprintPreviewMode op);
TRN_API TRN_PDFRasterizerSetCaching(TRN_PDFRasterizer r,TRN_Bool enabled);
TRN_API TRN_PDFDrawSetOCGContext(TRN_PDFDraw r, TRN_OCGContext ctx);

TRN_API TRN_PDFRasterizerSetAnnotationState(TRN_PDFRasterizer r, TRN_Annot annot, enum TRN_AnnotState new_view_state);

typedef void (*TRN_RasterizerErrorReportProc) (const char* message, void* data);

TRN_API TRN_PDFRasterizerSetErrorReportProc(TRN_PDFRasterizer r,TRN_RasterizerErrorReportProc error_proc, void* data);
TRN_API TRN_PDFRasterizerSetRasterizerType (TRN_PDFRasterizer r,enum TRN_PDFRasterizerType type);
TRN_API TRN_PDFRasterizerGetRasterizerType (TRN_PDFRasterizer r,enum TRN_PDFRasterizerType* result);

enum TRN_PDFRasterizerColorPostProcessMode {
	e_PDFRasterizer_postprocess_none = 0,
	e_PDFRasterizer_postprocess_invert
};
TRN_API TRN_PDFRasterizerSetColorPostProcessMode(TRN_PDFRasterizer r, enum TRN_PDFRasterizerColorPostProcessMode mode);
TRN_API TRN_PDFRasterizerGetColorPostProcessMode(TRN_PDFRasterizer r, enum TRN_PDFRasterizerColorPostProcessMode* result);

TRN_API TRN_PDFRasterizerEnableDisplayListCaching(TRN_PDFRasterizer r, TRN_Bool enabled);
TRN_API TRN_PDFRasterizerUpdateBuffer(TRN_PDFRasterizer r);

TRN_API TRN_PDFRasterizerRasterizeAnnot(TRN_PDFRasterizer r, TRN_Annot annot, TRN_Page page,
	const TRN_Matrix2D* device_mtx, TRN_Bool demult, volatile TRN_Bool* cancel, TRN_OwnedBitmap* result);

TRN_API TRN_PDFRasterizerRasterizeSeparations(TRN_PDFRasterizer r, TRN_Page page,  int width, int height, const TRN_Matrix2D* mtx,
	const TRN_Rect* clip, volatile TRN_Bool* cancel, TRN_Vector* result);

TRN_API TRN_SeparationDestroy(TRN_Separation* sep);


#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFRasterizer
