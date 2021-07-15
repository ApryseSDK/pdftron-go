//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFBookmark
#define PDFTRON_H_CPDFBookmark

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_BookmarkCreate(TRN_PDFDoc in_doc, TRN_UString in_title, TRN_Bookmark* result);

TRN_API TRN_BookmarkCreateFromObj(TRN_Obj in_bookmark_dict, TRN_Bookmark* result);

TRN_API TRN_BookmarkCopy(const TRN_Bookmark in_bookmark, TRN_Bookmark* result);

TRN_API TRN_BookmarkCompare(TRN_Bookmark bm, const TRN_Bookmark in_bookmark, TRN_Bool* result);

TRN_API TRN_BookmarkIsValid(const TRN_Bookmark bm, TRN_Bool* result);

TRN_API TRN_BookmarkHasChildren(TRN_Bookmark bm, TRN_Bool* result);

TRN_API TRN_BookmarkGetNext(TRN_Bookmark bm, TRN_Bookmark* result);

TRN_API TRN_BookmarkGetPrev(TRN_Bookmark bm, TRN_Bookmark* result);

TRN_API TRN_BookmarkGetFirstChild(TRN_Bookmark bm, TRN_Bookmark* result);

TRN_API TRN_BookmarkGetLastChild(TRN_Bookmark bm, TRN_Bookmark* result);

TRN_API TRN_BookmarkGetParent(TRN_Bookmark bm, TRN_Bookmark* result);

TRN_API TRN_BookmarkFind(TRN_Bookmark bm, const TRN_UString in_title, TRN_Bookmark* result);

TRN_API TRN_BookmarkAddNewChild(TRN_Bookmark bm, const TRN_UString in_title, TRN_Bookmark* result);

TRN_API TRN_BookmarkAddChild(TRN_Bookmark bm, TRN_Bookmark in_bookmark);

TRN_API TRN_BookmarkAddNewNext(TRN_Bookmark bm, const TRN_UString in_title, TRN_Bookmark* result);

TRN_API TRN_BookmarkAddNext(TRN_Bookmark bm, TRN_Bookmark in_bookmark);

TRN_API TRN_BookmarkAddNewPrev(TRN_Bookmark bm, const TRN_UString in_title, TRN_Bookmark* result);

TRN_API TRN_BookmarkAddPrev(TRN_Bookmark bm,TRN_Bookmark in_bookmark);

TRN_API TRN_BookmarkDelete(TRN_Bookmark bm);

TRN_API TRN_BookmarkUnlink(TRN_Bookmark bm);

TRN_API TRN_BookmarkGetIndent(TRN_Bookmark bm, int* result);

TRN_API TRN_BookmarkIsOpen(TRN_Bookmark bm, TRN_Bool* result);

TRN_API TRN_BookmarkSetOpen(TRN_Bookmark bm, TRN_Bool in_open);

TRN_API TRN_BookmarkGetOpenCount(TRN_Bookmark bm, int* result);

TRN_API TRN_BookmarkGetTitle(TRN_Bookmark bm, TRN_UString* result);

TRN_API TRN_BookmarkGetTitleObj(TRN_Bookmark bm, TRN_Obj* result);

TRN_API TRN_BookmarkSetTitle(TRN_Bookmark bm, const TRN_UString title);

TRN_API TRN_BookmarkGetAction(TRN_Bookmark bm, TRN_Action* result);

TRN_API TRN_BookmarkSetAction(TRN_Bookmark bm, TRN_Action in_action);

TRN_API TRN_BookmarkRemoveAction(TRN_Bookmark bm);

TRN_API TRN_BookmarkGetFlags(TRN_Bookmark bm, int* result);

TRN_API TRN_BookmarkSetFlags(TRN_Bookmark bm, int in_flags);

TRN_API TRN_BookmarkGetColor(TRN_Bookmark bm, double* out_r, double* out_g, double* out_b);

TRN_API TRN_BookmarkSetColor(TRN_Bookmark bm, double in_r, double in_g, double in_b);

TRN_API TRN_BookmarkGetSDFObj(const TRN_Bookmark bm, TRN_Obj* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFBookmark
