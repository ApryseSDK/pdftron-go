//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFDigestAlgorithm
#define PDFTRON_H_CPPPDFDigestAlgorithm
#include <C/PDF/TRN_DigestAlgorithm.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace PDF { 


class DigestAlgorithm
{
public:
	//enums:
	enum Type {
		e_SHA1 = 0,
		e_SHA256 = 1,
		e_SHA384 = 2,
		e_SHA512 = 3,
		e_RIPEMD160 = 4,
		e_unknown_digest_algorithm = 5
	};


};

} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFDigestAlgorithm
