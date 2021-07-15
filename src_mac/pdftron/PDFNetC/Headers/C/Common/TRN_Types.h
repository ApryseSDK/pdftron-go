//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CCommonTypes
#define PDFTRON_H_CCommonTypes

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_BasicTypes.h>

#ifdef SWIG 
	#define TRN_API_CALL 
	#define TRN_API_T(type) type 
	#define TRN_API TRN_Exception
#else
#ifdef __PNACL__
	#define TRN_API_CALL
	#ifdef TRN_API_EXPORT
	#define TRN_API_T(type) type TRN_API_CALL
	#define TRN_API TRN_API_T(TRN_Exception)
	#else
	#define TRN_API_T(type) type TRN_API_CALL
	#define TRN_API TRN_API_T(TRN_Exception)
	#endif
#elif EMSCRIPTEN
	#define TRN_API_CALL
	#ifdef TRN_API_EXPORT
#ifdef PDFNET_LEAN
	#define TRN_API_T(type) type TRN_API_CALL
#else
	typedef short __attribute__((aligned(1))) emscripten_align1_short;

	typedef long long __attribute__((aligned(4))) emscripten_align4_int64;
	typedef long long __attribute__((aligned(2))) emscripten_align2_int64;
	typedef long long __attribute__((aligned(1))) emscripten_align1_int64;

	typedef int __attribute__((aligned(2))) emscripten_align2_int;
	typedef int __attribute__((aligned(1))) emscripten_align1_int;

	typedef float __attribute__((aligned(2))) emscripten_align2_float;
	typedef float __attribute__((aligned(1))) emscripten_align1_float;

	typedef double __attribute__((aligned(4))) emscripten_align4_double;
	typedef double __attribute__((aligned(2))) emscripten_align2_double;
	typedef double __attribute__((aligned(1))) emscripten_align1_double;

	#define EMSCRIPTEN_KEEPALIVE __attribute__((used))

	#define TRN_API_T(type) EMSCRIPTEN_KEEPALIVE type TRN_API_CALL
#endif
	#define TRN_API TRN_API_T(TRN_Exception)
	#else
	#define TRN_API_T(type) type TRN_API_CALL
	#define TRN_API TRN_API_T(TRN_Exception)
	#endif

#elif _WIN32
	#define TRN_API_CALL __cdecl
	#ifdef TRN_API_EXPORT
		#define TRN_API_T(type) __declspec(dllexport) type TRN_API_CALL
		#define TRN_API TRN_API_T(TRN_Exception)
	#else
		#define TRN_API_T(type) __declspec(dllimport) type TRN_API_CALL
		#define TRN_API TRN_API_T(TRN_Exception)
	#endif
#else
	#ifdef TRN_API_EXPORT
		#define TRN_API_CALL
		#define TRN_API_T(type) __attribute__((visibility("default"))) type TRN_API_CALL
		#define TRN_API TRN_API_T(TRN_Exception)
	#else
		#define TRN_API_CALL
		#define TRN_API_T(type) type
		#define TRN_API TRN_API_T(TRN_Exception)
	#endif
#endif
#endif

#define BToTB(in) ((TRN_Bool)(in))
#define BToTBP(ptr) ((TRN_Bool*)(ptr))
#define TBToB(in) ((in)!=0)
#define TBToBP(ptr) ((bool*)(ptr))


#ifndef __cplusplus
/* #define const */
/* typedef unsigned char bool; */
#endif

#include <stdlib.h>
#include <stddef.h>

/* set alignment to 8 byte boundary  */
#pragma pack(8)  

struct TRN_exception_;
typedef struct TRN_exception_* TRN_Exception;

struct TRN_font_;
typedef struct TRN_font_* TRN_Font;

struct TRN_sdfdoc;
typedef struct TRN_sdfdoc* TRN_SDFDoc;

struct TRN_securityhandler;
typedef struct TRN_securityhandler* TRN_SecurityHandler;

typedef TRN_SecurityHandler (*TRN_PDFNetCreateSecurityHandler) (const char* name, int key_len, int enc_code, void* custom_data);
struct TRN_sechdlrinfo
{
	const char* m_name;
	const char* m_gui_name;
	TRN_PDFNetCreateSecurityHandler m_factory_method;
};
typedef struct TRN_sechdlrinfo TRN_SecHdlrInfo;

struct TRN_iterator;
typedef struct TRN_iterator* TRN_Iterator;

struct TRN_itrdata;
typedef struct TRN_itrdata* TRN_ItrData;

struct TRN_dictiterator;
typedef struct TRN_dictiterator* TRN_DictIterator;

struct TRN_numbertree;
typedef struct TRN_numbertree* TRN_NumberTree;

struct TRN_nametree;
typedef struct TRN_nametree* TRN_NameTree;

struct TRN_progressmonitor;
typedef struct TRN_progressmonitor* TRN_ProgressMonitor;

struct TRN_objpair
{
	TRN_Obj key;
	TRN_Obj value;
};
typedef struct TRN_objpair TRN_ObjPair;


struct TRN_fontcharcodeiterator;
typedef struct TRN_fontcharcodeiterator* TRN_FontCharCodeIterator;

struct TRN_UVector;
struct TRN_list;
typedef struct TRN_list* TRN_List;

#include <C/Common/TRN_BasicTypes.h>

struct TRN_ustring;
typedef struct TRN_ustring* TRN_UString;

struct TRN_filter;
typedef struct TRN_filter* TRN_Filter;

struct TRN_filterreader;
typedef struct TRN_filterreader* TRN_FilterReader;

struct TRN_filterwriter;
typedef struct TRN_filterwriter* TRN_FilterWriter;

struct TRN_string {
	const char* str;
	unsigned int len;
};

typedef struct TRN_string TRN_String;

struct TRN_colorpt {
	double* c; 
	double _c[4];
};

typedef struct TRN_colorpt TRN_ColorPt;

struct TRN_conversionmonitor;
typedef struct TRN_conversionmonitor* TRN_ConversionMonitor;

struct TRN_annot;
typedef struct TRN_annot* TRN_Annot;

typedef TRN_Annot TRN_MarkupAnnot;
typedef TRN_MarkupAnnot TRN_TextMarkupAnnot;
typedef TRN_MarkupAnnot TRN_CaretAnnot;
typedef TRN_MarkupAnnot TRN_LineAnnot;
typedef TRN_MarkupAnnot TRN_CircleAnnot;
typedef TRN_MarkupAnnot TRN_FileAttachmentAnnot;
typedef TRN_MarkupAnnot TRN_FreeTextAnnot;
typedef TRN_TextMarkupAnnot TRN_HighlightAnnot;
typedef TRN_MarkupAnnot TRN_InkAnnot;
typedef TRN_Annot TRN_LinkAnnot;
typedef TRN_Annot TRN_MovieAnnot;
typedef TRN_LineAnnot TRN_PolyLineAnnot;
typedef TRN_PolyLineAnnot TRN_PolygonAnnot;
typedef TRN_Annot TRN_PopupAnnot;
typedef TRN_MarkupAnnot TRN_RedactionAnnot;
typedef TRN_MarkupAnnot TRN_RubberStampAnnot;
typedef TRN_Annot TRN_ScreenAnnot;
typedef TRN_MarkupAnnot TRN_SoundAnnot;
typedef TRN_MarkupAnnot TRN_SquareAnnot;
typedef TRN_TextMarkupAnnot TRN_SquigglyAnnot;
typedef TRN_TextMarkupAnnot TRN_StrikeOutAnnot;
typedef TRN_MarkupAnnot TRN_TextAnnot;
typedef TRN_TextMarkupAnnot TRN_UnderlineAnnot;
typedef TRN_Annot TRN_WatermarkAnnot;
typedef TRN_Annot TRN_WidgetAnnot;
typedef TRN_WidgetAnnot TRN_SignatureWidget;
typedef TRN_WidgetAnnot TRN_ComboBoxWidget;
typedef TRN_WidgetAnnot TRN_ListBoxWidget;
typedef TRN_WidgetAnnot TRN_TextWidget;
typedef TRN_WidgetAnnot TRN_CheckBoxWidget;
typedef TRN_WidgetAnnot TRN_RadioButtonWidget;
typedef TRN_WidgetAnnot TRN_PushButtonWidget;

struct TRN_radiobuttongroup;
typedef struct TRN_radiobuttongroup* TRN_RadioButtonGroup;

struct TRN_action;
typedef struct TRN_action* TRN_Action;

struct TRN_annotborderstyle;
typedef struct TRN_annotborderstyle* TRN_AnnotBorderStyle;

struct TRN_filespec;
typedef struct TRN_filespec* TRN_FileSpec;

struct TRN_destination;
typedef struct TRN_destination* TRN_Destination;

struct TRN_bookmark;
typedef struct TRN_bookmark* TRN_Bookmark;

struct TRN_page;
typedef struct TRN_page* TRN_Page;

struct TRN_pdfdc;
typedef struct TRN_pdfdc * TRN_PDFDC;

struct TRN_pdfdcex;
typedef struct TRN_pdfdcex * TRN_PDFDCEX;

struct TRN_pdfdoc;
typedef struct TRN_pdfdoc* TRN_PDFDoc;

struct TRN_pdfdocinfo;
typedef struct TRN_pdfdocinfo* TRN_PDFDocInfo;

struct TRN_pdfdocviewprefs;
typedef struct TRN_pdfdocviewprefs* TRN_PDFDocViewPrefs;

struct TRN_pagelabel
{
	TRN_Obj mp_obj;
	int m_first_page;
	int m_last_page;
};
typedef struct TRN_pagelabel TRN_PageLabel;

struct TRN_elementbuilder;
typedef struct TRN_elementbuilder* TRN_ElementBuilder;

struct TRN_image;
typedef struct TRN_image* TRN_Image;

struct TRN_element;
typedef struct TRN_element* TRN_Element;


struct TRN_shading;
typedef struct TRN_shading* TRN_Shading;


struct TRN_field
{
	TRN_Obj leaf_node;
	TRN_ElementBuilder builder;
};
typedef struct TRN_field TRN_Field;

struct TRN_digitalsignaturefield
{
	TRN_Obj mp_field_dict_obj;
};
typedef struct TRN_digitalsignaturefield TRN_DigitalSignatureField;

struct TRN_stree;
typedef struct TRN_stree* TRN_STree;

struct TRN_contentitem
{
	TRN_Obj o;
	TRN_Obj p;
};
typedef struct TRN_contentitem TRN_ContentItem;

struct TRN_selement
{
	TRN_Obj obj;
	TRN_Obj k;
};
typedef struct TRN_selement TRN_SElement;

struct TRN_classmap;
typedef struct TRN_classmap* TRN_ClassMap;

struct TRN_rolemap;
typedef struct TRN_rolemap* TRN_RoleMap;

struct TRN_attrobj;
typedef struct TRN_attrobj* TRN_AttrObj;

struct TRN_ocgconfig;
typedef struct TRN_ocgconfig* TRN_OCGConfig;

struct TRN_ocgcontext;
typedef struct TRN_ocgcontext* TRN_OCGContext;

struct TRN_ocg;
typedef struct TRN_ocg* TRN_OCG;

struct TRN_ocmd;
typedef struct TRN_ocmd* TRN_OCMD;

struct TRN_colorspace;
typedef struct TRN_colorspace* TRN_ColorSpace;

struct TRN_function;
typedef struct TRN_function* TRN_Function;

struct TRN_gstate;
typedef struct TRN_gstate* TRN_GState;

struct TRN_elementreader;
typedef struct TRN_elementreader* TRN_ElementReader;

struct TRN_elementwriter;
typedef struct TRN_elementwriter* TRN_ElementWriter;


struct TRN_fdfdoc;
typedef struct TRN_fdfdoc* TRN_FDFDoc;

struct TRN_fdffield
{
	TRN_Obj	mp_leaf_node;
	TRN_Obj mp_root_array;
};
typedef struct TRN_fdffield TRN_FDFField;


#ifdef _WIN32
struct TRN_gdiplusbitmap;
typedef struct TRN_gdiplusbitmap* TRN_GDIPlusBitmap;
#endif

struct TRN_patterncolor;
typedef struct TRN_patterncolor* TRN_PatternColor;

struct TRN_pdfdraw;
typedef struct TRN_pdfdraw* TRN_PDFDraw;

struct TRN_pdfrasterizer;
typedef struct TRN_pdfrasterizer* TRN_PDFRasterizer;

struct TRN_chunkrenderer;
typedef struct TRN_chunkrenderer* TRN_ChunkRenderer;

struct TRN_systemdrawingbitmap;
typedef struct TRN_systemdrawingbitmap* TRN_SystemDrawingBitmap;

struct TRN_pdfview;
typedef struct TRN_pdfview* TRN_PDFView;

struct TRN_pdfviewselection;
typedef struct TRN_pdfviewselection* TRN_PDFViewSelection;

struct TRN_pdfviewctrl;
typedef struct TRN_pdfviewctrl* TRN_PDFViewCtrl;

struct TRN_textextractor;
typedef struct TRN_textextractor* TRN_TextExtractor;

struct TRN_highlights;
typedef struct TRN_highlights* TRN_Highlights;

struct TRN_textsearch;
typedef struct TRN_textsearch* TRN_TextSearch;

struct TRN_viewchangecollection;
typedef struct TRN_viewchangecollection* TRN_ViewChangeCollection;

struct TRN_keystrokeactionresult;
typedef struct TRN_keystrokeactionresult* TRN_KeyStrokeActionResult;

struct TRN_keystrokeeventdata;
typedef struct TRN_keystrokeeventdata* TRN_KeyStrokeEventData;

struct TRN_actionparameter;
typedef struct TRN_actionparameter* TRN_ActionParameter;

struct TRN_textextractorstyle {
	void* mp_imp;
};
typedef struct TRN_textextractorstyle TRN_TextExtractorStyle;

struct TRN_textextractorword {
	const double *line, *word, *end; 
	const TRN_Unicode *uni; 
	int num, cur_num; 
	void* mp_bld;
};
typedef struct TRN_textextractorword TRN_TextExtractorWord;

struct TRN_textextractorline {
	const double *line; 
	const TRN_Unicode *uni; 
	int num, cur_num; 
	double m_direction;
	void* mp_bld;
};

typedef struct TRN_textextractorline TRN_TextExtractorLine;

struct TRN_securityhandler;

struct TRN_objset;
typedef struct TRN_objset* TRN_ObjSet;
typedef const char* TRN_JSONOptions;


enum trn_option_type
{
	e_option_type_json,
	e_option_type_sdf
};

struct TRN_optionbase
{
	void* impl;
	enum trn_option_type type;
};
typedef struct TRN_optionbase TRN_OptionBase;

struct TRN_separation
{
	TRN_UChar* data;
	TRN_UInt32 data_size;
	TRN_UString separation_name;
	TRN_UInt8 c;
	TRN_UInt8 m;
	TRN_UInt8 y;
	TRN_UInt8 k;
};
typedef struct TRN_separation TRN_Separation;

enum vector_type
{
	e_vector_separation,
	e_vector_byte
};

struct TRN_vector;
typedef struct TRN_vector* TRN_Vector;


/*
#ifdef _WIN32
#define TRN_SIGAPI __stdcall
#elif __iOS__
#define TRN_SIGAPI
#else // _WIN32
#define TRN_SIGAPI __attribute__((stdcall))
#endif // _WIN32
*/
#define TRN_SIGAPI

typedef size_t TRN_SignatureHandlerId;

typedef struct TRN_signaturedata
{
    TRN_UInt8* data;
    TRN_Size length;
}
TRN_SignatureData;
/*
typedef struct TRN_validatesignatureresult
{
    TRN_Bool valid;
    TRN_Bool wrong_handler;
    TRN_Int32 error_code;
    TRN_UString message;
}
TRN_ValidateSignatureResult;
*/

struct TRN_appearancereferencelist;
typedef struct TRN_appearancereferencelist* TRN_AppearanceReferenceList;

struct TRN_ownedbitmap;
typedef struct TRN_ownedbitmap* TRN_OwnedBitmap;

struct TRN_signaturehandler;
typedef struct TRN_signaturehandler* TRN_SignatureHandler;

struct TRN_pdfacompliance;
typedef struct TRN_pdfacompliance* TRN_PDFACompliance;

struct TRN_contentreplacer;
typedef struct TRN_contentreplacer* TRN_ContentReplacer;

struct TRN_stamper;
typedef struct TRN_stamper* TRN_Stamper;

struct TRN__pageset;
typedef struct TRN_pageset* TRN_PageSet;

struct TRN_flattener;
typedef struct TRN_flattener* TRN_Flattener;

struct TRN_UndoManager_tag;
typedef struct TRN_UndoManager_tag* TRN_UndoManager;

struct TRN_ResultSnapshot_tag;
typedef struct TRN_ResultSnapshot_tag* TRN_ResultSnapshot;

struct TRN_DocSnapshot_tag;
typedef struct TRN_DocSnapshot_tag* TRN_DocSnapshot;

struct TRN_TrustVerificationResult_tag
{
	void* mp_impl;
};
typedef struct TRN_TrustVerificationResult_tag* TRN_TrustVerificationResult;

struct TRN_VerificationResult_tag;
typedef struct TRN_VerificationResult_tag* TRN_VerificationResult;

struct TRN_TimestampingTestResult_tag;
typedef struct TRN_TimestampingTestResult_tag* TRN_TimestampingTestResult;

struct TRN_TimestampingConfiguration_tag;
typedef struct TRN_TimestampingConfiguration_tag* TRN_TimestampingConfiguration;

struct TRN_EmbeddedTimestampVerificationResult_tag;
typedef struct TRN_EmbeddedTimestampVerificationResult_tag* TRN_EmbeddedTimestampVerificationResult;

struct TRN_appearancedocument
{
	TRN_PDFDoc doc;
	TRN_UString id;
};
typedef struct TRN_appearancedocument TRN_AppearanceDocument;

struct TRN_VerificationOptions_tag;
typedef struct TRN_VerificationOptions_tag* TRN_VerificationOptions;

    enum TRN_PrinterModePaperSize {
		e_PrinterMode_custom = 0,
		e_PrinterMode_letter,
		e_PrinterMode_letter_small,
		e_PrinterMode_tabloid,
		e_PrinterMode_ledger,
        e_PrinterMode_legal,
        e_PrinterMode_statement,
        e_PrinterMode_executive,
        e_PrinterMode_a3,
        e_PrinterMode_a4,
        e_PrinterMode_a4_mall,
        e_PrinterMode_a5,
        e_PrinterMode_b4_jis,
        e_PrinterMode_b5_jis,
        e_PrinterMode_folio,
        e_PrinterMode_quarto,
        e_PrinterMode_10x14,
        e_PrinterMode_11x17,
        e_PrinterMode_note,
        e_PrinterMode_envelope_9,
        e_PrinterMode_envelope_10,
        e_PrinterMode_envelope_11,
        e_PrinterMode_envelope_12,
        e_PrinterMode_envelope_14,
        e_PrinterMode_c_size_sheet,
        e_PrinterMode_d_size_sheet,
        e_PrinterMode_e_size_sheet,		
		e_PrinterMode_envelope_dl,
		e_PrinterMode_envelope_c5,
        e_PrinterMode_envelope_c3,
        e_PrinterMode_envelope_c4,
        e_PrinterMode_envelope_c6,
        e_PrinterMode_envelope_c65,
        e_PrinterMode_envelope_b4,
        e_PrinterMode_envelope_b5,
        e_PrinterMode_envelope_b6,
        e_PrinterMode_envelope_italy,
        e_PrinterMode_envelope_monarch,
        e_PrinterMode_6_3_quarters_envelope,
        e_PrinterMode_us_std_fanfold,
        e_PrinterMode_german_std_fanfold,
        e_PrinterMode_german_legal_fanfold,
        e_PrinterMode_b4_iso,
        e_PrinterMode_japanese_postcard,
        e_PrinterMode_9x11,
        e_PrinterMode_10x11,
        e_PrinterMode_15x11,
        e_PrinterMode_envelope_invite,
        e_PrinterMode_reserved_48,
        e_PrinterMode_reserved_49,
        e_PrinterMode_letter_extra,
        e_PrinterMode_legal_extra,
        e_PrinterMode_tabloid_extra,
        e_PrinterMode_a4_extra,
        e_PrinterMode_letter_transverse,
        e_PrinterMode_a4_transverse,
        e_PrinterMode_letter_extra_transverse,
        e_PrinterMode_supera_supera_a4,
        e_PrinterMode_Superb_Superb_a3,
        e_PrinterMode_letter_plus,
        e_PrinterMode_a4_plus,
        e_PrinterMode_a5_transverse,
        e_PrinterMode_b5_jis_transverse,
        e_PrinterMode_a3_extra,
        e_PrinterMode_a5_extra,
        e_PrinterMode_b5_iso_extra,
		e_PrinterMode_a2,
		e_PrinterMode_a3_transverse,
		e_PrinterMode_a3_extra_transverse,
		e_PrinterMode_japanese_double_postcard,
		e_PrinterMode_a6,
		e_PrinterMode_japanese_envelope_kaku_2,
		e_PrinterMode_japanese_envelope_kaku_3,
		e_PrinterMode_japanese_envelope_chou_3,
		e_PrinterMode_japanese_envelope_chou_4,
		e_PrinterMode_letter_rotated,
		e_PrinterMode_a3_rotated,
		e_PrinterMode_a4_rotated,
		e_PrinterMode_a5_rotated,
		e_PrinterMode_b4_jis_rotated,
		e_PrinterMode_b5_jis_rotated,
		e_PrinterMode_japanese_postcard_rotated,
		e_PrinterMode_double_japanese_postcard_rotated,
		e_PrinterMode_a6_rotated,
		e_PrinterMode_japanese_envelope_kaku_2_rotated,
		e_PrinterMode_japanese_envelope_kaku_3_rotated,
		e_PrinterMode_japanese_envelope_chou_3_rotated,
		e_PrinterMode_japanese_envelope_chou_4_rotated,
		e_PrinterMode_b6_jis,
		e_PrinterMode_b6_jis_rotated,
		e_PrinterMode_12x11,
		e_PrinterMode_japanese_envelope_you_4,
		e_PrinterMode_japanese_envelope_you_4_rotated,
		e_PrinterMode_PrinterMode_prc_16k,
        e_PrinterMode_prc_32k,
        e_PrinterMode_prc_32k_big,
        e_PrinterMode_prc_envelop_1,
        e_PrinterMode_prc_envelop_2,
        e_PrinterMode_prc_envelop_3,
        e_PrinterMode_prc_envelop_4,
        e_PrinterMode_prc_envelop_5,
        e_PrinterMode_prc_envelop_6,
        e_PrinterMode_prc_envelop_7,
        e_PrinterMode_prc_envelop_8,
        e_PrinterMode_prc_envelop_9,
        e_PrinterMode_prc_envelop_10,
        e_PrinterMode_prc_16k_rotated,
        e_PrinterMode_prc_32k_rotated,
        e_PrinterMode_prc_32k_big__rotated,
        e_PrinterMode_prc_envelop_1_rotated,
        e_PrinterMode_prc_envelop_2_rotated,
        e_PrinterMode_prc_envelop_3_rotated,
        e_PrinterMode_prc_envelop_4_rotated,
        e_PrinterMode_prc_envelop_5_rotated,
        e_PrinterMode_prc_envelop_6_rotated,
        e_PrinterMode_prc_envelop_7_rotated,
        e_PrinterMode_prc_envelop_8_rotated,
        e_PrinterMode_prc_envelop_9_rotated,
        e_PrinterMode_prc_envelop_10_rotated,
    };  
    
/* restore the original alignment */
#pragma pack()   

#ifdef __cplusplus
}
#endif 

#endif // PDFTRON_H_CCommonTypes
