//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonBasicTypes
#define PDFTRON_H_CCommonBasicTypes

#include <stddef.h>

struct TRN_rect;
typedef struct TRN_rect TRN_Rect;

typedef unsigned char TRN_Bool;
typedef unsigned char TRN_UChar;

typedef unsigned int    TRN_UInt32;
typedef unsigned short  TRN_UInt16;
typedef unsigned char   TRN_UInt8;
typedef signed int      TRN_Int32;
typedef signed short    TRN_Int16;
typedef signed char     TRN_Int8;

#ifdef _WIN32
	typedef __int64 TRN_Int64;
	typedef unsigned __int64 TRN_UInt64;
#else /* use standard C++ types */
	typedef long long TRN_Int64;
	typedef unsigned long long TRN_UInt64;
#endif

typedef size_t TRN_Size;
typedef ptrdiff_t TRN_Ptrdiff;
typedef TRN_UInt16 TRN_Unicode;

struct TRN_obj_;
typedef struct TRN_obj_* TRN_Obj;

struct TRN_matrix2d 
{
	double m_a;
	double m_b;
	double m_c;
	double m_d;
	double m_h;
	double m_v;
};

typedef struct TRN_matrix2d TRN_Matrix2D;

struct TRN_byterange
{
	TRN_UInt64 m_offset;
	TRN_UInt64 m_size;
};
typedef struct TRN_byterange TRN_ByteRange;

struct TRN_rect {
	double x1; 
	double y1; 
	double x2; 
	double y2; 
	TRN_Obj mp_rect;
};


struct TRN_date {
	TRN_UInt16 year; 
	char month; 
	char day; 
	char hour; 
	char minute; 
	char second; 
	char UT; 
	char UT_hour; 
	char UT_minutes;	
	TRN_Obj mp_obj;
};
typedef struct TRN_date TRN_Date;

struct TRN_chardata
{
	unsigned int char_code;
	double x;	
	double y;	
 	unsigned char* char_data;	
	int bytes;
};
typedef struct TRN_chardata TRN_CharData;

struct TRN_point{
	double x;
	double y;
};

typedef struct TRN_point TRN_Point;

struct TRN_quadpoint{
	double p1x;
	double p1y;
	double p2x;
	double p2y;
	double p3x;
	double p3y;
	double p4x;
	double p4y;
};

typedef struct TRN_quadpoint TRN_QuadPoint; 

#endif // PDFTRON_H_CCommonBasicTypes
