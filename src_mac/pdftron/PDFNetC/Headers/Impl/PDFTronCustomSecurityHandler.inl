
#ifndef PDFTronCustomSecurityHandler_INL
#define PDFTronCustomSecurityHandler_INL

#include <C/SDF/TRN_PDFTronCustomSecurityHandler.h>
#include <C/Common/TRN_BasicTypes.h>
#include <SDF/PDFTronCustomSecurityHandler.h>


inline PDFTronCustomSecurityHandler::PDFTronCustomSecurityHandler(UInt32 custom_id)
{
	REX(TRN_PDFTronCustomSecurityHandlerCreate((TRN_UInt32)custom_id, (TRN_SecurityHandler*)&mp_handler));
}

#endif
