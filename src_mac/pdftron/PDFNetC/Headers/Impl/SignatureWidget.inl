#ifndef HPP_PDFTRON_PDF_SIGNATUREWIDGET_INL
#define HPP_PDFTRON_PDF_SIGNATUREWIDGET_INL

#include <SDF/Obj.h>
#include <PDF/Field.h>
#include <PDF/Annots.h>


namespace pdftron {
	namespace PDF {
		namespace Annots {


inline SignatureWidget::SignatureWidget(SDF::Obj d):Widget(d)
{
	REX(TRN_SignatureWidgetCreateFromObj(d.mp_obj, &mp_annot));
}

inline SignatureWidget::SignatureWidget(const Annot& annot):Widget(annot)
{
	REX(TRN_SignatureWidgetCreateFromAnnot(annot.mp_annot, &mp_annot));
}

inline DigitalSignatureField SignatureWidget::GetDigitalSignatureField()
{
	TRN_DigitalSignatureField result;
	REX(TRN_SignatureWidgetGetDigitalSignatureField((TRN_SignatureWidget) mp_annot, &result));
	return DigitalSignatureField(result);
}

inline void SignatureWidget::CreateSignatureAppearance(Image& img)
{
	REX(TRN_SignatureWidgetCreateSignatureAppearance((TRN_SignatureWidget) mp_annot, img.mp_image));
}

inline SignatureWidget SignatureWidget::Create(PDFDoc& doc, const Rect& pos, const UString& field_name)
{
	TRN_SignatureWidget result;
	REX(TRN_SignatureWidgetCreate(doc.mp_doc, (const TRN_Rect*)&pos, field_name.mp_impl, &result));
	return (SignatureWidget) result;
}

inline SignatureWidget SignatureWidget::Create(PDFDoc& doc, const Rect& pos, const Field& field)
{
	TRN_SignatureWidget result;
	REX(TRN_SignatureWidgetCreateWithField(doc.mp_doc, (const TRN_Rect*)&pos, (const TRN_Field*)&field, &result));
	return (SignatureWidget) result;
}

inline SignatureWidget SignatureWidget::Create(PDFDoc& doc, const Rect& pos, const DigitalSignatureField& field)
{
	TRN_SignatureWidget result;
	REX(TRN_SignatureWidgetCreateWithDigitalSignatureField(doc.mp_doc, (const TRN_Rect*)&pos, (const TRN_DigitalSignatureField*)&field.m_impl, &result));
	return (SignatureWidget) result;
}
		};// namespace Annots
	};
};

#endif
