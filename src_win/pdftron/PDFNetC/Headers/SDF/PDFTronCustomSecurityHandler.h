//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPSDFPDFTronCustomSecurityHandler
#define PDFTRON_H_CPPSDFPDFTronCustomSecurityHandler

#include <Common/BasicTypes.h>
#include <SDF/SecurityHandler.h>

namespace pdftron { namespace SDF { 

/**
 * This class represents PDFTron Custom Security handler that applies PDFTron's custom encryption method on save.
 */
class PDFTronCustomSecurityHandler : public SecurityHandler
{
public:
	/**
	 * constructor
	 *
	 * @param custom_id the user's custom ID. A random ID is suggested to make the custom security unique to the application.
	 *
	 * @note Please refer to PDFNet::AddPDFTronCustomHandler(UInt32 custom_id) for more details.
	 */
	PDFTronCustomSecurityHandler(UInt32 custom_id);

};

#include <Impl/PDFTronCustomSecurityHandler.inl>
} //end pdftron
} //end SDF


#endif //PDFTRON_H_CPPSDFPDFTronCustomSecurityHandler
