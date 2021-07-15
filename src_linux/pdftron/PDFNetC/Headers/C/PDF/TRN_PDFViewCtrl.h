//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFViewCtrl
#define PDFTRON_H_CPDFPDFViewCtrl

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_PDFView.h>
#include <C/PDF/TRN_Page.h>
#include <C/PDF/TRN_Annot.h>

TRN_API TRN_PDFViewCtrlCreate(void* hwnd, void* hinstance, TRN_Bool compatibility, TRN_PDFViewCtrl* result);
TRN_API TRN_PDFViewCtrlDestroy(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlSetDoc(TRN_PDFViewCtrl view,  TRN_PDFDoc doc, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlCloseDoc(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlSetDocWithPassword(TRN_PDFViewCtrl view, TRN_PDFDoc doc, const char* password, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlGetDoc(TRN_PDFViewCtrl view, TRN_PDFDoc* result);

TRN_API TRN_PDFViewCtrlDocLock(TRN_PDFViewCtrl view, TRN_Bool cancel);
TRN_API TRN_PDFViewCtrlDocUnlock(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlDocTryLock(TRN_PDFViewCtrl view, int milliseconds, TRN_Bool* result);

TRN_API TRN_PDFViewCtrlDocLockRead(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlDocUnlockRead(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlDocTryLockRead(TRN_PDFViewCtrl view, int milliseconds, TRN_Bool* result);

enum TRN_PDFViewCtrlPageViewMode
{
	e_PDFViewCtrl_fit_page = 0,
	e_PDFViewCtrl_fit_width,
	e_PDFViewCtrl_fit_height,
	e_PDFViewCtrl_zoom
};

TRN_API TRN_PDFViewCtrlSetPageViewMode(TRN_PDFViewCtrl view,  enum TRN_PDFViewCtrlPageViewMode mode);
TRN_API TRN_PDFViewCtrlGetPageViewMode( const TRN_PDFViewCtrl view, enum TRN_PDFViewCtrlPageViewMode* result);

enum TRN_PDFViewCtrlPagePresentationMode
{
	e_PDFViewCtrl_single_page = 1,
	e_PDFViewCtrl_single_continuous,
	e_PDFViewCtrl_facing,
	e_PDFViewCtrl_facing_continuous,
	e_PDFViewCtrl_facing_cover,
	e_PDFViewCtrl_facing_continuous_cover
};

TRN_API TRN_PDFViewCtrlSetPagePresentationMode(TRN_PDFViewCtrl view,  enum TRN_PDFViewCtrlPagePresentationMode mode);
TRN_API TRN_PDFViewCtrlGetPagePresentationMode( const TRN_PDFViewCtrl view,  enum TRN_PDFViewCtrlPagePresentationMode* result);
TRN_API TRN_PDFViewCtrlGetCurrentPage( const TRN_PDFViewCtrl view,  int* result);
TRN_API TRN_PDFViewCtrlGetPageCount( const TRN_PDFViewCtrl view,  int* result);
TRN_API TRN_PDFViewCtrlGetVisiblePageCount( const TRN_PDFViewCtrl view,  int* result);
TRN_API TRN_PDFViewCtrlGetVisiblePage( const TRN_PDFViewCtrl view, int idx, int* result);
TRN_API TRN_PDFViewCtrlGotoFirstPage(TRN_PDFViewCtrl view,  TRN_Bool* result);
TRN_API TRN_PDFViewCtrlGotoLastPage(TRN_PDFViewCtrl view, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlGotoNextPage(TRN_PDFViewCtrl view, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlGotoPreviousPage(TRN_PDFViewCtrl view, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSetCurrentPage(TRN_PDFViewCtrl view,  int page_num, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlShowRect( TRN_PDFViewCtrl view, int page_num, const TRN_Rect* rect, TRN_Bool* result );
TRN_API TRN_PDFViewCtrlGetZoom( const TRN_PDFViewCtrl view, double* result);
TRN_API TRN_PDFViewCtrlSetZoom(TRN_PDFViewCtrl view,  double zoom, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSetZoomOnPoint(TRN_PDFViewCtrl view,  int x, int y, double zoom, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSmartZoomOnPoint(TRN_PDFViewCtrl view,  int x, int y,  TRN_Bool* result);
TRN_API TRN_PDFViewCtrlRotateClockwise(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlRotateCounterClockwise(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlGetPageNumberFromScreenPt( const TRN_PDFViewCtrl view,  double x, double y, int* result);
TRN_API TRN_PDFViewCtrlConvScreenPtToCanvasPt( const TRN_PDFViewCtrl view,  double* x, double* y);
TRN_API TRN_PDFViewCtrlConvCanvasPtToScreenPt( const TRN_PDFViewCtrl view,  double* x, double* y);
TRN_API TRN_PDFViewCtrlConvCanvasPtToPagePt( const TRN_PDFViewCtrl view,  double* x, double* y, int page_num);
TRN_API TRN_PDFViewCtrlConvPagePtToCanvasPt( const TRN_PDFViewCtrl view,  double* x, double* y, int page_num);
TRN_API TRN_PDFViewCtrlConvScreenPtToPagePt( const TRN_PDFViewCtrl view,  double* x, double* y, int page_num);
TRN_API TRN_PDFViewCtrlConvPagePtToScreenPt( const TRN_PDFViewCtrl view,  double* x, double* y, int page_num);
TRN_API TRN_PDFViewCtrlSnapToNearestInDoc(TRN_PDFViewCtrl view, double* screen_x, double* screen_y);
TRN_API TRN_PDFViewCtrlSetSnappingMode(TRN_PDFViewCtrl view, unsigned int mode_flags);

TRN_API TRN_PDFViewCtrlGetDeviceTransform( const TRN_PDFViewCtrl view,  int page_num, TRN_Matrix2D* result);

typedef void (*TRN_PDFViewCtrlErrorReportHandler) (const char* message, void* data);

TRN_API TRN_PDFViewCtrlSetErrorReportHandler(TRN_PDFViewCtrl view,  TRN_PDFViewCtrlErrorReportHandler error_proc, void* data);

typedef void (*TRN_PDFViewCtrlCurrentPageHandler) (int current_page, int num_pages, void* data);

TRN_API TRN_PDFViewCtrlSetCurrentPageHandler(TRN_PDFViewCtrl view,  TRN_PDFViewCtrlCurrentPageHandler curr_pagenum_proc, void* data);

typedef void (*TRN_PDFViewCtrlCurrentZoomHandler) (double current_zoom, void* data);

TRN_API TRN_PDFViewCtrlSetCurrentZoomHandler(TRN_PDFViewCtrl view,  TRN_PDFViewCtrlCurrentZoomHandler curr_zoom_proc, void* data);

TRN_API TRN_PDFViewCtrlGetCanvasWidth( const TRN_PDFViewCtrl view, double* result);
TRN_API TRN_PDFViewCtrlGetCanvasHeight( const TRN_PDFViewCtrl view, double* result);
TRN_API TRN_PDFViewCtrlGetHScrollPos( const TRN_PDFViewCtrl view, double* result);
TRN_API TRN_PDFViewCtrlGetVScrollPos( const TRN_PDFViewCtrl view, double* result);
TRN_API TRN_PDFViewCtrlOnScroll(TRN_PDFViewCtrl view,  int pix_dx, int pix_dy);
TRN_API TRN_PDFViewCtrlSetHScrollPos(TRN_PDFViewCtrl view,  double pos);
TRN_API TRN_PDFViewCtrlSetVScrollPos(TRN_PDFViewCtrl view,  double pos);
TRN_API TRN_PDFViewCtrlIsFinishedRendering( const TRN_PDFViewCtrl view, TRN_Bool visible_region_only, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlCancelRendering(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlUpdate(TRN_PDFViewCtrl view, TRN_Bool all);
TRN_API TRN_PDFViewCtrlUpdate2(TRN_PDFViewCtrl view, const TRN_Rect* rect);
TRN_API TRN_PDFViewCtrlUpdate3(TRN_PDFViewCtrl view, TRN_Annot annot, int num_page);
TRN_API TRN_PDFViewCtrlUpdateField(TRN_PDFViewCtrl view, const TRN_Field* field);
TRN_API TRN_PDFViewCtrlUpdatePageLayout(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlHideAnnotation(TRN_PDFViewCtrl view, TRN_Annot annot);
TRN_API TRN_PDFViewCtrlShowAnnotation(TRN_PDFViewCtrl view, TRN_Annot annot);
TRN_API TRN_PDFViewCtrlSetDrawAnnotations(TRN_PDFViewCtrl view,  TRN_Bool render_annots);
TRN_API TRN_PDFViewCtrlSetHighlightFields(TRN_PDFViewCtrl view,  TRN_Bool highlight);
TRN_API TRN_PDFViewCtrlSetRequiredFieldBorderColor(TRN_PDFViewCtrl view, const TRN_ColorPt* col);
TRN_API TRN_PDFViewCtrlSetGamma(TRN_PDFViewCtrl view, double gamma);
TRN_API TRN_PDFViewCtrlSetOverprint(TRN_PDFViewCtrl view, enum TRN_PDFRasterizerOverprintPreviewMode op);
TRN_API TRN_PDFViewCtrlSetAntiAliasing(TRN_PDFViewCtrl view,  TRN_Bool enable_aa);
TRN_API TRN_PDFViewCtrlSetPathHinting(TRN_PDFViewCtrl view, TRN_Bool enable_hinting);
TRN_API TRN_PDFViewCtrlSetThinLineAdjustment(TRN_PDFViewCtrl view,  TRN_Bool grid_fit, TRN_Bool stroke_adjust);
TRN_API TRN_PDFViewCtrlSetImageSmoothing(TRN_PDFViewCtrl view,  TRN_Bool smoothing_enabled);
TRN_API TRN_PDFViewCtrlSetCaching(TRN_PDFViewCtrl view,  TRN_Bool enabled);
TRN_API TRN_PDFViewCtrlSetRasterizerType (TRN_PDFViewCtrl view,  enum TRN_PDFRasterizerType type);
TRN_API TRN_PDFViewCtrlGetScreenRectForAnnot(const TRN_PDFViewCtrl view, TRN_Annot annot, int page_num, TRN_Rect* result);
TRN_API TRN_PDFViewCtrlGetAnnotationAt(const TRN_PDFViewCtrl view, int x, int, TRN_Annot* result);

TRN_API TRN_PDFViewCtrlSetUrlExtraction(const TRN_PDFViewCtrl view, TRN_Bool enabled);
TRN_API TRN_PDFViewCtrlGetLinkAt(const TRN_PDFViewCtrl view, int x, int y, TRN_Rect* rect, TRN_UString* url);

enum TRN_PDFViewCtrlToolMode
{
	e_PDFViewCtrl_custom,
	e_PDFViewCtrl_pan,
	e_PDFViewCtrl_text_rect_select,
	e_PDFViewCtrl_text_struct_select,
	e_PDFViewCtrl_zoom_in,
	e_PDFViewCtrl_zoom_out,
	e_PDFViewCtrl_annot_edit,
	e_PDFViewCtrl_line_create,
	e_PDFViewCtrl_arrow_create,
	e_PDFViewCtrl_rect_create,
	e_PDFViewCtrl_oval_create,
	e_PDFViewCtrl_ink_create,
	e_PDFViewCtrl_text_annot_create,
	e_PDFViewCtrl_stamp_create,
	e_PDFViewCtrl_highlight_create,
	e_PDFViewCtrl_underline_create,
	e_PDFViewCtrl_strikeout_create,
	e_PDFViewCtrl_squiggly_create,
	e_PDFViewCtrl_text_box_create,
	e_PDFViewCtrl_calloutbox_create,
	e_PDFViewCtrl_polygon_create,
	e_PDFViewCtrl_polyline_create,
	e_PDFViewCtrl_file_attachment,
	e_PDFViewCtrl_sound_attachment,
	e_PDFViewCtrl_movie_attachment,
	e_PDFViewCtrl_caret_create,
	e_PDFViewCtrl_redaction_create,
	e_PDFViewCtrl_text_field_create,
	e_PDFViewCtrl_check_box_create,
	e_PDFViewCtrl_radio_button_create,
	e_PDFViewCtrl_list_box_create,
	e_PDFViewCtrl_combo_box_create,
	e_PDFViewCtrl_button_create,
	e_PDFViewCtrl_link_create
};

TRN_API TRN_PDFViewCtrlSetToolMode(TRN_PDFViewCtrl view,  enum TRN_PDFViewCtrlToolMode mode);
TRN_API TRN_PDFViewCtrlGetToolMode( const TRN_PDFViewCtrl view, enum TRN_PDFViewCtrlToolMode* result);

enum TRN_PDFViewCtrlTextSelectionMode
{
	e_PDFViewCtrl_structural,
	e_PDFViewCtrl_rectangular
};

TRN_API TRN_PDFViewCtrlSetTextSelectionMode(TRN_PDFViewCtrl view, enum TRN_PDFViewCtrlTextSelectionMode tm);
TRN_API TRN_PDFViewCtrlSelect(TRN_PDFViewCtrl view,  double x1, double y1, double x2, double y2, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSelectWithSnapping(TRN_PDFViewCtrl view, double x1, double y1, double x2, double y2, 
	TRN_Bool snap_to_start, TRN_Bool snap_to_end, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSelectWithSmartSnapping(TRN_PDFViewCtrl view, double x1, double y1, double x2, double y2, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSelectByStruct(TRN_PDFViewCtrl view, double x1, double y1, int page1, double x2, double y2, int page2, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSelectByStructWithSnapping(TRN_PDFViewCtrl view, double x1, double y1, int page1, double x2, double y2, int page2, 
	TRN_Bool snap_to_start, TRN_Bool snap_to_end, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSelectByStructWithSmartSnapping(TRN_PDFViewCtrl view, double x1, double y1, int page1, 
	double x2, double y2, int page2, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSelectByHighlights(TRN_PDFViewCtrl view,  TRN_Highlights h, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlSelectBySelection(TRN_PDFViewCtrl view, TRN_PDFViewSelection s, TRN_Bool* result);

TRN_API TRN_PDFViewCtrlHasSelection(const TRN_PDFViewCtrl view, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlClearSelection(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlGetSelection(const TRN_PDFViewCtrl view, int pagenum, TRN_PDFViewSelection* result);
TRN_API TRN_PDFViewCtrlGetSelectionBeginPage(const TRN_PDFViewCtrl view, int * result );
TRN_API TRN_PDFViewCtrlGetSelectionEndPage(const TRN_PDFViewCtrl view, int * result );
TRN_API TRN_PDFViewCtrlHasSelectionOnPage(const TRN_PDFViewCtrl view, int pagenum, TRN_Bool * result );

TRN_API TRN_PDFViewCtrlPrepareWords(const TRN_PDFViewCtrl view, int page_num);
TRN_API TRN_PDFViewCtrlWereWordsPrepared(const TRN_PDFViewCtrl view, int page_num, TRN_Bool * result);
TRN_API TRN_PDFViewCtrlIsThereTextInRect(const TRN_PDFViewCtrl view, double x1, double y1, double x2, double y2, TRN_Bool * result);
TRN_API TRN_PDFViewCtrlPrepareAnnotsForMouse(const TRN_PDFViewCtrl view, int page_num, double distance_threshold, double minimum_line_weight);
TRN_API TRN_PDFViewCtrlWereAnnotsForMousePrepared(const TRN_PDFViewCtrl view, int page_num, TRN_Bool * result);
TRN_API TRN_PDFViewCtrlGetAnnotTypeUnder(const TRN_PDFViewCtrl view, double x, double y, enum TRN_AnnotType * result);

TRN_API TRN_PDFViewCtrlSetPageBorderVisibility(TRN_PDFViewCtrl view, TRN_Bool border_visible);
TRN_API TRN_PDFViewCtrlSetPageTransparencyGrid(TRN_PDFViewCtrl view, TRN_Bool trans_grid_visible);
TRN_API TRN_PDFViewCtrlSetDefaultPageColor(TRN_PDFViewCtrl view, TRN_UInt8 r, TRN_UInt8 g, TRN_UInt8 b);
TRN_API TRN_PDFViewCtrlSetBackgroundColor(TRN_PDFViewCtrl view, TRN_UInt8 r, TRN_UInt8 g, TRN_UInt8 b);
TRN_API TRN_PDFViewCtrlSetHorizontalAlign(TRN_PDFViewCtrl view, int align);
TRN_API TRN_PDFViewCtrlSetVerticalAlign(TRN_PDFViewCtrl view, int align);
TRN_API TRN_PDFViewCtrlSetPageSpacing(TRN_PDFViewCtrl view, int horiz_col_space, int vert_col_space, int horiz_pad, int vert_pad);

TRN_API TRN_PDFViewCtrlSetOCGContext(TRN_PDFViewCtrl view, TRN_OCGContext ctx);
TRN_API TRN_PDFViewCtrlGetOCGContext(TRN_PDFViewCtrl view, TRN_OCGContext* result);

TRN_API TRN_PDFViewCtrlSetProgressiveRendering(TRN_PDFViewCtrl view, TRN_Bool progressive);
TRN_API TRN_PDFViewCtrlShowNavPanel(TRN_PDFViewCtrl view, TRN_Bool show);
TRN_API TRN_PDFViewCtrlIsNavPanelVisible(TRN_PDFViewCtrl view, TRN_Bool* result);

TRN_API TRN_PDFViewCtrlCopy(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlSelectAll(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlEnableInteractiveForms(TRN_PDFViewCtrl view, TRN_Bool on);
TRN_API TRN_PDFViewCtrlShowDialogs(TRN_PDFViewCtrl view, TRN_Bool show);
TRN_API TRN_PDFViewCtrlGetRotation( const TRN_PDFViewCtrl view, enum TRN_PageRotate* result);

TRN_API TRN_PDFViewCtrlSetSplitPosition(TRN_PDFViewCtrl view, int pos);
TRN_API TRN_PDFViewCtrlGetSplitPosition( const TRN_PDFViewCtrl view, int* result);

enum TRN_PDFViewCtrlPanelType
{
	e_PDFViewCtrl_none=0x00,
	e_PDFViewCtrl_bookmarks=0x01,
	e_PDFViewCtrl_layers=0x02,
	e_PDFViewCtrl_thumbview=0x04,
	e_PDFViewCtrl_all=0x07
};

TRN_API TRN_PDFViewCtrlSetEnabledPanels(TRN_PDFViewCtrl view, TRN_UInt32 panels);
TRN_API TRN_PDFViewCtrlGetEnabledPanels( const TRN_PDFViewCtrl view, TRN_UInt32* result);

TRN_API TRN_PDFViewCtrlSetSelectedPanel(TRN_PDFViewCtrl view, enum TRN_PDFViewCtrlPanelType panel);
TRN_API TRN_PDFViewCtrlGetSelectedPanel( const TRN_PDFViewCtrl view, enum TRN_PDFViewCtrlPanelType* result);

TRN_API TRN_PDFViewCtrlEnableScrollbar( TRN_PDFViewCtrl view, TRN_Bool show );
TRN_API TRN_PDFViewCtrlShowToolbar( TRN_PDFViewCtrl view, TRN_Bool show );
TRN_API TRN_PDFViewCtrlShowNavToolbar( TRN_PDFViewCtrl view, TRN_Bool show );
TRN_API TRN_PDFViewCtrlShowStatusBar( TRN_PDFViewCtrl view, TRN_Bool show );
TRN_API TRN_PDFViewCtrlShowMenuBar( TRN_PDFViewCtrl view, TRN_Bool show );

TRN_API TRN_PDFViewCtrlPrintDialog(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlPrint(TRN_PDFViewCtrl view, int first_page, int last_page, enum TRN_PageRotate rotation, int copies, const char* printer_name);
TRN_API TRN_PDFViewCtrlPrintUStr(TRN_PDFViewCtrl view, int first_page, int last_page, enum TRN_PageRotate rotation, int copies, const TRN_UString printer_name);


// ===========================================================================================
enum TRN_PDFViewCtrlWindowID {
	e_PDFViewCtrl_main_view,
	e_PDFViewCtrl_thumb_view,
	e_PDFViewCtrl_layers_view,
	e_PDFViewCtrl_bookmark_view,
	e_PDFViewCtrl_navigation_pane,
	e_PDFViewCtrl_navigation_toolbar,
	e_PDFViewCtrl_toolbar,
	e_PDFViewCtrl_status_bar,
	e_PDFViewCtrl_dialog_modal,
	e_PDFViewCtrl_dialog_modeless
};

enum TRN_PDFViewCtrlEventType {
	e_PDFViewCtrl_mouse_move,
	e_PDFViewCtrl_mouse_enter,
	e_PDFViewCtrl_mouse_leave,
	e_PDFViewCtrl_mouse_left_down,
	e_PDFViewCtrl_mouse_left_up,
	e_PDFViewCtrl_mouse_left_dclick,
	e_PDFViewCtrl_mouse_right_down,
	e_PDFViewCtrl_mouse_right_up,
	e_PDFViewCtrl_mouse_right_dclick,
	e_PDFViewCtrl_mouse_middle_down,
	e_PDFViewCtrl_mouse_middle_up,
	e_PDFViewCtrl_mouse_middle_dclick,
	e_PDFViewCtrl_mouse_wheel,
	e_PDFViewCtrl_context_menu,
	e_PDFViewCtrl_key_down,
	e_PDFViewCtrl_key_up,
	e_PDFViewCtrl_key_press,
	e_PDFViewCtrl_paint,
	e_PDFViewCtrl_window_open,
	e_PDFViewCtrl_window_close
};


struct TRN_PDFViewCtrlMouseEvent {
	int				m_x;
	int				m_y;
	int             m_wheelRotation;
	int             m_wheelDelta;
	int             m_linesPerAction;
	TRN_Bool        m_leftDown;
	TRN_Bool        m_middleDown;
	TRN_Bool        m_rightDown;
	TRN_Bool        m_controlDown;
	TRN_Bool        m_shiftDown;
	TRN_Bool        m_altDown;
	TRN_Bool        m_metaDown;
    enum TRN_PDFViewCtrlEventType m_event_type;
	// identifies which window emitted the event
	enum TRN_PDFViewCtrlWindowID m_event_window;
	// if TRUE, this event was emitted after PDFViewCtrl has processed it
	TRN_Bool        m_pdfviewctrl_processed;
};

struct TRN_PDFViewCtrlKeyEvent {
	int				m_x;
	int				m_y;
	long int        m_keyCode;
	TRN_Unicode		m_unicode;
	TRN_Bool        m_controlDown;
	TRN_Bool        m_shiftDown;
	TRN_Bool        m_altDown;
	TRN_Bool        m_metaDown;
    enum TRN_PDFViewCtrlEventType m_event_type;
	enum TRN_PDFViewCtrlWindowID m_event_window;
	TRN_Bool        m_pdfviewctrl_processed;
};

struct TRN_PDFViewCtrlPaintEvent {
	// platform-dependent device context pointer
	void*              m_hdc;
	enum TRN_PDFViewCtrlWindowID m_event_window;
	TRN_Bool           m_pdfviewctrl_processed;
};

struct TRN_PDFViewCtrlSizeEvent {
	int m_width;
	int m_height;
	int m_x_position;
	int m_y_position;
	enum TRN_PDFViewCtrlWindowID m_event_window;
};

struct TRN_PDFViewCtrlWindowEvent {
	enum TRN_PDFViewCtrlEventType m_event_type;
	enum TRN_PDFViewCtrlWindowID m_event_window;
};

struct TRN_PDFViewCtrlTextFindDoneEvent {
	TRN_Bool m_found;
	enum TRN_PDFViewCtrlEventType m_event_type;
	enum TRN_PDFViewCtrlWindowID m_event_window;
};

struct TRN_PDFViewCtrlAnnotationEditPermissionEvent {
	TRN_Annot m_annot;
	enum TRN_PDFViewCtrlEventType m_event_type;
	enum TRN_PDFViewCtrlWindowID m_event_window;
};

// handlers for generic event signals emitted by PDFViewCtrl;
// if return value is true, and the handler was called before and PDFViewCtrl processing
// took place, PDFViewCtrl will not do any further processing of the event.
typedef TRN_Bool (*TRN_PDFViewCtrlMouseEventHandler) ( struct TRN_PDFViewCtrlMouseEvent* evt, void* custom_data);
typedef TRN_Bool (*TRN_PDFViewCtrlKeyEventHandler)   ( struct TRN_PDFViewCtrlKeyEvent*   evt, void* custom_data);
typedef TRN_Bool (*TRN_PDFViewCtrlPaintEventHandler) ( struct TRN_PDFViewCtrlPaintEvent* evt, void* custom_data);
typedef TRN_Bool (*TRN_PDFViewCtrlSizeEventHandler)  ( struct TRN_PDFViewCtrlSizeEvent*  evt, void* custom_data);
typedef TRN_Bool (*TRN_PDFViewCtrlWindowEventHandler)( struct TRN_PDFViewCtrlWindowEvent* evt, void* custom_data);
typedef TRN_Bool (*TRN_PDFViewCtrlTextFindDoneHandler)( struct TRN_PDFViewCtrlTextFindDoneEvent* evt, void* custom_data);
typedef TRN_Bool (*TRN_PDFViewCtrlAnnotationEditPermissionHandler)( struct TRN_PDFViewCtrlAnnotationEditPermissionEvent* evt, void* custom_data);

struct TRN_PDFViewCtrlEventHandlers
{
	TRN_PDFViewCtrlMouseEventHandler mouse_move;
	TRN_PDFViewCtrlMouseEventHandler mouse_enter;
	TRN_PDFViewCtrlMouseEventHandler mouse_leave;
	TRN_PDFViewCtrlMouseEventHandler mouse_left_down;
	TRN_PDFViewCtrlMouseEventHandler mouse_left_up;
	TRN_PDFViewCtrlMouseEventHandler mouse_left_dclick;
	TRN_PDFViewCtrlMouseEventHandler mouse_right_down;
	TRN_PDFViewCtrlMouseEventHandler mouse_right_up;
	TRN_PDFViewCtrlMouseEventHandler mouse_right_dclick;
	TRN_PDFViewCtrlMouseEventHandler mouse_middle_down;
	TRN_PDFViewCtrlMouseEventHandler mouse_middle_up;
	TRN_PDFViewCtrlMouseEventHandler mouse_middle_dclick;
	TRN_PDFViewCtrlMouseEventHandler on_mousewheel;
	TRN_PDFViewCtrlMouseEventHandler on_context_menu;
	TRN_PDFViewCtrlKeyEventHandler   key_down;
	TRN_PDFViewCtrlKeyEventHandler   key_up;
	TRN_PDFViewCtrlKeyEventHandler   character_entered;
	TRN_PDFViewCtrlPaintEventHandler on_paint;
	TRN_PDFViewCtrlSizeEventHandler  on_size;
	TRN_PDFViewCtrlWindowEventHandler on_window_event;
	TRN_PDFViewCtrlTextFindDoneHandler on_find_text_done;
	TRN_PDFViewCtrlAnnotationEditPermissionHandler on_annotation_edit_permission;

	void* custom_data;
};

TRN_API TRN_PDFViewCtrlSetCustomEventHandlers( TRN_PDFViewCtrl view, struct TRN_PDFViewCtrlEventHandlers* events);

typedef TRN_Bool (*TRN_PDFViewCtrlActionHandler) ( TRN_Action action, void* custom_data );

TRN_API TRN_PDFViewCtrlSetActionHandler( TRN_PDFViewCtrl view, TRN_PDFViewCtrlActionHandler action_callback, void* custom_data  );

TRN_API TRN_PDFViewCtrlExecuteAction( TRN_PDFViewCtrl view, TRN_Action action );

// ===========================================================================================
TRN_API TRN_PDFViewCtrlSetWindowBackgroundColor( const TRN_PDFViewCtrl view, enum TRN_PDFViewCtrlWindowID winid, const TRN_ColorPt* color );
#ifdef WIN32
TRN_API TRN_PDFViewCtrlSetWindowCursor( const TRN_PDFViewCtrl view, enum TRN_PDFViewCtrlWindowID winid, void* cursor );
#endif

TRN_API TRN_PDFViewCtrlGetViewHeight( const TRN_PDFViewCtrl view, int* result);
TRN_API TRN_PDFViewCtrlGetViewWidth( const TRN_PDFViewCtrl view, int* result);
TRN_API TRN_PDFViewCtrlOnSize(TRN_PDFViewCtrl view, int width, int height);
TRN_API TRN_PDFViewCtrlOnChangeRect(TRN_PDFViewCtrl view,  int x, int y, int width, int height);

TRN_API TRN_PDFViewCtrlRefresh(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlRequestRender(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlCaptureMouse(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlReleaseMouse(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlHasCapture(TRN_PDFViewCtrl view, TRN_Bool* result);
TRN_API TRN_PDFViewCtrlFind(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlEnableLinkActivation(TRN_PDFViewCtrl view, TRN_Bool on);

TRN_API TRN_PDFViewCtrlSaveCurrentConfiguration( TRN_PDFViewCtrl view, const TRN_UString path, TRN_ProgressMonitor* progress);
TRN_API TRN_PDFViewCtrlLoadCurrentConfiguration( TRN_PDFViewCtrl view, const TRN_UString path );
TRN_API TRN_PDFViewCtrlGetDefaultAnnotation( TRN_PDFViewCtrl view, const char* type, TRN_Annot* result );
TRN_API TRN_PDFViewCtrlSetFocus( TRN_PDFViewCtrl view );

TRN_API TRN_PDFViewCtrlDeletePages(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlInsertBlankPages(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlInsertPages(TRN_PDFViewCtrl view, const TRN_UString src_name);
TRN_API TRN_PDFViewCtrlReplacePages(TRN_PDFViewCtrl view, const TRN_UString src_name);
TRN_API TRN_PDFViewCtrlDocProperties(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlRotatePages(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlExtractPages(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlCropPages(TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlAddWatermark(TRN_PDFViewCtrl view);

TRN_API TRN_PDFViewCtrlSetDownloadReportHandler(TRN_PDFViewCtrl view, TRN_PDFViewPartDownloadedProc proc, void* data);
TRN_API TRN_PDFViewCtrlOpenURLAsync(TRN_PDFViewCtrl view, const char* url, TRN_UString cache_file, const char* password, TRN_Obj options);

TRN_API TRN_PDFViewCtrlSetupThumbnails(TRN_PDFViewCtrl view, TRN_Bool use_embedded, TRN_Bool generate_at_runtime, TRN_Bool use_disk_cache, int thumb_max_side_length, size_t max_abs_cache_size, double max_perc_cache_size);
TRN_API TRN_PDFViewCtrlGetThumbAsync(TRN_PDFViewCtrl view, int page_num, TRN_PDFViewThumbAsyncHandler proc, void* custom_data);
TRN_API TRN_PDFViewCtrlCancelAllThumbRequests( TRN_PDFViewCtrl view);
TRN_API TRN_PDFViewCtrlClearThumbCache(TRN_PDFViewCtrl view);


TRN_API TRN_PDFViewCtrlSetRequestRenderinWorkerThreadProc(TRN_PDFViewCtrl view, TRN_PDFViewRequestRenderInWorkerThreadProc proc, void * custom_data);


TRN_API TRN_PDFViewCtrlSetFindTextHandler(TRN_PDFViewCtrl view, TRN_PDFViewFindTextAsyncHandler proc, void * custom_data);
TRN_API TRN_PDFViewCtrlFindTextAsync(TRN_PDFViewCtrl view, const TRN_UString search_str, TRN_Bool match_case, TRN_Bool match_whole_word,
								 TRN_Bool search_up, TRN_Bool reg_exp);

TRN_API TRN_PDFViewCtrlSetColorPostProcessMode(TRN_PDFViewCtrl view, enum TRN_PDFRasterizerColorPostProcessMode mode);
TRN_API TRN_PDFViewCtrlGetColorPostProcessMode(TRN_PDFViewCtrl view, enum TRN_PDFRasterizerColorPostProcessMode* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFViewCtrl
