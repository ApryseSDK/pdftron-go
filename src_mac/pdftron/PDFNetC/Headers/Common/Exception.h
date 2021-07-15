//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPCommonException
#define PDFTRON_H_CPPCommonException

#include <typeinfo>
#include <string>
#include <memory>
#include <cstdio>
#include <C/Common/TRN_Exception.h>

namespace pdftron { 
	namespace Common {

/**
 *  Exception is derived from standard C++ exception class and it is a superclass 
 *  for all PDFNet library exceptions.
 *
 *  Exception and its subclasses have two constructors: one that takes no arguments and 
 *  one that takes a string argument that can be used to report an error message.
 */
class Exception : public std::exception
{
public: 

	/**
	 * Constructs an Exception with no specified detail message.
	 */
	 Exception(){};

	 Exception(TRN_Exception e);

	/**
	 * Constructs an Exception with detailed error info.
	 *
	 * @param cond_expr - conditional expression that failed.
	 * @param line_number - line number where the exception occurred.
	 * @param file_name - file name where the exception occurred.
	 * @param function - function in which the exception occurred.
	 * @param message - detailed error message.
	 */
	 Exception(const char* cond_expr,
			  TRN_Int32 line_number, 
			  const char* file_name,
			  const char* function, 
			  const char* message,
			  TRN_UInt32 error_code = 0);

	 ~Exception() throw() {};

	/**
	 * @return the conditional expression that caused the exception
	 */
	 const char* GetCondExpr();

	/**
	 * @return the filename indicating where the exception occurred
	 */
	 const char* GetFileName();

	/**
	 * @return the line number indicating where the exception occurred
	 */
	 TRN_Int32 GetLineNumber();
	
	/**
	 * @return the function name where the exception occurred
	 */
	 const char* GetFunction();

	/**
	 * @return the error message string of this Exception object.
	 */
	 const char* GetMessage();

	/**
	 * @return a full description of this Exception object.
	 */
	 std::string ToString();

	/**
	 * Print out the Exception to the output stream.
	 */
	 std::ostream& Print(std::ostream& stream);

	 /**
	 * @return the error code of this Exception object.
	 */
	 TRN_UInt32 GetErrorCode();

	 /**
	  * Returns the full error message string.
	  * @return Pointer to a null-terminated string with full error information.
	  */
	 virtual const char* what() const throw();

	TRN_Exception e;

};


/**
 * The function allows the use of operator<< instead of Exception::Print
 * on any object derived from Exception
 *
 * @param	stream - the input stream where the print message will be written
 * @param	e - the exception object
 * @return  returns the output stream
 */
inline std::ostream& operator<<(std::ostream& stream, Exception& e) 
{
	return e.Print(stream);
}

#include <Impl/Exception.inl>

	};	// namespace Common
};	// namespace pdftron

#endif // PDFTRON_H_CPPCommonException
