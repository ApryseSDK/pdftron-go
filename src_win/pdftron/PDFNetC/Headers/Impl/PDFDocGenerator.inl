inline PDFDoc PDFDocGenerator::GenerateBlankPaperDoc(double width, double height, double background_red, double background_green, double background_blue)
{
	PDFDoc result;
	REX(TRN_PDFDocGeneratorGenerateBlankPaperDoc(width, height, background_red, background_green, background_blue, (TRN_PDFDoc*)&result.mp_doc));
	return result;
}

inline PDFDoc PDFDocGenerator::GenerateGridPaperDoc(double width, double height, double grid_spacing, double line_thickness, double red, double green, double blue, double background_red, double background_green, double background_blue)
{
	PDFDoc result;
	REX(TRN_PDFDocGeneratorGenerateGridPaperDoc(width, height, grid_spacing, line_thickness, red, green, blue, background_red, background_green, background_blue, (TRN_PDFDoc*)&result.mp_doc));
	return result;
}

inline PDFDoc PDFDocGenerator::GenerateLinedPaperDoc(double width, double height, double line_spacing, double line_thickness, double red, double green, double blue, double left_margin_distance, double left_margin_red, double left_margin_green, double left_margin_blue, double right_margin_red, double right_margin_green, double right_margin_blue, double background_red, double background_green, double background_blue, double top_margin_distance, double bottom_margin_distance)
{
	PDFDoc result;
	REX(TRN_PDFDocGeneratorGenerateLinedPaperDoc(width, height, line_spacing, line_thickness, red, green, blue, left_margin_distance, left_margin_red, left_margin_green, left_margin_blue, right_margin_red, right_margin_green, right_margin_blue, background_red, background_green, background_blue, top_margin_distance, bottom_margin_distance, (TRN_PDFDoc*)&result.mp_doc));
	return result;
}

inline PDFDoc PDFDocGenerator::GenerateGraphPaperDoc(double width, double height, double grid_spacing, double line_thickness, double weighted_line_thickness, int weighted_line_freq, double red, double green, double blue, double background_red, double background_green, double background_blue)
{
	PDFDoc result;
	REX(TRN_PDFDocGeneratorGenerateGraphPaperDoc(width, height, grid_spacing, line_thickness, weighted_line_thickness, weighted_line_freq, red, green, blue, background_red, background_green, background_blue, (TRN_PDFDoc*)&result.mp_doc));
	return result;
}

inline PDFDoc PDFDocGenerator::GenerateMusicPaperDoc(double width, double height, double margin, int staves, double linespace_size_pts, double line_thickness, double red, double green, double blue, double background_red, double background_green, double background_blue)
{
	PDFDoc result;
	REX(TRN_PDFDocGeneratorGenerateMusicPaperDoc(width, height, margin, staves, linespace_size_pts, line_thickness, red, green, blue, background_red, background_green, background_blue, (TRN_PDFDoc*)&result.mp_doc));
	return result;
}

inline PDFDoc PDFDocGenerator::GenerateDottedPaperDoc(double width, double height, double dot_spacing, double dot_size, double red, double green, double blue, double background_red, double background_green, double background_blue)
{
	PDFDoc result;
	REX(TRN_PDFDocGeneratorGenerateDottedPaperDoc(width, height, dot_spacing, dot_size, red, green, blue, background_red, background_green, background_blue, (TRN_PDFDoc*)&result.mp_doc));
	return result;
}

inline PDFDoc PDFDocGenerator::GenerateIsometricDottedPaperDoc(double width, double height, double dot_spacing, double dot_size, double red, double green, double blue, double background_red, double background_green, double background_blue)
{
	PDFDoc result;
	REX(TRN_PDFDocGeneratorGenerateIsometricDottedPaperDoc(width, height, dot_spacing, dot_size, red, green, blue, background_red, background_green, background_blue, (TRN_PDFDoc*)&result.mp_doc));
	return result;
}