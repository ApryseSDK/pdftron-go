inline PDFViewCtrl::PDFViewCtrl(void* parent_hwnd, void* hinstance, bool compatibility) :	m_findtext_proc(0), m_findtext_data(0)
{
	REX(TRN_PDFViewCtrlCreate(parent_hwnd, hinstance, compatibility, &mp_view));
}

inline PDFViewCtrl::~PDFViewCtrl()
{
	DREX(mp_view, TRN_PDFViewCtrlDestroy(mp_view));
}

inline bool PDFViewCtrl::SetDoc(PDFDoc& doc, const char* password)
{
	RetBool(TRN_PDFViewCtrlSetDocWithPassword(mp_view,doc.mp_doc,password, &result));
}

inline void PDFViewCtrl::CloseDoc()
{
    REX(TRN_PDFViewCtrlCloseDoc(mp_view));
}

inline PDFDoc* PDFViewCtrl::GetDoc()
{
	REX(TRN_PDFViewCtrlGetDoc(mp_view,&temp_doc));
	if(temp_doc)
		return ((PDFDoc*)&temp_doc);
	else
		return 0;
}

inline void PDFViewCtrl::DocLock(bool cancel_threads)
{
	REX(TRN_PDFViewCtrlDocLock(mp_view, BToTB(cancel_threads)));
}

inline void PDFViewCtrl::DocUnlock()
{	
	REX(TRN_PDFViewCtrlDocUnlock(mp_view));
}

inline bool PDFViewCtrl::DocTryLock(int milliseconds)
{
	RetBool(TRN_PDFViewCtrlDocTryLock(mp_view, milliseconds, &result));
}

inline void PDFViewCtrl::DocLockRead()
{
	REX(TRN_PDFViewCtrlDocLockRead(mp_view));
}

inline void PDFViewCtrl::DocUnlockRead()
{
	REX(TRN_PDFViewCtrlDocUnlockRead(mp_view));
}
inline bool PDFViewCtrl::DocTryLockRead(int milliseconds)
{
	RetBool(TRN_PDFViewCtrlDocTryLockRead(mp_view, milliseconds, &result));
}

inline void PDFViewCtrl::SetPageViewMode(PageViewMode mode)
{
	REX(TRN_PDFViewCtrlSetPageViewMode(mp_view,(enum TRN_PDFViewCtrlPageViewMode)mode));
}

inline PDFViewCtrl::PageViewMode PDFViewCtrl::GetPageViewMode() const
{
	enum TRN_PDFViewCtrlPageViewMode result;
	REX(TRN_PDFViewCtrlGetPageViewMode(mp_view,&result));
	return (PageViewMode)result;
}

inline void PDFViewCtrl::SetPagePresentationMode(PagePresentationMode mode)
{
	REX(TRN_PDFViewCtrlSetPagePresentationMode(mp_view,(enum TRN_PDFViewCtrlPagePresentationMode)mode));
}

inline PDFViewCtrl::PagePresentationMode PDFViewCtrl::GetPagePresentationMode() const
{
	enum TRN_PDFViewCtrlPagePresentationMode result;
	REX(TRN_PDFViewCtrlGetPagePresentationMode(mp_view,&result));
	return (PagePresentationMode)result;
}

inline void PDFViewCtrl::SetColorPostProcessMode(PDFRasterizer::ColorPostProcessMode mode)
{
	REX(TRN_PDFViewCtrlSetColorPostProcessMode(mp_view,(enum TRN_PDFRasterizerColorPostProcessMode)mode));
}

inline PDFRasterizer::ColorPostProcessMode PDFViewCtrl::GetColorPostProcessMode() const
{
	enum TRN_PDFRasterizerColorPostProcessMode result;
	REX(TRN_PDFViewCtrlGetColorPostProcessMode(mp_view,&result));
	return (PDFRasterizer::ColorPostProcessMode)result;
}

inline int PDFViewCtrl::GetCurrentPage() const
{
	RetInt(TRN_PDFViewCtrlGetCurrentPage(mp_view,&result));
}

inline int PDFViewCtrl::GetPageCount() const
{
	RetInt(TRN_PDFViewCtrlGetPageCount(mp_view,&result));
}

inline std::vector<int> PDFViewCtrl::GetVisiblePages() const
{
	int c = 0;
	int res = 0;
	REX( TRN_PDFViewCtrlGetVisiblePageCount(mp_view, &c ));
	//int c = GetVisiblePageCount();
	std::vector<int> result(c);
	for (int i = 0; i < c; i++)
	{
		REX( TRN_PDFViewCtrlGetVisiblePage(mp_view, i, &res ));
		result[i] = res;
	}
	return result;
}

inline bool PDFViewCtrl::GotoFirstPage()
{
	RetBool(TRN_PDFViewCtrlGotoFirstPage(mp_view,&result));
}

inline bool PDFViewCtrl::GotoLastPage()
{
	RetBool(TRN_PDFViewCtrlGotoLastPage(mp_view,&result));
}

inline bool PDFViewCtrl::GotoNextPage()
{
	RetBool(TRN_PDFViewCtrlGotoNextPage(mp_view,&result));
}

inline bool PDFViewCtrl::GotoPreviousPage()
{
	RetBool(TRN_PDFViewCtrlGotoPreviousPage(mp_view,&result));
}

inline bool PDFViewCtrl::SetCurrentPage(int page_num)
{
	RetBool(TRN_PDFViewCtrlSetCurrentPage(mp_view,page_num,&result));
}

inline bool PDFViewCtrl::ShowRect( int page_num, const Rect& rect )
{
	RetBool(TRN_PDFViewCtrlShowRect( mp_view, page_num, (const TRN_Rect*)(&rect), &result ) );
}

inline double PDFViewCtrl::GetZoom() const
{
	RetDbl(TRN_PDFViewCtrlGetZoom(mp_view,&result));
}

inline bool PDFViewCtrl::SetZoom(double zoom)
{
	RetBool(TRN_PDFViewCtrlSetZoom(mp_view,zoom,&result))
}

inline bool PDFViewCtrl::SetZoom(int x, int y, double zoom)
{
	RetBool(TRN_PDFViewCtrlSetZoomOnPoint(mp_view,x,y,zoom,&result));
}

inline bool PDFViewCtrl::SmartZoom(int x, int y)
{
	RetBool(TRN_PDFViewCtrlSmartZoomOnPoint(mp_view,x,y,&result));
}

inline void PDFViewCtrl::RotateClockwise()
{
	REX(TRN_PDFViewCtrlRotateClockwise(mp_view));
}

inline void PDFViewCtrl::RotateCounterClockwise()
{
	REX(TRN_PDFViewCtrlRotateCounterClockwise(mp_view));
}

inline int PDFViewCtrl::GetPageNumberFromScreenPt(double x, double y) const
{
	RetInt(TRN_PDFViewCtrlGetPageNumberFromScreenPt(mp_view,x,y,&result));
}

inline void PDFViewCtrl::ConvScreenPtToCanvasPt(double& x, double& y) const
{
	REX(TRN_PDFViewCtrlConvScreenPtToCanvasPt(mp_view,&x,&y));
}

inline void PDFViewCtrl::ConvCanvasPtToScreenPt(double& x, double& y) const
{
	REX(TRN_PDFViewCtrlConvCanvasPtToScreenPt(mp_view,&x,&y));
}

inline void PDFViewCtrl::ConvCanvasPtToPagePt(double& x, double& y, int page_num) const
{
	REX(TRN_PDFViewCtrlConvCanvasPtToPagePt(mp_view,&x,&y,page_num));
}

inline void PDFViewCtrl::ConvPagePtToCanvasPt(double& x, double& y, int page_num) const
{
	REX(TRN_PDFViewCtrlConvPagePtToCanvasPt(mp_view,&x,&y,page_num));
}

inline void PDFViewCtrl::ConvScreenPtToPagePt(double& x, double& y, int page_num) const
{
	REX(TRN_PDFViewCtrlConvScreenPtToPagePt(mp_view,&x,&y,page_num));
}

inline void PDFViewCtrl::ConvPagePtToScreenPt(double& x, double& y, int page_num) const
{
	REX(TRN_PDFViewCtrlConvPagePtToScreenPt(mp_view,&x,&y,page_num));
}

inline void PDFViewCtrl::SnapToNearestInDoc(double& screen_x, double& screen_y)
{
	REX(TRN_PDFViewCtrlSnapToNearestInDoc(mp_view, &screen_x, &screen_y));
}

inline void PDFViewCtrl::SetSnappingMode(UInt32 mode_flags)
{
	REX(TRN_PDFViewCtrlSetSnappingMode(mp_view, mode_flags));
}

inline Common::Matrix2D PDFViewCtrl::GetDeviceTransform(int page_num) const
{
	RetMtx(TRN_PDFViewCtrlGetDeviceTransform(mp_view,page_num,&result));
}

inline void PDFViewCtrl::SetErrorReportHandler(ErrorReportHandler error_proc, void* data)
{
	REX(TRN_PDFViewCtrlSetErrorReportHandler(mp_view,error_proc,data));
}

inline void PDFViewCtrl::SetCurrentPageHandler(CurrentPageHandler curr_pagenum_proc, void* data)
{
	REX(TRN_PDFViewCtrlSetCurrentPageHandler(mp_view,curr_pagenum_proc,data));
}

inline void PDFViewCtrl::SetCurrentZoomHandler(CurrentZoomHandler curr_zoom_proc, void* data)
{
	REX(TRN_PDFViewCtrlSetCurrentZoomHandler(mp_view,curr_zoom_proc,data));
}

inline double PDFViewCtrl::GetCanvasWidth() const
{
	RetDbl(TRN_PDFViewCtrlGetCanvasWidth(mp_view,&result));
}

inline double PDFViewCtrl::GetCanvasHeight() const
{
	RetDbl(TRN_PDFViewCtrlGetCanvasHeight(mp_view,&result));
}

inline double PDFViewCtrl::GetHScrollPos() const
{
	RetDbl(TRN_PDFViewCtrlGetHScrollPos(mp_view,&result));
}

inline double PDFViewCtrl::GetVScrollPos() const
{
	RetDbl(TRN_PDFViewCtrlGetVScrollPos(mp_view,&result));
}

inline void PDFViewCtrl::OnScroll(int pix_dx, int pix_dy)
{
	REX(TRN_PDFViewCtrlOnScroll(mp_view,pix_dx,pix_dy));
}

inline void PDFViewCtrl::SetHScrollPos(double pos)
{
	REX(TRN_PDFViewCtrlSetHScrollPos(mp_view,pos));
}

inline void PDFViewCtrl::SetVScrollPos(double pos)
{
	REX(TRN_PDFViewCtrlSetVScrollPos(mp_view,pos));
}


inline bool PDFViewCtrl::IsFinishedRendering(bool visible_region_only) const
{
	RetBool(TRN_PDFViewCtrlIsFinishedRendering(mp_view, visible_region_only, &result));
}

inline void PDFViewCtrl::CancelRendering()
{
	REX(TRN_PDFViewCtrlCancelRendering(mp_view));
}

inline void PDFViewCtrl::Update(bool all)
{
	REX(TRN_PDFViewCtrlUpdate(mp_view, BToTB(all)));
}

inline void PDFViewCtrl::Update(const Rect& update)
{
	REX(TRN_PDFViewCtrlUpdate2(mp_view, (const TRN_Rect*)&update));
}

inline void PDFViewCtrl::Update(const Annot& annot, int page_num)
{
	REX(TRN_PDFViewCtrlUpdate3(mp_view, annot.mp_annot, page_num));
}

inline void PDFViewCtrl::Update(const Field& field)
{
	REX(TRN_PDFViewCtrlUpdateField(mp_view, &field.mp_field));
}

inline void PDFViewCtrl::UpdatePageLayout()
{
	REX(TRN_PDFViewCtrlUpdatePageLayout(mp_view));
}

inline void PDFViewCtrl::HideAnnotation(const Annot& annot)
{
	REX(TRN_PDFViewCtrlHideAnnotation(mp_view, annot.mp_annot));
}

inline void PDFViewCtrl::ShowAnnotation(const Annot& annot)
{
	REX(TRN_PDFViewCtrlShowAnnotation(mp_view, annot.mp_annot));
}

inline void PDFViewCtrl::SetDrawAnnotations(bool render_annots)
{
	REX(TRN_PDFViewCtrlSetDrawAnnotations(mp_view,BToTB(render_annots)));
}

inline void PDFViewCtrl::SetHighlightFields(bool highlight)
{
	REX(TRN_PDFViewCtrlSetHighlightFields(mp_view,BToTB(highlight)));
}

inline void PDFViewCtrl::SetRequiredFieldBorderColor(const ColorPt& new_border_color)
{
	REX(TRN_PDFViewCtrlSetRequiredFieldBorderColor(mp_view, &new_border_color.m_c));
}

inline void PDFViewCtrl::SetGamma(double exp)
{
	REX(TRN_PDFViewCtrlSetGamma(mp_view,exp));
}

inline void PDFViewCtrl::SetOverprint(PDFRasterizer::OverprintPreviewMode op)
{
	REX(TRN_PDFViewCtrlSetOverprint(mp_view, (enum TRN_PDFRasterizerOverprintPreviewMode)(op)));
}

inline void PDFViewCtrl::SetAntiAliasing(bool enable_aa)
{
	REX(TRN_PDFViewCtrlSetAntiAliasing(mp_view,BToTB(enable_aa)));
}

inline void PDFViewCtrl::SetPathHinting(bool enable_hinting)
{
	REX(TRN_PDFViewCtrlSetPathHinting(mp_view, BToTB(enable_hinting)));
}

inline void PDFViewCtrl::SetThinLineAdjustment(bool pixel_grid_fit, bool stroke_adjust)
{
	REX(TRN_PDFViewCtrlSetThinLineAdjustment(mp_view,BToTB(pixel_grid_fit), BToTB(stroke_adjust)));
}

inline void PDFViewCtrl::SetImageSmoothing(bool smoothing_enabled)
{
	REX(TRN_PDFViewCtrlSetImageSmoothing(mp_view,BToTB(smoothing_enabled)));
}

inline void PDFViewCtrl::SetCaching(bool enabled)
{
	REX(TRN_PDFViewCtrlSetCaching(mp_view,BToTB(enabled)));
}

inline void PDFViewCtrl::SetRasterizerType (PDFRasterizer::Type type)
{
	REX(TRN_PDFViewCtrlSetRasterizerType(mp_view,(enum TRN_PDFRasterizerType)type));
}

inline void PDFViewCtrl::SetToolMode(ToolMode mode)
{
	REX(TRN_PDFViewCtrlSetToolMode(mp_view,(enum TRN_PDFViewCtrlToolMode)mode));
}

inline PDFViewCtrl::ToolMode PDFViewCtrl::GetToolMode() const
{
	enum TRN_PDFViewCtrlToolMode result;
	REX(TRN_PDFViewCtrlGetToolMode(mp_view,&result));
	return (ToolMode)result;
}

inline void PDFViewCtrl::SetTextSelectionMode(TextSelectionMode tm)
{
	REX(TRN_PDFViewCtrlSetTextSelectionMode(mp_view, (enum TRN_PDFViewCtrlTextSelectionMode)tm));
}

inline bool PDFViewCtrl::Select(double x1, double y1, double x2, double y2)
{
	RetBool(TRN_PDFViewCtrlSelect(mp_view, x1, y1, x2, y2, &result));
}

inline bool PDFViewCtrl::SelectWithSnapping(double x1, double y1, double x2, double y2, bool snap_to_start, bool snap_to_end)
{
	RetBool(TRN_PDFViewCtrlSelectWithSnapping(mp_view, x1, y1, x2, y2, BToTB(snap_to_start), BToTB(snap_to_end), &result));
}

inline bool PDFViewCtrl::SelectWithSmartSnapping(double x1, double y1, double x2, double y2)
{
	RetBool(TRN_PDFViewCtrlSelectWithSmartSnapping(mp_view, x1, y1, x2, y2, &result));
}

inline bool PDFViewCtrl::Select(double x1, double y1, int page1, double x2, double y2, int page2)
{
	RetBool(TRN_PDFViewCtrlSelectByStruct(mp_view, x1, y1, page1, x2, y2, page2, &result));
}

inline bool PDFViewCtrl::SelectWithSnapping(double x1, double y1, int page1, double x2, double y2, int page2, bool snap_to_start, bool snap_to_end)
{
	RetBool(TRN_PDFViewCtrlSelectByStructWithSnapping(mp_view, x1, y1, page1, x2, y2, page2, BToTB(snap_to_start), BToTB(snap_to_end), &result));
}

inline bool PDFViewCtrl::SelectWithSmartSnapping(double x1, double y1, int page1, double x2, double y2, int page2)
{
	RetBool(TRN_PDFViewCtrlSelectByStructWithSmartSnapping(mp_view, x1, y1, page1, x2, y2, page2, &result));
}

inline bool PDFViewCtrl::Select(const Highlights& highlights)
{
	RetBool(TRN_PDFViewCtrlSelectByHighlights(mp_view, (highlights.mp_highlights), &result));
}

inline bool PDFViewCtrl::Select(const Selection& select)
{
	RetBool(TRN_PDFViewCtrlSelectBySelection(mp_view, select.mp_selection, &result));
}

inline void PDFViewCtrl::SelectAll()
{
	REX(TRN_PDFViewCtrlSelectAll(mp_view));
}

inline bool PDFViewCtrl::HasSelection() const
{
	RetBool(TRN_PDFViewCtrlHasSelection(mp_view,&result));
}

inline void PDFViewCtrl::ClearSelection()
{
	REX(TRN_PDFViewCtrlClearSelection(mp_view));
}

inline Selection PDFViewCtrl::GetSelection( int ipage ) const
{
	TRN_PDFViewSelection result;
	REX(TRN_PDFViewCtrlGetSelection(mp_view, ipage, &result));
	return Selection(result);
}


inline int PDFViewCtrl::GetSelectionBeginPage() const {
	int res = 0;
	REX( TRN_PDFViewCtrlGetSelectionBeginPage(mp_view, &res ));
	return res;
}

inline int PDFViewCtrl::GetSelectionEndPage() const {
	int res = 0;
	REX( TRN_PDFViewCtrlGetSelectionEndPage(mp_view, &res ));
	return res;
}

inline void PDFViewCtrl::PrepareWords(int page_num)
{
	REX(TRN_PDFViewCtrlPrepareWords(mp_view, page_num));
}

inline bool PDFViewCtrl::WereWordsPrepared(int page_num) const
{
	RetBool(TRN_PDFViewCtrlWereWordsPrepared(mp_view, page_num, &result));
}

inline bool PDFViewCtrl::IsThereTextInRect(double x1, double y1, double x2, double y2) const
{
	RetBool(TRN_PDFViewCtrlIsThereTextInRect(mp_view, x1, y1, x2, y2, &result));
}

inline void PDFViewCtrl::PrepareAnnotsForMouse(int page_num, double distance_threshold, double minimum_line_weight)
{
	REX(TRN_PDFViewCtrlPrepareAnnotsForMouse(mp_view, page_num, distance_threshold, minimum_line_weight));
}

inline bool PDFViewCtrl::WereAnnotsForMousePrepared(int page_num) const
{
	RetBool(TRN_PDFViewCtrlWereAnnotsForMousePrepared(mp_view, page_num, &result));
}

inline Annot::Type PDFViewCtrl::GetAnnotTypeUnder(double x, double y)
{
	enum TRN_AnnotType type;
	REX(TRN_PDFViewCtrlGetAnnotTypeUnder(mp_view, x, y, &type));
	return (Annot::Type)type;
}

inline bool PDFViewCtrl::HasSelectionOnPage( int ipage ) const 
{
	TRN_Bool res = 0;
	REX( TRN_PDFViewCtrlHasSelectionOnPage(mp_view, ipage, &res ));
	return (res!=0);
}

inline void PDFViewCtrl::SetPageBorderVisibility(bool border_visible)
{
	REX(TRN_PDFViewCtrlSetPageBorderVisibility(mp_view, BToTB(border_visible)));
}

inline void PDFViewCtrl::SetPageTransparencyGrid(bool trans_grid_visible)
{
	REX(TRN_PDFViewCtrlSetPageTransparencyGrid(mp_view, BToTB(trans_grid_visible)));
}

inline void PDFViewCtrl::SetDefaultPageColor(UInt8 r, UInt8 g, UInt8 b)
{
	REX(TRN_PDFViewCtrlSetDefaultPageColor(mp_view,r,g,b));
}

inline void PDFViewCtrl::SetBackgroundColor(UInt8 r, UInt8 g, UInt8 b)
{
	REX(TRN_PDFViewCtrlSetBackgroundColor(mp_view,r,g,b));
}

inline void PDFViewCtrl::SetHorizontalAlign(int align)
{
	REX(TRN_PDFViewCtrlSetHorizontalAlign(mp_view,align));
}

inline void PDFViewCtrl::SetVerticalAlign(int align)
{
	REX(TRN_PDFViewCtrlSetVerticalAlign(mp_view, align));
}

inline void PDFViewCtrl::SetPageSpacing(int horiz_col_space, int vert_col_space, int horiz_pad, int vert_pad) 
{
	REX(TRN_PDFViewCtrlSetPageSpacing(mp_view, horiz_col_space, vert_col_space, horiz_pad, vert_pad));
}

inline void PDFViewCtrl::SetOCGContext(const OCG::Context& ctx) 
{
	REX(TRN_PDFViewCtrlSetOCGContext(mp_view, ctx.mp_obj));
}

inline OCG::Context PDFViewCtrl::GetOCGContext() {
	TRN_OCGContext result; 
	REX(TRN_PDFViewCtrlGetOCGContext(mp_view, &result));
	return OCG::Context(result);
}

inline void PDFViewCtrl::OnSize(int x, int y, int width, int height)
{
	REX(TRN_PDFViewCtrlOnChangeRect(mp_view,x,y,width,height));
}

inline void PDFViewCtrl::SetProgressiveRendering(bool progressive)
{
	REX(TRN_PDFViewCtrlSetProgressiveRendering(mp_view,BToTB(progressive)))
}
inline void PDFViewCtrl::ShowNavPanel(bool show)
{
	REX(TRN_PDFViewCtrlShowNavPanel(mp_view,BToTB(show)));
}

inline bool PDFViewCtrl::IsNavPanelVisible() const
{
	RetBool(TRN_PDFViewCtrlIsNavPanelVisible(mp_view,&result))
}

inline void PDFViewCtrl::EnableScrollbar( bool show )
{
	REX(TRN_PDFViewCtrlEnableScrollbar(mp_view,show));
}

inline void PDFViewCtrl::ShowToolbar( bool show )
{
	REX(TRN_PDFViewCtrlShowToolbar(mp_view,show));
}


inline void PDFViewCtrl::ShowStatusBar( bool show)
{
	REX(TRN_PDFViewCtrlShowStatusBar(mp_view,show));
}


inline void PDFViewCtrl::ShowNavToolbar( bool show )
{
	REX(TRN_PDFViewCtrlShowNavToolbar(mp_view,show));
}

inline void PDFViewCtrl::ShowMenuBar( bool show )
{
	REX(TRN_PDFViewCtrlShowMenuBar(mp_view,show));
}

inline void PDFViewCtrl::Copy()
{
	REX(TRN_PDFViewCtrlCopy(mp_view));
}

inline void PDFViewCtrl::EnableInteractiveForms(bool on)
{
	REX(TRN_PDFViewCtrlEnableInteractiveForms(mp_view, BToTB(on)));
}

inline void PDFViewCtrl::ShowDialogs(bool show)
{
	REX(TRN_PDFViewCtrlShowDialogs(mp_view,BToTB(show)));
}

inline Page::Rotate PDFViewCtrl::GetRotation() const
{
	enum TRN_PageRotate result;
	REX(TRN_PDFViewCtrlGetRotation(mp_view,&result));
	return (Page::Rotate)result;
}

inline Rect PDFViewCtrl::GetScreenRectForAnnot(Annot annot, int page_num)
{
	Rect result;
	REX(TRN_PDFViewCtrlGetScreenRectForAnnot(mp_view, annot.mp_annot, page_num, (TRN_Rect*)&result));
	return result;
}

inline Annot PDFViewCtrl::GetAnnotationAt(int x, int y)
{
	TRN_Annot result;
	REX(TRN_PDFViewCtrlGetAnnotationAt(mp_view, x, y, &result));
	return Annot(result);
}

inline void PDFViewCtrl::SetUrlExtraction(bool enabled)
{
	REX(TRN_PDFViewCtrlSetUrlExtraction(mp_view, BToTB(enabled)));
}

inline LinkInfo PDFViewCtrl::GetLinkAt(int x, int y)
{
	LinkInfo linkInfo;
	REX(TRN_PDFViewCtrlGetLinkAt(mp_view, x, y, (TRN_Rect*)&(linkInfo.rect), (TRN_UString*)&linkInfo.url));
	return linkInfo;
}

inline void PDFViewCtrl::SetEnabledPanels(UInt32 panels)
{
	REX(TRN_PDFViewCtrlSetEnabledPanels(mp_view,panels));
}

inline UInt32 PDFViewCtrl::GetEnabledPanels() const
{
	TRN_UInt32 result;
	REX(TRN_PDFViewCtrlGetEnabledPanels(mp_view, &result));
	return result;
}

inline void PDFViewCtrl::SetSelectedPanel(PanelType panel)
{
	REX(TRN_PDFViewCtrlSetSelectedPanel(mp_view,(enum TRN_PDFViewCtrlPanelType)panel));
}


inline PDFViewCtrl::PanelType PDFViewCtrl::GetSelectedPanel() const
{
	enum TRN_PDFViewCtrlPanelType result;
	REX(TRN_PDFViewCtrlGetSelectedPanel(mp_view,&result));
	return (PDFViewCtrl::PanelType)result;
}


inline void PDFViewCtrl::SetSplitPosition(int pos)
{
	REX(TRN_PDFViewCtrlSetSplitPosition(mp_view,pos));
}


inline int PDFViewCtrl::GetSplitPosition() const
{
	RetInt(TRN_PDFViewCtrlGetSplitPosition(mp_view,&result));
}


inline void PDFViewCtrl::Print()
{
	REX(TRN_PDFViewCtrlPrintDialog(mp_view));
}


inline void PDFViewCtrl::Print(int first_page, int last_page, Page::Rotate rotation, 
		   int copies, const char* printer_name)
{
	REX(TRN_PDFViewCtrlPrint(mp_view,first_page,last_page,(enum TRN_PageRotate)rotation,
		copies,printer_name));
}

inline void PDFViewCtrl::Print(int first_page, int last_page, Page::Rotate rotation, 
							   int copies, const UString& printer_name)
{
	REX(TRN_PDFViewCtrlPrintUStr(mp_view,first_page,last_page,(enum TRN_PageRotate)rotation,
		copies,printer_name.mp_impl));
}

inline void PDFViewCtrl::SetCustomEventHandlers( PDFViewCtrl::EventHandlers* handlers ) {
	REX(TRN_PDFViewCtrlSetCustomEventHandlers(mp_view, (TRN_PDFViewCtrlEventHandlers*)handlers));
}

inline void PDFViewCtrl::SetActionHandler( ActionHandler action_callback, void* custom_data )  {
	REX(TRN_PDFViewCtrlSetActionHandler( mp_view, action_callback, custom_data ) );
}

inline int PDFViewCtrl::GetViewWidth() const
{
	RetInt(TRN_PDFViewCtrlGetViewWidth(mp_view, &result));
}

inline int PDFViewCtrl::GetViewHeight() const
{
	RetInt(TRN_PDFViewCtrlGetViewHeight(mp_view, &result));	
}

inline void PDFViewCtrl::Find()
{
	REX(TRN_PDFViewCtrlFind(mp_view));
}

inline void PDFViewCtrl::Refresh()
{
	REX(TRN_PDFViewCtrlRefresh(mp_view));
}


inline void PDFViewCtrl::RequestRendering()
{
	REX(TRN_PDFViewCtrlRequestRender(mp_view));
}

inline void PDFViewCtrl::CaptureMouse()
{
	REX(TRN_PDFViewCtrlCaptureMouse(mp_view));
}

inline void PDFViewCtrl::ReleaseMouse()
{
	REX(TRN_PDFViewCtrlReleaseMouse(mp_view));
}

inline bool PDFViewCtrl::HasCapture() const
{
	RetBool(TRN_PDFViewCtrlHasCapture(mp_view,&result))
}

inline void PDFViewCtrl::EnableLinkActivation(bool enable)
{
	REX(TRN_PDFViewCtrlEnableLinkActivation(mp_view,BToTB(enable)));
}

inline 	void  PDFViewCtrl::LoadCurrentConfiguration( const UString & path )
{
	REX( TRN_PDFViewCtrlLoadCurrentConfiguration(mp_view, path.mp_impl ) );
}


inline 	void  PDFViewCtrl::SaveCurrentConfiguration( const UString & path, Common::ProgressMonitor* progress ) 
{
	REX( TRN_PDFViewCtrlSaveCurrentConfiguration(mp_view, path.mp_impl, 0 ) );
}

inline 	Annot  PDFViewCtrl::GetDefaultAnnotation( const char* type ) 
{
	TRN_Annot an;
	REX( TRN_PDFViewCtrlGetDefaultAnnotation(mp_view,type, &an ));
	return an;
}

inline void PDFViewCtrl::SetWindowBackgroundColor( PDFViewCtrl::WindowID winid, const ColorPt& color )
{
	REX( TRN_PDFViewCtrlSetWindowBackgroundColor(mp_view, (TRN_PDFViewCtrlWindowID)winid, (TRN_ColorPt*)(&color) ));
}
#ifdef WIN32
inline void PDFViewCtrl::SetWindowCursor( PDFViewCtrl::WindowID winid, HCURSOR cursor )
{
	REX( TRN_PDFViewCtrlSetWindowCursor(mp_view, (TRN_PDFViewCtrlWindowID)winid, (void*)cursor ));
}
#endif

inline 	void  PDFViewCtrl::SetFocus() 
{
	REX( TRN_PDFViewCtrlSetFocus(mp_view) );
}

inline void PDFViewCtrl::DocProperties() 
{
	REX( TRN_PDFViewCtrlDocProperties(mp_view) );
}


inline void PDFViewCtrl::DeletePages() 
{
	REX( TRN_PDFViewCtrlDeletePages(mp_view) );
}

inline void PDFViewCtrl::InsertBlankPages() 
{
	REX( TRN_PDFViewCtrlInsertBlankPages(mp_view) );
}

inline void PDFViewCtrl::InsertPages(const UString& src_name) 
{
	REX( TRN_PDFViewCtrlInsertPages(mp_view, src_name.mp_impl) );
}

inline void PDFViewCtrl::ReplacePages(const UString& src_name) 
{
	REX( TRN_PDFViewCtrlReplacePages(mp_view, src_name.mp_impl) );
}

inline void PDFViewCtrl::RotatePages() 
{
	REX( TRN_PDFViewCtrlRotatePages(mp_view) );
}

inline void PDFViewCtrl::ExtractPages() 
{
	REX( TRN_PDFViewCtrlExtractPages(mp_view) );
}

inline void PDFViewCtrl::CropPages() 
{
	REX( TRN_PDFViewCtrlCropPages(mp_view) );
}

inline void PDFViewCtrl::AddWatermark() 
{
	REX( TRN_PDFViewCtrlAddWatermark(mp_view) );
}

inline PDFViewCtrl::EventHandlers::EventHandlers() 
{
	memset(this, 0, sizeof(EventHandlers));
}

inline void PDFViewCtrl::SetDownloadReportHandler(DownloadReportHandler download_proc, void* data)
{
	TRN_PDFViewPartDownloadedProc p = (TRN_PDFViewPartDownloadedProc)download_proc;
	REX(TRN_PDFViewCtrlSetDownloadReportHandler(mp_view,p,data));
}

inline void PDFViewCtrl::OpenURLAsync(const char* url, UString cache_file, const char* password, const HTTPRequestOptions* options)
{
	REX(TRN_PDFViewCtrlOpenURLAsync(mp_view,url,cache_file.mp_impl,password, (options ? options->m_obj : 0)));
}

inline void PDFViewCtrl::SetupThumbnails(bool use_embedded, bool generate_at_runtime, bool use_disk_cache, int thumb_max_side_length, size_t max_abs_cache_size, double max_perc_cache_size)
{
	REX(TRN_PDFViewCtrlSetupThumbnails(mp_view, BToTB(use_embedded), BToTB(generate_at_runtime), BToTB(use_disk_cache), thumb_max_side_length, max_abs_cache_size, max_perc_cache_size));
}

inline void PDFViewCtrl::ClearThumbCache()
{
	REX(TRN_PDFViewCtrlClearThumbCache(mp_view));
}

inline void PDFViewCtrl::GetThumbAsync(int page_num, ThumbAsyncHandler thumb_async_handler, void* custom_data)
{
	REX(TRN_PDFViewCtrlGetThumbAsync(mp_view, page_num, (TRN_PDFViewThumbAsyncHandler)thumb_async_handler, custom_data));
}

inline void PDFViewCtrl::CancelAllThumbRequests()
{
	REX(TRN_PDFViewCtrlCancelAllThumbRequests(mp_view));
}

#ifdef SWIG
inline void PDFViewCtrl::SetRequestRenderInWorkerThreadProc(Callback* instance)
{
	REX(TRN_PDFViewCtrlSetRequestRenderinWorkerThreadProc(mp_view,
		(TRN_PDFViewCtrlRequestRenderInWorkerThreadProc)Callback::StaticRequestRenderInWorkerThread,instance));
}
#else
inline void PDFViewCtrl::SetRequestRenderInWorkerThreadProc(RequestRenderInWorkerThreadProc proc, void* custom_data)
{
	REX(TRN_PDFViewCtrlSetRequestRenderinWorkerThreadProc(mp_view, (TRN_PDFViewRequestRenderInWorkerThreadProc)proc, custom_data));
}
#endif // SWIG

inline void PDFViewCtrl::FindTextAsync(const UString& search_str, bool match_case, bool match_whole_word, bool search_up, bool reg_exp)
{
	REX(TRN_PDFViewCtrlFindTextAsync(mp_view, search_str.mp_impl, match_case, match_whole_word, search_up, reg_exp));
}

#ifdef SWIG
inline void PDFViewCtrl::SetFindTextHandler(Callback * instance)
{
	REX(TRN_PDFViewCtrlSetFindTextHandler(mp_view, Callback::StaticFindTextProc(), instance);
}
#else
inline void PDFViewCtrl::SetFindTextHandler(FindTextAsyncHandler proc, void * custom_data)
{
	m_findtext_proc = proc;
	m_findtext_data = custom_data;
	REX(TRN_PDFViewCtrlSetFindTextHandler(mp_view, (TRN_PDFViewFindTextAsyncHandler)NativeFindTextHandler, this));
}

inline void PDFViewCtrl::NativeFindTextHandler(unsigned char success, TRN_PDFViewSelection select, void * custom_data)
{
	PDFViewCtrl * self = (PDFViewCtrl*) custom_data;
	Selection wrapped_sel(select);
	if (self->m_findtext_proc)
		self->m_findtext_proc( 0 != success, wrapped_sel, self->m_findtext_data);
}
#endif // SWIG

inline HTTPRequestOptions::HTTPRequestOptions()
{
	m_obj = m_objset.CreateDict().mp_obj;
}

inline void HTTPRequestOptions::AddHeader(const UString& header, const UString& val)
{
	TRN_Obj result;
	std::string temp(header.ConvertToUtf8());
	REX(TRN_ObjPutText(m_obj, temp.c_str(), val.mp_impl, &result));
}
