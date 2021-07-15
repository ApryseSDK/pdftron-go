//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFImage2RGBA
#define PDFTRON_H_CPPPDFImage2RGBA

#include <Filters/Filter.h>
#include <Filters/FilterReader.h>
#include <PDF/Element.h>
#include <PDF/Image.h>

namespace pdftron { 
	namespace PDF {

/** 
 * Image2RGBA is a filter that can decompress and normalize any PDF image stream 
 * (e.g. monochrome, CMYK, etc) into a raw RGBA pixel stream.
 */
class Image2RGBA : public Filters::Filter
{
public:
	Image2RGBA(Element image_element, bool premultiply = false);
	Image2RGBA(SDF::Obj image_xobject, bool premultiply = false);
	Image2RGBA(Image& image, bool premultiply = false);
};


#include <Impl/Image2RGBA.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFImage2RGBA
