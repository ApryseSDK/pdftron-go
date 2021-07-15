//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPoint
#define PDFTRON_H_CPPPDFPoint

namespace pdftron { 
	namespace PDF {


class Point: public TRN_Point
{
	public:
		Point()	{ x=(0); y=(0);}
		Point(double px,double py) { x=(px); y=(py); }
};

	}	// namespace PDF
}	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPoint
