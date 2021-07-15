inline PDFView::PDFView()
{
	REX(TRN_PDFViewCreate(&mp_view));
	mp_findtexthandler = NULL;
    mp_findtextdata = NULL;
}

inline PDFView::~PDFView()
{
	DREX(mp_view, TRN_PDFViewDestroy(mp_view));
}

inline void PDFView::Destroy() {
	REX(TRN_PDFViewDestroy(mp_view));
	mp_view = 0;
}

inline void PDFView::SetDoc(PDFDoc& doc)
{
	REX(TRN_PDFViewSetDoc(mp_view,doc.mp_doc));
}

inline void PDFView::CloseDoc()
{
    REX(TRN_PDFViewCloseDoc(mp_view));
}

inline PDFDoc* PDFView::GetDoc()
{
    TRN_PDFDoc localTempDoc;
	REX(TRN_PDFViewGetDoc(mp_view,&localTempDoc));
	if(localTempDoc)
    {
        temp_doc = localTempDoc;
		return ((PDFDoc*)&temp_doc);
    }
	else
		return 0;
}


inline void PDFView::DocLock(bool cancel_threads)
{
	REX(TRN_PDFViewDocLock(mp_view, BToTB(cancel_threads)));
}

inline void PDFView::DocUnlock()
{	
	REX(TRN_PDFViewDocUnlock(mp_view));
}

inline bool PDFView::DocTryLock(int milliseconds)
{
	RetBool(TRN_PDFViewDocTryLock(mp_view, milliseconds, &result));
}

inline void PDFView::DocLockRead()
{
	REX(TRN_PDFViewDocLockRead(mp_view));
}

inline void PDFView::DocUnlockRead()
{
	REX(TRN_PDFViewDocUnlockRead(mp_view));
}
inline bool PDFView::DocTryLockRead(int milliseconds)
{
	RetBool(TRN_PDFViewDocTryLockRead(mp_view, milliseconds, &result));
}

inline PDFView::PageViewMode PDFView::GetPageRefViewMode() const
{
	enum TRN_PDFViewPageViewMode result;
	REX(TRN_PDFViewGetPageRefViewMode(mp_view,&result));
	return (PageViewMode)result;
}

inline void PDFView::RefreshAndUpdate(const ViewChangeCollection& view_change)
{
	REX(TRN_PDFViewRefreshAndUpdate(mp_view,view_change.mp_collection));
}

inline void PDFView::SetPageRefViewMode(PageViewMode mode)
{
	REX(TRN_PDFViewSetPageRefViewMode(mp_view,(enum TRN_PDFViewPageViewMode)mode));
}

inline void PDFView::SetPageViewMode(PageViewMode mode)
{
	REX(TRN_PDFViewSetPageViewMode(mp_view,(enum TRN_PDFViewPageViewMode)mode));
}

inline PDFView::PageViewMode PDFView::GetPageViewMode() const
{
	enum TRN_PDFViewPageViewMode result;
	REX(TRN_PDFViewGetPageViewMode(mp_view,&result));
	return (PageViewMode)result;
}

inline void PDFView::SetPagePresentationMode(PagePresentationMode mode)
{
	REX(TRN_PDFViewSetPagePresentationMode(mp_view,(enum TRN_PDFViewPagePresentationMode)mode));
}

inline PDFView::PagePresentationMode PDFView::GetPagePresentationMode() const
{
	enum TRN_PDFViewPagePresentationMode result;
	REX(TRN_PDFViewGetPagePresentationMode(mp_view,&result));
	return (PagePresentationMode)result;
}

inline void PDFView::SetColorPostProcessMode(PDFRasterizer::ColorPostProcessMode mode)
{
	REX(TRN_PDFViewSetColorPostProcessMode(mp_view,(enum TRN_PDFRasterizerColorPostProcessMode)mode));
}

inline void PDFView::SetColorPostProcessColors(unsigned int white_color, unsigned int black_color)
{
    REX(TRN_PDFViewSetColorPostProcessColors(mp_view, white_color, black_color));
}

inline void PDFView::SetColorPostProcessMapFile(Filters::Filter filter)
{
    filter.m_owner = false;
    REX(TRN_PDFViewSetColorPostProcessMapFile(mp_view, filter.m_impl));
}

inline PDFRasterizer::ColorPostProcessMode PDFView::GetColorPostProcessMode() const
{
	enum TRN_PDFRasterizerColorPostProcessMode result;
	REX(TRN_PDFViewGetColorPostProcessMode(mp_view,&result));
	return (PDFRasterizer::ColorPostProcessMode)result;
}


inline int PDFView::GetCurrentPage() const
{
	RetInt(TRN_PDFViewGetCurrentPage(mp_view,&result));
}



inline int PDFView::GetPageCount() const
{
	RetInt(TRN_PDFViewGetPageCount(mp_view,&result));
}

inline bool PDFView::GotoFirstPage()
{
	RetBool(TRN_PDFViewGotoFirstPage(mp_view,&result));
}

inline bool PDFView::GotoLastPage()
{
	RetBool(TRN_PDFViewGotoLastPage(mp_view,&result));
}

inline bool PDFView::GotoNextPage()
{
	RetBool(TRN_PDFViewGotoNextPage(mp_view,&result));
}

inline bool PDFView::GotoPreviousPage()
{
	RetBool(TRN_PDFViewGotoPreviousPage(mp_view,&result));
}

inline bool PDFView::SetCurrentPage(int page_num)
{
	RetBool(TRN_PDFViewSetCurrentPage(mp_view,page_num,&result));
}

inline bool PDFView::ShowRect( int page_num, const Rect& rect )
{
	RetBool(TRN_PDFViewShowRect( mp_view, page_num, (const TRN_Rect*)(&rect), &result ) );
}

inline double PDFView::GetZoom() const
{
	RetDbl(TRN_PDFViewGetZoom(mp_view,&result));
}

inline bool PDFView::SetZoom(double zoom)
{
	RetBool(TRN_PDFViewSetZoom(mp_view,zoom,&result))
}

inline bool PDFView::SetZoom(int x, int y, double zoom)
{
	RetBool(TRN_PDFViewSetZoomOnPoint(mp_view,x,y,zoom,&result));
}

inline bool PDFView::SmartZoom(int x, int y)
{
	RetBool(TRN_PDFViewSmartZoomOnPoint(mp_view,x,y,&result));
}

inline void PDFView::RotateClockwise()
{
	REX(TRN_PDFViewRotateClockwise(mp_view));
}

inline void PDFView::RotateCounterClockwise()
{
	REX(TRN_PDFViewRotateCounterClockwise(mp_view));
}

inline int PDFView::GetPageNumberFromScreenPt(double x, double y) const
{
	RetInt(TRN_PDFViewGetPageNumberFromScreenPt(mp_view,x,y,&result));
}

inline Point PDFView::ConvScreenPtToCanvasPt(const Point& pt) const
{
	Point result;
	REX(TRN_PDFViewConvScreenPtToCanvasPt(mp_view,(double*)&(pt.x),(double*)&(pt.y)));
	result.x = pt.x;
	result.y = pt.y;
	return result;
}

inline void PDFView::ExecuteAction(Action& action)
{
	TRN_ActionParameter action_param;
	REX(TRN_ActionParameterCreate(action.mp_action, &action_param));
	REX(TRN_PDFViewDoAction(mp_view, action_param));
}

inline void PDFView::ExecuteAction(ActionParameter& action_param)
{
	REX(TRN_PDFViewDoAction(mp_view, action_param.mp_parameter));
}

#ifndef SWIG
inline void PDFView::ConvScreenPtToCanvasPt(double& x, double& y) const
{
	REX(TRN_PDFViewConvScreenPtToCanvasPt(mp_view,&x,&y));
}
#endif

inline Point PDFView::ConvCanvasPtToScreenPt(const Point& pt) const
{
	Point result;
	REX(TRN_PDFViewConvCanvasPtToScreenPt(mp_view,(double*)&(pt.x),(double*)&(pt.y)));
	result.x = pt.x;
	result.y = pt.y;
	return result;
}

#ifndef SWIG
inline void PDFView::ConvCanvasPtToScreenPt(double& x, double& y) const
{
	REX(TRN_PDFViewConvCanvasPtToScreenPt(mp_view,&x,&y));
}
#endif

inline Point PDFView::ConvCanvasPtToPagePt(const Point& pt, int page_num) const
{
	Point result;
	REX(TRN_PDFViewConvCanvasPtToPagePt(mp_view,(double*)&(pt.x),(double*)&(pt.y),page_num));
	result.x = pt.x;
	result.y = pt.y;
	return result;
}

#ifndef SWIG
inline void PDFView::ConvCanvasPtToPagePt(double& x, double& y, int page_num) const
{
	REX(TRN_PDFViewConvCanvasPtToPagePt(mp_view,&x,&y,page_num));
}
#endif

inline Point PDFView::ConvPagePtToCanvasPt(const Point& pt, int page_num) const
{
	Point result;
	REX(TRN_PDFViewConvPagePtToCanvasPt(mp_view,(double*)&(pt.x),(double*)&(pt.y),page_num));
	result.x = pt.x;
	result.y = pt.y;
	return result;
}

#ifndef SWIG
inline void PDFView::ConvPagePtToCanvasPt(double& x, double& y, int page_num) const
{
	REX(TRN_PDFViewConvPagePtToCanvasPt(mp_view,&x,&y,page_num));
}
#endif

inline Point PDFView::ConvScreenPtToPagePt(const Point& pt, int page_num) const
{
	Point result;
	REX(TRN_PDFViewConvScreenPtToPagePt(mp_view,(double*)&(pt.x),(double*)&(pt.y),page_num));
	result.x = pt.x;
	result.y = pt.y;
	return result;
}

#ifndef SWIG
inline void PDFView::ConvScreenPtToPagePt(double& x, double& y, int page_num) const
{
	REX(TRN_PDFViewConvScreenPtToPagePt(mp_view,&x,&y,page_num));
}
#endif

inline Point PDFView::ConvPagePtToScreenPt(const Point& pt, int page_num) const
{
	Point result;
	REX(TRN_PDFViewConvPagePtToScreenPt(mp_view,(double*)&(pt.x),(double*)&(pt.y),page_num));
	result.x = pt.x;
	result.y = pt.y;
	return result;
}

#ifndef SWIG
inline void PDFView::ConvPagePtToScreenPt(double& x, double& y, int page_num) const
{
	REX(TRN_PDFViewConvPagePtToScreenPt(mp_view,&x,&y,page_num));
}
#endif

inline Point PDFView::SnapToNearestInDoc(const Point& screen_pt)
{
	Point result;
	REX(TRN_PDFViewSnapToNearestInDoc(mp_view,(double*)&(screen_pt.x),(double*)&(screen_pt.y)));
	result.x = screen_pt.x;
	result.y = screen_pt.y;
	return result;
}

inline void PDFView::SetSnappingMode(UInt32 mode_flags)
{
	REX(TRN_PDFViewSetSnappingMode(mp_view, mode_flags));
}

inline Common::Matrix2D PDFView::GetDeviceTransform(int page_num) const
{
	RetMtx(TRN_PDFViewGetDeviceTransform(mp_view,page_num,&result));
}

#ifdef SWIG
inline void PDFView::SetErrorReportProc(Callback* instance)
{
	REX(TRN_PDFViewSetErrorReportProc(mp_view,&(Callback::StaticErrorReportProc),instance));
}
#else
inline void PDFView::SetErrorReportProc(PDFRasterizer::ErrorReportProc error_proc, void* data)
{
	REX(TRN_PDFViewSetErrorReportProc(mp_view,error_proc,data));
}
#endif

#ifdef SWIG
inline void PDFView::SetCurrentPageProc(Callback* instance)
{
	REX(TRN_PDFViewSetCurrentPageProc(mp_view,&(Callback::StaticCurrentPageProc),instance));
}
#else
inline void PDFView::SetCurrentPageProc(CurrentPageProc curr_pagenum_proc, void* data)
{
	REX(TRN_PDFViewSetCurrentPageProc(mp_view,curr_pagenum_proc,data));
}
#endif

#ifdef SWIG
inline void PDFView::SetJavaScriptEventCallBack(Callback* instance)
{
	REX(TRN_PDFViewSetJavaScriptEventCallBack(mp_view,&(Callback::StaticJavaScriptEventProc),instance));
}
#else
inline void PDFView::SetJavaScriptEventCallBack(JavaScriptEventProc js_proc, void* data)
{
	REX(TRN_PDFViewSetJavaScriptEventCallBack(mp_view,js_proc,data));
}
#endif

#ifdef SWIG
inline void PDFView::SetCurrentZoomProc(Callback* instance)
{
	REX(TRN_PDFViewSetCurrentZoomProc(mp_view,&(Callback::StaticCurrentZoomProc),instance));
}
#else
inline void PDFView::SetCurrentZoomProc(CurrentZoomProc curr_zoom_proc, void* data)
{
	REX(TRN_PDFViewSetCurrentZoomProc(mp_view,curr_zoom_proc,data));
}
#endif

inline double PDFView::GetCanvasWidth() const
{
	RetDbl(TRN_PDFViewGetCanvasWidth(mp_view,&result));
}

inline double PDFView::GetCanvasHeight() const
{
	RetDbl(TRN_PDFViewGetCanvasHeight(mp_view,&result));
}

inline double PDFView::GetHScrollPos() const
{
	RetDbl(TRN_PDFViewGetHScrollPos(mp_view,&result));
}

inline double PDFView::GetVScrollPos() const
{
	RetDbl(TRN_PDFViewGetVScrollPos(mp_view,&result));
}



inline void PDFView::OnScroll(int pix_dx, int pix_dy)
{
	REX(TRN_PDFViewOnScroll(mp_view,pix_dx,pix_dy));
}

inline void PDFView::SetHScrollPos(double pos)
{
	REX(TRN_PDFViewSetHScrollPos(mp_view,pos));
}

inline void PDFView::SetVScrollPos(double pos)
{
	REX(TRN_PDFViewSetVScrollPos(mp_view,pos));
}

inline void PDFView::OnSize(int width, int height)
{
	REX(TRN_PDFViewOnSize(mp_view,width,height));
}

//inline bool PDFView::IsFinishedRendering() const
//{
//	RetBool(TRN_PDFViewIsFinishedRendering(mp_view, false, &result));
//}

inline bool PDFView::IsFinishedRendering(bool visible_region_only) const
{
	RetBool(TRN_PDFViewIsFinishedRendering(mp_view, visible_region_only, &result));
}

inline void PDFView::CancelRendering()
{
	REX(TRN_PDFViewCancelRendering(mp_view));
}

inline void PDFView::Update(bool all)
{
	REX(TRN_PDFViewUpdate(mp_view, BToTB(all)));
}

inline void PDFView::Update(const Rect& update)
{
	REX(TRN_PDFViewUpdate2(mp_view, (const TRN_Rect*)&update));
}

inline void PDFView::Update(const Annot& annot, int page_num)
{
	REX(TRN_PDFViewUpdate3(mp_view, annot.mp_annot, page_num));
}

inline void PDFView::Update(const Field& field)
{
	REX(TRN_PDFViewUpdateField(mp_view, &field.mp_field));
}

inline void PDFView::UpdatePageLayout()
{
	REX(TRN_PDFViewUpdatePageLayout(mp_view));
}

inline void PDFView::UpdateBuffer()
{
	REX(TRN_PDFViewUpdateBuffer(mp_view));
}

#ifdef SWIG
inline std::vector<unsigned char> PDFView::GetBuffer() const
{
	char* arr;
	int height, stride;
	TRN_PDFViewGetBufferHeight(mp_view,&height);
	TRN_PDFViewGetBufferStride(mp_view,&stride);

	std::vector<unsigned char> result(height * stride);
	TRN_PDFViewGetBuffer(mp_view,(const char**)&arr);
	memcpy(&result[0], arr, height*stride);
	return result;

}
#else
inline const char* PDFView::GetBuffer() const
{
	RetCCS(TRN_PDFViewGetBuffer(mp_view,&result));
}
#endif

inline int PDFView::GetBufferWidth() const
{
	RetInt(TRN_PDFViewGetBufferWidth(mp_view,&result));
}

inline int PDFView::GetBufferHeight() const
{
	RetInt(TRN_PDFViewGetBufferHeight(mp_view,&result));
}

inline int PDFView::GetBufferStride() const
{
	RetInt(TRN_PDFViewGetBufferStride(mp_view,&result));
}

inline void PDFView::HideAnnotation(PDF::Annot annot)
{
	REX(TRN_PDFViewHideAnnotation(mp_view, annot.mp_annot));
}

inline void PDFView::ShowAnnotation(PDF::Annot annot)
{
	REX(TRN_PDFViewShowAnnotation(mp_view, annot.mp_annot));
}

inline void PDFView::SetDrawAnnotations(bool render_annots)
{
	REX(TRN_PDFViewSetDrawAnnotations(mp_view,BToTB(render_annots)));
}

inline void PDFView::SetHighlightFields(bool highlight)
{
	REX(TRN_PDFViewSetHighlightFields(mp_view,BToTB(highlight)));
}

inline void PDFView::SetRequiredFieldBorderColor(const ColorPt& new_border_color)
{
	REX(TRN_PDFViewSetRequiredFieldBorderColor(mp_view, &new_border_color.m_c));
}

inline void PDFView::SetGamma(double exp)
{
	REX(TRN_PDFViewSetGamma(mp_view,exp));
}

inline void PDFView::SetOverprint(PDFRasterizer::OverprintPreviewMode op)
{
	REX(TRN_PDFViewSetOverprint(mp_view, (enum TRN_PDFRasterizerOverprintPreviewMode)(op)));
}

inline void PDFView::SetAntiAliasing(bool enable_aa)
{
	REX(TRN_PDFViewSetAntiAliasing(mp_view,BToTB(enable_aa)));
}

inline void PDFView::SetPathHinting(bool enable_hinting)
{
	REX(TRN_PDFViewSetPathHinting(mp_view, BToTB(enable_hinting)));
}

inline void PDFView::SetThinLineAdjustment(bool pixel_grid_fit, bool stroke_adjust)
{
	REX(TRN_PDFViewSetThinLineAdjustment(mp_view,BToTB(pixel_grid_fit), BToTB(stroke_adjust)));
}

inline void PDFView::SetImageSmoothing(bool smoothing_enabled)
{
	REX(TRN_PDFViewSetImageSmoothing(mp_view,BToTB(smoothing_enabled)));
}

inline void PDFView::SetCaching(bool enabled)
{
	REX(TRN_PDFViewSetCaching(mp_view,BToTB(enabled)));
}

inline void PDFView::SetRasterizerType (PDFRasterizer::Type type)
{
	REX(TRN_PDFViewSetRasterizerType(mp_view,(enum TRN_PDFRasterizerType)type));
}

#ifdef SWIG
inline void PDFView::SetRenderBeginProc(Callback* instance)
{
	REX(TRN_PDFViewSetRenderBeginProc(mp_view, &Callback::StaticRenderBeginEventProc, instance));
}
#else
inline void PDFView::SetRenderBeginProc(RenderBeginEventProc proc, void* data)
{
	REX(TRN_PDFViewSetRenderBeginProc(mp_view,proc,data));
}
#endif

#ifdef SWIG
inline void PDFView::SetRenderFinishProc(Callback* instance)
{
	REX(TRN_PDFViewSetRenderFinishProc(mp_view,(TRN_PDFViewRenderFinishEventProc)&Callback::StaticRenderFinishEventProc, instance));
}
#else
inline void PDFView::SetRenderFinishProc(RenderFinishEventProc proc, void* data)
{
	REX(TRN_PDFViewSetRenderFinishProc(mp_view,(TRN_PDFViewRenderFinishEventProc)proc,data));
}
#endif

inline void PDFView::SetTextSelectionMode(TextSelectionMode tm)
{
	REX(TRN_PDFViewSetTextSelectionMode(mp_view, (enum TRN_PDFViewTextSelectionMode)tm));
}

inline bool PDFView::Select(double x1, double y1, double x2, double y2)
{
	RetBool(TRN_PDFViewSelect(mp_view, x1, y1, x2, y2, &result));
}

inline bool PDFView::SelectWithSnapping(double x1, double y1, double x2, double y2, 
	bool snap_to_start, bool snap_to_end)
{
	RetBool(TRN_PDFViewSelectWithSnapping(mp_view, x1, y1, x2, y2, 
		BToTB(snap_to_start), BToTB(snap_to_end), &result));
}

inline bool PDFView::SelectWithSmartSnapping(double x1, double y1, double x2, double y2)
{
	RetBool(TRN_PDFViewSelectWithSmartSnapping(mp_view, x1, y1, x2, y2, &result));
}

inline bool PDFView::Select(double x1, double y1, int page1, double x2, double y2, int page2)
{
	RetBool(TRN_PDFViewSelectByStruct(mp_view, x1, y1, page1, x2, y2, page2, &result));
}

inline bool PDFView::SelectWithSnapping(double x1, double y1, int page1, double x2, double y2, int page2,
	bool snap_to_start, bool snap_to_end)
{
	RetBool(TRN_PDFViewSelectByStructWithSnapping(mp_view, x1, y1, page1, x2, y2, page2,
		BToTB(snap_to_start), BToTB(snap_to_end), &result));
}

inline bool PDFView::SelectWithSmartSnapping(double x1, double y1, int page1, double x2, double y2, int page2)
{
	RetBool(TRN_PDFViewSelectByStructWithSmartSnapping(mp_view, x1, y1, page1, x2, y2, page2, &result));
}

inline bool PDFView::Select(const Highlights& highlights)
{
	RetBool(TRN_PDFViewSelectByHighlights(mp_view, (highlights.mp_highlights), &result));
}

inline bool PDFView::Select(const Selection& select)
{
	RetBool(TRN_PDFViewSelectBySelection(mp_view, select.mp_selection, &result));
}

inline void PDFView::CancelFindText()
{
	REX(TRN_PDFViewCancelFindText(mp_view));
}

inline void PDFView::SelectAll()
{
	REX(TRN_PDFViewSelectAll(mp_view));
}

inline bool PDFView::HasSelection() const
{
	RetBool(TRN_PDFViewHasSelection(mp_view,&result));
}

inline void PDFView::ClearSelection()
{
	REX(TRN_PDFViewClearSelection(mp_view));
}

inline Selection PDFView::GetSelection( int ipage ) const
{
	TRN_PDFViewSelection result;
	REX(TRN_PDFViewGetSelection(mp_view, ipage, &result));
	return Selection(result);
}

inline int PDFView::GetSelectionBeginPage() const {
	int res = 0;
	REX( TRN_PDFViewGetSelectionBeginPage(mp_view, &res ));
	return res;
}

inline int PDFView::GetSelectionEndPage() const {
	int res = 0;
	REX( TRN_PDFViewGetSelectionEndPage(mp_view, &res ));
	return res;
}

inline void PDFView::PrepareWords(int page_num)
{
	REX(TRN_PDFViewPrepareWords(mp_view, page_num));
}

inline bool PDFView::WereWordsPrepared(int page_num) const
{
	TRN_Bool res = 0;
	REX(TRN_PDFViewWereWordsPrepared(mp_view, page_num, &res));
	return (res != 0);
}

inline bool PDFView::IsThereTextInRect(double x1, double y1, double x2, double y2) const
{
	TRN_Bool res = 0;
	REX(TRN_PDFViewIsThereTextInRect(mp_view, x1, y1, x2, y2, &res));
	return (res != 0);
}

inline void PDFView::PrepareAnnotsForMouse(int page_num, double distance_threshold, double minimum_line_weight)
{
	REX(TRN_PDFViewPrepareAnnotsForMouse(mp_view, page_num, distance_threshold, minimum_line_weight));
}

inline bool PDFView::WereAnnotsForMousePrepared(int page_num) const
{
	TRN_Bool res = 0;
	REX(TRN_PDFViewWereAnnotsForMousePrepared(mp_view, page_num, &res));
	return (res != 0);
}

inline Annot::Type PDFView::GetAnnotTypeUnder(double x, double y)
{
	enum TRN_AnnotType type;
	REX(TRN_PDFViewGetAnnotTypeUnder(mp_view, x, y, &type));
	return (Annot::Type)type;
}

inline bool PDFView::HasSelectionOnPage( int ipage ) const {
	TRN_Bool res = 0;
	REX( TRN_PDFViewHasSelectionOnPage(mp_view, ipage, &res ));
	return (res!=0);
}

inline void PDFView::SetPageBorderVisibility(bool border_visible)
{
	REX(TRN_PDFViewSetPageBorderVisibility(mp_view, BToTB(border_visible)));
}



inline void PDFView::SetPageTransparencyGrid(bool trans_grid_visible)
{
	REX(TRN_PDFViewSetPageTransparencyGrid(mp_view, BToTB(trans_grid_visible)));
}

inline void PDFView::SetDefaultPageColor(UInt8 r, UInt8 g, UInt8 b)
{
	REX(TRN_PDFViewSetDefaultPageColor(mp_view,r,g,b));
}

inline void PDFView::SetBackgroundColor(UInt8 r, UInt8 g, UInt8 b, UInt8 a)
{
	REX(TRN_PDFViewSetBackgroundColor(mp_view,r,g,b,a));
}

inline void PDFView::SetHorizontalAlign(int align)
{
	REX(TRN_PDFViewSetHorizontalAlign(mp_view,align));
}

inline void PDFView::SetVerticalAlign(int align)
{
	REX(TRN_PDFViewSetVerticalAlign(mp_view, align));
}

inline void PDFView::SetPageSpacing(int horiz_col_space, int vert_col_space, int horiz_pad, int vert_pad) 
{
	REX(TRN_PDFViewSetPageSpacing(mp_view, horiz_col_space, vert_col_space, horiz_pad, vert_pad));
}

inline void PDFView::SetViewerCache(SDF::SDFDoc& document, size_t max_cache_size, bool on_disk)
{
	REX(TRN_PDFViewSetViewerCache(document.mp_doc, max_cache_size, on_disk));
}

inline void PDFView::SetOCGContext(const OCG::Context& ctx) 
{
	REX(TRN_PDFViewSetOCGContext(mp_view, ctx.mp_obj));
}

inline OCG::Context PDFView::GetOCGContext() {
	TRN_OCGContext result; 
	REX(TRN_PDFViewGetOCGContext(mp_view, &result));
	return OCG::Context(result);
}

inline void PDFView::UpdateOCGContext()
{
	REX(TRN_PDFViewUpdateOCGContext(mp_view));
}

inline Page::Rotate PDFView::GetRotation() const
{
	enum TRN_PageRotate result;
	REX(TRN_PDFViewGetRotation(mp_view, &result));
	return (Page::Rotate)result;
}

inline void PDFView::SetDevicePixelDensity(double dpi, double scale_factor)
{
	REX(TRN_SetDevicePixelDensity(mp_view, dpi, scale_factor));
}

inline Rect PDFView::GetScreenRectForAnnot(PDF::Annot annot, int page_num /* = -1 */)
{
	Rect result;
	REX(TRN_PDFViewGetScreenRectForAnnot(mp_view, annot.mp_annot, page_num, (TRN_Rect*)&result));
	return result;
}

inline Annot PDFView::GetAnnotationAt(int x, int y, double distanceThreshold, double minimumLineWeight)
{
	TRN_Annot result;
	REX(TRN_PDFViewGetAnnotationAt(mp_view, x, y, distanceThreshold, minimumLineWeight, &result));
	return Annot(result);
}

inline void PDFView::SetUrlExtraction(bool enabled)
{
	REX(TRN_PDFViewSetUrlExtraction(mp_view, BToTB(enabled)));
}

inline LinkInfo PDFView::GetLinkAt(int x, int y)
{
	LinkInfo linkInfo;
	REX(TRN_PDFViewGetLinkAt(mp_view, x, y, (TRN_Rect*)&(linkInfo.rect), (TRN_UString*)&linkInfo.url));
	return linkInfo;
}

inline std::vector<int> PDFView::GetVisiblePages() const
{
	int c = 0;
	int res = 0;
	REX( TRN_PDFViewGetVisiblePageCount(mp_view, &c ));
	std::vector<int> result(c);
	for (int i = 0; i < c; i++)
	{
		REX( TRN_PDFViewGetVisiblePage(mp_view, i, &res ));
		result[i] = res;
	}
	return result;
}

inline void PDFView::EnableUndoRedo()
{
    REX(TRN_PDFViewEnableUndoRedo(mp_view));
}

inline UString PDFView::Undo()
{
    RetStr(TRN_PDFViewUndo(mp_view, &result));
}

inline UString PDFView::Redo()
{
    RetStr(TRN_PDFViewRedo(mp_view, &result));
}

inline void PDFView::TakeSnapshot(const UString& meta_info)
{
    REX(TRN_PDFViewTakeSnapshot(mp_view, meta_info.mp_impl))
}

inline UString PDFView::GetNextUndoInfo()
{
    RetStr(TRN_PDFViewGetNextUndoInfo(mp_view, &result));
}

inline UString PDFView::GetNextRedoInfo()
{
    RetStr(TRN_PDFViewGetNextRedoInfo(mp_view, &result));
}

inline void PDFView::RevertAllChanges()
{
    REX(TRN_PDFViewRevertAllChanges(mp_view));
}

inline ExternalAnnotManager PDFView::GetExternalAnnotManager(const UString& author, ExternalAnnotManager::Mode mode)
{
	TRN_ExternalAnnotManager result;
    REX(TRN_PDFViewGetExternalAnnotManager(mp_view, author.mp_impl, &result, (TRN_PDF_ExternalAnnotManager_Mode)mode));
    return ExternalAnnotManager(result);
}

inline std::vector<Annot> PDFView::GetAnnotationListAt(int x1, int y1, int x2, int y2)
{
	TRN_Vector annots_vec = NULL;
    REX(TRN_PDFViewGetAnnotationListAt(mp_view, x1, y1, x2, y2, (TRN_Vector*)&annots_vec));
    
    TRN_UInt32 annots_vec_size;
    TRN_VectorGetSize(annots_vec, &annots_vec_size);
    
    std::vector<Annot> result;
    for (TRN_UInt32 i = 0; i < annots_vec_size; i++)
    {
        TRN_Annot current_annot = NULL;
        TRN_VectorGetAt(annots_vec, i, (void**)&current_annot);
        result.push_back(Annot(current_annot));
    }
    
    TRN_VectorDestroyKeepContents(annots_vec);
    return result;
}

inline std::vector<Annot> PDFView::GetAnnotationsOnPage(int page_num)
{
    // Broadly similar to PDFDraw::GetSeparationBitmaps implementation
    TRN_Vector annots_vec = NULL;
    REX(TRN_PDFViewGetAnnotationsOnPage(mp_view, page_num, (TRN_Vector*)&annots_vec));
    
    TRN_UInt32 annots_vec_size;
    TRN_VectorGetSize(annots_vec, &annots_vec_size);
    
    std::vector<Annot> result;
    for (TRN_UInt32 i = 0; i < annots_vec_size; i++)
    {
        TRN_Annot current_annot = NULL;
        TRN_VectorGetAt(annots_vec, i, (void**)&current_annot);
        result.push_back(Annot(current_annot));
    }
    
    TRN_VectorDestroyKeepContents(annots_vec);
    return result;
}

#if defined(__iOS__)




inline PDFView::HTTPRequestOptions::HTTPRequestOptions()
{
	m_obj = m_objset.CreateDict().mp_obj;
}

inline void PDFView::HTTPRequestOptions::AddHeader(const UString& header, const UString& val)
{
	TRN_Obj result;
	std::string temp(header.ConvertToUtf8());
	REX(TRN_ObjPutText(m_obj, temp.c_str(), val.mp_impl, &result));
}

inline void PDFView::HTTPRequestOptions::RestrictDownloadUsage(bool restrict)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"MINIMAL_DOWNLOAD", BToTB(restrict), &result));
}

inline void PDFView::HTTPRequestOptions::SkipByteRangeTest(bool skip)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"SKIP_BYTE_RANGE_TEST", BToTB(skip), &result));
}

inline void PDFView::HTTPRequestOptions::UseRemoteFileSize(Int64 size_in_bytes)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"FORCE_REMOTE_SIZE", static_cast<double>(size_in_bytes), &result));
}

inline void PDFView::OpenURLAsync(const char* url, UString cache_file, const char* password, const HTTPRequestOptions* options)
{
	REX(TRN_PDFViewOpenURLAsync(mp_view,url,cache_file.mp_impl,password, (options ? options->m_obj : 0)));
}

inline bool PDFView::DownloaderUpdatePage(TRN_PDFDoc doc, TRN_UInt32 page_num, TRN_UInt32 obj_num)
{
	RetBool(TRN_PDFViewDownloaderUpdatePage(mp_view, doc, page_num, obj_num, &result));
}

inline void PDFView::DownloaderUpdateOutline(TRN_PDFDoc doc)
{
	REX(TRN_PDFViewDownloaderUpdateOutline(mp_view, doc));
}

inline void PDFView::DownloaderUpdateThumb(TRN_PDFDoc doc, TRN_UInt32 page_num, TRN_UInt32 obj_num)
{
	REX(TRN_PDFViewDownloaderUpdateThumb(mp_view, doc, page_num, obj_num));
}

inline void PDFView::DownloaderFinishedDownload(TRN_PDFDoc doc)
{
	REX(TRN_PDFViewDownloaderFinishedDownload(mp_view, doc));
}

inline bool PDFView::DownloaderIsCorrectDoc(TRN_PDFDoc doc)
{
	RetBool(TRN_PDFViewDownloaderIsCorrectDoc(mp_view, doc, &result));
}

inline void PDFView::DownloaderInitialized(TRN_PDFDoc doc)
{
	REX(TRN_PDFViewDownloaderInitialized(mp_view, doc));
}

inline int PDFView::GetCurCanvasId() const
{
	RetInt(TRN_PDFViewGetCurCanvasId(mp_view,&result));
}

inline void PDFView::PopViewingStates(bool restore)
{
	REX(TRN_PDFViewPopViewingStates(mp_view, BToTB(restore)));
}

inline void PDFView::SetFreezeTile(bool freeze)
{
	REX(TRN_PDFViewSetFreezeTile(mp_view, BToTB(freeze)));
}

inline void PDFView::PushViewingStates()
{
	REX(TRN_PDFViewPushViewingStates(mp_view));
}


inline void PDFView::DoProgressiveRender()
{
	REX(TRN_PDFViewDoProgressiveRender(mp_view));
}

inline int PDFView::GetCellSideLength() const
{
	RetInt(TRN_PDFViewGetCellSideLength(mp_view, &result));
}

inline double PDFView::GetPageVGap() const
{
	RetDbl(TRN_PDFViewGetPageVGap(mp_view, &result));
}

inline double PDFView::GetPageHGap() const
{
	RetDbl(TRN_PDFViewGetPageHGap(mp_view, &result));
}

inline void PDFView::RequestRender()
{
	REX(TRN_PDFViewRequestRender(mp_view));
}

inline void PDFView::SetRightToLeftLanguage(bool flag)
{
	REX(TRN_PDFViewSetRightToLeftLanguage(mp_view,BToTB(flag)));
}

#ifdef SWIG

inline void PDFView::SetWrapperAnnotBitmapProc(Callback* instance, PDFView::AnnotVectorMode mode)
{
	REX(TRN_PDFViewSetWrapperAnnotBitmapProc(mp_view, &(Callback::StaticAnnotBitmapProc), instance, (TRN_PDFViewAnnotVectorMode)mode));
}


inline void PDFView::SetWrapperCreateTileProc(Callback* instance)
{
	REX(TRN_PDFViewSetWrapperCreateTileProc(mp_view, &(Callback::StaticCreateTileProc), instance));
}

inline void PDFView::SetWrapperDeluxeCreateTileProc(Callback* instance)
{
	REX(TRN_PDFViewSetWrapperDeluxeCreateTileProc(mp_view, &(Callback::StaticDeluxeCreateTileProc), instance));
}

inline void PDFView::SetWrapperRemoveTileProc(Callback* instance)
{
	REX(TRN_PDFViewSetWrapperRemoveTileProc(mp_view, &(Callback::StaticRemoveTileProc), instance));
}

inline void PDFView::SetPartDownloadedProc(Callback* instance)
{
	REX(TRN_PDFViewSetPartDownloadedProc(mp_view, (TRN_PDFViewPartDownloadedProc) &(Callback::StaticPartDownloadedProc), instance));
}

#else // SWIG

inline void PDFView::SetWrapperAnnotBitmapProc(PDFView::AnnotBitmapProc wrapperAnnotBitmapProc, void* callingObject, PDFView::AnnotVectorMode mode)
{
	REX(TRN_PDFViewSetWrapperAnnotBitmapProc(mp_view, wrapperAnnotBitmapProc, callingObject, (TRN_PDFViewAnnotVectorMode)mode));
}

inline void PDFView::SetWrapperCreateTileProc(PDFView::CreateTileProc wrapperCreateTileProc, void* callingObject)
{
	REX(TRN_PDFViewSetWrapperCreateTileProc(mp_view, wrapperCreateTileProc, callingObject));
}

inline void PDFView::SetWrapperDeluxeCreateTileProc(PDFView::DeluxeCreateTileProc wrapperDeluxeCreateTileProc, void* callingObject)
{
	REX(TRN_PDFViewSetWrapperDeluxeCreateTileProc(mp_view, wrapperDeluxeCreateTileProc, callingObject));
}

inline void PDFView::SetWrapperRemoveTileProc(PDFView::RemoveTileProc wrapperRemoveTileProc, void* callingObject)
{
	REX(TRN_PDFViewSetWrapperRemoveTileProc(mp_view, wrapperRemoveTileProc, callingObject));
}

inline void PDFView::SetPartDownloadedProc(PartDownloadedProc proc, void* user_data)
{
	REX(TRN_PDFViewSetPartDownloadedProc(mp_view, (TRN_PDFViewPartDownloadedProc)proc, user_data));
}

#endif // SWIG

inline void PDFView::GetPageRects(const Rect& rect, std::vector<double>& page_rects_info) const
{
	int size;
	REX(TRN_PDFViewGetPageRects(mp_view, &rect, 0, &size));
	page_rects_info.resize(size);
	REX(TRN_PDFViewGetPageRects(mp_view, &rect, &page_rects_info.front(), &size));
}

inline void PDFView::GetPageRectsOnCanvas(std::vector<double>& page_rects_info, int canvasNumber) const
{
	int size;
	REX(TRN_PDFViewGetPageRectsOnCanvas(mp_view, 0, canvasNumber, &size));
	page_rects_info.resize(size);
	REX(TRN_PDFViewGetPageRectsOnCanvas(mp_view, &page_rects_info.front(), canvasNumber, &size));
}

inline double PDFView::GetRefZoomForPage(PDFView::PageViewMode viewMode, int pageNum) const
{

	RetDbl(TRN_PDFViewGetRefZoomForPage(mp_view, (enum TRN_PDFViewPageViewMode)viewMode, pageNum, &result));
}

inline void PDFView::PurgeMemory()
{
	REX(TRN_PDFViewPurgeMemory(mp_view));
}

inline void PDFView::SetMemInfo(double total_mem, double mem_cap)
{
	REX(TRN_PDFViewSetMemInfo(mp_view, total_mem, mem_cap));
}

#endif //__iOS__

inline void PDFView::OpenUniversalDoc(DocumentConversion& conv)
{
	REX(TRN_OpenUniversalDoc(mp_view, conv.m_impl));
}

inline void PDFView::SetupThumbnails(bool use_embedded, bool generate_at_runtime, bool use_disk_cache, int thumb_max_side_length, size_t max_abs_cache_size, double max_perc_cache_size)
{
	REX(TRN_PDFViewSetupThumbnails(mp_view, BToTB(use_embedded), BToTB(generate_at_runtime), BToTB(use_disk_cache), thumb_max_side_length, max_abs_cache_size, max_perc_cache_size));
}

#ifdef SWIG

inline void PDFView::GetThumbAsync(int page_num, Callback* instance)
{
	REX(TRN_PDFViewGetThumbAsync(mp_view, page_num, (TRN_PDFViewThumbAsyncHandler)Callback::StaticThumbAsyncHandler, (void*)instance));
}

#else // SWIG

inline void PDFView::GetThumbAsync(int page_num, ThumbAsyncHandler thumb_async_handler, void* custom_data)
{
	REX(TRN_PDFViewGetThumbAsync(mp_view, page_num, (TRN_PDFViewThumbAsyncHandler)thumb_async_handler, custom_data));
}

#endif // SWIG

inline size_t PDFView::GetThumbInCacheSize(int page_num)
{
	size_t result;
	REX(TRN_PDFViewGetThumbInCacheSize(mp_view,page_num,&result));
	return result;
}

inline bool PDFView::GetThumbInCache(int page_num, UChar* buf, UInt32& out_width, UInt32& out_height)
{
	RetBool(TRN_PDFViewGetThumbInCache(mp_view,page_num,buf,&out_width,&out_height,&result));
}

inline void PDFView::ClearThumbCache()
{
	REX(TRN_PDFViewClearThumbCache(mp_view));
}

#ifdef SWIG

inline void PDFView::SetRequestRenderInWorkerThreadProc(Callback* instance)
{
	REX(TRN_PDFViewSetRequestRenderinWorkerThreadProc(mp_view,
		(TRN_PDFViewRequestRenderInWorkerThreadProc)Callback::StaticRequestRenderInWorkerThread,instance));
}

#else // SWIG

inline void PDFView::SetRequestRenderInWorkerThreadProc(RequestRenderInWorkerThreadProc proc, void* custom_data)
{
	REX(TRN_PDFViewSetRequestRenderinWorkerThreadProc(mp_view, (TRN_PDFViewRequestRenderInWorkerThreadProc)proc, custom_data));
}

#endif // SWIG

inline void PDFView::CancelAllThumbRequests()
{
	REX(TRN_PDFViewCancelAllThumbRequests(mp_view));
}

inline void PDFView::FindTextAsync(const UString& search_str, bool match_case, bool match_whole_word, bool search_up, bool reg_exp)
{
	REX(TRN_PDFViewFindTextAsync(mp_view, search_str.mp_impl, match_case, match_whole_word, search_up, reg_exp));
}

#ifdef SWIG

inline void PDFView::SetFindTextHandler(Callback* instance)
{
	REX(TRN_PDFViewSetFindTextHandler(mp_view, StaticTRNPDFViewFindTextHandler, instance));
}

#else // SWIG

inline void PDFView::SetFindTextHandler(FindTextHandler proc, void* custom_data)
{
	mp_findtexthandler = proc;
    mp_findtextdata = custom_data;
	REX(TRN_PDFViewSetFindTextHandler(mp_view, StaticTRNPDFViewFindTextHandler, this));
}

#endif // SWIG

inline void PDFView::StaticTRNPDFViewFindTextHandler(TRN_Bool success, TRN_PDFViewSelection selection, void* custom_data)
{
	if (custom_data == NULL)
		return;
#if defined(SWIG) && !defined(__iOS__)
    Callback::StaticFindTextHandler(TBToB(success), PDF::Selection(selection), custom_data);
#else // SWIG
    PDFView* view = (PDFView*) custom_data;
	if (view->mp_findtexthandler != NULL) {
		view->mp_findtexthandler(TBToB(success), PDF::Selection(selection), view->mp_findtextdata);
	}
#endif // SWIG
}
