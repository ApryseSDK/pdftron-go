#ifndef CPPContentReplacer_INL
#define CPPContentReplacer_INL

#include <cassert>

namespace pdftron {
namespace PDF {

inline ContentReplacer::ContentReplacer()
{
	REX(TRN_ContentReplacerCreate(&mp_impl));
}

inline ContentReplacer::~ContentReplacer()
{
	DREX(mp_impl, TRN_ContentReplacerDestroy(mp_impl));
}

inline void ContentReplacer::Destroy() {
	REX(TRN_ContentReplacerDestroy(mp_impl));
	mp_impl=0;
}

inline void ContentReplacer::AddImage(const Rect& target_region, SDF::Obj replacement_image)
{
	REX(TRN_ContentReplacer_AddImage(mp_impl, (const TRN_Rect*)&target_region, replacement_image.mp_obj));
}

inline void ContentReplacer::AddText(const Rect& target_region, const UString& replacement_text)
{
	REX(TRN_ContentReplacer_AddText(mp_impl,(const TRN_Rect*)&target_region, replacement_text.mp_impl));
}

inline void ContentReplacer::AddString(const UString& template_text, const UString& replacement_text)
{
	REX(TRN_ContentReplacer_AddString(mp_impl, template_text.mp_impl, replacement_text.mp_impl));
}

inline void ContentReplacer::SetMatchStrings(const UString& start_str, const UString& end_str)
{
	REX(TRN_ContentReplacer_SetMatchStrings(mp_impl, start_str.mp_impl, end_str.mp_impl));
}

inline void ContentReplacer::Process(Page& page)
{
	REX(TRN_ContentReplacer_Process(mp_impl, page.mp_page));
}

}; // namespace PDF
}; // namespace pdftron

#endif // CPPContentReplacer_INL
