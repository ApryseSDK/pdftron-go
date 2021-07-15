#ifndef HPP_PDFTRON_PDF_MARKUP_INL
#define HPP_PDFTRON_PDF_MARKUP_INL

#include <SDF/Obj.h>
//#include <PDF/Field.h>
//#include <PDF/Action.h>
#include <PDF/Annots/Markup.h>
//#include <PDF/Destination.h>
#include <PDF/Page.h>


namespace pdftron {
	namespace PDF {
		namespace Annots {

//Markup
inline Markup::Markup(SDF::Obj d):Annot(d)
{
	REX(TRN_MarkupAnnotCreateFromObj(d.mp_obj, &mp_annot));
}

inline UString Markup::GetTitle(){
	RetStr(TRN_MarkupAnnotGetTitle(mp_annot,&result));
}

inline void Markup::SetTitle(const UString& title)
{
	REX(TRN_MarkupAnnotSetTitleUString(mp_annot, title.mp_impl));
}

inline void Markup::SetTitle(const char* title)
{
	REX(TRN_MarkupAnnotSetTitle(mp_annot, title));
}

//Popup
inline Popup Markup::GetPopup() const
{
	TRN_Annot result;
	REX(TRN_MarkupAnnotGetPopup(mp_annot,&result));
	return Annot(result);
}

inline void Markup::SetPopup(const Popup& bs)
{
	REX(TRN_MarkupAnnotSetPopup(mp_annot, bs.mp_annot));
}

//CA
inline double Markup::GetOpacity() const
{
	double result;
	REX(TRN_MarkupAnnotGetOpacity(mp_annot, &result)); 
	return result;
}

inline void Markup::SetOpacity(double op)
{
	REX(TRN_MarkupAnnotSetOpacity(mp_annot, op));
}

//Subj
inline UString Markup::GetSubject() const
{
	RetStr(TRN_MarkupAnnotGetSubject(mp_annot, &result));
}

inline void Markup::SetSubject(const UString& subj)
{
	REX(TRN_MarkupAnnotSetSubject(mp_annot, subj.mp_impl));
}

//CreationDate
inline Date Markup::GetCreationDates() const
{
	TRN_Date result;
	REX(TRN_MarkupAnnotGetCreationDates(mp_annot,&result));
	return *((Date*)&result);
}

inline void Markup::SetCreationDates(const Date& dt)
{
	REX(TRN_MarkupAnnotSetCreationDates(mp_annot,(const TRN_Date*)&dt));
}

//BE
inline Markup::BorderEffect Markup::GetBorderEffect() const
{
	enum TRN_MarkupAnnotBorderEffect result;
	REX(TRN_MarkupAnnotGetBorderEffect(mp_annot,&result));
	return (BorderEffect)result;
}

inline void Markup::SetBorderEffect(Markup::BorderEffect effect)
{
	REX(TRN_MarkupAnnotSetBorderEffect(mp_annot,(enum TRN_MarkupAnnotBorderEffect)effect));
}


//BEI
inline double Markup::GetBorderEffectIntensity() const
{
	double result;
	REX(TRN_MarkupAnnotGetBorderEffectIntensity(mp_annot, &result)); 
	return result;
}
inline void Markup::SetBorderEffectIntensity(double intensity)
{
	REX(TRN_MarkupAnnotSetBorderEffectIntensity(mp_annot, intensity));
}

inline Markup::Markup(TRN_Annot markup) : Annot(markup)
{
	
}


//IC 						
inline ColorPt Markup::GetInteriorColor() const
{
	RetCPT(TRN_MarkupAnnotGetInteriorColor(mp_annot, &result));
}

inline int Markup::GetInteriorColorCompNum() const
{ 
	//return GetColorCompNumUtil();
	int result;
	REX(TRN_MarkupAnnotGetInteriorColorCompNum(mp_annot, &result));
	return result;
}

inline void Markup::SetInteriorColor(const ColorPt& c, int CompNum)
{
	//SetColorUtil(c, CompNum);
	REX(TRN_MarkupAnnotSetInteriorColor(mp_annot, &c.m_c, CompNum));
}


//RD
inline Rect Markup::GetContentRect() const
{
	TRN_Rect result;
	REX(TRN_MarkupAnnotGetContentRect(mp_annot, &result));
	return *((Rect*)&result);
}

inline void Markup::SetContentRect(const Rect& cr)
{
	REX(TRN_MarkupAnnotSetContentRect(mp_annot,(const TRN_Rect*)&cr));
}

//RD
inline Rect Markup::GetPadding() const
{
	TRN_Rect result;
	REX(TRN_MarkupAnnotGetPadding(mp_annot, &result));
	return *((Rect*)&result);
}

inline void Markup::SetPadding(const Rect& rd)
{
	REX(TRN_MarkupAnnotSetPadding(mp_annot,(const TRN_Rect*)&rd));
}					

inline void Markup::SetPadding( double d )
{
	Rect r(d,d,d,d);
	this->SetPadding(r);
}					

inline void Markup::RotateAppearance(double angle)
{
	REX(TRN_MarkupAnnotRotateAppearance(mp_annot, angle));
}

		} // namespace Annots
	}
}

#endif
