#ifndef EmbeddedTimestampVerificationResult_TrustVerificationResult_VerificationResult_INL
#define EmbeddedTimestampVerificationResult_TrustVerificationResult_VerificationResult_INL

#include <PDF/EmbeddedTimestampVerificationResult.h>
#include <PDF/TrustVerificationResult.h>
#include <PDF/VerificationResult.h>


namespace pdftron {
	namespace PDF {


/////////////////////////////////////////////////////////////////////////////////////////////////
// start EmbeddedTimestampVerificationResult
inline EmbeddedTimestampVerificationResult::EmbeddedTimestampVerificationResult(const EmbeddedTimestampVerificationResult& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline EmbeddedTimestampVerificationResult& pdftron::PDF::EmbeddedTimestampVerificationResult::operator= (const EmbeddedTimestampVerificationResult& other)
{
	Destroy();

	m_impl = other.m_impl;

	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

#ifdef SWIG
inline EmbeddedTimestampVerificationResult::EmbeddedTimestampVerificationResult()
	: m_impl(0)
	, m_owner(false)
{}
#endif
		
inline EmbeddedTimestampVerificationResult::EmbeddedTimestampVerificationResult(TRN_EmbeddedTimestampVerificationResult impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline EmbeddedTimestampVerificationResult::~EmbeddedTimestampVerificationResult()
{
	Destroy();
}


inline void EmbeddedTimestampVerificationResult::Destroy()
{
	if (m_owner)
	{
		DREX(m_impl, TRN_EmbeddedTimestampVerificationResultDestroy(m_impl));
		m_owner = false;
		//delete m_trust_verify_ptr;
	}
}

inline bool EmbeddedTimestampVerificationResult::GetVerificationStatus() const
{
	TRN_Bool result = 0;
	REX(TRN_EmbeddedTimestampVerificationResultGetVerificationStatus((TRN_EmbeddedTimestampVerificationResult)m_impl, &result));
	return result != 0;
}

inline VerificationResult::DigestStatus EmbeddedTimestampVerificationResult::GetCMSDigestStatus() const
{
	VerificationResult::DigestStatus result;
	REX(TRN_EmbeddedTimestampVerificationResultGetCMSDigestStatus((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_VerificationResult_DigestStatus*)&result));
	return result;
}

inline VerificationResult::DigestStatus EmbeddedTimestampVerificationResult::GetMessageImprintDigestStatus() const
{
	VerificationResult::DigestStatus result;
	REX(TRN_EmbeddedTimestampVerificationResultGetMessageImprintDigestStatus((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_VerificationResult_DigestStatus*)&result));
	return result;
}

inline VerificationResult::TrustStatus EmbeddedTimestampVerificationResult::GetTrustStatus() const
{
	VerificationResult::TrustStatus result;
	REX(TRN_EmbeddedTimestampVerificationResultGetTrustStatus((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_VerificationResult_TrustStatus*)&result));
	return result;
}

inline UString EmbeddedTimestampVerificationResult::GetCMSDigestStatusAsString() const
{
	UString result;
	REX(TRN_EmbeddedTimestampVerificationResultGetCMSDigestStatusAsString((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString EmbeddedTimestampVerificationResult::GetMessageImprintDigestStatusAsString() const
{
	UString result;
	REX(TRN_EmbeddedTimestampVerificationResultGetMessageImprintDigestStatusAsString((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString EmbeddedTimestampVerificationResult::GetTrustStatusAsString() const
{
	UString result;
	REX(TRN_EmbeddedTimestampVerificationResultGetTrustStatusAsString((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline bool EmbeddedTimestampVerificationResult::HasTrustVerificationResult() const
{
	TRN_Bool result = 0;
	REX(TRN_EmbeddedTimestampVerificationResultHasTrustVerificationResult((TRN_EmbeddedTimestampVerificationResult)m_impl, &result));
	return result != 0;
}

inline TrustVerificationResult EmbeddedTimestampVerificationResult::GetTrustVerificationResult() const
{
	TRN_TrustVerificationResult result;
	REX(TRN_EmbeddedTimestampVerificationResultGetTrustVerificationResult((TRN_EmbeddedTimestampVerificationResult)m_impl, &result));
	return TrustVerificationResult(result);
}

inline Crypto::DigestAlgorithm::Type EmbeddedTimestampVerificationResult::GetCMSSignatureDigestAlgorithm() const
{
	Crypto::DigestAlgorithm::Type result;
	REX(TRN_EmbeddedTimestampVerificationResultGetCMSSignatureDigestAlgorithm((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_DigestAlgorithm_Type*)&result));
	return result;
}

inline Crypto::DigestAlgorithm::Type EmbeddedTimestampVerificationResult::GetMessageImprintDigestAlgorithm() const
{
	Crypto::DigestAlgorithm::Type result;
	REX(TRN_EmbeddedTimestampVerificationResultGetMessageImprintDigestAlgorithm((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_DigestAlgorithm_Type*)&result));
	return result;
}


#ifdef SWIG
inline std::vector<std::string> EmbeddedTimestampVerificationResult::GetUnsupportedFeatures() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_EmbeddedTimestampVerificationResultGetUnsupportedFeatures((TRN_EmbeddedTimestampVerificationResult)m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<std::string> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UString current_ustr = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current_ustr);

		result.push_back(UString(current_ustr).ConvertToUtf8());
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}
#else
inline std::vector<UString> EmbeddedTimestampVerificationResult::GetUnsupportedFeatures() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_EmbeddedTimestampVerificationResultGetUnsupportedFeatures(m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<UString> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UString current_ustr = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current_ustr);
		result.push_back(UString(current_ustr));
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}
#endif
// end EmbeddedTimestampVerificationResult
/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////
// start TrustVerificationResult
#ifdef SWIG
inline TrustVerificationResult::TrustVerificationResult()
	: m_impl(NULL), m_owner(false)
{
}
#endif

inline TrustVerificationResult::~TrustVerificationResult()
{
	Destroy();
}

inline TrustVerificationResult::TrustVerificationResult(const TrustVerificationResult& other)
	: m_impl(other.m_impl)
	, m_owner(false)

{
	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void TrustVerificationResult::Destroy()
{
	if (m_owner)
	{
		DREX(m_impl, TRN_TrustVerificationResultDestroy(m_impl));
		m_owner = false;
	}
}

inline TrustVerificationResult& TrustVerificationResult::operator= (const TrustVerificationResult& other)
{
	Destroy();

	m_impl = other.m_impl;

	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline TrustVerificationResult::TrustVerificationResult(TRN_TrustVerificationResult impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline bool TrustVerificationResult::WasSuccessful() const
{
	TRN_Bool result = 0;
	REX(TRN_TrustVerificationResultWasSuccessful((TRN_TrustVerificationResult)m_impl, &result));
	return result != 0;
}

inline UString TrustVerificationResult::GetResultString() const
{
	UString result;
	REX(TRN_TrustVerificationResultGetResultString((TRN_TrustVerificationResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline Int64 TrustVerificationResult::GetTimeOfTrustVerification() const
{
	TRN_Int64 result;
	REX(TRN_TrustVerificationResultGetTimeOfTrustVerification((TRN_TrustVerificationResult)m_impl, &result));
	return result;
}

inline VerificationOptions::TimeMode TrustVerificationResult::GetTimeOfTrustVerificationEnum() const
{
	VerificationOptions::TimeMode result;
	REX(TRN_TrustVerificationResultGetTimeOfTrustVerificationEnum((TRN_TrustVerificationResult)m_impl, (enum TRN_VerificationOptions_TimeMode*) &result));
	return result;
}

inline bool TrustVerificationResult::HasEmbeddedTimestampVerificationResult() const
{
	TRN_Bool result = 0;
	REX(TRN_TrustVerificationResultHasEmbeddedTimestampVerificationResult((TRN_TrustVerificationResult)m_impl, &result));
	return result != 0;
}

inline EmbeddedTimestampVerificationResult TrustVerificationResult::GetEmbeddedTimestampVerificationResult()
{
	TRN_EmbeddedTimestampVerificationResult result;
	REX(TRN_TrustVerificationResultGetEmbeddedTimestampVerificationResult((TRN_TrustVerificationResult)m_impl, &result));
	return EmbeddedTimestampVerificationResult(result);
}

inline std::vector<Crypto::X509Certificate> TrustVerificationResult::GetCertPath() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_TrustVerificationResultGetCertPath(m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<Crypto::X509Certificate> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_X509Certificate current = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current);
		result.push_back(Crypto::X509Certificate(current));
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}
// end TrustVerificationResult
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
// start VerificationResult

inline VerificationResult::~VerificationResult()
{
	Destroy();
}

inline void VerificationResult::Destroy()
{
	if (m_owner)
	{
		DREX(m_impl, TRN_VerificationResultDestroy(m_impl));
		m_owner = false;
	}
}

#ifdef SWIG
inline VerificationResult::VerificationResult()
	: m_impl(0)
	, m_owner(false)
{}
#endif

inline VerificationResult::VerificationResult(TRN_VerificationResult impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline VerificationResult::VerificationResult(const VerificationResult& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline VerificationResult& VerificationResult::operator= (const VerificationResult& other)
{
	Destroy();

	m_impl = other.m_impl;

	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline bool VerificationResult::GetVerificationStatus() const
{
	TRN_Bool result = 0;
	REX(TRN_VerificationResultGetVerificationStatus((TRN_VerificationResult)m_impl, &result));
	return result != 0;
}

inline VerificationResult::DocumentStatus VerificationResult::GetDocumentStatus() const
{
	DocumentStatus result;
	REX(TRN_VerificationResultGetDocumentStatus((TRN_VerificationResult)m_impl, (enum TRN_VerificationResult_DocumentStatus*) &result));
	return result;
}

inline VerificationResult::DigestStatus VerificationResult::GetDigestStatus() const
{
	DigestStatus result;
	REX(TRN_VerificationResultGetDigestStatus((TRN_VerificationResult)m_impl, (enum TRN_VerificationResult_DigestStatus*) &result));
	return result;
}

inline VerificationResult::TrustStatus VerificationResult::GetTrustStatus() const
{
	TrustStatus result;
	REX(TRN_VerificationResultGetTrustStatus((TRN_VerificationResult)m_impl, (enum TRN_VerificationResult_TrustStatus*) &result));
	return result;
}

inline VerificationResult::ModificationPermissionsStatus VerificationResult::GetPermissionsStatus() const
{
	ModificationPermissionsStatus result;
	REX(TRN_VerificationResultGetPermissionsStatus((TRN_VerificationResult)m_impl, (enum TRN_VerificationResult_ModificationPermissionsStatus*) &result));
	return result;
}


inline bool pdftron::PDF::VerificationResult::HasTrustVerificationResult() const
{
	TRN_Bool result = 0;
	REX(TRN_VerificationResultHasTrustVerificationResult((TRN_VerificationResult)m_impl, &result));
	return result != 0;
}

inline TrustVerificationResult VerificationResult::GetTrustVerificationResult() const
{
	TRN_TrustVerificationResult result;
	REX(TRN_VerificationResultGetTrustVerificationResult((TRN_VerificationResult)m_impl, &result));
	return TrustVerificationResult(result);
}

inline std::vector<pdftron::PDF::DisallowedChange> pdftron::PDF::VerificationResult::GetDisallowedChanges() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps and DigitalSignatureField::GetLockedFields implementations
	TRN_Vector changes_vec = NULL;
	REX(TRN_VerificationResultGetDisallowedChanges(m_impl, (TRN_Vector*)&changes_vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(changes_vec, &vec_size);

	std::vector<DisallowedChange> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_DisallowedChange current_disallowed_change_ptr = NULL;
		TRN_VectorGetAt(changes_vec, i, (void**)&current_disallowed_change_ptr);
		result.push_back(DisallowedChange(current_disallowed_change_ptr));
	}

	TRN_VectorDestroyKeepContents(changes_vec);
	return result;
}

inline Crypto::DigestAlgorithm::Type VerificationResult::GetDigestAlgorithm() const
{
	Crypto::DigestAlgorithm::Type result;
	REX(TRN_VerificationResultGetDigestAlgorithm((TRN_VerificationResult)m_impl, (TRN_DigestAlgorithm_Type*)&result));
	return result;
}

inline UString VerificationResult::GetDocumentStatusAsString() const
{
	UString result;
	REX(TRN_VerificationResultGetDocumentStatusAsString((TRN_VerificationResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString VerificationResult::GetDigestStatusAsString() const
{
	UString result;
	REX(TRN_VerificationResultGetDigestStatusAsString((TRN_VerificationResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString VerificationResult::GetTrustStatusAsString() const
{
	UString result;
	REX(TRN_VerificationResultGetTrustStatusAsString((TRN_VerificationResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString VerificationResult::GetPermissionsStatusAsString() const
{
	UString result;
	REX(TRN_VerificationResultGetPermissionsStatusAsString((TRN_VerificationResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}


#ifdef SWIG
inline std::vector<std::string> VerificationResult::GetUnsupportedFeatures() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_VerificationResultGetUnsupportedFeatures((TRN_VerificationResult)m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<std::string> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UString current_ustr = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current_ustr);

		result.push_back(UString(current_ustr).ConvertToUtf8());
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}
#else
inline std::vector<UString> VerificationResult::GetUnsupportedFeatures() const
{
	// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
	TRN_Vector vec = NULL;
	REX(TRN_VerificationResultGetUnsupportedFeatures((TRN_VerificationResult)m_impl, (TRN_Vector*)&vec));

	TRN_UInt32 vec_size;
	TRN_VectorGetSize(vec, &vec_size);

	std::vector<UString> result;
	for (TRN_UInt32 i = 0; i < vec_size; i++)
	{
		TRN_UString current_ustr = NULL;
		TRN_VectorGetAt(vec, i, (void**)&current_ustr);
		result.push_back(UString(current_ustr));
	}

	TRN_VectorDestroyKeepContents(vec);
	return result;
}
#endif
// end VerificationResult
///////////////////////////////////////////////////////////////////////////////////////////////



} //PDF
} //pdftron

#endif