#ifndef PDFTRON_CPPPDFAC_INL
#define PDFTRON_CPPPDFAC_INL

#define PDFACCast(pdfac) ((PDFACompliance*)pdfac)

#include <PDF/PDFA/PDFACompliance.h>
#include <C/PDF/PDFA/TRN_PDFACompliance.h>
#include <cassert>
#include <cstring>

namespace pdftron { 
	namespace PDF { 
		namespace PDFA {

	inline PDFACompliance::PDFACompliance(bool convert, const UString& file_path, const char* password, Conformance conf, ErrorCode* exceptions, int num_exceptions, int max_ref_objs, bool first_stop)
	{
		REX(TRN_PDFAComplianceCreateFromFile(BToTB(convert), file_path.mp_impl, password, (enum TRN_PDFAComplianceConformance)conf, (enum TRN_PDFAComplianceErrorCode*)exceptions, num_exceptions, max_ref_objs, first_stop, &mp_pdfac));
	}

	inline PDFACompliance::PDFACompliance(bool convert, const char* buf, size_t buf_size, const char* password, Conformance conf, ErrorCode* exceptions, int num_exceptions, int max_ref_objs, bool first_stop)
	{
		REX(TRN_PDFAComplianceCreateFromBuffer(BToTB(convert), buf, (int)buf_size, password, (enum TRN_PDFAComplianceConformance)conf, (enum TRN_PDFAComplianceErrorCode*)exceptions, num_exceptions, max_ref_objs, first_stop, &mp_pdfac));
	}

	inline void PDFACompliance::SaveAs(const UString& file_path, bool linearized){
		REX(TRN_PDFAComplianceSaveAsFromFileName(mp_pdfac, file_path.mp_impl, BToTB(linearized)));
	}

	inline std::vector<unsigned char> PDFACompliance::SaveAs(bool linearized){
		size_t size;
		char* buf;
		std::vector<unsigned char> result;
		REX(TRN_PDFAComplianceSaveAsFromBuffer(mp_pdfac, (const char**)&buf, &size, BToTB(linearized)));
		result.resize(size);
		std::memcpy(&(result[0]), buf, size);
		return result;
	}

#ifndef SWIG
	inline void PDFACompliance::SaveAs(const char* &out_buf, size_t& out_buf_size, bool linearized){
		REX(TRN_PDFAComplianceSaveAsFromBuffer(mp_pdfac, &out_buf, &out_buf_size, BToTB(linearized)));
	}
#endif

	inline size_t PDFACompliance::GetErrorCount(){
			int result;
			REX(TRN_PDFAComplianceGetErrorCount(mp_pdfac, &result));
			return (size_t)result;
	}

	inline PDFACompliance::ErrorCode PDFACompliance::GetError(size_t idx){
			enum TRN_PDFAComplianceErrorCode result;
			REX(TRN_PDFAComplianceGetError(mp_pdfac, (int)idx, &result));
			return (ErrorCode)result;
	}

	inline size_t PDFACompliance::GetRefObjCount(ErrorCode id)
	{
			int result;
			REX(TRN_PDFAComplianceGetRefObjCount(mp_pdfac, (enum TRN_PDFAComplianceErrorCode)id, &result));
			return (size_t)result;
	}

	inline size_t PDFACompliance::GetRefObj(ErrorCode id, size_t err_idx){
			int result;
			REX(TRN_PDFAComplianceGetRefObj(mp_pdfac, (enum TRN_PDFAComplianceErrorCode)id, (int)err_idx, &result));
			return (size_t)result;
	}

	inline const char* PDFACompliance::GetPDFAErrorMessage(ErrorCode id)
	{
		const char* result;
		REX(TRN_PDFAComplianceGetPDFAErrorMessage((enum TRN_PDFAComplianceErrorCode)id, &result));
		return result;
	}

	inline PDFACompliance::Conformance PDFACompliance::GetDeclaredConformance(const PDFDoc& in_doc)
	{
		enum TRN_PDFAComplianceConformance result;
		REX(TRN_PDFAComplianceGetDeclaredConformance(in_doc.mp_doc, &result));
		return (PDFACompliance::Conformance)result;
	}

	inline PDFACompliance::~PDFACompliance() {
		DREX(mp_pdfac, TRN_PDFAComplianceDestroy(mp_pdfac));
	}

	inline void PDFACompliance::Destroy() {
		REX(TRN_PDFAComplianceDestroy(mp_pdfac));
		mp_pdfac=0;
	}
		};	// namespace PDFA
	};	// namespace PDF
};	// namespace pdftron

#endif
