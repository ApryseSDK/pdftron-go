
#include <C/PDF/TRN_RadioButtonGroup.h>

namespace pdftron {
	namespace PDF {
		namespace Annots {


inline RadioButtonWidget::RadioButtonWidget(SDF::Obj d) : Widget(d)
{

}

inline RadioButtonWidget::RadioButtonWidget(const Annot& annot) : Widget(annot.GetSDFObj())
{

}

inline RadioButtonGroup RadioButtonWidget::GetGroup()
{
	TRN_RadioButtonGroup result;
	REX(TRN_RadioButtonWidgetGetGroup(mp_annot, &result));
	return RadioButtonGroup(result);
}

inline void RadioButtonWidget::EnableButton()
{
	REX(TRN_RadioButtonWidgetEnableButton(mp_annot));
}

inline bool RadioButtonWidget::IsEnabled()
{
	RetBool(TRN_RadioButtonWidgetIsEnabled(mp_annot, &result));
}


inline RadioButtonGroup::RadioButtonGroup(const Field& field)
{
	REX(TRN_RadioButtonGroupCreateFromField(&field.mp_field,&mp_group))
}

inline RadioButtonGroup::RadioButtonGroup(const RadioButtonGroup& other)
{
	REX(TRN_RadioButtonGroupCopy(other.mp_group, &mp_group));
}

inline RadioButtonGroup& RadioButtonGroup::operator=(const RadioButtonGroup& other)
{
	REX(TRN_RadioButtonGroupAssign(mp_group, other.mp_group));
	return *this;
}

inline RadioButtonGroup RadioButtonGroup::Create(PDFDoc& doc, const UString& field_name)
{
	TRN_RadioButtonGroup group;
	REX(TRN_RadioButtonGroupCreate(doc.mp_doc, field_name.mp_impl, &group));
	return RadioButtonGroup(group);
}

inline RadioButtonGroup::~RadioButtonGroup()
{
	TRN_RadioButtonGroupDestroy(mp_group);
}

inline RadioButtonWidget RadioButtonGroup::Add(const Rect& pos, const char* onstate)
{
	TRN_RadioButtonWidget annot;
	REX(TRN_RadioButtonGroupAdd(mp_group, &pos, onstate, &annot));
	return RadioButtonWidget(annot);
}

inline UInt32 RadioButtonGroup::GetNumButtons()
{
	UInt32 result;
	REX(TRN_RadioButtonGroupGetNumButtons(mp_group, &result));
	return result;
}

inline RadioButtonWidget RadioButtonGroup::GetButton(UInt32 index)
{
	TRN_RadioButtonWidget annot;
	REX(TRN_RadioButtonGroupGetButton(mp_group, index, &annot));
	return RadioButtonWidget(annot);
}

inline Field RadioButtonGroup::GetField() const
{
	Field result;
	REX(TRN_RadioButtonGroupGetField(mp_group,&result.mp_field));
	return result;
}

inline void RadioButtonGroup::AddGroupButtonsToPage(Page page)
{
	REX(TRN_RadioButtonGroupAddGroupButtonsToPage(mp_group, page.mp_page));
}


inline RadioButtonGroup::RadioButtonGroup(TRN_RadioButtonGroup impl) : mp_group(impl)
{

}







		};// namespace Annots
	};
};