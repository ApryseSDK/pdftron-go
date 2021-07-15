#ifndef HPP_PDFTRON_PDF_PUSHBUTTONWIDGET_INL
#define HPP_PDFTRON_PDF_PUSHBUTTONWIDGET_INL



namespace pdftron {
	namespace PDF {
		namespace Annots {

			
			inline PushButtonWidget::PushButtonWidget(SDF::Obj d) : Widget(d)
			{

			}
			inline PushButtonWidget::PushButtonWidget(const Annot& annot) : Widget(annot.GetSDFObj())
			{

			}

			inline PushButtonWidget PushButtonWidget::Create(PDFDoc& doc, const Rect& pos, const UString& field_name)
			{
				TRN_Annot result;
				REX(TRN_PushButtonWidgetCreate(doc.mp_doc, (const TRN_Rect*)&pos, field_name.mp_impl, &result));
				return PushButtonWidget(result);
			}

			inline PushButtonWidget PushButtonWidget::Create(PDFDoc& doc, const Rect& pos, const Field& field)
			{
				TRN_Annot result;
				REX(TRN_PushButtonWidgetCreateWithField(doc.mp_doc, (const TRN_Rect*)&pos, (const TRN_Field*)&field, &result));
				return PushButtonWidget(result);
			}

		};// namespace Annots
	};
};

#endif
