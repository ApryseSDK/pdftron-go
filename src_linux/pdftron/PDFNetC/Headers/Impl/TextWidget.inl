


namespace pdftron {
	namespace PDF {
		namespace Annots {

inline TextWidget::TextWidget(SDF::Obj d) : Widget(d)
{

}

inline TextWidget::TextWidget(const Annot& annot) : Widget(annot.GetSDFObj())
{

}

inline TextWidget TextWidget::Create(PDFDoc& doc, const Rect& pos, const UString& field_name)
{
	TRN_Annot result;
	REX(TRN_TextWidgetCreate(doc.mp_doc, (const TRN_Rect*)&pos, field_name.mp_impl, &result));
	return TextWidget(result);
}

inline TextWidget TextWidget::Create(PDFDoc& doc, const Rect& pos, const Field& field)
{
	TRN_Annot result;
	REX(TRN_TextWidgetCreateWithField(doc.mp_doc, (const TRN_Rect*)&pos, (const TRN_Field*)&field, &result));
	return TextWidget(result);
}


inline void TextWidget::SetText(const UString& text)
{
	REX(TRN_TextWidgetSetText(mp_annot, text.mp_impl));
}

inline UString TextWidget::GetText()
{
	TRN_UString result;
	REX(TRN_TextWidgetGetText(mp_annot, &result));
	return UString(result);
}

		};// namespace Annots
	};
};
