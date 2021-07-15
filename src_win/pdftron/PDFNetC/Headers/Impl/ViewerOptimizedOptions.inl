#include <Impl/Utils.inl>

inline ViewerOptimizedOptions::ViewerOptimizedOptions()
{
    m_obj = m_objset.CreateDict().mp_obj;
}

inline void ViewerOptimizedOptions::SetThumbnailRenderingThreshold(UInt32 threshold)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "COMPLEXITY_THRESHOLD", threshold, &result)); 
}
inline void ViewerOptimizedOptions::SetThumbnailSize(UInt32 size)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "THUMB_SIZE", size, &result));
}

inline void ViewerOptimizedOptions::SetOverprint(PDFRasterizer::OverprintPreviewMode mode)
{
	TRN_Obj result; 
	SetOverprintImpl(m_obj, mode, &result);
}




