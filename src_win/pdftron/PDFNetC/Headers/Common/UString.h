//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPCommonUString
#define PDFTRON_H_CPPCommonUString

#include <Common/BasicTypes.h>
#include <Common/Exception.h>
#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_UString.h>
#include <Common/Common.h>
#include <ostream>

namespace pdftron { 

/**
 * Represents text as a series of Unicode characters.
 * 
 * @note Under .NET and Java environments the UString is mapped to built-in 
 * String types, so it is usually not necessary to directly use UString.
 * 
 * @note UString-s are usually referred to as strings, but they should not be 
 * confused with the null-terminated C-strings.
 */
class UString
{
public:

	/**
	 *  Create an empty string.
	 */
	 UString();

	/**
	 * Create a new string from UString.
	 * @param str a UString.
	 */
	 UString(const UString& str);

	/**
	 * Create a new string from a single Unicode character.
	 *
	 * @param value a Unicode character.
	 */
	 explicit UString(Unicode value);

	/**
	 * Create a new string from a Unicode character buffer array.
	 * 
	 *  @param value - a NULL-terminated Unicode character array.
	 */
	 UString(const Unicode* value);

	/**
	 * Create a new string from a Unicode character buffer array.
	 *
	 * @param value a Unicode character array.
	 * @param length the number of character which should be copied.
	 * The character array length must be greater or equal than this value.
	 */
	 UString(const Unicode* value, int length);

	/** 
	 * A descriptor for the 8-bit character buffer encoding
	 */
	enum TextEncoding {
		e_ascii_enc = 0,   ///< ASCII encoded text.
		e_pdfdoc_enc,      ///< PDFDocEncoding. See Appendix 'D' in PDF Reference.
		e_winansii_enc,    ///< WinAnsiiEncoding. See Appendix 'D' in PDF Reference.
		e_pdftext_enc,     ///< Text represented as PDF Text (section 3.8.1 'Text Strings' in PDF Reference).
		e_utf16be_enc,     ///< UTF-16BE (big-endian) encoding scheme.
		e_utf8,            ///< UTF-8 encoding scheme.
		e_no_enc           ///< No specific encoding.
	};

	/**
	 * Create a new string from a 8-bit character buffer array.
	 * 
	 * @param value An 8-bit character array.
	 * @param buf_sz the number of character which should be converted. The 8-bit 
	 * character array length must be greater or equal than this value. A negative 
	 * number means that the string is null terminated.
	 * @param encoding the text encoding from which the 8-bit character sequence 
	 * should be converted.
	 */
	 UString(const char* buf, int buf_sz = -1, TextEncoding enc = e_utf8);

	/**
	 * Create a new string from a 8-bit std::string
	 * 
	 * @param value An 8-bit character array.
	 * @param encoding the text encoding from which the 8-bit character sequence 
	 * should be converted.
	 */
	UString(const std::string & str, TextEncoding enc = e_utf8);

	/**
	 * Create a new string from a wide string native to the current compiler.
	 *
	 * @param value a string which will be converted to a new UString.
	 */
	UString( const std::wstring& value );

	/**
	 * Destructor
	 */
	~UString();

	/**
	 * 	Assign a new string.
	 *	@param str  a UString.
	 */
	 UString& operator=(const UString& str);
	 UString& operator=(const char* ascii_str);

	/** 
	 * Assigns new character values to the contents of a string.
	 * @return A reference to the string object that is being assigned new characters.
	 */
	 UString& Assign(const UString& uni);
	 UString& Assign(const Unicode* uni, int buf_sz = -1);
	 UString& Assign2(const char* buf, int buf_sz = -1, TextEncoding enc = e_utf8);

	/**
	 *	Append a string to this string.
	 *	@param str a UString to append to this string.
	 */
	 UString& operator+=(const UString& str);

	/**
	 * Concatenates the specified string to the end of this string.
	 * 
	 * @param str   the string that is concatenated to the end of this string.
	 * @return a string that represents the concatenation of this string
	 * followed by the string argument.
	 */
	 UString Concat(const UString &str) const;

	friend UString operator+( const UString& str1, const UString& str2) { return str1.Concat(str2);}

	/**
	 * Returns the length of this string.
	 * The length is equal to the number of Unicode characters in this string.
	 *
	 * @return the length of the sequence of characters represented by this object.
	 */
	 int GetLength() const;

	/**
	 * Tests whether the string contains any characters.
	 * @return true is the string is empty, false otherwise. 
	 */
	 bool Empty() const;

	/**
	 * Returns a pointer to the Unicode character buffer from this string.
	 * The string is not necessarily NULL terminated.
	 * 
	 * @return a pointer to the Unicode characters buffer from this object.
	 * For an empty string return a non-null pointer that cannot be dereferenced.
	 */
	 const Unicode* GetBuffer() const;

	/**
	 * Compares two strings.
	 * 
	 * 	The comparison is based on the numeric value of each character in
	 * 	the strings and return a value indicating their relationship.
	 * 	This function can't be used for language specific sorting.
	 * 
	 * @param    str         the object to be compared.
	 * @param    max_length (optional parameter) the maximum count of characters 
	 *           to be compared. Negative number means that the entire string 
	 *           should be compared.
	 * @return   0 - if both strings are equal
	 *         < 0 - if this string is less than the string argument
	 *         > 0 - if this string is greater than the string argument
	 */
	 int Compare(const UString& str, int max_length = -1) const;

	/**
	 * Copies a substring of at most some number of characters from a string 
	 * beginning from a specified position.
	 *
	 * @param off An index locating the element at the position from which 
	 * the copy of the string is made, with a default value of 0.
	 * 
	 * @param count The number of characters that are to be copied if they 
	 * are present. -1 means copy the entire string.
	 *
	 * @return A substring object that is a copy of elements of the string operand 
	 * beginning at the position specified by the first argument.
	 */
	 UString SubStr(int off = 0, int count = -1) const;

	/** 
	 * Provides a reference to the character with a specified index in a string.
	 * 
	 * @param idx The index of the position of the element to be referenced 
	 *
	 * @return A reference to the character of the string at the position specified 
	 * by the parameter index. 
	 * 
	 * The first element of the string has an index of zero and the following elements 
	 * are indexed consecutively by the positive integers.
	 */
	 Unicode GetAt(int idx) const;

	/**
	 * Adds an element to the end of the string.
	 * @param ch The character to be added to the end of the string.
	 */
	 void PushBack(Unicode ch);

	/** 
	 * Specifies a new size for a string, appending or erasing elements as required.
	 * 
	 * @param count The new size of the string.
	 * @param ch The value that appended characters are initialized with if additional 
	 * elements are required.
	 */
	 void Resize(int count, Unicode ch = ' ');

	/** 
	 * Converts all characters in a string to uppercase.
	 */
	void ToUpper();

	/** 
	 * Converts all characters in a string to lowercase.
	 */
	void ToLower();

	/** 
	 * Sets the capacity of the string to a number at least as great as a specified number.
	 * @param count The number of characters for which memory is being reserved.
	 */
	 void Reserve(int count);

	/** 
	 * Returns the contents of a UString as a C-style, null-terminated Unicode string.
	 * 
	 * @note same as string::c_str() method in standard C++ library. All caveats
	 * apply here.
	 */
	 const Unicode* CStr() const;
	
	/**
	 * @return true if all characters in the string are ASCII, false 
	 * otherwise.
	 */
	 bool IsInAscii() const;

	/**
	 * Convert to ASCII C string.
	 * 
	 * @param in_out_buf if NULL the function returns the number of bytes
	 * required to store the ASCII string. If in_out_buf is not NULL the 
	 * function will fill out the buffer with ASCII converted string.
	 * 
	 * @param buf_sz Size of the in_out_buf buffer, in bytes. 
	 * If the length of the converted string exceeds the size that the buf_sz
	 * parameter specifies, the string is truncated to buf_sz-1 characters.
	 * 
	 * @param null_term to null terminate the converted string set this 
	 * parameter to true.
	 * 
	 * @return the number of bytes written in the buffer. If the buffer is 
	 * too small to hold the converted string, the string is truncated to buf_sz-1.
	 */
	 int ConvertToAscii(char* in_out_buf, int buf_sz, bool null_term) const;

	/**
	 * Convert to UTF8 C string.
	 * 
	 * @param in_out_buf if NULL the function returns the number of bytes
	 * required to store the UTF8 string. If in_out_buf is not NULL the 
	 * function will fill out the buffer with UTF8 converted string.
	 * 
	 * @param buf_sz Size of the in_out_buf buffer, in bytes. 
	 * If the length of the converted string exceeds the size that the buf_sz
	 * parameter specifies, the string is truncated to buf_sz-1 characters.
	 * 
	 * @param null_term to null terminate the converted string set this 
	 * parameter to true.
	 * 
	 * @return the number of bytes written in the buffer (including null 
	 * terminator if specified).  If the buffer is too small to hold the 
	 * converted string, the string is truncated to buf_sz-1.
	 */
	 int ConvertToUtf8(char* in_out_buf, int buf_sz, bool null_term) const; 

	/**
	 * Convert to UTF32 C string.
	 * 
	 * @param in_out_buf if NULL the function returns the number of bytes
	 * required to store the UTF8 string. If in_out_buf is not NULL the 
	 * function will fill out the buffer with UTF32 converted string.
	 * 
	 * @param buf_sz Size of the in_out_buf buffer, in bytes. 
	 * If the length of the converted string exceeds the size that the buf_sz
	 * parameter specifies, the string is truncated to buf_sz-1 characters.
	 * 
	 * @param null_term to null terminate the converted string set this 
	 * parameter to true.
	 * 
	 * @return the number of bytes written in the buffer (including null 
	 * terminator if specified).  If the buffer is too small to hold the 
	 * converted string, the string is truncated to buf_sz-1.
	 */
	int ConvertToUtf32( UInt32* out_buf, int buf_sz, bool null_term ) const;

	/**
	 * Convert to std::wstring that is in the native representation of the current platform.
	 */
	std::wstring ConvertToNativeWString() const;

	/**
	 * Convert to ASCII std::string.
	 * @note A C++ utility method for quick and simple conversion to ASCII std::string.
	 */
	 std::string ConvertToAscii() const; 

	/**
	* Convert to UTF8 encoded std::string.
	* @note A C++ utility method for quick and simple conversion to UTF8 std::string.
	*/
	std::string ConvertToUtf8() const;

	/**
	* Convert to UTF32 encoded std::string.
	*/
	std::basic_string<UInt32> ConvertToUtf32() const;

	/**
	 * Convert the Unicode string to 'PDF Text' string. 
	 * 
	 * PDF Text Strings are not used to represent page content, however they
	 * are used in text annotations, bookmark names, article names, document 
	 * information etc. These strings are encoded in either PDFDocEncoding or 
	 * Unicode character encoding. For more information on PDF Text Strings, 
	 * please refer to section 3.8.1 'Text Strings' in PDF Reference.
	 * 
	 * @param in_out_buf if NULL the function returns the number of bytes
	 * required to store the converted string. If in_out_buf is not NULL the 
	 * function will fill out the buffer with PDF Text data.
	 * 
	 * @param buf_sz Size of the in_out_buf buffer, in bytes. 
	* If the length of the converted string exceeds the size that the buf_sz
	 * parameter specifies, the string is truncated to buf_sz characters.
	 * 
	 * @param force_unicode (optional) If true the string will always be 
	 * converted as Unicode. If false (which is default) the function will 
	 * first attempt to encode the sting using PDFDocEncoding. If the string 
	 * can't be mapped to PDFDocEncoding it will be converted as Unicode.
	 * 
	 * @return the number of bytes written in the buffer. If the buffer is 
	 * too small to hold the converted string, the string is truncated to buf_sz.
	 */
	 int ConvertToPDFText(char* in_out_buf, int buf_sz, bool force_unicode = false) const;

	 friend bool operator == (const UString& rStr1, const UString& rStr2) { return rStr1.GetLength() == rStr2.GetLength() && rStr1.Compare( rStr2 ) == 0; }
	 friend bool operator == (const UString& rStr1, const Unicode* pStr2) { return rStr1.Compare( pStr2 ) == 0; }
	 friend bool operator == (const Unicode* pStr1, const UString& rStr2) { return UString( pStr1 ).Compare( rStr2 ) == 0; }
	 friend bool operator != (const UString& rStr1, const UString& rStr2) { return !(operator == ( rStr1, rStr2 )); }
	 friend bool operator != (const UString& rStr1, const Unicode* pStr2) { return !(operator == ( rStr1, pStr2 )); }
	 friend bool operator != (const Unicode* pStr1, const UString& rStr2) { return !(operator == ( pStr1, rStr2 )); }
	 friend bool operator <  (const UString& rStr1, const UString& rStr2) { return rStr1.Compare( rStr2 ) < 0; }
	 friend bool operator >  (const UString& rStr1, const UString& rStr2) { return rStr1.Compare( rStr2 ) > 0; }
	 friend bool operator <= (const UString& rStr1, const UString& rStr2) { return rStr1.Compare( rStr2 ) <= 0; }
	 friend bool operator >= (const UString& rStr1, const UString& rStr2) { return rStr1.Compare( rStr2 ) >= 0; }
	
// private:
	// @cond PRIVATE_DOC
	UString(TRN_UString impl);
	TRN_UString mp_impl;  ///< Implementation detail.
	// @endcond
};


/**
 * A C++ utility function that can be used to dump ASCII version of UString to 
 * any output stream. This function is typically used for debugging or in console 
 * applications.
 */
inline std::ostream& operator<<(std::ostream& stream, const UString& str) {
	return stream << str.ConvertToAscii();
}


#include <Impl/UString.inl>


};	// namespace pdftron

#endif // PDFTRON_H_CPPCommonUString
