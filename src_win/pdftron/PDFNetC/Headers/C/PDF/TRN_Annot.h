//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPDFAnnot
#define PDFTRON_H_CPDFAnnot

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_Page.h>

enum TRN_AnnotEventType
{
	e_Annot_action_trigger_activate = 0,
	e_Annot_action_trigger_annot_enter,	
	e_Annot_action_trigger_annot_exit,
	e_Annot_action_trigger_annot_down,
	e_Annot_action_trigger_annot_up,
	e_Annot_action_trigger_annot_focus,
	e_Annot_action_trigger_annot_blur,
	e_Annot_action_trigger_annot_page_open,
	e_Annot_action_trigger_annot_page_close,
	e_Annot_action_trigger_annot_page_visible,
	e_Annot_action_trigger_annot_page_invisible
};

//1. General Annot
enum TRN_AnnotType
{
	e_Annot_Text,           ///< Text annotation
	e_Annot_Link,           ///< Link annotation
	e_Annot_FreeText,       ///< Free text annotation
	e_Annot_Line,           ///< Line annotation
	e_Annot_Square,         ///< Square annotation
	e_Annot_Circle,         ///< Circle annotation
	e_Annot_Polygon,        ///< Polygon annotation
	e_Annot_Polyline,       ///< Polyline annotation
	e_Annot_Highlight,      ///< Highlight annotation
	e_Annot_Underline,      ///< Underline annotation
	e_Annot_Squiggly,       ///< Squiggly-underline annotation
	e_Annot_StrikeOut,      ///< Strikeout annotation
	e_Annot_Stamp,          ///< Rubber stamp annotation
	e_Annot_Caret,          ///< Caret annotation
	e_Annot_Ink,            ///< Ink annotation
	e_Annot_Popup,          ///< Pop-up annotation
	e_Annot_FileAttachment, ///< File attachment annotation
	e_Annot_Sound,          ///< Sound annotation
	e_Annot_Movie,          ///< Movie annotation
	e_Annot_Widget,         ///< Widget annotation
	e_Annot_Screen,         ///< Screen annotation
	e_Annot_PrinterMark,    ///< Printer's mark annotation
	e_Annot_TrapNet,        ///< Trap network annotation
	e_Annot_Watermark,      ///< Watermark annotation
	e_Annot_3D,             ///< 3D annotation
	e_Annot_Redact,         ///< Redact annotation
	e_Annot_Projection,	  ///< Projection annotation, Adobe supplement to ISO 32000 
	e_Annot_RichMedia,      ///< Rich Media annotation, Adobe supplement to ISO 32000 
	e_Annot_Unknown         ///< Any other annotation type, not listed in PDF spec and unrecognized by PDFTron software
};	



enum TRN_AnnotFlag
{
	e_Annot_invisible,         // PDF 1.2
	e_Annot_hidden,            // PDF 1.2
	e_Annot_print,             // PDF 1.2
	e_Annot_no_zoom,           // PDF 1.3
	e_Annot_no_rotate,         // PDF 1.3
	e_Annot_no_view,           // PDF 1.3
	e_Annot_annot_read_only,   // PDF 1.3
	e_Annot_locked,            // PDF 1.4
	e_Annot_toggle_no_view,    // PDF 1.5
	e_Annot_locked_contents    // PDF 1.7
};

enum TRN_AnnotBorderStyleStyle {
	e_AnnotBorderStyle_solid,   ///< A solid rectangle surrounding the annotation.
	e_AnnotBorderStyle_dashed,  ///< A dashed rectangle surrounding the annotation.
	e_AnnotBorderStyle_beveled, ///< A simulated embossed rectangle that appears to be raised above the surface of the page.
	e_AnnotBorderStyle_inset,   ///< A simulated engraved rectangle that appears to be recessed below the surface of the page. 
	e_AnnotBorderStyle_underline  ///< A single line along the bottom of the annotation rectangle.
};


enum TRN_AnnotState
{
	e_Annot_normal,
	e_Annot_rollover,
	e_Annot_down
};

TRN_API TRN_AnnotCreate(TRN_SDFDoc doc, enum TRN_AnnotType type, const TRN_Rect* pos, TRN_Annot* result);
TRN_API TRN_AnnotCreateFromObj (TRN_Obj d, TRN_Annot* result);
//TRN_API TRN_AnnotAssign(TRN_Annot* left, TRN_Annot* right);
TRN_API TRN_AnnotCopy (const TRN_Annot d, TRN_Annot* result);
TRN_API TRN_AnnotCompare(const TRN_Annot annot, const TRN_Annot d, TRN_Bool* result);
TRN_API TRN_AnnotIsValid(TRN_Annot annot, TRN_Bool* result);
TRN_API TRN_AnnotGetSDFObj (TRN_Annot annot, TRN_Obj* result);
TRN_API TRN_AnnotGetType(TRN_Annot annot, enum TRN_AnnotType* result);
TRN_API TRN_AnnotIsMarkup( TRN_Annot annot, TRN_Bool* result );
TRN_API TRN_AnnotGetRect(TRN_Annot annot, TRN_Rect* result) ;
TRN_API TRN_AnnotGetVisibleContentBox(TRN_Annot annot, TRN_Rect* result);
TRN_API TRN_AnnotSetRect(TRN_Annot annot, const TRN_Rect* pos); 
TRN_API TRN_AnnotResize(TRN_Annot annot, const TRN_Rect* newrect) ;
TRN_API TRN_AnnotSetContents(TRN_Annot annot, const TRN_UString contents);
TRN_API TRN_AnnotGetContents(TRN_Annot annot, TRN_UString* result );
TRN_API TRN_AnnotGetTriggerAction(TRN_Annot annot, enum TRN_AnnotEventType trigger, TRN_Obj* result);
TRN_API TRN_AnnotGetCustomData(TRN_Annot annot, TRN_UString key, TRN_UString* result);
TRN_API TRN_AnnotSetCustomData(TRN_Annot annot, TRN_UString key, TRN_UString value);
TRN_API TRN_AnnotDeleteCustomData(TRN_Annot annot, TRN_UString key);

//---------------------------------------------------------------------------------------
//TRN_API TRN_AnnotUpdateRect(TRN_Annot annot, const TRN_Rect* pos);
//---------------------------------------------------------------------------------------
TRN_API TRN_AnnotGetPage(TRN_Annot annot, TRN_Page* result);
TRN_API TRN_AnnotSetPage(TRN_Annot annot, const TRN_Page page);
TRN_API TRN_AnnotGetUniqueID(TRN_Annot annot,TRN_Obj* result);
TRN_API TRN_AnnotSetUniqueID(TRN_Annot annot, const char* id, int id_buf_sz);
TRN_API TRN_AnnotGetDate(TRN_Annot annot, TRN_Date* result);
TRN_API TRN_AnnotSetDate(TRN_Annot annot, const TRN_Date* date);
TRN_API TRN_AnnotGetFlag(TRN_Annot annot, enum TRN_AnnotFlag flag, TRN_Bool* result);
TRN_API TRN_AnnotSetFlag(TRN_Annot annot, enum TRN_AnnotFlag flag, TRN_Bool value);
TRN_API TRN_AnnotBorderStyleCreate(enum TRN_AnnotBorderStyleStyle s, double b_width, double b_hr, double b_vr, TRN_AnnotBorderStyle* result);
TRN_API	TRN_AnnotBorderStyleCreateWithDashPattern(enum TRN_AnnotBorderStyleStyle s, double b_width, double b_hr, double b_vr, double* b_dash_list, int b_dash_list_size, TRN_AnnotBorderStyle* result);
TRN_API TRN_AnnotBorderStyleCopy(const TRN_AnnotBorderStyle bs,TRN_AnnotBorderStyle* result);
TRN_API TRN_AnnotBorderStyleGetStyle(TRN_AnnotBorderStyle bs,enum TRN_AnnotBorderStyleStyle* result);
TRN_API TRN_AnnotBorderStyleSetStyle(TRN_AnnotBorderStyle bs,enum TRN_AnnotBorderStyleStyle style);
TRN_API TRN_AnnotBorderStyleDestroy(TRN_AnnotBorderStyle bs);
TRN_API TRN_AnnotGetAppearance(TRN_Annot annot, enum TRN_AnnotState annot_state, const char* app_state, TRN_Obj* result);
TRN_API TRN_AnnotSetAppearance(TRN_Annot annot, TRN_Obj app_stream, enum TRN_AnnotState annot_state, const char* app_state);
TRN_API TRN_AnnotRemoveAppearance(TRN_Annot annot, enum TRN_AnnotState annot_state, const char* app_state);
TRN_API TRN_AnnotFlatten(TRN_Annot annot, TRN_Page page);
TRN_API TRN_AnnotGetActiveAppearanceState(TRN_Annot annot, const char** result);
TRN_API TRN_AnnotSetActiveAppearanceState(TRN_Annot annot, const char* astate);
TRN_API TRN_AnnotGetColor(TRN_Annot annot, TRN_ColorPt* result);
TRN_API TRN_AnnotGetColorAsRGB(TRN_Annot annot, TRN_ColorPt* result);
TRN_API TRN_AnnotGetColorAsCMYK(TRN_Annot annot, TRN_ColorPt* result);
TRN_API TRN_AnnotGetColorAsGray(TRN_Annot annot, TRN_ColorPt* result);
TRN_API TRN_AnnotGetColorCompNum(TRN_Annot annot, int* result);
TRN_API TRN_AnnotSetColorDefault(TRN_Annot annot, const TRN_ColorPt* col);
TRN_API TRN_AnnotSetColor(TRN_Annot annot, const TRN_ColorPt* col, int numcomp);
TRN_API TRN_AnnotGetStructParent(TRN_Annot annot, int* result);
TRN_API TRN_AnnotSetStructParent(TRN_Annot annot, int parkeyval);
TRN_API TRN_AnnotGetOptionalContent(TRN_Annot annot, TRN_Obj* result);
TRN_API TRN_AnnotSetOptionalContent(TRN_Annot annot, const TRN_Obj content);
TRN_API TRN_AnnotRefreshAppearance(TRN_Annot annot);
TRN_API TRN_AnnotRefreshAppearanceRefreshOptions(TRN_Annot annot, const TRN_OptionBase* options);
TRN_API TRN_AnnotGetRotation(const TRN_Annot annot, int* result);
TRN_API TRN_AnnotSetRotation(TRN_Annot annot, int angle);
TRN_API TRN_AnnotBorderStyleCopy(const TRN_AnnotBorderStyle bs,TRN_AnnotBorderStyle* result);
TRN_API TRN_AnnotBorderStyleGetWidth(TRN_AnnotBorderStyle bs, double* result);
TRN_API TRN_AnnotBorderStyleSetWidth(TRN_AnnotBorderStyle bs, double width);
TRN_API TRN_AnnotBorderStyleGetHR(TRN_AnnotBorderStyle bs, double* result);
TRN_API TRN_AnnotBorderStyleSetHR(TRN_AnnotBorderStyle bs,double horizontal_radius);
TRN_API TRN_AnnotBorderStyleGetVR(TRN_AnnotBorderStyle bs, double* result);
TRN_API TRN_AnnotBorderStyleSetVR(TRN_AnnotBorderStyle bs, double vertical_radius);
TRN_API TRN_AnnotBorderStyleGetDashPattern(TRN_AnnotBorderStyle bs, double** out_buf, int* out_buf_length);
TRN_API TRN_AnnotBorderStyleSetDashPattern(TRN_AnnotBorderStyle bs, const double* const buffer, int buf_length);
TRN_API TRN_AnnotGetBorderStyle(TRN_Annot annot,TRN_AnnotBorderStyle* result);
TRN_API TRN_AnnotSetBorderStyle(TRN_Annot annot, const TRN_AnnotBorderStyle bs, TRN_Bool oldStyleOnly );
TRN_API TRN_AnnotGetBorderStyleStyle( const TRN_AnnotBorderStyle bs, enum TRN_AnnotBorderStyleStyle* result);
TRN_API TRN_AnnotSetBorderStyleStyle( TRN_AnnotBorderStyle bs, const enum TRN_AnnotBorderStyleStyle bst );
TRN_API TRN_AnnotBorderStyleAssign( const TRN_AnnotBorderStyle from, TRN_AnnotBorderStyle to );
TRN_API TRN_AnnotBorderStyleCompare( const TRN_AnnotBorderStyle a, const TRN_AnnotBorderStyle b, TRN_Bool *result );

//Caret
TRN_API TRN_CaretAnnotCreateFromObj(TRN_Obj d, TRN_CaretAnnot* result);
TRN_API TRN_CaretAnnotCreateFromAnnot(TRN_Annot ann, TRN_CaretAnnot* result);
TRN_API TRN_CaretAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_CaretAnnot* result);
TRN_API TRN_CaretAnnotGetSymbol(TRN_CaretAnnot caret, const char** result);
TRN_API TRN_CaretAnnotSetSymbol(TRN_CaretAnnot caret, const char* symbol);


enum TRN_LineAnnotEndingStyle
{
	e_LineAnnot_Square,
	e_LineAnnot_Circle,
	e_LineAnnot_Diamond,
	e_LineAnnot_OpenArrow,
	e_LineAnnot_ClosedArrow,						
	e_LineAnnot_Butt,
	e_LineAnnot_ROpenArrow,
	e_LineAnnot_RClosedArrow,
	e_LineAnnot_Slash,
	e_LineAnnot_None,
	e_LineAnnot_Unknown
};

enum TRN_LineAnnotIntentType
{
	e_LineAnnot_LineArrow,
	e_LineAnnot_LineDimension,
	e_LineAnnot_null
};

enum TRN_LineAnnotCapPos
{
	e_LineAnnot_Inline, //changed by Maxim
	e_LineAnnot_Top
};

TRN_API TRN_LineAnnotCreateFromObj(TRN_Obj d, TRN_LineAnnot* result);
TRN_API TRN_LineAnnotCreateFromAnnot(TRN_Annot ann, TRN_LineAnnot* result);		
TRN_API TRN_LineAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_LineAnnot* result);
TRN_API TRN_LineAnnotGetStartPoint(TRN_LineAnnot line, TRN_Point* result);
TRN_API TRN_LineAnnotSetStartPoint(TRN_LineAnnot line, const TRN_Point* sp);
TRN_API TRN_LineAnnotGetEndPoint(TRN_LineAnnot line, TRN_Point* result);
TRN_API TRN_LineAnnotSetEndPoint(TRN_LineAnnot line, const TRN_Point* ep);
TRN_API TRN_LineAnnotGetStartStyle(TRN_LineAnnot line, enum TRN_LineAnnotEndingStyle* result);
TRN_API TRN_LineAnnotSetStartStyle(TRN_LineAnnot line, enum TRN_LineAnnotEndingStyle ss);
TRN_API TRN_LineAnnotGetEndStyle(TRN_LineAnnot line, enum TRN_LineAnnotEndingStyle* result);
TRN_API TRN_LineAnnotSetEndStyle(TRN_LineAnnot line, enum TRN_LineAnnotEndingStyle es);
TRN_API TRN_LineAnnotGetLeaderLineLength(TRN_LineAnnot line, double* result);
TRN_API TRN_LineAnnotSetLeaderLineLength(TRN_LineAnnot line, double length);
TRN_API TRN_LineAnnotGetLeaderLineExtensionLength(TRN_LineAnnot line, double* result);
TRN_API TRN_LineAnnotSetLeaderLineExtensionLength(TRN_LineAnnot line, double length);
TRN_API TRN_LineAnnotGetShowCaption(TRN_LineAnnot line, TRN_Bool* result);
TRN_API TRN_LineAnnotSetShowCaption(TRN_LineAnnot line, TRN_Bool showCaption);
TRN_API TRN_LineAnnotGetIntentType(TRN_LineAnnot line, enum TRN_LineAnnotIntentType* result);
TRN_API TRN_LineAnnotSetIntentType(TRN_LineAnnot line, enum TRN_LineAnnotIntentType it);
TRN_API TRN_LineAnnotGetCapPos(TRN_LineAnnot line, enum TRN_LineAnnotCapPos* result);
TRN_API TRN_LineAnnotSetCapPos(TRN_LineAnnot line, enum TRN_LineAnnotCapPos it);
TRN_API TRN_LineAnnotGetLeaderLineOffset(TRN_LineAnnot line, double* result);
TRN_API TRN_LineAnnotSetLeaderLineOffset(TRN_LineAnnot line, double length);
TRN_API TRN_LineAnnotGetTextHOffset(TRN_LineAnnot line, double* result);
TRN_API TRN_LineAnnotSetTextHOffset(TRN_LineAnnot line, double offset);
TRN_API TRN_LineAnnotGetTextVOffset(TRN_LineAnnot line, double* result);
TRN_API TRN_LineAnnotSetTextVOffset(TRN_LineAnnot line, double offset);



//Circle
TRN_API TRN_CircleAnnotCreateFromObj(TRN_Obj d, TRN_CircleAnnot* result);
TRN_API TRN_CircleAnnotCreateFromAnnot(TRN_Annot circle, TRN_CircleAnnot* result);
TRN_API TRN_CircleAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_CircleAnnot* result);
TRN_API TRN_CircleAnnotGetInteriorColor(TRN_CircleAnnot circle, TRN_ColorPt* result);
TRN_API TRN_CircleAnnotGetInteriorColorCompNum(TRN_CircleAnnot circle, int* result);
TRN_API TRN_CircleAnnotSetInteriorColorDefault(TRN_CircleAnnot circle, const TRN_ColorPt* col);
TRN_API TRN_CircleAnnotSetInteriorColor(TRN_CircleAnnot circle, const TRN_ColorPt* col, int numcomp);
TRN_API TRN_CircleAnnotGetContentRect(TRN_CircleAnnot circle, TRN_Rect* result);
TRN_API TRN_CircleAnnotSetContentRect(TRN_CircleAnnot circle, const TRN_Rect* cr);
TRN_API TRN_CircleAnnotGetPadding(TRN_CircleAnnot circle, TRN_Rect* result);
TRN_API TRN_CircleAnnotSetPadding(TRN_CircleAnnot circle, const TRN_Rect* cr);


//FileAttachment
enum TRN_FileAttachmentAnnotIcon
{
	e_FileAttachmentAnnot_Graph,
	e_FileAttachmentAnnot_PushPin,
	e_FileAttachmentAnnot_Paperclip,
	e_FileAttachmentAnnot_Tag,
	e_FileAttachmentAnnot_Unknown
};

TRN_API TRN_FileAttachmentAnnotCreateFromObj(TRN_Obj d, TRN_FileAttachmentAnnot* result);
TRN_API TRN_FileAttachmentAnnotExport(TRN_FileAttachmentAnnot fileatt, const TRN_UString save_as, TRN_Bool* result);
TRN_API TRN_FileAttachmentAnnotCreateFromAnnot(TRN_FileAttachmentAnnot fileatt, TRN_Annot* result);
TRN_API TRN_FileAttachmentAnnotCreateWithFileSpec(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_FileSpec fs, enum TRN_FileAttachmentAnnotIcon icon_name, TRN_FileAttachmentAnnot* result);
TRN_API TRN_FileAttachmentAnnotCreateWithIcon(TRN_SDFDoc doc, const TRN_Rect* pos, const TRN_UString path, enum TRN_FileAttachmentAnnotIcon icon_name, TRN_FileAttachmentAnnot* result);
TRN_API TRN_FileAttachmentAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, const TRN_UString path, const char* icon_name, TRN_FileAttachmentAnnot* result);
TRN_API TRN_FileAttachmentAnnotCreateDefault(TRN_SDFDoc doc, const TRN_Rect* pos, const TRN_UString path, TRN_FileAttachmentAnnot* result);
TRN_API TRN_FileAttachmentAnnotGetFileSpec(TRN_FileAttachmentAnnot fileatt, TRN_FileSpec* result);
TRN_API TRN_FileAttachmentAnnotSetFileSpec(TRN_FileAttachmentAnnot fileatt, TRN_FileSpec file);
TRN_API TRN_FileAttachmentAnnotGetIcon(TRN_FileAttachmentAnnot fileatt, enum TRN_FileAttachmentAnnotIcon* result);
TRN_API TRN_FileAttachmentAnnotSetIcon(TRN_FileAttachmentAnnot fileatt, enum TRN_FileAttachmentAnnotIcon type);
TRN_API TRN_FileAttachmentAnnotGetIconName(TRN_FileAttachmentAnnot fileatt, const char** result);
TRN_API TRN_FileAttachmentAnnotSetIconName(TRN_FileAttachmentAnnot fileatt, const char* iname);


enum TRN_FreeTextAnnotIntentName
{
	e_FreeTextAnnot_FreeText,
	e_FreeTextAnnot_FreeTextCallout,
	e_FreeTextAnnot_FreeTextTypeWriter,
	e_FreeTextAnnot_Unknown
};


TRN_API TRN_FreeTextAnnotCreateFromObj(TRN_Obj d, TRN_FreeTextAnnot* result);
TRN_API TRN_FreeTextAnnotCreateFromAnnot(TRN_Annot ann, TRN_FreeTextAnnot* result);
TRN_API TRN_FreeTextAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_FreeTextAnnot* result);
TRN_API TRN_FreeTextAnnotGetDefaultAppearance(TRN_FreeTextAnnot ft, TRN_UString* result );
TRN_API TRN_FreeTextAnnotSetDefaultAppearance(TRN_FreeTextAnnot ft, const char* app_str);
TRN_API TRN_FreeTextAnnotGetQuaddingFormat(TRN_FreeTextAnnot ft, int* result);
TRN_API TRN_FreeTextAnnotSetQuaddingFormat(TRN_FreeTextAnnot ft, int format);
TRN_API TRN_FreeTextAnnotGetCalloutLinePoints(TRN_FreeTextAnnot ft, const TRN_Point* out_p1, const TRN_Point* out_p2, const TRN_Point* out_p3);
TRN_API TRN_FreeTextAnnotSetCalloutLinePoints(TRN_FreeTextAnnot ft, const TRN_Point* p1, const TRN_Point* p2, const TRN_Point* p3);
TRN_API TRN_FreeTextAnnotSetCalloutLinePointsTwo(TRN_FreeTextAnnot ft, const TRN_Point* p1, const TRN_Point* p2);
TRN_API TRN_FreeTextAnnotGetIntentName(TRN_FreeTextAnnot ft, enum TRN_FreeTextAnnotIntentName* result);
TRN_API TRN_FreeTextAnnotSetIntentName(TRN_FreeTextAnnot ft, enum TRN_FreeTextAnnotIntentName mode);
TRN_API TRN_FreeTextAnnotSetIntentNameDefault(TRN_FreeTextAnnot ft);
TRN_API TRN_FreeTextAnnotGetEndingStyle(TRN_FreeTextAnnot ft, enum TRN_LineAnnotEndingStyle* result);
TRN_API TRN_FreeTextAnnotSetEndingStyle(TRN_FreeTextAnnot ft, enum TRN_LineAnnotEndingStyle style);
TRN_API TRN_FreeTextAnnotSetEndingStyleName(TRN_FreeTextAnnot ft, const char* est);
TRN_API TRN_FreeTextAnnotSetTextColor(TRN_FreeTextAnnot ft, const TRN_ColorPt* color, int col_comp);
TRN_API TRN_FreeTextAnnotGetTextColor(TRN_FreeTextAnnot ft, TRN_ColorPt* out_color, int* out_col_comp);
TRN_API TRN_FreeTextAnnotSetLineColor(TRN_FreeTextAnnot ft, const TRN_ColorPt* color, int col_comp);
TRN_API TRN_FreeTextAnnotGetLineColor(TRN_FreeTextAnnot ft, TRN_ColorPt* out_color, int* out_col_comp);
TRN_API TRN_FreeTextAnnotSetFontSize( TRN_FreeTextAnnot ft, double font_size );
TRN_API TRN_FreeTextAnnotGetFontSize( TRN_FreeTextAnnot ft, double* result );

TRN_API TRN_HighlightAnnotCreateFromObj(TRN_Obj d, TRN_HighlightAnnot* result);
TRN_API TRN_HighlightAnnotCreateFromAnnot(TRN_Annot ann, TRN_HighlightAnnot* result);
TRN_API TRN_HighlightAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_HighlightAnnot* result);


TRN_API TRN_InkAnnotCreateFromObj(TRN_Obj d, TRN_InkAnnot* result);
TRN_API TRN_InkAnnotCreateFromAnnot(TRN_Annot ann, TRN_InkAnnot* result);
TRN_API TRN_InkAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_InkAnnot* result);
TRN_API TRN_InkAnnotGetPathCount(TRN_InkAnnot ink, int* result);
TRN_API TRN_InkAnnotGetPointCount(TRN_InkAnnot ink, int pathindex, int* result);
TRN_API TRN_InkAnnotGetPoint(TRN_InkAnnot ink, unsigned int pathindex, unsigned int pointindex, TRN_Point* result);
TRN_API TRN_InkAnnotSetPoint(TRN_InkAnnot ink, unsigned int pathindex, unsigned int pointindex, const TRN_Point* pt);
TRN_API TRN_InkAnnotErase(TRN_InkAnnot ink, const TRN_Point* pt1, const TRN_Point* pt2, double width, TRN_Bool* result);
TRN_API TRN_InkAnnotGetHighlightIntent(TRN_InkAnnot ink, TRN_Bool* result);
TRN_API TRN_InkAnnotSetHighlightIntent(TRN_InkAnnot ink, TRN_Bool highlight);

enum TRN_LinkAnnotHighlightingMode 
{
	e_LinkAnnot_none,     
	e_LinkAnnot_invert,
	e_LinkAnnot_outline,
	e_LinkAnnot_push
};

TRN_API TRN_LinkAnnotCreateFromObj(TRN_Obj d, TRN_LinkAnnot* result);
TRN_API TRN_LinkAnnotCreateFromAnnot(TRN_Annot ann, TRN_LinkAnnot* result);
TRN_API TRN_LinkAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_LinkAnnot* result);
TRN_API TRN_LinkAnnotRemoveAction(TRN_LinkAnnot link);
TRN_API TRN_LinkAnnotGetAction(TRN_LinkAnnot link, TRN_Action* result);
TRN_API TRN_LinkAnnotSetAction(TRN_LinkAnnot link, TRN_Action action);
TRN_API TRN_LinkAnnotGetHighlightingMode(TRN_LinkAnnot link, enum TRN_LinkAnnotHighlightingMode* result);
TRN_API TRN_LinkAnnotSetHighlightingMode(TRN_LinkAnnot link, enum TRN_LinkAnnotHighlightingMode value);
TRN_API TRN_LinkAnnotGetQuadPointCount(TRN_LinkAnnot link, int* result);
TRN_API TRN_LinkAnnotGetQuadPoint(TRN_LinkAnnot link, int idx, TRN_QuadPoint* result);
TRN_API TRN_LinkAnnotSetQuadPoint(TRN_LinkAnnot link, int idx, const TRN_QuadPoint* qp);
TRN_API TRN_GetNormalizedUrl(const TRN_UString url, TRN_UString* result);

enum TRN_MarkupAnnotBorderEffect 
{
	e_MarkupAnnot_None,
	e_MarkupAnnot_Cloudy
};

TRN_API TRN_MarkupAnnotCreateFromObj(TRN_Obj d, TRN_MarkupAnnot* result);
TRN_API TRN_MarkupAnnotCreateFromAnnot(TRN_Annot ann, TRN_MarkupAnnot* result);
TRN_API TRN_MarkupAnnotGetTitle(TRN_MarkupAnnot markup, TRN_UString* result);
TRN_API TRN_MarkupAnnotSetTitle(TRN_MarkupAnnot markup, const char* title);
TRN_API TRN_MarkupAnnotSetTitleUString(TRN_MarkupAnnot markup, TRN_UString title);
TRN_API TRN_MarkupAnnotGetPopup(TRN_MarkupAnnot markup, TRN_Annot* result);
TRN_API TRN_MarkupAnnotSetPopup(TRN_MarkupAnnot markup, TRN_Annot ppup);
TRN_API TRN_MarkupAnnotGetOpacity(TRN_MarkupAnnot markup, double* result);
TRN_API TRN_MarkupAnnotSetOpacity(TRN_MarkupAnnot markup, double op);
TRN_API TRN_MarkupAnnotGetSubject(TRN_MarkupAnnot markup, TRN_UString* result);
TRN_API TRN_MarkupAnnotSetSubject(TRN_MarkupAnnot markup, TRN_UString contents);
TRN_API TRN_MarkupAnnotGetCreationDates(TRN_MarkupAnnot markup, TRN_Date* result);
TRN_API TRN_MarkupAnnotGetCreationDates(TRN_MarkupAnnot markup, TRN_Date* date);
TRN_API TRN_MarkupAnnotGetBorderEffect(TRN_MarkupAnnot markup, enum TRN_MarkupAnnotBorderEffect* result);
TRN_API TRN_MarkupAnnotSetBorderEffect(TRN_MarkupAnnot markup, enum TRN_MarkupAnnotBorderEffect effect);
TRN_API TRN_MarkupAnnotGetBorderEffectIntensity(TRN_MarkupAnnot markup, double* result);
TRN_API TRN_MarkupAnnotSetBorderEffectIntensity(TRN_MarkupAnnot markup, double intensity);
TRN_API TRN_MarkupAnnotGetCreationDates(TRN_MarkupAnnot markup, TRN_Date* result);
TRN_API TRN_MarkupAnnotSetCreationDates(TRN_MarkupAnnot markup, const TRN_Date* dt);
TRN_API TRN_MarkupAnnotGetInteriorColor(TRN_MarkupAnnot markup, TRN_ColorPt* result);
TRN_API TRN_MarkupAnnotGetInteriorColorCompNum(TRN_MarkupAnnot markup, int* result);
TRN_API TRN_MarkupAnnotSetInteriorColorRGB(TRN_MarkupAnnot markup, const TRN_ColorPt* col);
TRN_API TRN_MarkupAnnotSetInteriorColor(TRN_MarkupAnnot markup, const TRN_ColorPt* c, int CompNum);
TRN_API TRN_MarkupAnnotGetContentRect(TRN_MarkupAnnot markup, TRN_Rect* result);
TRN_API TRN_MarkupAnnotSetContentRect(TRN_MarkupAnnot markup, const TRN_Rect* cr);
TRN_API TRN_MarkupAnnotGetPadding(TRN_MarkupAnnot markup, TRN_Rect* result);
TRN_API TRN_MarkupAnnotSetPadding(TRN_MarkupAnnot markup, const TRN_Rect* rd);
TRN_API TRN_MarkupAnnotRotateAppearance(TRN_MarkupAnnot markup, double angle);

TRN_API TRN_MovieAnnotCreateFromObj(TRN_Obj d, TRN_MovieAnnot* result);
TRN_API TRN_MovieAnnotCreateFromAnnot(TRN_Annot ann, TRN_MovieAnnot* result);
TRN_API TRN_MovieAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_MovieAnnot* result);
TRN_API TRN_MovieAnnotGetTitle(TRN_MovieAnnot movie, TRN_UString* result);
TRN_API TRN_MovieAnnotSetTitle(TRN_MovieAnnot movie, TRN_UString title);
TRN_API TRN_MovieAnnotIsToBePlayed(TRN_MovieAnnot movie, TRN_Bool* result);
TRN_API TRN_MovieAnnotSetToBePlayed(TRN_MovieAnnot movie, TRN_Bool isplay);

enum TRN_PolyLineAnnotIntentType
{
	e_PolyLineAnnot_PolygonCloud,
	e_PolyLineAnnot_PolyLineDimension,
	e_PolyLineAnnot_PolygonDimension,
	e_PolyLineAnnot_Unknown
};

TRN_API TRN_PolyLineAnnotCreateFromObj(TRN_Obj d, TRN_PolyLineAnnot* result);
TRN_API TRN_PolyLineAnnotCreateFromAnnot(TRN_Annot ann, TRN_PolyLineAnnot* result);
TRN_API TRN_PolyLineAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_PolyLineAnnot* result);
TRN_API TRN_PolyLineAnnotGetVertexCount(TRN_PolyLineAnnot polyline, int* result);
TRN_API TRN_PolyLineAnnotGetVertex(TRN_PolyLineAnnot polyline, int idx, TRN_Point* result);
TRN_API TRN_PolyLineAnnotSetVertex(TRN_PolyLineAnnot polyline, int idx, const TRN_Point* pt);
TRN_API TRN_PolyLineAnnotGetStartStyle(TRN_PolyLineAnnot polyline, enum TRN_LineAnnotEndingStyle* result);
TRN_API TRN_PolyLineAnnotSetStartStyle(TRN_PolyLineAnnot polyline, enum TRN_LineAnnotEndingStyle style);
TRN_API TRN_PolyLineAnnotGetEndStyle(TRN_PolyLineAnnot polyline, enum TRN_LineAnnotEndingStyle* result);
TRN_API TRN_PolyLineAnnotSetEndStyle(TRN_PolyLineAnnot polyline, enum TRN_LineAnnotEndingStyle style);
TRN_API TRN_PolyLineAnnotGetIntentName(TRN_PolyLineAnnot polyline, enum TRN_PolyLineAnnotIntentType* result);
TRN_API TRN_PolyLineAnnotSetIntentName(TRN_PolyLineAnnot polyline, enum TRN_PolyLineAnnotIntentType mode);


TRN_API TRN_PolygonAnnotCreateFromObj(TRN_Obj d, TRN_PolygonAnnot* result);
TRN_API TRN_PolygonAnnotCreateFromAnnot(TRN_Annot ann, TRN_PolygonAnnot* result);
TRN_API TRN_PolygonAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_PolygonAnnot* result);



TRN_API TRN_PopupAnnotCreateFromObj(TRN_Obj d, TRN_PopupAnnot* result);
TRN_API TRN_PopupAnnotCreateFromAnnot(TRN_Annot ann, TRN_PopupAnnot* result);
TRN_API TRN_PopupAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_PopupAnnot* result);
TRN_API TRN_PopupAnnotGetParent(TRN_PopupAnnot popup, TRN_Annot* result);
TRN_API TRN_PopupAnnotSetParent(TRN_PopupAnnot popup, TRN_Annot parent);
TRN_API TRN_PopupAnnotIsOpen(TRN_PopupAnnot popup, TRN_Bool* result);
TRN_API TRN_PopupAnnotSetOpen(TRN_PopupAnnot popup, TRN_Bool isopen);


enum TRN_RedactionAnnotQuadForm
{
	e_RedactionAnnot_LeftJustified,
	e_RedactionAnnot_Centered,
	e_RedactionAnnot_RightJustified,
	e_RedactionAnnot_None
};

TRN_API TRN_RedactionAnnotCreateFromObj(TRN_Obj d, TRN_RedactionAnnot* result);
TRN_API TRN_RedactionAnnotCreateFromAnnot(TRN_Annot ann, TRN_RedactionAnnot* result);
TRN_API TRN_RedactionAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_RedactionAnnot* result);
TRN_API TRN_RedactionAnnotGetQuadPointCount(TRN_RedactionAnnot redaction, int* result);
TRN_API TRN_RedactionAnnotGetQuadPoint(TRN_RedactionAnnot redaction, int idx, TRN_QuadPoint* result); 
TRN_API TRN_RedactionAnnotSetQuadPoint(TRN_RedactionAnnot redaction, int idx, const TRN_QuadPoint* qp);


TRN_API TRN_RedactionAnnotSetAppFormXO(TRN_RedactionAnnot redaction, TRN_Obj formxo);
TRN_API TRN_RedactionAnnotGetOverlayText(TRN_RedactionAnnot redaction, TRN_UString* result);
TRN_API TRN_RedactionAnnotSetOverlayText(TRN_RedactionAnnot redaction, TRN_UString title);
TRN_API TRN_RedactionAnnotGetUseRepeat(TRN_RedactionAnnot redaction, TRN_Bool* result);
TRN_API TRN_RedactionAnnotSetUseRepeat(TRN_RedactionAnnot redaction, TRN_Bool userepeat);
TRN_API TRN_RedactionAnnotGetOverlayTextAppearance(TRN_RedactionAnnot redaction, TRN_UString* result);
TRN_API TRN_RedactionAnnotSetOverlayTextAppearance(TRN_RedactionAnnot redaction, TRN_UString app);
TRN_API TRN_RedactionAnnotGetQuadForm(TRN_RedactionAnnot redaction, enum TRN_RedactionAnnotQuadForm* result);
TRN_API TRN_RedactionAnnotSetQuadForm(TRN_RedactionAnnot redaction, enum TRN_RedactionAnnotQuadForm form);
TRN_API TRN_RedactionAnnotGetAppFormXO(TRN_RedactionAnnot redaction, TRN_Obj* result);
TRN_API TRN_RedactionAnnotSetAppFormXO(TRN_RedactionAnnot redaction, TRN_Obj formxo);

enum TRN_RubberStampAnnotIcon
{
	e_RubberStampAnnot_Approved, 
	e_RubberStampAnnot_Experimental, 
	e_RubberStampAnnot_NotApproved, 
	e_RubberStampAnnot_AsIs, 
	e_RubberStampAnnot_Expired , 
	e_RubberStampAnnot_NotForPublicRelease, 
	e_RubberStampAnnot_Confidential, 
	e_RubberStampAnnot_Final, 
	e_RubberStampAnnot_Sold, 
	e_RubberStampAnnot_Departmental, 
	e_RubberStampAnnot_ForComment, 
	e_RubberStampAnnot_TopSecret, 						 
	e_RubberStampAnnot_ForPublicRelease,
	e_RubberStampAnnot_Draft,
	e_RubberStampAnnot_Unknown
};

TRN_API TRN_RubberStampAnnotCreateFromObj(TRN_Obj d, TRN_RubberStampAnnot* result);
TRN_API TRN_RubberStampAnnotCreateFromAnnot(TRN_Annot ann, TRN_RubberStampAnnot* result);
TRN_API TRN_RubberStampAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_RubberStampAnnot* result);
TRN_API TRN_RubberStampAnnotCreateCustom(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_Obj form_xobject, TRN_RubberStampAnnot* result);
TRN_API TRN_RubberStampAnnotGetIcon(TRN_RubberStampAnnot stamp, enum TRN_RubberStampAnnotIcon* result);
TRN_API TRN_RubberStampAnnotSetIcon(TRN_RubberStampAnnot stamp, enum TRN_RubberStampAnnotIcon type); 
TRN_API TRN_RubberStampAnnotSetIconDefault(TRN_RubberStampAnnot stamp);
TRN_API TRN_RubberStampAnnotGetIconName(TRN_RubberStampAnnot stamp, const char** result);
TRN_API TRN_RubberStampAnnotSetIconName(TRN_RubberStampAnnot stamp, const char* iconstring);

enum TRN_ScreenAnnotScaleType
{
	e_ScreenAnnot_Anamorphic,
	e_ScreenAnnot_Proportional
};

enum TRN_ScreenAnnotScaleCondition
{
	e_ScreenAnnot_Always,
	e_ScreenAnnot_WhenBigger,
	e_ScreenAnnot_WhenSmaller,
	e_ScreenAnnot_Never
};


enum TRN_ScreenAnnotIconCaptionRelation
{
	e_ScreenAnnot_NoIcon,
	e_ScreenAnnot_NoCaption,
	e_ScreenAnnot_CBelowI,
	e_ScreenAnnot_CAboveI,
	e_ScreenAnnot_CRightILeft,
	e_ScreenAnnot_CLeftIRight,
	e_ScreenAnnot_COverlayI
};


TRN_API TRN_ScreenAnnotCreateFromObj(TRN_Obj d, TRN_ScreenAnnot* result);
TRN_API TRN_ScreenAnnotCreateFromAnnot(TRN_Annot ann, TRN_ScreenAnnot* result);
TRN_API TRN_ScreenAnnotGetTitle(TRN_ScreenAnnot s, TRN_UString* result);
TRN_API TRN_ScreenAnnotSetTitle(TRN_ScreenAnnot s, TRN_UString title);
TRN_API TRN_ScreenAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_ScreenAnnot* result);
TRN_API TRN_ScreenAnnotGetAction(TRN_ScreenAnnot s, TRN_Action* result);
TRN_API TRN_ScreenAnnotSetAction(TRN_ScreenAnnot s, TRN_Action action);
TRN_API TRN_ScreenAnnotGetBorderColor(TRN_ScreenAnnot s, TRN_ColorPt* result);
TRN_API TRN_ScreenAnnotSetBorderColor(TRN_ScreenAnnot s, const TRN_ColorPt* col, int numcomp);					
TRN_API TRN_ScreenAnnotGetBorderColorCompNum(TRN_ScreenAnnot s, int* result);
TRN_API TRN_ScreenAnnotGetBackgroundColorCompNum(TRN_ScreenAnnot s, int* result);
TRN_API TRN_ScreenAnnotGetBackgroundColor(TRN_ScreenAnnot s, TRN_ColorPt* result); 
TRN_API TRN_ScreenAnnotSetBackgroundColor(TRN_ScreenAnnot s, const TRN_ColorPt* col, int numcomp);
TRN_API TRN_ScreenAnnotGetStaticCaptionText(TRN_ScreenAnnot s, TRN_UString* result);
TRN_API TRN_ScreenAnnotSetStaticCaptionText(TRN_ScreenAnnot s, TRN_UString contents);
TRN_API TRN_ScreenAnnotGetRolloverCaptionText(TRN_ScreenAnnot s, TRN_UString* result);
TRN_API TRN_ScreenAnnotSetRolloverCaptionText(TRN_ScreenAnnot s, TRN_UString contents);
TRN_API TRN_ScreenAnnotGetMouseDownCaptionText(TRN_ScreenAnnot s, TRN_UString* result);
TRN_API TRN_ScreenAnnotSetMouseDownCaptionText(TRN_ScreenAnnot s, TRN_UString contents);
TRN_API TRN_ScreenAnnotGetStaticIcon(TRN_ScreenAnnot s,TRN_Obj* result);
TRN_API TRN_ScreenAnnotSetStaticIcon(TRN_ScreenAnnot s, TRN_Obj icon);
TRN_API TRN_ScreenAnnotGetRolloverIcon(TRN_ScreenAnnot s,TRN_Obj* result);
TRN_API TRN_ScreenAnnotSetRolloverIcon(TRN_ScreenAnnot s, TRN_Obj icon);
TRN_API TRN_ScreenAnnotGetMouseDownIcon(TRN_ScreenAnnot s,TRN_Obj* result);
TRN_API TRN_ScreenAnnotSetMouseDownIcon(TRN_ScreenAnnot s, TRN_Obj icon);
TRN_API TRN_ScreenAnnotGetScaleType(TRN_ScreenAnnot s, enum TRN_ScreenAnnotScaleType* result);
TRN_API TRN_ScreenAnnotSetScaleType(TRN_ScreenAnnot s, enum TRN_ScreenAnnotScaleType st);
TRN_API TRN_ScreenAnnotGetIconCaptionRelation(TRN_ScreenAnnot s, enum TRN_ScreenAnnotIconCaptionRelation* result);
TRN_API TRN_ScreenAnnotSetIconCaptionRelation(TRN_ScreenAnnot s, enum TRN_ScreenAnnotIconCaptionRelation icr);
TRN_API TRN_ScreenAnnotGetScaleCondition(TRN_ScreenAnnot s, enum TRN_ScreenAnnotScaleCondition* result);
TRN_API TRN_ScreenAnnotSetScaleCondition(TRN_ScreenAnnot s, enum TRN_ScreenAnnotScaleCondition sc);
TRN_API TRN_ScreenAnnotGetFitFull(const TRN_ScreenAnnot s, TRN_Bool* result);
TRN_API TRN_ScreenAnnotSetFitFull(TRN_ScreenAnnot s, TRN_Bool ff);
TRN_API TRN_ScreenAnnotGetHIconLeftOver(TRN_ScreenAnnot s, double* result);
TRN_API TRN_ScreenAnnotSetHIconLeftOver(TRN_ScreenAnnot s, double hl);
TRN_API TRN_ScreenAnnotGetVIconLeftOver(TRN_ScreenAnnot s, double* result);
TRN_API TRN_ScreenAnnotSetVIconLeftOver(TRN_ScreenAnnot s, double vl);



enum TRN_SoundAnnotIcon
{
	e_SoundAnnot_Speaker,
	e_SoundAnnot_Mic,
	e_SoundAnnot_Unknown
};

TRN_API TRN_SoundAnnotCreateFromObj(TRN_Obj d, TRN_SoundAnnot* result);
TRN_API TRN_SoundAnnotCreateFromAnnot(TRN_Annot ann, TRN_SoundAnnot* result);
TRN_API TRN_SoundAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_SoundAnnot* result);
TRN_API TRN_SoundAnnotCreateWithData(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_Filter no_own_stream, int sample_bits, int sample_freq, int num_channels, TRN_SoundAnnot* result);
TRN_API TRN_SoundAnnotCreateAtPoint(TRN_SDFDoc doc, const TRN_Point* pos, TRN_SoundAnnot* result);
TRN_API TRN_SoundAnnotGetSoundStream(TRN_SoundAnnot sound,TRN_Obj* result);
TRN_API TRN_SoundAnnotSetSoundStream(TRN_SoundAnnot sound, TRN_Obj icon);
TRN_API TRN_SoundAnnotGetIcon(TRN_SoundAnnot sound, enum TRN_SoundAnnotIcon* result);
TRN_API TRN_SoundAnnotSetIcon(TRN_SoundAnnot sound, enum TRN_SoundAnnotIcon type);
TRN_API TRN_SoundAnnotGetIconName(TRN_SoundAnnot sound, const char** result);
TRN_API TRN_SoundAnnotSetIconName(TRN_SoundAnnot sound, const char* type);

TRN_API TRN_SquareAnnotCreateFromObj(TRN_Obj d, TRN_SquareAnnot* result);
TRN_API TRN_SquareAnnotCreateFromAnnot(TRN_Annot ann, TRN_SquareAnnot* result);
TRN_API TRN_SquareAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_SquareAnnot* result);
TRN_API TRN_SquareAnnotGetInteriorColor(TRN_SquareAnnot square, TRN_ColorPt* result);
TRN_API TRN_SquareAnnotGetInteriorColorCompNum(TRN_SquareAnnot square, int* result);
TRN_API TRN_SquareAnnotSetInteriorColorDefault(TRN_SquareAnnot square, const TRN_ColorPt* col);
TRN_API TRN_SquareAnnotSetInteriorColor(TRN_SquareAnnot square, const TRN_ColorPt* col, int numcomp);
TRN_API TRN_SquareAnnotGetContentRect(TRN_SquareAnnot square, TRN_Rect* result);
TRN_API TRN_SquareAnnotSetContentRect(TRN_SquareAnnot square, const TRN_Rect* cr);
TRN_API TRN_SquareAnnotGetPadding(TRN_SquareAnnot square, TRN_Rect* result);
TRN_API TRN_SquareAnnotSetPadding(TRN_SquareAnnot square, const TRN_Rect* cr);

TRN_API TRN_SquigglyAnnotCreateFromObj(TRN_Obj d, TRN_SquigglyAnnot* result);
TRN_API TRN_SquigglyAnnotCreateFromAnnot(TRN_Annot ann, TRN_SquigglyAnnot* result);
TRN_API TRN_SquigglyAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_SquigglyAnnot* result);

TRN_API TRN_StrikeOutAnnotCreateFromObj(TRN_Obj d, TRN_StrikeOutAnnot* result);
TRN_API TRN_StrikeOutAnnotCreateFromAnnot(TRN_Annot ann, TRN_StrikeOutAnnot* result);
TRN_API TRN_StrikeOutAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_StrikeOutAnnot* result);


enum TRN_TextAnnotIcon //Corresponding to the "name" attribute.
{
	e_TextAnnot_Comment,
	e_TextAnnot_Key,							
	e_TextAnnot_Help,
	e_TextAnnot_NewParagraph,
	e_TextAnnot_Paragraph,
	e_TextAnnot_Insert,
	e_TextAnnot_Note,
	e_TextAnnot_Unknown //This corresponds to user defined names.							 
};


TRN_API TRN_TextAnnotCreateFromObj(TRN_Obj d, TRN_TextAnnot* result);
TRN_API TRN_TextAnnotCreateFromAnnot(TRN_Annot ann, TRN_TextAnnot* result);
TRN_API TRN_TextAnnotCreateAtPoint(TRN_SDFDoc doc, const TRN_Point* pos, TRN_TextAnnot* result);
TRN_API TRN_TextAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_TextAnnot* result);
TRN_API TRN_TextAnnotIsOpen(TRN_TextAnnot text, TRN_Bool* result);
TRN_API TRN_TextAnnotSetOpen(TRN_TextAnnot text, TRN_Bool isopen);
TRN_API TRN_TextAnnotGetIcon(TRN_TextAnnot text, enum TRN_TextAnnotIcon* result);
TRN_API TRN_TextAnnotSetIcon(TRN_TextAnnot text, enum TRN_TextAnnotIcon icon);
TRN_API TRN_TextAnnotSetIconDefault(TRN_TextAnnot text);
TRN_API TRN_TextAnnotGetIconName(TRN_TextAnnot text, const char** result);
TRN_API TRN_TextAnnotSetIconName(TRN_TextAnnot text, const char* icon);
TRN_API TRN_TextAnnotGetState(TRN_TextAnnot text, TRN_UString* result);
TRN_API TRN_TextAnnotSetState(TRN_TextAnnot text, TRN_UString state);
TRN_API TRN_TextAnnotGetStateModel(TRN_TextAnnot text, TRN_UString* result);
TRN_API TRN_TextAnnotSetStateModel(TRN_TextAnnot text, TRN_UString sm);


TRN_API TRN_UnderlineAnnotCreateFromObj(TRN_Obj d, TRN_UnderlineAnnot* result); 
TRN_API TRN_UnderlineAnnotCreateFromAnnot(TRN_Annot ann, TRN_UnderlineAnnot* result);
TRN_API TRN_UnderlineAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_UnderlineAnnot* result);

TRN_API TRN_WatermarkAnnotCreateFromObj(TRN_Obj d, TRN_WatermarkAnnot* result);
TRN_API TRN_WatermarkAnnotCreateFromAnnot(TRN_Annot ann, TRN_WatermarkAnnot* result);
TRN_API TRN_WatermarkAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_WatermarkAnnot* result);

TRN_API TRN_TextMarkupAnnotCreateFromObj(TRN_Obj d, TRN_TextMarkupAnnot* result);
TRN_API TRN_TextMarkupAnnotCreateFromAnnot(TRN_Annot ann, TRN_TextMarkupAnnot* result);
TRN_API TRN_TextMarkupAnnotGetQuadPointCount(TRN_TextMarkupAnnot textmarkup, int* result);
TRN_API TRN_TextMarkupAnnotGetQuadPoint(TRN_TextMarkupAnnot textmarkup, int idx, TRN_QuadPoint* result); 
TRN_API TRN_TextMarkupAnnotSetQuadPoint(TRN_TextMarkupAnnot textmarkup, int idx, const TRN_QuadPoint* qp);

enum TRN_WidgetAnnotHighlightingMode
{
	e_WidgetAnnot_none,
	e_WidgetAnnot_invert,
	e_WidgetAnnot_outline,
	e_WidgetAnnot_push,
	e_WidgetAnnot_toggle
};

enum TRN_WidgetAnnotScaleType
{
	e_WidgetAnnot_Anamorphic,
	e_WidgetAnnot_Proportional
};

enum TRN_WidgetAnnotIconCaptionRelation
{
	e_WidgetAnnot_NoIcon,
	e_WidgetAnnot_NoCaption,
	e_WidgetAnnot_CBelowI,
	e_WidgetAnnot_CAboveI,
	e_WidgetAnnot_CRightILeft,
	e_WidgetAnnot_CLeftIRight,
	e_WidgetAnnot_COverlayI
};

enum TRN_WidgetAnnotScaleCondition
{
	e_WidgetAnnot_Always,
	e_WidgetAnnot_WhenBigger,
	e_WidgetAnnot_WhenSmaller,
	e_WidgetAnnot_Never
};

TRN_API TRN_WidgetAnnotCreate(TRN_SDFDoc doc, const TRN_Rect* pos, TRN_Field* field, TRN_WidgetAnnot* result);
TRN_API TRN_WidgetAnnotCreateFromObj(TRN_Obj d, TRN_WidgetAnnot* result);
TRN_API TRN_WidgetAnnotCreateFromAnnot(TRN_Annot ann, TRN_WidgetAnnot* result);
TRN_API TRN_WidgetAnnotGetField(TRN_WidgetAnnot widget, TRN_Field* result);
TRN_API TRN_WidgetAnnotGetHighlightingMode(TRN_WidgetAnnot widget, enum TRN_WidgetAnnotHighlightingMode* result);
TRN_API TRN_WidgetAnnotSetHighlightingMode(TRN_WidgetAnnot widget, enum TRN_WidgetAnnotHighlightingMode value);
TRN_API TRN_WidgetAnnotGetAction(TRN_WidgetAnnot widget, TRN_Action* result);
TRN_API TRN_WidgetAnnotSetAction(TRN_WidgetAnnot widget, TRN_Action action);
TRN_API TRN_WidgetAnnotGetBorderColor(TRN_WidgetAnnot widget, TRN_ColorPt* result);
TRN_API TRN_WidgetAnnotSetBorderColor(TRN_WidgetAnnot widget, const TRN_ColorPt* col, int compnum);					
TRN_API TRN_WidgetAnnotGetBorderColorCompNum(TRN_WidgetAnnot widget, int* result);
TRN_API TRN_WidgetAnnotGetBackgroundColorCompNum(TRN_WidgetAnnot widget, int* result);
TRN_API TRN_WidgetAnnotGetBackgroundColor(TRN_WidgetAnnot widget, TRN_ColorPt* result); 
TRN_API TRN_WidgetAnnotSetBackgroundColor(TRN_WidgetAnnot widget, const TRN_ColorPt* col, int compnum);
TRN_API TRN_WidgetAnnotGetStaticCaptionText(TRN_WidgetAnnot widget, TRN_UString* result);
TRN_API TRN_WidgetAnnotSetStaticCaptionText(TRN_WidgetAnnot widget, TRN_UString contents);
TRN_API TRN_WidgetAnnotGetRolloverCaptionText(TRN_WidgetAnnot widget, TRN_UString* result);
TRN_API TRN_WidgetAnnotSetRolloverCaptionText(TRN_WidgetAnnot widget, TRN_UString contents);
TRN_API TRN_WidgetAnnotGetMouseDownCaptionText(TRN_WidgetAnnot widget, TRN_UString* result);
TRN_API TRN_WidgetAnnotSetMouseDownCaptionText(TRN_WidgetAnnot widget, TRN_UString contents);
TRN_API TRN_WidgetAnnotGetStaticIcon(TRN_WidgetAnnot widget,TRN_Obj* result);
TRN_API TRN_WidgetAnnotSetStaticIcon(TRN_WidgetAnnot widget, TRN_Obj icon);
TRN_API TRN_WidgetAnnotGetRolloverIcon(TRN_WidgetAnnot widget,TRN_Obj* result);
TRN_API TRN_WidgetAnnotSetRolloverIcon(TRN_WidgetAnnot widget, TRN_Obj icon);
TRN_API TRN_WidgetAnnotGetMouseDownIcon(TRN_WidgetAnnot widget,TRN_Obj* result);
TRN_API TRN_WidgetAnnotSetMouseDownIcon(TRN_WidgetAnnot widget, TRN_Obj icon);
TRN_API TRN_WidgetAnnotGetScaleType(TRN_WidgetAnnot widget, enum TRN_WidgetAnnotScaleType* result);
TRN_API TRN_WidgetAnnotSetScaleType(TRN_WidgetAnnot widget, enum TRN_WidgetAnnotScaleType st);
TRN_API TRN_WidgetAnnotGetIconCaptionRelation(TRN_WidgetAnnot widget, enum TRN_WidgetAnnotIconCaptionRelation* result);
TRN_API TRN_WidgetAnnotSetIconCaptionRelation(TRN_WidgetAnnot widget, enum TRN_WidgetAnnotIconCaptionRelation icr);
TRN_API TRN_WidgetAnnotGetScaleCondition(TRN_WidgetAnnot widget, enum TRN_WidgetAnnotScaleCondition* result);
TRN_API TRN_WidgetAnnotSetScaleCondition(TRN_WidgetAnnot widget, enum TRN_WidgetAnnotScaleCondition sd);
TRN_API TRN_WidgetAnnotGetFitFull(const TRN_WidgetAnnot widget, TRN_Bool* result);
TRN_API TRN_WidgetAnnotSetFitFull(TRN_WidgetAnnot widget, TRN_Bool ff);
TRN_API TRN_WidgetAnnotGetHIconLeftOver(TRN_WidgetAnnot widget, double* result);
TRN_API TRN_WidgetAnnotSetHIconLeftOver(TRN_WidgetAnnot widget, double hl);
TRN_API TRN_WidgetAnnotGetVIconLeftOver(TRN_WidgetAnnot widget, double* result);
TRN_API TRN_WidgetAnnotSetVIconLeftOver(TRN_WidgetAnnot widget, double vl);
TRN_API TRN_WidgetAnnotSetFontSize(TRN_WidgetAnnot widget, double font_size);
TRN_API TRN_WidgetAnnotSetTextColor(TRN_WidgetAnnot widget, const TRN_ColorPt* color, int col_comp);
TRN_API TRN_WidgetAnnotSetFont(TRN_WidgetAnnot widget, const TRN_Font font);
TRN_API TRN_WidgetAnnotGetFontSize(TRN_WidgetAnnot widget, double* result);
TRN_API TRN_WidgetAnnotGetTextColor(TRN_WidgetAnnot widget, TRN_ColorPt* out_col, int* out_col_comp);
TRN_API TRN_WidgetAnnotGetFont(TRN_WidgetAnnot widget, TRN_Font* result);

TRN_API TRN_SignatureWidgetCreate(TRN_PDFDoc doc, const TRN_Rect* pos, TRN_UString field_name, TRN_SignatureWidget* result);
TRN_API TRN_SignatureWidgetCreateWithField(TRN_PDFDoc doc, const TRN_Rect* pos, const TRN_Field* field, TRN_SignatureWidget* result);
TRN_API TRN_SignatureWidgetCreateWithDigitalSignatureField(TRN_PDFDoc doc, const TRN_Rect* pos, const TRN_DigitalSignatureField* field, TRN_SignatureWidget* result);
TRN_API TRN_SignatureWidgetCreateFromObj(TRN_Obj d, TRN_SignatureWidget* result);
TRN_API TRN_SignatureWidgetCreateFromAnnot(TRN_Annot annot, TRN_SignatureWidget* result);
TRN_API TRN_SignatureWidgetCreateSignatureAppearance(TRN_SignatureWidget self, TRN_Image img);
TRN_API TRN_SignatureWidgetGetDigitalSignatureField(TRN_SignatureWidget self, TRN_DigitalSignatureField* result);

TRN_API TRN_ComboBoxWidgetCreate(TRN_PDFDoc doc, const TRN_Rect* pos, TRN_UString field_name, TRN_ComboBoxWidget* result);
TRN_API TRN_ComboBoxWidgetCreateWithField(TRN_PDFDoc doc, const TRN_Rect* pos, const TRN_Field* field, TRN_ComboBoxWidget* result);
TRN_API TRN_ComboBoxWidgetCreateFromObj(TRN_Obj d, TRN_ComboBoxWidget* result);
TRN_API TRN_ComboBoxWidgetCreateFromAnnot(TRN_Annot annot, TRN_ComboBoxWidget* result);
TRN_API TRN_ComboBoxWidgetAddOption(TRN_ComboBoxWidget combobox, TRN_UString value);
TRN_API TRN_ComboBoxWidgetAddOptions(TRN_ComboBoxWidget combobox, TRN_UString* opts_list, TRN_UInt32 opts_list_size);
TRN_API TRN_ComboBoxWidgetSetSelectedOption(TRN_ComboBoxWidget combobox, TRN_UString value);
TRN_API TRN_ComboBoxWidgetGetSelectedOption(TRN_ComboBoxWidget combobox, TRN_UString* result);
TRN_API TRN_ComboBoxWidgetGetOptions(TRN_ComboBoxWidget combobox, TRN_Vector* result);
TRN_API TRN_ComboBoxWidgetReplaceOptions(TRN_ComboBoxWidget combobox, TRN_UString* new_opts_list, TRN_UInt32 new_opts_list_size);
TRN_API TRN_ComboBoxWidgetRemoveOption(TRN_ComboBoxWidget combobox, TRN_UString value);

TRN_API TRN_ListBoxWidgetCreate(TRN_PDFDoc doc, const TRN_Rect* pos, TRN_UString field_name, TRN_ListBoxWidget* result);
TRN_API TRN_ListBoxWidgetCreateWithField(TRN_PDFDoc doc, const TRN_Rect* pos, const TRN_Field* field, TRN_ListBoxWidget* result);
TRN_API TRN_ListBoxWidgetCreateFromObj(TRN_Obj d, TRN_ListBoxWidget* result);
TRN_API TRN_ListBoxWidgetCreateFromAnnot(TRN_Annot annot, TRN_ListBoxWidget* result);
TRN_API TRN_ListBoxWidgetAddOption(TRN_ListBoxWidget listbox, TRN_UString value);
TRN_API TRN_ListBoxWidgetAddOptions(TRN_ListBoxWidget listbox, TRN_UString* opts_list, TRN_UInt32 opts_list_size);
TRN_API TRN_ListBoxWidgetSetSelectedOptions(TRN_ListBoxWidget listbox, TRN_UString* selected_opts_list, TRN_UInt32 selected_opts_list_size);
TRN_API TRN_ListBoxWidgetGetSelectedOptions(TRN_ListBoxWidget listbox, TRN_Vector* result);
TRN_API TRN_ListBoxWidgetGetOptions(TRN_ListBoxWidget listbox, TRN_Vector* result);
TRN_API TRN_ListBoxWidgetReplaceOptions(TRN_ListBoxWidget listbox, TRN_UString* new_opts_list, TRN_UInt32 new_opts_list_size);
TRN_API TRN_ListBoxWidgetRemoveOption(TRN_ListBoxWidget listbox, TRN_UString value);


TRN_API TRN_TextWidgetCreate(TRN_PDFDoc doc, const TRN_Rect* pos, TRN_UString field_name, TRN_TextWidget* result);
TRN_API TRN_TextWidgetCreateWithField(TRN_PDFDoc doc, const TRN_Rect* pos, const TRN_Field* field, TRN_TextWidget* result);
TRN_API TRN_TextWidgetCreateFromObj(TRN_Obj d, TRN_TextWidget* result);
TRN_API TRN_TextWidgetCreateFromAnnot(TRN_Annot annot, TRN_TextWidget* result);
TRN_API TRN_TextWidgetSetText(TRN_TextWidget widget, TRN_UString text);
TRN_API TRN_TextWidgetGetText(TRN_TextWidget widget, TRN_UString* result);

TRN_API TRN_CheckBoxWidgetCreate(TRN_PDFDoc doc, const TRN_Rect* pos, TRN_UString field_name, TRN_CheckBoxWidget* result);
TRN_API TRN_CheckBoxWidgetCreateWithField(TRN_PDFDoc doc, const TRN_Rect* pos, const TRN_Field* field, TRN_CheckBoxWidget* result);
TRN_API TRN_CheckBoxWidgetCreateFromObj(TRN_Obj d, TRN_CheckBoxWidget* result);
TRN_API TRN_CheckBoxWidgetCreateFromAnnot(TRN_Annot annot, TRN_CheckBoxWidget* result);
TRN_API TRN_CheckBoxWidgetIsChecked(TRN_CheckBoxWidget button, TRN_Bool* result);
TRN_API TRN_CheckBoxWidgetSetChecked(TRN_CheckBoxWidget button, TRN_Bool checked);

TRN_API TRN_RadioButtonWidgetCreateFromObj(TRN_Obj d, TRN_RadioButtonWidget* result);
TRN_API TRN_RadioButtonWidgetCreateFromAnnot(TRN_Annot annot, TRN_RadioButtonWidget* result);
TRN_API TRN_RadioButtonWidgetIsEnabled(TRN_RadioButtonWidget button, TRN_Bool* result);
TRN_API TRN_RadioButtonWidgetEnableButton(TRN_RadioButtonWidget button);
TRN_API TRN_RadioButtonWidgetGetGroup(TRN_RadioButtonWidget button, TRN_RadioButtonGroup* result);

TRN_API TRN_PushButtonWidgetCreate(TRN_PDFDoc doc, const TRN_Rect* pos, TRN_UString field_name, TRN_PushButtonWidget* result);
TRN_API TRN_PushButtonWidgetCreateWithField(TRN_PDFDoc doc, const TRN_Rect* pos, const TRN_Field* field, TRN_PushButtonWidget* result);
TRN_API TRN_PushButtonWidgetCreateFromObj(TRN_Obj obj, TRN_PushButtonWidget* result);
TRN_API TRN_PushButtonWidgetCreateFromAnnot(TRN_Annot annot, TRN_PushButtonWidget* result);

#ifdef __cplusplus
}
#endif


#endif // PDFTRON_H_CPDFAnnot


