inline bool OCRModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_OCRModuleIsModuleAvailable(&result));
	return result != 0;
}

inline void OCRModule::ImageToPDF(PDFDoc dst, const UString& src, OCROptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_OCRModuleImageToPDF((TRN_PDFDoc)dst.mp_doc, (TRN_UString)src.mp_impl, opt_ptr));
}

inline void OCRModule::ProcessPDF(PDFDoc dst, OCROptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_OCRModuleProcessPDF((TRN_PDFDoc)dst.mp_doc, opt_ptr));
}

inline UString OCRModule::GetOCRJsonFromImage(PDFDoc dst, const UString& src, OCROptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	UString result;
	REX(TRN_OCRModuleGetOCRJsonFromImage((TRN_PDFDoc)dst.mp_doc, (TRN_UString)src.mp_impl, opt_ptr, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString OCRModule::GetOCRJsonFromPDF(PDFDoc src, OCROptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	UString result;
	REX(TRN_OCRModuleGetOCRJsonFromPDF((TRN_PDFDoc)src.mp_doc, opt_ptr, (TRN_UString*)&result.mp_impl));
	return result;
}

inline void OCRModule::ApplyOCRJsonToPDF(PDFDoc dst, const UString& json)
{
	REX(TRN_OCRModuleApplyOCRJsonToPDF((TRN_PDFDoc)dst.mp_doc, (TRN_UString)json.mp_impl));
}

inline UString OCRModule::GetOCRXmlFromImage(PDFDoc dst, const UString& src, OCROptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	UString result;
	REX(TRN_OCRModuleGetOCRXmlFromImage((TRN_PDFDoc)dst.mp_doc, (TRN_UString)src.mp_impl, opt_ptr, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString OCRModule::GetOCRXmlFromPDF(PDFDoc src, OCROptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	UString result;
	REX(TRN_OCRModuleGetOCRXmlFromPDF((TRN_PDFDoc)src.mp_doc, opt_ptr, (TRN_UString*)&result.mp_impl));
	return result;
}

inline void OCRModule::ApplyOCRXmlToPDF(PDFDoc dst, const UString& xml)
{
	REX(TRN_OCRModuleApplyOCRXmlToPDF((TRN_PDFDoc)dst.mp_doc, (TRN_UString)xml.mp_impl));
}

