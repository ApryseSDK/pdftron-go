#ifndef HPP_PDFTRON_PDF_CHECKBOXWIDGET_INL
#define HPP_PDFTRON_PDF_CHECKBOXWIDGET_INL



namespace pdftron {
	namespace PDF {
		namespace Annots {


inline CheckBoxWidget::CheckBoxWidget(SDF::Obj d) : Widget(d)
{

}
inline CheckBoxWidget::CheckBoxWidget(const Annot& annot) : Widget(annot.GetSDFObj())
{

}

inline CheckBoxWidget CheckBoxWidget::Create(PDFDoc& doc, const Rect& pos, const UString& field_name)
{
	TRN_Annot result;
	REX(TRN_CheckBoxWidgetCreate(doc.mp_doc, (const TRN_Rect*)&pos, field_name.mp_impl, &result));
	return CheckBoxWidget(result);
}

inline CheckBoxWidget CheckBoxWidget::Create(PDFDoc& doc, const Rect& pos, const Field& field)
{
	TRN_Annot result;
	REX(TRN_CheckBoxWidgetCreateWithField(doc.mp_doc, (const TRN_Rect*)&pos, (const TRN_Field*)&field, &result));
	return CheckBoxWidget(result);
}

inline bool CheckBoxWidget::IsChecked()
{
	RetBool(TRN_CheckBoxWidgetIsChecked(mp_annot, &result));
}

inline void CheckBoxWidget::SetChecked(bool checked)
{
	REX(TRN_CheckBoxWidgetSetChecked(mp_annot, BToTB(checked)));
}




		};// namespace Annots
	};
};

#endif
