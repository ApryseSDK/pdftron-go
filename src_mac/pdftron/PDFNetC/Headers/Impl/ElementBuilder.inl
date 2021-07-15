
inline ElementBuilder::ElementBuilder() {
	REX(TRN_ElementBuilderCreate(&mp_builder));
}

inline ElementBuilder::~ElementBuilder() {
	DREX(mp_builder, TRN_ElementBuilderDestroy(mp_builder));
}

inline void ElementBuilder::Destroy()
{
	REX(TRN_ElementBuilderDestroy(mp_builder));
	mp_builder=0;
}

inline void ElementBuilder::Reset(GState gs) {
	REX(TRN_ElementBuilderReset(mp_builder,gs.mp_state));
}

inline Element ElementBuilder::CreateImage(Image& img) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateImage(mp_builder,img.mp_image,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateImage(Image& img, const Common::Matrix2D& mtx) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateImageFromMatrix(mp_builder,img.mp_image,(const TRN_Matrix2D*)&mtx,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateImage(Image& img, double x, double y, double hscale, double vscale) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateImageScaled(mp_builder,img.mp_image,x,y,hscale,vscale,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateGroupBegin() {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateGroupBegin(mp_builder,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateGroupEnd() {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateGroupEnd(mp_builder,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateShading(Shading& sh) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateShading(mp_builder,sh.mp_shade,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateForm(SDF::Obj form) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateFormFromStream(mp_builder,form.mp_obj,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateForm(Page page) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateFormFromPage(mp_builder,page.mp_page,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateForm(Page page, class PDFDoc& doc) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateFormFromDoc(mp_builder,page.mp_page,doc.mp_doc,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateTextBegin(Font font, double font_sz) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateTextBeginWithFont(mp_builder,font.mp_font,font_sz,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateTextBegin() {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateTextBegin(mp_builder,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateTextEnd() {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateTextEnd(mp_builder,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateTextRun(const char* text_data, Font font, double font_sz) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateTextRun(mp_builder,text_data,
		font.mp_font,font_sz,&result));
	return Element(result);
}

#ifndef SWIG
inline Element ElementBuilder::CreateTextRun(const char* text_data, UInt32 text_data_sz, Font font, double font_sz) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateTextRunWithSize(mp_builder,text_data,text_data_sz,font.mp_font,font_sz,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateTextRun(const UChar* text_data, UInt32 text_data_sz, Font font, double font_sz) {
	TRN_Element result;
	TRN_String text_dataString = { (const char*) text_data, (unsigned int) text_data_sz };
	REX(TRN_ElementBuilderCreateTextRunUnsigned(mp_builder,
		text_dataString, font.mp_font, font_sz, &result));
	return Element(result);
}
#endif

inline Element ElementBuilder::CreateTextRun(const char* text_data) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateNewTextRun(mp_builder,text_data,&result));
	return Element(result);
}

#ifndef SWIG
inline Element ElementBuilder::CreateTextRun(const char* text_data, UInt32 text_data_sz) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateNewTextRunWithSize(mp_builder,text_data,text_data_sz,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateTextRun(const UChar* text_data, UInt32 text_data_sz) {
	TRN_Element result;
	TRN_String text_dataString = { (const char*) text_data, (unsigned int) text_data_sz };
	REX(TRN_ElementBuilderCreateNewTextRunUnsigned(mp_builder, text_dataString, &result));
	return Element(result);
}
#endif

inline Element ElementBuilder::CreateUnicodeTextRun(const Unicode* text_data, UInt32 text_data_sz) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateUnicodeTextRun(mp_builder,text_data,text_data_sz,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateShapedTextRun(ShapedText shaped_text) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateShapedTextRun(mp_builder, shaped_text.m_impl, &result));
	return Element(result);
}

inline Element ElementBuilder::CreateTextNewLine(double dx, double dy) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateTextNewLineWithOffset(mp_builder,dx,dy,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateTextNewLine() {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateTextNewLine(mp_builder,&result));
	return Element(result);
}

inline Element ElementBuilder::CreatePath(const std::vector<double>& points, const std::vector<unsigned char>& seg_types) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreatePath(mp_builder,&(points[0]),static_cast<int>(points.size()),(const char*)&(seg_types[0]),static_cast<int>(seg_types.size()),&result));
	return Element(result);
}

#ifndef SWIG
inline Element ElementBuilder::CreatePath(const double* points, int point_count, const char* seg_types, int seg_types_count) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreatePath(mp_builder,points,point_count,seg_types,seg_types_count,&result));
	return Element(result);
}
#endif

inline Element ElementBuilder::CreateRect(double x, double y, double width, double height) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateRect(mp_builder,x,y,width,height,&result));
	return Element(result);
}

inline Element ElementBuilder::CreateEllipse(double cx, double cy, double rx, double ry) {
	TRN_Element result;
	REX(TRN_ElementBuilderCreateEllipse(mp_builder,cx,cy,rx,ry,&result));
	return Element(result);
}

inline void ElementBuilder::PathBegin() {
	REX(TRN_ElementBuilderPathBegin(mp_builder));
}

inline Element ElementBuilder::PathEnd() {
	TRN_Element result;
	REX(TRN_ElementBuilderPathEnd(mp_builder,&result));
	return Element(result);
}

inline void ElementBuilder::Rect(double x, double y, double width, double height) {
	REX(TRN_ElementBuilderRect(mp_builder,x,y,width,height));
}

inline void ElementBuilder::Ellipse(double cx, double cy, double rx, double ry) {
	REX(TRN_ElementBuilderEllipse(mp_builder,cx, cy, rx, ry));
}

inline void ElementBuilder::MoveTo(double x, double y) {
	REX(TRN_ElementBuilderMoveTo(mp_builder,x,y));
}

inline void ElementBuilder::LineTo(double x, double y) {
	REX(TRN_ElementBuilderLineTo(mp_builder,x,y));
}

inline void ElementBuilder::CurveTo(double cx1, double cy1, double cx2, double cy2, double x2, double y2) {
	REX(TRN_ElementBuilderCurveTo(mp_builder,cx1,cy1,cx2,cy2,x2,y2));
}

inline void ElementBuilder::ArcTo(double x, double y, double width, double height, double start, double extent) {
	REX(TRN_ElementBuilderArcTo(mp_builder, x, y, width, height, start, extent));
}

inline void ElementBuilder::ArcTo(double xr, double yr, double rx, bool isLargeArc, bool sweep, double endX, double endY) {
	REX(TRN_ElementBuilderArcTo2(mp_builder, xr, yr, rx, isLargeArc, sweep, endX, endY));
}

inline void ElementBuilder::ClosePath() {
	REX(TRN_ElementBuilderClosePath(mp_builder));
}

inline Element ElementBuilder::CreateMarkedContentBeginInlineProperties(const char* tag)
{
	TRN_Element result;
	REX(TRN_ElementBuilderCreateMarkedContentBeginInlineProperties(mp_builder, tag, (TRN_Element*) &result));
	return Element(result);
}

inline Element ElementBuilder::CreateMarkedContentBegin(const char* tag, SDF::Obj property_dict)
{
	TRN_Element result;
	REX(TRN_ElementBuilderCreateMarkedContentBegin(mp_builder, tag, property_dict.mp_obj, (TRN_Element*) &result));
	return Element(result);
}

inline Element ElementBuilder::CreateMarkedContentEnd()
{
	TRN_Element result;
	REX(TRN_ElementBuilderCreateMarkedContentEnd(mp_builder, (TRN_Element*) &result));
	return Element(result);
}

inline Element ElementBuilder::CreateMarkedContentPointInlineProperties(const char* tag)
{
	TRN_Element result;
	REX(TRN_ElementBuilderCreateMarkedContentPointInlineProperties(mp_builder, tag, (TRN_Element*) &result));
	return Element(result);
}

inline Element ElementBuilder::CreateMarkedContentPoint(const char* tag, SDF::Obj property_dict)
{
	TRN_Element result;
	REX(TRN_ElementBuilderCreateMarkedContentPoint(mp_builder, tag, property_dict.mp_obj, (TRN_Element*) &result));
	return Element(result);
}
