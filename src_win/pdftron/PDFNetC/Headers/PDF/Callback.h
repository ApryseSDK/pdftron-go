//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFCallback
#define PDFTRON_H_CPPPDFCallback

#ifdef SWIG

#include <C/Common/TRN_Types.h>
#include <Common/BasicTypes.h>
#include <PDF/Selection.h>

namespace pdftron { 
	namespace PDF {

/**
 *	SWIG director's base class
 *
 *	Contains virtual functions which match the signature of the PDFNet function pointers.
 *  Each virtual function has a matching static function calling it.
 *	User extends this class in the target language and overrides the function of interest.
 *	The static function is assigned to the function pointer.
 */
class Callback
{
public:
	Callback() {}
	virtual ~Callback() {
	}

// PDFView Callbacks
	virtual void RenderBeginEventProc(){}

	static void StaticRenderBeginEventProc(void* data)
	{
		Callback* cb = (Callback*) data;
		cb->RenderBeginEventProc();
	}

	virtual void RenderFinishEventProc(bool cancelled){}

	static void StaticRenderFinishEventProc(void* data, bool cancelled)
	{
		Callback* cb = (Callback*) data;
		cb->RenderFinishEventProc(cancelled);
	}

	virtual void ErrorReportProc (const char* message) {}

	static void StaticErrorReportProc (const char* message, void* data)
	{
		Callback* cb = (Callback*) data;
		cb->ErrorReportProc(message);
	}

	virtual void CurrentPageProc(int current_page, int num_pages) {}

	static void StaticCurrentPageProc(int current_page, int num_pages, void* data)
	{
		Callback* cb = (Callback*) data;
		cb->CurrentPageProc(current_page, num_pages);
	}

	virtual void JavaScriptEventProc(const char* event_type, const char* json) {}

	static void StaticJavaScriptEventProc(const char* event_type, const char* json, void* data)
	{
		Callback* cb= (Callback*) data;
		cb->JavaScriptEventProc(event_type,json);
	}

	virtual void CurrentZoomProc(double curr_zoom_proc) {}

	static void StaticCurrentZoomProc(double curr_zoom_proc, void* data)
	{
		Callback* cb = (Callback*) data;
		cb->CurrentZoomProc(curr_zoom_proc);
	}

	virtual void ThumbAsyncHandler(int page_num, bool was_thumb_found, const char* thumb_buf, int thumb_width, int thumb_height) {}
	
	static void StaticThumbAsyncHandler(int page_num, bool was_thumb_found, const char* thumb_buf, int thumb_width, int thumb_height, void* custom_data)
	{
		Callback* cb = (Callback*) custom_data;
		cb->ThumbAsyncHandler(page_num, was_thumb_found, thumb_buf, thumb_width, thumb_height);
	}

	virtual void RequestRenderInWorkerThread() {}

	static void StaticRequestRenderInWorkerThread(void* custom_data)
	{
		Callback* cb = (Callback*) custom_data;
		cb->RequestRenderInWorkerThread();
	}

	virtual void FindTextHandler(bool success, PDF::Selection selection) {}

	static void StaticFindTextHandler(bool success, PDF::Selection selection, void* custom_data)
	{
		Callback* cb = (Callback*) custom_data;
		cb->FindTextHandler(success, selection);
	}
	
	virtual void CreateTileProc(
    	char* buffer, int originX, int originY, int width, int height,
       	int pagNum, long long cellNumber,
       	bool finalRender, bool predictionRender,
       	int tilesRemaining, bool firstTile,
       	int canvasWidth, int canvasHeight, int cellSideLength, int cellPerRow, int cellPerCol,
       	int thumbnailId
   	) { }
	
	static void StaticCreateTileProc(             
       	void* customData,
    	char* buffer, int originX, int originY, int width, int height,
       	int pageNum, long long cellNumber,
       	bool finalRender, bool predictionRender,
       	int tilesRemaining, bool firstTile,
       	int canvasWidth, int canvasHeight, int cellSideLength, int cellPerRow, int cellPerCol,
       	int thumbnailId
	)
	{
		Callback* cb = (Callback*) customData;
		cb->CreateTileProc(
			buffer, originX, originY, width, height,
			pageNum, cellNumber,
			finalRender, predictionRender,
			tilesRemaining, firstTile,
			canvasWidth, canvasHeight, cellSideLength, cellPerRow, cellPerCol,
			thumbnailId
		);
	}

	virtual void AnnotBitmapProc(int operation_type,
		char* buffer, UInt32 width, UInt32 height, UInt32 stride,
		UInt32 page_num, UInt32 annot_index, const void* annot_key,
		Int64 x_in_page, Int64 y_in_page, int x_offset, int y_offset,
		int remaining_tiles,  int sequence_number, Int64 x_page_size, Int64 y_page_size) {}

	static void StaticAnnotBitmapProc(void* me, int operation_type,
		char* buffer, UInt32 width, UInt32 height, UInt32 stride,
		UInt32 page_num, UInt32 annot_index, const void* annot_key,
		Int64 x_in_page, Int64 y_in_page, int x_offset, int y_offset,
		int remaining_tiles, int sequence_number, Int64 x_page_size, Int64 y_page_size) 
	{
		Callback* cb = (Callback*) me;
		cb->AnnotBitmapProc(operation_type, buffer,
			width, height, stride,
			page_num, annot_index, annot_key,
			x_in_page, y_in_page, x_offset, y_offset,
			remaining_tiles, sequence_number, x_page_size, y_page_size);
	}


	/* deluxe start */

virtual void DeluxeCreateTileProc(
		char* buffer, unsigned int width, unsigned int height, unsigned int stride,
		unsigned int page_num, UInt64 x_page_loc, UInt64 y_page_loc,
        unsigned int zoomed_page_width, unsigned int zoomed_page_height,
		unsigned int tile_id, unsigned int x_in_page, unsigned int y_in_page,
		int canvas_id, int remaining_tiles, int tile_type,
		int sequence_number
   	) { }
	
	static void StaticDeluxeCreateTileProc(             
       	void* me,
       char* buffer, unsigned int width, unsigned int height, unsigned int stride,
       unsigned int page_num, UInt64 x_page_loc, UInt64 y_page_loc,
       unsigned int zoomed_page_width, unsigned int zoomed_page_height,
       unsigned int tile_id, unsigned int x_in_page, unsigned int y_in_page,
       int canvas_id, int remaining_tiles, int tile_type,
       int sequence_number
       )
	{
		Callback* cb = (Callback*) me;
		cb->DeluxeCreateTileProc(
			buffer, width, height, stride, 
			page_num, x_page_loc, y_page_loc,
            zoomed_page_width, zoomed_page_height,
			tile_id, x_in_page, y_in_page,
			canvas_id, remaining_tiles, tile_type, 
			sequence_number
		);
	}

	/* deluxe end */
	
	virtual void RemoveTileProc(int canvasNumber, Int64 cellNumber, int thumbnailId, int sequenceNumber) { }
	
	static void StaticRemoveTileProc(void* customData, int canvasNumber, Int64 cellNumber, int thumbnailId, int sequenceNumber)
	{
		Callback* cb = (Callback*) customData;
		cb->RemoveTileProc(canvasNumber, cellNumber, thumbnailId, sequenceNumber);
	}

	virtual void PartDownloadedProc(int dlType, TRN_PDFDoc doc, unsigned int pageNum, unsigned int objNum, const char* message) { }

	static void StaticPartDownloadedProc(int dlType, TRN_PDFDoc doc, unsigned int pageNum, unsigned int objNum, const char* message, void* customData)
	{
		Callback* cb = (Callback*) customData;
		cb->PartDownloadedProc(dlType, doc, pageNum, objNum, message);
	}
};

	};	// namespace PDF
};	// namespace pdftron

#endif  // SWIG

#endif  // PDFTRON_H_CPPPDFCallback
