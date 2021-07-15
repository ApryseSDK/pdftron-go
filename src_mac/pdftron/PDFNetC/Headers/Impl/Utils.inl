#ifndef PDFTRON_H_CPPUTILS
#define PDFTRON_H_CPPUTILS

inline void SetOverprintImpl(TRN_Obj obj, enum PDFRasterizer::OverprintPreviewMode mode, TRN_Obj* result)
{
	switch (mode)
	{
	case PDFRasterizer::e_op_off:
		REX(TRN_ObjPutName(obj, "OVERPRINT_MODE", "OFF", result));
		break;
	case PDFRasterizer::e_op_on:
		REX(TRN_ObjPutName(obj, "OVERPRINT_MODE", "ON", result));
		break;
	case PDFRasterizer::e_op_pdfx_on:
		REX(TRN_ObjPutName(obj, "OVERPRINT_MODE", "PDFX", result));
		break;
	}
}
#endif // PDFTRON_H_CPPUTILS
