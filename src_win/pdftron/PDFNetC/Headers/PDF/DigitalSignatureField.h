//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFDigitalSignatureField
#define PDFTRON_H_CPPPDFDigitalSignatureField
#include <C/PDF/TRN_DigitalSignatureField.h>
#include <C/PDF/TRN_VerificationResult.h>

#include <PDF/VerificationOptions.h>
#include <PDF/VerificationResult.h>
#include <PDF/TimestampingConfiguration.h>
#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>
#include <Crypto/X509Certificate.h>
#include <Common/ByteRange.h>
#include <vector>

namespace pdftron { namespace PDF { 


/**
 * A class representing a digital signature form field.
 */
class DigitalSignatureField
{
public:
	//enums:

	enum SubFilterType {
		e_adbe_x509_rsa_sha1 = 0,
		e_adbe_pkcs7_detached = 1,
		e_adbe_pkcs7_sha1 = 2,
		e_ETSI_CAdES_detached = 3,
		e_ETSI_RFC3161 = 4,
		e_unknown = 5,
		e_absent = 6
	};
	enum DocumentPermissions {
		// No changes to the document shall be permitted; any change to the document shall invalidate the signature.
		e_no_changes_allowed = 1,
		// Permitted changes shall be filling in forms, instantiating page templates, and signing; other changes shall invalidate the signature.
		e_formfilling_signing_allowed = 2,
		// Permitted changes shall be the same as for 2, as well as annotation creation, deletion, and modification; other changes shall invalidate the signature.
		e_annotating_formfilling_signing_allowed = 3,
		// Represents the absence of any document permissions during retrieval; not to be used during setting
		e_unrestricted = 4
	};
	enum FieldPermissions {
		// Locks all form fields.
		e_lock_all = 0,
		// Locks only those form fields specified.
		e_include = 1,
		// Locks only those form fields not specified.
		e_exclude = 2
	};

	DigitalSignatureField(const DigitalSignatureField& other);
	DigitalSignatureField& operator= (const DigitalSignatureField& other);

	/**
	 * Constructs a PDF::DigitalSignatureField from a PDF::Field.
	 * 
	 * @param in_field -- the PDF::Field to construct the DigitalSignatureField from.
	 */
	DigitalSignatureField(const PDF::Field& in_field);
	
	/**
	 * Returns whether the digital signature field has been cryptographically signed. Checks whether there is a digital signature dictionary in the field and whether it has a Contents entry. Must be called before using various digital signature dictionary-related functions. Does not check validity - will return true even if a valid hash has not yet been generated (which will be the case after [Certify/Sign]OnNextSave[WithCustomHandler] has been called on the signature but even before Save is called on the document).
	 * 
	 * @return A boolean value representing whether the digital signature field has a digital signature dictionary with a Contents entry.
	 */
	bool HasCryptographicSignature() const;
	
	/**
	 * Returns the SubFilter type of the digital signature. Specification says that one must check the SubFilter before using various getters. Must call HasCryptographicSignature first and use it to check whether the signature is signed.
	 * 
	 * @return An enumeration describing what the SubFilter of the digital signature is from within the digital signature dictionary.
	 */
	SubFilterType GetSubFilter() const;
	
	/**
	 * Should not be called when SubFilter is ETSI.RFC3161 (i.e. on a DocTimeStamp). Returns the name of the signer of the signature from the digital signature dictionary. Must call HasCryptographicSignature first and use it to check whether the signature is signed.
	 * 
	 * @return A unicode string containing the name of the signer from within the digital signature dictionary. Empty if Name entry not present.
	 */
	UString GetSignatureName() const;
	
	/**
	 * Should not be called when SubFilter is ETSI.RFC3161 (i.e. on a DocTimeStamp). 
	 * Returns the "M" entry from the digital signature dictionary, which represents the 
	 * signing date/time. Must call HasCryptographicSignature first and use it to check whether the 
	 * signature is signed. 
	 * 
	 * @return A PDF::Date object holding the signing date/time from within the digital signature dictionary. Returns a default-constructed PDF::Date if no date is present. 
	 */
	Date GetSigningTime() const;
	
	/**
	 * Should not be called when SubFilter is ETSI.RFC3161 (i.e. on a DocTimeStamp). Returns the Location of the signature from the digital signature dictionary. Must call HasCryptographicSignature first and use it to check whether the signature is signed.
	 * 
	 * @return A unicode string containing the signing location from within the digital signature dictionary. Empty if Location entry not present.
	 */
	UString GetLocation() const;
	
	/**
	 * Should not be called when SubFilter is ETSI.RFC3161 (i.e. on a DocTimeStamp). Returns the Reason for the signature from the digital signature dictionary. Must call HasCryptographicSignature first and use it to check whether the signature is signed.
	 * 
	 * @return A unicode string containing the reason for the signature from within the digital signature dictionary. Empty if Reason entry not present.
	 */
	UString GetReason() const;
	
	/**
	 * Should not be called when SubFilter is ETSI.RFC3161 (i.e. on a DocTimeStamp). Returns the contact information of the signer from the digital signature dictionary. Must call HasCryptographicSignature first and use it to check whether the signature is signed.
	 * 
	 * @return A unicode string containing the contact information of the signer from within the digital signature dictionary. Empty if ContactInfo entry not present.
	 */
	UString GetContactInfo() const;
	
	/**
	 * Gets a certificate in the certificate chain (Cert entry) of the digital signature dictionary by index. Throws if Cert is not Array or String, throws if index is out of range and Cert is Array, throws if index is > 1 and Cert is string, otherwise retrieves the certificate.
	 * 
	 * @param in_index -- An integral index which must be greater than 0 and less than the cert count as retrieved using GetCertCount.
	 * @return A vector of bytes containing the certificate at the index. Returns empty vector if Cert is missing.
	 */
	std::vector<UChar> GetCert(UInt32 in_index) const;
	
	/**
	 * Gets number of certificates in certificate chain (Cert entry of digital signature dictionary). Must call HasCryptographicSignature first and use it to check whether the signature is signed.
	 * 
	 * @return An integer value - the number of certificates in the Cert entry of the digital signature dictionary.
	 */
	UInt32 GetCertCount() const;
	
	/**
	 * Returns whether the field has a visible appearance. Can be called without checking HasCryptographicSignature first, since it operates on the surrounding Field dictionary, not the "V" entry (i.e. digital signature dictionary). Performs the zero-width+height check, the Hidden bit check, and the NoView bit check as described by the PDF 2.0 specification, section 12.7.5.5 "Signature fields".
	 * 
	 * @return A boolean representing whether or not the signature field has a visible signature.
	 */
	bool HasVisibleAppearance() const;
	
	/**
	 * Should not be called when SubFilter is ETSI.RFC3161 (i.e. on a DocTimeStamp). Sets the ContactInfo entry in the digital signature dictionary. Must create a digital signature dictionary first using [Certify/Sign]OnNextSave[WithCustomHandler]. If this function is called on a digital signature field that has already been cryptographically signed with a valid hash, the hash will no longer be valid, so do not call Save (to sign/create the hash) until after you call this function, if you need to call this function in the first place. Essentially, call this function after [Certify/Sign]OnNextSave[WithCustomHandler] and before Save.
	 * 
	 * @param in_contact_info -- A string containing the ContactInfo to be set.
	 */
	void SetContactInfo(const UString& in_contact_info);
	
	/**
	 * Should not be called when SubFilter is ETSI.RFC3161 (i.e. on a DocTimeStamp). Sets the Location entry in the digital signature dictionary. Must create a digital signature dictionary first using [Certify/Sign]OnNextSave[WithCustomHandler]. If this function is called on a digital signature field that has already been cryptographically signed with a valid hash, the hash will no longer be valid, so do not call Save (to sign/create the hash) until after you call this function, if you need to call this function in the first place. Essentially, call this function after [Certify/Sign]OnNextSave[WithCustomHandler] and before Save.
	 * 
	 * @param in_location -- A string containing the Location to be set.
	 */
	void SetLocation(const UString& in_location);
	
	/**
	 * Should not be called when SubFilter is ETSI.RFC3161 (i.e. on a DocTimeStamp). Sets the Reason entry in the digital signature dictionary. Must create a digital signature dictionary first using [Certify/Sign]OnNextSave[WithCustomHandler]. If this function is called on a digital signature field that has already been cryptographically signed with a valid hash, the hash will no longer be valid, so do not call Save (to sign/create the hash) until after you call this function, if you need to call this function in the first place. Essentially, call this function after [Certify/Sign]OnNextSave[WithCustomHandler] and before Save.
	 * 
	 * @param in_reason -- A string containing the Reason to be set.
	 */
	void SetReason(const UString& in_reason);
	
	/**
	* Tentatively sets which fields are to be locked by this digital signature upon signing. It is not necessary to call HasCryptographicSignature before using this function. Throws if non-empty array of field names is passed along with FieldPermissions Action == e_lock_all. 
	* 
	* @param in_action -- An enumerated value representing which sort of field locking should be done. Options are All (lock all fields), Include (lock listed fields), and Exclude (lock all fields except listed fields).
	* @param in_field_names -- A list of field names; can be empty (and must be empty, if Action is set to All). Empty by default.
	*/
#ifdef SWIG
// We use an std::vector of UTF-8 std::strings for SWIG, because SWIG has trouble with mapping UString to string when it's in a vector<UString>.
	void SetFieldPermissions(const FieldPermissions in_action, const std::vector<std::string>& in_field_names = std::vector<std::string>());
#else
	/**
	* Tentatively sets which fields are to be locked by this digital signature upon signing. It is not necessary to call HasCryptographicSignature before using this function. Throws if non-empty array of field names is passed along with FieldPermissions Action == e_lock_all.
	*
	* @param in_action -- An enumerated value representing which sort of field locking should be done. Options are All (lock all fields), Include (lock listed fields), and Exclude (lock all fields except listed fields).
	* @param in_field_names_list -- A list of field names; can be empty (and must be empty, if Action is set to All). Empty by default.
	*/
	void SetFieldPermissions(const FieldPermissions in_action, const std::vector<UString>& in_field_names_list = std::vector<UString>());
	void SetFieldPermissions(const FieldPermissions in_action, const UString* in_field_names_list, const size_t in_field_names_list_size);
#endif
	
	/**
	 * Sets the document locking permission level for this digital signature field. Call only on unsigned signatures, otherwise a valid hash will be invalidated.
	 * 
	 * @param in_perms -- An enumerated value representing the document locking permission level to set.
	 */
	void SetDocumentPermissions(DocumentPermissions in_perms);
	
	/**
	 * Must be called to prepare a signature for signing, which is done afterwards by calling Save. Cannot sign two signatures during one save (throws). Default document permission level is e_annotating_formfilling_signing_allowed. Throws if signature field already has a digital signature dictionary.
	 * 
	 * @param in_pkcs12_keyfile_path -- The path to the PKCS #12 private keyfile to use to sign this digital signature.
	 * @param in_password -- The password to use to parse the PKCS #12 keyfile.
	 */
	void SignOnNextSave(const UString& in_pkcs12_keyfile_path, const UString& in_password);
	
	/**
	 * Must be called to prepare a signature for signing, which is done afterwards by calling Save. Cannot sign two signatures during one save (throws). Default document permission level is e_annotating_formfilling_signing_allowed. Throws if signature field already has a digital signature dictionary.
	 * 
	 * @param in_pkcs12_buffer -- A buffer of bytes containing the PKCS #12 private key certificate store to use to sign this digital signature.
	 * @param in_buf_size -- buffer size.
	 * @param in_password -- The password to use to parse the PKCS #12 buffer.
	 */
	void SignOnNextSave(const UChar* in_pkcs12_buffer, size_t in_buf_size, const UString& in_password);

	/**
	 * Must be called to prepare a signature for signing, which is done afterwards by calling Save. Cannot sign two signatures during one save (throws). Default document permission level is e_annotating_formfilling_signing_allowed. Throws if signature field already has a digital signature dictionary.
	 * 
	 * @param in_signature_handler_id -- The unique id of the signature handler to use to sign this digital signature. 
	 */
	void SignOnNextSaveWithCustomHandler(const SDF::SignatureHandlerId in_signature_handler_id);
	
	/**
	 * Must be called to prepare a signature for certification, which is done afterwards by calling Save. Throws if document already certified. Default document permission level is e_annotating_formfilling_signing_allowed. Throws if signature field already has a digital signature dictionary.
	 * 
	 * @param in_pkcs12_keyfile_path -- The path to the PKCS #12 private keyfile to use to certify this digital signature.
	 * @param in_password -- The password to use to parse the PKCS #12 keyfile.
	 */
	void CertifyOnNextSave(const UString& in_pkcs12_keyfile_path, const UString& in_password);
	
	/**
	 * Must be called to prepare a signature for certification, which is done afterwards by calling Save. Throws if document already certified. Default document permission level is e_annotating_formfilling_signing_allowed. Throws if signature field already has a digital signature dictionary.
	 * 
	 * @param in_pkcs12_buffer -- A buffer of bytes containing the PKCS #12 private key certificate store to use to certify this digital signature.
	 * @param in_buf_size -- buffer size.
	 * @param in_password -- The password to use to parse the PKCS #12 buffer.
	 */
	void CertifyOnNextSave(const UChar* in_pkcs12_buffer, size_t in_buf_size, const UString& in_password);
	
	/**
	 * Must be called to prepare a signature for certification, which is done afterwards by calling Save. Throws if document already certified. Default document permission level is e_annotating_formfilling_signing_allowed. Throws if signature field already has a digital signature dictionary.
	 * 
	 * @param in_signature_handler_id -- The unique id of the signature handler to use to certify this digital signature. 
	 */
	void CertifyOnNextSaveWithCustomHandler(const SDF::SignatureHandlerId in_signature_handler_id);
	
	/**
	 * Retrieves the SDF Obj of the digital signature field.
	 *
	 * @return the underlying SDF/Cos object.
	 */
	SDF::Obj GetSDFObj() const;
	
	/**
	 * Returns whether this digital signature field is locked against modifications by any digital signatures. Can be called when this field is unsigned.
	 * 
	 * @return A boolean representing whether this digital signature field is locked against modifications by any digital signatures in the document.
	 */
	bool IsLockedByDigitalSignature() const;
	
	/**
	 * Returns the fully-qualified names of all fields locked by this signature using the field permissions feature. Retrieves from the digital signature dictionary if the form field HasCryptographicSignature. Otherwise, retrieves from the Lock entry of the digital signature form field. Result is invalidated by any field additions or removals. Does not take document permissions restrictions into account.
	 *
	 * @return A vector of UStrings representing the fully-qualified names of all fields locked by this signature.
	 */
#ifdef SWIG
// We use an std::vector of UTF-8 std::strings for SWIG, because SWIG has trouble with mapping UString to string when it's in a vector<UString>.
	std::vector<std::string> GetLockedFields() const;
#else
	std::vector<UString> GetLockedFields() const;
#endif
	
	/**
	 * If HasCryptographicSignature, returns most restrictive permissions found in any reference entries in this digital signature. Returns Lock-resident (i.e. tentative) permissions otherwise. Throws if invalid permission value is found.
	 * 
	 * @return An enumeration value representing the level of restrictions (potentially) placed on the document by this signature.
	 */
	DocumentPermissions GetDocumentPermissions() const;
	
	/**
	 * Clears cryptographic signature, if present. Otherwise, does nothing. Do not need to call HasCryptographicSignature before calling this. After clearing, other signatures should still pass validation if saving after clearing was done incrementally. Clears the appearance as well.
	 * 
	 */
	void ClearSignature();
	
	/**
	 * Verifies this cryptographic digital signature in the manner specified by the VerificationOptions. EXPERIMENTAL. Digital signature verification is undergoing active development, but currently does not support a number of features. If we are missing a feature that is important to you, or if you have files that do not act as expected, please contact us using one of the following forms: https://www.pdftron.com/form/trial-support/ or https://www.pdftron.com/form/request/
	 *
	 * @param in_opts -- The options specifying how to do the verification.
	 * @return A VerificationResult object containing various information about the verifiability of the cryptographic digital signature.
	 */
	VerificationResult Verify(const VerificationOptions& in_opts) const;

	/**
	 * Returns whether or not this signature is a certification.
	 * 
	 * @return a boolean value representing whether or not this signature is a certification.
	 */
	bool IsCertification() const;
	
	/**
	 * Returns the signing certificate. Must only be called on signed adbe.pkcs7.detached signatures. 
	 *
	 * @return An X509Certificate object.
	 *
	 * @note This function does not verify the signature. It merely extracts the claimed signing certificate.
	 * This function only works when the build has support for verification-related APIs. 
	 */
	Crypto::X509Certificate GetSignerCertFromCMS() const;

	/** 
	 * Retrieves the ranges of byte indices within the document over which this signature is intended to apply/be verifiable.
	 *
	 * @return a container of byte range objects
	 *
	 * @note This function does not verify that the signature is valid over its byte 
	 * ranges. It merely returns them. This can be useful when a document consists of 
	 * multiple incremental revisions, the latter of which may or may not have been 
	 * signed, for telling which revisions were actually signed by which signature. 
	 * The outputs of this function can also be used to truncate the document at the 
	 * end of a signed byte range, in order that the signed document revision may
	 * be retrieved from a document with later incremental revisions. Of course, to 
	 * be certain that the signature is valid, it must also then be verified using the 
	 * verification API. Also, the caller is responsible for making sure that the 
	 * byte ranges returned from this function actually make sense (i.e. fit inside
	 * the document).
	 */
	std::vector<Common::ByteRange> GetByteRanges() const;
	
	/** Retrieves all constructible certificate paths from an adbe.pkcs7.detached digital signature. The signer 
	 * will always be returned if the signature is CMS-based and not corrupt. Must only be called on 
	 * signed adbe.pkcs7.detached signatures. The order of the certificates in each of the paths returned is as follows: 
	 * the signer will be first, and issuers come after it in order of the issuer of the previous certificate.
	 * The default behaviour is to return a sub-path for each marginal issuer in a max-length path.
	 * 
	 * @return a container of X509Certificate objects
	 * 
	 * @note This function does not verify the paths. It merely extracts certificates and constructs paths. 
	 * This function only works when the build has support for verification-related APIs. 
	 */
	std::vector<std::vector<Crypto::X509Certificate> > GetCertPathsFromCMS() const;

	/**
	 * Given a successful verification result that required online information to verify trust
	 * (trust verification must have been enabled and successful during the verification),
	 * embeds data into the PDF document that allows the signature to be verified offline.
	 * (This is accomplished using DSS and VRI dictionaries.) When this operation is
	 * successfully completed, one of the two components of secure long term validation (LTV)
	 * will be in place. The other necessary component of secure long term validation is
	 * to make sure to timestamp the document appropriately while the signature
	 * is still verifiable to maintain a chain of unexpired secure timestamps
	 * attesting to the integrity of the document. The verifiability of the signature
	 * should thereafter be maintainable in such a fashion despite any possible
	 * certificate expiry, algorithm compromise, or key compromise that would
	 * have otherwise rendered it invalid if it were to be verified using a time in
	 * the future rather than a securely-signed timestamp-derived time nearer the time
	 * of signing (at which which the signature was verifiable without extra data).
	 * This function, if given a good verification result, is also capable of making timestamp
	 * (DocTimeStamp ETSI.RFC3161) signatures LTV-enabled, which is necessary to do first when
	 * you intend to add another timestamp around an already-timestamped document to extend
	 * or enhance its verifiability (as described above), as per the PDF 2.0 and
	 * ETSI TS 102 778-4 (PAdES Level 4) specifications.
	 *
	 * @param in_verification_result -- a successful verification result containing a successful
	 * TrustVerificationResult
	 *
	 * @return a boolean status that reflects whether offline verification information was added successfully
	 *
	 * @note It is necessary to save the document incrementally after this function completes successfully
	 * in order to actually write the LTV data into the document.
	*/
	bool EnableLTVOfflineVerification(const VerificationResult& in_verification_result) const;	

	/** Must be called to prepare a secure PDF-embedded timestamp signature (RFC 3161 
	 * DocTimeStamp) for signing, which is done afterwards by calling Save on the 
	 * document with an e_incremental flag. Throws if document is locked by other 
	 * signatures,  if signature is already signed, or if another signature has already 
	 * been prepared for signing on the next save (because only one signing operation 
	 * can be done per incremental save). Default document permission level is 
	 * e_annotating_formfilling_signing_allowed.
	 * 
	 * @param in_timestamping_config -- Configuration options to store for timestamping.
	 * These will include various items related to contacting a timestamping authority.
	 * Incorrect configuration will result in document Save throwing an exception. 
	 * The usability of a combination of a TimestampingConfiguration and VerificationOptions 
	 * can be checked ahead of time to prevent exceptions by calling TestConfiguration on 
	 * TimestampingConfiguration and passing VerificationOptions.
	 *
	 * @param in_timestamp_response_verification_options -- Options for the timestamp
	 * response verification step (which is required by RFC 3161 to be done as part of 
	 * timestamping). These response verification options should include the root certificate
	 * of the timestamp authority, so that the trust status of the timestamp signature
	 * can be verified. The options that should be passed are the same ones that one expects
	 * the timestamp to be verifiable with in the future (once it is embedded in the document),
	 * except the response verification requires online revocation information whereas
	 * the later verification may not (depending on whether LTV offline verification
	 * information for the timestamp signature gets embedded into the document by that
	 * time). The timestamp response verification step makes sure that (a) the
	 * timestamp response has a success status, which is the only time that this is 
	 * verified in the entire workflow, which prevents embedding an unsuccessful 
	 * response; (b) that it digests the document correctly and is otherwise generally 
	 * verifiable; and (c) that the nonce is correct (which is the only time that this 
	 * is verifiable in the entire workflow) to prevent replay attacks (if it was not 
	 * requested in the TimestampingConfiguration that the nonce mechanism should be 
	 * disabled). 
	 *
	 * @note A failure in timestamp response verification will result in document Save
	 * throwing an exception. It is recommended to use TimestampingConfiguration.TestConfiguration 
	 * with the VerificationOptions ahead of time to avoid this.
	 * 
	 */
	void TimestampOnNextSave(const TimestampingConfiguration& in_timestamping_config,
		const VerificationOptions& in_timestamp_response_verification_options);
		
	/**
	 * Sets the requested SubFilter value (which identifies a signature type) as the only one to use during future signing, overwriting all such previous settings. It is not necessary to call HasCryptographicSignature before calling this function. For example, this function can be used to switch to PAdES signing mode.
	 * 
	 * @param in_subfilter_type -- The SubFilter type to set.
	 * @param in_make_mandatory -- Whether to make usage of this SubFilter mandatory for future signing applications. Default value for this parameter is true.
	 */
	void UseSubFilter(const SubFilterType in_subfilter_type, const bool in_make_mandatory = true);
		
// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	DigitalSignatureField(TRN_DigitalSignatureField impl);
	TRN_DigitalSignatureField m_impl;
#endif
// @endcond
};

#include <Impl/DigitalSignatureField.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFDigitalSignatureField
