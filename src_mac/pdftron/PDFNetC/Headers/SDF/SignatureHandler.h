//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPSDFSignatureHandler
#define PDFTRON_H_CPPSDFSignatureHandler

#include <vector>
#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <SDF/Obj.h>
#include <C/Common/TRN_Types.h>
#include <C/SDF/TRN_SignatureHandler.h>

namespace pdftron {
namespace SDF {

/**
 * Used for identifying a SignatureHandler instances as they are added to the PDFDoc's SignatureManager.
 */
typedef size_t SignatureHandlerId;

/**
 * A base class for SignatureHandler. SignatureHandler instances are responsible for defining the digest and cipher
 * algorithms to create and/or validate a signed PDF document. SignatureHandlers are added to PDFDoc instances by
 * calling the PDFDoc::AddSignatureHandler method.
 */
class SignatureHandler
{
public:
    /**
	 * Gets the name of this SignatureHandler. The name of the SignatureHandler is what identifies this SignatureHandler
     * from all others. This name is also added to the PDF as the value of /Filter entry in the signature dictionary.
	 * @return The name of this SignatureHandler.
	 */
	virtual UString GetName() const;
    
	/**
	 * Adds data to be signed. This data will be the raw serialized byte buffer as the PDF is being saved to any stream.
	 * @param data A chunk of data to be signed.
	 */
    virtual void AppendData(const std::vector<pdftron::UInt8>& data);
    
	/**
	 * Resets any data appending and signature calculations done so far. This method should allow PDFNet to restart the
     * whole signature calculation process. It is important that when this method is invoked, any data processed with
     * the AppendData method should be discarded.
	 * @return True if there are no errors, otherwise false.
	 */
	virtual bool Reset();
    
	/**
	 * Calculates the actual signature using client implemented signing methods. The returned value (byte array) will
	 * be written as the /Contents entry in the signature dictionary.
	 * @return The calculated signature data.
	 */
	virtual std::vector<pdftron::UInt8> CreateSignature();

    /**
     * This method returns a cloned copy of the current instance.
	 * @return A new, cloned instance of SignatureHandler.
	 * @note this method must be implemented in any derived class from SignatureHandler.
     */
    virtual SignatureHandler* Clone() const = 0;

    /**
     * Destructor.
     */
    virtual ~SignatureHandler();

#ifndef SWIGHIDDEN_SIG
    static TRN_Exception TRN_SIGAPI TRN_SignatureHandlerGetNameImpl(TRN_UString* out_name, void* derived);
    static TRN_Exception TRN_SIGAPI TRN_SignatureHandlerAppendDataImpl(const TRN_SignatureData in_data, void* derived);
    static TRN_Exception TRN_SIGAPI TRN_SignatureHandlerResetImpl(TRN_Bool* out_result, void* derived);
    static TRN_Exception TRN_SIGAPI TRN_SignatureHandlerCreateSignatureImpl(TRN_SignatureData* out_signature, void* derived);
    //static TRN_Exception TRN_SIGAPI TRN_SignatureHandlerValidateSignatureImpl(TRN_Obj in_sig_dict, TRN_ValidateSignatureResult* out_result, void* derived);
    static TRN_Exception TRN_SIGAPI TRN_SignatureHandlerDestroyImpl(void* derived);

    std::vector<pdftron::UInt8> m_signature_data;
#endif // SWIGHIDDEN_SIG
}; // class SignatureHandler

}; // namespace SDF
}; // namespace pdftron

#include <Impl/SignatureHandler.inl>

#endif // PDFTRON_H_CPPSDFSignatureHandler
