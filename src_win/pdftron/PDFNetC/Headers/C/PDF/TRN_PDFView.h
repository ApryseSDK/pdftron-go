//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFView
#define PDFTRON_H_CPDFPDFView

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Vector.h>
#include <C/PDF/TRN_PDFRasterizer.h>
#include <C/PDF/TRN_DocumentConversion.h>
#include <C/PDF/TRN_ExternalAnnotManager.h>
#include <C/PDF/TRN_Page.h>
#include <C/PDF/TRN_Annot.h>

TRN_API TRN_PDFViewCreate(TRN_PDFView* result);
TRN_API TRN_PDFViewDestroy(TRN_PDFView view);
TRN_API TRN_PDFViewSetDoc(TRN_PDFView view,  TRN_PDFDoc doc);
TRN_API TRN_OpenUniversalDoc(TRN_PDFView view, TRN_DocumentConversion conversion);
TRN_API TRN_PDFViewCloseDoc(TRN_PDFView view);
TRN_API TRN_PDFViewGetDoc(TRN_PDFView view, TRN_PDFDoc* result);

TRN_API TRN_PDFViewDocLock(TRN_PDFView view, TRN_Bool cancel);
TRN_API TRN_PDFViewDocUnlock(TRN_PDFView view);
TRN_API TRN_PDFViewDocTryLock(TRN_PDFView view, int milliseconds, TRN_Bool* result);

TRN_API TRN_PDFViewDocLockRead(TRN_PDFView view);
TRN_API TRN_PDFViewDocUnlockRead(TRN_PDFView view);
TRN_API TRN_PDFViewDocTryLockRead(TRN_PDFView view, int milliseconds, TRN_Bool* result);

enum TRN_PDFViewPageViewMode
{
	e_PDFView_fit_page = 0,
	e_PDFView_fit_width,
	e_PDFView_fit_height,
	e_PDFView_zoom
};

TRN_API TRN_PDFViewRefreshAndUpdate(TRN_PDFView view, const TRN_ViewChangeCollection view_change);
TRN_API TRN_PDFViewSetPageRefViewMode(TRN_PDFView view,  enum TRN_PDFViewPageViewMode mode);
TRN_API TRN_PDFViewGetPageRefViewMode( const TRN_PDFView view, enum TRN_PDFViewPageViewMode* result);

TRN_API TRN_PDFViewSetPageViewMode(TRN_PDFView view,  enum TRN_PDFViewPageViewMode mode);
TRN_API TRN_PDFViewGetPageViewMode( const TRN_PDFView view, enum TRN_PDFViewPageViewMode* result);

enum TRN_PDFViewPagePresentationMode
{
	e_PDFView_single_page = 1,
	e_PDFView_single_continuous,
	e_PDFView_facing,
	e_PDFView_facing_continuous,
	e_PDFView_facing_cover,
	e_PDFView_facing_continuous_cover
};

TRN_API TRN_PDFViewSetPagePresentationMode(TRN_PDFView view,  enum TRN_PDFViewPagePresentationMode mode);
TRN_API TRN_PDFViewGetPagePresentationMode( const TRN_PDFView view,  enum TRN_PDFViewPagePresentationMode* result);
TRN_API TRN_PDFViewGetCurrentPage( const TRN_PDFView view,  int* result);
TRN_API TRN_PDFViewGetVisiblePageCount( const TRN_PDFView view,  int* result);
TRN_API TRN_PDFViewGetVisiblePage( const TRN_PDFView view, int idx, int* result);
TRN_API TRN_PDFViewGetPageCount( const TRN_PDFView view,  int* result);
TRN_API TRN_PDFViewGotoFirstPage(TRN_PDFView view,  TRN_Bool* result);
TRN_API TRN_PDFViewGotoLastPage(TRN_PDFView view, TRN_Bool* result);
TRN_API TRN_PDFViewGotoNextPage(TRN_PDFView view, TRN_Bool* result);
TRN_API TRN_PDFViewGotoPreviousPage(TRN_PDFView view, TRN_Bool* result);
TRN_API TRN_PDFViewSetCurrentPage(TRN_PDFView view,  int page_num, TRN_Bool* result);
TRN_API TRN_PDFViewShowRect( TRN_PDFView view, int page_num, const TRN_Rect* rect, TRN_Bool* result );
TRN_API TRN_PDFViewGetZoom( const TRN_PDFView view, double* result);
TRN_API TRN_PDFViewSetZoom(TRN_PDFView view,  double zoom, TRN_Bool* result);
TRN_API TRN_PDFViewSetZoomOnPoint(TRN_PDFView view,  int x, int y, double zoom, TRN_Bool* result);
TRN_API TRN_PDFViewSmartZoomOnPoint(TRN_PDFView view,  int x, int y, TRN_Bool* result);
TRN_API TRN_PDFViewRotateClockwise(TRN_PDFView view);
TRN_API TRN_PDFViewRotateCounterClockwise(TRN_PDFView view);
TRN_API TRN_PDFViewGetPageNumberFromScreenPt( const TRN_PDFView view,  double x, double y, int* result);
TRN_API TRN_PDFViewConvScreenPtToCanvasPt( const TRN_PDFView view,  double* x, double* y);
TRN_API TRN_PDFViewConvCanvasPtToScreenPt( const TRN_PDFView view,  double* x, double* y);
TRN_API TRN_PDFViewConvCanvasPtToPagePt( const TRN_PDFView view,  double* x, double* y, int page_num);
TRN_API TRN_PDFViewConvPagePtToCanvasPt( const TRN_PDFView view,  double* x, double* y, int page_num);
TRN_API TRN_PDFViewConvScreenPtToPagePt( const TRN_PDFView view,  double* x, double* y, int page_num);
TRN_API TRN_PDFViewConvPagePtToScreenPt( const TRN_PDFView view,  double* x, double* y, int page_num);
TRN_API TRN_PDFViewSnapToNearestInDoc(TRN_PDFView view, double* screen_x, double* screen_y);
TRN_API TRN_PDFViewSetSnappingMode(TRN_PDFView view, unsigned int mode_flags);
TRN_API TRN_PDFViewGetDeviceTransform( const TRN_PDFView view,  int page_num, TRN_Matrix2D* result);
TRN_API TRN_PDFViewSetErrorReportProc(TRN_PDFView view,  TRN_RasterizerErrorReportProc error_proc, void* data);
    
TRN_API TRN_PDFViewEnableUndoRedo(TRN_PDFView view);
TRN_API TRN_PDFViewUndo(TRN_PDFView view, TRN_UString* result);
TRN_API TRN_PDFViewRedo(TRN_PDFView view, TRN_UString* result);
TRN_API TRN_PDFViewTakeSnapshot(TRN_PDFView view, const TRN_UString meta_info);
TRN_API TRN_PDFViewGetNextUndoInfo(TRN_PDFView view, TRN_UString* result);
TRN_API TRN_PDFViewGetNextRedoInfo(TRN_PDFView view, TRN_UString* result);
TRN_API TRN_PDFViewRevertAllChanges(TRN_PDFView view);
 
enum TRN_PDF_ExternalAnnotManager_Mode
{
	e_ExternalAnnotManager_Mode_user_only,			// each user can only edit the annotations they created
	e_ExternalAnnotManager_Mode_admin_undo_others,	// all the annotations can be edited, can undo yours and other's changes
	e_ExternalAnnotManager_Mode_admin_undo_own		// all the annotations can be edited, can undo only your changes
};
   
TRN_API TRN_PDFViewGetExternalAnnotManager(TRN_PDFView view, const TRN_UString author, TRN_ExternalAnnotManager* externalAnnotManager, enum TRN_PDF_ExternalAnnotManager_Mode mode);

    
typedef void (*TRN_PDFViewCurrentPageProc) (int current_page, int num_pages, void* data);
typedef void (*TRN_PDFViewCurrentZoomProc) (double current_zoom, void* data);
typedef void (*TRN_JavaScriptEventProc) (const char* event_type, const char* json, void* data);

TRN_API TRN_PDFViewSetCurrentPageProc(TRN_PDFView view,  TRN_PDFViewCurrentPageProc curr_pagenum_proc, void* data);
TRN_API TRN_PDFViewSetCurrentZoomProc(TRN_PDFView view,  TRN_PDFViewCurrentZoomProc curr_zoom_proc, void* data);
TRN_API TRN_PDFViewSetJavaScriptEventCallBack(TRN_PDFView view, TRN_JavaScriptEventProc js_proc, void* data);
TRN_API TRN_PDFViewGetCanvasWidth( const TRN_PDFView view, double* result);
TRN_API TRN_PDFViewGetCanvasHeight( const TRN_PDFView view, double* result);
TRN_API TRN_PDFViewGetHScrollPos( const TRN_PDFView view, double* result);
TRN_API TRN_PDFViewGetVScrollPos( const TRN_PDFView view, double* result);
TRN_API TRN_PDFViewOnScroll(TRN_PDFView view,  int pix_dx, int pix_dy);
TRN_API TRN_PDFViewSetHScrollPos(TRN_PDFView view,  double pos);
TRN_API TRN_PDFViewSetVScrollPos(TRN_PDFView view,  double pos);
TRN_API TRN_PDFViewOnSize(TRN_PDFView view,  int width, int height);
TRN_API TRN_PDFViewIsFinishedRendering( const TRN_PDFView view, TRN_Bool visible_region_only, TRN_Bool* result);
TRN_API TRN_PDFViewCancelRendering(TRN_PDFView view);
TRN_API TRN_PDFViewUpdate(TRN_PDFView view, TRN_Bool all);
TRN_API TRN_PDFViewUpdate2(TRN_PDFView view, const TRN_Rect* rect);
TRN_API TRN_PDFViewUpdate3(TRN_PDFView view, TRN_Annot annot, int num_page);
TRN_API TRN_PDFViewUpdateField(TRN_PDFView view, const TRN_Field* field);
TRN_API TRN_PDFViewUpdatePageLayout(TRN_PDFView view);
TRN_API TRN_PDFViewUpdateBuffer(TRN_PDFView view);
TRN_API TRN_PDFViewGetBuffer( const TRN_PDFView view, const char** result);
TRN_API TRN_PDFViewGetBufferWidth( const TRN_PDFView view, int* result);
TRN_API TRN_PDFViewGetBufferHeight( const TRN_PDFView view, int* result);
TRN_API TRN_PDFViewGetBufferStride( const TRN_PDFView view, int* result);
TRN_API TRN_PDFViewHideAnnotation(TRN_PDFView view, TRN_Annot annot);
TRN_API TRN_PDFViewShowAnnotation(TRN_PDFView view, TRN_Annot annot);
TRN_API TRN_PDFViewSetDrawAnnotations(TRN_PDFView view,  TRN_Bool render_annots);
TRN_API TRN_PDFViewSetHighlightFields(TRN_PDFView view,  TRN_Bool highlight);
TRN_API TRN_PDFViewSetRequiredFieldBorderColor(TRN_PDFView view, const TRN_ColorPt* col);

TRN_API TRN_PDFViewSetGamma(TRN_PDFView view, double gamma);
TRN_API TRN_PDFViewSetOverprint(TRN_PDFView view, enum TRN_PDFRasterizerOverprintPreviewMode op);
TRN_API TRN_PDFViewSetAntiAliasing(TRN_PDFView view,  TRN_Bool enable_aa);
TRN_API TRN_PDFViewSetPathHinting(TRN_PDFView view, TRN_Bool enable_hinting);
TRN_API TRN_PDFViewSetThinLineAdjustment(TRN_PDFView view, TRN_Bool grid_fit, TRN_Bool stroke_adjust);
TRN_API TRN_PDFViewSetImageSmoothing(TRN_PDFView view,  TRN_Bool smoothing_enabled);
TRN_API TRN_PDFViewSetCaching(TRN_PDFView view,  TRN_Bool enabled);
TRN_API TRN_PDFViewSetRightToLeftLanguage(TRN_PDFView view,  TRN_Bool enabled);
TRN_API TRN_PDFViewSetRasterizerType (TRN_PDFView view,  enum TRN_PDFRasterizerType type);
TRN_API TRN_PDFViewSetColorPostProcessColors (TRN_PDFView view, unsigned int white_color, unsigned int black_color);
TRN_API TRN_PDFViewSetColorPostProcessMapFile (TRN_PDFView view, TRN_Filter no_own_stream);

typedef void (*TRN_PDFViewRenderBeginEventProc) (void* data);
typedef void (*TRN_PDFViewRenderFinishEventProc) (void* data, TRN_Bool canceled);

TRN_API TRN_PDFViewSetRenderBeginProc(TRN_PDFView view,  TRN_PDFViewRenderBeginEventProc proc, void* data);
TRN_API TRN_PDFViewSetRenderFinishProc(TRN_PDFView view,  TRN_PDFViewRenderFinishEventProc proc, void* data);

enum TRN_PDFViewToolMode
{
	e_PDFView_custom,
	e_PDFView_pan,
	e_PDFView_text_rect_select,
	e_PDFView_text_struct_select,
};

TRN_API TRN_PDFViewSetToolMode(TRN_PDFView view,  enum TRN_PDFViewToolMode mode);
TRN_API TRN_PDFViewGetToolMode( const TRN_PDFView view, enum TRN_PDFViewToolMode* result);
TRN_API TRN_PDFViewSelectionCreate(TRN_PDFViewSelection* result);
TRN_API TRN_PDFViewSelectionDestroy(TRN_PDFViewSelection result);
TRN_API TRN_PDFViewSelectionAssign(TRN_PDFViewSelection left, TRN_PDFViewSelection right);
TRN_API TRN_PDFViewSelectionGetPageNum(const TRN_PDFViewSelection s, int* result);
//TRN_API TRN_PDFViewSelectionGetRects(const TRN_PDFViewSelection s, const double** rects, int* result);
TRN_API TRN_PDFViewSelectionGetQuads(const TRN_PDFViewSelection s, const double** quads, int* result);
TRN_API TRN_PDFViewSelectionGetAsUnicode(const TRN_PDFViewSelection s, TRN_UString result);
TRN_API TRN_PDFViewSelectionGetAsHtml(const TRN_PDFViewSelection s, const char** result);

enum TRN_PDFViewTextSelectionMode
{
	e_PDFView_structural,
	e_PDFView_rectangular,
	e_PDFView_structural_algorithm_2
};

TRN_API TRN_PDFViewSetTextSelectionMode(TRN_PDFView view, enum TRN_PDFViewTextSelectionMode tm);
TRN_API TRN_PDFViewSelect(TRN_PDFView view,  double x1, double y1, double x2, double y2, TRN_Bool* result);
TRN_API TRN_PDFViewSelectWithSnapping(TRN_PDFView view, double x1, double y1, double x2, double y2, 
	TRN_Bool snap_to_start, TRN_Bool snap_to_end, TRN_Bool* result);
TRN_API TRN_PDFViewSelectWithSmartSnapping(TRN_PDFView view, double x1, double y1, double x2, double y2, TRN_Bool* result);
TRN_API TRN_PDFViewSelectByStruct(TRN_PDFView view,  double x1, double y1, int page1, double x2, double y2, int page2, TRN_Bool* result);
TRN_API TRN_PDFViewSelectByStructWithSnapping(TRN_PDFView view, double x1, double y1, int page1, double x2, double y2, 
	int page2, TRN_Bool snap_to_start, TRN_Bool snap_to_end, TRN_Bool* result);
TRN_API TRN_PDFViewSelectByStructWithSmartSnapping(TRN_PDFView view, double x1, double y1, int page1, double x2, double y2,
	int page2, TRN_Bool* result);
TRN_API TRN_PDFViewSelectByHighlights(TRN_PDFView view,  TRN_Highlights h, TRN_Bool* result);
TRN_API TRN_PDFViewSelectBySelection(TRN_PDFView view, TRN_PDFViewSelection s, TRN_Bool * result);
TRN_API TRN_PDFViewSelectAll(TRN_PDFView view);

TRN_API TRN_PDFViewHasSelection(const TRN_PDFView view, TRN_Bool* result);
TRN_API TRN_PDFViewClearSelection(TRN_PDFView view);
TRN_API TRN_PDFViewGetSelection(const TRN_PDFView view, int pagenum, TRN_PDFViewSelection* result);
TRN_API TRN_PDFViewGetSelectionBeginPage( const TRN_PDFView view, int * result );
TRN_API TRN_PDFViewGetSelectionEndPage(const TRN_PDFView view, int * result );
TRN_API TRN_PDFViewHasSelectionOnPage(const TRN_PDFView view, int pagenum, TRN_Bool * result );

TRN_API TRN_PDFViewPrepareWords(const TRN_PDFView view, int page_num);
TRN_API TRN_PDFViewWereWordsPrepared(const TRN_PDFView view, int page_num, TRN_Bool * result);
TRN_API TRN_PDFViewIsThereTextInRect(const TRN_PDFView view, double x1, double y1, double x2, double y2, TRN_Bool * result);
TRN_API TRN_PDFViewPrepareAnnotsForMouse(const TRN_PDFView view, int page_num, double distance_threshold, double minimum_line_weight);
TRN_API TRN_PDFViewWereAnnotsForMousePrepared(const TRN_PDFView view, int page_num, TRN_Bool * result);
TRN_API TRN_PDFViewGetAnnotTypeUnder(const TRN_PDFView view, double x, double y, enum TRN_AnnotType * result);

TRN_API TRN_PDFViewSetPageBorderVisibility(TRN_PDFView view, TRN_Bool border_visible);
TRN_API TRN_PDFViewSetPageTransparencyGrid(TRN_PDFView view, TRN_Bool trans_grid_visible);
TRN_API TRN_PDFViewSetDefaultPageColor(TRN_PDFView view, TRN_UInt8 r, TRN_UInt8 g, TRN_UInt8 b);
TRN_API TRN_PDFViewSetBackgroundColor(TRN_PDFView view, TRN_UInt8 r, TRN_UInt8 g, TRN_UInt8 b, TRN_UInt8 a);
TRN_API TRN_PDFViewSetHorizontalAlign(TRN_PDFView view, int align);
TRN_API TRN_PDFViewSetVerticalAlign(TRN_PDFView view, int align);
TRN_API TRN_PDFViewSetPageSpacing(TRN_PDFView view, int horiz_col_space, int vert_col_space, int horiz_pad, int vert_pad);
TRN_API TRN_PDFViewSetViewerCache(TRN_SDFDoc document, TRN_Size max_cache_size, TRN_Bool on_disk);

TRN_API TRN_PDFViewSetOCGContext(TRN_PDFView view, TRN_OCGContext ctx);
TRN_API TRN_PDFViewGetOCGContext(TRN_PDFView view, TRN_OCGContext* result);
TRN_API TRN_PDFViewUpdateOCGContext(TRN_PDFView view);
TRN_API TRN_PDFViewGetRotation( const TRN_PDFView view, enum TRN_PageRotate* result);
TRN_API TRN_SetDevicePixelDensity(const TRN_PDFView view, double dpi, double scale_factor);
TRN_API TRN_PDFViewGetScreenRectForAnnot(const TRN_PDFView view, TRN_Annot annot, int page_num, TRN_Rect* result);
TRN_API TRN_PDFViewGetAnnotationAt(const TRN_PDFView view, int x, int y, double distanceThreshold, double minimumLineWeight, TRN_Annot* result);
TRN_API TRN_PDFViewGetAnnotationListAt(const TRN_PDFView view, int x1, int y1, int x2, int y2, TRN_Vector* result);

//TRN_API TRN_PDFViewSetDownloadReportHandler( TRN_PDFView view, TRN_PDFViewPartDownloadedProc proc, void* data );

typedef void (*TRN_PDFViewFindTextAsyncHandler)(TRN_Bool success, TRN_PDFViewSelection selection, void* custom_data);

TRN_API TRN_PDFViewCancelFindText(TRN_PDFView view);
TRN_API TRN_PDFViewSetFindTextHandler(TRN_PDFView view, TRN_PDFViewFindTextAsyncHandler proc, void* custom_data);
TRN_API TRN_PDFViewFindTextAsync(TRN_PDFView view, const TRN_UString search_str, TRN_Bool match_case, TRN_Bool match_whole_word,
								TRN_Bool search_up, TRN_Bool reg_exp);

TRN_API TRN_PDFViewSetupThumbnails(TRN_PDFView view, TRN_Bool use_embedded, TRN_Bool generate_at_runtime, TRN_Bool use_disk_cache, int thumb_max_side_length, size_t max_abs_cache_size, double max_perc_cache_size);
TRN_API TRN_PDFViewGetThumbAsync( TRN_PDFView view, int page_num, TRN_PDFViewThumbAsyncHandler proc, void* custom_data );


TRN_API TRN_PDFViewGetThumbInCacheSize(TRN_PDFView view, int page_num, size_t* result);
TRN_API TRN_PDFViewGetThumbInCache(TRN_PDFView view, int page_num, TRN_UChar* buf, TRN_UInt32* width_result, TRN_UInt32* height_result, TRN_Bool* result);

TRN_API TRN_PDFViewCancelAllThumbRequests( TRN_PDFView view);
TRN_API TRN_PDFViewSetRequestRenderinWorkerThreadProc(TRN_PDFView view, TRN_PDFViewRequestRenderInWorkerThreadProc proc, void * custom_data);
TRN_API TRN_PDFViewClearThumbCache(TRN_PDFView view);


TRN_API TRN_PDFViewSetUrlExtraction(const TRN_PDFView view, TRN_Bool enabled);
TRN_API TRN_PDFViewGetLinkAt(const TRN_PDFView view, int x, int y, TRN_Rect* rect, TRN_UString* url);

TRN_API TRN_PDFViewSetColorPostProcessMode(TRN_PDFView view, enum TRN_PDFRasterizerColorPostProcessMode mode);
TRN_API TRN_PDFViewGetColorPostProcessMode(TRN_PDFView view, enum TRN_PDFRasterizerColorPostProcessMode* result);

enum TRN_PDFViewDownloadedType
{
	e_downloadedtype_page = 0,
	e_downloadedtype_thumb,
	e_downloadedtype_named_dests,
	e_downloadedtype_outline,
	e_downloadedtype_finished,
	e_downloadedtype_failed,
	e_downloadedtype_opened
};

typedef void(*TRN_PDFViewPartDownloadedProc) (enum TRN_PDFViewDownloadedType type, TRN_PDFDoc doc, int page_num, int obj_num, const char* msg, void* user_data);
TRN_API TRN_PDFViewDoAction(const TRN_PDFView view, TRN_ActionParameter action_param);

enum TRN_PDFViewAnnotBitmapFlags
{
	e_normal_annot_bitmap = 1,
	e_mult_blend_annot_bitmap = 2,
	e_normal_annot_vector = 3,
	e_mult_blend_annot_vector = 4,
	e_resize_annot_bitmap = 128,
	e_remove_annot_bitmap = 129,
	e_clear_all_annot_bitmaps = 130,
	e_annot_renders_complete = 131
};

enum TRN_PDFViewAnnotVectorMode
{
	e_no_vector_annots = 0,
	e_pdftron_vector_annots = 1
};

TRN_API TRN_PDFViewGetAnnotationsOnPage(TRN_PDFView view, int page_num, TRN_Vector* result);
#if defined(__iOS__)
TRN_API TRN_PDFViewOpenURLAsync(TRN_PDFView view, const char* url, TRN_UString cache_file, const char* password, TRN_Obj options);
TRN_API TRN_PDFViewSetPartDownloadedProc(TRN_PDFView view, TRN_PDFViewPartDownloadedProc proc, void* data);
TRN_API TRN_PDFViewDownloaderUpdatePage(TRN_PDFView view, TRN_PDFDoc doc, TRN_UInt32 page_num, TRN_UInt32 obj_num, TRN_Bool* result);
TRN_API TRN_PDFViewDownloaderUpdateOutline(TRN_PDFView view, TRN_PDFDoc doc);
TRN_API TRN_PDFViewDownloaderUpdateThumb(TRN_PDFView view, TRN_PDFDoc doc, TRN_UInt32 page_num, TRN_UInt32 obj_num);
TRN_API TRN_PDFViewDownloaderFinishedDownload(TRN_PDFView view, TRN_PDFDoc doc);
TRN_API TRN_PDFViewDownloaderIsCorrectDoc(TRN_PDFView view, TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFViewDownloaderInitialized(TRN_PDFView view, TRN_PDFDoc doc);
TRN_API TRN_PDFViewGetCurCanvasId(const TRN_PDFView view, int*result);
TRN_API TRN_PDFViewPopViewingStates(TRN_PDFView view,  TRN_Bool restore);


TRN_API TRN_PDFViewSetFreezeTile(TRN_PDFView view,  TRN_Bool freeze);
TRN_API TRN_PDFViewPushViewingStates(TRN_PDFView mp_view);
TRN_API TRN_PDFViewDoProgressiveRender(const TRN_PDFView view);
TRN_API TRN_PDFViewGetCellSideLength(const TRN_PDFView view, int* result);
TRN_API TRN_PDFViewGetPageVGap(const TRN_PDFView view, double* result);
TRN_API TRN_PDFViewGetPageHGap(const TRN_PDFView view, double* result);
TRN_API TRN_PDFViewRequestRender(const TRN_PDFView);
TRN_API TRN_PDFViewGetPageRects(const TRN_PDFView view, const TRN_Rect* rect, double* page_rects_info, int* page_rects_size);
TRN_API TRN_PDFViewGetPageRectsOnCanvas(const TRN_PDFView view, double* page_rects_info, int canvasNumber, int* page_rects_size);
TRN_API TRN_PDFViewGetRefZoomForPage(const TRN_PDFView view, enum TRN_PDFViewPageViewMode viewMode, int pageNum, double* result);
TRN_API TRN_PDFViewPurgeMemory(const TRN_PDFView view);
TRN_API TRN_PDFViewSetMemInfo(const TRN_PDFView view, double total_mem, double mem_cap);
  
typedef void(*TRN_PDFViewAnnotBitmapProc)(void* self, int operation_type,
	char* buffer, unsigned int width, unsigned int height, unsigned int stride,
	unsigned int page_num, unsigned int annot_index, const void* annot_key,
	long long x_in_page, long long y_in_page, int x_offset, int y_offset,
	int remaining_tiles, int sequence_number, long long x_page_size, long long y_page_size);

TRN_API TRN_PDFViewSetWrapperAnnotBitmapProc(TRN_PDFView view, TRN_PDFViewAnnotBitmapProc annotBitmapProc,
	void* callingObject, TRN_PDFViewAnnotVectorMode mode);

typedef void (*TRN_PDFViewDeluxeCreateTileProc)( void* custom_data,
	char* buffer, unsigned int width, unsigned int height, unsigned int stride,
	unsigned int page_num, unsigned long long x_page_loc, unsigned long long y_page_loc,
    unsigned int zoomed_page_width, unsigned int zoomed_page_height,
	unsigned int tile_id, unsigned int x_in_page, unsigned int y_in_page,
	int canvas_id, int remaining_tiles, int tile_type,
	int sequence_number);

TRN_API TRN_PDFViewSetWrapperDeluxeCreateTileProc(TRN_PDFView view, TRN_PDFViewDeluxeCreateTileProc wrapperDeluxeCreateTileProc, void* callingObject);


typedef void (*TRN_PDFViewCreateTileProc)(void* data, char* buffer, int originX, int originY, int width, int height, int page_id,
										  long long cellNumber, bool finalRender, bool predictionRender, int tiles_remaining,
										  bool first_tile, int canvas_width, int canvas_height, int cell_side_length, int cell_per_row, int cell_per_col,
										  int thumb_nail_id);
typedef void (*TRN_PDFViewRemoveTileProc)(void* callingObject, int page_id, long long cellNumber, int thumb_nail_id, int sequenceNumber);
TRN_API TRN_PDFViewSetWrapperCreateTileProc(TRN_PDFView, TRN_PDFViewCreateTileProc wrapperCreateTileProc, void* callingObject);
TRN_API TRN_PDFViewSetWrapperRemoveTileProc(TRN_PDFView, TRN_PDFViewRemoveTileProc wrapperRemoveTileProc, void* callingObject);

#endif


#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFView
