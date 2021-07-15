//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef H_PDFDate
#define H_PDFDate

#include <SDF/Obj.h>
#include <C/PDF/TRN_Date.h>

namespace pdftron { 
	namespace PDF {


/** 
 * The Date class is a utility class used to simplify work with PDF date objects.
 *
 * PDF defines a standard date format, which closely follows international
 * standard ASN.1 (Abstract Syntax Notation One), A date is a string of the form
 * (D:YYYYMMDDHHmmSSOHH'mm'); See PDF Reference Manual for details. 
 * 
 * Date can be associated with a SDF/Cos date string using Date(Obj*) constructor 
 * or later using Date::Attach(Obj*) or Date::Update(Obj*) methods. 
 * 
 * Date keeps a local date/time cache so it is necessary to call Date::Update() 
 * method if the changes to the Date should be saved in the attached Cos/SDF string.
 */
class Date : public TRN_Date
{
public:

	/**
	 * Date default constructor.
	 */
	 Date ();

	/**
	 * Create a Date and initialize it using given Cos/SDF string date object.
	 * String date object is attached to this Date.
	 * @param d The Cos/SDF object to initialze the Date object with.
	 */
	 Date (SDF::Obj d);

	/**
	 * Create a Date and initialize it using specified parameters.
	 * The Date is not attached to any Cos/SDF object.
	 * @param year number representing the year to initialize the Date object to.
	 * @param month number representing the month to initialize the Date object to.
	 * @param day number representing the day to initialize the Date object to.
	 * @param hour number representing the hour to initialize the Date object to.
	 * @param minute number representing the minute to initialize the Date object to.
	 * @param second number representing the second to initialize the Date object to.
	 */
	 Date (UInt16 year, char month, char day, char hour, char minute, char second);

	/**
	 * Copy constructor
	 */
	 Date (const Date& d);

	/**
	 * Assignment operator
	 */
	 Date& operator=(const Date& d);

	/**
	 * Indicates whether the Date is valid (non-null).
	 *
	 * @return True if this is a valid (non-null) Date; otherwise false.
	 *
	 * @note If this method returns false the underlying SDF/Cos object is null and 
	 * the Date object should be treated as null as well.
	 */ 	
	 bool IsValid() const;

	/**
	 * Sets the date object to the current date and time. The method also updates 
	 * associated SDF object.
	 */
	void SetCurrentTime();

	/** 
	 * Attach the Cos/SDF object to the Date. 
	 * 
	 * @param d - underlying Cos/SDF object. Must be an SDF::Str containing
	 *  a PDF date object.
	 */
	 void Attach(SDF::Obj d);

	/** 
	 * Saves changes made to the Date object in the attached (or specified) SDF/Cos string.
	 * 
	 * @param d - an optional parameter indicating a SDF string that should be
	 *  updated and attached to this Date. If parameter d is NULL or is omitted, update 
	 *  is performed on previously attached Cos/SDF date.
	 * 
	 * @return true if the attached Cos/SDF string was successfully updated, false otherwise.
	 */
	 bool Update(SDF::Obj d = NULL);

	 /** 
	  * @return The year.
	  */
	UInt16 GetYear(); 

#ifndef SWIG
	/** 
	 * @return The month.
	 */
	char GetMonth();

	/** 
	 * @return The day (01-31).
	 */
	char GetDay();

	/** 
	 * @return The hour (00-23).
	 */
	char GetHour();

	/** 
	 * @return The minute (00-59).
	 */
	char GetMinute();

	/** 
	 * @return The second (00-59).
	 */
	char GetSecond();

	/** 
	 * @return The relationship of local time to Universal Time (UT), 
	 * denoted by one of the characters +, -, or Z 
	 */
	char GetUT();	   

	/** 
	 * @return the absolute value of the offset from UT in hours (00-23)
	 */
	char GetUTHour();  

	/** 
	* @return the absolute value of the offset from UT in minutes (00-59)
	*/
	char GetUTMin();
#else // SWIG
	UInt8 GetMonth();
	UInt8 GetDay();
	UInt8 GetHour();
	UInt8 GetMinute();
	UInt8 GetSecond();
	UInt8 GetUT();	
	UInt8 GetUTHour();
	UInt8 GetUTMin();
#endif // SWIG
};


#include <Impl/Date.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif // H_PDFDate
