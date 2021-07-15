//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFRect
#define PDFTRON_H_CPPPDFRect

#include <C/PDF/TRN_Rect.h>
#include <Common/Common.h>
#include <SDF/Obj.h>

namespace pdftron { 
	namespace PDF {

/**
 * Rect is a utility class used to manipulate PDF rectangle objects (refer to 
 * section 3.8.3 of the PDF Reference Manual). 
 * 
 * Rect can be associated with a SDF/Cos rectangle array using Rect(Obj*) constructor 
 * or later using Rect::Attach(Obj*) or Rect::Update(Obj*) methods. 
 * 
 * Rect keeps a local cache for rectangle points so it is necessary to call Rect::Update() 
 * method if the changes to the Rect should be saved in the attached Cos/SDF array.
 *
 * @note - Although rectangles are conventionally specified by their lower-left and 
 * upper-right corners, it is acceptable to specify any two diagonally opposite corners.
 */
class Rect : public TRN_Rect
{
public:

	/**
	 * Rect default constructor.
	 */
	 Rect ();

	/**
	 * Create a Rect and initialize it using given Cos/SDF rectangle Array object.
	 * The rect is attached to this object.
	 */
	 Rect (SDF::Obj rect);

	/**
	 * Create a Rect and initialize it using specified parameters.
	 * @param x1 The left-most position of the rect.
	 * @param y1 The bottom-most position of the rect.
	 * @param x2 The right-most position of the rect.
	 * @param y2 The top-most position of the rect.
	 * @return a Rect (rectangle) object
	 * The rect is not attached to any Cos/SDF object.
	 */
	 Rect (double x1, double y1, double x2, double y2);

	// copy constructor
	 Rect (const Rect& rect);

	// assignment operator
	 Rect& operator=(const Rect& rect);

	/** 
	 * Attach the Cos/SDF object to the Rect. 
	 * 
	 * @param obj - underlying Cos/SDF object. Must be an SDF::Array with four 
	 *  SDF::Number elements.
	 */
	 void Attach(SDF::Obj obj);

	/** 
	 * Saves changes made to the Rect object in the attached (or specified) SDF/Cos rectangle.
	 * 
	 * @param obj - an optional parameter indicating a SDF array that should be
	 *  updated and attached to this Rect. If parameter rect is NULL or is omitted, update 
	 *  is performed on previously attached Cos/SDF rectangle.
	 * 
	 * @return true if the attached Cos/SDF rectangle array was successfully updated, 
	 * false otherwise.
	 */
	 bool Update(SDF::Obj obj = NULL);

#ifndef SWIG
	/**
	 * Get the coordinates of the rectangle
	 */ 
	 void Get(double& out_x1, double& out_y1, double& out_x2, double& out_y2) const;
#endif

	/**
	 * Set the coordinates of the rectangle
	 * 
	 * @param x1 The left-most position of the rect.
	 * @param y1 The bottom-most position of the rect.
	 * @param x2 The right-most position of the rect.
	 * @param y2 The top-most position of the rect.
	 * The rect is not attached to any Cos/SDF object.
	 */ 
	 void Set(double x1, double y1, double x2, double y2);

	/**
	 * @return rectangle's width 
	 */ 
	 double Width() const;

	/**
	 * @return rectangle's height
	 */ 
	 double Height() const;

	/**
	 * Determines if the specified point is contained within the rectangular region 
	 * defined by this Rectangle
	 * @param x horizontal x value of the point to check
	 * @param y vertical y value of the point to check
	 * @return true is the point is in the rectangle, false otherwise.
	 */ 
	 bool Contains(double x, double y) const;

	/**
	 * Makes a Rect equal to the intersection of two existing rectangles.	 
	 * 
	 * @param rect1 - A Rect object that contains a source rectangle. 
	 * @param rect2 - A Rect object that contains a source rectangle. 
	 * 
	 * @return true if the intersection is not empty; 0 if the intersection is empty.
	 * 
	 * @note The intersection is the largest rectangle contained in both existing rectangles.
	 */
	 bool IntersectRect(const Rect& rect1, const Rect& rect2);

	/**
	 * Arrange the points in the rectangle so that the first point is the lower-left 
	 * corner and the second point is the upper-right corner of the rectangle.
	 * 
	 * @note Although rectangles are conventionally specified by their lower-left 
	 * and upper-right corners, it is acceptable to specify any two diagonally 
	 * opposite corners.
	 */ 
	 void Normalize();

	/**
	 * Expands the rectangle by the specified size, in all directions. 
	 * 
	 * @param amount Specifies the amount to increase the rectangle in all directions.
	 */ 
	void Inflate(double amount);

	/**
	 * Expands the rectangle by the specified size, in all directions. 
	 * 
	 * @param x Specifies the amount to increase the rectangle's Left (x1) and Right (x2) properties. 
	 * @param y Specifies the amount to increase the rectangle's Top (y1) and Bottom (y2) properties.
	 */ 
	void Inflate(double x, double y);


	/**
	 * @return The horizontal value of lower-left point.
	 */ 
	double GetX1() const; 

	/**
	* @return The vertical value of lower-left point.
	*/ 
	double GetY1() const; 

	/**
	 * @return The horizontal value of upper-right point.
	 */ 
	double GetX2() const; 

	/**
	* @return The vertical value of upper-right point.
	*/ 
	double GetY2() const;

	/**
	 * Set the horizontal value of lower-left point.
	 * @param x1 The left-most position of the rect.
	 */ 
	void SetX1(double x1); 

	/**
	 * Set the vertical value of lower-left point.
	 * @param y1 The bottom-most position of the rect.
	 */ 
	void SetY1(double y1); 

	/**
	 * Set the horizontal value of upper-right point.
	 * @param x2 The right-most position of the rect.
	 */ 
	void SetX2(double x2); 

	/**
	 * Set the vertical value of upper-right point.
	 * @param y2 The top-most position of the rect.
	 */ 
	void SetY2(double y2);
};

#include <Impl/Rect.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFRect
