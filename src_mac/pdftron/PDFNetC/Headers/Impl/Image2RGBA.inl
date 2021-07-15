
inline Image2RGBA::Image2RGBA(Element image_element, bool premultiply) 
 : Filter(0, true)
{
	REX(TRN_FilterCreateImage2RGBAFromElement(image_element.mp_elem,BToTB(premultiply),&m_impl));
}

inline Image2RGBA::Image2RGBA(SDF::Obj image_xobject, bool premultiply) 
 : Filter(0, true)
{
	REX(TRN_FilterCreateImage2RGBAFromObj(image_xobject.mp_obj,BToTB(premultiply),&m_impl));
}

inline Image2RGBA::Image2RGBA(Image& image, bool premultiply) 
 : Filter(0, true)
{
	REX(TRN_FilterCreateImage2RGBA(image.mp_image,BToTB(premultiply),&m_impl));
}

