//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFQuadPoint
#define PDFTRON_H_CPPPDFQuadPoint

#include <PDF/Point.h>
#include <PDF/Rect.h>

namespace pdftron {
	namespace PDF {

		class QuadPoint
		{
		public:
			QuadPoint()
			{
				p1.x = 0;
				p1.y = 0;
				p2.x = 0;
				p2.y = 0;
				p3.x = 0;
				p3.y = 0;
				p4.x = 0;
				p4.y = 0;
			}

			QuadPoint(Point p11, Point p22, Point p33, Point p44)
			{
				p1.x = p11.x;
				p1.y = p11.y;
				p2.x = p22.x;
				p2.y = p22.y;
				p3.x = p33.x;
				p3.y = p33.y;
				p4.x = p44.x;
				p4.y = p44.y;
			}

			QuadPoint(const Rect& r)
			{
				p1.x = r.GetX1();
				p1.y = r.GetY1();
				p2.x = r.GetX2();
				p2.y = r.GetY1();
				p3.x = r.GetX2();
				p3.y = r.GetY2();
				p4.x = r.GetX1();
				p4.y = r.GetY2();
			}

			Point p1;
			Point p2;
			Point p3;
			Point p4;
		};

	}	// namespace PDF
}	// namespace pdftron

#endif // PDFTRON_H_CPPPDFQuadPoint
