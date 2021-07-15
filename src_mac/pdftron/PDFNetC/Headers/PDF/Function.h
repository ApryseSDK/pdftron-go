//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFFunction
#define PDFTRON_H_CPPPDFFunction

#include <C/PDF/TRN_Function.h>
#include <SDF/Obj.h>


namespace pdftron { 
	namespace PDF {


/** 
 * Although PDF is not a programming language it provides several types of function 
 * object that represent parameterized classes of functions, including mathematical 
 * formulas and sampled representations with arbitrary resolution. Functions are used 
 * in various ways in PDF, including device-dependent rasterization information for 
 * high-quality printing (halftone spot functions and transfer functions), color 
 * transform functions for certain color spaces, and specification of colors as a 
 * function of position for smooth shadings. Functions in PDF represent static, 
 * self-contained numerical transformations.<br><br>
 * 
 * PDF::Function represents a single, flat interface around all PDF function types.
 */
class Function
{
public:

	/** 
	 * Create a PDF::Function object from an existing SDF function dictionary. If funct_dict
	 * is null, a non valid Function object is created.
	 */
	 Function (SDF::Obj funct_dict = 0);
	 Function(const Function& f);
	 Function& operator=(const Function& f);
	 ~Function();

	enum Type
	{
		e_sampled     = 0, // uses a table of sample values to define the function.
		e_exponential = 2, // defines a set of coefficients for an exponential function.
		e_stitching   = 3, // a combination of other functions, partitioned across a domain.
		e_postscript  = 4  // A PostScript calculator function.
	};

	/**
	 * @return The function type
	 */ 
	 Type GetType() const;

	/** 
	 * @return the number of input components required by the function
	 */
	 int GetInputCardinality();

	/** 
	 * @return the number of output components returned by the function
	 */
	 int GetOutputCardinality();

	/**
	 * Evaluate the function at a given point.
	 *
	 * @note that size of 'in' array must be greater than or equal to function 
	 * input cardinality. and the size of 'out' array must be greater than or equal 
	 * to function output cardinality.
	 */ 
	 std::vector<double> Eval(const std::vector<double>& in_arr);

#ifndef SWIG
	 void Eval(double *in, double *out);
#endif

	/**
	 * @return the underlying SDF/Cos object
	 */
	 SDF::Obj GetSDFObj ();

	 /**
	 * Frees the native memory of the object.
	 */
	 void Destroy();

// @cond PRIVATE_DOC	
#ifndef SWIGHIDDEN
	 Function(TRN_Function impl);
	TRN_Function mp_func;
#endif
// @endcond
};


#include <Impl/Function.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFFunction
