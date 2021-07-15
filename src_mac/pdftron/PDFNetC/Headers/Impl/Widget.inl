#ifndef HPP_PDFTRON_PDF_WIDGET_INL
#define HPP_PDFTRON_PDF_WIDGET_INL

#include <SDF/Obj.h>
//#include <PDF/Field.h>
//#include <PDF/Action.h>
#include <PDF/Annots.h>
//#include <PDF/Destination.h>
#include <PDF/Page.h>


namespace pdftron {
	namespace PDF {
		namespace Annots {


//Widget
inline Widget::Widget(SDF::Obj d):Annot(d)
{
	REX(TRN_WidgetAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Widget Widget::Create(SDF::SDFDoc& doc, const Rect& pos, Field field)
{
	TRN_Annot result;
	REX(TRN_WidgetAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, (TRN_Field*)&field, &result));
	return Widget(result);
}


inline Field Widget::GetField() const
{
	TRN_Field result;
	REX(TRN_WidgetAnnotGetField(mp_annot,&result));
	return *((Field*)&result);
}


//H
inline Widget::HighlightingMode Widget::GetHighlightingMode() const
{
	enum TRN_WidgetAnnotHighlightingMode result;
	REX(TRN_WidgetAnnotGetHighlightingMode(mp_annot,&result));
	return (HighlightingMode)result;
}

inline void Widget::SetHighlightingMode(HighlightingMode mode)
{
	REX(TRN_WidgetAnnotSetHighlightingMode(mp_annot,(enum TRN_WidgetAnnotHighlightingMode)mode));
}
		
//A
inline Action Widget::GetAction() const
{
	TRN_Action result;
	REX(TRN_WidgetAnnotGetAction(mp_annot,&result));
	return Action(result);
}

inline void Widget::SetAction(const Action& action)
{
	REX(TRN_WidgetAnnotSetAction(mp_annot,action.mp_action));
}

//BC
inline int Widget::GetBorderColorCompNum() const
{
	int result;
	REX(TRN_WidgetAnnotGetBorderColorCompNum(mp_annot, &result));
	return result;
}

inline ColorPt Widget::GetBorderColor() const
{
	RetCPT(TRN_WidgetAnnotGetBorderColor(mp_annot, &result));
}

inline void Widget::SetBorderColor(const ColorPt& c, int CompNum)
{
	REX(TRN_WidgetAnnotSetBorderColor(mp_annot, &c.m_c, CompNum));
}

//BG
inline int Widget::GetBackgroundColorCompNum() const
{
	int result;
	REX(TRN_WidgetAnnotGetBackgroundColorCompNum(mp_annot, &result));
	return result;
}
inline ColorPt Widget::GetBackgroundColor() const
{
	RetCPT(TRN_WidgetAnnotGetBackgroundColor(mp_annot, &result));
}

inline void Widget::SetBackgroundColor(const ColorPt& c, int CompNum)
{
	REX(TRN_WidgetAnnotSetBackgroundColor(mp_annot, &c.m_c, CompNum));
}


//CA 
inline UString Widget::GetStaticCaptionText() const
{
	TRN_UString result;
	REX(TRN_WidgetAnnotGetStaticCaptionText(mp_annot,&result));
	return UString(result);	
}

inline void Widget::SetStaticCaptionText(const UString& ct)
{
	REX(TRN_WidgetAnnotSetStaticCaptionText(mp_annot,ct.mp_impl));
}

//RC
inline UString Widget::GetRolloverCaptionText() const
{
	TRN_UString result;
	REX(TRN_WidgetAnnotGetRolloverCaptionText(mp_annot,&result));
	return UString(result);
}
inline void Widget::SetRolloverCaptionText(const UString& ct)
{
	REX(TRN_WidgetAnnotSetRolloverCaptionText(mp_annot,ct.mp_impl));
}

//AC
inline UString Widget::GetMouseDownCaptionText() const
{
	TRN_UString result;
	REX(TRN_WidgetAnnotGetMouseDownCaptionText(mp_annot,&result));
	return UString(result);
}
inline void Widget::SetMouseDownCaptionText(const UString& ct)
{
	REX(TRN_WidgetAnnotSetMouseDownCaptionText(mp_annot, ct.mp_impl));
}


//I
inline SDF::Obj Widget::GetStaticIcon() const
{
	TRN_Obj result;
	REX(TRN_WidgetAnnotGetStaticIcon(mp_annot, &result));
	return SDF::Obj(result);
}

inline void Widget::SetStaticIcon(SDF::Obj ic)
{
	REX(TRN_WidgetAnnotSetStaticIcon(mp_annot, ic.mp_obj));
}

//RI
inline SDF::Obj Widget::GetRolloverIcon() const
{
	TRN_Obj result;
	REX(TRN_WidgetAnnotGetRolloverIcon(mp_annot, &result));
	return SDF::Obj(result);
}

inline void Widget::SetRolloverIcon(SDF::Obj ic)
{
	REX(TRN_WidgetAnnotSetRolloverIcon(mp_annot, ic.mp_obj));
}

//IX
inline SDF::Obj Widget::GetMouseDownIcon() const
{
	TRN_Obj result;
	REX(TRN_WidgetAnnotGetMouseDownIcon(mp_annot, &result));
	return SDF::Obj(result);
}

inline void Widget::SetMouseDownIcon(SDF::Obj ic)
{
	REX(TRN_WidgetAnnotSetMouseDownIcon(mp_annot, ic.mp_obj));
}



inline Widget::ScaleType Widget::GetScaleType() const
{
	enum TRN_WidgetAnnotScaleType result;
	REX(TRN_WidgetAnnotGetScaleType(mp_annot, &result));
	return (ScaleType)result;
}

inline void Widget::SetScaleType(ScaleType st)
{
	REX(TRN_WidgetAnnotSetScaleType(mp_annot,(enum TRN_WidgetAnnotScaleType)st));
}

inline Widget::IconCaptionRelation Widget::GetIconCaptionRelation() const
{
	enum TRN_WidgetAnnotIconCaptionRelation result;
	REX(TRN_WidgetAnnotGetIconCaptionRelation(mp_annot, &result));
	return (IconCaptionRelation)result;
}

inline void Widget::SetIconCaptionRelation(IconCaptionRelation icr)
{
	REX(TRN_WidgetAnnotSetIconCaptionRelation(mp_annot,(enum TRN_WidgetAnnotIconCaptionRelation)icr));
}


inline Widget::ScaleCondition Widget::GetScaleCondition() const
{
	enum TRN_WidgetAnnotScaleCondition result;
	REX(TRN_WidgetAnnotGetScaleCondition(mp_annot, &result));
	return (ScaleCondition)result;
}

inline void Widget::SetScaleCondition(ScaleCondition sd)
{
	REX(TRN_WidgetAnnotSetScaleCondition(mp_annot,(enum TRN_WidgetAnnotScaleCondition)sd));
}

//LO
inline double Widget::GetHIconLeftOver() const
{
	double result;
	REX(TRN_WidgetAnnotGetHIconLeftOver(mp_annot,&result));
	return result;
}
inline void Widget::SetHIconLeftOver(double hl)
{
	REX(TRN_WidgetAnnotSetHIconLeftOver(mp_annot, hl));
}
inline double Widget::GetVIconLeftOver() const
{
	double result;
	REX(TRN_WidgetAnnotGetVIconLeftOver(mp_annot,&result));
	return result;
}

inline void Widget::SetVIconLeftOver(double vl)
{
	REX(TRN_WidgetAnnotSetVIconLeftOver(mp_annot, vl));
}


//FB
inline bool Widget::GetFitFull() const
{
	TRN_Bool result;
	REX(TRN_WidgetAnnotGetFitFull(mp_annot,&result));
	return TBToB(result);
}

inline void Widget::SetFitFull(bool ff)
{
	REX(TRN_WidgetAnnotSetFitFull(mp_annot,BToTB(ff)));
}

inline void Widget::SetFontSize(double font_size)
{
	REX(TRN_WidgetAnnotSetFontSize(mp_annot, font_size));
}

inline void Widget::SetTextColor(const ColorPt& color, int col_comp)
{
	REX(TRN_WidgetAnnotSetTextColor(mp_annot, &color.m_c, col_comp));
}

inline void Widget::SetFont(const Font& font)
{
	REX(TRN_WidgetAnnotSetFont(mp_annot, font.mp_font));
}

inline double Widget::GetFontSize() const
{
	double result;
	REX(TRN_WidgetAnnotGetFontSize(mp_annot, &result));
	return result;
}

inline ColorPt Widget::GetTextColor()
{
	ColorPt color;
	int col_comp = 0;
	REX(TRN_WidgetAnnotGetTextColor(mp_annot, reinterpret_cast<TRN_ColorPt*>(&color), &col_comp));
	return color;
}

inline int Widget::GetTextColorCompNum()
{
	ColorPt color;
	int col_comp = 0;
	REX(TRN_WidgetAnnotGetTextColor(mp_annot, reinterpret_cast<TRN_ColorPt*>(&color), &col_comp));
	return col_comp;
}

inline Font Widget::GetFont() const
{
	TRN_Font result;
	REX(TRN_WidgetAnnotGetFont(mp_annot, &result));
	return Font(result);
}

inline Widget::Widget(TRN_Annot widget) : Annot(widget)
{
}

		};// namespace Annots
	};
};

#endif
