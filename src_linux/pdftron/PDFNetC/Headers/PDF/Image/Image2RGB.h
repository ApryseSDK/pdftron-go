//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFImage2RGB
#define PDFTRON_H_CPPPDFImage2RGB

#include <Filters/Filter.h>
#include <C/Filters/TRN_Filter.h>
#include <PDF/Element.h>
#include <PDF/Image.h>

namespace pdftron { 
	namespace PDF {

/** 
 * Image2RGB is a filter that can decompress and normalize any PDF image stream 
 * (e.g. monochrome, CMYK, etc) into a raw RGB pixel stream.
 */
class Image2RGB : public Filters::Filter
{
public:
	Image2RGB(Element image_element);
	Image2RGB(SDF::Obj image_xobject);
	Image2RGB(Image image);
};

#include <Impl/Image2RGB.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFImage2RGB
