//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFAPDFACompliance
#define PDFTRON_H_CPDFPDFAPDFACompliance

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

enum TRN_PDFAComplianceConformance {
	e_PDFACompliance_Level1A = 1,
	e_PDFACompliance_Level1B,
	e_PDFACompliance_Level2A,
	e_PDFACompliance_Level2B,
	e_PDFACompliance_Level2U,
	e_PDFACompliance_Level3A,
	e_PDFACompliance_Level3B,
	e_PDFACompliance_Level3U,
};

enum TRN_PDFAComplianceErrorCode
{
	// PDF/A-1 Level B Validation Errors --------------------------------
	e_PDFACompliance_PDFA0_1_0 = 10,   ///< Invalid PDF structure.
	e_PDFACompliance_PDFA0_1_1 = 11,   ///< Corrupt document.
	e_PDFACompliance_PDFA0_1_2 = 12,   ///< Corrupt content stream.
	e_PDFACompliance_PDFA0_1_3 = 13,   ///< Using JPEG2000 compression (PDF 1.4 compatibility).
	e_PDFACompliance_PDFA0_1_4 = 14,   ///< Contains compressed object streams (PDF 1.4 compatibility).
	e_PDFACompliance_PDFA0_1_5 = 15,   ///< Contains cross-reference streams (PDF 1.4 compatibility).
	e_PDFACompliance_PDFA1_2_1 = 121,  ///< Document does not start with % character.
	e_PDFACompliance_PDFA1_2_2  =122,  ///< File header line not followed by % and 4 characters > 127.
	e_PDFACompliance_PDFA1_3_1  =131,  ///< The trailer dictionary does not contain ID.
	e_PDFACompliance_PDFA1_3_2  =132,  ///< Trailer dictionary contains Encrypt.
	e_PDFACompliance_PDFA1_3_3  =133,  ///< Data after last EOF marker.
	e_PDFACompliance_PDFA1_3_4  =134,  ///< Linearized file: ID in 1st page and last trailer are different.
	e_PDFACompliance_PDFA1_4_1  =141,  ///< Subsection header: starting object number and range not separated by a single space.
	e_PDFACompliance_PDFA1_4_2  =142,  ///< 'xref' and cross reference subsection header not separated by a single EOL marker.
	e_PDFACompliance_PDFA1_6_1  =161,  ///< Invalid hexadecimal strings used.
	e_PDFACompliance_PDFA1_7_1  =171,  ///< The 'stream' token is not followed by CR and LF or a single LF.
	e_PDFACompliance_PDFA1_7_2  =172,  ///< The 'endstream' token is not preceded by EOL.
	e_PDFACompliance_PDFA1_7_3  =173,  ///< The value of Length does not match the number of bytes.
	e_PDFACompliance_PDFA1_7_4  =174,  ///< A stream object dictionary contains the F, FFilter, or FDecodeParms keys.
	e_PDFACompliance_PDFA1_8_1  =181,  ///< Object number and generation number are not separated by a single white-space.
	e_PDFACompliance_PDFA1_8_2  =182,  ///< Generation number and 'obj' are not separated by a single white-space.
	e_PDFACompliance_PDFA1_8_3  =183,  ///< Object number not preceded by EOL marker
	e_PDFACompliance_PDFA1_8_4  =184,  ///< 'endobj' not preceded by EOL marker
	e_PDFACompliance_PDFA1_8_5  =185,  ///< 'obj' not followed by EOL marker
	e_PDFACompliance_PDFA1_8_6  =186,  ///< 'endobj' not followed by EOL marker
	e_PDFACompliance_PDFA1_10_1 =1101, ///< Using LZW compression.
	e_PDFACompliance_PDFA1_11_1 =1111, ///< A file specification dictionary contains a non-compliant embedded file (EF key).
	e_PDFACompliance_PDFA1_11_2 =1112, ///< Contains the EmbeddedFiles key
	e_PDFACompliance_PDFA1_12_1 =1121, ///< Array contains more than 8191 elements
	e_PDFACompliance_PDFA1_12_2 =1122, ///< Dictionary contains more than 4095 elements
	e_PDFACompliance_PDFA1_12_3 =1123, ///< Name with more than 127 bytes
	e_PDFACompliance_PDFA1_12_4 =1124, ///< Contains an integer value outside of the allowed range [-2^31, 2^31-1],
	e_PDFACompliance_PDFA1_12_5 =1125, ///< Exceeds the maximum number (8,388,607) of indirect objects in a PDF file.
	e_PDFACompliance_PDFA1_12_6 =1126, ///< The number of nested q/Q operators is greater than 28.
	e_PDFACompliance_PDFA1_13_1 =1131, ///< Optional content (layers) not allowed.
	e_PDFACompliance_PDFA2_2_1  =221,  ///< DestOutputProfile-s in OutputIntents array do not match.
	e_PDFACompliance_PDFA2_3_2  =232,  ///< Not a valid ICC color profile.
	e_PDFACompliance_PDFA2_3_3  =233,  ///< The N entry does not match the number of color components in the embedded ICC profile.
	e_PDFACompliance_PDFA2_3_3_1=2331, ///< Device-specific color space used, but no GTS_PDFA1 OutputIntent.
	e_PDFACompliance_PDFA2_3_3_2=2332, ///< Device-specific color space, does not match OutputIntent.
	e_PDFACompliance_PDFA2_3_4_1=2341, ///< Device-specific color space used in an alternate color space.
	e_PDFACompliance_PDFA2_4_1  =241,  ///< Image with Alternates key.
	e_PDFACompliance_PDFA2_4_2  =242,  ///< Image with OPI key.
	e_PDFACompliance_PDFA2_4_3  =243,  ///< Image with invalid rendering intent.
	e_PDFACompliance_PDFA2_4_4  =244,  ///< Image with Interpolate key set to true.
	e_PDFACompliance_PDFA2_5_1  =251,  ///< XObject with OPI key.
	e_PDFACompliance_PDFA2_5_2  =252,  ///< PostScript XObject.
	e_PDFACompliance_PDFA2_6_1  =261,  ///< Contains a reference XObject.
	e_PDFACompliance_PDFA2_7_1  =271,  ///< Contains an XObject that is not supported (e.g. PostScript XObject).
	e_PDFACompliance_PDFA2_8_1  =281,  ///< Contains an invalid Transfer Curve in the extended graphics state.
	e_PDFACompliance_PDFA2_9_1  =291,  ///< Use of an invalid rendering intent.
	e_PDFACompliance_PDFA2_10_1 =2101, ///< Illegal operator.
	e_PDFACompliance_PDFA3_2_1  =321,  ///< Embedded font is damaged.
	e_PDFACompliance_PDFA3_3_1  =331,  ///< Incompatible CIDSystemInfo entries
	e_PDFACompliance_PDFA3_3_2  =332,  ///< Type 2 CIDFont without CIDToGIDMap
	e_PDFACompliance_PDFA3_3_3_1=3331, ///< CMap not embedded
	e_PDFACompliance_PDFA3_3_3_2=3332, ///< Inconsistent WMode in embedded CMap dictionary and stream.
	e_PDFACompliance_PDFA3_4_1  =341,  ///< The font is not embedded.
	e_PDFACompliance_PDFA3_5_1  =351,  ///< Embedded composite (Type0) font program does not define all font glyphs.
	e_PDFACompliance_PDFA3_5_2  =352,  ///< Embedded Type1 font program does not define all font glyphs.
	e_PDFACompliance_PDFA3_5_3  =353,  ///< Embedded TrueType font program does not define all font glyphs.
	e_PDFACompliance_PDFA3_5_4  =354,  ///< The font descriptor dictionary does not include a	CIDSet stream for CIDFont subset.
	e_PDFACompliance_PDFA3_5_5  =355,  ///< The font descriptor dictionary does not include a	CharSet string for Type1 font subset.
	e_PDFACompliance_PDFA3_5_6  =356,  ///< CIDSet in subset font is incomplete.
	e_PDFACompliance_PDFA3_6_1  =361,  ///< Widths in embedded font are inconsistent with /Widths entry in the font dictionary.
	e_PDFACompliance_PDFA3_7_1  =371,  ///< A non-symbolic TrueType font must use WinAnsiEncoding or MacRomanEncoding.
	e_PDFACompliance_PDFA3_7_2  =372,  ///< A symbolic TrueType font must not specify encoding.
	e_PDFACompliance_PDFA3_7_3  =373,  ///< A symbolic TrueType font does not have exactly one entry in cmap table.
	e_PDFACompliance_PDFA4_1    =41,   ///< Transparency used (ExtGState with soft mask).
	e_PDFACompliance_PDFA4_2    =42,   ///< Transparency used (XObject with soft mask).
	e_PDFACompliance_PDFA4_3    =43,   ///< Transparency used (Page or Form XObject with transparency group).
	e_PDFACompliance_PDFA4_4    =44,   ///< Transparency used (Blend mode is not 'Normal').
	e_PDFACompliance_PDFA4_5    =45,   ///< Transparency used ('CA' value is not 1.0).
	e_PDFACompliance_PDFA4_6    =46,   ///< Transparency used ('ca' value is not 1.0).
	e_PDFACompliance_PDFA5_2_1  =521,  ///< Unknown annotation type.
	e_PDFACompliance_PDFA5_2_2  =522,  ///< FileAttachment annotation is not permitted.
	e_PDFACompliance_PDFA5_2_3  =523,  ///< Sound annotation is not permitted.
	e_PDFACompliance_PDFA5_2_4  =524,  ///< Movie annotation is not permitted.
	e_PDFACompliance_PDFA5_2_5  =525,  ///< Redact annotation is not permitted.
	e_PDFACompliance_PDFA5_2_6  =526,  ///< 3D annotation is not permitted.
	e_PDFACompliance_PDFA5_2_7  =527,  ///< Caret annotation is not permitted.
	e_PDFACompliance_PDFA5_2_8  =528,  ///< Watermark annotation is not permitted.
	e_PDFACompliance_PDFA5_2_9  =529,  ///< Polygon annotation is not permitted.
	e_PDFACompliance_PDFA5_2_10 =5210, ///< PolyLine annotation is not permitted.
	e_PDFACompliance_PDFA5_2_11 =5211, ///< Screen annotation is not permitted.
	e_PDFACompliance_PDFA5_3_1  =531,  ///< An annotation dictionary contains the CA key with a value other than 1.0.
	e_PDFACompliance_PDFA5_3_2_1=5321, ///< An annotation dictionary is missing F key.
	e_PDFACompliance_PDFA5_3_2_2=5322, ///< An annotation's 'Print' flag is not set.
	e_PDFACompliance_PDFA5_3_2_3=5323, ///< An annotation's 'Hidden' flag is set.
	e_PDFACompliance_PDFA5_3_2_4=5324, ///< An annotation's 'Invisible' flag is set.
	e_PDFACompliance_PDFA5_3_2_5=5325, ///< An annotation's 'NoView' flag is set.
	e_PDFACompliance_PDFA5_3_3_1=5331, ///< An annotation's C entry present but no OutputIntent present
	e_PDFACompliance_PDFA5_3_3_2=5332, ///< An annotation's C entry present but OutputIntent has non-RGB destination profile
	e_PDFACompliance_PDFA5_3_3_3=5333, ///< An annotation's IC entry present but no OutputIntent present
	e_PDFACompliance_PDFA5_3_3_4=5334, ///< An annotation's IC entry present and OutputIntent has non-RGB destination profile
	e_PDFACompliance_PDFA5_3_4_0=5340, ///< Annotation is missing AP entry.
	e_PDFACompliance_PDFA5_3_4_1=5341, ///< An annotation AP dictionary has entries other than the N entry.
	e_PDFACompliance_PDFA5_3_4_2=5342, ///< An annotation AP dictionary does not contain N entry
	e_PDFACompliance_PDFA5_3_4_3=5343, ///< AP has an N entry whose value is invalid.
	e_PDFACompliance_PDFA6_1_1  =611,  ///< Contains an action type that is not permitted.
	e_PDFACompliance_PDFA6_1_2  =612,  ///< Contains a non-predefined Named action.
	e_PDFACompliance_PDFA6_2_1  =621,  ///< The document catalog dictionary contains AA entry.
	e_PDFACompliance_PDFA6_2_2 = 622,  ///< Contains the JavaScript key.
	e_PDFACompliance_PDFA6_2_3 = 623,  ///< Invalid destination.
	e_PDFACompliance_PDFA7_2_1  =721,  ///< The document catalog does not contain Metadata stream.
	e_PDFACompliance_PDFA7_2_2  =722,  ///< The Metadata object stream contains Filter key.
	e_PDFACompliance_PDFA7_2_3  =723,  ///< The XMP Metadata stream is not valid.
	e_PDFACompliance_PDFA7_2_4  =724,  ///< XMP property not predefined and no extension schema present.
	e_PDFACompliance_PDFA7_2_5  =725,  ///< XMP not included in 'xpacket'.
	e_PDFACompliance_PDFA7_3_1  =731,  ///< Document information entry 'Title' not synchronized with XMP.
	e_PDFACompliance_PDFA7_3_2  =732,  ///< Document information entry 'Author' not synchronized with XMP.
	e_PDFACompliance_PDFA7_3_3  =733,  ///< Document information entry 'Subject' not synchronized with XMP.
	e_PDFACompliance_PDFA7_3_4  =734,  ///< Document information entry 'Keywords' not synchronized with XMP.
	e_PDFACompliance_PDFA7_3_5  =735,  ///< Document information entry 'Creator' not synchronized with XMP.
	e_PDFACompliance_PDFA7_3_6  =736,  ///< Document information entry 'Producer' not synchronized with XMP.
	e_PDFACompliance_PDFA7_3_7  =737,  ///< Document information entry 'CreationDate' not synchronized with XMP.
	e_PDFACompliance_PDFA7_3_8  =738,  ///< Document information entry 'ModDate' not synchronized with XMP.
	e_PDFACompliance_PDFA7_3_9  =739,  ///< Wrong value type for predefined XMP property.
	e_PDFACompliance_PDFA7_5_1  =751,  ///< 'bytes' and 'encoding' attributes are allowed in the header of an XMP packet.
	e_PDFACompliance_PDFA7_8_1  =781,  ///< XMP Extension schema doesn't have a description.
	e_PDFACompliance_PDFA7_8_2  =782,  ///< XMP Extension schema is not valid. Required property 'namespaceURI' might be missing in PDF/A Schema value Type.
	e_PDFACompliance_PDFA7_8_3  =783,  ///< 'pdfaExtension:schemas' not found. 
	e_PDFACompliance_PDFA7_8_4  =784,  ///< 'pdfaExtension:schemas' is using a wrong value type.
	e_PDFACompliance_PDFA7_8_5  =785,  ///< 'pdfaExtension:property' not found. 
	e_PDFACompliance_PDFA7_8_6  =786,  ///< 'pdfaExtension:property' is using a wrong value type.
	e_PDFACompliance_PDFA7_8_7  =787,  ///< 'pdfaProperty:name' not found. 
	e_PDFACompliance_PDFA7_8_8  =788,  ///< 'pdfaProperty:name' is using a wrong value type.
	e_PDFACompliance_PDFA7_8_9  =789,  ///< A description for a property is missing in 'pdfaSchema:property' sequence.
	e_PDFACompliance_PDFA7_8_10 =7810, ///< 'pdfaProperty:valueType' not found.
	e_PDFACompliance_PDFA7_8_11 =7811, ///< The required namespace prefix for extension schema is 'pdfaExtension'.
	e_PDFACompliance_PDFA7_8_12 =7812, ///< The required field namespace prefix is 'pdfaSchema'.
	e_PDFACompliance_PDFA7_8_13 =7813, ///< The required field namespace prefix is 'pdfaProperty'.
	e_PDFACompliance_PDFA7_8_14 =7814, ///< The required field namespace prefix is 'pdfaType'.
	e_PDFACompliance_PDFA7_8_15 =7815, ///< The required field namespace prefix is 'pdfaField'.
	e_PDFACompliance_PDFA7_8_16 =7816, ///< 'pdfaSchema:valueType' not found.
	e_PDFACompliance_PDFA7_8_17 =7817, ///< 'pdfaSchema:valueType' is using a wrong value type.
	e_PDFACompliance_PDFA7_8_18= 7818, ///< Required property 'valueType' missing in PDF/A Schema Value Type.
	e_PDFACompliance_PDFA7_8_19= 7819, ///< 'pdfaType:type' not found.
	e_PDFACompliance_PDFA7_8_20 =7820, ///< 'pdfaType:type' is using a wrong value type.
	e_PDFACompliance_PDFA7_8_21 =7821, ///< 'pdfaType:description' not found.
	e_PDFACompliance_PDFA7_8_22 =7822, ///< 'pdfaType:namespaceURI' not found.
	e_PDFACompliance_PDFA7_8_23 =7823, ///< 'pdfaType:field' is using a wrong value type.
	e_PDFACompliance_PDFA7_8_24 =7824, ///< 'pdfaField:name' not found.
	e_PDFACompliance_PDFA7_8_25 =7825, ///< 'pdfaField:name' is using a wrong value type.
	e_PDFACompliance_PDFA7_8_26 =7826, ///< 'pdfaField:valueType' not found.
	e_PDFACompliance_PDFA7_8_27 =7827, ///< 'pdfaField:valueType' is using a wrong type.
	e_PDFACompliance_PDFA7_8_28 =7828, ///< 'pdfaField:description' not found.
	e_PDFACompliance_PDFA7_8_29 =7829, ///< 'pdfaField:description' is using a wrong type.
	e_PDFACompliance_PDFA7_8_30 =7830, ///< Required description for 'pdfaField::valueType' is missing.
	e_PDFACompliance_PDFA7_8_31 =7831, ///< A property doesn't match its custom schema type.
	e_PDFACompliance_PDFA7_11_1 =7111, ///< Missing PDF/A identifier
	e_PDFACompliance_PDFA7_11_2 =7112, ///< Invalid PDF/A identifier namespace
	e_PDFACompliance_PDFA7_11_3 =7113, ///< Invalid PDF/A conformance level.
	e_PDFACompliance_PDFA7_11_4 =7114, ///< Invalid PDF/A part number.
	e_PDFACompliance_PDFA7_11_5 =7115, ///< Invalid PDF/A amendment identifier.
	e_PDFACompliance_PDFA9_1    =91,   ///< An interactive form field contains an action.
	e_PDFACompliance_PDFA9_2    =92,   ///< The NeedAppearances flag in the interactive form dictionary is set to true.
	e_PDFACompliance_PDFA9_3    =93,   ///< AcroForms contains XFA.
	e_PDFACompliance_PDFA9_4    =94,   ///< Catalog contains NeedsRendering.

	// PDF/A-1 Level A Validation Errors --------------------------------
	e_PDFACompliance_PDFA3_8_1  =381,  ///< The font dictionary is missing 'ToUnicode' entry.
	e_PDFACompliance_PDFA8_2_2  =822,  ///< The PDF is not marked as Tagged PDF.
	e_PDFACompliance_PDFA8_3_3_1=8331, ///< Bad StructTreeRoot 
	e_PDFACompliance_PDFA8_3_3_2=8332, ///< Each structure element dictionary in the structure hierarchy must have a Type entry with the name value of StructElem.
	e_PDFACompliance_PDFA8_3_4_1=8341, ///< A non-standard structure type does not map to a standard type.


	// PDF/A-2 Level B Validation Errors --------------------------------
	e_PDFACompliance_PDFA1_2_3   =123,     ///< Bad file header.
	e_PDFACompliance_PDFA1_10_2  =1102,    ///< Invalid use of Crypt filter.
	e_PDFACompliance_PDFA1_10_3  =1103,    ///< Bad stream Filter.
	e_PDFACompliance_PDFA1_12_10 =11210,   ///< Bad Permission Dictionary
	e_PDFACompliance_PDFA1_13_5  =1135,    ///< Page dimensions are outside of the allowed range (3-14400).
	e_PDFACompliance_PDFA2_3_10  =2310,    ///< Contains DestOutputProfileRef
	e_PDFACompliance_PDFA2_4_2_10 =24220,  ///< OPM is 1
	e_PDFACompliance_PDFA2_4_2_11 =24221,  ///< Incorrect colorant specification in DeviceN 
	e_PDFACompliance_PDFA2_4_2_12 =24222,  ///< tintTransform is different in Separations with the same colorant name.
	e_PDFACompliance_PDFA2_4_2_13 =24223,  ///< alternateSpace is different in Separations with the same colorant name.
	e_PDFACompliance_PDFA2_5_10   =2510,   ///< HTP entry in ExtGState.
	e_PDFACompliance_PDFA2_5_11   =2511,   ///< Unsupported HalftoneType.
	e_PDFACompliance_PDFA2_5_12   =2512,   ///< Uses HalftoneName key.
	e_PDFACompliance_PDFA2_8_3_1  =2831,   ///< JPEG2000: Only the JPX baseline is supported.
	e_PDFACompliance_PDFA2_8_3_2  =2832,   ///< JPEG2000: Invalid number of colour channels.
	e_PDFACompliance_PDFA2_8_3_3  =2833,   ///< JPEG2000: Invalid color space.
	e_PDFACompliance_PDFA2_8_3_4  =2834,   ///< JPEG2000: The bit-depth JPEG2000 data must be in range 1-38. 
	e_PDFACompliance_PDFA2_8_3_5  =2835,   ///< JPEG2000: All colour channels in the JPEG2000 data must have the same bit-depth.
	e_PDFACompliance_PDFA2_10_20  =21020,  ///< Page Group entry is missing in a document without OutputIntent.
	e_PDFACompliance_PDFA2_10_21  =21021,  ///< Invalid blend mode.
	e_PDFACompliance_PDFA11_0_0   =11000,  ///< Catalog contains Requirements key.
	e_PDFACompliance_PDFA6_2_11_8 =62118,  ///< Use of .notdef glyph
	e_PDFACompliance_PDFA8_1      =81,     ///< FileSpec is missing F or UF key

	// PDF/A-3 Validation Errors --------------------------------------
	e_PDFACompliance_PDFA_3E1     =1,      ///< Embedded file has no MIME type entry
	e_PDFACompliance_PDFA_3E2     =2,      ///< Embedded file has no AFRelationship
	e_PDFACompliance_PDFA_3E3     =3,      ///< Doc catalog is missing AF entry

	e_PDFACompliance_PDFA_LAST
};

TRN_API TRN_PDFAComplianceCreateFromFile(TRN_Bool convert, const TRN_UString file_path, const char* password, enum TRN_PDFAComplianceConformance conf, enum TRN_PDFAComplianceErrorCode* exceptions, int exlength, int max_ref_objs, TRN_Bool first_stop, TRN_PDFACompliance* result);
TRN_API TRN_PDFAComplianceCreateFromBuffer(TRN_Bool convert, const char* buf, int buf_size, const char* password, enum TRN_PDFAComplianceConformance conf, enum TRN_PDFAComplianceErrorCode* exceptions, int exlength, int max_ref_objs, TRN_Bool first_stop, TRN_PDFACompliance* result);
TRN_API TRN_PDFAComplianceDestroy(TRN_PDFACompliance pdfac);
TRN_API TRN_PDFAComplianceGetErrorCount(TRN_PDFACompliance pdfac, int* result);
TRN_API TRN_PDFAComplianceGetError(TRN_PDFACompliance pdfac, int idx, enum TRN_PDFAComplianceErrorCode* result);
TRN_API TRN_PDFAComplianceGetRefObjCount(TRN_PDFACompliance pdfac, enum TRN_PDFAComplianceErrorCode id, int* result);
TRN_API TRN_PDFAComplianceGetRefObj(TRN_PDFACompliance pdfac, enum TRN_PDFAComplianceErrorCode id, int err_idx, int* result);
TRN_API TRN_PDFAComplianceGetPDFAErrorMessage(enum TRN_PDFAComplianceErrorCode id, const char** result);
TRN_API TRN_PDFAComplianceGetDeclaredConformance(TRN_PDFDoc doc, TRN_PDFAComplianceConformance* result);
TRN_API TRN_PDFAComplianceSaveAsFromFileName(TRN_PDFACompliance pdfac, TRN_UString file_path, TRN_Bool linearized);
TRN_API TRN_PDFAComplianceSaveAsFromBuffer(TRN_PDFACompliance pdfac, const char** out_buf, TRN_Size* out_buf_size, TRN_Bool linearized);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFPDFAPDFACompliance
