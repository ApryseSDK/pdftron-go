#ifndef HPP_PDFTRON_PDF_SCREEN_INL
#define HPP_PDFTRON_PDF_SCREEN_INL

#include <SDF/Obj.h>
//#include <PDF/Field.h>
//#include <PDF/Action.h>
#include <PDF/Annots/Screen.h>
//#include <PDF/Destination.h>
#include <PDF/Page.h>


namespace pdftron {
	namespace PDF {
		namespace Annots {


//Screen
inline Screen::Screen(SDF::Obj d):Annot(d)
{
	REX(TRN_ScreenAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline Screen Screen::Create(SDF::SDFDoc& doc, const Rect& pos)
{
	TRN_Annot result;
	REX(TRN_ScreenAnnotCreate(doc.mp_doc,(const TRN_Rect*)&pos, &result));
	return Screen(result);
}

//T
inline UString Screen::GetTitle() const
{
	RetStr(TRN_ScreenAnnotGetTitle(mp_annot, &result));
}

inline void Screen::SetTitle(const UString& title)
{
	REX(TRN_ScreenAnnotSetTitle(mp_annot, title.mp_impl));
}

//A
inline Action Screen::GetAction() const
{
	TRN_Action result;
	REX(TRN_ScreenAnnotGetAction(mp_annot,&result));
	return Action(result);
}

inline void Screen::SetAction(const Action& action)
{
	REX(TRN_ScreenAnnotSetAction(mp_annot,action.mp_action));
}

//BC
inline int Screen::GetBorderColorCompNum() const
{
	int result;
	REX(TRN_ScreenAnnotGetBorderColorCompNum(mp_annot, &result));
	return result;
}

inline ColorPt Screen::GetBorderColor() const
{
	RetCPT(TRN_ScreenAnnotGetBorderColor(mp_annot, &result));
}

inline void Screen::SetBorderColor(const ColorPt& c, int CompNum)
{
	REX(TRN_ScreenAnnotSetBorderColor(mp_annot, &c.m_c, CompNum));
}

//BG
inline int Screen::GetBackgroundColorCompNum() const
{
	int result;
	REX(TRN_ScreenAnnotGetBackgroundColorCompNum(mp_annot, &result));
	return result;
}
inline ColorPt Screen::GetBackgroundColor() const
{
	RetCPT(TRN_ScreenAnnotGetBackgroundColor(mp_annot, &result));
}

inline void Screen::SetBackgroundColor(const ColorPt& c, int CompNum)
{
	REX(TRN_ScreenAnnotSetBackgroundColor(mp_annot, &c.m_c, CompNum));
}


//CA 
inline UString Screen::GetStaticCaptionText() const
{
	TRN_UString result;
	REX(TRN_ScreenAnnotGetStaticCaptionText(mp_annot,&result));
	return UString(result);	
}

inline void Screen::SetStaticCaptionText(const UString& ct)
{
	REX(TRN_ScreenAnnotSetStaticCaptionText(mp_annot,ct.mp_impl));
}

//RC
inline UString Screen::GetRolloverCaptionText() const
{
	TRN_UString result;
	REX(TRN_ScreenAnnotGetRolloverCaptionText(mp_annot,&result));
	return UString(result);
}
inline void Screen::SetRolloverCaptionText(const UString& ct)
{
	REX(TRN_ScreenAnnotSetRolloverCaptionText(mp_annot,ct.mp_impl));
}

//AC
inline UString Screen::GetMouseDownCaptionText() const
{
	TRN_UString result;
	REX(TRN_ScreenAnnotGetMouseDownCaptionText(mp_annot,&result));
	return UString(result);
}
inline void Screen::SetMouseDownCaptionText(const UString& ct)
{
	REX(TRN_ScreenAnnotSetMouseDownCaptionText(mp_annot, ct.mp_impl));
}


//I
inline SDF::Obj Screen::GetStaticIcon() const
{
	TRN_Obj result;
	REX(TRN_ScreenAnnotGetStaticIcon(mp_annot, &result));
	return SDF::Obj(result);
}

inline void Screen::SetStaticIcon(SDF::Obj ic)
{
	REX(TRN_ScreenAnnotSetStaticIcon(mp_annot, ic.mp_obj));
}

//RI
inline SDF::Obj Screen::GetRolloverIcon() const
{
	TRN_Obj result;
	REX(TRN_ScreenAnnotGetRolloverIcon(mp_annot, &result));
	return SDF::Obj(result);
}

inline void Screen::SetRolloverIcon(SDF::Obj ic)
{
	REX(TRN_ScreenAnnotSetRolloverIcon(mp_annot, ic.mp_obj));
}

//IX
inline SDF::Obj Screen::GetMouseDownIcon() const
{
	TRN_Obj result;
	REX(TRN_ScreenAnnotGetMouseDownIcon(mp_annot, &result));
	return SDF::Obj(result);
}

inline void Screen::SetMouseDownIcon(SDF::Obj ic)
{
	REX(TRN_ScreenAnnotSetMouseDownIcon(mp_annot, ic.mp_obj));
}



inline Screen::ScaleType Screen::GetScaleType() const
{
	enum TRN_ScreenAnnotScaleType result;
	REX(TRN_ScreenAnnotGetScaleType(mp_annot, &result));
	return (ScaleType)result;
}

inline void Screen::SetScaleType(ScaleType st)
{
	REX(TRN_ScreenAnnotSetScaleType(mp_annot,(enum TRN_ScreenAnnotScaleType)st));
}

inline Screen::IconCaptionRelation Screen::GetIconCaptionRelation() const
{
	enum TRN_ScreenAnnotIconCaptionRelation result;
	REX(TRN_ScreenAnnotGetIconCaptionRelation(mp_annot, &result));
	return (IconCaptionRelation)result;
}

inline void Screen::SetIconCaptionRelation(IconCaptionRelation icr)
{
	REX(TRN_ScreenAnnotSetIconCaptionRelation(mp_annot,(enum TRN_ScreenAnnotIconCaptionRelation)icr));
}


inline Screen::ScaleCondition Screen::GetScaleCondition() const
{
	enum TRN_ScreenAnnotScaleCondition result;
	REX(TRN_ScreenAnnotGetScaleCondition(mp_annot, &result));
	return (ScaleCondition)result;
}

inline void Screen::SetScaleCondition(ScaleCondition sd)
{
	REX(TRN_ScreenAnnotSetScaleCondition(mp_annot,(enum TRN_ScreenAnnotScaleCondition)sd));
}

//LO
inline double Screen::GetHIconLeftOver() const
{
	double result;
	REX(TRN_ScreenAnnotGetHIconLeftOver(mp_annot,&result));
	return result;
}
inline void Screen::SetHIconLeftOver(double hl)
{
	REX(TRN_ScreenAnnotSetHIconLeftOver(mp_annot, hl));
}
inline double Screen::GetVIconLeftOver() const
{
	double result;
	REX(TRN_ScreenAnnotGetVIconLeftOver(mp_annot,&result));
	return result;
}

inline void Screen::SetVIconLeftOver(double vl)
{
	REX(TRN_ScreenAnnotSetVIconLeftOver(mp_annot, vl));
}


//FB
inline bool Screen::GetFitFull() const
{
	TRN_Bool result;
	REX(TRN_ScreenAnnotGetFitFull(mp_annot,&result));
	return TBToB(result);
}
				
inline void Screen::SetFitFull(bool ff)
{
	REX(TRN_ScreenAnnotSetFitFull(mp_annot,BToTB(ff)));
}
	
inline Screen::Screen(TRN_Annot Screen) : Annot(Screen)
{
}

		};// namespace Annots
	};
};

#endif
