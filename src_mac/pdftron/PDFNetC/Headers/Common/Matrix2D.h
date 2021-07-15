//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPCommonMatrix2D
#define PDFTRON_H_CPPCommonMatrix2D

#include <Common/Common.h>
#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Matrix2D.h>
#include <PDF/Point.h>
#include <vector>


namespace pdftron { 
	namespace Common {


/** 
 * 2D Matrix
 *
 * A Matrix2D object represents a 3x3 matrix that, in turn, represents an affine transformation. 
 * A Matrix2D object stores only six of the nine numbers in a 3x3 matrix because all 3x3 
 * matrices that represent affine transformations have the same third column (0, 0, 1).
 * 
 * Affine transformations include rotating, scaling, reflecting, shearing, and translating. 
 * In PDFNet, the Matrix2D class provides the foundation for performing affine transformations 
 * on vector drawings, images, and text.
 * 
 * A transformation matrix specifies the relationship between two coordinate spaces.
 * By modifying a transformation matrix, objects can be scaled, rotated, translated,
 * or transformed in other ways.
 * 
 * A transformation matrix in PDF is specified by six numbers, usually in the form
 * of an array containing six elements. In its most general form, this array is denoted
 * [a b c d h v]; The following table lists the arrays that specify the most common
 * transformations:
 * 
 *   - Translations are specified as [1 0 0 1 tx ty], where tx and ty are the distances
 *     to translate the origin of the coordinate system in the horizontal and vertical
 *     dimensions, respectively.
 *
 *   - Scaling is obtained by [sx 0 0 sy 0 0]. This scales the coordinates so that 1
 *     unit in the horizontal and vertical dimensions of the new coordinate system is
 *     the same size as sx and sy units, respectively, in the previous coordinate system.
 * 
 *   - Rotations are produced by [cos(A) sin(A) -sin(A) cos(A) 0 0], which has the effect
 *     of rotating the coordinate system axes by an angle 'A' counterclockwise.
 *
 *   - Skew is specified by [1 tan(A) tan(B) 1 0 0], which skews the x axis by an angle
 *     A and the y axis by an angle B.
 * 
 *  Matrix2D elements are positioned as follows :
 *			| m_a m_b 0 |
 *			| m_c m_d 0 |
 *			| m_h m_v 1 |
 * 
 * A single Matrix2D object can store a single transformation or a sequence of transformations. 
 * The latter is called a composite transformation. The matrix of a composite transformation is 
 * obtained by multiplying (concatenating) the matrices of the individual transformations. 
 * Because matrix multiplication is not commutative-the order in which matrices are multiplied
 * is significant. For example, if you first rotate, then scale, then translate, you get a 
 * different result than if you first translate, then rotate, then scale.
 *
 * For more information on properties of PDF matrices please refer to PDF Reference Manual 
 * (Sections 4.2 'Coordinate Systems' and 4.2.3 'Transformation Matrices')
 * 
 * @code 		
 * The following sample illustrates how to use Matrix2D in order to position
 * an image on the page. Note that PDFNet uses the same convention of matrix 
 * multiplication used in PostScript and OpenGL.
 *
 *	Element element = eb.CreateImage(Image(...));
 *	double deg2rad = 3.1415926535 / 180.0;
 *
 *	Matrix2D mtx = Matrix2D(1, 0, 0, 1, 0, 200); // Translate
 *	mtx *= Matrix2D(300, 0, 0, 200, 0, 0);    // Scale
 *	mtx *= Matrix2D::RotationMatrix( 90 * deg2rad ); // Rotate
 *	element.GetGState().SetTransform(mtx);
 *	writer.WritePlacedElement(element);
 * @endcode 					
 * 
 * @code 		
 * The following sample sample illustrates how to use Matrix2D in order to calculate 
 * absolute positioning for the text on the page.
 * ...
 * Matrix2D text_mtx = text_element.GetTextMatrix();
 * double x, y;
 * for (CharIterator itr = text_element.GetCharIterator(); itr.HasNext(); itr.Next()) {
 *   x = itr.Current().x; // character positioning information
 *   y = itr.Current().y;
 *   // Get current transformation matrix (CTM)
 *   Matrix2D ctm = text_element.GetCTM();
 *
 *   // To get the absolute character positioning information concatenate current 
 *   // text matrix with CTM and then multiply relative positioning coordinates with 
 *   // the resulting matrix.
 *   Matrix2D mtx = ctm * text_mtx;
 *   mtx.Mult(x, y);
 * }
 * @endcode 					
 */
class Matrix2D : public TRN_Matrix2D
{
public:

	/**
	 * Creates and initializes a Matrix object based on six numbers that define an 
	 * affine transformation. 
	 *
	 * @param a the matrix element in the first row, first column. 
	 * @param b the matrix element in the first row, second column. 
	 * @param c the matrix element in the second row, first column. 
	 * @param d the matrix element in the second row, second column. 
	 * @param h the matrix element in the third row, first column. 
	 * @param v the matrix element in the third row, second column. 
	 *
	 * @default when none the arguments are specified, an identity matrix is created.
	 */
	 Matrix2D(double a = 1, double b = 0, double c = 0, double d = 1, double h = 0, double v = 0);

	/**
	 * Copy constructor.
	 */
	 Matrix2D(const Matrix2D& m);

	/**
	 * Assignment operator.
	 */
	 Matrix2D& operator= (const Matrix2D& m);

	/**
	 * The Set method sets the elements of this matrix.
	 *
	 * @param a the matrix element in the first row, first column. 
	 * @param b the matrix element in the first row, second column. 
	 * @param c the matrix element in the second row, first column. 
	 * @param d the matrix element in the second row, second column. 
	 * @param h the matrix element in the third row, first column. 
	 * @param v the matrix element in the third row, second column. 
	 */
	 void Set (double a, double b, double c, double d, double h, double v);

	/** 
	 * The Concat method updates this matrix with the product of itself and another matrix
	 * specified through an argument list.
	 *
	 * @param a the matrix element in the first row, first column. 
	 * @param b the matrix element in the first row, second column. 
	 * @param c the matrix element in the second row, first column. 
	 * @param d the matrix element in the second row, second column. 
	 * @param h the matrix element in the third row, first column. 
	 * @param v the matrix element in the third row, second column. 
	 */
	 void Concat(double a, double b, double c, double d, double h, double v);

#if !defined(SWIG)
	/** 
	 * The multiply method updates this matrix with the product of itself and another matrix.
	 *
	 * @param m A matrix used to update this matrix
	 * @return updated this matrix representing the product of this matrix and given matrix 'm'.
	 */
	 Matrix2D& operator*= (const Matrix2D& m);

	/** 
	 * Multiplies this matrix with another matrix and return the result in a new matrix.
	 *
	 * @return a matrix representing the product of this matrix and given matrix 'm'.
	 */
	 Matrix2D operator* (const Matrix2D& m) const;

	/** 
	 * The equality operator determines whether the elements of this matrix are equal to 
	 * the elements of another matrix.
	 * 
	 * @param m A Matrix object that is compared with this Matrix object.
	 * @return A boolean regarding whether two matrices are the same.
	 */
	 bool operator== (const Matrix2D& m) const;

	/** 
	 * The inequality operator determines whether the elements of this matrix are not equal to 
	 * the elements of another matrix.
	 * 
	 * @param A Matrix object that is compared with this Matrix object.
	 * @return A boolean regarding whether two matrices are different.
	 */
	 bool operator!= (const Matrix2D& m) const {return !(this->operator ==(m));}
#else // !defined(SWIG)
     Matrix2D Multiply(const Matrix2D& m);
     bool IsEquals(const Matrix2D& m) const;
     bool IsNotEquals(const Matrix2D& m) const
     {
         return (!this->IsEquals(m));
     }
#endif // !defined(SWIG)
	/**
	 * Transform/multiply the point (in_out_x, in_out_y) using this matrix
	 */
	 PDF::Point Mult(const PDF::Point & pt) const;

#ifndef SWIG
	 void Mult(double& in_out_x, double& in_out_y) const;
#endif


	/**
	 * @return If this matrix is invertible, the Inverse method returns its inverse matrix.
	 */ 
	 Matrix2D Inverse () const;

	/**
	 * Updates this matrix with the product of itself and a 
	 * translation matrix (i.e. it is equivalent to this.m_h += h; this.m_v += v).
	 * 
	 * @param h the horizontal component of the translation. 
	 * @param v the vertical component of the translation. 
	 * @note This method is deprecated. Please use PreTranslate or PostTranslate instead. The behavior of this method is identical to PreTranslate, but
	 * PostTranslate will be more suitable for some use cases. 
	 */
	 void Translate (double h, double v);

	/**
	 * Updates this matrix to the concatenation of a translation matrix and the original matrix.
	 * M' = T(h, v) * M. It is equivalent to this.m_h += h; this.m_v += v.
	 *
	 * @param h the horizontal component of the translation.
	 * @param v the vertical component of the translation.
	 */
	 void PreTranslate(double h, double v);

	/**
	  * Updates this matrix by concatenating a translation matrix.
	  * M' = M * T(h, v). It is equivalent to this.Concat(1,0,0,1,h,v).
	  *
	  * @param h the horizontal component of the translation.
	  * @param v the vertical component of the translation.
	  */
	  void PostTranslate(double h, double v);

	/**
	 * The Scale method updates this matrix with the product of itself and a scaling matrix.
	 * @param h the horizontal scale factor. 
	 * @param v the vertical scale factor
	 */
	 void Scale (double h, double v);

	/**
	 * Create zero matrix (0 0 0 0 0 0)
	 */
	 static Matrix2D ZeroMatrix ();			

	/**
	 * Create identity matrix (1 0 0 1 0 0)
	 */
	 static Matrix2D IdentityMatrix ();		

	/** 
	 * @return A rotation matrix for a given angle.
	 * @param angle the angle of rotation in radians. 
	 * Positive values specify clockwise rotation. 
	 */
	 static Matrix2D RotationMatrix (const double angle);
};


#include <Impl/Matrix2D.inl>

	};	// namespace Common
};	// namespace pdftron

#endif // PDFTRON_H_CPPCommonMatrix2D
