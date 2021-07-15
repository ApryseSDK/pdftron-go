#ifndef PDFNetOBJC_H
#define PDFNetOBJC_H

#import "PDFNetOBJC_Private.h"

typedef enum PTReferencePos {  e_ptbegin = SEEK_SET,
  e_ptend = SEEK_END,
  e_ptcur = SEEK_CUR}PTReferencePos;

typedef enum PTSaveOptions {  e_ptincremental = 0x01,
  e_ptremove_unused = 0x02,
  e_pthex_strings = 0x04,
  e_ptomit_xref = 0x08,
  e_ptlinearized = 0x10,
  e_ptcompatibility = 0x20}PTSaveOptions;

typedef enum PTObjType {  e_ptnull,
  e_ptbool,
  e_ptnumber,
  e_ptname,
  e_ptstring,
  e_ptdict,
  e_ptarray,
  e_ptstream}PTObjType;

typedef enum PTPermission {  e_ptowner = 1,
  e_ptdoc_open,
  e_ptdoc_modify,
  e_ptprint,
  e_ptprint_high,
  e_ptextract_content,
  e_ptmod_annot,
  e_ptfill_forms,
  e_ptaccess_support,
  e_ptassemble_doc}PTPermission;

typedef enum PTAlgorithmType {  e_ptRC4_40 = 1,
  e_ptRC4_128,
  e_ptAES,
  e_ptAES_256}PTAlgorithmType;

typedef enum PTOverloadedFunction {  pthas_CloneProc = 0x01,
  pthas_AuthProc = 0x02,
  pthas_AuthFailedProc = 0x04,
  pthas_GetAuthDataProc = 0x08,
  pthas_EditSecurDataProc = 0x10,
  pthas_FillEncDictProc = 0x20}PTOverloadedFunction;

typedef enum PTFunctionType {  e_ptsampled = 0,
  e_ptexponential = 2,
  e_ptstitching = 3,
  e_ptpostscript = 4}PTFunctionType;

typedef enum PTGeometryCollectionSnappingMode {  e_ptDefaultSnapMode = 14,
  e_ptPointOnLine = 1,
  e_ptLineMidpoint = 2,
  e_ptLineIntersection = 4,
  e_ptPathEndpoint = 8}PTGeometryCollectionSnappingMode;

typedef enum PTColorSpaceType {  e_ptdevice_gray,
  e_ptdevice_rgb,
  e_ptdevice_cmyk,
  e_ptcal_gray,
  e_ptcal_rgb,
  e_ptlab,
  e_pticc,
  e_ptindexed,
  e_ptpattern,
  e_ptseparation,
  e_ptdevice_n,
  e_ptc_null}PTColorSpaceType;

typedef enum PTBox {  e_ptmedia,
  e_ptcrop,
  e_ptbleed,
  e_pttrim,
  e_ptart}PTBox;

typedef enum PTRotate {  e_pt0,
  e_pt90,
  e_pt180,
  e_pt270}PTRotate;

typedef enum PTPageActionTriggerEvent {  e_ptaction_trigger_page_open = 11,
  e_ptaction_trigger_page_close = 12}PTPageActionTriggerEvent;

typedef enum PTGStateAttribute {  e_pttransform = 0,
  e_ptrendering_intent,
  e_ptstroke_cs,
  e_ptstroke_color,
  e_ptfill_cs,
  e_ptfill_color,
  e_ptline_width,
  e_ptline_cap,
  e_ptline_join,
  e_ptflatness,
  e_ptmiter_limit,
  e_ptdash_pattern,
  e_ptchar_spacing,
  e_ptword_spacing,
  e_pthorizontal_scale,
  e_ptleading,
  e_ptfont,
  e_ptfont_size,
  e_pttext_render_mode,
  e_pttext_rise,
  e_pttext_knockout,
  e_pttext_pos_offset,
  e_ptblend_mode,
  e_ptopacity_fill,
  e_ptopacity_stroke,
  e_ptalpha_is_shape,
  e_ptsoft_mask,
  e_ptsmoothnes,
  e_ptauto_stoke_adjust,
  e_ptstroke_overprint,
  e_ptfill_overprint,
  e_ptoverprint_mode,
  e_pttransfer_funct,
  e_ptBG_funct,
  e_ptUCR_funct,
  e_pthalftone,
  e_ptg_null}PTGStateAttribute;

typedef enum PTLineCap {  e_ptbutt_cap = 0,
  e_ptround_cap,
  e_ptsquare_cap}PTLineCap;

typedef enum PTLineJoin {  e_ptmiter_join = 0,
  e_ptround_join,
  e_ptbevel_join}PTLineJoin;

typedef enum PTTextRenderingMode {  e_ptfill_text = 0,
  e_ptstroke_text,
  e_ptfill_stroke_text,
  e_ptinvisible_text,
  e_ptfill_clip_text,
  e_ptstroke_clip_text,
  e_ptfill_stroke_clip_text,
  e_ptclip_text}PTTextRenderingMode;

typedef enum PTRenderingIntent {  e_ptabsolute_colorimetric,
  e_ptrelative_colorimetric,
  e_ptsaturation,
  e_ptperceptual}PTRenderingIntent;

typedef enum PTBlendMode {  e_ptbl_compatible = 0,
  e_ptbl_normal,
  e_ptbl_multiply,
  e_ptbl_screen,
  e_ptbl_difference,
  e_ptbl_darken,
  e_ptbl_lighten,
  e_ptbl_color_dodge,
  e_ptbl_color_burn,
  e_ptbl_exclusion,
  e_ptbl_hard_light,
  e_ptbl_overlay,
  e_ptbl_soft_light,
  e_ptbl_luminosity,
  e_ptbl_hue,
  e_ptbl_saturation,
  e_ptbl_color}PTBlendMode;

typedef enum PTInputFilter {  e_pti_none,
  e_pti_jpeg,
  e_ptjp2,
  e_pti_flate,
  e_ptg3,
  e_ptg4,
  e_ptascii_hex}PTInputFilter;

typedef enum PTFieldType {  e_ptbutton,
  e_ptcheck,
  e_ptradio,
  e_pttext,
  e_ptchoice,
  e_ptsignature,
  e_ptf_null}PTFieldType;

typedef enum PTFieldActionTriggerEvent {  e_ptaction_trigger_keystroke = 13,
  e_ptaction_trigger_format = 14,
  e_ptaction_trigger_validate = 15,
  e_ptaction_trigger_calculate = 16}PTFieldActionTriggerEvent;

typedef enum PTFieldFlag {  e_ptread_only,
  e_ptrequired,
  e_ptno_export,
  e_ptpushbutton_flag,
  e_ptradio_flag,
  e_pttoggle_to_off,
  e_ptradios_in_unison,
  e_ptmultiline,
  e_ptpassword,
  e_ptfile_select,
  e_ptno_spellcheck,
  e_ptno_scroll,
  e_ptcomb,
  e_ptrich_text,
  e_ptcombo,
  e_ptedit,
  e_ptsort,
  e_ptmultiselect,
  e_ptcommit_on_sel_change}PTFieldFlag;

typedef enum PTTextJustification {  e_ptleft_justified,
  e_ptcentered,
  e_ptright_justified}PTTextJustification;

typedef enum PTPredefined {  e_ptcommonName = 0,
  e_ptsurname = 1,
  e_ptcountryName = 2,
  e_ptlocalityName = 3,
  e_ptstateOrProvinceName = 4,
  e_ptstreetAddress = 5,
  e_ptorganizationName = 6,
  e_ptorganizationalUnitName = 7}PTPredefined;

typedef enum PTDisallowedChangeType {  e_ptform_filled = 0,
  e_ptdigital_signature_signed = 1,
  e_ptpage_template_instantiated = 2,
  e_ptannotation_created_or_updated_or_deleted = 3,
  e_ptother = 4,
  e_ptdct_unknown = 5}PTDisallowedChangeType;

typedef enum PTVerificationOptionsSecurityLevel {  e_ptcompatibility_and_archiving = 0,
  e_ptmaximum = 1}PTVerificationOptionsSecurityLevel;

typedef enum PTVerificationOptionsTimeMode {  e_ptsigning = 0,
  e_pttimestamp = 1,
  e_ptcurrent = 2}PTVerificationOptionsTimeMode;

typedef enum PTVerificationOptionsCertificateTrustFlag {  e_ptsigning_trust = 1,
  e_ptcertification_trust = 2,
  e_ptdynamic_content = 4,
  e_ptjavascript = 16,
  e_ptidentity = 32,
  e_pttrust_anchor = 64,
  e_ptdefault_trust = 97,
  e_ptcomplete_trust = 119}PTVerificationOptionsCertificateTrustFlag;

typedef enum PTVerificationResultDocumentStatus {  e_ptno_error = 0,
  e_ptcorrupt_file = 1,
  e_ptunsigned = 2,
  e_ptbad_byteranges = 3,
  e_ptcorrupt_cryptographic_contents = 4}PTVerificationResultDocumentStatus;

typedef enum PTVerificationResultDigestStatus {  e_ptdigest_invalid = 0,
  e_ptdigest_verified = 1,
  e_ptdigest_verification_disabled = 2,
  e_ptweak_digest_algorithm_but_digest_verifiable = 3,
  e_ptno_digest_status = 4,
  e_ptunsupported_encoding = 5,
  e_ptunsupported_digest_algorithm = 6}PTVerificationResultDigestStatus;

typedef enum PTVerificationResultTrustStatus {  e_pttrust_verified = 0,
  e_ptuntrusted = 1,
  e_pttrust_verification_disabled = 2,
  e_ptno_trust_status = 3,
  e_ptunsupported_trust_features = 4}PTVerificationResultTrustStatus;

typedef enum PTVerificationResultModificationPermissionsStatus {  e_ptinvalidated_by_disallowed_changes = 0,
  e_pthas_allowed_changes = 1,
  e_ptunmodified = 2,
  e_ptpermissions_verification_disabled = 3,
  e_ptno_permissions_status = 4,
  e_ptunsupported_permissions_features = 5}PTVerificationResultModificationPermissionsStatus;

typedef enum PTDigestAlgorithmType {  e_ptsha1 = 0,
  e_ptsha256 = 1,
  e_ptsha384 = 2,
  e_ptsha512 = 3,
  e_ptripemd160 = 4,
  e_ptunknown_digest_algorithm = 5}PTDigestAlgorithmType;

typedef enum PTDigitalSignatureFieldSubFilterType {  e_ptadbe_x509_rsa_sha1 = 0,
  e_ptadbe_pkcs7_detached = 1,
  e_ptadbe_pkcs7_sha1 = 2,
  e_ptETSI_CAdES_detached = 3,
  e_ptETSI_RFC3161 = 4,
  e_ptunknown = 5,
  e_ptabsent = 6}PTDigitalSignatureFieldSubFilterType;

typedef enum PTDigitalSignatureFieldDocumentPermissions {  e_ptno_changes_allowed = 1,
  e_ptformfilling_signing_allowed = 2,
  e_ptannotating_formfilling_signing_allowed = 3,
  e_ptunrestricted = 4}PTDigitalSignatureFieldDocumentPermissions;

typedef enum PTDigitalSignatureFieldFieldPermissions {  e_ptdigsig_permission_lock_all = 0,
  e_ptdigsig_permission_include = 1,
  e_ptdigsig_permission_exclude = 2}PTDigitalSignatureFieldFieldPermissions;

typedef enum PTAnnotType {  e_ptText,
  e_ptLink,
  e_ptFreeText,
  e_ptLine,
  e_ptSquare,
  e_ptCircle,
  e_ptPolygon,
  e_ptPolyline,
  e_ptHighlight,
  e_ptUnderline,
  e_ptSquiggly,
  e_ptStrikeOut,
  e_ptStamp,
  e_ptCaret,
  e_ptInk,
  e_ptPopup,
  e_ptFileAttachment,
  e_ptSound,
  e_ptMovie,
  e_ptWidget,
  e_ptScreen,
  e_ptPrinterMark,
  e_ptTrapNet,
  e_ptWatermark,
  e_pt3D,
  e_ptRedact,
  e_ptProjection,
  e_ptRichMedia,
  e_ptUnknown}PTAnnotType;

typedef enum PTAnnotFlag {  e_ptinvisible,
  e_pthidden,
  e_ptprint_annot,
  e_ptno_zoom,
  e_ptno_rotate,
  e_ptno_view,
  e_ptannot_read_only,
  e_ptlocked,
  e_pttoggle_no_view,
  e_ptlocked_contents}PTAnnotFlag;

typedef enum PTAnnotActionTriggerEvent {  e_ptaction_trigger_activate = 0,
  e_ptaction_trigger_annot_enter = 1,
  e_ptaction_trigger_annot_exit = 2,
  e_ptaction_trigger_annot_down = 3,
  e_ptaction_trigger_annot_up = 4,
  e_ptaction_trigger_annot_focus = 5,
  e_ptaction_trigger_annot_blur = 6,
  e_ptaction_trigger_annot_page_open = 7,
  e_ptaction_trigger_annot_page_close = 8,
  e_ptaction_trigger_annot_page_visible = 9,
  e_ptaction_trigger_annot_page_invisible = 10}PTAnnotActionTriggerEvent;

typedef enum PTAnnotationState {  e_ptnormal,
  e_ptrollover,
  e_ptdown}PTAnnotationState;

typedef enum PTBdStyle {  e_ptsolid,
  e_ptdashed,
  e_ptbeveled,
  e_ptinset,
  e_ptunderline}PTBdStyle;

typedef enum PTBorderEffect {  e_ptNone,
  e_ptCloudy}PTBorderEffect;

typedef enum PTFileIcon {  e_ptGraph,
  e_ptPushPin,
  e_ptPaperclip,
  e_ptTag,
  e_ptfi_Unknown}PTFileIcon;

typedef enum PTFitType {  e_ptXYZ,
  e_ptFit,
  e_ptFitH,
  e_ptFitV,
  e_ptFitR,
  e_ptFitB,
  e_ptFitBH,
  e_ptFitBV}PTFitType;

typedef enum PTActionType {  e_ptGoTo,
  e_ptGoToR,
  e_ptGoToE,
  e_ptLaunch,
  e_ptThread,
  e_ptURI,
  e_pta_sound,
  e_pta_Movie,
  e_ptHide,
  e_ptNamed,
  e_ptSubmitForm,
  e_ptResetForm,
  e_ptImportData,
  e_ptJavaScript,
  e_ptSetOCGState,
  e_ptRendition,
  e_ptTrans,
  e_ptGoTo3DView,
  e_ptRichMediaExecute,
  e_pta_Unknown}PTActionType;

typedef enum PTFormActionFlag {  e_ptexclude = 0,
  e_ptinclude_no_value_fields = 1,
  e_ptexport_format = 2,
  e_ptget_method = 3,
  e_ptsubmit_coordinates = 4,
  e_ptxfdf = 5,
  e_ptinclude_append_saves = 6,
  e_ptinclude_annotations = 7,
  e_ptsubmit_pdf = 8,
  e_ptcanonical_format = 9,
  e_ptexcl_non_user_annots = 10,
  e_ptexcl_F_key = 11,
  e_ptembed_form = 13}PTFormActionFlag;

typedef enum PTEndingStyle {  e_ptl_Square,
  e_ptl_Circle,
  e_ptDiamond,
  e_ptOpenArrow,
  e_ptClosedArrow,
  e_ptButt,
  e_ptROpenArrow,
  e_ptRClosedArrow,
  e_ptSlash,
  e_ptl_None,
  e_ptl_Unknown}PTEndingStyle;

typedef enum PTLineIntentType {  e_ptLineArrow,
  e_ptLineDimension,
  e_ptl_null}PTLineIntentType;

typedef enum PTCapPos {  e_ptInline,
  e_ptTop}PTCapPos;

typedef enum PTIntentName {  e_ptf_FreeText,
  e_ptFreeTextCallout,
  e_ptFreeTextTypeWriter,
  e_ptf_Unknown}PTIntentName;

typedef enum PTLinkHighlightingMode {  e_ptl_none,
  e_ptinvert,
  e_pthighlight_outline,
  e_ptpush}PTLinkHighlightingMode;

typedef enum PTPolyLineIntentType {  e_ptPolygonCloud,
  e_ptPolyLineDimension,
  e_ptPolygonDimension,
  e_ptp_Unknown}PTPolyLineIntentType;

typedef enum PTQuadForm {  e_ptLeftJustified,
  e_ptCentered,
  e_ptRightJustified,
  e_ptr_None}PTQuadForm;

typedef enum PTRubberStampIcon {  e_ptApproved,
  e_ptExperimental,
  e_ptNotApproved,
  e_ptAsIs,
  e_ptExpired,
  e_ptNotForPublicRelease,
  e_ptConfidential,
  e_ptFinal,
  e_ptSold,
  e_ptDepartmental,
  e_ptForComment,
  e_ptTopSecret,
  e_ptForPublicRelease,
  e_ptDraft,
  e_ptr_Unknown}PTRubberStampIcon;

typedef enum PTScreenIconCaptionRelation {  e_ptNoIcon,
  e_ptNoCaption,
  e_ptCBelowI,
  e_ptCAboveI,
  e_ptCRightILeft,
  e_ptCLeftIRight,
  e_ptCOverlayI}PTScreenIconCaptionRelation;

typedef enum PTScreenScaleCondition {  e_ptAlways,
  e_ptWhenBigger,
  e_ptWhenSmaller,
  e_ptNever}PTScreenScaleCondition;

typedef enum PTScreenScaleType {  e_ptAnamorphic,
  e_ptProportional}PTScreenScaleType;

typedef enum PTSoundIcon {  e_ptSpeaker,
  e_ptMic,
  e_pts_Unknown}PTSoundIcon;

typedef enum PTTextIcon {  e_ptComment,
  e_ptKey,
  e_ptHelp,
  e_ptNewParagraph,
  e_ptParagraph,
  e_ptInsert,
  e_ptNote,
  e_ptt_Unknown}PTTextIcon;

typedef enum PTWidgetHighlightingMode {  e_ptw_none,
  e_ptw_invert,
  e_ptw_outline,
  e_ptw_push,
  e_pttoggle}PTWidgetHighlightingMode;

typedef enum PTWidgetIconCaptionRelation {  e_ptw_NoIcon,
  e_ptw_NoCaption,
  e_ptw_CBelowI,
  e_ptw_CAboveI,
  e_ptw_CRightILeft,
  e_ptw_CLeftIRight,
  e_ptw_COverlayI}PTWidgetIconCaptionRelation;

typedef enum PTWidgetScaleCondition {  e_ptw_Always,
  e_ptw_WhenBigger,
  e_ptw_WhenSmaller,
  e_ptw_Never}PTWidgetScaleCondition;

typedef enum PTWidgetScaleType {  e_ptw_Anamorphic,
  e_ptw_Proportional}PTWidgetScaleType;

typedef enum PTOCDrawMode {  e_ptVisibleOC,
  e_ptAllOC,
  e_ptNoOC}PTOCDrawMode;

typedef enum PTVisibilityPolicyType {  e_ptAllOn,
  e_ptAnyOn,
  e_ptAnyOff,
  e_ptAllOff}PTVisibilityPolicyType;

typedef enum PTConformance {  e_ptNoConformance = 0,
  e_ptLevel1A,
  e_ptLevel1B,
  e_ptLevel2A,
  e_ptLevel2B,
  e_ptLevel2U,
  e_ptLevel3A,
  e_ptLevel3B,
  e_ptLevel3U}PTConformance;

typedef enum PTErrorCode {  e_ptPDFA0_1_0 = 10,
  e_ptPDFA0_1_1 = 11,
  e_ptPDFA0_1_2 = 12,
  e_ptPDFA0_1_3 = 13,
  e_ptPDFA0_1_4 = 14,
  e_ptPDFA0_1_5 = 15,
  e_ptPDFA1_2_1 = 121,
  e_ptPDFA1_2_2 = 122,
  e_ptPDFA1_3_1 = 131,
  e_ptPDFA1_3_2 = 132,
  e_ptPDFA1_3_3 = 133,
  e_ptPDFA1_3_4 = 134,
  e_ptPDFA1_4_1 = 141,
  e_ptPDFA1_4_2 = 142,
  e_ptPDFA1_6_1 = 161,
  e_ptPDFA1_7_1 = 171,
  e_ptPDFA1_7_2 = 172,
  e_ptPDFA1_7_3 = 173,
  e_ptPDFA1_7_4 = 174,
  e_ptPDFA1_8_1 = 181,
  e_ptPDFA1_8_2 = 182,
  e_ptPDFA1_8_3 = 183,
  e_ptPDFA1_8_4 = 184,
  e_ptPDFA1_8_5 = 185,
  e_ptPDFA1_8_6 = 186,
  e_ptPDFA1_8_7 = 187,
  e_ptPDFA1_10_1 = 1101,
  e_ptPDFA1_11_1 = 1111,
  e_ptPDFA1_11_2 = 1112,
  e_ptPDFA1_12_1 = 1121,
  e_ptPDFA1_12_2 = 1122,
  e_ptPDFA1_12_3 = 1123,
  e_ptPDFA1_12_4 = 1124,
  e_ptPDFA1_12_5 = 1125,
  e_ptPDFA1_12_6 = 1126,
  e_ptPDFA1_13_1 = 1131,
  e_ptPDFA2_2_1 = 221,
  e_ptPDFA2_3_2 = 232,
  e_ptPDFA2_3_3 = 233,
  e_ptPDFA2_3_3_1 = 2331,
  e_ptPDFA2_3_3_2 = 2332,
  e_ptPDFA2_3_4_1 = 2341,
  e_ptPDFA2_4_1 = 241,
  e_ptPDFA2_4_2 = 242,
  e_ptPDFA2_4_3 = 243,
  e_ptPDFA2_4_4 = 244,
  e_ptPDFA2_5_1 = 251,
  e_ptPDFA2_5_2 = 252,
  e_ptPDFA2_6_1 = 261,
  e_ptPDFA2_7_1 = 271,
  e_ptPDFA2_8_1 = 281,
  e_ptPDFA2_9_1 = 291,
  e_ptPDFA2_10_1 = 2101,
  e_ptPDFA3_2_1 = 321,
  e_ptPDFA3_3_1 = 331,
  e_ptPDFA3_3_2 = 332,
  e_ptPDFA3_3_3_1 = 3331,
  e_ptPDFA3_3_3_2 = 3332,
  e_ptPDFA3_4_1 = 341,
  e_ptPDFA3_5_1 = 351,
  e_ptPDFA3_5_2 = 352,
  e_ptPDFA3_5_3 = 353,
  e_ptPDFA3_5_4 = 354,
  e_ptPDFA3_5_5 = 355,
  e_ptPDFA3_5_6 = 356,
  e_ptPDFA3_6_1 = 361,
  e_ptPDFA3_7_1 = 371,
  e_ptPDFA3_7_2 = 372,
  e_ptPDFA3_7_3 = 373,
  e_ptPDFA4_1 = 41,
  e_ptPDFA4_2 = 42,
  e_ptPDFA4_3 = 43,
  e_ptPDFA4_4 = 44,
  e_ptPDFA4_5 = 45,
  e_ptPDFA4_6 = 46,
  e_ptPDFA5_2_1 = 521,
  e_ptPDFA5_2_2 = 522,
  e_ptPDFA5_2_3 = 523,
  e_ptPDFA5_2_4 = 524,
  e_ptPDFA5_2_5 = 525,
  e_ptPDFA5_2_6 = 526,
  e_ptPDFA5_2_7 = 527,
  e_ptPDFA5_2_8 = 528,
  e_ptPDFA5_2_9 = 529,
  e_ptPDFA5_2_10 = 5210,
  e_ptPDFA5_2_11 = 5211,
  e_ptPDFA5_3_1 = 531,
  e_ptPDFA5_3_2_1 = 5321,
  e_ptPDFA5_3_2_2 = 5322,
  e_ptPDFA5_3_2_3 = 5323,
  e_ptPDFA5_3_2_4 = 5324,
  e_ptPDFA5_3_2_5 = 5325,
  e_ptPDFA5_3_3_1 = 5331,
  e_ptPDFA5_3_3_2 = 5332,
  e_ptPDFA5_3_3_3 = 5333,
  e_ptPDFA5_3_3_4 = 5334,
  e_ptPDFA5_3_4_0 = 5340,
  e_ptPDFA5_3_4_1 = 5341,
  e_ptPDFA5_3_4_2 = 5342,
  e_ptPDFA5_3_4_3 = 5343,
  e_ptPDFA6_1_1 = 611,
  e_ptPDFA6_1_2 = 612,
  e_ptPDFA6_2_1 = 621,
  e_ptPDFA6_2_2 = 622,
  e_ptPDFA6_2_3 = 623,
  e_ptPDFA7_2_1 = 721,
  e_ptPDFA7_2_2 = 722,
  e_ptPDFA7_2_3 = 723,
  e_ptPDFA7_2_4 = 724,
  e_ptPDFA7_2_5 = 725,
  e_ptPDFA7_3_1 = 731,
  e_ptPDFA7_3_2 = 732,
  e_ptPDFA7_3_3 = 733,
  e_ptPDFA7_3_4 = 734,
  e_ptPDFA7_3_5 = 735,
  e_ptPDFA7_3_6 = 736,
  e_ptPDFA7_3_7 = 737,
  e_ptPDFA7_3_8 = 738,
  e_ptPDFA7_3_9 = 739,
  e_ptPDFA7_5_1 = 751,
  e_ptPDFA7_8_1 = 781,
  e_ptPDFA7_8_2 = 782,
  e_ptPDFA7_8_3 = 783,
  e_ptPDFA7_8_4 = 784,
  e_ptPDFA7_8_5 = 785,
  e_ptPDFA7_8_6 = 786,
  e_ptPDFA7_8_7 = 787,
  e_ptPDFA7_8_8 = 788,
  e_ptPDFA7_8_9 = 789,
  e_ptPDFA7_8_10 = 7810,
  e_ptPDFA7_8_11 = 7811,
  e_ptPDFA7_8_12 = 7812,
  e_ptPDFA7_8_13 = 7813,
  e_ptPDFA7_8_14 = 7814,
  e_ptPDFA7_8_15 = 7815,
  e_ptPDFA7_8_16 = 7816,
  e_ptPDFA7_8_17 = 7817,
  e_ptPDFA7_8_18 = 7818,
  e_ptPDFA7_8_19 = 7819,
  e_ptPDFA7_8_20 = 7820,
  e_ptPDFA7_8_21 = 7821,
  e_ptPDFA7_8_22 = 7822,
  e_ptPDFA7_8_23 = 7823,
  e_ptPDFA7_8_24 = 7824,
  e_ptPDFA7_8_25 = 7825,
  e_ptPDFA7_8_26 = 7826,
  e_ptPDFA7_8_27 = 7827,
  e_ptPDFA7_8_28 = 7828,
  e_ptPDFA7_8_29 = 7829,
  e_ptPDFA7_8_30 = 7830,
  e_ptPDFA7_8_31 = 7831,
  e_ptPDFA7_11_1 = 7111,
  e_ptPDFA7_11_2 = 7112,
  e_ptPDFA7_11_3 = 7113,
  e_ptPDFA7_11_4 = 7114,
  e_ptPDFA7_11_5 = 7115,
  e_ptPDFA9_1 = 91,
  e_ptPDFA9_2 = 92,
  e_ptPDFA9_3 = 93,
  e_ptPDFA9_4 = 94,
  e_ptPDFA3_8_1 = 381,
  e_ptPDFA8_2_2 = 822,
  e_ptPDFA8_3_3_1 = 8331,
  e_ptPDFA8_3_3_2 = 8332,
  e_ptPDFA8_3_4_1 = 8341,
  e_ptPDFA1_2_3 = 123,
  e_ptPDFA1_10_2 = 1102,
  e_ptPDFA1_10_3 = 1103,
  e_ptPDFA1_12_10 = 11210,
  e_ptPDFA1_13_5 = 1135,
  e_ptPDFA2_3_10 = 2310,
  e_ptPDFA2_4_2_10 = 24220,
  e_ptPDFA2_4_2_11 = 24221,
  e_ptPDFA2_4_2_12 = 24222,
  e_ptPDFA2_4_2_13 = 24223,
  e_ptPDFA2_5_10 = 2510,
  e_ptPDFA2_5_11 = 2511,
  e_ptPDFA2_5_12 = 2512,
  e_ptPDFA2_8_3_1 = 2831,
  e_ptPDFA2_8_3_2 = 2832,
  e_ptPDFA2_8_3_3 = 2833,
  e_ptPDFA2_8_3_4 = 2834,
  e_ptPDFA2_8_3_5 = 2835,
  e_ptPDFA2_10_20 = 21020,
  e_ptPDFA2_10_21 = 21021,
  e_ptPDFA11_0_0 = 11000,
  e_ptPDFA6_10_0 = 6100,
  e_ptPDFA6_10_1 = 6101,
  e_ptPDFA6_2_11_5 = 62115,
  e_ptPDFA6_2_11_6 = 62116,
  e_ptPDFA6_2_11_7 = 62117,
  e_ptPDFA6_2_11_8 = 62118,
  e_ptPDFA6_9_1 = 69001,
  e_ptPDFA6_9_3 = 69003,
  e_ptPDFA8_1 = 81,
  e_ptPDFA_3E1 = 1,
  e_ptPDFA_3E1_1 = 101,
  e_ptPDFA_3E2 = 2,
  e_ptPDFA_3E3 = 3,
  e_ptPDFA_LAST}PTErrorCode;

typedef enum PTContentItemType {  e_ptMCR,
  e_ptMCID,
  e_ptOBJR,
  e_ptc_Unknown}PTContentItemType;

typedef enum PTPathSegmentType {  e_ptmoveto = 1,
  e_ptlineto,
  e_ptcubicto,
  e_ptconicto,
  e_ptrect,
  e_ptclosepath}PTPathSegmentType;

typedef enum PTShapingStatus {  e_ptFullShaping = 0,
  e_ptPartialShaping = 1,
  e_ptNoShaping = 2}PTShapingStatus;

typedef enum PTShapingFailureReason {  e_ptNoFailure = 0,
  e_ptUnsupportedFontType = 1,
  e_ptNotIndexEncoded = 2,
  e_ptFontDataNotFound = 3}PTShapingFailureReason;

typedef enum PTStandardType1Font {  e_pttimes_roman = 0,
  e_pttimes_bold,
  e_pttimes_italic,
  e_pttimes_bold_italic,
  e_pthelvetica,
  e_pthelvetica_bold,
  e_pthelvetica_oblique,
  e_pthelvetica_bold_oblique,
  e_ptcourier,
  e_ptcourier_bold,
  e_ptcourier_oblique,
  e_ptcourier_bold_oblique,
  e_ptsymbol,
  e_ptzapf_dingbats,
  e_ptft_null}PTStandardType1Font;

typedef enum PTEncoding {  e_ptIdentityH = 0,
  e_ptIndices}PTEncoding;

typedef enum PTFontType {  e_ptType1,
  e_ptTrueType,
  e_ptMMType1,
  e_ptType3,
  e_ptType0,
  e_ptCIDType0,
  e_ptCIDType2}PTFontType;

typedef enum PTShadingType {  e_ptfunction_shading,
  e_ptaxial_shading,
  e_ptradial_shading,
  e_ptfree_gouraud_shading,
  e_ptlattice_gouraud_shading,
  e_ptcoons_shading,
  e_pttensor_shading,
  e_pts_null}PTShadingType;

typedef enum PTPatternColorType {  e_ptuncolored_tiling_pattern,
  e_ptcolored_tiling_pattern,
  e_ptshading,
  e_ptp_null}PTPatternColorType;

typedef enum PTTilingType {  e_ptconstant_spacing,
  e_ptno_distortion,
  e_ptconstant_spacing_fast_fill}PTTilingType;

typedef enum PTElementType {  e_pte_null,
  e_ptpath,
  e_pttext_begin,
  e_pttext_obj,
  e_pttext_new_line,
  e_pttext_end,
  e_ptimage,
  e_ptinline_image,
  e_pte_shading,
  e_ptform,
  e_ptgroup_begin,
  e_ptgroup_end,
  e_ptmarked_content_begin,
  e_ptmarked_content_end,
  e_ptmarked_content_point}PTElementType;

typedef enum PTWriteMode {  e_ptunderlay,
  e_ptoverlay,
  e_ptreplacement}PTWriteMode;

typedef enum PTExternalAnnotManagerMode {  e_ptuser_only,
  e_ptadmin_undo_others,
  e_ptadmin_undo_own}PTExternalAnnotManagerMode;

typedef enum PTThreshold {  e_ptthreshold_very_strict,
  e_ptthreshold_strict,
  e_ptthreshold_default,
  e_ptthreshold_keep_most,
  e_ptthreshold_keep_all}PTThreshold;

typedef enum PTFlattenMode {  e_ptsimple,
  e_ptfast}PTFlattenMode;

typedef enum PTCompressionMode {  e_ptretain,
  e_ptflate,
  e_ptjpeg,
  e_ptjpeg2000,
  e_ptnone}PTCompressionMode;

typedef enum PTDownsampleMode {  e_ptoff,
  e_ptds_default}PTDownsampleMode;

typedef enum PTMonoCompressionMode {  e_ptmn_jbig2,
  e_ptmn_flate,
  e_ptmn_none,
  e_ptmn_ccitt}PTMonoCompressionMode;

typedef enum PTMonoDownsampleMode {  e_ptmn_off,
  e_ptmn_default}PTMonoDownsampleMode;

typedef enum PTPageLabelStyle {  e_ptdecimal,
  e_ptroman_uppercase,
  e_ptroman_lowercase,
  e_ptalphabetic_uppercase,
  e_ptalphabetic_lowercase,
  e_ptpg_none}PTPageLabelStyle;

typedef enum PTPageSetFilter {  e_ptall,
  e_pteven,
  e_ptodd}PTPageSetFilter;

typedef enum PTPageMode {  e_ptUseNone,
  e_ptUseThumbs,
  e_ptUseBookmarks,
  e_ptFullScreen,
  e_ptUseOC,
  e_ptUseAttachments}PTPageMode;

typedef enum PTPageLayout {  e_ptDefault,
  e_ptSinglePage,
  e_ptOneColumn,
  e_ptTwoColumnLeft,
  e_ptTwoColumnRight,
  e_ptTwoPageLeft,
  e_ptTwoPageRight}PTPageLayout;

typedef enum PTViewerPref {  e_ptHideToolbar,
  e_ptHideMenubar,
  e_ptHideWindowUI,
  e_ptFitWindow,
  e_ptCenterWindow,
  e_ptDisplayDocTitle}PTViewerPref;

typedef enum PTDownloadedType {  e_ptdownloadedtype_page = 0,
  e_ptdownloadedtype_thumb,
  e_ptdownloadedtype_named_dests,
  e_ptdownloadedtype_outline,
  e_ptdownloadedtype_finished,
  e_ptdownloadedtype_failed,
  e_ptdownloadedtype_opened}PTDownloadedType;

typedef enum PTRasterizerType {  e_ptBuiltIn,
  e_ptGDIPlus}PTRasterizerType;

typedef enum PTOverprintPreviewMode {  e_ptop_off = 0,
  e_ptop_on,
  e_ptop_pdfx_on}PTOverprintPreviewMode;

typedef enum PTColorPostProcessMode {  e_ptpostprocess_none = 0,
  e_ptpostprocess_invert,
  e_ptpostprocess_gradient_map,
  e_ptpostprocess_night_mode}PTColorPostProcessMode;

typedef enum PTPDFDocActionTriggerEvent {  e_ptaction_trigger_doc_will_close = 17,
  e_ptaction_trigger_doc_will_save = 18,
  e_ptaction_trigger_doc_did_save = 19,
  e_ptaction_trigger_doc_will_print = 20,
  e_ptaction_trigger_doc_did_print = 21}PTPDFDocActionTriggerEvent;

typedef enum PTInsertFlag {  e_ptinsert_none,
  e_ptinsert_bookmark,
  e_ptinsert_goto_bookmark}PTInsertFlag;

typedef enum PTExtractFlag {  e_ptforms_only,
  e_ptannots_only,
  e_ptboth,
  e_ptannots_only_no_links = 5}PTExtractFlag;

typedef enum PTSignaturesVerificationStatus {  e_ptdoc_unsigned,
  e_ptdoc_failure,
  e_ptdoc_untrusted,
  e_ptdoc_unsupported,
  e_ptdoc_verified}PTSignaturesVerificationStatus;

typedef enum PTPixelFormat {  e_ptrgba,
  e_ptbgra,
  e_ptrgb,
  e_ptbgr,
  e_ptgray,
  e_ptgray_alpha,
  e_ptcmyk}PTPixelFormat;

typedef enum PTResult {  e_ptSuccess = 0,
  e_ptIncomplete = 1,
  e_ptFailure = 2}PTResult;

typedef enum PTFlattenThresholdFlag {  e_ptvery_strict,
  e_ptstrict,
  e_ptdefault,
  e_ptkeep_most,
  e_ptkeep_all}PTFlattenThresholdFlag;

typedef enum PTFlattenFlag {  e_ptflatten_off,
  e_ptflatten_simple,
  e_ptflatten_fast,
  e_pthigh_quality}PTFlattenFlag;

typedef enum PTXPSOverprintPreviewMode {  e_ptxps_op_off = 0,
  e_ptxps_op_on,
  e_ptcps_op_pdfx_on}PTXPSOverprintPreviewMode;

typedef enum PTAnnotationOutputFlag {  e_ptinternal_xfdf,
  e_ptexternal_xfdf,
  e_ptflatten}PTAnnotationOutputFlag;

typedef enum PTHTMLContentReflowSetting {  e_pthtml_fixed_position = 0,
  e_pthtml_reflow_paragraphs}PTHTMLContentReflowSetting;

typedef enum PTHTMLSearchableImageSetting {  e_pthtml_ocr_image_text = 0,
  e_pthtml_ocr_image,
  e_pthtml_ocr_text}PTHTMLSearchableImageSetting;

typedef enum PTWordOutputFormat {  e_ptwof_docx = 0,
  e_ptwof_doc,
  e_ptwof_rtf}PTWordOutputFormat;

typedef enum PTBookmarkConversionMethod {  e_ptword_bm_none = 0,
  e_ptword_bm_page,
  e_ptword_bm_extract}PTBookmarkConversionMethod;

typedef enum PTWordSearchableImageSetting {  e_ptword_ocr_image_text = 0,
  e_ptword_ocr_image,
  e_ptword_ocr_text}PTWordSearchableImageSetting;

typedef enum PTCMSType {  e_ptlcms,
  e_pticm,
  e_ptno_cms}PTCMSType;

typedef enum PTFlateCompressionLevel {  e_ptZ_DEFAULT_COMPRESSION = -1,
  e_ptZ_NO_COMPRESSION = 0,
  e_ptZ_BEST_SPEED = 1,
  e_ptZ_BEST_COMPRESSION = 9}PTFlateCompressionLevel;

typedef enum PTCharacterOrdering {  e_ptIdentity = 0,
  e_ptJapan1 = 1,
  e_ptJapan2 = 2,
  e_ptGB1 = 3,
  e_ptCNS1 = 4,
  e_ptKorea1 = 5}PTCharacterOrdering;

typedef enum PTLogLevel {  e_ptLogLevel_Off = -1,
  e_ptLogLevel_Fatal = 5,
  e_ptLogLevel_Error = 4,
  e_ptLogLevel_Warning = 3,
  e_ptLogLevel_Info = 2,
  e_ptLogLevel_Trace = 1,
  e_ptLogLevel_Debug = 0}PTLogLevel;

typedef enum PTPagePresentationMode {  e_ptsingle_page = 1,
  e_ptsingle_continuous,
  e_ptfacing,
  e_ptfacing_continuous,
  e_ptfacing_cover,
  e_ptfacing_continuous_cover}PTPagePresentationMode;

typedef enum PTTextSelectionMode {  e_ptstructural,
  e_ptrectangular,
  e_ptstructural_algorithm_2}PTTextSelectionMode;

typedef enum PTPageViewMode {  e_ptfit_page = 0,
  e_ptfit_width,
  e_ptfit_height,
  e_ptzoom,
  PTPVM_SIZE}PTPageViewMode;

typedef enum PaperSize {  e_custom = 0,
  e_letter,
  e_letter_small,
  e_tabloid,
  e_ledger,
  e_legal,
  e_statement,
  e_executive,
  e_a3,
  e_a4,
  e_a4_small,
  e_a5,
  e_b4_jis,
  e_b5_jis,
  e_folio,
  e_quarto,
  e_10x14,
  e_11x17,
  e_note,
  e_envelope_9,
  e_envelope_10,
  e_envelope_11,
  e_envelope_12,
  e_envelope_14,
  e_c_size_sheet,
  e_d_size_sheet,
  e_e_size_sheet,
  e_envelope_dl,
  e_envelope_c5,
  e_envelope_c3,
  e_envelope_c4,
  e_envelope_c6,
  e_envelope_c65,
  e_envelope_b4,
  e_envelope_b5,
  e_envelope_b6,
  e_envelope_italy,
  e_envelope_monarch,
  e_6_3_quarters_envelope,
  e_us_std_fanfold,
  e_german_std_fanfold,
  e_german_legal_fanfold,
  e_b4_iso,
  e_japanese_postcard,
  e_9x11,
  e_10x11,
  e_15x11,
  e_envelope_invite,
  e_reserved_48,
  e_reserved_49,
  e_letter_extra,
  e_legal_extra,
  e_tabloid_extra,
  e_a4_extra,
  e_letter_transverse,
  e_a4_transverse,
  e_letter_extra_transverse,
  e_supera_supera_a4,
  e_Superb_Superb_a3,
  e_letter_plus,
  e_a4_plus,
  e_a5_transverse,
  e_b5_jis_transverse,
  e_a3_extra,
  e_a5_extra,
  e_b5_iso_extra,
  e_a2,
  e_a3_transverse,
  e_a3_extra_transverse,
  e_japanese_double_postcard,
  e_a6,
  e_japanese_envelope_kaku_2,
  e_japanese_envelope_kaku_3,
  e_japanese_envelope_chou_3,
  e_japanese_envelope_chou_4,
  e_letter_rotated,
  e_a3_rotated,
  e_a4_rotated,
  e_a5_rotated,
  e_b4_jis_rotated,
  e_b5_jis_rotated,
  e_japanese_postcard_rotated,
  e_double_japanese_postcard_rotated,
  e_a6_rotated,
  e_japanese_envelope_kaku_2_rotated,
  e_japanese_envelope_kaku_3_rotated,
  e_japanese_envelope_chou_3_rotated,
  e_japanese_envelope_chou_4_rotated,
  e_b6_jis,
  e_b6_jis_rotated,
  e_12x11,
  e_japanese_envelope_you_4,
  e_japanese_envelope_you_4_rotated,
  e_prc_16k,
  e_prc_32k,
  e_prc_32k_big,
  e_prc_envelop_1,
  e_prc_envelop_2,
  e_prc_envelop_3,
  e_prc_envelop_4,
  e_prc_envelop_5,
  e_prc_envelop_6,
  e_prc_envelop_7,
  e_prc_envelop_8,
  e_prc_envelop_9,
  e_prc_envelop_10,
  e_prc_16k_rotated,
  e_prc_32k_rotated,
  e_prc_32k_big__rotated,
  e_prc_envelop_1_rotated,
  e_prc_envelop_2_rotated,
  e_prc_envelop_3_rotated,
  e_prc_envelop_4_rotated,
  e_prc_envelop_5_rotated,
  e_prc_envelop_6_rotated,
  e_prc_envelop_7_rotated,
  e_prc_envelop_8_rotated,
  e_prc_envelop_9_rotated,
  e_prc_envelop_10_rotated}PaperSize;

typedef enum DuplexMode {  e_Duplex_Auto = 0,
  e_Duplex_None = 1,
  e_Duplex_LongSide = 2,
  e_Duplex_ShortSide = 3}DuplexMode;

typedef enum OutputQuality {  e_OutputQuality_Draft = -1,
  e_OutputQuality_Low = -2,
  e_OutputQuality_Medium = -3,
  e_OutputQuality_High = -4}OutputQuality;

typedef enum OutputColor {  e_OutputColor_Color = 0,
  e_OutputColor_Grayscale = 1,
  e_OutputColor_Monochrome = 2}OutputColor;

typedef enum Orientation {  e_Orientation_Portrait = 0,
  e_Orientation_Landscape = 1}Orientation;

typedef enum PTPrintScaleType {  e_ScaleType_None = 0,
  e_ScaleType_FitToOutputPage = 1,
  e_ScaleType_ReduceToOutputPage = 2}PTPrintScaleType;

typedef enum NUp {  e_NUp_1_1 = 0,
  e_NUp_2_1 = 1,
  e_NUp_2_2 = 2,
  e_NUp_3_2 = 3,
  e_NUp_3_3 = 4,
  e_NUp_4_4 = 5}NUp;

typedef enum NUpPageOrder {  e_PageOrder_LeftToRightThenTopToBottom = 0,
  e_PageOrder_RightToLeftThenTopToBottom = 1,
  e_PageOrder_TopToBottomThenLeftToRight = 2,
  e_PageOrder_BottomToTopThenLeftToRight = 3}NUpPageOrder;

typedef enum PrintContentTypes {  e_PrintContent_DocumentOnly = 0,
  e_PrintContent_DocumentAndAnnotations = 1,
  e_PrintContent_DocumentAnnotationsAndComments = 2}PrintContentTypes;

typedef enum PTProxyType {  e_ptp_default,
  e_ptp_none,
  e_pthttp,
  e_ptsocks5}PTProxyType;

typedef enum PTErrorHandling {  e_ptabort,
  e_ptskip,
  e_ptignore}PTErrorHandling;

typedef enum PTSizeType {  e_ptrelative_scale = 1,
  e_ptabsolute_size = 2,
  e_pts_font_size = 3}PTSizeType;

typedef enum PTHorizontalAlignment {  e_pthorizontal_left = -1,
  e_pthorizontal_center = 0,
  e_pthorizontal_right = 1}PTHorizontalAlignment;

typedef enum PTVerticalAlignment {  e_ptvertical_bottom = -1,
  e_ptvertical_center = 0,
  e_ptvertical_top = 1}PTVerticalAlignment;

typedef enum PTTextAlignment {  e_ptalign_left = -1,
  e_ptalign_center = 0,
  e_ptalign_right = 1}PTTextAlignment;

typedef enum PTProcessingFlags {  e_ptno_ligature_exp = 1,
  e_ptno_dup_remove = 2,
  e_ptpunct_break = 4,
  e_ptremove_hidden_text = 8,
  e_ptno_invisible_text = 16,
  e_ptno_watermarks = 128}PTProcessingFlags;

typedef enum PTXMLOutputFlags {  e_ptwords_as_elements = 1,
  e_ptoutput_bbox = 2,
  e_ptoutput_style_info = 4}PTXMLOutputFlags;

typedef enum PTTextSearchModes {  e_ptreg_expression = 0x0001,
  e_ptcase_sensitive = e_ptreg_expression << 1,
  e_ptwhole_word = e_ptcase_sensitive << 1,
  e_ptsearch_up = e_ptwhole_word << 1,
  e_ptpage_stop = e_ptsearch_up << 1,
  e_pthighlight = e_ptpage_stop << 1,
  e_ptambient_string = e_pthighlight << 1,
  e_ptraw_text_search = e_ptambient_string << 1}PTTextSearchModes;



@interface PTVectorObj : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (unsigned long)size;
- (unsigned long)capacity;
- (void)reserve: (unsigned long)n;
- (BOOL)isEmpty;
- (void)clear;
- (void)add: (PTObj*)x;
- (PTObj*)get: (int)i;
- (void)set: (int)i val:  (PTObj*)val;
- (id)init;
@end


@interface PTVectorPage : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (unsigned long)size;
- (unsigned long)capacity;
- (void)reserve: (unsigned long)n;
- (BOOL)isEmpty;
- (void)clear;
- (void)add: (PTPage*)x;
- (PTPage*)get: (int)i;
- (void)set: (int)i val:  (PTPage*)val;
- (id)init;
@end


@interface PTVectorRedaction : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (unsigned long)size;
- (unsigned long)capacity;
- (void)reserve: (unsigned long)n;
- (BOOL)isEmpty;
- (void)clear;
- (void)add: (PTRedaction*)x;
- (PTRedaction*)get: (int)i;
- (void)set: (int)i val:  (PTRedaction*)val;
- (id)init;
@end


@interface PTVectorQuadPoint : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (unsigned long)size;
- (unsigned long)capacity;
- (void)reserve: (unsigned long)n;
- (BOOL)isEmpty;
- (void)clear;
- (void)add: (PTQuadPoint*)x;
- (PTQuadPoint*)get: (int)i;
- (void)set: (int)i val:  (PTQuadPoint*)val;
- (id)init;
@end


@interface PTVectorAnnot : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (unsigned long)size;
- (unsigned long)capacity;
- (void)reserve: (unsigned long)n;
- (BOOL)isEmpty;
- (void)clear;
- (void)add: (PTAnnot*)x;
- (PTAnnot*)get: (int)i;
- (void)set: (int)i val:  (PTAnnot*)val;
- (id)init;
@end


@interface TRN_matrix2d : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setM_a: (double)value;
- (double)getM_a;
- (void)setM_b: (double)value;
- (double)getM_b;
- (void)setM_c: (double)value;
- (double)getM_c;
- (void)setM_d: (double)value;
- (double)getM_d;
- (void)setM_h: (double)value;
- (double)getM_h;
- (void)setM_v: (double)value;
- (double)getM_v;
- (id)init;
@end


@interface TRN_date : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setYear: (unsigned short)value;
- (unsigned short)getYear;
- (void)setMonth: (char)value;
- (char)getMonth;
- (void)setDay: (char)value;
- (char)getDay;
- (void)setHour: (char)value;
- (char)getHour;
- (void)setMinute: (char)value;
- (char)getMinute;
- (void)setSecond: (char)value;
- (char)getSecond;
- (void)setUT: (char)value;
- (char)getUT;
- (void)setUT_hour: (char)value;
- (char)getUT_hour;
- (void)setUT_minutes: (char)value;
- (char)getUT_minutes;
- (void)setMp_obj: (void *)value;
- (void *)getMp_obj;
- (id)init;
@end


@interface TRN_chardata : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setChar_code: (unsigned int)value;
- (unsigned int)getChar_code;
- (void)setX: (double)value;
- (double)getX;
- (void)setY: (double)value;
- (double)getY;
- (void)setChar_data: (NSData*)value;
- (NSData*)getChar_data;
- (void)setBytes: (int)value;
- (int)getBytes;
- (id)init;
@end


@interface TRN_point : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setX: (double)value;
- (double)getX;
- (void)setY: (double)value;
- (double)getY;
- (id)init;
@end


@interface TRN_quadpoint : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setP1x: (double)value;
- (double)getP1x;
- (void)setP1y: (double)value;
- (double)getP1y;
- (void)setP2x: (double)value;
- (double)getP2x;
- (void)setP2y: (double)value;
- (double)getP2y;
- (void)setP3x: (double)value;
- (double)getP3x;
- (void)setP3y: (double)value;
- (double)getP3y;
- (void)setP4x: (double)value;
- (double)getP4x;
- (void)setP4y: (double)value;
- (double)getP4y;
- (id)init;
@end


@interface PTPDFPoint : TRN_point
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (id)init;- (id)initWithPx: (double)px py:  (double)py;
@end


@interface PTByteRange : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (unsigned long long)GetStartOffset;
- (unsigned long long)GetEndOffset;
- (unsigned long long)GetSize;
- (id)init;
@end


@interface PTRecentlyUsedCache : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (void)RemoveDocument: (NSString *)document_path;
+ (void)AccessDocument: (NSString *)document_path;
+ (NSString *)GetBitmapPathIfExists: (NSString *)document_path;
+ (void)ResetCache;
+ (void)InitializeRecentlyUsedCache: (unsigned long)num_documents max_absolute_space:  (unsigned long)max_absolute_space max_percentage_space:  (double)max_percentage_space;
- (id)init;
@end


@interface PTMatrix2D : TRN_matrix2d
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Set: (double)a b:  (double)b c:  (double)c d:  (double)d h:  (double)h v:  (double)v;
- (void)Concat: (double)a b:  (double)b c:  (double)c d:  (double)d h:  (double)h v:  (double)v;
- (PTMatrix2D*)Multiply: (PTMatrix2D*)m;
- (BOOL)IsEquals: (PTMatrix2D*)m;
- (BOOL)IsNotEquals: (PTMatrix2D*)m;
- (PTPDFPoint*)Mult: (PTPDFPoint*)pt;
- (PTMatrix2D*)Inverse;
- (void)Translate: (double)h v:  (double)v;
- (void)PreTranslate: (double)h v:  (double)v;
- (void)PostTranslate: (double)h v:  (double)v;
- (void)Scale: (double)h v:  (double)v;
+ (PTMatrix2D*)ZeroMatrix;
+ (PTMatrix2D*)IdentityMatrix;
+ (PTMatrix2D*)RotationMatrix: (double)angle;
- (id)initWithA: (double)a b:  (double)b c:  (double)c d:  (double)d h:  (double)h v:  (double)v;
@end


@interface PTGSChangesIterator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)Next;
- (int)Current;
- (BOOL)HasNext;
- (id)init;
@end


@interface PTUInt32Iterator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)Next;
- (unsigned int)Current;
- (BOOL)HasNext;
- (id)init;
@end


@interface PTCharIterator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)Next;
- (TRN_chardata*)Current;
- (BOOL)HasNext;
- (id)init;
@end


@interface PTFilter : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)AttachFilter: (PTFilter*)attach_filter;
- (PTFilter*)ReleaseAttachedFilter;
- (PTFilter*)GetAttachedFilter;
- (PTFilter*)GetSourceFilter;
- (NSString *)GetName;
- (NSString *)GetDecodeName;
- (unsigned long)Size;
- (void)Consume: (unsigned long)num_bytes;
- (unsigned long)Count;
- (unsigned long)SetCount: (unsigned long)new_count;
- (void)SetStreamLength: (unsigned long)bytes;
- (void)Flush;
- (void)FlushAll;
- (BOOL)IsInputFilter;
- (BOOL)CanSeek;
- (void)Seek: (unsigned long long)offset origin:  (PTReferencePos)origin;
- (unsigned long long)Tell;
- (PTFilter*)CreateInputIterator;
- (NSString *)GetFilePath;
- (void)Destroy;
- (void)WriteToFile: (NSString *)path append:  (BOOL)append;
- (id)init;
@end


@interface PTASCII85Encode : PTFilter
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (id)initWithInput_filter: (PTFilter*)input_filter line_width:  (int)line_width buf_sz:  (unsigned long)buf_sz;
@end


@interface PTFilterReader : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (int)Get;
- (int)Peek;
- (NSData*)Read: (unsigned long)buf_size;
- (void)AttachFilter: (PTFilter*)filter;
- (PTFilter*)GetAttachedFilter;
- (void)Seek: (unsigned long long)offset origin:  (PTReferencePos)origin;
- (unsigned long long)Tell;
- (unsigned long)Count;
- (void)Flush;
- (void)FlushAll;
- (id)init;- (id)initWithFilter: (PTFilter*)filter;
@end


@interface PTFilterWriter : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)WriteUChar: (unsigned char)ch;
- (void)WriteInt16: (short)num;
- (void)WriteUInt16: (unsigned short)num;
- (void)WriteInt32: (int)num;
- (void)WriteUInt32: (unsigned int)num;
- (void)WriteInt64: (long long)num;
- (void)WriteUInt64: (unsigned long long)num;
- (void)WriteString: (NSString*)str;
- (void)WriteFilter: (PTFilterReader*)reader;
- (void)WriteLine: (NSString *)line eol:  (char)eol;
- (unsigned long)WriteBuffer: (NSData*)buf;
- (void)AttachFilter: (PTFilter*)filter;
- (PTFilter*)GetAttachedFilter;
- (void)Seek: (unsigned long long)offset origin:  (PTReferencePos)origin;
- (unsigned long long)Tell;
- (unsigned long)Count;
- (void)Flush;
- (void)FlushAll;
- (id)init;- (id)initWithFilter: (PTFilter*)filter;
@end


@interface PTFlateEncode : PTFilter
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (id)initWithInput_filter: (PTFilter*)input_filter compression_level:  (int)compression_level buf_sz:  (unsigned long)buf_sz;
@end


@interface PTMappedFile : PTFilter
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)isEqualTo: (PTMappedFile*)f;
+ (BOOL)Equivalent: (NSString *)ph1 ph2:  (NSString *)ph2;
- (unsigned long)FileSize;
- (id)initWithFilename: (NSString *)filename;
@end


@interface PTMemoryFilter : PTFilter
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (NSData*)GetBuffer;
- (void)SetAsInputFilter;
- (id)initWithBuf_sz: (unsigned long)buf_sz is_input:  (BOOL)is_input;
@end


@interface PTSDFDoc : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Close;
- (BOOL)IsEncrypted;
- (BOOL)InitSecurityHandler;
- (BOOL)InitStdSecurityHandler: (NSString *)password password_sz:  (int)password_sz;
- (BOOL)IsModified;
- (BOOL)HasRepairedXRef;
- (BOOL)IsFullSaveRequired;
- (PTObj*)GetTrailer;
- (PTObj*)GetObj: (unsigned int)obj_num;
- (PTObj*)ImportObj: (PTObj*)obj deep_copy:  (BOOL)deep_copy;
- (PTVectorObj*)ImportObjs: (PTVectorObj*)obj_list;
- (PTVectorObj*)ImportObjsWithExcludeList: (PTVectorObj*)obj_list exclude_list:  (PTVectorObj*)exclude_list;
- (unsigned int)XRefSize;
- (void)ClearMarks;
- (void)SaveSDFDocToFile: (NSString *)path flags:  (unsigned int)flags header:  (NSString *)header;
- (NSData*)SaveSDFDocToBuf: (unsigned int)flags header:  (NSString *)header;
- (void)Save: (PTFilter*)stream flags:  (unsigned int)flags header:  (NSString *)header;
- (NSString *)GetHeader;
- (PTSecurityHandler*)GetSecurityHandler;
- (void)SetSecurityHandler: (PTSecurityHandler*)handler;
- (void)RemoveSecurity;
- (void)Swap: (unsigned int)obj_num1 obj_num2:  (unsigned int)obj_num2;
- (PTObj*)CreateIndirectName: (NSString *)name;
- (PTObj*)CreateIndirectArray;
- (PTObj*)CreateIndirectBool: (BOOL)value;
- (PTObj*)CreateIndirectDict;
- (PTObj*)CreateIndirectNull;
- (PTObj*)CreateIndirectNumber: (double)value;
- (PTObj*)CreateIndirectString: (NSData*)value size:  (unsigned int)size;
- (PTObj*)CreateIndirectStringWithStr: (NSString *)str;
- (PTObj*)CreateIndirectStreamWithFilterReader: (PTFilterReader*)data filter_chain:  (PTFilter*)filter_chain;
- (PTObj*)CreateIndirectStream: (PTFilterReader*)data;
- (PTObj*)CreateIndirectStreamWithbuf: (NSString *)data data_size:  (unsigned long)data_size filter_chain:  (PTFilter*)filter_chain;
- (BOOL)IsLinearized;
- (PTObj*)GetLinearizationDict;
- (PTObj*)GetHintStream;
- (void)Lock;
- (void)Unlock;
- (BOOL)TryLock: (int)milliseconds;
- (void)LockRead;
- (void)UnlockRead;
- (BOOL)TryLockRead: (int)milliseconds;
- (NSString *)GetFileName;
- (void)EnableDiskCaching: (BOOL)use_cache_flag;
+ (PTSDFDoc*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)init;- (id)initWithFilepath: (NSString *)filepath;- (id)initWithStream: (PTFilter*)stream;- (id)initWithBuf: (NSData*)buf buf_size:  (unsigned long)buf_size;
@end


@interface PTObj : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTObjType)GetType;
- (BOOL)IsBool;
- (BOOL)IsNumber;
- (BOOL)IsNull;
- (BOOL)IsString;
- (BOOL)IsName;
- (BOOL)IsIndirect;
- (BOOL)IsContainer;
- (BOOL)IsDict;
- (BOOL)IsArray;
- (BOOL)IsStream;
- (PTSDFDoc*)GetDoc;
- (void)Write: (PTFilterWriter*)stream;
- (unsigned long)Size;
- (unsigned int)GetObjNum;
- (unsigned short)GetGenNum;
- (unsigned long)GetOffset;
- (BOOL)IsFree;
- (void)SetMark: (BOOL)mark;
- (BOOL)IsMarked;
- (BOOL)IsLoaded;
- (BOOL)IsValid;
- (BOOL)GetBool;
- (void)SetBool: (BOOL)b;
- (double)GetNumber;
- (void)SetNumber: (double)n;
- (NSData*)GetBuffer;
- (NSData*)GetRawBuffer;
- (NSString *)GetAsPDFText;
- (void)SetString: (NSData*)value size:  (unsigned long)size;
- (void)SetStringWithStr: (NSString *)str;
- (NSString *)GetName;
- (void)SetName: (NSString *)name;
- (PTDictIterator*)GetDictIterator;
- (PTDictIterator*)Find: (NSString *)key;
- (PTObj*)FindObj: (NSString *)key;
- (PTDictIterator*)Get: (NSString *)key;
- (PTObj*)PutName: (NSString *)key name:  (NSString *)name;
- (PTObj*)PutArray: (NSString *)key;
- (PTObj*)PutBool: (NSString *)key value:  (BOOL)value;
- (PTObj*)PutDict: (NSString *)key;
- (PTObj*)PutNumber: (NSString *)key value:  (double)value;
- (PTObj*)PutString: (NSString *)key value:  (NSString *)value;
- (PTObj*)PutStringWithSize: (NSString *)key value:  (NSString *)value size:  (int)size;
- (PTObj*)PutText: (NSString *)key value:  (NSString *)value;
- (void)PutNull: (NSString *)key;
- (PTObj*)Put: (NSString *)key obj:  (PTObj*)obj;
- (PTObj*)PutRect: (NSString *)key x1:  (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
- (PTObj*)PutMatrix: (NSString *)key value:  (PTMatrix2D*)value;
- (void)EraseDictElementWithKey: (NSString *)key;
- (void)EraseDictElementWithPos: (PTDictIterator*)pos;
- (BOOL)Rename: (NSString *)old_key new_key:  (NSString *)new_key;
- (PTObj*)GetAt: (unsigned long)index;
- (PTObj*)InsertName: (unsigned long)pos name:  (NSString *)name;
- (PTObj*)InsertArray: (unsigned long)pos;
- (PTObj*)InsertBool: (unsigned long)pos value:  (BOOL)value;
- (PTObj*)InsertDict: (unsigned long)pos;
- (PTObj*)InsertNumber: (unsigned long)pos value:  (double)value;
- (PTObj*)InsertString: (unsigned long)pos value:  (NSString *)value;
- (PTObj*)InsertStringWithSize: (unsigned long)pos value:  (NSString *)value size:  (int)size;
- (PTObj*)InsertText: (unsigned long)pos value:  (NSString *)value;
- (PTObj*)InsertNull: (unsigned long)pos;
- (PTObj*)Insert: (unsigned long)pos obj:  (PTObj*)obj;
- (PTObj*)InsertRect: (unsigned long)pos x1:  (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
- (PTObj*)InsertMatrix: (unsigned long)pos value:  (PTMatrix2D*)value;
- (PTObj*)PushBackName: (NSString *)name;
- (PTObj*)PushBackArray;
- (PTObj*)PushBackBool: (BOOL)value;
- (PTObj*)PushBackDict;
- (PTObj*)PushBackNumber: (double)value;
- (PTObj*)PushBackString: (NSString *)value;
- (PTObj*)PushBackStringWithSize: (NSString *)value size:  (int)size;
- (PTObj*)PushBackText: (NSString *)value;
- (PTObj*)PushBackNull;
- (PTObj*)PushBack: (PTObj*)obj;
- (PTObj*)PushBackRect: (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
- (PTObj*)PushBackMatrix: (PTMatrix2D*)value;
- (void)EraseAt: (unsigned long)pos;
- (unsigned long)GetRawStreamLength;
- (PTFilter*)GetRawStream: (BOOL)decrypt;
- (PTFilter*)GetDecodedStream;
- (void)SetStreamData: (NSString *)data data_size:  (unsigned long)data_size filter_chain:  (PTFilter*)filter_chain;
- (BOOL)IsEqual: (PTObj*)to;
- (BOOL)isEqualTo: (PTObj*)to;
+ (PTObj*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)init;
@end


@interface PTDictIterator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Next;
- (PTObj*)Key;
- (PTObj*)Value;
- (BOOL)HasNext;
- (void)Destroy;
- (id)initWithC: (PTDictIterator*)c;
@end


@interface PTSecurityHandler : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)GetPermission: (PTPermission)p;
- (int)GetKeyLength;
- (int)GetEncryptionAlgorithmID;
- (NSString *)GetHandlerDocName;
- (BOOL)IsModified;
- (BOOL)IsValid;
- (void)SetModified: (BOOL)is_modified;
- (void)ChangeUserPasswordASCII: (NSString *)password;
- (void)ChangeUserPasswordWithLength: (NSString *)password pwd_length:  (unsigned long)pwd_length;
- (void)ChangeUserPassword: (NSString *)password;
- (NSString *)GetUserPassword;
- (unsigned long)GetUserPasswordSize;
- (void)ChangeMasterPasswordASCII: (NSString *)password;
- (void)ChangeMasterPasswordWithLength: (NSString *)password pwd_length:  (unsigned long)pwd_length;
- (void)ChangeMasterPassword: (NSString *)password;
- (NSString *)GetMasterPassword;
- (unsigned long)GetMasterPasswordSize;
- (void)SetPermission: (PTPermission)perm value:  (BOOL)value;
- (void)ChangeRevisionNumber: (int)rev_num;
- (void)SetEncryptMetadata: (BOOL)encrypt_metadata;
- (int)GetRevisionNumber;
- (BOOL)IsUserPasswordRequired;
- (BOOL)IsMasterPasswordRequired;
- (BOOL)IsAES;
- (BOOL)IsAESWithStream: (PTObj*)stream;
- (BOOL)IsRC4;
- (void)AuthorizeFailed;
- (BOOL)Authorize: (PTPermission)p;
- (BOOL)GetAuthorizationData: (PTPermission)req_opr;
- (BOOL)EditSecurityData: (PTSDFDoc*)doc;
- (PTObj*)FillEncryptDict: (PTSDFDoc*)doc;
- (PTSecurityHandler*)Clone: (void *)base;
- (void)InitPasswordASCII: (NSString *)password;
- (void)InitPasswordWithLength: (NSString *)password pwd_length:  (unsigned long)pwd_length;
- (void)InitPassword: (NSString *)password;
- (void)SetDerived: (unsigned int)overloaded_funct;
- (PTSecurityHandler*)GetDerived;
- (id)initWithCrypt_type: (PTAlgorithmType)crypt_type;- (id)initWithName: (NSString *)name key_len:  (int)key_len enc_code:  (int)enc_code;- (id)init;
@end


@interface PTPDFTronCustomSecurityHandler : PTSecurityHandler
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (id)initWithCustom_id: (unsigned int)custom_id;
@end


@interface PTNameTree : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTNameTree*)Create: (PTSDFDoc*)doc name:  (NSString*)name;
+ (PTNameTree*)Find: (PTSDFDoc*)doc name:  (NSString*)name;
- (BOOL)IsValid;
- (PTDictIterator*)GetNameIteratorWithKey: (NSData*)key key_sz:  (int)key_sz;
- (PTDictIterator*)GetIterator;
- (PTObj*)GetValue: (NSData*)key key_sz:  (int)key_sz;
- (void)Put: (NSData*)key key_sz:  (int)key_sz value:  (PTObj*)value;
- (void)EraseNameTreeEntryWithKey: (NSData*)key key_sz:  (int)key_sz;
- (void)EraseNameTreeEntryWithPos: (PTDictIterator*)pos;
- (PTObj*)GetSDFObj;
- (id)initWithName_tree: (PTObj*)name_tree;
@end


@interface PTNumberTree : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsValid;
- (PTDictIterator*)GetNumberIteratorWithKey: (int)key;
- (PTDictIterator*)GetIterator;
- (PTObj*)GetValue: (int)key;
- (void)Put: (int)key value:  (PTObj*)value;
- (void)EraseNumberTreeEntryWithKey: (int)key;
- (void)EraseNumberTreeEntryWithPos: (PTDictIterator*)pos;
- (PTObj*)GetSDFObj;
- (id)initWithNumber_tree: (PTObj*)number_tree;
@end


@interface PTObjSet : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTObj*)CreateName: (NSString *)name;
- (PTObj*)CreateArray;
- (PTObj*)CreateBool: (BOOL)value;
- (PTObj*)CreateDict;
- (PTObj*)CreateNull;
- (PTObj*)CreateNumber: (double)value;
- (PTObj*)CreateString: (NSString *)value;
- (PTObj*)CreateFromJson: (NSString *)value;
- (void)Destroy;
- (id)init;
@end



@interface PTSignatureHandler : NSObject
{
    void* m_cPtr;
}
- (void*) getCptr;
- (void) unsetCPtr;
- (NSString*) GetName;
- (void) AppendData : (NSData*) data;
- (BOOL) Reset;
- (NSData*) CreateSignature;
- (instancetype) init;
- (instancetype) initWithCptr: (void*) cptr;
- (void) dealloc;
@end // @interface PTSignatureHandler



@interface PTSDFDocSnapshot : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (unsigned int)GetHash;
- (BOOL)IsValid;
- (BOOL)Equals: (PTSDFDocSnapshot*)snapshot;
- (id)initWithImpl: (void *)impl;
@end


@interface PTSDFResultSnapshot : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (PTSDFDocSnapshot*)CurrentState;
- (PTSDFDocSnapshot*)PreviousState;
- (BOOL)IsOk;
- (BOOL)IsNullTransition;
- (id)initWithImpl: (void *)impl;
@end


@interface PTSDFUndoManager : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (PTSDFDocSnapshot*)DiscardAllSnapshots;
- (PTSDFResultSnapshot*)Undo;
- (BOOL)CanUndo;
- (PTSDFDocSnapshot*)GetNextUndoSnapshot;
- (PTSDFResultSnapshot*)Redo;
- (BOOL)CanRedo;
- (PTSDFDocSnapshot*)GetNextRedoSnapshot;
- (PTSDFResultSnapshot*)TakeSnapshot;
- (id)initWithImpl: (void *)impl;
@end


@interface PTFunction : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTFunctionType)GetType;
- (int)GetInputCardinality;
- (int)GetOutputCardinality;
- (NSMutableArray*)Eval: (NSMutableArray*)in_arr;
- (PTObj*)GetSDFObj;
- (void)Destroy;
- (id)initWithFunct_dict: (PTObj*)funct_dict;
@end


@interface PTGeometryCollection : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (PTPDFPoint*)SnapToNearest: (double)x y:  (double)y mode:  (unsigned int)mode;
- (PTPDFPoint*)SnapToNearestPixel: (double)x y:  (double)y dpi:  (double)dpi mode:  (unsigned int)mode;
- (id)init;- (id)initWithOther: (PTGeometryCollection*)other;
@end


@interface PTColorPt : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)isEqualTo: (PTColorPt*)co;
- (void)Set: (double)x y:  (double)y z:  (double)z w:  (double)w;
- (void)SetTintWithIndex: (int)colorant_index colorant_value:  (double)colorant_value;
- (double)Get: (int)colorant_index;
- (void)SetColorantNum: (int)num;
- (void)Destroy;
- (id)initWithX: (double)x y:  (double)y z:  (double)z w:  (double)w;
@end


@interface PTColorSpace : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTColorSpace*)CreateDeviceGray;
+ (PTColorSpace*)CreateDeviceRGB;
+ (PTColorSpace*)CreateDeviceCMYK;
+ (PTColorSpace*)CreatePattern;
+ (PTColorSpace*)CreateICCWithString: (PTSDFDoc*)doc filepath:  (NSString *)filepath;
+ (PTColorSpace*)CreateICCWithStream: (PTSDFDoc*)doc stm:  (PTFilter*)stm;
+ (PTColorSpace*)CreateICCWithBuf: (PTSDFDoc*)doc buf:  (NSData*)buf buf_sz:  (unsigned long)buf_sz;
- (PTColorSpaceType)GetType;
- (PTObj*)GetSDFObj;
- (int)GetComponentNum;
- (void)InitColor: (PTColorPt*)out_colorants;
- (void)InitComponentRanges: (NSMutableArray*)out_decode_low out_decode_range:  (NSMutableArray*)out_decode_range;
- (PTColorPt*)Convert2Gray: (PTColorPt*)in_color;
- (PTColorPt*)Convert2RGB: (PTColorPt*)in_color;
- (PTColorPt*)Convert2CMYK: (PTColorPt*)in_color;
- (PTColorSpace*)GetAlternateColorSpace;
- (PTColorSpace*)GetBaseColorSpace;
- (int)GetHighVal;
- (PTColorPt*)GetBaseColor: (unsigned char)color_idx;
- (BOOL)IsNone;
- (BOOL)IsAll;
- (PTFunction*)GetTintFunction;
- (void)Destroy;
- (id)initWithColor_space: (PTObj*)color_space;
@end


@interface PTPDFRect : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Attach: (PTObj*)obj;
- (BOOL)Update: (PTObj*)obj;
- (void)Set: (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
- (double)Width;
- (double)Height;
- (BOOL)Contains: (double)x y:  (double)y;
- (BOOL)IntersectRect: (PTPDFRect*)rect1 rect2:  (PTPDFRect*)rect2;
- (void)Normalize;
- (void)InflateWithAmount: (double)amount;
- (void)InflateWithXY: (double)x y:  (double)y;
- (double)GetX1;
- (double)GetY1;
- (double)GetX2;
- (double)GetY2;
- (void)SetX1: (double)x1;
- (void)SetY1: (double)y1;
- (void)SetX2: (double)x2;
- (void)SetY2: (double)y2;
- (id)init;- (id)initWithRect: (PTObj*)rect;- (id)initWithX1: (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
@end


@interface PTPDFRectCollection : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)AddRect: (PTPDFRect*)to_add;
- (PTPDFRect*)GetRectAt: (unsigned long)index;
- (unsigned long)GetNumRects;
- (void)Clear;
- (id)init;
@end


@interface PTViewChangeCollection : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
+ (PTViewChangeCollection*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)init;
@end


@interface PTPage : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsValid;
- (int)GetIndex;
- (PTPDFRect*)GetBox: (PTBox)type;
- (void)SetBox: (PTBox)type box:  (PTPDFRect*)box;
- (PTPDFRect*)GetCropBox;
- (void)SetCropBox: (PTPDFRect*)box;
- (PTPDFRect*)GetMediaBox;
- (void)SetMediaBox: (PTPDFRect*)box;
- (PTPDFRect*)GetVisibleContentBox;
+ (PTRotate)AddRotations: (PTRotate)r0 r1:  (PTRotate)r1;
+ (PTRotate)SubtractRotations: (PTRotate)r0 r1:  (PTRotate)r1;
+ (int)RotationToDegree: (PTRotate)r;
+ (PTRotate)DegreeToRotation: (int)r;
- (PTRotate)GetRotation;
- (void)SetRotation: (PTRotate)angle;
- (double)GetPageWidth: (PTBox)box_type;
- (double)GetPageHeight: (PTBox)box_type;
- (PTMatrix2D*)GetDefaultMatrix: (BOOL)flip_y box_type:  (PTBox)box_type angle:  (PTRotate)angle;
- (PTObj*)GetAnnots;
- (unsigned int)GetNumAnnots;
- (PTAnnot*)GetAnnot: (unsigned int)index;
- (PTObj*)GetTriggerAction: (PTPageActionTriggerEvent)trigger;
- (void)AnnotInsert: (unsigned int)pos annot:  (PTAnnot*)annot;
- (void)AnnotPushBack: (PTAnnot*)annot;
- (void)AnnotPushFront: (PTAnnot*)annot;
- (void)AnnotRemoveWithAnnot: (PTAnnot*)annot;
- (void)AnnotRemoveWithIndex: (unsigned int)index;
- (void)Scale: (double)scale;
- (void)FlattenField: (PTField*)field_to_flatten;
- (BOOL)HasTransition;
- (double)GetUserUnitSize;
- (void)SetUserUnitSize: (double)unit_size;
- (PTObj*)GetResourceDict;
- (PTObj*)GetContents;
- (PTObj*)GetSDFObj;
- (PTObj*)FindInheritedAttribute: (NSString *)attrib;
- (PTObj*)GetThumb;
- (id)initWithPage_dict: (PTObj*)page_dict;
@end


@interface PTPageIterator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)Next;
- (PTPage*)Current;
- (BOOL)HasNext;
- (id)init;
@end


@interface PTDate : TRN_date
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsValid;
- (void)SetCurrentTime;
- (void)Attach: (PTObj*)d;
- (BOOL)Update: (PTObj*)d;
- (unsigned short)GetYear;
- (unsigned char)GetMonth;
- (unsigned char)GetDay;
- (unsigned char)GetHour;
- (unsigned char)GetMinute;
- (unsigned char)GetSecond;
- (unsigned char)GetUT;
- (unsigned char)GetUTHour;
- (unsigned char)GetUTMin;
- (id)init;- (id)initWithD: (PTObj*)d;- (id)initWithYear: (unsigned short)year month:  (char)month day:  (char)day hour:  (char)hour minute:  (char)minute second:  (char)second;
@end


@interface PTGState : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTMatrix2D*)GetTransform;
- (PTColorSpace*)GetStrokeColorSpace;
- (PTColorSpace*)GetFillColorSpace;
- (PTColorPt*)GetStrokeColor;
- (PTPatternColor*)GetStrokePattern;
- (PTColorPt*)GetFillColor;
- (PTPatternColor*)GetFillPattern;
- (double)GetFlatness;
- (PTLineCap)GetLineCap;
- (PTLineJoin)GetLineJoin;
- (double)GetLineWidth;
- (double)GetMiterLimit;
- (NSMutableArray*)GetDashes;
- (double)GetPhase;
- (double)GetCharSpacing;
- (double)GetWordSpacing;
- (double)GetHorizontalScale;
- (double)GetLeading;
- (PTFont*)GetFont;
- (double)GetFontSize;
- (PTTextRenderingMode)GetTextRenderMode;
- (double)GetTextRise;
- (BOOL)IsTextKnockout;
- (PTRenderingIntent)GetRenderingIntent;
+ (PTRenderingIntent)GetRenderingIntentType: (NSString *)name;
- (PTBlendMode)GetBlendMode;
- (double)GetFillOpacity;
- (double)GetStrokeOpacity;
- (BOOL)GetAISFlag;
- (PTObj*)GetSoftMask;
- (PTMatrix2D*)GetSoftMaskTransform;
- (BOOL)GetStrokeOverprint;
- (BOOL)GetFillOverprint;
- (int)GetOverprintMode;
- (BOOL)GetAutoStrokeAdjust;
- (double)GetSmoothnessTolerance;
- (PTObj*)GetTransferFunct;
- (PTObj*)GetBlackGenFunct;
- (PTObj*)GetUCRFunct;
- (PTObj*)GetHalftone;
- (void)SetTransformWithMatrix: (PTMatrix2D*)mtx;
- (void)SetTransform: (double)a b:  (double)b c:  (double)c d:  (double)d h:  (double)h v:  (double)v;
- (void)ConcatWithMatrix: (PTMatrix2D*)mtx;
- (void)Concat: (double)a b:  (double)b c:  (double)c d:  (double)d h:  (double)h v:  (double)v;
- (void)SetStrokeColorSpace: (PTColorSpace*)cs;
- (void)SetFillColorSpace: (PTColorSpace*)cs;
- (void)SetStrokeColorWithColorPt: (PTColorPt*)c;
- (void)SetStrokeColorWithPattern: (PTPatternColor*)pattern;
- (void)SetStrokeColorWithPatternAndColorPt: (PTPatternColor*)pattern c:  (PTColorPt*)c;
- (void)SetFillColorWithColorPt: (PTColorPt*)c;
- (void)SetFillColorWithPattern: (PTPatternColor*)pattern;
- (void)SetFillColorWithPatternAndColorPt: (PTPatternColor*)pattern c:  (PTColorPt*)c;
- (void)SetFlatness: (double)flatness;
- (void)SetLineCap: (PTLineCap)cap;
- (void)SetLineJoin: (PTLineJoin)join;
- (void)SetLineWidth: (double)width;
- (void)SetMiterLimit: (double)miter_limit;
- (void)SetDashPattern: (NSMutableArray*)dash_array phase:  (double)phase;
- (void)SetCharSpacing: (double)char_spacing;
- (void)SetWordSpacing: (double)word_spacing;
- (void)SetHorizontalScale: (double)hscale;
- (void)SetLeading: (double)leading;
- (void)SetFont: (PTFont*)font font_sz:  (double)font_sz;
- (void)SetTextRenderMode: (PTTextRenderingMode)rmode;
- (void)SetTextRise: (double)rise;
- (void)SetTextKnockout: (BOOL)knockout;
- (void)SetRenderingIntent: (PTRenderingIntent)intent;
- (void)SetBlendMode: (PTBlendMode)BM;
- (void)SetFillOpacity: (double)ca;
- (void)SetStrokeOpacity: (double)ca;
- (void)SetAISFlag: (BOOL)AIS;
- (void)SetSoftMask: (PTObj*)SM;
- (void)SetStrokeOverprint: (BOOL)OP;
- (void)SetFillOverprint: (BOOL)op;
- (void)SetOverprintMode: (int)OPM;
- (void)SetAutoStrokeAdjust: (BOOL)SA;
- (void)SetSmoothnessTolerance: (double)SM;
- (void)SetBlackGenFunct: (PTObj*)BG;
- (void)SetUCRFunct: (PTObj*)UCR;
- (void)SetTransferFunct: (PTObj*)TR;
- (void)SetHalftone: (PTObj*)HT;
- (id)init;
@end


@interface PTImage : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTImage*)CreateWithFile: (PTSDFDoc*)doc filename:  (NSString *)filename encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)Create: (PTSDFDoc*)doc filename:  (NSString *)filename;
+ (PTImage*)CreateWithData: (PTSDFDoc*)doc buf:  (NSData*)buf buf_size:  (unsigned long)buf_size width:  (int)width height:  (int)height bpc:  (int)bpc color_space:  (PTColorSpace*)color_space encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)CreateWithFilterData: (PTSDFDoc*)doc image_data:  (PTFilterReader*)image_data width:  (int)width height:  (int)height bpc:  (int)bpc color_space:  (PTColorSpace*)color_space encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)CreateWithDataSimple: (PTSDFDoc*)doc buf:  (NSData*)buf buf_size:  (unsigned long)buf_size encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)CreateWithFilterDataSimple: (PTSDFDoc*)doc image_data:  (PTFilter*)image_data encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)CreateImageMaskWithBuffer: (PTSDFDoc*)doc buf:  (NSString *)buf buf_size:  (unsigned long)buf_size width:  (int)width height:  (int)height encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)CreateImageMask: (PTSDFDoc*)doc buf:  (NSString *)buf buf_size:  (unsigned long)buf_size width:  (int)width height:  (int)height;
+ (PTImage*)CreateImageMaskWithStream: (PTSDFDoc*)doc image_data:  (PTFilterReader*)image_data width:  (int)width height:  (int)height encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)CreateSoftMaskWithBuffer: (PTSDFDoc*)doc buf:  (NSString *)buf buf_size:  (unsigned long)buf_size width:  (int)width height:  (int)height bpc:  (int)bpc encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)CreateSoftMask: (PTSDFDoc*)doc buf:  (NSString *)buf buf_size:  (unsigned long)buf_size width:  (int)width height:  (int)height bpc:  (int)bpc;
+ (PTImage*)CreateSoftMaskWithStream: (PTSDFDoc*)doc image_data:  (PTFilterReader*)image_data width:  (int)width height:  (int)height bpc:  (int)bpc encoder_hints:  (PTObj*)encoder_hints;
+ (PTImage*)CreateWithStreamAndFormat: (PTSDFDoc*)doc image_data:  (PTFilterReader*)image_data width:  (int)width height:  (int)height bpc:  (int)bpc color_space:  (PTColorSpace*)color_space input_format:  (PTInputFilter)input_format;
- (PTObj*)GetSDFObj;
- (BOOL)IsValid;
- (PTFilter*)GetImageData;
- (int)GetImageDataSize;
- (PTColorSpace*)GetImageColorSpace;
- (int)GetImageWidth;
- (int)GetImageHeight;
- (PTObj*)GetDecodeArray;
- (int)GetBitsPerComponent;
- (int)GetComponentNum;
- (BOOL)IsImageMask;
- (BOOL)IsImageInterpolate;
- (PTObj*)GetMask;
- (void)SetMaskWithImage: (PTImage*)image_mask;
- (void)SetMaskWithColor: (PTObj*)mask;
- (PTObj*)GetSoftMask;
- (void)SetSoftMask: (PTImage*)soft_mask;
- (PTRenderingIntent)GetImageRenderingIntent;
- (int)ExportToFile: (NSString *)filename;
- (int)ExportToStream: (PTFilterWriter*)writer;
- (void)ExportAsTiffFile: (NSString *)filename;
- (void)ExportAsTiffStream: (PTFilterWriter*)writer;
- (void)ExportAsPngFile: (NSString *)filename;
- (void)ExportAsPngStream: (PTFilterWriter*)writer;
- (id)initWithImage_xobject: (PTObj*)image_xobject;
@end


@interface PTField : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsValid;
- (PTFieldType)GetType;
- (PTObj*)GetValue;
- (NSString *)GetValueAsString;
- (BOOL)GetValueAsBool;
- (PTViewChangeCollection*)SetValueWithString: (NSString *)value;
- (PTViewChangeCollection*)SetValueWithObj: (PTObj*)value;
- (PTViewChangeCollection*)SetValueWithBool: (BOOL)value;
- (PTObj*)GetTriggerAction: (PTFieldActionTriggerEvent)trigger;
- (void)RefreshAppearance;
- (void)EraseAppearance;
- (PTObj*)GetDefaultValue;
- (NSString *)GetDefaultValueAsString;
- (NSString *)GetName;
- (NSString *)GetPartialName;
- (void)Rename: (NSString *)field_name;
- (BOOL)IsAnnot;
- (BOOL)GetFlag: (PTFieldFlag)flag;
- (void)SetFlag: (PTFieldFlag)flag value:  (BOOL)value;
- (PTTextJustification)GetJustification;
- (void)SetJustification: (PTTextJustification)j;
- (void)SetMaxLen: (int)max_len;
- (int)GetOptCount;
- (NSString *)GetOpt: (int)index;
- (int)GetMaxLen;
- (PTGState*)GetDefaultAppearance;
- (void)Flatten: (PTPage*)page;
- (PTPDFRect*)GetUpdateRect;
- (PTObj*)FindInheritedAttribute: (NSString *)attrib;
- (PTObj*)GetSDFObj;
- (void)Destroy;
- (PTObj*)UseSignatureHandler: (unsigned long)signature_handler_id;
- (BOOL)IsLockedByDigitalSignature;
- (id)initWithField_dict: (PTObj*)field_dict;
@end


@interface PTFieldIterator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)Next;
- (PTField*)Current;
- (BOOL)HasNext;
- (id)init;
@end


@interface PTObjectIdentifier : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (NSArray<NSNumber *> *)GetRawValue;
- (id)initWithIn_oid_enum: (PTPredefined)in_oid_enum;
@end


@interface PTX501AttributeTypeAndValue : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (PTObjectIdentifier*)GetAttributeTypeOID;
- (NSString *)GetStringValue;
- (id)init;
@end


@interface PTX501DistinguishedName : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (BOOL)HasAttribute: (PTObjectIdentifier*)in_oid;
- (NSArray<NSString *> *)GetStringValuesForAttribute: (PTObjectIdentifier*)in_oid;
- (NSArray<PTX501AttributeTypeAndValue *> *)GetAllAttributesAndValues;
- (id)init;
@end


@interface PTX509Extension : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (BOOL)IsCritical;
- (PTObjectIdentifier*)GetObjectIdentifier;
- (NSString *)ToString;
- (NSData*)GetData;
- (id)init;
@end


@interface PTX509Certificate : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (PTX501DistinguishedName*)GetIssuerField;
- (PTX501DistinguishedName*)GetSubjectField;
- (long long)GetNotBeforeEpochTime;
- (long long)GetNotAfterEpochTime;
- (unsigned int)GetRawX509VersionNumber;
- (NSString *)ToString;
- (NSString *)GetFingerprint: (PTDigestAlgorithmType)in_digest_algorithm;
- (NSData*)GetSerialNumber;
- (NSArray<PTX509Extension *> *)GetExtensions;
- (NSData*)GetData;
- (id)init;
@end


@interface PTDisallowedChange : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (unsigned int)GetObjNum;
- (PTDisallowedChangeType)GetType;
- (NSString *)GetTypeAsString;
- (id)init;
@end


@interface PTFDFField : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTObj*)GetValue;
- (void)SetValue: (PTObj*)value;
- (NSString *)GetName;
- (NSString *)GetPartialName;
- (PTObj*)GetSDFObj;
- (PTObj*)FindAttribute: (NSString *)attrib;
- (id)initWithField_dict: (PTObj*)field_dict fdf_dict:  (PTObj*)fdf_dict;
@end


@interface PTFDFFieldIterator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)Next;
- (PTFDFField*)Current;
- (BOOL)HasNext;
- (id)init;
@end


@interface PTFDFDoc : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Close;
- (BOOL)IsModified;
- (void)SaveFDFDocToFile: (NSString *)path;
- (NSData*)SaveFDFDocToBuf;
- (PTObj*)GetTrailer;
- (PTObj*)GetRoot;
- (PTObj*)GetFDF;
- (NSString *)GetPDFFileName;
- (void)SetPDFFileName: (NSString *)filepath;
- (PTObj*)GetID;
- (void)SetID: (PTObj*)id;
- (PTFDFFieldIterator*)GetFieldIterator;
- (PTFDFFieldIterator*)GetFieldIteratorWithFieldName: (NSString *)field_name;
- (PTFDFField*)GetField: (NSString *)field_name;
- (PTFDFField*)FieldCreateWithObj: (NSString *)field_name type:  (PTFieldType)type field_value:  (PTObj*)field_value;
- (PTFDFField*)FieldCreate: (NSString *)field_name type:  (PTFieldType)type;
- (PTFDFField*)FieldCreateWithString: (NSString *)field_name type:  (PTFieldType)type field_value:  (NSString *)field_value;
- (PTSDFDoc*)GetSDFDoc;
+ (PTFDFDoc*)CreateFromXFDF: (NSString *)file_name;
- (void)SaveAsXFDF: (NSString *)filepath;
- (NSString *)SaveAsXFDFToString;
- (void)MergeAnnots: (NSString *)command_file permitted_user:  (NSString *)permitted_user;
- (id)init;- (id)initWithSdfdoc: (PTSDFDoc*)sdfdoc;- (id)initWithFilepath: (NSString *)filepath;- (id)initWithStream: (PTFilter*)stream;
@end


@interface PTVerificationOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)AddTrustedCertificateWithBuf: (NSData*)in_certificate_buf in_buf_size:  (unsigned long)in_buf_size in_trust_flags:  (unsigned short)in_trust_flags;
- (void)AddTrustedCertificate: (NSData*)in_certificate_buf in_buf_size:  (unsigned long)in_buf_size;
- (void)AddTrustedCertificateWithFilePath: (NSString *)in_filepath in_trust_flags:  (unsigned short)in_trust_flags;
- (void)AddTrustedCertificates: (NSData*)in_P7C_binary_DER_certificates_file_data in_size:  (unsigned long)in_size;
- (void)LoadTrustList: (PTFDFDoc*)in_fdf_cert_exchange_data;
- (void)EnableModificationVerification: (BOOL)in_on_or_off;
- (void)EnableDigestVerification: (BOOL)in_on_or_off;
- (void)EnableTrustVerification: (BOOL)in_on_or_off;
- (void)EnableOnlineCRLRevocationChecking: (BOOL)in_on_or_off;
- (void)EnableOnlineOCSPRevocationChecking: (BOOL)in_on_or_off;
- (void)EnableOnlineRevocationChecking: (BOOL)in_on_or_off;
- (id)initWithImpl: (void *)impl;- (id)initWithLevel: (PTVerificationOptionsSecurityLevel)level;
@end


@interface PTTrustVerificationResult : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (BOOL)WasSuccessful;
- (NSString *)GetResultString;
- (long long)GetTimeOfTrustVerification;
- (PTVerificationOptionsTimeMode)GetTimeOfTrustVerificationEnum;
- (BOOL)HasEmbeddedTimestampVerificationResult;
- (PTEmbeddedTimestampVerificationResult*)GetEmbeddedTimestampVerificationResult;
- (NSArray<PTX509Certificate *> *)GetCertPath;
- (id)init;
@end


@interface PTVerificationResult : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (BOOL)GetVerificationStatus;
- (PTVerificationResultDocumentStatus)GetDocumentStatus;
- (PTVerificationResultDigestStatus)GetDigestStatus;
- (PTVerificationResultTrustStatus)GetTrustStatus;
- (PTVerificationResultModificationPermissionsStatus)GetPermissionsStatus;
- (BOOL)HasTrustVerificationResult;
- (PTTrustVerificationResult*)GetTrustVerificationResult;
- (NSArray<PTDisallowedChange *> *)GetDisallowedChanges;
- (PTDigestAlgorithmType)GetDigestAlgorithm;
- (NSString *)GetDocumentStatusAsString;
- (NSString *)GetDigestStatusAsString;
- (NSString *)GetTrustStatusAsString;
- (NSString *)GetPermissionsStatusAsString;
- (NSArray<NSString *> *)GetUnsupportedFeatures;
- (id)init;
@end


@interface PTEmbeddedTimestampVerificationResult : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (BOOL)GetVerificationStatus;
- (PTVerificationResultDigestStatus)GetCMSDigestStatus;
- (PTVerificationResultDigestStatus)GetMessageImprintDigestStatus;
- (PTVerificationResultTrustStatus)GetTrustStatus;
- (NSString *)GetCMSDigestStatusAsString;
- (NSString *)GetMessageImprintDigestStatusAsString;
- (NSString *)GetTrustStatusAsString;
- (BOOL)HasTrustVerificationResult;
- (PTTrustVerificationResult*)GetTrustVerificationResult;
- (PTDigestAlgorithmType)GetCMSSignatureDigestAlgorithm;
- (PTDigestAlgorithmType)GetMessageImprintDigestAlgorithm;
- (NSArray<NSString *> *)GetUnsupportedFeatures;
- (id)init;
@end


@interface PTTimestampingTestResult : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (BOOL)GetStatus;
- (NSString *)GetString;
- (BOOL)HasResponseVerificationResult;
- (PTEmbeddedTimestampVerificationResult*)GetResponseVerificationResult;
- (id)init;
@end


@interface PTTimestampingConfiguration : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)SetTimestampAuthorityServerURL: (NSString *)in_url;
- (void)SetTimestampAuthorityServerUsername: (NSString *)in_username;
- (void)SetTimestampAuthorityServerPassword: (NSString *)in_password;
- (void)SetUseNonce: (BOOL)in_use_nonce;
- (PTTimestampingTestResult*)TestConfiguration: (PTVerificationOptions*)in_opts;
- (id)initWithIn_url: (NSString *)in_url;- (id)init;
@end


@interface PTDigestAlgorithm : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (id)init;
@end


@interface PTDigitalSignatureField : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)HasCryptographicSignature;
- (PTDigitalSignatureFieldSubFilterType)GetSubFilter;
- (NSString *)GetSignatureName;
- (PTDate*)GetSigningTime;
- (NSString *)GetLocation;
- (NSString *)GetReason;
- (NSString *)GetContactInfo;
- (NSData*)GetCert: (unsigned int)in_index;
- (unsigned int)GetCertCount;
- (BOOL)HasVisibleAppearance;
- (void)SetContactInfo: (NSString *)in_contact_info;
- (void)SetLocation: (NSString *)in_location;
- (void)SetReason: (NSString *)in_reason;
- (void)SetFieldPermissions: (PTDigitalSignatureFieldFieldPermissions)in_action in_field_names:  (NSArray<NSString *> *)in_field_names;
- (void)SetDocumentPermissions: (PTDigitalSignatureFieldDocumentPermissions)in_perms;
- (void)SignOnNextSave: (NSString *)in_pkcs12_keyfile_path in_password:  (NSString *)in_password;
- (void)SignOnNextSaveWithCustomHandler: (unsigned long)in_signature_handler_id;
- (void)CertifyOnNextSave: (NSString *)in_pkcs12_keyfile_path in_password:  (NSString *)in_password;
- (void)CertifyOnNextSaveWithCustomHandler: (unsigned long)in_signature_handler_id;
- (PTObj*)GetSDFObj;
- (BOOL)IsLockedByDigitalSignature;
- (NSArray<NSString *> *)GetLockedFields;
- (PTDigitalSignatureFieldDocumentPermissions)GetDocumentPermissions;
- (void)ClearSignature;
- (PTVerificationResult*)Verify: (PTVerificationOptions*)in_opts;
- (BOOL)IsCertification;
- (PTX509Certificate*)GetSignerCertFromCMS;
- (NSArray<PTByteRange *> *)GetByteRanges;
- (NSArray<NSArray<PTX509Certificate *> *> *)GetCertPathsFromCMS;
- (BOOL)EnableLTVOfflineVerification: (PTVerificationResult*)in_verification_result;
- (void)TimestampOnNextSave: (PTTimestampingConfiguration*)in_timestamping_config in_timestamp_response_verification_options:  (PTVerificationOptions*)in_timestamp_response_verification_options;
- (void)UseSubFilter: (PTDigitalSignatureFieldSubFilterType)in_subfilter_type in_make_mandatory:  (BOOL)in_make_mandatory;
- (id)initWithIn_field: (PTField*)in_field;
@end


@interface PTDigitalSignatureFieldIterator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)Next;
- (PTDigitalSignatureField*)Current;
- (BOOL)HasNext;
- (id)init;
@end


@interface PTFileSpec : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTFileSpec*)Create: (PTSDFDoc*)doc path:  (NSString *)path embed:  (BOOL)embed;
+ (PTFileSpec*)CreateURL: (PTSDFDoc*)doc url:  (NSString *)url;
- (BOOL)isEqualTo: (PTFileSpec*)d;
- (BOOL)IsValid;
- (BOOL)Export: (NSString *)save_as;
- (PTFilter*)GetFileData;
- (NSString *)GetFilePath;
- (void)SetDesc: (NSString *)desc;
- (PTObj*)GetSDFObj;
- (id)initWithF: (PTObj*)f;
@end


@interface PTRefreshOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)GetDrawBackgroundOnly;
- (PTRefreshOptions*)SetDrawBackgroundOnly: (BOOL)value;
- (BOOL)GetRefreshExisting;
- (PTRefreshOptions*)SetRefreshExisting: (BOOL)value;
- (BOOL)GetUseNonStandardRotation;
- (PTRefreshOptions*)SetUseNonStandardRotation: (BOOL)value;
- (BOOL)GetUseRoundedCorners;
- (PTRefreshOptions*)SetUseRoundedCorners: (BOOL)value;
- (id)init;
@end


@interface PTAnnot : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTAnnot*)Create: (PTSDFDoc*)doc type:  (PTAnnotType)type pos:  (PTPDFRect*)pos;
- (BOOL)isEqualTo: (PTAnnot*)d;
- (BOOL)IsValid;
- (PTObj*)GetSDFObj;
- (PTAnnotType)GetType;
- (PTPDFRect*)GetRect;
- (PTPDFRect*)GetVisibleContentBox;
- (BOOL)IsMarkup;
- (void)SetRect: (PTPDFRect*)pos;
- (PTPage*)GetPage;
- (void)SetPage: (PTPage*)page;
- (PTObj*)GetUniqueID;
- (void)SetUniqueID: (NSString *)id id_buf_sz:  (int)id_buf_sz;
- (PTDate*)GetDate;
- (void)SetDate: (PTDate*)date;
- (BOOL)GetFlag: (PTAnnotFlag)flag;
- (void)SetFlag: (PTAnnotFlag)flag value:  (BOOL)value;
- (PTObj*)GetTriggerAction: (PTAnnotActionTriggerEvent)trigger;
- (PTBorderStyle*)GetBorderStyle;
- (void)SetBorderStyle: (PTBorderStyle*)bs oldStyleOnly:  (BOOL)oldStyleOnly;
- (PTObj*)GetAppearance: (PTAnnotationState)annot_state app_state:  (NSString *)app_state;
- (void)SetAppearance: (PTObj*)app_stream annot_state:  (PTAnnotationState)annot_state app_state:  (NSString *)app_state;
- (void)RemoveAppearance: (PTAnnotationState)annot_state app_state:  (NSString *)app_state;
- (void)Flatten: (PTPage*)page;
- (NSString *)GetActiveAppearanceState;
- (void)SetActiveAppearanceState: (NSString *)astate;
- (PTColorPt*)GetColorAsRGB;
- (PTColorPt*)GetColorAsCMYK;
- (PTColorPt*)GetColorAsGray;
- (int)GetColorCompNum;
- (void)SetColor: (PTColorPt*)col numcomp:  (int)numcomp;
- (int)GetStructParent;
- (void)SetStructParent: (int)parkeyval;
- (PTObj*)GetOptionalContent;
- (void)SetOptionalContent: (PTObj*)content;
- (void)SetContents: (NSString *)contents;
- (NSString *)GetContents;
- (int)GetRotation;
- (void)SetRotation: (int)angle;
- (void)RefreshAppearance;
- (void)RefreshAppearanceWithOptions: (PTRefreshOptions*)options;
- (NSString *)GetCustomData: (NSString *)key;
- (void)SetCustomData: (NSString *)key value:  (NSString *)value;
- (void)DeleteCustomData: (NSString *)key;
- (void)Resize: (PTPDFRect*)newrect;
+ (PTAnnot*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)initWithD: (PTObj*)d;
@end


@interface PTBorderStyle : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (PTBdStyle)GetStyle;
- (void)SetStyle: (PTBdStyle)style;
- (double)GetHR;
- (void)SetHR: (double)horizontal_radius;
- (double)GetVR;
- (void)SetVR: (double)vertical_radius;
- (double)GetWidth;
- (void)SetWidth: (double)width;
- (NSMutableArray*)GetDash;
- (void)SetDash: (NSMutableArray*)dash;
- (id)initWithS: (PTBdStyle)s b_width:  (double)b_width b_hr:  (double)b_hr b_vr:  (double)b_vr;- (id)initWithS: (PTBdStyle)s b_width:  (double)b_width b_hr:  (double)b_hr b_vr:  (double)b_vr b_dash:  (NSMutableArray*)b_dash;
@end


@interface PTPopup : PTAnnot
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTPopup*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (PTAnnot*)GetParent;
- (void)SetParent: (PTAnnot*)parent;
- (BOOL)IsOpen;
- (void)SetOpen: (BOOL)is_open;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTMarkup : PTAnnot
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (NSString *)GetTitle;
- (void)SetTitle: (NSString *)title;
- (PTPopup*)GetPopup;
- (void)SetPopup: (PTPopup*)ppup;
- (double)GetOpacity;
- (void)SetOpacity: (double)op;
- (NSString *)GetSubject;
- (void)SetSubject: (NSString *)contents;
- (PTDate*)GetCreationDates;
- (void)SetCreationDates: (PTDate*)dt;
- (PTBorderEffect)GetBorderEffect;
- (void)SetBorderEffect: (PTBorderEffect)effect;
- (double)GetBorderEffectIntensity;
- (void)SetBorderEffectIntensity: (double)intensity;
- (PTColorPt*)GetInteriorColor;
- (int)GetInteriorColorCompNum;
- (void)SetInteriorColor: (PTColorPt*)c CompNum:  (int)CompNum;
- (PTPDFRect*)GetContentRect;
- (void)SetContentRect: (PTPDFRect*)cr;
- (PTPDFRect*)GetPadding;
- (void)SetPaddingWithRect: (PTPDFRect*)rd;
- (void)SetPadding: (double)x;
- (void)RotateAppearance: (double)angle;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTFileAttachment : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTFileAttachment*)CreateFileAttchWithFileSpec: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos fs:  (PTFileSpec*)fs icon_name:  (PTFileIcon)icon_name;
+ (PTFileAttachment*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos fs:  (PTFileSpec*)fs;
+ (PTFileAttachment*)CreateFileAttchWithPath: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos path:  (NSString *)path icon_name:  (PTFileIcon)icon_name;
+ (PTFileAttachment*)CreateFileAttchWithIconName: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos path:  (NSString *)path icon_name:  (NSString *)icon_name;
- (PTFileSpec*)GetFileSpec;
- (void)SetFileSpec: (PTFileSpec*)file;
- (BOOL)Export: (NSString *)save_as;
- (PTFileIcon)GetIcon;
- (void)SetIcon: (PTFileIcon)type;
- (NSString *)GetIconName;
- (void)SetIconName: (NSString *)iname;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTQuadPoint : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setP1: (PTPDFPoint*)value;
- (PTPDFPoint*)getP1;
- (void)setP2: (PTPDFPoint*)value;
- (PTPDFPoint*)getP2;
- (void)setP3: (PTPDFPoint*)value;
- (PTPDFPoint*)getP3;
- (void)setP4: (PTPDFPoint*)value;
- (PTPDFPoint*)getP4;
- (id)init;- (id)initWithP11: (PTPDFPoint*)p11 p22:  (PTPDFPoint*)p22 p33:  (PTPDFPoint*)p33 p44:  (PTPDFPoint*)p44;- (id)initWithR: (PTPDFRect*)r;
@end


@interface PTTextMarkup : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (int)GetQuadPointCount;
- (PTQuadPoint*)GetQuadPoint: (int)idx;
- (void)SetQuadPoint: (int)idx qp:  (PTQuadPoint*)qp;
- (id)initWithD: (PTObj*)d;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTInk : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTInk*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (int)GetPathCount;
- (int)GetPointCount: (unsigned int)pathindex;
- (PTPDFPoint*)GetPoint: (unsigned int)pathindex pointindex:  (unsigned int)pointindex;
- (void)SetPoint: (unsigned int)pathindex pointindex:  (unsigned int)pointindex pt:  (PTPDFPoint*)pt;
- (BOOL)Erase: (PTPDFPoint*)pt1 pt2:  (PTPDFPoint*)pt2 width:  (double)width;
- (BOOL)GetHighlightIntent;
- (void)SetHighlightIntent: (BOOL)highlight;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTDestination : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTDestination*)CreateXYZ: (PTPage*)page left:  (double)left top:  (double)top zoom:  (double)zoom;
+ (PTDestination*)CreateFit: (PTPage*)page;
+ (PTDestination*)CreateFitH: (PTPage*)page top:  (double)top;
+ (PTDestination*)CreateFitV: (PTPage*)page left:  (double)left;
+ (PTDestination*)CreateFitR: (PTPage*)page left:  (double)left bottom:  (double)bottom right:  (double)right top:  (double)top;
+ (PTDestination*)CreateFitB: (PTPage*)page;
+ (PTDestination*)CreateFitBH: (PTPage*)page top:  (double)top;
+ (PTDestination*)CreateFitBV: (PTPage*)page left:  (double)left;
- (BOOL)IsValid;
- (PTFitType)GetFitType;
- (PTPage*)GetPage;
- (void)SetPage: (PTPage*)page;
- (PTObj*)GetSDFObj;
- (PTObj*)GetExplicitDestObj;
- (id)initWithDest: (PTObj*)dest;
@end


@interface PTDiffOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)GetAddGroupAnnots;
- (PTDiffOptions*)SetAddGroupAnnots: (BOOL)value;
- (PTBlendMode)GetBlendMode;
- (PTDiffOptions*)SetBlendMode: (PTBlendMode)value;
- (PTColorPt*)GetColorA;
- (PTDiffOptions*)SetColorA: (PTColorPt*)value;
- (PTColorPt*)GetColorB;
- (PTDiffOptions*)SetColorB: (PTColorPt*)value;
- (id)init;
@end


@interface PTKeyStrokeEventData : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (id)initWithField_name: (NSString *)field_name current_value:  (NSString *)current_value change:  (NSString *)change selection_start:  (int)selection_start selection_end:  (int)selection_end;
@end


@interface PTKeyStrokeActionResult : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsValid;
- (NSString *)GetText;
- (void)Destroy;
- (id)initWithAction_result: (PTKeyStrokeActionResult*)action_result;
@end


@interface PTAction : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTAction*)CreateGoto: (PTDestination*)dest;
+ (PTAction*)CreateGotoWithNamedDestination: (NSData*)key key_sz:  (int)key_sz dest:  (PTDestination*)dest;
+ (PTAction*)CreateGotoRemote: (PTFileSpec*)file page_num:  (int)page_num;
+ (PTAction*)CreateGotoRemoteWithNewWindow: (PTFileSpec*)file page_num:  (int)page_num new_window:  (BOOL)new_window;
+ (PTAction*)CreateURI: (PTSDFDoc*)doc uri:  (NSString *)uri;
+ (PTAction*)CreateSubmitForm: (PTFileSpec*)url;
+ (PTAction*)CreateLaunch: (PTSDFDoc*)doc path:  (NSString *)path;
+ (PTAction*)CreateHideField: (PTSDFDoc*)sdfdoc list_length:  (int)list_length field:  (NSMutableArray*)field;
+ (PTAction*)CreateImportData: (PTSDFDoc*)doc path:  (NSString *)path;
+ (PTAction*)CreateResetForm: (PTSDFDoc*)doc;
+ (PTAction*)CreateJavaScript: (PTSDFDoc*)doc script:  (NSString *)script;
- (BOOL)isEqualTo: (PTAction*)in_action;
- (BOOL)IsValid;
- (PTActionType)GetType;
- (void)Execute;
- (PTKeyStrokeActionResult*)ExecuteKeyStrokeAction: (PTKeyStrokeEventData*)data;
- (BOOL)NeedsWriteLock;
- (PTObj*)GetNext;
- (PTDestination*)GetDest;
- (BOOL)GetFormActionFlag: (PTFormActionFlag)flag;
- (void)SetFormActionFlag: (PTFormActionFlag)flag value:  (BOOL)value;
- (PTObj*)GetSDFObj;
+ (PTAction*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)initWithIn_obj: (PTObj*)in_obj;
@end


@interface PTActionParameter : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTAction*)GetAction;
- (void)Destroy;
+ (PTActionParameter*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)initWithAction: (PTAction*)action field:  (PTField*)field;- (id)initWithAction: (PTAction*)action annot:  (PTAnnot*)annot;- (id)initWithAction: (PTAction*)action;
@end


@interface PTOCROptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTOCROptions*)AddIgnoreZonesForPage: (PTPDFRectCollection*)regions page_num:  (int)page_num;
- (PTOCROptions*)AddLang: (NSString *)lang;
- (PTOCROptions*)AddTextZonesForPage: (PTPDFRectCollection*)regions page_num:  (int)page_num;
- (PTOCROptions*)AddDPI: (int)dpi;
- (PTOCROptions*)SetUsePDFPageCoords: (BOOL)value;
- (id)init;
@end


@interface PTOCRModule : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (BOOL)IsModuleAvailable;
+ (void)ImageToPDF: (PTPDFDoc*)dst src:  (NSString *)src options:  (PTOCROptions*)options;
+ (void)ProcessPDF: (PTPDFDoc*)dst options:  (PTOCROptions*)options;
+ (NSString *)GetOCRJsonFromImage: (PTPDFDoc*)dst src:  (NSString *)src options:  (PTOCROptions*)options;
+ (NSString *)GetOCRJsonFromPDF: (PTPDFDoc*)src options:  (PTOCROptions*)options;
+ (void)ApplyOCRJsonToPDF: (PTPDFDoc*)dst json:  (NSString *)json;
+ (NSString *)GetOCRXmlFromImage: (PTPDFDoc*)dst src:  (NSString *)src options:  (PTOCROptions*)options;
+ (NSString *)GetOCRXmlFromPDF: (PTPDFDoc*)src options:  (PTOCROptions*)options;
+ (void)ApplyOCRXmlToPDF: (PTPDFDoc*)dst xml:  (NSString *)xml;
- (id)init;
@end


@interface PTCADConvertOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)GetAllowThinLines;
- (PTCADConvertOptions*)SetAllowThinLines: (BOOL)value;
- (BOOL)GetAutoRotate;
- (PTCADConvertOptions*)SetAutoRotate: (BOOL)value;
- (PTColorPt*)GetBackgroundColor;
- (PTCADConvertOptions*)SetBackgroundColor: (PTColorPt*)value;
- (PTCADConvertOptions*)SetColorMode: (NSString *)value;
- (double)GetPageHeight;
- (PTCADConvertOptions*)SetPageHeight: (double)value;
- (double)GetPageWidth;
- (PTCADConvertOptions*)SetPageWidth: (double)value;
- (double)GetRasterDPI;
- (PTCADConvertOptions*)SetRasterDPI: (double)value;
- (PTCADConvertOptions*)AddSheets: (NSString *)value;
- (id)init;
@end


@interface PTAdvancedImagingConvertOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (double)GetDefaultDPI;
- (PTAdvancedImagingConvertOptions*)SetDefaultDPI: (double)value;
- (id)init;
@end


@interface PTCADModule : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (BOOL)IsModuleAvailable;
- (id)init;
@end


@interface PTPDF2WordModule : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (BOOL)IsModuleAvailable;
- (id)init;
@end


@interface PTPDF2HtmlReflowParagraphsModule : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (BOOL)IsModuleAvailable;
- (id)init;
@end


@interface PTCaret : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTCaret*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
+ (PTCaret*)CreateWithPadding: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos padding:  (PTPDFRect*)padding;
- (NSString *)GetSymbol;
- (void)SetSymbol: (NSString *)symbol;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTCircle : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTCircle*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithCircle: (PTAnnot*)circle;
@end


@interface PTHighlightAnnot : PTTextMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTHighlightAnnot*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (id)initWithD: (PTObj*)d;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTLineAnnot : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTLineAnnot*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (PTPDFPoint*)GetStartPoint;
- (void)SetStartPoint: (PTPDFPoint*)sp;
- (PTPDFPoint*)GetEndPoint;
- (void)SetEndPoint: (PTPDFPoint*)ep;
- (PTEndingStyle)GetStartStyle;
- (void)SetStartStyle: (PTEndingStyle)sst;
- (PTEndingStyle)GetEndStyle;
- (void)SetEndStyle: (PTEndingStyle)est;
- (double)GetLeaderLineLength;
- (void)SetLeaderLineLength: (double)length;
- (double)GetLeaderLineExtensionLength;
- (void)SetLeaderLineExtensionLength: (double)length;
- (BOOL)GetShowCaption;
- (void)SetShowCaption: (BOOL)showCaption;
- (PTLineIntentType)GetIntentType;
- (void)SetIntentType: (PTLineIntentType)it;
- (double)GetLeaderLineOffset;
- (void)SetLeaderLineOffset: (double)length;
- (PTCapPos)GetCaptionPosition;
- (void)SetCaptionPosition: (PTCapPos)style;
- (double)GetTextHOffset;
- (void)SetTextHOffset: (double)offset;
- (double)GetTextVOffset;
- (void)SetTextVOffset: (double)offset;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTFreeText : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTFreeText*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (NSString *)GetDefaultAppearance;
- (void)SetDefaultAppearance: (NSString *)app_str;
- (int)GetQuaddingFormat;
- (void)SetQuaddingFormat: (int)format;
- (PTPDFPoint*)GetCalloutLinePoint1;
- (PTPDFPoint*)GetCalloutLinePoint2;
- (PTPDFPoint*)GetCalloutLinePoint3;
- (void)SetCalloutLinePointsWithKneePoint: (PTPDFPoint*)p1 p2:  (PTPDFPoint*)p2 p3:  (PTPDFPoint*)p3;
- (void)SetCalloutLinePoints: (PTPDFPoint*)p1 p2:  (PTPDFPoint*)p2;
- (PTIntentName)GetIntentName;
- (void)SetIntentName: (PTIntentName)mode;
- (PTEndingStyle)GetEndingStyle;
- (void)SetEndingStyle: (PTEndingStyle)style;
- (void)SetEndingStyleWithString: (NSString *)est;
- (void)SetTextColor: (PTColorPt*)color col_comp:  (int)col_comp;
- (PTColorPt*)GetTextColor;
- (int)GetTextColorCompNum;
- (void)SetLineColor: (PTColorPt*)color col_comp:  (int)col_comp;
- (PTColorPt*)GetLineColor;
- (int)GetLineColorCompNum;
- (void)SetFontSize: (double)font_size;
- (double)GetFontSize;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTLink : PTAnnot
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTLink*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
+ (PTLink*)CreateWithAction: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos action:  (PTAction*)action;
- (void)RemoveAction;
- (PTAction*)GetAction;
- (void)SetAction: (PTAction*)action;
- (PTLinkHighlightingMode)GetHighlightingMode;
- (void)SetHighlightingMode: (PTLinkHighlightingMode)mode;
- (int)GetQuadPointCount;
- (PTQuadPoint*)GetQuadPoint: (int)idx;
- (void)SetQuadPoint: (int)idx qp:  (PTQuadPoint*)qp;
+ (NSString *)GetNormalizedUrl: (NSString *)url;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTMovie : PTAnnot
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTMovie*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (NSString *)GetTitle;
- (void)SetTitle: (NSString *)title;
- (BOOL)IsToBePlayed;
- (void)SetToBePlayed: (BOOL)isplay;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTPolyLine : PTLineAnnot
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTPolyLine*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (int)GetVertexCount;
- (PTPDFPoint*)GetVertex: (int)idx;
- (void)SetVertex: (int)idx pt:  (PTPDFPoint*)pt;
- (PTPolyLineIntentType)GetIntentName;
- (void)SetIntentName: (PTPolyLineIntentType)mode;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTPolygon : PTPolyLine
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTPolygon*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTRedactionAnnot : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTRedactionAnnot*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (int)GetQuadPointCount;
- (PTQuadPoint*)GetQuadPoint: (int)idx;
- (void)SetQuadPoint: (int)idx qp:  (PTQuadPoint*)qp;
- (PTObj*)GetAppFormXO;
- (void)SetAppFormXO: (PTObj*)formxo;
- (NSString *)GetOverlayText;
- (void)SetOverlayText: (NSString *)title;
- (BOOL)GetUseRepeat;
- (void)SetUseRepeat: (BOOL)userepeat;
- (NSString *)GetOverlayTextAppearance;
- (void)SetOverlayTextAppearance: (NSString *)app;
- (PTQuadForm)GetQuadForm;
- (void)SetQuadForm: (PTQuadForm)form;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTRubberStamp : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTRubberStamp*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos icon:  (PTRubberStampIcon)icon;
+ (PTRubberStamp*)CreateCustom: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos form_xobject:  (PTObj*)form_xobject;
- (PTRubberStampIcon)GetIcon;
- (void)SetRubberStampIconType: (PTRubberStampIcon)type;
- (void)SetIcon;
- (NSString *)GetIconName;
- (void)SetRubberStampIconName: (NSString *)icon;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTScreen : PTAnnot
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTScreen*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (NSString *)GetTitle;
- (void)SetTitle: (NSString *)title;
- (PTAction*)GetAction;
- (void)SetAction: (PTAction*)action;
- (int)GetBorderColorCompNum;
- (PTColorPt*)GetBorderColor;
- (void)SetBorderColor: (PTColorPt*)col numcomp:  (int)numcomp;
- (int)GetBackgroundColorCompNum;
- (PTColorPt*)GetBackgroundColor;
- (void)SetBackgroundColor: (PTColorPt*)col numcomp:  (int)numcomp;
- (NSString *)GetStaticCaptionText;
- (void)SetStaticCaptionText: (NSString *)contents;
- (NSString *)GetRolloverCaptionText;
- (void)SetRolloverCaptionText: (NSString *)contents;
- (NSString *)GetMouseDownCaptionText;
- (void)SetMouseDownCaptionText: (NSString *)contents;
- (PTObj*)GetStaticIcon;
- (void)SetStaticIcon: (PTObj*)icon;
- (PTObj*)GetRolloverIcon;
- (void)SetRolloverIcon: (PTObj*)icon;
- (PTObj*)GetMouseDownIcon;
- (void)SetMouseDownIcon: (PTObj*)icon;
- (PTScreenIconCaptionRelation)GetIconCaptionRelation;
- (void)SetIconCaptionRelation: (PTScreenIconCaptionRelation)icr;
- (PTScreenScaleCondition)GetScaleCondition;
- (void)SetScaleCondition: (PTScreenScaleCondition)sc;
- (PTScreenScaleType)GetScaleType;
- (void)SetScaleType: (PTScreenScaleType)st;
- (double)GetHIconLeftOver;
- (void)SetHIconLeftOver: (double)hl;
- (double)GetVIconLeftOver;
- (void)SetVIconLeftOver: (double)vl;
- (BOOL)GetFitFull;
- (void)SetFitFull: (BOOL)ff;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTSound : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTSound*)CreateSoundWithRect: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos icon:  (PTSoundIcon)icon;
+ (PTSound*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
+ (PTSound*)CreateWithData: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos source_data:  (PTFilter*)source_data bits_per_sample:  (int)bits_per_sample sample_freq:  (int)sample_freq num_channels:  (int)num_channels icon:  (PTSoundIcon)icon;
+ (PTSound*)CreateSoundWithPoint: (PTSDFDoc*)doc pos:  (PTPDFPoint*)pos icon:  (PTSoundIcon)icon;
- (PTObj*)GetSoundStream;
- (void)SetSoundStream: (PTObj*)icon;
- (PTSoundIcon)GetIcon;
- (void)SetSoundIconType: (PTSoundIcon)type;
- (void)SetIcon;
- (NSString *)GetIconName;
- (void)SetSoundIconName: (NSString *)type;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTSquare : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTSquare*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTSquiggly : PTTextMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTSquiggly*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (id)initWithD: (PTObj*)d;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTStrikeOut : PTTextMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTStrikeOut*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (id)initWithD: (PTObj*)d;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTText : PTMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTText*)CreateTextWithRect: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos contents:  (NSString *)contents;
+ (PTText*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
+ (PTText*)CreateTextWithPoint: (PTSDFDoc*)doc pos:  (PTPDFPoint*)pos contents:  (NSString *)contents;
- (BOOL)IsOpen;
- (void)SetOpen: (BOOL)isopen;
- (PTTextIcon)GetIcon;
- (NSString *)GetIconName;
- (void)SetTextIconType: (PTTextIcon)icon;
- (void)SetIcon;
- (void)SetTextIconName: (NSString *)icon;
- (NSString *)GetState;
- (void)SetState: (NSString *)state;
- (NSString *)GetStateModel;
- (void)SetStateModel: (NSString *)sm;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTUnderline : PTTextMarkup
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTUnderline*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (id)initWithD: (PTObj*)d;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTWatermark : PTAnnot
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTWatermark*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTWidget : PTAnnot
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTWidget*)Create: (PTSDFDoc*)doc pos:  (PTPDFRect*)pos field:  (PTField*)field;
- (PTField*)GetField;
- (PTWidgetHighlightingMode)GetHighlightingMode;
- (void)SetHighlightingMode: (PTWidgetHighlightingMode)mode;
- (PTAction*)GetAction;
- (void)SetAction: (PTAction*)action;
- (int)GetBorderColorCompNum;
- (PTColorPt*)GetBorderColor;
- (void)SetBorderColor: (PTColorPt*)col compnum:  (int)compnum;
- (int)GetBackgroundColorCompNum;
- (PTColorPt*)GetBackgroundColor;
- (void)SetBackgroundColor: (PTColorPt*)c compnum:  (int)compnum;
- (NSString *)GetStaticCaptionText;
- (void)SetStaticCaptionText: (NSString *)contents;
- (NSString *)GetRolloverCaptionText;
- (void)SetRolloverCaptionText: (NSString *)contents;
- (NSString *)GetMouseDownCaptionText;
- (void)SetMouseDownCaptionText: (NSString *)contents;
- (PTObj*)GetStaticIcon;
- (void)SetStaticIcon: (PTObj*)icon;
- (PTObj*)GetRolloverIcon;
- (void)SetRolloverIcon: (PTObj*)icon;
- (PTObj*)GetMouseDownIcon;
- (void)SetMouseDownIcon: (PTObj*)icon;
- (PTWidgetIconCaptionRelation)GetIconCaptionRelation;
- (void)SetIconCaptionRelation: (PTWidgetIconCaptionRelation)icr;
- (PTWidgetScaleCondition)GetScaleCondition;
- (void)SetScaleCondition: (PTWidgetScaleCondition)sd;
- (PTWidgetScaleType)GetScaleType;
- (void)SetScaleType: (PTWidgetScaleType)st;
- (double)GetHIconLeftOver;
- (void)SetHIconLeftOver: (double)hl;
- (double)GetVIconLeftOver;
- (void)SetVIconLeftOver: (double)vl;
- (BOOL)GetFitFull;
- (void)SetFitFull: (BOOL)ff;
- (PTColorPt*)GetTextColor;
- (int)GetTextColorCompNum;
- (void)SetTextColor: (PTColorPt*)color col_comp:  (int)col_comp;
- (double)GetFontSize;
- (void)SetFontSize: (double)font_size;
- (PTFont*)GetFont;
- (void)SetFont: (PTFont*)font;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnn: (PTAnnot*)ann;
@end


@interface PTCheckBoxWidget : PTWidget
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTCheckBoxWidget*)Create: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field_name:  (NSString *)field_name;
+ (PTCheckBoxWidget*)CreateWithField: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field:  (PTField*)field;
- (BOOL)IsChecked;
- (void)SetChecked: (BOOL)checked;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnnot: (PTAnnot*)annot;
@end


@interface PTComboBoxWidget : PTWidget
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTComboBoxWidget*)Create: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field_name:  (NSString *)field_name;
+ (PTComboBoxWidget*)CreateWithField: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field:  (PTField*)field;
- (void)AddOption: (NSString *)value;
- (void)AddOptions: (NSArray<NSString *> *)opts;
- (NSArray<NSString *> *)GetOptions;
- (void)ReplaceOptions: (NSArray<NSString *> *)new_opts;
- (void)SetSelectedOption: (NSString *)value;
- (NSString *)GetSelectedOption;
- (void)RemoveOption: (NSString *)value;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnnot: (PTAnnot*)annot;
@end


@interface PTListBoxWidget : PTWidget
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTListBoxWidget*)Create: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field_name:  (NSString *)field_name;
+ (PTListBoxWidget*)CreateWithField: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field:  (PTField*)field;
- (void)AddOption: (NSString *)value;
- (void)AddOptions: (NSArray<NSString *> *)opts;
- (void)SetSelectedOptions: (NSArray<NSString *> *)selected_opts;
- (NSArray<NSString *> *)GetSelectedOptions;
- (NSArray<NSString *> *)GetOptions;
- (void)ReplaceOptions: (NSArray<NSString *> *)new_opts;
- (void)RemoveOption: (NSString *)value;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnnot: (PTAnnot*)annot;
@end


@interface PTPushButtonWidget : PTWidget
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTPushButtonWidget*)Create: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field_name:  (NSString *)field_name;
+ (PTPushButtonWidget*)CreateWithField: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field:  (PTField*)field;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnnot: (PTAnnot*)annot;
@end


@interface PTRadioButtonWidget : PTWidget
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTRadioButtonGroup*)GetGroup;
- (void)EnableButton;
- (BOOL)IsEnabled;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnnot: (PTAnnot*)annot;
@end


@interface PTRadioButtonGroup : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTRadioButtonGroup*)Create: (PTPDFDoc*)doc field_name:  (NSString *)field_name;
- (PTRadioButtonWidget*)Add: (PTPDFRect*)pos onstate:  (NSString *)onstate;
- (unsigned int)GetNumButtons;
- (PTRadioButtonWidget*)GetButton: (unsigned int)index;
- (PTField*)GetField;
- (void)AddGroupButtonsToPage: (PTPage*)page;
- (id)initWithField: (PTField*)field;- (id)initWithGroup: (PTRadioButtonGroup*)group;- (id)initWithImpl: (void *)impl;
@end


@interface PTSignatureWidget : PTWidget
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTDigitalSignatureField*)GetDigitalSignatureField;
- (void)CreateSignatureAppearance: (PTImage*)img;
+ (PTSignatureWidget*)Create: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field_name:  (NSString *)field_name;
+ (PTSignatureWidget*)CreateWithField: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field:  (PTField*)field;
+ (PTSignatureWidget*)CreateWithDigitalSignatureField: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field:  (PTDigitalSignatureField*)field;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnnot: (PTAnnot*)annot;
@end


@interface PTTextWidget : PTWidget
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTTextWidget*)Create: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field_name:  (NSString *)field_name;
+ (PTTextWidget*)CreateWithField: (PTPDFDoc*)doc pos:  (PTPDFRect*)pos field:  (PTField*)field;
- (void)SetText: (NSString *)text;
- (NSString *)GetText;
- (id)initWithD: (PTObj*)d;- (id)init;- (id)initWithAnnot: (PTAnnot*)annot;
@end


@interface PTConfig : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTConfig*)Create: (PTPDFDoc*)doc default_config:  (BOOL)default_config;
- (BOOL)IsValid;
- (PTObj*)GetOrder;
- (void)SetOrder: (PTObj*)ocgs_array;
- (NSString *)GetName;
- (void)SetName: (NSString *)name;
- (NSString *)GetCreator;
- (void)SetCreator: (NSString *)name;
- (NSString *)GetInitBaseState;
- (PTObj*)GetInitOnStates;
- (PTObj*)GetInitOffStates;
- (void)SetInitBaseState: (NSString *)state;
- (void)SetInitOnStates: (PTObj*)on_array;
- (void)SetInitOffStates: (PTObj*)off_array;
- (PTObj*)GetIntent;
- (void)SetIntent: (PTObj*)intent;
- (PTObj*)GetLockedOCGs;
- (void)SetLockedOCGs: (PTObj*)locked_ocg_array;
- (PTObj*)GetSDFObj;
- (id)initWithOcg_config: (PTObj*)ocg_config;
@end


@interface PTGroup : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTGroup*)Create: (PTPDFDoc*)doc name:  (NSString *)name;
- (BOOL)IsValid;
- (NSString *)GetName;
- (void)SetName: (NSString *)name;
- (BOOL)GetCurrentState: (PTContext*)context;
- (void)SetCurrentState: (PTContext*)context state:  (BOOL)state;
- (BOOL)GetInitialState: (PTConfig*)config;
- (void)SetInitialState: (PTConfig*)config state:  (BOOL)state;
- (PTObj*)GetIntent;
- (void)SetIntent: (PTObj*)intent;
- (BOOL)IsLocked: (PTConfig*)config;
- (void)SetLocked: (PTConfig*)config locked:  (BOOL)locked;
- (BOOL)HasUsage;
- (PTObj*)GetUsage: (NSString *)key;
- (PTObj*)GetSDFObj;
- (id)initWithOcg: (PTObj*)ocg;
@end


@interface PTContext : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsValid;
- (BOOL)GetState: (PTGroup*)group;
- (void)SetState: (PTGroup*)group state:  (BOOL)state;
- (void)ResetStates: (BOOL)all_on;
- (void)SetNonOCDrawing: (BOOL)draw_non_OC;
- (BOOL)GetNonOCDrawing;
- (void)SetOCDrawMode: (PTOCDrawMode)oc_draw_mode;
- (PTOCDrawMode)GetOCMode;
- (void)Destroy;
+ (PTContext*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)initWithConfig: (PTConfig*)config;
@end


@interface PTOCMD : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTOCMD*)Create: (PTPDFDoc*)doc ocgs:  (PTObj*)ocgs vis_policy:  (PTVisibilityPolicyType)vis_policy;
- (BOOL)IsValid;
- (PTObj*)GetOCGs;
- (PTVisibilityPolicyType)GetVisibilityPolicy;
- (void)SetVisibilityPolicy: (PTVisibilityPolicyType)vis_policy;
- (PTObj*)GetVisibilityExpression;
- (BOOL)IsCurrentlyVisible: (PTContext*)context;
- (PTObj*)GetSDFObj;
- (id)initWithOcmd: (PTObj*)ocmd;
@end


@interface PTPDFACompliance : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SaveAsFile: (NSString *)file_path linearized:  (BOOL)linearized;
- (void)SaveAs: (NSString *)file_path;
- (NSData*)SaveAsMemBuf: (BOOL)linearized;
- (unsigned long)GetErrorCount;
- (PTErrorCode)GetError: (unsigned long)idx;
- (unsigned long)GetRefObjCount: (PTErrorCode)id;
- (unsigned long)GetRefObj: (PTErrorCode)id err_idx:  (unsigned long)err_idx;
+ (NSString *)GetPDFAErrorMessage: (PTErrorCode)id;
+ (PTConformance)GetDeclaredConformance: (PTPDFDoc*)in_doc;
- (void)Destroy;
- (id)initWithConvert: (BOOL)convert file_path:  (NSString *)file_path password:  (NSString *)password conf:  (PTConformance)conf exceptions:  (int)exceptions num_exceptions:  (int)num_exceptions max_ref_objs:  (int)max_ref_objs first_stop:  (BOOL)first_stop;- (id)initWithConvert: (BOOL)convert file_path:  (NSString *)file_path password:  (NSString *)password conf:  (PTConformance)conf exceptions:  (int)exceptions num_exceptions:  (int)num_exceptions max_ref_objs:  (int)max_ref_objs;- (id)initWithConvert: (BOOL)convert buf:  (NSString *)buf buf_size:  (unsigned long)buf_size password:  (NSString *)password conf:  (PTConformance)conf exceptions:  (int)exceptions num_exceptions:  (int)num_exceptions max_ref_objs:  (int)max_ref_objs first_stop:  (BOOL)first_stop;
@end


@interface PTAttrObj : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (NSString *)GetOwner;
- (PTObj*)GetSDFObj;
- (id)initWithDict: (PTObj*)dict;
@end


@interface PTClassMap : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsValid;
- (PTObj*)GetSDFObj;
- (id)initWithDict: (PTObj*)dict;
@end


@interface PTContentItem : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTContentItemType)GetType;
- (PTSElement*)GetParent;
- (PTPage*)GetPage;
- (PTObj*)GetSDFObj;
- (int)GetMCID;
- (PTObj*)GetContainingStm;
- (PTObj*)GetStmOwner;
- (PTObj*)GetRefObj;
- (id)initWithArg0: (PTContentItem*)arg0;
@end


@interface PTRoleMap : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsValid;
- (NSString *)GetDirectMap: (NSString *)type;
- (PTObj*)GetSDFObj;
- (id)initWithDict: (PTObj*)dict;
@end


@interface PTSTree : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTSTree*)Create: (PTPDFDoc*)doc;
- (void)Insert: (PTSElement*)kid insert_before:  (int)insert_before;
- (BOOL)IsValid;
- (int)GetNumKids;
- (PTSElement*)GetKid: (int)index;
- (PTSElement*)GetElement: (NSString *)id_buf id_buf_sz:  (int)id_buf_sz;
- (PTRoleMap*)GetRoleMap;
- (PTClassMap*)GetClassMap;
- (PTObj*)GetSDFObj;
- (id)initWithStruct_dict: (PTObj*)struct_dict;
@end


@interface PTSElement : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTSElement*)Create: (PTPDFDoc*)doc struct_type:  (NSString *)struct_type;
- (void)Insert: (PTSElement*)kid insert_before:  (int)insert_before;
- (int)CreateContentItem: (PTPDFDoc*)doc page:  (PTPage*)page insert_before:  (int)insert_before;
- (BOOL)IsValid;
- (NSString *)GetType;
- (int)GetNumKids;
- (BOOL)IsContentItem: (int)index;
- (PTContentItem*)GetAsContentItem: (int)index;
- (PTSElement*)GetAsStructElem: (int)index;
- (PTSElement*)GetParent;
- (PTSTree*)GetStructTreeRoot;
- (BOOL)HasTitle;
- (NSString *)GetTitle;
- (PTObj*)GetID;
- (BOOL)HasActualText;
- (NSString *)GetActualText;
- (BOOL)HasAlt;
- (NSString *)GetAlt;
- (PTObj*)GetSDFObj;
- (id)initWithDict: (PTObj*)dict;
@end


@interface PTBookmark : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTBookmark*)Create: (PTPDFDoc*)in_doc in_title:  (NSString *)in_title;
- (BOOL)isEqualTo: (PTBookmark*)in_bookmark;
- (BOOL)IsValid;
- (BOOL)HasChildren;
- (PTBookmark*)GetNext;
- (PTBookmark*)GetPrev;
- (PTBookmark*)GetFirstChild;
- (PTBookmark*)GetLastChild;
- (PTBookmark*)GetParent;
- (PTBookmark*)Find: (NSString *)in_title;
- (PTBookmark*)AddChildWithTitle: (NSString *)in_title;
- (PTBookmark*)AddChildWithBookmark: (PTBookmark*)in_bookmark;
- (PTBookmark*)AddNextWithTitle: (NSString *)in_title;
- (void)AddNextWithBookmark: (PTBookmark*)in_bookmark;
- (PTBookmark*)AddPrevWithTitle: (NSString *)in_title;
- (void)AddPrevWithBookmark: (PTBookmark*)in_bookmark;
- (void)Delete;
- (void)Unlink;
- (int)GetIndent;
- (BOOL)IsOpen;
- (void)SetOpen: (BOOL)in_open;
- (int)GetOpenCount;
- (NSString *)GetTitle;
- (PTObj*)GetTitleObj;
- (void)SetTitle: (NSString *)title;
- (PTAction*)GetAction;
- (void)SetAction: (PTAction*)in_action;
- (void)RemoveAction;
- (int)GetFlags;
- (void)SetFlags: (int)in_flags;
- (NSMutableArray*)GetColor;
- (void)SetColor: (double)in_r in_g:  (double)in_g in_b:  (double)in_b;
- (PTObj*)GetSDFObj;
+ (PTBookmark*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)init;- (id)initWithIn_bookmark_dict: (PTObj*)in_bookmark_dict;
@end


@interface PTContentReplacer : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)AddImage: (PTPDFRect*)target_region replacement_image:  (PTObj*)replacement_image;
- (void)AddText: (PTPDFRect*)target_region replacement_text:  (NSString *)replacement_text;
- (void)AddString: (NSString *)template_text replacement_text:  (NSString *)replacement_text;
- (void)SetMatchStrings: (NSString *)start_str end_str:  (NSString *)end_str;
- (void)Process: (PTPage*)page;
- (void)Destroy;
- (id)init;
@end


@interface PTPathData : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetOperators: (NSData*)operators;
- (void)SetPoints: (NSMutableArray*)points;
- (NSData*)GetOperators;
- (NSMutableArray*)GetPoints;
- (BOOL)IsDefined;
- (int)GetGlyphIndex;
- (id)init;
@end


@interface PTShapedText : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (double)GetScale;
- (PTShapingStatus)GetShapingStatus;
- (PTShapingFailureReason)GetFailureReason;
- (NSString *)GetText;
- (int)GetNumGlyphs;
- (unsigned int)GetGlyph: (unsigned int)index;
- (double)GetGlyphXPos: (unsigned int)index;
- (double)GetGlyphYPos: (unsigned int)index;
- (id)init;
@end


@interface PTFont : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTFont*)Create: (PTSDFDoc*)doc type:  (PTStandardType1Font)type embed:  (BOOL)embed;
+ (PTFont*)CreateTrueTypeFont: (PTSDFDoc*)doc font_path:  (NSString *)font_path embed:  (BOOL)embed subset:  (BOOL)subset;
+ (PTFont*)CreateCIDTrueTypeFont: (PTSDFDoc*)doc font_path:  (NSString *)font_path embed:  (BOOL)embed subset:  (BOOL)subset encoding:  (PTEncoding)encoding ttc_font_index:  (unsigned int)ttc_font_index;
+ (PTFont*)CreateFromFont: (PTSDFDoc*)doc from:  (PTFont*)from char_set:  (NSString *)char_set;
+ (PTFont*)CreateFromName: (PTSDFDoc*)doc name:  (NSString *)name char_set:  (NSString *)char_set;
+ (PTFont*)CreateType1Font: (PTSDFDoc*)doc font_path:  (NSString *)font_path embed:  (BOOL)embed;
- (PTFontType)GetType;
- (BOOL)IsSimple;
- (PTObj*)GetSDFObj;
- (PTObj*)GetDescriptor;
- (NSString *)GetName;
- (NSString *)GetFamilyName;
- (BOOL)IsFixedWidth;
- (BOOL)IsSerif;
- (BOOL)IsSymbolic;
- (BOOL)IsItalic;
- (BOOL)IsAllCap;
- (BOOL)IsForceBold;
- (BOOL)IsHorizontalMode;
- (double)GetWidth: (unsigned int)char_code;
- (double)GetMaxWidth;
- (double)GetMissingWidth;
- (PTUInt32Iterator*)GetCharCodeIterator;
- (PTPathData*)GetGlyphPath: (unsigned int)char_code conics2cubics:  (BOOL)conics2cubics transform:  (PTMatrix2D*)transform;
- (PTShapedText*)GetShapedText: (NSString *)text_to_shape;
- (NSString *)MapToUnicode: (unsigned int)char_code;
- (BOOL)IsEmbedded;
- (NSString *)GetEmbeddedFontName;
- (PTObj*)GetEmbeddedFont;
- (int)GetEmbeddedFontBufSize;
- (unsigned short)GetUnitsPerEm;
- (PTPDFRect*)GetBBox;
- (double)GetAscent;
- (double)GetDescent;
- (int)GetStandardType1FontType;
- (BOOL)IsCFF;
- (PTMatrix2D*)GetType3FontMatrix;
- (PTObj*)GetType3GlyphStream: (unsigned int)char_code;
- (NSMutableArray*)GetVerticalAdvance: (unsigned int)char_code;
- (PTFont*)GetDescendant;
- (unsigned int)MapToCID: (unsigned int)char_code;
- (void)Destroy;
- (id)initWithFont_dict: (PTObj*)font_dict;
@end


@interface PTShading : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTShadingType)GetType;
- (PTObj*)GetSDFObj;
- (PTColorSpace*)GetBaseColorSpace;
- (BOOL)HasBBox;
- (PTPDFRect*)GetBBox;
- (BOOL)HasBackground;
- (PTColorPt*)GetBackground;
- (BOOL)GetAntialias;
- (double)GetParamStart;
- (double)GetParamEnd;
- (BOOL)IsExtendStart;
- (BOOL)IsExtendEnd;
- (PTColorPt*)GetColorForAxialOrRadial: (double)t;
- (NSMutableArray*)GetCoordsAxial;
- (NSMutableArray*)GetCoordsRadial;
- (NSMutableArray*)GetDomain;
- (PTMatrix2D*)GetMatrix;
- (PTColorPt*)GetColorForFunction: (double)t1 t2:  (double)t2;
- (void)Destroy;
- (id)initWithShading_dict: (PTObj*)shading_dict;
@end


@interface PTPatternColor : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTPatternColorType)GetType;
- (PTObj*)GetSDFObj;
- (PTMatrix2D*)GetMatrix;
- (PTShading*)GetShading;
- (PTTilingType)GetTilingType;
- (PTPDFRect*)GetBBox;
- (double)GetXStep;
- (double)GetYStep;
- (void)Destroy;
- (id)initWithPattern: (PTObj*)pattern;
@end


@interface PTElement : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTElementType)GetType;
- (PTGState*)GetGState;
- (PTMatrix2D*)GetCTM;
- (PTPDFRect*)GetBBox;
- (PTSElement*)GetParentStructElement;
- (int)GetStructMCID;
- (BOOL)IsOCVisible;
- (BOOL)IsClippingPath;
- (BOOL)IsStroked;
- (BOOL)IsFilled;
- (BOOL)IsWindingFill;
- (BOOL)IsClipWindingFill;
- (PTPathData*)GetPathData;
- (void)SetPathData: (PTPathData*)data;
- (void)SetPathClip: (BOOL)clip;
- (void)SetPathStroke: (BOOL)stroke;
- (void)SetPathFill: (BOOL)fill;
- (void)SetWindingFill: (BOOL)winding_rule;
- (void)SetClipWindingFill: (BOOL)winding_rule;
- (PTObj*)GetXObject;
- (PTFilter*)GetImageData;
- (int)GetImageDataSize;
- (PTColorSpace*)GetImageColorSpace;
- (int)GetImageWidth;
- (int)GetImageHeight;
- (PTObj*)GetDecodeArray;
- (int)GetBitsPerComponent;
- (int)GetComponentNum;
- (BOOL)IsImageMask;
- (BOOL)IsImageInterpolate;
- (PTObj*)GetMask;
- (PTRenderingIntent)GetImageRenderingIntent;
- (NSString *)GetTextString;
- (NSData*)GetTextData;
- (unsigned int)GetTextDataSize;
- (PTMatrix2D*)GetTextMatrix;
- (PTCharIterator*)GetCharIterator;
- (double)GetTextLength;
- (double)GetPosAdjustment;
- (PTPDFPoint*)GetNewTextLineOffset;
- (void)SetNewTextLineOffset: (double)dx dy:  (double)dy;
- (BOOL)HasTextMatrix;
- (void)SetTextData: (NSData*)buf_text_data text_data_size:  (int)text_data_size;
- (void)SetTextMatrixWithMatrix2D: (PTMatrix2D*)mtx;
- (void)SetTextMatrix: (double)a b:  (double)b c:  (double)c d:  (double)d h:  (double)h v:  (double)v;
- (void)SetPosAdjustment: (double)adjust;
- (void)UpdateTextMetrics;
- (PTShading*)GetShading;
- (PTObj*)GetMCPropertyDict;
- (PTObj*)GetMCTag;
- (id)init;
@end


@interface PTElementBuilder : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Reset: (PTGState*)gs;
- (PTElement*)CreateImage: (PTImage*)img;
- (PTElement*)CreateImageWithMatrix: (PTImage*)img mtx:  (PTMatrix2D*)mtx;
- (PTElement*)CreateImageWithCornerAndScale: (PTImage*)img x:  (double)x y:  (double)y hscale:  (double)hscale vscale:  (double)vscale;
- (PTElement*)CreateGroupBegin;
- (PTElement*)CreateGroupEnd;
- (PTElement*)CreateShading: (PTShading*)sh;
- (PTElement*)CreateFormWithObj: (PTObj*)form;
- (PTElement*)CreateFormWithPage: (PTPage*)page;
- (PTElement*)CreateFormWithPageAndDestination: (PTPage*)page doc:  (PTPDFDoc*)doc;
- (PTElement*)CreateTextBeginWithFont: (PTFont*)font font_sz:  (double)font_sz;
- (PTElement*)CreateTextBegin;
- (PTElement*)CreateTextEnd;
- (PTElement*)CreateTextRunWithFont: (NSString *)text_data font:  (PTFont*)font font_sz:  (double)font_sz;
- (PTElement*)CreateTextRun: (NSString *)text_data;
- (PTElement*)CreateUnicodeTextRun: (unsigned short*)text_data text_data_sz:  (unsigned int)text_data_sz;
- (PTElement*)CreateShapedTextRun: (PTShapedText*)text_data;
- (PTElement*)CreateTextNewLineWithOffset: (double)dx dy:  (double)dy;
- (PTElement*)CreateTextNewLine;
- (PTElement*)CreatePath: (NSMutableArray*)points seg_types:  (NSData*)seg_types;
- (PTElement*)CreateRect: (double)x y:  (double)y width:  (double)width height:  (double)height;
- (PTElement*)CreateEllipse: (double)x y:  (double)y width:  (double)width height:  (double)height;
- (void)PathBegin;
- (PTElement*)PathEnd;
- (void)MoveTo: (double)x y:  (double)y;
- (void)LineTo: (double)x y:  (double)y;
- (void)CurveTo: (double)cx1 cy1:  (double)cy1 cx2:  (double)cx2 cy2:  (double)cy2 x2:  (double)x2 y2:  (double)y2;
- (void)ArcToWithParam: (double)x y:  (double)y width:  (double)width height:  (double)height start:  (double)start extent:  (double)extent;
- (void)ArcToEndPt: (double)xr yr:  (double)yr rx:  (double)rx isLargeArc:  (BOOL)isLargeArc sweep:  (BOOL)sweep endX:  (double)endX endY:  (double)endY;
- (void)Ellipse: (double)x y:  (double)y width:  (double)width height:  (double)height;
- (void)Rect: (double)x y:  (double)y width:  (double)width height:  (double)height;
- (void)ClosePath;
- (PTElement*)CreateMarkedContentBeginInlineProperties: (NSString *)tag;
- (PTElement*)CreateMarkedContentBegin: (NSString *)tag property_dict:  (PTObj*)property_dict;
- (PTElement*)CreateMarkedContentEnd;
- (PTElement*)CreateMarkedContentPointInlineProperties: (NSString *)tag;
- (PTElement*)CreateMarkedContentPoint: (NSString *)tag property_dict:  (PTObj*)property_dict;
- (void)Destroy;
- (id)init;
@end


@interface PTElementReader : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)ReaderBeginWithPage: (PTPage*)page ocg_context:  (PTContext*)ocg_context;
- (void)Begin: (PTPage*)page;
- (void)ReaderBeginWithSDFObj: (PTObj*)content_stream resource_dict:  (PTObj*)resource_dict ocg_context:  (PTContext*)ocg_context;
- (PTElement*)Next;
- (PTElement*)Current;
- (void)FormBegin;
- (void)PatternBegin: (BOOL)fill_pattern reset_ctm_tfm:  (BOOL)reset_ctm_tfm;
- (void)Type3FontBegin: (TRN_chardata*)char_data resource_dict:  (PTObj*)resource_dict;
- (BOOL)End;
- (PTGSChangesIterator*)GetChangesIterator;
- (BOOL)IsChanged: (PTGStateAttribute)attrib;
- (void)ClearChangeList;
- (void)AppendResource: (PTObj*)res;
- (PTObj*)GetFont: (NSString *)name;
- (PTObj*)GetXObject: (NSString *)name;
- (PTObj*)GetShading: (NSString *)name;
- (PTObj*)GetColorSpace: (NSString *)name;
- (PTObj*)GetPattern: (NSString *)name;
- (PTObj*)GetExtGState: (NSString *)name;
- (void)Destroy;
- (id)init;
@end


@interface PTElementWriter : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)WriterBeginWithPage: (PTPage*)page placement:  (PTWriteMode)placement page_coord_sys:  (BOOL)page_coord_sys compress:  (BOOL)compress resources:  (PTObj*)resources;
- (void)Begin: (PTPage*)page placement:  (PTWriteMode)placement page_coord_sys:  (BOOL)page_coord_sys compress:  (BOOL)compress;
- (void)WriterBeginWithSDFDoc: (PTSDFDoc*)doc compress:  (BOOL)compress;
- (void)WriterBeginWithSDFObj: (PTObj*)stream_obj_to_update compress:  (BOOL)compress resources:  (PTObj*)resources;
- (PTObj*)End;
- (void)WriteElement: (PTElement*)element;
- (void)WritePlacedElement: (PTElement*)element;
- (void)Flush;
- (void)WriteBuffer: (NSData*)data;
- (void)WriteString: (NSString *)str;
- (void)WriteGStateChanges: (PTElement*)element;
- (void)SetDefaultGState: (PTElementReader*)reader;
- (void)Destroy;
- (id)init;
@end


@interface PTExternalAnnotManager : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (void)MergeXFDF: (NSString *)xfdf_content;
- (NSString *)Undo;
- (NSString *)GetLastXFDF;
- (NSString *)GetLastJSON;
- (NSString *)Redo;
- (NSString *)GetNextRedoInfo;
- (NSString *)GetNextUndoInfo;
- (NSString *)TakeSnapshot: (NSString *)payload;
- (id)init;
@end


@interface PTFlattener : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetDPI: (unsigned int)dpi;
- (void)SetMaximumImagePixels: (unsigned int)max_pixels;
- (void)SetPreferJPG: (BOOL)jpg;
- (void)SetJPGQuality: (unsigned int)quality;
- (void)SetThreshold: (PTThreshold)threshold;
- (void)SetPathHinting: (BOOL)enable_hinting;
- (void)Process: (PTPDFDoc*)doc mode:  (PTFlattenMode)mode;
- (void)Destroy;
- (id)init;
@end


@interface PTLinkInfo : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setRect: (PTPDFRect*)value;
- (PTPDFRect*)getRect;
- (void)setUrl: (NSString *)value;
- (NSString *)getUrl;
- (id)init;
@end


@interface PTImage2RGB : PTFilter
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (id)initWithImage_element: (PTElement*)image_element;- (id)initWithImage_xobject: (PTObj*)image_xobject;- (id)initWithImage: (PTImage*)image;
@end


@interface PTImage2RGBA : PTFilter
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (id)initWithImage_element: (PTElement*)image_element premultiply:  (BOOL)premultiply;- (id)initWithImage_element: (PTElement*)image_element;- (id)initWithImage_xobject: (PTObj*)image_xobject premultiply:  (BOOL)premultiply;- (id)initWithImage: (PTImage*)image premultiply:  (BOOL)premultiply;
@end


@interface PTCallback : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)RenderBeginEventProc;
+ (void)StaticRenderBeginEventProc: (void *)data;
- (void)RenderFinishEventProc: (BOOL)cancelled;
+ (void)StaticRenderFinishEventProc: (void *)data cancelled:  (BOOL)cancelled;
- (void)ErrorReportProc: (NSString *)message;
+ (void)StaticErrorReportProc: (NSString *)message data:  (void *)data;
- (void)CurrentPageProc: (int)current_page num_pages:  (int)num_pages;
+ (void)StaticCurrentPageProc: (int)current_page num_pages:  (int)num_pages data:  (void *)data;
- (void)JavaScriptEventProc: (NSString *)event_type json:  (NSString *)json;
+ (void)StaticJavaScriptEventProc: (NSString *)event_type json:  (NSString *)json data:  (void *)data;
- (void)CurrentZoomProc: (double)curr_zoom_proc;
+ (void)StaticCurrentZoomProc: (double)curr_zoom_proc data:  (void *)data;
- (void)ThumbAsyncHandler: (int)page_num was_thumb_found:  (BOOL)was_thumb_found thumb_buf:  (NSString *)thumb_buf thumb_width:  (int)thumb_width thumb_height:  (int)thumb_height;
+ (void)StaticThumbAsyncHandler: (int)page_num was_thumb_found:  (BOOL)was_thumb_found thumb_buf:  (NSString *)thumb_buf thumb_width:  (int)thumb_width thumb_height:  (int)thumb_height custom_data:  (void *)custom_data;
- (void)RequestRenderInWorkerThread;
+ (void)StaticRequestRenderInWorkerThread: (void *)custom_data;
- (void)FindTextHandler: (BOOL)success selection:  (PTSelection*)selection;
+ (void)StaticFindTextHandler: (BOOL)success selection:  (PTSelection*)selection custom_data:  (void *)custom_data;
- (void)CreateTileProc: (NSString *)buffer originX:  (int)originX originY:  (int)originY width:  (int)width height:  (int)height pagNum:  (int)pagNum cellNumber:  (long long)cellNumber finalRender:  (BOOL)finalRender predictionRender:  (BOOL)predictionRender tilesRemaining:  (int)tilesRemaining firstTile:  (BOOL)firstTile canvasWidth:  (int)canvasWidth canvasHeight:  (int)canvasHeight cellSideLength:  (int)cellSideLength cellPerRow:  (int)cellPerRow cellPerCol:  (int)cellPerCol thumbnailId:  (int)thumbnailId;
+ (void)StaticCreateTileProc: (void *)customData buffer:  (NSString *)buffer originX:  (int)originX originY:  (int)originY width:  (int)width height:  (int)height pageNum:  (int)pageNum cellNumber:  (long long)cellNumber finalRender:  (BOOL)finalRender predictionRender:  (BOOL)predictionRender tilesRemaining:  (int)tilesRemaining firstTile:  (BOOL)firstTile canvasWidth:  (int)canvasWidth canvasHeight:  (int)canvasHeight cellSideLength:  (int)cellSideLength cellPerRow:  (int)cellPerRow cellPerCol:  (int)cellPerCol thumbnailId:  (int)thumbnailId;
- (void)AnnotBitmapProc: (int)operation_type buffer:  (NSString *)buffer width:  (unsigned int)width height:  (unsigned int)height stride:  (unsigned int)stride page_num:  (unsigned int)page_num annot_index:  (unsigned int)annot_index annot_key:  (void *)annot_key x_in_page:  (long long)x_in_page y_in_page:  (long long)y_in_page x_offset:  (int)x_offset y_offset:  (int)y_offset remaining_tiles:  (int)remaining_tiles sequence_number:  (int)sequence_number x_page_size:  (long long)x_page_size y_page_size:  (long long)y_page_size;
+ (void)StaticAnnotBitmapProc: (void *)me operation_type:  (int)operation_type buffer:  (NSString *)buffer width:  (unsigned int)width height:  (unsigned int)height stride:  (unsigned int)stride page_num:  (unsigned int)page_num annot_index:  (unsigned int)annot_index annot_key:  (void *)annot_key x_in_page:  (long long)x_in_page y_in_page:  (long long)y_in_page x_offset:  (int)x_offset y_offset:  (int)y_offset remaining_tiles:  (int)remaining_tiles sequence_number:  (int)sequence_number x_page_size:  (long long)x_page_size y_page_size:  (long long)y_page_size;
- (void)DeluxeCreateTileProc: (NSString *)buffer width:  (unsigned int)width height:  (unsigned int)height stride:  (unsigned int)stride page_num:  (unsigned int)page_num x_page_loc:  (unsigned long long)x_page_loc y_page_loc:  (unsigned long long)y_page_loc zoomed_page_width:  (unsigned int)zoomed_page_width zoomed_page_height:  (unsigned int)zoomed_page_height tile_id:  (unsigned int)tile_id x_in_page:  (unsigned int)x_in_page y_in_page:  (unsigned int)y_in_page canvas_id:  (int)canvas_id remaining_tiles:  (int)remaining_tiles tile_type:  (int)tile_type sequence_number:  (int)sequence_number;
+ (void)StaticDeluxeCreateTileProc: (void *)me buffer:  (NSString *)buffer width:  (unsigned int)width height:  (unsigned int)height stride:  (unsigned int)stride page_num:  (unsigned int)page_num x_page_loc:  (unsigned long long)x_page_loc y_page_loc:  (unsigned long long)y_page_loc zoomed_page_width:  (unsigned int)zoomed_page_width zoomed_page_height:  (unsigned int)zoomed_page_height tile_id:  (unsigned int)tile_id x_in_page:  (unsigned int)x_in_page y_in_page:  (unsigned int)y_in_page canvas_id:  (int)canvas_id remaining_tiles:  (int)remaining_tiles tile_type:  (int)tile_type sequence_number:  (int)sequence_number;
- (void)RemoveTileProc: (int)canvasNumber cellNumber:  (long long)cellNumber thumbnailId:  (int)thumbnailId sequenceNumber:  (int)sequenceNumber;
+ (void)StaticRemoveTileProc: (void *)customData canvasNumber:  (int)canvasNumber cellNumber:  (long long)cellNumber thumbnailId:  (int)thumbnailId sequenceNumber:  (int)sequenceNumber;
- (void)PartDownloadedProc: (int)dlType doc:  (void *)doc pageNum:  (unsigned int)pageNum objNum:  (unsigned int)objNum message:  (NSString *)message;
+ (void)StaticPartDownloadedProc: (int)dlType doc:  (void *)doc pageNum:  (unsigned int)pageNum objNum:  (unsigned int)objNum message:  (NSString *)message customData:  (void *)customData;
- (id)init;
@end


@interface PTHighlight : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setPage_num: (int)value;
- (int)getPage_num;
- (void)setPosition: (int)value;
- (int)getPosition;
- (void)setLength: (int)value;
- (int)getLength;
- (id)init;- (id)initWithPg: (int)pg pos:  (int)pos len:  (int)len;
@end


@interface PTHighlights : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Load: (NSString *)file_name;
- (void)Save: (NSString *)file_name;
- (void)Add: (PTHighlights*)hlts;
- (void)Clear;
- (void)Begin: (PTPDFDoc*)doc;
- (BOOL)HasNext;
- (void)Next;
- (int)GetCurrentPageNumber;
- (PTVectorQuadPoint*)GetCurrentQuads;
- (void)Destroy;
+ (PTHighlights*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)init;
@end


@interface PTSelection : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (int)GetPageNum;
- (PTVectorQuadPoint*)GetQuads;
- (NSString *)GetAsUnicode;
- (NSString *)GetAsHtml;
- (id)init;
@end


@interface PTOptimizer : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (void)Optimize: (PTPDFDoc*)doc settings:  (PTOptimizerSettings*)settings;

@end


@interface PTImageSettings : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetImageDPI: (double)maximum resampling:  (double)resampling;
- (void)SetCompressionMode: (PTCompressionMode)mode;
- (void)SetDownsampleMode: (PTDownsampleMode)mode;
- (void)SetQuality: (unsigned int)quality;
- (void)ForceRecompression: (BOOL)force;
- (void)ForceChanges: (BOOL)force;
- (id)init;
@end


@interface PTMonoImageSettings : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetImageDPI: (double)maximum resampling:  (double)resampling;
- (void)SetCompressionMode: (PTMonoCompressionMode)mode;
- (void)SetDownsampleMode: (PTMonoDownsampleMode)mode;
- (void)ForceRecompression: (BOOL)force;
- (void)ForceChanges: (BOOL)force;
- (void)SetJBIG2Threshold: (double)jbig2_threshold;
- (id)init;
@end


@interface PTTextSettings : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SubsetFonts: (BOOL)subset;
- (void)EmbedFonts: (BOOL)embed;
- (id)init;
@end


@interface PTOptimizerSettings : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetColorImageSettings: (PTImageSettings*)settings;
- (void)SetGrayscaleImageSettings: (PTImageSettings*)settings;
- (void)SetMonoImageSettings: (PTMonoImageSettings*)settings;
- (void)SetTextSettings: (PTTextSettings*)settings;
- (void)RemoveCustomEntries: (BOOL)should_remove;
- (void)setM_color_image_settings: (PTImageSettings*)value;
- (PTImageSettings*)getM_color_image_settings;
- (void)setM_grayscale_image_settings: (PTImageSettings*)value;
- (PTImageSettings*)getM_grayscale_image_settings;
- (void)setM_mono_image_settings: (PTMonoImageSettings*)value;
- (PTMonoImageSettings*)getM_mono_image_settings;
- (void)setM_text_settings: (PTTextSettings*)value;
- (PTTextSettings*)getM_text_settings;
- (void)setM_remove_custom: (BOOL)value;
- (BOOL)getM_remove_custom;
- (id)init;
@end


@interface PTPageLabel : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTPageLabel*)Create: (PTSDFDoc*)doc style:  (PTPageLabelStyle)style prefix:  (NSString *)prefix start_at:  (int)start_at;
- (BOOL)isEqualTo: (PTPageLabel*)d;
- (BOOL)IsValid;
- (NSString *)GetLabelTitle: (int)page_num;
- (void)SetStyle: (PTPageLabelStyle)style;
- (PTPageLabelStyle)GetStyle;
- (NSString *)GetPrefix;
- (void)SetPrefix: (NSString *)prefix;
- (int)GetStart;
- (void)SetStart: (int)start_at;
- (int)GetFirstPageNum;
- (int)GetLastPageNum;
- (PTObj*)GetSDFObj;
- (id)initWithL: (PTObj*)l first_page:  (int)first_page last_page:  (int)last_page;
@end


@interface PTPageSet : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)AddPage: (int)one_page;
- (void)AddRange: (int)range_start range_end:  (int)range_end filter:  (PTPageSetFilter)filter;
- (void)Destroy;
- (id)init;- (id)initWithOne_page: (int)one_page;- (id)initWithRange_start: (int)range_start range_end:  (int)range_end filter:  (PTPageSetFilter)filter;
@end


@interface PTPDFDocInfo : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (NSString *)GetTitle;
- (PTObj*)GetTitleObj;
- (void)SetTitle: (NSString *)title;
- (NSString *)GetAuthor;
- (PTObj*)GetAuthorObj;
- (void)SetAuthor: (NSString *)author;
- (NSString *)GetSubject;
- (PTObj*)GetSubjectObj;
- (void)SetSubject: (NSString *)subject;
- (NSString *)GetKeywords;
- (PTObj*)GetKeywordsObj;
- (void)SetKeywords: (NSString *)keywords;
- (NSString *)GetCreator;
- (PTObj*)GetCreatorObj;
- (void)SetCreator: (NSString *)creator;
- (NSString *)GetProducer;
- (PTObj*)GetProducerObj;
- (void)SetProducer: (NSString *)producer;
- (PTDate*)GetCreationDate;
- (void)SetCreationDate: (PTDate*)creation_date;
- (PTDate*)GetModDate;
- (void)SetModDate: (PTDate*)mod_date;
- (PTObj*)GetSDFObj;
- (id)initWithTr: (PTObj*)tr;
@end


@interface PTPDFDocViewPrefs : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetInitialPage: (PTDestination*)dest;
- (void)SetPageMode: (PTPageMode)mode;
- (PTPageMode)GetPageMode;
- (void)SetLayoutMode: (PTPageLayout)layout;
- (PTPageLayout)GetLayoutMode;
- (void)SetPref: (PTViewerPref)pref value:  (BOOL)value;
- (BOOL)GetPref: (PTViewerPref)pref;
- (void)SetNonFullScreenPageMode: (PTPageMode)mode;
- (PTPageMode)GetNonFullScreenPageMode;
- (void)SetDirection: (BOOL)left_to_right;
- (BOOL)GetDirection;
- (void)SetViewArea: (PTBox)box;
- (PTBox)GetViewArea;
- (void)SetViewClip: (PTBox)box;
- (PTBox)GetViewClip;
- (void)SetPrintArea: (PTBox)box;
- (PTBox)GetPrintArea;
- (void)SetPrintClip: (PTBox)box;
- (PTBox)GetPrintClip;
- (PTObj*)GetSDFObj;
- (id)initWithTr: (PTObj*)tr;
@end


@interface PTSeparation : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (unsigned char)C;
- (unsigned char)M;
- (unsigned char)Y;
- (unsigned char)K;
- (unsigned int)GetDataSize;
- (NSString *)GetSeparationName;
- (NSData*)GetData;
- (id)init;
@end


@interface PTPDFRasterizer : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (NSData*)Rasterize: (PTPage*)page width:  (int)width height:  (int)height stride:  (int)stride num_comps:  (int)num_comps demult:  (BOOL)demult device_mtx:  (PTMatrix2D*)device_mtx clip:  (PTPDFRect*)clip scrl_clip_regions:  (PTPDFRect*)scrl_clip_regions;
- (NSMutableArray*)RasterizeSeparations: (PTPage*)page width:  (int)width height:  (int)height mtx:  (PTMatrix2D*)mtx clip:  (PTPDFRect*)clip cancel:  (BOOL *)cancel;
- (void)SetDrawAnnotations: (BOOL)render_annots;
- (void)SetHighlightFields: (BOOL)highlight_fields;
- (void)SetAntiAliasing: (BOOL)enable_aa;
- (void)SetPathHinting: (BOOL)enable_hinting;
- (void)SetThinLineAdjustment: (BOOL)pixel_grid_fit stroke_adjust:  (BOOL)stroke_adjust;
- (void)SetImageSmoothing: (BOOL)smoothing_enabled hq_image_resampling:  (BOOL)hq_image_resampling;
- (void)SetCaching: (BOOL)enabled;
- (void)SetGamma: (double)expgamma;
- (void)SetOCGContext: (PTContext*)ctx;
- (void)SetPrintMode: (BOOL)is_printing;
- (void)SetOverprint: (PTOverprintPreviewMode)op;
- (void)SetErrorReportProc: (PTCallback*)instance;
- (void)SetRasterizerType: (PTRasterizerType)type;
- (PTRasterizerType)GetRasterizerType;
- (void)SetColorPostProcessMode: (PTColorPostProcessMode)mode;
- (PTColorPostProcessMode)GetColorPostProcessMode;
- (void)UpdateBuffer;
- (void)Destroy;
- (id)initWithType: (PTRasterizerType)type;
@end


@interface PTViewerOptimizedOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetThumbnailRenderingThreshold: (unsigned int)threshold;
- (void)SetThumbnailSize: (unsigned int)size;
- (void)SetOverprint: (PTOverprintPreviewMode)mode;
- (id)init;
@end


@interface PTPDFDoc : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Close;
- (BOOL)IsEncrypted;
- (BOOL)InitSecurityHandler;
- (BOOL)InitStdSecurityHandlerWithPassword: (NSString *)password password_sz:  (int)password_sz;
- (BOOL)InitStdSecurityHandler: (NSString *)password;
- (PTSecurityHandler*)GetSecurityHandler;
- (void)SetSecurityHandler: (PTSecurityHandler*)handler;
- (void)RemoveSecurity;
- (BOOL)HasSignatures;
- (PTSignatureHandlerId)AddSignatureHandler: (PTSignatureHandler*)signature_handler;
- (unsigned long)AddStdSignatureHandlerFromFile: (NSString *)pkcs12_keyfile pkcs12_keypass:  (NSString *)pkcs12_keypass;
- (unsigned long)AddStdSignatureHandlerFromBuffer: (NSData*)pkcs12_keybuffer pkcs12_keypass:  (NSString *)pkcs12_keypass;
- (void)RemoveSignatureHandler: (PTSignatureHandlerId)signature_handler_id;
- (PTSignatureHandler*)GetSignatureHandler: (PTSignatureHandlerId)signature_handler_id;
- (PTSDFUndoManager*)GetUndoManager;
- (PTDigitalSignatureField*)CreateDigitalSignatureField: (NSString *)in_sig_field_name;
- (PTDigitalSignatureFieldIterator*)GetDigitalSignatureFieldIterator;
- (PTDigitalSignatureFieldDocumentPermissions)GetDigitalSignaturePermissions;
- (PTPDFDocInfo*)GetDocInfo;
- (PTPDFDocViewPrefs*)GetViewPrefs;
- (PTObj*)GetTriggerAction: (PTPDFDocActionTriggerEvent)trigger;
- (BOOL)IsModified;
- (BOOL)HasRepairedXRef;
- (BOOL)IsLinearized;
- (BOOL)HasDownloader;
- (unsigned long long)GetDownloadedByteCount;
- (unsigned long long)GetTotalRemoteByteCount;
- (void)SaveToFile: (NSString *)path flags:  (unsigned int)flags;
- (NSData*)SaveToBuf: (unsigned int)flags;
- (void)Save: (PTFilter*)stream flags:  (unsigned int)flags;
- (PTPageIterator*)GetPageIterator: (unsigned int)page_number;
- (PTPage*)GetPage: (unsigned int)page_number;
- (void)PageRemove: (PTPageIterator*)page_itr;
- (void)PageInsert: (PTPageIterator*)where page:  (PTPage*)page;
- (void)InsertPages: (int)insert_before_page_number src_doc:  (PTPDFDoc*)src_doc start_page:  (int)start_page end_page:  (int)end_page flag:  (PTInsertFlag)flag;
- (void)InsertPagesWithPageSet: (int)insert_before_page_number src_doc:  (PTPDFDoc*)src_doc source_page_set:  (PTPageSet*)source_page_set flag:  (PTInsertFlag)flag;
- (void)MovePages: (int)move_before_page_number src_doc:  (PTPDFDoc*)src_doc start_page:  (int)start_page end_page:  (int)end_page flag:  (PTInsertFlag)flag;
- (void)MovePagesWithPageSet: (int)move_before_page_number src_doc:  (PTPDFDoc*)src_doc source_page_set:  (PTPageSet*)source_page_set flag:  (PTInsertFlag)flag;
- (void)PagePushFront: (PTPage*)page;
- (void)PagePushBack: (PTPage*)page;
- (PTVectorPage*)ImportPages: (PTVectorPage*)pages import_bookmarks:  (BOOL)import_bookmarks;
- (PTPage*)PageCreate: (PTPDFRect*)media_box;
- (void)AppendTextDiff: (PTPage*)page1 page2:  (PTPage*)page2;
- (PTBookmark*)GetFirstBookmark;
- (void)AddRootBookmark: (PTBookmark*)root_bookmark;
- (PTObj*)GetTrailer;
- (PTObj*)GetRoot;
- (PTObj*)GetPages;
- (int)GetPageCount;
- (PTFieldIterator*)GetFieldIterator;
- (PTFieldIterator*)GetFieldIteratorWithName: (NSString *)field_name;
- (PTField*)GetField: (NSString *)field_name;
- (PTField*)FieldCreateWithObj: (NSString *)field_name type:  (PTFieldType)type field_value:  (PTObj*)field_value def_field_value:  (PTObj*)def_field_value;
- (PTField*)FieldCreate: (NSString *)field_name type:  (PTFieldType)type field_value:  (PTObj*)field_value;
- (PTField*)FieldCreateWithString: (NSString *)field_name type:  (PTFieldType)type field_value:  (NSString *)field_value def_field_value:  (NSString *)def_field_value;
- (void)RefreshFieldAppearances;
- (void)RefreshAnnotAppearances: (PTRefreshOptions*)options;
- (void)FlattenAnnotations: (BOOL)forms_only;
- (PTObj*)GetAcroForm;
- (PTFDFDoc*)FDFExtract: (PTExtractFlag)flag;
- (PTFDFDoc*)FDFExtractAnnots: (PTVectorAnnot*)annotations;
- (PTFDFDoc*)FDFExtractCommand: (PTVectorAnnot*)annot_added annot_modified:  (PTVectorAnnot*)annot_modified annot_deleted:  (PTVectorAnnot*)annot_deleted;
- (void)FDFMerge: (PTFDFDoc*)fdf_doc;
- (void)FDFUpdate: (PTFDFDoc*)fdf_doc;
- (PTAction*)GetOpenAction;
- (void)SetOpenAction: (PTAction*)action;
- (void)AddFileAttachment: (NSString *)file_key embedded_file:  (PTFileSpec*)embedded_file;
- (PTPageLabel*)GetPageLabel: (int)page_num;
- (void)SetPageLabel: (int)page_num label:  (PTPageLabel*)label;
- (void)RemovePageLabel: (int)page_num;
- (BOOL)IsTagged;
- (PTSTree*)GetStructTree;
- (BOOL)HasOC;
- (PTObj*)GetOCGs;
- (PTConfig*)GetOCGConfig;
- (void)AddHighlights: (NSString *)hilite;
- (PTObj*)CreateIndirectName: (NSString *)name;
- (PTObj*)CreateIndirectArray;
- (PTObj*)CreateIndirectBool: (BOOL)value;
- (PTObj*)CreateIndirectDict;
- (PTObj*)CreateIndirectNull;
- (PTObj*)CreateIndirectNumber: (double)value;
- (PTObj*)CreateIndirectString: (NSData*)value size:  (unsigned int)size;
- (PTObj*)CreateIndirectStream: (PTFilterReader*)data filter_chain:  (PTFilter*)filter_chain;
- (PTSDFDoc*)GetSDFDoc;
- (void)Lock;
- (void)Unlock;
- (BOOL)TryLock: (int)milliseconds;
- (void)LockRead;
- (void)UnlockRead;
- (BOOL)TryLockRead: (int)milliseconds;
- (NSString *)GetFileName;
- (void)GenerateThumbnails: (unsigned int)size;
- (void)AppendVisualDiff: (PTPage*)p1 p2:  (PTPage*)p2 opts:  (PTDiffOptions*)opts;
- (void)SaveViewerOptimized: (NSString *)path opts:  (PTViewerOptimizedOptions*)opts;
- (PTSignaturesVerificationStatus)VerifySignedDigitalSignatures: (PTVerificationOptions*)in_opts;
+ (PTPDFDoc*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)init;- (id)initWithSdfdoc: (PTSDFDoc*)sdfdoc;- (id)initWithFilepath: (NSString *)filepath;- (id)initWithStream: (PTFilter*)stream;- (id)initWithBuf: (NSData*)buf buf_size:  (unsigned long)buf_size;
@end


@interface PTBitmapInfo : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setWidth: (int)value;
- (int)getWidth;
- (void)setHeight: (int)value;
- (int)getHeight;
- (void)setStride: (int)value;
- (int)getStride;
- (void)setDpi: (double)value;
- (double)getDpi;
- (NSData*)GetBuffer;
- (id)initWithW: (int)w h:  (int)h s:  (int)s d:  (double)d b:  (NSString *)b;
@end


@interface PTPDFDraw : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetRasterizerType: (PTRasterizerType)type;
- (void)SetDPI: (double)dpi;
- (void)SetImageSize: (int)width height:  (int)height preserve_aspect_ratio:  (BOOL)preserve_aspect_ratio;
- (void)SetPageBox: (PTBox)region;
- (void)SetClipRect: (PTPDFRect*)clip_rect;
- (void)SetFlipYAxis: (BOOL)flip_y;
- (void)SetRotate: (PTRotate)r;
- (void)SetDrawAnnotations: (BOOL)render_annots;
- (void)SetHighlightFields: (BOOL)highlight_fields;
- (void)SetAntiAliasing: (BOOL)enable_aa;
- (void)SetPathHinting: (BOOL)enable_hinting;
- (void)SetThinLineAdjustment: (BOOL)pixel_grid_fit stroke_adjust:  (BOOL)stroke_adjust;
- (void)SetImageSmoothing: (BOOL)smoothing_enabled hq_image_resampling:  (BOOL)hq_image_resampling;
- (void)SetCaching: (BOOL)enabled;
- (void)SetGamma: (double)exp;
- (void)SetOCGContext: (PTContext*)ctx;
- (void)SetPrintMode: (BOOL)is_printing;
- (void)SetDefaultPageColor: (unsigned char)r g:  (unsigned char)g b:  (unsigned char)b;
- (void)SetPageTransparent: (BOOL)is_transparent;
- (void)SetOverprint: (PTOverprintPreviewMode)op;
- (void)ExportWithObj: (PTPage*)page filename:  (NSString *)filename format:  (NSString *)format encoder_params:  (PTObj*)encoder_params;
- (void)Export: (PTPage*)page filename:  (NSString *)filename format:  (NSString *)format;
- (PTBitmapInfo*)GetBitmap: (PTPage*)page pix_fmt:  (PTPixelFormat)pix_fmt demult:  (BOOL)demult;
- (NSMutableArray*)GetSeparationBitmaps: (PTPage*)page;
- (void)SetErrorReportProc: (PTCallback*)instance;
- (void)SetColorPostProcessMode: (PTColorPostProcessMode)mode;
- (void)Destroy;
- (id)initWithDpi: (double)dpi;
@end


@interface PTConversionOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (NSString *)GetFileExtension;
- (PTConversionOptions*)SetFileExtension: (NSString *)value;
- (id)init;- (id)initWithValue: (NSString *)value;
@end


@interface PTOfficeToPDFOptions : PTConversionOptions
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)GetApplyPageBreaksToSheet;
- (PTOfficeToPDFOptions*)SetApplyPageBreaksToSheet: (BOOL)value;
- (BOOL)GetDisplayChangeTracking;
- (PTOfficeToPDFOptions*)SetDisplayChangeTracking: (BOOL)value;
- (double)GetExcelDefaultCellBorderWidth;
- (PTOfficeToPDFOptions*)SetExcelDefaultCellBorderWidth: (double)value;
- (unsigned int)GetExcelMaxAllowedCellCount;
- (PTOfficeToPDFOptions*)SetExcelMaxAllowedCellCount: (unsigned int)value;
- (NSString *)GetLayoutResourcesPluginPath;
- (PTOfficeToPDFOptions*)SetLayoutResourcesPluginPath: (NSString *)value;
- (NSString *)GetLocale;
- (PTOfficeToPDFOptions*)SetLocale: (NSString *)value;
- (NSString *)GetResourceDocPath;
- (PTOfficeToPDFOptions*)SetResourceDocPath: (NSString *)value;
- (NSString *)GetSmartSubstitutionPluginPath;
- (PTOfficeToPDFOptions*)SetSmartSubstitutionPluginPath: (NSString *)value;
- (NSString *)GetTemplateParamsJson;
- (PTOfficeToPDFOptions*)SetTemplateParamsJson: (NSString *)value;
- (id)init;
@end


@interface PTWordToPDFOptions : PTConversionOptions
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (NSString *)GetLayoutResourcesPluginPath;
- (PTWordToPDFOptions*)SetLayoutResourcesPluginPath: (NSString *)value;
- (NSString *)GetResourceDocPath;
- (PTWordToPDFOptions*)SetResourceDocPath: (NSString *)value;
- (NSString *)GetSmartSubstitutionPluginPath;
- (PTWordToPDFOptions*)SetSmartSubstitutionPluginPath: (NSString *)value;
- (id)init;
@end


@interface PTReflow : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (NSString *)GetHtml;
- (NSString *)GetAnnot: (NSString *)in_id;
- (NSString *)SetAnnot: (NSString *)in_json;
- (id)init;
@end


@interface PTDocumentConversion : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (PTResult)TryConvert;
- (void)Convert;
- (void)ConvertNextPage;
- (PTPDFDoc*)GetDoc;
- (PTResult)GetConversionStatus;
- (void)CancelConversion;
- (BOOL)IsCancelled;
- (BOOL)HasProgressTracking;
- (double)GetProgress;
- (NSString *)GetProgressLabel;
- (unsigned int)GetNumConvertedPages;
- (NSString *)GetErrorString;
- (unsigned int)GetNumWarnings;
- (NSString *)GetWarningString: (unsigned int)index;
+ (PTDocumentConversion*)CreateInternal: (unsigned long long)impl;
- (unsigned long long)GetHandleInternal;
- (id)init;
@end


@interface PTConversionMonitor : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)Next;
- (BOOL)Ready;
- (unsigned int)Progress;
- (PTFilter*)Filter;
- (void)Destroy;
- (id)init;
@end


@interface PTConvert : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (void)FromXpsWithFilename: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename;
+ (void)FromXpsWithBuffer: (PTPDFDoc*)in_pdfdoc buf:  (NSString *)buf buf_sz:  (unsigned long)buf_sz;
+ (void)FromEmf: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename;
+ (void)FromText: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename in_options:  (PTObj*)in_options;
+ (void)ToEmfWithPDFDoc: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename;
+ (void)ToEmfWithPage: (PTPage*)in_page in_filename:  (NSString *)in_filename;
+ (void)ToSvgWithPDFDoc: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename in_options:  (PTSVGOutputOptions*)in_options;
+ (void)ToSvg: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename;
+ (void)ToSvgWithPage: (PTPage*)in_page in_filename:  (NSString *)in_filename in_options:  (PTSVGOutputOptions*)in_options;
+ (void)ToXpsWithPDFDoc: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename options:  (PTXPSOutputOptions*)options;
+ (void)ToXps: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename;
+ (void)ToXpsWithFilename: (NSString *)in_inputFilename in_outputFilename:  (NSString *)in_outputFilename options:  (PTXPSOutputOptions*)options;
+ (void)ToXodWithFilename: (NSString *)in_filename out_filename:  (NSString *)out_filename options:  (PTXODOutputOptions*)options;
+ (void)ToXod: (NSString *)in_filename out_filename:  (NSString *)out_filename;
+ (void)ToXodWithPDFDoc: (PTPDFDoc*)in_pdfdoc out_filename:  (NSString *)out_filename options:  (PTXODOutputOptions*)options;
+ (void)ToHtmlWithFilename: (NSString *)in_filename out_path:  (NSString *)out_path options:  (PTHTMLOutputOptions*)options;
+ (void)ToHtml: (NSString *)in_filename out_path:  (NSString *)out_path;
+ (NSString *)PageToHtml: (PTPage*)page;
+ (NSString *)PageToHtmlZoned: (PTPage*)page json_zones:  (NSString *)json_zones;
+ (void)ToHtmlWithPDFDoc: (PTPDFDoc*)in_pdfdoc out_path:  (NSString *)out_path options:  (PTHTMLOutputOptions*)options;
+ (void)ToWordWithFilename: (NSString *)inputFilename outputPath:  (NSString *)outputPath options:  (PTWordOutputOptions*)options;
+ (void)ToWord: (NSString *)inputFilename outputPath:  (NSString *)outputPath;
+ (void)ToWordWithPDFDoc: (PTPDFDoc*)pdfdoc outputPath:  (NSString *)outputPath options:  (PTWordOutputOptions*)options;
+ (void)ToEpubWithFilename: (NSString *)in_filename out_path:  (NSString *)out_path html_options:  (PTHTMLOutputOptions*)html_options epub_options:  (PTEPUBOutputOptions*)epub_options;
+ (void)ToEpub: (NSString *)in_filename out_path:  (NSString *)out_path html_options:  (PTHTMLOutputOptions*)html_options;
+ (void)ToEpubWithPDFDoc: (PTPDFDoc*)in_pdfdoc out_path:  (NSString *)out_path html_options:  (PTHTMLOutputOptions*)html_options epub_options:  (PTEPUBOutputOptions*)epub_options;
+ (void)ToTiff: (NSString *)in_filename out_path:  (NSString *)out_path options:  (PTTiffOutputOptions*)options;
+ (PTFilter*)ToXodWithFilenameToStream: (NSString *)in_filename options:  (PTXODOutputOptions*)options;
+ (PTFilter*)ToXodWithPDFDocToStream: (PTPDFDoc*)in_pdfdoc options:  (PTXODOutputOptions*)options;
+ (PTConversionMonitor*)ToXodWithMonitorAndOptions: (PTPDFDoc*)in_pdfdoc options:  (PTXODOutputOptions*)options;
+ (PTConversionMonitor*)ToXodWithMonitor: (PTPDFDoc*)in_pdfdoc;
+ (void)WordToPDF: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename options:  (PTWordToPDFOptions*)options;
+ (PTDocumentConversion*)WordToPDFConversion: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename options:  (PTWordToPDFOptions*)options;
+ (void)OfficeToPDF: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename options:  (PTConversionOptions*)options;
+ (PTDocumentConversion*)StreamingPDFConversionWithDoc: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename options:  (PTConversionOptions*)options;
+ (PTDocumentConversion*)StreamingPDFConversion: (NSString *)in_filename options:  (PTConversionOptions*)options;
+ (PTReflow*)CreateReflow: (PTPage*)in_page json_zones:  (NSString *)json_zones;
+ (void)ToPdf: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename;
+ (void)FromCAD: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename opts:  (PTCADConvertOptions*)opts;
+ (void)FromDICOM: (PTPDFDoc*)in_pdfdoc in_filename:  (NSString *)in_filename opts:  (PTAdvancedImagingConvertOptions*)opts;
+ (void)FromTiff: (PTPDFDoc*)in_pdfdoc in_data:  (PTFilter*)in_data;
+ (BOOL)RequiresPrinter: (NSString *)in_filename;

@end


@interface PTXPSOutputCommonOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetPrintMode: (BOOL)print_mode;
- (void)SetDPI: (unsigned int)dpi;
- (void)SetRenderPages: (BOOL)render;
- (void)SetThickenLines: (BOOL)thicken;
- (void)GenerateURLLinks: (BOOL)generate;
- (void)SetOverprint: (PTXPSOverprintPreviewMode)mode;
- (void)setM_obj: (void *)value;
- (void *)getM_obj;
- (id)init;
@end


@interface PTXPSOutputOptions : PTXPSOutputCommonOptions
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetOpenXps: (BOOL)openxps;
- (id)init;
@end


@interface PTXODOutputOptions : PTXPSOutputCommonOptions
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetOutputThumbnails: (BOOL)include_thumbs;
- (void)SetThumbnailSize: (unsigned int)size;
- (void)SetElementLimit: (unsigned int)element_limit;
- (void)SetOpacityMaskWorkaround: (BOOL)opacity_render;
- (void)SetMaximumImagePixels: (unsigned int)max_pixels;
- (void)SetFlattenContent: (PTFlattenFlag)flatten;
- (void)SetFlattenThreshold: (PTFlattenThresholdFlag)threshold;
- (void)SetPreferJPG: (BOOL)prefer_jpg;
- (void)SetJPGQuality: (unsigned int)quality;
- (void)SetSilverlightTextWorkaround: (BOOL)workaround;
- (void)SetAnnotationOutput: (PTAnnotationOutputFlag)annot_output;
- (void)SetExternalParts: (BOOL)generate;
- (void)SetEncryptPassword: (NSString *)pass;
- (void)UseSilverlightFlashCompatible: (BOOL)compatible;
- (id)init;
@end


@interface PTHTMLOutputOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetPreferJPG: (BOOL)prefer_jpg;
- (void)SetJPGQuality: (unsigned int)quality;
- (void)SetDPI: (unsigned int)dpi;
- (void)SetMaximumImagePixels: (unsigned int)max_pixels;
- (void)SetContentReflowSetting: (PTHTMLContentReflowSetting)reflow;
- (void)SetScale: (double)scale;
- (void)SetExternalLinks: (BOOL)enable;
- (void)SetInternalLinks: (BOOL)enable;
- (void)SetSimplifyText: (BOOL)enable;
- (void)SetReportFile: (NSString *)path;
- (void)SetTitle: (NSString *)title;
- (void)SetImageDPI: (unsigned int)dpi;
- (void)SetEmbedImages: (BOOL)embed;
- (void)SetFileConversionTimeoutSeconds: (int)seconds;
- (void)SetPages: (int)pageFrom pageTo:  (int)pageTo;
- (void)SetPDFPassword: (NSString *)password;
- (void)SetSearchableImageSetting: (PTHTMLSearchableImageSetting)setting;
- (void)SetSimpleLists: (BOOL)enable;
- (void)SetConnectHyphens: (BOOL)connect;
- (void)SetDisableVerticalSplit: (BOOL)disable;
- (void)SetNoPageWidth: (BOOL)enable;
- (id)init;
@end


@interface PTWordOutputOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetJPGQuality: (unsigned int)quality;
- (void)SetImageDPI: (unsigned int)dpi;
- (void)SetWordOutputFormat: (PTWordOutputFormat)format;
- (void)SetFileConversionTimeoutSeconds: (int)seconds;
- (void)SetPages: (int)pageFrom pageTo:  (int)pageTo;
- (void)SetPDFPassword: (NSString *)password;
- (void)SetBookmarkConversionMethod: (PTBookmarkConversionMethod)method;
- (void)SetSearchableImageSetting: (PTWordSearchableImageSetting)setting;
- (void)SetShrinkCharacterSpacingToPreventWrap: (BOOL)shrink;
- (void)SetMatchPDFLineBreaks: (BOOL)match;
- (void)SetConnectHyphens: (BOOL)connect;
- (void)SetDoNotAdjustFonts: (BOOL)do_not_adjust;
- (void)SetDisableVerticalSplit: (BOOL)disable;
- (id)init;
@end


@interface PTEPUBOutputOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetExpanded: (BOOL)expanded;
- (void)SetReuseCover: (BOOL)reuse;
- (id)init;
@end


@interface PTSVGOutputOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetEmbedImages: (BOOL)embed_images;
- (void)SetNoFonts: (BOOL)no_fonts;
- (void)SetSvgFonts: (BOOL)svg_fonts;
- (void)SetEmbedFonts: (BOOL)embed_fonts;
- (void)SetNoUnicode: (BOOL)no_unicode;
- (void)SetIndividualCharPlacement: (BOOL)individual_char_placement;
- (void)SetRemoveCharPlacement: (BOOL)remove_char_placement;
- (void)SetFlattenContent: (PTFlattenFlag)flatten;
- (void)SetFlattenThreshold: (PTFlattenThresholdFlag)threshold;
- (void)SetFlattenDPI: (unsigned int)dpi;
- (void)SetFlattenMaximumImagePixels: (unsigned int)max_pixels;
- (void)SetCompress: (BOOL)svgz;
- (void)SetOutputThumbnails: (BOOL)include_thumbs;
- (void)SetThumbnailSize: (unsigned int)size;
- (void)SetCreateXmlWrapper: (BOOL)xml;
- (void)SetDtd: (BOOL)dtd;
- (void)SetAnnots: (BOOL)annots;
- (void)SetOverprint: (PTOverprintPreviewMode)mode;
- (id)init;
@end


@interface PTTiffOutputOptions : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetBox: (PTBox)type;
- (void)SetRotate: (PTRotate)rotation;
- (void)SetClip: (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
- (void)SetPages: (NSString *)page_desc;
- (void)SetOverprint: (PTOverprintPreviewMode)mode;
- (void)SetCMYK: (BOOL)enable;
- (void)SetDither: (BOOL)enable;
- (void)SetGray: (BOOL)enable;
- (void)SetMono: (BOOL)enable;
- (void)SetAnnots: (BOOL)enable;
- (void)SetSmooth: (BOOL)enable;
- (void)SetPrintmode: (BOOL)enable;
- (void)SetTransparentPage: (BOOL)enable;
- (void)SetPalettized: (BOOL)enable;
- (void)SetDPI: (double)dpi;
- (void)SetGamma: (double)gamma;
- (void)SetHRes: (int)hres;
- (void)SetVRes: (int)vres;
- (id)init;
@end


@interface PTPDFNet : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (void)Initialize: (NSString *)license_key;
+ (void)EnableJavaScript: (BOOL)enable;
+ (BOOL)IsJavaScriptEnabled;
+ (BOOL)SetResourcesPath: (NSString *)path;
+ (NSString *)GetResourcesPath;
+ (void)AddResourceSearchPath: (NSString *)path;
+ (double)GetVersion;
+ (void)SetColorManagement: (PTCMSType)t;
+ (void)SetDefaultDeviceCMYKProfile: (NSString *)icc_filename;
+ (void)SetDefaultDeviceRGBProfile: (NSString *)icc_filename;
+ (void)SetDefaultDiskCachingEnabled: (BOOL)use_disk;
+ (void)SetDefaultFlateCompressionLevel: (int)level;
+ (void)SetViewerCache: (unsigned long)max_cache_size on_disk:  (BOOL)on_disk;
+ (BOOL)AddFontSubstWithFontName: (NSString *)fontname fontpath:  (NSString *)fontpath;
+ (BOOL)AddFontSubstWithOrdering: (PTCharacterOrdering)ordering fontpath:  (NSString *)fontpath;
+ (void)SetTempPath: (NSString *)temp_path;
+ (void)SetPersistentCachePath: (NSString *)persistent_path;
+ (NSString *)GetSystemFontList;
+ (void)SetLogLevel: (PTLogLevel)level;
+ (void)AddPDFTronCustomHandler: (unsigned int)custom_id;
- (id)init;
@end


@interface PTPDFView : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetDoc: (PTPDFDoc*)doc;
- (void)OpenUniversalDoc: (PTDocumentConversion*)conversion;
- (void)CloseDoc;
- (PTPDFDoc*)GetDoc;
- (void)DocLock: (BOOL)cancel_threads;
- (void)DocUnlock;
- (BOOL)DocTryLock: (int)milliseconds;
- (void)DocLockRead;
- (void)DocUnlockRead;
- (BOOL)DocTryLockRead: (int)milliseconds;
- (void)SetPagePresentationMode: (PTPagePresentationMode)mode;
- (PTPagePresentationMode)GetPagePresentationMode;
- (void)SetColorPostProcessMode: (PTColorPostProcessMode)mode;
- (void)SetColorPostProcessMapFile: (PTFilter*)image_file_contents;
- (void)SetColorPostProcessColors: (unsigned int)white_color black_color:  (unsigned int)black_color;
- (PTColorPostProcessMode)GetColorPostProcessMode;
- (int)GetCurrentPage;
- (int)GetPageCount;
- (BOOL)GotoFirstPage;
- (BOOL)GotoLastPage;
- (BOOL)GotoNextPage;
- (BOOL)GotoPreviousPage;
- (BOOL)SetCurrentPage: (int)page_num;
- (BOOL)ShowRect: (int)page_num rect:  (PTPDFRect*)rect;
- (NSArray<NSNumber *> *)GetVisiblePages;
- (double)GetZoom;
- (BOOL)SetZoom: (double)zoom;
- (BOOL)SetZoomWithCoord: (int)x y:  (int)y zoom:  (double)zoom;
- (BOOL)SmartZoom: (int)x y:  (int)y;
- (void)RotateClockwise;
- (void)RotateCounterClockwise;
- (PTRotate)GetRotation;
- (int)GetPageNumberFromScreenPt: (double)x y:  (double)y;
- (PTPDFPoint*)ConvScreenPtToCanvasPt: (PTPDFPoint*)pt;
- (PTPDFPoint*)ConvCanvasPtToScreenPt: (PTPDFPoint*)pt;
- (PTPDFPoint*)ConvCanvasPtToPagePt: (PTPDFPoint*)pt page_num:  (int)page_num;
- (PTPDFPoint*)ConvPagePtToCanvasPt: (PTPDFPoint*)pt page_num:  (int)page_num;
- (PTPDFPoint*)ConvScreenPtToPagePt: (PTPDFPoint*)pt page_num:  (int)page_num;
- (PTPDFPoint*)ConvPagePtToScreenPt: (PTPDFPoint*)pt page_num:  (int)page_num;
- (PTPDFPoint*)SnapToNearestInDoc: (PTPDFPoint*)screen_pt;
- (void)SetSnappingMode: (unsigned int)mode_flags;
- (PTMatrix2D*)GetDeviceTransform: (int)page_num;
- (void)SetErrorReportProc: (PTCallback*)instance;
- (void)SetCurrentPageProc: (PTCallback*)instance;
- (void)SetJavaScriptEventCallBack: (PTCallback*)instance;
- (void)SetCurrentZoomProc: (PTCallback*)instance;
- (void)ExecuteAction: (PTAction*)action;
- (void)ExecuteActionWithActionParameter: (PTActionParameter*)action_param;
- (double)GetCanvasWidth;
- (double)GetCanvasHeight;
- (double)GetHScrollPos;
- (double)GetVScrollPos;
- (void)OnScroll: (int)pix_dx pix_dy:  (int)pix_dy;
- (void)SetHScrollPos: (double)pos;
- (void)SetVScrollPos: (double)pos;
- (void)OnSize: (int)width height:  (int)height;
- (BOOL)IsFinishedRendering: (BOOL)visible_region_only;
- (void)CancelRendering;
- (void)Update: (BOOL)all;
- (void)UpdateWithRect: (PTPDFRect*)update;
- (void)UpdateWithAnnot: (PTAnnot*)annot page_num:  (int)page_num;
- (void)UpdateWithField: (PTField*)field;
- (void)UpdatePageLayout;
- (NSData*)GetBuffer;
- (void)UpdateBuffer;
- (int)GetBufferWidth;
- (int)GetBufferHeight;
- (int)GetBufferStride;
- (void)HideAnnotation: (PTAnnot*)annot;
- (void)ShowAnnotation: (PTAnnot*)annot;
- (void)SetDrawAnnotations: (BOOL)render_annots;
- (void)SetUrlExtraction: (BOOL)enabled;
- (PTLinkInfo*)GetLinkAt: (int)x y:  (int)y;
- (void)SetHighlightFields: (BOOL)highlight_fields;
- (void)SetRequiredFieldBorderColor: (PTColorPt*)new_border_color;
- (void)SetAntiAliasing: (BOOL)enable_aa;
- (void)SetPathHinting: (BOOL)enable_hinting;
- (void)SetThinLineAdjustment: (BOOL)pixel_grid_fit stroke_adjust:  (BOOL)stroke_adjust;
- (void)SetImageSmoothing: (BOOL)smoothing_enabled;
- (void)SetCaching: (BOOL)enabled;
- (void)SetRasterizerType: (PTRasterizerType)type;
- (void)SetGamma: (double)exp;
- (void)SetOverprint: (PTOverprintPreviewMode)op;
- (void)SetOCGContext: (PTContext*)ctx;
- (PTContext*)GetOCGContext;
- (void)UpdateOCGContext;
- (void)SetRenderBeginProc: (PTCallback*)instance;
- (void)SetRenderFinishProc: (PTCallback*)instance;
- (void)SetTextSelectionMode: (PTTextSelectionMode)tm;
- (BOOL)SelectWithTextSelect: (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
- (BOOL)SelectWithSnapping: (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2 snap_to_start:  (BOOL)snap_to_start snap_to_end:  (BOOL)snap_to_end;
- (BOOL)SelectWithSmartSnapping: (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
- (BOOL)SelectWithStructure: (double)x1 y1:  (double)y1 page1:  (int)page1 x2:  (double)x2 y2:  (double)y2 page2:  (int)page2;
- (BOOL)SelectWithHighlights: (PTHighlights*)highlights;
- (BOOL)SelectWithSelection: (PTSelection*)select;
- (void)CancelFindText;
- (void)SelectAll;
- (BOOL)HasSelection;
- (void)ClearSelection;
- (PTSelection*)GetSelection: (int)pagenum;
- (int)GetSelectionBeginPage;
- (int)GetSelectionEndPage;
- (BOOL)HasSelectionOnPage: (int)ipage;
- (void)PrepareWords: (int)page_num;
- (BOOL)WereWordsPrepared: (int)page_num;
- (BOOL)IsThereTextInRect: (double)x1 y1:  (double)y1 x2:  (double)x2 y2:  (double)y2;
- (void)PrepareAnnotsForMouse: (int)page_num distance_threshold:  (double)distance_threshold minimum_line_weight:  (double)minimum_line_weight;
- (BOOL)WereAnnotsForMousePrepared: (int)page_num;
- (PTAnnotType)GetAnnotTypeUnder: (double)x y:  (double)y;
- (void)SetPageBorderVisibility: (BOOL)border_visible;
- (void)SetPageTransparencyGrid: (BOOL)trans_grid_visible;
- (void)SetDefaultPageColor: (unsigned char)r g:  (unsigned char)g b:  (unsigned char)b;
- (void)SetBackgroundColor: (unsigned char)r g:  (unsigned char)g b:  (unsigned char)b a:  (unsigned char)a;
- (void)SetHorizontalAlign: (int)align;
- (void)SetVerticalAlign: (int)align;
- (void)SetPageSpacing: (int)horiz_col_space vert_col_space:  (int)vert_col_space horiz_pad:  (int)horiz_pad vert_pad:  (int)vert_pad;
+ (void)SetViewerCache: (PTSDFDoc*)document max_cache_size:  (unsigned long)max_cache_size on_disk:  (BOOL)on_disk;
- (void)Destroy;
- (void)SetDevicePixelDensity: (double)dpi scale_factor:  (double)scale_factor;
- (PTPDFRect*)GetScreenRectForAnnot: (PTAnnot*)annot page_num:  (int)page_num;
- (PTAnnot*)GetAnnotationAt: (int)x y:  (int)y distanceThreshold:  (double)distanceThreshold minimumLineWeight:  (double)minimumLineWeight;
- (void)SetPageViewMode: (PTPageViewMode)mode;
- (PTPageViewMode)GetPageViewMode;
- (void)RefreshAndUpdate: (PTViewChangeCollection*)view_change;
- (void)SetPageRefViewMode: (PTPageViewMode)mode;
- (PTPageViewMode)GetPageRefViewMode;
- (void)SetupThumbnails: (BOOL)use_embedded generate_at_runtime:  (BOOL)generate_at_runtime use_disk_cache:  (BOOL)use_disk_cache thumb_max_side_length:  (int)thumb_max_side_length max_abs_cache_size:  (unsigned long)max_abs_cache_size max_perc_cache_size:  (double)max_perc_cache_size;
- (void)ClearThumbCache;
- (void)GetThumbAsync: (int)page_num instance:  (PTCallback*)instance;
- (unsigned long)GetThumbInCacheSize: (int)page_num;
- (BOOL)GetThumbInCache: (int)page_num buf:  (NSData*)buf out_width:  (unsigned int)out_width out_height:  (unsigned int)out_height;
- (void)CancelAllThumbRequests;
- (void)SetRequestRenderInWorkerThreadProc: (PTCallback*)instance;
- (void)SetFindTextHandler: (PTCallback*)instance;
- (void)FindTextAsync: (NSString *)search_str match_case:  (BOOL)match_case match_whole_word:  (BOOL)match_whole_word search_up:  (BOOL)search_up reg_exp:  (BOOL)reg_exp;
- (NSArray<PTAnnot *> *)GetAnnotationsOnPage: (int)page_num;
- (NSArray<PTAnnot *> *)GetAnnotationListAt: (int)x1 y1:  (int)y1 x2:  (int)x2 y2:  (int)y2;
- (void)EnableUndoRedo;
- (NSString *)Undo;
- (NSString *)Redo;
- (void)TakeSnapshot: (NSString *)meta_info;
- (NSString *)GetNextUndoInfo;
- (NSString *)GetNextRedoInfo;
- (void)RevertAllChanges;
- (PTExternalAnnotManager*)GetExternalAnnotManager: (NSString *)author mode:  (PTExternalAnnotManagerMode)mode;
- (id)init;
@end


@interface Print : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (void)StartPrintJob: (PTPDFDoc*)in_pdfdoc in_printerName:  (NSString *)in_printerName in_jobName:  (NSString *)in_jobName in_outputFileName:  (NSString *)in_outputFileName in_pagesToPrint:  (PTPageSet*)in_pagesToPrint in_printerMode:  (PTPrinterMode*)in_printerMode in_cancel:  (BOOL *)in_cancel in_context:  (PTContext*)in_context;
- (id)init;
@end


@interface PTPrinterMode : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetAutoCenter: (BOOL)autoCenter;
- (void)SetAutoRotate: (BOOL)autoRotate;
- (void)SetCollation: (BOOL)collation;
- (void)SetCopyCount: (int)copyCount;
- (void)SetDPI: (int)dpi;
- (void)SetDuplexing: (DuplexMode)mode;
- (void)SetNUp: (NUp)nup pageOrder:  (NUpPageOrder)pageOrder;
- (void)SetOrientation: (Orientation)orientation;
- (void)SetOutputAnnot: (PrintContentTypes)printContent;
- (void)SetOutputColor: (OutputColor)color;
- (void)SetOutputQuality: (OutputQuality)quality;
- (void)SetOutputPageBorder: (BOOL)printBorder;
- (void)SetPaperSize: (PTPDFRect*)size;
- (void)SetScale: (double)scale;
- (void)SetScaleType: (PTPrintScaleType)scaleType;
- (void)SetUseRleImageCompression: (BOOL)useRleImageCompression;
- (id)init;
@end


@interface PTHTML2PDF : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)InsertFromURL: (NSString *)url;
- (void)InsertFromURLWithSettings: (NSString *)url settings:  (PTWebPageSettings*)settings;
- (void)InsertFromHtmlString: (NSString *)html;
- (void)InsertFromHtmlStringWithSettings: (NSString *)html settings:  (PTWebPageSettings*)settings;
- (void)InsertTOC;
- (void)InsertTOCWithSettings: (PTTOCSettings*)settings;
- (BOOL)Convert: (PTPDFDoc*)doc;
- (int)GetHTTPErrorCode;
- (void)SetQuiet: (BOOL)quiet;
- (NSString *)GetLog;
+ (void)SetModulePath: (NSString *)path;
- (void)SetPaperSize: (PaperSize)size;
- (void)SetPaperSizeWithWidthAndHeight: (NSString *)width height:  (NSString *)height;
- (void)SetLandscape: (BOOL)enable;
- (void)SetDPI: (int)dpi;
- (void)SetOutline: (BOOL)enable depth:  (int)depth;
- (void)DumpOutline: (NSString *)xml_file;
- (void)SetPDFCompression: (BOOL)enable;
- (void)SetMargins: (NSString *)top bottom:  (NSString *)bottom left:  (NSString *)left right:  (NSString *)right;
- (void)SetImageDPI: (int)dpi;
- (void)SetImageQuality: (int)quality;
- (void)SetCookieJar: (NSString *)path;
- (void)Destroy;
- (id)init;
@end


@interface PTProxy : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetType: (PTProxyType)type;
- (void)SetHost: (NSString *)host;
- (void)SetPort: (int)port;
- (void)SetUsername: (NSString *)username;
- (void)SetPassword: (NSString *)password;
- (void)Destroy;
- (id)init;
@end


@interface PTWebPageSettings : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetPrintBackground: (BOOL)background;
- (void)SetLoadImages: (BOOL)load;
- (void)SetAllowJavaScript: (BOOL)enable;
- (void)SetSmartShrinking: (BOOL)enable;
- (void)SetMinimumFontSize: (int)size;
- (void)SetDefaultEncoding: (NSString *)encoding;
- (void)SetUserStyleSheet: (NSString *)url;
- (void)SetAllowPlugins: (BOOL)enable;
- (void)SetPrintMediaType: (BOOL)print;
- (void)SetIncludeInOutline: (BOOL)include;
- (void)SetUsername: (NSString *)username;
- (void)SetPassword: (NSString *)password;
- (void)SetJavaScriptDelay: (int)msec;
- (void)SetZoom: (double)zoom;
- (void)SetBlockLocalFileAccess: (BOOL)block;
- (void)SetStopSlowScripts: (BOOL)stop;
- (void)SetDebugJavaScriptOutput: (BOOL)forward;
- (void)SetLoadErrorHandling: (PTErrorHandling)type;
- (void)SetExternalLinks: (BOOL)convert;
- (void)SetInternalLinks: (BOOL)convert;
- (void)SetProduceForms: (BOOL)forms;
- (void)SetProxy: (PTProxy*)proxy;
- (void)Destroy;
- (id)init;
@end


@interface PTTOCSettings : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)SetDottedLines: (BOOL)enable;
- (void)SetLinks: (BOOL)enable;
- (void)SetCaptionText: (NSString *)caption;
- (void)SetLevelIndentation: (int)indentation;
- (void)SetTextSizeShrink: (double)shrink;
- (void)SetXsl: (NSString *)style_sheet;
- (void)Destroy;
- (id)init;
@end


@interface PTStamper : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)StampImage: (PTPDFDoc*)dest_doc src_img:  (PTImage*)src_img dest_pages:  (PTPageSet*)dest_pages;
- (void)StampPage: (PTPDFDoc*)dest_doc src_page:  (PTPage*)src_page dest_pages:  (PTPageSet*)dest_pages;
- (void)StampText: (PTPDFDoc*)dest_doc src_txt:  (NSString *)src_txt dest_pages:  (PTPageSet*)dest_pages;
- (void)SetFont: (PTFont*)font;
- (void)SetFontColor: (PTColorPt*)color;
- (void)SetOpacity: (double)opacity;
- (void)SetRotation: (double)rotation;
- (void)SetAsBackground: (BOOL)background;
- (void)SetAsAnnotation: (BOOL)annotation;
- (void)ShowsOnScreen: (BOOL)on_screen;
- (void)ShowsOnPrint: (BOOL)on_print;
- (void)SetPosition: (double)horizontal_distance vertical_distance:  (double)vertical_distance use_percentage:  (BOOL)use_percentage;
- (void)SetAlignment: (PTHorizontalAlignment)horizontal_alignment vertical_alignment:  (PTVerticalAlignment)vertical_alignment;
- (void)SetTextAlignment: (PTTextAlignment)text_alignment;
- (void)SetSize: (PTSizeType)size_type a:  (double)a b:  (double)b;
+ (void)DeleteStamps: (PTPDFDoc*)doc page_set:  (PTPageSet*)page_set;
+ (BOOL)HasStamps: (PTPDFDoc*)doc page_set:  (PTPageSet*)page_set;
- (void)Destroy;
- (id)initWithSize_type: (PTSizeType)size_type a:  (double)a b:  (double)b;
@end


@interface PTTextExtractor : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Begin: (PTPage*)page clip_ptr:  (PTPDFRect*)clip_ptr flags:  (unsigned int)flags;
- (void)SetOCGContext: (PTContext*)ctx;
- (int)GetWordCount;
- (void)SetRightToLeftLanguage: (BOOL)rtl;
- (BOOL)GetRightToLeftLanguage;
- (NSString *)GetAsText: (BOOL)dehyphen;
- (NSString *)GetTextUnderAnnot: (PTAnnot*)annot;
- (NSString *)GetAsXML: (unsigned int)xml_output_flags;
- (int)GetNumLines;
- (PTTextExtractorLine*)GetFirstLine;
- (void)Destroy;
- (id)init;
@end


@interface PTTextExtractorStyle : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (PTObj*)GetFont;
- (NSString *)GetFontName;
- (double)GetFontSize;
- (int)GetWeight;
- (BOOL)IsItalic;
- (BOOL)IsSerif;
- (NSArray<NSNumber *> *)GetColor;
- (BOOL)isEqualTo: (PTTextExtractorStyle*)s;
- (id)init;
@end


@interface PTWord : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (int)GetNumGlyphs;
- (PTPDFRect*)GetBBox;
- (NSMutableArray*)GetQuad;
- (NSMutableArray*)GetGlyphQuad: (int)glyph_idx;
- (PTTextExtractorStyle*)GetCharStyle: (int)char_idx;
- (PTTextExtractorStyle*)GetStyle;
- (int)GetStringLen;
- (NSString *)GetString;
- (PTWord*)GetNextWord;
- (int)GetCurrentNum;
- (BOOL)IsValid;
- (BOOL)isEqualTo: (PTWord*)arg0;
- (id)init;
@end


@interface PTTextExtractorLine : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (int)GetNumWords;
- (BOOL)IsSimpleLine;
- (PTPDFRect*)GetBBox;
- (NSMutableArray*)GetQuad;
- (PTWord*)GetFirstWord;
- (PTWord*)GetWord: (int)word_idx;
- (PTTextExtractorLine*)GetNextLine;
- (int)GetCurrentNum;
- (PTTextExtractorStyle*)GetStyle;
- (int)GetParagraphID;
- (int)GetFlowID;
- (BOOL)EndsWithHyphen;
- (BOOL)IsValid;
- (BOOL)isEqualTo: (PTTextExtractorLine*)arg0;
- (id)init;
@end


@interface PTSearchResult : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)IsFound;
- (BOOL)IsDocEnd;
- (BOOL)IsPageEnd;
- (int)GetPageNumber;
- (NSString *)GetMatch;
- (NSString *)GetAmbientString;
- (PTHighlights*)GetHighlights;
- (id)init;
@end


@interface PTTextSearch : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (BOOL)Begin: (PTPDFDoc*)doc pattern:  (NSString *)pattern mode:  (unsigned int)mode start_page:  (int)start_page end_page:  (int)end_page;
- (PTSearchResult*)Run;
- (BOOL)SetPattern: (NSString *)pattern;
- (unsigned int)GetMode;
- (void)SetMode: (unsigned int)mode;
- (void)SetRightToLeftLanguage: (BOOL)flag;
- (int)GetCurrentPage;
- (void)SetOCGContext: (PTContext*)context;
- (void)Destroy;
- (id)init;
@end


@interface PTWebFontDownloader : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (BOOL)IsAvailable;
+ (void)EnableDownloads;
+ (void)DisableDownloads;
+ (void)PreCacheAsync;
+ (void)ClearCache;
+ (void)SetCustomWebFontURL: (NSString *)url;
- (id)init;
@end


@interface PTPDFDocGenerator : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (PTPDFDoc*)GenerateBlankPaperDoc: (double)width height:  (double)height background_red:  (double)background_red background_green:  (double)background_green background_blue:  (double)background_blue;
+ (PTPDFDoc*)GenerateGridPaperDoc: (double)width height:  (double)height grid_spacing:  (double)grid_spacing line_thickness:  (double)line_thickness red:  (double)red green:  (double)green blue:  (double)blue background_red:  (double)background_red background_green:  (double)background_green background_blue:  (double)background_blue;
+ (PTPDFDoc*)GenerateLinedPaperDoc: (double)width height:  (double)height line_spacing:  (double)line_spacing line_thickness:  (double)line_thickness red:  (double)red green:  (double)green blue:  (double)blue left_margin_distance:  (double)left_margin_distance left_margin_red:  (double)left_margin_red left_margin_green:  (double)left_margin_green left_margin_blue:  (double)left_margin_blue right_margin_red:  (double)right_margin_red right_margin_green:  (double)right_margin_green right_margin_blue:  (double)right_margin_blue background_red:  (double)background_red background_green:  (double)background_green background_blue:  (double)background_blue top_margin_distance:  (double)top_margin_distance bottom_margin_distance:  (double)bottom_margin_distance;
+ (PTPDFDoc*)GenerateGraphPaperDoc: (double)width height:  (double)height grid_spacing:  (double)grid_spacing line_thickness:  (double)line_thickness weighted_line_thickness:  (double)weighted_line_thickness weighted_line_freq:  (int)weighted_line_freq red:  (double)red green:  (double)green blue:  (double)blue background_red:  (double)background_red background_green:  (double)background_green background_blue:  (double)background_blue;
+ (PTPDFDoc*)GenerateMusicPaperDoc: (double)width height:  (double)height margin:  (double)margin staves:  (int)staves linespace_size_pts:  (double)linespace_size_pts line_thickness:  (double)line_thickness red:  (double)red green:  (double)green blue:  (double)blue background_red:  (double)background_red background_green:  (double)background_green background_blue:  (double)background_blue;
+ (PTPDFDoc*)GenerateDottedPaperDoc: (double)width height:  (double)height dot_spacing:  (double)dot_spacing dot_size:  (double)dot_size red:  (double)red green:  (double)green blue:  (double)blue background_red:  (double)background_red background_green:  (double)background_green background_blue:  (double)background_blue;
+ (PTPDFDoc*)GenerateIsometricDottedPaperDoc: (double)width height:  (double)height dot_spacing:  (double)dot_spacing dot_size:  (double)dot_size red:  (double)red green:  (double)green blue:  (double)blue background_red:  (double)background_red background_green:  (double)background_green background_blue:  (double)background_blue;
- (id)init;
@end


@interface PTRedactor : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
+ (void)Redact: (PTPDFDoc*)doc red_arr:  (PTVectorRedaction*)red_arr app:  (PTAppearance*)app ext_neg_mode:  (BOOL)ext_neg_mode page_coord_sys:  (BOOL)page_coord_sys;
- (id)init;
@end


@interface PTRedaction : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)Destroy;
- (id)initWithPage_num: (int)page_num bbox:  (PTPDFRect*)bbox negative:  (BOOL)negative text:  (NSString *)text;
@end


@interface PTAppearance : NSObject
{
	void *swigCPtr;
	BOOL swigCMemOwn;
}
- (void*)getCptr;
- (instancetype)initWithCptr: (void*) cptr;
- (void)setSwigCMemOwn: (BOOL) own;
- (void)dealloc;
- (void)setRedactionOverlay: (BOOL)value;
- (BOOL)getRedactionOverlay;
- (void)setPositiveOverlayColor: (PTColorPt*)value;
- (PTColorPt*)getPositiveOverlayColor;
- (void)setNegativeOverlayColor: (PTColorPt*)value;
- (PTColorPt*)getNegativeOverlayColor;
- (void)setBorder: (BOOL)value;
- (BOOL)getBorder;
- (void)setUseOverlayText: (BOOL)value;
- (BOOL)getUseOverlayText;
- (void)setTextFont: (PTFont*)value;
- (PTFont*)getTextFont;
- (void)setMinFontSize: (double)value;
- (double)getMinFontSize;
- (void)setMaxFontSize: (double)value;
- (double)getMaxFontSize;
- (void)setTextColor: (PTColorPt*)value;
- (PTColorPt*)getTextColor;
- (void)setHorizTextAlignment: (int)value;
- (int)getHorizTextAlignment;
- (void)setVertTextAlignment: (int)value;
- (int)getVertTextAlignment;
- (void)setShowRedactedContentRegions: (BOOL)value;
- (BOOL)getShowRedactedContentRegions;
- (void)setRedactedContentColor: (PTColorPt*)value;
- (PTColorPt*)getRedactedContentColor;
- (id)init;
@end



#if defined(USE_PDFNET_COMPAT)
#include "CompatibilityAlias.h"
#endif // defined(USE_PDFNET_COMPAT)

#endif // PDFNetOBJC_H

