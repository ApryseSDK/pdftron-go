
inline Image2RGB::Image2RGB(Element image_element) 
 : Filter(0, true)
{
	REX(TRN_FilterCreateImage2RGBFromElement(image_element.mp_elem,&m_impl));
}

inline Image2RGB::Image2RGB(SDF::Obj image_xobject) 
: Filter(0, true)
{
	REX(TRN_FilterCreateImage2RGBFromObj(image_xobject.mp_obj,&m_impl));
}

inline Image2RGB::Image2RGB(Image image)
 : Filter(0, true)
{
	REX(TRN_FilterCreateImage2RGB(image.mp_image,&m_impl));
}


